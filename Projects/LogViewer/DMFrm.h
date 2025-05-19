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
#include "nsoftfunc.h"
#include "NsDB.h"
#include "NsIni.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TADOConnection *ADOConnection;
	TADOQuery *Q_Log;
	TAutoIncField *Q_LogID;
	TStringField *Q_LogDSDesigner;
	TStringField *Q_LogDSDesigner2;
	TSmallintField *Q_LogDSDesigner3;
	TDateTimeField *Q_LogDSDesigner4;
	TStringField *Q_LogDSDesigner5;
	void __fastcall ADOConnectionBeforeConnect(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TDM(TComponent* Owner);
	NsIni ini_;
    NsDBInterface DBI;
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
