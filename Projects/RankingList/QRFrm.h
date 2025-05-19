//---------------------------------------------------------------------------

#ifndef QRFrmH
#define QRFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TQRForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRBand *DetailBand1;
	TQRSysData *QRSysData2;
	TQRSysData *QRSysData1;
	TQRLabel *TitleLabel;
	TQRLabel *RangeLabel;
	TQRShape *QRShape1;
	TQRLabel *QRLabel1;
	TQRShape *QRShape2;
	TQRShape *QRShape3;
	TADOQuery *Query;
	TIntegerField *QueryDSDesigner;
	TBCDField *QueryDSDesigner3;
	TBCDField *QueryDSDesigner4;
	TQRLabel *lblRank;
	TQRLabel *KomokuLabel;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel4;
	TQRDBText *QRDBText4;
	TStringField *QueryDSDesigner2;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
	int rank;
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
