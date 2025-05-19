//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
#include "SearchFrm.h"
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
	seikyu_id_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	try{
		DM->ADOConnection->Connected = true;
	}catch (Exception& e){
		Application->MessageBox(("�f�[�^�x�[�X�ւ̐ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

	SeikyusakiCodeEditF->Text = AnsiString();
	SeikyusakiCodeEditT->Text = AnsiString();

	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;

	MainForm->Resize();
	MonthPicker->Date = Date();
	MonthPicker->OnChange(NULL);
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
	MonthPicker->Date = IncMonth(GetFirstDate(MonthPicker->Date), -1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// ��͈�
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	MonthPicker->Date = IncMonth(GetFirstDate(MonthPicker->Date), 1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// F9 ���
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (Application->MessageBox("������܂����H", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	if (!CheckEdit())
		return;
	if (!SetRange())
		return;
	if (CreateDataComboBox->ItemIndex == 0)
		PostUrikake();

	QRForm->Query->Filter = "�O���c�� <> 0 OR ���������z <> 0 OR ��������z <> 0";
	QRForm->Query->Filtered = true;

	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
// F10 �v���r���[
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;
	if (!SetRange())
		return;
	if (CreateDataComboBox->ItemIndex == 0)
		PostUrikake();

	QRForm->Query->Filter = "�O���c�� <> 0 OR ���������z <> 0 OR ��������z <> 0";
	QRForm->Query->Filtered = true;

	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
// �o�͑O�`�F�b�N����
bool __fastcall TMainForm::CheckEdit()
{
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT COUNT(*) AS ���� FROM D_���� WHERE ���ؓ� = " + IntToStr(DateToInt(GetLastDate(MonthPicker->Date))), set);
	if (ToInt(set[0]["����"]) == 0){
		if (Application->MessageBox("�����߁i������99�j�̐����������s���Ă��܂���\r\n�����������s�킸�ɔ��㌳���𔭍s����Ɩ����߂̏���ł����f����܂���\r\n�����𑱍s���܂����H", "�����`�F�b�N", MB_YESNO | MB_ICONEXCLAMATION | MB_DEFBUTTON2) != IDYES)
			return false;
	} 

	return true;
}
//---------------------------------------------------------------------------
// �N�G���͈̔͐ݒ�
bool __fastcall TMainForm::SetRange()
{
	QRForm->Query->Close();
	QRForm->Query->Parameters->ParamByName("DATE_BEF")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -1)));
	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value  = DateToInt(DateFromPicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value    = DateToInt(DateToPicker->Date);
	QRForm->Query->Parameters->ParamByName("ZEIRITU")->Value    = DM->GetShohizeiritu(DateToInt(DateToPicker->Date));

	if (!AllCheckBox->Checked){
		QRForm->Query->Parameters->ParamByName("SEIKYU_FROM")->Value = SeikyusakiCodeEditF->Text.ToIntDef(0);
		QRForm->Query->Parameters->ParamByName("SEIKYU_TO")->Value   = SeikyusakiCodeEditT->Text.ToIntDef(0);
	}else{
		QRForm->Query->Parameters->ParamByName("SEIKYU_FROM")->Value = 0;
		QRForm->Query->Parameters->ParamByName("SEIKYU_TO")->Value   = 99999;
	}

	QRForm->Query->Filtered = false;
	QRForm->Query->Open();

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("�f�[�^������܂���", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	// �o�͔͈�
	QRForm->NendoLabel->Caption = DateFromPicker->Date.FormatString("yyyy'�N'mm'���x'");

	// ���������N���A
	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;

	return true;
}
//---------------------------------------------------------------------------
// ���|�f�[�^��o�^
bool __fastcall TMainForm::PostUrikake()
{
	try{
		DM->ADOConnection->BeginTrans();

		int sime = DateToInt(GetLastDate(MonthPicker->Date));	// ���ؓ�

		int seikyu_from = SeikyusakiCodeEditF->Text.ToIntDef(0);
		int seikyu_to   = SeikyusakiCodeEditT->Text.ToIntDef(0);

		std::auto_ptr<TStringList> seikyu_id_list(new TStringList());

		NsRecordSet set;
		DM->DBI.GetRecordSet("SELECT ���Ӑ�ID FROM M_���Ӑ� WHERE ���Ӑ�ID = ���Ӑ�ID AND ���Ӑ�R�[�h BETWEEN " + IntToStr(seikyu_from) + " AND " + IntToStr(seikyu_to), set);
		for (unsigned int i = 0; i < set.size(); i++)
			seikyu_id_list->Add(ToString(set[i]["���Ӑ�ID"]));

		// ���|�f�[�^�폜
		AnsiString sql = "DELETE FROM D_���| WHERE ���ؓ� = " + IntToStr(sime);
		if (!AllCheckBox->Checked && seikyu_id_list->Count != 0)
			sql += " AND ������ID IN ( " + seikyu_id_list->CommaText + ") ";
		DM->DBI.Execute(sql);

		seikyu_id_ = 0;
		int count = 0;

		// ���|�f�[�^�쐬
		NsFieldSet fields;
		while (!QRForm->Query->Eof){
			if (seikyu_id_ == QRForm->Query->FieldByName("������ID")->AsInteger){
				QRForm->Query->Next();
				continue;
			}
			seikyu_id_ = QRForm->Query->FieldByName("������ID")->AsInteger;

			fields.clear();
			fields	<< NsField("���ؓ�", sime)
				<< NsField("������ID", seikyu_id_)
				<< NsField("�J�n���t", DateToInt(GetFirstDate(MonthPicker->Date)))
				<< NsField("�I�����t", sime)
				<< NsField("�O���c��",   QRForm->Query->FieldByName("�O���c��")->AsCurrency)
				<< NsField("���������z", QRForm->Query->FieldByName("���������z")->AsCurrency)
				<< NsField("���������z", QRForm->Query->FieldByName("���������z")->AsCurrency)
				<< NsField("�����J�z�z", QRForm->Query->FieldByName("�����J�z�z")->AsCurrency)
				<< NsField("��������z", QRForm->Query->FieldByName("��������z")->AsCurrency)
				<< NsField("��������Ŋz", QRForm->Query->FieldByName("��������Ŋz")->AsCurrency)
				<< NsField("�����c��", QRForm->Query->FieldByName("�����J�z�z")->AsCurrency + QRForm->Query->FieldByName("��������z")->AsCurrency + QRForm->Query->FieldByName("��������Ŋz")->AsCurrency)
				<< NsField("�X�V����", Now())
				<< NsField("�쐬����", Now());
			DM->DBI.Insert("D_���|", fields);

			count++;
			QRForm->Query->Next();
		}

		ShoriKensuLabel->Caption = "�������� �F " + FormatFloat("#,##0", count) + "��";
		SeikyuConfButton->Visible = true;
		Application->ProcessMessages();

		DM->ADOConnection->CommitTrans();

	}catch (Exception& e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("�����f�[�^�̓o�^�Ɏ��s���܂���\r\n" + e.Message).c_str(), "�����f�[�^�o�^", MB_OK | MB_ICONSTOP);
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
// F12 �I��
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiCodeEditFChange(TObject *Sender)
{
	SeikyusakiNameEditF->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEditF->Text.ToIntDef(0), "���Ӑ於��", "���Ӑ�ID = ������ID"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiCodeEditTChange(TObject *Sender)
{
	SeikyusakiNameEditT->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEditT->Text.ToIntDef(0), "���Ӑ於��", "���Ӑ�ID = ������ID"));
}
//---------------------------------------------------------------------------
// ���Ӑ挟���{�^��
void __fastcall TMainForm::SeikyusakiSearchButtonFClick(TObject *Sender)
{
	SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1";
	SearchForm->orderby_sql = "ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditF->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsString;
	SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiSearchButtonTClick(TObject *Sender)
{
	SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1";
	SearchForm->orderby_sql = "ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditT->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsString;
	SeikyusakiCodeEditT->SetFocus();
}
//---------------------------------------------------------------------------
// �����f�[�^�쐬�敪
void __fastcall TMainForm::CreateDataComboBoxKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_NUMPAD1)
		CreateDataComboBox->ItemIndex = 0;
	else if (Key == VK_NUMPAD2)
		CreateDataComboBox->ItemIndex = 1;
}
//---------------------------------------------------------------------------
// ���|�f�[�^�m�F�{�^��
void __fastcall TMainForm::SeikyuConfButtonClick(TObject *Sender)
{
	// ���|�ꗗ�ďo
	AnsiString path = ExtractFilePath(Application->Name) + "UrikakeDataMaintenance.exe " + IntToStr(DateToInt(GetLastDate(MonthPicker->Date)));

	if (!CreateProcess(path, true)){
		Application->MessageBox("���|�f�[�^�����e�i���X���N���ł��܂���ł���",
						"�����f�[�^�m�F", MB_OK | MB_ICONSTOP);
	}
}
//---------------------------------------------------------------------------
//exe�t�@�C���ďo�ɕK�v�ȏ���
bool __fastcall TMainForm::CreateProcess(AnsiString exename, bool wait)
{
	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;
	if (!::CreateProcess(NULL, exename.c_str(), NULL, NULL, false,
			CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS,
			NULL, NULL, &stStartupInfo, &stProcessInfo))
		return false;
	if (wait)
		WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	return true;
}
//---------------------------------------------------------------------------
// �o�͔͈͂��ׂ�
void __fastcall TMainForm::AllCheckBoxClick(TObject *Sender)
{
	SiteiLabel->Font->Color = AllCheckBox->Checked ? clGray : clWindowText;
	SeikyusakiCodeEditF->Enabled = !AllCheckBox->Checked;
	SeikyusakiNameEditF->Enabled = !AllCheckBox->Checked;
	SeikyusakiSearchButtonF->Enabled = !AllCheckBox->Checked;
	SeikyusakiCodeEditT->Enabled = !AllCheckBox->Checked;
	SeikyusakiNameEditT->Enabled = !AllCheckBox->Checked;
	SeikyusakiSearchButtonT->Enabled = !AllCheckBox->Checked;
	if (!AllCheckBox->Checked)
		SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------

