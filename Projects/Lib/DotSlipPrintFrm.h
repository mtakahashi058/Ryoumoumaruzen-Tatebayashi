//---------------------------------------------------------------------------

#ifndef DotSlipPrintFrmH
#define DotSlipPrintFrmH
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
class TDotSlipPrintForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *QRBand1;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
    TQRDBText *Row1CodeText;
    TQRDBText *Row1NameText;
    TQRDBText *Row3CodeText;
    TQRDBText *Row3NameText;
    TQRDBText *Row2CodeText;
    TQRDBText *Row2NameText;
    TQRDBText *GrossTimeText;
    TQRDBText *GrossWText;
    TQRDBText *TareWText;
    TQRDBText *NetWText;
	TQRLabel *QRLabel1;
    TADOQuery *Q_Slip;
    TAutoIncField *Q_SlipID;
    TIntegerField *Q_SlipDSDesigner;
    TIntegerField *Q_SlipDSDesigner2;
    TIntegerField *Q_SlipDSDesigner3;
    TIntegerField *Q_SlipDSDesigner4;
    TIntegerField *Q_SlipID2;
    TStringField *Q_SlipDSDesigner5;
    TIntegerField *Q_SlipNo;
    TIntegerField *Q_SlipDSDesigner6;
    TStringField *Q_SlipDSDesigner7;
    TIntegerField *Q_SlipID3;
    TIntegerField *Q_SlipDSDesigner8;
    TStringField *Q_SlipDSDesigner9;
    TIntegerField *Q_SlipID4;
    TIntegerField *Q_SlipDSDesigner10;
    TStringField *Q_SlipDSDesigner11;
    TStringField *Q_SlipDSDesigner12;
    TStringField *Q_SlipDSDesigner13;
    TStringField *Q_SlipDSDesigner14;
    TIntegerField *Q_SlipDSDesigner1ID;
    TIntegerField *Q_SlipDSDesigner1;
    TStringField *Q_SlipDSDesigner15;
    TStringField *Q_SlipDSDesigner16;
    TStringField *Q_SlipDSDesigner17;
    TStringField *Q_SlipDSDesigner18;
    TIntegerField *Q_SlipDSDesigner2ID;
    TIntegerField *Q_SlipDSDesigner22;
    TStringField *Q_SlipDSDesigner23;
    TStringField *Q_SlipDSDesigner24;
    TStringField *Q_SlipDSDesigner25;
    TStringField *Q_SlipDSDesigner26;
    TStringField *Q_SlipDSDesigner19;
    TBCDField *Q_SlipDSDesigner20;
    TIntegerField *Q_SlipNo2;
    TIntegerField *Q_SlipID5;
    TIntegerField *Q_SlipDSDesigner21;
    TStringField *Q_SlipDSDesigner27;
    TStringField *Q_SlipDSDesigner28;
    TStringField *Q_SlipDSDesigner29;
    TStringField *Q_SlipDSDesigner30;
    TAutoIncField *Q_SlipID6;
    TIntegerField *Q_SlipDSDesigner31;
    TStringField *Q_SlipDSDesigner32;
    TStringField *Q_SlipDSDesigner33;
    TStringField *Q_SlipDSDesigner34;
    TBCDField *Q_SlipDSDesigner110;
    TDateTimeField *Q_SlipDSDesigner111;
    TBCDField *Q_SlipDSDesigner210;
    TDateTimeField *Q_SlipDSDesigner211;
    TBCDField *Q_SlipDSDesigner35;
    TBCDField *Q_SlipDSDesigner36;
    TBCDField *Q_SlipDSDesigner37;
    TBCDField *Q_SlipDSDesigner38;
    TBCDField *Q_SlipDSDesigner39;
    TIntegerField *Q_SlipID7;
    TIntegerField *Q_SlipDSDesigner40;
    TStringField *Q_SlipDSDesigner41;
    TBCDField *Q_SlipDSDesigner42;
    TBCDField *Q_SlipDSDesigner43;
    TBCDField *Q_SlipDSDesigner44;
    TStringField *Q_SlipDSDesigner45;
    TIntegerField *Q_SlipDSDesigner46;
    TStringField *Q_SlipDSDesigner47;
    TDateTimeField *Q_SlipDSDesigner48;
    TDateTimeField *Q_SlipDSDesigner49;
    TIntegerField *Q_SlipDSDesigner50;
    TQRDBText *Row4CodeText;
    TQRDBText *Row4NameText;
    TQRDBText *TareTimeText;
    TQRExpr *AmountText;
    TQRDBText *QuantityText;
    TQRLabel *QRLabel2;
    TQRDBText *UnitText;
    TQRLabel *YenLabel;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
private:	// ユーザー宣言
    bool kingaku_print1_;
public:		// ユーザー宣言
	__fastcall TDotSlipPrintForm(TComponent* Owner);
	bool __fastcall Print(int keiryo_id, bool hide_time = false);
};
//---------------------------------------------------------------------------
extern PACKAGE TDotSlipPrintForm *DotSlipPrintForm;
//---------------------------------------------------------------------------
#endif
