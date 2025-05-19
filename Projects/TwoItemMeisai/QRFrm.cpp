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
	: TForm(Owner), old_item1_(0), old_item2_(0), old_date_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QuickRepBeforePrint(TCustomQuickRep *Sender,
	  bool &PrintReport)
{
	Item1GroupHeaderBand->Height = 0;
	Item2GroupHeaderBand->Height = 0;

	old_item1_ = 0;
	old_item2_ = 0;
	old_date_  = 0;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::DetailBandBeforePrint(TQRCustomBand *Sender,
	  bool &PrintBand)
{
	if (old_item1_ != Query->FieldByName("項目コード1")->AsInteger){
		Item1CodeText->Enabled = true;
		Item1NameText->Enabled = true;
		Item2CodeText->Enabled = true;
		Item2NameText->Enabled = true;
		DateText->Enabled = true;
	}else{
		Item1CodeText->Enabled = false;
		Item1NameText->Enabled = false;
		if (old_item2_ != Query->FieldByName("項目コード2")->AsInteger){
			Item2CodeText->Enabled = true;
			Item2NameText->Enabled = true;
			DateText->Enabled = true;
		}else{
			Item2CodeText->Enabled = false;
			Item2NameText->Enabled = false;
			DateText->Enabled = old_date_ != Query->FieldByName("計量日")->AsInteger ? true : false; 
		}
	}

	old_item1_ = Query->FieldByName("項目コード1")->AsInteger;
	old_item2_ = Query->FieldByName("項目コード2")->AsInteger;
	old_date_  = Query->FieldByName("計量日")->AsInteger;
}
//---------------------------------------------------------------------------

