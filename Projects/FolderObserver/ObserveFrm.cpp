// ---------------------------------------------------------------------------
/* �Ď��Ώۃt�@�C���d�l
 * �e�[�u����-yyyymmddhhnnss.csv
 * (��)M_���Ӑ�-20171124103059.csv
 * �t�@�C���̈�s�ڂɃt�B�[���h����t��
 *
 * �}�X�^�̓o�b�`�O��̑S�폜���ǉ�����
 * �f�[�^�͖�����Βǉ��A����Ώ㏑��(�b��)
 * �v�ʂƎ���͌v��ID�łȂ���ׁAID�}���������ĂԂ�����
 * �o���Ńf�[�^�𐶐�����ꍇ�́A�������ɁuDBCC CHECKIDENT�v�ŏ��������Ă��Ԃ�Ȃ��悤�ɐݒ�K�{
 * �Ώۃe�[�u���͑S�}�X�^+D_�v��+D_����Ɍ���(�b��)
 * �}�X�^�͏�����A�ړ��̐ݒ�ɂȂ��Ă��Ă��폜�����
 * �`�[�Ĕ��s��W_�`�[���g�p���A�`�[���s��W_�`�[�̒��g�͍폜����
 */
// ---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN*1

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRChitFrm.h"
#include "ObserveFrm.h"
#include <windowsx.h>
#include <shlobj.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma link "CEdit"
#pragma resource "*.dfm"
TObserveForm *ObserveForm;

// ---------------------------------------------------------------------------
__fastcall TObserveForm::TObserveForm(TComponent* Owner)
	: TForm(Owner)
{
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::FormCreate(TObject *Sender)
{
	this->Caption = "�t�H���_�Ď�";

	if (!DM->Init()){
		is_exit_selected_ = true;
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

	LoadInifile();

	data_keys_.clear();
	data_keys_["D_�v��"] = "���_ID,�v�ʓ�,�`�[No,�sNo";
	data_keys_["D_���"] = "���_ID,�����,�`�[No,�sNo";
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (is_exit_selected_) {
		CanClose = true;
	}else{
		ObserveTimer->Enabled = true;
		CanClose = false;
		Visible = false;
		ShowWindow(Application->Handle, SW_HIDE);
	}
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::TargetButtonClick(TObject *Sender)
{
	AnsiString dir = ShowFolderDialog(TargetEdit->Text.c_str());
	if (dir.IsEmpty())
		return;
	TargetEdit->Text = dir;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::MoveRadioButtonClick(TObject *Sender)
{
	EvacuationEdit->Enabled   = MoveRadioButton->Checked;
	EvacuationButton->Enabled = MoveRadioButton->Checked;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::EvacuationButtonClick(TObject *Sender)
{
	AnsiString dir = ShowFolderDialog(EvacuationEdit->Text.c_str());
	if (dir.IsEmpty())
		return;
	EvacuationEdit->Text = dir;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::ApplyButtonClick(TObject *Sender)
{
	try {
		DM->INI.SaveSingle("FolderObserver", "Interval", IntervalEdit->Text);
		DM->INI.SaveSingle("FolderObserver", "TargetFolder", TargetEdit->Text);
		DM->INI.SaveSingle("FolderObserver", "Workaround", MoveRadioButton->Checked ? 1 : 2);
		DM->INI.SaveSingle("FolderObserver", "EvacuationFolder",	EvacuationEdit->Text);
	}catch (Exception& e){
		Application->MessageBox(("�ݒ�̍X�V�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		DM->LOG("�ݒ�̍X�V�Ɏ��s���܂���\r\n" + e.Message);
		return;
	}

	LoadInifile();

	Application->MessageBox("�ݒ���X�V���܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	is_exit_selected_ = false;
	Visible = false;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::CancelButtonClick(TObject *Sender)
{
	if (Application->MessageBox("�ύX�������e�͔j������܂��B��낵���ł����H",
		this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	LoadInifile();

	is_exit_selected_ = false;
	Visible = false;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::ObserveTimerTimer(TObject *Sender)
{
	ObserveTimer->Enabled = false;
	// �Ώۃt�H���_���̃t�@�C�������
	AnsiString dir  = TargetEdit->Text + "\\";
	AnsiString path = dir + "*.*";
	StringMap str_map;
	TSearchRec rec;
	AnsiString buff;
	SYSTEMTIME last_write_time;
	char file_age[17];

	if (!FindFirst(path, faAnyFile, rec)){
		do {
			if (rec.FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				continue;
			FileTimeToSystemTime(&rec.FindData.ftLastWriteTime, &last_write_time);
			wsprintf(file_age, TEXT("%04d%02d%02d%02d%02d%02d%03d"), last_write_time.wYear, last_write_time.wMonth,
					 last_write_time.wDay, last_write_time.wHour, last_write_time.wMinute, last_write_time.wSecond,
					 last_write_time.wMilliseconds);
			str_map[AnsiString(file_age)] = rec.Name;
		}while (!FindNext(rec));
	}

	NsFieldSet fields, keys;
	AnsiString table;
	AnsiString evacuation_dir = EvacuationEdit->Text + "\\";
	int pos;
	AnsiString msg;
	for (StringMap::iterator i = str_map.begin(); i != str_map.end(); i++){
		try{
			DM->ADOConnection->BeginTrans();

			if (i->second == "ExportMasterTables.CSV"){
				DeleteFile(dir + i->second);
				continue;
			}

			// �t�@�C���̃I�[�v����Ԋm�F
			if (IsFileAlreadyOpen(dir + i->second)){
				DM->ADOConnection->RollbackTrans();
				DM->LOG("�t�@�C�����g�p���Ȃ��ߏ����𒆒f���܂� - " + i->second);
				ObserveTimer->Enabled = true;
				return;
			}

			// �e�[�u�����擾
			pos   = i->second.AnsiPos("-");
			if (!pos)
				pos = i->second.AnsiPos(".");
			table = i->second.SubString(1, pos - 1);

			// �Ώ�(�}�X�^ or �f�[�^)�ʂɏ������L�q(�ʊ֐�)
			if (table.SubString(1, 1) == "M" || table.SubString(1, 1) == "D"){
				if (!PostTable(table, dir + i->second, msg)){
					DM->ADOConnection->RollbackTrans();
					DM->LOG("�f�[�^�X�V���ɃG���[���������܂���(" + i->second + ")\r\n" + msg);
					ObserveTimer->Enabled = true;
					return;
				}
			}else{
				DM->LOG("�����ȃt�@�C�����܂܂�Ă��܂� - " + i->second);
				continue;
			}

			// �Ώۃt�@�C�����ړ�/�폜
			if (table.SubString(1, 1) == "D" && MoveRadioButton->Checked)
				MoveFile((dir + i->second).c_str(), (evacuation_dir + i->second).c_str());
			else if (table.SubString(1, 1) == "M" || DeleteRadioButton->Checked)
				DeleteFile(dir + i->second);

			DM->ADOConnection->CommitTrans();
		}catch (Exception& e){
			DM->ADOConnection->RollbackTrans();
			DM->LOG("�f�[�^�X�V���ɃG���[���������܂���(" + i->second + ")\r\n" + e.Message);
			ObserveTimer->Enabled = true;
			return;
		}
	}

	ObserveTimer->Enabled = true;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::PrintTimerTimer(TObject *Sender)
{
	PrintTimer->Enabled = false;
	// �Ώۃt�H���_���̃t�@�C�������
	AnsiString dir  = ToString(DM->INI["FolderObserver::PrintFolder"]) + "\\";
	AnsiString path = dir + "*.*";
	StringMap str_map;
	TSearchRec rec;
	AnsiString buff;
	SYSTEMTIME last_write_time;
	char file_age[17];

	if (!FindFirst(path, faAnyFile, rec)){
		do {
			if (rec.FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				continue;
			FileTimeToSystemTime(&rec.FindData.ftLastWriteTime, &last_write_time);
			wsprintf(file_age, TEXT("%04d%02d%02d%02d%02d%02d%03d"), last_write_time.wYear, last_write_time.wMonth,
					 last_write_time.wDay, last_write_time.wHour, last_write_time.wMinute, last_write_time.wSecond,
					 last_write_time.wMilliseconds);
			str_map[AnsiString(file_age)] = rec.Name;
		}while (!FindNext(rec));
	}

	NsFieldSet fields, keys;
	AnsiString table;
	int pos;
	AnsiString msg;
	NsRecordSet set;
	for (StringMap::iterator i = str_map.begin(); i != str_map.end(); i++){
		try{
			DM->PrintConnection->BeginTrans();
			// �t�@�C���̃I�[�v����Ԋm�F
			if (IsFileAlreadyOpen(dir + i->second)){
				DM->PrintConnection->RollbackTrans();
				DM->LOG("�t�@�C�����g�p���Ȃ��ߏ����𒆒f���܂� - " + i->second);
				PrintTimer->Enabled = true;
				return;
			}

			// �e�[�u�����擾
			pos   = i->second.AnsiPos("-");
			table = i->second.SubString(1, pos - 1);

			// �Ώ�(�}�X�^ or �f�[�^)�ʂɏ������L�q(�ʊ֐�)
			if (table.SubString(1, 1) == "W"){
				if (!PostTable(table, dir + i->second, msg)){
					DM->PrintConnection->RollbackTrans();
					DM->LOG("�`�[�Ĕ��s���ɃG���[���������܂���(" + i->second + ")\r\n" + msg);
					PrintTimer->Enabled = true;
					return;
				}
			}else{
				DM->LOG("�����ȃt�@�C�����܂܂�Ă��܂� - " + i->second);
				continue;
			}

			// �`�[�Ĕ��s�������ꎞ�f�[�^�폜
			DM->DBI.GetRecordSet("SELECT �v��ID FROM W_�`�[ WHERE �sNo = (SELECT MIN(�sNo) AS �sNo FROM W_�`�[)", set);
			QRChitForm->Print(ToInt(SET_TOP(set)["�v��ID"]));

			DM->DBI.Execute("DELETE FROM W_�`�[");
			DeleteFile(dir + i->second);

			DM->PrintConnection->CommitTrans();
		}catch (Exception& e){
			DM->PrintConnection->RollbackTrans();
			DM->LOG("�f�[�^�X�V���ɃG���[���������܂���(" + i->second + ")\r\n" + e.Message);
			PrintTimer->Enabled = true;
			return;
		}
	}

	PrintTimer->Enabled = true;
}
//---------------------------------------------------------------------------
bool __fastcall TObserveForm::PostTable(AnsiString table, AnsiString file_path, AnsiString& msg)
{
	std::ifstream ifs(file_path.c_str());
	std::auto_ptr<TStringList> field_list(new TStringList());
	std::auto_ptr<TStringList> record(new TStringList());
	std::auto_ptr<TStringList> key_fields(new TStringList());
	std::string buff;
	NsFieldSet fields, keys;
	int idx;
	AnsiString table_type = table.SubString(1, 1);

	key_fields->CommaText = data_keys_[table];

//	std::getline(ifs, buff);
//	field_list->CommaText = buff.c_str();
	DM->ADOConnection->GetFieldNames(table, field_list.get());

	bool has_id = false;
	Variant col_buff;
	try{
		if (table_type == "M")
			DM->DBI.Execute("DELETE FROM " + table);

		// �擪�t�B�[���h����ID���܂܂�Ă����� IDENTITY ON
		has_id = field_list->Strings[0].AnsiPos("ID") > 0;
		if (has_id && table_type != "W")
			DM->DBI.Execute("SET IDENTITY_INSERT " + table + " ON");

		while (std::getline(ifs, buff)){
			record->CommaText = buff.c_str();

			fields.clear();
			for (int i = 0; i < field_list->Count; i++){
				if (record->Strings[i] == "@NULL@")
					col_buff = Variant();
				else
					col_buff = record->Strings[i];
				fields << NsField("[" + field_list->Strings[i] + "]", col_buff);
			}

			keys.clear();
			if (key_fields->Count > 0){
				for (int i = 0; i < key_fields->Count; i++){
					idx = field_list->IndexOf(key_fields->Strings[i]);
					keys << NsField(key_fields->Strings[i], record->Strings[idx]);
				}
			}

			if (table_type == "D"){
				if (DM->DBI.IsExist(table, keys)){
					// ID��̍X�V���o���Ȃ��ׁA�Y���f�[�^����x�폜���}������
					DM->DBI.Delete(table, keys);
					DM->DBI.Insert(table, fields);
				}else{
					DM->DBI.Insert(table, fields);
				}
			}else if (table_type == "M" || table_type == "W"){
				DM->DBI.Insert(table, fields);
			}
		}

		if (has_id && table_type != "W")
			DM->DBI.Execute("SET IDENTITY_INSERT " + table + " OFF");
	}catch (Exception& e){
		msg = e.Message;
		if (has_id && table_type != "W")
			DM->DBI.Execute("SET IDENTITY_INSERT " + table + " OFF");
		return false;
	}
	return true;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::LoadInifile()
{
	ObserveTimer->Enabled = false;
	PrintTimer->Enabled   = false;

	DM->INI.Reload();
	IntervalEdit->Text = ToInt(DM->INI["FolderObserver::Interval"]);
	TargetEdit->Text   = ToString(DM->INI["FolderObserver::TargetFolder"]);
	if (ToInt(DM->INI["FolderObserver::Workaround"]) == 1)
		MoveRadioButton->Checked = true;
	else
		DeleteRadioButton->Checked = true;
	EvacuationEdit->Text   = ToString(DM->INI["FolderObserver::EvacuationFolder"]);
	ObserveTimer->Interval = IntervalEdit->Text.ToIntDef(1) * 1000;
	ObserveTimer->Enabled  = true;

	if (!ToInt(DM->INI["FolderObserver::PrintChit"]))
		return;
	PrintTimer->Interval   = !ToInt(DM->INI["FolderObserver::PrintInterval"]) ? 1000 :
							  ToInt(DM->INI["FolderObserver::PrintInterval"]) * 1000;
	PrintTimer->Enabled    = true;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::N1Click(TObject *Sender)
{
	ObserveTimer->Enabled = false;
	Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TObserveForm::N2Click(TObject *Sender)
{
	ObserveTimer->Enabled = true;
	is_exit_selected_     = false;
	Visible               = false;
}
//---------------------------------------------------------------------------
void __fastcall TObserveForm::N3Click(TObject *Sender)
{
	is_exit_selected_ = true;
	Close();
}
//---------------------------------------------------------------------------
// �t�H���_�I���_�C�A���O�֐�
AnsiString __fastcall TObserveForm::ShowFolderDialog(char *path)
{
	BROWSEINFO BrowsingInfo;
	char DirPath[MAX_PATH];
	char FolderName[MAX_PATH];
	LPITEMIDLIST ItemID;

	ZeroMemory(&BrowsingInfo, sizeof(BROWSEINFO));
	ZeroMemory(DirPath, MAX_PATH);
	ZeroMemory(FolderName, MAX_PATH);
	BrowsingInfo.hwndOwner      = Handle;
	BrowsingInfo.pszDisplayName = FolderName;
	BrowsingInfo.lpszTitle      = "�t�H���_��I�����Ă�������";
	BrowsingInfo.ulFlags        = BIF_NEWDIALOGSTYLE;
	BrowsingInfo.lpfn           = &::BrowseCallbackProc;
	BrowsingInfo.lParam         = (LPARAM)path;
	ItemID = SHBrowseForFolder( &BrowsingInfo );
	SHGetPathFromIDList(ItemID, DirPath );
	GlobalFreePtr( ItemID );
	return (AnsiString)DirPath;
}
//---------------------------------------------------------------------------
// �t�H���_�I���_�C�A���O�pCallBack�֐�
int __stdcall BrowseCallbackProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch(uMsg){
	case BFFM_INITIALIZED:
		SendMessage(hWnd, BFFM_SETSELECTION, (WPARAM)TRUE, lpData);
		break;
	}
	return 0;
}
//---------------------------------------------------------------------------

