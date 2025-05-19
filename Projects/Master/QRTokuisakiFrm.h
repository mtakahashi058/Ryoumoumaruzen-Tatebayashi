//---------------------------------------------------------------------------

#ifndef QRTokuisakiFrmH
#define QRTokuisakiFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQRTokuisakiForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRBand *DetailBand1;
	TQRLabel *TitleLabel;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel10;
	TQRLabel *QRLabel11;
	TQRLabel *QRLabel12;
	TQRLabel *QRLabel13;
	TQRLabel *QRLabel14;
	TQRLabel *QRLabel15;
	TQRLabel *QRLabel17;
	TQRLabel *QRLabel18;
	TQRLabel *QRLabel19;
	TQRLabel *QRLabel20;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText10;
	TQRDBText *QRDBText11;
	TQRDBText *QRDBText12;
	TQRDBText *QRDBText13;
	TQRDBText *QRDBText15;
	TQRDBText *QRDBText17;
	TQRDBText *QRDBText18;
	TQRDBText *QRDBText19;
	TQRShape *QRShape3;
	TQRLabel *QRLabel16;
	TQRLabel *QRLabel21;
	TQRLabel *QRLabel22;
	TQRLabel *QRLabel23;
	TQRDBText *QRDBText14;
	TQRDBText *QRDBText16;
	TQRDBText *QRDBText20;
	TQRDBText *QRDBText21;
	TQRDBText *QRDBText22;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRTokuisakiForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRTokuisakiForm *QRTokuisakiForm;
//---------------------------------------------------------------------------
#endif
