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
		" 	V.$TARGETI1$ AS 項目ID1, MAX(V.$TARGETC1$) AS 項目コード1, MAX(V.$TARGETN1$) AS 項目略称1,"
		" 	V.$TARGETI2$ AS 項目ID2, MAX(V.$TARGETC2$) AS 項目コード2, MAX(V.$TARGETN2$) AS 項目略称2,"
		"  	MAX(KEN.回数) AS 回数,"
		"  	SUM(V.正味重量) AS 合計重量,"
		"  	SUM(V.数量) AS 合計数量,"
		"  	V.単位コード, MAX(V.単位マスタ名称) AS 単位,"
		"  	SUM(V.金額) AS 合計金額 "
		" FROM"
		" 	V_計量 AS V"
		"  	LEFT OUTER JOIN"
		"  		("
		" 		SELECT"
		"  			$TARGETI1$,"
		" 			$TARGETI2$,"
		" 			単位コード,"
		" 			COUNT(*) AS 回数"
		"  		FROM"
		" 			("
		" 			SELECT"
		" 				V.$TARGETI1$, V.$TARGETI2$, V.単位コード, V.計量日, V.伝票No"
		" 			FROM"
		" 				V_計量 AS V"
		" 			WHERE"
		" 				$WHERE$"
		" 			AND"
		" 				V.完了区分 = 1"
		" 			GROUP BY"
		" 				V.$TARGETI1$, V.$TARGETI2$, V.単位コード, V.計量日, V.伝票No"
		" 			) AS X"
		" 		GROUP BY"
		" 			$TARGETI1$, $TARGETI2$, 単位コード"
		" 		) AS KEN"
		"  	ON ISNULL(V.$TARGETI1$, 0) = ISNULL(KEN.$TARGETI1$, 0) AND ISNULL(V.$TARGETI2$, 0) = ISNULL(KEN.$TARGETI2$, 0) AND ISNULL(V.単位コード, 0) = ISNULL(KEN.単位コード, 0)"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	V.完了区分 = 1"
		" GROUP BY"
		"  	V.$TARGETI1$, V.$TARGETI2$, V.単位コード"
		" ORDER BY"
		"  	項目コード1, 項目ID1, 項目コード2, 項目ID2, V.単位コード";

	sql = AnsiReplaceStr(sql, "$TARGETI1$", target_total1);
	sql = AnsiReplaceStr(sql, "$TARGETI2$", target_total2);
	sql = AnsiReplaceStr(sql, "$TARGETC1$", target_code1);
	sql = AnsiReplaceStr(sql, "$TARGETC2$", target_code2);
	sql = AnsiReplaceStr(sql, "$TARGETN1$", target_name1);
	sql = AnsiReplaceStr(sql, "$TARGETN2$", target_name2);
	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

