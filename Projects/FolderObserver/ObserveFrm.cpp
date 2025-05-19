// ---------------------------------------------------------------------------
/* 監視対象ファイル仕様
 * テーブル名-yyyymmddhhnnss.csv
 * (例)M_得意先-20171124103059.csv
 * ファイルの一行目にフィールド情報を付加
 *
 * マスタはバッチ前提の全削除→追加方式
 * データは無ければ追加、あれば上書き(暫定)
 * 計量と取引は計量IDでつながる為、ID挿入を許可してぶっこむ
 * 双方でデータを生成する場合は、導入時に「DBCC CHECKIDENT」で初期化してかぶらないように設定必須
 * 対象テーブルは全マスタ+D_計量+D_取引に限定(暫定)
 * マスタは処理後、移動の設定になっていても削除される
 * 伝票再発行はW_伝票を使用し、伝票発行後W_伝票の中身は削除する
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
	this->Caption = "フォルダ監視";

	if (!DM->Init()){
		is_exit_selected_ = true;
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

	LoadInifile();

	data_keys_.clear();
	data_keys_["D_計量"] = "拠点ID,計量日,伝票No,行No";
	data_keys_["D_取引"] = "拠点ID,取引日,伝票No,行No";
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
		Application->MessageBox(("設定の更新に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		DM->LOG("設定の更新に失敗しました\r\n" + e.Message);
		return;
	}

	LoadInifile();

	Application->MessageBox("設定を更新しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	is_exit_selected_ = false;
	Visible = false;
}
// ---------------------------------------------------------------------------
void __fastcall TObserveForm::CancelButtonClick(TObject *Sender)
{
	if (Application->MessageBox("変更した内容は破棄されます。よろしいですか？",
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
	// 対象フォルダ内のファイル名を列挙
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

			// ファイルのオープン状態確認
			if (IsFileAlreadyOpen(dir + i->second)){
				DM->ADOConnection->RollbackTrans();
				DM->LOG("ファイルが使用中なため処理を中断します - " + i->second);
				ObserveTimer->Enabled = true;
				return;
			}

			// テーブル名取得
			pos   = i->second.AnsiPos("-");
			if (!pos)
				pos = i->second.AnsiPos(".");
			table = i->second.SubString(1, pos - 1);

			// 対象(マスタ or データ)別に処理を記述(別関数)
			if (table.SubString(1, 1) == "M" || table.SubString(1, 1) == "D"){
				if (!PostTable(table, dir + i->second, msg)){
					DM->ADOConnection->RollbackTrans();
					DM->LOG("データ更新中にエラーが発生しました(" + i->second + ")\r\n" + msg);
					ObserveTimer->Enabled = true;
					return;
				}
			}else{
				DM->LOG("無効なファイルが含まれています - " + i->second);
				continue;
			}

			// 対象ファイルを移動/削除
			if (table.SubString(1, 1) == "D" && MoveRadioButton->Checked)
				MoveFile((dir + i->second).c_str(), (evacuation_dir + i->second).c_str());
			else if (table.SubString(1, 1) == "M" || DeleteRadioButton->Checked)
				DeleteFile(dir + i->second);

			DM->ADOConnection->CommitTrans();
		}catch (Exception& e){
			DM->ADOConnection->RollbackTrans();
			DM->LOG("データ更新中にエラーが発生しました(" + i->second + ")\r\n" + e.Message);
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
	// 対象フォルダ内のファイル名を列挙
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
			// ファイルのオープン状態確認
			if (IsFileAlreadyOpen(dir + i->second)){
				DM->PrintConnection->RollbackTrans();
				DM->LOG("ファイルが使用中なため処理を中断します - " + i->second);
				PrintTimer->Enabled = true;
				return;
			}

			// テーブル名取得
			pos   = i->second.AnsiPos("-");
			table = i->second.SubString(1, pos - 1);

			// 対象(マスタ or データ)別に処理を記述(別関数)
			if (table.SubString(1, 1) == "W"){
				if (!PostTable(table, dir + i->second, msg)){
					DM->PrintConnection->RollbackTrans();
					DM->LOG("伝票再発行中にエラーが発生しました(" + i->second + ")\r\n" + msg);
					PrintTimer->Enabled = true;
					return;
				}
			}else{
				DM->LOG("無効なファイルが含まれています - " + i->second);
				continue;
			}

			// 伝票再発行処理＆一時データ削除
			DM->DBI.GetRecordSet("SELECT 計量ID FROM W_伝票 WHERE 行No = (SELECT MIN(行No) AS 行No FROM W_伝票)", set);
			QRChitForm->Print(ToInt(SET_TOP(set)["計量ID"]));

			DM->DBI.Execute("DELETE FROM W_伝票");
			DeleteFile(dir + i->second);

			DM->PrintConnection->CommitTrans();
		}catch (Exception& e){
			DM->PrintConnection->RollbackTrans();
			DM->LOG("データ更新中にエラーが発生しました(" + i->second + ")\r\n" + e.Message);
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

		// 先頭フィールド名にIDが含まれていたら IDENTITY ON
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
					// ID列の更新が出来ない為、該当データを一度削除し挿入する
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
// フォルダ選択ダイアログ関数
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
	BrowsingInfo.lpszTitle      = "フォルダを選択してください";
	BrowsingInfo.ulFlags        = BIF_NEWDIALOGSTYLE;
	BrowsingInfo.lpfn           = &::BrowseCallbackProc;
	BrowsingInfo.lParam         = (LPARAM)path;
	ItemID = SHBrowseForFolder( &BrowsingInfo );
	SHGetPathFromIDList(ItemID, DirPath );
	GlobalFreePtr( ItemID );
	return (AnsiString)DirPath;
}
//---------------------------------------------------------------------------
// フォルダ選択ダイアログ用CallBack関数
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

