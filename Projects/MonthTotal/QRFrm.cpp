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
	lbl[0][0] = MonthLabel01;	lbl[0][1] = JuryoLabel01;	lbl[0][2] = KinLabel01;
	lbl[1][0] = MonthLabel02;	lbl[1][1] = JuryoLabel02;	lbl[1][2] = KinLabel02;
	lbl[2][0] = MonthLabel03;	lbl[2][1] = JuryoLabel03;	lbl[2][2] = KinLabel03;
	lbl[3][0] = MonthLabel04;	lbl[3][1] = JuryoLabel04;	lbl[3][2] = KinLabel04;
	lbl[4][0] = MonthLabel05;	lbl[4][1] = JuryoLabel05;	lbl[4][2] = KinLabel05;
	lbl[5][0] = MonthLabel06;	lbl[5][1] = JuryoLabel06;	lbl[5][2] = KinLabel06;
	lbl[6][0] = MonthLabel07;	lbl[6][1] = JuryoLabel07;	lbl[6][2] = KinLabel07;
	lbl[7][0] = MonthLabel08;	lbl[7][1] = JuryoLabel08;	lbl[7][2] = KinLabel08;
	lbl[8][0] = MonthLabel09;	lbl[8][1] = JuryoLabel09;	lbl[8][2] = KinLabel09;
	lbl[9][0] = MonthLabel10;	lbl[9][1] = JuryoLabel10;	lbl[9][2] = KinLabel10;
	lbl[10][0] = MonthLabel11;	lbl[10][1] = JuryoLabel11;	lbl[10][2] = KinLabel11;
	lbl[11][0] = MonthLabel12;	lbl[11][1] = JuryoLabel12;	lbl[11][2] = KinLabel12;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QuickRepBeforePrint(TCustomQuickRep *Sender,
      bool &PrintReport)
{
	// èâä˙âª
	int i, j;

	for (i = 0; i < 12; i++){
		lbl[i][0]->Caption = IncMonth(start_date, i).FormatString("yyyy'îN'mm'åé'");
		month[i] = IncMonth(start_date, i).FormatString("yyyymm").ToIntDef(0);

		for (j = 1; j < 3; j++)
			lbl[i][j]->Caption = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TQRForm::DetailBand1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	int i;

	for (i = 0; i < 12; i++){
		if (Query->Locate("îNåé", month[i], TLocateOptions())){
			lbl[i][1]->Caption = FormatFloat("#,##0", Query->FieldByName("ê≥ñ°èdó ")->AsCurrency); 
			lbl[i][2]->Caption = FormatFloat("#,##0", Query->FieldByName("ã‡äz")->AsCurrency); 
		}
	}
}
//---------------------------------------------------------------------------

