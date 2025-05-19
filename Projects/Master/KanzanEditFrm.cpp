//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "KanzanEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TKanzanEditForm *KanzanEditForm;
//---------------------------------------------------------------------------
__fastcall TKanzanEditForm::TKanzanEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::FormShow(TObject *Sender)
{
	ClearForm();

      if (id_ == 0){
            SetMode(imNew);
            TokuisakiCodeEdit->SetFocus();
      }else{
            SetMode(imMod);
            KanzanEdit->SetFocus();
      }

	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

	is_edit_  = true;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];

	toku_ = AnsiReplaceStr(ToString(DM->config_["得意先マスタ名称"]), " ", "");
	toku_ = AnsiReplaceStr(toku_, "　", "");
	hin_  = AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]), " ", "");
	hin_  = AnsiReplaceStr(hin_, "　", "");
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall TKanzanEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::ClearForm()
{
      TokuisakiCodeEdit->Text = AnsiString();
      HinmokuCodeEdit->Text   = AnsiString();
      TaniCodeEdit->Text      = AnsiString();
	KanzanEdit->Text        = AnsiString();
	RenewDateEdit->Text     = AnsiString();
	CreateDateEdit->Text    = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption       = "新規";
		ModePanel->Color         = TColor(NEW_CLR);
		//TokuisakiCodeEdit->ReadOnly = false;
		//TokuisakiCodeEdit->Color = clWindow;
		//HinmokuCodeEdit->ReadOnly = false;
		//HinmokuCodeEdit->Color = clWindow;
		//TaniCodeEdit->ReadOnly = false;
		//TaniCodeEdit->Color = clWindow;
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled         = false;
		Action8->Enabled         = false;
	}else if (mode == imMod){
		ModePanel->Caption       = "修正";
		ModePanel->Color         = TColor(MOD_CLR);
		//TokuisakiCodeEdit->ReadOnly = true;
		//TokuisakiCodeEdit->Color = clSilver;
		//HinmokuCodeEdit->ReadOnly = true;
		//HinmokuCodeEdit->Color = clSilver;
		//TaniCodeEdit->ReadOnly = true;
		//TaniCodeEdit->Color = clSilver;
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled         = true;
		Action8->Enabled         = true;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TKanzanEditForm::CheckEdit()
{
	if (HinmokuCodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("品目が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		HinmokuCodeEdit->SetFocus();
		return false;
	}

	if (TaniCodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("単位が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		TaniCodeEdit->SetFocus();
		return false;
	}

	if (StrToCurrDef(KanzanEdit->Text, 0) == 0){
		Application->MessageBox("換算率が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		KanzanEdit->SetFocus();
		return false;
	}

      if (StrToCurrDef(KanzanEdit->Text, 0) > 99999999.99){
            Application->MessageBox("換算率が無効です\r\n0～99999999.99の間で設定してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            KanzanEdit->SetFocus();
            return false;
      }

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TKanzanEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[得意先ID]",   ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先ID", "使用区分 = 1")))
		   << NsField("[品目ID]",     ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID", "使用区分 = 1")))
		   << NsField("[単位ID]",     ToInt(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID", "")))
		   << NsField("[換算率]",     StrToCurrDef(KanzanEdit->Text, 0))
		   << NsField("[更新日時]",   Now());

	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_換算", fields);
		}else{
			DM->DBI.Update("M_換算", "換算ID", id_, fields);
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
void __fastcall TKanzanEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_換算 WHERE 換算ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                     = ToInt(set[0]["換算ID"]);
	TokuisakiCodeEdit->Text = ToInt(set[0]["得意先コード"]);
	HinmokuCodeEdit->Text   = ToInt(set[0]["品目コード"]);
	TaniCodeEdit->Text      = ToInt(set[0]["単位コード"]);
	KanzanEdit->Text        = ToCurrency(set[0]["換算率"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_換算", "換算ID", id_)){
            Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
            if (Application->MessageBox("本当に削除してもよろしいですか？", "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet keys;
            keys << NsField("[換算ID]", id_);
            try{
                  DM->DBI.Delete("M_換算", keys);
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
void __fastcall TKanzanEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == TokuisakiCodeEdit || ActiveControl == TokuisakiNameEdit)
		TokuisakiSearchButton->OnClick(NULL);

	if (ActiveControl == HinmokuCodeEdit || ActiveControl == HinmokuNameEdit)
		HinmokuSearchButton->OnClick(NULL);

	if (ActiveControl == TaniCodeEdit || ActiveControl == TaniNameEdit)
		TaniSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action5Execute(TObject *Sender)
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
		KanzanEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Kanzan->Bof)
		return;

	DM->M_Kanzan->Prior();
	id_ = DM->M_Kanzan->FieldByName("換算ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Kanzan->Eof)
		return;

	DM->M_Kanzan->Next();
	id_ = DM->M_Kanzan->FieldByName("換算ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiCodeEditChange(TObject *Sender)
{
	TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiCodeEditExit(TObject *Sender)
{
    int tokuisaki_id, hinmoku_id, tani_id;
    tokuisaki_id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先ID"));
    hinmoku_id   = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID"));
    tani_id      = ToInt(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID"));
    NsRecordSet set;
    AnsiString sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     M_換算"
          " WHERE"
          "     得意先ID = " + IntToStr(tokuisaki_id) +
          " AND"
          "     品目ID = " + IntToStr(hinmoku_id) +
          " AND"
          "     単位ID = " + IntToStr(tani_id);
          " AND"
          "     換算ID <> " + IntToStr(id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        id_ = 0;
        SetMode(imNew);
        is_edit_ = false;
        KanzanEdit->Text     = AnsiString();
        RenewDateEdit->Text  = AnsiString();
      	CreateDateEdit->Text = AnsiString();
    }else{
        SetMode(imMod);
        id_                  = ToInt(set[0]["換算ID"]);
        KanzanEdit->Text     = ToCurrency(set[0]["換算率"]);
      	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
        CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
    }
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 得意先コード, 得意先名称, 得意先カナ, 住所1, 住所2, 電話番号 FROM V_得意先";
	SearchForm->orderby_sql      = " ORDER BY 得意先コード";
	SearchForm->table_name       = " V_得意先";
	SearchForm->list_->CommaText = " 得意先コード,得意先略称,得意先カナ,住所1,住所2,電話番号";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TaniCodeEditChange(TObject *Sender)
{
	TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位名称", ""));
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TaniCodeEditExit(TObject *Sender)
{
/*
      if (TokuisakiCodeEdit->Text.ToIntDef(0) == 0 || HinmokuCodeEdit->Text.ToIntDef(0) == 0 || TaniCodeEdit->Text.ToIntDef(0) == 0)
            return;

      int tokuisaki_id, hinmoku_id, tani_id;
      tokuisaki_id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先ID"));
      hinmoku_id   = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID"));
      tani_id      = ToInt(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID"));
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT"
            "     *"
            " FROM"
            "     M_換算"
            " WHERE"
            "     得意先ID = " + IntToStr(tokuisaki_id) +
            " AND"
            "     品目ID = " + IntToStr(hinmoku_id) +
            " AND"
            "     単位ID = " + IntToStr(tani_id);
            " AND"
            "     換算ID <> " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set))
            return;

      if (Application->MessageBox("同一コードが登録されています。\r\n修正モードで呼び出しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

	SetMode(imMod);
	id_ = ToInt(set[0]["換算ID"]);
	BrowseRecord();
*/
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TaniSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 単位コード, 単位名称 FROM M_単位";
	SearchForm->orderby_sql      = " ORDER BY 単位コード";
	SearchForm->table_name       = " M_単位";
	SearchForm->list_->CommaText = " 単位コード,単位略称";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TaniCodeEdit->Text = SearchForm->Query->FieldByName("単位コード")->AsInteger;
	TaniCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::HinmokuSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 品目コード, 品目略称, 品目カナ FROM V_品目";
	SearchForm->orderby_sql      = " ORDER BY 品目コード";
	SearchForm->table_name       = " V_品目";
	SearchForm->list_->CommaText = " 品目略称, 品目カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	HinmokuCodeEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
	HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::KanzanEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  換算率を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + toku_ + "を入力して下さい。（[F4] " + toku_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TaniCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  単位を入力して下さい。（[F4] 単位検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + hin_ + "を入力して下さい。（[F4] " + hin_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

