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
	TQRLabel *Item3Label;
	TADOQuery *Query_;
	TQRLabel *WeightLabel;
	TQRLabel *AmountLabel;
	TQRLabel *MoneyLabel;
	TQRLabel *TaniLabel;
	TIntegerField *Query_DSDesigner3;
	TBCDField *Query_DSDesigner4;
	TBCDField *Query_DSDesigner5;
	TIntegerField *Query_DSDesigner6;
	TStringField *Query_DSDesigner7;
	TBCDField *Query_DSDesigner8;
	TQRDBText *ItemText3;
	TQRBand *SummaryBand1;
	TQRDBText *WeightText;
	TQRDBText *AmountText;
	TQRDBText *TaniText;
	TQRDBText *MoneyText;
	TQRLabel *QRLabel1;
	TQRExpr *QRExpr1;
	TQRExpr *MoneyExpr;
	TQRDBText *QRDBText1;
	TQRLabel *QRLabel2;
	TQRDBText *QRDBText2;
	TQRExpr *QRExpr2;
	TQRShape *QRShape4;
	TQRGroup *Item1GroupHeaderBand;
	TQRBand *Item1GroupFooterBand;
	TQRDBText *ItemText1;
	TQRDBText *QRDBText4;
	TQRLabel *Item1Label;
	TQRLabel *SumItem1Label;
	TQRExpr *QRExpr3;
	TQRExpr *Item1MoneyExpr;
	TQRExpr *QRExpr5;
	TIntegerField *Query_DSDesigner1;
	TStringField *Query_DSDesigner12;
	TIntegerField *Query_DSDesigner2;
	TStringField *Query_DSDesigner22;
	TIntegerField *Query_DSDesigner32;
	TStringField *Query_DSDesigner33;
	TQRGroup *Item2GroupHeaderBand;
	TQRDBText *ItemText2;
	TQRDBText *QRDBText6;
	TQRBand *Item2GroupFooterBand;
	TQRLabel *SumItem2Label;
	TQRExpr *QRExpr4;
	TQRExpr *Item2MoneyExpr;
	TQRExpr *QRExpr7;
	TQRLabel *Item2Label;
	TIntegerField *Query_ID1;
	TIntegerField *Query_ID2;
	TIntegerField *Query_ID3;
	TStringField *Query_ID;
	TQRShape *QRShape3;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	TADODataSet *Query;
	TIntegerField *QueryID1;
	TIntegerField *QueryDSDesigner1;
	TStringField *QueryDSDesigner12;
	TIntegerField *QueryID2;
	TIntegerField *QueryDSDesigner2;
	TStringField *QueryDSDesigner22;
	TIntegerField *QueryID3;
	TIntegerField *QueryDSDesigner3;
	TStringField *QueryDSDesigner32;
	TIntegerField *QueryDSDesigner;
	TBCDField *QueryDSDesigner4;
	TBCDField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TStringField *QueryDSDesigner7;
	TBCDField *QueryDSDesigner8;
	TStringField *QueryID;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
