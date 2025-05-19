//---------------------------------------------------------------------------

#ifndef QRLedgerFrmH
#define QRLedgerFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQRLedgerForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *QRPHeader;
	TQRSysData *QRSysData1;
	TQRLabel *TitleLabel;
	TQRLabel *RangeLabel;
	TQRSysData *QRSysData2;
	TQRBand *QRBand1;
	TQRShape *QRShape43;
	TQRShape *QRShape1;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel10;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText6;
	TQRLabel *QRLabel11;
	TQRDBText *QRDBText8;
	TQRLabel *QRLabel12;
	TQRDBText *QRDBText9;
	TQRLabel *QRLabel13;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText10;
	TQRDBText *QRDBText11;
	TQRDBText *QRDBText12;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRLedgerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRLedgerForm *QRLedgerForm;
//---------------------------------------------------------------------------
#endif
