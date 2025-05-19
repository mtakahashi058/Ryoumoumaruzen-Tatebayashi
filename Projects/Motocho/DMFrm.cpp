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
		" 	拠点名称,"
		" 	計量日,"
		" 	伝票No,"
		" 	搬入出区分名,"
		" 	車番,"
		" 	得意先コード,   得意先マスタ名称, 得意先略称,"
		" 	項目1コード,    項目1マスタ名称,  項目1略称,"
		" 	項目2コード,    項目2マスタ名称,  項目2略称,"
		" 	備考 AS 伝票備考,"
		" 	伝票消費税額,"
		" 	行No,"
		" 	品目コード,     品目マスタ名称,   品目略称,"
		" 	品目分類コード, 品目分類名称,     品目分類略称,"
		" 	[1回目重量], 計量日時1,"
		" 	[2回目重量], 計量日時2,"
		" 	調整率, 調整重量,"
		" 	重量引き,"
		" 	正味重量,"
		" 	数量,"
		" 	単位コード, 単位マスタ名称,"
		" 	単価,"
		" 	金額,"
		" 	消費税額,"
		" 	明細備考,"
		" 	更新日時,"
		" 	作成日時"
		" FROM"
		" 	V_計量"
		" WHERE"
		" 	完了区分 = 1"
		" AND"
		" 	計量日 BETWEEN @DATE_FROM AND @DATE_TO"
		" $WHERE$"
		" /*"
		" AND"
		" 	拠点ID = 1"
		" AND"
		" 	搬入出区分 = 1"
		" */"
		" ORDER BY"
		" 	拠点ID, 計量日, 伝票No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------

