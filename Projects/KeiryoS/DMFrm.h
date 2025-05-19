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
#include "nsoftfunc.h"
#include "NsIni.h"
#include "NsConfig.h"
#include "NP3411Thread.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:    // IDE 管理のコンポーネント
    TADOConnection *ADOConnection;
    TADOQuery *Q_Shaban;
    TIntegerField *Q_ShabanDSDesigner;
    TStringField *Q_ShabanDSDesigner2;
    TIntegerField *Q_ShabanID;
    TIntegerField *Q_ShabanDSDesigner6;
    TStringField *Q_ShabanDSDesigner3;
    TBCDField *Q_ShabanDSDesigner1;
    TStringField *Q_ShabanDSDesigner4;
    TStringField *Q_ShabanDSDesigner12;
    TStringField *Q_ShabanDSDesigner22;
    TStringField *Q_ShabanDSDesigner5;
private:    // ユーザー宣言
public:     // ユーザー宣言
	__fastcall TDM(TComponent* Owner);
    NsDBInterface DBI;
    NsIni INI;
    NsConfig CFG;
    void __fastcall Log(const AnsiString& type, const AnsiString& text, int err_level);
    bool __fastcall Init();
    int __fastcall GetTempNo(int place_id);
	int __fastcall GetKeiryoNo(int place_id, int date);
    int __fastcall GetTransTempNo(int place_id);
    int __fastcall GetTransNo(int place_id, int date);
	int __fastcall GetRemainedKeiryoID(int place_id, int car_id);
	int __fastcall GetLastKeiryoID(int place_id);
	int __fastcall GetPrevKeiryoID(int place_id, int date, int no);
	int __fastcall GetNextKeiryoID(int place_id, int date, int no);

	int __fastcall GetKanzanCode(int toku_id, int meig_id);
	Currency __fastcall GetKanzan(int toku_id, int meig_id, int tani_id);
	Currency __fastcall GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id);
	Currency __fastcall GetSalesTax(int date = 0);
	int __fastcall GetPrintInfo(int keiryo_id);

	void __fastcall SetShabanQuery(bool include_remained, int place_id, bool use_carno = true);

    NsRecordSet PlaceSet;
	int __fastcall FindPlaceIndexByID(int id);

	AnsiString kname_toku_, kname_hin_, kname_komoku1_, kname_komoku2_;
	Currency meryo_, hyoryo_;

    AnsiString __fastcall TrimSpace(const AnsiString& src);
	bool __fastcall GetKeiryoKey(int keiryo_id, int& date, int& place_id, int& no);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
