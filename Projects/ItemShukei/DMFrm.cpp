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
		" 	V.$TARGETI$ AS ����ID, MAX(V.$TARGETC$) AS ���ڃR�[�h, MAX(V.$TARGETN$) AS ���ڗ���,"
		"  	MAX(KEN.��) AS ��,"
		"  	SUM(V.�����d��) AS ���v�d��,"
		"  	SUM(V.����) AS ���v����,"
		"  	V.�P�ʃR�[�h, MAX(V.�P�ʃ}�X�^����) AS �P��,"
		"  	SUM(V.���z) AS ���v���z "
		" FROM"
		" 	V_�v�� AS V"
		"  	LEFT OUTER JOIN"
		"  		("
		" 		SELECT"
		"  			$TARGETI$,"
		" 			�P�ʃR�[�h,"
		" 			COUNT(*) AS ��"
		"  		FROM"
		" 			("
		" 			SELECT"
		" 				V.$TARGETI$, V.�P�ʃR�[�h, V.�v�ʓ�, V.�`�[No"
		" 			FROM"
		" 				V_�v�� AS V"
		" 			WHERE"
		" 				$WHERE$"
		" 			AND"
		" 				V.�����敪 = 1"
		" 			GROUP BY"
		" 				V.$TARGETI$, V.�P�ʃR�[�h, V.�v�ʓ�, V.�`�[No"
		" 			) AS X"
		" 		GROUP BY"
		" 			$TARGETI$, �P�ʃR�[�h"
		" 		) AS KEN"
		"  	ON ISNULL(V.$TARGETI$, 0) = ISNULL(KEN.$TARGETI$, 0) AND ISNULL(V.�P�ʃR�[�h, 0) = ISNULL(KEN.�P�ʃR�[�h, 0)"
		" WHERE"
		" 	$WHERE$"
		" AND"
		" 	V.�����敪 = 1"
		" GROUP BY"
		"  	V.$TARGETI$, V.�P�ʃR�[�h"
		" ORDER BY"
		"  	���ڃR�[�h, ����ID, V.�P�ʃR�[�h";

	sql = AnsiReplaceStr(sql, "$TARGETI$", target_total);
	sql = AnsiReplaceStr(sql, "$TARGETC$", target_code);
	sql = AnsiReplaceStr(sql, "$TARGETN$", target_name);
	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

