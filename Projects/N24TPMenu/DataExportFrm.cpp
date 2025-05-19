//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataExportFrm.h"
#include <DateUtils.hpp>
#include "DMFrm.h"
#include <fstream>
#include <memory>
#include "n24tp.h"8
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataExportForm *DataExportForm;
//---------------------------------------------------------------------------
__fastcall TDataExportForm::TDataExportForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	ErrorMemo->Lines->Clear();

	FromPicker->Date = Now();
	ToPicker->Date = Now();

    ExportTables_.clear();
    ExportTables_.push_back("D_計量");
    ExportTables_.push_back("D_取引");
    
    DateFields_.clear();
    DateFields_.push_back("計量日");
    DateFields_.push_back("取引日");

	ExportButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::FromDecButtonClick(TObject *Sender)
{
	FromPicker->Date = IncDay(FromPicker->Date, -1);
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::FromIncButtonClick(TObject *Sender)
{
	FromPicker->Date = IncDay(FromPicker->Date, 1);
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::ToDecButtonClick(TObject *Sender)
{
	ToPicker->Date = IncDay(ToPicker->Date, -1);
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::ToIncButtonClick(TObject *Sender)
{
	ToPicker->Date = IncDay(ToPicker->Date, 1);
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::FromTodayButtonClick(TObject *Sender)
{
	FromPicker->Date = Now();
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::ToTodayButtonClick(TObject *Sender)
{
	ToPicker->Date = Now();
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::ExportButtonClick(TObject *Sender)
{
	static_cast<TButton *>(Sender)->Enabled = false;
	Export();
	static_cast<TButton *>(Sender)->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDataExportForm::Export()
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

    if (!DirectoryExists(path)){
        if (!CreateDirectory(path.c_str(), 0))
            throw Exception("フォルダを作成できません");
    }

	int date_from = FromPicker->Date.FormatString("yyyymmdd").ToInt();
	int date_to   = ToPicker->Date.FormatString("yyyymmdd").ToInt();

	NsRecordSet set;
	AnsiString sql;

	try{
        std::auto_ptr<TStringList> fields(new TStringList());
        std::auto_ptr<TStringList> record(new TStringList());
        std::ofstream ofs;
        AnsiString table, date_field, file;
        Variant var;
        AnsiString val;

        for (unsigned int i = 0; i < ExportTables_.size(); i++){
            set.clear();
            fields->Clear();

            table = ExportTables_[i];
            DM->ADOConnection->GetFieldNames(table, fields.get());
            fields->Append("車番");

            // レプリケーションチェック
            for (int c = 0; c < fields->Count; c++)
                if (fields->Strings[c].AnsiCompareIC("rowguid") == 0)
                    throw Exception("レプリケーション環境下ではUSBによるデータ交換は行えません");

            sql = "SELECT *, 車番 FROM " + table + " LEFT OUTER JOIN M_車両 ON M_車両.車両ID = " + table + ".車両ID";

            date_field = DateFields_[i];
            if (date_field != "none"){
                sql += " WHERE " + date_field + " >= " + IntToStr(date_from) + " AND " + date_field + " <= " + IntToStr(date_to);
            }
            DM->DBI.GetRecordSet(sql, set);

            file = path + "\\" + table + ".CSV";
            ofs.open(file.c_str());

            for (unsigned int r = 0; r < set.size(); r++){
                record->Clear();
                for (int c = 0; c < fields->Count; c++){
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
	}catch(Exception& e){
		ErrorMemo->Lines->Append("データ出力: " + e.Message);
		return;
	}

	ErrorMemo->Font->Color = clBlue;
	ErrorMemo->Lines->Text = "完了しました";
}
//---------------------------------------------------------------------------
