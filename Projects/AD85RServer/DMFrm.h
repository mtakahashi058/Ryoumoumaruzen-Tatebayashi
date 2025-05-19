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
    void __fastcall Log(const AnsiString& type, const AnsiString& text, int err_level);

    int __fastcall GetTempNo(int place_id);
	int __fastcall GetKeiryoNo(int place_id, int date);
    bool __fastcall GetCardInfo(int card_no, NsRecord& rec);
	int __fastcall GetRemainedKeiryoID(int place_id, int car_id);
	int __fastcall GetKeiryoID(int place_id, int date, int no);

    bool __fastcall GetViewRec(const AnsiString& table, int id, NsRecord& rec);
	int __fastcall GetKanzanCode(int toku_id, int meig_id);
	Currency __fastcall GetKanzan(int toku_id, int meig_id, int tani_id);
	Currency __fastcall GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id);
	Currency __fastcall GetSalesTax(int date = 0);
	int __fastcall GetPrintInfo(int keiryo_id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
