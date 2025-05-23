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
bool __fastcall TDM::Init()
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");

	ADOConnection->Close();
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
	PrintConnection->Close();
	PrintConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
	try {
		ADOConnection->Open();
		PrintConnection->Open();
	}catch (Exception& e){
		Application->MessageBox(("データベース接続に失敗しました\r\n" + e.Message).c_str(),
			"DB接続エラー", MB_OK | MB_ICONHAND);
		return false;
	}
	CFG.Load(&DBI);

	AnsiString log_dir = ToString(INI["FolderObserver::LogFolder"]);
	if (log_dir.IsEmpty())
		log_dir = ExtractFilePath(Application->ExeName) + "FO_LOG\\";
	log_dir = IncludeTrailingPathDelimiter(log_dir);
	LOG.Initialize(log_dir);
	int sweep = ToString(INI["FolderObserver::LogSweep"]).ToIntDef(30);
	LOG.Sweep(sweep);

	return true;
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
int __fastcall TDM::GetPrintInfo(int keiryo_id)
{
	///// 伝票情報取得（単品なので簡易的／多段であれば各明細ごとにチェックが必要）

	AnsiString sql;
	NsRecordSet set, subset;

	sql = " SELECT * FROM W_伝票 WHERE 計量ID = " + IntToStr(keiryo_id);
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

	if (ToInt(SET_TOP(set)["現掛区分"])){
        int kubun_id = 0;
        sql = " SELECT 区分ID FROM M_区分 WHERE 区分分類コード = 4 AND 区分コード = " + IntToStr(ToInt(SET_TOP(set)["現掛区分"]));
        if (DM->DBI.GetRecordSet(sql, subset))
            kubun_id = ToInt(SET_TOP(subset)["区分ID"]);

		sql = " SELECT 伝票情報ID FROM V_伝票情報関連"
			  " WHERE 項目番号 = 5 AND 項目ID = " + IntToStr(kubun_id);
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
