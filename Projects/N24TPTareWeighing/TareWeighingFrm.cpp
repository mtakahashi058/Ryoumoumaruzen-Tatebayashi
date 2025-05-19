//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "n24tp.h"
#include "PageState.h"
#include "TareWeighingFrm.h"
#include "DMFrm.h"
#include <IniFiles.hpp>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TTareWeighingForm *TareWeighingForm;
//---------------------------------------------------------------------------
__fastcall TTareWeighingForm::TTareWeighingForm(TComponent* Owner)
	: TForm(Owner), rfid_thread_(0), cur_weight_(0)
{
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	current_state_ = &stateStartup;

    ///////////////////////////////////////////////
    // DB

	std::auto_ptr<TIniFile> ini(new TIniFile(ExtractFilePath(Application->ExeName) + N24TP::INI_NAME));

	AnsiString udl_file = ini->ReadString("ADO", "UDL", "");

	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Close();
	try{
		DM->ADOConnection->ConnectionString = "FILE NAME=" + udl_file;
		DM->ADOConnection->Open();

        DM->CFG.Load(&(DM->DBI));
	}catch(Exception& e){
		Application->MessageBox(AnsiString("�f�[�^�x�[�X�ɐڑ��ł��܂��� - \r\n" + e.Message).c_str(),
			Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

    AnsiString toku_master  = DM->TrimSpace(ToString(DM->CFG["���Ӑ�}�X�^����"]));
    AnsiString meig_master  = DM->TrimSpace(ToString(DM->CFG["�i�ڃ}�X�^����"]));
    AnsiString item1_master = DM->TrimSpace(ToString(DM->CFG["����1�}�X�^����"]));
    AnsiString item2_master = DM->TrimSpace(ToString(DM->CFG["����2�}�X�^����"]));

    TokuTitlePanel->Caption  = "  " + toku_master;
    MeigTitlePanel->Caption  = "  " + meig_master;
    Item1TitlePanel->Caption = "  " + item1_master;
    Item2TitlePanel->Caption = "  " + item2_master;

	///////////////////////////////////////////////
	// �d�ʎ�M�ݒ�

	ClientSocket->Port = ini->ReadInteger("WeightServer", "Port", 57160);
	ClientSocket->Host = ini->ReadString("WeightServer", "Host", "127.0.0.1");
	// ��M�J�n
	try{
		if (ClientSocket->Active)
			ClientSocket->Close();
		ClientSocket->Open();
	}catch(Exception& e){
		AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
		Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
	}

	///////////////////////////////////////////////
	// RFID Port
	int rfid_port = ini->ReadInteger("RFID", "CommPort", 1);


	stateStartup.connectEvent(evComplete, &stateWaitCard);

	stateWaitCard.connectEvent(evCard, &stateSelectMode);

	stateSelectMode.connectEvent(evRepealTare, &stateComplete);
	stateSelectMode.connectEvent(evWeighTare, &stateWeighTare);
	stateSelectMode.connectEvent(evBack, &stateWaitCard);

	stateWeighTare.connectEvent(evComplete, &stateComplete);
	stateWeighTare.connectEvent(evBack, &stateSelectMode);

	stateComplete.connectEvent(evComplete, &stateWaitCard);

	current_state_ = current_state_->transit(evComplete);

	// RFID�X���b�h�̊J�n
	rfid_thread_ = new THF04Thread(false, Handle, rfid_port);
}
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (rfid_thread_){
		rfid_thread_->Terminate();
		rfid_thread_->WaitFor();
		delete rfid_thread_;
	}

	if (ClientSocket->Active)
		ClientSocket->Close();
}
//---------------------------------------------------------------------------
/**
 * Implementation of Message Handler
 */
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
	// Application->MessageBox("RFID���j�b�g�Ƃ̒ʐM���ł��܂���", Caption.c_str(),
	//		MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	StatusLabel->Caption = status;
/*
	bool is_fatal = message.WParam;
	if (is_fatal)
		Application->MessageBox(status.c_str(),
			"RFID�J�[�h�ǂݎ��",
			MB_OK | MB_ICONSTOP);
*/
}
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;

	StatusMemo->Clear();

	if (!is_valid){
		// �����ȃJ�[�h

		StatusMemo->Lines->Append("�J�[�h�`���������ł��B");
		StatusMemo->Lines->Append("���̃J�[�h�́A���V�X�e���ł͎g�p�ł��܂���B");
		StatusMemo->Lines->Append(reinterpret_cast<LPCSTR>(message.LParam));
		return;
	}

	// �L���ȃJ�[�h
	int card_no = message.LParam;

	if (card_no == N24TP::ADMIN_CARD_NO){
		StatusMemo->Lines->Append("�Ǘ��J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}
	if (card_no == N24TP::SET_ZERO_CARD_NO){
		StatusMemo->Lines->Append("�d�ʃ[���ݒ�J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}
	if (card_no == N24TP::CLR_ZERO_CARD_NO){
		StatusMemo->Lines->Append("�d�ʃ[������J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�ԗ� WHERE �J�[�h�ԍ� = " + IntToStr(card_no);
	if (!DM->DBI.GetRecordSet(sql,set)){
		StatusMemo->Lines->Append("�J�[�h��񂪖����ł��B");
		StatusMemo->Lines->Append("���s���̏�񂪑��݂��܂���B");
		StatusMemo->Lines->Append("���̃J�[�h�́A���V�X�e���ł͎g�p�ł��܂���B");
		return;
	}

	current_state_ = current_state_->transit(evCard, reinterpret_cast<LPVOID>(&set));
}
//---------------------------------------------------------------------------
/**
 * Implementation of Public Method
 */
//---------------------------------------------------------------------------
Currency __fastcall TTareWeighingForm::GetWeight()
{
	return cur_weight_;
}
//---------------------------------------------------------------------------
/**
 * Implementation of Control Event
 */
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::ClientSocketError(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	switch (ErrorEvent){
	case eeReceive:
		//StatusBar->SimpleText = "TCP: �d�ʎ�M�G���[";
		break;
	case eeConnect:
		//StatusBar->SimpleText = "TCP: �ڑ��G���[";
		break;
	case eeDisconnect:
		//StatusBar->SimpleText = "TCP: �ؒf�G���[";
		break;
	default:
		//StatusBar->SimpleText = "TCP: �\�P�b�g�G���[";
		break;
	};

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
	int index;
	AnsiString weight = Socket->ReceiveText();

	int len = weight.Length();
	if (len < 4)
		return;

	if (weight[len - 1] != '\r')
		return;
	if (weight[len] != '\n')
		return;

	switch (weight[1]){
	case 'S':	WeightPanel->Font->Color = clLime; break;
	case 'U':	WeightPanel->Font->Color = clRed;  break;
	case 'O':	WeightPanel->Font->Color = clGray; break;
	default:
		return;
	}

	weight.Delete(1, 1);	// �X�e�[�^�X�L�����N�^�̍폜
	weight.Delete(weight.Length() - 1, 2);	// ������ \r\n ���폜

	try{
		cur_weight_ = Currency(weight);
	}catch(...){
		return;
	}

	WeightPanel->Caption = FormatFloat("###,##0kg", cur_weight_);
}
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
// ����y�߂�z
void __fastcall TTareWeighingForm::BackButtonClick(TObject *Sender)
{
	current_state_ = current_state_->transit(evBack);
}
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::ActivateTimerTimer(TObject *Sender)
{
	ActivateTimer->Enabled = false;
	SetForegroundWindow(Handle);
}
//---------------------------------------------------------------------------
// ��ԏd�ʐݒ�{�^��
void __fastcall TTareWeighingForm::SetTareButtonClick(TObject *Sender)
{
	current_state_ = current_state_->transit(evWeighTare);
}
//---------------------------------------------------------------------------
// ��ԏd�ʖ����{�^��
void __fastcall TTareWeighingForm::Button1Click(TObject *Sender)
{
	current_state_ = current_state_->transit(evRepealTare);
}
//---------------------------------------------------------------------------
// ��Ԍv�ʌx���m�F�{�^��
void __fastcall TTareWeighingForm::WarningConfirmButtonClick(
	  TObject *Sender)
{
	current_state_ = current_state_->transit(evWeighConfirm);
}
//---------------------------------------------------------------------------
// �����m�F�{�^��
void __fastcall TTareWeighingForm::CompleteConfirmButtonClick(TObject *Sender)
{
	current_state_ = current_state_->transit(evComplete);
}
//---------------------------------------------------------------------------
void __fastcall TTareWeighingForm::WeighTareButtonClick(TObject *Sender)
{
	if (cur_weight_ < 1)
		return;
	current_state_ = current_state_->transit(evComplete);
}
//---------------------------------------------------------------------------

