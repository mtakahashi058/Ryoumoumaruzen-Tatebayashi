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
		" 	æøú,"
		" 	`[No,"
		" 	æøæª¼Ì,"
		" 	»|æª¼Ì,"
		" 	ÔÔ,"
		" 	¾ÓæR[h,   ¾Óæ}X^¼Ì, ¾ÓæªÌ,"
		" 	Ú1R[h,    Ú1}X^¼Ì,  Ú1ªÌ,"
		" 	Ú2R[h,    Ú2}X^¼Ì,  Ú2ªÌ,"
		" 	õl AS `[õl,"
		" 	`[ÁïÅz,"
		" 	sNo,"
		" 	iÚR[h,     iÚ}X^¼Ì,   iÚªÌ,"
		" 	iÚªÞR[h, iÚªÞ¼Ì,     iÚªÞªÌ,"
		" 	Ê,"
		" 	PÊR[h, PÊ}X^¼Ì,"
		" 	P¿,"
		" 	àz,"
		" 	ÁïÅz,"
		" 	¾×õl,"
		" 	XVú,"
		" 	ì¬ú"
		" FROM"
		" 	V_æø"
		" WHERE"
		" 	®¹æª = 1"
		" AND"
		" 	æøú BETWEEN @DATE_FROM AND @DATE_TO"
		" $WHERE$"
		" ORDER BY"
		" 	_ID, æøú, `[No, sNo";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

