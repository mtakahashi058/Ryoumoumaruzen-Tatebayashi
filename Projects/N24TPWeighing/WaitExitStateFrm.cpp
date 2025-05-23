//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WaitExitStateFrm.h"
#include "DMFrm.h"
#include <mmsystem.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWaitExitStateForm *WaitExitStateForm;
//---------------------------------------------------------------------------
__fastcall TWaitExitStateForm::TWaitExitStateForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWaitExitStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::WaitExit, this);
}
//---------------------------------------------------------------------------
void __fastcall TWaitExitStateForm::OnEnter()
{
	SFM.AddLog("降車確認画面 車両ID/車番: " + ToString(SFM.Stashed("車両ID")) + "/" + ToString(SFM.car_rec["車番"]));

	SFM.SendStatus(AnsiString());

	try{
		// [CFG] Keiryo::MessageFile
		NoticeRichEdit->Lines->LoadFromFile(ToString(DM->INI["Keiryo::MessageFile"]));
	}catch(...){
		NoticeRichEdit->Lines->Clear();
	}

	PlaySound(ToString(DM->Sounds["ExitWeighing"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

	SFM.SendEvent(State::ForceWeighingEnabled, reinterpret_cast<LPVOID>(true));
}
//---------------------------------------------------------------------------
void __fastcall TWaitExitStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TWaitExitStateForm::OnExit()
{
	SFM.SendEvent(State::ForceWeighingEnabled, reinterpret_cast<LPVOID>(false));
}
//---------------------------------------------------------------------------

