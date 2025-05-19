//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "n24tp.h"

#include "DMFrm.h"
#include "nsoftfunc.h"
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner), DBI(ADOConnection), Sounds("Name")
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::Log(const AnsiString& type, const AnsiString& text, int err_level)
{
    AnsiString content = AnsiReplaceStr(text, "'", " ");

    NsFieldSet fields;
    fields << NsField("[種別]",         type)
           << NsField("[内容]",         content)
           << NsField("[エラーレベル]", err_level)
           ;
    DBI.Insert("D_ログ", fields);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::TrimSpace(const AnsiString& src)
{
    AnsiString hoge(src);
    hoge = AnsiReplaceStr(hoge, "　", "");
    hoge = AnsiReplaceStr(hoge, " ", "");
    return hoge;
}
//---------------------------------------------------------------------------
// 仮No の取得
int __fastcall TDM::GetTempKeiryoNo()
{
	AnsiString sql = " SELECT IsNull(MAX(伝票No), 900000000) + 1 AS 伝票No"
					 " FROM D_計量"
					 " WHERE 拠点ID = " + IntToStr(N24TP::place_id) + " AND 伝票No > 900000000";
	NsRecordSet set;

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["伝票No"]);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetNextKeiryoNo(int date)
{
	// [CFG]
	int no_mode = ToInt(DM->CFG["伝票採番区分"]);

	AnsiString sql;
	NsRecordSet set;

	switch (no_mode){
	case 1:		// 日連番
		sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
			  " FROM D_計量"
			  " WHERE"
			  " 	拠点ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	計量日 = " + IntToStr(date) +
			  " AND"
			  " 	伝票No < 900000000";
		break;
	case 2:		// 月連番
		sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
			  " FROM D_計量"
			  " WHERE"
			  " 	拠点ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	CAST(計量日 / 100 AS INTEGER) = " + IntToStr(date / 100) +
			  " AND"
			  " 	伝票No < 900000000";
		break;
	case 3:		// 年連番
		sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
			  " FROM D_計量"
			  " WHERE"
			  " 	拠点ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	CAST(計量日 / 10000 AS INTEGER) = " + IntToStr(date / 10000) +
			  " AND"
			  " 	伝票No < 900000000";
		break;
	case 4:		// 永久連番
		sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
			  " FROM D_計量"
			  " WHERE"
			  " 	拠点ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	伝票No < 900000000";
		break;
	default:
		throw Exception("伝票採番区分が無効です。設定を確認してください");
	}

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["伝票No"]);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetNextDetailNo(int keiryo_id)
{
    AnsiString sql;
    NsRecordSet set;

    sql = "SELECT 計量日, 拠点ID, 伝票No FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
    if (!DBI.GetRecordSet(sql, set))
        return 0;

    sql = " SELECT IsNull(MAX(行No), 0) + 1 AS 行No FROM D_計量"
          " WHERE 計量日 = " + ToString(SET_TOP(set)["計量日"]) +
          "   AND 拠点ID = " + ToString(SET_TOP(set)["拠点ID"]) +
          "   AND 伝票No = " + ToString(SET_TOP(set)["伝票No"]);
    if (!DBI.GetRecordSet(sql, set))
        return 0;

    return ToInt(SET_TOP(set)["行No"]);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetTransNo(int date)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
		  " FROM D_取引"
		  " WHERE"
		  " 	拠点ID = " + IntToStr(N24TP::place_id) +
    	  " AND"
		  " 	伝票No < 900000000";

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["伝票No"]);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetRemainedSet(int car_id, NsRecordSet& set)
{
	set.clear();
    AnsiString sql;
	sql = " SELECT TOP 1 * FROM V_計量"
          " WHERE カード車両ID = " + IntToStr(car_id) +
          "   AND 拠点ID = " + IntToStr(N24TP::place_id) +
          "   AND 完了区分 = 0"
          " ORDER BY 行No DESC";
	if (DBI.GetRecordSet(sql, set))
        return true;

	sql = " SELECT TOP 1 * FROM V_計量"
          " WHERE 車両ID = " + IntToStr(car_id) +
          "   AND 拠点ID = " + IntToStr(N24TP::place_id) +
          "   AND 完了区分 = 0"
          " ORDER BY 行No DESC";
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetTopID(int date, int place, int no)
{
    AnsiString sql = " SELECT 計量ID FROM V_計量"
                     " WHERE 計量日 = " + IntToStr(date) +
                     "   AND 拠点ID = " + IntToStr(place) +
                     "   AND 伝票No = " + IntToStr(no) +
                     "   AND 行No   = 1";
    NsRecordSet set;
    if (!DBI.GetRecordSet(sql, set))
        return 0;
    return ToInt(SET_TOP(set)["計量ID"]);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetKeiryoKey(int keiryo_id, int& date, int& place_id, int& no)
{
	AnsiString sql;
	NsRecordSet set;

    sql = " SELECT 計量日, 拠点ID, 伝票No FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
    if (!DBI.GetRecordSet(sql, set))
        return false;
        
    date     = ToInt(SET_TOP(set)["計量日"]);
    place_id = ToInt(SET_TOP(set)["拠点ID"]);
    no       = ToInt(SET_TOP(set)["伝票No"]);
    return true;
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetTotalSalesTax(int date, int place, int no)
{
    AnsiString sql = " SELECT SUM(消費税額) AS 税合計 FROM V_計量"
                     " WHERE 計量日 = " + IntToStr(date) +
                     "   AND 拠点ID = " + IntToStr(place) +
                     "   AND 伝票No = " + IntToStr(no);
    NsRecordSet set;
    if (!DBI.GetRecordSet(sql, set))
        return 0;
    return ToInt(SET_TOP(set)["税合計"]);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetTokuSet(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where 句作成
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(得意先カナ, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(得意先カナ, 1, 1) >= '" + kana1 + "' AND SUBSTRING(得意先カナ, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	得意先ID, 得意先コード, 得意先略称, 得意先名称, 得意先カナ"
		  "	FROM V_得意先"
          " WHERE 使用区分 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY 得意先カナ, 得意先コード";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetItem1Set(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where 句作成
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(項目1カナ, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(項目1カナ, 1, 1) >= '" + kana1 + "' AND SUBSTRING(項目1カナ, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	項目1ID, 項目1コード, 項目1略称, 項目1名称, 項目1カナ"
		  "	FROM V_項目1"
          " WHERE 使用区分 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY 項目1カナ, 項目1コード";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetItem2Set(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where 句作成
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(項目2カナ, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(項目2カナ, 1, 1) >= '" + kana1 + "' AND SUBSTRING(項目2カナ, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	項目2ID, 項目2コード, 項目2略称, 項目2名称, 項目2カナ"
		  "	FROM V_項目2"
          " WHERE 使用区分 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY 項目2カナ, 項目2コード";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetMeigSet(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where 句作成
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(品目カナ, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(品目カナ, 1, 1) >= '" + kana1 + "' AND SUBSTRING(品目カナ, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	品目ID, 品目コード, 品目略称, 品目名称, 品目カナ"
		  "	FROM V_品目"
          " WHERE 使用区分 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY 品目カナ, 品目コード";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
// 換算マスタよりデフォルト単位を取得
int __fastcall TDM::GetKanzanCode(int toku_id, int meig_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 単位コード FROM M_換算"
		  " INNER JOIN M_単位 ON M_換算.単位ID = M_単位.単位ID"
		  " WHERE 得意先ID = " + IntToStr(toku_id) + " AND 品目ID = " + IntToStr(meig_id) +
		  " ORDER BY M_換算.単位ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["単位コード"]);
	}

	sql = " SELECT TOP 1 単位コード FROM M_換算"
		  " INNER JOIN M_単位 ON M_換算.単位ID = M_単位.単位ID"
		  " WHERE "
          "     (得意先ID = 0 OR 得意先ID IS NULL)"
          " AND "
          "     品目ID = " + IntToStr(meig_id) +
		  " ORDER BY M_換算.単位ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["単位コード"]);
	}

	return ToInt(DM->CFG["標準単位"]);
}
//---------------------------------------------------------------------------
// 換算値の取得
Currency __fastcall TDM::GetKanzan(int toku_id, int meig_id, int tani_id)
{

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT * FROM M_換算"
		  " WHERE"
		  " 	得意先ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	品目ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["換算率"]);
	}

	// 標準換算
	sql = " SELECT * FROM M_換算"
		  " WHERE"
		  " 	(得意先ID = 0 OR 得意先ID IS NULL)"
		  " AND"
		  " 	品目ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["換算率"]);
	}

	return 0;
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
int __fastcall TDM::GetPrintInfo(int keiryo_id)
{
	///// 伝票情報取得（単品なので簡易的／多段であれば各明細ごとにチェックが必要）

	AnsiString sql;
	NsRecordSet set, subset;

	sql = " SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;

	if (ToInt(SET_TOP(set)["得意先ID"])){
		sql = " SELECT 伝票情報ID FROM V_伝票情報関連"
			  " WHERE 項目番号 = 1 AND 項目ID = " + IntToStr(ToInt(SET_TOP(set)["得意先ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["伝票情報ID"]);
	}

	if (ToInt(SET_TOP(set)["項目1ID"])){
		sql = " SELECT 伝票情報ID FROM V_伝票情報関連"
			  " WHERE 項目番号 = 2 AND 項目ID = " + IntToStr(ToInt(SET_TOP(set)["項目1ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["伝票情報ID"]);
	}

	if (ToInt(SET_TOP(set)["項目2ID"])){
		sql = " SELECT 伝票情報ID FROM V_伝票情報関連"
			  " WHERE 項目番号 = 3 AND 項目ID = " + IntToStr(ToInt(SET_TOP(set)["項目2ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["伝票情報ID"]);
	}

	if (ToInt(SET_TOP(set)["品目ID"])){
		sql = " SELECT 伝票情報ID FROM V_伝票情報関連"
			  " WHERE 項目番号 = 4 AND 項目ID = " + IntToStr(ToInt(SET_TOP(set)["品目ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["伝票情報ID"]);
	}

	sql = " SELECT 伝票情報ID FROM V_伝票情報関連"
		  " WHERE 項目番号 = 0 AND 項目ID = 0";
	if (DM->DBI.GetRecordSet(sql, subset))
		return ToInt(SET_TOP(subset)["伝票情報ID"]);
	else
		return 0;
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetViewRec(const AnsiString& table, int id, NsRecord& rec)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT * FROM V_" + table + 
		  " WHERE "
		  "     " + table + "ID = " + IntToStr(id);

	if (!DBI.GetRecordSet(sql, set))
		return false;

    rec = SET_TOP(set);
	return true;
}
//---------------------------------------------------------------------------

