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
	SFM.AddLog("�`�[�m�F��� �ԗ�ID/�Ԕ�: " + ToString(SFM.Stashed("�ԗ�ID")) + "/" + ToString(SFM.car_rec["�Ԕ�"]));

	SFM.SendStatus(AnsiString());

	try{
		// [CFG] Keiryo::CompleteFile
		NoticeRichEdit->Lines->LoadFromFile(ToString(DM->INI["Keiryo::CompleteFile"]));
	}catch(...){
		NoticeRichEdit->Lines->Clear();
	}

	if (ToBit(SFM.Stashed("�d�ʌv�ʕ["))){
        /*
		Title1Label->Caption = "�v�ʂ��������܂���";
		Title2Label->Caption = "�`�[���m�F���Ă�������";

		ReprintButton->Visible = true;

		PlaySound(ToString(DM->Sounds["Print"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

		PrintWeightChit();
        */
	}else{
		// [CFG] Chit::Print
		if (ToBit(DM->INI["Chit::Print"])){
			Title1Label->Caption = "�v�ʂ��������܂���";
			Title2Label->Caption = "�`�[���m�F���Ă�������";

			ReprintButton->Visible = true;

			PlaySound(ToString(DM->Sounds["Print"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

			Print();
		}else{
			Title1Label->Caption = "�v�ʂ��������܂���";
			Title2Label->Caption = "�ԗ����͂��肩��~�낵�ĉ�����";

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
	if (ToBit(SFM.Stashed("�d�ʌv�ʕ["))){
		;//PrintWeightChit();
	}else{
        ReprintButton->Enabled = false;
		Print();
    }
}
//---------------------------------------------------------------------------
void __fastcall TPrintStateForm::Print()
{
	AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID = " + ToString(SFM.Stashed("�v��ID"));
	NsRecordSet set;

	try{
		QRChitForm->Print(ToInt(SFM.Stashed("�v��ID")));
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

