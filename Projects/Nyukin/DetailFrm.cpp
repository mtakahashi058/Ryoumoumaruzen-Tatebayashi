//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DetailFrm.h"
#include <StrUtils.hpp>
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "StrCGrid"
#pragma resource "*.dfm"
TDetailForm *DetailForm;
//---------------------------------------------------------------------------
__fastcall TDetailForm::TDetailForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormShow(TObject *Sender)
{
	ClearForm();

	if (id_ == 0){
		SetMode(imNew);
	}else{
		BrowseRecord(id_);
		SetMode(imMod);
	}

	DateEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 99 && ActiveControl->Tag != 2){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 99){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag != 0 && ActiveControl->Tag != 2 && ActiveControl->Tag != 99){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
int __fastcall TDetailForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == DateEdit){
		if (GetMode() == imMod)
			return;
		DatePicker->SetFocus();
		keybd_event(VK_F4, 0, 0, 0);
	}else if (ActiveControl == KyotenCodeEdit || ActiveControl == KyotenNameEdit){
		KyotenSearchButton->Click();
	}else if (ActiveControl == SeikyusakiCodeEdit || ActiveControl == SeikyusakiNameEdit){
		SeikyusakiSearchButton->Click();
	}else if (ActiveControl == BankCodeEdit || ActiveControl == BankNameEdit){
		BankSearchButton->Click();
	}else if (ActiveControl == KijituEdit){
		if (TegataEdit->Text == "")
			return;
		KijituPicker->SetFocus();
		keybd_event(VK_F4, 0, 0, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("登録しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	if (GetMode() == imNew){
		if (RenzokuCheckBox->Checked)
			ClearForm();
		else
			ModalResult = mrOk;
	}else{
		BrowseRecord(id_);
	}

	KyotenCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::Action12Execute(TObject *Sender)
{
	if (RenzokuCheckBox->Checked || GetMode() == imMod)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
TInputMode __fastcall TDetailForm::GetMode()
{
	if (ModePanel->Caption == "新規")
		return imNew;
	else if (ModePanel->Caption == "修正")
		return imMod;
	else if (ModePanel->Caption == "削除")
		return imDel;
	else
		return imNon;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption = "新規";
		ModePanel->Color = TColor(NEW_CLR);
		SlipNoEdit->ReadOnly = false;
		SlipNoEdit->Color = clWindow;
		RenzokuCheckBox->Enabled = true;
	}else if (mode == imMod){
		ModePanel->Caption = "修正";
		ModePanel->Color = TColor(MOD_CLR);
		SlipNoEdit->ReadOnly = true;
		SlipNoEdit->Color = clSilver;
		RenzokuCheckBox->Checked = false;
		RenzokuCheckBox->Enabled = false;
	}else if (mode == imDel){
		ModePanel->Caption = "削除";
		ModePanel->Color = TColor(DEL_CLR);
	}
}
//---------------------------------------------------------------------------
int __fastcall TDetailForm::GetNo()
{
	int id = ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", KyotenCodeEdit->Text.ToIntDef(0), "拠点ID", ""));

	AnsiString sql = "SELECT ISNULL(MAX(伝票No), 0) + 1 AS 伝票番号 FROM D_入金 WHERE 拠点ID = " + IntToStr(id);
	NsRecordSet set;

	if (DM->DBI.GetRecordSet(sql, set))
		return ToInt(set[0]["伝票番号"]);
	else
		return 1;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::ClearForm()
{
	KyotenCodeEdit->Text = ToInt(DM->INI["Place::Code"]);

	SlipNoEdit->Text = GetNo();
	DateEdit->Text   = DateToStr(Date());
	DatePicker->Date = Date();

	SeikyusakiCodeEdit->Text = AnsiString();

	GenkinEdit->Text   = AnsiString();
	HurikomiEdit->Text = AnsiString();
	TesuryoEdit->Text  = AnsiString();
	KogitteEdit->Text  = AnsiString();
	TegataEdit->Text   = AnsiString();
	SousaiEdit->Text   = AnsiString();
	NebikiEdit->Text   = AnsiString();
	ChoseiEdit->Text   = AnsiString();
	SonotaEdit->Text   = AnsiString();
	GokeiEdit->Text    = AnsiString();

	BankCodeEdit->Text    = AnsiString();
	KijituEdit->Text      = AnsiString();
	KijituEdit->ReadOnly  = true;
	KijituEdit->Color     = clSilver;
	KijituPicker->Date    = Date();
	KijituPicker->Enabled = false;
	BikoEdit->Text        = AnsiString();

	RenewDateLabel->Caption  = AnsiString();
	CreateDateLabel->Caption = AnsiString();

	NyukinDatePicker->Date = Date();
	NyukinDatePicker->OnChange(NULL);

	for (int i = 1; i < 8; i++){
		StrColGrid->Cells[0][i] = AnsiString();
		StrColGrid->Cells[1][i] = AnsiString();
		StrColGrid->Cells[2][i] = AnsiString();
		StrColGrid->Cells[3][i] = AnsiString();
		StrColGrid->Cells[4][i] = AnsiString();
		StrColGrid->Cells[5][i] = AnsiString();
		StrColGrid->Cells[6][i] = AnsiString();
		StrColGrid->Cells[7][i] = AnsiString();
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BrowseRecord(int id)
{
	AnsiString sql = AnsiString();
	sql =
		" SELECT"
		" 	拠点コード,"
		" 	伝票No,"
		" 	入金日,"
		" 	請求先コード,"
		" 	現金,"
		" 	振込,"
		" 	手数料,"
		" 	小切手,"
		" 	手形,"
		" 	相殺,"
		" 	値引き,"
		" 	調整,"
		" 	その他,"
		" 	銀行コード,"
		" 	手形期日,"
		" 	備考,"
		" 	更新日時,"
		" 	作成日時"
		" FROM"
		" 	V_入金"
		" WHERE"
		" 	入金ID = " + IntToStr(id);
	NsRecordSet set;

	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータが見つかりませんでした",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	KyotenCodeEdit->Text     = ToInt(set[0]["拠点コード"]);
	SlipNoEdit->Text         = ToInt(set[0]["伝票No"]);
	DateEdit->Text           = IntToDate(ToInt(set[0]["入金日"]));
	DatePicker->Date         = IntToDate(ToInt(set[0]["入金日"]));
	if (ToInt(set[0]["銀行コード"]))
		BankCodeEdit->Text = ToInt(set[0]["銀行コード"]);
	else
		BankCodeEdit->Text = AnsiString();
	SeikyusakiCodeEdit->Text = ToInt(set[0]["請求先コード"]);
	if (ToCurrency(set[0]["現金"]) != 0)
		GenkinEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["現金"]));
	else
		GenkinEdit->Text = AnsiString();
	if (ToCurrency(set[0]["振込"]) != 0)
		HurikomiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["振込"]));
	else
		HurikomiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["手数料"]) != 0)
		TesuryoEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["手数料"]));
	else
		TesuryoEdit->Text = AnsiString();
	if (ToCurrency(set[0]["小切手"]) != 0)
		KogitteEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["小切手"]));
	else
		KogitteEdit->Text = AnsiString();
	if (ToCurrency(set[0]["手形"]) != 0)
		TegataEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["手形"]));
	else
		TegataEdit->Text = AnsiString();
	if (ToCurrency(set[0]["相殺"]) != 0)
		SousaiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["相殺"]));
	else
		SousaiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["値引き"]) != 0)
		NebikiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["値引き"]));
	else
		NebikiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["調整"]) != 0)
		ChoseiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["調整"]));
	else
		ChoseiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["その他"]) != 0)
		SonotaEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["その他"]));
	else
		SonotaEdit->Text = AnsiString();
	GenkinEdit->OnExit(NULL);

	if (!set[0]["手形期日"].IsNull()){
		KijituEdit->Text   = IntToDate(ToInt(set[0]["手形期日"]));
		KijituPicker->Date = IntToDate(ToInt(set[0]["手形期日"]));
	}else{
		KijituEdit->Text   = AnsiString();
		KijituPicker->Date = DateToStr(Date());
	}
	BikoEdit->Text = ToString(set[0]["備考"]);

	RenewDateLabel->Caption  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateLabel->Caption = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
bool __fastcall TDetailForm::CheckEdit()
{
	if (KyotenCodeEdit->Text == ""){
		Application->MessageBox("拠点が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		KyotenCodeEdit->SetFocus();
		return false;
	}

	if (SlipNoEdit->Text == ""){
		Application->MessageBox("伝票番号が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		SlipNoEdit->SetFocus();
		return false;
	}

	TDateTime dt;
	try{
		dt = StrToDate(DateEdit->Text);
	}catch (Exception &e){
		Application->MessageBox(("日付を再入力して下さい\r\n" + e.Message).c_str(),
			"【日付と認識できない入力】", MB_OK | MB_ICONWARNING);
		DateEdit->Text = DateToStr(Date());
		DateEdit->SetFocus();
		return false;
	}
	if (DateToInt(dt) < 17520914 || DateToInt(dt) > 99991231){
		Application->MessageBox("日付を再入力して下さい",
			"【日付と認識できない入力】", MB_OK | MB_ICONWARNING);
		DateEdit->Text = DateToStr(Date());
		DateEdit->SetFocus();
		return false;
	}

	if (SeikyusakiCodeEdit->Text == ""){
		Application->MessageBox("請求先が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		SeikyusakiCodeEdit->SetFocus();
		return false;
	}

	if (!KijituEdit->ReadOnly){
		try{
			dt = StrToDate(KijituEdit->Text);
		}catch (Exception &e){
			Application->MessageBox(("日付を再入力して下さい\r\n" + e.Message).c_str(),
				"【日付と認識できない入力】", MB_OK | MB_ICONWARNING);
			KijituEdit->Text = DateToStr(Date());
			KijituEdit->SetFocus();
			return false;
		}
		if (DateToInt(dt) < 17520914 || DateToInt(dt) > 99991231){
			Application->MessageBox("日付を再入力して下さい",
				"【日付と認識できない入力】", MB_OK | MB_ICONWARNING);
			KijituEdit->Text = DateToStr(Date());
			KijituEdit->SetFocus();
			return false;
		}
	}

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TDetailForm::PostRecord()
{
	NsFieldSet fields;

	try{
		DM->ADOConnection->BeginTrans();

		fields
			<< NsField("[拠点ID]",   ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", KyotenCodeEdit->Text.ToIntDef(0), "拠点ID", "")))
			<< NsField("[入金日]",   RemoveSlash(DateEdit->Text))
			<< NsField("[請求先ID]", ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "得意先ID", "")))
			<< NsField("[現金]",     StrToCurrDef(AnsiReplaceStr(GenkinEdit->Text, ",", ""), 0))
			<< NsField("[振込]",     StrToCurrDef(AnsiReplaceStr(HurikomiEdit->Text, ",", ""), 0))
			<< NsField("[手数料]",   StrToCurrDef(AnsiReplaceStr(TesuryoEdit->Text, ",", ""), 0))
			<< NsField("[小切手]",   StrToCurrDef(AnsiReplaceStr(KogitteEdit->Text, ",", ""), 0))
			<< NsField("[手形]",     StrToCurrDef(AnsiReplaceStr(TegataEdit->Text, ",", ""), 0))
			<< NsField("[相殺]",     StrToCurrDef(AnsiReplaceStr(SousaiEdit->Text, ",", ""), 0))
			<< NsField("[値引き]",   StrToCurrDef(AnsiReplaceStr(NebikiEdit->Text, ",", ""), 0))
			<< NsField("[調整]",     StrToCurrDef(AnsiReplaceStr(ChoseiEdit->Text, ",", ""), 0))
			<< NsField("[その他]",   StrToCurrDef(AnsiReplaceStr(SonotaEdit->Text, ",", ""), 0))
			<< NsField("[備考]",     BikoEdit->Text)
			<< NsField("[更新日時]", Now());

		if (BankCodeEdit->Text != "")
			fields << NsField("[銀行ID]", ToInt(DM->DBI.Lookup("M_銀行", "銀行コード", BankCodeEdit->Text.ToIntDef(0), "銀行ID", "")));
		else
			fields << NsField("[銀行ID]", Variant());

		if (TegataEdit->Text != "")
			fields << NsField("[手形期日]", RemoveSlash(KijituEdit->Text));
		else
			fields << NsField("[手形期日]", Variant());

		if (id_ == 0){
			fields	<< NsField("[伝票No]", GetNo())
				<< NsField("[作成日時]", Now());
			DM->DBI.Insert("D_入金", fields);
		}else{
			fields	<< NsField("[伝票No]", SlipNoEdit->Text.ToIntDef(0));
			DM->DBI.Update("D_入金", "入金ID", id_, fields);
		}

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("登録に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SetSeikyuDate()
{
	if (SeikyusakiCodeEdit->Text == "")
		return;

	AnsiString sql = "SELECT MAX(入金予定日) AS 入金予定日 FROM V_請求 WHERE 入金予定日 <= " + RemoveSlash(DateEdit->Text) + " AND 請求先ID = " + ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "得意先ID", ""));
	NsRecordSet set;
	if (!DM->DBI.GetRecordSet(sql, set)){
		NyukinDatePicker->Date = Date();
		return;
	}

	if (set[0]["入金予定日"].IsNull()){
		NyukinDatePicker->Date = Date();
		return;
	}

	NyukinDatePicker->Date = IntToDate(ToInt(set[0]["入金予定日"]));
	NyukinDatePicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DateEditEnter(TObject *Sender)
{
	DateEdit->Text = AnsiReplaceStr(DateEdit->Text, "/", "");
	DateEdit->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DateEditExit(TObject *Sender)
{
	if (DateEdit->Text.AnsiPos("/") == 0)
		DateEdit->Text = IntToDate(DateEdit->Text.ToIntDef(0));

	try{
		DatePicker->Date = StrToDate(DateEdit->Text);
	}catch (...){
		DatePicker->Date = Date();
	}

	SetSeikyuDate();

	if (GetMode() == imMod)
		return;

	SlipNoEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DateMaskEditExit(TObject *Sender)
{
/*
	try{
		DatePicker->Date = StrToDate(DateMaskEdit->Text);
	}catch (...){
		DatePicker->Date = Date();
	}

	if (GetMode() == imMod)
		return;

	SlipNoEdit->Text = GetNo();
*/
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerChange(TObject *Sender)
{
	try{
		DateEdit->Text = DateToStr(DatePicker->Date);
	}catch (...){
		DateEdit->Text = DateToStr(Date());
	}

	SetSeikyuDate();

	if (GetMode() == imMod)
		return;

	SlipNoEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerCloseUp(TObject *Sender)
{
	keybd_event(VK_TAB, 0, 0, 0);
//	SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerEnter(TObject *Sender)
{
	Action4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SlipNoEditExit(TObject *Sender)
{
	if (DateEdit->Text == "" || SlipNoEdit->Text == "")
		return;

	AnsiString sql = "SELECT 入金ID FROM D_入金 WHERE 入金日 = " + RemoveSlash(DateEdit->Text) + " AND 伝票No = " + SlipNoEdit->Text;
	NsRecordSet set;
	if (!DM->DBI.GetRecordSet(sql, set))
		return;

	BrowseRecord(ToInt(set[0]["入金ID"]));
	SetMode(imMod);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SaibanButtonClick(TObject *Sender)
{
	SlipNoEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KyotenCodeEditChange(TObject *Sender)
{
	if (KyotenCodeEdit->Text == ""){
		KyotenNameEdit->Text = AnsiString();
		return;
	}
	KyotenNameEdit->Text = ToString(DM->DBI.Lookup("M_拠点", "拠点コード", KyotenCodeEdit->Text.ToIntDef(0), "拠点名称", ""));
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KyotenSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = "SELECT 拠点コード, 拠点名称 FROM M_拠点";
	SearchForm->orderby_sql      = "ORDER BY 拠点コード";
	SearchForm->table_name       = "M_拠点";
	SearchForm->list_->CommaText = "拠点コード,拠点名称";

	if (SearchForm->ShowModal() != mrOk)
		return;
	KyotenCodeEdit->Text = SearchForm->Query->FieldByName("拠点コード")->AsInteger;
	KyotenCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SeikyusakiCodeEditChange(TObject *Sender)
{
	if (SeikyusakiCodeEdit->Text == ""){
		SeikyusakiNameEdit->Text = AnsiString();
		SiteLabel->Caption       = AnsiString();
		LastTesuryoLabel->Caption = "※前回の振込手数料 -----円";
		return;
	}

	// 振込手数料
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT TOP 1 手数料 FROM V_入金 WHERE 請求先コード = " + IntToStr(SeikyusakiCodeEdit->Text.ToIntDef(0)) + " AND 振込 <> 0 ORDER BY 入金日 DESC, 伝票No DESC", set);
	if (ToInt(set[0]["手数料"]) != 0)
		LastTesuryoLabel->Caption = "※前回の振込手数料 " + FormatFloat("#,##0", ToInt(set[0]["手数料"])) + "円";
	else
		LastTesuryoLabel->Caption = "※前回の振込手数料 -----円";
	
	try{
		SeikyusakiNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1"));
		AnsiString site = ToString(DM->DBI.Lookup("M_区分", "区分コード", DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "入金サイト", "使用区分 = 1"), "区分名称", "区分分類コード = 6"));
		AnsiString day  = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "入金日", "使用区分 = 1"));
		SiteLabel->Caption = "入金サイト：" + site + day + "日";
		SetSeikyuDate();
		NyukinDatePicker->OnChange(NULL);

		for (int i = 1; i < 8; i++){
			StrColGrid->Cells[0][i] = AnsiString();
			StrColGrid->Cells[1][i] = AnsiString();
			StrColGrid->Cells[2][i] = AnsiString();
			StrColGrid->Cells[3][i] = AnsiString();
			StrColGrid->Cells[4][i] = AnsiString();
			StrColGrid->Cells[5][i] = AnsiString();
			StrColGrid->Cells[6][i] = AnsiString();
			StrColGrid->Cells[7][i] = AnsiString();
		}
		AnsiString sql = AnsiString();
		NsRecordSet set;
		// 過去6ヶ月間の請求データ表示
		sql =
			" SELECT"
			" 	TOP 7"
			" 	締切日,"
			" 	ISNULL(前回請求額, 0) AS 前回請求額,"
			" 	ISNULL(今回入金額, 0) AS 今回入金額,"
			" 	ISNULL(今回調整額, 0) AS 今回調整額,"
			" 	ISNULL(今回繰越額, 0) AS 今回繰越額,"
			" 	ISNULL(今回売上額, 0) + ISNULL(今回消費税額, 0) AS 今回売上額,"
			" 	ISNULL(今回請求額, 0) AS 今回請求額,"
			" 	入金予定日"
			" FROM"
			" 	V_請求"
			" WHERE"
			" 	締切日 BETWEEN " + GetFirstDate(IncMonth(Date(), -6)).FormatString("yyyymmdd") +
						 " AND " + GetLastDate(Date()).FormatString("yyyymmdd") +
			" AND"
			" 	得意先コード = " + SeikyusakiCodeEdit->Text +
			" ORDER BY"
			" 	締切日 DESC";
		set.clear();
		if (!DM->DBI.GetRecordSet(sql, set))
			return;

		for (unsigned int i = 0; i < set.size(); i++){
			StrColGrid->Cells[0][i + 1] = IntToDate(ToInt(set[i]["締切日"]));
			StrColGrid->Cells[1][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["前回請求額"]));
			StrColGrid->Cells[2][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["今回入金額"]));
			StrColGrid->Cells[3][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["今回調整額"]));
			StrColGrid->Cells[4][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["今回繰越額"]));
			StrColGrid->Cells[5][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["今回売上額"]));
			StrColGrid->Cells[6][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["今回請求額"]));
			StrColGrid->Cells[7][i + 1] = IntToDate(ToInt(set[i]["入金予定日"]));
		}
	}catch (...){
		for (int i = 1; i < 8; i++){
			StrColGrid->Cells[0][i] = AnsiString();
			StrColGrid->Cells[1][i] = AnsiString();
			StrColGrid->Cells[2][i] = AnsiString();
			StrColGrid->Cells[3][i] = AnsiString();
			StrColGrid->Cells[4][i] = AnsiString();
			StrColGrid->Cells[5][i] = AnsiString();
			StrColGrid->Cells[6][i] = AnsiString();
			StrColGrid->Cells[7][i] = AnsiString();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SeikyusakiSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1";
	SearchForm->orderby_sql      = "ORDER BY 得意先コード";
	SearchForm->table_name       = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BankCodeEditChange(TObject *Sender)
{
	if (BankCodeEdit->Text == ""){
		BankNameEdit->Text = AnsiString();
		SitenEdit->Text    = AnsiString();
		KouzaEdit->Text    = AnsiString();
		return;
	}
	BankNameEdit->Text = ToString(DM->DBI.Lookup("M_銀行", "銀行コード", BankCodeEdit->Text.ToIntDef(0), "銀行名称", ""));
	SitenEdit->Text    = ToString(DM->DBI.Lookup("M_銀行", "銀行コード", BankCodeEdit->Text.ToIntDef(0), "支店名称", ""));
	KouzaEdit->Text    = ToString(DM->DBI.Lookup("M_銀行", "銀行コード", BankCodeEdit->Text.ToIntDef(0), "口座", ""));
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BankSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = " SELECT 銀行コード, 銀行名称, 支店名称, 口座 FROM M_銀行";
	SearchForm->orderby_sql      = " ORDER BY 銀行コード";
	SearchForm->table_name       = "M_銀行";
	SearchForm->list_->CommaText = "銀行コード,銀行名称,支店名称,口座";

	if (SearchForm->ShowModal() != mrOk)
		return;
	BankCodeEdit->Text = SearchForm->Query->FieldByName("銀行コード")->AsInteger;
	BankCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::GenkinEditExit(TObject *Sender)
{
	if (StrToCurrDef(AnsiReplaceStr(GenkinEdit->Text, ",", ""), 0) == 0  && StrToCurrDef(AnsiReplaceStr(HurikomiEdit->Text, ",", ""), 0) == 0 &&
		StrToCurrDef(AnsiReplaceStr(TesuryoEdit->Text, ",", ""), 0) == 0 && StrToCurrDef(AnsiReplaceStr(KogitteEdit->Text, ",", ""), 0) == 0  &&
		StrToCurrDef(AnsiReplaceStr(TegataEdit->Text, ",", ""), 0) == 0  && StrToCurrDef(AnsiReplaceStr(SousaiEdit->Text, ",", ""), 0) == 0   &&
		StrToCurrDef(AnsiReplaceStr(NebikiEdit->Text, ",", ""), 0) == 0  && StrToCurrDef(AnsiReplaceStr(ChoseiEdit->Text, ",", ""), 0) == 0   &&
		StrToCurrDef(AnsiReplaceStr(SonotaEdit->Text, ",", ""), 0) == 0)
		return;

	GokeiEdit->Text = FormatFloat("#,##0",
		StrToCurrDef(AnsiReplaceStr(GenkinEdit->Text, ",", ""), 0)  + StrToCurrDef(AnsiReplaceStr(HurikomiEdit->Text, ",", ""), 0) +
		StrToCurrDef(AnsiReplaceStr(TesuryoEdit->Text, ",", ""), 0) + StrToCurrDef(AnsiReplaceStr(KogitteEdit->Text, ",", ""), 0)  +
		StrToCurrDef(AnsiReplaceStr(TegataEdit->Text, ",", ""), 0)  + StrToCurrDef(AnsiReplaceStr(SousaiEdit->Text, ",", ""), 0)   +
		StrToCurrDef(AnsiReplaceStr(NebikiEdit->Text, ",", ""), 0)  + StrToCurrDef(AnsiReplaceStr(ChoseiEdit->Text, ",", ""), 0)   +
		StrToCurrDef(AnsiReplaceStr(SonotaEdit->Text, ",", ""), 0));

	((TCobEdit *)Sender)->Text = FormatFloat("#,###", StrToCurrDef(((TCobEdit *)Sender)->Text, 0));
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::TegataEditChange(TObject *Sender)
{
	if (TegataEdit->Text == ""){
		KijituEdit->ReadOnly = true;
		KijituEdit->Color = clSilver;
		KijituPicker->Enabled = false;
	}else{
		KijituEdit->ReadOnly = false;
		KijituEdit->Color = clWindow;
		KijituPicker->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituEditEnter(TObject *Sender)
{
	KijituEdit->Text = AnsiReplaceStr(KijituEdit->Text, "/", "");
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituEditExit(TObject *Sender)
{
	if (KijituEdit->Text == "")
		return;
	
	try{
		if (KijituEdit->Text.AnsiPos("/") == 0)
			KijituEdit->Text = IntToDate(KijituEdit->Text.ToIntDef(0));

		KijituPicker->Date = StrToDate(KijituEdit->Text);
	}catch (...){
		KijituPicker->Date = Date();
		KijituEdit->Text   = KijituPicker->Date;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerChange(TObject *Sender)
{
	try{
		KijituEdit->Text = DateToStr(KijituPicker->Date);
	}catch (...){
		KijituEdit->Text = DateToStr(Date());
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerCloseUp(TObject *Sender)
{
	BikoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerEnter(TObject *Sender)
{
	Action4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::GenkinEditEnter(TObject *Sender)
{
	((TCobEdit *)Sender)->Text = AnsiReplaceStr(((TCobEdit *)Sender)->Text, ",", "");
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BrowseSeikyuInfo()
{
	YoteigakuEdit->Text = "----------";
	NyukinEdit->Text    = "----------";
	SagakuEdit->Text    = "----------";

	if (SeikyusakiCodeEdit->Text == "")
		return;

	AnsiString from_date, to_date;
	from_date = RemoveSlash(DateToStr(GetFirstDate(NyukinDatePicker->Date)));
	to_date   = RemoveSlash(DateToStr(GetLastDate(NyukinDatePicker->Date)));
	NsRecordSet set;
	AnsiString sql =
		" SELECT"
		" 	TOP 1"
		" 	得意先コード AS 請求先コード,"
		" 	今回請求額,"
		" 	締切日"
		" FROM"
		" 	V_請求"
		" WHERE"
		" 	入金予定日 BETWEEN " + from_date + " AND " + to_date +
		" AND"
		" 	得意先コード = " + SeikyusakiCodeEdit->Text +
		" ORDER BY"
		" 	締切日 DESC";
	try{
		if (!DM->DBI.GetRecordSet(sql, set)){
			YoteigakuEdit->Text = "----------";
			NyukinEdit->Text    = "----------";
			SagakuEdit->Text    = "----------";
		}else{
			YoteigakuEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["今回請求額"]));

			sql =
				" SELECT"
				" 	請求先コード,"
				" 	ISNULL(SUM(現金), 0) + ISNULL(SUM(振込), 0)   + ISNULL(SUM(手数料), 0) + ISNULL(SUM(小切手), 0) + ISNULL(SUM(手形), 0) +"
				" 	ISNULL(SUM(相殺), 0) + ISNULL(SUM(値引き), 0) + ISNULL(SUM(調整), 0)   + ISNULL(SUM(その他), 0) AS 入金額"
				" FROM"
				" 	V_入金"
				" WHERE"
				" 	入金日 > " + ToString(set[0]["締切日"]) +
				" AND"
				" 	請求先コード = " + SeikyusakiCodeEdit->Text +
				" GROUP BY"
				" 	請求先コード";
			set.clear();
			DM->DBI.GetRecordSet(sql, set);

			NyukinEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["入金額"]));
			SagakuEdit->Text = FormatFloat("#,##0", StrToCurrDef(AnsiReplaceStr(YoteigakuEdit->Text, ",", ""), 0) - StrToCurrDef(AnsiReplaceStr(NyukinEdit->Text, ",", ""), 0));
		}
	}catch (...){
		YoteigakuEdit->Text = "----------";
		NyukinEdit->Text    = "----------";
		SagakuEdit->Text    = "----------";
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::NyukinDatePickerChange(TObject *Sender)
{
	BrowseSeikyuInfo();
	StrColGrid->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::PriorButtonClick(TObject *Sender)
{
	NyukinDatePicker->Date = IncMonth(NyukinDatePicker->Date, -1);
	NyukinDatePicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::NextButtonClick(TObject *Sender)
{
	NyukinDatePicker->Date = IncMonth(NyukinDatePicker->Date, 1);
	NyukinDatePicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::StrColGridDrawCell(TObject *Sender, int ACol,
	  int ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow == 0)
		return;

	if (StrColGrid->Cells[7][ARow] == "")
		return;

	AnsiString nyukin = NyukinDatePicker->Date.FormatString("yyyymm");
	if (nyukin == RemoveSlash(StrColGrid->Cells[7][ARow]).SubString(1, 6)){
		if (DateToInt(StrToDate(StrColGrid->Cells[7][ARow])) <= DateToInt(DatePicker->Date)){
			StrColGrid->Canvas->Brush->Color = TColor(0x00D7CBFE);
			StrColGrid->Canvas->FillRect(Rect);
		}else{
			StrColGrid->Canvas->Brush->Color = clWhite;
			StrColGrid->Canvas->FillRect(Rect);
		}
	}else{
		StrColGrid->Canvas->Brush->Color = clWhite;
		StrColGrid->Canvas->FillRect(Rect);
	}

	UINT opt = 0;
	switch(ACol){
		case 0:
		case 7:
			opt = DT_VCENTER | DT_CENTER | DT_SINGLELINE;
			break;

		default:  //数値は右寄せ
			opt = DT_VCENTER | DT_RIGHT | DT_SINGLELINE;
			break;
	}

	DrawText(StrColGrid->Canvas->Handle, StrColGrid->Cells[ACol][ARow].c_str(), -1, &Rect, opt);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

