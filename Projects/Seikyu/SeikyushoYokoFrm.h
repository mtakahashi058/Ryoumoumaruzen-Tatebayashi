//---------------------------------------------------------------------------

#ifndef SeikyushoYokoFrmH
#define SeikyushoYokoFrmH
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
class TSeikyushoYokoForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand1;
	TQRGroup *GroupHeaderSeikyu;
	TQRGroup *GroupHeader1;
	TQRBand *DetailBand1;
	TQRDBText *QRDBText2;
	TQRDBText *YubinDBLabel;
	TQRLabel *QRLabel2;
	TQRLabel *YubinTLabel;
	TQRDBText *DateDBText;
	TQRDBText *QRDBTextSuryo;
	TQRDBText *QRDBTextTani;
	TQRDBText *QRDBTextTanka;
	TQRDBText *QRDBTextKingaku;
	TQRLabel *KingakuLabel6;
	TQRBand *GroupFooter1;
	TQRLabel *ShokeiLabel1;
	TQRLabel *PageNumberLabel;
	TQRLabel *KingakuLabel1;
	TQRLabel *KingakuLabel2;
	TQRLabel *KingakuLabel3;
	TQRLabel *KingakuLabel4;
	TQRLabel *KingakuLabel5;
	TQRLabel *DateLabel;
	TQRLabel *TitleLabel;
	TQRLabel *QRLabel4;
	TQRLabel *ShameiLabel;
	TQRLabel *SeikyumotoLabel02;
	TQRShape *QRShape3;
	TQRLabel *KagamiLabel06;
	TQRLabel *KagamiLabel01;
	TQRLabel *KagamiLabel02;
	TQRLabel *KagamiLabel03;
	TQRLabel *KagamiLabel04;
	TQRLabel *KagamiLabel05;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	TQRShape *QRShape7;
	TQRShape *QRShape8;
	TQRShape *QRShape9;
	TQRShape *ColorShape1;
	TQRLabel *QRLabel22;
	TQRDBText *QRDBText1;
	TQRLabel *Message1Label;
	TQRShape *ColorShape2;
	TQRLabel *KagamiLabel07;
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
	TQRLabel *SeikyumotoLabel01;
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
	TQRDBText *QRDBTextHinName;
	TQRDBText *QRDBTextBiko;
	TQRLabel *UriageGokeiLabel;
	TQRLabel *Message3Label;
	TQRGroup *GroupHeader2;
	TQRShape *QRShape1;
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
	TQRDBText *Add1DBLabel;
	TQRDBText *Add2DBLabel;
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
	TQRImage *QRImage3;
	TQRShape *QRShape2;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
	  bool &PrintReport);
	void __fastcall PageHeaderBand1BeforePrint(TQRCustomBand *Sender,
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
	__fastcall TSeikyushoYokoForm(TComponent* Owner);
	AnsiString name1, name2, name3, name4, name5;
	AnsiString komoku1, komoku2, komoku3, komoku4, komoku5;
	bool div_total;
};
//---------------------------------------------------------------------------
extern PACKAGE TSeikyushoYokoForm *SeikyushoYokoForm;
//---------------------------------------------------------------------------
#endif
