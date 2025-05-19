//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SettingFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "CEdit"
#pragma resource "*.dfm"
TSettingForm *SettingForm;
//---------------------------------------------------------------------------
__fastcall TSettingForm::TSettingForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::LoadSetting()
{
	// 設定を画面に反映
	LocalFolderEdit->Text = ToString(DM->INI["Send::LocalReceiveFolder"]);
	ServerNameEdit->Text  = ToString(DM->INI["Send::ServerName"]);
	PortEdit->Text        = ToString(DM->INI["Send::Port"]);
	UserEdit->Text        = ToString(DM->INI["Send::User"]);
	PasswordEdit->Text    = ToString(DM->INI["Send::Password"]);
	ServerPathEdit->Text  = ToString(DM->INI["Send::ServerReceivePath"]);

	AnsiString server = "open " + ServerNameEdit->Text;
	if (PortEdit->Text.ToIntDef(0) != 0)
		server += " " + IntToStr(PortEdit->Text.ToIntDef(0));
	AnsiString cd = AnsiString();
	if (ServerPathEdit->Text != AnsiString())
		cd = "cd " + ServerPathEdit->Text;

	std::auto_ptr<TStringList> ftpcmd_list(new TStringList());		// すべてのデータを入れるための"StringList"
	ftpcmd_list->Append(server);
	ftpcmd_list->Append(UserEdit->Text);
	ftpcmd_list->Append(PasswordEdit->Text);
	ftpcmd_list->Append(cd);
	ftpcmd_list->Append("mget *.CSV");
	ftpcmd_list->Append("quit");
	ftpcmd_list->SaveToFile(ExtractFilePath(Application->ExeName) + "Receive\\ftp_receive.ftp");
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::SaveButtonClick(TObject *Sender)
{
	if (Application->MessageBox("保存しますか？", "保存", MB_ICONQUESTION | MB_YESNO) != IDYES)
		return;
	DM->INI["Send::LocalReceiveFolder"] = LocalFolderEdit->Text;
	DM->INI["Send::ServerName"] = ServerNameEdit->Text;
	DM->INI["Send::Port"] = PortEdit->Text;
	DM->INI["Send::User"] = UserEdit->Text;
	DM->INI["Send::Password"] = PasswordEdit->Text;
	DM->INI["Send::ServerReceivePath"] = ServerPathEdit->Text;
	DM->INI.Save();
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::CancelButtonClick(TObject *Sender)
{
	// キャンセル
	LoadSetting();
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

