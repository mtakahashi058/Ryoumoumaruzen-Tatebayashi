//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ErrorStateFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TErrorStateForm *ErrorStateForm;
//---------------------------------------------------------------------------
__fastcall TErrorStateForm::TErrorStateForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TErrorStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::Error, this);
}
//---------------------------------------------------------------------------
void __fastcall TErrorStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event != Event::Error)
		return;

	LPCSTR message = reinterpret_cast<LPCSTR>(param);
	ErrorMemo->Lines->Text = message;
}
//---------------------------------------------------------------------------
void __fastcall TErrorStateForm::OnEnter()
{
    SFM.AddLog("ƒGƒ‰[’Ê’m‰æ–Ê");

	KeiryoStateBaseForm->StatusBar->SimpleText = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TErrorStateForm::OnExit()
{
//
}
//---------------------------------------------------------------------------

