//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "DMFrm.h"
#include <vector>
/*
#define STRICT  1
#include <shlobj.h>
#include <windowsx.h>
*/
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
	if (!DM->Init()){
    	Close();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectAllButtonClick(TObject *Sender)
{
	for (int i = 0; i < TablesCheckList->Items->Count; i++)
    	TablesCheckList->Checked[i] = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CancelAllButtonClick(TObject *Sender)
{
	for (int i = 0; i < TablesCheckList->Items->Count; i++)
    	TablesCheckList->Checked[i] = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FolderSelectButtonClick(TObject *Sender)
{
/*
	BROWSEINFO BrowsingInfo;
	char DirPath[MAX_PATH];
	char FolderName[MAX_PATH];
	LPITEMIDLIST ItemID;

	ZeroMemory(&BrowsingInfo, sizeof(BROWSEINFO));
	ZeroMemory(DirPath, MAX_PATH);
	ZeroMemory(FolderName, MAX_PATH);
	BrowsingInfo.hwndOwner      = Handle;
	BrowsingInfo.pszDisplayName = FolderName;
	BrowsingInfo.lpszTitle      = "出力先を選択してください";
	BrowsingInfo.ulFlags        = BIF_NEWDIALOGSTYLE;
	BrowsingInfo.lpfn           = &::BrowseCallbackProc;
	BrowsingInfo.lParam         = (LPARAM)(TargetEdit->Text.c_str());
	ItemID = SHBrowseForFolder(&BrowsingInfo);
	SHGetPathFromIDList(ItemID, DirPath);
	GlobalFreePtr(ItemID);

    AnsiString path = DirPath;
    if (!path.IsEmpty())
        FolderEdit->Text = path;
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExportButtonClick(TObject *Sender)
{
	std::vector<AnsiString> tables;
	for (int i = 0; i < TablesCheckList->Items->Count; i++){
    	if (TablesCheckList->Checked[i])
        	tables.push_back(TablesCheckList->Items->Strings[i]);
    }
    if (tables.empty()){
    	Application->MessageBox("テーブルを指定してください", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

	ExportButton->Enabled = false;

    AnsiString path = FolderEdit->Text;
    if (path.IsEmpty())
    	path = ExtractFilePath(Application->ExeName);
    if (path[path.Length()] != '\\')
    	path += "\\";

    AnsiString sql;
    NsRecordSet set;
    std::vector<AnsiString>::iterator i;
    for (i = tables.begin(); i != tables.end(); i++){
		sql = "SELECT * FROM " + *i;
        DM->DBI.GetRecordSet(sql, set);

    	SetToLTSV(path + *i + ".tsv", set, true);
    }

	ExportButton->Enabled = true;
}
//---------------------------------------------------------------------------
