//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BankEditFrm.h"
#include "DMFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TBankEditForm *BankEditForm;
//---------------------------------------------------------------------------
__fastcall TBankEditForm::TBankEditForm(TComponent* Owner)
      : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall TBankEditForm::ShowModalWithId(int id)
{
      id_ = id;

      return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::FormShow(TObject *Sender)
{
      ClearForm();
      if (id_ == 0){
            SetMode(imNew);
      }else{
            SetMode(imMod);
            BrowseRecord();
      }

      CodeEdit->SetFocus();
      is_edit_ = false;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
void __fastcall TBankEditForm::CodeEditExit(TObject *Sender)
{
	if (CodeEdit->Text == "")
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT ��sID FROM M_��s WHERE ��s�R�[�h = " + CodeEdit->Text + " AND ��sID <> " + IntToStr(id_), set))
		return;

      if (Application->MessageBox("����R�[�h���o�^����Ă��܂��B\r\n�C�����[�h�ŌĂяo���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

	SetMode(imMod);
	id_ = ToInt(set[0]["��sID"]);
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_��s", "��sID", id_)){
            Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
            if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H", "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet keys;
            keys << NsField("[��sID]", id_);
            try{
                  DM->DBI.Delete("M_��s", keys);
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
void __fastcall TBankEditForm::Action5Execute(TObject *Sender)
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
			CodeEdit->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		NameEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Bank->Bof)
		return;

	DM->M_Bank->Prior();
	id_ = DM->M_Bank->FieldByName("��sID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Bank->Eof)
		return;

	DM->M_Bank->Next();
	id_ = DM->M_Bank->FieldByName("��sID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action12Execute(TObject *Sender)
{
      Close();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::ClearForm()
{
      CodeEdit->Text          = GetNo();
      NameEdit->Text          = AnsiString();
      SitenNameEdit->Text     = AnsiString();
      KozaNameEdit->Text      = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::BrowseRecord()
{
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT * FROM V_��s WHERE ��sID = " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
      }

      id_                     = ToInt(set[0]["��sID"]);
      CodeEdit->Text          = ToInt(set[0]["��s�R�[�h"]);
      NameEdit->Text          = ToString(set[0]["��s����"]);
      SitenNameEdit->Text     = ToString(set[0]["�x�X����"]);
      KozaNameEdit->Text      = ToString(set[0]["����"]);
      RenewDateEdit->Text     = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
      CreateDateEdit->Text    = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
bool __fastcall TBankEditForm::PostRecord()
{
      NsFieldSet fields;

      fields      << NsField("[��s�R�[�h]",    CodeEdit->Text.ToIntDef(0))
                  << NsField("[��s����]",      NameEdit->Text)
                  << NsField("[�x�X����]",      SitenNameEdit->Text)
                  << NsField("[����]",          KozaNameEdit->Text)
                  << NsField("[�X�V����]",      Now());

      try{
            if (id_ == 0){
                  fields << NsField("[�쐬����]", Now());
                  DM->DBI.Insert("M_��s", fields);
            }else{
                  DM->DBI.Update("M_��s", "��sID", id_, fields);
            }
      }catch (Exception &e){
		Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
      }

      is_edit_ = true;

      return true;
}
//---------------------------------------------------------------------------
bool __fastcall TBankEditForm::CheckEdit()
{
      if (CodeEdit->Text.ToIntDef(0) == 0){
            Application->MessageBox("�R�[�h�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            CodeEdit->SetFocus();
            return false;
      }

      ///// �R�[�h�d���`�F�b�N
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT"
            "     *"
            " FROM"
            "     M_��s"
            " WHERE"
            "     ��s�R�[�h = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
            " AND"
            "     ��sID <> " + IntToStr(id_);
      if (DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("�R�[�h���d�����Ă��܂��B���̃R�[�h���w�肵�Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            CodeEdit->SetFocus();
            return false;
      }

      if (NameEdit->Text.Length() > 16)
            NameEdit->Text = DM->TrimString(NameEdit->Text, 16);

      if (SitenNameEdit->Text.Length() > 16)
            SitenNameEdit->Text = DM->TrimString(SitenNameEdit->Text, 16);

      if (KozaNameEdit->Text.Length() > 14)
            KozaNameEdit->Text = DM->TrimString(KozaNameEdit->Text, 14);

      return true;
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
		ModePanel->Caption      = "�V�K";
		ModePanel->Color        = TColor(NEW_CLR);
            SaibanButton->Enabled   = true;
            Action7->Enabled        = false;
            Action8->Enabled        = false;
      }else if (mode == imMod){
		ModePanel->Caption      = "�C��";
		ModePanel->Color        = TColor(MOD_CLR);
            SaibanButton->Enabled   = false;
            Action7->Enabled        = true;
            Action8->Enabled        = true;
      }
}
//---------------------------------------------------------------------------
int __fastcall TBankEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT ��s�R�[�h FROM M_��s WHERE ��s�R�[�h > 0 ORDER BY ��s�R�[�h", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["��s�R�[�h"]))
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
void __fastcall TBankEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

