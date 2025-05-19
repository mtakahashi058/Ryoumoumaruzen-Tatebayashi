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
__published:	// IDE 管理のコンポーネント
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
	TQRLabel *FirstWLabel;
	TQRLabel *SecondWLabel;
	TQRLabel *FirstTLabel;
	TQRLabel *SecondTLabel;
	TQRLabel *ChoseiPLabel;
	TQRLabel *ChoseiWLabel;
	TQRLabel *JuryobikiLabel;
	TQRLabel *NetWLabel;
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
	TQRDBText *FirstWText;
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
	TQRDBText *FirstTText;
	TQRDBText *SecondWText;
	TQRDBText *SecondTText;
	TQRDBText *ChoseiPText;
	TQRDBText *ChoseiWText;
	TQRDBText *JuryobikiText;
	TQRDBText *NetWText;
	TQRDBText *SuryoText;
	TQRDBText *TaniText;
	TQRDBText *MoneyText;
	TQRDBText *DetailTaxText;
	TQRDBText *SlipTaxText;
	TQRDBText *DetailBikoText;
	TQRDBText *SlipBikoText;
	TQRDBText *KoshinText;
	TQRDBText *SakuseiText;
	TStringField *QueryDSDesigner;
	TIntegerField *QueryDSDesigner2;
	TIntegerField *QueryNo;
	TStringField *QueryDSDesigner3;
	TIntegerField *QueryDSDesigner4;
	TIntegerField *QueryDSDesigner5;
	TStringField *QueryDSDesigner6;
	TStringField *QueryDSDesigner7;
	TIntegerField *QueryDSDesigner1;
	TStringField *QueryDSDesigner12;
	TStringField *QueryDSDesigner13;
	TIntegerField *QueryDSDesigner22;
	TStringField *QueryDSDesigner23;
	TStringField *QueryDSDesigner24;
	TStringField *QueryDSDesigner8;
	TBCDField *QueryDSDesigner9;
	TIntegerField *QueryNo2;
	TIntegerField *QueryDSDesigner10;
	TStringField *QueryDSDesigner11;
	TStringField *QueryDSDesigner14;
	TBCDField *QueryDSDesigner18;
	TDateTimeField *QueryDSDesigner19;
	TBCDField *QueryDSDesigner25;
	TDateTimeField *QueryDSDesigner26;
	TBCDField *QueryDSDesigner20;
	TBCDField *QueryDSDesigner21;
	TBCDField *QueryDSDesigner27;
	TBCDField *QueryDSDesigner28;
	TBCDField *QueryDSDesigner29;
	TIntegerField *QueryDSDesigner30;
	TStringField *QueryDSDesigner31;
	TBCDField *QueryDSDesigner32;
	TBCDField *QueryDSDesigner33;
	TBCDField *QueryDSDesigner34;
	TStringField *QueryDSDesigner35;
	TDateTimeField *QueryDSDesigner36;
	TDateTimeField *QueryDSDesigner37;
	TQRBand *QRBand1;
	TQRLabel *QRLabel1;
	TQRExpr *QRExpr1;
	TQRExpr *QRExpr2;
	TQRShape *QRShape4;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
