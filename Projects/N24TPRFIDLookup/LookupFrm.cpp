//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "n24tp.h"
#include "LookupFrm.h"
#include "DMFrm.h"
#include <IniFiles.hpp>
#include <memory>
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLookupForm *LookupForm;
//---------------------------------------------------------------------------
__fastcall TLookupForm::TLookupForm(TComponent* Owner)
	: TForm(Owner), rfid_thread_(0)
{
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TLookupForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	std::auto_ptr<TIniFile> ini(new TIniFile(ExtractFilePath(Application->ExeName) + N24TP::INI_NAME));
	AnsiString udl_file = ini->ReadString("ADO", "UDL", "");

	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Close();
	try{
		DM->ADOConnection->ConnectionString = "FILE NAME=" + udl_file;

		DM->ADOConnection->Open();
        DM->CFG.Load(&(DM->DBI));
	}catch(Exception& e){
		Application->MessageBox(AnsiString("データベースに接続できません - \r\n" + e.Message).c_str(),
			Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

	TokuTitlePanel->Caption  = "  " + ToString(DM->CFG["得意先マスタ名称"]);
	MeigTitlePanel->Caption  = "  " + ToString(DM->CFG["品目マスタ名称"]);
	Item1TitlePanel->Caption = "  " + ToString(DM->CFG["項目1マスタ名称"]);
	Item2TitlePanel->Caption = "  " + ToString(DM->CFG["項目2マスタ名称"]);

    if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
		TokuTitlePanel->Visible = false;
		TokuPanel->Visible = false;
    }
    if (!ToBit(DM->CFG["品目マスタ使用区分"])){
		MeigTitlePanel->Visible = false;
		MeigPanel->Visible = false;
    }
    if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
		Item1TitlePanel->Visible = false;
		Item1Panel->Visible = false;
    }
    if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
		Item2TitlePanel->Visible = false;
		Item2Panel->Visible = false;
    }

    int port = ini->ReadInteger("RFID", "CommPort", 1);

	ClearForm();

	// RFIDスレッドの開始
	rfid_thread_ = new THF04Thread(false, Handle, port);
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (rfid_thread_){
		rfid_thread_->Terminate();
		rfid_thread_->WaitFor();
		delete rfid_thread_;
	}
}
//---------------------------------------------------------------------------
/**
 * Implementation of Private Method
 */
//---------------------------------------------------------------------------
void __fastcall TLookupForm::ClearForm()
{
	StatusMemo->Lines->Clear();
	StatusLabel->Caption     = AnsiString();
    TokuPanel->Caption       = AnsiString();
    MeigPanel->Caption       = AnsiString();
	Item1Panel->Caption      = AnsiString();
	Item2Panel->Caption      = AnsiString();
	CarNoPanel->Caption      = AnsiString();
	TareWeightLabel->Caption = AnsiString();
	GrossLimitLabel->Caption = AnsiString();
	NetLimitLabel->Caption   = AnsiString();
	UseDateLabel->Caption    = AnsiString();
}
//---------------------------------------------------------------------------
/**
 * Implementation of Message Handler
 */
//---------------------------------------------------------------------------
void __fastcall TLookupForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
	// Application->MessageBox("RFIDユニットとの通信ができません", Caption.c_str(),
	//		MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	StatusLabel->Caption = status;
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;

	ClearForm();

	if (!is_valid){
		// 無効なカード
		StatusMemo->Lines->Append("カード形式が無効です。");
		StatusMemo->Lines->Append("このカードは、当システムでは使用できません。");
		StatusMemo->Lines->Append(reinterpret_cast<LPCSTR>(message.LParam));
		return;
	}

	// 有効なカード
	int card_no = message.LParam;

	if (card_no == N24TP::ADMIN_CARD_NO){
		StatusMemo->Lines->Append("管理カードです。");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("このカードは使用可能です。");
		return;
	}
	if (card_no == N24TP::SET_ZERO_CARD_NO){
		StatusMemo->Lines->Append("重量ゼロ設定カードです。");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("このカードは使用可能です。");
		return;
	}
	if (card_no == N24TP::CLR_ZERO_CARD_NO){
		StatusMemo->Lines->Append("重量ゼロ取消カードです。");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("このカードは使用可能です。");
		return;
	}

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_車両 WHERE カード番号 = " + IntToStr(card_no);
	if (!DM->DBI.GetRecordSet(sql, set)){
		StatusMemo->Lines->Append("カード情報が無効です。");
		StatusMemo->Lines->Append("発行時の情報が存在しません。");
		StatusMemo->Lines->Append("このカードは、当システムでは使用できません。");
		return;
	}

    CarNoPanel->Caption = ToInt(SET_TOP(set)["車番"]) < 1    ? AnsiString(" 指定なし")
                                                             : AnsiString(" ") + ToString(SET_TOP(set)["車番"]) + " " + ToString(SET_TOP(set)["車両名称"]);
    TokuPanel->Caption  = SET_TOP(set)["得意先略称"].IsNull() ? AnsiString(" 指定なし")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["得意先略称"]);
    MeigPanel->Caption  = SET_TOP(set)["品目略称"].IsNull()   ? AnsiString(" 指定なし")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["品目略称"]);
    Item1Panel->Caption = SET_TOP(set)["項目1略称"].IsNull()  ? AnsiString(" 指定なし")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["項目1略称"]);
    Item2Panel->Caption = SET_TOP(set)["項目2略称"].IsNull()  ? AnsiString(" 指定なし")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["項目2略称"]);

	TareWeightLabel->Caption = ToInt(SET_TOP(set)["空車重量"])   ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["空車重量"]))
																 : AnsiString();
	GrossLimitLabel->Caption = ToInt(SET_TOP(set)["車両総重量"]) ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["車両総重量"]))
																 : AnsiString();
	NetLimitLabel->Caption   = ToInt(SET_TOP(set)["最大積載量"]) ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["最大積載量"]))
																 : AnsiString();
    sql = "SELECT TOP 1 計量日 FROM D_計量 WHERE 車両ID = " + ToString(SET_TOP(set)["車両ID"]) + " ORDER BY 計量日 DESC";
    if (DM->DBI.GetRecordSet(sql, set)){
        try{
    		UseDateLabel->Caption   = IntToDate(ToInt(SET_TOP(set)["計量日"])).FormatString("yyyy/mm/dd");
        }catch(...){}
    }
}
//---------------------------------------------------------------------------
/**
 * Implementation of Control Event
 */
//---------------------------------------------------------------------------
void __fastcall TLookupForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::ActivateTimerTimer(TObject *Sender)
{
	ActivateTimer->Enabled = false;
	SetForegroundWindow(Handle);
}
//---------------------------------------------------------------------------

