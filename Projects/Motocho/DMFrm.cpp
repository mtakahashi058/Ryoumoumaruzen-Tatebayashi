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
	ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(ini_["ADO::UDL"]);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::GetReportSQL(AnsiString where)
{
	AnsiString sql =
		" DECLARE @DATE_FROM AS [DECIMAL]"
		" DECLARE @DATE_TO   AS [DECIMAL]"
		" SET @DATE_FROM = :DATE_FROM"
		" SET @DATE_TO   = :DATE_TO"
		" "
		" SELECT"
		" 	_¼Ì,"
		" 	vÊú,"
		" 	`[No,"
		" 	Àüoæª¼,"
		" 	ÔÔ,"
		" 	¾ÓæR[h,   ¾Óæ}X^¼Ì, ¾ÓæªÌ,"
		" 	Ú1R[h,    Ú1}X^¼Ì,  Ú1ªÌ,"
		" 	Ú2R[h,    Ú2}X^¼Ì,  Ú2ªÌ,"
		" 	õl AS `[õl,"
		" 	`[ÁïÅz,"
		" 	sNo,"
		" 	iÚR[h,     iÚ}X^¼Ì,   iÚªÌ,"
		" 	iÚªÞR[h, iÚªÞ¼Ì,     iÚªÞªÌ,"
		" 	[1ñÚdÊ], vÊú1,"
		" 	[2ñÚdÊ], vÊú2,"
		" 	²®¦, ²®dÊ,"
		" 	dÊø«,"
		" 	³¡dÊ,"
		" 	Ê,"
		" 	PÊR[h, PÊ}X^¼Ì,"
		" 	P¿,"
		" 	àz,"
		" 	ÁïÅz,"
		" 	¾×õl,"
		" 	XVú,"
		" 	ì¬ú"
		" FROM"
		" 	V_vÊ"
		" WHERE"
		" 	®¹æª = 1"
		" AND"
		" 	vÊú BETWEEN @DATE_FROM AND @DATE_TO"
		" $WHERE$"
		" /*"
		" AND"
		" 	_ID = 1"
		" AND"
		" 	Àüoæª = 1"
		" */"
		" ORDER BY"
		" 	_ID, vÊú, `[No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

