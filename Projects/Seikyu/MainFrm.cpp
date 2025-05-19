//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SeikyushoFrm.h"
#include "MainFrm.h"
#include "SearchFrm.h"
#include "SettingsFrm.h"
#include "ConfirmFrm.h"
#include <memory>
#include <vcl\Clipbrd.hpp>
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
	try{
		DM->ADOConnection->Connected = true;

	}catch (Exception& e){
		Application->MessageBox(("�f�[�^�x�[�X�ւ̐ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

	MainForm->Resize();

	DM->config_.Load(&DM->DBI);

	// �����Z�b�g
	SimeComboBox->Items->Clear();
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT ���� FROM V_���Ӑ� WHERE ���� IS NOT NULL GROUP BY ���� ORDER BY ����", set);
	for (int i = 0; i < (int)set.size(); i++)
		SimeComboBox->Items->Append(set[i]["����"]);

	DateFromPicker->Date = GetFirstDate(Date());
	DateToPicker->Date   = GetLastDate(Date());

	SeikyusakiCodeEditF->Text = AnsiString();
	SeikyusakiCodeEditT->Text = AnsiString();
	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;

	// �ݒ�K�p
	SettingsForm->SetSeikyusho();

	// �v�����^�w��
	//DM->SetPrinter(SeikyushoForm->QuickRep, DM->ini_["Printer::SeikyuPrinter"]);
}
//---------------------------------------------------------------------------
// ���t
void __fastcall TMainForm::SetDate()
{
	SimekiriEdit->Text = SimekiriDatePicker->Date.FormatString("yyyy/mm/dd");
	DateFromEdit->Text = DateFromPicker->Date.FormatString("yyyy/mm/dd");
	DateToEdit->Text   = DateToPicker->Date.FormatString("yyyy/mm/dd");
}
//---------------------------------------------------------------------------
// ����->OnChange
void __fastcall TMainForm::SimeComboBoxChange(TObject *Sender)
{
	int day = SimeComboBox->Items->Strings[SimeComboBox->ItemIndex].ToIntDef(0);
	DateFromPicker->Date = DM->GetDateFrom(day);
	DateToPicker->Date   = DM->GetDateTo(day);
	SimekiriDatePicker->Date = DateToPicker->Date;
	SetDate();

	// �ŏI���ؓ�
	NsRecordSet set;
	AnsiString sql = "SELECT TOP 2 ���ؓ� FROM V_���� WHERE ���� = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] + " GROUP BY ���ؓ� ORDER BY ���ؓ� DESC";
	DM->DBI.GetRecordSet(sql, set);

	LastSimeLabel->Caption       = "�O����ؓ�   �F ----/--/--";
	BeforeLastSimeLabel->Caption = "�O�X����ؓ� �F ----/--/--";

	try{
		LastSimeLabel->Caption       = "�O����ؓ�   �F " + IntToDate(ToInt(set[0]["���ؓ�"])).FormatString("yyyy/mm/dd");
		BeforeLastSimeLabel->Caption = "�O�X����ؓ� �F " + IntToDate(ToInt(set[1]["���ؓ�"])).FormatString("yyyy/mm/dd");
	}catch (...){
	}

	// ���Ӑ挏��
	sql = "SELECT COUNT(*) AS ���� FROM M_���Ӑ� WHERE ���� = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] + " AND ���Ӑ�ID = ������ID";
	if (DM->DBI.GetRecordSet(sql, set))
		TokuKensuLabel->Caption = "���Ӑ挏�� �F " + FormatFloat("#,##0", ToInt(set[0]["����"])) + " ��";
	else
		TokuKensuLabel->Caption = "���Ӑ挏�� �F   ��";

	TokuKensuLabel->Hint = AnsiString();
	sql = "SELECT ���Ӑ�R�[�h, ���Ӑ於�� FROM M_���Ӑ� WHERE ���� = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] +  + " AND ���Ӑ�ID = ������ID ORDER BY ���Ӑ�R�[�h";
	if (DM->DBI.GetRecordSet(sql, set)){
		for (unsigned int i = 0; i < set.size(); i++)
			TokuKensuLabel->Hint += FormatFloat("00000", ToInt(set[i]["���Ӑ�R�[�h"])) + " : " + ToString(set[0]["���Ӑ於��"]) + "\r\n";
	}
}
//---------------------------------------------------------------------------
// �O�͈�
void __fastcall TMainForm::PrevButtonClick(TObject *Sender)
{
	ShiftDate(DateFromPicker, DateToPicker, -1);
	SimekiriDatePicker->Date = DateToPicker->Date;
	SetDate();
}
//---------------------------------------------------------------------------
// ��͈�
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(DateFromPicker, DateToPicker, 1);
	SimekiriDatePicker->Date = DateToPicker->Date;
	SetDate();
}
//---------------------------------------------------------------------------
// F4 �Q��
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == SeikyusakiCodeEditF)
		SeikyusakiSearchButtonF->OnClick(NULL);
	else if (ActiveControl == SeikyusakiCodeEditT)
		SeikyusakiSearchButtonT->OnClick(NULL);
}
//---------------------------------------------------------------------------
// F9 ��� / F10 �v���r���[
void __fastcall TMainForm::btnF9Click(TObject *Sender)
{
	if (!InputCheck())
		return;

	DM->zeiritu = GetShohizeiritu(DateToInt(DateToPicker->Date));
		
	// �����������e�m�F�t�H�[��
	int seikyu = CreateSeikyuComboBox->ItemIndex == 0 ? 1 : 0;
	int hikae  = HikaeComboBox->ItemIndex        == 0 ? 1 : 0;
	int print  = Sender == btnF9                      ? 1 : 0;
	SetSimeCheckRange();
	if (ConfirmForm->ShowModalWith(seikyu, hikae, print) != mrOk)
		return;
	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;
	if (CreateSeikyuComboBox->ItemIndex == 0){
		// �����f�[�^���쐬����
		if (!SetRange(true))
			return;
		if (!CreateSeikyuData())
			return;
	}
	if (!SetRange(false))
		return;
	if (print)
		SettingsForm->report->Print();
	else
		SettingsForm->report->Preview();
}
//---------------------------------------------------------------------------
// ���ؓ��`�F�b�N�p�N�G���͈͐ݒ�
void __fastcall TMainForm::SetSimeCheckRange()
{
	DM->Q_SimeCheck->Close();
	DM->Q_SimeCheck->Parameters->ParamByName("LAST_SIME")->Value = DateToInt(DateFromPicker->Date - 1);
	DM->Q_SimeCheck->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(DateFromPicker->Date);
	DM->Q_SimeCheck->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(DateToPicker->Date);
	DM->Q_SimeCheck->Parameters->ParamByName("SIME")->Value      = SimeComboBox->Items->Strings[SimeComboBox->ItemIndex].ToIntDef(0);
	DM->Q_SimeCheck->Open();
}
//---------------------------------------------------------------------------
// �N�G���͈̔͐ݒ�
bool __fastcall TMainForm::SetRange(bool create_data)
{
	try{
		JunbiPanel->Left = 300;
		JunbiPanel->Top  = 212;
		JunbiPanel->Visible = true;
		Application->ProcessMessages();

		DM->Q_Seikyu->Close();
		DM->Q_Seikyu->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(DateFromPicker->Date);
		DM->Q_Seikyu->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(DateToPicker->Date);
		DM->Q_Seikyu->Parameters->ParamByName("SIME")->Value      = SimeComboBox->Items->Strings[SimeComboBox->ItemIndex].ToIntDef(0);
		DM->Q_Seikyu->Parameters->ParamByName("TAX_RATE")->Value  = DM->zeiritu;

		// �w�萿����̂�
		if (!AllCheckBox->Checked && SeikyusakiCodeEditF->Text.ToIntDef(0) != 0 && SeikyusakiCodeEditT->Text.ToIntDef(0) != 0){
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_FROM")->Value = SeikyusakiCodeEditF->Text.ToIntDef(0);
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_TO")->Value   = SeikyusakiCodeEditT->Text.ToIntDef(0);
		}else{
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_FROM")->Value = 0;
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_TO")->Value   = 99999;
		}

		if (create_data){
			// �f�[�^�쐬�p
			DM->Q_Seikyu->SQL->Strings[266] = "	(ISNULL(C.���񔄏�z, 0) > 0 OR ISNULL(A.�O�񐿋��z, 0) <> 0 OR ISNULL(B.��������z, 0) <> 0 OR ISNULL(B.���񒲐��z, 0) <> 0)";
			DM->Q_Seikyu->SQL->Strings[267] = AnsiString();
		}else{
			// ���������s�p
			DM->Q_Seikyu->SQL->Strings[266] = AnsiString();
			DM->Q_Seikyu->SQL->Strings[267] = "	ISNULL(A.�O�񐿋��z, 0) - (ISNULL(B.��������z, 0) + ISNULL(B.���񒲐��z, 0)) + ISNULL(C.���񔄏�z, 0) + ISNULL(C.�������Ŋz, 0) <> 0";
		}

		RichEdit1->Lines->Text = DM->Q_Seikyu->SQL->Text;

		DM->Q_Seikyu->Open();

		if (DM->Q_Seikyu->RecordCount == 0){
			Application->MessageBox("�ΏۂƂȂ�f�[�^������܂���", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
			return false;
		}

		if (!create_data){
			// �������^�C�g���ύX
			if (HikaeComboBox->ItemIndex == 1)
				SettingsForm->title_label->Caption = "�� �� �� (�T)";
			else
				SettingsForm->title_label->Caption = "���@���@��";

			// �o�͓������ؓ�
			SettingsForm->date_label->Caption = FormatFloat("0000�N00��00��", DateToInt(DateToPicker->Date));
		}
	}__finally{
		JunbiPanel->Visible = false;
	}

	return true;
}
//---------------------------------------------------------------------------
// ���̓`�F�b�N
bool __fastcall TMainForm::InputCheck()
{
	if (SimeComboBox->ItemIndex == -1){
		Application->MessageBox("������I�����Ă�������", "���̓`�F�b�N", MB_OK | MB_ICONEXCLAMATION);
		SimeComboBox->SetFocus();
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
// �����f�[�^�̍쐬
bool __fastcall TMainForm::CreateSeikyuData()
{
	if (CreateSeikyuComboBox->ItemIndex != 0)
		return true;

	try{
		CreatePanel->Left = 300;
		CreatePanel->Top  = 212;
		KensuLabel->Caption = "  ��";
		ShoriKensuLabel->Caption = AnsiString();
		SeikyuConfButton->Visible = false;
		CreatePanel->Visible = true;
		Application->ProcessMessages();

		AnsiString toku_code_f = IntToStr(SeikyusakiCodeEditF->Text.ToIntDef(0));
		AnsiString toku_code_t = IntToStr(SeikyusakiCodeEditT->Text.ToIntDef(0));

		try{
			DM->ADOConnection->BeginTrans();

			NsFieldSet keys, fields;

			// ���������f�[�^�̍폜
			AnsiString sql = "DELETE FROM D_���� WHERE ���ؓ� = " + DateToPicker->Date.FormatString("yyyymmdd") + " AND EXISTS (SELECT * FROM M_���Ӑ� WHERE ���� = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] + " AND ������ID = ���Ӑ�ID)";
			if (!AllCheckBox->Checked)      // ������w��̏ꍇ
				sql += " AND ������ID IN ( SELECT ������ID FROM M_���Ӑ� WHERE ���Ӑ�R�[�h BETWEEN " + toku_code_f + " AND " + toku_code_t + ")";

			DM->DBI.Execute(sql);

			// �����f�[�^�쐬
			bool is_exist;

			int seikyu_bef = 0;
			create_cnt = 0;

			while (!DM->Q_Seikyu->Eof){
				if (DM->Q_Seikyu->FieldByName("������ID")->AsInteger == seikyu_bef){
					DM->Q_Seikyu->Next();
					continue;
				}
				seikyu_bef = DM->Q_Seikyu->FieldByName("������ID")->AsInteger;

				keys.clear();
				keys << NsField("���ؓ�",   DM->Q_Seikyu->FieldByName("���ؓ�")->AsInteger);
				keys << NsField("������ID", DM->Q_Seikyu->FieldByName("������ID")->AsInteger);
				if (DM->DBI.IsExist("D_����", keys))
					is_exist = true;
				else
					is_exist = false;

				fields.clear();
				if (!is_exist){
					fields << NsField("[���ؓ�]",   DM->Q_Seikyu->FieldByName("���ؓ�")->AsInteger);
					fields << NsField("[������ID]", DM->Q_Seikyu->FieldByName("������ID")->AsInteger);
				}
				fields << NsField("[�J�n���t]",     DM->Q_Seikyu->FieldByName("�J�n���t")->AsInteger);
				fields << NsField("[�I�����t]",     DM->Q_Seikyu->FieldByName("�I�����t")->AsInteger);
				fields << NsField("[�O�񐿋��z]",   DM->Q_Seikyu->FieldByName("�O�񐿋��z")->AsInteger);
				fields << NsField("[��������z]",   DM->Q_Seikyu->FieldByName("��������z")->AsInteger);
				fields << NsField("[���񒲐��z]",       DM->Q_Seikyu->FieldByName("���񒲐��z")->AsInteger);
				fields << NsField("[����J�z�z]",       DM->Q_Seikyu->FieldByName("����J�z�z")->AsInteger);
				fields << NsField("[���񔄏�z]",   DM->Q_Seikyu->FieldByName("���񔄏�z")->AsInteger);
				fields << NsField("[�������Ŋz]", DM->Q_Seikyu->FieldByName("�������Ŋz")->AsInteger);
				fields << NsField("[���񐿋��z]",   DM->Q_Seikyu->FieldByName("���񐿋��z")->AsInteger);
				fields << NsField("[�����\���]",   DateToInt(DM->GetNyukinYotei(DateToPicker->Date, DM->Q_Seikyu->FieldByName("�����T�C�g")->AsInteger, DM->Q_Seikyu->FieldByName("������")->AsInteger)));
				fields << NsField("[�X�V����]",     Now());
				if (!is_exist)
					fields << NsField("[�쐬����]", Now());

				if (is_exist)
					DM->DBI.Update("D_����", keys, fields);
				else
					DM->DBI.Insert("D_����", fields);

				KensuLabel->Caption = FormatFloat("#,##0", create_cnt++) + " ��";
				Application->ProcessMessages();
				DM->Q_Seikyu->Next();
			}
			ShoriKensuLabel->Caption = "�������� �F " + KensuLabel->Caption;
			SeikyuConfButton->Visible = true;

			DM->ADOConnection->CommitTrans();

		}catch (Exception& e){
			DM->ADOConnection->RollbackTrans();
			Application->MessageBox(("�����f�[�^�̓o�^�Ɏ��s���܂���\r\n" + e.Message).c_str(), "�����f�[�^�o�^", MB_OK | MB_ICONSTOP);
			return false;
		}
	}__finally{
		CreatePanel->Visible = false;
	}

	return true;
}
//---------------------------------------------------------------------------
// F11 ���x����
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (!InputCheck())
		return;
	if (!SetRange(false))
		return;

	// ���x���󎚌ďo
	AnsiString path = ExtractFilePath(Application->Name) + "PrintLabel.exe ";

	std::auto_ptr<TStringList> code_list(new TStringList());
	int code = 0;
	while (!DM->Q_Seikyu->Eof){
		if (code == DM->Q_Seikyu->FieldByName("������R�[�h")->AsInteger){
			DM->Q_Seikyu->Next();
			continue;
		}
		code = DM->Q_Seikyu->FieldByName("������R�[�h")->AsInteger;
		code_list->Add(DM->Q_Seikyu->FieldByName("������R�[�h")->AsString);
		DM->Q_Seikyu->Next();
	}

	path = path + code_list->CommaText;

	if (!CreateProcess(path, true)){
		Application->MessageBox("���x���󎚂��N���ł��܂���ł���", "���x����", MB_OK | MB_ICONSTOP);
	}
}
//---------------------------------------------------------------------------
// F12 �I��
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
// ����ŗ��擾
int __fastcall TMainForm::GetShohizeiritu(int date)
{
	AnsiString sql = AnsiString();
	sql =	" SELECT * FROM M_����� WHERE �J�n���t <= " + IntToStr(date);
	NsRecordSet set;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[set.size() - 1]["����ŗ�"]);
}
//---------------------------------------------------------------------------
// �o�͔͈͂��ׂ�
void __fastcall TMainForm::AllCheckBoxClick(TObject *Sender)
{
	SeikyusakiCodeEditF->Enabled     = !AllCheckBox->Checked;
	SeikyusakiNameEditF->Enabled     = !AllCheckBox->Checked;
	SeikyusakiSearchButtonF->Enabled = !AllCheckBox->Checked;

	SeikyusakiCodeEditT->Enabled     = !AllCheckBox->Checked;
	SeikyusakiNameEditT->Enabled     = !AllCheckBox->Checked;
	SeikyusakiSearchButtonT->Enabled = !AllCheckBox->Checked;

	if (!AllCheckBox->Checked)
		SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
// ���Ӑ�R�[�h(From)->OnChange
void __fastcall TMainForm::SeikyusakiCodeEditFChange(TObject *Sender)
{
	if (SeikyusakiCodeEditF->Text == ""){
		SeikyusakiNameEditF->Text = AnsiString();
		return;
	}
	SeikyusakiNameEditF->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEditF->Text, "���Ӑ於��", "���Ӑ�ID = ������ID"));
	if (SeikyusakiCodeEditT->Text == AnsiString())
		SeikyusakiCodeEditT->Text = SeikyusakiCodeEditF->Text;
}
//---------------------------------------------------------------------------
// ���Ӑ�(From)�����{�^��
void __fastcall TMainForm::SeikyusakiSearchButtonFClick(TObject *Sender)
{
	if (SimeComboBox->ItemIndex == -1)
		SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1";
	else
		SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1 AND ���� = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex];
	SearchForm->orderby_sql = "ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditF->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsString;
	SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
// ���Ӑ�R�[�h(To)->OnChange
void __fastcall TMainForm::SeikyusakiCodeEditTChange(TObject *Sender)
{
	if (SeikyusakiCodeEditT->Text == ""){
		SeikyusakiNameEditT->Text = AnsiString();
		return;
	}
	SeikyusakiNameEditT->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEditT->Text, "���Ӑ於��", "���Ӑ�ID = ������ID"));
}
//---------------------------------------------------------------------------
// ���Ӑ�(To)�����{�^��
void __fastcall TMainForm::SeikyusakiSearchButtonTClick(TObject *Sender)
{
	if (SimeComboBox->ItemIndex == -1)
		SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1";
	else
		SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1 AND ���� = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex];
	SearchForm->orderby_sql = "ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditT->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsString;
	SeikyusakiCodeEditT->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (ActiveControl->Tag != 9 && (Key == VK_RETURN || Key == VK_DOWN)){
		keybd_event(VK_TAB, 0, 0, 0);

	}else if (ActiveControl->Tag != 1 && (Key == VK_UP)){
		keybd_event(VK_SHIFT, 0, 0, 0);
		keybd_event(VK_TAB, 0, 0, 0);
		keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	}

	if (Key == VK_F9)
		btnF9->OnClick(btnF9);
	else if (Key == VK_F10)
		btnF10->OnClick(btnF10);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShosikiButtonClick(TObject *Sender)
{
	SettingsForm->ShowModal();	
}
//---------------------------------------------------------------------------
// �ʔ͈͐ݒ�
void __fastcall TMainForm::KobetuCheckBoxClick(TObject *Sender)
{
	SimekiriDatePicker->Enabled = KobetuCheckBox->Checked;
	DateFromPicker->Enabled     = KobetuCheckBox->Checked;
	DateToPicker->Enabled       = KobetuCheckBox->Checked;
	SimekiriEdit->Visible       = !KobetuCheckBox->Checked;
	DateFromEdit->Visible       = !KobetuCheckBox->Checked;
	DateToEdit->Visible         = !KobetuCheckBox->Checked;
}
//---------------------------------------------------------------------------
// DatePicker->OnChange
void __fastcall TMainForm::SimekiriDatePickerChange(TObject *Sender)
{
	SetDate();
}
//---------------------------------------------------------------------------
// ComboBox->OnKeyDown
void __fastcall TMainForm::CreateSeikyuComboBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key == VK_NUMPAD1)
		((TComboBox *)Sender)->ItemIndex = 0;
	else if (Key == VK_NUMPAD2)
		((TComboBox *)Sender)->ItemIndex = 1;
}
//---------------------------------------------------------------------------
// �����f�[�^�m�F�{�^��
void __fastcall TMainForm::SeikyuConfButtonClick(TObject *Sender)
{
	// �����ꗗ�ďo
	AnsiString path = ExtractFilePath(Application->Name) + "SeikyuDataMaintenance.exe " + IntToStr(DateToInt(SimekiriDatePicker->Date));

	if (!CreateProcess(path, true)){
		Application->MessageBox("�����f�[�^�����e�i���X���N���ł��܂���ł���",
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

