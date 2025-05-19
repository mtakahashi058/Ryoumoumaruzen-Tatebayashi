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
	// カードマスタの確認

	int card_no = reinterpret_cast<int>(param);

    SFM.AddLog("カード読取: " + IntToStr(card_no));

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_車両 WHERE カード番号 = " + IntToStr(card_no) + " AND 使用区分 = 1";
	if (!DM->DBI.GetRecordSet(sql,set)){
		CardPanel->Caption = "無効なカードです";
		CardPanel->Visible = true;
		return;
	}
    int car_id = ToInt(SET_TOP(set)["車両ID"]);
    int car_no = ToInt(SET_TOP(set)["車番"]);

	Currency tmp_weight = SFM.Stashed("Weight");
    //***** stash クリア
	SFM.stash.clear();
	SFM.stash["Weight"] = tmp_weight;

	SFM.stash["重量計量票"] = false;

    SFM.car_rec = SET_TOP(set);

	// 変動項目チェック
    SFM.stash["得意先選択"]   = ToString(SET_TOP(set)["得意先略称"]).IsEmpty();
    SFM.stash["品目選択"]     = ToString(SET_TOP(set)["品目略称"]).IsEmpty();
	SFM.stash["項目1選択"]    = ToString(SET_TOP(set)["項目1略称"]).IsEmpty();
	SFM.stash["項目2選択"]    = ToString(SET_TOP(set)["項目2略称"]).IsEmpty();
	SFM.stash["車番入力"]     = !car_no;
    SFM.stash["車両ID"]       = car_id;
    SFM.stash["車番"]         = car_no;
    SFM.stash["新車両"]       = car_no ? false : true;
    SFM.stash["カード車両ID"] = car_id;
    SFM.stash["得意先ID"]     = ToInt(SET_TOP(set)["得意先ID"]);
    SFM.stash["得意先略称"]   = ToString(SET_TOP(set)["得意先略称"]);
    SFM.stash["品目ID"]       = ToInt(SET_TOP(set)["品目ID"]);
    SFM.stash["品目略称"]     = ToString(SET_TOP(set)["品目略称"]);
    SFM.stash["項目1ID"]      = ToInt(SET_TOP(set)["項目1ID"]);
    SFM.stash["項目1略称"]    = ToString(SET_TOP(set)["項目1略称"]);
    SFM.stash["項目2ID"]      = ToInt(SET_TOP(set)["項目2ID"]);
    SFM.stash["項目2略称"]    = ToString(SET_TOP(set)["項目2略称"]);
	SFM.stash["1回計量"]      = ToInt(SET_TOP(set)["空車重量"]) > 0;

    if (!ToBit(DM->CFG["得意先マスタ使用区分"]))
        SFM.stash["得意先選択"]   = false;
    if (!ToBit(DM->CFG["品目マスタ使用区分"]))
        SFM.stash["品目選択"]     = false;
    if (!ToBit(DM->CFG["項目1マスタ使用区分"]))
    	SFM.stash["項目1選択"]    = false;
    if (!ToBit(DM->CFG["項目2マスタ使用区分"]))
    	SFM.stash["項目2選択"]    = false;

	SF.clear();
	SF.push_back(State::WaitCard);

	///////////////////////////////////////////////
	// 滞留データの確認
	NsRecordSet remained_set;
	if (!DM->GetRemainedSet(car_id, remained_set)){
		// 初回計量
		SFM.stash["初回計量"] = true;

		//SFM.CheckStash();

		if (ToBit(SFM.Stashed("車番入力")))
			SF.push_back(State::InputCarNo);
        if (ToBit(SFM.Stashed("得意先選択")))
            SF.push_back(State::SelectToku);
		if (ToBit(SFM.Stashed("項目1選択")))
			SF.push_back(State::SelectItem1);
		if (ToBit(SFM.Stashed("項目2選択")))
			SF.push_back(State::SelectItem2);
		if (ToBit(SFM.Stashed("1回計量"))){
			if (ToBit(SFM.Stashed("品目選択")))
				SF.push_back(State::SelectMeig);
			SF.push_back(State::ConfirmWeighing);
		}else{

			SF.push_back(State::ConfirmFirstWeight);
		}

		SFM.Transit(NextState(State::WaitCard));
	}else{
        SFM.stash["車両ID"]       = SET_TOP(remained_set)["車両ID"];

		// 2回目以降
		SFM.stash["初回計量"] = false;

		SFM.stash["計量ID"]       = SET_TOP(remained_set)["計量ID"];
		SFM.stash["計量日"]       = SET_TOP(remained_set)["計量日"];
		SFM.stash["伝票No"]       = SET_TOP(remained_set)["伝票No"];

		SFM.stash["カード番号"]   = SET_TOP(remained_set)["カード番号"];
		SFM.stash["車番"]         = SET_TOP(remained_set)["車番"];

        SFM.stash["得意先コード"] = SET_TOP(remained_set)["得意先コード"];
        SFM.stash["得意先略称"]   = SET_TOP(remained_set)["得意先略称"];

        SFM.stash["品目コード"]   = SET_TOP(remained_set)["品目コード"];
        SFM.stash["品目略称"]     = SET_TOP(remained_set)["品目略称"];

		SFM.stash["項目1コード"]  = SET_TOP(remained_set)["項目1コード"];
		SFM.stash["項目1略称"]    = SET_TOP(remained_set)["項目1略称"];

		SFM.stash["項目2コード"]  = SET_TOP(remained_set)["項目2コード"];
		SFM.stash["項目2略称"]    = SET_TOP(remained_set)["項目2略称"];

        SFM.remained_rec = SET_TOP(remained_set);

		///////////////////////////////////////////////
		// 前回の重量を取得

        if (ToInt(SFM.remained_rec["正味重量"]) > 0)
			SFM.stash["品目選択"] = true;

        //if (!ToBit(SFM.Stashed("1回計量")))
        //    SFM.stash["品目選択"]   = true;

		if (ToBit(SFM.Stashed("品目選択")))
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

	SFM.stash["重量計量票"] = true;
	SFM.Transit(NextState(State::WaitCard));
}
//---------------------------------------------------------------------------

