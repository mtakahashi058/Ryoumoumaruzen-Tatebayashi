//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NotifyFrm.h"
#include <mmsystem.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNotifyForm *NotifyForm;
//---------------------------------------------------------------------------
__fastcall TNotifyForm::TNotifyForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNotifyForm::FormCreate(TObject *Sender)
{
    SetWindowPos(Application->Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE + SWP_NOMOVE);

	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
    Width = rect.right - rect.left;
	Left = rect.left;
	Top  = rect.bottom - Height;
    //Top = rect.top + 1;
}
//---------------------------------------------------------------------------
void __fastcall TNotifyForm::Show()
{
    // override
	PlaySound(Sound.c_str(), 0, SND_ASYNC | SND_FILENAME);                 

    TForm::Show();
}
//---------------------------------------------------------------------------
void __fastcall TNotifyForm::Notify(const AnsiString& text, bool highlight, int disp_msec)
{
    if (HideTimer->Enabled)
        HideTimer->Enabled = false;
    HideTimer->Interval = disp_msec;

    TitlePanel->Caption     = "  " + text + Now().FormatString("' (Žž: 'hh:nn')'");
    TitlePanel->Font->Color = highlight ? clRed : clBlack;

    Show();

    HideTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TNotifyForm::ApplicationEventsDeactivate(TObject *Sender)
{
    SetWindowPos(Application->Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}
//---------------------------------------------------------------------------
void __fastcall TNotifyForm::HideTimerTimer(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

