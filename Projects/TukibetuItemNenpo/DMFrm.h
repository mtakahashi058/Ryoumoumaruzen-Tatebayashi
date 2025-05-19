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
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
	void __fastcall ADOConnectionBeforeConnect(TObject *Sender);
private:	// ユーザー宣言
	bool is_month_set;
	void __fastcall SetMonth();

public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);

	NsDBInterface DBI;
	NsIni ini_;
	NsConfig config_;

	TDateTime ST_DT;
	int kishu;
	int month[12];

	AnsiString __fastcall GetReportSQL(AnsiString target, AnsiString where);
	AnsiString __fastcall GetTotalSQL(AnsiString where);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
