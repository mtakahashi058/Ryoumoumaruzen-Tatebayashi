//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SettingFrm.h"
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
void __fastcall TSettingForm::LoadSetting()
{
	// 設定を画面に反映
	AnsiString send_list   = ToString(DM->INI["Send::SendList"]);
	AnsiString ignore_list = ToString(DM->INI["Send::IgnoreList"]);

	if (send_list == AnsiString() && ignore_list == AnsiString())
		ignore_list = "D_計量,D_取引,M_伝票情報,M_伝票情報関連,M_制御,M_区分,M_単位,M_単価,M_品目,M_品目分類,M_得意先,M_拠点,M_換算,M_消費税,M_車両,M_銀行,M_項目1,M_項目2,M_項目関連";

	SendListBox->Items->CommaText   = send_list;
	IgnoreListBox->Items->CommaText = ignore_list;

	LocalFolderEdit->Text = ToString(DM->INI["Send::LocalSendFolder"]);
	ServerNameEdit->Text  = ToString(DM->INI["Send::ServerName"]);
	PortEdit->Text        = ToString(DM->INI["Send::Port"]);
	UserEdit->Text        = ToString(DM->INI["Send::User"]);
	PasswordEdit->Text    = ToString(DM->INI["Send::Password"]);
	ServerPathEdit->Text  = ToString(DM->INI["Send::ServerSendPath"]);

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
	ftpcmd_list->Append("mdel *.CSV");
	ftpcmd_list->Append("mput ExportTables.CSV");
	ftpcmd_list->Append("mput " + AnsiReplaceStr(SendListBox->Items->CommaText, ",", ".CSV ") + ".CSV");
	ftpcmd_list->Append("quit");
	ftpcmd_list->SaveToFile(ExtractFilePath(Application->ExeName) + "Send\\ftp_send.ftp");
}
//---------------------------------------------------------------------------
void __fastcall TSettingForm::SaveButtonClick(TObject *Sender)
{
	if (Application->MessageBox("保存しますか？", "保存", MB_ICONQUESTION | MB_YESNO) != IDYES)
		return;
	DM->INI["Send::SendList"]   = SendListBox->Items->CommaText;
	DM->INI["Send::IgnoreList"] = IgnoreListBox->Items->CommaText;
	DM->INI["Send::LocalSendFolder"] = LocalFolderEdit->Text;
	DM->INI["Send::ServerName"] = ServerNameEdit->Text;
	DM->INI["Send::Port"] = PortEdit->Text;
	DM->INI["Send::User"] = UserEdit->Text;
	DM->INI["Send::Password"] = PasswordEdit->Text;
	DM->INI["Send::ServerSendPath"] = ServerPathEdit->Text;
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
// <<< すべて送信する
void __fastcall TSettingForm::AllSendButtonClick(TObject *Sender)
{
	int cnt = IgnoreListBox->Count;
	for (int i = 0; i < cnt; i++){
		SendListBox->Items->Add(IgnoreListBox->Items->Strings[0]);
		IgnoreListBox->Items->Delete(0);
	}
}
//---------------------------------------------------------------------------
// >>> すべて送信しない
void __fastcall TSettingForm::AllIgnoreButtonClick(TObject *Sender)
{
	int cnt = SendListBox->Count;
	for (int i = 0; i < cnt; i++){
		IgnoreListBox->Items->Add(SendListBox->Items->Strings[0]);
		SendListBox->Items->Delete(0);
	}
}
//---------------------------------------------------------------------------
// < 選択したテーブルを送信する
void __fastcall TSettingForm::SelectedSendButtonClick(TObject *Sender)
{
	if (IgnoreListBox->ItemIndex < 0){
		IgnoreListBox->ItemIndex = 0;
		return;
	}
	SendListBox->Items->Add(IgnoreListBox->Items->Strings[IgnoreListBox->ItemIndex]);
	IgnoreListBox->Items->Delete(IgnoreListBox->ItemIndex);
}
//---------------------------------------------------------------------------
// > 選択したテーブルを送信しない
void __fastcall TSettingForm::SelectedIgnoreButtonClick(TObject *Sender)
{
	if (SendListBox->ItemIndex < 0){
		SendListBox->ItemIndex = 0;
		return;
	}
	IgnoreListBox->Items->Add(SendListBox->Items->Strings[SendListBox->ItemIndex]);
	SendListBox->Items->Delete(SendListBox->ItemIndex);
}
//---------------------------------------------------------------------------
