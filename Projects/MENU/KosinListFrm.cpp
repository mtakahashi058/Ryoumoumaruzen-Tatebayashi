//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KosinListFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKosinListForm *KosinListForm;
//---------------------------------------------------------------------------
__fastcall TKosinListForm::TKosinListForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKosinListForm::FormShow(TObject *Sender)
{
	chSettingFile->Checked = false;	
}
//---------------------------------------------------------------------------
