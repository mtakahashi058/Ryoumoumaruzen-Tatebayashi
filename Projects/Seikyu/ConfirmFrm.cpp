//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "ConfirmFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfirmForm *ConfirmForm;
//---------------------------------------------------------------------------
__fastcall TConfirmForm::TConfirmForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// seikyu = 1 -> �����f�[�^���쐬���� 0 -> ���Ȃ�
// hikae  = 1 -> ������               0 -> ������(�T)
// print  = 1 -> ���                 0 -> �v���r���[
int __fastcall TConfirmForm::ShowModalWith(int seikyu, int hikae, int print)
{
	seikyu_ = seikyu;
	hikae_  = hikae;
	print_  = print;

	CreateDataPanel->Caption = seikyu == 1 ? "�����f�[�^���쐬����" : "�����f�[�^���쐬���Ȃ�";
	CreateDataPanel->Color   = seikyu == 1 ? TColor(0x00DB6D00) : TColor(0x00A4A4A4);
	CreateDataEdit->Color    = seikyu == 1 ? TColor(0x00D8D1FE) : TColor(0x00E1E1E1);
	SeikyuPanel->Color       = hikae == 1  ? TColor(0x00DB6D00) : TColor(0x00A4A4A4);
	HikaePanel->Color        = hikae == 1  ? TColor(0x00A4A4A4) : TColor(0x00DB6D00);
	PrintPanel->Color        = print       ? TColor(0x00DB6D00) : TColor(0x00A4A4A4);
	PreviewPanel->Color      = print       ? TColor(0x00A4A4A4) : TColor(0x00DB6D00);

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TConfirmForm::FormShow(TObject *Sender)
{
	// �O����ؓ��`�F�b�N
	if (DM->Q_SimeCheck->RecordCount > 0){
		ChuiPanel->Visible = true;
		DBGridSimeCheck->Visible = true;
	}else{
		ChuiPanel->Visible = false;
		DBGridSimeCheck->Visible = false;
	}

	AnsiString mess = 	"������f�[�^����W�v���s���A�����f�[�^���쐬���܂��B\r\n"
				"�@�i���łɍ쐬�����f�[�^������ꍇ�A�f�[�^�͈�U�폜����A�ďW�v����܂��B�j";
	if (seikyu_ == 1)
		CreateDataEdit->Text = mess;
	else
		CreateDataEdit->Text = "�����f�[�^�͕ҏW����܂���";
}
//---------------------------------------------------------------------------

