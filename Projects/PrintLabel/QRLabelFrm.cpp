//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRLabelFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRLabelForm *QRLabelForm;
//---------------------------------------------------------------------------
__fastcall TQRLabelForm::TQRLabelForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQRLabelForm::DetailBand1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	AnsiString name = Q_Label->FieldByName("–¼Ì")->AsString;

	if (name.Length() > 38){
		if (!name.IsLeadByte(38)){
			TokuName1->Caption = name.SubString(1, 38);
			TokuName2->Caption = name.SubString(39, 30);
		}else{
			TokuName1->Caption = name.SubString(1, 37);
			TokuName2->Caption = name.SubString(38, 30);
		}
	}else{
		TokuName1->Caption = name;
		TokuName2->Caption = "";
	}

	lblYubin->Enabled = Q_Label->FieldByName("ƒR[ƒh")->AsInteger != 0 ? true : false;
}
//---------------------------------------------------------------------------

