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
    ExportTables_.push_back("D_�v��");
    ExportTables_.push_back("D_���");
    //ExportTables_.push_back("D_����");
    //ExportTables_.push_back("D_����");
    //ExportTables_.push_back("D_���|");

    DateFields_.push_back("�v�ʓ�");
    DateFields_.push_back("�����");
    //DateFields_.push_back("none");
    //DateFields_.push_back("none");
    //DateFields_.push_back("none");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    DM->Init();

    FromPicker->Date = Now();
    ToPicker->Date   = Now();

	ErrorMemo->Lines->Clear();
	ErrorMemo->Font->Color = clRed;
	DriveList->Items->Clear();

    PageControl->ActivePage   = ToInt(DM->INI["DefaultValue::CSVExportTarget"]) == 0 ? USBSheet : PathSheet;
    PathEdit->Text            = ToString(DM->INI["DefaultValue::CSVExportPath"]);

    if (PageControl->ActivePage != USBSheet)
        ErrorMemo->Visible = false;

	// ��荞�݌��h���C�u�̗�
	char drive_buff[4];
	char drive_name[11];
	DWORD drives = GetLogicalDrives();
	for (int i = 0; i < sizeof(DWORD) * 8; i++){
		if (((1 << i) & drives) == 0)
			continue;
		wsprintf(drive_buff, "%C:\\", 'A' + i);

		if (GetDriveType(drive_buff) == DRIVE_REMOVABLE){
			wsprintf(drive_name, "%C �h���C�u", 'A' + i);
			DriveList->Items->Append(drive_name);
		}
	}
	if (DriveList->Items->Count == 0){
		ErrorMemo->Lines->Text = "USB ��������������܂���\r\n\r\n�}����A�ēx���j���[������s���邩�A\r\n�h���C�u���w�肵�ĉ�����";
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
        DM->INI.SaveSingle("DefaultValue", "CSVExportTarget", ActiveSheet == USBSheet ? "0" : "1");
        DM->INI.SaveSingle("DefaultValue", "CSVExportPath", PathEdit->Text);

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

        Export(path);
        Application->MessageBox("�o�͂��������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    }catch(Exception& e){
        AnsiString msg = "�o�͂Ɏ��s���܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
    }
    ExportButton->Enabled = true;
    ExportButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Export(const AnsiString& path)
{
    AnsiString file, table, date_field, sql;
    NsRecordSet set;
    Variant var;
    AnsiString val;

    if (!DirectoryExists(path)){
        if (!CreateDirectory(path.c_str(), 0))
            throw Exception("�t�H���_���쐬�ł��܂���");
    }

    int date_from = FromPicker->Date.FormatString("yyyymmdd").ToInt();
    int date_to   = ToPicker->Date.FormatString("yyyymmdd").ToInt();

    std::auto_ptr<TStringList> fields(new TStringList());
    std::auto_ptr<TStringList> record(new TStringList());
    std::ofstream ofs;
    for (unsigned int i = 0; i < ExportTables_.size(); i++){
        set.clear();
        fields->Clear();

        table = ExportTables_[i];
        DM->ADOConnection->GetFieldNames(table, fields.get());
        fields->Append("�Ԕ�");

        // ���v���P�[�V�����`�F�b�N
        for (int c = 0; c < fields->Count; c++)
            if (fields->Strings[c].AnsiCompareIC("rowguid") == 0)
                throw Exception("���v���P�[�V���������ł�USB�ɂ��f�[�^�����͍s���܂���");

        sql = "SELECT *, �Ԕ� FROM " + table + " LEFT OUTER JOIN M_�ԗ� ON M_�ԗ�.�ԗ�ID = " + table + ".�ԗ�ID";

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

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RefButtonClick(TObject *Sender)
{
    if (!SaveDialog->Execute())
        return;
    AnsiString path = ExtractFilePath(SaveDialog->FileName);
    if (path[path.Length()] == '\\')
        path.Delete(path.Length(), 1);
        
    PathEdit->Text = path;
}
//---------------------------------------------------------------------------

