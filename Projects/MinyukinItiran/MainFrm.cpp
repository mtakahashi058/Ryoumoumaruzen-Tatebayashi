//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
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
	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Connected = false;

	try{
		DM->ADOConnection->Connected = true;
	}catch (Exception& e){
		Application->MessageBox(("�f�[�^�x�[�X�ւ̐ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

	MainForm->Resize();
	MonthPicker->Date    = GetFirstDate(Date());
	DateFromPicker->Date = GetFirstDate(Date());
	DateToPicker->Date   = GetLastDate(Date());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MonthPickerChange(TObject *Sender)
{
	DateFromPicker->Date = GetFirstDate(MonthPicker->Date);
	DateToPicker->Date   = GetLastDate(MonthPicker->Date);
}
//---------------------------------------------------------------------------
// �O�͈�
void __fastcall TMainForm::PrevButtonClick(TObject *Sender)
{
	MonthPicker->Date = IncMonth(MonthPicker->Date, -1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// ��͈�
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	MonthPicker->Date = IncMonth(MonthPicker->Date, 1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// MainForm->Resize
void __fastcall TMainForm::FormResize(TObject *Sender)
{
	int interval = 10;
	btnF1->Width = int((MainForm->Width - interval * 4) / 12);
	btnF2->Width = int((MainForm->Width - interval * 4) / 12);
	btnF3->Width = int((MainForm->Width - interval * 4) / 12);
	btnF4->Width = int((MainForm->Width - interval * 4) / 12);
	btnF5->Width = int((MainForm->Width - interval * 4) / 12);
	btnF6->Width = int((MainForm->Width - interval * 4) / 12);
	btnF7->Width = int((MainForm->Width - interval * 4) / 12);
	btnF8->Width = int((MainForm->Width - interval * 4) / 12);
	btnF9->Width = int((MainForm->Width - interval * 4) / 12);
	btnF10->Width = int((MainForm->Width - interval * 4) / 12);
	btnF11->Width = int((MainForm->Width - interval * 4) / 12);
	btnF12->Width = int((MainForm->Width - interval * 4) / 12);

	btnF1->Left = interval;
	btnF2->Left = btnF1->Left + btnF1->Width - 1;
	btnF3->Left = btnF2->Left + btnF2->Width - 1;
	btnF4->Left = btnF3->Left + btnF3->Width - 1;
	btnF5->Left = btnF4->Left + btnF4->Width - 1 + interval;
	btnF6->Left = btnF5->Left + btnF5->Width - 1;
	btnF7->Left = btnF6->Left + btnF6->Width - 1;
	btnF8->Left = btnF7->Left + btnF7->Width - 1;
	btnF9->Left = btnF8->Left + btnF8->Width - 1 + interval;
	btnF10->Left = btnF9->Left + btnF9->Width - 1;
	btnF11->Left = btnF10->Left + btnF10->Width - 1;
	btnF12->Left = btnF11->Left + btnF11->Width - 1;
}
//---------------------------------------------------------------------------
// F9 ���
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (Application->MessageBox("������܂����H", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	if (!SetRange())
		return;
	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
// F10 �v���r���[
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (!SetRange())
		return;
	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetNyukinQuery(int date, int id)
{
	return
		" SELECT"
		" 	������ID,"
		" 	SUM(����) + SUM(�U��) + SUM(�萔��) + SUM(���؎�) + SUM(��`) + SUM(���E) + SUM(�l����) + SUM(����) + SUM(���̑�) AS �����z"
		" FROM"
		" 	D_����"
		" WHERE"
		" 	������ > " + IntToStr(date) +
		" AND"
		" 	������ID = " + IntToStr(id) +
		" GROUP BY"
		" 	������ID";
}
//---------------------------------------------------------------------------
// �N�G���͈̔͐ݒ�
bool __fastcall TMainForm::SetRange()
{
	NsRecordSet set, nyukin_set;
	try{
		QRForm->Query->Close();

		// �ꎞ�e�[�u�������݂���ꍇDROP����
		set.clear();
		DM->DBI.GetRecordSet("SELECT CASE WHEN object_id('tempdb..#MINYULIST', 'U') IS NOT NULL THEN 1 ELSE 0 END AS FLAG", set);
		if (ToBit(set[0]["FLAG"]))
			DM->DBI.Execute("DROP TABLE #MINYULIST");

		// ���z�v�Z���ځu�����z�v�u�s���z�v���܂ވꎞ�e�[�u�����쐬
		AnsiString sql =
			" DECLARE @DATE_FROM AS [DECIMAL]"
			" DECLARE @DATE_TO   AS [DECIMAL]"
			" SET @DATE_FROM = " + DateFromPicker->Date.FormatString("yyyymmdd") +
			" SET @DATE_TO   = " + DateToPicker->Date.FormatString("yyyymmdd") +
			" "
			" SELECT"
			" 	����ID,"
			" 	������ID, ������R�[�h, �����於��,"
			" 	���ؓ�,"
			" 	�����\���,"
			" 	���񐿋��z,"
			" 	CAST(NULL AS DECIMAL) AS �����z,"
			" 	CAST(NULL AS DECIMAL) AS �s���z"
			" INTO	#MINYULIST"
			" FROM"
			" 	("
			" 	SELECT"
			" 		����ID,"
			" 		������ID, ���Ӑ�R�[�h AS ������R�[�h, ���Ӑ於�� AS �����於��,"
			" 		���ؓ�, �����\���, ���񐿋��z"
			" 	FROM"
			" 		V_����"
			" 	WHERE"
			" 		�����\��� BETWEEN @DATE_FROM AND @DATE_TO"
			" 	) AS  X";

		// �ꎞ�e�[�u���쐬
		DM->DBI.Execute(sql);

		set.clear();
		if (!DM->DBI.GetRecordSet("SELECT * FROM #MINYULIST", set)){
			Application->MessageBox("�Y���͈̖͂������f�[�^������܂���",
				this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}

		// ���z�v�Z���ڂ�⊮
		for (unsigned int i = 0; i < set.size(); i++){
			nyukin_set.clear();
			if (!DM->DBI.GetRecordSet(GetNyukinQuery(ToInt(set[i]["���ؓ�"]), ToInt(set[i]["������ID"])), nyukin_set)){
				sql = "UPDATE #MINYULIST SET �����z = 0, �s���z = " + CurrToStr(ToCurrency(set[i]["���񐿋��z"])) +
					  " WHERE ����ID = " + IntToStr(ToInt(set[i]["����ID"]));
			}else{
				sql = "UPDATE #MINYULIST SET �����z = " + CurrToStr(ToCurrency(nyukin_set[0]["�����z"])) +
					  ", �s���z = " + CurrToStr(ToCurrency(set[i]["���񐿋��z"]) - ToCurrency(nyukin_set[0]["�����z"])) +
					  " WHERE ����ID = " + IntToStr(ToInt(set[i]["����ID"]));
			}
			DM->DBI.Execute(sql);
		}

		QRForm->Query->Open();

	}catch (Exception &e){
		Application->MessageBox(("�������f�[�^�̏W�v�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("�f�[�^������܂���", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	// �o�͔͈�
	QRForm->RangeLabel->Caption = DateFromPicker->Date.FormatString("yyyy'�N'mm'����'");

	return true;
}
//---------------------------------------------------------------------------
// F12 �I��
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

