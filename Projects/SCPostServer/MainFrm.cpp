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
TSCPostForm *SCPostForm;
//---------------------------------------------------------------------------
__fastcall TSCPostForm::TSCPostForm(TComponent* Owner)
    : TForm(Owner), cur_weight_(0), old_weight_(0), cur_wi_status_(wsOther),
        rfid_thread_(0), fbi_handle_(INVALID_HANDLE_VALUE), out_channels_(16), dio_thread_(0),
        last_card_no_(0), rfid_error_(false), wi_error_(false)
{
    cur_weight_     = 0;
	old_weight_     = 0;
	on_weighing_    = false;
	reversed_       = false;
	on_error_       = false;
	limit_over_     = false;
	on_printing_    = false;
	on_wait_exit_   = false;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::FormCreate(TObject *Sender)
{
    Caption = "SC����|�X�g����";

	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�[INI]

	if (!DM->Init()){
		PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }

	///////////////////////////////////////////////
	// DIO�{�[�h�ɐڑ�

    // �r���̏ꍇ
    // fbi_handle_ = DioOpen(ToString(DM->INI["FBIDIO::Device"]).c_str(), 0);
    // ���L

    if (ToString(DM->INI["FBIDIO::Device"]).IsEmpty()){
    }else{
        fbi_handle_ = DioOpen(ToString(DM->INI["FBIDIO::Device"]).c_str(), FBIDIO_FLAG_SHARE);
        if (fbi_handle_ == INVALID_HANDLE_VALUE){
            Application->MessageBox("DIO�f�o�C�X�̃I�[�v���Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONSTOP | MB_TOPMOST);
    		PostMessage(Handle, WM_CLOSE, 0, 0);
            return;
        }
    }

	//ApplyConfig();

    ThreadCreateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ThreadCreateTimerTimer(TObject *Sender)
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
	// RFID �ʐM�X���b�h�̍쐬 [INI]

    int rfid_port = ToInt(DM->INI["RFID::WeighingCommPort"]);
	rfid_thread_  = new THF04Thread(true, Handle, rfid_port);
    rfid_thread_->FreeOnTerminate = false;
    rfid_thread_->Resume();

    ///////////////////////////////////////////////
    // DIO �X���b�h�̍쐬

    if (fbi_handle_ != INVALID_HANDLE_VALUE){
        dio_thread_ = new TFbiDioThread(true, Handle, fbi_handle_);
        dio_thread_->FreeOnTerminate = false;
        dio_thread_->Resume();
    }

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
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (dio_thread_){
        out_channels_.SetWord(0);
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
        Sleep(500);
    }
    if (dio_thread_)
        dio_thread_->Terminate();
    if (dio_thread_)
        dio_thread_->WaitFor();
    if (dio_thread_)
        delete dio_thread_;

	if (rfid_thread_)
		rfid_thread_->Terminate();
	if (rfid_thread_)
		rfid_thread_->WaitFor();
	if (rfid_thread_)
		delete rfid_thread_;

    if (fbi_handle_ != INVALID_HANDLE_VALUE)
        DioClose(fbi_handle_);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("������I��������ƁA����|�X�g����؎g�p�ł��Ȃ��Ȃ�܂�\r\n"
                                "��낵���ł����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST)
                == IDYES){
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::SocketReopenTimerTimer(TObject *Sender)
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
void __fastcall TSCPostForm::ClientSocketError(TObject *Sender,
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
    OnExitWeighing(0);

    wi_error_ = true;
    UpdateWeighingState();

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ClientSocketRead(TObject *Sender,
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

	if (old_weight_ < weighing_border_ && cur_weight_ >= weighing_border_){
        on_weighing_ = true;
        OnEnterWeighing(0);
	}else if ((old_weight_ >= weighing_border_) && (cur_weight_ < weighing_border_)){
        on_weighing_ = false;
        OnExitWeighing(0);
    }
}
//---------------------------------------------------------------------------
/**
 * Implementation of Weighing Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnEnterWeighing(int tag)
{
	/*** �v�ʊJ�n(�X�P�[������) ***/

    /*
    // [INI]
    out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOn;
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
    */
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnExitWeighing(int tag)
{
	/*** �v�ʏI��(�~��) ***/

    if (DisplayForm->Visible)
        DisplayForm->Close();

    out_channels_.SetWord(0);
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
        
    UpdateWeighingState();

	on_wait_exit_ = false;	// �ގԑ҂���Ԃ��N���A
    last_card_no_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnDIOStatus(TMessage& message)
{
    AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    DM->Log("SCPOST(DIO)", status, 1);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnDIOInput(TMessage& message)
{
    DM->Log("SCPOST(DIO)", "���͌��m", 0);

    Channels channels(16);
    channels.SetWord(message.LParam);

    // [INI]
    if (channels[ToInt(DM->INI["FBIDIO::CallInCh"])] == chOn){
        OnCallButtonDown();
    }
    if (channels[ToInt(DM->INI["FBIDIO::ResetInCh"])] == chOn){
        OnResetButtonDown();
    }
    if (channels[ToInt(DM->INI["FBIDIO::ConfirmInCh"])] == chOn){
        OnConfirmButtonDown();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnConfirmButtonDown()
{
    out_channels_[ToInt(DM->INI["FBIDIO::ExitOutCh"])]  = chOff;
    out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOff;
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

    if (last_card_no_ < 1){
        DM->Log("SCPOST", "�J�[�h�����Ŋm�F�{�^������", 1);

        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
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
    int max_detail_count;

    int cmp_kbn = 0;

    //////////
    try{
    //////////

    // �ԗ����擾
    NsRecord    card_rec;
    if (!DM->GetCardInfo(card_no, card_rec)){
        DM->Log("SCPOST", "���o�^�ԗ��ɂ��v�ʒ��~�i�J�[�h�ԍ�:" + IntToStr(card_no) + "�j", 1);
        NotifyForm->Notify("���o�^�ԗ��ł�: " + IntToStr(card_no), false, 10000);;

		// on_error_ = true;

        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
        Sleep(1000);
        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOff;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

    	return;
	}

    max_detail_count = ToInt(card_rec["�i�ڌ���"]);

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
        DM->Log("SCPOST", "�ԗ����d�ʂɑ΂���ߐύځi�Ԕ�:" + IntToStr(car_no) + "�j", 1);
        NotifyForm->Notify("�ԗ����d�ʂɑ΂���ߐύڂł�: " + IntToStr(car_no), false, 30000);

  		on_error_ = true;

        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::OverOutCh"])]  = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

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

				DM->Log("SCPOST", "�ؗ��f�[�^���o���s�i�Ԕ�:" + IntToStr(car_no) + "�j", 2);
				NotifyForm->Notify("�ؗ��f�[�^�̌Ăяo���Ɏ��s���܂���:" + IntToStr(car_no), false, 10000);

				on_error_ = true;

                //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
                out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
                if (dio_thread_)
                    PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
				return;
			}

			weight1 = ToCurrency(SET_TOP(remained_set)["1��ڏd��"]);
			weight2 = cur_weight_;

		}else{
			// ���v��

			fields << NsField("[1��ڏd��]", tare_w)
				   //<< NsField("[�v�ʓ���1]", )    // ���v�ʂ��Ⴏ���v�ʓ���1�͂Ȃ�
				   ;

			weight1 = tare_w;
			weight2 = cur_weight_;
		}

		net = weight1 - weight2;
		if (net < 1) net *= -1;

		if (net > ToCurrency(card_rec["�ő�ύڗ�"]) && ToCurrency(card_rec["�ő�ύڗ�"]) > 0){
			DM->Log("SCPOST", "�ő�ύڗʂɑ΂���ߐύځi�Ԕ�:" + IntToStr(car_no) + "�j", 1);
			NotifyForm->Notify("�ő�ύڗʂɑ΂���ߐύڂł�: " + IntToStr(car_no), false, 30000);

			on_error_ = true;

            //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
            out_channels_[ToInt(DM->INI["FBIDIO::OverOutCh"])]  = chOn;
            out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOff;
            out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOn;
            if (dio_thread_)
                PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
            
            DM->ADOConnection->RollbackTrans();

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

        DM->Log("SCPOST", "�v�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);

        keiryo_id = remained_id;

    }else{
        // ���ڌv�ʂ܂��͈��v��

        DM->DBI.Insert("D_�v��", fields);

		if (tare_w < 1){
			DM->Log("SCPOST", "���ڌv�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);

            keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}else{
			// ���v�ʂɂ��v�ʊ���
			DM->Log("SCPOST", "���v�ʊ����i�Ԕ�:" + IntToStr(car_no) + "�j", 0);

			keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}
	}

    DM->ADOConnection->CommitTrans();

    //////////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        DM->Log("SCPOST", AnsiString("�o�^����O�i�J�[�h�ԍ�:") + IntToStr(card_no) + "�j: " + e.Message, 2);
        NotifyForm->Notify("�o�^���ɃG���[���������܂���:" + IntToStr(card_no), false, 10000);

		on_error_ = true;

        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

		return;
    }
    //////////

    if (cmp_kbn == 1){       // �v�ʊ���
        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::ExitOutCh"])]  = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOff;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
    }else{                   //
        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::ExitOutCh"])] = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOff;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
    }

    DisplayForm->ShowRecord(keiryo_id);

	if (print){
		PrintKeiryoData(0, keiryo_id);

        int print_copy = ToInt(DM->CFG["�����v�ʎ��T���`�[���s"]);
        if (print_copy)
            PrintCopy(keiryo_id);
    }

	on_wait_exit_ = true;	// �ގԑ҂����
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnResetButtonDown()
{
	ForceWeighing(0);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnCallButtonDown()
{
    ErrorForm->TitlePanel->Caption = "�v�ʑ���|�X�g�ŌĂяo��������܂���";
    ErrorForm->TextMemo->Lines->Clear();
    ErrorForm->TextMemo->Lines->Text = "\r\n"
                                       "�Ή����܂�����y����z�{�^�����N���b�N���Ă��������B";
    ErrorForm->ShowModal();
}
//---------------------------------------------------------------------------
/**
 * Implementation of RFID Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnRFIDAborted(TMessage& message)
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
void __fastcall TSCPostForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    bool is_fatal = message.WParam;

    DM->Log("SCPOST(RFID)", status, is_fatal ? 2 : 1);

    if (is_fatal)
        NotifyForm->Notify(AnsiString("RFID���[�_:" + status), true, 20000);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnRFIDTimeout(TMessage& message)
{
    rfid_error_ = static_cast<bool>(message.WParam);
    UpdateWeighingState();
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;
    int card_no = message.LParam;

	/*** �J�[�h���m ***/

    // �F�؃`�F�b�N
    if (!is_valid){
        DM->Log("SCPOST", "�J�[�h�F�؃G���[", 1);
        NotifyForm->Notify("�V�X�e���O�̃J�[�h�����m���܂���", false, 10000);
        return;
    }
    // ����J�[�h�`�F�b�N
    if (card_no >= RFID::ADMIN_CARDS_ID){
        DM->Log("SCPOST", "����p�J�[�h���m", 1);
        NotifyForm->Notify("����p�J�[�h�͂��̃V�X�e���Ŏg�p�ł��܂���", false, 10000);
        return;
    }

    DM->Log("SCPOST", "�J�[�h���m", 0);

    last_card_no_ = card_no;

    out_channels_[ToInt(DM->INI["FBIDIO::ComplOutCh"])] = chOn;
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

    //if (ToInt(DM->INI["FBIDIO::UseButton"]) == 0){
    if (dio_thread_ == 0){
        // �|�X�g�̃{�^�����g�p���Ȃ��ݒ�̏ꍇ�A���̂܂܌v�ʂɐi��
        OnConfirmButtonDown();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::PrintKeiryoData(int tag, int keiryo_id)
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
	if (!DM->DBI.GetRecordSet(sql, set))
		return;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::PrintCopy(int keiryo_id)
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
void __fastcall TSCPostForm::ForceWeighing(int tag)
{
	OnExitWeighing(0);
	cur_weight_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::UpdateWeighingState()
{
    CH_STATUS old;

    old = out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])];

    if (wi_error_ || rfid_error_){
        out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
    }else{
        out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOn;
    }

    if (dio_thread_ && old != out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])])
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
}
//---------------------------------------------------------------------------

