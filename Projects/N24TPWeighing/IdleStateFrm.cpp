//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "n24tp.h"
#include "DMFrm.h"
#include "IdleStateFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIdleStateForm *IdleStateForm;
//---------------------------------------------------------------------------
__fastcall TIdleStateForm::TIdleStateForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TIdleStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::Idle, this);
}
//---------------------------------------------------------------------------
void __fastcall TIdleStateForm::OnEnter()
{
    SFM.AddLog("待機画面");

    SFM.PatliteAlert(false, false);

    if (!N24TP::SetPlace(ToInt(DM->INI["N-24TP::PlaceCode"]))){
        Application->MessageBox("拠点コードが有効ではありません", "N-24TP 初期化処理", MB_OK | MB_ICONSTOP);
        PostMessage(KeiryoStateBaseForm->Handle, WM_CLOSE, 0, 0);
    }

	SFM.stash.clear();

	SFM.SendStatus(AnsiString());
}
//---------------------------------------------------------------------------
void __fastcall TIdleStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::EnterWeighing)
		SFM.Transit(State::WaitCard);
}
//---------------------------------------------------------------------------
void __fastcall TIdleStateForm::OnExit()
{
//
}
//---------------------------------------------------------------------------

