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
AnsiString __fastcall TDM::GetReportSQL(AnsiString target_total1, AnsiString target_code1, AnsiString target_name1,
										AnsiString target_total2, AnsiString target_code2, AnsiString target_name2,
										AnsiString target_total3, AnsiString target_code3, AnsiString target_name3,
										AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	$TARGETI1$ AS ÚID1, $TARGETC1$ AS ÚR[h1, $TARGETN1$ AS ÚªÌ1,"
		" 	$TARGETI2$ AS ÚID2, $TARGETC2$ AS ÚR[h2, $TARGETN2$ AS ÚªÌ2,"
		" 	$TARGETI3$ AS ÚID3, $TARGETC3$ AS ÚR[h3, $TARGETN3$ AS ÚªÌ3,"
		" 	æøú,"
		" 	`[No,"
		" 	sNo,"
		" 	ÔÔ,"
		" 	Ê,"
		" 	PÊR[h, PÊ}X^¼Ì,"
		" 	P¿,"
		" 	àz"
		" FROM"
		" 	V_æø"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	®¹æª = 1"
		" ORDER BY"
		" 	$TARGETC1$, $TARGETC2$, $TARGETC3$, æøú, `[No, sNo";

	sql = AnsiReplaceStr(sql, "$TARGETI1$", target_total1);
	sql = AnsiReplaceStr(sql, "$TARGETI2$", target_total2);
	sql = AnsiReplaceStr(sql, "$TARGETI3$", target_total3);
	sql = AnsiReplaceStr(sql, "$TARGETC1$", target_code1);
	sql = AnsiReplaceStr(sql, "$TARGETC2$", target_code2);
	sql = AnsiReplaceStr(sql, "$TARGETC3$", target_code3);
	sql = AnsiReplaceStr(sql, "$TARGETN1$", target_name1);
	sql = AnsiReplaceStr(sql, "$TARGETN2$", target_name2);
	sql = AnsiReplaceStr(sql, "$TARGETN3$", target_name3);
	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::GetHinShukeiSQL(AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	iÚR[h,"
		" 	CASE WHEN MAX(iÚ¼Ì) IS NULL OR MAX(iÚ¼Ì) = '' THEN '¼Ì¢üÍ' ELSE MAX(iÚ¼Ì) END AS iÚ¼Ì,"
		" 	PÊR[h, MAX(PÊ}X^¼Ì) AS PÊ¼Ì,"
		" 	SUM(Ê) AS Ê,"
		" 	SUM(àz) AS àz"
		" FROM"
		" 	V_æø"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	®¹æª = 1"
		" GROUP BY"
		" 	iÚR[h, PÊR[h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

