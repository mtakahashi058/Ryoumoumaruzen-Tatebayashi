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
// seikyu = 1 -> 請求データを作成する 0 -> しない
// hikae  = 1 -> 請求書               0 -> 請求書(控)
// print  = 1 -> 印刷                 0 -> プレビュー
int __fastcall TConfirmForm::ShowModalWith(int seikyu, int hikae, int print)
{
	seikyu_ = seikyu;
	hikae_  = hikae;
	print_  = print;

	CreateDataPanel->Caption = seikyu == 1 ? "請求データを作成する" : "請求データを作成しない";
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
	// 前回締切日チェック
	if (DM->Q_SimeCheck->RecordCount > 0){
		ChuiPanel->Visible = true;
		DBGridSimeCheck->Visible = true;
	}else{
		ChuiPanel->Visible = false;
		DBGridSimeCheck->Visible = false;
	}

	AnsiString mess = 	"※取引データから集計を行い、請求データを作成します。\r\n"
				"　（すでに作成したデータがある場合、データは一旦削除され、再集計されます。）";
	if (seikyu_ == 1)
		CreateDataEdit->Text = mess;
	else
		CreateDataEdit->Text = "請求データは編集されません";
}
//---------------------------------------------------------------------------

