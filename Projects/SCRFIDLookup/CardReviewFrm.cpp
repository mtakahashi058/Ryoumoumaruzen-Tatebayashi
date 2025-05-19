//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CardReviewFrm.h"
#include "DMFrm.h"
#include <IniFiles.hpp>
#include <memory>
#include "nsoftfunc.h"
#include "n24TP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCardReviewForm *CardReviewForm;
//---------------------------------------------------------------------------
__fastcall TCardReviewForm::TCardReviewForm(TComponent* Owner)
	: TForm(Owner), rfid_thread_(0)
{
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::FormShow(TObject *Sender)
{
	if (!DM->Init()){
		Close();
        return;
    }

	TokuTitlePanel->Caption  = "  " + ToString(DM->CFG["得意先マスタ名称"]);
	HinTitlePanel->Caption   = "  " + ToString(DM->CFG["品目マスタ名称"]);
	Item1TitlePanel->Caption = "  " + ToString(DM->CFG["項目1マスタ名称"]);
	Item2TitlePanel->Caption = "  " + ToString(DM->CFG["項目2マスタ名称"]);

	if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
        TokuPanel->Visible       = false;
	}
	if (!ToBit(DM->CFG["品目マスタ使用区分"])){
        HinPanel->Visible        = false;
	}
	if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        Item1Panel->Visible      = false;
	}
	if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
        Item2Panel->Visible      = false;
	}

    int port = ToInt(DM->INI["RFID::DeskCommPort"]);

	ClearForm();

    /////////////////////////////////////////
    // スマートカード初期化
    int reader_index = ToInt(DM->INI["SmartCard::ReaderIndex"]);

    if (!DM->cardService.CheckService()){
        Application->MessageBox("SmartCardサービスが起動していません", Caption.c_str(), MB_OK | MB_ICONSTOP);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }

    DWORD dw_err;
    AnsiString err_text;
    SmartCardService::Readers readers;

    if (!DM->cardService.Establish()){
        DM->cardService.GetLastError(dw_err, err_text);
		Application->MessageBox(AnsiString("SmartCard との通信確立に失敗しました - " + err_text).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
    }

    if (!DM->cardService.EnumReaders(readers)){
		DM->cardService.GetLastError(dw_err, err_text);
		Application->MessageBox(AnsiString("SmartCard リーダが取得できません - " + err_text).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;

    }

	if (readers.empty()){
		Application->MessageBox("SmartCard リーダが存在しません", Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

    if (int(readers.empty()) >= reader_index + 1)
        DM->cardService.SetReader(readers[reader_index]);
    else
        DM->cardService.SetReader(readers[0]);
}

//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
//
}
//---------------------------------------------------------------------------
/**
 * Implementation of Private Method
 */
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::ClearForm()
{
	StatusMemo->Lines->Clear();
	StatusLabel->Caption     = AnsiString();
    CarNoPanel->Caption      = AnsiString();
    TokuPanel->Caption       = AnsiString();
    HinPanel->Caption        = AnsiString();
    Item1Panel->Caption      = AnsiString();
    Item2Panel->Caption      = AnsiString();
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
void __fastcall TCardReviewForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
	// Application->MessageBox("RFIDユニットとの通信ができません", Caption.c_str(),
	//		MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	StatusLabel->Caption = status;
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::OnRFIDCard(TMessage& message)
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
		StatusMemo->Lines->Append("N-24TP用管理カードです。");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("このカードは使用可能です。");
		return;
	}
	if (card_no == N24TP::SET_ZERO_CARD_NO){
		StatusMemo->Lines->Append("N-24TP用重量ゼロ設定カードです。");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("このカードは使用可能です。");
		return;
	}
	if (card_no == N24TP::CLR_ZERO_CARD_NO){
		StatusMemo->Lines->Append("N-24TP用重量ゼロ取消カードです。");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("このカードは使用可能です。");
		return;
	}

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_車両 WHERE カード番号 = " + IntToStr(card_no) + " AND 使用区分 = 1";
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
    HinPanel->Caption   = SET_TOP(set)["品目略称"].IsNull()   ? AnsiString(" 指定なし")
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
void __fastcall TCardReviewForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::ActivateTimerTimer(TObject *Sender)
{
	ActivateTimer->Enabled = false;
	SetForegroundWindow(Handle);

    DWORD dw_err;
    AnsiString err_text;
    DWORD dw_event;

    if (!DM->cardService.GetStatusChange(dw_event)){
        DM->cardService.GetLastError(dw_err, err_text);
        return;
    }

    if (dw_event & SCARD_STATE_EMPTY){
        ClearForm();
    } else if (dw_event & SCARD_STATE_PRESENT){
        ClearForm();
        OnCardPresent();
    }

    ActivateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::OnCardPresent()
{
    DWORD dw_err;
    AnsiString err_text;
    if (!DM->cardService.ConnectCard(&DM->card_)){
        DM->cardService.GetLastError(dw_err, err_text);
        StatusMemo->Lines->Append("エラー: " + err_text);
        return;
    }

    BYTE sw1, sw2;
    BYTE key[6];

    ZeroMemory(key, sizeof(key));
    HexStringToBytes(DM->CardKey.c_str(), key);

    CardImage image;
    try {
        ReadImageFromSmartCard_ultra(&DM->card_, &image);

    }catch(Exception& e){
        StatusMemo->Lines->Append(e.Message);
        return;
    }

    DM->card_.Disconnect();

/*
    ///////////////////////////////////////////////////
    // Mifare UltraLightはカード認証不可

    if (!image.card_key_valid){
        StatusLabel->Caption = "このカードは使用できません";
        StatusMemo->Lines->Append("当システム外のカードです");
        return;
    }

    if (!image.system_key_valid){
        StatusLabel->Caption = "このカードは使用できません";
        StatusMemo->Lines->Append("別システムのカードです");
        return;
    }
*/

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM V_車両 where カード番号 = " + IntToStr(image.card_id) + " AND 使用区分 = 1";

    if (!DM->DBI.GetRecordSet(sql, set)){
        StatusMemo->Lines->Append("カード情報が無効です");
        StatusMemo->Lines->Append("発行時の情報が存在しません");
        StatusMemo->Lines->Append("このカードは、当システムでは使用できません");
        return;
    }

    CarNoPanel->Caption = ToInt(SET_TOP(set)["車番"]) < 1    ? AnsiString(" 指定なし")
                                                             : AnsiString(" ") + ToString(SET_TOP(set)["車番"]) + " " + ToString(SET_TOP(set)["車両名称"]);

    TokuPanel->Caption  = SET_TOP(set)["得意先略称"].IsNull() ? AnsiString(" 指定なし")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["得意先略称"]);
    HinPanel->Caption   = SET_TOP(set)["品目略称"].IsNull()   ? AnsiString(" 指定なし")
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

