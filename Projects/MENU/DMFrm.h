//---------------------------------------------------------------------------

#ifndef DMFrmH
#define DMFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "NsIni.h"
#include "NsDB.h"
#include "NsConfig.h"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);
	NsDBInterface DBI;
	NsIni ini_;
	NsConfig config_;
	bool __fastcall Init();
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
