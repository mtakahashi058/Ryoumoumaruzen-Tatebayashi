//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CarNoInputStateFrm.h"
#include "DMFrm.h"
#include <mmsystem.h>
#include "n24tp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCarNoInputForm *CarNoInputForm;
//---------------------------------------------------------------------------
__fastcall TCarNoInputForm::TCarNoInputForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCarNoInputForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::InputCarNo, this);
}
//---------------------------------------------------------------------------
void __fastcall TCarNoInputForm::OnEnter()
{
	SFM.AddLog("ŽÔ”Ô“ü—Í‰æ–Ê ŽÔ—¼ID/ŽÔ”Ô: " + ToString(SFM.Stashed("ŽÔ—¼ID")) + "/" + ToString(SFM.car_rec["ŽÔ”Ô"]));

	CarNoPanel->Caption = AnsiString();

	SFM.SendStatus(AnsiString());

	PlaySound(ToString(DM->Sounds["CarNoInput"]).c_str(), 0, SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TCarNoInputForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TCarNoInputForm::OnExit()
{
}
//---------------------------------------------------------------------------
void __fastcall TCarNoInputForm::Input0ButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;
	if (tag == 10){
		// ’ù³
		if (!CarNoPanel->Caption.IsEmpty()){
			AnsiString buff = CarNoPanel->Caption;
			buff.Delete(CarNoPanel->Caption.Length(), 1);
			CarNoPanel->Caption = buff;
		}
	}else if (tag == 11){
		CarNoPanel->Caption = AnsiString();
	}else{
		if (CarNoPanel->Caption.Length() != 4){
			AnsiString buff = CarNoPanel->Caption;
			buff += IntToStr(tag);
			CarNoPanel->Caption = buff;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TCarNoInputForm::CarNoSetButtonClick(TObject *Sender)
{
	if (CarNoPanel->Caption.IsEmpty())
		return;

	SFM.stash["ŽÔ”Ô"]   = CarNoPanel->Caption.ToInt();

	SFM.Transit(NextState(SFM.GetCurrentStateID()));
}
//---------------------------------------------------------------------------
void __fastcall TCarNoInputForm::CancelButtonClick(TObject *Sender)
{
	SFM.Transit(PrevState(SFM.GetCurrentStateID()));
}
//---------------------------------------------------------------------------

