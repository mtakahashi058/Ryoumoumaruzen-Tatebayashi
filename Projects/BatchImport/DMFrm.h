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
#include "nsoftfunc.h"
#include "NsIni.h"
#include "NsConfig.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:    // IDE �Ǘ��̃R���|�[�l���g
    TADOConnection *ADOConnection;
private:    // ���[�U�[�錾
public:     // ���[�U�[�錾
	__fastcall TDM(TComponent* Owner);
    NsDBInterface DBI;
    NsIni INI;
    NsConfig CFG;
    bool __fastcall Init();

	int __fastcall GetKanzanID(int toku_id, int meig_id);
	Currency __fastcall GetKanzan(int toku_id, int meig_id, int tani_id);
	Currency __fastcall GetTanka(int toku_id, int meig_id, int item1_id, int item2_id, int tani_id);
	Currency __fastcall GetSalesTax(int date = 0);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
