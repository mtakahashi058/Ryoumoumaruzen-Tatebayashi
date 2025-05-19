//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CardIssueFrm.h"
#include "DMFrm.h"
#include <memory>
#include "RFIDWriteFrm.h"
#include <vector>
#include "ShabanSanshoFrm.h"
#include "nsoftfunc.h"
#include "SearchFrm.h"
#include "N24TPCardsFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TCardIssueForm *CardIssueForm;
//---------------------------------------------------------------------------
__fastcall TCardIssueForm::TCardIssueForm(TComponent* Owner)
	: TForm(Owner)
{
    Application->OnMessage = MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::MessageProc(tagMSG &Msg, bool &Handled)
{
    TDBGrid *Grid = 0;

    switch (Msg.message){
    case WM_MOUSEWHEEL:
        if (Msg.hwnd == ShabanSanshoForm->DBGrid->Handle)
            Grid = ShabanSanshoForm->DBGrid;
        if (Msg.hwnd == SearchForm->DBGrid->Handle)
            Grid = SearchForm->DBGrid;

        if (!Grid)
            return;

        Grid->SetFocus();

        if((short)HIWORD(Msg.wParam) > 0){
            Grid->DataSource->DataSet->Prior();
        }else{
            Grid->DataSource->DataSet->Next();
        }
        Handled = true;
        break;
    }
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormShow(TObject *Sender)
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
        TokuEdit->Enabled       = false;
        TokuNameEdit->Enabled   = false;
        TokuRefButton->Enabled  = false;
	}
	if (!ToBit(DM->CFG["品目マスタ使用区分"])){
        HinEdit->Enabled        = false;
        HinNameEdit->Enabled    = false;
        HinRefButton->Enabled   = false;
	}
	if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        Item1Edit->Enabled      = false;
        Item1NameEdit->Enabled  = false;
        Item1RefButton->Enabled = false;
	}
	if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
        Item2Edit->Enabled      = false;
        Item2NameEdit->Enabled  = false;
        Item2RefButton->Enabled = false;
	}

    rfid_comm_port_ = ToInt(DM->INI["RFID::DeskCommPort"]);

	ClearForm();
	PageControl->ActivePage = CardSheet;

	CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
	case VK_RETURN:
		if (ActiveControl->Tag != 999 && ActiveControl->Tag > 0){
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag > 1){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB,   0, 0, 0);
			keybd_event(VK_TAB,   0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
/**
 * Implementation of Private Method
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::ClearForm()
{
    car_id_ = 0;

	CarNoEdit->Text      = AnsiString();
    CarNameEdit->Text    = AnsiString();
    TokuEdit->Text       = AnsiString();
    TokuNameEdit->Text   = AnsiString();
    HinEdit->Text        = AnsiString();
    HinNameEdit->Text    = AnsiString();
    Item1Edit->Text      = AnsiString();
    Item1NameEdit->Text  = AnsiString();
    Item2Edit->Text      = AnsiString();
    Item2NameEdit->Text  = AnsiString();
	TareEdit->Text       = AnsiString();
	GrossLimitEdit->Text = AnsiString();
	NetLimitEdit->Text   = AnsiString();
}
//---------------------------------------------------------------------------
bool __fastcall TCardIssueForm::IsValidForm()
{
	int val;

    /** まだ受け手側での実装ができていないが、車両指定なしも可能に
    if (car_id_ == 0){
        Application->MessageBox("車両の選択が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
        CarNoEdit->SetFocus();
        return false;
    }
    **/

    if (!TokuEdit->Text.IsEmpty() && TokuNameEdit->Text.IsEmpty()){
        AnsiString message = ToString(DM->CFG["得意先マスタ名称"]) + "が無効です";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		TokuEdit->Text = AnsiString();
		TokuEdit->SetFocus();
		return false;
    }
    if (!HinEdit->Text.IsEmpty() && HinNameEdit->Text.IsEmpty()){
        AnsiString message = ToString(DM->CFG["品目マスタ名称"]) + "が無効です";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		HinEdit->Text = AnsiString();
		HinEdit->SetFocus();
		return false;
    }
	if (!Item1Edit->Text.IsEmpty() && Item1NameEdit->Text.IsEmpty()){
		AnsiString message = ToString(DM->CFG["項目1マスタ名称"]) + "が無効です";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		Item1Edit->Text = AnsiString();
		Item1Edit->SetFocus();
		return false;
	}
	if (!Item2Edit->Text.IsEmpty() && Item2NameEdit->Text.IsEmpty()){
		AnsiString message = ToString(DM->CFG["項目2マスタ名称"]) + "が無効です";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		Item2Edit->Text = AnsiString();
		Item2Edit->SetFocus();
		return false;
	}

	if (!TareEdit->Text.IsEmpty() && TareEdit->Text != "0"){
		val = TareEdit->Text.ToIntDef(0);
		if (val < 1){
			Application->MessageBox("空車重量が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
			TareEdit->Text = AnsiString();
			TareEdit->SetFocus();
			return false;
		}
	}
	if (!GrossLimitEdit->Text.IsEmpty() && GrossLimitEdit->Text != "0"){
		val = GrossLimitEdit->Text.ToIntDef(0);
		if (val < 1){
			Application->MessageBox("総重量上限が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
			GrossLimitEdit->Text = AnsiString();
			GrossLimitEdit->SetFocus();
			return false;
		}
	}
	if (!NetLimitEdit->Text.IsEmpty() && NetLimitEdit->Text != "0"){
		val = NetLimitEdit->Text.ToIntDef(0);
		if (val < 1){
			Application->MessageBox("正味重量上限が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
			NetLimitEdit->Text = AnsiString();
			NetLimitEdit->SetFocus();
			return false;
		}
	}

	return true;
}
//---------------------------------------------------------------------------
/**
 * Implementation of Control Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarNoEditChange(TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_車両 WHERE 車番 = " + IntToStr(CarNoEdit->Text.ToIntDef(0));
    if (!DM->DBI.GetRecordSet(sql, set)){
        CarNameEdit->Text = AnsiString();
        return;
    }

    if (set.size() == 1){
        CarNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
    }else{
        CarNameEdit->Text = "複数の車両が存在";
    }
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarNoEditExit(TObject *Sender)
{
    if (ActiveControl == CloseButton)
        return;

    CarNameEdit->TabStop  = false;
    CarNameEdit->ReadOnly = true;
    CarNameEdit->Color    = clSilver;

    int car_no = CarNoEdit->Text.ToIntDef(0);
    if (car_no < 1){
        CarNoEdit->Text = AnsiString();
        return;
    }

    AnsiString sql;
    NsRecordSet set;

    sql = "SELECT 車両名称 FROM M_車両 WHERE 車両ID = " + IntToStr(car_id_);
    if (DM->DBI.GetRecordSet(sql, set)){
        if (ToString(SET_TOP(set)["車両名称"]) == CarNameEdit->Text)
            return;
    }

    if (DM->Q_Shaban->Active)
        DM->Q_Shaban->Close();
    DM->Q_Shaban->SQL->Text = " SELECT"
                              "     車両ID, 車番, 車両名称, 空車重量, 得意先略称, 品目略称, 項目1略称, 項目2略称"
                              " FROM V_車両"
                              " WHERE"
                              "     使用区分 = 1"
                              " AND"
                              "     車番 = " + IntToStr(car_no);
    DM->Q_Shaban->Open();

    if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
        // 新規車両登録

        car_id_ = -1;
        CarNameEdit->TabStop  = true;
        CarNameEdit->ReadOnly = false;
        CarNameEdit->Color    = clWindow;
        CarNameEdit->Text     = AnsiString(); //"車両名";
        CarNameEdit->SetFocus();

        return;
    }

    // 既存車両にヒットした場合、選択させる
    ShabanSanshoForm->TopPanel->Caption = "  車番：" + IntToStr(car_no);
    ShabanSanshoForm->NewButton->Visible = true;
    if (ShabanSanshoForm->ShowModal() != mrOk){
        CarNoEdit->SetFocus();
        return;
    }

    car_id_      = ShabanSanshoForm->GetCarID();

    if (!car_id_){
        // 新規車両（上と同じ処理）

        car_id_ = -1;
        CarNameEdit->TabStop  = true;
        CarNameEdit->ReadOnly = false;
        CarNameEdit->Color    = clWindow;
        CarNameEdit->Text  = "車両名";
        CarNameEdit->SetFocus();

        return;
    }

    // 車両マスタからの選択

    sql = "SELECT * FROM V_車両 WHERE 車両ID = " + IntToStr(car_id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("選択された車両が存在しません。\r\n別PCなどで削除されていないか確認してください。",
            Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    CarNameEdit->Text    = ToString(SET_TOP(set)["車両名称"]);
    TokuEdit->Text       = ZeroSuppress(ToInt(SET_TOP(set)["得意先コード"]));
    HinEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["品目コード"]));
    Item1Edit->Text      = ZeroSuppress(ToInt(SET_TOP(set)["項目1コード"]));
    Item2Edit->Text      = ZeroSuppress(ToInt(SET_TOP(set)["項目2コード"]));
    TareEdit->Text       = ToCurrency(SET_TOP(set)["空車重量"]);
    GrossLimitEdit->Text = ToCurrency(SET_TOP(set)["車両総重量"]);
    NetLimitEdit->Text   = ToCurrency(SET_TOP(set)["最大積載量"]);
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::TokuEditChange(TObject *Sender)
{
	int code = TokuEdit->Text.ToIntDef(0);

	NsRecordSet set;
	AnsiString sql = "SELECT 得意先略称 FROM M_得意先 WHERE 得意先コード = " + IntToStr(code);
	if (DM->DBI.GetRecordSet(sql, set)){
		TokuEdit->Text     = code;
		TokuNameEdit->Text = ToString(SET_TOP(set)["得意先略称"]);
	}else
		TokuNameEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::HinEditChange(TObject *Sender)
{
    int code = HinEdit->Text.ToIntDef(0);
    if (!code){
        HinNameEdit->Text = AnsiString();
        return;
    }

    AnsiString sql;
    NsRecordSet set;

    sql = "SELECT 品目名称 FROM M_品目 WHERE 品目コード = " + IntToStr(code);
    if (!DM->DBI.GetRecordSet(sql, set)){
        HinNameEdit->Text = AnsiString();
    }else{
        HinNameEdit->Text = ToString(SET_TOP(set)["品目名称"]);
    }
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item1EditChange(TObject *Sender)
{
	int code = Item1Edit->Text.ToIntDef(0);

	NsRecordSet set;
	AnsiString sql = "SELECT 項目1略称 FROM M_項目1 WHERE 項目1コード = " + IntToStr(code);
	if (DM->DBI.GetRecordSet(sql, set)){
		Item1Edit->Text     = code;
		Item1NameEdit->Text = ToString(SET_TOP(set)["項目1略称"]);
	}else
		Item1NameEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item2EditChange(TObject *Sender)
{
	int code = Item2Edit->Text.ToIntDef(0);

	NsRecordSet set;
	AnsiString sql = "SELECT 項目2名称 FROM M_項目2 WHERE 項目2コード = " + IntToStr(code);
	if (DM->DBI.GetRecordSet(sql, set)){
		Item2Edit->Text     = code;
		Item2NameEdit->Text = ToString(SET_TOP(set)["項目2名称"]);
	}else
		Item2NameEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarRefButtonClick(TObject *Sender)
{
    if (DM->Q_Shaban->Active)
        DM->Q_Shaban->Close();
    DM->Q_Shaban->SQL->Text = " SELECT"
                              "     車両ID, 車番, 車両名称, 空車重量, 得意先略称, 品目略称, 項目1略称, 項目2略称"
                              " FROM V_車両"
                              " WHERE"
                              "     使用区分 = 1";
    DM->Q_Shaban->Open();
    ShabanSanshoForm->TopPanel->Caption = "  車番：すべて";
    ShabanSanshoForm->NewButton->Visible = false;
    if (ShabanSanshoForm->ShowModal() != mrOk){
        return;
    }

    car_id_ = ShabanSanshoForm->GetCarID();
    AnsiString sql = " SELECT"
                     "  車両ID, 車番, 車両名称, 空車重量, 車両総重量, 最大積載量, "
                     "  得意先コード, 品目コード, 項目1コード, 項目2コード"
                     " FROM V_車両"
                     " WHERE"
                     "  使用区分 = 1"
                     " AND"
                     "  車両ID = " + IntToStr(car_id_);
    NsRecordSet set;
    if (!DM->DBI.GetRecordSet(sql, set)){
        return;
    }

    CarNoEdit->Text      = ToInt(SET_TOP(set)["車番"]);
    CarNameEdit->Text    = ToString(SET_TOP(set)["車両名称"]);
    if (ToInt(SET_TOP(set)["得意先コード"]))
        TokuEdit->Text   = ZeroSuppress(ToInt(SET_TOP(set)["得意先コード"]));
    if (ToInt(SET_TOP(set)["品目コード"]))
        HinEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["品目コード"]));
    if (ToInt(SET_TOP(set)["項目1コード"]))
        Item1Edit->Text  = ZeroSuppress(ToInt(SET_TOP(set)["項目1コード"]));
    if (ToInt(SET_TOP(set)["項目2コード"]))
        Item2Edit->Text  = ZeroSuppress(ToInt(SET_TOP(set)["項目2コード"]));
    TareEdit->Text       = ToCurrency(SET_TOP(set)["空車重量"]);
    GrossLimitEdit->Text = ToCurrency(SET_TOP(set)["車両総重量"]);
    NetLimitEdit->Text   = ToCurrency(SET_TOP(set)["最大積載量"]);

    TokuEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::TokuRefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT 得意先コード, 得意先略称 FROM M_得意先 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 得意先コード ";
    SearchForm->table_name = "M_得意先";
    if (SearchForm->ShowModal() != mrOk)
        return;
    TokuEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
    TokuEdit->OnChange(NULL);
    TokuEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::HinRefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT 品目コード, 品目略称 FROM M_品目 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 品目コード ";
    SearchForm->table_name = "M_品目";
    if (SearchForm->ShowModal() != mrOk)
        return;
    HinEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
    HinEdit->OnChange(NULL);
    HinEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item1RefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT 項目1コード, 項目1略称 FROM M_項目1 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目1コード ";
    SearchForm->table_name = "M_項目1";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item1Edit->Text = SearchForm->Query->FieldByName("項目1コード")->AsInteger;
    Item1Edit->OnChange(0);
    Item1Edit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item2RefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT 項目2コード, 項目2略称 FROM M_項目2 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目2コード ";
    SearchForm->table_name = "M_項目2";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item2Edit->Text = SearchForm->Query->FieldByName("項目2コード")->AsInteger;
    Item2Edit->OnChange(0);
    Item2Edit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarNoEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		CarRefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::TokuEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		TokuRefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::HinEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_F4)
		HinRefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item1EditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		Item1RefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item2EditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		Item2RefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::IssueButtonClick(TObject *Sender)
{
	if (!IsValidForm())
		return;
	IssueButton->Enabled = false;

	AnsiString sql;
	NsRecordSet set;
	NsFieldSet fields;
	bool succeeded = true;

	try{
		//DM->ADOConnection->BeginTrans();

        bool insert = car_id_ < 1 ? true : false;

        // 自動振り出しカード番号
		sql = "SELECT IsNull(MAX(カード番号), 500000) + 1 AS カード番号 FROM M_車両"
			  " WHERE カード番号 > 500000";
		DM->DBI.GetRecordSet(sql, set);
		int card_no = ToInt(SET_TOP(set)["カード番号"]);

        TDateTime now(Now());

        if (insert){
            fields << NsField("[車番]",     CarNoEdit->Text.ToIntDef(0))
                   << NsField("[作成日時]", now);
        }

		fields << NsField("[カード番号]",   card_no)
			   << NsField("[車両名称]",     CarNameEdit->Text)
               << NsField("[空車重量]",     TareEdit->Text.ToIntDef(0))
               << NsField("[最大積載量]",   NetLimitEdit->Text.ToIntDef(0))
               << NsField("[車両総重量]",   GrossLimitEdit->Text.ToIntDef(0))
               << NsField("[得意先ID]",     ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuEdit->Text.ToIntDef(0),  "得意先ID")))
               << NsField("[品目ID]",       ToInt(DM->DBI.Lookup("M_品目",   "品目コード",   HinEdit->Text.ToIntDef(0),   "品目ID")))
               << NsField("[項目1ID]",      ToInt(DM->DBI.Lookup("M_項目1",  "項目1コード",  Item1Edit->Text.ToIntDef(0), "項目1ID")))
               << NsField("[項目2ID]",      ToInt(DM->DBI.Lookup("M_項目2",  "項目2コード",  Item2Edit->Text.ToIntDef(0), "項目2ID")))
               << NsField("[使用区分]",     1)
               << NsField("[更新日時]",     now);
        if (insert)
    		DM->DBI.Insert("M_車両", fields);
        else
            DM->DBI.Update("M_車両", "車両ID", car_id_, fields);

		RFIDIssueForm->SetCommPort(rfid_comm_port_);
        RFIDIssueForm->SetCardNo(card_no);
		if (RFIDIssueForm->ShowModal() != mrOk)
			throw Exception("発行を中止しました");

		//DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		//DM->ADOConnection->RollbackTrans();

		AnsiString message = "エラーが発生しました - " + e.Message;

		Application->MessageBox(message.c_str(), "カード発行エラー", MB_OK | MB_ICONSTOP);

		succeeded = false;
	}

	IssueButton->Enabled = true;

	if (!succeeded)
		return;

	Application->MessageBox("カードを発行しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	ClearForm();
	CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::N24TPCardsButtonClick(TObject *Sender)
{
    int no = N24TPCardsForm->ShowModal();
    if (no < 90000000)
        return;

    RFIDIssueForm->SetCommPort(rfid_comm_port_);
    RFIDIssueForm->SetCardNo(no);
    if (RFIDIssueForm->ShowModal() != mrOk){
		Application->MessageBox("発行を中止しました", "カード発行エラー", MB_OK | MB_ICONSTOP);
        return;
    }
	Application->MessageBox("カードを発行しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::ClearButtonClick(TObject *Sender)
{
    ClearForm();
    CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------

