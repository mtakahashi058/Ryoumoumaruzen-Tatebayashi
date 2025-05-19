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
void __fastcall TDM::ADOConnectionBeforeConnect(TObject *Sender)
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::GetExtractionQuery(AnsiString where)
{
	AnsiString sql =
		" DECLARE @DATE_FROM  AS [DECIMAL]"
		" DECLARE @DATE_TO    AS [DECIMAL]"
		" DECLARE @GENKAKE    AS [DECIMAL]"
		" SET @DATE_FROM = :DATE_FROM"
		" SET @DATE_TO   = :DATE_TO"
		" SET @GENKAKE   = :GENKAKE"
		" "
		" SELECT"
		" 	�v��ID AS [ID],"
		" 	1 AS �f�[�^�敪, '�v��' AS �f�[�^�敪����,"
		" 	�v�ʓ� AS ���t,"
		" 	�`�[No,"
		" 	���_ID, ���_����,"
		" 	�����o�敪��,"
		" 	���Ӑ�R�[�h, ���Ӑ於��,"
		" 	�i�ڃR�[�h,   �i�ږ���,  ����敪��,"
		" 	����1�R�[�h,  ����1����,"
		" 	����2�R�[�h,  ����2����,"
		" 	����,"
		" 	�P�ʃ}�X�^����,"
		" 	�P��,"
		" 	���z,"
		" 	����Ŋz"
		" FROM"
		" 	V_�v��"
		" WHERE"
		" 	�����敪 = 1"
		" AND"
		" 	�v�ʓ� BETWEEN @DATE_FROM AND @DATE_TO"
		" AND"
		" 	���|�敪 = @GENKAKE"
		" $WHERE$"
		" "
		" UNION"
		" "
		" SELECT"
		" 	���ID AS [ID],"
		" 	2 AS �f�[�^�敪, '���' AS �f�[�^�敪����,"
		" 	����� AS ���t,"
		" 	�`�[No,"
		" 	���_ID, ���_����,"
		" 	'' AS �����o�敪����,"
		" 	���Ӑ�R�[�h, ���Ӑ於��,"
		" 	�i�ڃR�[�h,   �i�ږ���,  ����敪����,"
		" 	����1�R�[�h,  ����1����,"
		" 	����2�R�[�h,  ����2����,"
		" 	����,"
		" 	�P�ʃ}�X�^����,"
		" 	�P��,"
		" 	���z,"
		" 	����Ŋz	"
		" FROM"
		" 	V_���"
		" WHERE"
		" 	�����敪 = 1"
		" AND"
		" 	����� BETWEEN @DATE_FROM AND @DATE_TO"
		" AND"
		" 	���|�敪 = @GENKAKE"
		" $WHERE$"
		" ORDER BY"
		" 	�f�[�^�敪, ���t, �`�[No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
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

