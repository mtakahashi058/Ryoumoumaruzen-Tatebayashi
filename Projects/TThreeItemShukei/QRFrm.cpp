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
    TaniGroupHeaderBand->Height = 0;    
}
//---------------------------------------------------------------------------

