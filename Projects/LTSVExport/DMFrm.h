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
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:    // IDE 管理のコンポーネント
    TADOConnection *ADOConnection;
private:    // ユーザー宣言
public:     // ユーザー宣言
	__fastcall TDM(TComponent* Owner);
    NsDBInterface DBI;
    NsIni INI;
    bool __fastcall Init();
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
