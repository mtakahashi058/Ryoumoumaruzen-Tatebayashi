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
AnsiString __fastcall TDM::GetReportSQL(AnsiString target_total1, AnsiString target_code1, AnsiString target_name1,
										AnsiString target_total2, AnsiString target_code2, AnsiString target_name2,
										AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	V.$TARGETI1$ AS ÚID1, MAX(V.$TARGETC1$) AS ÚR[h1, MAX(V.$TARGETN1$) AS ÚªÌ1,"
		" 	V.$TARGETI2$ AS ÚID2, MAX(V.$TARGETC2$) AS ÚR[h2, MAX(V.$TARGETN2$) AS ÚªÌ2,"
		"  	MAX(KEN.ñ) AS ñ,"
		"  	SUM(V.³¡dÊ) AS vdÊ,"
		"  	SUM(V.Ê) AS vÊ,"
		"  	V.PÊR[h, MAX(V.PÊ}X^¼Ì) AS PÊ,"
		"  	SUM(V.àz) AS vàz "
		" FROM"
		" 	V_vÊ AS V"
		"  	LEFT OUTER JOIN"
		"  		("
		" 		SELECT"
		"  			$TARGETI1$,"
		" 			$TARGETI2$,"
		" 			PÊR[h,"
		" 			COUNT(*) AS ñ"
		"  		FROM"
		" 			("
		" 			SELECT"
		" 				V.$TARGETI1$, V.$TARGETI2$, V.PÊR[h, V.vÊú, V.`[No"
		" 			FROM"
		" 				V_vÊ AS V"
		" 			WHERE"
		" 				$WHERE$"
		" 			AND"
		" 				V.®¹æª = 1"
		" 			GROUP BY"
		" 				V.$TARGETI1$, V.$TARGETI2$, V.PÊR[h, V.vÊú, V.`[No"
		" 			) AS X"
		" 		GROUP BY"
		" 			$TARGETI1$, $TARGETI2$, PÊR[h"
		" 		) AS KEN"
		"  	ON ISNULL(V.$TARGETI1$, 0) = ISNULL(KEN.$TARGETI1$, 0) AND ISNULL(V.$TARGETI2$, 0) = ISNULL(KEN.$TARGETI2$, 0) AND ISNULL(V.PÊR[h, 0) = ISNULL(KEN.PÊR[h, 0)"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	V.®¹æª = 1"
		" GROUP BY"
		"  	V.$TARGETI1$, V.$TARGETI2$, V.PÊR[h"
		" ORDER BY"
		"  	ÚR[h1, ÚID1, ÚR[h2, ÚID2, V.PÊR[h";

	sql = AnsiReplaceStr(sql, "$TARGETI1$", target_total1);
	sql = AnsiReplaceStr(sql, "$TARGETI2$", target_total2);
	sql = AnsiReplaceStr(sql, "$TARGETC1$", target_code1);
	sql = AnsiReplaceStr(sql, "$TARGETC2$", target_code2);
	sql = AnsiReplaceStr(sql, "$TARGETN1$", target_name1);
	sql = AnsiReplaceStr(sql, "$TARGETN2$", target_name2);
	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

