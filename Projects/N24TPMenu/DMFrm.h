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
    NsConfig CFG;
    NsIni INI;
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
