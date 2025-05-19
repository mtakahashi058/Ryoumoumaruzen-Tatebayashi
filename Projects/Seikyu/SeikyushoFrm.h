//---------------------------------------------------------------------------

#ifndef SeikyushoFrmH
#define SeikyushoFrmH
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
#include <Graphics.hpp>
#include <DBCtrls.hpp>
#include <jpeg.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TSeikyushoForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRGroup *GroupHeaderSeikyu;
	TQRGroup *GroupHeaderGenb;
	TQRBand *DetailBand1;
	TQRDBText *QRDBText2;
	TQRDBText *YubinLabel;
	TQRLabel *QRLabel2;
	TQRLabel *YubinTLabel;
	TQRDBText *DateDBText;
	TQRDBText *QRDBTextSuryo;
	TQRDBText *QRDBText16;
	TQRDBText *QRDBText17;
	TQRDBText *QRDBTextKingaku;
	TQRLabel *KingakuLabel6;
	TQRBand *GroupFooterGenb;
	TQRLabel *GFGLabel;
	TQRLabel *PageNumberLabel;
	TQRLabel *KingakuLabel1;
	TQRLabel *KingakuLabel2;
	TQRLabel *KingakuLabel3;
	TQRLabel *KingakuLabel4;
	TQRLabel *KingakuLabel5;
	TADOQuery *Q_Seikyu;
	TQRLabel *HakkobiLabel;
	TQRLabel *TitleLabel;
	TQRLabel *QRLabel4;
	TQRLabel *SeikyumotoLabel01;
	TQRLabel *SeikyumotoLabel02;
	TQRShape *QRShape3;
	TQRLabel *QRLabel15;
	TQRLabel *QRLabel17;
	TQRLabel *QRLabel18;
	TQRLabel *QRLabel19;
	TQRLabel *QRLabel20;
	TQRLabel *QRLabel21;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	TQRShape *QRShape7;
	TQRShape *QRShape8;
	TQRShape *QRShape9;
	TQRShape *QRShape11;
	TQRLabel *QRLabel22;
	TQRDBText *QRDBText1;
	TQRLabel *QRLabel23;
	TQRShape *QRShape4;
	TQRLabel *QRLabel24;
	TQRShape *QRShape12;
	TQRLabel *KingakuLabel7;
	TQRShape *QRShape13;
	TQRShape *QRShape15;
	TQRShape *QRShape16;
	TQRShape *QRShape17;
	TQRShape *QRShape18;
	TQRShape *QRShape20;
	TQRShape *QRShape21;
	TQRShape *QRShape22;
	TQRShape *QRShape23;
	TQRShape *QRShape24;
	TQRShape *QRShape25;
	TQRShape *QRShape26;
	TQRShape *QRShape27;
	TQRShape *QRShape28;
	TQRShape *QRShape29;
	TQRShape *QRShape30;
	TQRShape *QRShape31;
	TQRShape *QRShape32;
	TQRShape *QRShape33;
	TQRShape *QRShape34;
	TQRShape *QRShape35;
	TQRShape *QRShape36;
	TQRShape *QRShape37;
	TQRShape *QRShape38;
	TQRLabel *SeikyumotoLabel03;
	TQRLabel *SeikyumotoLabel04;
	TQRLabel *SeikyumotoLabel05;
	TQRLabel *SeikyumotoLabel06;
	TQRLabel *SeikyumotoLabel07;
	TQRLabel *SeikyumotoLabel08;
	TQRLabel *SeikyumotoLabel09;
	TQRLabel *SeikyumotoLabel10;
	TQRShape *QRShape14;
	TQRShape *QRShape39;
	TQRBand *GroupFooterSeikyu;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel27;
	TQRLabel *QRLabel37;
	TQRLabel *ShohizeiLabel;
	TQRLabel *TotalLabel;
	TQRImage *QRImage2;
	TQRImage *QRImage1;
	TQRImage *QRImage3;
	TQRShape *QRShape19;
	TQRLabel *QRLabel31;
	TQRLabel *QRLabel32;
	TQRLabel *QRLabel33;
	TQRLabel *QRLabel34;
	TQRLabel *QRLabel35;
	TQRLabel *QRLabel29;
	TQRLabel *QRLabel30;
	TQRLabel *HurikaeCodeLabel;
	TQRLabel *HikiwatasibiLabel;
	TQRLabel *AddressLabel1;
	TQRLabel *AddressLabel2;
	TQRLabel *AddressLabel3;
	TQRLabel *SeikyusakiLabel1;
	TQRLabel *SeikyusakiLabel2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBTextBiko;
	TBCDField *Q_SeikyuDSDesigner;
	TBCDField *Q_SeikyuDSDesigner2;
	TBCDField *Q_SeikyuDSDesigner3;
	TIntegerField *Q_SeikyuID;
	TStringField *Q_SeikyuDSDesigner4;
	TStringField *Q_SeikyuDSDesigner5;
	TStringField *Q_SeikyuDSDesigner6;
	TStringField *Q_SeikyuDSDesigner7;
	TStringField *Q_SeikyuDSDesigner1;
	TStringField *Q_SeikyuDSDesigner22;
	TIntegerField *Q_SeikyuDSDesigner8;
	TStringField *Q_SeikyuDSDesigner9;
	TIntegerField *Q_SeikyuDSDesigner10;
	TIntegerField *Q_SeikyuDSDesigner11;
	TIntegerField *Q_SeikyuDSDesigner12;
	TIntegerField *Q_SeikyuDSDesigner13;
	TStringField *Q_SeikyuDSDesigner14;
	TIntegerField *Q_SeikyuDSDesigner15;
	TStringField *Q_SeikyuDSDesigner16;
	TIntegerField *Q_SeikyuDSDesigner17;
	TStringField *Q_SeikyuDSDesigner18;
	TBCDField *Q_SeikyuDSDesigner19;
	TIntegerField *Q_SeikyuDSDesigner20;
	TBCDField *Q_SeikyuDSDesigner21;
	TBCDField *Q_SeikyuDSDesigner23;
	TBCDField *Q_SeikyuDSDesigner24;
	TBCDField *Q_SeikyuDSDesigner25;
	TBCDField *Q_SeikyuDSDesigner26;
	TBCDField *Q_SeikyuDSDesigner27;
	TBCDField *Q_SeikyuDSDesigner28;
	TIntegerField *Q_SeikyuDSDesigner29;
	TStringField *Q_SeikyuDSDesigner30;
	TStringField *Q_SeikyuDSDesigner31;
	TStringField *Q_SeikyuDSDesigner33;
	TBCDField *Q_SeikyuDSDesigner34;
	TIntegerField *Q_SeikyuDSDesigner35;
	TStringField *Q_SeikyuDSDesigner36;
	TBCDField *Q_SeikyuDSDesigner37;
	TBCDField *Q_SeikyuDSDesigner38;
	TStringField *Q_SeikyuDSDesigner39;
	TQRLabel *UriageGokeiLabel;
	TIntegerField *Q_SeikyuID2;
	TQRLabel *TokuisakiLabel;
	TIntegerField *Q_SeikyuDSDesigner32;
	TQRLabel *FooterLabel;
	TQRLabel *GenbKeiLabel;
	TQRGroup *QRGroupKenmei;
	TIntegerField *Q_SeikyuID3;
	TStringField *Q_SeikyuDSDesigner40;
	TQRLabel *KenmeiLabel;
	TIntegerField *Q_SeikyuDSDesigner41;
	TIntegerField *Q_SeikyuID4;
	TQRLabel *HonshaLabel;
	TQRLabel *DainiLabel;
	TQRLabel *SeikyuNoLabel;
	TIntegerField *Q_SeikyuID5;
	TIntegerField *Q_SeikyuNO;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
	  bool &PrintReport);
	void __fastcall PageHeaderBand1BeforePrint(TQRCustomBand *Sender,
	  bool &PrintBand);
	void __fastcall GroupHeaderGenbBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooterSeikyuBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooterGenbBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall QRGroupKenmeiBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
	AnsiString old_seikyu_code_;
	int old_month_, old_day_, old_slip_no_, page_no_;
	Currency uriage_;
	Currency genb_kei_;
public:		// ユーザー宣言
	__fastcall TSeikyushoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSeikyushoForm *SeikyushoForm;
//---------------------------------------------------------------------------
#endif
