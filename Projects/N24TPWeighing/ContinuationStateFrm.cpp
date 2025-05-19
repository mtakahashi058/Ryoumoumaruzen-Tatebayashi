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
	SFM.AddLog("�p����� �ԗ�ID/�Ԕ�: " + ToString(SFM.Stashed("�ԗ�ID")) + "/" + ToString(SFM.car_rec["�Ԕ�"]));

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

    int keiryo_id  = ToInt(SFM.Stashed("�V�v��ID"));
    int new_lineno = ToInt(SFM.Stashed("�V�sNo"));

    try{
		DM->ADOConnection->BeginTrans();

        if (new_lineno == 1){
            keys << NsField("�v��ID", keiryo_id);
            fields << NsField("[2��ڏd��]", 0)
                   << NsField("[�v�ʓ���2]", Variant())
                   << NsField("[�����d��]",  0)
                   << NsField("[�����敪]",  0)
                   ;

    		DM->DBI.Update("D_�v��", keys, fields);
        }else{
            fields << NsField("[�����敪]", 9)
                   << NsField("[�sNo]", 0);
            keys   << NsField("�v��ID", keiryo_id);
            DM->DBI.Update("D_�v��", keys , fields);
         }

		DM->ADOConnection->CommitTrans();
    }catch(Exception& e){
		DM->ADOConnection->RollbackTrans();
		AnsiString message = "DB�G���[: " + e.Message;
		SFM.SendStatus(message);
        return;
    }

	SFM.Transit(State::ConfirmWeighing);
}
//---------------------------------------------------------------------------

