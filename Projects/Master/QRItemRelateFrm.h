//---------------------------------------------------------------------------

#ifndef QRItemRelateFrmH
#define QRItemRelateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TQRItemRelateForm : public TForm
{
__published:	// IDE 管理のコンポーネント
      TQuickRep *QuickRep;
      TQRBand *PageHeaderBand1;
      TQRLabel *TitleLabel;
      TQRSysData *QRSysData1;
      TQRSysData *QRSysData2;
      TQRLabel *QRLabel3;
      TQRShape *QRShape1;
      TQRShape *QRShape2;
      TQRLabel *TokuisakiNameLabel;
      TQRLabel *QRLabel5;
      TQRBand *DetailBand1;
      TQRDBText *QRDBText2;
      TQRShape *QRShape3;
      TQRDBText *QRDBText3;
      TQRDBText *QRDBText4;
      TQRDBText *QRDBText1;
      TQRDBText *QRDBText5;
      TQRDBText *QRDBText6;
      TQRDBText *QRDBText7;
      TQRDBText *QRDBText8;
      TQRDBText *QRDBText9;
      TQRDBText *QRDBText10;
      TQRDBText *QRDBText11;
      TQRLabel *Item1NameLabel;
      TQRLabel *Item2NameLabel;
      TQRLabel *HinmokuNameLabel;
private:	// ユーザー宣言
public:		// ユーザー宣言
      __fastcall TQRItemRelateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRItemRelateForm *QRItemRelateForm;
//---------------------------------------------------------------------------
#endif
