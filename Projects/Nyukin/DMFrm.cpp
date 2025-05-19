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
AnsiString __fastcall TDM::GetItiranQuery(AnsiString where)
{
	AnsiString sql =
		" SELECT"
		" 	入金ID,"
		" 	拠点コード, 拠点名称,"
		" 	伝票No,"
		" 	入金日,"
		" 	請求先コード, 請求先名称, 請求先略称,	"
		"	現金 + 振込 + 手数料 + 小切手 + 手形 + 相殺 + 値引き + 調整 + その他 AS 合計,"	
		" 	現金,"
		" 	振込,"
		" 	手数料,"
		" 	小切手,"
		" 	手形,"
		" 	相殺,"
		" 	値引き,"
		" 	調整,"
		" 	その他,	"
		" 	銀行コード, 銀行名称, 支店名称, 口座,"
		" 	手形期日,"
		" 	備考,"
		" 	更新日時,"
		" 	作成日時"
		" FROM"
		" 	V_入金"
		" $WHERE$"
		"";
		//" ORDER BY"
		//" 	拠点コード, 伝票No";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
