//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner), DBI(ADOConnection)
{
}
//---------------------------------------------------------------------------
// Connection �̊m���Ɛݒ�̓ǂݍ���
bool __fastcall TDM::Init()
{
	ini_.Load(ExtractFilePath(Application->ExeName) + "settings.ini");

	if (ADOConnection->Connected)
		ADOConnection->Close();
	try{
		ADOConnection->ConnectionString = "FILE NAME=" + ToString(ini_["ADO::UDL"]);
		ADOConnection->Open();
	}catch(Exception& e){
		Application->MessageBox((	"�f�[�^�x�[�X�ڑ��Ɏ��s���܂����B\r\n"
									"�Г��l�b�g���[�N�ɖ�肪�Ȃ��������m�F���������B\r\n\r\n"
									"�@�ELAN�P�[�u�������������Ă��Ȃ����B\r\n"
									"�@�EHUB�̓d���������Ă��邩�B�Ȃ�\r\n\r\n"
									"�����g�p�̒[�������ł͂Ȃ��A�T�[�o�@�ւ̌o�H�����m�F���������B\r\n"
									"\r\n[�ڍ�]" + e.Message).c_str(),
								Application->Title.c_str(),
								MB_OK | MB_ICONHAND);
		return false;
	}

	config_.Load(&DBI);

	return true;
}
//---------------------------------------------------------------------------

