//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlipInfoRelateEditFrm.h"
#include "DMFrm.h"
#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TSlipInfoRelateEditForm *SlipInfoRelateEditForm;
//---------------------------------------------------------------------------
__fastcall TSlipInfoRelateEditForm::TSlipInfoRelateEditForm(TComponent* Owner)
      : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall TSlipInfoRelateEditForm::ShowModalWithId(int id)
{
    id_ = id;
    return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::FormShow(TObject *Sender)
{
    //DM->AddComboMap(ItemNoNameComboBox, DM->itemno_map_, "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 12");
    DM->AddComboMap_Item(ItemNoNameComboBox, DM->itemno_map_);

    if (id_ == 0)
        SetMode(imNew);
    else
        SetMode(imMod);

    ClearForm();
    ClearSlipInfo();
    if (DM->GetMode(ModePanel) == imMod){
        BrowseRecord();
        SlipInfoCodeEdit->SetFocus();
    }else
        ItemNoCodeEdit->SetFocus();

    is_edit_ = false;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::FormKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
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
                  }else{
                        Action5->OnExecute(NULL);
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
void __fastcall TSlipInfoRelateEditForm::Action4Execute(TObject *Sender)
{
      if (ActiveControl == ItemNoCodeEdit){
            ItemNoNameComboBox->Perform(CB_SHOWDROPDOWN, 1, 0);
            ItemNoNameComboBox->SetFocus();
      }else if (ActiveControl == SettingCodeEdit)
            SettingSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::Action5Execute(TObject *Sender)
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
                  ClearSlipInfo();
                  ItemNoCodeEdit->SetFocus();
            }else
                  Close();
      }else{
            BrowseRecord();
            SlipInfoCodeEdit->SetFocus();
      }
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::Action7Execute(TObject *Sender)
{
      if (DM->M_SlipInfoRelate->Bof)
            return;

      DM->M_SlipInfoRelate->Prior();
      id_ = DM->M_SlipInfoRelate->FieldByName("伝票情報関連ID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::Action8Execute(TObject *Sender)
{
      if (DM->M_SlipInfoRelate->Eof)
            return;

      DM->M_SlipInfoRelate->Next();
      id_ = DM->M_SlipInfoRelate->FieldByName("伝票情報関連ID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::Action12Execute(TObject *Sender)
{
      Close();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::ClearForm()
{
      ItemNoCodeEdit->Text    = AnsiString();
      SettingCodeEdit->Text   = AnsiString();
      SlipInfoCodeEdit->Text  = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::ClearSlipInfo()
{
      SlipInfoNameEdit->Text              = AnsiString();
      StoreroomEntryTitleEdit1->Text      = AnsiString();
      StoreroomEntryTitleEdit2->Text      = AnsiString();
      StoreroomEntryTitleEdit3->Text      = AnsiString();
      DeliverySlipEdit1->Text             = AnsiString();
      DeliverySlipEdit2->Text             = AnsiString();
      DeliverySlipEdit3->Text             = AnsiString();
      CompanyNameEdit->Text               = AnsiString();
      CompanyInfoEdit1->Text              = AnsiString();
      CompanyInfoEdit2->Text              = AnsiString();
      CompanyInfoEdit3->Text              = AnsiString();
      CompanyInfoEdit4->Text              = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::BrowseRecord()
{
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT * FROM V_伝票情報関連 WHERE 伝票情報関連ID = " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            ClearForm();
            ClearSlipInfo();
            id_ = 0;
            return;
      }

      ItemNoCodeEdit->Text    = ToInt(set[0]["項目番号"]);
      SettingCodeEdit->Text   = ToInt(set[0]["項目コード"]);
      SlipInfoCodeEdit->Text  = ToInt(set[0]["伝票情報コード"]);
}
//---------------------------------------------------------------------------
bool __fastcall TSlipInfoRelateEditForm::PostRecord()
{
    NsFieldSet slipinfo_fields, sliprelate_fields;
    int item_no, item_id, slipinfo_id;

    item_no = ItemNoCodeEdit->Text.ToIntDef(0);
    int code = SettingCodeEdit->Text.ToIntDef(0);
    if (item_no == 1){
        // 得意先
        item_id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", code, "得意先ID"));
    }else if (item_no == 2){
        // 項目1
        item_id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", code, "項目1ID"));
    }else if (item_no == 3){
        // 項目2
        item_id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", code, "項目2ID"));
    }else if (item_no == 4){
        // 品目
        item_id = ToInt(DM->DBI.Lookup("M_品目", "品目コード", code, "品目ID"));
    }else if (item_no == 5){
        // 現掛区分
        NsFieldSet keys;
        keys << NsField("区分分類コード", 4)
             << NsField("区分コード",     code);
        item_id = ToInt(DM->DBI.Lookup("M_区分", keys, "区分ID"));
    }else
        item_id = 0;

    slipinfo_id = ToInt(DM->DBI.Lookup("M_伝票情報", "伝票情報コード", SlipInfoCodeEdit->Text.ToIntDef(0), "伝票情報ID"));

    // 伝票情報関連
    sliprelate_fields
        << NsField("[項目番号]",   item_no)
        << NsField("[項目ID]",     item_id)
        << NsField("[伝票情報ID]", slipinfo_id);

    // 伝票情報も更新
    slipinfo_fields
        << NsField("[伝票情報名]",        SlipInfoNameEdit->Text)
        << NsField("[入庫伝票タイトル1]", StoreroomEntryTitleEdit1->Text)
        << NsField("[入庫伝票タイトル2]", StoreroomEntryTitleEdit2->Text)
        << NsField("[入庫伝票タイトル3]", StoreroomEntryTitleEdit3->Text)
        << NsField("[出庫伝票タイトル1]", DeliverySlipEdit1->Text)
        << NsField("[出庫伝票タイトル2]", DeliverySlipEdit2->Text)
        << NsField("[出庫伝票タイトル3]", DeliverySlipEdit3->Text)
        << NsField("[会社名]",            CompanyNameEdit->Text)
        << NsField("[会社情報1]",         CompanyInfoEdit1->Text)
        << NsField("[会社情報2]",         CompanyInfoEdit2->Text)
        << NsField("[会社情報3]",         CompanyInfoEdit3->Text)
        << NsField("[会社情報4]",         CompanyInfoEdit4->Text);

    DM->ADOConnection->BeginTrans();
    try{
        // 伝票情報マスタ
        DM->DBI.Update("M_伝票情報", "伝票情報ID", slipinfo_id, slipinfo_fields);

        // 伝票情報関連マスタ
        if (id_ == 0)
            DM->DBI.Insert("M_伝票情報関連", sliprelate_fields);
        else
            DM->DBI.Update("M_伝票情報関連", "伝票情報関連ID", id_, sliprelate_fields);
    }catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
        Application->MessageBox(("登録／修正に失敗しました\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
        return false;
    }
    DM->ADOConnection->CommitTrans();

    is_edit_ = true;

    return true;
}
//---------------------------------------------------------------------------
bool __fastcall TSlipInfoRelateEditForm::CheckEdit()
{
    if (ItemNoCodeEdit->Text.ToIntDef(0) == 0 && SettingCodeEdit->Text.ToIntDef(0) == 0){
        NsFieldSet keys;
        int slip_id = ToInt(DM->DBI.Lookup("M_伝票情報", "伝票情報コード", SlipInfoCodeEdit->Text.ToIntDef(0), "伝票情報ID"));
        keys << NsField("[伝票情報ID]", slip_id);
        if (!DM->DBI.IsExist("M_伝票情報", keys)){
            Application->MessageBox("伝票情報が不正です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoCodeEdit->SetFocus();
            return false;
        }
        return true;
    }

    if (ItemNoCodeEdit->Text.ToIntDef(0) == 0 || ItemNoNameComboBox->ItemIndex == -1){
        Application->MessageBox("項目番号が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        ItemNoCodeEdit->SetFocus();
        return false;
    }

    if (SettingCodeEdit->Text.ToIntDef(0) == 0){
        Application->MessageBox("設定コードが無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        SettingCodeEdit->SetFocus();
        return false;
    }

    NsFieldSet keys;
    int slipinfo_id = ToInt(DM->DBI.Lookup("M_伝票情報", "伝票情報コード", SlipInfoCodeEdit->Text.ToIntDef(0), "伝票情報ID"));
    keys << NsField("[伝票情報ID]", slipinfo_id);
    if (!DM->DBI.IsExist("M_伝票情報", keys)){
        Application->MessageBox("伝票情報が不正です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SetMode(TInputMode mode)
{
    if (mode == imNew){
        ModePanel->Caption       = "新規";
        ModePanel->Color         = TColor(NEW_CLR);
        RenzokuCheckBox->Enabled = true;
        Action7->Enabled         = false;
        Action8->Enabled         = false;
    }else if (mode == imMod){
        ModePanel->Caption       = "修正";
        ModePanel->Color         = TColor(MOD_CLR);
        RenzokuCheckBox->Enabled = false;
        Action7->Enabled         = true;
        Action8->Enabled         = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::ItemNoCodeEditChange(
      TObject *Sender)
{
    ItemNoNameComboBox->ItemIndex = DM->SearchIndex(DM->itemno_map_, ItemNoCodeEdit->Text.ToIntDef(0));
    SettingCodeEdit->Text         = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::ItemNoCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  項目を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::ItemNoNameComboBoxChange(
      TObject *Sender)
{
    ItemNoCodeEdit->Text = DM->itemno_map_[ItemNoNameComboBox->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SettingCodeEditChange(
      TObject *Sender)
{
    AnsiString name = AnsiString();
    int code = SettingCodeEdit->Text.ToIntDef(0);

    if (ItemNoCodeEdit->Text.ToIntDef(0) == 1){
        // 得意先
        name = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", code, "得意先名称"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 2){
        // 項目１
        name = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", code, "項目1名称"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 3){
        // 項目2
        name = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", code, "項目2名称"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 4){
        // 品目
        name = ToString(DM->DBI.Lookup("M_品目", "品目コード", code, "品目名称"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 5){
        // 現掛区分
        NsFieldSet keys;
        keys << NsField("区分分類コード", 4)
             << NsField("区分コード",     code);
        name = ToString(DM->DBI.Lookup("M_区分", keys, "区分名称"));
    }else{
        name = "";
    }

    SettingNameEdit->Text = name;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SettingCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  設定対象を入力してください";
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SettingSearchButtonClick(
      TObject *Sender)
{
    if (ItemNoCodeEdit->Text.ToIntDef(0) == 1){
        // 得意先
        SearchForm->based_sql        = " SELECT 得意先コード AS コード, 得意先名称 AS 名称 FROM V_得意先";
        SearchForm->orderby_sql      = " ORDER BY 得意先コード";
        SearchForm->table_name       = " V_得意先";
        SearchForm->list_->CommaText = " 得意先略称, 得意先カナ";
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 2){
        // 項目１
        SearchForm->based_sql        = " SELECT 項目1コード AS コード, 項目1名称 AS 名称 FROM V_項目1";
        SearchForm->orderby_sql      = " ORDER BY 項目1コード";
        SearchForm->table_name       = " V_項目1";
        SearchForm->list_->CommaText = " 項目1名称, 項目1カナ";
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 3){
        // 項目2
        SearchForm->based_sql        = " SELECT 項目2コード AS コード, 項目2名称 AS 名称 FROM V_項目2";
        SearchForm->orderby_sql      = " ORDER BY 項目2コード";
        SearchForm->table_name       = " V_項目2";
        SearchForm->list_->CommaText = " 項目2名称, 項目2カナ";
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 4){
        // 品目
        SearchForm->based_sql        = " SELECT 品目コード AS コード, 品目名称 AS 名称 FROM V_品目";
        SearchForm->orderby_sql      = " ORDER BY 品目コード";
        SearchForm->table_name       = " V_品目";
        SearchForm->list_->CommaText = " 品目名称, 品目カナ";
    }else{
        Application->MessageBox("項目番号が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    SearchForm->Top  = Application->MainForm->Top + 50;
    SearchForm->Left = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;

    if (SearchForm->ShowModal() != mrOk)
        return;

    SettingCodeEdit->Text = SearchForm->Query->FieldByName("コード")->AsInteger;
    SlipInfoCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SlipInfoCodeEditChange(
      TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql;
    sql = "SELECT * FROM V_伝票情報 WHERE 伝票情報コード = " + IntToStr(SlipInfoCodeEdit->Text.ToIntDef(0));
    if (!DM->DBI.GetRecordSet(sql, set)){
        ClearSlipInfo();
        return;
    }

    SlipInfoNameEdit->Text         = ToString(set[0]["伝票情報名"]);
    StoreroomEntryTitleEdit1->Text = ToString(set[0]["入庫伝票タイトル1"]);
    StoreroomEntryTitleEdit2->Text = ToString(set[0]["入庫伝票タイトル2"]);
    StoreroomEntryTitleEdit3->Text = ToString(set[0]["入庫伝票タイトル3"]);
    DeliverySlipEdit1->Text        = ToString(set[0]["出庫伝票タイトル1"]);
    DeliverySlipEdit2->Text        = ToString(set[0]["出庫伝票タイトル2"]);
    DeliverySlipEdit3->Text        = ToString(set[0]["出庫伝票タイトル3"]);
    CompanyNameEdit->Text          = ToString(set[0]["会社名"]);
    CompanyInfoEdit1->Text         = ToString(set[0]["会社情報1"]);
    CompanyInfoEdit2->Text         = ToString(set[0]["会社情報2"]);
    CompanyInfoEdit3->Text         = ToString(set[0]["会社情報3"]);
    CompanyInfoEdit4->Text         = ToString(set[0]["会社情報4"]);
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SlipInfoCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  伝票情報を選択してください";
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SlipInfoSerachButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT 伝票情報コード, 伝票情報名, 入庫伝票タイトル1, 入庫伝票タイトル2, 入庫伝票タイトル3, 出庫伝票タイトル1, 出庫伝票タイトル2, 出庫伝票タイトル3,"
                                   "        会社名, 会社情報1, 会社情報2, 会社情報3, 会社情報4"
                                   " FROM   V_伝票情報";
    SearchForm->orderby_sql      = " ORDER BY 伝票情報コード";
    SearchForm->table_name       = " V_伝票情報";
    SearchForm->list_->CommaText = " 伝票情報コード, 伝票情報名, 入庫伝票タイトル1, 入庫伝票タイトル2, 入庫伝票タイトル3, 出庫伝票タイトル1, 出庫伝票タイトル2, 出庫伝票タイトル3,"
                                   " 会社名, 会社情報1, 会社情報2, 会社情報3, 会社情報4";

    if (SearchForm->ShowModal() != mrOk)
        return;

    SlipInfoCodeEdit->Text = SearchForm->Query->FieldByName("伝票情報コード")->AsInteger;
    SlipInfoCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::ItemNoPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::ItemNoPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

