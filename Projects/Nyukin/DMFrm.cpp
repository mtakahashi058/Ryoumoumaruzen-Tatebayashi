//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include <StrUtils.hpp>
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
void __fastcall TDM::ADOConnectionBeforeConnect(TObject *Sender)
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::GetItiranQuery(AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	üàID,"
		" 	_R[h, _¼Ì,"
		" 	`[No,"
		" 	üàú,"
		" 	¿æR[h, ¿æ¼Ì, ¿æªÌ,	"
		"	»à + U + è¿ + ¬Øè + è` + E + lø« + ²® + »Ì¼ AS v,"	
		" 	»à,"
		" 	U,"
		" 	è¿,"
		" 	¬Øè,"
		" 	è`,"
		" 	E,"
		" 	lø«,"
		" 	²®,"
		" 	»Ì¼,	"
		" 	âsR[h, âs¼Ì, xX¼Ì, ûÀ,"
		" 	è`úú,"
		" 	õl,"
		" 	XVú,"
		" 	ì¬ú"
		" FROM"
		" 	V_üà"
		" $WHERE$"
		"";
		//" ORDER BY"
		//" 	_R[h, `[No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
