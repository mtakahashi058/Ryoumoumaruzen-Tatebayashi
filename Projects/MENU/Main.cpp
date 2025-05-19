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
	// データベース接続
	if (!DM->Init()){
		Close();
		return;
	}

	// 設定ファイル読み込み ⇒ 読み込む menu.ini を切替
	//DM->ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	int ini_no = ToInt(DM->ini_["Menu::No"]);
	ini_no = ini_no == 0 ? 1 : ini_no;

	Sections.clear();
	TabPages->Tabs->Clear();
	IniName = GetCurrentDir() + "\\menu" + FormatFloat("#", ini_no) + ".ini";

	if (!FileExists(IniName)){
		Application->MessageBox(("メニュー設定ファイルが見つかりませんでした\r\nファイル名：" + IniName).c_str(), "メニュー", MB_ICONEXCLAMATION);
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

	// マスタ名称を取得
	//DM->config_.Load(&DM->DBI);
	AnsiString toku_name, hin_name, komoku1_name, komoku2_name;
	toku_name    = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["得意先マスタ名称"]), "　", ""), " ", "") + "マスタ";
	hin_name     = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]),   "　", ""), " ", "") + "マスタ";
	komoku1_name = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["項目1マスタ名称"]),  "　", ""), " ", "") + "マスタ";
	komoku2_name = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->config_["項目2マスタ名称"]),  "　", ""), " ", "") + "マスタ";

    if (!ToBit(DM->config_["得意先マスタ使用区分"]))
        toku_name    = AnsiString();
    if (!ToBit(DM->config_["品目マスタ使用区分"]))
        hin_name     = AnsiString();
    if (!ToBit(DM->config_["項目1マスタ使用区分"]))
        komoku1_name = AnsiString();
    if (!ToBit(DM->config_["項目2マスタ使用区分"]))
        komoku2_name = AnsiString();


	// 自動計量ありなし
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

			// 自動計量ログ閲覧切替
			if (s == "メインメニュー" && i == 1 && !auto_keiryo){
				section.ShiftPaths[i - 1]    = AnsiString();
				section.ShiftCaptions[i - 1] = AnsiString();
			}
			
			// マスタ名称を書き換え
			if (s == "マスタメンテナンス" && i == 1){
				section.Captions[i - 1] = AddSpace(toku_name);
                if (toku_name.IsEmpty())
                    section.Paths[i - 1] = AnsiString();
			}else if (s == "マスタメンテナンス" && i == 2){
				section.Captions[i - 1] = AddSpace(komoku1_name);
                if (komoku1_name.IsEmpty())
                    section.Paths[i - 1] = AnsiString();
			}else if (s == "マスタメンテナンス" && i == 3){
				section.Captions[i - 1] = AddSpace(komoku2_name);
                if (komoku2_name.IsEmpty())
                    section.Paths[i - 1] = AnsiString();
			}else if (s == "マスタメンテナンス" && i == 4){
				section.Captions[i - 1] = AddSpace(AnsiReplaceStr(hin_name, "マスタ", "分類マスタ"));
			}else if (s == "マスタメンテナンス" && i == 5){
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
		ShowMessage("読み込むセクションが見つかりません");
		PostMessage(Handle, WM_CLOSE, 0, 0);
	}

	delete SectList;
	TabPages->TabIndex = 0;
	TabPagesChange(NULL);
	if (OnLoadPath != "")
		AppExec(OnLoadPath);

	// 更新情報
	if (!SettingForm->ReadKosinIni())
		StatusBar->Panels->Items[2]->Text = "";
	SettingForm->SetIni2Form();
	KosinButton->Enabled = SettingForm->UseKosin;

	// 更新チェック
	if (SettingForm->UseKosin)
		CheckExistKosin();

	MainForm->Height = 730;
	MainForm->Width = 1024;
	MainForm->FormResize(NULL);
	Timer1->OnTimer(NULL);
}
//---------------------------------------------------------------------------
// 更新チェック
void __fastcall TMainForm::CheckExistKosin()
{
	// 更新対象ファイルの検索
	int kensu = SettingForm->CopySearch()->Count;

/*	if (kensu == 0)
		KosinButton->Enabled = false;
	else
		KosinButton->Enabled = true;
*/
	if (kensu == 0){
		StatusBar->Panels->Items[2]->Text = "更新対象ファイルはありません";
		StatusBar->Color = TColor(0x00D2FDD2);
	}else{
		StatusBar->Panels->Items[2]->Text = "更新対象ファイルがあります " + FormatFloat("#,##0", kensu) + " / " + FormatFloat("#,##0", SettingForm->TaishoListBox->Items->Count) + " 件";
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
		throw Exception("実行に失敗しました");
	if (Wait)
		WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	return stProcessInfo.dwProcessId;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::AddSpace(AnsiString str)
{
	// 左寄せにするためにスペースを足す
	if (str == "")
		return str;
	for (int i = 0; i < nSpaceCount; i++)
		str = "　" + str;
	while (str.Length() < 42){
		str = str + "　";
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
		throw Exception("タブインデックスが範囲を超えています");

	for (int i = 1; i <= 9; i++){
		ButtonTable[i - 1]->Caption = Sections[Index].Captions[i - 1];
		ShiftButtonTable[i - 1]->Caption = Sections[Index].ShiftCaptions[i - 1];
	}
}
//---------------------------------------------------------------------------
// プログラムを実行する
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
        int keiryo_div = ToInt(DM->config_["単品多段区分"]);
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
			ShowMessage("無効なセクションインデックスです");
			return;
		}
		TabPages->TabIndex = SectNo - 1;
		TabPagesChange(NULL);
	}else{
		ProcessIterator it = process_map_.find(Path);
		if (it == process_map_.end()){
			if (Exec && !chofuku)
				return;

			// 起動していいよ
			// ここで起動する
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
			// 起動したら、
			Exec = true;
			process_map_[Path] = stProcessInfo;

		}else{
			// すでに起動中なのでなにもしない
			//ShowMessage("起動中");
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
// プログラム実行ボタン->OnClick
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
// Timer で現在日時を表示する
void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	StatusBar->Panels->Items[0]->Text = "現在日時： " + Date().FormatString("yyyy-mm-dd") + " " + Time().FormatString("hh:nn");
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
// 設定変更ボタン
void __fastcall TMainForm::SettingButtonClick(TObject *Sender)
{
	SettingForm->ShowModal();
}
//---------------------------------------------------------------------------
// 更新ボタン
void __fastcall TMainForm::KosinButtonClick(TObject *Sender)
{
	if (!DirectoryExists(SettingForm->MotoPath)){
		Application->MessageBox("コピー元フォルダが見つからなかったため処理を開始できませんでした\r\nネットワークの状態を確認してください", "更新処理開始", MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	if (!DirectoryExists(SettingForm->SakiPath)){
		if (!ForceDirectories(SettingForm->SakiPath)){
			Application->MessageBox("コピー先フォルダの作成に失敗しました", "更新処理開始", MB_OK | MB_ICONEXCLAMATION);
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
		// [ReadOnly]だったら、[ReadOnly]を解除する 
		int Attrs = FileGetAttr((SettingForm->MotoPath + "\\"+ Files->Strings[i]).c_str());
		if (Attrs & faReadOnly){
			is_readonly = true;
			if (FileExists(SettingForm->SakiPath + "\\"+ Files->Strings[i]))
				FileSetAttr((SettingForm->SakiPath + "\\"+ Files->Strings[i]).c_str(), Attrs & !faReadOnly);
		}else
			is_readonly = false;

		CopyFile((SettingForm->MotoPath + "\\"+ Files->Strings[i]).c_str(), (SettingForm->SakiPath + "\\"+ Files->Strings[i]).c_str(), false);
		StatusBar->Panels->Items[2]->Text = "更新中... " + FormatFloat("#,##0", i + 1) + " / " + FormatFloat("#,##0", Files->Count) + " " + Files->Strings[i];

		// [ReadOnly]属性を元に戻す
		if (is_readonly)
			FileSetAttr((SettingForm->SakiPath + "\\"+ Files->Strings[i]).c_str(), Attrs);

		Application->ProcessMessages();
	}

	if (KosinListForm->chSettingFile->Checked){
		// 設定ファイルをコピーする
		CopyFile((SettingForm->MotoPath + "\\"+ SettingForm->SettingName).c_str(), (SettingForm->SakiPath + "\\"+ SettingForm->SettingName).c_str(), false);
		StatusBar->Panels->Items[2]->Text = "更新中... 設定ファイル";
		Application->ProcessMessages();
	}

	// 更新情報
	if (!SettingForm->ReadKosinIni())
		StatusBar->Panels->Items[2]->Text = "";
	SettingForm->SetIni2Form();

	// 更新チェック
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

