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
// INI�t�@�C��������ʏ�ɃZ�b�g
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
/* �t�H���_�I���_�C�A���O�֐��ƃf�t�H���g�t�H���_�w���CallBack�֐��̒�` */
// �t�H���_�I���_�C�A���O�֐�
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
	BrowsingInfo.lpszTitle      = "�t�H���_��I�����Ă�������";
	BrowsingInfo.ulFlags        = BIF_RETURNONLYFSDIRS;
	BrowsingInfo.lpfn           = &::BrowseCallbackProc;
	BrowsingInfo.lParam         = (LPARAM)path;
	ItemID = SHBrowseForFolder( &BrowsingInfo );
	SHGetPathFromIDList(ItemID, DirPath );
	GlobalFreePtr( ItemID );
	return (AnsiString)DirPath;
}
//---------------------------------------------------------------------------
// �t�H���_�I���_�C�A���O�pCallBack�֐�
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
// �X�V��->OnExit
void __fastcall TSettingForm::MotoPathEditExit(TObject *Sender)
{
	if (MotoPathEdit->Text == MotoPath)
		return;
	if (!DirectoryExists(MotoPathEdit->Text)){
		Application->MessageBox("�X�V����������܂���ł���", "�ݒ�ύX", MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	// �X�V�����ύX���ꂽ��A�ăZ�b�g
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
// �u�Ώہ̑ΏۊO�v�̈ړ�
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
// INIFILE �ǂݍ���
bool __fastcall TSettingForm::ReadKosinIni()
{
	std::auto_ptr<TIniFile> ini(new TIniFile(ExtractFilePath(Application->ExeName) + "\\Kosin.ini"));
	UseKosin = ini->ReadInteger("�X�V�ݒ�", "Use", 0);		// �X�V�@�\�g�p�敪
	MotoPath = ini->ReadString("�X�V�ݒ�", "MOTO", "");		// �R�s�[��
	SakiPath = ini->ReadString("�X�V�ݒ�", "SAKI", "");		// �R�s�[��
	GaiList = ini->ReadString("�X�V�ݒ�", "GaiList", "");		// �X�V�ΏۊO�t�@�C�����X�g
	SettingName = ini->ReadString("�X�V�ݒ�", "Setting", "");	// Ini�t�@�C��

	if (!DirectoryExists(SettingForm->MotoPath) || !DirectoryExists(SettingForm->SakiPath))
		return false;

	// �X�V����ݒ�
	FileListBox->Directory = SettingForm->MotoPath;

	// �ݒ�t�@�C���R���{�̈ꗗ���X�V
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
// INIFILE ��������
void __fastcall TSettingForm::SaveKosinIni()
{
	std::auto_ptr<TIniFile> ini(new TIniFile(ExtractFilePath(Application->ExeName) + "\\Kosin.ini"));
	if (UseKosin)
		ini->WriteInteger("�X�V�ݒ�", "Use", 1);		// �X�V�@�\�g�p�敪
	else
		ini->WriteInteger("�X�V�ݒ�", "Use", 0);		// �X�V�@�\�g�p�敪
	ini->WriteString("�X�V�ݒ�", "MOTO", MotoPath);		// �R�s�[��
	ini->WriteString("�X�V�ݒ�", "SAKI", SakiPath);		// �R�s�[��
	ini->WriteString("�X�V�ݒ�", "GaiList", GaiList);    	// �X�V�ΏۊO�t�@�C�����X�g
	ini->WriteString("�X�V�ݒ�", "Setting", SettingName);	// Ini�t�@�C��

	if (cbConnFile->Items->Strings[cbConnFile->ItemIndex] != MainForm->asConnName){
		std::auto_ptr<TIniFile> menu_ini(new TIniFile(ExtractFilePath(Application->ExeName) + "\\menu.ini"));
		menu_ini->WriteString("System", "Conn", cbConnFile->Items->Strings[cbConnFile->ItemIndex]);
	}
}
//---------------------------------------------------------------------------
// OK�{�^��
void __fastcall TSettingForm::OKButtonClick(TObject *Sender)
{
	UseKosin = rbUseKosin->Checked ? true : false;
	MainForm->KosinButton->Enabled = UseKosin;
	MotoPath = MotoPathEdit->Text;
	SakiPath = SakiPathEdit->Text;
	GaiList    = GaiListBox->Items->CommaText;
	SettingName  = cbSettingFile->Items->Strings[cbSettingFile->ItemIndex];

	// INIFILE ��������
	SaveKosinIni();

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
// �X�V�Ώۃt�@�C���̌���
std::auto_ptr<TStringList> __fastcall TSettingForm::CopySearch()
{
	std::auto_ptr<TStringList> Files(new TStringList());

	bool div_overwrite;	// �㏑���敪
	AnsiString FileName;
	TDateTime dt_moto, dt_saki;
	MainForm->StatusBar->Hint = "�X�V�ΏہF";

	if (!DirectoryExists(MotoPath) || !DirectoryExists(SakiPath))
		return Files;

	for (int i = 0; i < TaishoListBox->Items->Count; i++){
		FileName = TaishoListBox->Items->Strings[i];

		//if (FileName == IniName && !chOverwrite->Checked)
			//continue;
		if (FileExists((SakiPath + "\\" + FileName).c_str())){
			dt_moto = FileDateToDateTime(FileAge((MotoPath + "\\"+ FileName).c_str()));
			dt_saki = FileDateToDateTime(FileAge((SakiPath + "\\"+ FileName).c_str()));
			if (dt_moto == dt_saki)		// �X�V������������������Acontinue
				continue;
		}

		Files->Append(FileName);
		MainForm->StatusBar->Hint += " " + FileName;
	}

	return Files;
}
//---------------------------------------------------------------------------
// �ڑ���ݒ�ҏW�{�^��
void __fastcall TSettingForm::ConnEditButtonClick(TObject *Sender)
{
	ShellExecute(NULL, NULL, cbConnFile->Items->Strings[cbConnFile->ItemIndex].c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

