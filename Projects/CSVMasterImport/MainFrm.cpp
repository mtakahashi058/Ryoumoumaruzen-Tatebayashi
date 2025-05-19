//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "DMFrm.h"
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

	ErrorMemo->Lines->Clear();
	ErrorMemo->Font->Color = clRed;
	DriveList->Items->Clear();

    PageControl->ActivePage   = ToInt(DM->INI["DefaultValue::CSVImportTarget"]) == 0 ? USBSheet : PathSheet;
	PathEdit->Text            = ToString(DM->INI["DefaultValue::CSVImportPath"]);
	ExportSharyoCheck->Checked = ToInt(DM->INI["DefaultValue::ImportSharyo"]) == 0 ? false : true;

    if (PageControl->ActivePage != USBSheet)
        ErrorMemo->Visible = false;

	// 取り込み元ドライブの列挙
	char drive_buff[4];
	char drive_name[11];
	DWORD drives = GetLogicalDrives();
	for (int i = 0; i < sizeof(DWORD) * 8; i++){
		if (((1 << i) & drives) == 0)
			continue;
		wsprintf(drive_buff, "%C:\\", 'A' + i);

		if (GetDriveType(drive_buff) == DRIVE_REMOVABLE){
			wsprintf(drive_name, "%C ドライブ", 'A' + i);
			DriveList->Items->Append(drive_name);
		}
	}
	if (DriveList->Items->Count == 0){
		ErrorMemo->Lines->Text = "USB メモリが見つかりません\r\n\r\n挿入後、再度メニューから実行するか、\r\nドライブを指定して下さい";
		ExportButton->Enabled = true;
        SelectPanel->Visible  = true;
        DriveCombo->Visible   = true;
        //DriveCombo->SetFocus();
	}else{
		DriveList->ItemIndex = DriveList->Count - 1;
        ExportButton->SetFocus();
	}
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
void __fastcall TMainForm::ExportButtonClick(TObject *Sender)
{
    ExportButton->Enabled = false;

    TTabSheet *ActiveSheet = PageControl->ActivePage;
    
    try{
        AnsiString path;

        if (ActiveSheet == USBSheet){
            if (DriveList->Items->Count > 0){
                path = (DriveList->Items->Strings[DriveList->ItemIndex])[1];
            }else{
                path = (DriveCombo->Items->Strings[DriveCombo->ItemIndex])[1];
                ErrorMemo->Visible = false;
            }
            path = path + ":\\ScaleManagerCSV";
        }else{
            path = PathEdit->Text;
            if (path[path.Length()] == '\\')
                path.Delete(path.Length(), 1);
        }

        DM->ADOConnection->BeginTrans();
        Import(path);
        DM->ADOConnection->CommitTrans();

        Application->MessageBox("読込が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

        DM->INI.SaveSingle("DefaultValue", "CSVImportTarget", ActiveSheet == USBSheet ? "0" : "1");
		DM->INI.SaveSingle("DefaultValue", "CSVImportPath", PathEdit->Text);
		DM->INI.SaveSingle("DefaultValue", "ImportSharyo", ExportSharyoCheck->Checked ? "1" : "0");

	}catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString msg = "読込に失敗しました - " + e.Message;
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
    }
    ExportButton->Enabled = true;
    ExportButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Import(const AnsiString& path)
{
    AnsiString file, table, sql;
    NsFieldSet fields;

    if (!DirectoryExists(path)){
        throw Exception("CSVフォルダがありません");
    }

    ///// インポートテーブルリスト作成
    std::auto_ptr<TStringList> tables(new TStringList());
    file = path + "\\ExportMasterTables.CSV";
    tables->LoadFromFile(file);

    std::auto_ptr<TStringList> columns(new TStringList());
    std::auto_ptr<TStringList> record(new TStringList());
    std::string line;
    bool has_id;
    Variant var;
    for (int i = 0; i < tables->Count; i++){
        columns->Clear();

        table = tables->Strings[i];
        if (table == "M_車両" && !ExportSharyoCheck->Checked)
            continue;

        try{
            DM->ADOConnection->GetFieldNames(table, columns.get());

            DM->DBI.Execute("DELETE FROM " + table);

            // 先頭フィールド名にIDが含まれていたら IDENTITY ON
            has_id = columns->Strings[0].AnsiPos("ID") > 0;

            if (has_id)
                DM->DBI.Execute("SET IDENTITY_INSERT " + table + " ON");

            // レプリケーションチェック
            for (int c = 0; c < columns->Count; c++)
                if (columns->Strings[c].AnsiCompareIC("rowguid") == 0)
                    throw Exception("レプリケーション環境下ではUSBによるデータ交換は行えません");

            file = path + "\\" + table + ".CSV";
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
        }catch(Exception& e){                  
            AnsiString hoge = table + ": " + e.Message;
            throw Exception(hoge);
        }
    }

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RefButtonClick(TObject *Sender)
{
    if (!OpenDialog->Execute())
        return;
    AnsiString path = ExtractFilePath(OpenDialog->FileName);
    if (path[path.Length()] == '\\')
        path.Delete(path.Length(), 1);

    PathEdit->Text = path;
}
//---------------------------------------------------------------------------

