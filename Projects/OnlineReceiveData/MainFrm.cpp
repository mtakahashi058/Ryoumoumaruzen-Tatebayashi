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
		StatusBar->Panels->Items[0]->Text = "受信中";
		Download();
		Import();
		StatusBar->Panels->Items[0]->Text = "受信完了";
		StatusBar->Panels->Items[1]->Text = AnsiString();
		Application->MessageBox("受信が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	}catch(Exception& e){
		AnsiString msg = "送信に失敗しました - " + e.Message;
		Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
	}
	ReceiveButton->Enabled = true;
	ReceiveButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Download()
{
	StatusBar->Panels->Items[1]->Text = "FTP受信中...";

	AnsiString path = ExtractFilePath(Application->ExeName) + "\\Receive\\ftp_receive.bat";
	AnsiString del_path = ExtractFilePath(Application->ExeName) + "\\Receive\\delete_file.bat";
	AnsiString curr_path = ExtractFilePath(Application->ExeName) + "\\Receive";

	if (!DirectoryExists(curr_path)){
		if (!CreateDirectory(curr_path.c_str(), 0))
			throw Exception(("フォルダを作成できません\r\n" + curr_path).c_str());
	}

	// 既存ファイルを削除
	DeleteFile(curr_path + "\*.csv");

	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;

	// 既存ファイル削除
	if (!CreateProcess(NULL, del_path.c_str(), NULL, NULL, false, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, curr_path.c_str(), &stStartupInfo, &stProcessInfo)){
		Application->MessageBox("既存ファイルの削除に失敗しました", "送信", MB_ICONSTOP | MB_OK);
		StatusBar->Panels->Items[1]->Text = "FTP受信エラー";
		return;
	}

	// プロセス待ち
	WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	CloseHandle(stProcessInfo.hThread);
	CloseHandle(stProcessInfo.hProcess);

	// FTPダウンロード
	if (!CreateProcess(NULL, path.c_str(), NULL, NULL, false, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, curr_path.c_str(), &stStartupInfo, &stProcessInfo)){
		Application->MessageBox("ファイルダウンロード中にエラーが発生しました", "送信", MB_ICONSTOP | MB_OK);
		StatusBar->Panels->Items[1]->Text = "FTP受信エラー";
		return;
	}

	// プロセス待ち
	WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	CloseHandle(stProcessInfo.hThread);
	CloseHandle(stProcessInfo.hProcess);

	StatusBar->Panels->Items[1]->Text = "FTP受信が完了しました";
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

	///// インポートテーブルリスト作成
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
		if (table == "M_車両")
			continue;

		try{
			DM->ADOConnection->GetFieldNames(table, columns.get());
			StatusBar->Panels->Items[1]->Text = "受信データ取込中... " + table;

			if (table.Pos("M_") != 0){
				/* -----------------------------------
				 * マスタ取込
				 * ----------------------------------*/
				// マスタの場合、全クリア後に再取り込みを行う
				DM->DBI.Execute("DELETE FROM " + table);

				// 先頭フィールド名にIDが含まれていたら IDENTITY ON
				has_id = columns->Strings[0].AnsiPos("ID") > 0;

				if (has_id)
					DM->DBI.Execute("SET IDENTITY_INSERT " + table + " ON");

				// レプリケーションチェック
				for (int c = 0; c < columns->Count; c++)
					if (columns->Strings[c].AnsiCompareIC("rowguid") == 0)
						throw Exception("レプリケーション環境下ではデータ送受信は行えません");

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
				 * データ取込
				 * ----------------------------------*/
				// データは削除しない
				//DM->DBI.Execute("DELETE FROM " + table);

				// IDENTITY の挿入はしない
				//DM->DBI.Execute("SET IDENTITY_INSERT " + table + " ON");

				// レプリケーションチェック
				for (int c = 0; c < columns->Count; c++)
					if (columns->Strings[c].AnsiCompareIC("rowguid") == 0)
						throw Exception("レプリケーション環境下ではUSBによるデータ交換は行えません");

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
					ReplaceSetField(fields, "[車両ID]", FindOrInsertSyaryo(car_no));

					if (table == "D_計量"){
						keys.clear();
						keys << NsField("計量日", record->Strings[1])
							 << NsField("拠点ID", record->Strings[2])
							 << NsField("伝票No", record->Strings[3])
							 << NsField("行No",   record->Strings[14]);
						is_exist = DM->DBI.IsExist(table, keys);

					}else if (table == "D_取引"){
						keys.clear();
						keys << NsField("取引日", record->Strings[1])
							 << NsField("拠点ID", record->Strings[2])
							 << NsField("伝票No", record->Strings[3])
							 << NsField("行No",   record->Strings[15]);
						is_exist = DM->DBI.IsExist(table, keys);

					}else
						continue;

					if (!is_exist){
						// インポート側にデータがなければ作成
						DM->DBI.Insert(table, fields);
					}else{
						// インポート側にデータがあれば修正しない
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
    // 車両の検索（なければ作成）
    int car_id;
    sql = " SELECT 車両ID FROM M_車両 WHERE 車番 = " + IntToStr(car_no) + " AND 使用区分 = 1";
    if (DM->DBI.GetRecordSet(sql, set)){
        car_id = ToInt(SET_TOP(set)["車両ID"]);
    }else{
        fields.clear();
        fields << NsField("[車番]",     car_no)
               << NsField("[車両名称]", "受信時自動登録")
               << NsField("[使用区分]", 1)
               << NsField("[更新日時]", now)
               << NsField("[作成日時]", now);
        DM->DBI.Insert("M_車両", fields);
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

