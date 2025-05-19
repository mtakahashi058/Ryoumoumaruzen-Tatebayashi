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
		" 	$TARGETI1$ AS 項目ID1, $TARGETC1$ AS 項目コード1, $TARGETN1$ AS 項目略称1,"
		" 	$TARGETI2$ AS 項目ID2, $TARGETC2$ AS 項目コード2, $TARGETN2$ AS 項目略称2,"
		" 	$TARGETI3$ AS 項目ID3, $TARGETC3$ AS 項目コード3, $TARGETN3$ AS 項目略称3,"
		" 	計量日,"
		" 	伝票No,"
		" 	行No,"
		" 	車番,"
		" 	正味重量,"
		" 	数量,"
		" 	単位コード, 単位マスタ名称,"
		" 	単価,"
		" 	金額"
		" FROM"
		" 	V_計量"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	完了区分 = 1"
		" ORDER BY"
		" 	$TARGETC1$, $TARGETC2$, $TARGETC3$, 計量日, 伝票No";

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
		" 	品目コード,"
		" 	CASE WHEN MAX(品目名称) IS NULL OR MAX(品目名称) = '' THEN '名称未入力' ELSE MAX(品目名称) END AS 品目名称,"
		" 	SUM(正味重量) AS 重量,"
		" 	SUM(金額)     AS 金額"
		" FROM"
		" 	V_計量"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	完了区分 = 1"
		" GROUP BY"
		" 	品目コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

