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
		" 	����ID, MAX(���ڃR�[�h) AS ���ڃR�[�h, MAX(���ڗ���) AS ���ڗ���,"
		" 	SUM(����01) AS ����01,"
		" 	SUM(����02) AS ����02,"
		" 	SUM(����03) AS ����03,"
		" 	SUM(����04) AS ����04,"
		" 	SUM(����05) AS ����05,"
		" 	SUM(����06) AS ����06,"
		" 	SUM(����07) AS ����07,"
		" 	SUM(����08) AS ����08,"
		" 	SUM(����09) AS ����09,"
		" 	SUM(����10) AS ����10,"
		" 	SUM(����11) AS ����11,"
		" 	SUM(����12) AS ����12,"
		" "
		" 	SUM(�d��01) AS �d��01,"
		" 	SUM(�d��02) AS �d��02,"
		" 	SUM(�d��03) AS �d��03,"
		" 	SUM(�d��04) AS �d��04,"
		" 	SUM(�d��05) AS �d��05,"
		" 	SUM(�d��06) AS �d��06,"
		" 	SUM(�d��07) AS �d��07,"
		" 	SUM(�d��08) AS �d��08,"
		" 	SUM(�d��09) AS �d��09,"
		" 	SUM(�d��10) AS �d��10,"
		" 	SUM(�d��11) AS �d��11,"
		" 	SUM(�d��12) AS �d��12,"
		" "
		" 	SUM(���z01) AS ���z01,"
		" 	SUM(���z02) AS ���z02,"
		" 	SUM(���z03) AS ���z03,"
		" 	SUM(���z04) AS ���z04,"
		" 	SUM(���z05) AS ���z05,"
		" 	SUM(���z06) AS ���z06,"
		" 	SUM(���z07) AS ���z07,"
		" 	SUM(���z08) AS ���z08,"
		" 	SUM(���z09) AS ���z09,"
		" 	SUM(���z10) AS ���z10,"
		" 	SUM(���z11) AS ���z11,"
		" 	SUM(���z12) AS ���z12"
		" FROM"
		" 	("
		" 	SELECT"
		" 		$TARGET$"
		" 	"
		" 		CASE WHEN �� = " + IntToStr(month[0])  + " THEN 1 ELSE 0 END AS ����01,"
		" 		CASE WHEN �� = " + IntToStr(month[1])  + " THEN 1 ELSE 0 END AS ����02,"
		" 		CASE WHEN �� = " + IntToStr(month[2])  + " THEN 1 ELSE 0 END AS ����03,"
		" 		CASE WHEN �� = " + IntToStr(month[3])  + " THEN 1 ELSE 0 END AS ����04,"
		" 		CASE WHEN �� = " + IntToStr(month[4])  + " THEN 1 ELSE 0 END AS ����05,"
		" 		CASE WHEN �� = " + IntToStr(month[5])  + " THEN 1 ELSE 0 END AS ����06,"
		" 		CASE WHEN �� = " + IntToStr(month[6])  + " THEN 1 ELSE 0 END AS ����07,"
		" 		CASE WHEN �� = " + IntToStr(month[7])  + " THEN 1 ELSE 0 END AS ����08,"
		" 		CASE WHEN �� = " + IntToStr(month[8])  + " THEN 1 ELSE 0 END AS ����09,"
		" 		CASE WHEN �� = " + IntToStr(month[9])  + " THEN 1 ELSE 0 END AS ����10,"
		" 		CASE WHEN �� = " + IntToStr(month[10]) + " THEN 1 ELSE 0 END AS ����11,"
		" 		CASE WHEN �� = " + IntToStr(month[11]) + " THEN 1 ELSE 0 END AS ����12,"
		" 	"
		" 		CASE WHEN �� = " + IntToStr(month[0])  + " THEN �����d�� ELSE 0 END AS �d��01,"
		" 		CASE WHEN �� = " + IntToStr(month[1])  + " THEN �����d�� ELSE 0 END AS �d��02,"
		" 		CASE WHEN �� = " + IntToStr(month[2])  + " THEN �����d�� ELSE 0 END AS �d��03,"
		" 		CASE WHEN �� = " + IntToStr(month[3])  + " THEN �����d�� ELSE 0 END AS �d��04,"
		" 		CASE WHEN �� = " + IntToStr(month[4])  + " THEN �����d�� ELSE 0 END AS �d��05,"
		" 		CASE WHEN �� = " + IntToStr(month[5])  + " THEN �����d�� ELSE 0 END AS �d��06,"
		" 		CASE WHEN �� = " + IntToStr(month[6])  + " THEN �����d�� ELSE 0 END AS �d��07,"
		" 		CASE WHEN �� = " + IntToStr(month[7])  + " THEN �����d�� ELSE 0 END AS �d��08,"
		" 		CASE WHEN �� = " + IntToStr(month[8])  + " THEN �����d�� ELSE 0 END AS �d��09,"
		" 		CASE WHEN �� = " + IntToStr(month[9])  + " THEN �����d�� ELSE 0 END AS �d��10,"
		" 		CASE WHEN �� = " + IntToStr(month[10]) + " THEN �����d�� ELSE 0 END AS �d��11,"
		" 		CASE WHEN �� = " + IntToStr(month[11]) + " THEN �����d�� ELSE 0 END AS �d��12,"
		" 	"
		" 		CASE WHEN �� = " + IntToStr(month[0])  + " THEN ���z ELSE 0 END AS ���z01,"
		" 		CASE WHEN �� = " + IntToStr(month[1])  + " THEN ���z ELSE 0 END AS ���z02,"
		" 		CASE WHEN �� = " + IntToStr(month[2])  + " THEN ���z ELSE 0 END AS ���z03,"
		" 		CASE WHEN �� = " + IntToStr(month[3])  + " THEN ���z ELSE 0 END AS ���z04,"
		" 		CASE WHEN �� = " + IntToStr(month[4])  + " THEN ���z ELSE 0 END AS ���z05,"
		" 		CASE WHEN �� = " + IntToStr(month[5])  + " THEN ���z ELSE 0 END AS ���z06,"
		" 		CASE WHEN �� = " + IntToStr(month[6])  + " THEN ���z ELSE 0 END AS ���z07,"
		" 		CASE WHEN �� = " + IntToStr(month[7])  + " THEN ���z ELSE 0 END AS ���z08,"
		" 		CASE WHEN �� = " + IntToStr(month[8])  + " THEN ���z ELSE 0 END AS ���z09,"
		" 		CASE WHEN �� = " + IntToStr(month[9])  + " THEN ���z ELSE 0 END AS ���z10,"
		" 		CASE WHEN �� = " + IntToStr(month[10]) + " THEN ���z ELSE 0 END AS ���z11,"
		" 		CASE WHEN �� = " + IntToStr(month[11]) + " THEN ���z ELSE 0 END AS ���z12"
		" 	FROM"
		" 		V_�v��"
		" 	WHERE"
		" 		�v�ʓ� BETWEEN @DATE_FROM AND @DATE_TO"
		" 	AND"
		" 		�����敪 = 1"
		" 	$WHERE$"
		" 	) AS D"
		" GROUP BY"
		" 	����ID"
		" ORDER BY"
		" 	���ڃR�[�h";

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
		" 	SUM(����01) AS ����01,"
		" 	SUM(����02) AS ����02,"
		" 	SUM(����03) AS ����03,"
		" 	SUM(����04) AS ����04,"
		" 	SUM(����05) AS ����05,"
		" 	SUM(����06) AS ����06,"
		" 	SUM(����07) AS ����07,"
		" 	SUM(����08) AS ����08,"
		" 	SUM(����09) AS ����09,"
		" 	SUM(����10) AS ����10,"
		" 	SUM(����11) AS ����11,"
		" 	SUM(����12) AS ����12,"
		" "
		" 	SUM(�d��01) AS �d��01,"
		" 	SUM(�d��02) AS �d��02,"
		" 	SUM(�d��03) AS �d��03,"
		" 	SUM(�d��04) AS �d��04,"
		" 	SUM(�d��05) AS �d��05,"
		" 	SUM(�d��06) AS �d��06,"
		" 	SUM(�d��07) AS �d��07,"
		" 	SUM(�d��08) AS �d��08,"
		" 	SUM(�d��09) AS �d��09,"
		" 	SUM(�d��10) AS �d��10,"
		" 	SUM(�d��11) AS �d��11,"
		" 	SUM(�d��12) AS �d��12,"
		" "
		" 	SUM(���z01) AS ���z01,"
		" 	SUM(���z02) AS ���z02,"
		" 	SUM(���z03) AS ���z03,"
		" 	SUM(���z04) AS ���z04,"
		" 	SUM(���z05) AS ���z05,"
		" 	SUM(���z06) AS ���z06,"
		" 	SUM(���z07) AS ���z07,"
		" 	SUM(���z08) AS ���z08,"
		" 	SUM(���z09) AS ���z09,"
		" 	SUM(���z10) AS ���z10,"
		" 	SUM(���z11) AS ���z11,"
		" 	SUM(���z12) AS ���z12"
		" FROM"
		" 	("
		" 	SELECT"
		" 		CASE WHEN �� = " + IntToStr(month[0])  + " THEN 1 ELSE 0 END AS ����01,"
		" 		CASE WHEN �� = " + IntToStr(month[1])  + " THEN 1 ELSE 0 END AS ����02,"
		" 		CASE WHEN �� = " + IntToStr(month[2])  + " THEN 1 ELSE 0 END AS ����03,"
		" 		CASE WHEN �� = " + IntToStr(month[3])  + " THEN 1 ELSE 0 END AS ����04,"
		" 		CASE WHEN �� = " + IntToStr(month[4])  + " THEN 1 ELSE 0 END AS ����05,"
		" 		CASE WHEN �� = " + IntToStr(month[5])  + " THEN 1 ELSE 0 END AS ����06,"
		" 		CASE WHEN �� = " + IntToStr(month[6])  + " THEN 1 ELSE 0 END AS ����07,"
		" 		CASE WHEN �� = " + IntToStr(month[7])  + " THEN 1 ELSE 0 END AS ����08,"
		" 		CASE WHEN �� = " + IntToStr(month[8])  + " THEN 1 ELSE 0 END AS ����09,"
		" 		CASE WHEN �� = " + IntToStr(month[9])  + " THEN 1 ELSE 0 END AS ����10,"
		" 		CASE WHEN �� = " + IntToStr(month[10]) + " THEN 1 ELSE 0 END AS ����11,"
		" 		CASE WHEN �� = " + IntToStr(month[11]) + " THEN 1 ELSE 0 END AS ����12,"
		" 	"
		" 		CASE WHEN �� = " + IntToStr(month[0])  + " THEN �����d�� ELSE 0 END AS �d��01,"
		" 		CASE WHEN �� = " + IntToStr(month[1])  + " THEN �����d�� ELSE 0 END AS �d��02,"
		" 		CASE WHEN �� = " + IntToStr(month[2])  + " THEN �����d�� ELSE 0 END AS �d��03,"
		" 		CASE WHEN �� = " + IntToStr(month[3])  + " THEN �����d�� ELSE 0 END AS �d��04,"
		" 		CASE WHEN �� = " + IntToStr(month[4])  + " THEN �����d�� ELSE 0 END AS �d��05,"
		" 		CASE WHEN �� = " + IntToStr(month[5])  + " THEN �����d�� ELSE 0 END AS �d��06,"
		" 		CASE WHEN �� = " + IntToStr(month[6])  + " THEN �����d�� ELSE 0 END AS �d��07,"
		" 		CASE WHEN �� = " + IntToStr(month[7])  + " THEN �����d�� ELSE 0 END AS �d��08,"
		" 		CASE WHEN �� = " + IntToStr(month[8])  + " THEN �����d�� ELSE 0 END AS �d��09,"
		" 		CASE WHEN �� = " + IntToStr(month[9])  + " THEN �����d�� ELSE 0 END AS �d��10,"
		" 		CASE WHEN �� = " + IntToStr(month[10]) + " THEN �����d�� ELSE 0 END AS �d��11,"
		" 		CASE WHEN �� = " + IntToStr(month[11]) + " THEN �����d�� ELSE 0 END AS �d��12,"
		" 	"
		" 		CASE WHEN �� = " + IntToStr(month[0])  + " THEN ���z ELSE 0 END AS ���z01,"
		" 		CASE WHEN �� = " + IntToStr(month[1])  + " THEN ���z ELSE 0 END AS ���z02,"
		" 		CASE WHEN �� = " + IntToStr(month[2])  + " THEN ���z ELSE 0 END AS ���z03,"
		" 		CASE WHEN �� = " + IntToStr(month[3])  + " THEN ���z ELSE 0 END AS ���z04,"
		" 		CASE WHEN �� = " + IntToStr(month[4])  + " THEN ���z ELSE 0 END AS ���z05,"
		" 		CASE WHEN �� = " + IntToStr(month[5])  + " THEN ���z ELSE 0 END AS ���z06,"
		" 		CASE WHEN �� = " + IntToStr(month[6])  + " THEN ���z ELSE 0 END AS ���z07,"
		" 		CASE WHEN �� = " + IntToStr(month[7])  + " THEN ���z ELSE 0 END AS ���z08,"
		" 		CASE WHEN �� = " + IntToStr(month[8])  + " THEN ���z ELSE 0 END AS ���z09,"
		" 		CASE WHEN �� = " + IntToStr(month[9])  + " THEN ���z ELSE 0 END AS ���z10,"
		" 		CASE WHEN �� = " + IntToStr(month[10]) + " THEN ���z ELSE 0 END AS ���z11,"
		" 		CASE WHEN �� = " + IntToStr(month[11]) + " THEN ���z ELSE 0 END AS ���z12"
		" 	FROM"
		" 		V_�v��"
		" 	WHERE"
		" 		�v�ʓ� BETWEEN @DATE_FROM AND @DATE_TO"
		" 	AND"
		" 		�����敪 = 1"
		" 	$WHERE$"
		" 	) AS D";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

