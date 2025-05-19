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
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
	TADOQuery *Q_Itiran;
	TIntegerField *Q_ItiranID;
	TIntegerField *Q_ItiranDSDesigner;
	TStringField *Q_ItiranDSDesigner2;
	TIntegerField *Q_ItiranDSDesigner3;
	TIntegerField *Q_ItiranNo;
	TStringField *Q_ItiranDSDesigner4;
	TStringField *Q_ItiranDSDesigner5;
	TIntegerField *Q_ItiranDSDesigner6;
	TStringField *Q_ItiranDSDesigner7;
	TIntegerField *Q_ItiranDSDesigner8;
	TStringField *Q_ItiranDSDesigner9;
	TStringField *Q_ItiranDSDesigner10;
	TIntegerField *Q_ItiranDSDesigner1;
	TStringField *Q_ItiranDSDesigner12;
	TIntegerField *Q_ItiranDSDesigner22;
	TStringField *Q_ItiranDSDesigner23;
	TBCDField *Q_ItiranDSDesigner11;
	TStringField *Q_ItiranDSDesigner13;
	TBCDField *Q_ItiranDSDesigner14;
	TBCDField *Q_ItiranDSDesigner15;
	TBCDField *Q_ItiranDSDesigner16;
	TBCDField *Q_ItiranID2;
	void __fastcall ADOConnectionBeforeConnect(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);

	NsDBInterface DBI;
	NsIni         INI;
	NsConfig      CFG;

	AnsiString __fastcall GetExtractionQuery(AnsiString where);
	Currency __fastcall GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id);
    Currency __fastcall GetSalesTax(int date);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
