//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "KyotenEditFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TKyotenEditForm *KyotenEditForm;
//---------------------------------------------------------------------------
__fastcall TKyotenEditForm::TKyotenEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::FormShow(TObject *Sender)
{
    if (id_ == 0)
        SetMode(imNew);
    else
        SetMode(imMod);

	ClearForm();
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

    CodeEdit->SetFocus();
	is_edit_  = true;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall TKyotenEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::ClearForm()
{
      int code = GetNo();
      if (code != -1)
            CodeEdit->Text = code;
      else
            CodeEdit->Text = AnsiString();
	NameEdit->Text       = AnsiString();
	RenewDateEdit->Text  = AnsiString();
	CreateDateEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption = "�V�K";
		ModePanel->Color = TColor(NEW_CLR);
		SaibanButton->Enabled = true;
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "�C��";
		ModePanel->Color = TColor(MOD_CLR);
		SaibanButton->Enabled = false;
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled = true;
		Action8->Enabled = true;
	}
}
//---------------------------------------------------------------------------
int __fastcall TKyotenEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT ���_�R�[�h FROM M_���_ WHERE ���_�R�[�h > 0 ORDER BY ���_�R�[�h", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["���_�R�[�h"]))
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
bool __fastcall TKyotenEditForm::CheckEdit()
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
            "     M_���_"
            " WHERE"
            "     ���_�R�[�h = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
            " AND"
            "     ���_ID <> " + IntToStr(id_);
      if (DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("�R�[�h���d�����Ă��܂��B���̃R�[�h���w�肵�Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            CodeEdit->SetFocus();
            return false;
      }

	if (NameEdit->Text == ""){
		Application->MessageBox("���̂������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		NameEdit->SetFocus();
		return false;
	}

      if (NameEdit->Text.Length() > 20)
            NameEdit->Text = DM->TrimString(NameEdit->Text, 20);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TKyotenEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[���_�R�[�h]",       CodeEdit->Text.ToIntDef(0))
		   << NsField("[���_����]",         NameEdit->Text)
		   << NsField("[�X�V����]",          Now());

	try{
		if (id_ == 0){
			fields << NsField("[�쐬����]", Now());
			DM->DBI.Insert("M_���_", fields);
		}else{
			DM->DBI.Update("M_���_", "���_ID", id_, fields);
		}
	}catch (Exception &e){
		Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	is_edit_ = true;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM M_���_ WHERE ���_ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                       = ToInt(set[0]["���_ID"]);
	CodeEdit->Text            = ToString(set[0]["���_�R�[�h"]);
	NameEdit->Text            = ToString(set[0]["���_����"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_���_", "���_ID", id_)){
            Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
            if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H", "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet keys;
            keys << NsField("[���_ID]", id_);
            try{
                  DM->DBI.Delete("M_���_", keys);
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
void __fastcall TKyotenEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == CodeEdit)
		SaibanButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::Action5Execute(TObject *Sender)
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
void __fastcall TKyotenEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Kyoten->Bof)
		return;

	DM->M_Kyoten->Prior();
	id_ = DM->M_Kyoten->FieldByName("���_ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Kyoten->Eof)
		return;

	DM->M_Kyoten->Next();
	id_ = DM->M_Kyoten->FieldByName("���_ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::CodeEditExit(TObject *Sender)
{
	if (CodeEdit->Text == "")
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT ���_ID FROM M_���_ WHERE ���_�R�[�h = " + CodeEdit->Text + " AND ���_ID <> " + IntToStr(id_), set))
		return;

      if (Application->MessageBox("����R�[�h���o�^����Ă��܂��B\r\n�C�����[�h�ŌĂяo���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

	SetMode(imMod);
	id_ = ToInt(set[0]["���_ID"]);
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::SaibanButtonClick(TObject *Sender)
{
	CodeEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �R�[�h����͂��ĉ������i�̔�[F4]���������ŁA�󂫔Ԍ������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::NameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  ���̂���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TKyotenEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

