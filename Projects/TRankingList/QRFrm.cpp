//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
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
void __fastcall TQRForm::QuickRepBeforePrint(TCustomQuickRep *Sender,
      bool &PrintReport)
{
	rank = 1;	
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::DetailBand1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	lblRank->Caption = rank++;	
}
//---------------------------------------------------------------------------

