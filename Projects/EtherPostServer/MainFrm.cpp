//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "DMFrm.h"
#include "ErrorFrm.h"
#include "NotifyFrm.h"
#include "DotSlipPrintFrm.h"
#include "LaserSlipPrintFrm.h"
#include "DisplayFrm.h"
#include "SystemID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"

NsRecordSet global_set;

TEtherPostForm *EtherPostForm;
//---------------------------------------------------------------------------
__fastcall TEtherPostForm::TEtherPostForm(TComponent* Owner)
	: TForm(Owner), cur_weight_(0), old_weight_(0), cur_wi_status_(wsOther), io_thread_(0),
		rfid_thread_(0), last_card_no_(0), printer_thread_(0), rfid_error_(false), wi_error_(false)
{
	cur_weight_     = 0;
	old_weight_     = 0;
	on_weighing_    = false;
	reversed_       = false;
	on_error_       = false;
	limit_over_     = false;
	on_printing_    = false;
	on_wait_exit_   = false;

	ready_sw_    = chOff;
	card_sw_     = chOff;
	exit_sw_     = chOff;
	overload_sw_ = chOff;
	buzzer_sw_   = chOff;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::FormCreate(TObject *Sender)
{
	Caption = "����|�X�g����";

	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�[INI]

	if (!DM->Init()){
		PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }

	/*
	///////////////////////////////////////////////
	// IO
	try{
		IO_.SetHandler(OnIOInput, OnIOResponse, OnIOError);
		IO_.Open(ToString(DM->INI["IO::Address"]));
	}catch(Exception& e){
		Application->MessageBox(("IO���j�b�g�ɐڑ��ł��܂��� - " + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP | MB_TOPMOST);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	*/

	//ApplyConfig();



    ThreadCreateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::ThreadCreateTimerTimer(TObject *Sender)
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
	// DIOM �ʐM�X���b�h�̍쐬 [INI]

	io_thread_  = new TioMirrorThread(true, Handle, ToString(DM->INI["IO::Address"]));
	io_thread_->FreeOnTerminate = false;
	io_thread_->Resume();

	///////////////////////////////////////////////
	// RFID �ʐM�X���b�h�̍쐬 [INI]

	int rfid_port = ToInt(DM->INI["RFID::WeighingCommPort"]);
	rfid_thread_  = new THF04Thread(true, Handle, rfid_port);
    rfid_thread_->FreeOnTerminate = false;
    rfid_thread_->Resume();

	///////////////////////////////////////////////
	// �d�ʎ�M
	try{
		// [INI] Weighing::WIPort
		ClientSocket->Port = ToInt(DM->INI["Weighing::WIPort"]);
		// [INI] Weighing::WIServer
		ClientSocket->Host = ToString(DM->INI["Weighing::WIServer"]);

		if (ClientSocket->Active)
			ClientSocket->Close();
		ClientSocket->Open();

	}catch(Exception& e){
		AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
		Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONSTOP | MB_TOPMOST);

        wi_error_ = true;
        UpdateWeighingState();
	}
	SocketReopenTimer->Enabled = true;

	weighing_border_ = ToInt(DM->INI["Weighing::SoundBorder"]);

	int port;

	///////////////////////////////////////////////
	// NP3411
	port = ToInt(DM->INI["OuterPrinter::Port"]);
    cfginfo_.customer = DM->TrimSpace(ToString(DM->CFG["���Ӑ�}�X�^����"]));
    cfginfo_.items    = DM->TrimSpace(ToString(DM->CFG["�i�ڃ}�X�^����"]));
    cfginfo_.item1    = DM->TrimSpace(ToString(DM->CFG["����1�}�X�^����"]));
    cfginfo_.item2    = DM->TrimSpace(ToString(DM->CFG["����2�}�X�^����"]));
    cfginfo_.use_toku  = ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"]);
    cfginfo_.use_items = ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"]);
    cfginfo_.use_item1 = ToBit(DM->CFG["����1�}�X�^�g�p�敪"]);
    cfginfo_.use_item2 = ToBit(DM->CFG["����2�}�X�^�g�p�敪"]);
	if (port){                               
		printer_thread_ = new TNP3411Thread(false, port, ToString(DM->INI["OuterPrinter::Def"]), Handle, cfginfo_, ToInt(DM->INI["OuterPrinter::PrintCopy"]));
	}else{
		Application->MessageBox("�O���v�����^�Ƃ̒ʐM�͒�~���Ă��܂�", "�d�ʕ\����", MB_OK | MB_ICONWARNING);
	}

	///////////////////////////////////////////////
	// �d�ʕ\����
	port = ToInt(DM->INI["F0399::Port"]);
	if (port){
		if (!indicator_.Initialize(port))
			Application->MessageBox("�d�ʕ\����Ƃ̒ʐM���J�n�ł��܂���", "�d�ʕ\����", MB_OK | MB_ICONWARNING);
	}else{
		Application->MessageBox("�d�ʕ\����Ƃ̒ʐM�͒�~���Ă��܂�", "�d�ʕ\����", MB_OK | MB_ICONWARNING);
	}
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (indicator_.IsActive())
		indicator_.Display(" ");

	if (io_thread_)
		io_thread_->Terminate();
	if (io_thread_)
		io_thread_->WaitFor();
	if (io_thread_)
		delete io_thread_;


	if (printer_thread_)
		printer_thread_->Terminate();
	if (printer_thread_)
		printer_thread_->WaitFor();
	if (printer_thread_)
		delete printer_thread_;

	if (rfid_thread_)
		rfid_thread_->Terminate();
	if (rfid_thread_)
		rfid_thread_->WaitFor();
	if (rfid_thread_)
		delete rfid_thread_;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnEndSession(TMessage& message)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("������I��������ƁA����|�X�g����؎g�p�ł��Ȃ��Ȃ�܂�\r\n"
                                "��낵���ł����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST)
                == IDYES){
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::SocketReopenTimerTimer(TObject *Sender)
{
	if (ClientSocket->Active)
		return;

	try{
		// [INI] Weighing::WIPort
		ClientSocket->Port = ToInt(DM->INI["Weighing::WIPort"]);
		// [INI] Weighing::WIServer
		ClientSocket->Host = ToString(DM->INI["Weighing::WIServer"]);

		ClientSocket->Open();
	}catch(Exception& e){
		//AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
		//Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
		;
        wi_error_ = true;
		UpdateWeighingState();
	}
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::ClientSocketError(TObject *Sender,
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
	ClientSocket->Close();
    old_weight_ = 0;
    cur_weight_ = 0;
    OnExitWeighing();

    wi_error_ = true;
    UpdateWeighingState();

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
	int index;
	AnsiString weight = Socket->ReceiveText();

	int len = weight.Length();
	if (len < 4)					return;
	if (weight[len - 1] != '\r')	return;
	if (weight[len] != '\n')		return;
	switch (weight[1]){
	case 'S':	cur_wi_status_ = wsStable;      break;
	case 'U':	cur_wi_status_ = wsUnstable;    break;
	case 'O':	cur_wi_status_ = wsOther;       break;
	default:
		return;
	}

	weight.Delete(1, 1);	// �X�e�[�^�X�L�����N�^�̍폜
	weight.Delete(weight.Length() - 1, 2);	// ������ \r\n ���폜
	Currency tmp_weight;
	try{

		tmp_weight = Currency(weight);

	}catch(...){return;}

    wi_error_ = false;
    UpdateWeighingState();

	old_weight_ = cur_weight_;
	cur_weight_ = tmp_weight;

	if (indicator_.IsActive())
		indicator_.Display(IntToStr(cur_weight_).c_str());

	if (old_weight_ < weighing_border_ && cur_weight_ >= weighing_border_){
		OnEnterWeighing();
	}else if ((old_weight_ >= weighing_border_) && (cur_weight_ < weighing_border_)){
		OnExitWeighing();
	}
}
//---------------------------------------------------------------------------
/**
 * Implementation of Weighing Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnEnterWeighing()
{
	/*** �v�ʊJ�n(�X�P�[������) ***/

	on_weighing_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnExitWeighing()
{
	/*** �v�ʏI��(�~��) ***/

	if (DisplayForm->Visible)
		DisplayForm->Close();

	card_sw_     = chOff;
	exit_sw_     = chOff;
	overload_sw_ = chOff;
	buzzer_sw_   = chOff;
	OutputCh();

	on_weighing_  = false;
	on_wait_exit_ = false;	// �ގԑ҂���Ԃ��N���A
	last_card_no_ = 0;
    on_error_ = false;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::PostWeighing()
{
    if (last_card_no_ < 1){
        DM->Log("����|�X�g", "�J�[�h�����Ŋm�F�{�^������", 1);

		return;
	}

	int card_no = last_card_no_;
	if (!on_weighing_)
		return;
	if (on_printing_)
		return;
	if (on_wait_exit_)
		return;
	if (on_error_)
		return;

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
		if (cur_weight_ < weighing_border_)
			return;
	}

    AnsiString sql;
	TDateTime now(Now());
	int date = now.FormatString("yyyymmdd").ToInt();
    bool print = false;

	int toku_cd, item1_cd, item2_cd, meig_cd;
	int toku_id, item1_id, item2_id, meig_id, tani_id;
	NsRecord toku_rec, item1_rec, item2_rec, meig_rec;

	int car_no, keiryo_no, keiryo_id;

	int cmp_kbn = 0;

	//////////
	try{
	//////////

	// �ԗ����擾
	NsRecord    card_rec;
	if (!DM->GetCardInfo(card_no, card_rec)){
		DM->Log("����|�X�g", "���o�^�ԗ��ɂ��v�ʒ��~�i�J�[�h�ԍ�:" + IntToStr(card_no) + "�j", 1);
		NotifyForm->Notify("���o�^�ԗ��ł�: " + IntToStr(card_no), false, 10000);;

		// �ԗ����ڂ����܂܂ł����Ȃ����߁A�G���[�����Ƃ͂��Ȃ�
		// on_error_ = true;
		return;
	}

    car_no   = ToInt(card_rec["�Ԕ�"]);

    ///// �D��x�i��j�J�[�h���
    toku_id  = ToInt(card_rec["���Ӑ�ID"]);
    meig_id  = ToInt(card_rec["�i��ID"]);
    item1_id = ToInt(card_rec["����1ID"]);
    item2_id = ToInt(card_rec["����2ID"]);
    DM->GetViewRec("���Ӑ�", toku_id,  toku_rec);
    DM->GetViewRec("�i��",   meig_id,  meig_rec);
    DM->GetViewRec("����1",  item1_id, item1_rec);
    DM->GetViewRec("����2",  item2_id, item2_rec);

    if (cur_weight_ > ToCurrency(card_rec["�ԗ����d��"]) && ToCurrency(card_rec["�ԗ����d��"]) > 0){
        DM->Log("����|�X�g", "�ԗ����d�ʂɑ΂���ߐύځi�Ԕ�:" + IntToStr(car_no) + "�j", 1);
        NotifyForm->Notify("�ԗ����d�ʂɑ΂���ߐύڂł�: " + IntToStr(car_no), false, 30000);

		on_error_     = true;
		on_wait_exit_ = true;

		overload_sw_ = true;
		buzzer_sw_   = true;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = false;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = true;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = false;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = true;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = false;
		OutputCh();

		return;
    }
    
   	NsFieldSet fields;

  	fields
        << NsField("[�v�ʓ�]",     date)
        << NsField("[���_ID]",     place_id_)
        << NsField("[�sNo]",       1)
		<< NsField("[�ԗ�ID]",     ToInt(card_rec["�ԗ�ID"]))
        << NsField("[���Ӑ�ID]",   toku_id)
		<< NsField("[���Ӑ於��]", ToString(toku_rec["���Ӑ於��"]))
		<< NsField("[����1ID]",    item1_id)
        << NsField("[����1����]",  ToString(item1_rec["����1����"]))
        << NsField("[����2ID]",    item2_id)
        << NsField("[����2����]",  ToString(item2_rec["����2����"]))
        << NsField("[�i��ID]",     meig_id)
        << NsField("[�i�ږ���]",   ToString(meig_rec["�i�ږ���"]))
        << NsField("[�����o�敪]", ToInt(meig_rec["�����o�敪"]))
        << NsField("[�X�V����]",   now)
       	;

    DM->ADOConnection->BeginTrans();

    Currency tare_w = ToCurrency(card_rec["��ԏd��"]);
    int remained_id = DM->GetRemainedKeiryoID(place_id_, ToInt(card_rec["�ԗ�ID"]));

    if (!remained_id && tare_w < 1){
		// ���ڌv�ʂ����v�ʂłȂ��ꍇ �� ���ڌv�ʁ^���v��

        print = false;

		keiryo_no = DM->GetTempNo(place_id_);

		fields << NsField("[�`�[No]",    keiryo_no)
			   << NsField("[1��ڏd��]", cur_weight_)
			   << NsField("[�v�ʓ���1]", now)
			   << NsField("[�����敪]",  0)
			   << NsField("[�쐬����]",  now)
			   ;
        cmp_kbn = 0;

	}else{
		print = true;

		Currency weight1, weight2, net;
		int tani_code = DM->GetKanzanCode(toku_id, meig_id);
		tani_id   = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tani_code, "�P��ID"));

		if (remained_id){
			// ���ڌv��

			NsRecordSet remained_set;
			if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(remained_id), remained_set)){

				DM->Log("����|�X�g", "�ؗ��f�[�^���o���s�i�Ԕ�:" + IntToStr(car_no) + "�j", 2);
				NotifyForm->Notify("�ؗ��f�[�^�̌Ăяo���Ɏ��s���܂���:" + IntToStr(car_no), false, 10000);

				on_error_ = true;

				buzzer_sw_   = true;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = false;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = true;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = false;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = true;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = false;
				OutputCh();

				return;
			}

			weight1 = ToCurrency(SET_TOP(remained_set)["1��ڏd��"]);
			weight2 = cur_weight_;

		}else{
			// ���v��

			fields << NsField("[1��ڏd��]", tare_w)
                   << NsField("[�쐬����]",  now)
				   //<< NsField("[�v�ʓ���1]", )    // ���v�ʂ��Ⴏ���v�ʓ���1�͂Ȃ�
				   ;

			weight1 = tare_w;
			weight2 = cur_weight_;
		}

		net = weight1 - weight2;
		if (net < 1) net *= -1;

		if (net > ToCurrency(card_rec["�ő�ύڗ�"]) && ToCurrency(card_rec["�ő�ύڗ�"]) > 0){
			DM->Log("����|�X�g", "�ő�ύڗʂɑ΂���ߐύځi�Ԕ�:" + IntToStr(car_no) + "�j", 1);
			NotifyForm->Notify("�ő�ύڗʂɑ΂���ߐύڂł�: " + IntToStr(car_no), false, 30000);

			on_error_     = true;
			on_wait_exit_ = true;

			overload_sw_ = true;
			OutputCh();

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

        ReplaceSetField(fields, "[�`�[No]",   keiryo_no);
        ReplaceSetField(fields, "[�����敪]", 1);

		fields << NsField("[2��ڏd��]", weight2)
			   << NsField("[�v�ʓ���2]", now)
	    	   << NsField("[������]",    adj_per)
               << NsField("[�����d��]",  adj_weight)
			   << NsField("[�����d��]",  net)
			   << NsField("[�P��ID]",    tani_id)
			   ;

        cmp_kbn = 1;

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

    if (remained_id){
        // ���ڌv��

        DM->DBI.Update("D_�v��", "�v��ID", remained_id, fields);

        DM->Log("����|�X�g", "�v�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);

        keiryo_id = remained_id;

    }else{
		// ���ڌv�ʂ܂��͈��v��

        DM->DBI.Insert("D_�v��", fields);

		if (tare_w < 1){
			DM->Log("����|�X�g", "���ڌv�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);

            keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}else{
			// ���v�ʂɂ��v�ʊ���
			DM->Log("����|�X�g", "���v�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);

			keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}
	}

    DM->ADOConnection->CommitTrans();

    //////////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        DM->Log("����|�X�g", AnsiString("�o�^����O�i�J�[�h�ԍ�:") + IntToStr(card_no) + "�j: " + e.Message, 2);
        NotifyForm->Notify("�o�^���ɃG���[���������܂���:" + IntToStr(card_no), false, 10000);

		on_error_ = true;

		// todo error

		return;
    }
    //////////

	if (cmp_kbn == 1){       // �v�ʊ���
	}else{                   //
	}

	on_wait_exit_ = true;	// �ގԑ҂����

	DisplayForm->ShowRecord(keiryo_id);

    // PrintCopy��0�̂Ƃ��͓`�[�o�͂��s��Ȃ�
    int use_print = ToInt(DM->INI["OuterPrinter::PrintCopy"]);

	if (print && use_print){
   		PrintKeiryoData(keiryo_id);

		int print_copy = ToInt(DM->CFG["�����v�ʎ��T���`�[���s"]);
		if (print_copy)
			PrintCopy(keiryo_id);
	}

	card_sw_   = false;
	exit_sw_   = true;
	buzzer_sw_ = true;
	OutputCh();

	BuzzerSwitchTimer->Interval = 1000;
	BuzzerSwitchTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnConfirmButton()
{
	DM->Log("DEBUG", "�m�F�{�^��", 1);

	if (last_card_no_)
	    PostWeighing();
	else
		DM->Log("����|�X�g", "�J�[�h�����Ŋm�F�{�^������", 1);
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnResetButton()
{
	DM->Log("DEBUG", "���Z�b�g�{�^��", 1);


	ForceWeighing();
}
//---------------------------------------------------------------------------
/**
 * Implementation of NP3411 Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UMNiiAborted(TMessage& message)
{
	Application->MessageBox("�O���v�����^�̎g�p���ł��܂���", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("�O���v�����^", "�ʐM��~", 2);

	delete printer_thread_;
	printer_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UMNiiStatus(TMessage& message)
{
	NiiStatus status(*(reinterpret_cast<NiiStatus *>(message.LParam)));

    /*
        NiiStatus
        - comm_error
        - status
        - message

        status = -2
        �v�����^�X�e�[�^�X���擾�ł��܂���
        �󎚒����擾���邽��mdb�̗e�ʐߖ�̂��ߔ�\������

    */

	if (status.comm_error){
	   DM->Log("�O���v�����^", status.message, 1);
	}else if (status.status == -1){
       DM->Log("�O���v�����^", status.message, 1);
    }else{
        BF8 bf8;
        bf8.val = (char)(status.status);

        AnsiString msg;

        if (bf8.channels.ch1)
            msg = "���Ȃ�";
        if (bf8.channels.ch2)
            msg = "�w�b�h�J�o�[�I�[�v��";
        if (bf8.channels.ch3)
			msg = "���Ȃ�";
        if (bf8.channels.ch4)
            msg = "�w�b�h���x�ُ�܂��͔r�o�G���[";
        if (bf8.channels.ch5)
            msg = "�J�b�^�[�l��";

        if (!msg.IsEmpty()){
	       //DM->Log("�O���v�����^", status.message, 0);
            NotifyForm->Notify("�O���v�����^: " + msg, true, 30000);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UMNiiReboot(TMessage& message)
{
	DM->Log("�O���v�����^", "�ċN���v��", 1);
}
//---------------------------------------------------------------------------
/**
 * Implementation of RFID Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
	// Application->MessageBox("RFID���j�b�g�Ƃ̒ʐM���ł��܂���", Caption.c_str(),
	//		MB_OK | MB_ICONINFORMATION);


    if (!ErrorForm->Visible){
        ErrorForm->TitlePanel->Caption = "RFID���[�_�Ƃ̒ʐM���ł��܂���";
        ErrorForm->TextMemo->Lines->Clear();
		ErrorForm->TextMemo->Lines->Text = "RFID���[�_���g�p�ł��Ȃ����߁A�ʐM���s���܂���B\r\n"
                                           "\r\n"
                                           "ScaleManger �ݒ��񂪕ύX���ꂽ�\��������܂��B\r\n"
                                           "�܂��A�z���̕ύX���ł���������ꍇ������܂��B\r\n"
                                           "\r\n"
                                           "PC ���ċN�����Ă���肪�������Ȃ��ꍇ�́A���₢���킹���������B";
        ErrorForm->ShowModal();
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    bool is_fatal = message.WParam;

    DM->Log("����|�X�g(RFID)", status, is_fatal ? 2 : 1);

    if (is_fatal)
        NotifyForm->Notify(AnsiString("RFID���[�_:" + status), true, 20000);
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnRFIDTimeout(TMessage& message)
{
    rfid_error_ = static_cast<bool>(message.WParam);
    UpdateWeighingState();
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;
    int card_no = message.LParam;

	/*** �J�[�h���m ***/

    // �F�؃`�F�b�N
    if (!is_valid){
        DM->Log("����|�X�g", "�J�[�h�F�؃G���[", 1);
        NotifyForm->Notify("�V�X�e���O�̃J�[�h�����m���܂���", false, 10000);
        return;
    }
    // ����J�[�h�`�F�b�N
    if (card_no >= RFID::ADMIN_CARDS_ID){
        DM->Log("����|�X�g", "����p�J�[�h���m", 1);
        NotifyForm->Notify("����p�J�[�h�͂��̃V�X�e���Ŏg�p�ł��܂���", false, 10000);
        return;
    }

    DM->Log("����|�X�g", "�J�[�h���m", 0);

	if (card_no == last_card_no_)
		return;
		
    last_card_no_ = card_no;

	card_sw_ = true;
	OutputCh();
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::PrintKeiryoData(int keiryo_id)
{
	if (printer_thread_){
        AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID =" + ToString(keiryo_id);

        keiryo_set_.clear();
        print_set_.clear();

        if (!DM->DBI.GetRecordSet(sql, keiryo_set_)){
            DM->Log("������","���擾���s���܂���", 2);
            return;
        }else{
            //ShowMessage(ToString(SET_TOP(printer_set_)["�v��ID"]));
        }

        int print_info_id = DM->GetPrintInfo(keiryo_id);

        if (!print_info_id){
            DM->Log("�`�[���s", "�`�[��񂪐ݒ肳��Ă��܂���", 2);
            return;
        }

        sql = "SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(print_info_id);

        if (!DM->DBI.GetRecordSet(sql, print_set_)){
            DM->Log("�`�[���s", "�`�[��񂪖����ł�", 2);
            return;
        }


   		//PostThreadMessage(printer_thread_->ThreadID, UM_NII_PRINT, keiryo_id, 0);
        PostThreadMessage(printer_thread_->ThreadID, UM_NII_PRINT, (WPARAM)&keiryo_set_, (LPARAM)&print_set_);


    }
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::PrintCopy(int keiryo_id)
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
void __fastcall TEtherPostForm::ForceWeighing()
{
	OnExitWeighing();
	cur_weight_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UpdateWeighingState()
{
	bool old_ready = ready_sw_;

	if (wi_error_ || rfid_error_){
		ready_sw_ = false;
	}else{
		ready_sw_ = true;
	}

	if (old_ready != ready_sw_){
		Sleep(300);
		OutputCh();
	}
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOAborted(TMessage& message)
{
	Application->MessageBox("IO���j�b�g�Ƃ̒ʐM���ؒf����܂���", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("IO���j�b�g", "TCP�ʐM��~", 2);

	delete io_thread_;
	io_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	DM->Log("IO���j�b�g", status, 1);
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOInput(TMessage& message)
{
	Channels cur_channels((BYTE)(message.LParam));

	DM->Log("DEBUG", "���͌��m", 1);

    if (ToInt(DM->INI["IO::Invert"]) == 1){
	    if (cur_channels[ToInt(DM->INI["IO::ConfirmInCh"])] == chOff)
	    	OnConfirmButton();
    	if (cur_channels[ToInt(DM->INI["IO::ResetInCh"])] == chOff)
		    OnResetButton();
    }else{
	    if (cur_channels[ToInt(DM->INI["IO::ConfirmInCh"])] == chOn)
	    	OnConfirmButton();
	    if (cur_channels[ToInt(DM->INI["IO::ResetInCh"])] == chOn)
    		OnResetButton();
    }
}
//---------------------------------------------------------------------------
/*
void __fastcall TEtherPostForm::OnIOInput(const Channels& channels)
{
	Channels cur_channels(channels);

	if (last_inputs_.GetByteImage() != cur_channels.GetByteImage()){
		for (int i = 1; i <= 8; i++){
			if (cur_channels[i] == last_inputs_[i])
				cur_channels[i] = chNull;
		}

		if (cur_channels[ToInt(DM->INI["IO::ConfirmInCh"])] == chOff)
			OnConfirmButton();
		if (cur_channels[ToInt(DM->INI["IO::ResetInCh"])] == chOff)
			OnResetButton();

	}
	last_inputs_.SetByte(cur_channels.GetByteImage());
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOResponse(const AnsiString& message)
{
	// nothing to do
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOError(const AnsiString& message)
{
	InputTimer->Enabled = false;

	Application->MessageBox("IO���j�b�g�Ƃ̒ʐM���ؒf����܂���", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("IO���j�b�g", "TCP�ʐM��~", 2);
}
*/
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OutputCh()
{
	Channels outputs(8);
	outputs[ToInt(DM->INI["IO::ReadyOutCh"])]  = ready_sw_    ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::CardOutCh"])]   = card_sw_     ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::ExitOutCh"])]   = exit_sw_     ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::OverOutCh"])]   = overload_sw_ ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::BuzzerOutCh"])] = buzzer_sw_   ? chOn : chOff;

	if (io_thread_)
		PostThreadMessage(io_thread_->ThreadID, DIOM_OUTPUT, 0, outputs.GetByteImage());
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::BuzzerSwitchTimerTimer(TObject *Sender)
{
	BuzzerSwitchTimer->Enabled = false;

	buzzer_sw_ = !buzzer_sw_;
	OutputCh();
}
//---------------------------------------------------------------------------
