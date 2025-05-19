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
	TQRLabel *Item2CodeLabel;
	TQRLabel *Item2NameLabel;
	TQRLabel *Item3CodeLabel;
	TQRLabel *Item3NameLabel;
	TQRLabel *DateLabel;
	TQRLabel *NoLabel;
	TQRLabel *AmountLabel;
	TQRLabel *TaniLabel;
	TQRLabel *ShabanLabel;
	TQRLabel *PriceLabel;
	TQRLabel *MoneyLabel;
	TQRDBText *Item2CodeText;
	TQRDBText *Item2NameText;
	TQRDBText *Item3CodeText;
	TQRDBText *Item3NameText;
	TQRDBText *DateText;
	TQRDBText *NoText;
	TQRDBText *ShabanText;
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
	TIntegerField *QueryNo;
	TIntegerField *QueryDSDesigner3;
	TBCDField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TStringField *QueryDSDesigner7;
	TBCDField *QueryDSDesigner8;
	TBCDField *QueryDSDesigner9;
	TQRLabel *TitleLabel;
	TQRSysData *QRSysData1;
	TQRLabel *RangeLabel;
	TQRSysData *QRSysData2;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TIntegerField *QueryNo2;
	TQRDBText *LineNoText;
	TQRExpr *Item2MoneyExpr;
	TQRLabel *SumItem2Label;
	TQRExpr *Item1MoneyExpr;
	TQRLabel *SumItem1Label;
	TQRExpr *MoneyExpr;
	TQRLabel *QRLabel4;
	TADOQuery *MeigaraQuery;
	TIntegerField *MeigaraQueryDSDesigner;
	TStringField *MeigaraQueryDSDesigner2;
	TBCDField *MeigaraQueryDSDesigner4;
	TQRShape *QRShape3;
	TQRShape *QRShape4;
	TQRLabel *LineNoLabel;
	TQRLabel *Item1Label;
	TQRGroup *Item3GroupHeaderBand;
	TQRBand *Item3GroupFooterBand;
	TQRExpr *Item3MoneyExpr;
	TQRLabel *SumItem3Label;
	TIntegerField *QueryID3;
	TIntegerField *QueryDSDesigner32;
	TStringField *QueryDSDesigner33;
	TIntegerField *QueryDSDesigner;
	TIntegerField *MeigaraQueryDSDesigner3;
	TStringField *MeigaraQueryDSDesigner5;
	TBCDField *MeigaraQueryDSDesigner6;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	TQRShape *QRShape7;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
	void __fastcall DetailBandBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall PageHeaderBandBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall Item1GroupHeaderBandBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
	int old_item1_, old_item2_, old_item3_, old_date_;
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);

	AnsiString ITEM1;
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
