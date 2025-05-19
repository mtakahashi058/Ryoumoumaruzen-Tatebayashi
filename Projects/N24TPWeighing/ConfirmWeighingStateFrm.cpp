//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfirmWeighingStateFrm.h"
#include "DMFrm.h"
#include "n24tp.h"
#include <mmsystem.h>
#include <cstdlib>
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfirmWeighingStateForm *ConfirmWeighingStateForm;
//---------------------------------------------------------------------------
__fastcall TConfirmWeighingStateForm::TConfirmWeighingStateForm(TComponent* Owner)
	: AbstractStateForm(Owner),current_weight_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::ConfirmWeighing, this);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::OnEnter()
{
	WarningMemo->Lines->Clear();
	ContinueButton->Enabled = true;
	CompleteButton->Enabled = true;

	SFM.AddLog("計量確認画面 車両ID/車番: " + ToString(SFM.Stashed("車両ID")) + "/" + ToString(SFM.car_rec["車番"]));

	///////////////////////////////////////////////
    int last_w;
    int curr_w = ToInt(SFM.Stashed("Weight"));

	DBGrid->Columns->Items[0]->Title->Caption = ToString(DM->CFG["品目マスタ名称"]);

	// 計量内容 Grid
	if (SFM.stash.find("計量ID") != SFM.stash.end()){
		if (GridQuery->Active)
			GridQuery->Close();
		GridQuery->SQL->Text = " SELECT 品目略称, 正味重量 FROM V_計量"
                               " WHERE 車両ID = " + ToString(SFM.Stashed("車両ID")) + " AND 完了区分 = 0 AND 正味重量 > 0"
                               " ORDER BY 行No";
		GridQuery->Open();
	}else{
		GridQuery->Close();
	}

    if (ToBit(DM->CFG["品目マスタ使用区分"])){
		MeigPanel->Visible         = true;
		MeigChangeButton->Visible  = true;
	}else{
		MeigPanel->Visible         = false;
		MeigChangeButton->Visible  = false;
    }

	if (ToBit(SFM.Stashed("1回計量"))){
		// 1回計量

		// 継続なし、完了→確認に変更、グリッドなし
		ContinueButton->Enabled = false;
		ContinueButton->Visible = false;
		CompleteButton->Caption = "確認";

		if (!ToBit(SFM.Stashed("品目選択")))
            MeigChangeButton->Enabled = false;
        else
            MeigChangeButton->Enabled = true;

        last_w = ToInt(SFM.car_rec["空車重量"]);
	}else{
		if (ToBit(SFM.Stashed("品目選択"))){
			MeigChangeButton->Enabled  = true;
		}

        if (IsNull(SFM.remained_rec["計量日時2"])){       // １明細目
            last_w = ToInt(SFM.remained_rec["1回目重量"]);
        }else{
            last_w = ToInt(SFM.remained_rec["2回目重量"]);
        }

        int last_lineno = ToInt(SFM.remained_rec["行No"]);

		// [INI] Keiryo::MaxDetails
        int max_details = ToInt(DM->INI["Keiryo::MaxDetails"]) - 1;

        // [CFG]
        if (ToInt(DM->CFG["単品多段区分"]) == 1)
            max_details = 0;

		if (last_lineno >= max_details){
			if (last_lineno == 0){
				CompleteButton->Caption = "確認";
			}else{
				CompleteButton->Caption = "完了";
			}
			ContinueButton->Enabled = false;
			ContinueButton->Visible = false;
		}else{
			ContinueButton->Enabled = true;
			ContinueButton->Visible = true;
			CompleteButton->Caption = "完了";
		}
	}

	int gross_w = std::max(last_w, curr_w);
	int tare_w  = std::min(last_w, curr_w);
	int net_w   = gross_w - tare_w;
    current_weight_ = curr_w;

	CarNoLabel->Caption = ToString(SFM.Stashed("車番"));
    TokuLabel->Caption  = ToString(SFM.Stashed("得意先略称"));
	Item1Label->Caption = ToString(SFM.Stashed("項目1略称"));
	Item2Label->Caption = ToString(SFM.Stashed("項目2略称"));
	MeigPanel->Caption  = ToString(SFM.Stashed("品目略称"));

	NetWeightPanel->Caption = FormatFloat("###,##0 ", net_w);

	int limit_weight;
	limit_weight = ToInt(SFM.car_rec["車両総重量"]);
	if (gross_w > limit_weight && limit_weight){
		WarningMemo->Lines->Append("総重量超過です。計量できません。");
		ContinueButton->Enabled = false;
		CompleteButton->Enabled = false;
		PlaySound(ToString(DM->Sounds["OverWeight"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

	    SFM.PatliteAlert(false, true);
	}
	limit_weight = ToInt(SFM.car_rec["最大積載量"]);
	if (net_w > limit_weight && limit_weight){
		WarningMemo->Lines->Append("正味重量超過です。計量できません。");
		ContinueButton->Enabled = false;
		CompleteButton->Enabled = false;
		PlaySound(ToString(DM->Sounds["OverWeight"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

	    SFM.PatliteAlert(false, true);
	}

	if (CompleteButton->Enabled)
		PlaySound(ToString(DM->Sounds["Weighing"]).c_str(), 0, SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::OnExit()
{
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::ContinueButtonClick(
	  TObject *Sender)
{
	try{
		DM->ADOConnection->BeginTrans();

        PostRecord(false);

		DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		DM->ADOConnection->RollbackTrans();
		AnsiString message = "DBエラー: " + e.Message;
		SFM.SendStatus(message);

		SFM.PatliteAlert(false, true);
		return;
	}

	SFM.PatliteAlert(true, false);
	SFM.Transit(State::ConfirmContinuation);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::CompleteButtonClick(
	  TObject *Sender)
{
	try{
		DM->ADOConnection->BeginTrans();

		PostRecord(true);

		DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		DM->ADOConnection->RollbackTrans();
		AnsiString message = "DBエラー: " + e.Message;
		SFM.SendStatus(message);

		SFM.PatliteAlert(false, true);
		return;
	}

	SFM.PatliteAlert(true, false);
	SFM.Transit(State::ConfirmPrint);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::PostRecord(bool complete)
{
	// トランザクションはこの上でかけて

	if (!DM->ADOConnection->InTransaction)
		throw Exception("[PGE] トランザクションが開始されていません");

	NsFieldSet fields;
	TDateTime now(Now());
	int date = now.FormatString("yyyymmdd").ToInt();

    int cur_weight = current_weight_;

    int keiryo_id = 0;
    int last_w;
    int toku_id;
    int meig_id;
    int item1_id;
    int item2_id;
    int net;
    int old_date, old_no;
    int lineno = 1;

	if (ToBit(SFM.Stashed("1回計量"))){
        old_date = date;
        old_no   = DM->GetTempKeiryoNo();
        last_w   = ToInt(SFM.car_rec["空車重量"]);
        toku_id  = ToInt(SFM.Stashed("得意先ID"));
        meig_id  = ToInt(SFM.Stashed("品目ID"));
        item1_id = ToInt(SFM.Stashed("項目1ID"));
        item2_id = ToInt(SFM.Stashed("項目2ID"));

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
            << NsField("[計量日]",       old_date)
            << NsField("[拠点ID]",       N24TP::place_id)
            << NsField("[伝票No]",       old_no)
            << NsField("[行No]",         1)
            << NsField("[車両ID]",       car_id)
            << NsField("[カード車両ID]", ToInt(SFM.Stashed("カード車両ID")))
            << NsField("[得意先ID]",     toku_id)
            << NsField("[得意先名称]",   ToString(DM->DBI.Lookup("M_得意先", "得意先ID", toku_id,  "得意先名称")))
            << NsField("[項目1ID]",      item1_id)
            << NsField("[項目1名称]",    ToString(DM->DBI.Lookup("M_項目1",  "項目1ID",  item1_id, "項目1名称")))
            << NsField("[項目2ID]",      item2_id)
            << NsField("[項目2名称]",    ToString(DM->DBI.Lookup("M_項目2",  "項目2ID",  item2_id, "項目2名称")))
            << NsField("[1回目重量]",    last_w)
            << NsField("[計量日時1]",    Variant())
            << NsField("[作成日時]",     now)
            ;
        net = std::abs(cur_weight - last_w);

	}else{  // 一回計量以外

        int last_w;

        old_date = ToInt(SFM.remained_rec["計量日"]);
        old_no   = ToInt(SFM.remained_rec["伝票No"]);

        //if (SFM.Stashed("行No") == 1){                  // １明細目
        if (IsNull(SFM.remained_rec["計量日時2"])){       // １明細目
            keiryo_id           = ToInt(SFM.Stashed("計量ID"));
            last_w              = ToInt(SFM.remained_rec["1回目重量"]);
            SFM.stash["新行No"] = ToInt(SFM.remained_rec["行No"]);
        }else{
            lineno = DM->GetNextDetailNo(ToInt(SFM.Stashed("計量ID")));
            fields
                << NsField("[計量日]",       ToInt(SFM.remained_rec["計量日"]))
                << NsField("[拠点ID]",       N24TP::place_id)
                << NsField("[伝票No]",       ToInt(SFM.remained_rec["伝票No"]))
                << NsField("[行No]",         lineno)
                << NsField("[車両ID]",       ToInt(SFM.remained_rec["車両ID"]))
                << NsField("[カード車両ID]", ToInt(SFM.Stashed("カード車両ID")))
                << NsField("[得意先ID]",     ToInt(SFM.remained_rec["得意先ID"]))
        		<< NsField("[得意先名称]",   ToString(SFM.remained_rec["得意先名称"]))
                << NsField("[項目1ID]",      ToInt(SFM.remained_rec["項目1ID"]))
                << NsField("[項目1名称]",    ToString(SFM.remained_rec["項目1名称"]))
                << NsField("[項目2ID]",      ToInt(SFM.remained_rec["項目2ID"]))
                << NsField("[項目2名称]",    ToString(SFM.remained_rec["項目2名称"]))
                << NsField("[1回目重量]",    ToInt(SFM.remained_rec["2回目重量"]))
                << NsField("[計量日時1]",    SFM.remained_rec["計量日時2"])
                << NsField("[作成日時]",     now)
                ;
            last_w              = ToInt(SFM.remained_rec["2回目重量"]);
            SFM.stash["新行No"] = lineno;
        }

        toku_id  = ToInt(SFM.remained_rec["得意先ID"]);
        meig_id  = ToInt(SFM.Stashed("品目ID"));
        item1_id = ToInt(SFM.remained_rec["項目1ID"]);
        item2_id = ToInt(SFM.remained_rec["項目2ID"]);
        net = std::abs(cur_weight - last_w);
    }

    NsRecord toku_rec, item1_rec;
    DM->GetViewRec("得意先", toku_id,  toku_rec);
    DM->GetViewRec("項目1",  item1_id, item1_rec);

	///// 重量調整率
    Currency adj_per = 0;
    int adj_weight   = 0;

	adj_per    = ToCurrency(DM->DBI.Lookup("M_品目", "品目ID", meig_id, "重量調整率"));
	if (adj_per != 0){
	    adj_per   /= 100;

	    ///// 調整端数処理区分の取得
    	int cnv_div = -1;

	    if (!toku_rec.empty()){
    	    if (!IsNull(toku_rec["調整端数処理区分"]))
        	    cnv_div = ToInt(toku_rec["調整端数処理区分"]);
	    }
    	if (cnv_div == -1)
        	cnv_div = ToInt(DM->CFG["調整端数処理区分"]);

   	    adj_weight = ExtendedRound(Currency(net) * adj_per, ToInt(DM->CFG["調整端数処理桁数"]), cnv_div);

        net -= adj_weight;
    }

    fields
        << NsField("[品目ID]",     meig_id)
        << NsField("[品目名称]",   ToString(DM->DBI.Lookup("M_品目", "品目ID", ToInt(SFM.Stashed("品目ID")), "品目名称")))
        << NsField("[搬入出区分]", ToInt(DM->DBI.Lookup("M_品目", "品目ID", ToInt(SFM.Stashed("品目ID")), "搬入出区分")))
        << NsField("[2回目重量]",  cur_weight)
        << NsField("[計量日時2]",  now)
        << NsField("[調整率]",     adj_per)
        << NsField("[調整重量]",   adj_weight)
        << NsField("[正味重量]",   net)
        << NsField("[完了区分]",   0)
        << NsField("[更新日時]",   now)
        ;

    //////////////////////////////////////////////////////////////////////
    // 単位の取得

    int tani_code = DM->GetKanzanCode(toku_id, meig_id);
    int tani_id = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tani_code, "単位ID"));
    fields << NsField("[単位ID]",     tani_id);

    //////////////////////////////////////////////////////////////////////
    // 正味や金額等の計算

	Currency quantity;
	if (tani_id == 3)
		quantity = Currency(net);
	else
		quantity = Currency(net) / Currency(1000);
	Currency cnv_ratio = DM->GetKanzan(toku_id, meig_id, tani_id);

    ///// 換算端数処理区分の取得
    int cnv_div = -1;

    if (!toku_rec.empty()){
        if (!IsNull(toku_rec["換算端数処理区分"]))
            cnv_div = ToInt(toku_rec["換算端数処理区分"]);
    }
    if (cnv_div == -1)
        cnv_div = ToInt(DM->CFG["換算端数処理区分"]);
    /////

    if (cnv_ratio == 0){
        quantity = ExtendedRound(quantity,             ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
    }else{
        quantity = ExtendedRound(quantity / cnv_ratio, ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
    }

    fields << NsField("[数量]",     quantity);

    Currency tanka = DM->GetTanka(toku_id, meig_id, item1_id, item2_id, tani_id);
    int amount, tax;

    ///// 金額端数処理区分の取得
    int amount_div = -1;

    if (!toku_rec.empty()){
        if (!IsNull(toku_rec["金額端数処理区分"]))
            amount_div = ToInt(toku_rec["金額端数処理区分"]);
    }
    if (amount_div == -1)
        amount_div = ToInt(DM->CFG["金額端数処理区分"]);
    /////

    amount = ExtendedRound(quantity * tanka, 0, amount_div);

    Currency tax_rate = DM->GetSalesTax();			// 消費税率

    ///// 消費税端数処理区分の取得
    int tax_div = -1;

    if (!toku_rec.empty()){
        if (!IsNull(toku_rec["消費税端数処理区分"]))
            tax_div = ToInt(toku_rec["消費税端数処理区分"]);
    }
    if (tax_div == -1)
        tax_div = ToInt(DM->CFG["消費税端数処理区分"]);
    /////

    tax = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

    fields << NsField("[単価]",         tanka)
           << NsField("[金額]",         amount)
           << NsField("[消費税額]",     tax)
           ;
           
    if (keiryo_id){
        DM->DBI.Update("D_計量", "計量ID", keiryo_id, fields);
    }else{
        DM->DBI.Insert("D_計量", fields);
        keiryo_id = DM->DBI.GetLastID();
		SFM.stash["計量ID"] = keiryo_id;	// 2012.07.13 追加（野村）
    }

    {
        NsFieldSet keys;

        keys <<  NsField("計量日", ToInt(SFM.remained_rec["計量日"]))
             <<  NsField("拠点ID", N24TP::place_id)
             <<  NsField("伝票No", ToInt(SFM.remained_rec["伝票No"]))
             <<  NsField("行No",   0);

        DM->DBI.Delete("D_計量", keys);
    }

    if (!complete){     // 継続
        SFM.stash["新計量ID"] = keiryo_id;
    }else{              // 完了
        NsFieldSet keys;
        keys << NsField("計量日", old_date)
             << NsField("拠点ID", N24TP::place_id)
             << NsField("伝票No", old_no);

        // 計量日と伝票No, 伝票消費税は計量完了後に更新をかける
        int no = DM->GetNextKeiryoNo(date);
        fields.clear();
        fields << NsField("[計量日]",       date)
               << NsField("[伝票No]",       no)
               << NsField("[伝票消費税額]", DM->GetTotalSalesTax(ToInt(SFM.remained_rec["計量日"]), N24TP::place_id, ToInt(SFM.remained_rec["伝票No"])))
               << NsField("[完了区分]",     1);

        int cnt = DM->DBI.Update("D_計量", keys, fields);

        SFM.stash["新計量ID"] = DM->GetTopID(date, N24TP::place_id, no);

        CopyRecords(date, N24TP::place_id, no);
    }
}
//---------------------------------------------------------------------------
// 計量データを取引データへ
void __fastcall TConfirmWeighingStateForm::CopyRecords(int date, int place, int no)
{
    AnsiString sql = " SELECT * FROM D_計量"
                     " WHERE 計量日 = " + IntToStr(date) +
                     "   AND 拠点ID = " + IntToStr(place) +
                     "   AND 伝票No = " + IntToStr(no);
    NsRecordSet set, meig_set;
    NsFieldSet fields;

    if (!DM->DBI.GetRecordSet(sql, set))
        return;

    int tran_div;
    int tran_no = DM->GetTransNo(ToInt(SET_TOP(set)["計量日"]));
    TDateTime now(Now());
    for (unsigned int i = 0; i < set.size(); i++){
        sql = "SELECT 取引区分 FROM M_品目 WHERE 品目ID = " + IntToStr(ToInt(set[i]["品目ID"]));
        if (!DM->DBI.GetRecordSet(sql, meig_set))
            tran_div = 1;
        else
            tran_div = ToInt(SET_TOP(meig_set)["取引区分"]);

        fields.clear();
        fields
            << NsField("[取引日]",       set[i]["計量日"])
            << NsField("[拠点ID]",       set[i]["拠点ID"])
            << NsField("[伝票No]",       tran_no)
            << NsField("[計量ID]",       set[i]["計量ID"])
            << NsField("[取引区分]",     tran_div)
            << NsField("[車両ID]",       set[i]["車両ID"])
            << NsField("[得意先ID]",     set[i]["得意先ID"])
            << NsField("[得意先名称]",   set[i]["得意先名称"])
            << NsField("[項目1ID]",      set[i]["項目1ID"])
            << NsField("[項目1名称]",    set[i]["項目1名称"])
            << NsField("[項目2ID]",      set[i]["項目2ID"])
            << NsField("[項目2名称]",    set[i]["項目2名称"])
            << NsField("[備考]",         set[i]["備考"])
            << NsField("[伝票消費税額]", set[i]["伝票消費税額"])
            << NsField("[行No]",         set[i]["行No"])
            << NsField("[品目ID]",       set[i]["品目ID"])
            << NsField("[品目名称]",     set[i]["品目名称"])
            << NsField("[数量]",         set[i]["数量"])
            << NsField("[単位ID]",       set[i]["単位ID"])
            << NsField("[単価]",         set[i]["単価"])
            << NsField("[金額]",         set[i]["金額"])
            << NsField("[消費税額]",     set[i]["消費税額"])
            << NsField("[明細備考]",     set[i]["明細備考"])
            << NsField("[完了区分]",     set[i]["完了区分"])
            << NsField("[更新日時]",     now)
            << NsField("[作成日時]",     now)
            ;
        DM->DBI.Insert("D_取引", fields);
    }
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::MeigChangeButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::SelectMeig);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::CancelButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::WaitCard);
}
//---------------------------------------------------------------------------


