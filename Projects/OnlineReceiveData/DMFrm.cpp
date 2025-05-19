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
// 換算マスタよりデフォルト単位を取得
int __fastcall TDM::GetKanzanID(int toku_id, int meig_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 単位ID FROM M_換算"
		  " WHERE 得意先ID = " + IntToStr(toku_id) + " AND 品目ID = " + IntToStr(meig_id) +
		  " ORDER BY M_換算.単位ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["単位ID"]);
	}

	sql = " SELECT TOP 1 単位ID FROM M_換算"
		  " WHERE 得意先ID = 0 AND 品目ID = " + IntToStr(meig_id) + 
		  " ORDER BY M_換算.単位ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["単位ID"]);
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
		  " 	項目2ID  = 0"
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
		  " 	項目1ID  = 0"
		  " AND"
		  " 	項目2ID  = 0"
		  " AND"
		  " 	単位ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["単価"]);
	}

	sql = " SELECT * FROM M_単価"
		  " WHERE"
		  " 	得意先ID = 0"
		  " AND"
		  " 	品目ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	項目1ID  = 0"
		  " AND"
		  " 	項目2ID  = 0"
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

