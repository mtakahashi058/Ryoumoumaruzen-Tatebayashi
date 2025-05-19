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
		" 	€–ÚID, MAX(€–ÚƒR[ƒh) AS €–ÚƒR[ƒh, MAX(€–Ú—ªÌ) AS €–Ú—ªÌ,"
		" 	SUM(Œ”01) AS Œ”01,"
		" 	SUM(Œ”02) AS Œ”02,"
		" 	SUM(Œ”03) AS Œ”03,"
		" 	SUM(Œ”04) AS Œ”04,"
		" 	SUM(Œ”05) AS Œ”05,"
		" 	SUM(Œ”06) AS Œ”06,"
		" 	SUM(Œ”07) AS Œ”07,"
		" 	SUM(Œ”08) AS Œ”08,"
		" 	SUM(Œ”09) AS Œ”09,"
		" 	SUM(Œ”10) AS Œ”10,"
		" 	SUM(Œ”11) AS Œ”11,"
		" 	SUM(Œ”12) AS Œ”12,"
		" "
		" 	SUM(d—Ê01) AS d—Ê01,"
		" 	SUM(d—Ê02) AS d—Ê02,"
		" 	SUM(d—Ê03) AS d—Ê03,"
		" 	SUM(d—Ê04) AS d—Ê04,"
		" 	SUM(d—Ê05) AS d—Ê05,"
		" 	SUM(d—Ê06) AS d—Ê06,"
		" 	SUM(d—Ê07) AS d—Ê07,"
		" 	SUM(d—Ê08) AS d—Ê08,"
		" 	SUM(d—Ê09) AS d—Ê09,"
		" 	SUM(d—Ê10) AS d—Ê10,"
		" 	SUM(d—Ê11) AS d—Ê11,"
		" 	SUM(d—Ê12) AS d—Ê12,"
		" "
		" 	SUM(‹àŠz01) AS ‹àŠz01,"
		" 	SUM(‹àŠz02) AS ‹àŠz02,"
		" 	SUM(‹àŠz03) AS ‹àŠz03,"
		" 	SUM(‹àŠz04) AS ‹àŠz04,"
		" 	SUM(‹àŠz05) AS ‹àŠz05,"
		" 	SUM(‹àŠz06) AS ‹àŠz06,"
		" 	SUM(‹àŠz07) AS ‹àŠz07,"
		" 	SUM(‹àŠz08) AS ‹àŠz08,"
		" 	SUM(‹àŠz09) AS ‹àŠz09,"
		" 	SUM(‹àŠz10) AS ‹àŠz10,"
		" 	SUM(‹àŠz11) AS ‹àŠz11,"
		" 	SUM(‹àŠz12) AS ‹àŠz12"
		" FROM"
		" 	("
		" 	SELECT"
		" 		$TARGET$"
		" 	"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[0])  + " THEN 1 ELSE 0 END AS Œ”01,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[1])  + " THEN 1 ELSE 0 END AS Œ”02,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[2])  + " THEN 1 ELSE 0 END AS Œ”03,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[3])  + " THEN 1 ELSE 0 END AS Œ”04,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[4])  + " THEN 1 ELSE 0 END AS Œ”05,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[5])  + " THEN 1 ELSE 0 END AS Œ”06,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[6])  + " THEN 1 ELSE 0 END AS Œ”07,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[7])  + " THEN 1 ELSE 0 END AS Œ”08,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[8])  + " THEN 1 ELSE 0 END AS Œ”09,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[9])  + " THEN 1 ELSE 0 END AS Œ”10,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[10]) + " THEN 1 ELSE 0 END AS Œ”11,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[11]) + " THEN 1 ELSE 0 END AS Œ”12,"
		" 	"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[0])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê01,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[1])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê02,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[2])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê03,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[3])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê04,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[4])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê05,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[5])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê06,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[6])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê07,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[7])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê08,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[8])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê09,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[9])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê10,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[10]) + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê11,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[11]) + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê12,"
		" 	"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[0])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz01,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[1])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz02,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[2])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz03,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[3])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz04,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[4])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz05,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[5])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz06,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[6])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz07,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[7])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz08,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[8])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz09,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[9])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz10,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[10]) + " THEN ‹àŠz ELSE 0 END AS ‹àŠz11,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[11]) + " THEN ‹àŠz ELSE 0 END AS ‹àŠz12"
		" 	FROM"
		" 		V_Œv—Ê"
		" 	WHERE"
		" 		Œv—Ê“ú BETWEEN @DATE_FROM AND @DATE_TO"
		" 	AND"
		" 		Š®—¹‹æ•ª = 1"
		" 	$WHERE$"
		" 	) AS D"
		" GROUP BY"
		" 	€–ÚID"
		" ORDER BY"
		" 	€–ÚƒR[ƒh";

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
		" 	SUM(Œ”01) AS Œ”01,"
		" 	SUM(Œ”02) AS Œ”02,"
		" 	SUM(Œ”03) AS Œ”03,"
		" 	SUM(Œ”04) AS Œ”04,"
		" 	SUM(Œ”05) AS Œ”05,"
		" 	SUM(Œ”06) AS Œ”06,"
		" 	SUM(Œ”07) AS Œ”07,"
		" 	SUM(Œ”08) AS Œ”08,"
		" 	SUM(Œ”09) AS Œ”09,"
		" 	SUM(Œ”10) AS Œ”10,"
		" 	SUM(Œ”11) AS Œ”11,"
		" 	SUM(Œ”12) AS Œ”12,"
		" "
		" 	SUM(d—Ê01) AS d—Ê01,"
		" 	SUM(d—Ê02) AS d—Ê02,"
		" 	SUM(d—Ê03) AS d—Ê03,"
		" 	SUM(d—Ê04) AS d—Ê04,"
		" 	SUM(d—Ê05) AS d—Ê05,"
		" 	SUM(d—Ê06) AS d—Ê06,"
		" 	SUM(d—Ê07) AS d—Ê07,"
		" 	SUM(d—Ê08) AS d—Ê08,"
		" 	SUM(d—Ê09) AS d—Ê09,"
		" 	SUM(d—Ê10) AS d—Ê10,"
		" 	SUM(d—Ê11) AS d—Ê11,"
		" 	SUM(d—Ê12) AS d—Ê12,"
		" "
		" 	SUM(‹àŠz01) AS ‹àŠz01,"
		" 	SUM(‹àŠz02) AS ‹àŠz02,"
		" 	SUM(‹àŠz03) AS ‹àŠz03,"
		" 	SUM(‹àŠz04) AS ‹àŠz04,"
		" 	SUM(‹àŠz05) AS ‹àŠz05,"
		" 	SUM(‹àŠz06) AS ‹àŠz06,"
		" 	SUM(‹àŠz07) AS ‹àŠz07,"
		" 	SUM(‹àŠz08) AS ‹àŠz08,"
		" 	SUM(‹àŠz09) AS ‹àŠz09,"
		" 	SUM(‹àŠz10) AS ‹àŠz10,"
		" 	SUM(‹àŠz11) AS ‹àŠz11,"
		" 	SUM(‹àŠz12) AS ‹àŠz12"
		" FROM"
		" 	("
		" 	SELECT"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[0])  + " THEN 1 ELSE 0 END AS Œ”01,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[1])  + " THEN 1 ELSE 0 END AS Œ”02,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[2])  + " THEN 1 ELSE 0 END AS Œ”03,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[3])  + " THEN 1 ELSE 0 END AS Œ”04,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[4])  + " THEN 1 ELSE 0 END AS Œ”05,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[5])  + " THEN 1 ELSE 0 END AS Œ”06,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[6])  + " THEN 1 ELSE 0 END AS Œ”07,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[7])  + " THEN 1 ELSE 0 END AS Œ”08,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[8])  + " THEN 1 ELSE 0 END AS Œ”09,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[9])  + " THEN 1 ELSE 0 END AS Œ”10,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[10]) + " THEN 1 ELSE 0 END AS Œ”11,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[11]) + " THEN 1 ELSE 0 END AS Œ”12,"
		" 	"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[0])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê01,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[1])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê02,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[2])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê03,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[3])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê04,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[4])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê05,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[5])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê06,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[6])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê07,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[7])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê08,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[8])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê09,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[9])  + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê10,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[10]) + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê11,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[11]) + " THEN ³–¡d—Ê ELSE 0 END AS d—Ê12,"
		" 	"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[0])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz01,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[1])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz02,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[2])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz03,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[3])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz04,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[4])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz05,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[5])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz06,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[6])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz07,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[7])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz08,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[8])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz09,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[9])  + " THEN ‹àŠz ELSE 0 END AS ‹àŠz10,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[10]) + " THEN ‹àŠz ELSE 0 END AS ‹àŠz11,"
		" 		CASE WHEN ŒŽ = " + IntToStr(month[11]) + " THEN ‹àŠz ELSE 0 END AS ‹àŠz12"
		" 	FROM"
		" 		V_Œv—Ê"
		" 	WHERE"
		" 		Œv—Ê“ú BETWEEN @DATE_FROM AND @DATE_TO"
		" 	AND"
		" 		Š®—¹‹æ•ª = 1"
		" 	$WHERE$"
		" 	) AS D";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

