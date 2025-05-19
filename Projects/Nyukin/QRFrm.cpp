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
void __fastcall TQRForm::DetailBandBeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	if (DM->Q_Itiran->FieldByName("ŽèŒ`")->AsCurrency == 0)
		TegataText->Enabled = false;
	else
		TegataText->Enabled = true;
}
//---------------------------------------------------------------------------

