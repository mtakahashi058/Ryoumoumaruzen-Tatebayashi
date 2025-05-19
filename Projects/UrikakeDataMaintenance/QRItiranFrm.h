//---------------------------------------------------------------------------

#ifndef QRItiranFrmH
#define QRItiranFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQRItiranForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRBand *DetailBand1;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRLabel *lblRange;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel10;
	TQRDBText *QRDBText9;
	TQRLabel *QRLabel12;
	TQRDBText *QRDBText11;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRShape *QRShape3;
	TQRDBText *QRDBText2;
	TQRBand *SummaryBand1;
	TQRGroup *QRGroup1;
	TQRDBText *QRDBText1;
	TQRLabel *QRLabel3;
	TQRShape *QRShape4;
	TQRLabel *QRLabel13;
	TQRExpr *QRExpr1;
	TQRShape *QRShape5;
	TQRExpr *QRExpr2;
	TQRExpr *QRExpr4;
	TQRDBText *QRDBText6;
	TQRExpr *QRExpr5;
	TQRExpr *QRExpr6;
	TQRExpr *QRExpr7;
	TQRExpr *QRExpr8;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRItiranForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRItiranForm *QRItiranForm;
//---------------------------------------------------------------------------
#endif
