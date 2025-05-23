//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
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
AnsiString __fastcall TDM::GetBaseQuery()
{
	return
		" SELECT"
		" 	¿ID,"
		" 	÷ú,"
		" 	÷Øú,"
		" 	¾ÓæR[h, ¾Óæ¼Ì,"
		" 	Jnút,"
		" 	I¹út,"
		" 	Oñ¿z,"
		" 	¡ñüàz,"
		" 	¡ñ²®z,"
		" 	¡ñJzz,"
		" 	¡ñãz,"
		" 	¡ñÁïÅz,"
		" 	¡ñ¿z,"
		" 	üà\èú,"
		" 	`[,"
		" 	XVú,"
		" 	ì¬ú"
		" FROM"
		" 	V_¿"
		" $WHERE$"
		" ORDER BY"
		" 	÷Øú, ¾ÓæR[h";
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetShohizeiritu(AnsiString date)
{
	AnsiString sql = AnsiString();
	sql =	" SELECT"
		" 	*"
		" FROM"
		" 	M_ÁïÅ"
		" WHERE"
		" 	Jnút <= " + date;
	NsRecordSet set;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[set.size() - 1]["ÁïÅ¦"]);
}
//---------------------------------------------------------------------------

