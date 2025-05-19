//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "DMFrm.h"
#include "ErrorFrm.h"
#include "NotifyFrm.h"
#include "DotSlipPrintFrm.h"
#include "LaserSlipPrintFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TAD4385PostForm *AD4385PostForm;
//---------------------------------------------------------------------------
__fastcall TAD4385PostForm::TAD4385PostForm(TComponent* Owner)
    : TForm(Owner)
{
    for (int i = 0; i < SCALE_COUNT; i++){
        thread_[i]         = 0;
        cur_weight_[i]     = 0;
        old_weight_[i]     = 0;
        cur_wi_status_[i]  = wsOther;
        top_margin_[i]     = 0;
        display_weight_[i] = 0;

        ScaleForm_[i]      = 0;

    	on_weighing_[i]    = false;
    	reversed_[i]       = false;
    	on_error_[i]       = false;
    	limit_over_[i]     = false;
    	on_printing_[i]    = false;
    	on_wait_exit_[i]   = false;

        thread_id_[i]      = 0;
        post_name_[i]      = AnsiString("����|�X�g(") + AnsiString(char('A' + i))+ ")";
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::FormCreate(TObject *Sender)
{
    Caption = "AD4385 ����|�X�g����";

	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�

	if (!DM->Init())
		Close();

	//ApplyConfig();

	///////////////////////////////////////////////
	// AD4385 �ʐM�X���b�h�̏��� [INI]

    int port         = ToInt(DM->INI["AD4385::Port"]);
    std::string def  = ToString(DM->INI["AD4385::Def"]).c_str();
    weighing_border_ = ToInt(DM->INI["AD4385::Border"]);
    notify_sound_    = ToString(DM->INI["AD4385::NotifySound"]).c_str();

    if (port < 1)
        port = 1;
    if (def.empty())
        def = "9600,E,8,1";

	ad85_info_[ScaleA].port  		  = port;
	ad85_info_[ScaleA].def   		  = def;
	ad85_info_[ScaleA].owner 		  = Handle;
	ad85_info_[ScaleA].tag   		  = ScaleA;
	ad85_info_[ScaleA].display_weight = &(display_weight_[ScaleA]);
	ad85_info_[ScaleA].thread_id	  = &(thread_id_[ScaleA]);
	ad85_info_[ScaleA].warning		  = &(ad85_warning_[ScaleA]);
	ad85_info_[ScaleA].status		  = &(ad85_status_[ScaleA]);
    top_margin_[ScaleA]               = ToInt(DM->INI["AD4385::TopMargin"]);

    port = ToInt(DM->INI["AD4385_2::Port"]);
    def  = ToString(DM->INI["AD4385_2::Def"]).c_str();

    if (port < 1)
        port = 1;
    if (def.empty())
        def = "9600,E,8,1";

	ad85_info_[ScaleB].port  		  = port;
	ad85_info_[ScaleB].def   		  = def;
	ad85_info_[ScaleB].owner 		  = Handle;
	ad85_info_[ScaleB].tag   		  = ScaleB;
	ad85_info_[ScaleB].display_weight = &(display_weight_[ScaleB]);
	ad85_info_[ScaleB].thread_id	  = &(thread_id_[ScaleB]);
	ad85_info_[ScaleB].warning		  = &(ad85_warning_[ScaleB]);
	ad85_info_[ScaleB].status		  = &(ad85_status_[ScaleB]);
    top_margin_[ScaleB]               = ToInt(DM->INI["AD4385_2::TopMargin"]);

    ThreadCreateTimer->Enabled = true;

	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
    Width = rect.right - rect.left;

    ScaleForm_[ScaleA] = new TDisplayForm(this);
    ScaleForm_[ScaleA]->ScaleNamePanel->Caption = "�X�P�[�� 1";
    ScaleForm_[ScaleA]->ScaleNamePanel->Color   = TColor(0x006882F9);
    //ScaleForm_[ScaleA]->Height = 120;
    ScaleForm_[ScaleA]->Top  = rect.top + 4;
    ScaleForm_[ScaleA]->Left = rect.left + 4;
    ScaleForm_[ScaleB] = new TDisplayForm(this);
    ScaleForm_[ScaleB]->ScaleNamePanel->Caption = "�X�P�[�� 2";
    ScaleForm_[ScaleB]->ScaleNamePanel->Color   = TColor(0x0044EA65);
    //ScaleForm_[ScaleB]->Height = 120;
    ScaleForm_[ScaleB]->Top  = rect.top + 4;
    ScaleForm_[ScaleB]->Left = rect.left + 4 + ScaleForm_[ScaleA]->Width + 20;

    ScaleForm_[ScaleA]->Clear();
    ScaleForm_[ScaleA]->Show();
    ScaleForm_[ScaleB]->Clear();
    ScaleForm_[ScaleB]->Show();
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ThreadCreateTimerTimer(TObject *Sender)
{
    ThreadCreateTimer->Enabled = false;

    place_id_ = ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", ToInt(DM->INI["Place::Code"]), "���_ID"));
    if (place_id_ < 1){
        Application->MessageBox("���_��񂪐���������܂���", "�v�ʐݒ�G���[", MB_OK | MB_ICONSTOP | MB_TOPMOST);
        Close();
        return;
    }

    NotifyForm->Sound = notify_sound_;

	///////////////////////////////////////////////
	// AD4385 �ʐM�X���b�h�̍쐬

	thread_[ScaleA] = new TAD4385Thread(false, ad85_info_[ScaleA], top_margin_[ScaleA]);
	thread_[ScaleA]->FreeOnTerminate = false;
	thread_[ScaleB] = new TAD4385Thread(false, ad85_info_[ScaleB], top_margin_[ScaleB]);
	thread_[ScaleB]->FreeOnTerminate = false;

	/* AD4385 �Ƃ̒ʐM���n�܂�܂őҋ@�itnk�j
	 * �N������Ɍv�ʊJ�n�d�ʂɓ��B���A�����v����Ȃǂ̏���������ꍇ�ɁA
	 * AD4385 �Ƃ̒ʐM�����S�Ɋm������Ă��Ȃ��ƁA����̃^�C�~���O�������Ă��܂��B
	 */
	Sleep(2000);

	///////////////////////////////////////////////
	// �d�ʎ�M
	try{
		// [INI] Weighing::WIPort
		ClientSocket1->Port = ToInt(DM->INI["Weighing::WIPort"]);
		// [INI] Weighing::WIServer
		ClientSocket1->Host = ToString(DM->INI["Weighing::WIServer"]);
		// [INI] Weighing::WIPort2
		ClientSocket2->Port = ToInt(DM->INI["Weighing::WIPort2"]);
		// [INI] Weighing::WIServer2
		ClientSocket2->Host = ToString(DM->INI["Weighing::WIServer2"]);

		if (ClientSocket1->Active)
			ClientSocket1->Close();
		ClientSocket1->Open();

		if (ClientSocket2->Active)
			ClientSocket2->Close();
		ClientSocket2->Open();
	}catch(Exception& e){
		AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
		Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONSTOP | MB_TOPMOST);
	}
	SocketReopenTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (thread_[ScaleA])
		thread_[ScaleA]->Terminate();
    if (thread_[ScaleA])
		thread_[ScaleA]->WaitFor();
    if (thread_[ScaleA])
        delete thread_[ScaleA];
    if (thread_[ScaleB])
		thread_[ScaleB]->Terminate();
    if (thread_[ScaleB])
		thread_[ScaleB]->WaitFor();
    if (thread_[ScaleB])
        delete thread_[ScaleB];

    if (ScaleForm_[ScaleA]){
        ScaleForm_[ScaleA]->Close();
        delete ScaleForm_[ScaleA];
    }
    if (ScaleForm_[ScaleB]){
        ScaleForm_[ScaleB]->Close();
        delete ScaleForm_[ScaleB];
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("������I��������ƁA����|�X�g����؎g�p�ł��Ȃ��Ȃ�܂�\r\n"
                                "��낵���ł����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST)
                == IDYES){
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::SocketReopenTimerTimer(TObject *Sender)
{
	if (ClientSocket1->Active && ClientSocket2->Active)
		return;

    if (!(ClientSocket1->Active)){
    	try{
	    	// [INI] Weighing::WIPort
		    ClientSocket1->Port = ToInt(DM->INI["Weighing::WIPort"]);
    		// [INI] Weighing::WIServer
    		ClientSocket1->Host = ToString(DM->INI["Weighing::WIServer"]);

    		ClientSocket1->Open();
    	}catch(Exception& e){
    		//AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
    		//Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
    		;
    	}
    }
    if (!(ClientSocket2->Active)){
    	try{
	    	// [INI] Weighing::WIPort2
		    ClientSocket2->Port = ToInt(DM->INI["Weighing::WIPort2"]);
    		// [INI] Weighing::WIServer2
    		ClientSocket2->Host = ToString(DM->INI["Weighing::WIServer2"]);

    		ClientSocket2->Open();
    	}catch(Exception& e){
    		//AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
    		//Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
    		;
    	}
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ClientSocketError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
/*
	switch (ErrorEvent){
	case eeReceive:
		StatusBar->SimpleText = "�d�ʒl��M: ��M�G���[";
		break;
	case eeConnect:
		StatusBar->SimpleText = "�d�ʒl��M: �ڑ��G���[";
		break;
	case eeDisconnect:
		StatusBar->SimpleText = "�d�ʒl��M: �ؒf�G���[";
		break;
	default:
		StatusBar->SimpleText = "�d�ʒl��M: �\�P�b�g�G���[";
		break;
	};
*/
    TClientSocket *Sock = dynamic_cast<TClientSocket *>(Sender);
    if (!Sock)
        return;
    int tag = Sock->Tag;

	Sock->Close();
    old_weight_[tag] = 0;
    cur_weight_[tag] = 0;
    OnExitWeighing(tag);

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    TClientSocket *Sock = dynamic_cast<TClientSocket *>(Sender);
    if (!Sock)
        return;
    int tag = Sock->Tag;

	int index;
	AnsiString weight = Socket->ReceiveText();

	int len = weight.Length();
	if (len < 4)					return;
	if (weight[len - 1] != '\r')	return;
	if (weight[len] != '\n')		return;
	switch (weight[1]){
	case 'S':	cur_wi_status_[tag] = wsStable;      break;
	case 'U':	cur_wi_status_[tag] = wsUnstable;    break;
	case 'O':	cur_wi_status_[tag] = wsOther;       break;
	default:
		return;
	}

	weight.Delete(1, 1);	// �X�e�[�^�X�L�����N�^�̍폜
	weight.Delete(weight.Length() - 1, 2);	// ������ \r\n ���폜
	Currency tmp_weight;
	try{
		tmp_weight = Currency(weight);
	}catch(...){return;}

	old_weight_[tag] = cur_weight_[tag];
	cur_weight_[tag] = tmp_weight;

    display_weight_[tag] = cur_weight_[tag];

	if (old_weight_[tag] < weighing_border_ && cur_weight_[tag] >= weighing_border_){
        on_weighing_[tag] = true;
        OnEnterWeighing(tag);
	}else if ((old_weight_[tag] >= weighing_border_) && (cur_weight_[tag] < weighing_border_)){
        on_weighing_[tag] = false;
        OnExitWeighing(tag);
    }

    switch (cur_wi_status_[tag]){
    case wsStable:   ScaleForm_[tag]->WeightPanel->Font->Color = TColor(0x00CDF7A4); break;
    case wsUnstable: ScaleForm_[tag]->WeightPanel->Font->Color = TColor(0x008080FF); break;
    case wsOther:    ScaleForm_[tag]->WeightPanel->Font->Color = clGray;             break;
    };
    ScaleForm_[tag]->WeightPanel->Caption = FormatFloat("###,##0", cur_weight_[tag]);
}
//---------------------------------------------------------------------------
/**
 * Implementation of Weighing Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnEnterWeighing(int tag)
{
	/*** �v�ʊJ�n(�X�P�[������) ***/

	if (IsThreadActive(tag)){
		// �����v�̓_���ƁA�L�[�{�[�h�̏�����
		ad85_params_[tag].lamp = AD4385Lamp(true, false, false);
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
		ad85_params_[tag].key = true;
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmKey, (LPARAM)(&(ad85_params_[tag])));
	}
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnExitWeighing(int tag)
{
	/*** �v�ʏI��(�~��) ***/

	if (IsThreadActive(tag)){
		ad85_params_[tag].lamp = AD4385Lamp(false, false, false);
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
		ad85_params_[tag].key = false;
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmKey, (LPARAM)(&(ad85_params_[tag])));
	}

    //ScaleForm_[tag]->Height = 103;
    ScaleForm_[tag]->Clear();

	on_wait_exit_[tag] = false;	// �ގԑ҂���Ԃ��N���A
}
//---------------------------------------------------------------------------
/**
 * Implementation of AD4385 Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::UMAD4385Aborted(TMessage& message)
{
	DWORD thread_id = message.WParam;
	int tag         = message.LParam;

	if (thread_id == thread_[tag]->ThreadID){
		delete thread_[tag];
        thread_[tag] = 0;
	}

    DM->Log(post_name_[tag], "�ʐM�s��", 2);

    if (ErrorForm->Showed)
        return;

    ErrorForm->TitlePanel->Caption = post_name_[tag] + " �Ƃ̒ʐM���ł��܂���";
    ErrorForm->TextMemo->Lines->Clear();
    ErrorForm->TextMemo->Lines->Text = "�ʐM�|�[�g���g�p�ł��Ȃ����߁A�ʐM���s���܂���B\r\n"
                                       "\r\n"
                                       "ScaleManger �ݒ��񂪕ύX���ꂽ�\��������܂��B\r\n"
                                       "�܂��APC �̌̏ᓙ�ł���������ꍇ������܂��B\r\n"
                                       "\r\n"
                                       "PC ���ċN�����Ă���肪�������Ȃ��ꍇ�́A���₢���킹���������B";
    ErrorForm->ShowModal();
    
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385Warning(int tag)
{
    DM->Log(post_name_[tag], ad85_warning_[tag].message, 1);

    if (ad85_warning_[tag].is_fatal){
        NotifyForm->HeaderPanel->Caption = post_name_[tag];
        NotifyForm->Notify(ad85_warning_[tag].message, true, 20000);
    }else{
        if (ad85_warning_[tag].message == "�ʐM���J�n���܂���")
            return;

        NotifyForm->HeaderPanel->Caption = post_name_[tag];
        NotifyForm->Notify("�ʐM�x��", false, 6000);
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385Event(int tag)
{
	switch (ad85_status_[tag].event){
	case evCard:
		OnAD4385CardInsert(tag, ad85_status_[tag].card_key_info);
		break;
	case evCardReverse:
		OnAD4385CardReverse(tag);
		break;
	case evCardOut:
		OnAD4385CardOut(tag);
		break;
	case evPowerOn:
		OnAD4385PowerOn(tag);
		break;
	case evPowerNg:
		OnAD4385PowerNg(tag);
		break;
	case evPrinterAbnormal:
		OnAD4385PrinterAbnormal(tag);
		break;
	case evPaperExist:
		OnAD4385PaperExist(tag);
		break;
	case evNoPaper:
		OnAD4385NoPaper(tag);
		break;
	case evKeiryo:
		OnAD4385Keiryo(tag);
		break;
	case evPrintAck:
		OnAD4385PrintAck(tag);
		break;
	case evNm:
		OnAD4385NameRequired(tag, ad85_status_[tag].required_info);
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385CardInsert(int tag, const AD4385CardKeyInfo& info)
{
	/*** �J�[�h�}���C�x���g ***/
    DM->Log(post_name_[tag], "�J�[�h�}��", 0);

    if (!IsThreadActive(tag)){
        DM->Log(post_name_[tag], "debug thread non-active", 0);
        return;
    }

	if (!on_weighing_[tag]){
        DM->Log(post_name_[tag], "debug no car", 0);
		return;
    }
	if (on_printing_[tag]){
        DM->Log(post_name_[tag], "debug on printing", 0);
		return;
    }
	if (on_wait_exit_[tag]){
        DM->Log(post_name_[tag], "debug wait exit", 0);
		return;
    }
	if (on_error_[tag]){
        DM->Log(post_name_[tag], "debug on error", 0);
		return;
    }

    ////////// �����҂�
	{
		// ����M����҂�
		DWORD start = GetTickCount();
		DWORD now;
		while (cur_wi_status_ != wsStable){
			Sleep(0);
			Application->ProcessMessages();
			now = GetTickCount();
			if (int(now - start) >= 1000)
				break;
		}
		if (cur_weight_[tag] < weighing_border_)
			return;
	}

	// ��x�S�Ẵ����v������
	ad85_params_[tag].lamp = AD4385Lamp(false, false, false);
	PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));

	AD4385CardKeyInfo::CardInfo card(info.card);
    AD4385CardKeyInfo::KeyInfo  key(info.key);
    bool print = false;

	TDateTime now(Now());
	int date = now.FormatString("yyyymmdd").ToInt();

	int toku_cd, meig_cd, item1_cd, item2_cd;
	int toku_id, meig_id, item1_id, item2_id, tani_id;
	NsRecord toku_rec, meig_rec, item1_rec, item2_rec;
	int car_no, keiryo_no, keiryo_id;

	if (card.id < 1){
        DM->Log(post_name_[tag], "�J�[�h�ԍ������ɂ��v�ʒ��~�iID < 1�j", 1);
        NotifyForm->HeaderPanel->Caption = post_name_[tag];
        NotifyForm->Notify("�����ȃJ�[�h���}������܂���", false, 10000);

		on_error_[tag] = true;

		ad85_params_[tag].lamp = AD4385Lamp(false, false, true);
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
    	return;
	}

    //////////
    try{
    //////////

  	NsRecord card_rec;

    if (!DM->GetCardInfo(card.id, card_rec)){
        DM->Log(post_name_[tag], "���o�^�ԗ��ɂ��v�ʒ��~�i�J�[�h�ԍ�:" + IntToStr(card.id) + "�j", 1);
        NotifyForm->HeaderPanel->Caption = post_name_[tag];
        NotifyForm->Notify("���o�^�ԗ��ł�: " + IntToStr(card.id), false, 10000);

  		on_error_[tag] = true;

   		ad85_params_[tag].lamp = AD4385Lamp(false, false, true);
  		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
   		return;
   	}

    car_no = ToInt(card_rec["�Ԕ�"]);

    ////////////////////////////////////////////////////////////////////////////
    // AD4385 ���ڂ� ScM �}�X�^�Ƃ̑Ή��\�^�ϐ��\���쐬
    std::map<int, int> cnv_table;   // map<AD4385����, ScM�}�X�^>
    cnv_table[1] = ToInt(DM->CFG["AD4385 ���ڂP"]);
    cnv_table[2] = ToInt(DM->CFG["AD4385 ���ڂQ"]);
    cnv_table[3] = ToInt(DM->CFG["AD4385 ���ڂR"]);
    cnv_table[4] = ToInt(DM->CFG["AD4385 ���ڂS"]);
    for (int i = 1; i <= 4; i++){
        if (cnv_table[i] < 1 || cnv_table[i] > 4)
            cnv_table[i] = 0;
    }

    // cnv_table[] = 1..4
    std::map<int, int *> scm_codes;
    int dummy;
    scm_codes[0] = &dummy;
    scm_codes[1] = &toku_cd;
    scm_codes[2] = &item1_cd;
    scm_codes[3] = &item2_cd;
    scm_codes[4] = &meig_cd;

    ////////////////////////////////////////////////////////////////////////////
    // �J�[�h���A�J�[�h�}�X�^���A�L�[���Ŏԗ�������������

    if (cur_weight_[tag] > ToCurrency(card_rec["�ԗ����d��"]) && ToCurrency(card_rec["�ԗ����d��"]) > 0){
        DM->Log(post_name_[tag], "�ԗ����d�ʂɑ΂���ߐύځi�Ԕ�:" + IntToStr(car_no) + "�j", 1);
        NotifyForm->HeaderPanel->Caption = post_name_[tag];
        NotifyForm->Notify("�ԗ����d�ʂɑ΂���ߐύڂł�: " + IntToStr(car_no), false, 30000);

  		on_error_[tag] = true;

   		ad85_params_[tag].lamp = AD4385Lamp(false, false, true);
  		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
   		return;
    }

   	NsFieldSet fields;
  	fields
        << NsField("[�v�ʓ�]",     date)
        << NsField("[���_ID]",     place_id_)
        << NsField("[�sNo]",       1)
        << NsField("[�ԗ�ID]",     ToInt(card_rec["�ԗ�ID"]))
        << NsField("[�X�V����]",   now)
       	;
    Currency tare_w = ToCurrency(card_rec["��ԏd��"]);
    int remained_id = DM->GetRemainedKeiryoID(place_id_, ToInt(card_rec["�ԗ�ID"]));

    if (!remained_id){
        // ���ڌv�ʁ^���v�ʂ������͈��v��

        ////////////////////////////////////////////////////////////////////////////
        // �J�[�h���A�J�[�h�}�X�^���A�L�[���Ŏԗ�������������

        ///// �D��x�i��j�J�[�h���
        *(scm_codes[cnv_table[1]]) = card.item1;
        *(scm_codes[cnv_table[2]]) = card.item2;
        *(scm_codes[cnv_table[3]]) = card.item3;
        *(scm_codes[cnv_table[4]]) = card.item4;

        //----------------------------------------------------------------------

        int code;

        ///// �D��x�i���j�}�X�^���
        code = ToInt(card_rec["���Ӑ�R�[�h"]);
        if (code)       toku_cd  = code;
        code = ToInt(card_rec["�i�ڃR�[�h"]);
        if (code)       meig_cd  = code;
        code = ToInt(card_rec["����1�R�[�h"]);
        if (code)       item1_cd = code;
        code = ToInt(card_rec["����2�R�[�h"]);
        if (code)       item2_cd = code;

        //----------------------------------------------------------------------

        toku_id  = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", toku_cd,  "���Ӑ�ID"));
        meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   meig_cd, "�i��ID"));
        item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h",  item1_cd, "����1ID"));
        item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h",  item2_cd,  "����2ID"));

        DM->GetViewRec("���Ӑ�", toku_id,  toku_rec);
        DM->GetViewRec("�i��",   meig_id,  meig_rec);
        DM->GetViewRec("����1",  item1_id, item1_rec);
        DM->GetViewRec("����2",  item2_id, item2_rec);

        fields
            << NsField("[���Ӑ�ID]",   toku_id)
    		<< NsField("[���Ӑ於��]", ToString(toku_rec["���Ӑ於��"]))
            << NsField("[����1ID]",    item1_id)
            << NsField("[����1����]",  ToString(item1_rec["����1����"]))
            << NsField("[����2ID]",    item2_id)
            << NsField("[����2����]",  ToString(item2_rec["����2����"]))
            << NsField("[�i��ID]",     meig_id)
            << NsField("[�i�ږ���]",   ToString(meig_rec["�i�ږ���"]))
            << NsField("[�����o�敪]", ToInt(meig_rec["�����o�敪"]))
            ;
    }


    ///// �D��x�i���j�L�[���
    if (key.item1){
        *(scm_codes[cnv_table[1]]) = key.item1;
        switch (cnv_table[1]){       // key.item1 ���ǂ̍��ڂɑΉ����Ă��邩
        case 1:
            toku_id  = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", toku_cd,  "���Ӑ�ID"));
            DM->GetViewRec("���Ӑ�", toku_id,  toku_rec);
            ReplaceSetField(fields, "[���Ӑ�ID]",   toku_id);
            ReplaceSetField(fields, "[���Ӑ於��]", ToString(toku_rec["���Ӑ於��"]));
            break;
        case 2:
            item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h",  item1_cd, "����1ID"));
            DM->GetViewRec("����1",  item1_id, item1_rec);
            ReplaceSetField(fields, "[����1ID]",    item1_id);
            ReplaceSetField(fields, "[����1����]",  ToString(item1_rec["����1����"]));
            break;
        case 3:
            item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h",  item2_cd,  "����2ID"));
            DM->GetViewRec("����2",  item2_id, item2_rec);
            ReplaceSetField(fields, "[����2ID]",    item2_id);
            ReplaceSetField(fields, "[����2����]",  ToString(item2_rec["����2����"]));
        case 4:
            meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   meig_cd, "�i��ID"));
            DM->GetViewRec("�i��",   meig_id,  meig_rec);
            ReplaceSetField(fields, "[�i��ID]",     meig_id);
            ReplaceSetField(fields, "[�i�ږ���]",   ToString(meig_rec["�i�ږ���"]));
            ReplaceSetField(fields, "[�����o�敪]", ToInt(meig_rec["�����o�敪"]));
        }
    }
    if (key.item2){
        *(scm_codes[cnv_table[2]]) = key.item2;
        switch (cnv_table[2]){       // key.item2 ���ǂ̍��ڂɑΉ����Ă��邩
        case 1:
            toku_id  = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", toku_cd,  "���Ӑ�ID"));
            DM->GetViewRec("���Ӑ�", toku_id,  toku_rec);
            ReplaceSetField(fields, "[���Ӑ�ID]",   toku_id);
            ReplaceSetField(fields, "[���Ӑ於��]", ToString(toku_rec["���Ӑ於��"]));
            break;
        case 2:
            item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h",  item1_cd, "����1ID"));
            DM->GetViewRec("����1",  item1_id, item1_rec);
            ReplaceSetField(fields, "[����1ID]",    item1_id);
            ReplaceSetField(fields, "[����1����]",  ToString(item1_rec["����1����"]));
            break;
        case 3:
            item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h",  item2_cd,  "����2ID"));
            DM->GetViewRec("����2",  item2_id, item2_rec);
            ReplaceSetField(fields, "[����2ID]",    item2_id);
            ReplaceSetField(fields, "[����2����]",  ToString(item2_rec["����2����"]));
            break;
        case 4:
            meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   meig_cd, "�i��ID"));
            DM->GetViewRec("�i��",   meig_id,  meig_rec);
            ReplaceSetField(fields, "[�i��ID]",     meig_id);
            ReplaceSetField(fields, "[�i�ږ���]",   ToString(meig_rec["�i�ږ���"]));
            ReplaceSetField(fields, "[�����o�敪]", ToInt(meig_rec["�����o�敪"]));
            break;
        }
    }
    if (key.item3){
        *(scm_codes[cnv_table[3]]) = key.item3;
        switch (cnv_table[3]){       // key.item3 ���ǂ̍��ڂɑΉ����Ă��邩
        case 1:
            toku_id  = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", toku_cd,  "���Ӑ�ID"));
            DM->GetViewRec("���Ӑ�", toku_id,  toku_rec);
            ReplaceSetField(fields, "[���Ӑ�ID]",   toku_id);
            ReplaceSetField(fields, "[���Ӑ於��]", ToString(toku_rec["���Ӑ於��"]));
            break;
        case 2:
            item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h",  item1_cd, "����1ID"));
            DM->GetViewRec("����1",  item1_id, item1_rec);
            ReplaceSetField(fields, "[����1ID]",    item1_id);
            ReplaceSetField(fields, "[����1����]",  ToString(item1_rec["����1����"]));
            break;
        case 3:
            item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h",  item2_cd,  "����2ID"));
            DM->GetViewRec("����2",  item2_id, item2_rec);
            ReplaceSetField(fields, "[����2ID]",    item2_id);
            ReplaceSetField(fields, "[����2����]",  ToString(item2_rec["����2����"]));
        case 4:
            meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   meig_cd, "�i��ID"));
            DM->GetViewRec("�i��",   meig_id,  meig_rec);
            ReplaceSetField(fields, "[�i��ID]",     meig_id);
            ReplaceSetField(fields, "[�i�ږ���]",   ToString(meig_rec["�i�ږ���"]));
            ReplaceSetField(fields, "[�����o�敪]", ToInt(meig_rec["�����o�敪"]));
        }
    }
    if (key.item4){
        *(scm_codes[cnv_table[4]]) = key.item4;
        switch (cnv_table[4]){       // key.item4 ���ǂ̍��ڂɑΉ����Ă��邩
        case 1:
            toku_id  = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", toku_cd,  "���Ӑ�ID"));
            DM->GetViewRec("���Ӑ�", toku_id,  toku_rec);
            ReplaceSetField(fields, "[���Ӑ�ID]",   toku_id);
            ReplaceSetField(fields, "[���Ӑ於��]", ToString(toku_rec["���Ӑ於��"]));
            break;
        case 2:
            item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h",  item1_cd, "����1ID"));
            DM->GetViewRec("����1",  item1_id, item1_rec);
            ReplaceSetField(fields, "[����1ID]",    item1_id);
            ReplaceSetField(fields, "[����1����]",  ToString(item1_rec["����1����"]));
            break;
        case 3:
            item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h",  item2_cd,  "����2ID"));
            DM->GetViewRec("����2",  item2_id, item2_rec);
            ReplaceSetField(fields, "[����2ID]",    item2_id);
            ReplaceSetField(fields, "[����2����]",  ToString(item2_rec["����2����"]));
        case 4:
            meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   meig_cd, "�i��ID"));
            DM->GetViewRec("�i��",   meig_id,  meig_rec);
            ReplaceSetField(fields, "[�i��ID]",     meig_id);
            ReplaceSetField(fields, "[�i�ږ���]",   ToString(meig_rec["�i�ږ���"]));
            ReplaceSetField(fields, "[�����o�敪]", ToInt(meig_rec["�����o�敪"]));
        }
    }

    if (!remained_id && tare_w < 1){
		// ���ڌv�ʂ����v�ʂłȂ��ꍇ

		keiryo_no = DM->GetTempNo(place_id_);

		fields << NsField("[�`�[No]",    keiryo_no)
			   << NsField("[1��ڏd��]", cur_weight_[tag])
			   << NsField("[�v�ʓ���1]", now)
			   << NsField("[�����敪]",  0)
			   << NsField("[�쐬����]",  now)
			   ;

	}else{
		print = true;

		Currency weight1, weight2, net;

		int tani_code = DM->GetKanzanCode(toku_id, meig_id);
		tani_id = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tani_code, "�P��ID"));

		if (remained_id){
			// ���ڌv��

			NsRecordSet remained_set;
			if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(remained_id), remained_set)){

				DM->Log(post_name_[tag], "�ؗ��f�[�^���o���s�i�Ԕ�:" + IntToStr(car_no) + "�j", 2);
                NotifyForm->HeaderPanel->Caption = post_name_[tag];
				NotifyForm->Notify("�ؗ��f�[�^�̌Ăяo���Ɏ��s���܂���:" + IntToStr(card.id), false, 10000);

				on_error_[tag] = true;

				ad85_params_[tag].lamp = AD4385Lamp(false, false, true);
				PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
				return;
			}

			weight1 = ToCurrency(SET_TOP(remained_set)["1��ڏd��"]);
			weight2 = cur_weight_[tag];
		}else{
			// ���v��

			fields << NsField("[1��ڏd��]", tare_w)
				   //<< NsField("[�v�ʓ���1]", )
				   ;
			weight1 = tare_w;
			weight2 = cur_weight_[tag];
		}

		net = weight1 - weight2;
		if (net < 1) net *= -1;

		if (net > ToCurrency(card_rec["�ő�ύڗ�"]) && ToCurrency(card_rec["�ő�ύڗ�"]) > 0){
			DM->Log(post_name_[tag], "�ő�ύڗʂɑ΂���ߐύځi�Ԕ�:" + IntToStr(car_no) + "�j", 1);
            NotifyForm->HeaderPanel->Caption = post_name_[tag];
			NotifyForm->Notify("�ő�ύڗʂɑ΂���ߐύڂł�: " + IntToStr(car_no), false, 30000);

			on_error_[tag] = true;

			ad85_params_[tag].lamp = AD4385Lamp(false, false, true);
			PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
			return;
		}

		keiryo_no = DM->GetKeiryoNo(place_id_, date);

		///// �d�ʒ�����
    	Currency adj_per = 0;
	    int adj_weight   = 0;

		adj_per    = ToCurrency(DM->DBI.Lookup("M_�i��", "�i��ID", meig_id, "�d�ʒ�����"));
		if (adj_per != 0){
		    adj_per   /= 100;

		    ///// �����[�������敪�̎擾
    		int cnv_div = -1;

		    if (!toku_rec.empty()){
    		    if (!IsNull(toku_rec["�����[�������敪"]))
        		    cnv_div = ToInt(toku_rec["�����[�������敪"]);
		    }
    		if (cnv_div == -1)
        		cnv_div = ToInt(DM->CFG["�����[�������敪"]);

	   	    adj_weight = ExtendedRound(Currency(net) * adj_per, ToInt(DM->CFG["�����[����������"]), cnv_div);

            net -= adj_weight;
	    }

		fields << NsField("[�`�[No]",    keiryo_no)
			   << NsField("[2��ڏd��]", weight2)
			   << NsField("[�v�ʓ���2]", now)
	    	   << NsField("[������]",    adj_per)
               << NsField("[�����d��]",  adj_weight)
			   << NsField("[�����d��]",  net)
			   << NsField("[�P��ID]",    tani_id)
			   << NsField("[�����敪]",  1)
			   ;

        //////////////////////////////////////////////////////////////////////
        // ��������z���̌v�Z

		Currency quantity;
		if (tani_id == 3)
			quantity = Currency(net);
		else
			quantity = Currency(net) / Currency(1000);
		Currency cnv_ratio = DM->GetKanzan(toku_id, meig_id, tani_id);

      	///// ���Z�[�������敪�̎擾
        int cnv_div = -1;

      	if (!toku_rec.empty()){
       		if (!IsNull(toku_rec["���Z�[�������敪"]))
       			cnv_div = ToInt(toku_rec["���Z�[�������敪"]);
		}
       	if (cnv_div == -1)
       		cnv_div = ToInt(DM->CFG["���Z�[�������敪"]);
       	/////

       	if (cnv_ratio == 0){
       		quantity = ExtendedRound(quantity,             ToInt(DM->CFG["���Z�[����������"]), cnv_div);
       	}else{
       		quantity = ExtendedRound(quantity / cnv_ratio, ToInt(DM->CFG["���Z�[����������"]), cnv_div);
       	}

        fields << NsField("[����]", quantity);

       	if (ToBit(DM->CFG["�P���g�p�敪"])){

            Currency tanka = DM->GetTanka(toku_id, meig_id, item1_id, item2_id, tani_id);
            int amount, tax;

        	///// ���z�[�������敪�̎擾
        	int amount_div = -1;

        	if (!toku_rec.empty()){
        		if (!IsNull(toku_rec["���z�[�������敪"]))
        			amount_div = ToInt(toku_rec["���z�[�������敪"]);
        	}
        	if (amount_div == -1)
        		amount_div = ToInt(DM->CFG["���z�[�������敪"]);
        	/////

        	amount = ExtendedRound(quantity * tanka, 0, amount_div);

        	Currency tax_rate = DM->GetSalesTax();			// ����ŗ�

        	///// ����Œ[�������敪�̎擾
        	int tax_div = -1;

        	if (!toku_rec.empty()){
        		if (!IsNull(toku_rec["����Œ[�������敪"]))
        			tax_div = ToInt(toku_rec["����Œ[�������敪"]);
        	}
        	if (tax_div == -1)
        		tax_div = ToInt(DM->CFG["����Œ[�������敪"]);
        	/////

        	tax = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

            fields << NsField("[�P��]",         tanka)
            	   << NsField("[���z]",         amount)
				   << NsField("[����Ŋz]",     tax)
                   << NsField("[�`�[����Ŋz]", tax)
                   ;
       	}
    }

    DM->ADOConnection->BeginTrans();

    if (remained_id){
        // ���ڌv��

        DM->DBI.Update("D_�v��", "�v��ID", remained_id, fields);

        DM->Log(post_name_[tag], "�v�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);

        keiryo_id = remained_id;
    }else{
        // ���ڌv�ʂ܂��͈��v��

        DM->DBI.Insert("D_�v��", fields);

		if (tare_w < 1){
			DM->Log(post_name_[tag], "���ڌv�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);
		}else{
			// ���v�ʂɂ��v�ʊ���
			DM->Log(post_name_[tag], "���v�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);
		}

        keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
	}

    DM->ADOConnection->CommitTrans();

    //////////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        DM->Log(post_name_[tag], AnsiString("�o�^����O�i�J�[�h�ԍ�:") + IntToStr(card.id) + "�j: " + e.Message, 2);
        NotifyForm->HeaderPanel->Caption = post_name_[tag];
        NotifyForm->Notify("�o�^���ɃG���[���������܂���:" + IntToStr(card.id), false, 10000);

		on_error_[tag] = true;

		ad85_params_[tag].lamp = AD4385Lamp(false, false, true);
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
		return;
    }
    //////////

    ScaleForm_[tag]->ShowRecord(keiryo_id);

	if (print){
    	int print_denpyo = ToString(DM->CFG["�����v�ʎ��`�[���s"]).ToIntDef(1);	// 2012.10.29 �ǉ�
		if (print_denpyo)
			PrintKeiryoData(tag, keiryo_id);

        int print_copy = ToInt(DM->CFG["�����v�ʎ��T���`�[���s"]);
        if (print_copy)
            PrintCopy(keiryo_id);
    }

	// ���������v��_��
	ad85_params_[tag].lamp = AD4385Lamp(false, true, false);
	PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
	ad85_params_[tag].beep_len = 5;
	PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmBeep, (LPARAM)(&(ad85_params_[tag])));

	on_wait_exit_[tag] = true;	// �ގԑ҂����
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385CardReverse(int tag)
{
	/*** �J�[�h�t�}���C�x���g ***/
    DM->Log(post_name_[tag], "�J�[�h�t�}��", 0);

	if (IsThreadActive(tag)){
		ad85_params_[tag].lamp = AD4385Lamp(false, false, true);
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
		ad85_params_[tag].beep_len = 5;
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmBeep, (LPARAM)(&(ad85_params_[tag])));
	}

    NotifyForm->HeaderPanel->Caption = post_name_[tag];
    NotifyForm->Notify("�J�[�h���t�ɑ}������܂���", false, 10000);

	reversed_[tag] = true;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385CardOut(int tag)
{
	/*** �J�[�h�������C�x���g ***/

	if (reversed_[tag] || on_error_[tag]){	// �t�}���A�������̓f�[�^�G���[�̏ꍇ
		if (!on_weighing_[tag]){
			ad85_params_[tag].lamp = AD4385Lamp(false, false, false);
		}else{
			if (on_wait_exit_[tag])			// �~�ԑ҂�
				ad85_params_[tag].lamp = AD4385Lamp(false, true, false);
			else
				ad85_params_[tag].lamp = AD4385Lamp(true, false, false);
		}
		if (IsThreadActive(tag))
			PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmLamp, (LPARAM)(&(ad85_params_[tag])));
	}

	reversed_[tag] = false;
	on_error_[tag] = false;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PowerOn(int tag)
{
    DM->Log(post_name_[tag], "�Z���t�e�X�g OK", 0);

    if (ErrorForm->Visible)
        ErrorForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PowerNg(int tag)
{
    DM->Log(post_name_[tag], "�Z���t�e�X�g NG", 2);

    ErrorForm->TitlePanel->Caption = post_name_[tag] + " ���ُ��Ԃł�";
    ErrorForm->TextMemo->Lines->Clear();
    ErrorForm->TextMemo->Lines->Text = "�J�[�h��}�������܂ܓd������ꂽ\r\n"
                                       "���邢�̓J�[�h�}����������Ă���Ǝv���܂��B\r\n"
                                       "\r\n"
                                       "�J�[�h�}������|�����A������x�d�������Ȃ����Ă��������B\r\n";
                                       "�������Ȃ��ꍇ�͌̏Ⴊ�l�����܂��̂ŁA���₢���킹���������B";
    ErrorForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PrinterAbnormal(int tag)
{
    DM->Log(post_name_[tag], "�v�����^�ُ�", 2);

    NotifyForm->HeaderPanel->Caption = post_name_[tag];
    NotifyForm->Notify("����|�X�g�̃v�����^���ُ퓮�삵�Ă��܂�", false, 10000);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PaperExist(int tag)
{
    DM->Log(post_name_[tag], "�p������", 0);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385NoPaper(int tag)
{
    DM->Log(post_name_[tag], "�p���Ȃ�", 1);

    NotifyForm->HeaderPanel->Caption = post_name_[tag];
    NotifyForm->Notify("����|�X�g�̓`�[�p�������Ȃ��Ȃ��Ă��܂�", true, 60000);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PrintAck(int tag)
{
    DM->Log(post_name_[tag], "�󎚊m�F", 0);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385Keiryo(int tag)
{
    DM->Log(post_name_[tag], "�����v��", 0);

	ForceWeighing(tag);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385NameRequired(int tag, AD4385RequiredInfo *info)
{
    DM->Log(post_name_[tag], "���O�v��", 0);

    char name_buff[30];
    AnsiString text;

    AnsiString key;
    if (info->item_no == 1){
        key = "AD4385 ���ڂP";
    }else if (info->item_no == 2){
        key = "AD4385 ���ڂQ";
    }else if (info->item_no == 3){
        key = "AD4385 ���ڂR";
    }else if (info->item_no == 4){
        key = "AD4385 ���ڂS";
    }else{
		text = "             ";
        wsprintf(name_buff, "%-28s", text.SubString(1, 28).c_str());
        info->reply = name_buff;
        return;
    }

    // [CFG] AD4385 �̍��ڂP�`�S�ɑΉ����� ScM �̃}�X�^���Q��
    int master_no = ToInt(DM->CFG[key]);
    switch (master_no){
    case 1:
		text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", info->item_code, "���Ӑ旪��"));
		break;
	case 2:
		text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", info->item_code, "����1����"));
		break;
	case 3:
        text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", info->item_code, "����2����"));
        break;
	case 4:
		text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", info->item_code, "�i�ڗ���"));
		break;
	default:
		break;
	}
	if (text.IsEmpty())
		text = "             ";

    wsprintf(name_buff, "%-28s", text.SubString(1, 28).c_str());
    info->reply = name_buff;
}
//---------------------------------------------------------------------------
bool __fastcall TAD4385PostForm::IsThreadActive(int tag)
{
	return thread_[tag] ? true : false;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::CreatePrintImage(PrintImage& image, NsRecord& record)
{
	image.clear();

	char buff[256];
	int date;

	image.push_back("_");

	// ���t�A�`�[�ԍ�
	date = ToInt(record["�v�ʓ�"]);
	wsprintf(buff, "   No.%3d  %04d.%02d.%02d", ToInt(record["�`�[No"]), date / 10000, (date % 10000) / 100, date % 100);
	image.push_back(buff);
	// �Ԕ�
	wsprintf(buff, "   %5d", ToInt(record["�Ԕ�"]));
	image.push_back(buff);

    AnsiString item_order = ToString(DM->CFG["�h�b�g�`�[���ڏ�"]);
    int no;
    for (int i = 1; i <= 4; i++){
        if (item_order.IsEmpty()){
            image.push_back("_");
            continue;
        }
        no = item_order.SubString(1, 1).ToIntDef(0);
        item_order.Delete(1, 1);

        if (no == 1){
            // ���Ӑ�
            if (ToInt(record["���Ӑ�R�[�h"])){
            	wsprintf(buff, "   %5d %s", ToInt(record["���Ӑ�R�[�h"]), ToString(record["���Ӑ旪��"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }else if (no == 2){
        	// ����1
            if (ToInt(record["����1�R�[�h"])){
            	wsprintf(buff, "   %5d %s", ToInt(record["����1�R�[�h"]), ToString(record["����1����"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }else if (no == 3){
        	// ����2
            if (ToInt(record["����2�R�[�h"])){
            	wsprintf(buff, "   %5d %s", ToInt(record["����2�R�[�h"]), ToString(record["����2����"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }else if (no == 4){
        	// �i��
            if (ToInt(record["�i�ڃR�[�h"])){
            	wsprintf(buff, "   %5d %s", ToInt(record["�i�ڃR�[�h"]), ToString(record["�i�ڗ���"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }
        image.push_back(buff);
    }

    /*
	// ���Ӑ�
    if (ToInt(record["���Ӑ�R�[�h"])){
    	wsprintf(buff, "   %5d %s", ToInt(record["���Ӑ�R�[�h"]), ToString(record["���Ӑ旪��"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
	image.push_back(buff);
	// �i��
    if (ToInt(record["�i�ڃR�[�h"])){
    	wsprintf(buff, "   %5d %s", ToInt(record["�i�ڃR�[�h"]), ToString(record["�i�ڗ���"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
	image.push_back(buff);
	// ����1
    if (ToInt(record["����1�R�[�h"])){
    	wsprintf(buff, "   %5d %s", ToInt(record["����1�R�[�h"]), ToString(record["����1����"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
	image.push_back(buff);
	// ����2
    if (ToInt(record["����2�R�[�h"])){
    	wsprintf(buff, "   %5d %s", ToInt(record["����2�R�[�h"]), ToString(record["����2����"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
	image.push_back(buff);
    */

	int gross, tare;
    int gross_time = 0;
    int tare_time  = 0;
    Currency weight1, weight2;
    TDateTime dt;

    weight1 = ToCurrency(record["1��ڏd��"]);
    weight2 = ToCurrency(record["2��ڏd��"]);

    if (weight1 > weight2){
        gross = weight1;
        tare  = weight2;

        try{
            dt = TDateTime(record["�v�ʓ���1"]);
            gross_time = dt.FormatString("hhnn").ToInt();
        }catch(...){}
        try{
            dt = TDateTime(record["�v�ʓ���2"]);
            tare_time  = dt.FormatString("hhnn").ToInt();
        }catch(...){}
    }else{
        gross = weight2;
        tare  = weight1;

        try{
            dt = TDateTime(record["�v�ʓ���2"]);
            gross_time = dt.FormatString("hhnn").ToInt();
        }catch(...){}
        try{
            dt = TDateTime(record["�v�ʓ���1"]);
            tare_time  = dt.FormatString("hhnn").ToInt();
        }catch(...){}
	}

    bool print_time = ToBit(DM->CFG["�����v�ʎ��Ԉ�"]);

	// ���d��
	if (gross_time && print_time){
		wsprintf(buff, "      %02d:%02d  %7skg", gross_time / 100, gross_time % 100,
							FormatFloat("###,##0", gross).c_str());
	}else{
		wsprintf(buff, "             %7skg", FormatFloat("###,##0", gross).c_str());
	}
	image.push_back(buff);

	// ��ԏd��
	if (tare_time && print_time){
		wsprintf(buff, "      %02d:%02d  %7skg", tare_time / 100, tare_time % 100,
							FormatFloat("###,##0", tare).c_str());
	}else{
		wsprintf(buff, "             %7skg", FormatFloat("###,##0", tare).c_str());
	}
	image.push_back(buff);

	// �����d��
	wsprintf(buff, "             %7skg", FormatFloat("###,##0", ToInt(record["�����d��"])).c_str());
	image.push_back(buff);

	int gk_div = ToInt(record["���|�敪"]);
	int mon    = ToInt(record["���z"]) + ToInt(record["����Ŋz"]);

	// ���z
	if (gk_div == 2 && mon){
		wsprintf(buff, "           %9s�~", FormatFloat("#,###,##0", mon).c_str());
	}else{
		lstrcpy(buff, "_");
	}
	image.push_back(buff);

    image.push_back("END");
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::PrintKeiryoData(int tag, int keiryo_id)
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
	if (!DM->DBI.GetRecordSet(sql, set))
		return;

	if (IsThreadActive(tag)){
		CreatePrintImage(ad85_params_[tag].image, SET_TOP(set));
		PostThreadMessage(thread_id_[tag], UM_AD4385_COMMAND, cmPrint, (LPARAM)(&(ad85_params_[tag])));
	}
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::PrintCopy(int keiryo_id)
{
	int slip_type   = ToInt(DM->CFG["�`�[���s�v�����^"]);

    /***************************************************/
    /* ���ӁF �T���`�[�̏ꍇ�́A����͂̂ق��̎��Ԉ󎚐ݒ�����Ă��� */

    bool print_time = ToBit(DM->CFG["���Ԉ󎚏����敪"]);

	if (slip_type == 1){
		// ���[�U�[

		if (!LaserSlipPrintForm->Print(keiryo_id, !print_time))
			return;
			
	}else if (slip_type == 2){
		// �h�b�g

        if (!DotSlipPrintForm->Print(keiryo_id, !print_time))
            return;

	}else{
		// nothing to do
	}
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ForceWeighing(int tag)
{
	OnExitWeighing(tag);
	cur_weight_[tag] = 0;
}
//---------------------------------------------------------------------------

