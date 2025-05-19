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
//---------------------------------------------------------------------------
class TQRForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand;
	TQRBand *DetailBand;
	TQRLabel *QRLabel1;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRLabel *RangeLabel;
	TQRShape *QRShape1;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel14;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel10;
	TQRLabel *QRLabel11;
	TQRLabel *QRLabel12;
	TQRLabel *QRLabel13;
	TQRLabel *QRLabel15;
	TQRLabel *QRLabel16;
	TQRShape *QRShape2;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText10;
	TQRDBText *QRDBText11;
	TQRDBText *QRDBText12;
	TQRDBText *QRDBText13;
	TQRDBText *QRDBText14;
	TQRDBText *QRDBText15;
	TQRDBText *TegataText;
	TQRShape *QRShape3;
	TQRExpr *SumMoneyExpr;
	TQRLabel *QRLabel2;
	TQRShape *QRShape4;
	TQRDBText *QRDBText5;
	TQRShape *QRShape5;
	TQRBand *SummaryBand1;
	TQRShape *QRShape6;
	TQRExpr *QRExpr1;
	TQRShape *QRShape8;
	TQRExpr *QRExpr2;
	TQRExpr *QRExpr3;
	TQRExpr *QRExpr4;
	TQRExpr *QRExpr5;
	TQRExpr *QRExpr6;
	TQRExpr *QRExpr7;
	TQRExpr *QRExpr8;
	TQRExpr *QRExpr9;
	TQRExpr *QRExpr10;
	TQRLabel *QRLabel17;
	void __fastcall DetailBandBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
