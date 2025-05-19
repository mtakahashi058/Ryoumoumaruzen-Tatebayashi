/** PageState.cpp
 *
 */

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include <mmsystem.h>
#include "PageState.h"

#include "TareWeighingFrm.h"
#include "DMFrm.h"

#define Form	(TareWeighingForm)

StartUpState stateStartup;
SelectModeState stateSelectMode;
WaitCardState stateWaitCard;
WeighTareState stateWeighTare;
CompleteState stateComplete;

int PageState::car_id_;
int PageState::car_no_;

/** WaitCardState Implementation
  */
void WaitCardState::onEnter(void *v){
	// 初期化
	this->car_id_ = 0;

	Form->StatusLabel->Caption = "";
	Form->StatusMemo->Lines->Clear();

	Form->TokuPanel->Caption  = AnsiString();
	Form->MeigPanel->Caption  = AnsiString();
	Form->Item1Panel->Caption = AnsiString();
	Form->Item2Panel->Caption = AnsiString();
	Form->CarNoPanel->Caption = AnsiString();
	Form->TareWeightLabel->Caption = AnsiString();

	Form->CloseButton->SetFocus();

	Form->PageControl->ActivePage = Form->WaitCardSheet;
	Form->BackButton->Enabled = false;
}

void WaitCardState::onExit(void *v){
	Form->BackButton->Enabled = true;
}

int WaitCardState::onEvent(int event, void *arg){
	if (event != evCard)
		return event;

	NsRecordSet set(*reinterpret_cast<NsRecordSet *>(arg));

	Form->TokuPanel->Caption  = SET_TOP(set)["得意先略称"].IsNull()
			? AnsiString(" 指定なし") : AnsiString(" ") + ToString(SET_TOP(set)["得意先略称"]);
	Form->MeigPanel->Caption  = SET_TOP(set)["品目略称"].IsNull()
			? AnsiString(" 指定なし") : AnsiString(" ") + ToString(SET_TOP(set)["品目略称"]);
	Form->Item1Panel->Caption = SET_TOP(set)["項目1略称"].IsNull()
			? AnsiString(" 指定なし") : AnsiString(" ") + ToString(SET_TOP(set)["項目1略称"]);
	Form->Item2Panel->Caption = SET_TOP(set)["項目2略称"].IsNull()
			? AnsiString(" 指定なし") : AnsiString(" ") + ToString(SET_TOP(set)["項目2略称"]);
	Form->CarNoPanel->Caption     = ToInt(SET_TOP(set)["車番"]) < 1
			? AnsiString(" 指定なし") : " " + ToString(SET_TOP(set)["車番"]);
	if (ToInt(SET_TOP(set)["空車重量"])){
		Form->TareWeightLabel->Caption = FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["空車重量"]));
	}

	this->car_id_ = ToInt(SET_TOP(set)["車両ID"]);
	this->car_no_ = ToInt(SET_TOP(set)["車番"]);
	return evCard;
}

/** SelectModeState Implementation
  */
void SelectModeState::onEnter(void *v){
	Form->PageControl->ActivePage = Form->ModeSelectSheet;
}

void SelectModeState::onExit(void *v){
}

int SelectModeState::onEvent(int event, void *arg){
	if (event == evRepealTare){
		NsFieldSet fields;
		fields << NsField("[空車重量]", 0)
               << NsField("[更新日時]", Now());
		DM->DBI.Update("M_車両", "車両ID", this->car_id_, fields);
		Form->CompleteMemo->Lines->Text = "空車重量を無効にしました。";
	}
	if (event == evWeighTare){
		if (this->car_no_ < 1){
			// 警告シートに移動
			Form->PageControl->ActivePage = Form->WarningSheet;
			return evNone;
		}
	}
	if (event == evWeighConfirm){
		// 警告シートで確認
		return evWeighTare;
	}
	return event;
}

/** WeighTareState Implementation
  */
void WeighTareState::onEnter(void *v){
	Form->PageControl->ActivePage = Form->WeighTareSheet;
}

void WeighTareState::onExit(void *v){
}

int WeighTareState::onEvent(int event, void *arg){
	if (event == evComplete){
		NsFieldSet fields;
		fields << NsField("[空車重量]", int(Form->GetWeight()))
               << NsField("[更新日時]", Now());
		DM->DBI.Update("M_車両", "車両ID", this->car_id_, fields);
		Form->CompleteMemo->Lines->Text = "空車重量を設定しました。";
	}
	return event;
}

/** CompleteState Implementation
  */
void CompleteState::onEnter(void *v){
	Form->PageControl->ActivePage = Form->CompleteSheet;
	Form->CompleteConfirmButton->SetFocus();
}

void CompleteState::onExit(void *v){
}

int CompleteState::onEvent(int event, void *arg){
	return event;
}

