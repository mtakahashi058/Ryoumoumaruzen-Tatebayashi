//---------------------------------------------------------------------------

#ifndef SeikyushoTateFrmH
#define SeikyushoTateFrmH
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
class TSeikyushoTateForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand;
	TQRGroup *GroupHeaderSeikyu;
	TQRGroup *GroupHeader1;
	TQRBand *DetailBand1;
	TQRDBText *QRDBText2;
	TQRLabel *QRLabel2;
	TQRDBText *DateDBText;
	TQRDBText *QRDBTextSuryo;
	TQRDBText *QRDBTextTani;
	TQRDBText *QRDBTextTanka;
	TQRDBText *QRDBTextKingaku;
	TQRBand *GroupFooter1;
	TQRLabel *ShokeiLabel1;
	TQRLabel *PageNumberLabel;
	TQRLabel *DateLabel;
	TQRLabel *TitleLabel;
	TQRLabel *QRLabel4;
	TQRShape *QRShapeTate01;
	TQRShape *QRShapeTate03;
	TQRShape *QRShapeTate04;
	TQRShape *QRShapeTate05;
	TQRShape *QRShapeTate06;
	TQRShape *QRShapeWaku;
	TQRShape *QRShapeTate02;
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
	TQRDBText *QRDBTextHinName;
	TQRDBText *QRDBTextBiko;
	TQRLabel *UriageGokeiLabel;
	TQRLabel *Message3Label;
	TQRGroup *GroupHeader2;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRShape *QRShape10;
	TQRShape *QRShape40;
	TQRShape *QRShape41;
	TQRShape *QRShape42;
	TQRShape *QRShape43;
	TQRShape *QRShape44;
	TQRShape *QRShape45;
	TQRShape *QRShape46;
	TQRShape *QRShape47;
	TQRShape *QRShape48;
	TQRShape *QRShape49;
	TQRShape *QRShape50;
	TQRShape *QRShape51;
	TQRShape *QRShape52;
	TQRShape *QRShape53;
	TQRGroup *GroupHeader3;
	TQRGroup *GroupHeader4;
	TQRGroup *GroupHeader5;
	TQRBand *GroupFooter2;
	TQRLabel *ShokeiLabel2;
	TQRBand *GroupFooter3;
	TQRLabel *ShokeiLabel3;
	TQRBand *GroupFooter4;
	TQRLabel *ShokeiLabel4;
	TQRBand *GroupFooter5;
	TQRLabel *ShokeiLabel5;
	TQRExpr *QRExpr1;
	TQRExpr *QRExpr2;
	TQRExpr *QRExpr3;
	TQRExpr *QRExpr4;
	TQRExpr *QRExpr5;
	TQRShape *ColorShape;
	TQRLabel *QRLabel3;
	TQRLabel *QRLabel5;
	TQRLabel *QRLabel6;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRLabel *QRLabel9;
	TQRLabel *QRLabel10;
	TQRLabel *QRLabel11;
	TQRLabel *QRLabel12;
	TQRLabel *QRLabel13;
	TQRLabel *QRLabel14;
	TQRLabel *QRLabel15;
	TQRChildBand *QRChildBand1;
	TQRShape *QRShape3;
	TQRShape *QRShape12;
	TQRShape *ColorShape1;
	TQRDBText *YubinDBLabel;
	TQRLabel *YubinTLabel;
	TQRLabel *KingakuLabel6;
	TQRLabel *KingakuLabel1;
	TQRLabel *KingakuLabel2;
	TQRLabel *KingakuLabel3;
	TQRLabel *KingakuLabel4;
	TQRLabel *KingakuLabel5;
	TQRLabel *ShameiLabel;
	TQRLabel *SeikyumotoLabel02;
	TQRLabel *KagamiLabel06;
	TQRLabel *KagamiLabel01;
	TQRLabel *KagamiLabel02;
	TQRLabel *KagamiLabel03;
	TQRLabel *KagamiLabel04;
	TQRLabel *KagamiLabel05;
	TQRShape *QRShape6;
	TQRShape *QRShape7;
	TQRShape *QRShape8;
	TQRShape *QRShape9;
	TQRLabel *QRLabel22;
	TQRDBText *QRDBText1;
	TQRLabel *Message1Label;
	TQRShape *ColorShape2;
	TQRLabel *KagamiLabel07;
	TQRLabel *KingakuLabel7;
	TQRLabel *SeikyumotoLabel03;
	TQRLabel *SeikyumotoLabel04;
	TQRLabel *SeikyumotoLabel05;
	TQRLabel *SeikyumotoLabel06;
	TQRLabel *SeikyumotoLabel07;
	TQRLabel *SeikyumotoLabel08;
	TQRLabel *SeikyumotoLabel01;
	TQRShape *ColorShape3;
	TQRLabel *MeiTitleLabel01;
	TQRLabel *MeiTitleLabel02;
	TQRLabel *MeiTitleLabel03;
	TQRLabel *MeiTitleLabel04;
	TQRLabel *MeiTitleLabel05;
	TQRLabel *MeiTitleLabel06;
	TQRLabel *MeiTitleLabel07;
	TQRLabel *Message2Label;
	TQRLabel *SeikyusakiLabel;
	TQRShape *QRShape5;
	TQRDBText *Add1DBLabel;
	TQRDBText *Add2DBLabel;
	TQRChildBand *QRChildBand2;
	TQRShape *ColorShape3_;
	TQRLabel *SeikyusakiLabel_;
	TQRShape *QRShapeLine11;
	TQRShape *QRShapeLine10;
	TQRShape *QRShapeLine09;
	TQRShape *QRShapeLine08;
	TQRShape *QRShapeLine07;
	TQRShape *QRShapeLine06;
	TQRShape *QRShapeLine05;
	TQRShape *QRShapeLine04;
	TQRShape *QRShapeLine03;
	TQRShape *QRShapeLine02;
	TQRShape *QRShapeLine01;
	TQRShape *QRShapeLine12;
	TQRLabel *MeiTitleLabel01_;
	TQRLabel *MeiTitleLabel02_;
	TQRLabel *MeiTitleLabel03_;
	TQRLabel *MeiTitleLabel04_;
	TQRLabel *MeiTitleLabel05_;
	TQRLabel *MeiTitleLabel06_;
	TQRLabel *MeiTitleLabel07_;
	TQRShape *QRShape19;
	TQRShape *QRShape54;
	TQRShape *ColorShape4;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
	  bool &PrintReport);
	void __fastcall PageHeaderBandBeforePrint(TQRCustomBand *Sender,
	  bool &PrintBand);
	void __fastcall GroupHeader1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooterSeikyuBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupHeader2BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupHeader3BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupHeader4BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupHeader5BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooter5BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooter4BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooter3BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooter2BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupFooter1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
	void __fastcall GroupHeaderSeikyuBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ユーザー宣言
	AnsiString old_seikyu_code_;
	int page_no_;
	Currency seikyu_kei_, kei1_, kei2_, kei3_, kei4_, kei5_;

public:		// ユーザー宣言
	__fastcall TSeikyushoTateForm(TComponent* Owner);
	AnsiString name1, name2, name3, name4, name5;
	AnsiString komoku1, komoku2, komoku3, komoku4, komoku5;
	bool div_total;
};
//---------------------------------------------------------------------------
extern PACKAGE TSeikyushoTateForm *SeikyushoTateForm;
//---------------------------------------------------------------------------
#endif
