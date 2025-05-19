//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DivideDateFrm.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TDivideDateForm *DivideDateForm;
//---------------------------------------------------------------------------
__fastcall TDivideDateForm::TDivideDateForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDivideDateForm::FormShow(TObject *Sender)
{
	TDateTime now(Now());
	Date1Picker->Date     = now;
	Date1NoFromEdit->Text = AnsiString();
	Date1NoToEdit->Text   = AnsiString();
	Date2Picker->Date     = now;
	Date2NoFromEdit->Text = AnsiString();
	Date2NoToEdit->Text   = AnsiString();
	Date3Picker->Date     = now;
	Date3NoFromEdit->Text = AnsiString();
	Date3NoToEdit->Text   = AnsiString();
	Date4Picker->Date     = now;
	Date4NoFromEdit->Text = AnsiString();
	Date4NoToEdit->Text   = AnsiString();
	Date5Picker->Date     = now;
	Date5NoFromEdit->Text = AnsiString();
	Date5NoToEdit->Text   = AnsiString();

    Date1NoFromEdit->Text = IntToStr(r1_from_);
    Date1NoToEdit->Text   = IntToStr(r1_to_);
    if (r2_from_){
    	Date2NoFromEdit->Text = IntToStr(r2_from_);
	    Date2NoToEdit->Text   = IntToStr(r2_to_);
    }
}
//---------------------------------------------------------------------------
void __fastcall TDivideDateForm::SetNoRange(int r1from, int r1to, int r2from, int r2to)
{
	r1_from_ = r1from;
    r1_to_   = r1to;
    r2_from_ = r2from;
    r2_to_   = r2to;
}
//---------------------------------------------------------------------------
void __fastcall TDivideDateForm::DateNPrevButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;
	TDateTimePicker *Picker = 0;
    if (tag == 1)
    	Picker = Date1Picker;
    else if (tag == 2)
    	Picker = Date2Picker;
    else if (tag == 3)
    	Picker = Date3Picker;
    else if (tag == 4)
    	Picker = Date4Picker;
    else if (tag == 5)
    	Picker = Date5Picker;

	if (Picker)
    	Picker->Date = IncDay(Picker->Date, -1);
}
//---------------------------------------------------------------------------
void __fastcall TDivideDateForm::DateNNextButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;
	TDateTimePicker *Picker = 0;
    if (tag == 1)
    	Picker = Date1Picker;
    else if (tag == 2)
    	Picker = Date2Picker;
    else if (tag == 3)
    	Picker = Date3Picker;
    else if (tag == 4)
    	Picker = Date4Picker;
    else if (tag == 5)
    	Picker = Date5Picker;

	if (Picker)
    	Picker->Date = IncDay(Picker->Date, 1);
}
//---------------------------------------------------------------------------
void __fastcall TDivideDateForm::PostButtonClick(TObject *Sender)
{
	NoRangeDates.clear();

	NRDates nrd;
	nrd.push_back(NoRangeDate(Date1NoFromEdit->Text.ToIntDef(0), Date1NoToEdit->Text.ToIntDef(0), Date1Picker->Date.FormatString("yyyymmdd").ToInt()));
	nrd.push_back(NoRangeDate(Date2NoFromEdit->Text.ToIntDef(0), Date2NoToEdit->Text.ToIntDef(0), Date2Picker->Date.FormatString("yyyymmdd").ToInt()));
	nrd.push_back(NoRangeDate(Date3NoFromEdit->Text.ToIntDef(0), Date3NoToEdit->Text.ToIntDef(0), Date3Picker->Date.FormatString("yyyymmdd").ToInt()));
	nrd.push_back(NoRangeDate(Date4NoFromEdit->Text.ToIntDef(0), Date4NoToEdit->Text.ToIntDef(0), Date4Picker->Date.FormatString("yyyymmdd").ToInt()));
	nrd.push_back(NoRangeDate(Date5NoFromEdit->Text.ToIntDef(0), Date5NoToEdit->Text.ToIntDef(0), Date5Picker->Date.FormatString("yyyymmdd").ToInt()));

    for (unsigned int i = 0; i < nrd.size(); i++){
    	if (nrd[i].from == 0 && nrd[i].to == 0){
        	; // ƒRƒs[‚µ‚È‚¢
        }else if (nrd[i].from == 0 || nrd[i].to == 0){
        	Application->MessageBox("“`•[”Ô†‚Ì”ÍˆÍ‚ª•Ð•û‚µ‚©Žw’è‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }else{
        	NoRangeDates.push_back(nrd[i]);
        }
    }

    if (NoRangeDates.empty()){
		Application->MessageBox("“`•[”Ô†‚ÌŽw’è‚ª‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ", Caption.c_str(), MB_OK | MB_ICONWARNING);
    	return;
    }

    ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TDivideDateForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
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

