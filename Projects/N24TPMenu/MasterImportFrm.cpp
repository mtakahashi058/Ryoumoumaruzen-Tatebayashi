//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MasterImportFrm.h"
#include "DMFrm.h"
#include <string>
#include <fstream>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMasterImportForm *MasterImportForm;
//---------------------------------------------------------------------------
__fastcall TMasterImportForm::TMasterImportForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMasterImportForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	ErrorMemo->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TMasterImportForm::CloseButtonClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
void __fastcall TMasterImportForm::ImportButtonClick(TObject *Sender)
{
	static_cast<TButton *>(Sender)->Enabled = false;
	Import();
	static_cast<TButton *>(Sender)->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMasterImportForm::Import()
{
	ErrorMemo->Lines->Clear();
	ErrorMemo->Font->Color = clRed;

	// ドライブの列挙
	AnsiString drive;
	{
		char drive_buff[4];
		DWORD drives = GetLogicalDrives();
		for (int i = 0; i < sizeof(DWORD) * 8; i++){
			if (((1 << i) & drives) == 0)
				continue;
			wsprintf(drive_buff, "%C:\\", 'A' + i);

			if (GetDriveType(drive_buff) == DRIVE_REMOVABLE){
				drive = drive_buff;
				break;
			}
		}
	}
	if (drive.IsEmpty()){
		ErrorMemo->Lines->Text = "USB メモリが見つかりません。\r\nUSB メモリを挿入してもう一度出力してください。";
		return;
	}

    AnsiString path = drive + "ScaleManagerCSV";
    AnsiString file, table;

    ///// インポートテーブルリスト作成
    std::auto_ptr<TStringList> tables(new TStringList());
    file = path + "\\ExportMasterTables.CSV";
    try{
	    tables->LoadFromFile(file);
    }catch(Exception& e){
		ErrorMemo->Lines->Text = "マスタ情報が見つかりません。\r\nもう一度管理PCでマスタ出力をしてください。";
    	return;
    }

    std::auto_ptr<TStringList> columns(new TStringList());
    std::auto_ptr<TStringList> record(new TStringList());
    std::string line;
    bool has_id;
    Variant var;
    NsFieldSet fields;
    
    for (int i = 0; i < tables->Count; i++){
        columns->Clear();

        table = tables->Strings[i];

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
    	    DM->ADOConnection->RollbackTrans();

            AnsiString hoge = table + ": " + e.Message;
    		ErrorMemo->Lines->Text = hoge;
	    	return;
        }
	}


	// 削除
	DeleteFile(AnsiString(drive + "M_項目1.csv").c_str());
	DeleteFile(AnsiString(drive + "M_項目2.csv").c_str());
	DeleteFile(AnsiString(drive + "M_項目3.csv").c_str());
	DeleteFile(AnsiString(drive + "M_項目1項目3関連.csv").c_str());
	DeleteFile(AnsiString(drive + "M_カード.csv").c_str());

	ErrorMemo->Font->Color = clBlue;
	ErrorMemo->Lines->Text = "完了しました";
}
//---------------------------------------------------------------------------
