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
	// �J�[�h�}�X�^�̊m�F

	int card_no = reinterpret_cast<int>(param);

    SFM.AddLog("�J�[�h�ǎ�: " + IntToStr(card_no));

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�ԗ� WHERE �J�[�h�ԍ� = " + IntToStr(card_no) + " AND �g�p�敪 = 1";
	if (!DM->DBI.GetRecordSet(sql,set)){
		CardPanel->Caption = "�����ȃJ�[�h�ł�";
		CardPanel->Visible = true;
		return;
	}
    int car_id = ToInt(SET_TOP(set)["�ԗ�ID"]);
    int car_no = ToInt(SET_TOP(set)["�Ԕ�"]);

	Currency tmp_weight = SFM.Stashed("Weight");
    //***** stash �N���A
	SFM.stash.clear();
	SFM.stash["Weight"] = tmp_weight;

	SFM.stash["�d�ʌv�ʕ["] = false;

    SFM.car_rec = SET_TOP(set);

	// �ϓ����ڃ`�F�b�N
    SFM.stash["���Ӑ�I��"]   = ToString(SET_TOP(set)["���Ӑ旪��"]).IsEmpty();
    SFM.stash["�i�ڑI��"]     = ToString(SET_TOP(set)["�i�ڗ���"]).IsEmpty();
	SFM.stash["����1�I��"]    = ToString(SET_TOP(set)["����1����"]).IsEmpty();
	SFM.stash["����2�I��"]    = ToString(SET_TOP(set)["����2����"]).IsEmpty();
	SFM.stash["�Ԕԓ���"]     = !car_no;
    SFM.stash["�ԗ�ID"]       = car_id;
    SFM.stash["�Ԕ�"]         = car_no;
    SFM.stash["�V�ԗ�"]       = car_no ? false : true;
    SFM.stash["�J�[�h�ԗ�ID"] = car_id;
    SFM.stash["���Ӑ�ID"]     = ToInt(SET_TOP(set)["���Ӑ�ID"]);
    SFM.stash["���Ӑ旪��"]   = ToString(SET_TOP(set)["���Ӑ旪��"]);
    SFM.stash["�i��ID"]       = ToInt(SET_TOP(set)["�i��ID"]);
    SFM.stash["�i�ڗ���"]     = ToString(SET_TOP(set)["�i�ڗ���"]);
    SFM.stash["����1ID"]      = ToInt(SET_TOP(set)["����1ID"]);
    SFM.stash["����1����"]    = ToString(SET_TOP(set)["����1����"]);
    SFM.stash["����2ID"]      = ToInt(SET_TOP(set)["����2ID"]);
    SFM.stash["����2����"]    = ToString(SET_TOP(set)["����2����"]);
	SFM.stash["1��v��"]      = ToInt(SET_TOP(set)["��ԏd��"]) > 0;

    if (!ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"]))
        SFM.stash["���Ӑ�I��"]   = false;
    if (!ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"]))
        SFM.stash["�i�ڑI��"]     = false;
    if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"]))
    	SFM.stash["����1�I��"]    = false;
    if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"]))
    	SFM.stash["����2�I��"]    = false;

	SF.clear();
	SF.push_back(State::WaitCard);

	///////////////////////////////////////////////
	// �ؗ��f�[�^�̊m�F
	NsRecordSet remained_set;
	if (!DM->GetRemainedSet(car_id, remained_set)){
		// ����v��
		SFM.stash["����v��"] = true;

		//SFM.CheckStash();

		if (ToBit(SFM.Stashed("�Ԕԓ���")))
			SF.push_back(State::InputCarNo);
        if (ToBit(SFM.Stashed("���Ӑ�I��")))
            SF.push_back(State::SelectToku);
		if (ToBit(SFM.Stashed("����1�I��")))
			SF.push_back(State::SelectItem1);
		if (ToBit(SFM.Stashed("����2�I��")))
			SF.push_back(State::SelectItem2);
		if (ToBit(SFM.Stashed("1��v��"))){
			if (ToBit(SFM.Stashed("�i�ڑI��")))
				SF.push_back(State::SelectMeig);
			SF.push_back(State::ConfirmWeighing);
		}else{

			SF.push_back(State::ConfirmFirstWeight);
		}

		SFM.Transit(NextState(State::WaitCard));
	}else{
        SFM.stash["�ԗ�ID"]       = SET_TOP(remained_set)["�ԗ�ID"];

		// 2��ڈȍ~
		SFM.stash["����v��"] = false;

		SFM.stash["�v��ID"]       = SET_TOP(remained_set)["�v��ID"];
		SFM.stash["�v�ʓ�"]       = SET_TOP(remained_set)["�v�ʓ�"];
		SFM.stash["�`�[No"]       = SET_TOP(remained_set)["�`�[No"];

		SFM.stash["�J�[�h�ԍ�"]   = SET_TOP(remained_set)["�J�[�h�ԍ�"];
		SFM.stash["�Ԕ�"]         = SET_TOP(remained_set)["�Ԕ�"];

        SFM.stash["���Ӑ�R�[�h"] = SET_TOP(remained_set)["���Ӑ�R�[�h"];
        SFM.stash["���Ӑ旪��"]   = SET_TOP(remained_set)["���Ӑ旪��"];

        SFM.stash["�i�ڃR�[�h"]   = SET_TOP(remained_set)["�i�ڃR�[�h"];
        SFM.stash["�i�ڗ���"]     = SET_TOP(remained_set)["�i�ڗ���"];

		SFM.stash["����1�R�[�h"]  = SET_TOP(remained_set)["����1�R�[�h"];
		SFM.stash["����1����"]    = SET_TOP(remained_set)["����1����"];

		SFM.stash["����2�R�[�h"]  = SET_TOP(remained_set)["����2�R�[�h"];
		SFM.stash["����2����"]    = SET_TOP(remained_set)["����2����"];

        SFM.remained_rec = SET_TOP(remained_set);

		///////////////////////////////////////////////
		// �O��̏d�ʂ��擾

        if (ToInt(SFM.remained_rec["�����d��"]) > 0)
			SFM.stash["�i�ڑI��"] = true;

        //if (!ToBit(SFM.Stashed("1��v��")))
        //    SFM.stash["�i�ڑI��"]   = true;

		if (ToBit(SFM.Stashed("�i�ڑI��")))
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

	SFM.stash["�d�ʌv�ʕ["] = true;
	SFM.Transit(NextState(State::WaitCard));
}
//---------------------------------------------------------------------------

