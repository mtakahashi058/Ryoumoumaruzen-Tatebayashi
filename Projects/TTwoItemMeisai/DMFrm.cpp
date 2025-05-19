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
		" 	$TARGETI1$ AS ����ID1, $TARGETC1$ AS ���ڃR�[�h1, $TARGETN1$ AS ���ڗ���1,"
		" 	$TARGETI2$ AS ����ID2, $TARGETC2$ AS ���ڃR�[�h2, $TARGETN2$ AS ���ڗ���2,"
		" 	�����,"
		" 	�`�[No,"
		" 	�sNo,"
		" 	�Ԕ�,"
		" 	����,"
		" 	�P�ʃR�[�h, �P�ʃ}�X�^����,"
		" 	�P��,"
		" 	���z,"
		" 	���l"
		" FROM"
		" 	V_���"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	�����敪 = 1"
		" ORDER BY"
		"  	���ڃR�[�h1, ���ڃR�[�h2, �����, �`�[No";

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
		" 	�i�ڃR�[�h,"
		" 	CASE WHEN MAX(�i�ږ���) IS NULL OR MAX(�i�ږ���) = '' THEN '���̖�����' ELSE MAX(�i�ږ���) END AS �i�ږ���,"
		" 	�P�ʃR�[�h, MAX(�P�ʃ}�X�^����) AS �P�ʖ���,"
		" 	SUM(����) AS ����,"
		" 	SUM(���z) AS ���z"
		" FROM"
		" 	V_���"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	�����敪 = 1"
		" GROUP BY"
		" 	�i�ڃR�[�h, �P�ʃR�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

