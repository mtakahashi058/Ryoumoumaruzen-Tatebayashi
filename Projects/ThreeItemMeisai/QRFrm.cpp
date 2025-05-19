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
	: TForm(Owner), old_item1_(0), old_item2_(0), old_item3_(0), old_date_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QuickRepBeforePrint(TCustomQuickRep *Sender,
	  bool &PrintReport)
{
	Item1GroupHeaderBand->Height = 0;
	Item2GroupHeaderBand->Height = 0;
	Item3GroupHeaderBand->Height = 0;

	old_item1_ = -1;
	old_item2_ = -1;
	old_item3_ = -1;
	old_date_  = -1;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::Item1GroupHeaderBandBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	old_item1_ = -1;
	old_item2_ = -1;
	old_item3_ = -1;
	old_date_  = -1;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::DetailBandBeforePrint(TQRCustomBand *Sender,
	  bool &PrintBand)
{
	Item2CodeText->Enabled = true;
	Item2NameText->Enabled = true;
	Item3CodeText->Enabled = true;
	Item3NameText->Enabled = true;
	DateText->Enabled = true;

	if (old_item2_ == Query->FieldByName("項目コード2")->AsInteger){
		Item2CodeText->Enabled = false;
		Item2NameText->Enabled = false;
		if (old_item3_ == Query->FieldByName("項目コード3")->AsInteger){
			Item3CodeText->Enabled = false;
			Item3NameText->Enabled = false;
		}
		DateText->Enabled = old_date_ != Query->FieldByName("計量日")->AsInteger ? true : false;
	}else if (old_item3_ == Query->FieldByName("項目コード3")->AsInteger){
		Item3CodeText->Enabled = false;
		Item3NameText->Enabled = false;
		DateText->Enabled = old_date_ != Query->FieldByName("計量日")->AsInteger ? true : false;
	}

	old_item1_ = Query->FieldByName("項目コード1")->AsInteger;
	old_item2_ = Query->FieldByName("項目コード2")->AsInteger;
	old_item3_ = Query->FieldByName("項目コード3")->AsInteger;
	old_date_  = Query->FieldByName("計量日")->AsInteger;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::PageHeaderBandBeforePrint(TQRCustomBand *Sender,
	  bool &PrintBand)
{
	Item1Label->Caption = ITEM1 + "：" + Query->FieldByName("項目コード1")->AsString + "  " +Query->FieldByName("項目略称1")->AsString;
}
//---------------------------------------------------------------------------

