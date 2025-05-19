//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "N24TPCardsFrm.h"
#include "n24tp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TN24TPCardsForm *N24TPCardsForm;
//---------------------------------------------------------------------------
__fastcall TN24TPCardsForm::TN24TPCardsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TN24TPCardsForm::CancelButtonClick(TObject *Sender)
{
    ModalResult = 0;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TN24TPCardsForm::AdminButtonClick(TObject *Sender)
{
    ModalResult = N24TP::ADMIN_CARD_NO;
}
//---------------------------------------------------------------------------
void __fastcall TN24TPCardsForm::ZeroSetButtonClick(TObject *Sender)
{
    ModalResult = N24TP::SET_ZERO_CARD_NO;
}
//---------------------------------------------------------------------------
void __fastcall TN24TPCardsForm::ZeroClrButtonClick(TObject *Sender)
{
    ModalResult = N24TP::CLR_ZERO_CARD_NO;
}
//---------------------------------------------------------------------------
