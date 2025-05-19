//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
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
AnsiString __fastcall TDM::GetBaseQuery()
{
	return
		" SELECT"
		" 	����ID,"
		" 	����,"
		" 	���ؓ�,"
		" 	���Ӑ�R�[�h, ���Ӑ於��,"
		" 	�J�n���t,"
		" 	�I�����t,"
		" 	�O�񐿋��z,"
		" 	��������z,"
		" 	���񒲐��z,"
		" 	����J�z�z,"
		" 	���񔄏�z,"
		" 	�������Ŋz,"
		" 	���񐿋��z,"
		" 	�����\���,"
		" 	�`�[����,"
		" 	�X�V����,"
		" 	�쐬����"
		" FROM"
		" 	V_����"
		" $WHERE$"
		" ORDER BY"
		" 	���ؓ�, ���Ӑ�R�[�h";
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetShohizeiritu(AnsiString date)
{
	AnsiString sql = AnsiString();
	sql =	" SELECT"
		" 	*"
		" FROM"
		" 	M_�����"
		" WHERE"
		" 	�J�n���t <= " + date;
	NsRecordSet set;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[set.size() - 1]["����ŗ�"]);
}
//---------------------------------------------------------------------------

