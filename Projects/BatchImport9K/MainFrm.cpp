//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include <memory>
#include <fstream>
#include <StrUtils.hpp>
#include <DateUtils.hpp>
#include "DMFrm.h"
#include "nsoftfunc.h"
#include "N95BatchThread.h"
#include "DivideDateFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner), thread_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 5;
    ProgressBar->Step     = 1;

	///////////////////////////////////////////////
	// データベースに接続

	if (!DM->Init())
		Close();

    port_ = ToInt(DM->INI["Batch::Port"]);
    def_  = ToString(DM->INI["Batch::Def"]);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ImportButtonClick(TObject *Sender)
{
    // 受信開始

    ImportButton->Enabled = false;
    CloseButton->Enabled  = false;

    received_rec_.clear();
    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 5;
    ProgressBar->Step     = 1;
    
    thread_ = new TN95BatchThread(false, port_, def_, Handle);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnCompleted(TMessage& message)
{
	StatusLabel->Caption = "完了しました";

    delete thread_;
    thread_ = 0;

	std::ofstream ofs("batchimport.log");
	for (unsigned int i = 0; i < received_rec_.size(); i++){
		ofs << received_rec_[i].c_str() << std::endl;
	}

    // 伝票番号抽出
    no_date_map_.clear();
    int no;
    int today = Now().FormatString("yyyymmdd").ToInt();
    for (unsigned int i = 0; i < received_rec_.size(); i++){
    	no = AnsiString(received_rec_[i].c_str()).SubString(9, 3).ToIntDef(0);
		no_date_map_[no] = today;
    }

    int r1from = 0, r1to = 0;
    int r2from = 0, r2to = 0;
    if (no_date_map_.find(999) != no_date_map_.end()){		// 999 を挟む

    	// 999 以下で最小の数を探す
    	for (int i = 999; i > 0; i--){
			if (no_date_map_.find(i) == no_date_map_.end())
            	break;
            r1from = i;
        }

		r1to   = 999;
        r2from = 1;

        // 1以上で最大の数を探す
        for (int i = 1; i < 1000; i++){
        	if (no_date_map_.find(i) == no_date_map_.end())
            	break;
            r2to = i;
        }
    }else{
    	r1from = no_date_map_.begin()->first;
        std::map <int, int>::iterator last = no_date_map_.end();
        last--;
        r1to   = last->first;
    }

    // 日付入力画面
    DivideDateForm->SetNoRange(r1from, r1to, r2from, r2to);
    if (DivideDateForm->ShowModal() != mrOk){
    	CloseButton->Enabled = true;
    	return;
    }

    // 伝票番号と日付の関連テーブル作成
    no_date_map_.clear();
    for (NRDates::iterator i = DivideDateForm->NoRangeDates.begin(); i != DivideDateForm->NoRangeDates.end(); i++){
    	for (int no = i->from; no <= i->to; no++){
        	no_date_map_[no] = i->date;
        }
    }

    // データコンバート
    for (unsigned int i = 0; i < received_rec_.size(); i++){
        PostRecord(received_rec_[i]);
    }

    Application->MessageBox("受信が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	CloseButton->Enabled = true;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::PostRecord(AnsiString record)
{
    AnsiString sql;

    TDateTime now(Now());

    int place_id = ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", ToInt(DM->INI["Place::Code"]), "拠点ID"));

    NsFieldSet fields, keys;
    NsRecordSet set;

    AnsiString buff = record;

    int car_no     = buff.SubString(14, 6).Trim().ToIntDef(0);

    buff = AnsiReplaceStr(record, " ", "0");

    int no         = buff.SubString( 9, 3).ToIntDef(0);
    int item1_code = buff.SubString(21, 3).ToIntDef(0);
    int item2_code = buff.SubString(25, 3).ToIntDef(0);
    int item3_code = buff.SubString(29, 3).ToIntDef(0);
    int item4_code = buff.SubString(33, 3).ToIntDef(0);
    int weight1    = buff.SubString(36, 8).ToIntDef(0);
    int hhnn1      = buff.SubString(44, 4).ToIntDef(0);
    int weight2    = buff.SubString(48, 8).ToIntDef(0);
    int hhnn2      = buff.SubString(56, 4).ToIntDef(0);
    int net        = buff.SubString(73, 7).ToIntDef(0);

    int date = no_date_map_[no];
    if (!date)
    	return false;

    keys.clear();
    keys << NsField("計量日", date)
         << NsField("拠点ID", place_id)
         << NsField("伝票No", no);

    if (DM->DBI.IsExist("D_計量", keys))
        return true;

    ////////////////////////////////////////////////////////////////////////////
    // 指示計と ScaM の項目割り当てマッピング
    std::map<int, int> cnv_table;   // map<AD4385項目, ScMマスタ>
    cnv_table[1] = ToInt(DM->CFG["指示計項目１"]);
    cnv_table[2] = ToInt(DM->CFG["指示計項目２"]);
    cnv_table[3] = ToInt(DM->CFG["指示計項目３"]);
    cnv_table[4] = ToInt(DM->CFG["指示計項目４"]);
    for (int i = 1; i <= 4; i++){
        if (cnv_table[i] < 1 || cnv_table[i] > 4)
            cnv_table[i] = 0;
    }

    std::map<int, int *> scm_codes;
    int dummy, scm_toku_cd, scm_item1_cd, scm_item2_cd, scm_meig_cd;
    scm_codes[0] = &dummy;
    scm_codes[1] = &scm_toku_cd;
    scm_codes[2] = &scm_item1_cd;
    scm_codes[3] = &scm_item2_cd;
    scm_codes[4] = &scm_meig_cd;

    *(scm_codes[cnv_table[1]]) = item1_code;
    *(scm_codes[cnv_table[2]]) = item2_code;
    *(scm_codes[cnv_table[3]]) = item3_code;
    *(scm_codes[cnv_table[4]]) = item4_code;

    ////////////////////////////////////////////////////////////////////////////
    // マスタ情報列挙
    int scm_toku_id, scm_item1_id, scm_item2_id, scm_meig_id;
    NsRecordSet toku_set, item1_set, item2_set, meig_set;

    sql = "SELECT * FROM V_得意先 WHERE 得意先コード = " + IntToStr(scm_toku_cd);
    if (DM->DBI.GetRecordSet(sql, toku_set))
        scm_toku_id = ToInt(SET_TOP(toku_set)["得意先ID"]);
    else
        scm_toku_id = 0;
    sql = "SELECT * FROM V_項目1 WHERE 項目1コード = " + IntToStr(scm_item1_cd);
    if (DM->DBI.GetRecordSet(sql, item1_set))
        scm_item1_id = ToInt(SET_TOP(item1_set)["項目1ID"]);
    else
        scm_item1_id = 0;
    sql = "SELECT * FROM V_項目2 WHERE 項目2コード = " + IntToStr(scm_item2_cd);
    if (DM->DBI.GetRecordSet(sql, item2_set))
        scm_item2_id = ToInt(SET_TOP(item2_set)["項目2ID"]);
    else
        scm_item2_id = 0;
    sql = "SELECT * FROM V_品目 WHERE 品目コード = " + IntToStr(scm_meig_cd);
    if (DM->DBI.GetRecordSet(sql, meig_set))
        scm_meig_id = ToInt(SET_TOP(meig_set)["品目ID"]);
    else
        scm_meig_id = 0;

    ////////////////////////////////////////////////////////////////////////////
    // 車両の検索（なければ作成）
    int car_id;
    sql = " SELECT 車両ID FROM M_車両 WHERE 車番 = " + IntToStr(car_no) + " AND 使用区分 = 1";
    if (DM->DBI.GetRecordSet(sql, set)){
        car_id = ToInt(SET_TOP(set)["車両ID"]);
    }else{
        fields.clear();
        fields << NsField("[車番]",     car_no)
               << NsField("[車両名称]", "受信時自動登録")
               << NsField("[使用区分]", 1)
               << NsField("[更新日時]", now)
               << NsField("[作成日時]", now);
        DM->DBI.Insert("M_車両", fields);
        car_id = DM->DBI.GetLastID();
    }

    ////////////////////////////////////////////////////////////////////////////
    // 計量日時の取得
    TDateTime time1 = EncodeDateTime(date / 10000, (date % 10000) / 100, date % 100, hhnn1 / 100, hhnn1 % 100, 0, 0);
    TDateTime time2 = EncodeDateTime(date / 10000, (date % 10000) / 100, date % 100, hhnn2 / 100, hhnn2 % 100, 0, 0);

    ////////////////////////////////////////////////////////////////////////////
    // 単位、数量、金額

    int tani_id   = DM->GetKanzanID(scm_toku_id, scm_meig_id);
    int tani_code = DM->DBI.Lookup("M_単位", "単位ID", tani_id, "単位コード");
	Currency net_ton = Currency(net) / Currency(1000);
	Currency quantity;
	Currency cnv_ratio = DM->GetKanzan(scm_toku_id, scm_meig_id, tani_id);

	int cnv_div = -1;
	if (!toku_set.empty()){
		if (!IsNull(SET_TOP(toku_set)["換算端数処理区分"]))
			cnv_div = ToInt(SET_TOP(toku_set)["換算端数処理区分"]);
	}
	if (cnv_div == -1)
		cnv_div = ToInt(DM->CFG["換算端数処理区分"]);

	if (cnv_ratio == 0){
		quantity = ExtendedRound(net_ton,             ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
	}else{
		quantity = ExtendedRound(net_ton / cnv_ratio, ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
	}

    if (quantity > ToCurrency(DM->CFG["上限m3数量"]) && tani_code == 2){
        quantity = ToCurrency(DM->CFG["上限m3数量"]);
    }

	Currency tanka    = DM->GetTanka(scm_toku_id, scm_meig_id, scm_item1_id, scm_item2_id, tani_id);

	int amount_div = -1;
	if (!toku_set.empty()){
		if (!IsNull(SET_TOP(toku_set)["金額端数処理区分"]))
			amount_div = ToInt(SET_TOP(toku_set)["金額端数処理区分"]);
	}
	if (amount_div == -1)
		amount_div = ToInt(DM->CFG["金額端数処理区分"]);

	int amount = ExtendedRound(quantity * tanka, 0, amount_div);

	Currency tax_rate = DM->GetSalesTax();			// 消費税率

	int tax_div = -1;
	if (!toku_set.empty()){
		if (!IsNull(SET_TOP(toku_set)["消費税端数処理区分"]))
			tax_div = ToInt(SET_TOP(toku_set)["消費税端数処理区分"]);
	}
	if (tax_div == -1)
		tax_div = ToInt(DM->CFG["消費税端数処理区分"]);

	int tax    = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

    AnsiString null;

    /////
    try{
    /////

    DM->ADOConnection->BeginTrans();

    fields.clear();
    fields << NsField("[計量日]",       date)
           << NsField("[拠点ID]",       place_id)
           << NsField("[伝票No]",       no)
           << NsField("[搬入出区分]",   scm_meig_id ? ToInt(SET_TOP(meig_set)["搬入出区分"]) : 0)
           << NsField("[車両ID]",       car_id)
           << NsField("[得意先ID]",     scm_toku_id)
           << NsField("[得意先名称]",   scm_toku_id ? ToString(SET_TOP(toku_set)["得意先名称"]) : null)
           << NsField("[項目1ID]",      scm_item1_id)
           << NsField("[項目1名称]",    scm_item1_id ? ToString(SET_TOP(item1_set)["項目1名称"]) : null)
           << NsField("[項目2ID]",      scm_item2_id)
           << NsField("[項目2名称]",    scm_item2_id ? ToString(SET_TOP(item2_set)["項目2名称"]) : null)
           << NsField("[行No]",         1)
           << NsField("[品目ID]",       scm_meig_id)
           << NsField("[品目名称]",     scm_meig_id ? ToString(SET_TOP(meig_set)["品目名称"]) : null)
           << NsField("[1回目重量]",    weight1)
           << NsField("[計量日時1]",    time1)
           << NsField("[2回目重量]",    weight2)
           << NsField("[計量日時2]",    time2)
           << NsField("[正味重量]",     net)
           << NsField("[数量]",         quantity)
           << NsField("[単位ID]",       tani_id)
           << NsField("[単価]",         tanka)
           << NsField("[金額]",         amount)
           << NsField("[伝票消費税額]", tax)
           << NsField("[消費税額]",     tax)
           << NsField("[完了区分]",     1)
           << NsField("[更新日時]",     now)
           << NsField("[作成日時]",     now)
           ;

    DM->DBI.Insert("D_計量", fields);

    int keiryo_id = DM->DBI.GetLastID();

    // 取引データ作成
    keys.clear();
    keys << NsField("取引日", date)
         << NsField("拠点ID", place_id)
         << NsField("伝票No", no);

    if (!DM->DBI.IsExist("D_取引", keys)){
        fields.clear();
        fields << NsField("[取引日]",       date)
               << NsField("[拠点ID]",       place_id)
               << NsField("[伝票No]",       no)
               << NsField("[計量ID]",       keiryo_id)
               << NsField("[取引区分]",     ToInt(DM->DBI.Lookup("M_品目", "品目ID", scm_meig_id, "取引区分")))
               << NsField("[車両ID]",       car_id)
               << NsField("[得意先ID]",     scm_toku_id)
               << NsField("[得意先名称]",   scm_toku_id ? ToString(SET_TOP(toku_set)["得意先名称"]) : null)
               << NsField("[項目1ID]",      scm_item1_id)
               << NsField("[項目1名称]",    scm_item1_id ? ToString(SET_TOP(item1_set)["項目1名称"]) : null)
               << NsField("[項目2ID]",      scm_item2_id)
               << NsField("[項目2名称]",    scm_item2_id ? ToString(SET_TOP(item2_set)["項目2名称"]) : null)
               << NsField("[行No]",         1)
               << NsField("[品目ID]",       scm_meig_id)
               << NsField("[品目名称]",     scm_meig_id ? ToString(SET_TOP(meig_set)["品目名称"]) : null)
               << NsField("[数量]",         quantity)
               << NsField("[単位ID]",       tani_id)
               << NsField("[単価]",         tanka)
               << NsField("[金額]",         amount)
               << NsField("[伝票消費税額]", tax)
               << NsField("[消費税額]",     tax)
               << NsField("[完了区分]",     1)
               << NsField("[更新日時]",     now)
               << NsField("[作成日時]",     now)
               ;

        DM->DBI.Insert("D_取引", fields);
    }

    DM->ADOConnection->CommitTrans();
    /////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "データ登録時にエラーが発生しました - " + e.Message;
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }
    /////
    return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnAborted(TMessage& message)
{
    Application->MessageBox("データ受信に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);

    ImportButton->Enabled = true;
	CloseButton->Enabled = true;

    delete thread_;
    thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnStatus(TMessage& message)
{
	StatusLabel->Caption = (LPCSTR)(message.LParam);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnDataReceived(TMessage& message)
{
	received_rec_.push_back((LPCSTR)(message.LParam));
	CountLabel->Caption = IntToStr(received_rec_.size());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnProcessStep(TMessage& message)
{
    ProgressBar->StepIt();
}
//---------------------------------------------------------------------------

