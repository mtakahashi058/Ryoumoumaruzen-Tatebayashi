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
// ���Z�}�X�^���f�t�H���g�P�ʂ��擾
int __fastcall TDM::GetKanzanID(int toku_id, int meig_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 �P��ID FROM M_���Z"
		  " WHERE ���Ӑ�ID = " + IntToStr(toku_id) + " AND �i��ID = " + IntToStr(meig_id) +
		  " ORDER BY M_���Z.�P��ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["�P��ID"]);
	}

	sql = " SELECT TOP 1 �P��ID FROM M_���Z"
		  " WHERE ���Ӑ�ID = 0 AND �i��ID = " + IntToStr(meig_id) + 
		  " ORDER BY M_���Z.�P��ID";
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToInt(SET_TOP(set)["�P��ID"]);
	}

	return 1;
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
		  " 	���Ӑ�ID = 0"
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
		  " 	���Ӑ�ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	�i��ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	����1ID  = " + IntToStr(item1_id) +
		  " AND"
		  " 	����2ID  = 0"
		  " AND"
		  " 	�P��ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
	}

	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	���Ӑ�ID = " + IntToStr(toku_id) +
		  " AND"
		  " 	�i��ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	����1ID  = 0"
		  " AND"
		  " 	����2ID  = 0"
		  " AND"
		  " 	�P��ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
	}

	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	���Ӑ�ID = 0"
		  " AND"
		  " 	�i��ID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	����1ID  = 0"
		  " AND"
		  " 	����2ID  = 0"
		  " AND"
		  " 	�P��ID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["�P��"]);
	}

	// �W���P��
	sql = " SELECT * FROM M_�P��"
		  " WHERE"
		  " 	���Ӑ�ID = 0"
		  " AND"
		  " 	�i��ID   = 0"
		  " AND"
		  " 	����1ID  = 0"
		  " AND"
		  " 	����2ID  = 0"
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

