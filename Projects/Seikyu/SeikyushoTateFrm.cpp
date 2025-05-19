//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SeikyushoTateFrm.h"
//---------------------------------------------------------------------------
#include <DateUtils.hpp>
#include <math.hpp>
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSeikyushoTateForm *SeikyushoTateForm;
//---------------------------------------------------------------------------
__fastcall TSeikyushoTateForm::TSeikyushoTateForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::QuickRepBeforePrint(
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
void __fastcall TSeikyushoTateForm::PageHeaderBandBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (old_seikyu_code_ != DM->Q_Seikyu->FieldByName("������R�[�h")->AsString){
		// �P�y�[�W�ڂ́A���o����\������
		QRChildBand2->ParentBand = NULL;
		QRChildBand1->ParentBand = PageHeaderBand;

		QRChildBand1->Enabled = true;
		QRChildBand2->Enabled = false;

		QRShapeWaku->Top    = 339;
		QRShapeWaku->Height = 746;
		QRShapeLine01->Enabled = false;
		QRShapeLine02->Enabled = false;
		QRShapeLine03->Enabled = false;
		QRShapeLine04->Enabled = false;
		QRShapeLine05->Enabled = false;
		QRShapeLine06->Enabled = false;
		QRShapeLine07->Enabled = false;
		QRShapeLine08->Enabled = false;
		QRShapeLine09->Enabled = false;
		QRShapeLine10->Enabled = false;
		QRShapeLine11->Enabled = false;
		QRShapeLine12->Enabled = false;

		YubinTLabel->Enabled  = true;
		YubinDBLabel->Enabled = true;
		Add1DBLabel->Enabled = true;
		Add2DBLabel->Enabled = true;

		KingakuLabel1->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("�O�񐿋��z")->AsCurrency);
		KingakuLabel2->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("��������z")->AsCurrency);
		KingakuLabel3->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("���񒲐��z")->AsCurrency);
		KingakuLabel4->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("����J�z�z")->AsCurrency);
		KingakuLabel5->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency);
		KingakuLabel6->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);

		if (DM->Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1)
			KingakuLabel7->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("���񐿋��z")->AsCurrency);
		else
			KingakuLabel7->Caption = FormatFloat("#,###", DM->Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency + DM->Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);

		page_no_ = 1;
		seikyu_kei_  = 0;
		old_seikyu_code_ = DM->Q_Seikyu->FieldByName("������R�[�h")->AsString;

	}else{
		// �Q�y�[�W�ڈȍ~�́A���o����\�����Ȃ�
		QRChildBand1->ParentBand = NULL;
		QRChildBand2->ParentBand = PageHeaderBand;

		QRChildBand1->Enabled = false;
		QRChildBand2->Enabled = true;

		QRShapeWaku->Top    = 97;
		QRShapeWaku->Height = 988;
		QRShapeLine01->Enabled = true;
		QRShapeLine02->Enabled = true;
		QRShapeLine03->Enabled = true;
		QRShapeLine04->Enabled = true;
		QRShapeLine05->Enabled = true;
		QRShapeLine06->Enabled = true;
		QRShapeLine07->Enabled = true;
		QRShapeLine08->Enabled = true;
		QRShapeLine09->Enabled = true;
		QRShapeLine10->Enabled = true;
		QRShapeLine11->Enabled = true;
		QRShapeLine12->Enabled = true;

		YubinTLabel->Enabled  = false;
		YubinDBLabel->Enabled = false;
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

	QRShapeTate01->Top = QRShapeWaku->Top;
	QRShapeTate02->Top = QRShapeWaku->Top;
	QRShapeTate03->Top = QRShapeWaku->Top;
	QRShapeTate04->Top = QRShapeWaku->Top;
	QRShapeTate05->Top = QRShapeWaku->Top;
	QRShapeTate06->Top = QRShapeWaku->Top;
	QRShapeTate01->Height = QRShapeWaku->Height;
	QRShapeTate02->Height = QRShapeWaku->Height;
	QRShapeTate03->Height = QRShapeWaku->Height;
	QRShapeTate04->Height = QRShapeWaku->Height;
	QRShapeTate05->Height = QRShapeWaku->Height;
	QRShapeTate06->Height = QRShapeWaku->Height;

	PageNumberLabel->Caption  = IntToStr(page_no_) + " ��";

	SeikyusakiLabel->Caption  = DM->Q_Seikyu->FieldByName("�����於��")->AsString + "�@" + DM->Q_Seikyu->FieldByName("�h��")->AsString;
	SeikyusakiLabel_->Caption = DM->Q_Seikyu->FieldByName("�����於��")->AsString + "�@" + DM->Q_Seikyu->FieldByName("�h��")->AsString;
	int len = SeikyusakiLabel->Caption.Length();
	SeikyusakiLabel->Font->Size  = len <= 48 ? 10 : len <= 54 ? 9 : 7;
	SeikyusakiLabel_->Font->Size = len <= 48 ? 10 : len <= 54 ? 9 : 7;

	KingakuLabel1->Caption = DM->Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? KingakuLabel1->Caption : AnsiString("************");
	KingakuLabel2->Caption = DM->Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? KingakuLabel2->Caption : AnsiString("************");
	KingakuLabel3->Caption = DM->Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? KingakuLabel3->Caption : AnsiString("************");
	KingakuLabel4->Caption = DM->Q_Seikyu->FieldByName("�c���\���敪")->AsInteger == 1 ? KingakuLabel4->Caption : AnsiString("************");

	// ���׍��v
	ShohizeiLabel->Caption = FormatFloat("#,###,###,###", DM->Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);
	TotalLabel->Caption    = FormatFloat("#,###,###,###", DM->Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency + DM->Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency);

	// ����E����ŁE������0�̏ꍇ�A�W�v�s�͕\�����Ȃ�
	if (DM->Q_Seikyu->FieldByName("���񔄏�z")->AsCurrency == 0 && DM->Q_Seikyu->FieldByName("�������Ŋz")->AsCurrency == 0 && DM->Q_Seikyu->FieldByName("��������z")->AsCurrency == 0){
		GroupFooterSeikyu->Enabled = false;
	}else{
		GroupFooterSeikyu->Enabled = div_total;
	}
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupHeaderSeikyuBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	//
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupHeader1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 2)
		ShokeiLabel1->Caption = "";
	else if (DM->Q_Seikyu->FieldByName(name1)->AsString.SubString(1, 4) != "����")
		ShokeiLabel1->Caption = "�� " + DM->Q_Seikyu->FieldByName(name1)->AsString;
	else
		ShokeiLabel1->Caption = "�� ���� �y���@�v�z";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupHeader2BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 2)
		ShokeiLabel2->Caption = "";
	else if (DM->Q_Seikyu->FieldByName(name2)->AsString.SubString(1, 4) != "����")
		ShokeiLabel2->Caption = "[" + DM->Q_Seikyu->FieldByName(name2)->AsString + "]";
	else
		ShokeiLabel2->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupHeader3BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name3)->AsString.SubString(1, 4) != "����")
		ShokeiLabel3->Caption = "[" + DM->Q_Seikyu->FieldByName(name3)->AsString + "]";
	else
		ShokeiLabel3->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupHeader4BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name4)->AsString.SubString(1, 4) != "����")
		ShokeiLabel4->Caption = "[" + DM->Q_Seikyu->FieldByName(name4)->AsString + "]";
	else
		ShokeiLabel4->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupHeader5BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name5)->AsString.SubString(1, 4) != "����")
		ShokeiLabel5->Caption = "[" + DM->Q_Seikyu->FieldByName(name5)->AsString + "]";
	else
		ShokeiLabel5->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::DetailBand1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 1){
		seikyu_kei_ += DM->Q_Seikyu->FieldByName("���z")->AsCurrency;
		kei1_ += DM->Q_Seikyu->FieldByName("���z")->AsCurrency;
		kei2_ += DM->Q_Seikyu->FieldByName("���z")->AsCurrency;
		kei3_ += DM->Q_Seikyu->FieldByName("���z")->AsCurrency;
		kei4_ += DM->Q_Seikyu->FieldByName("���z")->AsCurrency;
		kei5_ += DM->Q_Seikyu->FieldByName("���z")->AsCurrency;
	}

	// �i�ږ��̂̃t�H���g�T�C�Y
	QRDBTextHinName->Font->Size = DM->Q_Seikyu->FieldByName("�i�ږ���")->AsString.Length() <= 30 ? 10 : DM->Q_Seikyu->FieldByName("�i�ږ���")->AsString.Length() <= 35 ? 9 : 7;
	// ���l�̃t�H���g�T�C�Y
	QRDBTextBiko->Font->Size = DM->Q_Seikyu->FieldByName(QRDBTextBiko->DataField)->AsString.Length() <= 15 ? 10 : DM->Q_Seikyu->FieldByName(QRDBTextBiko->DataField)->AsString.Length() <= 18 ? 9 : 7;

	// ���ʁA�P�ʁA�P���͓����̏ꍇ�\�����Ȃ�
	QRDBTextSuryo->Enabled = DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 1 ? true : false;
	QRDBTextTani->Enabled  = DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 1 ? true : false;
	QRDBTextTanka->Enabled = DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 1 ? true : false;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupFooter5BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	ShokeiLabel5->Font->Size = ShokeiLabel5->Caption.Length() <= 30 ? 10 : ShokeiLabel5->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupFooter4BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	ShokeiLabel4->Font->Size = ShokeiLabel4->Caption.Length() <= 30 ? 10 : ShokeiLabel4->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupFooter3BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	ShokeiLabel3->Font->Size = ShokeiLabel3->Caption.Length() <= 30 ? 10 : ShokeiLabel3->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupFooter2BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	ShokeiLabel2->Font->Size = ShokeiLabel2->Caption.Length() <= 30 ? 10 : ShokeiLabel2->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupFooter1BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	ShokeiLabel1->Font->Size = ShokeiLabel1->Caption.Length() <= 30 ? 10 : ShokeiLabel1->Caption.Length() <= 35 ? 9 : 7;
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoTateForm::GroupFooterSeikyuBeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	UriageGokeiLabel->Caption = FormatFloat("#,##0", seikyu_kei_);
	seikyu_kei_ = 0;
}
//---------------------------------------------------------------------------

