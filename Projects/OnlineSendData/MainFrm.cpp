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

	if (SettingForm->SendListBox->Items->IndexOf("D_計量") >= 0 || SettingForm->SendListBox->Items->IndexOf("D_取引") >= 0)
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
		StatusBar->Panels->Items[0]->Text = "送信中";
		Export();
		Upload();
		StatusBar->Panels->Items[0]->Text = "送信完了";
		StatusBar->Panels->Items[1]->Text = AnsiString();
		Application->MessageBox("送信が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	}catch(Exception& e){
		AnsiString msg = "送信に失敗しました - " + e.Message;
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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Export()
{
	// 既存ファイルを削除
	DeleteFiles();

	AnsiString dir = ExtractFilePath(Application->ExeName) + "Send";
	AnsiString file, table, sql;
	NsRecordSet set;
	Variant var;
	AnsiString val;

	if (!DirectoryExists(dir)){
		if (!CreateDirectory(dir.c_str(), 0))
			throw Exception(("フォルダを作成できません\r\n" + dir).c_str());
	}

	///// エクスポートテーブルリスト作成
	std::auto_ptr<TStringList> tables(new TStringList());
	tables->CommaText = SettingForm->SendListBox->Items->CommaText;

	file = dir + "\\ExportTables.CSV";
	tables->SaveToFile(file);

	std::auto_ptr<TStringList> fields(new TStringList());
	std::auto_ptr<TStringList> record(new TStringList());
	std::ofstream ofs;
	for (int i = 0; i < tables->Count; i++){
		StatusBar->Panels->Items[1]->Text = "送信データ作成中... " + tables->Strings[i];
		Application->ProcessMessages();

		set.clear();
		fields->Clear();

		table = tables->Strings[i];
		DM->ADOConnection->GetFieldNames(table, fields.get());

		// レプリケーションチェック
		for (int c = 0; c < fields->Count; c++)
			if (fields->Strings[c].AnsiCompareIC("rowguid") == 0)
				throw Exception("レプリケーション環境下ではデータ送受信は行えません");

		if (table == "D_計量")
			sql = "SELECT *, 車番 FROM " + table + " LEFT OUTER JOIN M_車両 ON M_車両.車両ID = " + table + ".車両ID WHERE 計量日 BETWEEN " + IntToStr(DateToInt(DatePickerFrom->Date)) + " AND " + IntToStr(DateToInt(DatePickerTo->Date)) + " AND 完了区分 = 1";
		else if (table == "D_取引")
			sql = "SELECT *, 車番 FROM " + table + " LEFT OUTER JOIN M_車両 ON M_車両.車両ID = " + table + ".車両ID WHERE 取引日 BETWEEN " + IntToStr(DateToInt(DatePickerFrom->Date)) + " AND " + IntToStr(DateToInt(DatePickerTo->Date)) + " AND 完了区分 = 1";
		else
			sql = "SELECT * FROM " + table;

		DM->DBI.GetRecordSet(sql, set);

		file = dir + "\\" + table + ".CSV";
		ofs.open(file.c_str());

        int field_count = fields->Count;
		if (table == "D_計量" || table == "D_取引"){
            fields->Add("車番");
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
	StatusBar->Panels->Items[1]->Text = "FTP送信中...";

	AnsiString path = ExtractFilePath(Application->ExeName) + "\\Send\\ftp_send.bat";
	AnsiString curr_path = ExtractFilePath(Application->ExeName) + "\\Send";

	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;

	// FTPアップロード
	if (!CreateProcess(NULL, path.c_str(), NULL, NULL, false, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, curr_path.c_str(), &stStartupInfo, &stProcessInfo)){
		Application->MessageBox("ファイルアップロード中にエラーが発生しました", "送信", MB_ICONSTOP | MB_OK);
		StatusBar->Panels->Items[1]->Text = "FTP送信エラー";
		return;
	}

	// プロセス待ち
	WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	CloseHandle(stProcessInfo.hThread);
	CloseHandle(stProcessInfo.hProcess);

	StatusBar->Panels->Items[1]->Text = "FTP送信が完了しました";
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
	if (SettingForm->SendListBox->Items->IndexOf("D_計量") >= 0 || SettingForm->SendListBox->Items->IndexOf("D_取引") >= 0)
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

