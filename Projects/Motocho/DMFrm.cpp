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
AnsiString __fastcall TDM::GetReportSQL(AnsiString where)
{
	AnsiString sql =
		" DECLARE @DATE_FROM AS [DECIMAL]"
		" DECLARE @DATE_TO   AS [DECIMAL]"
		" SET @DATE_FROM = :DATE_FROM"
		" SET @DATE_TO   = :DATE_TO"
		" "
		" SELECT"
		" 	���_����,"
		" 	�v�ʓ�,"
		" 	�`�[No,"
		" 	�����o�敪��,"
		" 	�Ԕ�,"
		" 	���Ӑ�R�[�h,   ���Ӑ�}�X�^����, ���Ӑ旪��,"
		" 	����1�R�[�h,    ����1�}�X�^����,  ����1����,"
		" 	����2�R�[�h,    ����2�}�X�^����,  ����2����,"
		" 	���l AS �`�[���l,"
		" 	�`�[����Ŋz,"
		" 	�sNo,"
		" 	�i�ڃR�[�h,     �i�ڃ}�X�^����,   �i�ڗ���,"
		" 	�i�ڕ��ރR�[�h, �i�ڕ��ޖ���,     �i�ڕ��ޗ���,"
		" 	[1��ڏd��], �v�ʓ���1,"
		" 	[2��ڏd��], �v�ʓ���2,"
		" 	������, �����d��,"
		" 	�d�ʈ���,"
		" 	�����d��,"
		" 	����,"
		" 	�P�ʃR�[�h, �P�ʃ}�X�^����,"
		" 	�P��,"
		" 	���z,"
		" 	����Ŋz,"
		" 	���ה��l,"
		" 	�X�V����,"
		" 	�쐬����"
		" FROM"
		" 	V_�v��"
		" WHERE"
		" 	�����敪 = 1"
		" AND"
		" 	�v�ʓ� BETWEEN @DATE_FROM AND @DATE_TO"
		" $WHERE$"
		" /*"
		" AND"
		" 	���_ID = 1"
		" AND"
		" 	�����o�敪 = 1"
		" */"
		" ORDER BY"
		" 	���_ID, �v�ʓ�, �`�[No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

