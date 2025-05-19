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
		" 	請求ID,"
		" 	締日,"
		" 	締切日,"
		" 	得意先コード, 得意先名称,"
		" 	開始日付,"
		" 	終了日付,"
		" 	前回請求額,"
		" 	今回入金額,"
		" 	今回調整額,"
		" 	今回繰越額,"
		" 	今回売上額,"
		" 	今回消費税額,"
		" 	今回請求額,"
		" 	入金予定日,"
		" 	伝票枚数,"
		" 	更新日時,"
		" 	作成日時"
		" FROM"
		" 	V_請求"
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

