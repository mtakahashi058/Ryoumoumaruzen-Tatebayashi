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
		" 	$TARGETI1$ AS 項目ID1, $TARGETC1$ AS 項目コード1, $TARGETN1$ AS 項目略称1,"
		" 	$TARGETI2$ AS 項目ID2, $TARGETC2$ AS 項目コード2, $TARGETN2$ AS 項目略称2,"
		" 	取引日,"
		" 	伝票No,"
		" 	行No,"
		" 	車番,"
		" 	数量,"
		" 	単位コード, 単位マスタ名称,"
		" 	単価,"
		" 	金額,"
		" 	備考"
		" FROM"
		" 	V_取引"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	完了区分 = 1"
		" ORDER BY"
		"  	項目コード1, 項目コード2, 取引日, 伝票No";

	sql = AnsiReplaceStr(sql, "$TARGETI1$", target_total1);
	sql = AnsiReplaceStr(sql, "$TARGETI2$", target_total2);
	sql = AnsiReplaceStr(sql, "$TARGETC1$", target_code1);
	sql = AnsiReplaceStr(sql, "$TARGETC2$", target_code2);
	sql = AnsiReplaceStr(sql, "$TARGETN1$", target_name1);
	sql = AnsiReplaceStr(sql, "$TARGETN2$", target_name2);
	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::GetHinShukeiSQL(AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	品目コード,"
		" 	CASE WHEN MAX(品目名称) IS NULL OR MAX(品目名称) = '' THEN '名称未入力' ELSE MAX(品目名称) END AS 品目名称,"
		" 	単位コード, MAX(単位マスタ名称) AS 単位名称,"
		" 	SUM(数量) AS 数量,"
		" 	SUM(金額) AS 金額"
		" FROM"
		" 	V_取引"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	完了区分 = 1"
		" GROUP BY"
		" 	品目コード, 単位コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

