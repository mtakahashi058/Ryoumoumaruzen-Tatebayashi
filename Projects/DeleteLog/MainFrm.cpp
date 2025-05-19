//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	try{
		DM->ADOConnection->Connected = true;
	}catch (Exception& e){
		Application->MessageBox(("�f�[�^�x�[�X�ւ̐ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(), "�ڑ��G���[", MB_OK | MB_ICONSTOP);
		Close();
	}

	DatePickerFrom->Date = Date();
	DatePickerTo->Date   = Date();
    FromCheckBox->Checked = true;
    ToCheckBox->Checked = true;
    FromCheckBox->OnClick(NULL);
    ToCheckBox->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteLogButtonClick(TObject *Sender)
{
	AnsiString mess = "���t�͈�( ";

    if (FromCheckBox->Checked)
    	mess = mess + DateToStr(DatePickerFrom->Date);
	mess = mess + " �` ";
    if (ToCheckBox->Checked)
    	mess = mess + DateToStr(DatePickerTo->Date);
	mess = mess + " ) �̃��O���폜���܂����H";

	if (Application->MessageBox(mess.c_str(), "���O�폜", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
    	return;

	AnsiString sql = "DELETE FROM D_���O WHERE ���� BETWEEN ";

    if (FromCheckBox->Checked)
		sql = sql + "'" + DateToStr(DatePickerFrom->Date) + " 00:00' AND ";
    else
		sql = sql + "'1900/01/01 00:00' AND ";

    if (ToCheckBox->Checked)
		sql = sql + "'" + DateToStr(DatePickerTo->Date + 1) + " 00:00' ";
    else
		sql = sql + "'2200/01/01 00:00' ";

	int cnt = DM->DBI.Execute(sql);

    Application->MessageBox(("���O���폜���܂��� (����:" + FormatFloat("#,##0", cnt) + "��)").c_str(), "���O�폜", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FromCheckBoxClick(TObject *Sender)
{
	DatePickerFrom->Color = FromCheckBox->Checked ? TColor(0x0080FFFF) : clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToCheckBoxClick(TObject *Sender)
{
	DatePickerTo->Color = ToCheckBox->Checked ? TColor(0x0080FFFF) : clWhite;
}
//---------------------------------------------------------------------------

