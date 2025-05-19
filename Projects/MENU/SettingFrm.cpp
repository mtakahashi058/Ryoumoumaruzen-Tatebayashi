//---------------------------------------------------------------------------

#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "SettingFrm.h"
//---------------------------------------------------------------------------
#include <windowsx.h>
#include <shlobj.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TSettingForm *SettingForm;
//---------------------------------------------------------------------------
__fastcall TSettingForm::TSettingForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::FormShow(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------
// INIファイル情報を画面上にセット
void __fastcall TSettingForm::SetIni2Form()
{
	if (UseKosin)
		rbUseKosin->Checked = true;
	else
		rbUnuseKosin->Checked = true;

	MotoPathEdit->Text = MotoPath;
	SakiPathEdit->Text = SakiPath;

	TaishoListBox->Items->Clear();
	GaiListBox->Items->Clear();

	std::auto_ptr<TStringList> GaiFileList(new TStringList());
	GaiFileList->CommaText = GaiList;

	for (int i = 0; i < FileListBox->Items->Count; i++){
		if (GaiFileList->IndexOf(FileListBox->Items->Strings[i]) == -1)
			TaishoListBox->Items->Append(FileListBox->Items->Strings[i]);
		else
			GaiListBox->Items->Append(FileListBox->Items->Strings[i]);
	}

	cbSettingFile->ItemIndex = cbSettingFile->Items->IndexOf(SettingName);	
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::btnMotoPathClick(TObject *Sender)
{
	AnsiString dir = ShowFolderDialog(MotoPathEdit->Text.c_str());
	if (dir != "" && dir.SubString(dir.Length(), 1) != "\\")
		MotoPathEdit->Text = dir + "\\";

	MotoPathEdit->OnExit(MotoPathEdit);
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::btnSakiPathClick(TObject *Sender)
{
	AnsiString dir = ShowFolderDialog(SakiPathEdit->Text.c_str());
	if (dir != "" && dir.SubString(dir.Length(), 1) != "\\")
		SakiPathEdit->Text = dir + "\\";
}
//---------------------------------------------------------------------------
/* フォルダ選択ダイアログ関数とデフォルトフォルダ指定のCallBack関数の定義 */
// フォルダ選択ダイアログ関数
AnsiString __fastcall TSettingForm::ShowFolderDialog(char *path)
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
	BrowsingInfo.ulFlags        = BIF_RETURNONLYFSDIRS;
	BrowsingInfo.lpfn           = &::BrowseCallbackProc;
	BrowsingInfo.lParam         = (LPARAM)path;
	ItemID = SHBrowseForFolder( &BrowsingInfo );
	SHGetPathFromIDList(ItemID, DirPath );
	GlobalFreePtr( ItemID );
	return (AnsiString)DirPath;
}
//---------------------------------------------------------------------------
// フォルダ選択ダイアログ用CallBack関数
static int __stdcall BrowseCallbackProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch(uMsg){
	case BFFM_INITIALIZED:
		SendMessage(hWnd, BFFM_SETSELECTION, (WPARAM)TRUE, lpData);
		break;
	}
	return 0;
}
//---------------------------------------------------------------------------
// 更新元->OnExit
void __fastcall TSettingForm::MotoPathEditExit(TObject *Sender)
{
	if (MotoPathEdit->Text == MotoPath)
		return;
	if (!DirectoryExists(MotoPathEdit->Text)){
		Application->MessageBox("更新元が見つかりませんでした", "設定変更", MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	// 更新元が変更されたら、再セット
	FileListBox->Directory = MotoPathEdit->Text;
	TaishoListBox->Items->Clear();
	GaiListBox->Items->Clear();

	cbSettingFile->Items->Clear();
	cbConnFile->Items->Clear();
	for (int i = 0; i < FileListBox->Items->Count; i++){
		TaishoListBox->Items->Append(FileListBox->Items->Strings[i]);
		cbSettingFile->Items->Append(FileListBox->Items->Strings[i]);
		cbConnFile->Items->Append(FileListBox->Items->Strings[i]);
	}
	cbConnFile->ItemIndex = cbConnFile->Items->IndexOf(MainForm->asConnName);
}
//---------------------------------------------------------------------------
// 「対象⇔対象外」の移動
void __fastcall TSettingForm::TaishoButtonClick(TObject *Sender)
{
	TListBox *listbox1, *listbox2;
	if ((TButton *)Sender == TaishoButton){
		listbox1 = GaiListBox;
		listbox2 = TaishoListBox;
	}else{
		listbox1 = TaishoListBox;
		listbox2 = GaiListBox;
	}

	listbox2->Items->Append(listbox1->Items->Strings[listbox1->ItemIndex]);
	listbox1->Items->Delete(listbox1->ItemIndex);
}
//---------------------------------------------------------------------------
// INIFILE 読み込み
bool __fastcall TSettingForm::ReadKosinIni()
{
	std::auto_ptr<TIniFile> ini(new TIniFile(ExtractFilePath(Application->ExeName) + "\\Kosin.ini"));
	UseKosin = ini->ReadInteger("更新設定", "Use", 0);		// 更新機能使用区分
	MotoPath = ini->ReadString("更新設定", "MOTO", "");		// コピー元
	SakiPath = ini->ReadString("更新設定", "SAKI", "");		// コピー先
	GaiList = ini->ReadString("更新設定", "GaiList", "");		// 更新対象外ファイルリスト
	SettingName = ini->ReadString("更新設定", "Setting", "");	// Iniファイル

	if (!DirectoryExists(SettingForm->MotoPath) || !DirectoryExists(SettingForm->SakiPath))
		return false;

	// 更新元を設定
	FileListBox->Directory = SettingForm->MotoPath;

	// 設定ファイルコンボの一覧を更新
	cbSettingFile->Items->Clear();
	cbConnFile->Items->Clear();
	for (int i = 0; i < FileListBox->Items->Count; i++){
		cbSettingFile->Items->Append(FileListBox->Items->Strings[i]);
		cbConnFile->Items->Append(FileListBox->Items->Strings[i]);
	}
	cbConnFile->ItemIndex = cbConnFile->Items->IndexOf(MainForm->asConnName);

	return true;
}
//---------------------------------------------------------------------------
// INIFILE 書き込み
void __fastcall TSettingForm::SaveKosinIni()
{
	std::auto_ptr<TIniFile> ini(new TIniFile(ExtractFilePath(Application->ExeName) + "\\Kosin.ini"));
	if (UseKosin)
		ini->WriteInteger("更新設定", "Use", 1);		// 更新機能使用区分
	else
		ini->WriteInteger("更新設定", "Use", 0);		// 更新機能使用区分
	ini->WriteString("更新設定", "MOTO", MotoPath);		// コピー元
	ini->WriteString("更新設定", "SAKI", SakiPath);		// コピー先
	ini->WriteString("更新設定", "GaiList", GaiList);    	// 更新対象外ファイルリスト
	ini->WriteString("更新設定", "Setting", SettingName);	// Iniファイル

	if (cbConnFile->Items->Strings[cbConnFile->ItemIndex] != MainForm->asConnName){
		std::auto_ptr<TIniFile> menu_ini(new TIniFile(ExtractFilePath(Application->ExeName) + "\\menu.ini"));
		menu_ini->WriteString("System", "Conn", cbConnFile->Items->Strings[cbConnFile->ItemIndex]);
	}
}
//---------------------------------------------------------------------------
// OKボタン
void __fastcall TSettingForm::OKButtonClick(TObject *Sender)
{
	UseKosin = rbUseKosin->Checked ? true : false;
	MainForm->KosinButton->Enabled = UseKosin;
	MotoPath = MotoPathEdit->Text;
	SakiPath = SakiPathEdit->Text;
	GaiList    = GaiListBox->Items->CommaText;
	SettingName  = cbSettingFile->Items->Strings[cbSettingFile->ItemIndex];

	// INIFILE 書き込み
	SaveKosinIni();

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
// 更新対象ファイルの検索
std::auto_ptr<TStringList> __fastcall TSettingForm::CopySearch()
{
	std::auto_ptr<TStringList> Files(new TStringList());

	bool div_overwrite;	// 上書き区分
	AnsiString FileName;
	TDateTime dt_moto, dt_saki;
	MainForm->StatusBar->Hint = "更新対象：";

	if (!DirectoryExists(MotoPath) || !DirectoryExists(SakiPath))
		return Files;

	for (int i = 0; i < TaishoListBox->Items->Count; i++){
		FileName = TaishoListBox->Items->Strings[i];

		//if (FileName == IniName && !chOverwrite->Checked)
			//continue;
		if (FileExists((SakiPath + "\\" + FileName).c_str())){
			dt_moto = FileDateToDateTime(FileAge((MotoPath + "\\"+ FileName).c_str()));
			dt_saki = FileDateToDateTime(FileAge((SakiPath + "\\"+ FileName).c_str()));
			if (dt_moto == dt_saki)		// 更新日時が同じだったら、continue
				continue;
		}

		Files->Append(FileName);
		MainForm->StatusBar->Hint += " " + FileName;
	}

	return Files;
}
//---------------------------------------------------------------------------
// 接続先設定編集ボタン
void __fastcall TSettingForm::ConnEditButtonClick(TObject *Sender)
{
	ShellExecute(NULL, NULL, cbConnFile->Items->Strings[cbConnFile->ItemIndex].c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

