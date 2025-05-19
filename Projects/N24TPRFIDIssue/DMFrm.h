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
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);
	NsDBInterface DBI;
    NsConfig CFG;

    AnsiString __fastcall TDM::TrimSpace(const AnsiString& src);

	bool __fastcall GetTokuRecords(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
	bool __fastcall GetMeigRecords(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
	bool __fastcall GetItem1Records(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
	bool __fastcall GetItem2Records(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
