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
	is_month_set = false;
}
//---------------------------------------------------------------------------
void __fastcall TDM::ADOConnectionBeforeConnect(TObject *Sender)
{
	ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(ini_["ADO::UDL"]);
}
//---------------------------------------------------------------------------
void __fastcall TDM::SetMonth()
{
//	TDateTime dt = EncodeDate(WORD(Date().FormatString("yyyy").ToIntDef(0)), kishu, 1);
	TDateTime dt = ST_DT;

	for (int i = 0; i < 12; i++){
		month[i] = dt.FormatString("m").ToIntDef(0);
		dt = IncMonth(dt, 1);
	}

	is_month_set = true;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::GetReportSQL(AnsiString target, AnsiString where)
{
//	if (!is_month_set)
	SetMonth();

	AnsiString sql =
		" DECLARE @DATE_FROM [DECIMAL]"
		" DECLARE @DATE_TO   [DECIMAL]"
		" SET @DATE_FROM = :DATE_FROM"
		" SET @DATE_TO   = :DATE_TO"
		" "
		" SELECT"
		" 	ÚID, MAX(ÚR[h) AS ÚR[h, MAX(ÚªÌ) AS ÚªÌ,"
		" 	SUM(01) AS 01,"
		" 	SUM(02) AS 02,"
		" 	SUM(03) AS 03,"
		" 	SUM(04) AS 04,"
		" 	SUM(05) AS 05,"
		" 	SUM(06) AS 06,"
		" 	SUM(07) AS 07,"
		" 	SUM(08) AS 08,"
		" 	SUM(09) AS 09,"
		" 	SUM(10) AS 10,"
		" 	SUM(11) AS 11,"
		" 	SUM(12) AS 12,"
		" "
		" 	SUM(dÊ01) AS dÊ01,"
		" 	SUM(dÊ02) AS dÊ02,"
		" 	SUM(dÊ03) AS dÊ03,"
		" 	SUM(dÊ04) AS dÊ04,"
		" 	SUM(dÊ05) AS dÊ05,"
		" 	SUM(dÊ06) AS dÊ06,"
		" 	SUM(dÊ07) AS dÊ07,"
		" 	SUM(dÊ08) AS dÊ08,"
		" 	SUM(dÊ09) AS dÊ09,"
		" 	SUM(dÊ10) AS dÊ10,"
		" 	SUM(dÊ11) AS dÊ11,"
		" 	SUM(dÊ12) AS dÊ12,"
		" "
		" 	SUM(àz01) AS àz01,"
		" 	SUM(àz02) AS àz02,"
		" 	SUM(àz03) AS àz03,"
		" 	SUM(àz04) AS àz04,"
		" 	SUM(àz05) AS àz05,"
		" 	SUM(àz06) AS àz06,"
		" 	SUM(àz07) AS àz07,"
		" 	SUM(àz08) AS àz08,"
		" 	SUM(àz09) AS àz09,"
		" 	SUM(àz10) AS àz10,"
		" 	SUM(àz11) AS àz11,"
		" 	SUM(àz12) AS àz12"
		" FROM"
		" 	("
		" 	SELECT"
		" 		$TARGET$"
		" 	"
		" 		CASE WHEN  = " + IntToStr(month[0])  + " THEN 1 ELSE 0 END AS 01,"
		" 		CASE WHEN  = " + IntToStr(month[1])  + " THEN 1 ELSE 0 END AS 02,"
		" 		CASE WHEN  = " + IntToStr(month[2])  + " THEN 1 ELSE 0 END AS 03,"
		" 		CASE WHEN  = " + IntToStr(month[3])  + " THEN 1 ELSE 0 END AS 04,"
		" 		CASE WHEN  = " + IntToStr(month[4])  + " THEN 1 ELSE 0 END AS 05,"
		" 		CASE WHEN  = " + IntToStr(month[5])  + " THEN 1 ELSE 0 END AS 06,"
		" 		CASE WHEN  = " + IntToStr(month[6])  + " THEN 1 ELSE 0 END AS 07,"
		" 		CASE WHEN  = " + IntToStr(month[7])  + " THEN 1 ELSE 0 END AS 08,"
		" 		CASE WHEN  = " + IntToStr(month[8])  + " THEN 1 ELSE 0 END AS 09,"
		" 		CASE WHEN  = " + IntToStr(month[9])  + " THEN 1 ELSE 0 END AS 10,"
		" 		CASE WHEN  = " + IntToStr(month[10]) + " THEN 1 ELSE 0 END AS 11,"
		" 		CASE WHEN  = " + IntToStr(month[11]) + " THEN 1 ELSE 0 END AS 12,"
		" 	"
		" 		CASE WHEN  = " + IntToStr(month[0])  + " THEN ³¡dÊ ELSE 0 END AS dÊ01,"
		" 		CASE WHEN  = " + IntToStr(month[1])  + " THEN ³¡dÊ ELSE 0 END AS dÊ02,"
		" 		CASE WHEN  = " + IntToStr(month[2])  + " THEN ³¡dÊ ELSE 0 END AS dÊ03,"
		" 		CASE WHEN  = " + IntToStr(month[3])  + " THEN ³¡dÊ ELSE 0 END AS dÊ04,"
		" 		CASE WHEN  = " + IntToStr(month[4])  + " THEN ³¡dÊ ELSE 0 END AS dÊ05,"
		" 		CASE WHEN  = " + IntToStr(month[5])  + " THEN ³¡dÊ ELSE 0 END AS dÊ06,"
		" 		CASE WHEN  = " + IntToStr(month[6])  + " THEN ³¡dÊ ELSE 0 END AS dÊ07,"
		" 		CASE WHEN  = " + IntToStr(month[7])  + " THEN ³¡dÊ ELSE 0 END AS dÊ08,"
		" 		CASE WHEN  = " + IntToStr(month[8])  + " THEN ³¡dÊ ELSE 0 END AS dÊ09,"
		" 		CASE WHEN  = " + IntToStr(month[9])  + " THEN ³¡dÊ ELSE 0 END AS dÊ10,"
		" 		CASE WHEN  = " + IntToStr(month[10]) + " THEN ³¡dÊ ELSE 0 END AS dÊ11,"
		" 		CASE WHEN  = " + IntToStr(month[11]) + " THEN ³¡dÊ ELSE 0 END AS dÊ12,"
		" 	"
		" 		CASE WHEN  = " + IntToStr(month[0])  + " THEN àz ELSE 0 END AS àz01,"
		" 		CASE WHEN  = " + IntToStr(month[1])  + " THEN àz ELSE 0 END AS àz02,"
		" 		CASE WHEN  = " + IntToStr(month[2])  + " THEN àz ELSE 0 END AS àz03,"
		" 		CASE WHEN  = " + IntToStr(month[3])  + " THEN àz ELSE 0 END AS àz04,"
		" 		CASE WHEN  = " + IntToStr(month[4])  + " THEN àz ELSE 0 END AS àz05,"
		" 		CASE WHEN  = " + IntToStr(month[5])  + " THEN àz ELSE 0 END AS àz06,"
		" 		CASE WHEN  = " + IntToStr(month[6])  + " THEN àz ELSE 0 END AS àz07,"
		" 		CASE WHEN  = " + IntToStr(month[7])  + " THEN àz ELSE 0 END AS àz08,"
		" 		CASE WHEN  = " + IntToStr(month[8])  + " THEN àz ELSE 0 END AS àz09,"
		" 		CASE WHEN  = " + IntToStr(month[9])  + " THEN àz ELSE 0 END AS àz10,"
		" 		CASE WHEN  = " + IntToStr(month[10]) + " THEN àz ELSE 0 END AS àz11,"
		" 		CASE WHEN  = " + IntToStr(month[11]) + " THEN àz ELSE 0 END AS àz12"
		" 	FROM"
		" 		V_vÊ"
		" 	WHERE"
		" 		vÊú BETWEEN @DATE_FROM AND @DATE_TO"
		" 	AND"
		" 		®¹æª = 1"
		" 	$WHERE$"
		" 	) AS D"
		" GROUP BY"
		" 	ÚID"
		" ORDER BY"
		" 	ÚR[h";

	sql = AnsiReplaceStr(sql, "$TARGET$", target);
	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::GetTotalSQL(AnsiString where)
{
	if (!is_month_set)
		SetMonth();

	AnsiString sql =
		" DECLARE @DATE_FROM [DECIMAL]"
		" DECLARE @DATE_TO   [DECIMAL]"
		" SET @DATE_FROM = :DATE_FROM"
		" SET @DATE_TO   = :DATE_TO"
		" "
		" SELECT"
		" 	SUM(01) AS 01,"
		" 	SUM(02) AS 02,"
		" 	SUM(03) AS 03,"
		" 	SUM(04) AS 04,"
		" 	SUM(05) AS 05,"
		" 	SUM(06) AS 06,"
		" 	SUM(07) AS 07,"
		" 	SUM(08) AS 08,"
		" 	SUM(09) AS 09,"
		" 	SUM(10) AS 10,"
		" 	SUM(11) AS 11,"
		" 	SUM(12) AS 12,"
		" "
		" 	SUM(dÊ01) AS dÊ01,"
		" 	SUM(dÊ02) AS dÊ02,"
		" 	SUM(dÊ03) AS dÊ03,"
		" 	SUM(dÊ04) AS dÊ04,"
		" 	SUM(dÊ05) AS dÊ05,"
		" 	SUM(dÊ06) AS dÊ06,"
		" 	SUM(dÊ07) AS dÊ07,"
		" 	SUM(dÊ08) AS dÊ08,"
		" 	SUM(dÊ09) AS dÊ09,"
		" 	SUM(dÊ10) AS dÊ10,"
		" 	SUM(dÊ11) AS dÊ11,"
		" 	SUM(dÊ12) AS dÊ12,"
		" "
		" 	SUM(àz01) AS àz01,"
		" 	SUM(àz02) AS àz02,"
		" 	SUM(àz03) AS àz03,"
		" 	SUM(àz04) AS àz04,"
		" 	SUM(àz05) AS àz05,"
		" 	SUM(àz06) AS àz06,"
		" 	SUM(àz07) AS àz07,"
		" 	SUM(àz08) AS àz08,"
		" 	SUM(àz09) AS àz09,"
		" 	SUM(àz10) AS àz10,"
		" 	SUM(àz11) AS àz11,"
		" 	SUM(àz12) AS àz12"
		" FROM"
		" 	("
		" 	SELECT"
		" 		CASE WHEN  = " + IntToStr(month[0])  + " THEN 1 ELSE 0 END AS 01,"
		" 		CASE WHEN  = " + IntToStr(month[1])  + " THEN 1 ELSE 0 END AS 02,"
		" 		CASE WHEN  = " + IntToStr(month[2])  + " THEN 1 ELSE 0 END AS 03,"
		" 		CASE WHEN  = " + IntToStr(month[3])  + " THEN 1 ELSE 0 END AS 04,"
		" 		CASE WHEN  = " + IntToStr(month[4])  + " THEN 1 ELSE 0 END AS 05,"
		" 		CASE WHEN  = " + IntToStr(month[5])  + " THEN 1 ELSE 0 END AS 06,"
		" 		CASE WHEN  = " + IntToStr(month[6])  + " THEN 1 ELSE 0 END AS 07,"
		" 		CASE WHEN  = " + IntToStr(month[7])  + " THEN 1 ELSE 0 END AS 08,"
		" 		CASE WHEN  = " + IntToStr(month[8])  + " THEN 1 ELSE 0 END AS 09,"
		" 		CASE WHEN  = " + IntToStr(month[9])  + " THEN 1 ELSE 0 END AS 10,"
		" 		CASE WHEN  = " + IntToStr(month[10]) + " THEN 1 ELSE 0 END AS 11,"
		" 		CASE WHEN  = " + IntToStr(month[11]) + " THEN 1 ELSE 0 END AS 12,"
		" 	"
		" 		CASE WHEN  = " + IntToStr(month[0])  + " THEN ³¡dÊ ELSE 0 END AS dÊ01,"
		" 		CASE WHEN  = " + IntToStr(month[1])  + " THEN ³¡dÊ ELSE 0 END AS dÊ02,"
		" 		CASE WHEN  = " + IntToStr(month[2])  + " THEN ³¡dÊ ELSE 0 END AS dÊ03,"
		" 		CASE WHEN  = " + IntToStr(month[3])  + " THEN ³¡dÊ ELSE 0 END AS dÊ04,"
		" 		CASE WHEN  = " + IntToStr(month[4])  + " THEN ³¡dÊ ELSE 0 END AS dÊ05,"
		" 		CASE WHEN  = " + IntToStr(month[5])  + " THEN ³¡dÊ ELSE 0 END AS dÊ06,"
		" 		CASE WHEN  = " + IntToStr(month[6])  + " THEN ³¡dÊ ELSE 0 END AS dÊ07,"
		" 		CASE WHEN  = " + IntToStr(month[7])  + " THEN ³¡dÊ ELSE 0 END AS dÊ08,"
		" 		CASE WHEN  = " + IntToStr(month[8])  + " THEN ³¡dÊ ELSE 0 END AS dÊ09,"
		" 		CASE WHEN  = " + IntToStr(month[9])  + " THEN ³¡dÊ ELSE 0 END AS dÊ10,"
		" 		CASE WHEN  = " + IntToStr(month[10]) + " THEN ³¡dÊ ELSE 0 END AS dÊ11,"
		" 		CASE WHEN  = " + IntToStr(month[11]) + " THEN ³¡dÊ ELSE 0 END AS dÊ12,"
		" 	"
		" 		CASE WHEN  = " + IntToStr(month[0])  + " THEN àz ELSE 0 END AS àz01,"
		" 		CASE WHEN  = " + IntToStr(month[1])  + " THEN àz ELSE 0 END AS àz02,"
		" 		CASE WHEN  = " + IntToStr(month[2])  + " THEN àz ELSE 0 END AS àz03,"
		" 		CASE WHEN  = " + IntToStr(month[3])  + " THEN àz ELSE 0 END AS àz04,"
		" 		CASE WHEN  = " + IntToStr(month[4])  + " THEN àz ELSE 0 END AS àz05,"
		" 		CASE WHEN  = " + IntToStr(month[5])  + " THEN àz ELSE 0 END AS àz06,"
		" 		CASE WHEN  = " + IntToStr(month[6])  + " THEN àz ELSE 0 END AS àz07,"
		" 		CASE WHEN  = " + IntToStr(month[7])  + " THEN àz ELSE 0 END AS àz08,"
		" 		CASE WHEN  = " + IntToStr(month[8])  + " THEN àz ELSE 0 END AS àz09,"
		" 		CASE WHEN  = " + IntToStr(month[9])  + " THEN àz ELSE 0 END AS àz10,"
		" 		CASE WHEN  = " + IntToStr(month[10]) + " THEN àz ELSE 0 END AS àz11,"
		" 		CASE WHEN  = " + IntToStr(month[11]) + " THEN àz ELSE 0 END AS àz12"
		" 	FROM"
		" 		V_vÊ"
		" 	WHERE"
		" 		vÊú BETWEEN @DATE_FROM AND @DATE_TO"
		" 	AND"
		" 		®¹æª = 1"
		" 	$WHERE$"
		" 	) AS D";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

