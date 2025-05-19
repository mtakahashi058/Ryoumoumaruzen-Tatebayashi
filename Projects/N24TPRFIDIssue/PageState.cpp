/** PageState.cpp
 *
 */

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include <mmsystem.h>
#include "PageState.h"

#include "CardIssueFrm.h"
#include "DMFrm.h"

#define Form	(CardIssueForm)

StartUpState stateStartup;
SelectTokuState stateSelectToku;
SelectMeigState stateSelectMeig;
SelectItem1State stateSelectItem1;
SelectItem2State stateSelectItem2;
InputCarNoState stateInputCarNo;
ConfirmState stateConfirm;
IssueState stateIssue;
AdminIssueState stateAdminIssue;

int        PageState::toku_id_;
AnsiString PageState::toku_name_;
int        PageState::meig_id_;
AnsiString PageState::meig_name_;
int        PageState::item1_id_;
AnsiString PageState::item1_name_;
int        PageState::item2_id_;
AnsiString PageState::item2_name_;
int        PageState::car_no_;
int        PageState::car_id_;
bool       PageState::add_car_;

/** SelectTokuState Implementation
  */
void SelectTokuState::onEnter(void *v){
	// 初期化
	this->toku_id_  = 0;
	this->toku_name_  = AnsiString();
	this->meig_id_  = 0;
	this->meig_name_  = AnsiString();
	this->item1_id_ = 0;
	this->item1_name_ = AnsiString();
	this->item2_id_ = 0;
	this->item2_name_ = AnsiString();
	this->car_no_     = 0;
    this->car_id_     = 0;

	Form->PageControl->ActivePage = Form->TokuSheet;

	Form->BackButton->Enabled = false;

	Form->AdminCardIssueButton->Enabled = true;

	kana_buttons_[0]->Caption = "ｱ";
	kana_buttons_[1]->Caption = "ｶ";
	kana_buttons_[2]->Caption = "ｻ";
	kana_buttons_[3]->Caption = "ﾀ";
	kana_buttons_[4]->Caption = "ﾅ";
	kana_buttons_[5]->Caption = "ﾊ";
	kana_buttons_[6]->Caption = "ﾏ";
	kana_buttons_[7]->Caption = "ﾔ";
	kana_buttons_[8]->Caption = "ﾗ";
	kana_buttons_[9]->Caption = "ﾜ";
	kana_buttons_[0]->Visible = true;
	kana_buttons_[1]->Visible = true;
	kana_buttons_[2]->Visible = true;
	kana_buttons_[3]->Visible = true;
	kana_buttons_[4]->Visible = true;
	kana_buttons_[5]->Visible = true;
	kana_buttons_[6]->Visible = true;
	kana_buttons_[7]->Visible = true;
	kana_buttons_[8]->Visible = true;
	kana_buttons_[9]->Visible = true;
	Form->TokuKanaBackButton->Visible = false;

	SetKana(AnsiString(), AnsiString());

	SetupButtons(0);
}

void SelectTokuState::onExit(void *v){
	Form->BackButton->Enabled = true;

	Form->AdminCardIssueButton->Enabled = false;
}

int SelectTokuState::onEvent(int event, void *arg){
	if (event == evTokuSelect){
		NsRecord record(*reinterpret_cast<NsRecord *>(arg));
		this->toku_id_   = ToInt(record["得意先ID"]);
		this->toku_name_ = ToString(record["得意先名称"]);
	}
	return event;
}

void SelectTokuState::Initialize(){
	kana_buttons_[0] = Form->TokuKana1Button;
	kana_buttons_[1] = Form->TokuKana2Button;
	kana_buttons_[2] = Form->TokuKana3Button;
	kana_buttons_[3] = Form->TokuKana4Button;
	kana_buttons_[4] = Form->TokuKana5Button;
	kana_buttons_[5] = Form->TokuKana6Button;
	kana_buttons_[6] = Form->TokuKana7Button;
	kana_buttons_[7] = Form->TokuKana8Button;
	kana_buttons_[8] = Form->TokuKana9Button;
	kana_buttons_[9] = Form->TokuKana10Button;

	buttons_[0] = Form->Toku1Button;
	buttons_[1] = Form->Toku2Button;
	buttons_[2] = Form->Toku3Button;
	buttons_[3] = Form->Toku4Button;
	buttons_[4] = Form->Toku5Button;
	buttons_[5] = Form->Toku6Button;
	buttons_[6] = Form->Toku7Button;
	buttons_[7] = Form->Toku8Button;
	buttons_[8] = Form->Toku9Button;
	buttons_[9] = Form->Toku10Button;
	buttons_[10] = Form->Toku11Button;
	buttons_[11] = Form->Toku12Button;
	buttons_[12] = Form->Toku13Button;
	buttons_[13] = Form->Toku14Button;
	buttons_[14] = Form->Toku15Button;
}

void SelectTokuState::SetupButtons(int start_no){
	current_top_ = start_no;

	NsRecordSet set;
	DM->GetTokuRecords(kana1_, kana2_, set);

	int record_count = int(set.size());

	enable_cnt_ = 0;
	int len;
	for (int i = 0; i < 15; i++){
		if (i + start_no >= record_count){
			buttons_[i]->Caption = "";
			buttons_[i]->Hint = "";
			buttons_[i]->Tag = 0;
			buttons_[i]->Enabled = false;
		}else{
			buttons_[i]->Caption = ToString(set[i + start_no]["得意先略称"]);
			buttons_[i]->Tag = ToInt(set[i + start_no]["得意先ID"]);
			buttons_[i]->Enabled = true;

			len = buttons_[i]->Caption.Length();
			if (len <= 20)
				buttons_[i]->Font->Size = 16;
			else if (len <= 22)
				buttons_[i]->Font->Size = 14;
			else if (len <= 26)
				buttons_[i]->Font->Size = 12;
			else
				buttons_[i]->Font->Size = 10;

			enable_cnt_++;
		}
	}
}

/** SelectMeigState Implementation
  */
void SelectMeigState::onEnter(void *v){
	Form->PageControl->ActivePage = Form->MeigSheet;

	kana_buttons_[0]->Caption = "ｱ";
	kana_buttons_[1]->Caption = "ｶ";
	kana_buttons_[2]->Caption = "ｻ";
	kana_buttons_[3]->Caption = "ﾀ";
	kana_buttons_[4]->Caption = "ﾅ";
	kana_buttons_[5]->Caption = "ﾊ";
	kana_buttons_[6]->Caption = "ﾏ";
	kana_buttons_[7]->Caption = "ﾔ";
	kana_buttons_[8]->Caption = "ﾗ";
	kana_buttons_[9]->Caption = "ﾜ";
	kana_buttons_[0]->Visible = true;
	kana_buttons_[1]->Visible = true;
	kana_buttons_[2]->Visible = true;
	kana_buttons_[3]->Visible = true;
	kana_buttons_[4]->Visible = true;
	kana_buttons_[5]->Visible = true;
	kana_buttons_[6]->Visible = true;
	kana_buttons_[7]->Visible = true;
	kana_buttons_[8]->Visible = true;
	kana_buttons_[9]->Visible = true;
	Form->Item2KanaBackButton->Visible = false;

	SetKana(AnsiString(), AnsiString());

	SetupButtons(0);
}

void SelectMeigState::onExit(void *v){
	Form->BackButton->Enabled = true;

	Form->AdminCardIssueButton->Enabled = false;
}

int SelectMeigState::onEvent(int event, void *arg){
	if (event == evMeigSelect){
		NsRecord record(*reinterpret_cast<NsRecord *>(arg));
		this->meig_id_   = ToInt(record["品目ID"]);
		this->meig_name_ = ToString(record["品目名称"]);
	}
	return event;
}

void SelectMeigState::Initialize(){
	kana_buttons_[0] = Form->MeigKana1Button;
	kana_buttons_[1] = Form->MeigKana2Button;
	kana_buttons_[2] = Form->MeigKana3Button;
	kana_buttons_[3] = Form->MeigKana4Button;
	kana_buttons_[4] = Form->MeigKana5Button;
	kana_buttons_[5] = Form->MeigKana6Button;
	kana_buttons_[6] = Form->MeigKana7Button;
	kana_buttons_[7] = Form->MeigKana8Button;
	kana_buttons_[8] = Form->MeigKana9Button;
	kana_buttons_[9] = Form->MeigKana10Button;

	buttons_[0]  = Form->Meig1Button;
	buttons_[1]  = Form->Meig2Button;
	buttons_[2]  = Form->Meig3Button;
	buttons_[3]  = Form->Meig4Button;
	buttons_[4]  = Form->Meig5Button;
	buttons_[5]  = Form->Meig6Button;
	buttons_[6]  = Form->Meig7Button;
	buttons_[7]  = Form->Meig8Button;
	buttons_[8]  = Form->Meig9Button;
	buttons_[9]  = Form->Meig10Button;
	buttons_[10] = Form->Meig11Button;
	buttons_[11] = Form->Meig12Button;
	buttons_[12] = Form->Meig13Button;
	buttons_[13] = Form->Meig14Button;
	buttons_[14] = Form->Meig15Button;
}

void SelectMeigState::SetupButtons(int start_no){
	current_top_ = start_no;

	NsRecordSet set;
	DM->GetMeigRecords(kana1_, kana2_, set);

	int record_count = int(set.size());

	enable_cnt_ = 0;
	int len;
	for (int i = 0; i < 15; i++){
		if (i + start_no >= record_count){
			buttons_[i]->Caption = "";
			buttons_[i]->Hint = "";
			buttons_[i]->Tag = 0;
			buttons_[i]->Enabled = false;
		}else{
			buttons_[i]->Caption = ToString(set[i + start_no]["品目略称"]);
			buttons_[i]->Tag = ToInt(set[i + start_no]["品目ID"]);
			buttons_[i]->Enabled = true;

			len = buttons_[i]->Caption.Length();
			if (len <= 20)
				buttons_[i]->Font->Size = 16;
			else if (len <= 22)
				buttons_[i]->Font->Size = 14;
			else if (len <= 26)
				buttons_[i]->Font->Size = 12;
			else
				buttons_[i]->Font->Size = 10;

			enable_cnt_++;
		}
	}
}

/** SelectItem1State Implementation
  */
void SelectItem1State::onEnter(void *v){
	Form->PageControl->ActivePage = Form->Item1Sheet;

	kana_buttons_[0]->Caption = "ｱ";
	kana_buttons_[1]->Caption = "ｶ";
	kana_buttons_[2]->Caption = "ｻ";
	kana_buttons_[3]->Caption = "ﾀ";
	kana_buttons_[4]->Caption = "ﾅ";
	kana_buttons_[5]->Caption = "ﾊ";
	kana_buttons_[6]->Caption = "ﾏ";
	kana_buttons_[7]->Caption = "ﾔ";
	kana_buttons_[8]->Caption = "ﾗ";
	kana_buttons_[9]->Caption = "ﾜ";
	kana_buttons_[0]->Visible = true;
	kana_buttons_[1]->Visible = true;
	kana_buttons_[2]->Visible = true;
	kana_buttons_[3]->Visible = true;
	kana_buttons_[4]->Visible = true;
	kana_buttons_[5]->Visible = true;
	kana_buttons_[6]->Visible = true;
	kana_buttons_[7]->Visible = true;
	kana_buttons_[8]->Visible = true;
	kana_buttons_[9]->Visible = true;
	Form->Item1KanaBackButton->Visible = false;

	SetKana(AnsiString(), AnsiString());

	SetupButtons(0);
}

void SelectItem1State::onExit(void *v){
	Form->BackButton->Enabled = true;

	Form->AdminCardIssueButton->Enabled = false;
}

int SelectItem1State::onEvent(int event, void *arg){
	if (event == evItem1Select){
		NsRecord record(*reinterpret_cast<NsRecord *>(arg));
		this->item1_id_   = ToInt(record["項目1ID"]);
		this->item1_name_ = ToString(record["項目1名称"]);
	}
	return event;
}

void SelectItem1State::Initialize(){
	kana_buttons_[0] = Form->Item1Kana1Button;
	kana_buttons_[1] = Form->Item1Kana2Button;
	kana_buttons_[2] = Form->Item1Kana3Button;
	kana_buttons_[3] = Form->Item1Kana4Button;
	kana_buttons_[4] = Form->Item1Kana5Button;
	kana_buttons_[5] = Form->Item1Kana6Button;
	kana_buttons_[6] = Form->Item1Kana7Button;
	kana_buttons_[7] = Form->Item1Kana8Button;
	kana_buttons_[8] = Form->Item1Kana9Button;
	kana_buttons_[9] = Form->Item1Kana10Button;

	buttons_[0] = Form->Item11Button;
	buttons_[1] = Form->Item12Button;
	buttons_[2] = Form->Item13Button;
	buttons_[3] = Form->Item14Button;
	buttons_[4] = Form->Item15Button;
	buttons_[5] = Form->Item16Button;
	buttons_[6] = Form->Item17Button;
	buttons_[7] = Form->Item18Button;
	buttons_[8] = Form->Item19Button;
	buttons_[9] = Form->Item110Button;
	buttons_[10] = Form->Item111Button;
	buttons_[11] = Form->Item112Button;
	buttons_[12] = Form->Item113Button;
	buttons_[13] = Form->Item114Button;
	buttons_[14] = Form->Item115Button;
}

void SelectItem1State::SetupButtons(int start_no){
	current_top_ = start_no;

	NsRecordSet set;
	DM->GetItem1Records(kana1_, kana2_, set);

	int record_count = int(set.size());

	enable_cnt_ = 0;
	int len;
	for (int i = 0; i < 15; i++){
		if (i + start_no >= record_count){
			buttons_[i]->Caption = "";
			buttons_[i]->Hint = "";
			buttons_[i]->Tag = 0;
			buttons_[i]->Enabled = false;
		}else{
			buttons_[i]->Caption = ToString(set[i + start_no]["項目1略称"]);
			buttons_[i]->Tag = ToInt(set[i + start_no]["項目1ID"]);
			buttons_[i]->Enabled = true;

			len = buttons_[i]->Caption.Length();
			if (len <= 20)
				buttons_[i]->Font->Size = 16;
			else if (len <= 22)
				buttons_[i]->Font->Size = 14;
			else if (len <= 26)
				buttons_[i]->Font->Size = 12;
			else
				buttons_[i]->Font->Size = 10;

			enable_cnt_++;
		}
	}
}

/** SelectItem2State Implementation
  */
void SelectItem2State::onEnter(void *v){
	Form->PageControl->ActivePage = Form->Item2Sheet;

	kana_buttons_[0]->Caption = "ｱ";
	kana_buttons_[1]->Caption = "ｶ";
	kana_buttons_[2]->Caption = "ｻ";
	kana_buttons_[3]->Caption = "ﾀ";
	kana_buttons_[4]->Caption = "ﾅ";
	kana_buttons_[5]->Caption = "ﾊ";
	kana_buttons_[6]->Caption = "ﾏ";
	kana_buttons_[7]->Caption = "ﾔ";
	kana_buttons_[8]->Caption = "ﾗ";
	kana_buttons_[9]->Caption = "ﾜ";
	kana_buttons_[0]->Visible = true;
	kana_buttons_[1]->Visible = true;
	kana_buttons_[2]->Visible = true;
	kana_buttons_[3]->Visible = true;
	kana_buttons_[4]->Visible = true;
	kana_buttons_[5]->Visible = true;
	kana_buttons_[6]->Visible = true;
	kana_buttons_[7]->Visible = true;
	kana_buttons_[8]->Visible = true;
	kana_buttons_[9]->Visible = true;
	Form->Item2KanaBackButton->Visible = false;

	SetKana(AnsiString(), AnsiString());

	SetupButtons(0);
}

void SelectItem2State::onExit(void *v){
}

int SelectItem2State::onEvent(int event, void *arg){
	if (event == evItem2Select){
		NsRecord record(*reinterpret_cast<NsRecord *>(arg));
		this->item2_id_   = ToInt(record["項目2ID"]);
		this->item2_name_ = ToString(record["項目2名称"]);
	}
	return event;
}

void SelectItem2State::Initialize(){
	kana_buttons_[0] = Form->Item2Kana1Button;
	kana_buttons_[1] = Form->Item2Kana2Button;
	kana_buttons_[2] = Form->Item2Kana3Button;
	kana_buttons_[3] = Form->Item2Kana4Button;
	kana_buttons_[4] = Form->Item2Kana5Button;
	kana_buttons_[5] = Form->Item2Kana6Button;
	kana_buttons_[6] = Form->Item2Kana7Button;
	kana_buttons_[7] = Form->Item2Kana8Button;
	kana_buttons_[8] = Form->Item2Kana9Button;
	kana_buttons_[9] = Form->Item2Kana10Button;

	buttons_[0] = Form->Item21Button;
	buttons_[1] = Form->Item22Button;
	buttons_[2] = Form->Item23Button;
	buttons_[3] = Form->Item24Button;
	buttons_[4] = Form->Item25Button;
	buttons_[5] = Form->Item26Button;
	buttons_[6] = Form->Item27Button;
	buttons_[7] = Form->Item28Button;
	buttons_[8] = Form->Item29Button;
	buttons_[9] = Form->Item210Button;
	buttons_[10] = Form->Item211Button;
	buttons_[11] = Form->Item212Button;
	buttons_[12] = Form->Item213Button;
	buttons_[13] = Form->Item214Button;
	buttons_[14] = Form->Item215Button;
}

void SelectItem2State::SetupButtons(int start_no){
	current_top_ = start_no;

	NsRecordSet set;
	DM->GetItem2Records(kana1_, kana2_, set);

	int record_count = int(set.size());

	enable_cnt_ = 0;
	int len;
	for (int i = 0; i < 15; i++){
		if (i + start_no >= record_count){
			buttons_[i]->Caption = "";
			buttons_[i]->Hint = "";
			buttons_[i]->Tag = 0;
			buttons_[i]->Enabled = false;
		}else{
			buttons_[i]->Caption = ToString(set[i + start_no]["項目2略称"]);
			buttons_[i]->Tag = ToInt(set[i + start_no]["項目2ID"]);
			buttons_[i]->Enabled = true;

			len = buttons_[i]->Caption.Length();
			if (len <= 20)
				buttons_[i]->Font->Size = 16;
			else if (len <= 22)
				buttons_[i]->Font->Size = 14;
			else if (len <= 26)
				buttons_[i]->Font->Size = 12;
			else
				buttons_[i]->Font->Size = 10;

			enable_cnt_++;
		}
	}
}

/** InputCarNoState Implementation
  */
void InputCarNoState::onEnter(void *v){
	Form->PageControl->ActivePage = Form->CarNoSheet;

	Form->CarNoInputEdit->Text = AnsiString();
	Form->CarNoInputEdit->SetFocus();
    Form->CarNoSelectButton->Enabled = false;
    Form->CarNoAddButton->Enabled    = false;
    Form->Q_Syaryo->Close();
}

void InputCarNoState::onExit(void *v){
}

int InputCarNoState::onEvent(int event, void *arg){
	if (event != evCarNoInput)
		return event;
	NsRecord record(*reinterpret_cast<NsRecord *>(arg));
    this->car_id_  = ToInt(record["車両ID"]);
	this->car_no_  = ToInt(record["車番"]);
    this->add_car_ = ToBit(record["車両追加"]);
	return event;
}


/** ConfirmState Implementation
  */
void ConfirmState::onEnter(void *v){
	Form->PageControl->ActivePage = Form->ConfirmSheet;

    if (this->toku_id_)
    	Form->TokuPanel->Caption  = " " + this->toku_name_;
    else
    	Form->TokuPanel->Caption  = " 指定なし";

    if (this->meig_id_)
    	Form->MeigPanel->Caption  = " " + this->meig_name_;
    else
    	Form->MeigPanel->Caption  = " 指定なし";

    if (this->item1_id_)
    	Form->Item1Panel->Caption = " " + this->item1_name_;
    else
    	Form->Item1Panel->Caption = " 指定なし";

    if (this->item2_id_)
    	Form->Item2Panel->Caption = " " + this->item2_name_;
    else
    	Form->Item2Panel->Caption = " 指定なし";

	if (this->car_no_)
		Form->CarNoPanel->Caption = " " + IntToStr(this->car_no_);
	else
		Form->CarNoPanel->Caption = " 指定なし";
}

void ConfirmState::onExit(void *v){
}

int ConfirmState::onEvent(int event, void *arg){
	return event;
}

/** IssueState Implementation
  */
void IssueState::onEnter(void *v){
	Form->WriteButton->Visible = true;

	Form->PageControl->ActivePage = Form->IssueSheet;

	Form->WriteButton->Enabled = true;
	Form->CardIssueStatus->Lines->Clear();
}

void IssueState::onExit(void *v){
}

int IssueState::onEvent(int event, void *arg){
	return event;
}

/** AdminIssueState Implementation
  */
void AdminIssueState::onEnter(void *v){
	Form->PageControl->ActivePage = Form->AdminIssueSheet;

	Form->AdminIssueButton->Enabled      = true;
	Form->ZeroSetIssueButton->Enabled    = true;
	Form->ZeroCancelIssueButton->Enabled = true;

	Form->AdminCardIssueStatus->Lines->Clear();
}

void AdminIssueState::onExit(void *v){
}

int AdminIssueState::onEvent(int event, void *arg){
	return event;
}


