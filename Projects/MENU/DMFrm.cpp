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
// Connection の確立と設定の読み込み
bool __fastcall TDM::Init()
{
	ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");

	if (ADOConnection->Connected)
		ADOConnection->Close();
	try{
		ADOConnection->ConnectionString = "FILE NAME=" + ToString(ini_["ADO::UDL"]);
		ADOConnection->Open();
	}catch(Exception& e){
		Application->MessageBox((	"データベース接続に失敗しました。\r\n"
									"社内ネットワークに問題がないかをご確認ください。\r\n\r\n"
									"　・LANケーブルが抜けかけていないか。\r\n"
									"　・HUBの電源が入っているか。など\r\n\r\n"
									"※ご使用の端末だけではなく、サーバ機への経路をご確認ください。\r\n"
									"\r\n[詳細]" + e.Message).c_str(),
								Application->Title.c_str(),
								MB_OK | MB_ICONHAND);
		return false;
	}

	config_.Load(&DBI);

	return true;
}
//---------------------------------------------------------------------------

