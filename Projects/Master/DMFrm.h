//---------------------------------------------------------------------------

#ifndef DMFrmH
#define DMFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
#include "NsDB.h"
#include "NsIni.h"
#include "NsConfig.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#include <map>
typedef std::map<int, int> MasterMap;
//---------------------------------------------------------------------------
#define NEW_CLR	(0x00E8D0B9)
#define MOD_CLR	(0x00BEE7BA)
#define NON_CLR	(clBtnFace)
#ifndef _INPUTMODE_
#define _INPUTMODE_
enum TInputMode{imNew,imMod,imNon};
#endif
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
	TADOQuery *M_Tokuisaki;
	TADOQuery *M_Kyoten;
	TADOQuery *M_Item1;
	TADOQuery *M_Item2;
	TADOQuery *M_Hinmoku;
	TADOQuery *M_Sharyo;
	TADOQuery *M_Kanzan;
	TADOQuery *M_HinBunrui;
	TADOQuery *M_Tani;
	TAutoIncField *M_TokuisakiID;
	TIntegerField *M_TokuisakiDSDesigner;
	TStringField *M_TokuisakiDSDesigner2;
	TStringField *M_TokuisakiDSDesigner3;
	TStringField *M_TokuisakiDSDesigner4;
	TStringField *M_TokuisakiDSDesigner5;
	TStringField *M_TokuisakiDSDesigner1;
	TStringField *M_TokuisakiDSDesigner22;
	TStringField *M_TokuisakiDSDesigner6;
	TStringField *M_TokuisakiFAX;
	TIntegerField *M_TokuisakiID2;
	TIntegerField *M_TokuisakiDSDesigner7;
	TStringField *M_TokuisakiDSDesigner8;
	TStringField *M_TokuisakiDSDesigner9;
	TIntegerField *M_TokuisakiDSDesigner10;
	TStringField *M_TokuisakiDSDesigner11;
	TStringField *M_TokuisakiDSDesigner12;
	TIntegerField *M_TokuisakiDSDesigner13;
	TStringField *M_TokuisakiDSDesigner14;
	TIntegerField *M_TokuisakiDSDesigner15;
	TIntegerField *M_TokuisakiDSDesigner16;
	TStringField *M_TokuisakiDSDesigner17;
	TStringField *M_TokuisakiDSDesigner18;
	TIntegerField *M_TokuisakiDSDesigner19;
	TStringField *M_TokuisakiDSDesigner20;
	TIntegerField *M_TokuisakiDSDesigner21;
	TStringField *M_TokuisakiDSDesigner23;
	TIntegerField *M_TokuisakiDSDesigner24;
	TStringField *M_TokuisakiDSDesigner25;
	TIntegerField *M_TokuisakiDSDesigner26;
	TIntegerField *M_TokuisakiDSDesigner27;
	TStringField *M_TokuisakiDSDesigner28;
	TIntegerField *M_TokuisakiDSDesigner29;
	TStringField *M_TokuisakiDSDesigner30;
	TStringField *M_TokuisakiDSDesigner31;
	TDateTimeField *M_TokuisakiDSDesigner32;
	TDateTimeField *M_TokuisakiDSDesigner33;
	TAutoIncField *M_Item1DSDesigner1ID;
	TIntegerField *M_Item1DSDesigner1;
	TStringField *M_Item1DSDesigner12;
	TStringField *M_Item1DSDesigner13;
	TStringField *M_Item1DSDesigner14;
	TIntegerField *M_Item1DSDesigner;
	TStringField *M_Item1DSDesigner2;
	TStringField *M_Item1DSDesigner3;
	TDateTimeField *M_Item1DSDesigner4;
	TDateTimeField *M_Item1DSDesigner5;
	TAutoIncField *M_Item2DSDesigner2ID;
	TIntegerField *M_Item2DSDesigner2;
	TStringField *M_Item2DSDesigner22;
	TStringField *M_Item2DSDesigner23;
	TStringField *M_Item2DSDesigner24;
	TIntegerField *M_Item2DSDesigner;
	TStringField *M_Item2DSDesigner3;
	TStringField *M_Item2DSDesigner4;
	TDateTimeField *M_Item2DSDesigner5;
	TDateTimeField *M_Item2DSDesigner6;
	TAutoIncField *M_HinBunruiID;
	TIntegerField *M_HinBunruiDSDesigner;
	TStringField *M_HinBunruiDSDesigner2;
	TStringField *M_HinBunruiDSDesigner3;
	TStringField *M_HinBunruiDSDesigner4;
	TIntegerField *M_HinBunruiDSDesigner5;
	TStringField *M_HinBunruiDSDesigner6;
	TStringField *M_HinBunruiDSDesigner7;
	TDateTimeField *M_HinBunruiDSDesigner8;
	TDateTimeField *M_HinBunruiDSDesigner9;
	TAutoIncField *M_HinmokuID;
	TIntegerField *M_HinmokuDSDesigner;
	TStringField *M_HinmokuDSDesigner2;
	TStringField *M_HinmokuDSDesigner3;
	TStringField *M_HinmokuDSDesigner4;
	TIntegerField *M_HinmokuDSDesigner5;
	TStringField *M_HinmokuDSDesigner6;
	TIntegerField *M_HinmokuID2;
	TIntegerField *M_HinmokuDSDesigner7;
	TStringField *M_HinmokuDSDesigner8;
	TStringField *M_HinmokuDSDesigner9;
	TIntegerField *M_HinmokuDSDesigner10;
	TStringField *M_HinmokuDSDesigner11;
	TStringField *M_HinmokuDSDesigner12;
	TDateTimeField *M_HinmokuDSDesigner13;
	TDateTimeField *M_HinmokuDSDesigner14;
	TAutoIncField *M_SharyoID;
	TIntegerField *M_SharyoDSDesigner;
	TStringField *M_SharyoDSDesigner2;
	TBCDField *M_SharyoDSDesigner3;
	TBCDField *M_SharyoDSDesigner5;
	TIntegerField *M_SharyoID2;
	TIntegerField *M_SharyoDSDesigner6;
	TStringField *M_SharyoDSDesigner7;
	TStringField *M_SharyoDSDesigner8;
	TIntegerField *M_SharyoDSDesigner1ID;
	TIntegerField *M_SharyoDSDesigner1;
	TStringField *M_SharyoDSDesigner12;
	TStringField *M_SharyoDSDesigner13;
	TIntegerField *M_SharyoDSDesigner2ID;
	TIntegerField *M_SharyoDSDesigner22;
	TStringField *M_SharyoDSDesigner23;
	TStringField *M_SharyoDSDesigner24;
	TIntegerField *M_SharyoID3;
	TIntegerField *M_SharyoDSDesigner9;
	TStringField *M_SharyoDSDesigner10;
	TStringField *M_SharyoDSDesigner11;
	TDateTimeField *M_SharyoDSDesigner14;
	TDateTimeField *M_SharyoDSDesigner15;
	TAutoIncField *M_KanzanID;
	TIntegerField *M_KanzanID2;
	TIntegerField *M_KanzanDSDesigner;
	TStringField *M_KanzanDSDesigner2;
	TStringField *M_KanzanDSDesigner3;
	TIntegerField *M_KanzanID3;
	TIntegerField *M_KanzanDSDesigner4;
	TStringField *M_KanzanDSDesigner5;
	TStringField *M_KanzanDSDesigner6;
	TIntegerField *M_KanzanID4;
	TIntegerField *M_KanzanDSDesigner7;
	TStringField *M_KanzanDSDesigner8;
	TBCDField *M_KanzanDSDesigner9;
	TDateTimeField *M_KanzanDSDesigner10;
	TDateTimeField *M_KanzanDSDesigner11;
	TAutoIncField *M_KyotenID;
	TIntegerField *M_KyotenDSDesigner;
	TStringField *M_KyotenDSDesigner2;
	TDateTimeField *M_KyotenDSDesigner3;
	TDateTimeField *M_KyotenDSDesigner4;
	TAutoIncField *M_TaniID;
	TIntegerField *M_TaniDSDesigner;
	TStringField *M_TaniDSDesigner2;
	TDateTimeField *M_TaniDSDesigner3;
	TDateTimeField *M_TaniDSDesigner4;
	TADOQuery *M_Tanka;
	TDateTimeField *DateTimeField1;
	TDateTimeField *DateTimeField2;
	TAutoIncField *M_TankaID;
	TIntegerField *M_TankaID2;
	TIntegerField *M_TankaDSDesigner;
	TStringField *M_TankaDSDesigner2;
	TStringField *M_TankaDSDesigner3;
	TIntegerField *M_TankaID3;
	TIntegerField *M_TankaDSDesigner4;
	TStringField *M_TankaDSDesigner5;
	TStringField *M_TankaDSDesigner6;
	TIntegerField *M_TankaDSDesigner1ID;
	TIntegerField *M_TankaDSDesigner1;
	TStringField *M_TankaDSDesigner12;
	TStringField *M_TankaDSDesigner13;
	TIntegerField *M_TankaDSDesigner2ID;
	TIntegerField *M_TankaDSDesigner22;
	TStringField *M_TankaDSDesigner23;
	TStringField *M_TankaDSDesigner24;
	TIntegerField *M_TankaID4;
	TIntegerField *M_TankaDSDesigner7;
	TStringField *M_TankaDSDesigner8;
	TBCDField *M_TankaDSDesigner9;
	TIntegerField *M_TokuisakiDSDesigner34;
	TStringField *M_TokuisakiDSDesigner35;
	TIntegerField *M_TokuisakiID3;
	TIntegerField *M_TokuisakiDSDesigner36;
	TStringField *M_TokuisakiDSDesigner37;
	TStringField *M_TokuisakiDSDesigner38;
	TStringField *M_TokuisakiDSDesigner39;
	TStringField *M_TokuisakiDSDesigner40;
	TStringField *M_TokuisakiDSDesigner41;
	TBCDField *M_SharyoDSDesigner4;
      TADOQuery *M_SlipInfo;
      TADOQuery *M_SlipInfoRelate;
      TADOQuery *M_Bank;
      TADOQuery *M_Tax;
      TADOQuery *M_ItemRelate;
      TAutoIncField *M_SlipInfoID;
      TIntegerField *M_SlipInfoDSDesigner;
      TStringField *M_SlipInfoDSDesigner2;
      TStringField *M_SlipInfoDSDesigner1;
      TStringField *M_SlipInfoDSDesigner22;
      TStringField *M_SlipInfoDSDesigner3;
      TStringField *M_SlipInfoDSDesigner12;
      TStringField *M_SlipInfoDSDesigner23;
      TStringField *M_SlipInfoDSDesigner32;
      TStringField *M_SlipInfoDSDesigner4;
      TStringField *M_SlipInfoDSDesigner13;
      TStringField *M_SlipInfoDSDesigner24;
      TStringField *M_SlipInfoDSDesigner33;
      TStringField *M_SlipInfoDSDesigner42;
      TAutoIncField *M_SlipInfoRelateID;
      TIntegerField *M_SlipInfoRelateDSDesigner;
      TIntegerField *M_SlipInfoRelateID2;
      TAutoIncField *M_SlipInfoRelateID3;
      TIntegerField *M_SlipInfoRelateDSDesigner2;
      TStringField *M_SlipInfoRelateDSDesigner3;
      TStringField *M_SlipInfoRelateDSDesigner1;
      TStringField *M_SlipInfoRelateDSDesigner22;
      TStringField *M_SlipInfoRelateDSDesigner32;
      TStringField *M_SlipInfoRelateDSDesigner12;
      TStringField *M_SlipInfoRelateDSDesigner23;
      TStringField *M_SlipInfoRelateDSDesigner33;
      TStringField *M_SlipInfoRelateDSDesigner4;
      TStringField *M_SlipInfoRelateDSDesigner13;
      TStringField *M_SlipInfoRelateDSDesigner24;
      TStringField *M_SlipInfoRelateDSDesigner34;
      TStringField *M_SlipInfoRelateDSDesigner42;
      TAutoIncField *M_BankID;
      TIntegerField *M_BankDSDesigner;
      TStringField *M_BankDSDesigner2;
      TStringField *M_BankDSDesigner3;
      TStringField *M_BankDSDesigner4;
      TDateTimeField *M_BankDSDesigner5;
      TDateTimeField *M_BankDSDesigner6;
      TIntegerField *M_TaxDSDesigner;
      TIntegerField *M_TaxDSDesigner2;
      TAutoIncField *M_ItemRelateID;
      TIntegerField *M_ItemRelateDSDesigner;
      TIntegerField *M_ItemRelateID2;
      TIntegerField *M_ItemRelateDSDesigner3;
      TStringField *M_ItemRelateDSDesigner4;
      TStringField *M_ItemRelateDSDesigner5;
      TIntegerField *M_ItemRelateID3;
      TIntegerField *M_ItemRelateDSDesigner6;
      TStringField *M_ItemRelateDSDesigner7;
      TStringField *M_ItemRelateDSDesigner8;
      TIntegerField *M_ItemRelateDSDesigner1ID;
      TIntegerField *M_ItemRelateDSDesigner1;
      TStringField *M_ItemRelateDSDesigner12;
      TStringField *M_ItemRelateDSDesigner13;
      TIntegerField *M_ItemRelateDSDesigner2ID;
      TIntegerField *M_ItemRelateDSDesigner22;
      TStringField *M_ItemRelateDSDesigner23;
      TStringField *M_ItemRelateDSDesigner24;
      TIntegerField *M_ItemRelateID4;
      TIntegerField *M_ItemRelateDSDesigner9;
      TStringField *M_ItemRelateDSDesigner10;
      TStringField *M_ItemRelateDSDesigner11;
      TStringField *M_SlipInfoRelateDSDesigner5;
      TIntegerField *M_SlipInfoRelateDSDesigner6;
      TStringField *M_SlipInfoRelateDSDesigner7;
      TStringField *M_SlipInfoRelateDSDesigner8;
      TIntegerField *M_SharyoDSDesigner16;
      TStringField *M_SharyoDSDesigner17;
      TStringField *M_SharyoDSDesigner18;
      TIntegerField *M_SharyoDSDesigner19;
      TIntegerField *M_SharyoDSDesigner20;
      TIntegerField *M_SharyoDSDesigner21;
      TIntegerField *M_SharyoDSDesigner25;
      TIntegerField *M_SharyoDSDesigner26;
      TIntegerField *M_SharyoDSDesigner27;
    TIntegerField *M_HinmokuDSDesigner15;
    TStringField *M_HinmokuDSDesigner16;
    TStringField *M_ItemRelateField;
	TBCDField *M_HinmokuDSDesigner17;
    TIntegerField *M_SlipInfoDSDesigner14;
    TStringField *M_SlipInfoDSDesigner15;
    TIntegerField *M_SlipInfoDSDesigner25;
    TStringField *M_SlipInfoDSDesigner26;
    TIntegerField *M_SlipInfoDSDesigner34;
    TStringField *M_SlipInfoDSDesigner35;
    TStringField *M_SlipInfoRelateField;
	void __fastcall ADOConnectionBeforeConnect(TObject *Sender);
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
    void __fastcall M_ItemRelateCalcFields(TDataSet *DataSet);
    void __fastcall M_SlipInfoRelateCalcFields(TDataSet *DataSet);
private:	// ユーザー宣言
	TStringList *long_list_, *short_list_;
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);

	NsDBInterface DBI;
	NsIni INI;
	NsConfig config_;
    MasterMap itemno_map_;

	AnsiString __fastcall Formal2Informal(AnsiString args);

    AnsiString __fastcall GetTokuisakiQuery(AnsiString search_word, bool all_show, AnsiString order);
    AnsiString __fastcall GetItem1Query(AnsiString search_word, bool all_show, AnsiString order);
    AnsiString __fastcall GetItem2Query(AnsiString search_word, bool all_show, AnsiString order);
    AnsiString __fastcall GetHinBunruiQuery(AnsiString search_word, bool all_show, AnsiString order);
    AnsiString __fastcall GetHinmokuQuery(AnsiString search_word, bool all_show, AnsiString order);
    AnsiString __fastcall GetSharyoQuery(AnsiString search_word, bool all_show, AnsiString order);
	AnsiString __fastcall GetKanzanQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetKyotenQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetTaniQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetTankaQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetSlipInfoQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetSlipInfoRelateQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetBankQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetKamokuQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetHojoboQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetTaxQuery(AnsiString search_word, AnsiString order);
    AnsiString __fastcall GetItemRelateQuery(AnsiString search_word, AnsiString order);

	void __fastcall AddComboMap(TComboBox *combo, MasterMap &map, AnsiString sql);
    void __fastcall AddComboMap_Item(TComboBox *combo, MasterMap &map);
    void __fastcall AddComboBox_Honorific(TComboBox *combo); // 敬称コンボボックス
	int __fastcall SearchIndex(MasterMap &map, int value);
	TInputMode __fastcall GetMode(TPanel *panel);
    void __fastcall DataSetCloseOpen(TDataSet *query);
    AnsiString __fastcall TrimString(AnsiString str, int width);
    void __fastcall DeleteRelateMaster(int page, AnsiString keyfield, int key);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
