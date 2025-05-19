//---------------------------------------------------------------------------

#ifndef QRFrmH
#define QRFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TQRForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand;
	TQRBand *DetailBand;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRLabel *TitleLabel;
	TQRLabel *RangeLabel;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRLabel *KyotenLabel;
	TADOQuery *Query;
	TQRShape *QRShape3;
	TQRDBText *KyotenText;
	TQRLabel *KeiryobiLabel;
	TQRLabel *SlipNoLabel;
	TQRLabel *IoLabel;
	TQRLabel *ShabanLabel;
	TQRLabel *TokuisakiCodeLabel;
	TQRLabel *TokuisakiNameLabel;
	TQRLabel *Item1CodeLabel;
	TQRLabel *Item1NameLabel;
	TQRLabel *Item2CodeLabel;
	TQRLabel *Item2NameLabel;
	TQRLabel *SlipBikoLabel;
	TQRLabel *SlipTaxLabel;
	TQRLabel *KoshinLabel;
	TQRLabel *SakuseiLabel;
	TQRLabel *LineNoLabel;
	TQRLabel *HinmokuCodeLabel;
	TQRLabel *HinmokuNameLabel;
	TQRLabel *SuryoLabel;
	TQRLabel *TaniLabel;
	TQRLabel *PriceLabel;
	TQRLabel *MoneyLabel;
	TQRLabel *DetailTaxLabel;
	TQRLabel *DetailBikoLabel;
	TQRDBText *KeiryobiText;
	TQRDBText *SlipNoText;
	TQRDBText *LineNoText;
	TQRDBText *IoText;
	TQRDBText *ShabanText;
	TQRDBText *TokuisakiCodeText;
	TQRDBText *QRDBText8;
	TQRDBText *TokuisakiNameText;
	TQRDBText *PriceText;
	TQRDBText *Item1CodeText;
	TQRDBText *QRDBText13;
	TQRDBText *Item1NameText;
	TQRDBText *Item2CodeText;
	TQRDBText *QRDBText16;
	TQRDBText *Item2NameText;
	TQRDBText *HinmokuCodeText;
	TQRDBText *QRDBText19;
	TQRDBText *HinmokuNameText;
	TQRDBText *SuryoText;
	TQRDBText *TaniText;
	TQRDBText *MoneyText;
	TQRDBText *DetailTaxText;
	TQRDBText *SlipTaxText;
	TQRDBText *DetailBikoText;
	TQRDBText *SlipBikoText;
	TQRDBText *KoshinText;
	TQRDBText *SakuseiText;
	TQRBand *QRBand1;
	TQRLabel *QRLabel1;
	TQRExpr *QRExpr1;
	TQRExpr *QRExpr2;
	TQRShape *QRShape4;
	TQRLabel *QRLabel2;
	TStringField *QueryDSDesigner;
	TIntegerField *QueryDSDesigner2;
	TIntegerField *QueryNo;
	TStringField *QueryDSDesigner3;
	TStringField *QueryDSDesigner4;
	TIntegerField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TStringField *QueryDSDesigner7;
	TStringField *QueryDSDesigner8;
	TIntegerField *QueryDSDesigner1;
	TStringField *QueryDSDesigner12;
	TStringField *QueryDSDesigner13;
	TIntegerField *QueryDSDesigner22;
	TStringField *QueryDSDesigner23;
	TStringField *QueryDSDesigner24;
	TStringField *QueryDSDesigner9;
	TBCDField *QueryDSDesigner10;
	TIntegerField *QueryNo2;
	TIntegerField *QueryDSDesigner11;
	TStringField *QueryDSDesigner14;
	TStringField *QueryDSDesigner15;
	TIntegerField *QueryDSDesigner16;
	TStringField *QueryDSDesigner17;
	TStringField *QueryDSDesigner18;
	TBCDField *QueryDSDesigner19;
	TIntegerField *QueryDSDesigner20;
	TStringField *QueryDSDesigner21;
	TBCDField *QueryDSDesigner25;
	TBCDField *QueryDSDesigner26;
	TBCDField *QueryDSDesigner27;
	TStringField *QueryDSDesigner28;
	TDateTimeField *QueryDSDesigner29;
	TDateTimeField *QueryDSDesigner30;
	TQRDBText *QRDBText1;
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
