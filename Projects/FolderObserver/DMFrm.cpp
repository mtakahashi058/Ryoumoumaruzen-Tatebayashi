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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
			"DB�ڑ��G���[", MB_OK | MB_ICONHAND);
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
	hoge = AnsiReplaceStr(hoge, "�@", "");
	hoge = AnsiReplaceStr(hoge, " ", "");
	return hoge;
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
int __fastcall TDM::GetPrintInfo(int keiryo_id)
{
	///// �`�[���擾�i�P�i�Ȃ̂ŊȈՓI�^���i�ł���Ίe���ׂ��ƂɃ`�F�b�N���K�v�j

	AnsiString sql;
	NsRecordSet set, subset;

	sql = " SELECT * FROM W_�`�[ WHERE �v��ID = " + IntToStr(keiryo_id);
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
