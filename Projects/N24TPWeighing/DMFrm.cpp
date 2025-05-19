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
    fields << NsField("[���]",         type)
           << NsField("[���e]",         content)
           << NsField("[�G���[���x��]", err_level)
           ;
    DBI.Insert("D_���O", fields);
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
// ��No �̎擾
int __fastcall TDM::GetTempKeiryoNo()
{
	AnsiString sql = " SELECT IsNull(MAX(�`�[No), 900000000) + 1 AS �`�[No"
					 " FROM D_�v��"
					 " WHERE ���_ID = " + IntToStr(N24TP::place_id) + " AND �`�[No > 900000000";
	NsRecordSet set;

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["�`�[No"]);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetNextKeiryoNo(int date)
{
	// [CFG]
	int no_mode = ToInt(DM->CFG["�`�[�̔ԋ敪"]);

	AnsiString sql;
	NsRecordSet set;

	switch (no_mode){
	case 1:		// ���A��
		sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
			  " FROM D_�v��"
			  " WHERE"
			  " 	���_ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	�v�ʓ� = " + IntToStr(date) +
			  " AND"
			  " 	�`�[No < 900000000";
		break;
	case 2:		// ���A��
		sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
			  " FROM D_�v��"
			  " WHERE"
			  " 	���_ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	CAST(�v�ʓ� / 100 AS INTEGER) = " + IntToStr(date / 100) +
			  " AND"
			  " 	�`�[No < 900000000";
		break;
	case 3:		// �N�A��
		sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
			  " FROM D_�v��"
			  " WHERE"
			  " 	���_ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	CAST(�v�ʓ� / 10000 AS INTEGER) = " + IntToStr(date / 10000) +
			  " AND"
			  " 	�`�[No < 900000000";
		break;
	case 4:		// �i�v�A��
		sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
			  " FROM D_�v��"
			  " WHERE"
			  " 	���_ID = " + IntToStr(N24TP::place_id) +
			  " AND"
			  " 	�`�[No < 900000000";
		break;
	default:
		throw Exception("�`�[�̔ԋ敪�������ł��B�ݒ���m�F���Ă�������");
	}

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["�`�[No"]);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetNextDetailNo(int keiryo_id)
{
    AnsiString sql;
    NsRecordSet set;

    sql = "SELECT �v�ʓ�, ���_ID, �`�[No FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
    if (!DBI.GetRecordSet(sql, set))
        return 0;

    sql = " SELECT IsNull(MAX(�sNo), 0) + 1 AS �sNo FROM D_�v��"
          " WHERE �v�ʓ� = " + ToString(SET_TOP(set)["�v�ʓ�"]) +
          "   AND ���_ID = " + ToString(SET_TOP(set)["���_ID"]) +
          "   AND �`�[No = " + ToString(SET_TOP(set)["�`�[No"]);
    if (!DBI.GetRecordSet(sql, set))
        return 0;

    return ToInt(SET_TOP(set)["�sNo"]);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetTransNo(int date)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
		  " FROM D_���"
		  " WHERE"
		  " 	���_ID = " + IntToStr(N24TP::place_id) +
    	  " AND"
		  " 	�`�[No < 900000000";

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["�`�[No"]);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetRemainedSet(int car_id, NsRecordSet& set)
{
	set.clear();
    AnsiString sql;
	sql = " SELECT TOP 1 * FROM V_�v��"
          " WHERE �J�[�h�ԗ�ID = " + IntToStr(car_id) +
          "   AND ���_ID = " + IntToStr(N24TP::place_id) +
          "   AND �����敪 = 0"
          " ORDER BY �sNo DESC";
	if (DBI.GetRecordSet(sql, set))
        return true;

	sql = " SELECT TOP 1 * FROM V_�v��"
          " WHERE �ԗ�ID = " + IntToStr(car_id) +
          "   AND ���_ID = " + IntToStr(N24TP::place_id) +
          "   AND �����敪 = 0"
          " ORDER BY �sNo DESC";
	return DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetTopID(int date, int place, int no)
{
    AnsiString sql = " SELECT �v��ID FROM V_�v��"
                     " WHERE �v�ʓ� = " + IntToStr(date) +
                     "   AND ���_ID = " + IntToStr(place) +
                     "   AND �`�[No = " + IntToStr(no) +
                     "   AND �sNo   = 1";
    NsRecordSet set;
    if (!DBI.GetRecordSet(sql, set))
        return 0;
    return ToInt(SET_TOP(set)["�v��ID"]);
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetKeiryoKey(int keiryo_id, int& date, int& place_id, int& no)
{
	AnsiString sql;
	NsRecordSet set;

    sql = " SELECT �v�ʓ�, ���_ID, �`�[No FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
    if (!DBI.GetRecordSet(sql, set))
        return false;
        
    date     = ToInt(SET_TOP(set)["�v�ʓ�"]);
    place_id = ToInt(SET_TOP(set)["���_ID"]);
    no       = ToInt(SET_TOP(set)["�`�[No"]);
    return true;
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetTotalSalesTax(int date, int place, int no)
{
    AnsiString sql = " SELECT SUM(����Ŋz) AS �ō��v FROM V_�v��"
                     " WHERE �v�ʓ� = " + IntToStr(date) +
                     "   AND ���_ID = " + IntToStr(place) +
                     "   AND �`�[No = " + IntToStr(no);
    NsRecordSet set;
    if (!DBI.GetRecordSet(sql, set))
        return 0;
    return ToInt(SET_TOP(set)["�ō��v"]);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetTokuSet(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where ��쐬
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(���Ӑ�J�i, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(���Ӑ�J�i, 1, 1) >= '" + kana1 + "' AND SUBSTRING(���Ӑ�J�i, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	���Ӑ�ID, ���Ӑ�R�[�h, ���Ӑ旪��, ���Ӑ於��, ���Ӑ�J�i"
		  "	FROM V_���Ӑ�"
          " WHERE �g�p�敪 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY ���Ӑ�J�i, ���Ӑ�R�[�h";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetItem1Set(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where ��쐬
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(����1�J�i, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(����1�J�i, 1, 1) >= '" + kana1 + "' AND SUBSTRING(����1�J�i, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	����1ID, ����1�R�[�h, ����1����, ����1����, ����1�J�i"
		  "	FROM V_����1"
          " WHERE �g�p�敪 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY ����1�J�i, ����1�R�[�h";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetItem2Set(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where ��쐬
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(����2�J�i, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(����2�J�i, 1, 1) >= '" + kana1 + "' AND SUBSTRING(����2�J�i, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	����2ID, ����2�R�[�h, ����2����, ����2����, ����2�J�i"
		  "	FROM V_����2"
          " WHERE �g�p�敪 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY ����2�J�i, ����2�R�[�h";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
void __fastcall TDM::GetMeigSet(const AnsiString& kana1, const AnsiString& kana2, NsRecordSet& set)
{
	set.clear();

	AnsiString sql;
	AnsiString kana_cond;

	// where ��쐬
	if (!kana1.IsEmpty()){
		if (kana2.IsEmpty())
			kana_cond = " SUBSTRING(�i�ڃJ�i, 1, 1) = '" + kana1 + "'";
		else
			kana_cond = " SUBSTRING(�i�ڃJ�i, 1, 1) >= '" + kana1 + "' AND SUBSTRING(�i�ڃJ�i, 1, 1) <= '" + kana2 + "' ";
	}

	sql = " SELECT"
		  " 	�i��ID, �i�ڃR�[�h, �i�ڗ���, �i�ږ���, �i�ڃJ�i"
		  "	FROM V_�i��"
          " WHERE �g�p�敪 = 1";
	if (!kana_cond.IsEmpty())
		sql += " AND " + kana_cond;
	sql += " ORDER BY �i�ڃJ�i, �i�ڃR�[�h";
	DBI.GetRecordSet(sql, set);
}
//---------------------------------------------------------------------------
// ���Z�}�X�^���f�t�H���g�P�ʂ��擾
int __fastcall TDM::GetKanzanCode(int toku_id, int meig_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 �P�ʃR�[�h FROM M_���Z"
		  " INNER JOIN M_�P�� ON M_���Z.�P��ID = M_�P��.�P��ID"
		  " WHERE ���Ӑ�ID = " + IntToStr(toku_id) + " AND �i��ID = " + IntToStr(meig_id) +
		  " ORDER BY M_���Z.�P��ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["�P�ʃR�[�h"]);
	}

	sql = " SELECT TOP 1 �P�ʃR�[�h FROM M_���Z"
		  " INNER JOIN M_�P�� ON M_���Z.�P��ID = M_�P��.�P��ID"
		  " WHERE "
          "     (���Ӑ�ID = 0 OR ���Ӑ�ID IS NULL)"
          " AND "
          "     �i��ID = " + IntToStr(meig_id) +
		  " ORDER BY M_���Z.�P��ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["�P�ʃR�[�h"]);
	}

	return ToInt(DM->CFG["�W���P��"]);
}
//---------------------------------------------------------------------------
// ���Z�l�̎擾
Currency __fastcall TDM::GetKanzan(int toku_id, int meig_id, int tani_id)
{

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT * FROM M_���Z"
		  " WHERE"
		  " 	���Ӑ�ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	�i��ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	�P��ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["���Z��"]);
	}

	// �W�����Z
	sql = " SELECT * FROM M_���Z"
		  " WHERE"
		  " 	(���Ӑ�ID = 0 OR ���Ӑ�ID IS NULL)"
		  " AND"
		  " 	�i��ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	�P��ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["���Z��"]);
	}

	return 0;
}
//---------------------------------------------------------------------------
// �P���̎擾
Currency __fastcall TDM::GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	���Ӑ�ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	�i��ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	����1ID  = " + IntToStr(item1_id) +
		  " AND"
		  " 	����2ID  = " + IntToStr(item2_id) +
		  " AND"
		  " 	�P��ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
	}

	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	���Ӑ�ID  = " + IntToStr(toku_id) +
		  " AND"
		  " 	�i��ID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	����1ID   = " + IntToStr(item1_id) +
		  " AND"
		  " 	(����2ID  = 0 OR ����2ID IS NULL)"
		  " AND"
		  " 	�P��ID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
	}

	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	���Ӑ�ID  = " + IntToStr(toku_id) +
		  " AND"
		  " 	�i��ID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	(����1ID  = 0 OR ����1ID IS NULL)"
		  " AND"
		  " 	(����2ID  = 0 OR ����2ID IS NULL)"
		  " AND"
		  " 	�P��ID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
	}

	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	(���Ӑ�ID = 0 OR ���Ӑ�ID IS NULL)"
		  " AND"
		  " 	�i��ID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	(����1ID  = 0 OR ����1ID IS NULL)"
		  " AND"
		  " 	(����2ID  = 0 OR ����2ID IS NULL)"
		  " AND"
		  " 	�P��ID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
	}

	// �W���P��
	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	(���Ӑ�ID = 0 OR ���Ӑ�ID IS NULL)"
		  " AND"
		  " 	(�i��ID   = 0 OR �i��ID IS NULL)"
		  " AND"
		  " 	(����1ID  = 0 OR ����1ID IS NULL)"
		  " AND"
		  " 	(����2ID  = 0 OR ����2ID IS NULL)"
		  " AND"
		  " 	�P��ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
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

	sql = " SELECT TOP 1 ����ŗ� FROM M_�����"
		  " WHERE"
		  " 	�J�n���t <= " + IntToStr(date) +
		  " ORDER BY �J�n���t DESC";
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0.05;
	int n = ToInt(SET_TOP(set)["����ŗ�"]);
	return n / Currency(100);
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetPrintInfo(int keiryo_id)
{
	///// �`�[���擾�i�P�i�Ȃ̂ŊȈՓI�^���i�ł���Ίe���ׂ��ƂɃ`�F�b�N���K�v�j

	AnsiString sql;
	NsRecordSet set, subset;

	sql = " SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;

	if (ToInt(SET_TOP(set)["���Ӑ�ID"])){
		sql = " SELECT �`�[���ID FROM V_�`�[���֘A"
			  " WHERE ���ڔԍ� = 1 AND ����ID = " + IntToStr(ToInt(SET_TOP(set)["���Ӑ�ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["�`�[���ID"]);
	}

	if (ToInt(SET_TOP(set)["����1ID"])){
		sql = " SELECT �`�[���ID FROM V_�`�[���֘A"
			  " WHERE ���ڔԍ� = 2 AND ����ID = " + IntToStr(ToInt(SET_TOP(set)["����1ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["�`�[���ID"]);
	}

	if (ToInt(SET_TOP(set)["����2ID"])){
		sql = " SELECT �`�[���ID FROM V_�`�[���֘A"
			  " WHERE ���ڔԍ� = 3 AND ����ID = " + IntToStr(ToInt(SET_TOP(set)["����2ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["�`�[���ID"]);
	}

	if (ToInt(SET_TOP(set)["�i��ID"])){
		sql = " SELECT �`�[���ID FROM V_�`�[���֘A"
			  " WHERE ���ڔԍ� = 4 AND ����ID = " + IntToStr(ToInt(SET_TOP(set)["�i��ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["�`�[���ID"]);
	}

	sql = " SELECT �`�[���ID FROM V_�`�[���֘A"
		  " WHERE ���ڔԍ� = 0 AND ����ID = 0";
	if (DM->DBI.GetRecordSet(sql, subset))
		return ToInt(SET_TOP(subset)["�`�[���ID"]);
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

