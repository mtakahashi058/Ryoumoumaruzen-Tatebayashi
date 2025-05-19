//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SeikyushoFrm.h"
//---------------------------------------------------------------------------
#include <DateUtils.hpp>
#include <math.hpp>
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSeikyushoForm *SeikyushoForm;
//---------------------------------------------------------------------------
__fastcall TSeikyushoForm::TSeikyushoForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::QuickRepBeforePrint(
	  TCustomQuickRep *Sender, bool &PrintReport)
{
	old_month_       = -1;
	old_day_         = -1;
	old_slip_no_     = -1;
	old_seikyu_code_ = -1;

	GroupHeaderSeikyu->Height = 0;

	// 請求元
	SeikyumotoLabel01->Caption = DM->ini_["SeikyuMoto::Info01"];
	SeikyumotoLabel02->Caption = DM->ini_["SeikyuMoto::Info02"];
	SeikyumotoLabel03->Caption = DM->ini_["SeikyuMoto::Info03"];
	SeikyumotoLabel04->Caption = DM->ini_["SeikyuMoto::Info04"];
	SeikyumotoLabel05->Caption = DM->ini_["SeikyuMoto::Info05"];
	SeikyumotoLabel06->Caption = DM->ini_["SeikyuMoto::Info06"];
	SeikyumotoLabel07->Caption = DM->ini_["SeikyuMoto::Info07"];
	SeikyumotoLabel08->Caption = DM->ini_["SeikyuMoto::Info08"];
	SeikyumotoLabel09->Caption = DM->ini_["SeikyuMoto::Info09"];
	SeikyumotoLabel10->Caption = DM->ini_["SeikyuMoto::Info10"];
	FooterLabel->Caption = DM->ini_["SeikyuFooter::Info"];

/*	if (DM->hd_kubun == 2){		// 第二工場
		HonshaLabel->Enabled = false;
		DainiLabel->Enabled  = true;
	}else{				// 本社
		HonshaLabel->Enabled = true;
		DainiLabel->Enabled  = false;
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::PageHeaderBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	// 請求NO
	NsFieldSet keys;
	keys	<< NsField("締切日",	Q_Seikyu->FieldByName("締切日")->AsInteger)
		<< NsField("請求先ID",	Q_Seikyu->FieldByName("請求先ID")->AsInteger);
	TDateTime kosin = TDateTime(DM->DBI.Lookup("D_請求", keys, "更新日時"));
	SeikyuNoLabel->Caption = "請求NO： " + IntToDate(Q_Seikyu->FieldByName("締切日")->AsInteger).FormatString("yymm") + "-" + kosin.FormatString("ddhhnn") + "-" + Q_Seikyu->FieldByName("請求先コード")->AsString;

	// 入金予定日及び引渡日を計算
	TDateTime yoteibi = DM->GetNyukinYotei(IntToDate(Q_Seikyu->FieldByName("締切日")->AsInteger), Q_Seikyu->FieldByName("入金サイト")->AsInteger, Q_Seikyu->FieldByName("入金日")->AsInteger);

	if (old_seikyu_code_ != Q_Seikyu->FieldByName("請求先コード")->AsString){
		// １ページ目は、見出しを表示する
		YubinTLabel->Enabled   = true;
		YubinLabel->Enabled    = true;
		AddressLabel1->Enabled = true;
		AddressLabel2->Enabled = true;
		AddressLabel3->Enabled = true;

		KingakuLabel1->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("前回請求額")->AsCurrency);
		KingakuLabel2->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("入金額")->AsCurrency);
		KingakuLabel3->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("調整額")->AsCurrency);
		KingakuLabel4->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("繰越額")->AsCurrency);
		KingakuLabel5->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("売上額")->AsCurrency);
		KingakuLabel6->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("消費税額")->AsCurrency);

		if (Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1)
			KingakuLabel7->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("今回請求額")->AsCurrency);
		else
			KingakuLabel7->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("売上額")->AsCurrency + Q_Seikyu->FieldByName("消費税額")->AsCurrency);

		page_no_ = 1;
		uriage_  = 0;
		old_seikyu_code_ = Q_Seikyu->FieldByName("請求先コード")->AsString;
	}else{
		// ２ページ目以降は、見出しを表示しない
		YubinTLabel->Enabled   = false;
		YubinLabel->Enabled    = false;
		AddressLabel1->Enabled = false;
		AddressLabel2->Enabled = false;
		AddressLabel3->Enabled = false;

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

	YubinLabel->Caption = Q_Seikyu->FieldByName("郵便番号")->AsString;
	AnsiString buff = Q_Seikyu->FieldByName("住所1")->AsString + Q_Seikyu->FieldByName("住所2")->AsString;
	AddressLabel1->Caption = AnsiDivide(&buff, 44);
	AddressLabel2->Caption = AnsiDivide(&buff, 44);
	AddressLabel3->Caption = buff;

	buff = Q_Seikyu->FieldByName("請求先名称")->AsString + "　　" + Q_Seikyu->FieldByName("敬称区分名称")->AsString;
	SeikyusakiLabel1->Caption = AnsiDivide(&buff, 44);
	SeikyusakiLabel2->Caption = buff;

	// 自動振替コードに値が入っている場合は、自動振替コードと引渡日を印字する
	if (!Q_Seikyu->FieldByName("自動振替コード")->IsNull && Q_Seikyu->FieldByName("自動振替コード")->AsString != ""){
		HurikaeCodeLabel->Caption  = "自動振替コード：" + Q_Seikyu->FieldByName("自動振替コード")->AsString;
		HikiwatasibiLabel->Caption = "※" + yoteibi.FormatString("yyyy'年'mm'月'dd'日'") + "に指定口座より引落としいたします。" + yoteibi.FormatString("dd") + "日が土日祝日の場合は、翌営業日となります。";
	}else{
		HurikaeCodeLabel->Caption  = AnsiString();
		HikiwatasibiLabel->Caption = AnsiString();
	}

	KingakuLabel1->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;
	KingakuLabel2->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;
	KingakuLabel3->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;
	KingakuLabel4->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;

	// 明細合計
	ShohizeiLabel->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("消費税額")->AsCurrency);
	TotalLabel->Caption    = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("売上額")->AsCurrency + Q_Seikyu->FieldByName("消費税額")->AsCurrency);

	// 売上・消費税・入金＝0の場合、集計行は表示しない
	if (Q_Seikyu->FieldByName("売上額")->AsCurrency == 0 && Q_Seikyu->FieldByName("消費税額")->AsCurrency == 0 && Q_Seikyu->FieldByName("入金額")->AsCurrency == 0){
		GFGLabel->Font->Color = clWhite;
		GenbKeiLabel->Font->Color  = clWhite;
		GroupFooterSeikyu->Enabled = false;
	}else{
		GFGLabel->Font->Color = clBlack;
		GenbKeiLabel->Font->Color  = clBlack;
		GroupFooterSeikyu->Enabled = true;
	}

	// 事務担当者で◎の位置を切替
	if (Q_Seikyu->FieldByName("事務担当社員コード")->AsInteger == 1 || Q_Seikyu->FieldByName("事務担当社員コード")->AsInteger == 5){
		HonshaLabel->Enabled = false;
		DainiLabel->Enabled  = true;
	}else{
		HonshaLabel->Enabled = true;
		DainiLabel->Enabled  = false;
	}

/*
	// 今回請求額算出
	Currency seikyu =	Q_Seikyu->FieldByName("今回繰越額")->AsCurrency +
				Q_Seikyu->FieldByName("今回売上額")->AsCurrency +
				Q_Seikyu->FieldByName("今回消費税額")->AsCurrency;

	if (old_seikyu_code_ != Q_Seikyu->FieldByName("請求先コード")->AsInteger){
		// １ページ目は、見出しを表示する
		lblYubinT->Enabled = true;
		qrdbYubin->Enabled = true;
		qrdbAdd1->Enabled = true;
		qrdbAdd2->Enabled = true;
		lblKingaku1->Caption = "";
		lblKingaku2->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("前回請求額")->AsCurrency);
		lblKingaku3->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回入金額")->AsCurrency);
		lblKingaku4->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回調整額")->AsCurrency);
		lblKingaku5->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回繰越額")->AsCurrency);
		lblKingaku6->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回売上額")->AsCurrency);
		lblKingaku7->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);

		if (Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1)
			lblKingaku8->Caption = FormatFloat("#,###,###,###", seikyu);
		else
			lblKingaku8->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回売上額")->AsCurrency + Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);

		page_no_ = 1;
		old_seikyu_code_ = Q_Seikyu->FieldByName("請求先コード")->AsInteger;

	}else{
		// ２ページ目以降は、見出しを表示しない
		lblYubinT->Enabled = false;
		qrdbYubin->Enabled = false;
		qrdbAdd1->Enabled = false;
		qrdbAdd2->Enabled = false;
		lblKingaku1->Caption = "**********";
		lblKingaku2->Caption = "**********";
		lblKingaku3->Caption = "**********";
		lblKingaku4->Caption = "**********";
		lblKingaku5->Caption = "**********";
		lblKingaku6->Caption = "**********";
		lblKingaku7->Caption = "**********";
		lblKingaku8->Caption = "**********";
		page_no_++;
	}
	lblPageNumber->Caption = IntToStr(page_no_) + " 頁";

	// 残高表示区分
	lblKingaku1->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;
	lblKingaku2->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;
	lblKingaku3->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;
	lblKingaku4->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;
	lblKingaku5->Enabled = Q_Seikyu->FieldByName("残高表示区分")->AsInteger == 1 ? true : false;

	// 請求元情報
	if (Q_Seikyu->FieldByName("請求元区分")->AsInteger == 1){
		lblSeikyumoto01->Caption = DM->ini_["請求元::IF101"];
		lblSeikyumoto02->Caption = DM->ini_["請求元::IF102"];
		lblSeikyumoto03->Caption = DM->ini_["請求元::IF103"];
		lblSeikyumoto04->Caption = DM->ini_["請求元::IF104"];
		lblSeikyumoto05->Caption = DM->ini_["請求元::IF105"];
		lblSeikyumoto06->Caption = DM->ini_["請求元::IF106"];
		lblSeikyumoto07->Caption = DM->ini_["請求元::IF107"];
		lblSeikyumoto08->Caption = DM->ini_["請求元::IF108"];
		lblSeikyumoto09->Caption = DM->ini_["請求元::IF109"];
		lblSeikyumoto10->Caption = DM->ini_["請求元::IF110"];
		lblSeikyumoto11->Caption = DM->ini_["請求元::IF111"];
	}else{
		lblSeikyumoto01->Caption = DM->ini_["請求元::IF201"];
		lblSeikyumoto02->Caption = DM->ini_["請求元::IF202"];
		lblSeikyumoto03->Caption = DM->ini_["請求元::IF203"];
		lblSeikyumoto04->Caption = DM->ini_["請求元::IF204"];
		lblSeikyumoto05->Caption = DM->ini_["請求元::IF205"];
		lblSeikyumoto06->Caption = DM->ini_["請求元::IF206"];
		lblSeikyumoto07->Caption = DM->ini_["請求元::IF207"];
		lblSeikyumoto08->Caption = DM->ini_["請求元::IF208"];
		lblSeikyumoto09->Caption = DM->ini_["請求元::IF209"];
		lblSeikyumoto10->Caption = DM->ini_["請求元::IF210"];
		lblSeikyumoto11->Caption = DM->ini_["請求元::IF211"];
	}

	// 明細合計
	lblShohizei->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);
	lblUriageGokei->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("今回売上額")->AsCurrency + Q_Seikyu->FieldByName("今回消費税額")->AsCurrency);
*/
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::GroupHeaderGenbBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	TokuisakiLabel->Caption = Q_Seikyu->FieldByName("得意先名称")->AsString;

	// 1つの請求先に複数の得意先が含まれている場合、得意先グループヘッダを印字する
	int count = DM->GetTokuCount(Q_Seikyu->FieldByName("開始日付")->AsInteger, Q_Seikyu->FieldByName("終了日付")->AsInteger, Q_Seikyu->FieldByName("請求先ID")->AsInteger);

	if (Q_Seikyu->FieldByName("データ区分")->AsInteger == 1 && (count > 1 || (count == 1 && Q_Seikyu->FieldByName("請求先ID")->AsInteger != Q_Seikyu->FieldByName("得意先ID")->AsInteger)))
		GroupHeaderGenb->Height = 20;
	else
		GroupHeaderGenb->Height = 0;

	TokuisakiLabel->Caption = "[" + Q_Seikyu->FieldByName("得意先名称")->AsString + "]";

	genb_kei_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::DetailBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	// 売上品目ID＝0 の場合、0 を表示しない（備考行対策）
	if (Q_Seikyu->FieldByName("データ区分")->AsInteger == 1 &&
			Q_Seikyu->FieldByName("売上品目ID")->AsInteger == 0 &&
			Q_Seikyu->FieldByName("売上数量")->AsCurrency == 0){
		QRDBTextSuryo->Enabled = false;
	}else
		QRDBTextSuryo->Enabled = true;

	if (Q_Seikyu->FieldByName("データ区分")->AsInteger == 1 &&
			Q_Seikyu->FieldByName("売上品目ID")->AsInteger == 0 &&
			Q_Seikyu->FieldByName("売上金額")->AsCurrency == 0){
		QRDBTextKingaku->Enabled = false;
	}else
		QRDBTextKingaku->Enabled = true;

	if (Q_Seikyu->FieldByName("データ区分")->AsInteger == 1 &&
			Q_Seikyu->FieldByName("売上品目ID")->AsInteger == 0 &&
			Q_Seikyu->FieldByName("売上数量")->AsCurrency  == 0 &&
			Q_Seikyu->FieldByName("売上金額")->AsCurrency  == 0){
		DateDBText->Enabled = false;
	}else
		DateDBText->Enabled = true;


	if (Q_Seikyu->FieldByName("データ区分")->AsInteger == 1){
		uriage_   += Q_Seikyu->FieldByName("売上金額")->AsCurrency;
		genb_kei_ += Q_Seikyu->FieldByName("売上金額")->AsCurrency;
	}
	QRDBTextBiko->Enabled = Q_Seikyu->FieldByName("売上備考表示区分")->AsInteger == 1 ? true : false;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::GroupFooterSeikyuBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	UriageGokeiLabel->Caption = FormatFloat("#,##0", uriage_);
	uriage_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::GroupFooterGenbBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (Q_Seikyu->FieldByName("データ区分")->AsInteger == 2){
		GFGLabel->Enabled = false;
		GenbKeiLabel->Enabled  = false;
		GroupFooterGenb->Height = 20;
	}else{
		GFGLabel->Enabled = true;
		GenbKeiLabel->Enabled  = true;
		GroupFooterGenb->Height = 40;
		GenbKeiLabel->Caption = FormatFloat("#,##0", genb_kei_);
	}
}
//---------------------------------------------------------------------------

void __fastcall TSeikyushoForm::QRGroupKenmeiBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (Q_Seikyu->FieldByName("件名")->AsString != AnsiString() && Q_Seikyu->FieldByName("件名")->AsString != Q_Seikyu->FieldByName("売上品目名称")->AsString){
		QRGroupKenmei->Height = 20;
		KenmeiLabel->Caption = "- " + Q_Seikyu->FieldByName("件名")->AsString + " -";
	}else{
		QRGroupKenmei->Height = 0;
		KenmeiLabel->Caption = AnsiString();
	}
}
//---------------------------------------------------------------------------

