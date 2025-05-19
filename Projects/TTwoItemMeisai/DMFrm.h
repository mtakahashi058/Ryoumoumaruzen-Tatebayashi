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
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TADOConnection *ADOConnection;
	void __fastcall ADOConnectionBeforeConnect(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TDM(TComponent* Owner);

	NsDBInterface DBI;
	NsIni ini_;
	NsConfig config_;

AnsiString __fastcall GetReportSQL(AnsiString target_total1, AnsiString target_code1, AnsiString target_name1,
										AnsiString target_total2, AnsiString target_code2, AnsiString target_name2,
										AnsiString where);
AnsiString __fastcall GetHinShukeiSQL(AnsiString where);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
