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
		" 	vÊID AS [ID],"
		" 	1 AS f[^æª, 'vÊ' AS f[^æª¼Ì,"
		" 	vÊú AS út,"
		" 	`[No,"
		" 	_ID, _¼Ì,"
		" 	Àüoæª¼,"
		" 	¾ÓæR[h, ¾Óæ¼Ì,"
		" 	iÚR[h,   iÚ¼Ì,  æøæª¼,"
		" 	Ú1R[h,  Ú1¼Ì,"
		" 	Ú2R[h,  Ú2¼Ì,"
		" 	Ê,"
		" 	PÊ}X^¼Ì,"
		" 	P¿,"
		" 	àz,"
		" 	ÁïÅz"
		" FROM"
		" 	V_vÊ"
		" WHERE"
		" 	®¹æª = 1"
		" AND"
		" 	vÊú BETWEEN @DATE_FROM AND @DATE_TO"
		" AND"
		" 	»|æª = @GENKAKE"
		" $WHERE$"
		" "
		" UNION"
		" "
		" SELECT"
		" 	æøID AS [ID],"
		" 	2 AS f[^æª, 'æø' AS f[^æª¼Ì,"
		" 	æøú AS út,"
		" 	`[No,"
		" 	_ID, _¼Ì,"
		" 	'' AS Àüoæª¼Ì,"
		" 	¾ÓæR[h, ¾Óæ¼Ì,"
		" 	iÚR[h,   iÚ¼Ì,  æøæª¼Ì,"
		" 	Ú1R[h,  Ú1¼Ì,"
		" 	Ú2R[h,  Ú2¼Ì,"
		" 	Ê,"
		" 	PÊ}X^¼Ì,"
		" 	P¿,"
		" 	àz,"
		" 	ÁïÅz	"
		" FROM"
		" 	V_æø"
		" WHERE"
		" 	®¹æª = 1"
		" AND"
		" 	æøú BETWEEN @DATE_FROM AND @DATE_TO"
		" AND"
		" 	»|æª = @GENKAKE"
		" $WHERE$"
		" ORDER BY"
		" 	f[^æª, út, `[No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// P¿Ìæ¾
Currency __fastcall TDM::GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id)
{
	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT * FROM M_P¿"
		  " WHERE"
		  " 	¾ÓæID = " + IntToStr(toku_id) +
		  " AND"
		  " 	iÚID   = " + IntToStr(meig_id) +
		  " AND"
		  " 	Ú1ID  = " + IntToStr(item1_id) +
		  " AND"
		  " 	Ú2ID  = " + IntToStr(item2_id) +
		  " AND"
		  " 	PÊID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["P¿"]);
	}

	sql = " SELECT * FROM M_P¿"
		  " WHERE"
		  " 	¾ÓæID  = " + IntToStr(toku_id) +
		  " AND"
		  " 	iÚID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	Ú1ID   = " + IntToStr(item1_id) +
		  " AND"
		  " 	(Ú2ID  = 0 OR Ú2ID IS NULL)"
		  " AND"
		  " 	PÊID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["P¿"]);
	}

	sql = " SELECT * FROM M_P¿"
		  " WHERE"
		  " 	¾ÓæID  = " + IntToStr(toku_id) +
		  " AND"
		  " 	iÚID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	(Ú1ID  = 0 OR Ú1ID IS NULL)"
		  " AND"
		  " 	(Ú2ID  = 0 OR Ú2ID IS NULL)"
		  " AND"
		  " 	PÊID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["P¿"]);
	}

	sql = " SELECT * FROM M_P¿"
		  " WHERE"
		  " 	(¾ÓæID = 0 OR ¾ÓæID IS NULL)"
		  " AND"
		  " 	iÚID    = " + IntToStr(meig_id) +
		  " AND"
		  " 	(Ú1ID  = 0 OR Ú1ID IS NULL)"
		  " AND"
		  " 	(Ú2ID  = 0 OR Ú2ID IS NULL)"
		  " AND"
		  " 	PÊID    = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["P¿"]);
	}

	// WP¿
	sql = " SELECT * FROM M_P¿"
		  " WHERE"
		  " 	(¾ÓæID = 0 OR ¾ÓæID IS NULL)"
		  " AND"
		  " 	(iÚID   = 0 OR iÚID IS NULL)"
		  " AND"
		  " 	(Ú1ID  = 0 OR Ú1ID IS NULL)"
		  " AND"
		  " 	(Ú2ID  = 0 OR Ú2ID IS NULL)"
		  " AND"
		  " 	PÊID   = " + IntToStr(tani_id);
	if (DM->DBI.GetRecordSet(sql, set)){
		return ToCurrency(SET_TOP(set)["P¿"]);
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

	sql = " SELECT TOP 1 ÁïÅ¦ FROM M_ÁïÅ"
		  " WHERE"
		  " 	Jnút <= " + IntToStr(date) +
		  " ORDER BY Jnút DESC";
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0.05;
	int n = ToInt(SET_TOP(set)["ÁïÅ¦"]);
	return n / Currency(100);
}
//---------------------------------------------------------------------------

