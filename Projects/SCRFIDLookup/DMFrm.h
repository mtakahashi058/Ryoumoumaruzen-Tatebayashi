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
// winscard.lib���v���W�F�N�g�ɒǉ�����
#include "SmartCard.h"
#include "CardStruct.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TADOConnection *ADOConnection;
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TDM(TComponent* Owner);
	NsDBInterface DBI;
    NsIni INI;
    NsConfig CFG;

    // �X�}�[�g�J�[�h
    SmartCard card_;
    SmartCardService cardService;
    AnsiString CardKey;

    bool __fastcall Init();
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
