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
    ImportTables_.push_back("D_計量");
    ImportTables_.push_back("D_取引");
    //ImportTables_.push_back("D_請求");
    //ImportTables_.push_back("D_入金");
    //ImportTables_.push_back("D_売掛");
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
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        
        AnsiString msg = "読込に失敗しました - " + e.Message;
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
    }
    ExportButton->Enabled = true;
    ExportButton->SetFocus();
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
void __fastcall TMainForm::Import(const AnsiString& path)
{
    AnsiString file, table, sql;
    NsFieldSet fields;

    if (!DirectoryExists(path)){
        throw Exception("CSVフォルダがありません");
    }

    std::auto_ptr<TStringList> columns(new TStringList());
    std::auto_ptr<TStringList> record(new TStringList());
    std::string line;

    Variant var;
    bool is_exist;
    NsFieldSet keys;
    int car_no;

    AnsiString id_field;
    int id_val;

    for (unsigned int i = 0; i < ImportTables_.size(); i++){
        columns->Clear();

        table = ImportTables_[i];

        try{
            DM->ADOConnection->GetFieldNames(table, columns.get());

            // データは削除しない
            //DM->DBI.Execute("DELETE FROM " + table);

            // IDENTITY の挿入はしない
            //DM->DBI.Execute("SET IDENTITY_INSERT " + table + " ON");

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
						 << NsField("行No",   record->Strings[15]);
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

