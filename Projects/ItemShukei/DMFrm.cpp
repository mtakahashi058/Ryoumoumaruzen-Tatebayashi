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
AnsiString __fastcall TDM::GetReportSQL(AnsiString target_total, AnsiString target_code, AnsiString target_name, AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	V.$TARGETI$ AS 項目ID, MAX(V.$TARGETC$) AS 項目コード, MAX(V.$TARGETN$) AS 項目略称,"
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
		"  			$TARGETI$,"
		" 			単位コード,"
		" 			COUNT(*) AS 回数"
		"  		FROM"
		" 			("
		" 			SELECT"
		" 				V.$TARGETI$, V.単位コード, V.計量日, V.伝票No"
		" 			FROM"
		" 				V_計量 AS V"
		" 			WHERE"
		" 				$WHERE$"
		" 			AND"
		" 				V.完了区分 = 1"
		" 			GROUP BY"
		" 				V.$TARGETI$, V.単位コード, V.計量日, V.伝票No"
		" 			) AS X"
		" 		GROUP BY"
		" 			$TARGETI$, 単位コード"
		" 		) AS KEN"
		"  	ON ISNULL(V.$TARGETI$, 0) = ISNULL(KEN.$TARGETI$, 0) AND ISNULL(V.単位コード, 0) = ISNULL(KEN.単位コード, 0)"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	V.完了区分 = 1"
		" GROUP BY"
		"  	V.$TARGETI$, V.単位コード"
		" ORDER BY"
		"  	項目コード, 項目ID, V.単位コード";

	sql = AnsiReplaceStr(sql, "$TARGETI$", target_total);
	sql = AnsiReplaceStr(sql, "$TARGETC$", target_code);
	sql = AnsiReplaceStr(sql, "$TARGETN$", target_name);
	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

