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
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel4;
	TIntegerField *QueryDSDesigner;
	TIntegerField *QueryDSDesigner2;
	TBCDField *QueryDSDesigner3;
	TBCDField *QueryDSDesigner4;
	TIntegerField *QueryDSDesigner5;
	TQRLabel *MonthLabel01;
	TQRLabel *JuryoLabel01;
	TQRLabel *KinLabel01;
	TQRShape *QRShape4;
	TQRLabel *MonthLabel02;
	TQRLabel *JuryoLabel02;
	TQRLabel *KinLabel02;
	TQRShape *QRShape5;
	TQRLabel *MonthLabel03;
	TQRLabel *JuryoLabel03;
	TQRLabel *KinLabel03;
	TQRShape *QRShape6;
	TQRLabel *MonthLabel04;
	TQRLabel *JuryoLabel04;
	TQRLabel *KinLabel04;
	TQRShape *QRShape7;
	TQRLabel *MonthLabel05;
	TQRLabel *JuryoLabel05;
	TQRLabel *KinLabel05;
	TQRShape *QRShape8;
	TQRLabel *MonthLabel06;
	TQRLabel *JuryoLabel06;
	TQRLabel *KinLabel06;
	TQRShape *QRShape9;
	TQRLabel *MonthLabel07;
	TQRLabel *JuryoLabel07;
	TQRLabel *KinLabel07;
	TQRShape *QRShape10;
	TQRLabel *MonthLabel08;
	TQRLabel *JuryoLabel08;
	TQRLabel *KinLabel08;
	TQRShape *QRShape11;
	TQRLabel *MonthLabel09;
	TQRLabel *JuryoLabel09;
	TQRLabel *KinLabel09;
	TQRShape *QRShape12;
	TQRLabel *MonthLabel10;
	TQRLabel *JuryoLabel10;
	TQRLabel *KinLabel10;
	TQRShape *QRShape13;
	TQRLabel *MonthLabel11;
	TQRLabel *JuryoLabel11;
	TQRLabel *KinLabel11;
	TQRShape *QRShape14;
	TQRLabel *MonthLabel12;
	TQRLabel *JuryoLabel12;
	TQRLabel *KinLabel12;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
	TQRLabel *lbl[12][3];
	int month[12];

public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
	TDateTime start_date;
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
