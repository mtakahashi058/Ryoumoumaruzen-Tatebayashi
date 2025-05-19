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
	dt_label[0]  = DateLabel01;
	dt_label[1]  = DateLabel02;
	dt_label[2]  = DateLabel03;
	dt_label[3]  = DateLabel04;
	dt_label[4]  = DateLabel05;
	dt_label[5]  = DateLabel06;
	dt_label[6]  = DateLabel07;
	dt_label[7]  = DateLabel08;
	dt_label[8]  = DateLabel09;
	dt_label[9]  = DateLabel10;
	dt_label[10] = DateLabel11;
	dt_label[11] = DateLabel12;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QuickRepBeforePrint(TCustomQuickRep *Sender,
      bool &PrintReport)
{
	GroupHeaderBand->Height = 0;
	DetailBand1->Height = 659;
	GroupFooterBand->Height = 659;

	// “ú•t
	TDateTime dt = dt_from;
	for (int i = 0; i < 12; i++){
		dt_label[i]->Caption = dt.FormatString("yy'”N'mm'ŒŽ'");
		dt = IncMonth(dt, 1);
	}
}
//---------------------------------------------------------------------------

