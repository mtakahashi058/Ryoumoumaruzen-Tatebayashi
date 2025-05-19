//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SeikyushoYokoFrm.h"
//---------------------------------------------------------------------------
#include <DateUtils.hpp>
#include <math.hpp>
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSeikyushoYokoForm *SeikyushoYokoForm;
//---------------------------------------------------------------------------
__fastcall TSeikyushoYokoForm::TSeikyushoYokoForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::QuickRepBeforePrint(
	  TCustomQuickRep *Sender, bool &PrintReport)
{
	old_seikyu_code_ = -1;

	GroupHeaderSeikyu->Height = 0;
	GroupHeader1->Height = 0;
	GroupHeader2->Height = 0;
	GroupHeader3->Height = 0;
	GroupHeader4->Height = 0;
	GroupHeader5->Height = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::PageHeaderBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (old_seikyu_code_ != DM->Q_Seikyu->FieldByName("¿‹æƒR[ƒh")->AsString){
		// ‚Pƒy[ƒW–Ú‚ÍAŒ©o‚µ‚ð•\Ž¦‚·‚é
		YubinTLabel->Enabled   = true;
		YubinDBLabel->Enabled    = true;

		KingakuLabel1->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("‘O‰ñ¿‹Šz")->AsCurrency);
		KingakuLabel2->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("¡‰ñ“ü‹àŠz")->AsCurrency);
		KingakuLabel3->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("¡‰ñ’²®Šz")->AsCurrency);
		KingakuLabel4->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("¡‰ñŒJ‰zŠz")->AsCurrency);
		KingakuLabel5->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("¡‰ñ”„ãŠz")->AsCurrency);
		KingakuLabel6->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("¡‰ñÁ”ïÅŠz")->AsCurrency);

		if (DM->Q_Seikyu->FieldByName("Žc‚•\Ž¦‹æ•ª")->AsInteger == 1)
			KingakuLabel7->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("¡‰ñ¿‹Šz")->AsCurrency);
		else
			KingakuLabel7->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("¡‰ñ”„ãŠz")->AsCurrency + DM->Q_Seikyu->FieldByName("¡‰ñÁ”ïÅŠz")->AsCurrency);

		page_no_ = 1;
		seikyu_kei_  = 0;
		old_seikyu_code_ = DM->Q_Seikyu->FieldByName("¿‹æƒR[ƒh")->AsString;

	}else{
		// ‚Qƒy[ƒW–ÚˆÈ~‚ÍAŒ©o‚µ‚ð•\Ž¦‚µ‚È‚¢
		YubinTLabel->Enabled   = false;
		YubinDBLabel->Enabled    = false;
		Add1DBLabel->Enabled = false;
		Add2DBLabel->Enabled = false;

		KingakuLabel1->Caption = "************";
		KingakuLabel2->Caption = "************";
		KingakuLabel3->Caption = "************";
		KingakuLabel4->Caption = "************";
		KingakuLabel5->Caption = "************";
		KingakuLabel6->Caption = "************";
		KingakuLabel7->Caption = "************";

		page_no_++;
	}

	PageNumberLabel->Caption  = IntToStr(page_no_) + " •Å";

	SeikyusakiLabel->Caption  = DM->Q_Seikyu->FieldByName("¿‹æ–¼Ì")->AsString + "@" + DM->Q_Seikyu->FieldByName("ŒhÌ")->AsString;
	int len = SeikyusakiLabel->Caption.Length();
	SeikyusakiLabel->Font->Size  = len <= 48 ? 10 : len <= 54 ? 9 : 7;

	KingakuLabel1->Caption = DM->Q_Seikyu->FieldByName("Žc‚•\Ž¦‹æ•ª")->AsInteger == 1 ? KingakuLabel1->Caption : AnsiString("************");
	KingakuLabel2->Caption = DM->Q_Seikyu->FieldByName("Žc‚•\Ž¦‹æ•ª")->AsInteger == 1 ? KingakuLabel2->Caption : AnsiString("************");
	KingakuLabel3->Caption = DM->Q_Seikyu->FieldByName("Žc‚•\Ž¦‹æ•ª")->AsInteger == 1 ? KingakuLabel3->Caption : AnsiString("************");
	KingakuLabel4->Caption = DM->Q_Seikyu->FieldByName("Žc‚•\Ž¦‹æ•ª")->AsInteger == 1 ? KingakuLabel4->Caption : AnsiString("************");

	// –¾×‡Œv
	ShohizeiLabel->Caption = FormatFloat("#,###,###,###", DM->Q_Seikyu->FieldByName("¡‰ñÁ”ïÅŠz")->AsCurrency);
	TotalLabel->Caption    = FormatFloat("#,###,###,###", DM->Q_Seikyu->FieldByName("¡‰ñ”„ãŠz")->AsCurrency + DM->Q_Seikyu->FieldByName("¡‰ñÁ”ïÅŠz")->AsCurrency);

	// ”„ãEÁ”ïÅE“ü‹à0‚Ìê‡AWŒvs‚Í•\Ž¦‚µ‚È‚¢
	if (DM->Q_Seikyu->FieldByName("¡‰ñ”„ãŠz")->AsCurrency == 0 && DM->Q_Seikyu->FieldByName("¡‰ñÁ”ïÅŠz")->AsCurrency == 0 && DM->Q_Seikyu->FieldByName("¡‰ñ“ü‹àŠz")->AsCurrency == 0){
		GroupFooterSeikyu->Enabled = false;
	}else{
		GroupFooterSeikyu->Enabled = div_total;
	}
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeaderSeikyuBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	//
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name1)->AsString.SubString(1, 4) != "“ü‹à")
		ShokeiLabel1->Caption = "[" + DM->Q_Seikyu->FieldByName(name1)->AsString + "]";
	else
		ShokeiLabel1->Caption = "[“ü‹à y‡@Œvz]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader2BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name2)->AsString.SubString(1, 4) != "“ü‹à")
		ShokeiLabel2->Caption = "[" + DM->Q_Seikyu->FieldByName(name2)->AsString + "]";
	else
		ShokeiLabel2->Caption = "[“ü‹à y‡@Œvz]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader3BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name3)->AsString.SubString(1, 4) != "“ü‹à")
		ShokeiLabel3->Caption = "[" + DM->Q_Seikyu->FieldByName(name3)->AsString + "]";
	else
		ShokeiLabel3->Caption = "[“ü‹à y‡@Œvz]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader4BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name4)->AsString.SubString(1, 4) != "“ü‹à")
		ShokeiLabel4->Caption = "[" + DM->Q_Seikyu->FieldByName(name4)->AsString + "]";
	else
		ShokeiLabel4->Caption = "[“ü‹à y‡@Œvz]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader5BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name5)->AsString.SubString(1, 4) != "“ü‹à")
		ShokeiLabel5->Caption = "[" + DM->Q_Seikyu->FieldByName(name5)->AsString + "]";
	else
		ShokeiLabel5->Caption = "[“ü‹à y‡@Œvz]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::DetailBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName("”„ã“ü‹à‹æ•ª")->AsInteger == 1){
		seikyu_kei_ += DM->Q_Seikyu->FieldByName("‹àŠz")->AsCurrency;
		kei1_ += DM->Q_Seikyu->FieldByName("‹àŠz")->AsCurrency;
		kei2_ += DM->Q_Seikyu->FieldByName("‹àŠz")->AsCurrency;
		kei3_ += DM->Q_Seikyu->FieldByName("‹àŠz")->AsCurrency;
		kei4_ += DM->Q_Seikyu->FieldByName("‹àŠz")->AsCurrency;
		kei5_ += DM->Q_Seikyu->FieldByName("‹àŠz")->AsCurrency;
	}

	// •i–Ú–¼Ì‚ÌƒtƒHƒ“ƒgƒTƒCƒY
	//QRDBTextHinName->Font->Size = DM->Q_Seikyu->FieldByName("•i–Ú–¼Ì")->AsString.Length() <= 30 ? 10 : DM->Q_Seikyu->FieldByName("•i–Ú–¼Ì")->AsString.Length() <= 35 ? 9 : 7;

	// ”—ÊA’PˆÊA’P‰¿‚Í“ü‹à‚Ìê‡•\Ž¦‚µ‚È‚¢
	QRDBTextSuryo->Enabled = DM->Q_Seikyu->FieldByName("”„ã“ü‹à‹æ•ª")->AsInteger == 1 ? true : false;
	QRDBTextTani->Enabled  = DM->Q_Seikyu->FieldByName("”„ã“ü‹à‹æ•ª")->AsInteger == 1 ? true : false;
	QRDBTextTanka->Enabled = DM->Q_Seikyu->FieldByName("”„ã“ü‹à‹æ•ª")->AsInteger == 1 ? true : false;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupFooter5BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	//ShokeiLabel5->Font->Size = ShokeiLabel5->Caption.Length() <= 30 ? 10 : ShokeiLabel5->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupFooter4BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	//ShokeiLabel4->Font->Size = ShokeiLabel4->Caption.Length() <= 30 ? 10 : ShokeiLabel4->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupFooter3BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	//ShokeiLabel3->Font->Size = ShokeiLabel3->Caption.Length() <= 30 ? 10 : ShokeiLabel3->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupFooter2BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	//ShokeiLabel2->Font->Size = ShokeiLabel2->Caption.Length() <= 30 ? 10 : ShokeiLabel2->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupFooter1BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	//ShokeiLabel1->Font->Size = ShokeiLabel1->Caption.Length() <= 30 ? 10 : ShokeiLabel1->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupFooterSeikyuBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	UriageGokeiLabel->Caption = FormatFloat("#,##0", seikyu_kei_);
	seikyu_kei_ = 0;
}
//---------------------------------------------------------------------------

