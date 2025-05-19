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

	if (!DM->DBI.GetRecordSet("SELECT ���_ID, ���_�R�[�h, ���_���� FROM M_���_", PlaceSet)){
		Application->MessageBox("���_�}�X�^���ݒ肳��Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Application->Title.c_str(), MB_OK | MB_ICONWARNING);
		return false;;
	}

	return true;
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
// ���::��No �̎擾
int __fastcall TDM::GetTransTempNo(int place_id)
{
	AnsiString sql = " SELECT IsNull(MAX(�`�[No), 900000000) + 1 AS �`�[No"
					 " FROM D_���"
					 " WHERE ���_ID = " + IntToStr(place_id) + " AND �`�[No > 900000000";
	NsRecordSet set;

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["�`�[No"]);
}
//---------------------------------------------------------------------------
// ���::�`�[No �̎擾
int __fastcall TDM::GetTransNo(int place_id, int date)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT IsNull(MAX(�`�[No), 0) + 1 AS �`�[No"
		  " FROM D_���"
		  " WHERE"
		  " 	���_ID = " + IntToStr(place_id) +
    	  " AND"
		  " 	�`�[No < 900000000";

	DBI.GetRecordSet(sql, set);
	return ToInt(SET_TOP(set)["�`�[No"]);
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
// �w�苒�_�ɂ�����ŏI�v�ʃ��R�[�h�� ID ���擾�i�C�����p�j
int __fastcall TDM::GetLastKeiryoID(int place_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 �v��ID FROM D_�v��"
		  " WHERE ���_ID = " + IntToStr(place_id) + " AND �����敪 <> 9"
		  " ORDER BY �v�ʓ� DESC, �`�[No DESC";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["�v��ID"]);
}
//---------------------------------------------------------------------------
// �w�苒�_�ɂ�����O�̃��R�[�h
int __fastcall TDM::GetPrevKeiryoID(int place_id, int date, int no)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 �v��ID FROM D_�v��"
		  " WHERE"
		  " 	���_ID = " + IntToStr(place_id) + " AND �����敪 <> 9"
		  " AND"
		  " 	((�v�ʓ� = " + IntToStr(date) + " AND �`�[No < " + IntToStr(no) + ") OR (�v�ʓ� < " + IntToStr(date) + "))"
		  " ORDER BY �v�ʓ� DESC, �`�[No DESC";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["�v��ID"]);
}
//---------------------------------------------------------------------------
// �w�苒�_�ɂ����鎟�̃��R�[�h
int __fastcall TDM::GetNextKeiryoID(int place_id, int date, int no)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 �v��ID FROM D_�v��"
		  " WHERE"
		  " 	���_ID = " + IntToStr(place_id) + " AND �����敪 <> 9"
		  " AND"
		  " 	((�v�ʓ� = " + IntToStr(date) + " AND �`�[No > " + IntToStr(no) + ") OR (�v�ʓ� > " + IntToStr(date) + "))"
		  " ORDER BY �v�ʓ�, �`�[No";

	if (!DBI.GetRecordSet(sql, set))
		return 0;
	return ToInt(SET_TOP(set)["�v��ID"]);
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
		  " WHERE"
          "     (���Ӑ�ID = 0 OR ���Ӑ�ID IS NULL)"
          " AND"
          "     �i��ID = " + IntToStr(meig_id) +
		  " ORDER BY M_���Z.�P��ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["�P�ʃR�[�h"]);
	}

	//return 3;   // 1
    int default_code = ToInt(DM->CFG["�W���P��"]);
    if (!default_code)
        default_code = 3;
    return default_code;
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
		  " 	�i��ID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	�P��ID    = " + IntToStr(tani_id);
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

	sql = " SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
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

	if (ToInt(SET_TOP(set)["���|�敪"])){
        int kubun_id = 0;
        sql = " SELECT �敪ID FROM M_�敪 WHERE �敪���ރR�[�h = 4 AND �敪�R�[�h = " + IntToStr(ToInt(SET_TOP(set)["���|�敪"]));
        if (DM->DBI.GetRecordSet(sql, subset))
            kubun_id = ToInt(SET_TOP(subset)["�敪ID"]);

		sql = " SELECT �`�[���ID FROM V_�`�[���֘A"
			  " WHERE ���ڔԍ� = 5 AND ����ID = " + IntToStr(kubun_id);
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
				" 	0 AS �ԗ����ރR�[�h, '�ؗ�' AS �ԗ����ޖ�,"
				" 	�ԗ�ID, �Ԕ�, �ԗ�����, [1��ڏd��], ���Ӑ旪��, ����1����, ����2����, �i�ڗ���"
				" FROM V_�v��"
				" WHERE"
				" 	�����敪 = 0 AND �Ԕ� = @CARNO AND ���_ID = " + IntToStr(place_id) + " AND �sNo = 1 " // �sNo�ǉ� 2013.10.15
				" UNION ALL"
				" SELECT"
				" 	1 AS �ԗ����ރR�[�h, '�ԗ�' AS �ԗ����ޖ�,"
				" 	�ԗ�ID, �Ԕ�, �ԗ�����, ��ԏd��, ���Ӑ旪��, ����1����, ����2����, �i�ڗ���"
				" FROM V_�ԗ�"
				" WHERE"
				" 	�Ԕ� = @CARNO"
				" AND"
				" 	�ԗ�ID NOT IN (SELECT �ԗ�ID FROM V_�v�� WHERE �����敪 = 0 AND �Ԕ� = @CARNO)"
				" AND"
				" 	�g�p�敪 = 1";
		}else{
			Q_Shaban->SQL->Text =
	    		" SELECT"
		    	" 	0 AS �ԗ����ރR�[�h, '�ؗ�' AS �ԗ����ޖ�,"
    			" 	�ԗ�ID, �Ԕ�, �ԗ�����, [1��ڏd��], ���Ӑ旪��, ����1����, ����2����, �i�ڗ���"
	    		" FROM V_�v��"
		    	" WHERE"
				" 	�����敪 = 0 AND ���_ID = " + IntToStr(place_id) + " AND �sNo = 1 " // �sNo�ǉ� 2013.10.15
				" UNION ALL"
				" SELECT"
				" 	1 AS �ԗ����ރR�[�h, '�ԗ�' AS �ԗ����ޖ�,"
				" 	�ԗ�ID, �Ԕ�, �ԗ�����, ��ԏd��, ���Ӑ旪��, ����1����, ����2����, �i�ڗ���"
				" FROM V_�ԗ�"
				" WHERE"
				" 	�ԗ�ID NOT IN (SELECT �ԗ�ID FROM V_�v�� WHERE �����敪 = 0)"
				" AND"
				" 	�g�p�敪 = 1"
				" ORDER BY �ԗ����ރR�[�h, �Ԕ�";
				;
		}
	}else{
		if (use_carno){
			Q_Shaban->SQL->Text =
				" DECLARE @CARNO decimal"
				" SET @CARNO = :CARNO"

				" SELECT"
				" 	1 AS �ԗ����ރR�[�h, '�ԗ�' AS �ԗ����ޖ�,"
				" 	�ԗ�ID, �Ԕ�, �ԗ�����, ��ԏd�� AS [1��ڏd��], ���Ӑ旪��, ����1����, ����2����, �i�ڗ���"
				" FROM V_�ԗ�"
				" WHERE"
				" 	�Ԕ� = @CARNO"
				" AND"
				" 	�g�p�敪 = 1";
		}else{
			Q_Shaban->SQL->Text =
				" SELECT"
				" 	1 AS �ԗ����ރR�[�h, '�ԗ�' AS �ԗ����ޖ�,"
				" 	�ԗ�ID, �Ԕ�, �ԗ�����, ��ԏd�� AS [1��ڏd��], ���Ӑ旪��, ����1����, ����2����, �i�ڗ���"
				" FROM V_�ԗ�"
				" WHERE"
				" 	�g�p�敪 = 1"
				" ORDER BY �ԗ����ރR�[�h, �Ԕ�";
		}
	}
}
//---------------------------------------------------------------------------
int __fastcall TDM::FindPlaceIndexByID(int id)
{
	for (unsigned int i = 0; i < PlaceSet.size(); i++){
		if (ToInt(PlaceSet[i]["���_ID"]) == id)
			return i;
	}
	return -1;
}
//---------------------------------------------------------------------------

