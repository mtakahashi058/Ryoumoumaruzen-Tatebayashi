//---------------------------------------------------------------------------

#ifndef QRKanzanFrmH
#define QRKanzanFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQRKanzanForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRBand *DetailBand1;
	TQRLabel *TitleLabel;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel18;
	TQRLabel *QRLabel19;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText18;
	TQRDBText *QRDBText19;
	TQRShape *QRShape3;
	TQRLabel *TokuisakiLabel;
	TQRLabel *HinmokuLabel;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText8;
	TQRLabel *QRLabel1;
	TQRDBText *QRDBText1;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRKanzanForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRKanzanForm *QRKanzanForm;
//---------------------------------------------------------------------------
#endif
