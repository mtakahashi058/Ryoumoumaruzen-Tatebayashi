//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RFIDWriteFrm.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRFIDIssueForm *RFIDIssueForm;
//---------------------------------------------------------------------------
__fastcall TRFIDIssueForm::TRFIDIssueForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRFIDIssueForm::FormShow(TObject *Sender)
{
	StatusMemo->Lines->Clear();

	WriteButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TRFIDIssueForm::SetCommPort(int port)
{
    comm_port_ = port;
}
//---------------------------------------------------------------------------
void __fastcall TRFIDIssueForm::SetCardNo(int card_no)
{
    card_no_ = card_no;
}
//---------------------------------------------------------------------------
bool __fastcall TRFIDIssueForm::IssueCard()
{
	StatusMemo->Lines->Clear();

    HF04Issuer HF04(comm_port_);

    try{
        HF04.IssueCard(card_no_);
    }catch(Exception& e){
        StatusMemo->Lines->Append(e.Message);
		Application->MessageBox("ƒGƒ‰[‚ª”­¶‚µ‚Ü‚µ‚½", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
        return false;
    }

	::MessageBeep(MB_ICONINFORMATION);

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TRFIDIssueForm::WriteButtonClick(TObject *Sender)
{
	WriteButton->Enabled = false;
	CancelButton->Enabled = false;

	if (IssueCard())
		ModalResult = mrOk;

	WriteButton->Enabled = true;
	CancelButton->Enabled = true;
}
//---------------------------------------------------------------------------

