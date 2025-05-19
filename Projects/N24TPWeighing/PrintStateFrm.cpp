//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PrintStateFrm.h"
#include "DMFrm.h"
#include <mmsystem.h>
#include "n24tp.h"
#include "QRChitFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrintStateForm *PrintStateForm;
//---------------------------------------------------------------------------
__fastcall TPrintStateForm::TPrintStateForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::ConfirmPrint, this);
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::OnEnter()
{
	SFM.AddLog("“`•[Šm”F‰æ–Ê ŽÔ—¼ID/ŽÔ”Ô: " + ToString(SFM.Stashed("ŽÔ—¼ID")) + "/" + ToString(SFM.car_rec["ŽÔ”Ô"]));

	SFM.SendStatus(AnsiString());

	try{
		// [CFG] Keiryo::CompleteFile
		NoticeRichEdit->Lines->LoadFromFile(ToString(DM->INI["Keiryo::CompleteFile"]));
	}catch(...){
		NoticeRichEdit->Lines->Clear();
	}

	if (ToBit(SFM.Stashed("d—ÊŒv—Ê•["))){
        /*
		Title1Label->Caption = "Œv—Ê‚ªŠ®—¹‚µ‚Ü‚µ‚½";
		Title2Label->Caption = "“`•[‚ðŠm”F‚µ‚Ä‚­‚¾‚³‚¢";

		ReprintButton->Visible = true;

		PlaySound(ToString(DM->Sounds["Print"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

		PrintWeightChit();
        */
	}else{
		// [CFG] Chit::Print
		if (ToBit(DM->INI["Chit::Print"])){
			Title1Label->Caption = "Œv—Ê‚ªŠ®—¹‚µ‚Ü‚µ‚½";
			Title2Label->Caption = "“`•[‚ðŠm”F‚µ‚Ä‚­‚¾‚³‚¢";

			ReprintButton->Visible = true;

			PlaySound(ToString(DM->Sounds["Print"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

			Print();
		}else{
			Title1Label->Caption = "Œv—Ê‚ªŠ®—¹‚µ‚Ü‚µ‚½";
			Title2Label->Caption = "ŽÔ—¼‚ð‚Í‚©‚è‚©‚ç~‚ë‚µ‚Ä‰º‚³‚¢";

			ReprintButton->Visible = false;

			PlaySound(ToString(DM->Sounds["Complete"]).c_str(), 0, SND_ASYNC | SND_FILENAME);
		}
	}

	SFM.SendEvent(State::ForceWeighingEnabled, reinterpret_cast<LPVOID>(true));

	//ForceTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::OnExit()
{
	SFM.SendEvent(State::ForceWeighingEnabled, reinterpret_cast<LPVOID>(false));

	ForceTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::ReprintButtonClick(TObject *Sender)
{
	if (ToBit(SFM.Stashed("d—ÊŒv—Ê•["))){
		;//PrintWeightChit();
	}else{
        ReprintButton->Enabled = false;
		Print();
    }
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::Print()
{
	AnsiString sql = "SELECT * FROM V_Œv—Ê WHERE Œv—ÊID = " + ToString(SFM.Stashed("Œv—ÊID"));
	NsRecordSet set;

	try{
		QRChitForm->Print(ToInt(SFM.Stashed("Œv—ÊID")));
	}catch(Exception& e){
		SFM.SendStatus(e.Message);
		::MessageBeep(MB_ICONEXCLAMATION);
		return;
	}

    ReprintTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::ForceTimerTimer(TObject *Sender)
{
	ForceTimer->Enabled = false;

	SFM.Transit(State::WaitCard);
}
//---------------------------------------------------------------------------

void __fastcall TPrintStateForm::ReprintTimerTimer(TObject *Sender)
{
    ReprintTimer->Enabled = false;

    ReprintButton->Enabled = true;    
}
//---------------------------------------------------------------------------

