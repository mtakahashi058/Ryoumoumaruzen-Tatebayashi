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
AnsiString __fastcall TDM::GetItiranQuery(AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	����ID,"
		" 	���_�R�[�h, ���_����,"
		" 	�`�[No,"
		" 	������,"
		" 	������R�[�h, �����於��, �����旪��,	"
		"	���� + �U�� + �萔�� + ���؎� + ��` + ���E + �l���� + ���� + ���̑� AS ���v,"	
		" 	����,"
		" 	�U��,"
		" 	�萔��,"
		" 	���؎�,"
		" 	��`,"
		" 	���E,"
		" 	�l����,"
		" 	����,"
		" 	���̑�,	"
		" 	��s�R�[�h, ��s����, �x�X����, ����,"
		" 	��`����,"
		" 	���l,"
		" 	�X�V����,"
		" 	�쐬����"
		" FROM"
		" 	V_����"
		" $WHERE$"
		"";
		//" ORDER BY"
		//" 	���_�R�[�h, �`�[No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
