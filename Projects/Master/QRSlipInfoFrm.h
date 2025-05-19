//---------------------------------------------------------------------------

#ifndef QRSlipInfoFrmH
#define QRSlipInfoFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TQRSlipInfoForm : public TForm
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
      TQRLabel *QRLabel4;
      TQRBand *DetailBand1;
      TQRDBText *QRDBText1;
      TQRDBText *QRDBText2;
      TQRShape *QRShape3;
      TQRDBText *QRDBText3;
      TQRDBText *QRDBText4;
      TQRDBText *QRDBText8;
      TQRDBText *QRDBText6;
      TQRDBText *QRDBText7;
      TQRDBText *QRDBText9;
      TQRDBText *QRDBText10;
      TQRDBText *QRDBText11;
      TQRDBText *QRDBText12;
      TQRDBText *QRDBText5;
      TQRDBText *QRDBText13;
      TQRLabel *QRLabel1;
      TQRLabel *QRLabel5;
      TQRLabel *QRLabel7;
      TQRLabel *QRLabel8;
      TQRLabel *QRLabel9;
      TQRLabel *QRLabel10;
      TQRLabel *QRLabel11;
      TQRLabel *QRLabel12;
      TQRLabel *QRLabel13;
      TQRLabel *QRLabel14;
      TQRLabel *QRLabel15;
      TQRLabel *QRLabel16;
private:	// ユーザー宣言
public:		// ユーザー宣言
      __fastcall TQRSlipInfoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRSlipInfoForm *QRSlipInfoForm;
//---------------------------------------------------------------------------
#endif
