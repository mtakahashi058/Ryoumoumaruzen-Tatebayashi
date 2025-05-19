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

NsRecordSet global_set;

TEtherPostForm *EtherPostForm;
//---------------------------------------------------------------------------
__fastcall TEtherPostForm::TEtherPostForm(TComponent* Owner)
	: TForm(Owner), cur_weight_(0), old_weight_(0), cur_wi_status_(wsOther), io_thread_(0),
		rfid_thread_(0), last_card_no_(0), printer_thread_(0), rfid_error_(false), wi_error_(false)
{
	cur_weight_     = 0;
	old_weight_     = 0;
	on_weighing_    = false;
	reversed_       = false;
	on_error_       = false;
	limit_over_     = false;
	on_printing_    = false;
	on_wait_exit_   = false;

	ready_sw_    = chOff;
	card_sw_     = chOff;
	exit_sw_     = chOff;
	overload_sw_ = chOff;
	buzzer_sw_   = chOff;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::FormCreate(TObject *Sender)
{
	Caption = "操作ポスト制御";

	///////////////////////////////////////////////
	// データベースに接続[INI]

	if (!DM->Init()){
		PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }

	/*
	///////////////////////////////////////////////
	// IO
	try{
		IO_.SetHandler(OnIOInput, OnIOResponse, OnIOError);
		IO_.Open(ToString(DM->INI["IO::Address"]));
	}catch(Exception& e){
		Application->MessageBox(("IOユニットに接続できません - " + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP | MB_TOPMOST);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	*/

	//ApplyConfig();



    ThreadCreateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::ThreadCreateTimerTimer(TObject *Sender)
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
	// DIOM 通信スレッドの作成 [INI]

	io_thread_  = new TioMirrorThread(true, Handle, ToString(DM->INI["IO::Address"]));
	io_thread_->FreeOnTerminate = false;
	io_thread_->Resume();

	///////////////////////////////////////////////
	// RFID 通信スレッドの作成 [INI]

	int rfid_port = ToInt(DM->INI["RFID::WeighingCommPort"]);
	rfid_thread_  = new THF04Thread(true, Handle, rfid_port);
    rfid_thread_->FreeOnTerminate = false;
    rfid_thread_->Resume();

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

	int port;

	///////////////////////////////////////////////
	// NP3411
	port = ToInt(DM->INI["OuterPrinter::Port"]);
    cfginfo_.customer = DM->TrimSpace(ToString(DM->CFG["得意先マスタ名称"]));
    cfginfo_.items    = DM->TrimSpace(ToString(DM->CFG["品目マスタ名称"]));
    cfginfo_.item1    = DM->TrimSpace(ToString(DM->CFG["項目1マスタ名称"]));
    cfginfo_.item2    = DM->TrimSpace(ToString(DM->CFG["項目2マスタ名称"]));
    cfginfo_.use_toku  = ToBit(DM->CFG["得意先マスタ使用区分"]);
    cfginfo_.use_items = ToBit(DM->CFG["品目マスタ使用区分"]);
    cfginfo_.use_item1 = ToBit(DM->CFG["項目1マスタ使用区分"]);
    cfginfo_.use_item2 = ToBit(DM->CFG["項目2マスタ使用区分"]);
	if (port){                               
		printer_thread_ = new TNP3411Thread(false, port, ToString(DM->INI["OuterPrinter::Def"]), Handle, cfginfo_, ToInt(DM->INI["OuterPrinter::PrintCopy"]));
	}else{
		Application->MessageBox("外部プリンタとの通信は停止しています", "重量表示器", MB_OK | MB_ICONWARNING);
	}

	///////////////////////////////////////////////
	// 重量表示器
	port = ToInt(DM->INI["F0399::Port"]);
	if (port){
		if (!indicator_.Initialize(port))
			Application->MessageBox("重量表示器との通信が開始できません", "重量表示器", MB_OK | MB_ICONWARNING);
	}else{
		Application->MessageBox("重量表示器との通信は停止しています", "重量表示器", MB_OK | MB_ICONWARNING);
	}
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (indicator_.IsActive())
		indicator_.Display(" ");

	if (io_thread_)
		io_thread_->Terminate();
	if (io_thread_)
		io_thread_->WaitFor();
	if (io_thread_)
		delete io_thread_;


	if (printer_thread_)
		printer_thread_->Terminate();
	if (printer_thread_)
		printer_thread_->WaitFor();
	if (printer_thread_)
		delete printer_thread_;

	if (rfid_thread_)
		rfid_thread_->Terminate();
	if (rfid_thread_)
		rfid_thread_->WaitFor();
	if (rfid_thread_)
		delete rfid_thread_;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnEndSession(TMessage& message)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("制御を終了させると、操作ポストが一切使用できなくなります\r\n"
                                "よろしいですか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST)
                == IDYES){
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::SocketReopenTimerTimer(TObject *Sender)
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
void __fastcall TEtherPostForm::ClientSocketError(TObject *Sender,
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
    OnExitWeighing();

    wi_error_ = true;
    UpdateWeighingState();

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::ClientSocketRead(TObject *Sender,
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

	if (indicator_.IsActive())
		indicator_.Display(IntToStr(cur_weight_).c_str());

	if (old_weight_ < weighing_border_ && cur_weight_ >= weighing_border_){
		OnEnterWeighing();
	}else if ((old_weight_ >= weighing_border_) && (cur_weight_ < weighing_border_)){
		OnExitWeighing();
	}
}
//---------------------------------------------------------------------------
/**
 * Implementation of Weighing Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnEnterWeighing()
{
	/*** 計量開始(スケール負荷) ***/

	on_weighing_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnExitWeighing()
{
	/*** 計量終了(降車) ***/

	if (DisplayForm->Visible)
		DisplayForm->Close();

	card_sw_     = chOff;
	exit_sw_     = chOff;
	overload_sw_ = chOff;
	buzzer_sw_   = chOff;
	OutputCh();

	on_weighing_  = false;
	on_wait_exit_ = false;	// 退車待ち状態をクリア
	last_card_no_ = 0;
    on_error_ = false;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::PostWeighing()
{
    if (last_card_no_ < 1){
        DM->Log("操作ポスト", "カード無しで確認ボタン押下", 1);

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

	int cmp_kbn = 0;

	//////////
	try{
	//////////

	// 車両情報取得
	NsRecord    card_rec;
	if (!DM->GetCardInfo(card_no, card_rec)){
		DM->Log("操作ポスト", "未登録車両による計量中止（カード番号:" + IntToStr(card_no) + "）", 1);
		NotifyForm->Notify("未登録車両です: " + IntToStr(card_no), false, 10000);;

		// 車両を載せたままでも問題ないため、エラー扱いとはしない
		// on_error_ = true;
		return;
	}

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
        DM->Log("操作ポスト", "車両総重量に対する過積載（車番:" + IntToStr(car_no) + "）", 1);
        NotifyForm->Notify("車両総重量に対する過積載です: " + IntToStr(car_no), false, 30000);

		on_error_     = true;
		on_wait_exit_ = true;

		overload_sw_ = true;
		buzzer_sw_   = true;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = false;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = true;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = false;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = true;
		OutputCh();

		Sleep(200);
		buzzer_sw_   = false;
		OutputCh();

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

				DM->Log("操作ポスト", "滞留データ抽出失敗（車番:" + IntToStr(car_no) + "）", 2);
				NotifyForm->Notify("滞留データの呼び出しに失敗しました:" + IntToStr(car_no), false, 10000);

				on_error_ = true;

				buzzer_sw_   = true;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = false;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = true;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = false;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = true;
				OutputCh();

				Sleep(200);
				buzzer_sw_   = false;
				OutputCh();

				return;
			}

			weight1 = ToCurrency(SET_TOP(remained_set)["1回目重量"]);
			weight2 = cur_weight_;

		}else{
			// 一回計量

			fields << NsField("[1回目重量]", tare_w)
                   << NsField("[作成日時]",  now)
				   //<< NsField("[計量日時1]", )    // 一回計量じゃけぇ計量日時1はなし
				   ;

			weight1 = tare_w;
			weight2 = cur_weight_;
		}

		net = weight1 - weight2;
		if (net < 1) net *= -1;

		if (net > ToCurrency(card_rec["最大積載量"]) && ToCurrency(card_rec["最大積載量"]) > 0){
			DM->Log("操作ポスト", "最大積載量に対する過積載（車番:" + IntToStr(car_no) + "）", 1);
			NotifyForm->Notify("最大積載量に対する過積載です: " + IntToStr(car_no), false, 30000);

			on_error_     = true;
			on_wait_exit_ = true;

			overload_sw_ = true;
			OutputCh();

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

        DM->Log("操作ポスト", "計量完了（車番:" + IntToStr(car_no) + "）", 0);

        keiryo_id = remained_id;

    }else{
		// 一回目計量または一回計量

        DM->DBI.Insert("D_計量", fields);

		if (tare_w < 1){
			DM->Log("操作ポスト", "一回目計量完了（車番:" + IntToStr(car_no) + "）", 0);

            keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}else{
			// 一回計量により計量完了
			DM->Log("操作ポスト", "一回計量完了（車番:" + IntToStr(car_no) + "）", 0);

			keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
		}
	}

    DM->ADOConnection->CommitTrans();

    //////////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        DM->Log("操作ポスト", AnsiString("登録時例外（カード番号:") + IntToStr(card_no) + "）: " + e.Message, 2);
        NotifyForm->Notify("登録時にエラーが発生しました:" + IntToStr(card_no), false, 10000);

		on_error_ = true;

		// todo error

		return;
    }
    //////////

	if (cmp_kbn == 1){       // 計量完了
	}else{                   //
	}

	on_wait_exit_ = true;	// 退車待ち状態

	DisplayForm->ShowRecord(keiryo_id);

    // PrintCopyが0のときは伝票出力を行わない
    int use_print = ToInt(DM->INI["OuterPrinter::PrintCopy"]);

	if (print && use_print){
   		PrintKeiryoData(keiryo_id);

		int print_copy = ToInt(DM->CFG["自動計量時控え伝票発行"]);
		if (print_copy)
			PrintCopy(keiryo_id);
	}

	card_sw_   = false;
	exit_sw_   = true;
	buzzer_sw_ = true;
	OutputCh();

	BuzzerSwitchTimer->Interval = 1000;
	BuzzerSwitchTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnConfirmButton()
{
	DM->Log("DEBUG", "確認ボタン", 1);

	if (last_card_no_)
	    PostWeighing();
	else
		DM->Log("操作ポスト", "カード無しで確認ボタン押下", 1);
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnResetButton()
{
	DM->Log("DEBUG", "リセットボタン", 1);


	ForceWeighing();
}
//---------------------------------------------------------------------------
/**
 * Implementation of NP3411 Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UMNiiAborted(TMessage& message)
{
	Application->MessageBox("外部プリンタの使用ができません", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("外部プリンタ", "通信停止", 2);

	delete printer_thread_;
	printer_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UMNiiStatus(TMessage& message)
{
	NiiStatus status(*(reinterpret_cast<NiiStatus *>(message.LParam)));

    /*
        NiiStatus
        - comm_error
        - status
        - message

        status = -2
        プリンタステータスを取得できません
        印字中も取得するためmdbの容量節約のため非表示処理

    */

	if (status.comm_error){
	   DM->Log("外部プリンタ", status.message, 1);
	}else if (status.status == -1){
       DM->Log("外部プリンタ", status.message, 1);
    }else{
        BF8 bf8;
        bf8.val = (char)(status.status);

        AnsiString msg;

        if (bf8.channels.ch1)
            msg = "紙なし";
        if (bf8.channels.ch2)
            msg = "ヘッドカバーオープン";
        if (bf8.channels.ch3)
			msg = "紙なし";
        if (bf8.channels.ch4)
            msg = "ヘッド温度異常または排出エラー";
        if (bf8.channels.ch5)
            msg = "カッター詰り";

        if (!msg.IsEmpty()){
	       //DM->Log("外部プリンタ", status.message, 0);
            NotifyForm->Notify("外部プリンタ: " + msg, true, 30000);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UMNiiReboot(TMessage& message)
{
	DM->Log("外部プリンタ", "再起動要求", 1);
}
//---------------------------------------------------------------------------
/**
 * Implementation of RFID Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnRFIDAborted(TMessage& message)
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
void __fastcall TEtherPostForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    bool is_fatal = message.WParam;

    DM->Log("操作ポスト(RFID)", status, is_fatal ? 2 : 1);

    if (is_fatal)
        NotifyForm->Notify(AnsiString("RFIDリーダ:" + status), true, 20000);
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnRFIDTimeout(TMessage& message)
{
    rfid_error_ = static_cast<bool>(message.WParam);
    UpdateWeighingState();
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;
    int card_no = message.LParam;

	/*** カード検知 ***/

    // 認証チェック
    if (!is_valid){
        DM->Log("操作ポスト", "カード認証エラー", 1);
        NotifyForm->Notify("システム外のカードを検知しました", false, 10000);
        return;
    }
    // 制御カードチェック
    if (card_no >= RFID::ADMIN_CARDS_ID){
        DM->Log("操作ポスト", "制御用カード検知", 1);
        NotifyForm->Notify("制御用カードはこのシステムで使用できません", false, 10000);
        return;
    }

    DM->Log("操作ポスト", "カード検知", 0);

	if (card_no == last_card_no_)
		return;
		
    last_card_no_ = card_no;

	card_sw_ = true;
	OutputCh();
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::PrintKeiryoData(int keiryo_id)
{
	if (printer_thread_){
        AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID =" + ToString(keiryo_id);

        keiryo_set_.clear();
        print_set_.clear();

        if (!DM->DBI.GetRecordSet(sql, keiryo_set_)){
            DM->Log("印刷情報","情報取得失敗しました", 2);
            return;
        }else{
            //ShowMessage(ToString(SET_TOP(printer_set_)["計量ID"]));
        }

        int print_info_id = DM->GetPrintInfo(keiryo_id);

        if (!print_info_id){
            DM->Log("伝票発行", "伝票情報が設定されていません", 2);
            return;
        }

        sql = "SELECT * FROM M_伝票情報 WHERE 伝票情報ID = " + IntToStr(print_info_id);

        if (!DM->DBI.GetRecordSet(sql, print_set_)){
            DM->Log("伝票発行", "伝票情報が無効です", 2);
            return;
        }


   		//PostThreadMessage(printer_thread_->ThreadID, UM_NII_PRINT, keiryo_id, 0);
        PostThreadMessage(printer_thread_->ThreadID, UM_NII_PRINT, (WPARAM)&keiryo_set_, (LPARAM)&print_set_);


    }
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::PrintCopy(int keiryo_id)
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
void __fastcall TEtherPostForm::ForceWeighing()
{
	OnExitWeighing();
	cur_weight_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::UpdateWeighingState()
{
	bool old_ready = ready_sw_;

	if (wi_error_ || rfid_error_){
		ready_sw_ = false;
	}else{
		ready_sw_ = true;
	}

	if (old_ready != ready_sw_){
		Sleep(300);
		OutputCh();
	}
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOAborted(TMessage& message)
{
	Application->MessageBox("IOユニットとの通信が切断されました", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("IOユニット", "TCP通信停止", 2);

	delete io_thread_;
	io_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	DM->Log("IOユニット", status, 1);
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOInput(TMessage& message)
{
	Channels cur_channels((BYTE)(message.LParam));

	DM->Log("DEBUG", "入力検知", 1);

    if (ToInt(DM->INI["IO::Invert"]) == 1){
	    if (cur_channels[ToInt(DM->INI["IO::ConfirmInCh"])] == chOff)
	    	OnConfirmButton();
    	if (cur_channels[ToInt(DM->INI["IO::ResetInCh"])] == chOff)
		    OnResetButton();
    }else{
	    if (cur_channels[ToInt(DM->INI["IO::ConfirmInCh"])] == chOn)
	    	OnConfirmButton();
	    if (cur_channels[ToInt(DM->INI["IO::ResetInCh"])] == chOn)
    		OnResetButton();
    }
}
//---------------------------------------------------------------------------
/*
void __fastcall TEtherPostForm::OnIOInput(const Channels& channels)
{
	Channels cur_channels(channels);

	if (last_inputs_.GetByteImage() != cur_channels.GetByteImage()){
		for (int i = 1; i <= 8; i++){
			if (cur_channels[i] == last_inputs_[i])
				cur_channels[i] = chNull;
		}

		if (cur_channels[ToInt(DM->INI["IO::ConfirmInCh"])] == chOff)
			OnConfirmButton();
		if (cur_channels[ToInt(DM->INI["IO::ResetInCh"])] == chOff)
			OnResetButton();

	}
	last_inputs_.SetByte(cur_channels.GetByteImage());
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOResponse(const AnsiString& message)
{
	// nothing to do
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OnIOError(const AnsiString& message)
{
	InputTimer->Enabled = false;

	Application->MessageBox("IOユニットとの通信が切断されました", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("IOユニット", "TCP通信停止", 2);
}
*/
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::OutputCh()
{
	Channels outputs(8);
	outputs[ToInt(DM->INI["IO::ReadyOutCh"])]  = ready_sw_    ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::CardOutCh"])]   = card_sw_     ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::ExitOutCh"])]   = exit_sw_     ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::OverOutCh"])]   = overload_sw_ ? chOn : chOff;
	outputs[ToInt(DM->INI["IO::BuzzerOutCh"])] = buzzer_sw_   ? chOn : chOff;

	if (io_thread_)
		PostThreadMessage(io_thread_->ThreadID, DIOM_OUTPUT, 0, outputs.GetByteImage());
}
//---------------------------------------------------------------------------
void __fastcall TEtherPostForm::BuzzerSwitchTimerTimer(TObject *Sender)
{
	BuzzerSwitchTimer->Enabled = false;

	buzzer_sw_ = !buzzer_sw_;
	OutputCh();
}
//---------------------------------------------------------------------------
