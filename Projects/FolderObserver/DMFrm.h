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
#include "NsVar.h"
#include "NsIni.h"
#include "NsConfig.h"
#include "NsDateLog.h"
#include "nsoftfunc.h"
// ---------------------------------------------------------------------------
#include <memory>
// ---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TADOConnection *ADOConnection;
	TADOConnection *PrintConnection;
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TDM(TComponent* Owner);

	NsDBInterface DBI;
	NsIni INI;
	NsConfig CFG;
	NsDateLog LOG;

	bool __fastcall Init();
	AnsiString __fastcall TrimSpace(const AnsiString& src);
	bool __fastcall GetKeiryoKey(int keiryo_id, int& date, int& place_id, int& no);
	int __fastcall GetPrintInfo(int keiryo_id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
