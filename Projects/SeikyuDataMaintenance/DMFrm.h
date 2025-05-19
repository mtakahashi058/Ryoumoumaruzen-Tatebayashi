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
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE 管理のコンポーネント
	TADOConnection *ADOConnection;
	TADOQuery *Q_Itiran;
	TAutoIncField *Q_ItiranID;
	TIntegerField *Q_ItiranDSDesigner;
	TIntegerField *Q_ItiranDSDesigner2;
	TIntegerField *Q_ItiranDSDesigner3;
	TStringField *Q_ItiranDSDesigner4;
	TIntegerField *Q_ItiranDSDesigner5;
	TIntegerField *Q_ItiranDSDesigner6;
	TIntegerField *Q_ItiranDSDesigner13;
	TDateTimeField *Q_ItiranDSDesigner14;
	TDateTimeField *Q_ItiranDSDesigner15;
	TBCDField *Q_ItiranDSDesigner7;
	TBCDField *Q_ItiranDSDesigner8;
	TBCDField *Q_ItiranDSDesigner9;
	TBCDField *Q_ItiranDSDesigner10;
	TBCDField *Q_ItiranDSDesigner11;
	TBCDField *Q_ItiranDSDesigner12;
	TBCDField *Q_ItiranDSDesigner16;
	TIntegerField *Q_ItiranDSDesigner17;
	void __fastcall ADOConnectionBeforeConnect(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);

	NsDBInterface DBI;
	NsIni INI;

	AnsiString __fastcall GetBaseQuery();
	int __fastcall GetShohizeiritu(AnsiString date);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
