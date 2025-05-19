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
#include <QRCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TQRForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRBand *DetailBand1;
	TQRLabel *QRLabel1;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRShape *QRShape3;
	TQRLabel *QRLabel3;
	TQRLabel *RangeLabel;
	TADOQuery *Query_;
        TQRLabel *QRLabel2;
        TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TIntegerField *Query_ID;
	TStringField *Query_DSDesigner2;
	TStringField *Query_DSDesigner3;
	TIntegerField *Query_DSDesigner4;
	TStringField *Query_DSDesigner5;
	TIntegerField *Query_DSDesigner6;
	TIntegerField *Query_DSDesigner7;
	TStringField *Query_DSDesigner8;
	TIntegerField *Query_DSDesigner9;
	TStringField *Query_DSDesigner10;
	TBCDField *Query_DSDesigner62;
	TBCDField *Query_DSDesigner52;
	TBCDField *Query_DSDesigner42;
	TBCDField *Query_DSDesigner32;
	TBCDField *Query_DSDesigner22;
	TBCDField *Query_DSDesigner1;
	TBCDField *Query_DSDesigner15;
	TStringField *Query_StringField1;
	TStringField *Query_StringField2;
	TQRLabel *QRLabel4;
	TQRDBText *QRDBText3;
	TQRLabel *QRLabel7;
	TQRDBText *QRDBText4;
	TQRLabel *QRLabel10;
	TQRDBText *QRDBText5;
	TQRGroup *QRGroup1;
	TQRLabel *QRLabel12;
	TQRDBText *QRDBText6;
	TIntegerField *Query_DSDesigner16;
	TQRLabel *QRLabel13;
	TQRLabel *QRLabel14;
	TQRLabel *QRLabel15;
	TQRLabel *QRLabel16;
	TQRLabel *QRLabel17;
	TQRLabel *QRLabel26;
	TQRLabel *QRLabel27;
	TQRLabel *QRLabel28;
	TQRLabel *QRLabel29;
	TQRDBText *QRDBTextZan6;
	TCurrencyField *Query_Field6;
	TCurrencyField *Query_Field5;
	TCurrencyField *Query_Field4;
	TCurrencyField *Query_Field3;
	TCurrencyField *Query_Field2;
	TCurrencyField *Query_Field1;
	TQRDBText *QRDBTextZan5;
	TQRDBText *QRDBTextZan4;
	TQRDBText *QRDBTextZan3;
	TQRDBText *QRDBTextZan2;
	TQRDBText *QRDBTextZan1;
	TQRDBText *QRDBTextZan0;
	TQRDBText *QRDBText14;
	TBCDField *Query_DSDesigner0;
	TCurrencyField *Query_Field0;
	TQRDBText *QRDBText15;
	TIntegerField *Query_DSDesigner17;
	TQRLabel *MonthLabel1;
	TQRLabel *MonthLabel2;
	TQRLabel *MonthLabel3;
	TQRLabel *MonthLabel4;
	TQRLabel *MonthLabel5;
	TQRLabel *MonthLabel6;
	TQRLabel *MonthLabel7;
	TBCDField *Query_DSDesigner02;
	TCurrencyField *Query_Field;
	TIntegerField *Query_DSDesigner;
	TADODataSet *Query;
	TIntegerField *QueryID;
	TIntegerField *QueryDSDesigner;
	TStringField *QueryDSDesigner2;
	TStringField *QueryDSDesigner3;
	TIntegerField *QueryDSDesigner4;
	TStringField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TIntegerField *QueryDSDesigner7;
	TStringField *QueryDSDesigner8;
	TIntegerField *QueryDSDesigner9;
	TStringField *QueryDSDesigner10;
	TIntegerField *QueryDSDesigner11;
	TBCDField *QueryDSDesigner62;
	TBCDField *QueryDSDesigner52;
	TBCDField *QueryDSDesigner42;
	TBCDField *QueryDSDesigner32;
	TBCDField *QueryDSDesigner22;
	TBCDField *QueryDSDesigner1;
	TBCDField *QueryDSDesigner0;
	TBCDField *QueryDSDesigner02;
	TBCDField *QueryDSDesigner12;
	TIntegerField *QueryDSDesigner13;
	TCurrencyField *QueryField6;
	TCurrencyField *QueryField5;
	TCurrencyField *QueryField4;
	TCurrencyField *QueryField3;
	TCurrencyField *QueryField2;
	TCurrencyField *QueryField1;
	TCurrencyField *QueryField0;
	TCurrencyField *QueryField;
	TStringField *QueryStringField1;
	TStringField *QueryStringField2;
	TQRShape *QRShape4;
	TQRDBText *QRDBText16;
	TQRShape *QRShape5;
	TQRBand *SummaryBand1;
	TQRLabel *QRLabel5;
	TQRShape *QRShape6;
	TQRExpr *QRExpr1;
	TQRExpr *QRExpr2;
	TQRExpr *QRExpr3;
	TQRExpr *QRExpr4;
	TQRExpr *QRExpr5;
	TQRExpr *QRExpr6;
	TQRExpr *QRExpr7;
	TQRExpr *QRExpr8;
	TQRExpr *QRExpr9;
	TQRShape *QRShape8;
	void __fastcall Query_CalcFields(TDataSet *DataSet);
	void __fastcall QueryCalcFields(TDataSet *DataSet);
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);

private:	// ユーザー宣言
	AnsiString field_name[2][7];
	Currency kuri[7];
	TColor __fastcall GetLabelColor(int label_no, int site_month, int site_date);
	
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
