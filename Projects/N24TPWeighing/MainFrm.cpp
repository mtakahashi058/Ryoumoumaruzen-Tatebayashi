//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "n24tp.h"
#include "StateForm.h"
#include "MainFrm.h"
#include "DMFrm.h"
#include "mmsystem.h"
#include "nsoftfunc.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKeiryoStateBaseForm *KeiryoStateBaseForm;
//---------------------------------------------------------------------------
__fastcall TKeiryoStateBaseForm::TKeiryoStateBaseForm(TComponent* Owner)
	: TForm(Owner),
		rfid_thread_(0), cur_weight_(0), old_weight_(0),
		weight_detected_(false), close_tick_(0),
        phc_thread_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::FormCreate(TObject *Sender)
{
    DM->INI.Load(ExtractFilePath(Application->ExeName) + N24TP::INI_NAME);
	DM->Sounds.Load(ExtractFilePath(Application->ExeName) + N24TP::SOUNDS_INI);


	///////////////////////////////////////////////
	// 基本設定
	//N24TP::terminal_id = ToInt(DM->INI["N-24TP::ID"]);

	///////////////////////////////////////////////
	// 計量情報
	if (ToInt(DM->INI["Keiryo::Border"]) < 0)
		DM->INI["Keiryo::Border"] = 0;

	///////////////////////////////////////////////
	// RFID スレッド
	if (ToInt(DM->INI["RFID::Delay"]) < 200)
		DM->INI["RFID::Delay"] = 200;

	ForceWeighingButton->Visible = false;
	ForceWeighingButton->Enabled = ToBit(DM->INI["Keiryo::UseForceWeighing"]);
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (rfid_thread_){
		rfid_thread_->Terminate();
		rfid_thread_->WaitFor();
		delete rfid_thread_;
		rfid_thread_ = 0;
	}

    if (use_phc_){
		PHC_OCTET octet;
		octet.ch = 0xff;    // 全点
		PostThreadMessage(phc_thread_->ThreadID, PHCM_COMMAND, (WPARAM)false, (LPARAM)octet.ch);
        Sleep(300);
    }

    if (phc_thread_)
        phc_thread_->Terminate();
    if (phc_thread_)
        phc_thread_->WaitFor();
    delete phc_thread_;
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	TRect client_rect = ClientRect;
	client_rect.Left = 4;
	client_rect.Top = 4;
	client_rect.Bottom -= (HeaderPanel->Height + StatusBar->Height + 6);
	client_rect.Right -= 6;

	SFM.Initialize(client_rect, OnStatus, OnEvent, OnLog, OnPatlite);

	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Close();
	try{
		// [INI] ADO::UDL
		DM->ADOConnection->ConnectionString = "FILE NAME=" + ToString(DM->INI["ADO::UDL"]);
		DM->ADOConnection->Open();
	}catch(Exception& e){
		SFM.Transit(State::Error);
		SFM.NotifyEvent(Event::Error, "\r\n内部データベースエラー");

		CloseTimer->Interval = 4000;
		CloseTimer->Enabled = true;
		return;
	}

    DM->CFG.Load(&(DM->DBI));

	SFM.Transit(State::Idle);

	///////////////////////////////////////////////
	// 重量受信
	try{
		// [INI] WeightServer::Port
		ClientSocket->Port = ToInt(DM->INI["WeightServer::Port"]);
		// [INI] WeightServer::Host
		ClientSocket->Host = ToString(DM->INI["WeightServer::Host"]);

		if (ClientSocket->Active)
			ClientSocket->Close();
		ClientSocket->Open();
	}catch(Exception& e){
		AnsiString msg = "TCP/IP通信ができません: \r\n" + e.Message;
		Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONINFORMATION);
	}

	WeightDetectTimer->Enabled = true;

	// RFIDスレッドの開始
	// [INI] RFID::Delay
	rfid_thread_ = new THF04Thread(false, Handle, ToInt(DM->INI["RFID::CommPort"]));

    ///////////////////////////////////////////////
    // PHC100
	use_phc_        = ToBit(DM->INI["PHC100::Use"]);
    phc_info_.port  = ToInt(DM->INI["PHC100::PHCPort"]);
    phc_info_.def   = "9600,N,8,1";
 	phc_info_.owner = Handle;
    if (phc_info_.port < 1)
    	use_phc_ = false;

    if (use_phc_)
	    phc_thread_ = new TPHCThread(false, phc_info_);
}
//---------------------------------------------------------------------------
/**
 * Implementation of SFM Handler
 */
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnStatus(const AnsiString& message)
{
	StatusBar->SimpleText = message;

	if (!message.IsEmpty()){
		std::ofstream ofs("c:\\status.txt", std::ios::out | std::ios::app);

		ofs << Now().FormatString("yyyy'-'mm'-'dd hh:nn:ss").c_str() << " " << message.c_str() << std::endl;
	}
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnEvent(State::EventID event, void *param)
{
	if (event == State::ForceWeighingEnabled){
		if (ForceWeighingButton->Enabled)	// → DM->INI::UseForceWeighing
			ForceWeighingButton->Visible = reinterpret_cast<int>(param) ? true : false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnLog(const AnsiString& message)
{
	if (!message.IsEmpty()){
        DM->Log("N-24TP", message, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnPatlite(bool complete, bool error)
{
	if (!use_phc_)
    	return;

	PHC_OCTET on_octet;
    PHC_OCTET off_octet;
	on_octet.ch  = 0;
	off_octet.ch = 0;

    if (complete)
    	on_octet  << ToInt(DM->INI["PHC100::CompleteCh"]);
	else
    	off_octet << ToInt(DM->INI["PHC100::CompleteCh"]);
	if (error)
    	on_octet  << ToInt(DM->INI["PHC100::ErrorCh"]);
    else
    	off_octet << ToInt(DM->INI["PHC100::ErrorCh"]);

	if (on_octet.ch != 0){
		PostThreadMessage(phc_thread_->ThreadID, PHCM_COMMAND, (WPARAM)true, (LPARAM)on_octet.ch);
        if (off_octet.ch != 0)
	    	Sleep(300);
    }
    if (off_octet.ch != 0){
		PostThreadMessage(phc_thread_->ThreadID, PHCM_COMMAND, (WPARAM)false, (LPARAM)off_octet.ch);
    }
}
//---------------------------------------------------------------------------
/**
 * Implementation of Message Handler
 */
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnPHCAborted(TMessage& message)
{
	StatusBar->SimpleText = "パトライト出力ユニットとの通信を停止しました";
	DM->Log("N-24TP", "パトライト出力ユニットとの通信を停止しました", 2);

    delete phc_thread_;
    phc_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnPHCStatus(TMessage& Message)
{
    AnsiString status = reinterpret_cast<LPCSTR>(Message.LParam);
	DM->Log("N-24TP", "外部パトライト警告: " + status, 1);
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;

	SFM.Transit(State::Error);
	SFM.NotifyEvent(Event::Error, "\r\nRFIDユニットが使用できません");

	CloseTimer->Interval = 4000;
	CloseTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	StatusBar->SimpleText = status;
//	CardMessagePanel->Caption = status;
/*
	bool is_fatal = message.WParam;
	if (is_fatal)
		Application->MessageBox(status.c_str(),
			"RFIDカード読み取り",
			MB_OK | MB_ICONSTOP);
*/
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::OnRFIDCard(TMessage& message)
{
	bool valid = static_cast<bool>(message.WParam);

	if (!valid){
		StatusBar->SimpleText = "無効なカードです";
		return;
	}

	int card_no = static_cast<int>(message.LParam);
	if (card_no == N24TP::ADMIN_CARD_NO){
		CloseTimer->Interval = 100;
		CloseTimer->Enabled = true;
		return;
	}
	if (card_no == N24TP::SET_ZERO_CARD_NO || card_no == N24TP::CLR_ZERO_CARD_NO){
		bool set_mode = (card_no == N24TP::SET_ZERO_CARD_NO);
		HWND menu_wnd = FindWindow("TConsoleForm", "N-24TP 管理メニュー");
		if (menu_wnd)
			PostMessage(menu_wnd, UM_CONTROL_ZERO, set_mode, 0);
		return;
	}

	SFM.NotifyEvent(Event::Card, reinterpret_cast<LPVOID>(card_no));
}
//---------------------------------------------------------------------------
/**
 * Implementation of Control Event
 */
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::ClientSocketError(TObject *Sender,
	  TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	switch (ErrorEvent){
	case eeReceive:
		StatusBar->SimpleText = "TCP: 重量受信エラー";
		break;
	case eeConnect:
		StatusBar->SimpleText = "TCP: 接続エラー";
		break;
	case eeDisconnect:
		StatusBar->SimpleText = "TCP: 切断エラー";
		break;
	default:
		StatusBar->SimpleText = "TCP: ソケットエラー";
		break;
	};

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::ClientSocketRead(TObject *Sender,
	  TCustomWinSocket *Socket)
{
	int index;
	AnsiString weight = Socket->ReceiveText();

	int len = weight.Length();
	if (len < 4)					return;
	if (weight[len - 1] != '\r')	return;
	if (weight[len] != '\n')		return;
	switch (weight[1]){
	case 'S':	WeightPanel->Font->Color = clLime; break;
	case 'U':	WeightPanel->Font->Color = clRed;  break;
	case 'O':	WeightPanel->Font->Color = clGray; break;
	default:
		return;
	}

	weight.Delete(1, 1);	// ステータスキャラクタの削除
	weight.Delete(weight.Length() - 1, 2);	// 末尾の \r\n を削除
	Currency tmp_weight;
	try{
		tmp_weight = Currency(weight);
	}catch(...){return;}

	// 重量検知がされていない
	if (!weight_detected_){
		WeightDetectTimer->Enabled = false;
		weight_detected_ = true;
		if (SFM.GetCurrentStateID() == State::Idle)
			PlaySound(0, 0, SND_LOOP | SND_ASYNC | SND_FILENAME);

		// if (SFM.GetCurrentStateID() == State::Error)
		//	SFM.Transit(State::Idle);
	}

	WeightDetectTimer->Enabled = false;
	WeightDetectTimer->Enabled = true;

	old_weight_     = cur_weight_;
	cur_weight_  = tmp_weight;

	// [INI] Keiryo::Border
	int border = ToInt(DM->INI["Keiryo::Border"]);

	if (old_weight_ < border && cur_weight_ >= border)
		SFM.NotifyEvent(Event::EnterWeighing);
	else if ((old_weight_ >= border) && (cur_weight_ < border))
		SFM.NotifyEvent(Event::ExitWeighing);

	WeightPanel->Caption = FormatFloat("###,##0kg", cur_weight_);

	SFM.stash["Weight"] = cur_weight_;
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::CloseTimerTimer(TObject *Sender)
{
	CloseTimer->Enabled = false;

	Close();
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::WeightDetectTimerTimer(TObject *Sender)
{
	WeightDetectTimer->Enabled = false;

	SFM.NotifyEvent(Event::ExitWeighing);

	if (!weight_detected_){
		SFM.Transit(State::Error);
		SFM.NotifyEvent(Event::Error, "\r\n重量値を受信できません");
	}

	weight_detected_ = false;

	old_weight_ = 0;
	cur_weight_ = 0;

	WeightPanel->Caption = AnsiString();

	PlaySound(ToString(DM->Sounds["WeightError"]).c_str(), 0, SND_LOOP | SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::TitlePanelMouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
	close_tick_ = GetTickCount();
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::TitlePanelMouseUp(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
	DWORD cur_tick = GetTickCount();
	if (cur_tick - close_tick_ > 5000){
		CloseTimer->Interval = 100;
		CloseTimer->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TKeiryoStateBaseForm::ForceWeighingButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::WaitCard);
}
//---------------------------------------------------------------------------

