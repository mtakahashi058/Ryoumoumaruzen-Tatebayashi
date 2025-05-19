//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "DMFrm.h"
#include "ErrorFrm.h"    
#include "NotifyFrm.h"
#include "DotSlipPrintFrm.h"                       
#include "LaserSlipPrintFrm.h"                    
#include "DisplayFrm.h"
#include "SystemID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TSCPostForm *SCPostForm;
//---------------------------------------------------------------------------
__fastcall TSCPostForm::TSCPostForm(TComponent* Owner)
    : TForm(Owner), cur_weight_(0), old_weight_(0), cur_wi_status_(wsOther),
        rfid_thread_(0), fbi_handle_(INVALID_HANDLE_VALUE), out_channels_(16), dio_thread_(0),
        last_card_no_(0), rfid_error_(false), wi_error_(false)
{
    cur_weight_     = 0;
	old_weight_     = 0;
	on_weighing_    = false;
	reversed_       = false;
	on_error_       = false;
	limit_over_     = false;
	on_printing_    = false;
	on_wait_exit_   = false;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::FormCreate(TObject *Sender)
{
    Caption = "SC操作ポスト制御";

	///////////////////////////////////////////////
	// データベースに接続[INI]

	if (!DM->Init()){
		PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }

	///////////////////////////////////////////////
	// DIOボードに接続

    // 排他の場合
    // fbi_handle_ = DioOpen(ToString(DM->INI["FBIDIO::Device"]).c_str(), 0);
    // 共有

    if (ToString(DM->INI["FBIDIO::Device"]).IsEmpty()){
    }else{
        fbi_handle_ = DioOpen(ToString(DM->INI["FBIDIO::Device"]).c_str(), FBIDIO_FLAG_SHARE);
        if (fbi_handle_ == INVALID_HANDLE_VALUE){
            Application->MessageBox("DIOデバイスのオープンに失敗しました", Caption.c_str(), MB_OK | MB_ICONSTOP | MB_TOPMOST);
    		PostMessage(Handle, WM_CLOSE, 0, 0);
            return;
        }
    }

	//ApplyConfig();

    ThreadCreateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ThreadCreateTimerTimer(TObject *Sender)
{
    ThreadCreateTimer->Enabled = false;

    place_id_ = ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", ToInt(DM->INI["Place::Code"]), "拠点ID"));
    if (place_id_ < 1){
        Application->MessageBox("拠点情報が正しくありません", "計量設定エラー", MB_OK | MB_ICONSTOP | MB_TOPMOST);
        Close();
        return;
    }

    NotifyForm->Sound = notify_sound_;

	///////////////////////////////////////////////
	// RFID 通信スレッドの作成 [INI]

    int rfid_port = ToInt(DM->INI["RFID::WeighingCommPort"]);
	rfid_thread_  = new THF04Thread(true, Handle, rfid_port);
    rfid_thread_->FreeOnTerminate = false;
    rfid_thread_->Resume();

    ///////////////////////////////////////////////
    // DIO スレッドの作成

    if (fbi_handle_ != INVALID_HANDLE_VALUE){
        dio_thread_ = new TFbiDioThread(true, Handle, fbi_handle_);
        dio_thread_->FreeOnTerminate = false;
        dio_thread_->Resume();
    }

	///////////////////////////////////////////////
	// 重量受信
	try{
		// [INI] Weighing::WIPort
		ClientSocket->Port = ToInt(DM->INI["Weighing::WIPort"]);
		// [INI] Weighing::WIServer                                                                                                                 
		ClientSocket->Host = ToString(DM->INI["Weighing::WIServer"]);

		if (ClientSocket->Active)
			ClientSocket->Close();
		ClientSocket->Open();

	}catch(Exception& e){
		AnsiString msg = "TCP/IP通信ができません: \r\n" + e.Message;
		Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONSTOP | MB_TOPMOST);

        wi_error_ = true;
        UpdateWeighingState();
	}
	SocketReopenTimer->Enabled = true;

    weighing_border_ = ToInt(DM->INI["Weighing::SoundBorder"]);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (dio_thread_){
        out_channels_.SetWord(0);
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
        Sleep(500);
    }
    if (dio_thread_)
        dio_thread_->Terminate();
    if (dio_thread_)
        dio_thread_->WaitFor();
    if (dio_thread_)
        delete dio_thread_;

	if (rfid_thread_)
		rfid_thread_->Terminate();
	if (rfid_thread_)
		rfid_thread_->WaitFor();
	if (rfid_thread_)
		delete rfid_thread_;

    if (fbi_handle_ != INVALID_HANDLE_VALUE)
        DioClose(fbi_handle_);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("制御を終了させると、操作ポストが一切使用できなくなります\r\n"
                                "よろしいですか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST)
                == IDYES){
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::SocketReopenTimerTimer(TObject *Sender)
{
	if (ClientSocket->Active)
		return;

	try{
		// [INI] Weighing::WIPort
		ClientSocket->Port = ToInt(DM->INI["Weighing::WIPort"]);
		// [INI] Weighing::WIServer
		ClientSocket->Host = ToString(DM->INI["Weighing::WIServer"]);

		ClientSocket->Open();
	}catch(Exception& e){
		//AnsiString msg = "TCP/IP通信ができません: \r\n" + e.Message;
		//Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONINFORMATION);
		;
        wi_error_ = true;
        UpdateWeighingState();
	}
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ClientSocketError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
/*
	switch (ErrorEvent){
	case eeReceive:
		StatusBar->SimpleText = "重量値受信: 受信エラー";
		break;
	case eeConnect:
		StatusBar->SimpleText = "重量値受信: 接続エラー";
		break;
	case eeDisconnect:
		StatusBar->SimpleText = "重量値受信: 切断エラー";
		break;
	default:
		StatusBar->SimpleText = "重量値受信: ソケットエラー";
		break;
	};
*/
	ClientSocket->Close();
    old_weight_ = 0;
    cur_weight_ = 0;
    OnExitWeighing(0);

    wi_error_ = true;
    UpdateWeighingState();

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
	int index;
	AnsiString weight = Socket->ReceiveText();

	int len = weight.Length();
	if (len < 4)					return;
	if (weight[len - 1] != '\r')	return;
	if (weight[len] != '\n')		return;
	switch (weight[1]){
	case 'S':	cur_wi_status_ = wsStable;      break;
	case 'U':	cur_wi_status_ = wsUnstable;    break;
	case 'O':	cur_wi_status_ = wsOther;       break;
	default:
		return;
	}

	weight.Delete(1, 1);	// ステータスキャラクタの削除
	weight.Delete(weight.Length() - 1, 2);	// 末尾の \r\n を削除
	Currency tmp_weight;
	try{
		tmp_weight = Currency(weight);
	}catch(...){return;}

    wi_error_ = false;
    UpdateWeighingState();

	old_weight_ = cur_weight_;
	cur_weight_ = tmp_weight;

	if (old_weight_ < weighing_border_ && cur_weight_ >= weighing_border_){
        on_weighing_ = true;
        OnEnterWeighing(0);
	}else if ((old_weight_ >= weighing_border_) && (cur_weight_ < weighing_border_)){
        on_weighing_ = false;
        OnExitWeighing(0);
    }
}
//---------------------------------------------------------------------------
/**
 * Implementation of Weighing Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnEnterWeighing(int tag)
{
	/*** 計量開始(スケール負荷) ***/

    /*
    // [INI]
    out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOn;
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
    */
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnExitWeighing(int tag)
{
	/*** 計量終了(降車) ***/

    if (DisplayForm->Visible)
        DisplayForm->Close();

    out_channels_.SetWord(0);
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
        
    UpdateWeighingState();

	on_wait_exit_ = false;	// 退車待ち状態をクリア
    last_card_no_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnDIOStatus(TMessage& message)
{
    AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    DM->Log("SCPOST(DIO)", status, 1);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnDIOInput(TMessage& message)
{
    DM->Log("SCPOST(DIO)", "入力検知", 0);

    Channels channels(16);
    channels.SetWord(message.LParam);

    // [INI]
    if (channels[ToInt(DM->INI["FBIDIO::CallInCh"])] == chOn){
        OnCallButtonDown();
    }
    if (channels[ToInt(DM->INI["FBIDIO::ResetInCh"])] == chOn){
        OnResetButtonDown();
    }
    if (channels[ToInt(DM->INI["FBIDIO::ConfirmInCh"])] == chOn){
        OnConfirmButtonDown();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnConfirmButtonDown()
{
    out_channels_[ToInt(DM->INI["FBIDIO::ExitOutCh"])]  = chOff;
    out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOff;
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

    if (last_card_no_ < 1){
        DM->Log("SCPOST", "カード無しで確認ボタン押下", 1);

        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
        return;
    }

    int card_no = last_card_no_;

	if (!on_weighing_)
		return;
	if (on_printing_)
		return;
	if (on_wait_exit_)
		return;
	if (on_error_)
		return;

    ////////// 安定を待つ
	{
		// 安定信号を待つ
		DWORD start = GetTickCount();
		DWORD now;
		while (cur_wi_status_ != wsStable){
			Sleep(0);
			Application->ProcessMessages();
			now = GetTickCount();
			if (int(now - start) >= 1000)
				break;
		}
		if (cur_weight_ < weighing_border_)
			return;
	}

    AnsiString sql;
	TDateTime now(Now());
	int date = now.FormatString("yyyymmdd").ToInt();
    bool print = false;

	int toku_cd, item1_cd, item2_cd, meig_cd;
	int toku_id, item1_id, item2_id, meig_id, tani_id;
	NsRecord toku_rec, item1_rec, item2_rec, meig_rec;

	int car_no, keiryo_no, keiryo_id;
    int max_detail_count;

    int cmp_kbn = 0;

    //////////
    try{
    //////////

    // 車両情報取得
    NsRecord    card_rec;
    if (!DM->GetCardInfo(card_no, card_rec)){
        DM->Log("SCPOST", "未登録車両による計量中止（カード番号:" + IntToStr(card_no) + "）", 1);
        NotifyForm->Notify("未登録車両です: " + IntToStr(card_no), false, 10000);;

		// on_error_ = true;

        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
        Sleep(1000);
        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOff;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

    	return;
	}

    max_detail_count = ToInt(card_rec["品目件数"]);

    car_no   = ToInt(card_rec["車番"]);

    ///// 優先度（低）カード情報
    toku_id  = ToInt(card_rec["得意先ID"]);
    meig_id  = ToInt(card_rec["品目ID"]);
    item1_id = ToInt(card_rec["項目1ID"]);
    item2_id = ToInt(card_rec["項目2ID"]);
    DM->GetViewRec("得意先", toku_id,  toku_rec);
    DM->GetViewRec("品目",   meig_id,  meig_rec);
    DM->GetViewRec("項目1",  item1_id, item1_rec);
    DM->GetViewRec("項目2",  item2_id, item2_rec);

    if (cur_weight_ > ToCurrency(card_rec["車両総重量"]) && ToCurrency(card_rec["車両総重量"]) > 0){
        DM->Log("SCPOST", "車両総重量に対する過積載（車番:" + IntToStr(car_no) + "）", 1);
        NotifyForm->Notify("車両総重量に対する過積載です: " + IntToStr(car_no), false, 30000);

  		on_error_ = true;

        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::OverOutCh"])]  = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

   		return;
    }
    
   	NsFieldSet fields;

  	fields
        << NsField("[計量日]",     date)
        << NsField("[拠点ID]",     place_id_)
        << NsField("[行No]",       1)
        << NsField("[車両ID]",     ToInt(card_rec["車両ID"]))
        << NsField("[得意先ID]",   toku_id)
		<< NsField("[得意先名称]", ToString(toku_rec["得意先名称"]))
        << NsField("[項目1ID]",    item1_id)
        << NsField("[項目1名称]",  ToString(item1_rec["項目1名称"]))
        << NsField("[項目2ID]",    item2_id)
        << NsField("[項目2名称]",  ToString(item2_rec["項目2名称"]))
        << NsField("[品目ID]",     meig_id)
        << NsField("[品目名称]",   ToString(meig_rec["品目名称"]))
        << NsField("[搬入出区分]", ToInt(meig_rec["搬入出区分"]))
        << NsField("[更新日時]",   now)
       	;

    DM->ADOConnection->BeginTrans();

    Currency tare_w = ToCurrency(card_rec["空車重量"]);
    int remained_id = DM->GetRemainedKeiryoID(place_id_, ToInt(card_rec["車両ID"]));

    if (!remained_id && tare_w < 1){
		// 一回目計量かつ一回計量でない場合 → 一回目計量／二回計量

        print = false;

		keiryo_no = DM->GetTempNo(place_id_);

		fields << NsField("[伝票No]",    keiryo_no)
			   << NsField("[1回目重量]", cur_weight_)
			   << NsField("[計量日時1]", now)
			   << NsField("[完了区分]",  0)
			   << NsField("[作成日時]",  now)
			   ;
        cmp_kbn = 0;

	}else{
		print = true;

		Currency weight1, weight2, net;
		int tani_code = DM->GetKanzanCode(toku_id, meig_id);
		tani_id   = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tani_code, "単位ID"));

		if (remained_id){
			// 二回目計量

			NsRecordSet remained_set;
			if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(remained_id), remained_set)){

				DM->Log("SCPOST", "滞留データ抽出失敗（車番:" + IntToStr(car_no) + "）", 2);
				NotifyForm->Notify("滞留データの呼び出しに失敗しました:" + IntToStr(car_no), false, 10000);

				on_error_ = true;

                //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
                out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
                if (dio_thread_)
                    PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
				return;
			}

			weight1 = ToCurrency(SET_TOP(remained_set)["1回目重量"]);
			weight2 = cur_weight_;

		}else{
			// 一回計量

			fields << NsField("[1回目重量]", tare_w)
				   //<< NsField("[計量日時1]", )    // 一回計量じゃけぇ計量日時1はなし
				   ;

			weight1 = tare_w;
			weight2 = cur_weight_;
		}

		net = weight1 - weight2;
		if (net < 1) net *= -1;

		if (net > ToCurrency(card_rec["最大積載量"]) && ToCurrency(card_rec["最大積載量"]) > 0){
			DM->Log("SCPOST", "最大積載量に対する過積載（車番:" + IntToStr(car_no) + "）", 1);
			NotifyForm->Notify("最大積載量に対する過積載です: " + IntToStr(car_no), false, 30000);

			on_error_ = true;

            //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
            out_channels_[ToInt(DM->INI["FBIDIO::OverOutCh"])]  = chOn;
            out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOff;
            out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOn;
            if (dio_thread_)
                PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
            
            DM->ADOConnection->RollbackTrans();

			return;
		}

		keiryo_no = DM->GetKeiryoNo(place_id_, date);

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

        ReplaceSetField(fields, "[伝票No]",   keiryo_no);
        ReplaceSetField(fields, "[完了区分]", 1);

		fields << NsField("[2回目重量]", weight2)
			   << NsField("[計量日時2]", now)
	    	   << NsField("[調整率]",    adj_per)
               << NsField("[調整重量]",  adj_weight)
			   << NsField("[正味重量]",  net)
			   << NsField("[単位ID]",    tani_id)
			   ;

        cmp_kbn = 1;

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

        fields << NsField("[数量]", quantity);

       	if (ToBit(DM->CFG["単価使用区分"])){

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
                   << NsField("[伝票消費税額]", tax)
                   ;
       	}
    }

    if (remained_id){
        // 二回目計量

        DM->DBI.Update("D_計量", "計量ID", remained_id, fields);

        DM->Log("SCPOST", "計量完了（車番:" + IntToStr(car_no) + "）", 0);

        keiryo_id = remained_id;

    }else{
        // 一回目計量または一回計量

        DM->DBI.Insert("D_計量", fields);

		if (tare_w < 1){
			DM->Log("SCPOST", "一回目計量完了（車番:" + IntToStr(car_no) + "）", 0);

            keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}else{
			// 一回計量により計量完了
			DM->Log("SCPOST", "一回計量完了（車番:" + IntToStr(car_no) + "）", 0);

			keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}
	}

    DM->ADOConnection->CommitTrans();

    //////////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        DM->Log("SCPOST", AnsiString("登録時例外（カード番号:") + IntToStr(card_no) + "）: " + e.Message, 2);
        NotifyForm->Notify("登録時にエラーが発生しました:" + IntToStr(card_no), false, 10000);

		on_error_ = true;

        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::ErrorOutCh"])] = chOn;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

		return;
    }
    //////////

    if (cmp_kbn == 1){       // 計量完了
        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::ExitOutCh"])]  = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOff;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
    }else{                   //
        //out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
        out_channels_[ToInt(DM->INI["FBIDIO::ExitOutCh"])] = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatOkOutCh"])] = chOn;
        out_channels_[ToInt(DM->INI["FBIDIO::PatNgOutCh"])] = chOff;
        if (dio_thread_)
            PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
    }

    DisplayForm->ShowRecord(keiryo_id);

	if (print){
		PrintKeiryoData(0, keiryo_id);

        int print_copy = ToInt(DM->CFG["自動計量時控え伝票発行"]);
        if (print_copy)
            PrintCopy(keiryo_id);
    }

	on_wait_exit_ = true;	// 退車待ち状態
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnResetButtonDown()
{
	ForceWeighing(0);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnCallButtonDown()
{
    ErrorForm->TitlePanel->Caption = "計量操作ポストで呼び出しがありました";
    ErrorForm->TextMemo->Lines->Clear();
    ErrorForm->TextMemo->Lines->Text = "\r\n"
                                       "対応しましたら【閉じる】ボタンをクリックしてください。";
    ErrorForm->ShowModal();
}
//---------------------------------------------------------------------------
/**
 * Implementation of RFID Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
	// Application->MessageBox("RFIDユニットとの通信ができません", Caption.c_str(),
	//		MB_OK | MB_ICONINFORMATION);


    if (!ErrorForm->Visible){
        ErrorForm->TitlePanel->Caption = "RFIDリーダとの通信ができません";
        ErrorForm->TextMemo->Lines->Clear();
        ErrorForm->TextMemo->Lines->Text = "RFIDリーダが使用できないため、通信が行えません。\r\n"
                                           "\r\n"
                                           "ScaleManger 設定情報が変更された可能性があります。\r\n"
                                           "また、配線の変更等でも発生する場合があります。\r\n"
                                           "\r\n"
                                           "PC を再起動しても問題が解消しない場合は、お問い合わせください。";
        ErrorForm->ShowModal();
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    bool is_fatal = message.WParam;

    DM->Log("SCPOST(RFID)", status, is_fatal ? 2 : 1);

    if (is_fatal)
        NotifyForm->Notify(AnsiString("RFIDリーダ:" + status), true, 20000);
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnRFIDTimeout(TMessage& message)
{
    rfid_error_ = static_cast<bool>(message.WParam);
    UpdateWeighingState();
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;
    int card_no = message.LParam;

	/*** カード検知 ***/

    // 認証チェック
    if (!is_valid){
        DM->Log("SCPOST", "カード認証エラー", 1);
        NotifyForm->Notify("システム外のカードを検知しました", false, 10000);
        return;
    }
    // 制御カードチェック
    if (card_no >= RFID::ADMIN_CARDS_ID){
        DM->Log("SCPOST", "制御用カード検知", 1);
        NotifyForm->Notify("制御用カードはこのシステムで使用できません", false, 10000);
        return;
    }

    DM->Log("SCPOST", "カード検知", 0);

    last_card_no_ = card_no;

    out_channels_[ToInt(DM->INI["FBIDIO::ComplOutCh"])] = chOn;
    if (dio_thread_)
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));

    //if (ToInt(DM->INI["FBIDIO::UseButton"]) == 0){
    if (dio_thread_ == 0){
        // ポストのボタンを使用しない設定の場合、このまま計量に進む
        OnConfirmButtonDown();
    }
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::PrintKeiryoData(int tag, int keiryo_id)
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
	if (!DM->DBI.GetRecordSet(sql, set))
		return;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::PrintCopy(int keiryo_id)
{
	int slip_type   = ToInt(DM->CFG["伝票発行プリンタ"]);

    /***************************************************/
    /* 注意： 控え伝票の場合は、手入力のほうの時間印字設定を見ている */

    bool print_time = ToBit(DM->CFG["時間印字初期区分"]);

	if (slip_type == 1){
		// レーザー

		if (!LaserSlipPrintForm->Print(keiryo_id, !print_time))
			return;

	}else if (slip_type == 2){
		// ドット

        if (!DotSlipPrintForm->Print(keiryo_id, !print_time))
            return;

	}else{
		// nothing to do
	}
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::ForceWeighing(int tag)
{
	OnExitWeighing(0);
	cur_weight_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TSCPostForm::UpdateWeighingState()
{
    CH_STATUS old;

    old = out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])];

    if (wi_error_ || rfid_error_){
        out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOff;
    }else{
        out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])] = chOn;
    }

    if (dio_thread_ && old != out_channels_[ToInt(DM->INI["FBIDIO::ReadyOutCh"])])
        PostThreadMessage(dio_thread_->ThreadID, DIOM_OUTPUT, 0, LPARAM(&out_channels_));
}
//---------------------------------------------------------------------------

