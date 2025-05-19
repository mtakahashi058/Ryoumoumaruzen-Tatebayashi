//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner), DBI(DM->ADOConnection)
{
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
bool __fastcall TDM::GetTokuRecords(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	得意先ID, 得意先コード, 得意先略称, カナ"
		  " FROM"
		  " 	("
		  " 	SELECT 得意先ID, 得意先コード, 得意先略称, SUBSTRING(得意先カナ, 1, 1) AS カナ"
		  " 	FROM M_得意先"
		  " 	WHERE 使用区分 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE カナ = '" + kana1 + "'";
		}else{
			sql += " WHERE カナ >= '" + kana1 + "' AND カナ <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY カナ, 得意先コード";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetMeigRecords(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	品目ID, 品目コード, 品目略称, カナ"
		  " FROM"
		  " 	("
		  " 	SELECT 品目ID, 品目コード, 品目略称, SUBSTRING(品目カナ, 1, 1) AS カナ"
		  " 	FROM M_品目"
		  " 	WHERE 使用区分 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE カナ = '" + kana1 + "'";
		}else{
			sql += " WHERE カナ >= '" + kana1 + "' AND カナ <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY カナ, 品目コード";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetItem1Records(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	項目1ID, 項目1コード, 項目1略称, カナ"
		  " FROM"
		  " 	("
		  " 	SELECT 項目1ID, 項目1コード, 項目1略称, SUBSTRING(項目1カナ, 1, 1) AS カナ"
		  " 	FROM M_項目1"
		  " 	WHERE 使用区分 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE カナ = '" + kana1 + "'";
		}else{
			sql += " WHERE カナ >= '" + kana1 + "' AND カナ <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY カナ, 項目1コード";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetItem2Records(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	項目2ID, 項目2コード, 項目2略称, カナ"
		  " FROM"
		  " 	("
		  " 	SELECT 項目2ID, 項目2コード, 項目2略称, SUBSTRING(項目2カナ, 1, 1) AS カナ"
		  " 	FROM M_項目2"
		  " 	WHERE 使用区分 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE カナ = '" + kana1 + "'";
		}else{
			sql += " WHERE カナ >= '" + kana1 + "' AND カナ <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY カナ, 項目2コード";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
