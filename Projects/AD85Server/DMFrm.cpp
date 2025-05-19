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
// Connection �̊m���Ɛݒ�̓ǂݍ���
bool __fastcall TDM::Init()
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");

	if (ADOConnection->Connected)
		ADOConnection->Close();
	try{
		ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
		ADOConnection->Open();
	}catch(Exception& e){
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
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
    fields << NsField("[���]",         type)
           << NsField("[���e]",         content)
           << NsField("[�G���[���x��]", err_level)
           ;
    DBI.Insert("D_���O", fields);
}
//---------------------------------------------------------------------------
// ��No �̎擾
int __fastcall TDM::GetTempNo(int place_id)
{
	AnsiString sql = " SELECT IsNull(MAX(�`�[No), 900000000) + 1 AS �`�[No"
					 " FROM D_�v��"
					 " WHERE ���_ID = " + IntToStr(place_id) + " AND �`�[No > 900000000";
	NsRecordSet set;

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["�`�[No"]);

}
//---------------------------------------------------------------------------
// �`�[No �̎擾
int __fastcall TDM::GetKeiryoNo(int place_id, int date)
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
			  " 	���_ID = " + IntToStr(place_id) +
			  " AND"
			  " 	�v�ʓ� = " + IntToStr(date) +
			  " AND"
			  " 	�`�[No < 900000000";
		break;
	case 2:		// ���A��
		sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
			  " FROM D_�v��"
			  " WHERE"
			  " 	���_ID = " + IntToStr(place_id) +
			  " AND"
			  " 	CAST(�v�ʓ� / 100 AS INTEGER) = " + IntToStr(date / 100) +
			  " AND"
			  " 	�`�[No < 900000000";
		break;
	case 3:		// �N�A��
		sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
			  " FROM D_�v��"
			  " WHERE"
			  " 	���_ID = " + IntToStr(place_id) +
			  " AND"
			  " 	CAST(�v�ʓ� / 10000 AS INTEGER) = " + IntToStr(date / 10000) +
			  " AND"
			  " 	�`�[No < 900000000";
		break;
	case 4:		// �i�v�A��
		sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
			  " FROM D_�v��"
			  " WHERE"
			  " 	���_ID = " + IntToStr(place_id) +
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
// �ԗ����̎擾
bool __fastcall TDM::GetCardInfo(int card_no, NsRecord& rec)
{
    AnsiString sql = " SELECT * FROM V_�ԗ� WHERE �J�[�h�ԍ� = " + IntToStr(card_no) + " AND �g�p�敪 = 1";
    NsRecordSet set;

    if (!DBI.GetRecordSet(sql, set))
        return false;

    rec = SET_TOP(set);
    return true;
}
//---------------------------------------------------------------------------
// �ԗ�ID����w�苒�_�ɂ�����ؗ����R�[�h���擾����
int __fastcall TDM::GetRemainedKeiryoID(int place_id, int car_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 �v��ID FROM D_�v��"
		  " WHERE "
		  " 	���_ID = " + IntToStr(place_id) +
		  " AND"
		  " 	�����敪 = 0"
		  " AND"
		  " 	�ԗ�ID = " + IntToStr(car_id) +
		  " AND"
		  " 	�sNo = 1"
		  " ORDER BY �v�ʓ� DESC, �`�[No DESC";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["�v��ID"]);
}
//---------------------------------------------------------------------------
// ���_�A�v�ʓ��A�`�[�ԍ�����v��ID���擾
int __fastcall TDM::GetKeiryoID(int place_id, int date, int no)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT �v��ID FROM D_�v��"
		  " WHERE "
		  " 	���_ID = " + IntToStr(place_id) +
		  " AND"
		  " 	�v�ʓ� = " + IntToStr(date) +
		  " AND"
		  " 	�`�[No = " + IntToStr(no) +
		  " AND"
		  " 	�sNo = 1";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["�v��ID"]);
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

