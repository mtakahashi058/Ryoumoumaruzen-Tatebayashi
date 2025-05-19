//---------------------------------------------------------------------------

#ifndef DMFrmH
#define DMFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
#include "NsDB.h"
#include "NsIni.h"
#include "NsConfig.h"
//---------------------------------------------------------------------------
#include "SmartCard.h"
#include "CardStruct.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
    TADOQuery *Q_Shaban;
    TIntegerField *Q_ShabanID;
    TStringField *Q_ShabanDSDesigner3;
    TStringField *Q_ShabanDSDesigner4;
    TStringField *Q_ShabanDSDesigner12;
    TStringField *Q_ShabanDSDesigner22;
    TStringField *Q_ShabanDSDesigner5;
    TIntegerField *Q_ShabanDSDesigner;
    TBCDField *Q_ShabanDSDesigner2;
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);
	NsDBInterface DBI;
    NsIni INI;
    NsConfig CFG;

    bool __fastcall Init();

    // スマートカード
    SmartCardService cardService;
    AnsiString       cardKey;
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
