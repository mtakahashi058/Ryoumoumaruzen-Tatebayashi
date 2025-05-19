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
	SFM.AddLog("1回目重量確認画面 車両ID/車番: " + ToString(SFM.Stashed("車両ID")) + "/" + ToString(SFM.car_rec["車番"]));

	weight_ = ToInt(SFM.Stashed("Weight"));

	WarningMemo->Lines->Clear();
	ConfirmButton->Enabled = true;

	CarNoLabel->Caption = ToString(SFM.Stashed("車番"));
	TokuLabel->Caption  = ToString(SFM.Stashed("得意先略称"));
	Item1Label->Caption = ToString(SFM.Stashed("項目1略称"));
	Item2Label->Caption = ToString(SFM.Stashed("項目2略称"));

    CarNoChangeButton->Enabled = ToBit(SFM.Stashed("車番入力"));
	TokuChangeButton->Enabled  = ToBit(SFM.Stashed("得意先選択"));
	Item1ChangeButton->Enabled = ToBit(SFM.Stashed("項目1選択"));
	Item2ChangeButton->Enabled = ToBit(SFM.Stashed("項目2選択"));

    if (ToBit(DM->CFG["得意先マスタ使用区分"])){
		TokuLabel->Visible         = true;
		TokuChangeButton->Visible  = true;
	}else{
		TokuLabel->Visible         = false;
		TokuChangeButton->Visible  = false;
    }
    if (ToBit(DM->CFG["項目1マスタ使用区分"])){
		Item1Label->Visible        = true;
		Item1ChangeButton->Visible = true;
	}else{
		Item1Label->Visible        = false;
		Item1ChangeButton->Visible = false;
    }
    if (ToBit(DM->CFG["項目2マスタ使用区分"])){
		Item2Label->Visible        = true;
		Item2ChangeButton->Visible = true;
	}else{
		Item2Label->Visible        = false;
		Item2ChangeButton->Visible = false;
    }

	WeightPanel->Caption = FormatFloat("###,##0", weight_);

	int limit_weight = ToInt(SFM.car_rec["車両総重量"]);
	if (weight_ > limit_weight && limit_weight){
		WarningMemo->Lines->Append("過積載です。計量できません。");
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
	// 初回計量情報登録

	NsFieldSet fields;
	TDateTime now(Now());
	int date = now.FormatString("yyyymmdd").ToInt();
	int no   = DM->GetTempKeiryoNo();

	try{
		DM->ADOConnection->BeginTrans();

        ///// 車両のチェック
        int car_id = ToInt(SFM.Stashed("車両ID"));
        int car_no = ToInt(SFM.Stashed("車番"));
        if (ToBit(SFM.Stashed("新車両")) && car_no){
            AnsiString sql;
            NsRecordSet set;

            sql = " SELECT TOP 1 車両ID FROM M_車両"
                  " WHERE 車番 = " + IntToStr(car_no) +
                  "   AND (カード番号 = 0 OR カード番号 IS NULL)";
            if (DM->DBI.GetRecordSet(sql, set)){
                car_id = ToInt(SET_TOP(set)["車両ID"]);
            }else{
                ///// 車両マスタ登録
                fields << NsField("[車番]",     car_no)
                       << NsField("[車両名称]", now.FormatString("mm/dd'に自動計量'"))
                       << NsField("[更新日時]", now)
                       << NsField("[作成日時]", now);
                DM->DBI.Insert("M_車両", fields);
                car_id = DM->DBI.GetLastID();
            }
        }

        fields.clear();
        fields
            << NsField("[計量日]",       date)
            << NsField("[拠点ID]",       N24TP::place_id)
			<< NsField("[伝票No]",       no)
            << NsField("[行No]",         1)
            << NsField("[車両ID]",       car_id)
            << NsField("[カード車両ID]", ToInt(SFM.Stashed("カード車両ID")))
            << NsField("[得意先ID]",     ToInt(SFM.Stashed("得意先ID")))
    		<< NsField("[得意先名称]",   ToString(DM->DBI.Lookup("M_得意先", "得意先ID", ToInt(SFM.Stashed("得意先ID")), "得意先名称")))
            << NsField("[項目1ID]",      ToInt(SFM.Stashed("項目1ID")))
            << NsField("[項目1名称]",    ToString(DM->DBI.Lookup("M_項目1", "項目1ID", ToInt(SFM.Stashed("項目1ID")), "項目1名称")))
            << NsField("[項目2ID]",      ToInt(SFM.Stashed("項目2ID")))
            << NsField("[項目2名称]",    ToString(DM->DBI.Lookup("M_項目2", "項目2ID", ToInt(SFM.Stashed("項目2ID")), "項目2名称")))
            << NsField("[品目ID]",       ToInt(SFM.Stashed("品目ID")))
            << NsField("[品目名称]",     ToString(DM->DBI.Lookup("M_品目", "品目ID", ToInt(SFM.Stashed("品目ID")), "品目名称")))
            << NsField("[搬入出区分]",   ToInt(DM->DBI.Lookup("M_品目", "品目ID", ToInt(SFM.Stashed("品目ID")), "搬入出区分")))
            << NsField("[1回目重量]",    weight_)
            << NsField("[計量日時1]",    now)
            << NsField("[完了区分]",     0)
            << NsField("[作成日時]",     now)
            << NsField("[更新日時]",     now)
            ;
		DM->DBI.Insert("D_計量", fields);
		DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		DM->ADOConnection->RollbackTrans();

		AnsiString message = "DBエラー: " + e.Message;
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

