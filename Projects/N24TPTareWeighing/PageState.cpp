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
	// ������
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

	Form->TokuPanel->Caption  = SET_TOP(set)["���Ӑ旪��"].IsNull()
			? AnsiString(" �w��Ȃ�") : AnsiString(" ") + ToString(SET_TOP(set)["���Ӑ旪��"]);
	Form->MeigPanel->Caption  = SET_TOP(set)["�i�ڗ���"].IsNull()
			? AnsiString(" �w��Ȃ�") : AnsiString(" ") + ToString(SET_TOP(set)["�i�ڗ���"]);
	Form->Item1Panel->Caption = SET_TOP(set)["����1����"].IsNull()
			? AnsiString(" �w��Ȃ�") : AnsiString(" ") + ToString(SET_TOP(set)["����1����"]);
	Form->Item2Panel->Caption = SET_TOP(set)["����2����"].IsNull()
			? AnsiString(" �w��Ȃ�") : AnsiString(" ") + ToString(SET_TOP(set)["����2����"]);
	Form->CarNoPanel->Caption     = ToInt(SET_TOP(set)["�Ԕ�"]) < 1
			? AnsiString(" �w��Ȃ�") : " " + ToString(SET_TOP(set)["�Ԕ�"]);
	if (ToInt(SET_TOP(set)["��ԏd��"])){
		Form->TareWeightLabel->Caption = FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["��ԏd��"]));
	}

	this->car_id_ = ToInt(SET_TOP(set)["�ԗ�ID"]);
	this->car_no_ = ToInt(SET_TOP(set)["�Ԕ�"]);
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
		fields << NsField("[��ԏd��]", 0)
               << NsField("[�X�V����]", Now());
		DM->DBI.Update("M_�ԗ�", "�ԗ�ID", this->car_id_, fields);
		Form->CompleteMemo->Lines->Text = "��ԏd�ʂ𖳌��ɂ��܂����B";
	}
	if (event == evWeighTare){
		if (this->car_no_ < 1){
			// �x���V�[�g�Ɉړ�
			Form->PageControl->ActivePage = Form->WarningSheet;
			return evNone;
		}
	}
	if (event == evWeighConfirm){
		// �x���V�[�g�Ŋm�F
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
		fields << NsField("[��ԏd��]", int(Form->GetWeight()))
               << NsField("[�X�V����]", Now());
		DM->DBI.Update("M_�ԗ�", "�ԗ�ID", this->car_id_, fields);
		Form->CompleteMemo->Lines->Text = "��ԏd�ʂ�ݒ肵�܂����B";
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

