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
#include "NsConfig.h"
#include "NsIni.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);

	NsDBInterface DBI;
    NsIni INI;
	NsIni Sounds;
    NsConfig CFG;

    void __fastcall Log(const AnsiString& type, const AnsiString& text, int err_level); // 0: info 1: warn 2: err
    AnsiString __fastcall TrimSpace(const AnsiString& src);

	int __fastcall GetTempKeiryoNo();
	int __fastcall GetNextKeiryoNo(int date);
	int __fastcall GetNextDetailNo(int keiryo_id);
    int __fastcall GetTransNo(int date);
	bool __fastcall GetRemainedSet(int car_id, NsRecordSet& set);
    int __fastcall GetTopID(int date, int place, int no);
    bool __fastcall GetKeiryoKey(int keiryo_id, int& date, int& place_id, int& no);
    int __fastcall GetTotalSalesTax(int date, int place, int no);

	int __fastcall GetKanzanCode(int toku_id, int meig_id);
	Currency __fastcall GetKanzan(int toku_id, int meig_id, int tani_id);
	Currency __fastcall GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id);
	Currency __fastcall GetSalesTax(int date = 0);
	int __fastcall GetPrintInfo(int keiryo_id);
    bool __fastcall GetViewRec(const AnsiString& table, int id, NsRecord& rec);

    void __fastcall GetTokuSet(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
	void __fastcall GetItem1Set(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
	void __fastcall GetItem2Set(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
    void __fastcall GetMeigSet(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
