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
	ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(ini_["ADO::UDL"]);
}
//---------------------------------------------------------------------------
// ����ŗ��擾
int __fastcall TDM::GetShohizeiritu(int date)
{
	AnsiString sql = "SELECT * FROM M_����� WHERE �J�n���t <= " + IntToStr(date);
	NsRecordSet set;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[set.size() - 1]["����ŗ�"]);
}
//---------------------------------------------------------------------------

