//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include "QRFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRForm *QRForm;
//---------------------------------------------------------------------------
__fastcall TQRForm::TQRForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QuickRepBeforePrint(TCustomQuickRep *Sender,
      bool &PrintReport)
{
	QRGroupFooter2->Height = 0;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QRGroup1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	zan = Query->FieldByName("�O���c��")->AsCurrency;
	ZenZanLabel->Caption = FormatFloat("#,##0", zan);

	uri = 0;
	nyukin = 0;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QRGroup2BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	if (Query->FieldByName("���Ӑ挏��")->AsInteger > 1)
		QRGroup2->Enabled = true;
	else
		QRGroup2->Enabled = false;

	if (Query->FieldByName("�敪")->AsString == "����")
		TokuNameText->Enabled = false;
	else
		TokuNameText->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::DetailBandBeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	if (Query->FieldByName("�敪")->AsString == "����")
		QRChildBand->Enabled = true;
	else
		QRChildBand->Enabled = false;

	if (Query->FieldByName("�敪")->AsString == "����" || Query->FieldByName("�敪")->AsString == "����"){
		UriLabel->Caption    = FormatFloat("#,##0", Query->FieldByName("���z")->AsCurrency);
		NyukinLabel->Caption = AnsiString();
		zan += Query->FieldByName("���z")->AsCurrency;
		uri += Query->FieldByName("���z")->AsCurrency;

	}else if (Query->FieldByName("�敪")->AsString == "����"){
		UriLabel->Caption    = AnsiString();
		NyukinLabel->Caption = FormatFloat("#,##0", Query->FieldByName("���z")->AsCurrency);
		zan -= Query->FieldByName("���z")->AsCurrency;
		nyukin += Query->FieldByName("���z")->AsCurrency;
	}else{
		UriLabel->Caption    = AnsiString();
		NyukinLabel->Caption = AnsiString();
	}
	ZanLabel->Caption = FormatFloat("#,##0", zan);
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QRChildBandBeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	SeikyuLabel->Caption = FormatFloat("#,##0", zan);
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QRGroupFooter2BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	QRGroup2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QRGroupFooter1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	UriKeiLabel->Caption    = FormatFloat("#,##0", uri);
	NyukinKeiLabel->Caption = FormatFloat("#,##0", nyukin);
	ZanKeiLabel->Caption    = FormatFloat("#,##0", zan);
}
//---------------------------------------------------------------------------

