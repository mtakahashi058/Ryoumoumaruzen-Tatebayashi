//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlipInfoEditFrm.h"
#include "DMFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TSlipInfoEditForm *SlipInfoEditForm;
//---------------------------------------------------------------------------
__fastcall TSlipInfoEditForm::TSlipInfoEditForm(TComponent* Owner)
      : TForm(Owner), is_edit_(false)
{
}
//---------------------------------------------------------------------------
int __fastcall TSlipInfoEditForm::ShowModalWithId(int id)
{
      id_ = id;
      return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::FormShow(TObject *Sender)
{
      if (id_ == 0){
            SetMode(imNew);
            SlipInfoNoEdit->SetFocus();
      }else{
            SetMode(imMod);
            SlipInfoNameEdit->SetFocus();
      }

      ClearForm();
      if (DM->GetMode(ModePanel) == imMod)
            BrowseRecord();

      is_edit_ = false;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
                  }else{
                        Action5->OnExecute(NULL);
                  }
                  break;
            case VK_UP:
                  if (ActiveControl->Tag != 0){
                        keybd_event(VK_SHIFT, 0, 0, 0);
                        keybd_event(VK_TAB, 0, 0, 0);
                        keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
                        keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
                  }
                  break;
      }
}
//---------------------------------------------------------------------------
// F1 �V�K
void __fastcall TSlipInfoEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      SlipInfoNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F3 �폜
void __fastcall TSlipInfoEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (id_ == 1){
        Application->MessageBox("���̃f�[�^�͍폜�ł��܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
        return;
    }

    if (!DM->DBI.IsExist("M_�`�[���", "�`�[���ID", id_)){
        Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H", "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    NsFieldSet keys;
    keys << NsField("[�`�[���ID]", id_);
    try{
        DM->DBI.Delete("M_�`�[���", keys);
    }catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
        Application->MessageBox(("�f�[�^�폜�Ɏ��s���܂���\r\n" + e.Message).c_str(), "�폜", MB_OK | MB_ICONWARNING);
        return;
    }
    msg = "�f�[�^���폜���܂���";

    DM->ADOConnection->CommitTrans();
    MainForm->OpenQuery(page_, MainForm->order_);
    id_ = MainForm->query[page_]->FieldByName(keyfield_)->AsInteger;
    BrowseRecord();
    Application->MessageBox(msg.c_str(), "�폜", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
// �o�^
void __fastcall TSlipInfoEditForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("�o�^�^�C�����܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("�o�^�^�C�����܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	if (DM->GetMode(ModePanel) == imNew){
		if (RenzokuCheckBox->Checked)
			ClearForm();
		else
			Close();
	}else{
		BrowseRecord();
	}
      SlipInfoNameEdit->SetFocus();
}
//---------------------------------------------------------------------------
// �O��
void __fastcall TSlipInfoEditForm::Action7Execute(TObject *Sender)
{
      if (DM->M_SlipInfo->Bof)
            return;

      DM->M_SlipInfo->Prior();
      id_ = DM->M_SlipInfo->FieldByName("�`�[���ID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
// ����
void __fastcall TSlipInfoEditForm::Action8Execute(TObject *Sender)
{
      if (DM->M_SlipInfo->Eof)
            return;

      DM->M_SlipInfo->Next();
      id_ = DM->M_SlipInfo->FieldByName("�`�[���ID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
// ����
void __fastcall TSlipInfoEditForm::Action12Execute(TObject *Sender)
{
      Close();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SlipInfoNoEditExit(TObject *Sender)
{
      if (SlipInfoNoEdit->Text.ToIntDef(0) == 0)
            return;

      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT * FROM V_�`�[��� WHERE �`�[���R�[�h = " + IntToStr(SlipInfoNoEdit->Text.ToIntDef(0)) + " AND �`�[���ID <> " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set))
            return;

      if (Application->MessageBox("����R�[�h���o�^����Ă��܂��B\r\n�C�����[�h�ŌĂяo���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

      id_ = ToInt(set[0]["�`�[���ID"]);
      SetMode(imMod);
      BrowseRecord();
      SlipInfoNameEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SaibanButtonClick(TObject *Sender)
{
      SlipInfoNoEdit->Text = GetSlipInfoNo();
      SlipInfoNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
            ModePanel->Caption       = "�V�K";
            ModePanel->Color         = TColor(NEW_CLR);
            //SlipInfoNoEdit->ReadOnly = false;
            //SlipInfoNoEdit->Color    = clWindow;
            SaibanButton->Enabled    = true;
            Action7->Enabled         = false;
            Action8->Enabled         = false;
      }else if (mode == imMod){
            ModePanel->Caption       = "�C��";
            ModePanel->Color         = TColor(MOD_CLR);
            //SlipInfoNoEdit->ReadOnly = true;
            //SlipInfoNoEdit->Color    = clSilver;
            SaibanButton->Enabled    = false;
            Action7->Enabled         = true;
            Action8->Enabled         = true;
      }
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::ClearForm()
{
      SlipInfoNoEdit->Text    = GetSlipInfoNo();
      SlipInfoNameEdit->Text  = AnsiString();
      NyukoTitleEdit1->Text   = AnsiString();
      NyukoTitleEdit2->Text   = AnsiString();
      NyukoTitleEdit3->Text   = AnsiString();
      ShukoTitleEdit1->Text   = AnsiString();
      ShukoTitleEdit2->Text   = AnsiString();
      ShukoTitleEdit3->Text   = AnsiString();
      CompanyNameEdit->Text   = AnsiString();
      CompanyInfoEdit1->Text  = AnsiString();
      CompanyInfoEdit2->Text  = AnsiString();
      CompanyInfoEdit3->Text  = AnsiString();
      CompanyInfoEdit4->Text  = AnsiString();

      AmountPrint1Check->Checked = true;
      AmountPrint2Check->Checked = true;
      AmountPrint3Check->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::BrowseRecord()
{
      NsRecordSet set;
      if (!DM->DBI.GetRecordSet("SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(id_), set)){
            Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            ClearForm();
            id_ = 0;
            return;
      }

      id_                        = ToInt(set[0]["�`�[���ID"]);
      SlipInfoNoEdit->Text       = ToInt(set[0]["�`�[���R�[�h"]);
      SlipInfoNameEdit->Text     = ToString(set[0]["�`�[���"]);
      NyukoTitleEdit1->Text      = ToString(set[0]["���ɓ`�[�^�C�g��1"]);
      NyukoTitleEdit2->Text      = ToString(set[0]["���ɓ`�[�^�C�g��2"]);
      NyukoTitleEdit3->Text      = ToString(set[0]["���ɓ`�[�^�C�g��3"]);
      ShukoTitleEdit1->Text      = ToString(set[0]["�o�ɓ`�[�^�C�g��1"]);
      ShukoTitleEdit2->Text      = ToString(set[0]["�o�ɓ`�[�^�C�g��2"]);
      ShukoTitleEdit3->Text      = ToString(set[0]["�o�ɓ`�[�^�C�g��3"]);
      CompanyNameEdit->Text      = ToString(set[0]["��Ж�"]);
      CompanyInfoEdit1->Text     = ToString(set[0]["��Џ��1"]);
      CompanyInfoEdit2->Text     = ToString(set[0]["��Џ��2"]);
      CompanyInfoEdit3->Text     = ToString(set[0]["��Џ��3"]);
      CompanyInfoEdit4->Text     = ToString(set[0]["��Џ��4"]);
      AmountPrint1Check->Checked = ToBit(set[0]["���z�󎚋敪1"]);
      AmountPrint2Check->Checked = ToBit(set[0]["���z�󎚋敪2"]);
      AmountPrint3Check->Checked = ToBit(set[0]["���z�󎚋敪3"]);
}
//---------------------------------------------------------------------------
bool __fastcall TSlipInfoEditForm::PostRecord()
{
      NsFieldSet fields, keys;

      fields      << NsField("[�`�[���R�[�h]",      SlipInfoNoEdit->Text.ToIntDef(0))
                  << NsField("[�`�[���]",          SlipInfoNameEdit->Text)
                  << NsField("[���ɓ`�[�^�C�g��1]",   NyukoTitleEdit1->Text)
                  << NsField("[���ɓ`�[�^�C�g��2]",   NyukoTitleEdit2->Text)
                  << NsField("[���ɓ`�[�^�C�g��3]",   NyukoTitleEdit3->Text)
                  << NsField("[�o�ɓ`�[�^�C�g��1]",   ShukoTitleEdit1->Text)
                  << NsField("[�o�ɓ`�[�^�C�g��2]",   ShukoTitleEdit2->Text)
                  << NsField("[�o�ɓ`�[�^�C�g��3]",   ShukoTitleEdit3->Text)
                  << NsField("[���z�󎚋敪1]",       AmountPrint1Check->Checked ? 1 : 0)
                  << NsField("[���z�󎚋敪2]",       AmountPrint2Check->Checked ? 1 : 0)
                  << NsField("[���z�󎚋敪3]",       AmountPrint3Check->Checked ? 1 : 0)
                  << NsField("[��Ж�]",              CompanyNameEdit->Text)
                  << NsField("[��Џ��1]",           CompanyInfoEdit1->Text)
                  << NsField("[��Џ��2]",           CompanyInfoEdit2->Text)
                  << NsField("[��Џ��3]",           CompanyInfoEdit3->Text)
                  << NsField("[��Џ��4]",           CompanyInfoEdit4->Text);

      try{
            if (id_ == 0){
                  // �V�K
                  DM->DBI.Insert("M_�`�[���", fields);
            }else{
                  // �X�V
                  DM->DBI.Update("M_�`�[���", "�`�[���ID", id_, fields);
            }
      }catch (Exception &e){
            Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
            return false;
      }

      is_edit_ = true;

      return true;
}
//---------------------------------------------------------------------------
bool __fastcall TSlipInfoEditForm::CheckEdit()
{
      if (DM->GetMode(ModePanel) != imNew && SlipInfoNoEdit->Text.ToIntDef(0) == 0){
            Application->MessageBox("�`�[���R�[�h�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoNoEdit->SetFocus();
            return false;
      }

      ///// �R�[�h�d���`�F�b�N
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT"
            "     *"
            " FROM"
            "     M_�`�[���"
            " WHERE"
            "     �`�[���R�[�h = " + IntToStr(SlipInfoNoEdit->Text.ToIntDef(0)) +
            " AND"
            "     �`�[���ID <> " + IntToStr(id_);
      if (DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("�R�[�h���d�����Ă��܂��B���̃R�[�h���w�肵�Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoNoEdit->SetFocus();
            return false;
      }

      if (SlipInfoNameEdit->Text == ""){
            Application->MessageBox("�`�[��񖼂������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoNameEdit->SetFocus();
            return false;
      }

      if (NyukoTitleEdit1->Text == ""){
            Application->MessageBox("���ɓ`�[�^�C�g��1�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            NyukoTitleEdit1->SetFocus();
            return false;
      }

      if (SlipInfoNameEdit->Text.Length() > 40)
            SlipInfoNameEdit->Text = DM->TrimString(SlipInfoNameEdit->Text, 40);

      if (NyukoTitleEdit1->Text.Length() > 16)
            NyukoTitleEdit1->Text = DM->TrimString(NyukoTitleEdit1->Text, 16);

      if (NyukoTitleEdit2->Text.Length() > 16)
            NyukoTitleEdit2->Text = DM->TrimString(NyukoTitleEdit2->Text, 16);

      if (NyukoTitleEdit3->Text.Length() > 16)
            NyukoTitleEdit3->Text = DM->TrimString(NyukoTitleEdit3->Text, 16);

      if (ShukoTitleEdit1->Text.Length() > 16)
            ShukoTitleEdit1->Text = DM->TrimString(ShukoTitleEdit1->Text, 16);

      if (ShukoTitleEdit2->Text.Length() > 16)
            ShukoTitleEdit2->Text = DM->TrimString(ShukoTitleEdit2->Text, 16);

      if (ShukoTitleEdit3->Text.Length() > 16)
            ShukoTitleEdit3->Text = DM->TrimString(ShukoTitleEdit3->Text, 16);

      if (CompanyNameEdit->Text.Length() > 40)
            CompanyNameEdit->Text = DM->TrimString(CompanyNameEdit->Text, 40);

      if (CompanyInfoEdit1->Text.Length() > 40)
            CompanyInfoEdit1->Text = DM->TrimString(CompanyInfoEdit1->Text, 40);

      if (CompanyInfoEdit2->Text.Length() > 40)
            CompanyInfoEdit2->Text = DM->TrimString(CompanyInfoEdit2->Text, 40);

      if (CompanyInfoEdit3->Text.Length() > 40)
            CompanyInfoEdit3->Text = DM->TrimString(CompanyInfoEdit3->Text, 40);

      if (CompanyInfoEdit4->Text.Length() > 40)
            CompanyInfoEdit4->Text = DM->TrimString(CompanyInfoEdit4->Text, 40);

      return true;
}
//---------------------------------------------------------------------------
int __fastcall TSlipInfoEditForm::GetSlipInfoNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT �`�[���R�[�h FROM M_�`�[��� WHERE �`�[���R�[�h > 0 ORDER BY �`�[���R�[�h", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["�`�[���R�[�h"]))
            break;
        else
            code++;
    }

    if (code > 999){
        Application->MessageBox("�o�^����������ɒB���܂����B\r\n����ȏ�o�^�ł��܂���B",
            this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return -1;
    }

    return code;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SlipInfoNoPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SlipInfoNoPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

