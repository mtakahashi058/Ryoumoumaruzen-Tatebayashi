//---------------------------------------------------------------------------

#ifndef QRBankFrmH
#define QRBankFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TQRBankForm : public TForm
{
__published:	// IDE 管理のコンポーネント
      TQuickRep *QuickRep;
      TQRBand *PageHeaderBand1;
      TQRLabel *TitleLabel;
      TQRSysData *QRSysData1;
      TQRSysData *QRSysData2;
      TQRLabel *QRLabel2;
      TQRShape *QRShape1;
      TQRShape *QRShape2;
      TQRLabel *QRLabel5;
      TQRBand *DetailBand1;
      TQRDBText *QRDBText2;
      TQRShape *QRShape3;
      TQRDBText *QRDBText3;
      TQRLabel *QRLabel1;
      TQRLabel *QRLabel3;
      TQRDBText *QRDBText1;
      TQRDBText *QRDBText4;
      TQRLabel *QRLabel4;
      TQRLabel *QRLabel7;
      TQRDBText *QRDBText5;
      TQRDBText *QRDBText6;
private:	// ユーザー宣言
public:		// ユーザー宣言
      __fastcall TQRBankForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRBankForm *QRBankForm;
//---------------------------------------------------------------------------
#endif
