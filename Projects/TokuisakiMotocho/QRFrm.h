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
	TQRBand *DetailBand;
	TQRLabel *QRLabel1;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRShape *QRShape3;
	TADOQuery *Query;
	TQRGroup *QRGroup1;
	TQRLabel *QRLabel12;
	TQRShape *QRShape1;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRLabel *QRLabel3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRLabel *QRLabel4;
	TQRLabel *QRLabel7;
	TQRDBText *QRDBText7;
	TQRLabel *QRLabel10;
	TQRLabel *NendoLabel;
	TQRShape *QRShape2;
	TQRLabel *QRLabel15;
	TQRDBText *QRDBText8;
	TQRLabel *QRLabel16;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText10;
	TQRLabel *QRLabel17;
	TQRDBText *QRDBText11;
	TQRLabel *QRLabel26;
	TQRDBText *QRDBText12;
	TQRLabel *QRLabel28;
	TQRShape *QRShape30;
	TQRShape *QRShape31;
	TQRShape *QRShape32;
	TQRShape *QRShape34;
	TQRShape *QRShape35;
	TQRShape *QRShape36;
	TQRLabel *QRLabel14;
	TQRLabel *QRLabel29;
	TQRLabel *QRLabel54;
	TQRLabel *QRLabel55;
	TQRLabel *QRLabel56;
	TQRLabel *QRLabel57;
	TQRLabel *QRLabel59;
	TQRLabel *QRLabel60;
	TQRLabel *QRLabel61;
	TQRShape *QRShape37;
	TQRLabel *ZenZanLabel;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText14;
	TQRDBText *QRDBText15;
	TQRDBText *QRDBText33;
	TQRDBText *QRDBText34;
	TQRLabel *UriLabel;
	TQRLabel *NyukinLabel;
	TQRLabel *ZanLabel;
	TQRChildBand *QRChildBand;
	TQRShape *QRShape33;
	TQRLabel *SeikyuLabel;
	TQRShape *QRShape38;
	TQRGroup *QRGroup2;
	TQRShape *QRShape39;
	TQRDBText *TokuNameText;
	TQRDBText *QRDBText37;
	TQRShape *QRShape40;
	TQRBand *QRGroupFooter1;
	TQRLabel *QRLabel2;
	TQRShape *QRShape41;
	TQRLabel *UriKeiLabel;
	TQRLabel *NyukinKeiLabel;
	TQRLabel *ZanKeiLabel;
	TQRBand *QRGroupFooter2;
	TQRShape *QRShape4;
	TQRShape *QRShape5;
	TQRShape *QRShape7;
	TQRShape *QRShape8;
	TQRShape *QRShape9;
	TQRShape *QRShape10;
	TQRShape *QRShape11;
	TQRShape *QRShape12;
	TBCDField *QueryDSDesigner;
	TBCDField *QueryDSDesigner2;
	TBCDField *QueryDSDesigner3;
	TIntegerField *QueryID;
	TIntegerField *QueryDSDesigner4;
	TStringField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TIntegerField *QueryDSDesigner7;
	TStringField *QueryDSDesigner8;
	TStringField *QueryDSDesigner9;
	TStringField *QueryDSDesigner10;
	TStringField *QueryDSDesigner11;
	TStringField *QueryFAX;
	TIntegerField *QueryDSDesigner12;
	TIntegerField *QueryDSDesigner13;
	TIntegerField *QueryDSDesigner14;
	TStringField *QueryDSDesigner15;
	TIntegerField *QueryDSDesigner16;
	TIntegerField *QueryDSDesigner17;
	TStringField *QueryDSDesigner18;
	TIntegerField *QueryDSDesigner19;
	TStringField *QueryDSDesigner20;
	TIntegerField *QueryDSDesigner21;
	TBCDField *QueryDSDesigner22;
	TBCDField *QueryDSDesigner23;
	TBCDField *QueryDSDesigner24;
	TBCDField *QueryDSDesigner25;
	TBCDField *QueryDSDesigner26;
	TBCDField *QueryDSDesigner27;
	TIntegerField *QueryDSDesigner28;
	TStringField *QueryDSDesigner29;
	TIntegerField *QueryID2;
	TIntegerField *QueryDSDesigner30;
	TIntegerField *QueryID3;
	TStringField *QueryDSDesigner31;
	TIntegerField *QueryNo;
	TIntegerField *QueryNo2;
	TIntegerField *QueryDSDesigner1;
	TStringField *QueryDSDesigner110;
	TIntegerField *QueryDSDesigner210;
	TStringField *QueryDSDesigner211;
	TIntegerField *QueryDSDesigner32;
	TStringField *QueryDSDesigner33;
	TIntegerField *QueryDSDesigner34;
	TStringField *QueryDSDesigner35;
	TBCDField *QueryDSDesigner36;
	TIntegerField *QueryDSDesigner37;
	TStringField *QueryDSDesigner38;
	TBCDField *QueryDSDesigner39;
	TBCDField *QueryDSDesigner40;
	TIntegerField *QueryDSDesigner41;
	TStringField *QueryDSDesigner42;
	void __fastcall DetailBandBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall QRGroup1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall QRChildBandBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall QRGroup2BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall QRGroupFooter1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall QRGroupFooter2BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
private:	// ユーザー宣言
	Currency zan, uri, nyukin;
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
