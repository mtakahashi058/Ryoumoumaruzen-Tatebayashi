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
void __fastcall TDM::ADOConnectionBeforeConnect(TObject *Sender)
{
	ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(ini_["ADO::UDL"]);
}
//---------------------------------------------------------------------------
// �����\������擾
TDateTime __fastcall TDM::GetNyukinYotei(TDateTime dt, int site, int sime)
{
	WORD y, m, d;

	dt = IncMonth(dt, site);
	dt.DecodeDate(&y, &m, &d);

	if ((sime == 99) || (sime < 1 || 31 < sime))
		return GetLastDate(dt);
	else{
		try{
			return EncodeDate(y, m, sime);
		}catch (...){
			return GetLastDate(dt);
		}
	}
}
//---------------------------------------------------------------------------
// ������Ɋ֘A�Â��Ă��链�Ӑ�̌������擾
int __fastcall TDM::GetTokuCount(int s_dt, int e_dt, int seikyu_id)
{
	AnsiString sql =
		" DECLARE @SEIKYU_ID AS [DECIMAL]"	// " DECLARE @SEIKYU_ID AS [VARCHAR]" 2009.12.22 �C��
		" SET @SEIKYU_ID = " + IntToStr(seikyu_id) +
		" "
		" SELECT"
		" 	������ID, COUNT(*) AS ����"
		" FROM"
		" 	M_���Ӑ�"
		" WHERE"
		" 	������ID = @SEIKYU_ID"
		" GROUP BY"
		" 	������ID";

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[0]["����"]);
}
//---------------------------------------------------------------------------
void __fastcall TDM::Q_SeikyuCalcFields(TDataSet *DataSet)
{
	if (!Q_Seikyu->FieldByName("�����")->IsNull){
		try{
			Q_Seikyu->FieldByName("�ȈՎ����")->AsString = IntToDate(Q_Seikyu->FieldByName("�����")->AsInteger).FormatString("mm/dd");
		}catch (...){}
	}
}
//---------------------------------------------------------------------------
// �����R�[�h���琿���J�n���t���擾
TDateTime __fastcall TDM::GetDateFrom(int sime)
{
	TDateTime D;
	WORD y, m, d;
	WORD yy, mm, dd;

	if (sime == 0 || sime >= 29){	// ������
		return GetFirstDate(IncMonth(Date(), -1));

	}else{			// �����߈ȊO
		DecodeDate(Date(), y, m, d);

		for(D = EncodeDate(y, m, d); D >= EncodeDate(y-1, m, 1); D--){
			DecodeDate(D, yy, mm, dd);
			if(dd == sime)	// �������t�������烋�[�v�𔲂���
				break;
		}
		mm--;
		if (mm == 0){
			mm = 12;
			yy--;
		}
		return IntToDate((yy * 10000) + (mm * 100) + (dd + 1));
	}
}
//---------------------------------------------------------------------------
// �����R�[�h���琿���J�n���t���擾
TDateTime __fastcall TDM::GetDateTo(int sime)
{
	TDateTime D;
	WORD y, m, d;
	WORD yy, mm, dd;

	if (sime == 0 || sime >= 29){	// ������
		return GetLastDate(IncMonth(Date(), -1));

	}else{			// �����߈ȊO
		DecodeDate(Date(), y, m, d);

		for(D = EncodeDate(y, m, d); D >= EncodeDate(y-1, m, 1); D--){
			DecodeDate(D, yy, mm, dd);
			if(dd == sime)	// �������t�������烋�[�v�𔲂���
				break;
		}
		return IntToDate((yy * 10000) + (mm * 100) + dd);
	}
}
//---------------------------------------------------------------------------

