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
	TADOQuery *Q_Seikyu;
	TBCDField *Q_SeikyuDSDesigner;
	TBCDField *Q_SeikyuDSDesigner2;
	TBCDField *Q_SeikyuDSDesigner3;
	TAutoIncField *Q_SeikyuID;
	TIntegerField *Q_SeikyuDSDesigner4;
	TStringField *Q_SeikyuDSDesigner5;
	TStringField *Q_SeikyuDSDesigner6;
	TStringField *Q_SeikyuDSDesigner1;
	TStringField *Q_SeikyuDSDesigner22;
	TStringField *Q_SeikyuDSDesigner7;
	TStringField *Q_SeikyuFAX;
	TIntegerField *Q_SeikyuDSDesigner8;
	TIntegerField *Q_SeikyuDSDesigner9;
	TIntegerField *Q_SeikyuDSDesigner10;
	TIntegerField *Q_SeikyuDSDesigner11;
	TIntegerField *Q_SeikyuDSDesigner12;
	TIntegerField *Q_SeikyuDSDesigner13;
	TIntegerField *Q_SeikyuDSDesigner14;
	TIntegerField *Q_SeikyuID2;
	TIntegerField *Q_SeikyuDSDesigner15;
	TStringField *Q_SeikyuDSDesigner16;
	TStringField *Q_SeikyuDSDesigner17;
	TIntegerField *Q_SeikyuDSDesigner18;
	TStringField *Q_SeikyuDSDesigner19;
	TStringField *Q_SeikyuDSDesigner20;
	TIntegerField *Q_SeikyuDSDesigner21;
	TBCDField *Q_SeikyuDSDesigner23;
	TBCDField *Q_SeikyuDSDesigner24;
	TBCDField *Q_SeikyuDSDesigner25;
	TBCDField *Q_SeikyuDSDesigner26;
	TBCDField *Q_SeikyuDSDesigner27;
	TBCDField *Q_SeikyuDSDesigner28;
	TBCDField *Q_SeikyuDSDesigner29;
	TIntegerField *Q_SeikyuID3;
	TStringField *Q_SeikyuDSDesigner31;
	TIntegerField *Q_SeikyuDSDesigner32;
	TIntegerField *Q_SeikyuNo;
	TIntegerField *Q_SeikyuID5;
	TIntegerField *Q_SeikyuDSDesigner33;
	TStringField *Q_SeikyuDSDesigner34;
	TIntegerField *Q_SeikyuID6;
	TIntegerField *Q_SeikyuDSDesigner35;
	TStringField *Q_SeikyuDSDesigner36;
	TIntegerField *Q_SeikyuDSDesigner1ID;
	TIntegerField *Q_SeikyuDSDesigner110;
	TStringField *Q_SeikyuDSDesigner111;
	TStringField *Q_SeikyuDSDesigner112;
	TIntegerField *Q_SeikyuDSDesigner2ID;
	TIntegerField *Q_SeikyuDSDesigner210;
	TStringField *Q_SeikyuDSDesigner211;
	TStringField *Q_SeikyuDSDesigner212;
	TIntegerField *Q_SeikyuID7;
	TIntegerField *Q_SeikyuDSDesigner37;
	TStringField *Q_SeikyuDSDesigner38;
	TStringField *Q_SeikyuDSDesigner39;
	TBCDField *Q_SeikyuDSDesigner40;
	TIntegerField *Q_SeikyuID8;
	TIntegerField *Q_SeikyuDSDesigner41;
	TStringField *Q_SeikyuDSDesigner42;
	TBCDField *Q_SeikyuDSDesigner43;
	TBCDField *Q_SeikyuDSDesigner44;
	TStringField *Q_SeikyuDSDesigner45;
	TStringField *Q_SeikyuDSDesigner46;
	TIntegerField *Q_SeikyuDSDesigner47;
	TStringField *Q_SeikyuField;
	TIntegerField *Q_SeikyuDSDesigner30;
	TStringField *Q_SeikyuDSDesigner48;
	TIntegerField *Q_SeikyuNo2;
	TIntegerField *Q_SeikyuID9;
	TIntegerField *Q_SeikyuDSDesigner49;
	TStringField *Q_SeikyuDSDesigner50;
	TBCDField *Q_SeikyuID4;
	TStringField *Q_SeikyuG1;
	TStringField *Q_SeikyuG2;
	TStringField *Q_SeikyuG3;
	TStringField *Q_SeikyuG4;
	TStringField *Q_SeikyuG5;
	TADOQuery *Q_SimeCheck;
	TIntegerField *Q_SimeCheckDSDesigner;
	TStringField *Q_SimeCheckDSDesigner2;
	TIntegerField *Q_SimeCheckDSDesigner3;
	void __fastcall ADOConnectionBeforeConnect(TObject *Sender);
	void __fastcall Q_SeikyuCalcFields(TDataSet *DataSet);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDM(TComponent* Owner);
	NsDBInterface DBI;
	NsIni ini_;
	NsConfig config_;
	int zeiritu;
	TDateTime __fastcall GetNyukinYotei(TDateTime dt, int site, int sime);
	bool __fastcall SetPrinter(TQuickRep *quickrep, AnsiString asPrtName);
	int __fastcall GetTokuCount(int s_dt, int e_dt, int seikyu_id);
	TDateTime __fastcall GetDateFrom(int sime);
	TDateTime __fastcall GetDateTo(int sime);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
