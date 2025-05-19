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
// Connection の確立と設定の読み込み
bool __fastcall TDM::Init()
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");

	if (ADOConnection->Connected)
		ADOConnection->Close();
	try{
		ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
		ADOConnection->Open();
	}catch(Exception& e){
		Application->MessageBox(("データベース接続に失敗しました\r\n" + e.Message).c_str(),
			Application->Title.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	CFG.Load(&DBI);
	return true;
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
// 仮No の取得
int __fastcall TDM::GetTempNo(int place_id)
{
	AnsiString sql = " SELECT IsNull(MAX(伝票No), 900000000) + 1 AS 伝票No"
					 " FROM D_計量"
					 " WHERE 拠点ID = " + IntToStr(place_id) + " AND 伝票No > 900000000";
	NsRecordSet set;

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["伝票No"]);

}
//---------------------------------------------------------------------------
// 伝票No の取得
int __fastcall TDM::GetKeiryoNo(int place_id, int date)
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
			  " 	拠点ID = " + IntToStr(place_id) +
			  " AND"
			  " 	計量日 = " + IntToStr(date) +
			  " AND"
			  " 	伝票No < 900000000";
		break;
	case 2:		// 月連番
		sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
			  " FROM D_計量"
			  " WHERE"
			  " 	拠点ID = " + IntToStr(place_id) +
			  " AND"
			  " 	CAST(計量日 / 100 AS INTEGER) = " + IntToStr(date / 100) +
			  " AND"
			  " 	伝票No < 900000000";
		break;
	case 3:		// 年連番
		sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
			  " FROM D_計量"
			  " WHERE"
			  " 	拠点ID = " + IntToStr(place_id) +
			  " AND"
			  " 	CAST(計量日 / 10000 AS INTEGER) = " + IntToStr(date / 10000) +
			  " AND"
			  " 	伝票No < 900000000";
		break;
	case 4:		// 永久連番
		sql = " SELECT IsNull(MAX(伝票No), 0) + 1 AS 伝票No"
			  " FROM D_計量"
			  " WHERE"
			  " 	拠点ID = " + IntToStr(place_id) +
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
// 車両情報の取得
bool __fastcall TDM::GetCardInfo(int card_no, NsRecord& rec)
{
    AnsiString sql = " SELECT * FROM V_車両 WHERE カード番号 = " + IntToStr(card_no) + " AND 使用区分 = 1";
    NsRecordSet set;

    if (!DBI.GetRecordSet(sql, set))
        return false;

    rec = SET_TOP(set);
    return true;
}
//---------------------------------------------------------------------------
// 車両IDから指定拠点における滞留レコードを取得する
int __fastcall TDM::GetRemainedKeiryoID(int place_id, int car_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 計量ID FROM D_計量"
		  " WHERE "
		  " 	拠点ID = " + IntToStr(place_id) +
		  " AND"
		  " 	完了区分 = 0"
		  " AND"
		  " 	車両ID = " + IntToStr(car_id) +
		  " AND"
		  " 	行No = 1"
		  " ORDER BY 計量日 DESC, 伝票No DESC";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["計量ID"]);
}
//---------------------------------------------------------------------------
// 拠点、計量日、伝票番号から計量IDを取得
int __fastcall TDM::GetKeiryoID(int place_id, int date, int no)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT 計量ID FROM D_計量"
		  " WHERE "
		  " 	拠点ID = " + IntToStr(place_id) +
		  " AND"
		  " 	計量日 = " + IntToStr(date) +
		  " AND"
		  " 	伝票No = " + IntToStr(no) +
		  " AND"
		  " 	行No = 1";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["計量ID"]);
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

