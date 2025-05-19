//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ItemRelateEditFrm.h"
#include "DMFrm.h"
#include "MainFrm.h"
#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TItemRelateEditForm *ItemRelateEditForm;
//---------------------------------------------------------------------------
__fastcall TItemRelateEditForm::TItemRelateEditForm(TComponent* Owner)
      : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall TItemRelateEditForm::ShowModalWithId(int id)
{
    id_ = id;
    return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::FormShow(TObject *Sender)
{
    DM->AddComboMap_Item(ItemNoNameComboBox, DM->itemno_map_);

    if (id_ == 0)
        SetMode(imNew);
    else
        SetMode(imMod);

    ClearForm();
    if (DM->GetMode(ModePanel) == imMod){
        BrowseRecord();
        if (TokuisakiCodeEdit->Enabled)
            TokuisakiCodeEdit->SetFocus();
        else if (Item1CodeEdit->Enabled)
            Item1CodeEdit->SetFocus();
        else if (Item2CodeEdit->Enabled)
            Item2CodeEdit->SetFocus();
        else if (HinmokuCodeEdit->Enabled)
            HinmokuCodeEdit->SetFocus();
    }else{
        ItemNoCodeEdit->SetFocus();
    }

    is_edit_ = false;
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::FormKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    switch (Key){
        case VK_DOWN:
            if (ActiveControl->Tag != 99 && ActiveControl->Tag != 2){
                keybd_event(VK_TAB, 0, 0, 0);
            }
            break;
        case VK_RETURN:
            if (ActiveControl->Tag != 99 && ActiveControl->Tag != 10){
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
void __fastcall TItemRelateEditForm::Action4Execute(TObject *Sender)
{
    if (ActiveControl == ItemNoCodeEdit){
        ItemNoNameComboBox->Perform(CB_SHOWDROPDOWN, 1, 0);
        ItemNoNameComboBox->SetFocus();
    }else if (ActiveControl == SetObjectCodeEdit)
        SetObjectSearchButton->OnClick(NULL);
    else if (ActiveControl == TokuisakiCodeEdit)
        TokuisakiSearchButton->OnClick(NULL);
    else if (ActiveControl == Item1CodeEdit)
        Item1SearchButton->OnClick(NULL);
    else if (ActiveControl == Item2CodeEdit)
        Item2SearchButton->OnClick(NULL);
    else if (ActiveControl == HinmokuCodeEdit)
        HinmokuSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Action5Execute(TObject *Sender)
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
            ItemNoCodeEdit->SetFocus();
        }else
            Close();
    }else{
        BrowseRecord();
        if (TokuisakiCodeEdit->Enabled)
            TokuisakiCodeEdit->SetFocus();
        else if (Item1CodeEdit->Enabled)
            Item1CodeEdit->SetFocus();
        else if (Item2CodeEdit->Enabled)
            Item2CodeEdit->SetFocus();
        else if (HinmokuCodeEdit->Enabled)
            HinmokuCodeEdit->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Action7Execute(TObject *Sender)
{
    if (DM->M_ItemRelate->Bof)
        return;

    DM->M_ItemRelate->Prior();
    id_ = DM->M_ItemRelate->FieldByName("項目関連ID")->AsInteger;
    BrowseRecord();
    if (TokuisakiCodeEdit->Enabled)
        TokuisakiCodeEdit->SetFocus();
    else if (Item1CodeEdit->Enabled)
        Item1CodeEdit->SetFocus();
    else if (Item2CodeEdit->Enabled)
        Item2CodeEdit->SetFocus();
    else if (HinmokuCodeEdit->Enabled)
        HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Action8Execute(TObject *Sender)
{
    if (DM->M_ItemRelate->Eof)
        return;

    DM->M_ItemRelate->Next();
    id_ = DM->M_ItemRelate->FieldByName("項目関連ID")->AsInteger;
    BrowseRecord();
    if (TokuisakiCodeEdit->Enabled)
        TokuisakiCodeEdit->SetFocus();
    else if (Item1CodeEdit->Enabled)
        Item1CodeEdit->SetFocus();
    else if (Item2CodeEdit->Enabled)
        Item2CodeEdit->SetFocus();
    else if (HinmokuCodeEdit->Enabled)
        HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Action12Execute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::ItemNoCodeEditChange(TObject *Sender)
{
    ItemNoNameComboBox->ItemIndex = DM->SearchIndex(DM->itemno_map_, ItemNoCodeEdit->Text.ToIntDef(0));

    SetComponent(ItemNoCodeEdit->Text.ToIntDef(0));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::ItemNoCodeEditEnter(TObject *Sender)
{
    StatusBar->SimpleText = "  項目を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::ItemNoNameComboBoxChange(
      TObject *Sender)
{
    ItemNoCodeEdit->Text = DM->itemno_map_[ItemNoNameComboBox->ItemIndex];
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::ItemNoNameComboBoxEnter(TObject *Sender)
{
    StatusBar->SimpleText = "  項目を選択してください";
    if (ItemNoNameComboBox->ItemIndex == -1 && ItemNoNameComboBox->ItemIndex >= 4){
        ItemNoNameComboBox->Perform(CB_SHOWDROPDOWN, 1, 0);
        ItemNoNameComboBox->ItemIndex = 0;
        ItemNoNameComboBox->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetObjectCodeEditChange(
      TObject *Sender)
{
    AnsiString name = AnsiString();
    if (ItemNoCodeEdit->Text.ToIntDef(0) == 1){
        // 得意先
        name = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SetObjectCodeEdit->Text.ToIntDef(0), "得意先名称"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 2){
        // 項目１
        name = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", SetObjectCodeEdit->Text.ToIntDef(0), "項目1名称"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 3){
        // 項目2
        name = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", SetObjectCodeEdit->Text.ToIntDef(0), "項目2名称"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 4){
        // 品目
        name = ToString(DM->DBI.Lookup("M_品目", "品目コード", SetObjectCodeEdit->Text.ToIntDef(0), "品目名称"));
    }else{
        name = "";
    }

    SetObjectNameEdit->Text = name;
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetObjectCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  設定対象を入力してください";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetObjectSearchButtonClick(
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
    SetObjectCodeEdit->Text = SearchForm->Query->FieldByName("コード")->AsInteger;

    if (TokuisakiCodeEdit->Enabled)
        TokuisakiCodeEdit->SetFocus();
    else if (Item1CodeEdit->Enabled)
        Item1CodeEdit->SetFocus();
    else if (Item2CodeEdit->Enabled)
        Item2CodeEdit->SetFocus();
    else
        HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::TokuisakiCodeEditChange(
      TObject *Sender)
{
    TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::TokuisakiCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  " + MainForm->toku_ + "を入力してください";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::TokuisakiSearchButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 得意先コード, 得意先名称, 得意先カナ, 住所1, 住所2, 電話番号 FROM V_得意先 WHERE 使用区分 = 1";
	SearchForm->orderby_sql      = " ORDER BY 得意先コード";
	SearchForm->table_name       = " V_得意先";
	SearchForm->list_->CommaText = " 得意先コード,得意先略称,得意先カナ,住所1,住所2,電話番号";

	if (SearchForm->ShowModal() != mrOk)
		return;

	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;

    if (Item1CodeEdit->Enabled)
    	Item1CodeEdit->SetFocus();
    else
        Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item1CodeEditChange(TObject *Sender)
{
    Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item1CodeEditEnter(TObject *Sender)
{
    StatusBar->SimpleText = "  " + MainForm->item1_ + "を入力してください";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item1SearchButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT 項目1コード, 項目1名称, 項目1カナ FROM V_項目1 WHERE 使用区分 = 1";
    SearchForm->orderby_sql      = " ORDER BY 項目1コード";
    SearchForm->table_name       = " V_項目1";
    SearchForm->list_->CommaText = " 項目1コード,項目1略称,項目1カナ";

    if (SearchForm->ShowModal() != mrOk)
        return;

    Item1CodeEdit->Text = SearchForm->Query->FieldByName("項目1コード")->AsInteger;
    if (Item2CodeEdit->Enabled)
        Item2CodeEdit->SetFocus();
    else
        HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item2CodeEditChange(TObject *Sender)
{
    Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item2CodeEditEnter(TObject *Sender)
{
    StatusBar->SimpleText = "  " + MainForm->item2_ + "を入力してください";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item2CodeEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    if (ItemNoCodeEdit->Text.ToIntDef(0) != 4)
        keybd_event(VK_TAB, 0, 0, 0);
    else
        Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item2SearchButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT 項目2コード, 項目2名称, 項目2カナ FROM V_項目2 WHERE 使用区分 = 1";
    SearchForm->orderby_sql      = " ORDER BY 項目2コード";
    SearchForm->table_name       = " V_項目2";
    SearchForm->list_->CommaText = " 項目2コード,項目2略称,項目2カナ";

    if (SearchForm->ShowModal() != mrOk)
        return;

    Item2CodeEdit->Text = SearchForm->Query->FieldByName("項目2コード")->AsInteger;

    if (HinmokuCodeEdit->Enabled)
        HinmokuCodeEdit->SetFocus();
    else
        Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::HinmokuCodeEditChange(TObject *Sender)
{
      HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  " + MainForm->hin_ + "入力してください";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::HinmokuSearchButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT 品目コード, 品目名称, 品目カナ FROM V_品目 WHERE 使用区分 = 1";
    SearchForm->orderby_sql      = " ORDER BY 品目コード";
    SearchForm->table_name       = " V_品目";
    SearchForm->list_->CommaText = " 品目コード,品目略称,品目カナ";

    if (SearchForm->ShowModal() != mrOk)
        return;

    HinmokuCodeEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
    HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::HinmokuCodeEditKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::ClearForm()
{
    ItemNoCodeEdit->Text          = AnsiString();
    ItemNoNameComboBox->ItemIndex = -1;
    SetObjectCodeEdit->Text       = AnsiString();
    TokuisakiCodeEdit->Text       = AnsiString();
    Item1CodeEdit->Text           = AnsiString();
    Item2CodeEdit->Text           = AnsiString();
    HinmokuCodeEdit->Text         = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::BrowseRecord()
{
    NsRecordSet set;
    AnsiString sql;
    sql = " SELECT * FROM V_項目関連 WHERE 項目関連ID = " + IntToStr(id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        ClearForm();
        id_ = 0;
        return;
    }

    ItemNoCodeEdit->Text    = ToInt(set[0]["項目番号"]);
    SetObjectCodeEdit->Text = ToInt(set[0]["項目コード"]);
    TokuisakiCodeEdit->Text = FormatFloat("#", ToInt(set[0]["得意先コード"]));
    Item1CodeEdit->Text     = FormatFloat("#", ToInt(set[0]["項目1コード"]));
    Item2CodeEdit->Text     = FormatFloat("#", ToInt(set[0]["項目2コード"]));
    HinmokuCodeEdit->Text   = FormatFloat("#", ToInt(set[0]["品目コード"]));
}
//---------------------------------------------------------------------------
bool __fastcall TItemRelateEditForm::PostRecord()
{
      NsFieldSet keys, fields;

      int item_no, setobject_id, tokuisaki_id, item1_id, item2_id, hin_id;

      item_no      = ItemNoCodeEdit->Text.ToIntDef(0);
      tokuisaki_id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先ID"));
      item1_id     = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1ID"));
      item2_id     = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2ID"));
      hin_id       = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID"));
      if (item_no == 1)
            setobject_id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", SetObjectCodeEdit->Text.ToIntDef(0), "得意先ID"));
      else if (item_no == 2)
            setobject_id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", SetObjectCodeEdit->Text.ToIntDef(0), "項目1ID"));
      else if (item_no == 3)
            setobject_id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", SetObjectCodeEdit->Text.ToIntDef(0), "項目2ID"));
      else if (item_no == 4)
            setobject_id = ToInt(DM->DBI.Lookup("M_品目", "品目コード", SetObjectCodeEdit->Text.ToIntDef(0), "品目ID"));
      else
            setobject_id = 0;


      fields      << NsField("[項目番号]", item_no)
                  << NsField("[項目ID]",   setobject_id)
                  << NsField("[得意先ID]", tokuisaki_id)
                  << NsField("[項目1ID]",  item1_id)
                  << NsField("[項目2ID]",  item2_id)
                  << NsField("[品目ID]",   hin_id);

      try{
            if (id_ == 0){
                  // 新規
                  DM->DBI.Insert("M_項目関連", fields);
            }else{
                  // 更新
                  DM->DBI.Update("M_項目関連", "項目関連ID", id_, fields);
            }
      }catch (Exception &e){
            Application->MessageBox(("登録／修正に失敗しました\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
            return false;
      }

      is_edit_ = true;

      return true;
}
//---------------------------------------------------------------------------
bool __fastcall TItemRelateEditForm::CheckEdit()
{
      if (ItemNoCodeEdit->Text.ToIntDef(0) == 0 || ItemNoNameComboBox->Text == ""){
            Application->MessageBox("項目が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            ItemNoCodeEdit->SetFocus();
            return false;
      }

      if (SetObjectCodeEdit->Text.ToIntDef(0) == 0){
            Application->MessageBox("設定対象が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SetObjectCodeEdit->SetFocus();
            return false;
      }

      return true;
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
            ModePanel->Caption = "新規";
            ModePanel->Color = TColor(NEW_CLR);
            ItemNoCodeEdit->ReadOnly       = false;
            ItemNoCodeEdit->Color          = clCream;
            ItemNoNameComboBox->Enabled    = true;
            ItemNoNameComboBox->Color      = clCream;
            SetObjectCodeEdit->ReadOnly    = false;
            SetObjectCodeEdit->Color       = clCream;
            SetObjectSearchButton->Enabled = true;
            RenzokuCheckBox->Enabled       = true;
            Action7->Enabled = false;
            Action8->Enabled = false;
      }else if (mode == imMod){
            ModePanel->Caption = "修正";
            ModePanel->Color = TColor(MOD_CLR);
            ItemNoCodeEdit->ReadOnly       = true;
            ItemNoCodeEdit->Color          = clSilver;
            ItemNoNameComboBox->Enabled    = false;
            ItemNoNameComboBox->Color      = clSilver;
            SetObjectCodeEdit->ReadOnly    = true;
            SetObjectCodeEdit->Color       = clSilver;
            SetObjectSearchButton->Enabled = false;
            RenzokuCheckBox->Enabled = false;
            Action7->Enabled = true;
            Action8->Enabled = true;
      }
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetComponent(int no)
{
    SetObjectCodeEdit->Text = AnsiString();
    SetObjectCodeEdit->OnChange(NULL);

    if (no == 1){       // 業者
        TokuisakiCodeEdit->Text        = AnsiString();
        TokuisakiCodeEdit->Enabled     = false;
        TokuisakiCodeEdit->Color       = clSilver;
        TokuisakiSearchButton->Enabled = false;
        Item1CodeEdit->Enabled         = true;
        Item1CodeEdit->Color           = clCream;
        Item1SearchButton->Enabled     = true;
        Item2CodeEdit->Enabled         = true;
        Item2CodeEdit->Color           = clCream;
        Item2SearchButton->Enabled     = true;
        HinmokuCodeEdit->Enabled       = true;
        HinmokuCodeEdit->Color         = clCream;
        HinmokuSearchButton->Enabled   = true;
    }else if (no == 2){ // 項目1
        TokuisakiCodeEdit->Enabled     = true;
        TokuisakiCodeEdit->Color       = clCream;
        TokuisakiSearchButton->Enabled = true;
        Item1CodeEdit->Enabled         = false;
        Item1CodeEdit->Text            = AnsiString();
        Item1CodeEdit->Color           = clSilver;
        Item1SearchButton->Enabled     = false;
        Item2CodeEdit->Enabled         = true;
        Item2CodeEdit->Color           = clCream;
        Item2SearchButton->Enabled     = true;
        HinmokuCodeEdit->Enabled       = true;
        HinmokuCodeEdit->Color         = clCream;
        HinmokuSearchButton->Enabled   = true;
    }else if (no == 3){ // 項目2
        TokuisakiCodeEdit->Enabled     = true;
        TokuisakiCodeEdit->Color       = clCream;
        TokuisakiSearchButton->Enabled = true;
        Item1CodeEdit->Enabled         = true;
        Item1CodeEdit->Color           = clCream;
        Item1SearchButton->Enabled     = true;
        Item2CodeEdit->Enabled         = false;
        Item2CodeEdit->Text            = AnsiString();
        Item2CodeEdit->Color           = clSilver;
        Item2SearchButton->Enabled     = false;
        HinmokuCodeEdit->Enabled       = true;
        HinmokuCodeEdit->Color         = clCream;
        HinmokuSearchButton->Enabled   = true;
    }else if (no == 4){ // 品目
        TokuisakiCodeEdit->Enabled     = true;
        TokuisakiCodeEdit->Color       = clCream;
        TokuisakiSearchButton->Enabled = true;
        Item1CodeEdit->Enabled         = true;
        Item1CodeEdit->Color           = clCream;
        Item1SearchButton->Enabled     = true;
        Item2CodeEdit->Enabled         = true;
        Item2CodeEdit->Color           = clCream;
        Item2SearchButton->Enabled     = true;
        HinmokuCodeEdit->Enabled       = false;
        HinmokuCodeEdit->Text          = AnsiString();
        HinmokuCodeEdit->Color         = clSilver;
        HinmokuSearchButton->Enabled   = false;
    }else{
        TokuisakiCodeEdit->Enabled     = false;
        TokuisakiCodeEdit->Text        = AnsiString();
        TokuisakiCodeEdit->Color       = clSilver;
        TokuisakiSearchButton->Enabled = false;
        Item1CodeEdit->Enabled         = false;
        Item1CodeEdit->Text            = AnsiString();
        Item1CodeEdit->Color           = clSilver;
        Item1SearchButton->Enabled     = false;
        Item2CodeEdit->Enabled         = false;
        Item2CodeEdit->Text            = AnsiString();
        Item2CodeEdit->Color           = clSilver;
        Item2SearchButton->Enabled     = false;
        HinmokuCodeEdit->Enabled       = false;
        HinmokuCodeEdit->Text          = AnsiString();
        HinmokuCodeEdit->Color         = clSilver;
        HinmokuSearchButton->Enabled   = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::ItemNoPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::ItemNoPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

