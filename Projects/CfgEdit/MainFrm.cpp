//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include <IniFiles.hpp>
#include <memory>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
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
	Application->OnMessage = this->MessageProc;

	AnsiString file_name = ExtractFilePath(Application->ExeName) + "settings.ini";
	std::auto_ptr<TIniFile> ini(new TIniFile(file_name));

	DM->ADOConnection->Connected = false;
	DM->ADOConnection->ConnectionString = "FILE NAME=" + ini->ReadString("ADO", "UDL", "");
	try{
		DM->ADOConnection->Connected = true;
		ConfigTable->Open();
	}catch (Exception &e){
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		Close();
        return;
	}

	DM->ADOConnection->BeginTrans();

	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT ���ޖ� FROM M_���� GROUP BY ���ޖ� ORDER BY ���ޖ�", set);
	TabControl->Tabs->Clear();
	for (NsRecordSet::iterator i = set.begin(); i != set.end(); i++){
		TabControl->Tabs->Append((i->second)["���ޖ�"]);
	}
	TabControl->Tabs->Append("�S��");

	InfoBlankPanel->Height = TabControl->TabHeight;

	TabControlChange(TabControl);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (!DM->ADOConnection->Connected)
        return;

	DM->ADOConnection->RollbackTrans();

	ConfigTable->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	switch(Msg.message){
		case WM_MOUSEWHEEL:
		if(Msg.hwnd == DBGrid->Handle){
			if((short)HIWORD(Msg.wParam) > 0){
				DBGrid->DataSource->DataSet->Prior();
			}else{
				DBGrid->DataSource->DataSet->Next();
			}
			Handled = true;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TabControlChanging(TObject *Sender,
	  bool &AllowChange)
{
	ConfigTable->Cancel();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TabControlChange(TObject *Sender)
{
	AnsiString tab = TabControl->Tabs->Strings[TabControl->TabIndex];

	if (tab == "�S��"){
		ConfigTable->Filtered = false;
		DBGrid->Columns->Items[0]->Visible = true;
	}else{
		ConfigTable->Filter   = "���ޖ� = '" + tab + "'";
		ConfigTable->Filtered = true;
		DBGrid->Columns->Items[0]->Visible = false;
	}
	ConfigTable->FindFirst();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ConfigTableAfterInsert(TDataSet *DataSet)
{
	DataSet->Cancel();

	/*
	AnsiString tab = TabControl->Tabs->Strings[TabControl->TabIndex];

	DataSet->FieldByName("���ޖ�")->AsString = tab;
	*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ConfigTableAfterScroll(TDataSet *DataSet)
{
	InfoLabelPanel->Caption = DataSet->FieldByName("�ݒ薼")->AsString;

	AnsiString desc         = DataSet->FieldByName("����")->AsString;
	desc = AnsiReplaceStr(desc, "�@", "\r\n");

	InfoMemo->Lines->Text   = desc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGridKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key == VK_RETURN){
		// �Ō�̗�ōX�V�\��������u�o�^���܂����H�v
		if (DBGrid->SelectedIndex == DBGrid->FieldCount - 1){
			if (DBGrid->DataSource->DataSet->State == dsInsert || DBGrid->DataSource->DataSet->State == dsEdit){
				if (Application->MessageBox("�o�^���܂����H", "�o�^", MB_YESNO | MB_ICONQUESTION) != IDYES){
					Key = NULL;
					return;
				}
				DBGrid->DataSource->DataSet->Post();
			}
			DBGrid->DataSource->DataSet->Next();
			DBGrid->SelectedIndex = DBGrid->Columns->Items[2]->Index;
		}else{
			DBGrid->SelectedIndex++;
		}
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SaveButtonClick(TObject *Sender)
{
	if (Application->MessageBox("�ݒ��K�p���Ă�낵���ł����H",
			Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
		return;

	if (DBGrid->DataSource->DataSet->State == dsInsert || DBGrid->DataSource->DataSet->State == dsEdit)
        DBGrid->DataSource->DataSet->Post();

	DM->ADOConnection->CommitTrans();

    Application->MessageBox("�ݒ��K�p���܂���\r\n�v���O�����i���j���[�܂ށj���N�����Ă���ꍇ�͍ċN�����Ă�������", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	DM->ADOConnection->BeginTrans();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

