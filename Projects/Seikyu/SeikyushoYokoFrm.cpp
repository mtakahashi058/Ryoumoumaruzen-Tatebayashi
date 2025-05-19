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
	if (old_seikyu_code_ != DM->Q_Seikyu->FieldByName("������R�[�h")->AsString){
		// �P�y�[�W�ڂ́A���o����\������
		YubinTLabel->Enabled   = true;
		YubinDBLabel->Enabled    = true;

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

	PageNumberLabel->Caption  = IntToStr(page_no_) + " ��";

	SeikyusakiLabel->Caption  = DM->Q_Seikyu->FieldByName("�����於��")->AsString + "�@" + DM->Q_Seikyu->FieldByName("�h��")->AsString;
	int len = SeikyusakiLabel->Caption.Length();
	SeikyusakiLabel->Font->Size  = len <= 48 ? 10 : len <= 54 ? 9 : 7;

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
void __fastcall TSeikyushoYokoForm::GroupHeaderSeikyuBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	//
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader1BeforePrint(
	  TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name1)->AsString.SubString(1, 4) != "����")
		ShokeiLabel1->Caption = "[" + DM->Q_Seikyu->FieldByName(name1)->AsString + "]";
	else
		ShokeiLabel1->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader2BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name2)->AsString.SubString(1, 4) != "����")
		ShokeiLabel2->Caption = "[" + DM->Q_Seikyu->FieldByName(name2)->AsString + "]";
	else
		ShokeiLabel2->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader3BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name3)->AsString.SubString(1, 4) != "����")
		ShokeiLabel3->Caption = "[" + DM->Q_Seikyu->FieldByName(name3)->AsString + "]";
	else
		ShokeiLabel3->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader4BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name4)->AsString.SubString(1, 4) != "����")
		ShokeiLabel4->Caption = "[" + DM->Q_Seikyu->FieldByName(name4)->AsString + "]";
	else
		ShokeiLabel4->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::GroupHeader5BeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
	if (DM->Q_Seikyu->FieldByName(name5)->AsString.SubString(1, 4) != "����")
		ShokeiLabel5->Caption = "[" + DM->Q_Seikyu->FieldByName(name5)->AsString + "]";
	else
		ShokeiLabel5->Caption = "[���� �y���@�v�z]";
}
//---------------------------------------------------------------------------
void __fastcall TSeikyushoYokoForm::DetailBand1BeforePrint(
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
	//QRDBTextHinName->Font->Size = DM->Q_Seikyu->FieldByName("�i�ږ���")->AsString.Length() <= 30 ? 10 : DM->Q_Seikyu->FieldByName("�i�ږ���")->AsString.Length() <= 35 ? 9 : 7;

	// ���ʁA�P�ʁA�P���͓����̏ꍇ�\�����Ȃ�
	QRDBTextSuryo->Enabled = DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 1 ? true : false;
	QRDBTextTani->Enabled  = DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 1 ? true : false;
	QRDBTextTanka->Enabled = DM->Q_Seikyu->FieldByName("��������敪")->AsInteger == 1 ? true : false;
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

