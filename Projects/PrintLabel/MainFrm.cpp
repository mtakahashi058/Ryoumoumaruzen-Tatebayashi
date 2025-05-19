//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRLabelFrm.h"
#include "MainFrm.h"
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
	// �f�[�^�x�[�X�ڑ�
	DM->ADOConnection->Connected = false;
	try{
		DM->ADOConnection->Connected = true;
		DM->Q_List->Open();
	}catch (Exception& e){
		Application->MessageBox("�f�[�^�x�[�X�ڑ��Ɏ��s���܂����B", "�G���[", MB_OK | MB_ICONSTOP);
		Application->MessageBox(e.Message.c_str(), "�G���[", MB_OK | MB_ICONSTOP);
		Close();
	}

	TokuList = new TStringList();

	// �O���v���O��������p�����[�^�ďo
	if (ParamCount() > 0)
		TokuList->CommaText = ParamStr(1);

	CheckListBox->Items->Clear();
	while (!DM->Q_List->Eof){
		CheckListBox->Items->Append(DM->Q_List->FieldByName("�Œ蒷�R�[�h����")->AsString);
		if (TokuList->IndexOf(DM->Q_List->FieldByName("�R�[�h")->AsString) != -1)	// �p�����[�^�Ƃ��ēn���ꂽ���ɊY���R�[�h����������`�F�b�N������
			CheckListBox->Checked[CheckListBox->Items->Count - 1] = true;
		DM->Q_List->Next();
	}

	cedtCode->Text = "";
	cedtCode->SetFocus();
}
//---------------------------------------------------------------------------
// ���
void __fastcall TMainForm::btnPrintClick(TObject *Sender)
{
	if (!SetRange())
		return;
	if (Application->MessageBox("���x���p�����Z�b�g���ĉ�����\r\n�������ł�����uOK�v�������ĉ�����", "���x�����", MB_OKCANCEL | MB_ICONINFORMATION) != IDOK)
		return;
	QRLabelForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
// �v���r���[
void __fastcall TMainForm::btnPreviewClick(TObject *Sender)
{
	if (!SetRange())
		return;
	QRLabelForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
// �ꎞ�e�[�u�����Z�b�g
bool __fastcall TMainForm::SetRange()
{
	QRLabelForm->Q_Label->Close();

	// �ꎞ�e�[�u���폜
	try{
		DM->DBI.Execute("DROP TABLE #LABEL");
	}catch (...){
	}

	// �ꎞ�e�[�u�����쐬
	if (TokuList->CommaText == AnsiString()){
		Application->MessageBox("�o�͂��链�Ӑ��I�����Ă�������", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
	DM->Q_CreateLabel->SQL->Strings[12] = "	���Ӑ�R�[�h IN (" + TokuList->CommaText + ")";
	DM->Q_CreateLabel->ExecSQL();

	// �󎚊J�n�ʒu
	int add_cnt = cbRetu->ItemIndex * 7 + cbGyo->ItemIndex;
	for (int i = 0; i < add_cnt; i++)
		DM->DBI.Execute("INSERT INTO #LABEL VALUES(0, NULL, NULL, NULL, NULL, NULL)"); 

	QRLabelForm->Q_Label->Open();

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnCloseClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
// �`�F�b�N���X�g�{�b�N�X->OnClick
void __fastcall TMainForm::CheckListBoxClick(TObject *Sender)
{
	if (CheckListBox->Checked[CheckListBox->ItemIndex])
		TokuList->Append(CheckListBox->Items->Strings[CheckListBox->ItemIndex].SubString(1, 5).Trim());
	else{
		try{
			TokuList->Delete(TokuList->IndexOf(CheckListBox->Items->Strings[CheckListBox->ItemIndex].SubString(1, 5).Trim()));
		}catch (...){
		}
	}
}
//---------------------------------------------------------------------------
// ���ׂđI��
void __fastcall TMainForm::btnAllClick(TObject *Sender)
{
	for (int i = 0; i < CheckListBox->Items->Count; i++)
		CheckListBox->Checked[i] = true;

	TokuList->Clear();
	DM->Q_List->First();
	while (!DM->Q_List->Eof){
		TokuList->Append(DM->Q_List->FieldByName("�R�[�h")->AsString);
		DM->Q_List->Next();
	}
}
//---------------------------------------------------------------------------
// ���ׂđI������
void __fastcall TMainForm::btnNoneClick(TObject *Sender)
{
	for (int i = 0; i < CheckListBox->Items->Count; i++)
		CheckListBox->Checked[i] = false;

	TokuList->Clear();
}
//---------------------------------------------------------------------------
// �R�[�h����
void __fastcall TMainForm::cedtCodeKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	if (!DM->Q_List->Locate("�R�[�h", cedtCode->Text.ToIntDef(0), TLocateOptions())){
		cedtCode->SetFocus();
		return;
	}
	CheckListBox->ItemIndex = CheckListBox->Items->IndexOf(DM->Q_List->FieldByName("�Œ蒷�R�[�h����")->AsString);
	CheckListBox->Checked[CheckListBox->ItemIndex] = true;
	CheckListBox->OnClick(CheckListBox);

	cedtCode->Text = AnsiString();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_F9)
		btnPrint->OnClick(NULL);
	else if (Key == VK_F10)
		btnPreview->OnClick(NULL);
	else if (Key == VK_F12)
		btnClose->OnClick(NULL);
}
//---------------------------------------------------------------------------

