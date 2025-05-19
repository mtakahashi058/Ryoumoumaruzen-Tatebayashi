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
		Application->MessageBox(("ƒf[ƒ^ƒx[ƒXÚ‘±‚É¸”s‚µ‚Ü‚µ‚½\r\n" + e.Message).c_str(),
			"DBÚ‘±ƒGƒ‰[", MB_OK | MB_ICONHAND);
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
	hoge = AnsiReplaceStr(hoge, "@", "");
	hoge = AnsiReplaceStr(hoge, " ", "");
	return hoge;
}
//---------------------------------------------------------------------------
bool __fastcall TDM::GetKeiryoKey(int keiryo_id, int& date, int& place_id, int& no)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT Œv—Ê“ú, ‹’“_ID, “`•[No FROM D_Œv—Ê WHERE Œv—ÊID = " + IntToStr(keiryo_id);
	if (!DBI.GetRecordSet(sql, set))
		return false;

	date     = ToInt(SET_TOP(set)["Œv—Ê“ú"]);
	place_id = ToInt(SET_TOP(set)["‹’“_ID"]);
	no       = ToInt(SET_TOP(set)["“`•[No"]);
	return true;
}
//---------------------------------------------------------------------------
int __fastcall TDM::GetPrintInfo(int keiryo_id)
{
	///// “`•[î•ñæ“¾i’P•i‚È‚Ì‚ÅŠÈˆÕ“I^‘½’i‚Å‚ ‚ê‚ÎŠe–¾×‚²‚Æ‚Éƒ`ƒFƒbƒN‚ª•K—vj

	AnsiString sql;
	NsRecordSet set, subset;

	sql = " SELECT * FROM W_“`•[ WHERE Œv—ÊID = " + IntToStr(keiryo_id);
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;

	if (ToInt(SET_TOP(set)["“¾ˆÓæID"])){
		sql = " SELECT “`•[î•ñID FROM V_“`•[î•ñŠÖ˜A"
			  " WHERE €–Ú”Ô† = 1 AND €–ÚID = " + IntToStr(ToInt(SET_TOP(set)["“¾ˆÓæID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["“`•[î•ñID"]);
	}

	if (ToInt(SET_TOP(set)["€–Ú1ID"])){
		sql = " SELECT “`•[î•ñID FROM V_“`•[î•ñŠÖ˜A"
			  " WHERE €–Ú”Ô† = 2 AND €–ÚID = " + IntToStr(ToInt(SET_TOP(set)["€–Ú1ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["“`•[î•ñID"]);
	}

	if (ToInt(SET_TOP(set)["€–Ú2ID"])){
		sql = " SELECT “`•[î•ñID FROM V_“`•[î•ñŠÖ˜A"
			  " WHERE €–Ú”Ô† = 3 AND €–ÚID = " + IntToStr(ToInt(SET_TOP(set)["€–Ú2ID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["“`•[î•ñID"]);
	}

	if (ToInt(SET_TOP(set)["•i–ÚID"])){
		sql = " SELECT “`•[î•ñID FROM V_“`•[î•ñŠÖ˜A"
			  " WHERE €–Ú”Ô† = 4 AND €–ÚID = " + IntToStr(ToInt(SET_TOP(set)["•i–ÚID"]));
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["“`•[î•ñID"]);
	}

	if (ToInt(SET_TOP(set)["Œ»Š|‹æ•ª"])){
        int kubun_id = 0;
        sql = " SELECT ‹æ•ªID FROM M_‹æ•ª WHERE ‹æ•ª•ª—ŞƒR[ƒh = 4 AND ‹æ•ªƒR[ƒh = " + IntToStr(ToInt(SET_TOP(set)["Œ»Š|‹æ•ª"]));
        if (DM->DBI.GetRecordSet(sql, subset))
            kubun_id = ToInt(SET_TOP(subset)["‹æ•ªID"]);

		sql = " SELECT “`•[î•ñID FROM V_“`•[î•ñŠÖ˜A"
			  " WHERE €–Ú”Ô† = 5 AND €–ÚID = " + IntToStr(kubun_id);
		if (DM->DBI.GetRecordSet(sql, subset))
			return ToInt(SET_TOP(subset)["“`•[î•ñID"]);
	}

	sql = " SELECT “`•[î•ñID FROM V_“`•[î•ñŠÖ˜A"
		  " WHERE €–Ú”Ô† = 0 AND €–ÚID = 0";
	if (DM->DBI.GetRecordSet(sql, subset))
		return ToInt(SET_TOP(subset)["“`•[î•ñID"]);
	else
		return 0;
}
//---------------------------------------------------------------------------
