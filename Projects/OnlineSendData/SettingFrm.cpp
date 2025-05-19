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
	// �ݒ����ʂɔ��f
	AnsiString send_list   = ToString(DM->INI["Send::SendList"]);
	AnsiString ignore_list = ToString(DM->INI["Send::IgnoreList"]);

	if (send_list == AnsiString() && ignore_list == AnsiString())
		ignore_list = "D_�v��,D_���,M_�`�[���,M_�`�[���֘A,M_����,M_�敪,M_�P��,M_�P��,M_�i��,M_�i�ڕ���,M_���Ӑ�,M_���_,M_���Z,M_�����,M_�ԗ�,M_��s,M_����1,M_����2,M_���ڊ֘A";

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

	std::auto_ptr<TStringList> ftpcmd_list(new TStringList());		// ���ׂẴf�[�^�����邽�߂�"StringList"
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
	if (Application->MessageBox("�ۑ����܂����H", "�ۑ�", MB_ICONQUESTION | MB_YESNO) != IDYES)
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
	// �L�����Z��
	LoadSetting();
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
// <<< ���ׂđ��M����
void __fastcall TSettingForm::AllSendButtonClick(TObject *Sender)
{
	int cnt = IgnoreListBox->Count;
	for (int i = 0; i < cnt; i++){
		SendListBox->Items->Add(IgnoreListBox->Items->Strings[0]);
		IgnoreListBox->Items->Delete(0);
	}
}
//---------------------------------------------------------------------------
// >>> ���ׂđ��M���Ȃ�
void __fastcall TSettingForm::AllIgnoreButtonClick(TObject *Sender)
{
	int cnt = SendListBox->Count;
	for (int i = 0; i < cnt; i++){
		IgnoreListBox->Items->Add(SendListBox->Items->Strings[0]);
		SendListBox->Items->Delete(0);
	}
}
//---------------------------------------------------------------------------
// < �I�������e�[�u���𑗐M����
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
// > �I�������e�[�u���𑗐M���Ȃ�
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
