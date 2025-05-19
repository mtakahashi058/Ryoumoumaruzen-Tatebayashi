//---------------------------------------------------------------------------

#ifndef QRSlipInfoRelateFrmH
#define QRSlipInfoRelateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TQRSlipInfoRelateForm : public TForm
{
__published:	// IDE 管理のコンポーネント
      TQuickRep *QuickRep;
      TQRBand *PageHeaderBand1;
      TQRLabel *TitleLabel;
      TQRSysData *QRSysData1;
      TQRSysData *QRSysData2;
      TQRLabel *QRLabel2;
      TQRLabel *QRLabel3;
      TQRShape *QRShape1;
      TQRShape *QRShape2;
      TQRBand *DetailBand1;
      TQRDBText *QRDBText2;
      TQRShape *QRShape3;
      TQRDBText *QRDBText3;
      TQRDBText *QRDBText4;
      TQRDBText *QRDBText1;
      TQRDBText *QRDBText5;
      TQRLabel *QRLabel1;
      TQRLabel *QRLabel4;
      TQRLabel *QRLabel5;
private:	// ユーザー宣言
public:		// ユーザー宣言
      __fastcall TQRSlipInfoRelateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRSlipInfoRelateForm *QRSlipInfoRelateForm;
//---------------------------------------------------------------------------
#endif
