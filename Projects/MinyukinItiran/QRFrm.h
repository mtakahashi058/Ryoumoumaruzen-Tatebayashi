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
#include <DBGrids.hpp>
#include <Grids.hpp>
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
        TQRLabel *QRLabel2;
	TQRDBText *QRDBText02;
	TQRDBText *QRDBText01;
	TQRDBText *QRDBText06;
	TADOQuery *Query;
	TQRLabel *QRLabel6;
	TQRDBText *QRDBText04;
	TQRLabel *QRLabel7;
	TQRDBText *QRDBText05;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRShape *QRShape01;
	TQRLabel *QRLabel5;
	TQRShape *QRShape02;
	TIntegerField *QueryID;
	TIntegerField *QueryDSDesigner;
	TStringField *QueryDSDesigner2;
	TIntegerField *QueryDSDesigner3;
	TIntegerField *QueryDSDesigner4;
	TBCDField *QueryDSDesigner5;
	TBCDField *QueryDSDesigner6;
	TBCDField *QueryDSDesigner7;
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
