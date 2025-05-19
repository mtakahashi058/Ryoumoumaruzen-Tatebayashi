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
// 入金予定日を取得
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
// 請求先に関連づいている得意先の件数を取得
int __fastcall TDM::GetTokuCount(int s_dt, int e_dt, int seikyu_id)
{
	AnsiString sql =
		" DECLARE @SEIKYU_ID AS [DECIMAL]"	// " DECLARE @SEIKYU_ID AS [VARCHAR]" 2009.12.22 修正
		" SET @SEIKYU_ID = " + IntToStr(seikyu_id) +
		" "
		" SELECT"
		" 	請求先ID, COUNT(*) AS 件数"
		" FROM"
		" 	M_得意先"
		" WHERE"
		" 	請求先ID = @SEIKYU_ID"
		" GROUP BY"
		" 	請求先ID";

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[0]["件数"]);
}
//---------------------------------------------------------------------------
void __fastcall TDM::Q_SeikyuCalcFields(TDataSet *DataSet)
{
	if (!Q_Seikyu->FieldByName("取引日")->IsNull){
		try{
			Q_Seikyu->FieldByName("簡易取引日")->AsString = IntToDate(Q_Seikyu->FieldByName("取引日")->AsInteger).FormatString("mm/dd");
		}catch (...){}
	}
}
//---------------------------------------------------------------------------
// 締日コードから請求開始日付を取得
TDateTime __fastcall TDM::GetDateFrom(int sime)
{
	TDateTime D;
	WORD y, m, d;
	WORD yy, mm, dd;

	if (sime == 0 || sime >= 29){	// 末締め
		return GetFirstDate(IncMonth(Date(), -1));

	}else{			// 末締め以外
		DecodeDate(Date(), y, m, d);

		for(D = EncodeDate(y, m, d); D >= EncodeDate(y-1, m, 1); D--){
			DecodeDate(D, yy, mm, dd);
			if(dd == sime)	// 同じ日付だったらループを抜ける
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
// 締日コードから請求開始日付を取得
TDateTime __fastcall TDM::GetDateTo(int sime)
{
	TDateTime D;
	WORD y, m, d;
	WORD yy, mm, dd;

	if (sime == 0 || sime >= 29){	// 末締め
		return GetLastDate(IncMonth(Date(), -1));

	}else{			// 末締め以外
		DecodeDate(Date(), y, m, d);

		for(D = EncodeDate(y, m, d); D >= EncodeDate(y-1, m, 1); D--){
			DecodeDate(D, yy, mm, dd);
			if(dd == sime)	// 同じ日付だったらループを抜ける
				break;
		}
		return IntToDate((yy * 10000) + (mm * 100) + dd);
	}
}
//---------------------------------------------------------------------------

