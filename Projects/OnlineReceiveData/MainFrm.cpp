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

	ReceiveButton->SetFocus();
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
void __fastcall TMainForm::ReceiveButtonClick(TObject *Sender)
{
    ReceiveButton->Enabled = false;
	try{
		StatusBar->Panels->Items[0]->Text = "��M��";
		Download();
		Import();
		StatusBar->Panels->Items[0]->Text = "��M����";
		StatusBar->Panels->Items[1]->Text = AnsiString();
		Application->MessageBox("��M���������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	}catch(Exception& e){
		AnsiString msg = "���M�Ɏ��s���܂��� - " + e.Message;
		Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
	}
	ReceiveButton->Enabled = true;
	ReceiveButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Download()
{
	StatusBar->Panels->Items[1]->Text = "FTP��M��...";

	AnsiString path = ExtractFilePath(Application->ExeName) + "\\Receive\\ftp_receive.bat";
	AnsiString del_path = ExtractFilePath(Application->ExeName) + "\\Receive\\delete_file.bat";
	AnsiString curr_path = ExtractFilePath(Application->ExeName) + "\\Receive";

	if (!DirectoryExists(curr_path)){
		if (!CreateDirectory(curr_path.c_str(), 0))
			throw Exception(("�t�H���_���쐬�ł��܂���\r\n" + curr_path).c_str());
	}

	// �����t�@�C�����폜
	DeleteFile(curr_path + "\*.csv");

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

	// FTP�_�E�����[�h
	if (!CreateProcess(NULL, path.c_str(), NULL, NULL, false, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, curr_path.c_str(), &stStartupInfo, &stProcessInfo)){
		Application->MessageBox("�t�@�C���_�E�����[�h���ɃG���[���������܂���", "���M", MB_ICONSTOP | MB_OK);
		StatusBar->Panels->Items[1]->Text = "FTP��M�G���[";
		return;
	}

	// �v���Z�X�҂�
	WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	CloseHandle(stProcessInfo.hThread);
	CloseHandle(stProcessInfo.hProcess);

	StatusBar->Panels->Items[1]->Text = "FTP��M���������܂���";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Import()
{
	AnsiString dir = ExtractFilePath(Application->ExeName) + "Receive";
	AnsiString file, table, sql;
	NsRecordSet set;
	NsFieldSet keys, fields;
	Variant var;
	AnsiString val;

	///// �C���|�[�g�e�[�u�����X�g�쐬
	std::auto_ptr<TStringList> tables(new TStringList());
	file = dir + "\\ExportTables.CSV";
	tables->LoadFromFile(file);

	std::auto_ptr<TStringList> columns(new TStringList());
	std::auto_ptr<TStringList> record(new TStringList());
	std::string line;
	bool has_id;
	bool is_exist;
	int car_no;

	for (int i = 0; i < tables->Count; i++){
		columns->Clear();

		table = tables->Strings[i];
		if (table == "M_�ԗ�")
			continue;

		try{
			DM->ADOConnection->GetFieldNames(table, columns.get());
			StatusBar->Panels->Items[1]->Text = "��M�f�[�^�捞��... " + table;

			if (table.Pos("M_") != 0){
				/* -----------------------------------
				 * �}�X�^�捞
				 * ----------------------------------*/
				// �}�X�^�̏ꍇ�A�S�N���A��ɍĎ�荞�݂��s��
				DM->DBI.Execute("DELETE FROM " + table);

				// �擪�t�B�[���h����ID���܂܂�Ă����� IDENTITY ON
				has_id = columns->Strings[0].AnsiPos("ID") > 0;

				if (has_id)
					DM->DBI.Execute("SET IDENTITY_INSERT " + table + " ON");

				// ���v���P�[�V�����`�F�b�N
				for (int c = 0; c < columns->Count; c++)
					if (columns->Strings[c].AnsiCompareIC("rowguid") == 0)
						throw Exception("���v���P�[�V���������ł̓f�[�^����M�͍s���܂���");

				file = dir + "\\" + table + ".CSV";
				std::ifstream ifs(file.c_str());

				while (std::getline(ifs, line)){
					fields.clear();
					record->Clear();
					record->CommaText = line.c_str();

					for (int c = 0; c < columns->Count; c++){
						if (record->Strings[c] == "@NULL@")
							var = Variant();
						else
							var = record->Strings[c];
						fields << NsField("[" + columns->Strings[c] + "]", var);
					}
					DM->DBI.Insert(table, fields);
				}
				ifs.close();

				if (has_id)
					DM->DBI.Execute("SET IDENTITY_INSERT " + table + " OFF");

			}else{
				/* -----------------------------------
				 * �f�[�^�捞
				 * ----------------------------------*/
				// �f�[�^�͍폜���Ȃ�
				//DM->DBI.Execute("DELETE FROM " + table);

				// IDENTITY �̑}���͂��Ȃ�
				//DM->DBI.Execute("SET IDENTITY_INSERT " + table + " ON");

				// ���v���P�[�V�����`�F�b�N
				for (int c = 0; c < columns->Count; c++)
					if (columns->Strings[c].AnsiCompareIC("rowguid") == 0)
						throw Exception("���v���P�[�V���������ł�USB�ɂ��f�[�^�����͍s���܂���");

				file = dir + "\\" + table + ".CSV";
				std::ifstream ifs(file.c_str());

				while (std::getline(ifs, line)){
					fields.clear();
					record->Clear();
					record->CommaText = line.c_str();

					for (int c = 1; c < columns->Count; c++){
						if (record->Strings[c] == "@NULL@")
							var = Variant();
						else
							var = record->Strings[c];
						fields << NsField("[" + columns->Strings[c] + "]", var);
					}
					car_no = (record->Strings[record->Count - 1]).ToIntDef(0);
					ReplaceSetField(fields, "[�ԗ�ID]", FindOrInsertSyaryo(car_no));

					if (table == "D_�v��"){
						keys.clear();
						keys << NsField("�v�ʓ�", record->Strings[1])
							 << NsField("���_ID", record->Strings[2])
							 << NsField("�`�[No", record->Strings[3])
							 << NsField("�sNo",   record->Strings[14]);
						is_exist = DM->DBI.IsExist(table, keys);

					}else if (table == "D_���"){
						keys.clear();
						keys << NsField("�����", record->Strings[1])
							 << NsField("���_ID", record->Strings[2])
							 << NsField("�`�[No", record->Strings[3])
							 << NsField("�sNo",   record->Strings[15]);
						is_exist = DM->DBI.IsExist(table, keys);

					}else
						continue;

					if (!is_exist){
						// �C���|�[�g���Ƀf�[�^���Ȃ���΍쐬
						DM->DBI.Insert(table, fields);
					}else{
						// �C���|�[�g���Ƀf�[�^������ΏC�����Ȃ�
						//DM->DBI.Update(table, id_field, id_val, fields);
					}
	            }
				//DM->DBI.Execute("SET IDENTITY_INSERT " + table + " OFF");

			}
		}catch(Exception& e){
			AnsiString hoge = table + ": " + e.Message;
			throw Exception(hoge);
		}
	}
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::FindOrInsertSyaryo(int car_no)
{
    if (car_no < 1)
        return 0;
        
    AnsiString sql;
    NsRecordSet set;
    NsFieldSet fields;
    TDateTime now(Now());
    
    ////////////////////////////////////////////////////////////////////////////
    // �ԗ��̌����i�Ȃ���΍쐬�j
    int car_id;
    sql = " SELECT �ԗ�ID FROM M_�ԗ� WHERE �Ԕ� = " + IntToStr(car_no) + " AND �g�p�敪 = 1";
    if (DM->DBI.GetRecordSet(sql, set)){
        car_id = ToInt(SET_TOP(set)["�ԗ�ID"]);
    }else{
        fields.clear();
        fields << NsField("[�Ԕ�]",     car_no)
               << NsField("[�ԗ�����]", "��M�������o�^")
               << NsField("[�g�p�敪]", 1)
               << NsField("[�X�V����]", now)
               << NsField("[�쐬����]", now);
        DM->DBI.Insert("M_�ԗ�", fields);
        car_id = DM->DBI.GetLastID();
    }
    return car_id;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TitlePanelDblClick(TObject *Sender)
{
	SettingButton->Visible = !SettingButton->Visible;	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SettingButtonClick(TObject *Sender)
{
	SettingForm->ShowModal();	
}
//---------------------------------------------------------------------------

