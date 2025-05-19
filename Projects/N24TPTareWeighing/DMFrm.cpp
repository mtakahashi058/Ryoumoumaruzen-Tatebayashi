//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner), DBI(ADOConnection)
{
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::TrimSpace(const AnsiString& src)
{
    AnsiString hoge(src);
    hoge = AnsiReplaceStr(hoge, "Å@", "");
    hoge = AnsiReplaceStr(hoge, " ", "");
    return hoge;
}
//---------------------------------------------------------------------------

