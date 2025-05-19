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
		" 	売掛ID,"
		" 	締切日,"
		" 	得意先コード, 得意先名称,"
		" 	締日,"
		" 	開始日付,"
		" 	終了日付,"
		" 	前月残高,"
		" 	当月入金額,"
		" 	当月調整額,"
		" 	当月繰越額,"
		" 	当月売上額,"
		" 	当月消費税額,"
		" 	当月残高,"
		" 	更新日時,"
		" 	作成日時"
		" FROM"
		" 	V_売掛"
		" $WHERE$"
		" ORDER BY"
		" 	締切日, 得意先コード";
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetShohizeiritu(AnsiString date)
{
	AnsiString sql = AnsiString();
	sql =	" SELECT"
		" 	*"
		" FROM"
		" 	M_消費税"
		" WHERE"
		" 	開始日付 <= " + date;
	NsRecordSet set;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[set.size() - 1]["消費税率"]);
}
//---------------------------------------------------------------------------

