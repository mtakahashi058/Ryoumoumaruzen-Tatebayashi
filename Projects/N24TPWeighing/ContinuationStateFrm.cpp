//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ContinuationStateFrm.h"
#include "DMFrm.h"
#include <mmsystem.h>
#include "n24tp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TContinuationStateForm *ContinuationStateForm;
//---------------------------------------------------------------------------
__fastcall TContinuationStateForm::TContinuationStateForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TContinuationStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::ConfirmContinuation, this);
}
//---------------------------------------------------------------------------
void __fastcall TContinuationStateForm::OnEnter()
{
	SFM.AddLog("継続画面 車両ID/車番: " + ToString(SFM.Stashed("車両ID")) + "/" + ToString(SFM.car_rec["車番"]));

	SFM.SendStatus(AnsiString());

	try{
		// [CFG] Keiryo::MessageFile
		NoticeRichEdit->Lines->LoadFromFile(ToString(DM->INI["Keiryo::MessageFile"]));
	}catch(...){
		NoticeRichEdit->Lines->Clear();
	}

	PlaySound(ToString(DM->Sounds["Continue"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

	SFM.SendEvent(State::ForceWeighingEnabled, reinterpret_cast<LPVOID>(true));
}
//---------------------------------------------------------------------------
void __fastcall TContinuationStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TContinuationStateForm::OnExit()
{
	SFM.SendEvent(State::ForceWeighingEnabled, reinterpret_cast<LPVOID>(false));
}
//---------------------------------------------------------------------------
void __fastcall TContinuationStateForm::CancelButtonClick(TObject *Sender)
{
	NsFieldSet fields, keys;

    int keiryo_id  = ToInt(SFM.Stashed("新計量ID"));
    int new_lineno = ToInt(SFM.Stashed("新行No"));

    try{
		DM->ADOConnection->BeginTrans();

        if (new_lineno == 1){
            keys << NsField("計量ID", keiryo_id);
            fields << NsField("[2回目重量]", 0)
                   << NsField("[計量日時2]", Variant())
                   << NsField("[正味重量]",  0)
                   << NsField("[完了区分]",  0)
                   ;

    		DM->DBI.Update("D_計量", keys, fields);
        }else{
            fields << NsField("[完了区分]", 9)
                   << NsField("[行No]", 0);
            keys   << NsField("計量ID", keiryo_id);
            DM->DBI.Update("D_計量", keys , fields);
         }

		DM->ADOConnection->CommitTrans();
    }catch(Exception& e){
		DM->ADOConnection->RollbackTrans();
		AnsiString message = "DBエラー: " + e.Message;
		SFM.SendStatus(message);
        return;
    }

	SFM.Transit(State::ConfirmWeighing);
}
//---------------------------------------------------------------------------

