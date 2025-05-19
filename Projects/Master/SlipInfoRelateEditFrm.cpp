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
    //DM->AddComboMap(ItemNoNameComboBox, DM->itemno_map_, "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 12");
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

      if (Application->MessageBox("�o�^�^�C�����܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
            return;

      if (!PostRecord())
            return;

      Application->MessageBox("�o�^�^�C�����܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

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
      id_ = DM->M_SlipInfoRelate->FieldByName("�`�[���֘AID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::Action8Execute(TObject *Sender)
{
      if (DM->M_SlipInfoRelate->Eof)
            return;

      DM->M_SlipInfoRelate->Next();
      id_ = DM->M_SlipInfoRelate->FieldByName("�`�[���֘AID")->AsInteger;
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
      sql = " SELECT * FROM V_�`�[���֘A WHERE �`�[���֘AID = " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            ClearForm();
            ClearSlipInfo();
            id_ = 0;
            return;
      }

      ItemNoCodeEdit->Text    = ToInt(set[0]["���ڔԍ�"]);
      SettingCodeEdit->Text   = ToInt(set[0]["���ڃR�[�h"]);
      SlipInfoCodeEdit->Text  = ToInt(set[0]["�`�[���R�[�h"]);
}
//---------------------------------------------------------------------------
bool __fastcall TSlipInfoRelateEditForm::PostRecord()
{
    NsFieldSet slipinfo_fields, sliprelate_fields;
    int item_no, item_id, slipinfo_id;

    item_no = ItemNoCodeEdit->Text.ToIntDef(0);
    int code = SettingCodeEdit->Text.ToIntDef(0);
    if (item_no == 1){
        // ���Ӑ�
        item_id = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", code, "���Ӑ�ID"));
    }else if (item_no == 2){
        // ����1
        item_id = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", code, "����1ID"));
    }else if (item_no == 3){
        // ����2
        item_id = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", code, "����2ID"));
    }else if (item_no == 4){
        // �i��
        item_id = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", code, "�i��ID"));
    }else if (item_no == 5){
        // ���|�敪
        NsFieldSet keys;
        keys << NsField("�敪���ރR�[�h", 4)
             << NsField("�敪�R�[�h",     code);
        item_id = ToInt(DM->DBI.Lookup("M_�敪", keys, "�敪ID"));
    }else
        item_id = 0;

    slipinfo_id = ToInt(DM->DBI.Lookup("M_�`�[���", "�`�[���R�[�h", SlipInfoCodeEdit->Text.ToIntDef(0), "�`�[���ID"));

    // �`�[���֘A
    sliprelate_fields
        << NsField("[���ڔԍ�]",   item_no)
        << NsField("[����ID]",     item_id)
        << NsField("[�`�[���ID]", slipinfo_id);

    // �`�[�����X�V
    slipinfo_fields
        << NsField("[�`�[���]",        SlipInfoNameEdit->Text)
        << NsField("[���ɓ`�[�^�C�g��1]", StoreroomEntryTitleEdit1->Text)
        << NsField("[���ɓ`�[�^�C�g��2]", StoreroomEntryTitleEdit2->Text)
        << NsField("[���ɓ`�[�^�C�g��3]", StoreroomEntryTitleEdit3->Text)
        << NsField("[�o�ɓ`�[�^�C�g��1]", DeliverySlipEdit1->Text)
        << NsField("[�o�ɓ`�[�^�C�g��2]", DeliverySlipEdit2->Text)
        << NsField("[�o�ɓ`�[�^�C�g��3]", DeliverySlipEdit3->Text)
        << NsField("[��Ж�]",            CompanyNameEdit->Text)
        << NsField("[��Џ��1]",         CompanyInfoEdit1->Text)
        << NsField("[��Џ��2]",         CompanyInfoEdit2->Text)
        << NsField("[��Џ��3]",         CompanyInfoEdit3->Text)
        << NsField("[��Џ��4]",         CompanyInfoEdit4->Text);

    DM->ADOConnection->BeginTrans();
    try{
        // �`�[���}�X�^
        DM->DBI.Update("M_�`�[���", "�`�[���ID", slipinfo_id, slipinfo_fields);

        // �`�[���֘A�}�X�^
        if (id_ == 0)
            DM->DBI.Insert("M_�`�[���֘A", sliprelate_fields);
        else
            DM->DBI.Update("M_�`�[���֘A", "�`�[���֘AID", id_, sliprelate_fields);
    }catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
        Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
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
        int slip_id = ToInt(DM->DBI.Lookup("M_�`�[���", "�`�[���R�[�h", SlipInfoCodeEdit->Text.ToIntDef(0), "�`�[���ID"));
        keys << NsField("[�`�[���ID]", slip_id);
        if (!DM->DBI.IsExist("M_�`�[���", keys)){
            Application->MessageBox("�`�[��񂪕s���ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoCodeEdit->SetFocus();
            return false;
        }
        return true;
    }

    if (ItemNoCodeEdit->Text.ToIntDef(0) == 0 || ItemNoNameComboBox->ItemIndex == -1){
        Application->MessageBox("���ڔԍ��������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        ItemNoCodeEdit->SetFocus();
        return false;
    }

    if (SettingCodeEdit->Text.ToIntDef(0) == 0){
        Application->MessageBox("�ݒ�R�[�h�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        SettingCodeEdit->SetFocus();
        return false;
    }

    NsFieldSet keys;
    int slipinfo_id = ToInt(DM->DBI.Lookup("M_�`�[���", "�`�[���R�[�h", SlipInfoCodeEdit->Text.ToIntDef(0), "�`�[���ID"));
    keys << NsField("[�`�[���ID]", slipinfo_id);
    if (!DM->DBI.IsExist("M_�`�[���", keys)){
        Application->MessageBox("�`�[��񂪕s���ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SetMode(TInputMode mode)
{
    if (mode == imNew){
        ModePanel->Caption       = "�V�K";
        ModePanel->Color         = TColor(NEW_CLR);
        RenzokuCheckBox->Enabled = true;
        Action7->Enabled         = false;
        Action8->Enabled         = false;
    }else if (mode == imMod){
        ModePanel->Caption       = "�C��";
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
    StatusBar->SimpleText = "  ���ڂ���͂��ĉ�����";
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
        // ���Ӑ�
        name = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", code, "���Ӑ於��"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 2){
        // ���ڂP
        name = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", code, "����1����"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 3){
        // ����2
        name = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", code, "����2����"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 4){
        // �i��
        name = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", code, "�i�ږ���"));
    }else if (ItemNoCodeEdit->Text.ToIntDef(0) == 5){
        // ���|�敪
        NsFieldSet keys;
        keys << NsField("�敪���ރR�[�h", 4)
             << NsField("�敪�R�[�h",     code);
        name = ToString(DM->DBI.Lookup("M_�敪", keys, "�敪����"));
    }else{
        name = "";
    }

    SettingNameEdit->Text = name;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SettingCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  �ݒ�Ώۂ���͂��Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SettingSearchButtonClick(
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

    SettingCodeEdit->Text = SearchForm->Query->FieldByName("�R�[�h")->AsInteger;
    SlipInfoCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SlipInfoCodeEditChange(
      TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql;
    sql = "SELECT * FROM V_�`�[��� WHERE �`�[���R�[�h = " + IntToStr(SlipInfoCodeEdit->Text.ToIntDef(0));
    if (!DM->DBI.GetRecordSet(sql, set)){
        ClearSlipInfo();
        return;
    }

    SlipInfoNameEdit->Text         = ToString(set[0]["�`�[���"]);
    StoreroomEntryTitleEdit1->Text = ToString(set[0]["���ɓ`�[�^�C�g��1"]);
    StoreroomEntryTitleEdit2->Text = ToString(set[0]["���ɓ`�[�^�C�g��2"]);
    StoreroomEntryTitleEdit3->Text = ToString(set[0]["���ɓ`�[�^�C�g��3"]);
    DeliverySlipEdit1->Text        = ToString(set[0]["�o�ɓ`�[�^�C�g��1"]);
    DeliverySlipEdit2->Text        = ToString(set[0]["�o�ɓ`�[�^�C�g��2"]);
    DeliverySlipEdit3->Text        = ToString(set[0]["�o�ɓ`�[�^�C�g��3"]);
    CompanyNameEdit->Text          = ToString(set[0]["��Ж�"]);
    CompanyInfoEdit1->Text         = ToString(set[0]["��Џ��1"]);
    CompanyInfoEdit2->Text         = ToString(set[0]["��Џ��2"]);
    CompanyInfoEdit3->Text         = ToString(set[0]["��Џ��3"]);
    CompanyInfoEdit4->Text         = ToString(set[0]["��Џ��4"]);
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SlipInfoCodeEditEnter(
      TObject *Sender)
{
    StatusBar->SimpleText = "  �`�[����I�����Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoRelateEditForm::SlipInfoSerachButtonClick(
      TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT �`�[���R�[�h, �`�[���, ���ɓ`�[�^�C�g��1, ���ɓ`�[�^�C�g��2, ���ɓ`�[�^�C�g��3, �o�ɓ`�[�^�C�g��1, �o�ɓ`�[�^�C�g��2, �o�ɓ`�[�^�C�g��3,"
                                   "        ��Ж�, ��Џ��1, ��Џ��2, ��Џ��3, ��Џ��4"
                                   " FROM   V_�`�[���";
    SearchForm->orderby_sql      = " ORDER BY �`�[���R�[�h";
    SearchForm->table_name       = " V_�`�[���";
    SearchForm->list_->CommaText = " �`�[���R�[�h, �`�[���, ���ɓ`�[�^�C�g��1, ���ɓ`�[�^�C�g��2, ���ɓ`�[�^�C�g��3, �o�ɓ`�[�^�C�g��1, �o�ɓ`�[�^�C�g��2, �o�ɓ`�[�^�C�g��3,"
                                   " ��Ж�, ��Џ��1, ��Џ��2, ��Џ��3, ��Џ��4";

    if (SearchForm->ShowModal() != mrOk)
        return;

    SlipInfoCodeEdit->Text = SearchForm->Query->FieldByName("�`�[���R�[�h")->AsInteger;
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

