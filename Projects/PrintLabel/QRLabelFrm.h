//---------------------------------------------------------------------------

#ifndef QRLabelFrmH
#define QRLabelFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TQRLabelForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *DetailBand1;
	TADOQuery *Q_Label;
	TQRDBText *QRDBText1;
	TQRLabel *TokuName1;
	TQRLabel *TokuName2;
	TQRLabel *lblYubin;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TQRLabelForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRLabelForm *QRLabelForm;
//---------------------------------------------------------------------------
#endif
