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
	TADOQuery *Query;
	TQRLabel *AmountLabel;
	TQRLabel *MoneyLabel;
	TQRLabel *TaniLabel;
	TIntegerField *QueryDSDesigner3;
	TBCDField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TStringField *QueryDSDesigner7;
	TBCDField *QueryDSDesigner8;
	TQRDBText *ItemText3;
	TQRBand *SummaryBand1;
	TQRDBText *AmountText;
	TQRDBText *TaniText;
	TQRDBText *MoneyText;
	TQRLabel *QRLabel1;
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
	TQRExpr *Item1MoneyExpr;
	TQRExpr *QRExpr5;
	TIntegerField *QueryDSDesigner1;
	TStringField *QueryDSDesigner12;
	TIntegerField *QueryDSDesigner2;
	TStringField *QueryDSDesigner22;
	TIntegerField *QueryDSDesigner32;
	TStringField *QueryDSDesigner33;
	TQRGroup *Item2GroupHeaderBand;
	TQRDBText *ItemText2;
	TQRDBText *QRDBText6;
	TQRBand *Item2GroupFooterBand;
	TQRLabel *SumItem2Label;
	TQRExpr *QRExpr6;
	TQRExpr *QRExpr7;
	TQRLabel *Item2Label;
	TIntegerField *QueryID1;
	TIntegerField *QueryID2;
	TIntegerField *QueryID3;
	TStringField *QueryID;
	TQRShape *QRShape3;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
    TQRGroup *TaniGroupHeaderBand;
    TQRBand *TaniGroupFooterBand;
    TQRLabel *QRLabel3;
    TQRExpr *QRExpr1;
    TQRExpr *QRExpr3;
    TQRShape *QRShape7;
    TQRExpr *QRExpr4;
    TQRExpr *QRExpr8;
    void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
