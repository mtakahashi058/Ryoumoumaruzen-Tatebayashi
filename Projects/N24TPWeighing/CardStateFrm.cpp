//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CardStateFrm.h"
#include "DMFrm.h"
#include <mmsystem.h>
#include "n24tp.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCardStateForm *CardStateForm;
//---------------------------------------------------------------------------
__fastcall TCardStateForm::TCardStateForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCardStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::WaitCard, this);
}
//---------------------------------------------------------------------------
void __fastcall TCardStateForm::OnEnter()
{
	SFM.SendStatus(AnsiString());

	CardPanel->Visible = false;

	PrintButton->Visible = ToBit(DM->INI["Keiryo::UseWeightChit"]);
	PrintButton->Enabled = ToBit(DM->INI["Keiryo::UseWeightChit"]);

	PlaySound(ToString(DM->Sounds["Card"]).c_str(), 0, SND_LOOP | SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TCardStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}

	if (event != Event::Card)
		return;

	///////////////////////////////////////////////
	// J[h}X^ÌmF

	int card_no = reinterpret_cast<int>(param);

    SFM.AddLog("J[hÇæ: " + IntToStr(card_no));

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_Ô¼ WHERE J[hÔ = " + IntToStr(card_no) + " AND gpæª = 1";
	if (!DM->DBI.GetRecordSet(sql,set)){
		CardPanel->Caption = "³øÈJ[hÅ·";
		CardPanel->Visible = true;
		return;
	}
    int car_id = ToInt(SET_TOP(set)["Ô¼ID"]);
    int car_no = ToInt(SET_TOP(set)["ÔÔ"]);

	Currency tmp_weight = SFM.Stashed("Weight");
    //***** stash NA
	SFM.stash.clear();
	SFM.stash["Weight"] = tmp_weight;

	SFM.stash["dÊvÊ["] = false;

    SFM.car_rec = SET_TOP(set);

	// Ï®Ú`FbN
    SFM.stash["¾ÓæIð"]   = ToString(SET_TOP(set)["¾ÓæªÌ"]).IsEmpty();
    SFM.stash["iÚIð"]     = ToString(SET_TOP(set)["iÚªÌ"]).IsEmpty();
	SFM.stash["Ú1Ið"]    = ToString(SET_TOP(set)["Ú1ªÌ"]).IsEmpty();
	SFM.stash["Ú2Ið"]    = ToString(SET_TOP(set)["Ú2ªÌ"]).IsEmpty();
	SFM.stash["ÔÔüÍ"]     = !car_no;
    SFM.stash["Ô¼ID"]       = car_id;
    SFM.stash["ÔÔ"]         = car_no;
    SFM.stash["VÔ¼"]       = car_no ? false : true;
    SFM.stash["J[hÔ¼ID"] = car_id;
    SFM.stash["¾ÓæID"]     = ToInt(SET_TOP(set)["¾ÓæID"]);
    SFM.stash["¾ÓæªÌ"]   = ToString(SET_TOP(set)["¾ÓæªÌ"]);
    SFM.stash["iÚID"]       = ToInt(SET_TOP(set)["iÚID"]);
    SFM.stash["iÚªÌ"]     = ToString(SET_TOP(set)["iÚªÌ"]);
    SFM.stash["Ú1ID"]      = ToInt(SET_TOP(set)["Ú1ID"]);
    SFM.stash["Ú1ªÌ"]    = ToString(SET_TOP(set)["Ú1ªÌ"]);
    SFM.stash["Ú2ID"]      = ToInt(SET_TOP(set)["Ú2ID"]);
    SFM.stash["Ú2ªÌ"]    = ToString(SET_TOP(set)["Ú2ªÌ"]);
	SFM.stash["1ñvÊ"]      = ToInt(SET_TOP(set)["óÔdÊ"]) > 0;

    if (!ToBit(DM->CFG["¾Óæ}X^gpæª"]))
        SFM.stash["¾ÓæIð"]   = false;
    if (!ToBit(DM->CFG["iÚ}X^gpæª"]))
        SFM.stash["iÚIð"]     = false;
    if (!ToBit(DM->CFG["Ú1}X^gpæª"]))
    	SFM.stash["Ú1Ið"]    = false;
    if (!ToBit(DM->CFG["Ú2}X^gpæª"]))
    	SFM.stash["Ú2Ið"]    = false;

	SF.clear();
	SF.push_back(State::WaitCard);

	///////////////////////////////////////////////
	// Ø¯f[^ÌmF
	NsRecordSet remained_set;
	if (!DM->GetRemainedSet(car_id, remained_set)){
		// ñvÊ
		SFM.stash["ñvÊ"] = true;

		//SFM.CheckStash();

		if (ToBit(SFM.Stashed("ÔÔüÍ")))
			SF.push_back(State::InputCarNo);
        if (ToBit(SFM.Stashed("¾ÓæIð")))
            SF.push_back(State::SelectToku);
		if (ToBit(SFM.Stashed("Ú1Ið")))
			SF.push_back(State::SelectItem1);
		if (ToBit(SFM.Stashed("Ú2Ið")))
			SF.push_back(State::SelectItem2);
		if (ToBit(SFM.Stashed("1ñvÊ"))){
			if (ToBit(SFM.Stashed("iÚIð")))
				SF.push_back(State::SelectMeig);
			SF.push_back(State::ConfirmWeighing);
		}else{

			SF.push_back(State::ConfirmFirstWeight);
		}

		SFM.Transit(NextState(State::WaitCard));
	}else{
        SFM.stash["Ô¼ID"]       = SET_TOP(remained_set)["Ô¼ID"];

		// 2ñÚÈ~
		SFM.stash["ñvÊ"] = false;

		SFM.stash["vÊID"]       = SET_TOP(remained_set)["vÊID"];
		SFM.stash["vÊú"]       = SET_TOP(remained_set)["vÊú"];
		SFM.stash["`[No"]       = SET_TOP(remained_set)["`[No"];

		SFM.stash["J[hÔ"]   = SET_TOP(remained_set)["J[hÔ"];
		SFM.stash["ÔÔ"]         = SET_TOP(remained_set)["ÔÔ"];

        SFM.stash["¾ÓæR[h"] = SET_TOP(remained_set)["¾ÓæR[h"];
        SFM.stash["¾ÓæªÌ"]   = SET_TOP(remained_set)["¾ÓæªÌ"];

        SFM.stash["iÚR[h"]   = SET_TOP(remained_set)["iÚR[h"];
        SFM.stash["iÚªÌ"]     = SET_TOP(remained_set)["iÚªÌ"];

		SFM.stash["Ú1R[h"]  = SET_TOP(remained_set)["Ú1R[h"];
		SFM.stash["Ú1ªÌ"]    = SET_TOP(remained_set)["Ú1ªÌ"];

		SFM.stash["Ú2R[h"]  = SET_TOP(remained_set)["Ú2R[h"];
		SFM.stash["Ú2ªÌ"]    = SET_TOP(remained_set)["Ú2ªÌ"];

        SFM.remained_rec = SET_TOP(remained_set);

		///////////////////////////////////////////////
		// OñÌdÊðæ¾

        if (ToInt(SFM.remained_rec["³¡dÊ"]) > 0)
			SFM.stash["iÚIð"] = true;

        //if (!ToBit(SFM.Stashed("1ñvÊ")))
        //    SFM.stash["iÚIð"]   = true;

		if (ToBit(SFM.Stashed("iÚIð")))
			SF.push_back(State::SelectMeig);
		SF.push_back(State::ConfirmWeighing);

		SFM.Transit(NextState(State::WaitCard));
	}
}
//---------------------------------------------------------------------------
void __fastcall TCardStateForm::OnExit()
{
	PlaySound(0, 0, SND_LOOP | SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TCardStateForm::PrintButtonClick(TObject *Sender)
{
	SF.clear();
	SF.push_back(State::WaitCard);
	SF.push_back(State::InputCarNo);
	SF.push_back(State::ConfirmPrint);

	Currency tmp_weight = SFM.Stashed("Weight");
	SFM.stash.clear();
	SFM.stash["Weight"] = tmp_weight;

	SFM.stash["dÊvÊ["] = true;
	SFM.Transit(NextState(State::WaitCard));
}
//---------------------------------------------------------------------------

