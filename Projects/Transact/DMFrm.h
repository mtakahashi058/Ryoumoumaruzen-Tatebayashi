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
    bool __fastcall Init();
    int __fastcall GetTempNo(int place_id);
	int __fastcall GetTransNo(int place_id, int date);
	int __fastcall GetLastTransID(int place_id);
	int __fastcall GetPrevTransID(int place_id, int date, int no);
	int __fastcall GetNextTransID(int place_id, int date, int no);
    bool __fastcall GetKeiryoKey(int keiryo_id, int& date, int& place_id, int& no);

    std::map<int, int> PlaceIDMap;

	int __fastcall GetDefaultTanka(int toku_id, int meig_id);
	Currency __fastcall GetKanzan(int toku_id, int meig_id, int tani_id);
	Currency __fastcall GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id);
	Currency __fastcall GetSalesTax(int date = 0);
	int __fastcall GetPrintInfo(int keiryo_id);

	void __fastcall SetShabanQuery(bool include_remained, int place_id, bool use_carno);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
