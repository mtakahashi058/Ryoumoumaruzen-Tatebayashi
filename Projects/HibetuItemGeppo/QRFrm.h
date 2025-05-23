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
	TQRLabel *TitleLabel;
	TQRSysData *QRSysData2;
	TADOQuery *Query;
	TIntegerField *QueryDSDesigner01;
	TIntegerField *QueryDSDesigner02;
	TIntegerField *QueryDSDesigner03;
	TIntegerField *QueryDSDesigner04;
	TIntegerField *QueryDSDesigner05;
	TIntegerField *QueryDSDesigner06;
	TIntegerField *QueryDSDesigner07;
	TIntegerField *QueryDSDesigner08;
	TIntegerField *QueryDSDesigner09;
	TIntegerField *QueryDSDesigner10;
	TIntegerField *QueryDSDesigner11;
	TIntegerField *QueryDSDesigner12;
	TIntegerField *QueryDSDesigner13;
	TIntegerField *QueryDSDesigner14;
	TIntegerField *QueryDSDesigner15;
	TIntegerField *QueryDSDesigner16;
	TIntegerField *QueryDSDesigner17;
	TIntegerField *QueryDSDesigner18;
	TIntegerField *QueryDSDesigner19;
	TIntegerField *QueryDSDesigner20;
	TIntegerField *QueryDSDesigner21;
	TIntegerField *QueryDSDesigner22;
	TIntegerField *QueryDSDesigner23;
	TIntegerField *QueryDSDesigner24;
	TIntegerField *QueryDSDesigner25;
	TIntegerField *QueryDSDesigner26;
	TIntegerField *QueryDSDesigner27;
	TIntegerField *QueryDSDesigner28;
	TIntegerField *QueryDSDesigner29;
	TIntegerField *QueryDSDesigner30;
	TIntegerField *QueryDSDesigner31;
	TQRLabel *DateLabel01;
	TQRLabel *QRLabel3;
	TQRSysData *QRSysData1;
	TQRBand *DetailBand1;
	TQRDBText *ItemNameText;
	TQRLabel *QRLabel7;
	TQRLabel *QRLabel8;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRLabel *DateLabel03;
	TQRLabel *DateLabel04;
	TQRLabel *DateLabel05;
	TQRLabel *DateLabel09;
	TQRLabel *DateLabel08;
	TQRLabel *DateLabel07;
	TQRLabel *DateLabel06;
	TQRShape *QRShape2;
	TQRLabel *DateLabel10;
	TQRLabel *DateLabel11;
	TQRLabel *DateLabel12;
	TQRLabel *DateLabel13;
	TQRLabel *DateLabel14;
	TQRLabel *DateLabel15;
	TQRLabel *DateLabel19;
	TQRLabel *DateLabel18;
	TQRLabel *DateLabel17;
	TQRLabel *DateLabel16;
	TQRLabel *DateLabel20;
	TQRLabel *DateLabel21;
	TQRLabel *DateLabel22;
	TQRLabel *DateLabel23;
	TQRLabel *DateLabel24;
	TQRLabel *DateLabel25;
	TQRLabel *DateLabel29;
	TQRLabel *DateLabel28;
	TQRLabel *DateLabel27;
	TQRLabel *DateLabel26;
	TQRLabel *DateLabel30;
	TQRLabel *DateLabel31;
	TQRLabel *QRLabel39;
	TQRLabel *DateLabel02;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText10;
	TQRDBText *QRDBText11;
	TQRDBText *QRDBText14;
	TQRDBText *QRDBText15;
	TQRDBText *QRDBText16;
	TQRDBText *QRDBText17;
	TQRDBText *QRDBText18;
	TQRDBText *QRDBText19;
	TQRDBText *QRDBText20;
	TQRDBText *QRDBText21;
	TQRDBText *QRDBText22;
	TQRDBText *QRDBText23;
	TQRDBText *QRDBText24;
	TQRDBText *QRDBText25;
	TQRDBText *QRDBText26;
	TQRDBText *QRDBText27;
	TQRDBText *QRDBText28;
	TQRDBText *QRDBText29;
	TQRDBText *QRDBText30;
	TQRDBText *QRDBText31;
	TQRDBText *QRDBText32;
	TQRDBText *QRDBText33;
	TQRDBText *QRDBText34;
	TQRDBText *QRDBText35;
	TQRDBText *QRDBText36;
	TQRDBText *QRDBText37;
	TQRDBText *QRDBText38;
	TQRDBText *QRDBText39;
	TQRDBText *QRDBText40;
	TQRDBText *QRDBText41;
	TQRDBText *QRDBText42;
	TQRDBText *QRDBText43;
	TQRDBText *QRDBText44;
	TQRDBText *QRDBText45;
	TQRDBText *QRDBText46;
	TQRDBText *QRDBText47;
	TQRDBText *QRDBText48;
	TQRDBText *QRDBText49;
	TQRDBText *QRDBText50;
	TQRDBText *QRDBText51;
	TQRDBText *QRDBText52;
	TQRDBText *QRDBText53;
	TQRDBText *QRDBText54;
	TQRDBText *QRDBText55;
	TQRDBText *QRDBText56;
	TQRDBText *QRDBText57;
	TQRDBText *QRDBText58;
	TQRDBText *QRDBText59;
	TQRDBText *QRDBText60;
	TQRDBText *QRDBText61;
	TQRDBText *QRDBText62;
	TQRDBText *QRDBText63;
	TQRDBText *QRDBText64;
	TQRDBText *QRDBText65;
	TQRShape *QRShape1;
	TQRShape *QRShape3;
	TQRLabel *RangeLabel;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	TQRShape *QRShape8;
	TQRShape *QRShape9;
	TQRShape *QRShape10;
	TQRShape *QRShape11;
	TQRShape *QRShape12;
	TQRShape *QRShape13;
	TQRShape *QRShape14;
	TQRShape *QRShape15;
	TQRShape *QRShape16;
	TQRShape *QRShape17;
	TQRShape *QRShape18;
	TQRShape *QRShape19;
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
	TQRShape *QRShape39;
	TQRShape *QRShape40;
	TQRLabel *ItemLabel;
	TQRShape *QRShape41;
	TQRLabel *QRLabel10;
	TQRShape *QRShape42;
	TQRExpr *QRExpr65;
	TQRExpr *QRExpr66;
	TQRShape *QRShape43;
	TQRDBText *QRDBText66;
	TQRShape *QRShape4;
	TQRShape *QRShape44;
	TQRShape *QRShape45;
	TQRShape *QRShape46;
	TQRShape *QRShape7;
	TQRShape *QRShape47;
	TQRShape *QRShape48;
	TQRShape *QRShape49;
	TQRLabel *QRLabel11;
	TQRDBText *QRDBText67;
	TQRDBText *QRDBText68;
	TQRDBText *QRDBText69;
	TQRDBText *QRDBText70;
	TQRDBText *QRDBText71;
	TQRDBText *QRDBText72;
	TQRDBText *QRDBText73;
	TQRDBText *QRDBText74;
	TQRDBText *QRDBText75;
	TQRDBText *QRDBText76;
	TQRDBText *QRDBText77;
	TQRDBText *QRDBText78;
	TQRDBText *QRDBText79;
	TQRDBText *QRDBText80;
	TQRDBText *QRDBText81;
	TQRDBText *QRDBText82;
	TQRDBText *QRDBText83;
	TQRDBText *QRDBText84;
	TQRDBText *QRDBText85;
	TQRDBText *QRDBText86;
	TQRDBText *QRDBText87;
	TQRDBText *QRDBText88;
	TQRDBText *QRDBText89;
	TQRDBText *QRDBText90;
	TQRDBText *QRDBText91;
	TQRDBText *QRDBText92;
	TQRDBText *QRDBText93;
	TQRDBText *QRDBText94;
	TQRDBText *QRDBText95;
	TQRDBText *QRDBText96;
	TQRExpr *QRExpr67;
	TIntegerField *QueryID;
	TIntegerField *QueryDSDesigner;
	TStringField *QueryDSDesigner2;
	TBCDField *QueryDSDesigner012;
	TBCDField *QueryDSDesigner022;
	TBCDField *QueryDSDesigner032;
	TBCDField *QueryDSDesigner042;
	TBCDField *QueryDSDesigner052;
	TBCDField *QueryDSDesigner062;
	TBCDField *QueryDSDesigner072;
	TBCDField *QueryDSDesigner082;
	TBCDField *QueryDSDesigner092;
	TBCDField *QueryDSDesigner102;
	TBCDField *QueryDSDesigner112;
	TBCDField *QueryDSDesigner122;
	TBCDField *QueryDSDesigner132;
	TBCDField *QueryDSDesigner142;
	TBCDField *QueryDSDesigner152;
	TBCDField *QueryDSDesigner162;
	TBCDField *QueryDSDesigner172;
	TBCDField *QueryDSDesigner182;
	TBCDField *QueryDSDesigner192;
	TBCDField *QueryDSDesigner202;
	TBCDField *QueryDSDesigner212;
	TBCDField *QueryDSDesigner222;
	TBCDField *QueryDSDesigner232;
	TBCDField *QueryDSDesigner242;
	TBCDField *QueryDSDesigner252;
	TBCDField *QueryDSDesigner262;
	TBCDField *QueryDSDesigner272;
	TBCDField *QueryDSDesigner282;
	TBCDField *QueryDSDesigner292;
	TBCDField *QueryDSDesigner302;
	TBCDField *QueryDSDesigner312;
	TBCDField *QueryDSDesigner013;
	TBCDField *QueryDSDesigner023;
	TBCDField *QueryDSDesigner033;
	TBCDField *QueryDSDesigner043;
	TBCDField *QueryDSDesigner053;
	TBCDField *QueryDSDesigner063;
	TBCDField *QueryDSDesigner073;
	TBCDField *QueryDSDesigner083;
	TBCDField *QueryDSDesigner093;
	TBCDField *QueryDSDesigner103;
	TBCDField *QueryDSDesigner113;
	TBCDField *QueryDSDesigner123;
	TBCDField *QueryDSDesigner133;
	TBCDField *QueryDSDesigner143;
	TBCDField *QueryDSDesigner153;
	TBCDField *QueryDSDesigner163;
	TBCDField *QueryDSDesigner173;
	TBCDField *QueryDSDesigner183;
	TBCDField *QueryDSDesigner193;
	TBCDField *QueryDSDesigner203;
	TBCDField *QueryDSDesigner213;
	TBCDField *QueryDSDesigner223;
	TBCDField *QueryDSDesigner233;
	TBCDField *QueryDSDesigner243;
	TBCDField *QueryDSDesigner253;
	TBCDField *QueryDSDesigner263;
	TBCDField *QueryDSDesigner273;
	TBCDField *QueryDSDesigner283;
	TBCDField *QueryDSDesigner293;
	TBCDField *QueryDSDesigner303;
	TBCDField *QueryDSDesigner313;
	TQRBand *GroupFooterBand;
	TQRLabel *QRLabel2;
	TQRLabel *QRLabel9;
	TQRExpr *QRExpr100;
	TQRExpr *QRExpr101;
	TQRExpr *QRExpr102;
	TQRExpr *QRExpr103;
	TQRExpr *QRExpr104;
	TQRExpr *QRExpr105;
	TQRExpr *QRExpr106;
	TQRExpr *QRExpr107;
	TQRExpr *QRExpr108;
	TQRExpr *QRExpr109;
	TQRExpr *QRExpr110;
	TQRExpr *QRExpr111;
	TQRExpr *QRExpr112;
	TQRExpr *QRExpr113;
	TQRExpr *QRExpr114;
	TQRExpr *QRExpr115;
	TQRExpr *QRExpr116;
	TQRExpr *QRExpr117;
	TQRExpr *QRExpr118;
	TQRExpr *QRExpr119;
	TQRExpr *QRExpr120;
	TQRExpr *QRExpr121;
	TQRExpr *QRExpr122;
	TQRExpr *QRExpr123;
	TQRExpr *QRExpr124;
	TQRExpr *QRExpr125;
	TQRExpr *QRExpr126;
	TQRExpr *QRExpr127;
	TQRExpr *QRExpr128;
	TQRExpr *QRExpr129;
	TQRExpr *QRExpr130;
	TQRExpr *QRExpr131;
	TQRExpr *QRExpr132;
	TQRExpr *QRExpr133;
	TQRExpr *QRExpr134;
	TQRExpr *QRExpr135;
	TQRExpr *QRExpr136;
	TQRExpr *QRExpr137;
	TQRExpr *QRExpr138;
	TQRExpr *QRExpr139;
	TQRExpr *QRExpr140;
	TQRExpr *QRExpr141;
	TQRExpr *QRExpr142;
	TQRExpr *QRExpr143;
	TQRExpr *QRExpr144;
	TQRExpr *QRExpr145;
	TQRExpr *QRExpr146;
	TQRExpr *QRExpr147;
	TQRExpr *QRExpr148;
	TQRExpr *QRExpr149;
	TQRExpr *QRExpr150;
	TQRExpr *QRExpr151;
	TQRExpr *QRExpr152;
	TQRExpr *QRExpr153;
	TQRExpr *QRExpr154;
	TQRExpr *QRExpr155;
	TQRExpr *QRExpr156;
	TQRExpr *QRExpr157;
	TQRExpr *QRExpr158;
	TQRExpr *QRExpr159;
	TQRExpr *QRExpr160;
	TQRExpr *QRExpr161;
	TQRExpr *QRExpr162;
	TQRExpr *QRExpr163;
	TQRLabel *ItemTotalLabel;
	TQRLabel *QRLabel13;
	TQRExpr *QRExpr164;
	TQRExpr *QRExpr165;
	TQRExpr *QRExpr166;
	TQRExpr *QRExpr167;
	TQRExpr *QRExpr168;
	TQRExpr *QRExpr169;
	TQRExpr *QRExpr170;
	TQRExpr *QRExpr171;
	TQRExpr *QRExpr172;
	TQRExpr *QRExpr173;
	TQRExpr *QRExpr174;
	TQRExpr *QRExpr175;
	TQRExpr *QRExpr176;
	TQRExpr *QRExpr177;
	TQRExpr *QRExpr178;
	TQRExpr *QRExpr179;
	TQRExpr *QRExpr180;
	TQRExpr *QRExpr181;
	TQRExpr *QRExpr182;
	TQRExpr *QRExpr183;
	TQRExpr *QRExpr184;
	TQRExpr *QRExpr185;
	TQRExpr *QRExpr186;
	TQRExpr *QRExpr187;
	TQRExpr *QRExpr188;
	TQRExpr *QRExpr189;
	TQRExpr *QRExpr190;
	TQRExpr *QRExpr191;
	TQRExpr *QRExpr192;
	TQRExpr *QRExpr193;
	TQRExpr *QRExpr194;
	TQRExpr *QRExpr195;
	TQRGroup *GroupHeaderBand;
	TADOQuery *TotalQuery;
	TIntegerField *IntegerField3;
	TIntegerField *IntegerField4;
	TIntegerField *IntegerField5;
	TIntegerField *IntegerField6;
	TIntegerField *IntegerField7;
	TIntegerField *IntegerField8;
	TIntegerField *IntegerField9;
	TIntegerField *IntegerField10;
	TIntegerField *IntegerField11;
	TIntegerField *IntegerField12;
	TIntegerField *IntegerField13;
	TIntegerField *IntegerField14;
	TIntegerField *IntegerField15;
	TIntegerField *IntegerField16;
	TIntegerField *IntegerField17;
	TIntegerField *IntegerField18;
	TIntegerField *IntegerField19;
	TIntegerField *IntegerField20;
	TIntegerField *IntegerField21;
	TIntegerField *IntegerField22;
	TIntegerField *IntegerField23;
	TIntegerField *IntegerField24;
	TIntegerField *IntegerField25;
	TIntegerField *IntegerField26;
	TIntegerField *IntegerField27;
	TIntegerField *IntegerField28;
	TIntegerField *IntegerField29;
	TIntegerField *IntegerField30;
	TIntegerField *IntegerField31;
	TIntegerField *IntegerField32;
	TIntegerField *IntegerField33;
	TBCDField *BCDField1;
	TBCDField *BCDField2;
	TBCDField *BCDField3;
	TBCDField *BCDField4;
	TBCDField *BCDField5;
	TBCDField *BCDField6;
	TBCDField *BCDField7;
	TBCDField *BCDField8;
	TBCDField *BCDField9;
	TBCDField *BCDField10;
	TBCDField *BCDField11;
	TBCDField *BCDField12;
	TBCDField *BCDField13;
	TBCDField *BCDField14;
	TBCDField *BCDField15;
	TBCDField *BCDField16;
	TBCDField *BCDField17;
	TBCDField *BCDField18;
	TBCDField *BCDField19;
	TBCDField *BCDField20;
	TBCDField *BCDField21;
	TBCDField *BCDField22;
	TBCDField *BCDField23;
	TBCDField *BCDField24;
	TBCDField *BCDField25;
	TBCDField *BCDField26;
	TBCDField *BCDField27;
	TBCDField *BCDField28;
	TBCDField *BCDField29;
	TBCDField *BCDField30;
	TBCDField *BCDField31;
	TBCDField *BCDField32;
	TBCDField *BCDField33;
	TBCDField *BCDField34;
	TBCDField *BCDField35;
	TBCDField *BCDField36;
	TBCDField *BCDField37;
	TBCDField *BCDField38;
	TBCDField *BCDField39;
	TBCDField *BCDField40;
	TBCDField *BCDField41;
	TBCDField *BCDField42;
	TBCDField *BCDField43;
	TBCDField *BCDField44;
	TBCDField *BCDField45;
	TBCDField *BCDField46;
	TBCDField *BCDField47;
	TBCDField *BCDField48;
	TBCDField *BCDField49;
	TBCDField *BCDField50;
	TBCDField *BCDField51;
	TBCDField *BCDField52;
	TBCDField *BCDField53;
	TBCDField *BCDField54;
	TBCDField *BCDField55;
	TBCDField *BCDField56;
	TBCDField *BCDField57;
	TBCDField *BCDField58;
	TBCDField *BCDField59;
	TBCDField *BCDField60;
	TBCDField *BCDField61;
	TBCDField *BCDField62;
	TQRLabel *QRLabel1;
	TQRDBText *ItemCodeText;
	void __fastcall QuickRepBeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
private:	// ユーザー宣言
	TQRLabel *dt_label[31];
public:		// ユーザー宣言
	__fastcall TQRForm(TComponent* Owner);
	TDateTime DT;

	AnsiString __fastcall GetWeekStr(int no);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
