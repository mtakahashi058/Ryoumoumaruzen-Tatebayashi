//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "TankaEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TTankaEditForm *TankaEditForm;
//---------------------------------------------------------------------------
__fastcall TTankaEditForm::TTankaEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::FormShow(TObject *Sender)
{
    if (id_ == 0){
        SetMode(imNew);
        TokuisakiCodeEdit->SetFocus();
    }else{
        SetMode(imMod);
        TankaEdit->SetFocus();
    }

	ClearForm();
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

	is_edit_  = false;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];

	toku_  = AnsiReplaceStr(ToString(DM->config_["得意先マスタ名称"]), " ", "");
	toku_  = AnsiReplaceStr(toku_, "　", "");
	hin_   = AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]), " ", "");
	hin_   = AnsiReplaceStr(hin_, "　", "");
	item1_ = AnsiReplaceStr(ToString(DM->config_["項目1マスタ名称"]), " ", "");
	item1_ = AnsiReplaceStr(item1_, "　", "");
	item2_ = AnsiReplaceStr(ToString(DM->config_["項目2マスタ名称"]), " ", "");
    item2_ = AnsiReplaceStr(item2_, "　", "");
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
		if (ActiveControl->Tag != 0 && ActiveControl->Tag != 2){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
int __fastcall TTankaEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::ClearForm()
{
	TokuisakiCodeEdit->Text = AnsiString();
	HinmokuCodeEdit->Text   = AnsiString();
	Item1CodeEdit->Text     = AnsiString();
	Item2CodeEdit->Text     = AnsiString();
	TaniCodeEdit->Text      = AnsiString();
	TankaEdit->Text         = AnsiString();
	RenewDateEdit->Text     = AnsiString();
	CreateDateEdit->Text    = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::SetMode(TInputMode mode)
{
    if (mode == imNew){
        ModePanel->Caption = "新規";
		ModePanel->Color   = TColor(NEW_CLR);
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "修正";
		ModePanel->Color   = TColor(MOD_CLR);
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled = true;
		Action8->Enabled = true;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TTankaEditForm::CheckEdit()
{
	if (TaniCodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("単位が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		TaniCodeEdit->SetFocus();
		return false;
	}

	if (StrToCurrDef(TankaEdit->Text, 0) == 0){
		Application->MessageBox("単価が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		TankaEdit->SetFocus();
		return false;
	}

    if (StrToCurrDef(TankaEdit->Text, 0) > 9999999999.999){
        Application->MessageBox("単価が無効です\r\n0～9999999999.999の間で設定してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        TankaEdit->SetFocus();
        return false;
    }

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TTankaEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[得意先ID]",   ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先ID", "使用区分 = 1")))
		   << NsField("[品目ID]",     ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID", "使用区分 = 1")))
		   << NsField("[項目1ID]",    ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1ID", "使用区分 = 1")))
		   << NsField("[項目2ID]",    ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2ID", "使用区分 = 1")))
		   << NsField("[単位ID]",     ToInt(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID", "")))
		   << NsField("[単価]",     StrToCurrDef(TankaEdit->Text, 0))
		   << NsField("[更新日時]",   Now());

	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_単価", fields);
		}else{
			DM->DBI.Update("M_単価", "単価ID", id_, fields);
		}
	}catch (Exception &e){
		Application->MessageBox(("登録／修正に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	is_edit_ = true;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_単価 WHERE 単価ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                     = ToInt(set[0]["単価ID"]);
	TokuisakiCodeEdit->Text = ToInt(set[0]["得意先コード"]);
	HinmokuCodeEdit->Text   = ToInt(set[0]["品目コード"]);
	Item1CodeEdit->Text     = ToInt(set[0]["項目1コード"]);
	Item2CodeEdit->Text     = ToInt(set[0]["項目2コード"]);
	TaniCodeEdit->Text      = ToInt(set[0]["単位コード"]);
	TankaEdit->Text         = ToCurrency(set[0]["単価"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action1Execute(TObject *Sender)
{
    id_ = 0;
    SetMode(imNew);
    ClearForm();
    TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (!DM->DBI.IsExist("M_単価", "単価ID", id_)){
        Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();

    if (Application->MessageBox("本当に削除してもよろしいですか？", "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    NsFieldSet keys;
    keys << NsField("[単価ID]", id_);
    try{
        DM->DBI.Delete("M_単価", keys);
    }catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
        Application->MessageBox(("データ削除に失敗しました\r\n" + e.Message).c_str(), "削除", MB_OK | MB_ICONWARNING);
        return;
    }
    msg = "データを削除しました";

    DM->ADOConnection->CommitTrans();
    MainForm->OpenQuery(page_, MainForm->order_);
    id_ = MainForm->query[page_]->FieldByName(keyfield_)->AsInteger;
    BrowseRecord();
    Application->MessageBox(msg.c_str(), "削除", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == TokuisakiCodeEdit || ActiveControl == TokuisakiNameEdit)
		TokuisakiSearchButton->OnClick(NULL);

	if (ActiveControl == HinmokuCodeEdit || ActiveControl == HinmokuNameEdit)
		HinmokuSearchButton->OnClick(NULL);

	if (ActiveControl == Item1CodeEdit || ActiveControl == Item1NameEdit)
		Item1SearchButton->OnClick(NULL);

	if (ActiveControl == Item2CodeEdit || ActiveControl == Item2NameEdit)
		Item2SearchButton->OnClick(NULL);

	if (ActiveControl == TaniCodeEdit || ActiveControl == TaniNameEdit)
		TaniSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("登録／修正しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("登録／修正しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	if (DM->GetMode(ModePanel) == imNew){
		if (RenzokuCheckBox->Checked){
			ClearForm();
			TokuisakiCodeEdit->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		TankaEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Tanka->Bof)
		return;

	DM->M_Tanka->Prior();
	id_ = DM->M_Tanka->FieldByName("単価ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Tanka->Eof)
		return;

	DM->M_Tanka->Next();
	id_ = DM->M_Tanka->FieldByName("単価ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiCodeEditChange(TObject *Sender)
{
	TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiCodeEditExit(TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql;
    int tokuisaki_id, hinmoku_id, item1_id, item2_id, tani_id;
    tokuisaki_id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先ID"));
    hinmoku_id   = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID"));
    item1_id     = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    item2_id     = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    tani_id      = ToInt(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID"));
    sql = " SELECT"
          "     *"
          " FROM"
          "     M_単価"
          " WHERE"
          "     得意先ID = " + IntToStr(tokuisaki_id) +
          " AND"
          "     品目ID = " + IntToStr(hinmoku_id) +
          " AND"
          "     項目1ID = " + IntToStr(item1_id) +
          " AND"
          "     項目2ID = " + IntToStr(item2_id) +
          " AND"
          "     単位ID = " + IntToStr(tani_id);
    if (!DM->DBI.GetRecordSet(sql, set)){
        id_ = 0;
        SetMode(imNew);
        TankaEdit->Text      = AnsiString();
        RenewDateEdit->Text  = AnsiString();
        CreateDateEdit->Text = AnsiString();
    }else{
        SetMode(imMod);
        id_                  = ToInt(set[0]["単価ID"]);
        TankaEdit->Text      = ToCurrency(set[0]["単価"]);
        RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
        CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
    }
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 得意先コード, 得意先名称, 得意先カナ, 住所1, 住所2, 電話番号 FROM V_得意先";
	SearchForm->orderby_sql      = " ORDER BY 得意先コード";
	SearchForm->table_name       = " V_得意先";
	SearchForm->list_->CommaText = " 得意先コード,得意先名称,得意先カナ,住所1,住所2,電話番号";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::HinmokuSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 品目コード, 品目名称, 品目カナ FROM V_品目";
	SearchForm->orderby_sql      = " ORDER BY 品目コード";
	SearchForm->table_name       = " V_品目";
	SearchForm->list_->CommaText = " 品目名称, 品目カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	HinmokuCodeEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
	HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item1CodeEditChange(TObject *Sender)
{
	Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item1SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 項目1コード, 項目1名称, 項目1カナ FROM V_項目1";
	SearchForm->orderby_sql      = " ORDER BY 項目1コード";
	SearchForm->table_name       = " V_項目1";
	SearchForm->list_->CommaText = " 項目1名称, 項目1カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEdit->Text = SearchForm->Query->FieldByName("項目1コード")->AsInteger;
	Item1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item2CodeEditChange(TObject *Sender)
{
	Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item2SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 項目2コード, 項目2名称, 項目2カナ FROM V_項目2";
	SearchForm->orderby_sql      = " ORDER BY 項目2コード";
	SearchForm->table_name       = " V_項目2";
	SearchForm->list_->CommaText = " 項目2名称, 項目2カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEdit->Text = SearchForm->Query->FieldByName("項目2コード")->AsInteger;
	Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TaniCodeEditChange(TObject *Sender)
{
	TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位名称", ""));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TaniSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 単位コード, 単位名称 FROM M_単位";
	SearchForm->orderby_sql      = " ORDER BY 単位コード";
	SearchForm->table_name       = " M_単位";
	SearchForm->list_->CommaText = " 単位コード,単位名称";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TaniCodeEdit->Text = SearchForm->Query->FieldByName("単位コード")->AsInteger;
	TaniCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + toku_ + "を入力して下さい。（[F4] " + toku_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + hin_ + "を入力して下さい。（[F4] " + hin_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item1CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item1_ + "を入力して下さい。（[F4] " + item1_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item2CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item2_ + "を入力して下さい。（[F4] " + item2_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TaniCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  単位を入力して下さい。（[F4] 単位検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TankaEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  単価を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

