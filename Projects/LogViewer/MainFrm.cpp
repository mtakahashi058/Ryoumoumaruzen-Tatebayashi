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
	Application->OnMessage = this->MessageProc;
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
	ErrorLevelCombo->ItemIndex = 0;

	SetRange();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetRange()
{
	DM->Q_Log->Close();
	DM->Q_Log->Parameters->ParamByName("DT_FROM")->Value = DateToStr(DatePickerFrom->Date) + " 00:00";
	DM->Q_Log->Parameters->ParamByName("DT_TO")->Value   = DateToStr(DatePickerTo->Date + 1) + " 00:00";
	if (ErrorLevelCombo->ItemIndex == 0)
		DM->Q_Log->SQL->Strings[24] = AnsiString();
	else
		DM->Q_Log->SQL->Strings[24] = "AND	�G���[���x�� = " + IntToStr(ErrorLevelCombo->ItemIndex - 1);
	DM->Q_Log->Open();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DatePickerFromChange(TObject *Sender)
{
	//SetRange();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriorButtonClick(TObject *Sender)
{
	ShiftDate(DatePickerFrom, DatePickerTo, -1);
	//SetRange();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(DatePickerFrom, DatePickerTo, 1);
	//SetRange();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OutputButtonClick(TObject *Sender)
{
	std::auto_ptr<TStringList> Records(new TStringList());
	Table2Str(DM->Q_Log, Records.get(), false);
	SaveDialog->FileName = "���O�f�[�^_" + DatePickerFrom->Date.FormatString("yyyymmdd") + "_" + DatePickerTo->Date.FormatString("yyyymmdd") + ".csv";
	if (SaveDialog->Execute())
		Records->SaveToFile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	int kaisu = 3;

	switch (Msg.message){
		case WM_MOUSEWHEEL:
		if (Msg.hwnd == DBGrid->Handle){
			//�z�C�[���}�E�X�̃C�x���g�ŏ㉺�ɓ����悤�ɐݒ�
			if (!DBGrid->DataSource->DataSet->Active)
				return;
			if ((short)HIWORD(Msg.wParam) > 0){
				for (int i = 0; i < kaisu; i++)
					DBGrid->DataSource->DataSet->Prior();
			}else{
				for (int i = 0; i < kaisu; i++)
					DBGrid->DataSource->DataSet->Next();
			}
			//�����͂����ŃX�g�b�v������
			Handled = true;
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateButtonClick(TObject *Sender)
{
    SetRange();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteLogButtonClick(TObject *Sender)
{
	if (!DM->Q_Log->Active)
    	return;
	if (Application->MessageBox("�\������Ă��郍�O���폜���܂����H", "���O�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
    	return;

	AnsiString sql = "DELETE FROM D_���O WHERE ���� BETWEEN ";

    if (DatePickerFrom->Checked)
		sql = sql + "'" + DateToStr(DatePickerFrom->Date) + " 00:00' AND ";
    else
		sql = sql + "'1900/01/01 00:00' AND ";

    if (DatePickerTo->Checked)
		sql = sql + "'" + DateToStr(DatePickerTo->Date + 1) + " 00:00' ";
    else
		sql = sql + "'2200/01/01 00:00' ";

	if (ErrorLevelCombo->ItemIndex != 0)
		sql = sql + "AND �G���[���x�� = " + IntToStr(ErrorLevelCombo->ItemIndex - 1);

	int cnt = DM->DBI.Execute(sql);

    SetRange();

    Application->MessageBox(("���O���폜���܂��� (����:" + FormatFloat("#,##0", cnt) + "��)").c_str(), "���O�폜", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

