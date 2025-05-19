//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DetailFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TDetailForm *DetailForm;
//---------------------------------------------------------------------------
__fastcall TDetailForm::TDetailForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// ShowModal
int __fastcall TDetailForm::ShowModalWithID(int id)
{
	id_ = id;
	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
// DetailForm->OnShow
void __fastcall TDetailForm::FormShow(TObject *Sender)
{
	if (id_ == 0){
		ClearForm(true);
		SetMode(imNew);
		SimekiribiMaskEdit->SetFocus();
	}else{
		BrowseRecord(id_);
		cedtZenSeikyu->SetFocus();
	}

	is_edit_ = false;

	post_count_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 99  && ActiveControl->Tag != 1){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 99){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 99){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
// データを表示する
void __fastcall TDetailForm::BrowseRecord(int id)
{
	NsRecordSet set;

	if (!DM->DBI.GetRecordSet("SELECT * FROM V_請求 WHERE 請求ID = " + IntToStr(id), set)){
		SetMode(imNew);
		ClearForm(true);
		return;
	}
	SetMode(imMod);

	cedtID->Text = set[0]["請求ID"];
	SimekiribiPicker->Date = IntToDate(ToInt(set[0]["締切日"]));
	SimekiribiMaskEdit->Text = DateToStr(SimekiribiPicker->Date);
	cedtSeikyuCode->Text = set[0]["得意先コード"];
	cedtZenSeikyu->Text = set[0]["前回請求額"];
	cedtKonNyukin->Text = set[0]["今回入金額"];
	cedtKonChosei->Text = set[0]["今回調整額"];
	cedtKonKurikosi->Text = set[0]["今回繰越額"];
	cedtKonUriage->Text = set[0]["今回売上額"];
	cedtKonShohizei->Text = set[0]["今回消費税額"];
	cedtKonSeikyu->Text = set[0]["今回請求額"];
	try{
		dtpNyukinYotei->Date = IntToDate(ToInt(set[0]["入金予定日"]));
	}catch (...){
		dtpNyukinYotei->Date = IntToDate(ToInt(set[0]["締切日"]));
		dtpNyukinYotei->Checked = false;
	}
}
//---------------------------------------------------------------------------
// id == 0 の場合⇒新規  id != 0 の場合⇒修正
bool __fastcall TDetailForm::PostRecord(int id)
{
	NsFieldSet keys;
	NsFieldSet fields;

	if (id != 0)
		keys << NsField("請求ID", id);

	fields << NsField("[締切日]", RemoveSlash(SimekiribiMaskEdit->Text).ToIntDef(0));
	fields << NsField("[請求先ID]", DM->DBI.Lookup("M_得意先", "得意先コード", cedtSeikyuCode->Text.ToIntDef(0), "得意先ID", ""));
	fields << NsField("[前回請求額]", StrToCurrDef(cedtZenSeikyu->Text, 0));
	fields << NsField("[今回入金額]", StrToCurrDef(cedtKonNyukin->Text, 0));
	fields << NsField("[今回調整額]", StrToCurrDef(cedtKonChosei->Text, 0));
	fields << NsField("[今回繰越額]", StrToCurrDef(cedtKonKurikosi->Text, 0));
	fields << NsField("[今回売上額]", StrToCurrDef(cedtKonUriage->Text, 0));
	fields << NsField("[今回消費税額]", StrToCurrDef(cedtKonShohizei->Text, 0));
	fields << NsField("[今回請求額]", StrToCurrDef(cedtKonSeikyu->Text, 0));
	if (dtpNyukinYotei->Checked)
		fields << NsField("入金予定日", DateToInt(dtpNyukinYotei->Date));
	else
		fields << NsField("入金予定日", Variant());
	fields << NsField("更新日時", Now());
	if (id == 0)
		fields << NsField("作成日時", Now());

	try{
		if (id == 0)
			DM->DBI.Insert("D_請求", fields);
		else
			DM->DBI.Update("D_請求", keys, fields);

	}catch (Exception& e){
		Application->MessageBox(("登録に失敗しました\r\nエラー：" + e.Message).c_str(), "登録", MB_OK | MB_ICONSTOP);
		return false;
	}

	is_edit_ = true;
	post_count_++;
	return true;
}
//---------------------------------------------------------------------------
// フォームのクリア
void __fastcall TDetailForm::ClearForm(bool date_clear)
{
	cedtID->Text = "0";
	if (date_clear){
		SimekiribiPicker->Date = Date();
		SimekiribiMaskEdit->Text = DateToStr(Date());
	}
	cedtSeikyuCode->Text = "";
	cedtSeikyuCode->OnChange(NULL);
	cedtZenSeikyu->Text = "";
	cedtKonNyukin->Text = "";
	cedtKonChosei->Text = "";
	cedtKonKurikosi->Text = "";
	cedtKonUriage->Text = "";
	cedtKonShohizei->Text = "";
	cedtKonSeikyu->Text = "";
	dtpNyukinYotei->Date = Date();
	dtpNyukinYotei->Checked = false;
}
//---------------------------------------------------------------------------
// モードを設定する
void __fastcall TDetailForm::SetMode(TInputMode Mode)
{
	switch(Mode){
	case imNew:
		pnlMode->Caption = "新規";
		pnlMode->Color = clSkyBlue;
		break;
	case imMod:
		pnlMode->Caption = "修正";
		pnlMode->Color = clMoneyGreen;
		break;
	case imDel:
		pnlMode->Caption = "削除";
		pnlMode->Color = TColor(0x00E4DDFF);
		break;
	}
}
//---------------------------------------------------------------------------
// 現在のモードを取得する
TInputMode __fastcall TDetailForm::GetMode()
{
	if (pnlMode->Caption == "新規")
		return imNew;
	else if (pnlMode->Caption == "修正")
		return imMod;
	else if (pnlMode->Caption == "削除")
		return imDel;
	throw Exception("入力モードが異常です");
}
//---------------------------------------------------------------------------
// 請求先コード->OnChange
void __fastcall TDetailForm::cedtSeikyuCodeChange(TObject *Sender)
{
	cedtSeikyuName->Text = DM->DBI.Lookup("M_得意先", "得意先コード", cedtSeikyuCode->Text.ToIntDef(0), "得意先名称", "使用区分 = 1 AND 得意先ID = 請求先ID");
	SetNyukinYotei();
}
//---------------------------------------------------------------------------
// 今回繰越額＝前回請求額－今回入金額－今回調整額
void __fastcall TDetailForm::cedtZenSeikyuChange(TObject *Sender)
{
	cedtKonKurikosi->Text =	StrToCurrDef(cedtZenSeikyu->Text, 0) -
				StrToCurrDef(cedtKonNyukin->Text, 0) -
				StrToCurrDef(cedtKonChosei->Text, 0);
}
//---------------------------------------------------------------------------
// 今回請求額＝今回繰越額＋今回売上額＋今回消費税額
void __fastcall TDetailForm::cedtKonUriageChange(TObject *Sender)
{
	int tax_rate     = DM->GetShohizeiritu(RemoveSlash(SimekiribiMaskEdit->Text));
	int tax_fraction = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", cedtSeikyuCode->Text.ToIntDef(0), "消費税端数処理区分", ""));
	// 消費税端数処理区分が見つからない場合、「切り捨て」がデフォルト

	Currency money = StrToCurrDef(cedtKonUriage->Text, 0);
	Currency tax = 0;
	tax = money * tax_rate / 100;
	TaxLabel->Caption = AnsiString();

	if (tax != 0)
		tax = ExtendedRound(tax, 0, tax_fraction);

	cedtKonShohizei->Text = tax;

	cedtKonSeikyu->Text = 	StrToCurrDef(cedtKonKurikosi->Text, 0) +
				StrToCurrDef(cedtKonUriage->Text, 0) +
				StrToCurrDef(cedtKonShohizei->Text, 0);
}
//---------------------------------------------------------------------------
// 締切日->OnChange
// 入金予定日を取得
void __fastcall TDetailForm::SetNyukinYotei()
{
	if (cedtSeikyuCode->Text.ToIntDef(0) == 0)
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT * FROM M_得意先 WHERE 得意先コード = " + IntToStr(cedtSeikyuCode->Text.ToIntDef(0)), set)){
		dtpNyukinYotei->Checked = false;
		return;
	}

	dtpNyukinYotei->Date = GetNyukinYotei(StrToDate(SimekiribiMaskEdit->Text), ToInt(set[0]["入金サイト"]), ToInt(set[0]["入金日"]));
	dtpNyukinYotei->Checked = true;
}
//---------------------------------------------------------------------------
// 入金予定日->OnKeyDown
void __fastcall TDetailForm::dtpNyukinYoteiKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN)
		btnOk->OnClick(NULL);
}
//---------------------------------------------------------------------------
// 入金予定日を取得
TDateTime __fastcall TDetailForm::GetNyukinYotei(TDateTime dt, int site, int sime)
{
	WORD y, m, d;

	dt = IncMonth(dt, site);
	dt.DecodeDate(&y, &m, &d);

	if (sime < 1 || 31 < sime)
		return GetLastDate(dt);
	else{
		try{
			return EncodeDate(y, m, sime);
		}catch (...){
			return GetLastDate(dt);
		}
	}
}
//---------------------------------------------------------------------------
// 請求先検索
void __fastcall TDetailForm::SanshoActionExecute(TObject *Sender)
{
	if (ActiveControl == SimekiribiMaskEdit){
		if (GetMode() == imMod)
			return;
		SimekiribiPicker->SetFocus();
		keybd_event(VK_F4, 0, 0, 0);
	}
	
	if (ActiveControl != cedtSeikyuCode && ActiveControl != cedtSeikyuName)
		return;
	btnSeikyu->OnClick(NULL);
}
//---------------------------------------------------------------------------
// 登録処理
void __fastcall TDetailForm::PostActionExecute(TObject *Sender)
{
	if (Application->MessageBox("登録しますか？", "OK", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	NsRecordSet set;
	if (GetMode() == imNew){
		if (DM->DBI.GetRecordSet("SELECT * FROM V_請求 WHERE 締切日 = " + RemoveSlash(SimekiribiMaskEdit->Text) + " AND 得意先コード = " + IntToStr(cedtSeikyuCode->Text.ToIntDef(0)), set)){
			if (Application->MessageBox("同じ締切日の請求データが既に存在します\r\n上書き登録を行いますか？", "重複チェック", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
				return;
			else
				cedtID->Text = set[0]["請求ID"];
		}
	}
	if (!PostRecord(cedtID->Text.ToIntDef(0)))
		return;

	if (RenzokuCheckBox->Checked){
		ClearForm(false);
		SimekiribiMaskEdit->SetFocus();
	}else{
		Close();
	}
}
//---------------------------------------------------------------------------
// キャンセル
void __fastcall TDetailForm::CloseActionExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::btnSeikyuClick(TObject *Sender)
{
	SearchForm->based_sql = " SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 使用区分 = 1 AND 得意先ID = 請求先ID";
	SearchForm->orderby_sql = " ORDER BY 得意先コード";
	SearchForm->table_name = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	cedtSeikyuCode->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	cedtSeikyuCode->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerChange(TObject *Sender)
{
	SimekiribiMaskEdit->Text = DateToStr(SimekiribiPicker->Date);

	SetNyukinYotei();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiMaskEditExit(TObject *Sender)
{
	SimekiribiPicker->Date = StrToDate(SimekiribiMaskEdit->Text);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerEnter(TObject *Sender)
{
	SanshoAction->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerExit(TObject *Sender)
{
	SanshoAction->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerCloseUp(TObject *Sender)
{
	cedtSeikyuCode->SetFocus();
}
//---------------------------------------------------------------------------

