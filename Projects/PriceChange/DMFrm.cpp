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
AnsiString __fastcall TDM::GetExtractionQuery(AnsiString where)
{
	AnsiString sql =
		" DECLARE @DATE_FROM  AS [DECIMAL]"
		" DECLARE @DATE_TO    AS [DECIMAL]"
		" DECLARE @GENKAKE    AS [DECIMAL]"
		" SET @DATE_FROM = :DATE_FROM"
		" SET @DATE_TO   = :DATE_TO"
		" SET @GENKAKE   = :GENKAKE"
		" "
		" SELECT"
		" 	計量ID AS [ID],"
		" 	1 AS データ区分, '計量' AS データ区分名称,"
		" 	計量日 AS 日付,"
		" 	伝票No,"
		" 	拠点ID, 拠点名称,"
		" 	搬入出区分名,"
		" 	得意先コード, 得意先名称,"
		" 	品目コード,   品目名称,  取引区分名,"
		" 	項目1コード,  項目1名称,"
		" 	項目2コード,  項目2名称,"
		" 	数量,"
		" 	単位マスタ名称,"
		" 	単価,"
		" 	金額,"
		" 	消費税額"
		" FROM"
		" 	V_計量"
		" WHERE"
		" 	完了区分 = 1"
		" AND"
		" 	計量日 BETWEEN @DATE_FROM AND @DATE_TO"
		" AND"
		" 	現掛区分 = @GENKAKE"
		" $WHERE$"
		" "
		" UNION"
		" "
		" SELECT"
		" 	取引ID AS [ID],"
		" 	2 AS データ区分, '取引' AS データ区分名称,"
		" 	取引日 AS 日付,"
		" 	伝票No,"
		" 	拠点ID, 拠点名称,"
		" 	'' AS 搬入出区分名称,"
		" 	得意先コード, 得意先名称,"
		" 	品目コード,   品目名称,  取引区分名称,"
		" 	項目1コード,  項目1名称,"
		" 	項目2コード,  項目2名称,"
		" 	数量,"
		" 	単位マスタ名称,"
		" 	単価,"
		" 	金額,"
		" 	消費税額	"
		" FROM"
		" 	V_取引"
		" WHERE"
		" 	完了区分 = 1"
		" AND"
		" 	取引日 BETWEEN @DATE_FROM AND @DATE_TO"
		" AND"
		" 	現掛区分 = @GENKAKE"
		" $WHERE$"
		" ORDER BY"
		" 	データ区分, 日付, 伝票No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 単価の取得
Currency __fastcall TDM::GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	得意先ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	品目ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	項目1ID  = " + IntToStr(item1_id) +
		  " AND"
		  " 	項目2ID  = " + IntToStr(item2_id) +
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	得意先ID  = " + IntToStr(toku_id) +
		  " AND"
		  " 	品目ID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	項目1ID   = " + IntToStr(item1_id) +
		  " AND"
		  " 	(項目2ID  = 0 OR 項目2ID IS NULL)"
		  " AND"
		  " 	単位ID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	得意先ID  = " + IntToStr(toku_id) +
		  " AND"
		  " 	品目ID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	(項目1ID  = 0 OR 項目1ID IS NULL)"
		  " AND"
		  " 	(項目2ID  = 0 OR 項目2ID IS NULL)"
		  " AND"
		  " 	単位ID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	(得意先ID = 0 OR 得意先ID IS NULL)"
		  " AND"
		  " 	品目ID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	(項目1ID  = 0 OR 項目1ID IS NULL)"
		  " AND"
		  " 	(項目2ID  = 0 OR 項目2ID IS NULL)"
		  " AND"
		  " 	単位ID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	// 標準単価
	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	(得意先ID = 0 OR 得意先ID IS NULL)"
		  " AND"
		  " 	(品目ID   = 0 OR 品目ID IS NULL)"
		  " AND"
		  " 	(項目1ID  = 0 OR 項目1ID IS NULL)"
		  " AND"
		  " 	(項目2ID  = 0 OR 項目2ID IS NULL)"
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	return 0;
}
//---------------------------------------------------------------------------
Currency __fastcall TDM::GetSalesTax(int date)
{
	if (!date)
		date = Now().FormatString("yyyymmdd").ToInt();

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 消費税率 FROM M_消費税"
		  " WHERE"
		  " 	開始日付 <= " + IntToStr(date) +
		  " ORDER BY 開始日付 DESC";
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0.05;
	int n = ToInt(SET_TOP(set)["消費税率"]);
	return n / Currency(100);
}
//---------------------------------------------------------------------------

