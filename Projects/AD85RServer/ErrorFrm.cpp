//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ErrorFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TErrorForm *ErrorForm;
//---------------------------------------------------------------------------
__fastcall TErrorForm::TErrorForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TErrorForm::FormCreate(TObject *Sender)
{
    SetWindowPos(Application->Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE + SWP_NOMOVE);
}
//---------------------------------------------------------------------------
void __fastcall TErrorForm::CloseButtonClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TErrorForm::ApplicationEventsDeactivate(TObject *Sender)
{
    SetWindowPos(Application->Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}
//---------------------------------------------------------------------------

