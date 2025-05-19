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
    hoge = AnsiReplaceStr(hoge, "�@", "");
    hoge = AnsiReplaceStr(hoge, " ", "");
    return hoge;
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetTokuRecords(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	���Ӑ�ID, ���Ӑ�R�[�h, ���Ӑ旪��, �J�i"
		  " FROM"
		  " 	("
		  " 	SELECT ���Ӑ�ID, ���Ӑ�R�[�h, ���Ӑ旪��, SUBSTRING(���Ӑ�J�i, 1, 1) AS �J�i"
		  " 	FROM M_���Ӑ�"
		  " 	WHERE �g�p�敪 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE �J�i = '" + kana1 + "'";
		}else{
			sql += " WHERE �J�i >= '" + kana1 + "' AND �J�i <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY �J�i, ���Ӑ�R�[�h";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetMeigRecords(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	�i��ID, �i�ڃR�[�h, �i�ڗ���, �J�i"
		  " FROM"
		  " 	("
		  " 	SELECT �i��ID, �i�ڃR�[�h, �i�ڗ���, SUBSTRING(�i�ڃJ�i, 1, 1) AS �J�i"
		  " 	FROM M_�i��"
		  " 	WHERE �g�p�敪 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE �J�i = '" + kana1 + "'";
		}else{
			sql += " WHERE �J�i >= '" + kana1 + "' AND �J�i <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY �J�i, �i�ڃR�[�h";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetItem1Records(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	����1ID, ����1�R�[�h, ����1����, �J�i"
		  " FROM"
		  " 	("
		  " 	SELECT ����1ID, ����1�R�[�h, ����1����, SUBSTRING(����1�J�i, 1, 1) AS �J�i"
		  " 	FROM M_����1"
		  " 	WHERE �g�p�敪 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE �J�i = '" + kana1 + "'";
		}else{
			sql += " WHERE �J�i >= '" + kana1 + "' AND �J�i <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY �J�i, ����1�R�[�h";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetItem2Records(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	AnsiString sql;
	sql = " SELECT"
		  " 	����2ID, ����2�R�[�h, ����2����, �J�i"
		  " FROM"
		  " 	("
		  " 	SELECT ����2ID, ����2�R�[�h, ����2����, SUBSTRING(����2�J�i, 1, 1) AS �J�i"
		  " 	FROM M_����2"
		  " 	WHERE �g�p�敪 = 1"
		  " 	) AS MASTER";

	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty()){
			sql += " WHERE �J�i = '" + kana1 + "'";
		}else{
			sql += " WHERE �J�i >= '" + kana1 + "' AND �J�i <= '" + kana2 + "' ";
		}
	}

	sql += " ORDER BY �J�i, ����2�R�[�h";

	set.clear();
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
