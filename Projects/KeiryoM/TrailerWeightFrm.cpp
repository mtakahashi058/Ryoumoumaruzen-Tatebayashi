//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "TrailerWeightFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "CEdit"
#pragma resource "*.dfm"
TTrailerWeightForm *TrailerWeightForm;
//---------------------------------------------------------------------------
__fastcall TTrailerWeightForm::TTrailerWeightForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::FormShow(TObject *Sender)
{
	FirstWEdit->Text  = AnsiString();
	SecondWEdit->Text = AnsiString();
	TotalWEdit->Text  = AnsiString();

	FirstWEdit->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
	/*
		if (ActiveControl->Tag != 999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
	*/
		break;
	case VK_UP:
		if (ActiveControl->Tag != 1){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::Action5Execute(TObject *Sender)
{
	ModalResult = mrOk;	
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::Action12Execute(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::CalcWeight()
{
	Currency w1, w2, total;

	try{
		w1 = StrToCurr(FirstWEdit->Text);
		w2 = StrToCurr(SecondWEdit->Text);
		total = w1 + w2;
	}catch(...){
		TotalWEdit->Text = AnsiString();
		return;
	}

	TotalWEdit->Text = AnsiString(total);
	TotalWeight = total;
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::FirstWEditEnter(TObject *Sender)
{
	TitlePanel->Caption = "‚P‰ñ–Ú‚ÌŒv—Ê‚ðs‚¢‚Ü‚·";
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::SecondWEditEnter(TObject *Sender)
{
	TitlePanel->Caption = "‚Q‰ñ–Ú‚ÌŒv—Ê‚ðs‚¢‚Ü‚·";
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::FirstWEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	if (FirstWEdit->Text.IsEmpty())
		FirstWEdit->Text = MainForm->GetWeight();
	SecondWEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::SecondWEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	if (SecondWEdit->Text.IsEmpty())
		SecondWEdit->Text = MainForm->GetWeight();
	TotalWEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::TotalWEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::OnWEditChange(TObject *Sender)
{
	CalcWeight();
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::WeightButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;
	if (tag == 1)
		FirstWEdit->Text = MainForm->GetWeight();
	else if (tag == 2)
		SecondWEdit->Text = MainForm->GetWeight();
	CalcWeight();
}
//---------------------------------------------------------------------------
void __fastcall TTrailerWeightForm::TotalWEditEnter(TObject *Sender)
{
	TotalWEdit->SelStart = 0;
	TotalWEdit->SelLength = 0;
}
//---------------------------------------------------------------------------

