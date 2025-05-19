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
										AnsiString target_total3, AnsiString target_code3, AnsiString target_name3,
										AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	V.$TARGETI1$ AS ����ID1, MAX(V.$TARGETC1$) AS ���ڃR�[�h1, MAX(V.$TARGETN1$) AS ���ڗ���1,"
		" 	V.$TARGETI2$ AS ����ID2, MAX(V.$TARGETC2$) AS ���ڃR�[�h2, MAX(V.$TARGETN2$) AS ���ڗ���2,"
		" 	V.$TARGETI3$ AS ����ID3, MAX(V.$TARGETC3$) AS ���ڃR�[�h3, MAX(V.$TARGETN3$) AS ���ڗ���3,"
		"  	MAX(KEN.��) AS ��,"
		"  	SUM(V.�����d��) AS ���v�d��,"
		"  	SUM(V.����) AS ���v����,"
		"  	V.�P�ʃR�[�h, MAX(V.�P�ʃ}�X�^����) AS �P��,"
		"  	SUM(V.���z) AS ���v���z, "
		"  	RIGHT('000000000'+ CAST(MAX(V.$TARGETI1$) AS VARCHAR), 9) + RIGHT('000000000'+ CAST(MAX(V.$TARGETI2$) AS VARCHAR), 9) AS �ؑ�ID"
		" FROM"
		" 	V_�v�� AS V"
		"  	LEFT OUTER JOIN"
		"  		("
		" 		SELECT"
		"  			$TARGETI1$,"
		" 			$TARGETI2$,"
		" 			$TARGETI3$,"
		" 			�P�ʃR�[�h,"
		" 			COUNT(*) AS ��"
		"  		FROM"
		" 			("
		" 			SELECT"
		" 				V.$TARGETI1$, V.$TARGETI2$, V.$TARGETI3$, V.�P�ʃR�[�h, V.�v�ʓ�, V.�`�[No"
		" 			FROM"
		" 				V_�v�� AS V"
		" 			WHERE"
		" 				$WHERE$"
		" 			AND"
		" 				V.�����敪 = 1"
		" 			GROUP BY"
		" 				V.$TARGETI1$, V.$TARGETI2$, V.$TARGETI3$, V.�P�ʃR�[�h, V.�v�ʓ�, V.�`�[No"
		" 			) AS X"
		" 		GROUP BY"
		" 			$TARGETI1$, $TARGETI2$, $TARGETI3$, �P�ʃR�[�h"
		" 		) AS KEN"
		"  	ON ISNULL(V.$TARGETI1$, 0) = ISNULL(KEN.$TARGETI1$, 0) AND ISNULL(V.$TARGETI2$, 0) = ISNULL(KEN.$TARGETI2$, 0) AND ISNULL(V.$TARGETI3$, 0) = ISNULL(KEN.$TARGETI3$, 0) AND ISNULL(V.�P�ʃR�[�h, 0) = ISNULL(KEN.�P�ʃR�[�h, 0)"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	V.�����敪 = 1"
		" GROUP BY"
		"  	V.$TARGETI1$, V.$TARGETI2$, V.$TARGETI3$, V.�P�ʃR�[�h"
		" ORDER BY"
		"  	���ڃR�[�h1, ����ID1, ���ڃR�[�h2, ����ID2, ���ڃR�[�h3, ����ID3, V.�P�ʃR�[�h";

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

