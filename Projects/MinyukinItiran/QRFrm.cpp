//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include "QRFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRForm *QRForm;
//---------------------------------------------------------------------------
__fastcall TQRForm::TQRForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::DetailBand1BeforePrint(TQRCustomBand *Sender,
	  bool &PrintBand)
{
	if (Query->FieldByName("“ü‹à—\’è“ú")->AsInteger > DateToInt(Date())){
		// –¢—ˆ‚Ì“ü‹à—\’è“ú‚Ìê‡AƒOƒŒ[•\Ž¦
		QRDBText01->Font->Color = clMedGray;
		QRDBText02->Font->Color = clMedGray;
		QRDBText04->Font->Color = clMedGray;
		QRDBText05->Font->Color = clMedGray;
		QRDBText06->Font->Color = clMedGray;
		QRShape01->Pen->Color   = clMedGray;
		QRShape02->Pen->Color   = clMedGray;
	}else{
		QRDBText01->Font->Color = clWindowText;
		QRDBText02->Font->Color = clWindowText;
		QRDBText04->Font->Color = clWindowText;
		QRDBText05->Font->Color = clWindowText;
		QRDBText06->Font->Color = clWindowText;
		QRShape01->Pen->Color   = clBlack;
		QRShape02->Pen->Color   = clBlack;
	}
}
//---------------------------------------------------------------------------

