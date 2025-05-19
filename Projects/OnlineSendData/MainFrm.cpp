//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "DMFrm.h"
#include "SettingFrm.h"
#include <memory>
#include <fstream>
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
	DM->Init();

	SettingForm->LoadSetting();

	if (SettingForm->SendListBox->Items->IndexOf("D_�v��") >= 0 || SettingForm->SendListBox->Items->IndexOf("D_���") >= 0)
		KeiryoDatePanel->Visible = true;
	else
		KeiryoDatePanel->Visible = false;

	DatePickerFrom->Date = Date();
	DatePickerTo->Date = Date();
	SendButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SendButtonClick(TObject *Sender)
{
    SendButton->Enabled = false;
    try{
		StatusBar->Panels->Items[0]->Text = "���M��";
		Export();
		Upload();
		StatusBar->Panels->Items[0]->Text = "���M����";
		StatusBar->Panels->Items[1]->Text = AnsiString();
		Application->MessageBox("���M���������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	}catch(Exception& e){
		AnsiString msg = "���M�Ɏ��s���܂��� - " + e.Message;
		Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
	}
	SendButton->Enabled = true;
	SendButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteFiles()
{
	AnsiString del_path = ExtractFilePath(Application->ExeName) + "\\Send\\delete_file.bat";
	AnsiString curr_path = ExtractFilePath(Application->ExeName) + "\\Send";

	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;

	// �����t�@�C���폜
	if (!CreateProcess(NULL, del_path.c_str(), NULL, NULL, false, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, curr_path.c_str(), &stStartupInfo, &stProcessInfo)){
		Application->MessageBox("�����t�@�C���̍폜�Ɏ��s���܂���", "���M", MB_ICONSTOP | MB_OK);
		StatusBar->Panels->Items[1]->Text = "FTP��M�G���[";
		return;
	}

	// �v���Z�X�҂�
	WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	CloseHandle(stProcessInfo.hThread);
	CloseHandle(stProcessInfo.hProcess);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Export()
{
	// �����t�@�C�����폜
	DeleteFiles();

	AnsiString dir = ExtractFilePath(Application->ExeName) + "Send";
	AnsiString file, table, sql;
	NsRecordSet set;
	Variant var;
	AnsiString val;

	if (!DirectoryExists(dir)){
		if (!CreateDirectory(dir.c_str(), 0))
			throw Exception(("�t�H���_���쐬�ł��܂���\r\n" + dir).c_str());
	}

	///// �G�N�X�|�[�g�e�[�u�����X�g�쐬
	std::auto_ptr<TStringList> tables(new TStringList());
	tables->CommaText = SettingForm->SendListBox->Items->CommaText;

	file = dir + "\\ExportTables.CSV";
	tables->SaveToFile(file);

	std::auto_ptr<TStringList> fields(new TStringList());
	std::auto_ptr<TStringList> record(new TStringList());
	std::ofstream ofs;
	for (int i = 0; i < tables->Count; i++){
		StatusBar->Panels->Items[1]->Text = "���M�f�[�^�쐬��... " + tables->Strings[i];
		Application->ProcessMessages();

		set.clear();
		fields->Clear();

		table = tables->Strings[i];
		DM->ADOConnection->GetFieldNames(table, fields.get());

		// ���v���P�[�V�����`�F�b�N
		for (int c = 0; c < fields->Count; c++)
			if (fields->Strings[c].AnsiCompareIC("rowguid") == 0)
				throw Exception("���v���P�[�V���������ł̓f�[�^����M�͍s���܂���");

		if (table == "D_�v��")
			sql = "SELECT *, �Ԕ� FROM " + table + " LEFT OUTER JOIN M_�ԗ� ON M_�ԗ�.�ԗ�ID = " + table + ".�ԗ�ID WHERE �v�ʓ� BETWEEN " + IntToStr(DateToInt(DatePickerFrom->Date)) + " AND " + IntToStr(DateToInt(DatePickerTo->Date)) + " AND �����敪 = 1";
		else if (table == "D_���")
			sql = "SELECT *, �Ԕ� FROM " + table + " LEFT OUTER JOIN M_�ԗ� ON M_�ԗ�.�ԗ�ID = " + table + ".�ԗ�ID WHERE ����� BETWEEN " + IntToStr(DateToInt(DatePickerFrom->Date)) + " AND " + IntToStr(DateToInt(DatePickerTo->Date)) + " AND �����敪 = 1";
		else
			sql = "SELECT * FROM " + table;

		DM->DBI.GetRecordSet(sql, set);

		file = dir + "\\" + table + ".CSV";
		ofs.open(file.c_str());

        int field_count = fields->Count;
		if (table == "D_�v��" || table == "D_���"){
            fields->Add("�Ԕ�");
            field_count++;
        }

		for (unsigned int r = 0; r < set.size(); r++){
			record->Clear();
			for (int c = 0; c < field_count; c++){
				var = set[r][fields->Strings[c]];
				if (var.IsNull())
					val = "@NULL@";
				else
					val = ToString(var);
				record->Append(val);
			}
			ofs << record->CommaText.c_str() << std::endl;
		}
		ofs.close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Upload()
{
	StatusBar->Panels->Items[1]->Text = "FTP���M��...";

	AnsiString path = ExtractFilePath(Application->ExeName) + "\\Send\\ftp_send.bat";
	AnsiString curr_path = ExtractFilePath(Application->ExeName) + "\\Send";

	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;

	// FTP�A�b�v���[�h
	if (!CreateProcess(NULL, path.c_str(), NULL, NULL, false, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, curr_path.c_str(), &stStartupInfo, &stProcessInfo)){
		Application->MessageBox("�t�@�C���A�b�v���[�h���ɃG���[���������܂���", "���M", MB_ICONSTOP | MB_OK);
		StatusBar->Panels->Items[1]->Text = "FTP���M�G���[";
		return;
	}

	// �v���Z�X�҂�
	WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	CloseHandle(stProcessInfo.hThread);
	CloseHandle(stProcessInfo.hProcess);

	StatusBar->Panels->Items[1]->Text = "FTP���M���������܂���";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TitlePanelDblClick(TObject *Sender)
{
	SettingButton->Visible = !SettingButton->Visible;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SettingButtonClick(TObject *Sender)
{
	if (SettingForm->ShowModal() != mrOk)
		return;
	if (SettingForm->SendListBox->Items->IndexOf("D_�v��") >= 0 || SettingForm->SendListBox->Items->IndexOf("D_���") >= 0)
		KeiryoDatePanel->Visible = true;
	else
		KeiryoDatePanel->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BeforeButtonClick(TObject *Sender)
{
	ShiftDate(DatePickerFrom, DatePickerTo, -1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(DatePickerFrom, DatePickerTo, 1);
}
//---------------------------------------------------------------------------

