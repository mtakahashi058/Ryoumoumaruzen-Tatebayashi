//---------------------------------------------------------------------------

#ifndef QRSharyoFrmH
#define QRSharyoFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TQRSharyoForm : public TForm
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
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel18;
	TQRLabel *QRLabel19;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText10;
	TQRDBText *QRDBText18;
	TQRDBText *QRDBText19;
	TQRShape *QRShape3;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel5;
	TQRDBText *QRDBText3;
	TQRLabel *TokuisakiLabel;
	TQRLabel *Item1Label;
	TQRLabel *Item2Label;
	TQRLabel *HinmokuLabel;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
      TQRDBText *QRDBText5;
      TQRLabel *QRLabel1;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRSharyoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRSharyoForm *QRSharyoForm;
//---------------------------------------------------------------------------
#endif
