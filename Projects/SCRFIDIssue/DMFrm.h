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
__published:	// IDE �Ǘ��̃R���|�[�l���g
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
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TDM(TComponent* Owner);
	NsDBInterface DBI;
    NsIni INI;
    NsConfig CFG;

    bool __fastcall Init();

    // �X�}�[�g�J�[�h
    SmartCardService cardService;
    AnsiString       cardKey;
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
