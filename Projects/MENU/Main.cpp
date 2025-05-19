//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Mutex.h"

#include "DMFrm.h"
#include "SettingFrm.h"
#include "KosinListFrm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "CuteBtn"
//#pragma link "GradBox"
//#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner), Exec(false)
{
	ButtonTable[0] = cbtn1;
	ButtonTable[1] = cbtn2;
	ButtonTable[2] = cbtn3;
	ButtonTable[3] = cbtn4;
	ButtonTable[4] = cbtn5;
	ButtonTable[5] = cbtn6;
	ButtonTable[6] = cbtn7;
	ButtonTable[7] = cbtn8;
	ButtonTable[8] = cbtn9;
	ShiftButtonTable[0] = cbtnS1;
	ShiftButtonTable[1] = cbtnS2;
	ShiftButtonTable[2] = cbtnS3;
	ShiftButtonTable[3] = cbtnS4;
	ShiftButtonTable[4] = cbtnS5;
	ShiftButtonTable[5] = cbtnS6;
	ShiftButtonTable[6] = cbtnS7;
	ShiftButtonTable[7] = cbtnS8;
	ShiftButtonTable[8] = cbtnS9;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	// �f�[�^�x�[�X�ڑ�
	if (!DM->Init()){
		Close();
		return;
	}

	// �ݒ�t�@�C���ǂݍ��� �� �ǂݍ��� menu.ini ��ؑ�
	//DM->ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	int ini_no = ToInt(DM->ini_["Menu::No"]);
	ini_no = ini_no == 0 ? 1 : ini_no;

	Sections.clear();
	TabPages->Tabs->Clear();
	IniName = GetCurrentDir() + "\\menu" + FormatFloat("#", ini_no) + ".ini";

	if (!FileExists(IniName)){
		Application->MessageBox(("���j���[�ݒ�t�@�C����������܂���ł���\r\n�t�@�C�����F" + IniName).c_str(), "���j���[", MB_ICONEXCLAMATION);
		Close();
		return;
	}

	AnsiString s;
	TSection section;
	TStringList *SectList = new TStringList();
	TIniFile *IniFile = new TIniFile(IniName);

	Caption = "Scale Manager " + IniFile->ReadString("System", "Caption", "");
	LabelTitle->Caption = IniFile->ReadString("System", "Caption", "");
	SubTitleLabel->Caption = IniFile->ReadString("System", "SubTitle", "");
	nSpaceCount = IniFile->ReadInteger("System", "Space", 3);
	asConnName = IniFile->ReadString("System", "Conn", "");
	chofuku = IniFile->ReadInteger("System", "Chofuku", 0);

	OnLoadPath = IniFile->ReadString("System", "OnLoadPath", "");
	OnEndPath = IniFile->ReadString("System", "OnEndPath", "");

	// �}�X�^���̂��擾
	//DM->config_.Load(&DM->DBI);
	AnsiString toku_name, hin_name, komoku1_name, komoku2_name;
	toku_name    = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["���Ӑ�}�X�^����"]), "�@", ""), " ", "") + "�}�X�^";
	hin_name     = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]),   "�@", ""), " ", "") + "�}�X�^";
	komoku1_name = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["����1�}�X�^����"]),  "�@", ""), " ", "") + "�}�X�^";
	komoku2_name = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["����2�}�X�^����"]),  "�@", ""), " ", "") + "�}�X�^";

    if (!ToBit(DM->config_["���Ӑ�}�X�^�g�p�敪"]))
        toku_name    = AnsiString();
    if (!ToBit(DM->config_["�i�ڃ}�X�^�g�p�敪"]))
        hin_name     = AnsiString();
    if (!ToBit(DM->config_["����1�}�X�^�g�p�敪"]))
        komoku1_name = AnsiString();
    if (!ToBit(DM->config_["����2�}�X�^�g�p�敪"]))
        komoku2_name = AnsiString();


	// �����v�ʂ���Ȃ�
	bool auto_keiryo = ToInt(DM->ini_["Menu::Auto"]);

	IniFile->ReadSections(SectList);
	for (int j = 0; j < SectList->Count; j++){
		s = SectList->Strings[j];
		if (s == "System")
			continue;
		section.SectionName = s;
		for (int i = 1; i <= 9; i++){
			section.Paths[i - 1]         = IniFile->ReadString(s, "Path" + AnsiString(i), "");
			section.Captions[i - 1]      = AddSpace(IniFile->ReadString(s, "Name" + AnsiString(i), ""));
			section.ShiftPaths[i - 1]    = IniFile->ReadString(s, "SPath" + AnsiString(i), "");
			section.ShiftCaptions[i - 1] = AddSpace(IniFile->ReadString(s, "SName" + AnsiString(i), ""));

			// �����v�ʃ��O�{���ؑ�
			if (s == "���C�����j���[" && i == 1 && !auto_keiryo){
				section.ShiftPaths[i - 1]    = AnsiString();
				section.ShiftCaptions[i - 1] = AnsiString();
			}
			
			// �}�X�^���̂���������
			if (s == "�}�X�^�����e�i���X" && i == 1){
				section.Captions[i - 1] = AddSpace(toku_name);
                if (toku_name.IsEmpty())
                    section.Paths[i - 1] = AnsiString();
			}else if (s == "�}�X�^�����e�i���X" && i == 2){
				section.Captions[i - 1] = AddSpace(komoku1_name);
                if (komoku1_name.IsEmpty())
                    section.Paths[i - 1] = AnsiString();
			}else if (s == "�}�X�^�����e�i���X" && i == 3){
				section.Captions[i - 1] = AddSpace(komoku2_name);
                if (komoku2_name.IsEmpty())
                    section.Paths[i - 1] = AnsiString();
			}else if (s == "�}�X�^�����e�i���X" && i == 4){
				section.Captions[i - 1] = AddSpace(AnsiReplaceStr(hin_name, "�}�X�^", "���ރ}�X�^"));
			}else if (s == "�}�X�^�����e�i���X" && i == 5){
				section.Captions[i - 1] = AddSpace(hin_name);
                if (hin_name.IsEmpty())
                    section.Paths[i - 1] = AnsiString();
            }
		}
		Sections.push_back(section);
		TabPages->Tabs->Append(s);
	}

	delete IniFile;
	if (SectList->Count == 0){
		ShowMessage("�ǂݍ��ރZ�N�V������������܂���");
		PostMessage(Handle, WM_CLOSE, 0, 0);
	}

	delete SectList;
	TabPages->TabIndex = 0;
	TabPagesChange(NULL);
	if (OnLoadPath != "")
		AppExec(OnLoadPath);

	// �X�V���
	if (!SettingForm->ReadKosinIni())
		StatusBar->Panels->Items[2]->Text = "";
	SettingForm->SetIni2Form();
	KosinButton->Enabled = SettingForm->UseKosin;

	// �X�V�`�F�b�N
	if (SettingForm->UseKosin)
		CheckExistKosin();

	MainForm->Height = 730;
	MainForm->Width = 1024;
	MainForm->FormResize(NULL);
	Timer1->OnTimer(NULL);
}
//---------------------------------------------------------------------------
// �X�V�`�F�b�N
void __fastcall TMainForm::CheckExistKosin()
{
	// �X�V�Ώۃt�@�C���̌���
	int kensu = SettingForm->CopySearch()->Count;

/*	if (kensu == 0)
		KosinButton->Enabled = false;
	else
		KosinButton->Enabled = true;
*/
	if (kensu == 0){
		StatusBar->Panels->Items[2]->Text = "�X�V�Ώۃt�@�C���͂���܂���";
		StatusBar->Color = TColor(0x00D2FDD2);
	}else{
		StatusBar->Panels->Items[2]->Text = "�X�V�Ώۃt�@�C��������܂� " + FormatFloat("#,##0", kensu) + " / " + FormatFloat("#,##0", SettingForm->TaishoListBox->Items->Count) + " ��";
		StatusBar->Color = TColor(0x00E4DDFF);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
/*	int FWidth = GetSystemMetrics(SM_CYFULLSCREEN);
	if (FWidth > 800){
		Position = poScreenCenter;
	}else{
		WindowState = wsMaximized;
		Top = 0;
		Left = 0;
	}
*/
	//WideString ws = GetCurrentDir() + "\\menu.html";
	//CppWebBrowser->Navigate(ws);
}
//---------------------------------------------------------------------------
DWORD __fastcall TMainForm::AppExec(AnsiString ExeName, bool Wait)
{
	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;
	if (!CreateProcess(NULL, ExeName.c_str(), NULL, NULL, false,
			CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS,
			NULL, NULL, &stStartupInfo, &stProcessInfo))
		throw Exception("���s�Ɏ��s���܂���");
	if (Wait)
		WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	return stProcessInfo.dwProcessId;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::AddSpace(AnsiString str)
{
	// ���񂹂ɂ��邽�߂ɃX�y�[�X�𑫂�
	if (str == "")
		return str;
	for (int i = 0; i < nSpaceCount; i++)
		str = "�@" + str;
	while (str.Length() < 42){
		str = str + "�@";
	}
	return str;
}
//---------------------------------------------------------------------------
// Form->Close
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (Exec){
		if (Thread)
			Thread->Terminate();
		if (Thread)
			Thread->WaitFor();
		if (Thread)
			delete Thread;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FillPanel(int Index)
{
	if (Index < 0 || Index >int(Sections.size() - 1))
		throw Exception("�^�u�C���f�b�N�X���͈͂𒴂��Ă��܂�");

	for (int i = 1; i <= 9; i++){
		ButtonTable[i - 1]->Caption = Sections[Index].Captions[i - 1];
		ShiftButtonTable[i - 1]->Caption = Sections[Index].ShiftCaptions[i - 1];
	}
}
//---------------------------------------------------------------------------
// �v���O���������s����
void __fastcall TMainForm::Execute(int Index, bool Shift)
{
	AnsiString Path;
	TSection section = Sections[TabPages->TabIndex];

	if (Shift){
		Path = section.ShiftPaths[Index - 1];
	}else{
		Path = section.Paths[Index - 1];
	}

	if (Path == "")
		return;

	Path = LowerCase(Path);

    if (Path == "keiryo"){
        Path = AnsiString();
        int keiryo_div = ToInt(DM->config_["�P�i���i�敪"]);
        if (keiryo_div == 1)
            Path = "KeiryoS.exe";
        else if (keiryo_div == 2)
            Path = "KeiryoM.exe";
        if (Path.IsEmpty())
            return;
    }

	if (Path == "end"){
		if (OnEndPath != "")
			AppExec(OnEndPath);
		Close();

	}else if (Path == "shutdown"){
		ExitWindowsEx(EWX_SHUTDOWN, 0);

	}else if (Path.SubString(1, 3) == "go "){
		int SectNo;
		try{
			SectNo = StrToInt(Path.SubString(4, 2));
		}catch(EConvertError& e){
			ShowMessage("�����ȃZ�N�V�����C���f�b�N�X�ł�");
			return;
		}
		TabPages->TabIndex = SectNo - 1;
		TabPagesChange(NULL);
	}else{
		ProcessIterator it = process_map_.find(Path);
		if (it == process_map_.end()){
			if (Exec && !chofuku)
				return;

			// �N�����Ă�����
			// �����ŋN������
			STARTUPINFO stStartupInfo;
			PROCESS_INFORMATION stProcessInfo;

			ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
			ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
			stStartupInfo.cb = sizeof(STARTUPINFO);
			stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
			stStartupInfo.wShowWindow = SW_SHOWNORMAL;
			if (!CreateProcess(NULL, Path.c_str(), NULL, NULL, false,
					CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS,
					NULL, NULL, &stStartupInfo, &stProcessInfo)){
				return;
			}
			// �N��������A
			Exec = true;
			process_map_[Path] = stProcessInfo;

		}else{
			// ���łɋN�����Ȃ̂łȂɂ����Ȃ�
			//ShowMessage("�N����");
		}

		//Thread = new TExecThread(false, Path, Handle);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TabPagesChange(TObject *Sender)
{
	FillPanel(TabPages->TabIndex);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::cbtn1_Click(TObject *Sender)
{
	Tag = ((TComponent *)Sender)->Tag;
	if (Tag > 10){
		Tag %= 10;
		Execute(Tag, true);
	}
	else
		Execute(Tag, false);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	OldKey = Key;
	DownedTime = GetTickCount();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key != OldKey){
		return;
	}
	if ((GetTickCount() - DownedTime) > 1000)
		return;
	switch (Key){
	case VK_F1: Tag = 1; break;
	case VK_F2: Tag = 2; break;
	case VK_F3: Tag = 3; break;
	case VK_F4: Tag = 4; break;
	case VK_F5: Tag = 5; break;
	case VK_F6: Tag = 6; break;
	case VK_F7: Tag = 7; break;
	case VK_F8: Tag = 8; break;
	case VK_F9: Tag = 9; break;
	default:
		return;
	}
	if (Shift.Contains(ssShift))
		Execute(Tag, true);
	else
		Execute(Tag, false);//*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnExecTerminate(TMessage& Message)
{
	Exec = false;
	if (Thread)
		Thread->Terminate();
	if (Thread)
		Thread->WaitFor();
	if (Thread)
		delete Thread;
}
//---------------------------------------------------------------------------
// �v���O�������s�{�^��->OnClick
void __fastcall TMainForm::cbtn1Click(TObject *Sender)
{
	Tag = ((TComponent *)Sender)->Tag;
	if (Tag > 10){
		Tag %= 10;
		Execute(Tag, true);
	}
	else
		Execute(Tag, false);

	TabPages->SetFocus();
}
//---------------------------------------------------------------------------
// Timer �Ō��ݓ�����\������
void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	StatusBar->Panels->Items[0]->Text = "���ݓ����F " + Date().FormatString("yyyy-mm-dd") + " " + Time().FormatString("hh:nn");
}
//---------------------------------------------------------------------------
// Form->Resize
void __fastcall TMainForm::FormResize(TObject *Sender)
{
	if (TabPages->Tabs->Count >= 3)
		TabPages->TabWidth = (MainForm->Width - 30) / TabPages->Tabs->Count;
	else
		TabPages->TabWidth = 150;

/*	for (int i = 0; i < 9; i++){
		ButtonTable[i]->Left = MainForm->Width * 119 / 1024;
		ShiftButtonTable[i]->Left = MainForm->Width * 611 / 1024;
	}
*/
}
//---------------------------------------------------------------------------
// �ݒ�ύX�{�^��
void __fastcall TMainForm::SettingButtonClick(TObject *Sender)
{
	SettingForm->ShowModal();
}
//---------------------------------------------------------------------------
// �X�V�{�^��
void __fastcall TMainForm::KosinButtonClick(TObject *Sender)
{
	if (!DirectoryExists(SettingForm->MotoPath)){
		Application->MessageBox("�R�s�[���t�H���_��������Ȃ��������ߏ������J�n�ł��܂���ł���\r\n�l�b�g���[�N�̏�Ԃ��m�F���Ă�������", "�X�V�����J�n", MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	if (!DirectoryExists(SettingForm->SakiPath)){
		if (!ForceDirectories(SettingForm->SakiPath)){
			Application->MessageBox("�R�s�[��t�H���_�̍쐬�Ɏ��s���܂���", "�X�V�����J�n", MB_OK | MB_ICONEXCLAMATION);
			return;
		}
	}

	std::auto_ptr<TStringList> Files(new TStringList());
	Files = SettingForm->CopySearch();

	KosinListForm->KosinListBox->Items->Clear();
	for (int i = 0; i < Files->Count; i++)
		KosinListForm->KosinListBox->Items->Append(Files->Strings[i]);

	if (KosinListForm->ShowModal() != mrOk)
		return;

	StatusBar->Color = TColor(0x00AAF0F2);

	bool is_readonly;

	for (int i = 0; i < Files->Count; i++){
		// [ReadOnly]��������A[ReadOnly]���������� 
		int Attrs = FileGetAttr((SettingForm->MotoPath + "\\"+ Files->Strings[i]).c_str());
		if (Attrs & faReadOnly){
			is_readonly = true;
			if (FileExists(SettingForm->SakiPath + "\\"+ Files->Strings[i]))
				FileSetAttr((SettingForm->SakiPath + "\\"+ Files->Strings[i]).c_str(), Attrs & !faReadOnly);
		}else
			is_readonly = false;

		CopyFile((SettingForm->MotoPath + "\\"+ Files->Strings[i]).c_str(), (SettingForm->SakiPath + "\\"+ Files->Strings[i]).c_str(), false);
		StatusBar->Panels->Items[2]->Text = "�X�V��... " + FormatFloat("#,##0", i + 1) + " / " + FormatFloat("#,##0", Files->Count) + " " + Files->Strings[i];

		// [ReadOnly]���������ɖ߂�
		if (is_readonly)
			FileSetAttr((SettingForm->SakiPath + "\\"+ Files->Strings[i]).c_str(), Attrs);

		Application->ProcessMessages();
	}

	if (KosinListForm->chSettingFile->Checked){
		// �ݒ�t�@�C�����R�s�[����
		CopyFile((SettingForm->MotoPath + "\\"+ SettingForm->SettingName).c_str(), (SettingForm->SakiPath + "\\"+ SettingForm->SettingName).c_str(), false);
		StatusBar->Panels->Items[2]->Text = "�X�V��... �ݒ�t�@�C��";
		Application->ProcessMessages();
	}

	// �X�V���
	if (!SettingForm->ReadKosinIni())
		StatusBar->Panels->Items[2]->Text = "";
	SettingForm->SetIni2Form();

	// �X�V�`�F�b�N
	CheckExistKosin();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ProcessTimerTimer(TObject *Sender)
{
	for (ProcessIterator it = process_map_.begin(); it != process_map_.end(); it++){
		if (WaitForSingleObject(it->second.hProcess, 0) != WAIT_TIMEOUT){
			process_map_.erase(it);
		}
	}
}
//---------------------------------------------------------------------------

