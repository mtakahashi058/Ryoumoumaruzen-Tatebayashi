//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "RFIDWriteFrm.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSCRFIDIssueForm *SCRFIDIssueForm;
//---------------------------------------------------------------------------
__fastcall TSCRFIDIssueForm::TSCRFIDIssueForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSCRFIDIssueForm::FormShow(TObject *Sender)
{
	StatusMemo->Lines->Clear();
    on_writting_ = false;

	//WriteButton->SetFocus();

    WriteButton->Enabled = false;

    SCTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSCRFIDIssueForm::SetCommPort(int port)
{
    comm_port_ = port;
}
//---------------------------------------------------------------------------
void __fastcall TSCRFIDIssueForm::SetCardNo(int card_no)
{
    card_no_ = card_no;
}
//---------------------------------------------------------------------------
void __fastcall TSCRFIDIssueForm::SetCardImage(CardImage& image)
{
    image_ = image;
}
//---------------------------------------------------------------------------
bool __fastcall TSCRFIDIssueForm::IssueCard()
{
	StatusMemo->Lines->Clear();

    DWORD err_dword;
    AnsiString err_text;

    BYTE sw1, sw2;
    BYTE key[6];

    ZeroMemory(key, sizeof(key));
    HexStringToBytes(DM->cardKey.c_str(), key);

    if (!card_.LoadKey(sw1, sw2, key)){
        card_.GetLastError(err_dword, err_text);
        return false;
    }

    if (!IsSucceeded(sw1)){
        StatusMemo->Lines->Append("エラー: " + err_text);
        return false;
    }

    try {

        WriteImageToSmartCard_ultra(&card_, &image_);

    }catch(Exception& e){
        StatusMemo->Lines->Append(e.Message);
        return false;
    }

    card_.Disconnect();
/*
    HF04Issuer HF04(comm_port_);

    try{
        HF04.IssueCard(card_no_);
    }catch(Exception& e){
        StatusMemo->Lines->Append(e.Message);
		Application->MessageBox("エラーが発生しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
        return false;
    }
*/

	::MessageBeep(MB_ICONINFORMATION);

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TSCRFIDIssueForm::WriteButtonClick(TObject *Sender)
{
	WriteButton->Enabled = false;
	CancelButton->Enabled = false;

	if (IssueCard())
		ModalResult = mrOk;

	WriteButton->Enabled = true;
	CancelButton->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TSCRFIDIssueForm::SCTimerTimer(TObject *Sender)
{
    SCTimer->Enabled = false;

    DWORD err_dword;
    AnsiString err_text;
    DWORD event_dword;

    if (!DM->cardService.GetStatusChange(event_dword)) {
        DM->cardService.GetLastError(err_dword, err_text);
        StatusMemo->Lines->Append("エラー: " + err_text);
        return;
    }

    if (event_dword & SCARD_STATE_EMPTY){
        WriteButton->Enabled = false;
    }else if (event_dword & SCARD_STATE_PRESENT){
        OnCardPresent();
    }

    SCTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSCRFIDIssueForm::OnCardPresent()
{
    if (on_writting_)
        return;

    DWORD err_dword;
    AnsiString err_text;

    if (!DM->cardService.ConnectCard(&card_)){
        DM->cardService.GetLastError(err_dword, err_text);
        StatusMemo->Lines->Append("エラー: " + err_text);
        return;
    }

    WriteButton->Enabled = true;
}
//---------------------------------------------------------------------------

