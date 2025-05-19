//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TaxEditFrm.h"
#include "DMFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TTaxEditForm *TaxEditForm;
//---------------------------------------------------------------------------
__fastcall TTaxEditForm::TTaxEditForm(TComponent* Owner)
      : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall TTaxEditForm::ShowModalWithId(int date)
{
      date_ = date;

      return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::FormShow(TObject *Sender)
{

      ClearForm();

      if (date_ == 0){
            SetMode(imNew);
            StartDatePicker->SetFocus();
      }else{
            SetMode(imMod);
            BrowseRecord();
            TaxRateEdit->SetFocus();
      }

      is_edit_ = false;
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
		if (ActiveControl->Tag != 0 && ActiveControl->Tag != 2 && ActiveControl->Tag != 99){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::Action5Execute(TObject *Sender)
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
			StartDatePicker->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		TaxRateEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Tax->Bof)
		return;

	DM->M_Tax->Prior();
	date_       = DM->M_Tax->FieldByName("�J�n���t")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Tax->Eof)
		return;

	DM->M_Tax->Next();
	date_       = DM->M_Tax->FieldByName("�J�n���t")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::Action12Execute(TObject *Sender)
{
      Close();
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
		ModePanel->Caption = "�V�K";
		ModePanel->Color = TColor(NEW_CLR);
            StartDatePicker->Color   = clCream;
            StartDatePicker->Enabled = true;
            Action7->Enabled        = false;
            Action8->Enabled        = false;
      }else if (mode == imMod){
		ModePanel->Caption = "�C��";
		ModePanel->Color = TColor(MOD_CLR);
            StartDatePicker->Color   = clSilver;
            StartDatePicker->Enabled = false;
            Action7->Enabled        = true;
            Action8->Enabled        = true;
      }
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::ClearForm()
{
      StartDatePicker->Date   = Date();
      TaxRateEdit->Text       = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::BrowseRecord()
{
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT * FROM M_����� WHERE �J�n���t = " + IntToStr(date_);
      if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            ClearForm();
            date_ = 0;
            return;
      }

      date_ = ToInt(set[0]["�J�n���t"]);
      StartDatePicker->Date   = IntToDate(ToInt(set[0]["�J�n���t"]));
      TaxRateEdit->Text       = ToInt(set[0]["����ŗ�"]);
}
//---------------------------------------------------------------------------
bool __fastcall TTaxEditForm::PostRecord()
{
      NsFieldSet fields;

      fields << NsField("[�J�n���t]", DateToInt(StartDatePicker->Date))
             << NsField("[����ŗ�]", TaxRateEdit->Text.ToIntDef(0));

      try{
            if (date_ == 0){
                  DM->DBI.Insert("M_�����", fields);
            }else{
                  DM->DBI.Update("M_�����", "�J�n���t", date_, fields);
            }
      }catch (Exception &e){
            Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
            return false;
      }

      is_edit_ = true;

      return true;
}
//---------------------------------------------------------------------------
bool __fastcall TTaxEditForm::CheckEdit()
{
      if (StrToCurrDef(TaxRateEdit->Text, 0) > 100){
            Application->MessageBox("�ŗ��������ł�\r\n0�`100�̊ԂŐݒ肵�Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            TaxRateEdit->SetFocus();
            return false;
      }

      return true;
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::DatePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TTaxEditForm::DatePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

