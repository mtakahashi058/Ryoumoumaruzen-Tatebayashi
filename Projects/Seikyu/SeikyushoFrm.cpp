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

	// ������
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

/*	if (DM->hd_kubun == 2){		// ���H��
		HonshaLabel->Enabled = false;
		DainiLabel->Enabled  = true;
	}else{				// �{��
		HonshaLabel->Enabled = true;
		DainiLabel->Enabled  = false;
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::PageHeaderBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	// ����NO
	NsFieldSet keys;
	keys	<< NsField("���ؓ�",	Q_Seikyu->FieldByName("���ؓ�")->AsInteger)
		<< NsField("������ID",	Q_Seikyu->FieldByName("������ID")->AsInteger);
	TDateTime kosin = TDateTime(DM->DBI.Lookup("D_����", keys, "�X�V����"));
	SeikyuNoLabel->Caption = "����NO�F " + IntToDate(Q_Seikyu->FieldByName("���ؓ�")->AsInteger).FormatString("yymm") + "-" + kosin.FormatString("ddhhnn") + "-" + Q_Seikyu->FieldByName("������R�[�h")->AsString;

	// �����\����y�ш��n�����v�Z
	TDateTime yoteibi = DM->GetNyukinYotei(IntToDate(Q_Seikyu->FieldByName("���ؓ�")->AsInteger), Q_Seikyu->FieldByName("�����T�C�g")->AsInteger, Q_Seikyu->FieldByName("������")->AsInteger);

	if (old_seikyu_code_ != Q_Seikyu->FieldByName("������R�[�h")->AsString){
		// �P�y�[�W�ڂ́A���o����\������
		YubinTLabel->Enabled   = true;
		YubinLabel->Enabled    = true;
		AddressLabel1->Enabled = true;
		AddressLabel2->Enabled = true;
		AddressLabel3->Enabled = true;

		KingakuLabel1->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("�O�񐿋��z")->AsCurrency);
		KingakuLabel2->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("�����z")->AsCurrency);
		KingakuLabel3->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("�����z")->AsCurrency);
		KingakuLabel4->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("�J�z�z")->AsCurrency);
		KingakuLabel5->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("����z")->AsCurrency);
		KingakuLabel6->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("����Ŋz")->AsCurrency);

		if (Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1)
			KingakuLabel7->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("���񐿋��z")->AsCurrency);
		else
			KingakuLabel7->Caption = FormatFloat("#,###", Q_Seikyu->FieldByName("����z")->AsCurrency + Q_Seikyu->FieldByName("����Ŋz")->AsCurrency);

		page_no_ = 1;
		uriage_  = 0;
		old_seikyu_code_ = Q_Seikyu->FieldByName("������R�[�h")->AsString;
	}else{
		// �Q�y�[�W�ڈȍ~�́A���o����\�����Ȃ�
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

	PageNumberLabel->Caption  = IntToStr(page_no_) + " ��";

	YubinLabel->Caption = Q_Seikyu->FieldByName("�X�֔ԍ�")->AsString;
	AnsiString buff = Q_Seikyu->FieldByName("�Z��1")->AsString + Q_Seikyu->FieldByName("�Z��2")->AsString;
	AddressLabel1->Caption = AnsiDivide(&buff, 44);
	AddressLabel2->Caption = AnsiDivide(&buff, 44);
	AddressLabel3->Caption = buff;

	buff = Q_Seikyu->FieldByName("�����於��")->AsString + "�@�@" + Q_Seikyu->FieldByName("�h�̋敪����")->AsString;
	SeikyusakiLabel1->Caption = AnsiDivide(&buff, 44);
	SeikyusakiLabel2->Caption = buff;

	// �����U�փR�[�h�ɒl�������Ă���ꍇ�́A�����U�փR�[�h�ƈ��n�����󎚂���
	if (!Q_Seikyu->FieldByName("�����U�փR�[�h")->IsNull && Q_Seikyu->FieldByName("�����U�փR�[�h")->AsString != ""){
		HurikaeCodeLabel->Caption  = "�����U�փR�[�h�F" + Q_Seikyu->FieldByName("�����U�փR�[�h")->AsString;
		HikiwatasibiLabel->Caption = "��" + yoteibi.FormatString("yyyy'�N'mm'��'dd'��'") + "�Ɏw������������Ƃ��������܂��B" + yoteibi.FormatString("dd") + "�����y���j���̏ꍇ�́A���c�Ɠ��ƂȂ�܂��B";
	}else{
		HurikaeCodeLabel->Caption  = AnsiString();
		HikiwatasibiLabel->Caption = AnsiString();
	}

	KingakuLabel1->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;
	KingakuLabel2->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;
	KingakuLabel3->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;
	KingakuLabel4->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;

	// ���׍��v
	ShohizeiLabel->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("����Ŋz")->AsCurrency);
	TotalLabel->Caption    = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("����z")->AsCurrency + Q_Seikyu->FieldByName("����Ŋz")->AsCurrency);

	// ����E����ŁE������0�̏ꍇ�A�W�v�s�͕\�����Ȃ�
	if (Q_Seikyu->FieldByName("����z")->AsCurrency == 0 && Q_Seikyu->FieldByName("����Ŋz")->AsCurrency == 0 && Q_Seikyu->FieldByName("�����z")->AsCurrency == 0){
		GFGLabel->Font->Color = clWhite;
		GenbKeiLabel->Font->Color  = clWhite;
		GroupFooterSeikyu->Enabled = false;
	}else{
		GFGLabel->Font->Color = clBlack;
		GenbKeiLabel->Font->Color  = clBlack;
		GroupFooterSeikyu->Enabled = true;
	}

	// �����S���҂Ł��̈ʒu��ؑ�
	if (Q_Seikyu->FieldByName("�����S���Ј��R�[�h")->AsInteger == 1 || Q_Seikyu->FieldByName("�����S���Ј��R�[�h")->AsInteger == 5){
		HonshaLabel->Enabled = false;
		DainiLabel->Enabled  = true;
	}else{
		HonshaLabel->Enabled = true;
		DainiLabel->Enabled  = false;
	}

/*
	// ���񐿋��z�Z�o
	Currency seikyu =	Q_Seikyu->FieldByName("����J�z�z")->AsCurrency +
				Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency +
				Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency;

	if (old_seikyu_code_ != Q_Seikyu->FieldByName("������R�[�h")->AsInteger){
		// �P�y�[�W�ڂ́A���o����\������
		lblYubinT->Enabled = true;
		qrdbYubin->Enabled = true;
		qrdbAdd1->Enabled = true;
		qrdbAdd2->Enabled = true;
		lblKingaku1->Caption = "";
		lblKingaku2->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("�O�񐿋��z")->AsCurrency);
		lblKingaku3->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("��������z")->AsCurrency);
		lblKingaku4->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("���񒲐��z")->AsCurrency);
		lblKingaku5->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("����J�z�z")->AsCurrency);
		lblKingaku6->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency);
		lblKingaku7->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);

		if (Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1)
			lblKingaku8->Caption = FormatFloat("#,###,###,###", seikyu);
		else
			lblKingaku8->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency + Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);

		page_no_ = 1;
		old_seikyu_code_ = Q_Seikyu->FieldByName("������R�[�h")->AsInteger;

	}else{
		// �Q�y�[�W�ڈȍ~�́A���o����\�����Ȃ�
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
	lblPageNumber->Caption = IntToStr(page_no_) + " ��";

	// �c���\���敪
	lblKingaku1->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;
	lblKingaku2->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;
	lblKingaku3->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;
	lblKingaku4->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;
	lblKingaku5->Enabled = Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? true : false;

	// ���������
	if (Q_Seikyu->FieldByName("�������敪")->AsInteger == 1){
		lblSeikyumoto01->Caption = DM->ini_["������::IF101"];
		lblSeikyumoto02->Caption = DM->ini_["������::IF102"];
		lblSeikyumoto03->Caption = DM->ini_["������::IF103"];
		lblSeikyumoto04->Caption = DM->ini_["������::IF104"];
		lblSeikyumoto05->Caption = DM->ini_["������::IF105"];
		lblSeikyumoto06->Caption = DM->ini_["������::IF106"];
		lblSeikyumoto07->Caption = DM->ini_["������::IF107"];
		lblSeikyumoto08->Caption = DM->ini_["������::IF108"];
		lblSeikyumoto09->Caption = DM->ini_["������::IF109"];
		lblSeikyumoto10->Caption = DM->ini_["������::IF110"];
		lblSeikyumoto11->Caption = DM->ini_["������::IF111"];
	}else{
		lblSeikyumoto01->Caption = DM->ini_["������::IF201"];
		lblSeikyumoto02->Caption = DM->ini_["������::IF202"];
		lblSeikyumoto03->Caption = DM->ini_["������::IF203"];
		lblSeikyumoto04->Caption = DM->ini_["������::IF204"];
		lblSeikyumoto05->Caption = DM->ini_["������::IF205"];
		lblSeikyumoto06->Caption = DM->ini_["������::IF206"];
		lblSeikyumoto07->Caption = DM->ini_["������::IF207"];
		lblSeikyumoto08->Caption = DM->ini_["������::IF208"];
		lblSeikyumoto09->Caption = DM->ini_["������::IF209"];
		lblSeikyumoto10->Caption = DM->ini_["������::IF210"];
		lblSeikyumoto11->Caption = DM->ini_["������::IF211"];
	}

	// ���׍��v
	lblShohizei->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);
	lblUriageGokei->Caption = FormatFloat("#,###,###,###", Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency + Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);
*/
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::GroupHeaderGenbBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	TokuisakiLabel->Caption = Q_Seikyu->FieldByName("���Ӑ於��")->AsString;

	// 1�̐�����ɕ����̓��Ӑ悪�܂܂�Ă���ꍇ�A���Ӑ�O���[�v�w�b�_���󎚂���
	int count = DM->GetTokuCount(Q_Seikyu->FieldByName("�J�n���t")->AsInteger, Q_Seikyu->FieldByName("�I�����t")->AsInteger, Q_Seikyu->FieldByName("������ID")->AsInteger);

	if (Q_Seikyu->FieldByName("�f�[�^�敪")->AsInteger == 1 && (count > 1 || (count == 1 && Q_Seikyu->FieldByName("������ID")->AsInteger != Q_Seikyu->FieldByName("���Ӑ�ID")->AsInteger)))
		GroupHeaderGenb->Height = 20;
	else
		GroupHeaderGenb->Height = 0;

	TokuisakiLabel->Caption = "[" + Q_Seikyu->FieldByName("���Ӑ於��")->AsString + "]";

	genb_kei_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoForm::DetailBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	// ����i��ID��0 �̏ꍇ�A0 ��\�����Ȃ��i���l�s�΍�j
	if (Q_Seikyu->FieldByName("�f�[�^�敪")->AsInteger == 1 &&
			Q_Seikyu->FieldByName("����i��ID")->AsInteger == 0 &&
			Q_Seikyu->FieldByName("���㐔��")->AsCurrency == 0){
		QRDBTextSuryo->Enabled = false;
	}else
		QRDBTextSuryo->Enabled = true;

	if (Q_Seikyu->FieldByName("�f�[�^�敪")->AsInteger == 1 &&
			Q_Seikyu->FieldByName("����i��ID")->AsInteger == 0 &&
			Q_Seikyu->FieldByName("������z")->AsCurrency == 0){
		QRDBTextKingaku->Enabled = false;
	}else
		QRDBTextKingaku->Enabled = true;

	if (Q_Seikyu->FieldByName("�f�[�^�敪")->AsInteger == 1 &&
			Q_Seikyu->FieldByName("����i��ID")->AsInteger == 0 &&
			Q_Seikyu->FieldByName("���㐔��")->AsCurrency  == 0 &&
			Q_Seikyu->FieldByName("������z")->AsCurrency  == 0){
		DateDBText->Enabled = false;
	}else
		DateDBText->Enabled = true;


	if (Q_Seikyu->FieldByName("�f�[�^�敪")->AsInteger == 1){
		uriage_   += Q_Seikyu->FieldByName("������z")->AsCurrency;
		genb_kei_ += Q_Seikyu->FieldByName("������z")->AsCurrency;
	}
	QRDBTextBiko->Enabled = Q_Seikyu->FieldByName("������l�\���敪")->AsInteger == 1 ? true : false;
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
	if (Q_Seikyu->FieldByName("�f�[�^�敪")->AsInteger == 2){
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
	if (Q_Seikyu->FieldByName("����")->AsString != AnsiString() && Q_Seikyu->FieldByName("����")->AsString != Q_Seikyu->FieldByName("����i�ږ���")->AsString){
		QRGroupKenmei->Height = 20;
		KenmeiLabel->Caption = "- " + Q_Seikyu->FieldByName("����")->AsString + " -";
	}else{
		QRGroupKenmei->Height = 0;
		KenmeiLabel->Caption = AnsiString();
	}
}
//---------------------------------------------------------------------------

