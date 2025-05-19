//---------------------------------------------------------------------------

#ifndef QRTaniFrmH
#define QRTaniFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQRTaniForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRBand *DetailBand1;
	TQRLabel *QRLabel1;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel18;
	TQRLabel *QRLabel19;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText18;
	TQRDBText *QRDBText19;
	TQRShape *QRShape3;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRTaniForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRTaniForm *QRTaniForm;
//---------------------------------------------------------------------------
#endif
