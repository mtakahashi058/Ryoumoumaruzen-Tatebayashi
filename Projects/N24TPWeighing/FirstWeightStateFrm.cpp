//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FirstWeightStateFrm.h"
#include "DMFrm.h"
#include "MainFrm.h"
#include <mmsystem.h>
#include "n24tp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFirstWeightStateForm *FirstWeightStateForm;
//---------------------------------------------------------------------------
__fastcall TFirstWeightStateForm::TFirstWeightStateForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::ConfirmFirstWeight, this);
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::OnEnter()
{
	SFM.AddLog("1��ڏd�ʊm�F��� �ԗ�ID/�Ԕ�: " + ToString(SFM.Stashed("�ԗ�ID")) + "/" + ToString(SFM.car_rec["�Ԕ�"]));

	weight_ = ToInt(SFM.Stashed("Weight"));

	WarningMemo->Lines->Clear();
	ConfirmButton->Enabled = true;

	CarNoLabel->Caption = ToString(SFM.Stashed("�Ԕ�"));
	TokuLabel->Caption  = ToString(SFM.Stashed("���Ӑ旪��"));
	Item1Label->Caption = ToString(SFM.Stashed("����1����"));
	Item2Label->Caption = ToString(SFM.Stashed("����2����"));

    CarNoChangeButton->Enabled = ToBit(SFM.Stashed("�Ԕԓ���"));
	TokuChangeButton->Enabled  = ToBit(SFM.Stashed("���Ӑ�I��"));
	Item1ChangeButton->Enabled = ToBit(SFM.Stashed("����1�I��"));
	Item2ChangeButton->Enabled = ToBit(SFM.Stashed("����2�I��"));

    if (ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
		TokuLabel->Visible         = true;
		TokuChangeButton->Visible  = true;
	}else{
		TokuLabel->Visible         = false;
		TokuChangeButton->Visible  = false;
    }
    if (ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
		Item1Label->Visible        = true;
		Item1ChangeButton->Visible = true;
	}else{
		Item1Label->Visible        = false;
		Item1ChangeButton->Visible = false;
    }
    if (ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
		Item2Label->Visible        = true;
		Item2ChangeButton->Visible = true;
	}else{
		Item2Label->Visible        = false;
		Item2ChangeButton->Visible = false;
    }

	WeightPanel->Caption = FormatFloat("###,##0", weight_);

	int limit_weight = ToInt(SFM.car_rec["�ԗ����d��"]);
	if (weight_ > limit_weight && limit_weight){
		WarningMemo->Lines->Append("�ߐύڂł��B�v�ʂł��܂���B");
		ConfirmButton->Enabled = false;
		PlaySound(ToString(DM->Sounds["OverWeight"]).c_str(), 0, SND_ASYNC | SND_FILENAME);
        
	    SFM.PatliteAlert(false, true);
	}

	if (ConfirmButton->Enabled)
		PlaySound(ToString(DM->Sounds["FirstWeighing"]).c_str(), 0, SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::OnExit()
{
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::ConfirmButtonClick(TObject *Sender)
{
	// ����v�ʏ��o�^

	NsFieldSet fields;
	TDateTime now(Now());
	int date = now.FormatString("yyyymmdd").ToInt();
	int no   = DM->GetTempKeiryoNo();

	try{
		DM->ADOConnection->BeginTrans();

        ///// �ԗ��̃`�F�b�N
        int car_id = ToInt(SFM.Stashed("�ԗ�ID"));
        int car_no = ToInt(SFM.Stashed("�Ԕ�"));
        if (ToBit(SFM.Stashed("�V�ԗ�")) && car_no){
            AnsiString sql;
            NsRecordSet set;

            sql = " SELECT TOP 1 �ԗ�ID FROM M_�ԗ�"
                  " WHERE �Ԕ� = " + IntToStr(car_no) +
                  "   AND (�J�[�h�ԍ� = 0 OR �J�[�h�ԍ� IS NULL)";
            if (DM->DBI.GetRecordSet(sql, set)){
                car_id = ToInt(SET_TOP(set)["�ԗ�ID"]);
            }else{
                ///// �ԗ��}�X�^�o�^
                fields << NsField("[�Ԕ�]",     car_no)
                       << NsField("[�ԗ�����]", now.FormatString("mm/dd'�Ɏ����v��'"))
                       << NsField("[�X�V����]", now)
                       << NsField("[�쐬����]", now);
                DM->DBI.Insert("M_�ԗ�", fields);
                car_id = DM->DBI.GetLastID();
            }
        }

        fields.clear();
        fields
            << NsField("[�v�ʓ�]",       date)
            << NsField("[���_ID]",       N24TP::place_id)
			<< NsField("[�`�[No]",       no)
            << NsField("[�sNo]",         1)
            << NsField("[�ԗ�ID]",       car_id)
            << NsField("[�J�[�h�ԗ�ID]", ToInt(SFM.Stashed("�J�[�h�ԗ�ID")))
            << NsField("[���Ӑ�ID]",     ToInt(SFM.Stashed("���Ӑ�ID")))
    		<< NsField("[���Ӑ於��]",   ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", ToInt(SFM.Stashed("���Ӑ�ID")), "���Ӑ於��")))
            << NsField("[����1ID]",      ToInt(SFM.Stashed("����1ID")))
            << NsField("[����1����]",    ToString(DM->DBI.Lookup("M_����1", "����1ID", ToInt(SFM.Stashed("����1ID")), "����1����")))
            << NsField("[����2ID]",      ToInt(SFM.Stashed("����2ID")))
            << NsField("[����2����]",    ToString(DM->DBI.Lookup("M_����2", "����2ID", ToInt(SFM.Stashed("����2ID")), "����2����")))
            << NsField("[�i��ID]",       ToInt(SFM.Stashed("�i��ID")))
            << NsField("[�i�ږ���]",     ToString(DM->DBI.Lookup("M_�i��", "�i��ID", ToInt(SFM.Stashed("�i��ID")), "�i�ږ���")))
            << NsField("[�����o�敪]",   ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", ToInt(SFM.Stashed("�i��ID")), "�����o�敪")))
            << NsField("[1��ڏd��]",    weight_)
            << NsField("[�v�ʓ���1]",    now)
            << NsField("[�����敪]",     0)
            << NsField("[�쐬����]",     now)
            << NsField("[�X�V����]",     now)
            ;
		DM->DBI.Insert("D_�v��", fields);
		DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		DM->ADOConnection->RollbackTrans();

		AnsiString message = "DB�G���[: " + e.Message;
		SFM.SendStatus(message);
		return;
	}

	SFM.PatliteAlert(true, false);

	SFM.Transit(State::WaitExit);
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::CancelButtonClick(TObject *Sender)
{
	SFM.Transit(State::WaitCard);
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::CarNoChangeButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::InputCarNo);
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::TokuChangeButtonClick(
      TObject *Sender)
{
	SFM.Transit(State::SelectToku);
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::Item1ChangeButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::SelectItem1);
}
//---------------------------------------------------------------------------
void __fastcall TFirstWeightStateForm::Item2ChangeButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::SelectItem2);
}
//---------------------------------------------------------------------------

