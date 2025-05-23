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
	if (old_seikyu_code_ != DM->Q_Seikyu->FieldByName("請求先コード")->AsString){
		// １ページ目は、見出しを表示する
		YubinTLabel->Enabled   = true;
		YubinDBLabel->Enabled    = true;

		KingakuLabel1->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("前回請求額")->AsCurrency);
		KingakuLabel2->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("今回入金額")->AsCurrency);
		KingakuLabel3->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("今回調整額")->AsCurrency);
		KingakuLabel4->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("今回繰越額")->AsCurrency);
		KingakuLabel5->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("今回売上額")->AsCurrency);
		KingakuLabel6->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);

		if (DM->Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1)
			KingakuLabel7->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("今回請求額")->AsCurrency);
		else
			KingakuLabel7->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("今回売上額")->AsCurrency + DM->Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);

		page_no_ = 1;
		seikyu_kei_  = 0;
		old_seikyu_code_ = DM->Q_Seikyu->FieldByName("請求先コード")->AsString;

	}else{
		// ２ページ目以降は、見出しを表示しない
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

	PageNumberLabel->Caption  = IntToStr(page_no_) + " 頁";

	SeikyusakiLabel->Caption  = DM->Q_Seikyu->FieldByName("請求先名称")->AsString + "　" + DM->Q_Seikyu->FieldByName("敬称")->AsString;
	int len = SeikyusakiLabel->Caption.Length();
	SeikyusakiLabel->Font->Size  = len <= 48 ? 10 : len <= 54 ? 9 : 7;

	KingakuLabel1->Caption = DM->Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? KingakuLabel1->Caption : AnsiString("************");
	KingakuLabel2->Caption = DM->Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? KingakuLabel2->Caption : AnsiString("************");
	KingakuLabel3->Caption = DM->Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? KingakuLabel3->Caption : AnsiString("************");
	KingakuLabel4->Caption = DM->Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? KingakuLabel4->Caption : AnsiString("************");

	// 明細合計
	ShohizeiLabel->Caption = FormatFloat("#,###,###,###", DM->Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);
	TotalLabel->Caption    = FormatFloat("#,###,###,###", DM->Q_Seikyu->FieldByName("今回売上額")->AsCurrency + DM->Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);

	// 売上・消費税・入金＝0の場合、集計行は表示しない
	if (DM->Q_Seikyu->FieldByName("今回売上額")->AsCurrency == 0 && DM->Q_Seikyu->FieldByName("今回消費税額")->AsCurrency == 0 && DM->Q_Seikyu->FieldByName("今回入金額")->AsCurrency == 0){
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
	if (DM->Q_Seikyu->FieldByName(name1)->AsString.SubString(1, 4) != "入金")
		ShokeiLabel1->Caption = "[" + DM->Q_Seikyu->FieldByName(name1)->AsString + "]";
	else
		ShokeiLabel1->Caption = "[入金 【合　計】]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader2BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name2)->AsString.SubString(1, 4) != "入金")
		ShokeiLabel2->Caption = "[" + DM->Q_Seikyu->FieldByName(name2)->AsString + "]";
	else
		ShokeiLabel2->Caption = "[入金 【合　計】]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader3BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name3)->AsString.SubString(1, 4) != "入金")
		ShokeiLabel3->Caption = "[" + DM->Q_Seikyu->FieldByName(name3)->AsString + "]";
	else
		ShokeiLabel3->Caption = "[入金 【合　計】]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader4BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name4)->AsString.SubString(1, 4) != "入金")
		ShokeiLabel4->Caption = "[" + DM->Q_Seikyu->FieldByName(name4)->AsString + "]";
	else
		ShokeiLabel4->Caption = "[入金 【合　計】]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader5BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name5)->AsString.SubString(1, 4) != "入金")
		ShokeiLabel5->Caption = "[" + DM->Q_Seikyu->FieldByName(name5)->AsString + "]";
	else
		ShokeiLabel5->Caption = "[入金 【合　計】]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::DetailBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName("売上入金区分")->AsInteger == 1){
		seikyu_kei_ += DM->Q_Seikyu->FieldByName("金額")->AsCurrency;
		kei1_ += DM->Q_Seikyu->FieldByName("金額")->AsCurrency;
		kei2_ += DM->Q_Seikyu->FieldByName("金額")->AsCurrency;
		kei3_ += DM->Q_Seikyu->FieldByName("金額")->AsCurrency;
		kei4_ += DM->Q_Seikyu->FieldByName("金額")->AsCurrency;
		kei5_ += DM->Q_Seikyu->FieldByName("金額")->AsCurrency;
	}

	// 品目名称のフォントサイズ
	//QRDBTextHinName->Font->Size = DM->Q_Seikyu->FieldByName("品目名称")->AsString.Length() <= 30 ? 10 : DM->Q_Seikyu->FieldByName("品目名称")->AsString.Length() <= 35 ? 9 : 7;

	// 数量、単位、単価は入金の場合表示しない
	QRDBTextSuryo->Enabled = DM->Q_Seikyu->FieldByName("売上入金区分")->AsInteger == 1 ? true : false;
	QRDBTextTani->Enabled  = DM->Q_Seikyu->FieldByName("売上入金区分")->AsInteger == 1 ? true : false;
	QRDBTextTanka->Enabled = DM->Q_Seikyu->FieldByName("売上入金区分")->AsInteger == 1 ? true : false;
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

