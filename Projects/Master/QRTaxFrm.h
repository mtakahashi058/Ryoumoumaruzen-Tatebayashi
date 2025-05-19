//---------------------------------------------------------------------------

#ifndef QRTaxFrmH
#define QRTaxFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TQRTaxForm : public TForm
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
private:	// ユーザー宣言
public:		// ユーザー宣言
      __fastcall TQRTaxForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRTaxForm *QRTaxForm;
//---------------------------------------------------------------------------
#endif
