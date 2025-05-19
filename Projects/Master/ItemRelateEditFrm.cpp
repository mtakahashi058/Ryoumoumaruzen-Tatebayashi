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

    if (Application->MessageBox("�o�^�^�C�����܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
        return;

    if (!PostRecord())
        return;

    Application->MessageBox("�o�^�^�C�����܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

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
    id_ = DM->M_ItemRelate->FieldByName("���ڊ֘AID")->AsInteger;
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
    id_ = DM->M_ItemRelate->FieldByName("���ڊ֘AID")->AsInteger;
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
    StatusBar->SimpleText = "  ���ڂ���͂��ĉ�����";
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
    StatusBar->SimpleText = "  ���ڂ�I�����Ă�������";
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
        // ���Ӑ�
        name = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "���Ӑ於��"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 2){
        // ���ڂP
        name = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "����1����"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 3){
        // ����2
        name = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "����2����"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 4){
        // �i��
        name = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "�i�ږ���"));
    }else{
        name = "";
    }

    SetObjectNameEdit->Text = name;
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetObjectCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  �ݒ�Ώۂ���͂��Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetObjectSearchButtonClick(
      TObject *Sender)
{
    if (ItemNoCodeEdit->Text.ToIntDef(0) == 1){
        // ���Ӑ�
        SearchForm->based_sql        = " SELECT ���Ӑ�R�[�h AS �R�[�h, ���Ӑ於�� AS ���� FROM V_���Ӑ�";
        SearchForm->orderby_sql      = " ORDER BY ���Ӑ�R�[�h";
        SearchForm->table_name       = " V_���Ӑ�";
        SearchForm->list_->CommaText = " ���Ӑ旪��, ���Ӑ�J�i";
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 2){
        // ���ڂP
        SearchForm->based_sql        = " SELECT ����1�R�[�h AS �R�[�h, ����1���� AS ���� FROM V_����1";
        SearchForm->orderby_sql      = " ORDER BY ����1�R�[�h";
        SearchForm->table_name       = " V_����1";
        SearchForm->list_->CommaText = " ����1����, ����1�J�i";
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 3){
        // ����2
        SearchForm->based_sql        = " SELECT ����2�R�[�h AS �R�[�h, ����2���� AS ���� FROM V_����2";
        SearchForm->orderby_sql      = " ORDER BY ����2�R�[�h";
        SearchForm->table_name       = " V_����2";
        SearchForm->list_->CommaText = " ����2����, ����2�J�i";
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 4){
        // �i��
        SearchForm->based_sql        = " SELECT �i�ڃR�[�h AS �R�[�h, �i�ږ��� AS ���� FROM V_�i��";
        SearchForm->orderby_sql      = " ORDER BY �i�ڃR�[�h";
        SearchForm->table_name       = " V_�i��";
        SearchForm->list_->CommaText = " �i�ږ���, �i�ڃJ�i";
    }else{
        Application->MessageBox("���ڔԍ��������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    SearchForm->Top  = Application->MainForm->Top + 50;
    SearchForm->Left = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    if (SearchForm->ShowModal() != mrOk)
        return;
    SetObjectCodeEdit->Text = SearchForm->Query->FieldByName("�R�[�h")->AsInteger;

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
    TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::TokuisakiCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  " + MainForm->toku_ + "����͂��Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::TokuisakiSearchButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i, �Z��1, �Z��2, �d�b�ԍ� FROM V_���Ӑ� WHERE �g�p�敪 = 1";
	SearchForm->orderby_sql      = " ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name       = " V_���Ӑ�";
	SearchForm->list_->CommaText = " ���Ӑ�R�[�h,���Ӑ旪��,���Ӑ�J�i,�Z��1,�Z��2,�d�b�ԍ�";

	if (SearchForm->ShowModal() != mrOk)
		return;

	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;

    if (Item1CodeEdit->Enabled)
    	Item1CodeEdit->SetFocus();
    else
        Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item1CodeEditChange(TObject *Sender)
{
    Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item1CodeEditEnter(TObject *Sender)
{
    StatusBar->SimpleText = "  " + MainForm->item1_ + "����͂��Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item1SearchButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT ����1�R�[�h, ����1����, ����1�J�i FROM V_����1 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql      = " ORDER BY ����1�R�[�h";
    SearchForm->table_name       = " V_����1";
    SearchForm->list_->CommaText = " ����1�R�[�h,����1����,����1�J�i";

    if (SearchForm->ShowModal() != mrOk)
        return;

    Item1CodeEdit->Text = SearchForm->Query->FieldByName("����1�R�[�h")->AsInteger;
    if (Item2CodeEdit->Enabled)
        Item2CodeEdit->SetFocus();
    else
        HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item2CodeEditChange(TObject *Sender)
{
    Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::Item2CodeEditEnter(TObject *Sender)
{
    StatusBar->SimpleText = "  " + MainForm->item2_ + "����͂��Ă�������";
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
    SearchForm->based_sql        = " SELECT ����2�R�[�h, ����2����, ����2�J�i FROM V_����2 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql      = " ORDER BY ����2�R�[�h";
    SearchForm->table_name       = " V_����2";
    SearchForm->list_->CommaText = " ����2�R�[�h,����2����,����2�J�i";

    if (SearchForm->ShowModal() != mrOk)
        return;

    Item2CodeEdit->Text = SearchForm->Query->FieldByName("����2�R�[�h")->AsInteger;

    if (HinmokuCodeEdit->Enabled)
        HinmokuCodeEdit->SetFocus();
    else
        Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::HinmokuCodeEditChange(TObject *Sender)
{
      HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i�ږ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  " + MainForm->hin_ + "���͂��Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::HinmokuSearchButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT �i�ڃR�[�h, �i�ږ���, �i�ڃJ�i FROM V_�i�� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql      = " ORDER BY �i�ڃR�[�h";
    SearchForm->table_name       = " V_�i��";
    SearchForm->list_->CommaText = " �i�ڃR�[�h,�i�ڗ���,�i�ڃJ�i";

    if (SearchForm->ShowModal() != mrOk)
        return;

    HinmokuCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
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
    sql = " SELECT * FROM V_���ڊ֘A WHERE ���ڊ֘AID = " + IntToStr(id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        ClearForm();
        id_ = 0;
        return;
    }

    ItemNoCodeEdit->Text    = ToInt(set[0]["���ڔԍ�"]);
    SetObjectCodeEdit->Text = ToInt(set[0]["���ڃR�[�h"]);
    TokuisakiCodeEdit->Text = FormatFloat("#", ToInt(set[0]["���Ӑ�R�[�h"]));
    Item1CodeEdit->Text     = FormatFloat("#", ToInt(set[0]["����1�R�[�h"]));
    Item2CodeEdit->Text     = FormatFloat("#", ToInt(set[0]["����2�R�[�h"]));
    HinmokuCodeEdit->Text   = FormatFloat("#", ToInt(set[0]["�i�ڃR�[�h"]));
}
//---------------------------------------------------------------------------
bool __fastcall TItemRelateEditForm::PostRecord()
{
      NsFieldSet keys, fields;

      int item_no, setobject_id, tokuisaki_id, item1_id, item2_id, hin_id;

      item_no      = ItemNoCodeEdit->Text.ToIntDef(0);
      tokuisaki_id = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
      item1_id     = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1ID"));
      item2_id     = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2ID"));
      hin_id       = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID"));
      if (item_no == 1)
            setobject_id = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
      else if (item_no == 2)
            setobject_id = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "����1ID"));
      else if (item_no == 3)
            setobject_id = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "����2ID"));
      else if (item_no == 4)
            setobject_id = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", SetObjectCodeEdit->Text.ToIntDef(0), "�i��ID"));
      else
            setobject_id = 0;


      fields      << NsField("[���ڔԍ�]", item_no)
                  << NsField("[����ID]",   setobject_id)
                  << NsField("[���Ӑ�ID]", tokuisaki_id)
                  << NsField("[����1ID]",  item1_id)
                  << NsField("[����2ID]",  item2_id)
                  << NsField("[�i��ID]",   hin_id);

      try{
            if (id_ == 0){
                  // �V�K
                  DM->DBI.Insert("M_���ڊ֘A", fields);
            }else{
                  // �X�V
                  DM->DBI.Update("M_���ڊ֘A", "���ڊ֘AID", id_, fields);
            }
      }catch (Exception &e){
            Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
            return false;
      }

      is_edit_ = true;

      return true;
}
//---------------------------------------------------------------------------
bool __fastcall TItemRelateEditForm::CheckEdit()
{
      if (ItemNoCodeEdit->Text.ToIntDef(0) == 0 || ItemNoNameComboBox->Text == ""){
            Application->MessageBox("���ڂ������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            ItemNoCodeEdit->SetFocus();
            return false;
      }

      if (SetObjectCodeEdit->Text.ToIntDef(0) == 0){
            Application->MessageBox("�ݒ�Ώۂ������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SetObjectCodeEdit->SetFocus();
            return false;
      }

      return true;
}
//---------------------------------------------------------------------------
void __fastcall TItemRelateEditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
            ModePanel->Caption = "�V�K";
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
            ModePanel->Caption = "�C��";
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

    if (no == 1){       // �Ǝ�
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
    }else if (no == 2){ // ����1
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
    }else if (no == 3){ // ����2
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
    }else if (no == 4){ // �i��
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

