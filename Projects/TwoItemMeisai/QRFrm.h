//---------------------------------------------------------------------------

#ifndef QRFrmH
#define QRFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQRForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TADOQuery *Query;
	TQRBand *PageHeaderBand;
	TQRBand *DetailBand;
	TQRBand *SummaryBand;
	TQRGroup *Item1GroupHeaderBand;
	TQRGroup *Item2GroupHeaderBand;
	TQRBand *Item1GroupFooterBand;
	TQRBand *Item2GroupFooterBand;
	TQRLabel *ItemCodeLabel;
	TQRLabel *Item1NameLabel;
	TQRLabel *Item2CodeLabel;
	TQRLabel *Item2NameLabel;
	TQRLabel *DateLabel;
	TQRLabel *NoLabel;
	TQRLabel *NetWLabel;
	TQRLabel *AmountLabel;
	TQRLabel *TaniLabel;
	TQRLabel *ShabanLabel;
	TQRLabel *PriceLabel;
	TQRLabel *MoneyLabel;
	TQRDBText *Item1CodeText;
	TQRDBText *Item1NameText;
	TQRDBText *Item2CodeText;
	TQRDBText *Item2NameText;
	TQRDBText *DateText;
	TQRDBText *NoText;
	TQRDBText *ShabanText;
	TQRDBText *NetWText;
	TQRDBText *AmountText;
	TQRDBText *TaniText;
	TQRDBText *PriceText;
	TQRDBText *MoneyText;
	TIntegerField *QueryID1;
	TIntegerField *QueryDSDesigner1;
	TStringField *QueryDSDesigner12;
	TIntegerField *QueryID2;
	TIntegerField *QueryDSDesigner2;
	TStringField *QueryDSDesigner22;
	TIntegerField *QueryDSDesigner;
	TIntegerField *QueryNo;
	TIntegerField *QueryDSDesigner3;
	TBCDField *QueryDSDesigner4;
	TBCDField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TStringField *QueryDSDesigner7;
	TBCDField *QueryDSDesigner8;
	TBCDField *QueryDSDesigner9;
	TStringField *QueryDSDesigner10;
	TQRLabel *TitleLabel;
	TQRSysData *QRSysData1;
	TQRLabel *RangeLabel;
	TQRSysData *QRSysData2;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TIntegerField *QueryNo2;
	TQRDBText *LineNoText;
	TQRExpr *QRExpr1;
	TQRExpr *Item2MoneyExpr;
	TQRLabel *SumItem2Label;
	TQRExpr *QRExpr3;
	TQRExpr *Item1MoneyExpr;
	TQRLabel *SumItem1Label;
	TQRExpr *QRExpr5;
	TQRExpr *MoneyExpr;
	TQRLabel *QRLabel4;
	TADOQuery *MeigaraQuery;
	TIntegerField *MeigaraQueryDSDesigner;
	TStringField *MeigaraQueryDSDesigner2;
	TBCDField *MeigaraQueryDSDesigner3;
	TBCDField *MeigaraQueryDSDesigner4;
	TQRShape *QRShape3;
	TQRShape *QRShape4;
	TQRLabel *LineNoLabel;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
	void __fastcall DetailBandBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
	int old_item1_, old_item2_, old_date_;
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
