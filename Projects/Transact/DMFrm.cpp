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
// 仮No の取得
int __fastcall TDM::GetTempNo(int place_id)
{
	AnsiString sql = " SELECT IsNull(MAX(伝票No), 900000000) + 1 AS 伝票No"
					 " FROM D_取引"
					 " WHERE 拠点ID = " + IntToStr(place_id) + " AND 伝票No > 900000000";
	NsRecordSet set;

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["伝票No"]);
}
//---------------------------------------------------------------------------
// 伝票No の取得
int __fastcall TDM::GetTransNo(int place_id, int date)
{
	// [CFG]
	//int no_mode = ToInt(DM->CFG["伝票採番区分"]);

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT IsNull(MAX(伝票No), 10000) + 1 AS 伝票No"
		  " FROM D_取引"
		  " WHERE"
		  " 	拠点ID = " + IntToStr(place_id) +
		  " AND"
		  " 	取引日 = " + IntToStr(date) +
    	  " AND"
		  " 	伝票No > 10000";

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["伝票No"]);
}
//---------------------------------------------------------------------------
// 指定拠点における最終取引レコードの ID を取得（修正時用）
int __fastcall TDM::GetLastTransID(int place_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 取引ID FROM D_取引"
		  " WHERE 拠点ID = " + IntToStr(place_id) + " AND 完了区分 = 1 AND 行No = 1"
		  " ORDER BY 取引日 DESC, 伝票No DESC";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["取引ID"]);
}
//---------------------------------------------------------------------------
// 指定拠点における前のレコード
int __fastcall TDM::GetPrevTransID(int place_id, int date, int no)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 取引ID FROM D_取引"
		  " WHERE"
		  " 	拠点ID = " + IntToStr(place_id) + " AND 完了区分 = 1 AND 行No = 1"
		  " AND"
		  " 	((取引日 = " + IntToStr(date) + " AND 伝票No < " + IntToStr(no) + ") OR (取引日 < " + IntToStr(date) + "))"
		  " ORDER BY 取引日 DESC, 伝票No DESC";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["取引ID"]);
}
//---------------------------------------------------------------------------
// 指定拠点における次のレコード
int __fastcall TDM::GetNextTransID(int place_id, int date, int no)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 取引ID FROM D_取引"
		  " WHERE"
		  " 	拠点ID = " + IntToStr(place_id) + " AND 完了区分 = 1 AND 行No = 1"
		  " AND"
		  " 	((取引日 = " + IntToStr(date) + " AND 伝票No > " + IntToStr(no) + ") OR (取引日 > " + IntToStr(date) + "))"
		  " ORDER BY 取引日, 伝票No";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["取引ID"]);
}
//---------------------------------------------------------------------------
// 計量IDから計量のキー項目値を取得
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
// 単価マスタよりデフォルト単位を取得
int __fastcall TDM::GetDefaultTanka(int toku_id, int meig_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 単位コード FROM M_単価"
		  " INNER JOIN M_単位 ON M_単価.単位ID = M_単位.単位ID"
		  " WHERE 得意先ID = " + IntToStr(toku_id) + " AND 品目ID = " + IntToStr(meig_id) +
		  " ORDER BY M_単価.単位ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["単位コード"]);
	}

	sql = " SELECT TOP 1 単位コード FROM M_単価"
		  " INNER JOIN M_単位 ON M_単価.単位ID = M_単位.単位ID"
		  " WHERE (得意先ID IS NULL OR 得意先ID = 0) AND 品目ID = " + IntToStr(meig_id) + 
		  " ORDER BY M_単価.単位ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["単位コード"]);
	}

	return 1;
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
		  " 	得意先ID = 0"
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
		  " 	得意先ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	品目ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	項目1ID  = " + IntToStr(item1_id) +
		  " AND"
		  " 	(項目2ID  = 0 OR 項目2ID IS NULL)"
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	得意先ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	品目ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	(項目1ID  = 0 OR 項目1ID IS NULL)"
		  " AND"
		  " 	(項目2ID  = 0 OR 項目2ID IS NULL)"
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	(得意先ID = 0 OR 得意先ID IS NULL)"
		  " AND"
		  " 	品目ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	(項目1ID  = 0 OR 項目1ID IS NULL)"
		  " AND"
		  " 	(項目2ID  = 0 OR 項目2ID IS NULL)"
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	// 標準単価
	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	得意先ID = 0"
		  " AND"
		  " 	品目ID   = 0"
		  " AND"
		  " 	項目1ID  = 0"
		  " AND"
		  " 	項目2ID  = 0"
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

	sql = " SELECT * FROM D_取引 WHERE 取引ID = " + IntToStr(keiryo_id);
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
void __fastcall TDM::SetShabanQuery(bool include_remained, int place_id, bool use_carno)
{
	if (Q_Shaban->Active)
		Q_Shaban->Close();

	if (include_remained){
        if (use_carno){
    		Q_Shaban->SQL->Text =
	    		" DECLARE @CARNO decimal"
		    	" SET @CARNO = :CARNO"

	    		" SELECT"
		    	" 	0 AS 車両分類コード, '滞留' AS 車両分類名,"
    			" 	車両ID, 車番, 車両名称, [1回目重量], 得意先略称, 項目1略称, 項目2略称, 品目略称"
	    		" FROM V_計量"
		    	" WHERE"
			    " 	完了区分 = 0 AND 車番 = @CARNO AND 拠点ID = " + IntToStr(place_id) +
    			" UNION ALL"
	    		" SELECT"
		    	" 	1 AS 車両分類コード, '車両' AS 車両分類名,"
			    " 	車両ID, 車番, 車両名称, 空車重量, 得意先略称, 項目1略称, 項目2略称, 品目略称"
    			" FROM V_車両"
	    		" WHERE"
		    	" 	車番 = @CARNO"
    			" AND"
	    		" 	車両ID NOT IN (SELECT 車両ID FROM V_計量 WHERE 完了区分 = 0 AND 車番 = @CARNO)"
		    	" AND"
			    " 	使用区分 = 1";
        }else{
    		Q_Shaban->SQL->Text =
	    		" SELECT"
		    	" 	0 AS 車両分類コード, '滞留' AS 車両分類名,"
    			" 	車両ID, 車番, 車両名称, [1回目重量], 得意先略称, 項目1略称, 項目2略称, 品目略称"
	    		" FROM V_計量"
		    	" WHERE"
			    " 	完了区分 = 0 AND 拠点ID = " + IntToStr(place_id) +
    			" UNION ALL"
	    		" SELECT"
		    	" 	1 AS 車両分類コード, '車両' AS 車両分類名,"
			    " 	車両ID, 車番, 車両名称, 空車重量, 得意先略称, 項目1略称, 項目2略称, 品目略称"
    			" FROM V_車両"
	    		" WHERE"
	    		" 	車両ID NOT IN (SELECT 車両ID FROM V_計量 WHERE 完了区分 = 0)"
		    	" AND"
			    " 	使用区分 = 1"
                " ORDER BY 車両分類コード, 車番";
                ;
        }
	}else{
        if (use_carno){
    		Q_Shaban->SQL->Text =
	    		" DECLARE @CARNO decimal"
		    	" SET @CARNO = :CARNO"

    			" SELECT"
	    		" 	1 AS 車両分類コード, '車両' AS 車両分類名,"
		    	" 	車両ID, 車番, 車両名称, 空車重量 AS [1回目重量], 得意先略称, 項目1略称, 項目2略称, 品目略称"
			    " FROM V_車両"
    			" WHERE"
	    		" 	車番 = @CARNO"
		    	" AND"
    			" 	使用区分 = 1";
        }else{
    		Q_Shaban->SQL->Text =
    			" SELECT"
	    		" 	1 AS 車両分類コード, '車両' AS 車両分類名,"
		    	" 	車両ID, 車番, 車両名称, 空車重量 AS [1回目重量], 得意先略称, 項目1略称, 項目2略称, 品目略称"
			    " FROM V_車両"
    			" WHERE"
    			" 	使用区分 = 1"
                " ORDER BY 車両分類コード, 車番";
        }
	}
}
//---------------------------------------------------------------------------

