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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TAD4385PostForm *AD4385PostForm;
//---------------------------------------------------------------------------
__fastcall TAD4385PostForm::TAD4385PostForm(TComponent* Owner)
    : TForm(Owner), thread_(0), cur_weight_(0), old_weight_(0), cur_wi_status_(wsOther)
{
    cur_weight_     = 0;
    old_weight_     = 0;
    on_weighing_    = false;
    reversed_       = false;
    on_error_       = false;
    limit_over_     = false;
    on_printing_    = false;
    on_wait_exit_   = false;

    display_weight_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::FormCreate(TObject *Sender)
{
    Caption = Application->Title.c_str();

    ///////////////////////////////////////////////
    // データベースに接続

    if (!DM->Init())
        Close();

    //ApplyConfig();

    // 計量結果の表示位置指定
    if (ParamCount() > 0) {
        target_scale_name_ = ParamStr(1);
        TMenuItem* NewItem = new TMenuItem(PopupMenu);
        NewItem->Caption = target_scale_name_;
        PopupMenu->Items->Insert(1, NewItem);

    }

    AnsiString sectionPrefix = "AD4385";
    if (target_scale_name_.Length() > 0) {
        sectionPrefix += "_" + target_scale_name_;
    }



    ///////////////////////////////////////////////
    // AD4385 通信スレッドの準備 [INI]

    int port         = ToInt(DM->INI[sectionPrefix + "::Port"]);
    std::string def  = ToString(DM->INI[sectionPrefix + "::Def"]).c_str();
    weighing_border_ = ToInt(DM->INI[sectionPrefix + "::Border"]);
    notify_sound_    = ToString(DM->INI[sectionPrefix + "::NotifySound"]).c_str();
    top_margin_      = ToInt(DM->INI[sectionPrefix + "::TopMargin"]);

    if (port < 1)
        port = 1;
    if (def.empty())
        def = "9600,E,8,1";

    ad85_info_.port           = port;
    ad85_info_.def            = def;
    ad85_info_.owner          = Handle;
    ad85_info_.tag            = 0;
    ad85_info_.display_weight = &(display_weight_);
    ad85_info_.thread_id      = &(thread_id_);
    ad85_info_.warning        = &(ad85_warning_);
    ad85_info_.status         = &(ad85_status_);

    ThreadCreateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ThreadCreateTimerTimer(TObject *Sender)
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
    // AD4385 通信スレッドの作成

    thread_ = new TAD4385Thread(false, ad85_info_, top_margin_);
    thread_->FreeOnTerminate = false;

    /* AD4385 との通信が始まるまで待機（tnk）
     * 起動直後に計量開始重量に到達し、ランプ制御などの処理をする場合に、
     * AD4385 との通信が完全に確立されていないと、制御のタイミングを失ってしまう。
     */
    Sleep(2000);

    AnsiString sectionPrefix = "AD4385";
    if (target_scale_name_.Length() > 0) {
        sectionPrefix += "_" + target_scale_name_;
        scale_title_ = ToString(DM->INI[sectionPrefix + "::Title"]);
        scale_position_    = ToInt(DM->INI[sectionPrefix + "::ScalePosition"]);

    }else{
        sectionPrefix = "Weighing";
    }


    ///////////////////////////////////////////////
    // 重量受信
    try{
        // [INI] Weighing::WIPort
        ClientSocket->Port = ToInt(DM->INI[sectionPrefix + "::WIPort"]);
        // [INI] Weighing::WIServer
        ClientSocket->Host = ToString(DM->INI[sectionPrefix + "::WIServer"]);

        if (ClientSocket->Active)
            ClientSocket->Close();
        ClientSocket->Open();
    }catch(Exception& e){
        AnsiString msg = "TCP/IP通信ができません: \r\n" + e.Message;
        Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONSTOP | MB_TOPMOST);
    }
    SocketReopenTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (thread_) {
        thread_->Terminate();
        thread_->WaitFor();
        delete thread_;
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("制御を終了させると、操作ポストが一切使用できなくなります\r\n"
                                "よろしいですか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST)
                == IDYES){
        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::SocketReopenTimerTimer(TObject *Sender)
{
    if (ClientSocket->Active)
        return;

    try{
        AnsiString sectionPrefix = "AD4385";
        if (target_scale_name_.Length() > 0) {
            sectionPrefix += "_" + target_scale_name_;
        }else{
            sectionPrefix = "Weighing";
        }

        ClientSocket->Socket->Close();

        // [INI] Weighing::WIPort
        ClientSocket->Port = ToInt(DM->INI[sectionPrefix + "::WIPort"]);
        // [INI] Weighing::WIServer
        ClientSocket->Host = ToString(DM->INI[sectionPrefix + "::WIServer"]);

        ClientSocket->Open();
    }catch(Exception& e){
        //AnsiString msg = "TCP/IP通信ができません: \r\n" + e.Message;
        //Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONINFORMATION);
        ;
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ClientSocketError(TObject *Sender,
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
    ClientSocket->Socket->Close();
    old_weight_ = 0;
    cur_weight_ = 0;
    OnExitWeighing(0);

    ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    int index;
    AnsiString weight = Socket->ReceiveText();

    int len = weight.Length();
    if (len < 4)                    return;
    if (weight[len - 1] != '\r')    return;
    if (weight[len] != '\n')        return;
    switch (weight[1]){
    case 'S':   cur_wi_status_ = wsStable;      break;
    case 'U':   cur_wi_status_ = wsUnstable;    break;
    case 'O':   cur_wi_status_ = wsOther;       break;
    default:
        return;
    }

    weight.Delete(1, 1);    // ステータスキャラクタの削除
    weight.Delete(weight.Length() - 1, 2);  // 末尾の \r\n を削除
    Currency tmp_weight;
    try{

        tmp_weight = Currency(weight);
    }catch(...){return;}

    old_weight_ = cur_weight_;
    cur_weight_ = tmp_weight;

    display_weight_ = cur_weight_;

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
void __fastcall TAD4385PostForm::OnEnterWeighing(int tag)
{
    /*** 計量開始(スケール負荷) ***/
    if (IsThreadActive(tag)){
        ad85_params_.lamp = AD4385Lamp(false, false, false);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        ad85_params_.key = false;
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmKey, (LPARAM)&ad85_params_);
    }

    if (DisplayForm->Visible)
        DisplayForm->Close();

    on_wait_exit_ = false;  // 退車待ち状態をクリア
/*
    if (IsThreadActive(tag)){
        // ランプの点灯と、キーボードの初期化
        ad85_params_.lamp = AD4385Lamp(true, false, false);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        ad85_params_.key = true;
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmKey, (LPARAM)&ad85_params_);
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnExitWeighing(int tag)
{
    /*** 計量終了(降車) ***/

    if (IsThreadActive(tag)){
        ad85_params_.lamp = AD4385Lamp(false, false, false);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        ad85_params_.key = false;
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmKey, (LPARAM)&ad85_params_);
    }

    if (DisplayForm->Visible)
        DisplayForm->Close();

    on_wait_exit_ = false;  // 退車待ち状態をクリア
}
//---------------------------------------------------------------------------
/**
 * Implementation of AD4385 Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::UMAD4385Aborted(TMessage& message)
{
    DWORD thread_id = message.WParam;
    // int tag         = message.LParam;

    if (thread_id == thread_->ThreadID){
        delete thread_;
        thread_ = 0;
    }

    DM->Log("AD4385", "通信不可", 2);

    ErrorForm->TitlePanel->Caption = "操作ポストとの通信ができません";
    ErrorForm->TextMemo->Lines->Clear();
    ErrorForm->TextMemo->Lines->Text = "通信ポートが使用できないため、通信が行えません。\r\n"
                                       "\r\n"
                                       "ScaleManger 設定情報が変更された可能性があります。\r\n"
                                       "また、PC の故障等でも発生する場合があります。\r\n"
                                       "\r\n"
                                       "PC を再起動しても問題が解消しない場合は、お問い合わせください。";
    ErrorForm->ShowModal();

    Close();
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385Warning(int tag)
{
    DM->Log("AD4385" + target_scale_name_, ad85_warning_.message, 1);

    if (ad85_warning_.is_fatal){
        NotifyForm->Notify(ad85_warning_.message, true, 20000);
    }else{
        if (ad85_warning_.message == "通信を開始しました")
            return;

        NotifyForm->Notify("通信警告", false, 6000);
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385Event(int tag)
{

    switch (ad85_status_.event){
    case evCard:
        OnAD4385CardInsert(tag, ad85_status_.card_key_info);
        break;
    case evCardReverse:
        OnAD4385CardReverse(tag);
        break;
    case evCardOut:
        OnAD4385CardOut(tag);
        break;
    case evPowerOn:
        OnAD4385PowerOn(tag);
        break;
    case evPowerNg:
        OnAD4385PowerNg(tag);
        break;
    case evPrinterAbnormal:
        OnAD4385PrinterAbnormal(tag);
        break;
    case evPaperExist:
        OnAD4385PaperExist(tag);
        break;
    case evNoPaper:
        OnAD4385NoPaper(tag);
        break;
    case evKeiryo:
        OnAD4385Keiryo(tag);
        break;
    case evPrintAck:
        OnAD4385PrintAck(tag);
        break;
    case evNm:
        OnAD4385NameRequired(tag, ad85_status_.required_info);
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385CardInsert(int tag, const AD4385CardKeyInfo& info)
{
    /*** カード挿入イベント ***/
    DM->Log("AD4385" + target_scale_name_, "カード挿入", 0);

    if (!IsThreadActive(tag))
        return;

    if (!on_weighing_)
        return;
    if (on_printing_)
        return;
    if (on_wait_exit_)
        return;
    if (on_error_)
        return;

    /*----------------------------
     * TODO tOdO ToDo todo
     *----------------------------
     * -伝票発行
     */


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

    // 一度全てのランプを消灯
    ad85_params_.lamp = AD4385Lamp(false, false, false);
    PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);


    // threadから情報を確保
    /*
    card内にはカード発行時に書き込まれたIDが入っているが、キーボードによる操作が発生した場合上書きされた値が入る
    */
    AD4385CardKeyInfo::CardInfo card(info.card);
    AD4385CardKeyInfo::KeyInfo  key(info.key);

    bool print = false;

    TDateTime now(Now());
    int date = now.FormatString("yyyymmdd").ToInt();

    int toku_cd, meig_cd, item1_cd, item2_cd;
    int toku_id, meig_id, item1_id, item2_id, tani_id;
    NsRecord toku_rec, meig_rec, item1_rec, item2_rec;
    int car_no, keiryo_no, keiryo_id;

    if (card.str_id == ""){
        DM->Log("AD4385" + target_scale_name_, "カード番号無効による計量中止（ID < 1）", 1);
        NotifyForm->Notify("無効なカードが挿入されました", false, 10000);

        //on_error_ = true;

        ad85_params_.lamp = AD4385Lamp(false, false, true);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        return;
    }

    //////////
    try{
    //////////

    NsRecord card_rec;

    if (!DM->GetCardInfo(card.str_id.c_str(), card_rec)){
        AnsiString str_temp = card.str_id.c_str();
        DM->Log("AD4385" + target_scale_name_, "未登録車両による計量中止（カード番号:" + str_temp + "）", 1);
        NotifyForm->Notify("未登録車両です: " + str_temp, false, 10000);

        //on_error_ = true;

        ad85_params_.lamp = AD4385Lamp(false, false, true);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        return;
    }

    car_no = ToInt(card_rec["車番"]);

    ////////////////////////////////////////////////////////////////////////////
    // AD4385 項目と ScM マスタとの対応表／変数表を作成
    std::map<int, int> cnv_table;   // map<AD4385項目, ScMマスタ>
    cnv_table[1] = ToInt(DM->CFG["AD4385 項目１"]);
    cnv_table[2] = ToInt(DM->CFG["AD4385 項目２"]);
    cnv_table[3] = ToInt(DM->CFG["AD4385 項目３"]);
    cnv_table[4] = ToInt(DM->CFG["AD4385 項目４"]);

    // 使用する項目が有効かどうか
    // 使用できなければ, 0にする
    for (int i = 1; i <= 4; i++){
         if (cnv_table[i] < 1 || cnv_table[i] > 4)
            cnv_table[i] = 0;
    }

    // cnv_table[] = 1..4
    std::map<int, int *> scm_codes;
    int dummy;
    scm_codes[0] = &dummy;
    scm_codes[1] = &toku_cd;
    scm_codes[2] = &item1_cd;
    scm_codes[3] = &item2_cd;
    scm_codes[4] = &meig_cd;

    ////////////////////////////////////////////////////////////////////////////
    // カード情報、カードマスタ情報、キー情報で車両情報を書き換え

    if (cur_weight_ > ToCurrency(card_rec["車両総重量"]) && ToCurrency(card_rec["車両総重量"]) > 0){
        DM->Log("AD4385", "車両総重量に対する過積載（車番:" + IntToStr(car_no) + "）", 1);
        NotifyForm->Notify("車両総重量に対する過積載です: " + IntToStr(car_no), false, 30000);

        //on_error_ = true;

        ad85_params_.lamp = AD4385Lamp(false, false, true);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        return;
    }

    NsFieldSet fields;
    fields
        << NsField("[計量日]",     date)
        << NsField("[拠点ID]",     place_id_)
        << NsField("[行No]",       1)
        << NsField("[車両ID]",     ToInt(card_rec["車両ID"]))
        << NsField("[更新日時]",   now)
        ;
    Currency tare_w = ToCurrency(card_rec["空車重量"]);


    ////////////////////////////////////////////////////////////////////////////
    // カード情報、カードマスタ情報、キー情報で車両情報を書き換え

    ///// 優先度（低）カード情報
    // 各_cd の値を設定
    *(scm_codes[cnv_table[1]]) = card.item1;
    *(scm_codes[cnv_table[2]]) = card.item2;
    *(scm_codes[cnv_table[3]]) = card.item3;
    *(scm_codes[cnv_table[4]]) = card.item4;

    /*
    20230909
    keyにはキーボード入力が入っていそうだが入っていない
    キーボードにて入力されて情報はすべてitemに入っている
    */
    AnsiString card_log = " item 1: " + ToString(card.item1) + " item 2: " + ToString(card.item2) + " item 3: " + ToString(card.item3) + " item 4: " + ToString(card.item4);
    DM->Log("AD4385" + target_scale_name_, "カード及びキー書換情報" + card_log, 0);


    /*
    計量IDから滞留情報を確認し、滞留があれば計量IDを取得する
    */
    int remained_keiryo_id = DM->GetRemainedKeiryoID(place_id_, ToInt(card_rec["車両ID"]));
    const int sharyo_id = ToInt(card_rec["車両ID"]);


    // 滞留が無い場合は、マスタ > キーボード
    if (!remained_keiryo_id) {
        // マスタ情報 キーボードより優先する
        //
        int code;

        // 得意先コード
        code = ToInt(card_rec["得意先コード"]);
        if (code) toku_cd = code;
        // 品目コード
        code = ToInt(card_rec["品目コード"]);
        if (code) meig_cd = code;
        // 項目1コード
        code = ToInt(card_rec["項目1コード"]);
        if (code) item1_cd = code;
        // 項目2コード
        code = ToInt(card_rec["項目2コード"]);
        if (code) item2_cd = code;

        toku_id  = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", toku_cd,  "得意先ID"));
        meig_id  = ToInt(DM->DBI.Lookup("M_品目",   "品目コード",   meig_cd, "品目ID"));
        item1_id = ToInt(DM->DBI.Lookup("M_項目1",  "項目1コード",  item1_cd, "項目1ID"));
        item2_id = ToInt(DM->DBI.Lookup("M_項目2",  "項目2コード",  item2_cd,  "項目2ID"));

        AnsiString info = "滞留なしマスタ優先 得意先コード: " + ToString(toku_cd) + " 品目コード: " + ToString(meig_cd) + " 項目1コード: " + ToString(item1_cd) + " 項目2コード: " + ToString(item2_cd);
        DM->Log("AD4385" + target_scale_name_, info, 0);

        // 該当のViewよりRecordを取得
        DM->GetViewRec("得意先", toku_id,  toku_rec);
        DM->GetViewRec("品目",   meig_id,  meig_rec);
        DM->GetViewRec("項目1",  item1_id, item1_rec);
        DM->GetViewRec("項目2",  item2_id, item2_rec);

        fields
            << NsField("[得意先ID]",   toku_id)
            << NsField("[得意先名称]", ToString(toku_rec["得意先名称"]))
            << NsField("[項目1ID]",    item1_id)
            << NsField("[項目1名称]",  ToString(item1_rec["項目1名称"]))
            << NsField("[項目2ID]",    item2_id)
            << NsField("[項目2名称]",  ToString(item2_rec["項目2名称"]))
            << NsField("[品目ID]",     meig_id)
            << NsField("[品目名称]",   ToString(meig_rec["品目名称"]))
            << NsField("[搬入出区分]", ToInt(meig_rec["搬入出区分"]))
            ;

    } else {


        // 滞留ありの場合は2回目計量のときに処理する

    }


    if (!remained_keiryo_id && tare_w < 1){
        // 一回目計量かつ一回計量でない場合

        keiryo_no = DM->GetTempNo(place_id_);

        fields << NsField("[伝票No]",    keiryo_no)
               << NsField("[1回目重量]", cur_weight_)
               << NsField("[計量日時1]", now)
               << NsField("[完了区分]",  0)
               << NsField("[作成日時]",  now)
               ;

    }else{

        // 2回目計量

        print = true;

        Currency weight1, weight2, net;

        int tani_code = DM->GetKanzanCode(toku_id, meig_id);
        tani_id = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tani_code, "単位ID"));

        if (remained_keiryo_id){
            // 二回目計量

            NsRecordSet remained_set;
            if (!DM->DBI.GetRecordSet("SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(remained_keiryo_id), remained_set)){

                AnsiString str_id = card.str_id.c_str();
                DM->Log("AD4385", "滞留データ抽出失敗（車番:" + IntToStr(car_no) + "）", 2);
                NotifyForm->Notify("滞留データの呼び出しに失敗しました:" + str_id, false, 10000);

                //on_error_ = true;

                ad85_params_.lamp = AD4385Lamp(false, false, true);
                PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
                return;
            }

            // 滞留から各コード取得
            int temp_remained_master_code = 0;

            AnsiString sql = "SELECT * FROM V_車両 WHERE 車両ID = " + ToString(sharyo_id);
            NsRecordSet sharyo_set;

            int toku_code_from_sharyo = 0;
            int item1_code_from_sharyo = 0;
            int item2_code_from_sharyo = 0;
            int meig_code_from_sharyo = 0;

            if (DM->DBI.GetRecordSet(sql, sharyo_set)) {
                toku_code_from_sharyo = ToInt(SET_TOP(sharyo_set)["得意先コード"]);
                item1_code_from_sharyo = ToInt(SET_TOP(sharyo_set)["項目1コード"]);
                item2_code_from_sharyo = ToInt(SET_TOP(sharyo_set)["項目2コード"]);
                meig_code_from_sharyo = ToInt(SET_TOP(sharyo_set)["品目コード"]);

            }

            AnsiString tairyu_info = " 滞留優先: ";

            temp_remained_master_code      = ToInt(SET_TOP(remained_set)["得意先コード"]);
            if (toku_code_from_sharyo != 0) {
                tairyu_info += " 得 ";
                toku_cd = toku_code_from_sharyo;
            } else if (toku_cd == 0 && temp_remained_master_code != 0) {
                tairyu_info += " 得 ";
                toku_cd = temp_remained_master_code;
            }            toku_id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", toku_cd, "得意先ID"));
            DM->GetViewRec("得意先", toku_id, toku_rec);
            fields  <<  NsField("[得意先ID]",   toku_id)
                    <<  NsField("[得意先名称]", ToString(toku_rec["得意先名称"]));


            temp_remained_master_code = ToInt(SET_TOP(remained_set)["項目1コード"]);
            if (item1_code_from_sharyo != 0) {
                tairyu_info += " 項1 ";
                item1_cd = item1_code_from_sharyo;
            }else if(item1_cd == 0 && temp_remained_master_code != 0){
                tairyu_info += " 項1 ";
                item1_cd = temp_remained_master_code;
            }
            item1_id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", item1_cd, "項目1ID"));
            DM->GetViewRec("項目1", item1_id, item1_rec);
            fields << NsField("[項目1ID]",   item1_id)
                   << NsField("[項目1名称]", ToString(item1_rec["項目1名称"]));


            temp_remained_master_code = ToInt(SET_TOP(remained_set)["項目2コード"]);
            if (item2_code_from_sharyo != 0) {
                tairyu_info += " 項2 ";
                item2_cd = item2_code_from_sharyo;
            }else if (item2_cd == 0 && temp_remained_master_code != 0){
                tairyu_info += " 項2 ";
                item2_cd = temp_remained_master_code;
            }
            item2_id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", item2_cd, "項目2ID"));
            DM->GetViewRec("項目2", item2_id, item2_rec);
            fields << NsField("[項目2ID]",   item2_id)
                   << NsField("[項目2名称]", ToString(item2_rec["項目2名称"]));

            temp_remained_master_code = ToInt(SET_TOP(remained_set)["品目コード"]);
            if (meig_code_from_sharyo != 0) {
                tairyu_info += " 品 ";
                meig_cd = meig_code_from_sharyo;
            }else if (meig_cd == 0 &&temp_remained_master_code != 0) {
                tairyu_info += " 品 ";
                meig_cd = temp_remained_master_code;

            }
            meig_id = ToInt(DM->DBI.Lookup("M_品目", "品目コード", meig_cd, "品目ID"));
            DM->GetViewRec("品目", meig_id, meig_rec);
            fields << NsField("[品目ID]",   meig_id)
                   << NsField("[品目名称]", ToString(meig_rec["品目名称"]));

            AnsiString log = "2回目計量" + tairyu_info + "得意先コード: " + ToString(toku_cd) +  " 品目コード: " + ToString(meig_cd) + " 項目1コード: " + ToString(item1_cd) + " 項目2コード: " + ToString(item2_cd);

            DM->Log("AD4385" + target_scale_name_, log, 0);

            weight1 = ToCurrency(SET_TOP(remained_set)["1回目重量"]);
            weight2 = cur_weight_;
        }else{
            // 一回計量

            fields << NsField("[1回目重量]", tare_w)
                   //<< NsField("[計量日時1]", )
                   ;
            weight1 = tare_w;
            weight2 = cur_weight_;
        }

        net = weight1 - weight2;
        if (net < 1) net *= -1;

        if (net > ToCurrency(card_rec["最大積載量"]) && ToCurrency(card_rec["最大積載量"]) > 0){
            DM->Log("AD4385", "最大積載量に対する過積載（車番:" + IntToStr(car_no) + "）", 1);
            NotifyForm->Notify("最大積載量に対する過積載です: " + IntToStr(car_no), false, 30000);

            //on_error_ = true;

            ad85_params_.lamp = AD4385Lamp(false, false, true);
            PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
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

        fields << NsField("[伝票No]",    keiryo_no)
               << NsField("[2回目重量]", weight2)
               << NsField("[計量日時2]", now)
	    	   << NsField("[調整率]",    adj_per)
               << NsField("[調整重量]",  adj_weight)
               << NsField("[正味重量]",  net)
               << NsField("[単位ID]",    tani_id)
               << NsField("[完了区分]",  1)
               ;

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

            Currency tax_rate = DM->GetSalesTax();          // 消費税率

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

    DM->ADOConnection->BeginTrans();

    if (remained_keiryo_id){
        // 二回目計量

        DM->DBI.Update("D_計量", "計量ID", remained_keiryo_id, fields);

        DM->Log("AD4385" + target_scale_name_, "計量完了（車番:" + IntToStr(car_no) + "）", 0);

        keiryo_id = remained_keiryo_id;
    }else{
        // 一回目計量または一回計量

        DM->DBI.Insert("D_計量", fields);

        if (tare_w < 1){
            DM->Log("AD4385" + target_scale_name_, "一回目計量完了（車番:" + IntToStr(car_no) + "）", 0);
        }else{
            // 一回計量により計量完了
            DM->Log("AD4385" + target_scale_name_, "一回計量完了（車番:" + IntToStr(car_no) + "）", 0);

        }

        keiryo_id = DM->GetKeiryoID(place_id_, date, keiryo_no);
    }

    DM->ADOConnection->CommitTrans();

    //////////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString str_id = card.str_id.c_str();
        DM->Log("AD4385" + target_scale_name_, AnsiString("登録時例外（カード番号:") + str_id + "）: " + e.Message, 2);
        NotifyForm->Notify("登録時にエラーが発生しました:" + str_id, false, 10000);

        //on_error_ = true;

        ad85_params_.lamp = AD4385Lamp(false, false, true);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        return;
    }
    //////////

    if (target_scale_name_.IsEmpty()) {
        DisplayForm->ShowRecord(keiryo_id);
    }else{
        DisplayForm->ShowRecord(keiryo_id, scale_title_, scale_position_);
    }

    if (print){
        int print_denpyo = ToString(DM->CFG["自動計量時伝票発行"]).ToIntDef(1); // 2012.10.29 追加
        if (print_denpyo){
            PrintKeiryoData(tag, keiryo_id);
            //PrintKeiryoData(tag, keiryo_id, true);
        }

        int print_copy = ToInt(DM->CFG["自動計量時控え伝票発行"]);
        if (print_copy)
            PrintCopy(keiryo_id);
    }

    // 完了ランプを点灯
    ad85_params_.lamp = AD4385Lamp(false, true, false);
    PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
    ad85_params_.beep_len = 5;
    PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmBeep, (LPARAM)&ad85_params_);

    on_wait_exit_ = true;   // 退車待ち状態
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385CardReverse(int tag)
{
    /*** カード逆挿入イベント ***/
    DM->Log("AD4385" + target_scale_name_, "カード逆挿入", 0);

    if (IsThreadActive(tag)){
        ad85_params_.lamp = AD4385Lamp(false, false, true);
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
        ad85_params_.beep_len = 5;
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmBeep, (LPARAM)&ad85_params_);
    }

    NotifyForm->Notify("カードが逆に挿入されました", false, 10000);

    reversed_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385CardOut(int tag)
{
    /*** カード抜き取りイベント ***/

    if (reversed_ || on_error_){    // 逆挿入、もしくはデータエラーの場合
        if (!on_weighing_){
            ad85_params_.lamp = AD4385Lamp(false, false, false);
        }else{
            if (on_wait_exit_)          // 降車待ち
                ad85_params_.lamp = AD4385Lamp(false, true, false);
            else
                ad85_params_.lamp = AD4385Lamp(true, false, false);
        }
        if (IsThreadActive(tag))
            PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmLamp, (LPARAM)&ad85_params_);
    }

    reversed_ = false;
    on_error_ = false;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PowerOn(int tag)
{
    DM->Log("AD4385" + target_scale_name_, "セルフテスト OK", 0);

    if (ErrorForm->Visible)
        ErrorForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PowerNg(int tag)
{
    DM->Log("AD4385" + target_scale_name_, "セルフテスト NG", 2);

    ErrorForm->TitlePanel->Caption = "操作ポストが異常状態です";
    ErrorForm->TextMemo->Lines->Clear();
    ErrorForm->TextMemo->Lines->Text = "カードを挿入したまま電源を入れた\r\n"
                                       "あるいはカード挿入部が汚れていると思われます。\r\n"
                                       "\r\n"
                                       "カード挿入部を掃除し、もう一度電源を入れなおしてください。\r\n";
                                       "解決しない場合は故障が考えられますので、お問い合わせください。";
    ErrorForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PrinterAbnormal(int tag)
{
    DM->Log("AD4385" + target_scale_name_, "プリンタ異常", 2);

    NotifyForm->Notify("操作ポストのプリンタが異常動作しています", false, 10000);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PaperExist(int tag)
{
    DM->Log("AD4385" + target_scale_name_, "用紙あり", 0);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385NoPaper(int tag)
{
    DM->Log("AD4385" + target_scale_name_, "用紙なし", 1);

    NotifyForm->Notify("操作ポストの伝票用紙が少なくなっています", true, 60000);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385PrintAck(int tag)
{
    DM->Log("AD4385" + target_scale_name_, "印字確認", 0);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385Keiryo(int tag)
{
    DM->Log("AD4385" + target_scale_name_, "強制計量", 0);

    ForceWeighing(tag);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::OnAD4385NameRequired(int tag, AD4385RequiredInfo *info)
{
    DM->Log("AD4385" + target_scale_name_, "名前要求", 0);

    char name_buff[30];
    AnsiString text;

    AnsiString key;
    if (info->item_no == 1){
        key = "AD4385 項目１";
        DM->Log("AD4385" + target_scale_name_, "85側項目1変更", 0);
    }else if (info->item_no == 2){
        key = "AD4385 項目２";
        DM->Log("AD4385" + target_scale_name_, "85側項目2変更", 0);
    }else if (info->item_no == 3){
        key = "AD4385 項目３";
        DM->Log("AD4385" + target_scale_name_, "85側項目3変更", 0);
    }else if (info->item_no == 4){
        key = "AD4385 項目４";
        DM->Log("AD4385" + target_scale_name_, "85側項目4変更", 0);
    }else{
        text = "             ";
        wsprintf(name_buff, "%-28s", text.SubString(1, 28).c_str());
        info->reply = name_buff;
        return;
    }

    // [CFG] AD4385 の項目１〜４に対応する ScM のマスタを参照
    int master_no = ToInt(DM->CFG[key]);
    switch (master_no){
    case 1:
        DM->Log("AD4385" + target_scale_name_, "得意先コード: " + ToString(info->item_code), 0);
        text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", info->item_code, "得意先略称"));
        break;
    case 2:
        DM->Log("AD4385" + target_scale_name_, "項目1コード: " + ToString(info->item_code), 0);
        text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", info->item_code, "項目1略称"));
        break;
    case 3:
        DM->Log("AD4385" + target_scale_name_, "項目2コード: " + ToString(info->item_code), 0);
        text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", info->item_code, "項目2略称"));
        break;
    case 4:
        DM->Log("AD4385" + target_scale_name_, "品目コード: " + ToString(info->item_code), 0);
        text = ToString(DM->DBI.Lookup("M_品目", "品目コード", info->item_code, "品目略称"));
        break;
    default:
        break;
    }
    if (text.IsEmpty())
        text = "             ";

    wsprintf(name_buff, "%-28s", text.SubString(1, 28).c_str());
    info->reply = name_buff;
}
//---------------------------------------------------------------------------
bool __fastcall TAD4385PostForm::IsThreadActive(int tag)
{
    /** In this program, tag is not in use. **/

    return thread_ ? true : false;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::CreatePrintImage(PrintImage& image, NsRecord& record)
{
    image.clear();

    char buff[256];
    int date;

    image.push_back("_");

    // 日付、伝票番号
    date = ToInt(record["計量日"]);
    wsprintf(buff, "   No.%3d  %04d.%02d.%02d", ToInt(record["伝票No"]), date / 10000, (date % 10000) / 100, date % 100);
    image.push_back(buff);
    // 車番
    wsprintf(buff, "   %5d", ToInt(record["車番"]));
    image.push_back(buff);

    AnsiString item_order = ToString(DM->CFG["ドット伝票項目順"]);
    int no;
    for (int i = 1; i <= 4; i++){
        if (item_order.IsEmpty()){
            image.push_back("_");
            continue;
        }
        no = item_order.SubString(1, 1).ToIntDef(0);
        item_order.Delete(1, 1);

        if (no == 1){
            // 得意先
            if (ToInt(record["得意先コード"])){
                wsprintf(buff, "   %5d %s", ToInt(record["得意先コード"]), ToString(record["得意先略称"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }else if (no == 2){
            // 項目1
            if (ToInt(record["項目1コード"])){
                wsprintf(buff, "   %5d %s", ToInt(record["項目1コード"]), ToString(record["項目1略称"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }else if (no == 3){
            // 項目2
            if (ToInt(record["項目2コード"])){
                wsprintf(buff, "   %5d %s", ToInt(record["項目2コード"]), ToString(record["項目2略称"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }else if (no == 4){
            // 品目
            if (ToInt(record["品目コード"])){
                wsprintf(buff, "   %5d %s", ToInt(record["品目コード"]), ToString(record["品目略称"]).c_str());
            }else{
                lstrcpy(buff, "_");
            }
        }
        image.push_back(buff);
    }

    /*
    // 得意先
    if (ToInt(record["得意先コード"])){
        wsprintf(buff, "   %5d %s", ToInt(record["得意先コード"]), ToString(record["得意先略称"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
    image.push_back(buff);
    // 品目
    if (ToInt(record["品目コード"])){
        wsprintf(buff, "   %5d %s", ToInt(record["品目コード"]), ToString(record["品目略称"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
    image.push_back(buff);
    // 項目1
    if (ToInt(record["項目1コード"])){
        wsprintf(buff, "   %5d %s", ToInt(record["項目1コード"]), ToString(record["項目1略称"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
    image.push_back(buff);
    // 項目2
    if (ToInt(record["項目2コード"])){
        wsprintf(buff, "   %5d %s", ToInt(record["項目2コード"]), ToString(record["項目2略称"]).c_str());
    }else{
        lstrcpy(buff, "  ");
    }
    image.push_back(buff);
    */

    int gross, tare;
    int gross_time = 0;
    int tare_time  = 0;
    Currency weight1, weight2;
    TDateTime dt;

    weight1 = ToCurrency(record["1回目重量"]);
    weight2 = ToCurrency(record["2回目重量"]);

    if (weight1 > weight2){
        gross = weight1;
        tare  = weight2;

        try{
            dt = TDateTime(record["計量日時1"]);
            gross_time = dt.FormatString("hhnn").ToInt();
        }catch(...){}
        try{
            dt = TDateTime(record["計量日時2"]);
            tare_time  = dt.FormatString("hhnn").ToInt();
        }catch(...){}
    }else{
        gross = weight2;
        tare  = weight1;

        try{
            dt = TDateTime(record["計量日時2"]);
            gross_time = dt.FormatString("hhnn").ToInt();
        }catch(...){}
        try{
            dt = TDateTime(record["計量日時1"]);
            tare_time  = dt.FormatString("hhnn").ToInt();
        }catch(...){}
    }

    bool print_time = ToBit(DM->CFG["自動計量時間印字"]);

    // 総重量
    if (gross_time && print_time){
        wsprintf(buff, "      %02d:%02d  %7skg", gross_time / 100, gross_time % 100,
                            FormatFloat("###,##0", gross).c_str());
    }else{
        wsprintf(buff, "             %7skg", FormatFloat("###,##0", gross).c_str());
    }
    image.push_back(buff);

    // 空車重量
    if (tare_time && print_time){
        wsprintf(buff, "      %02d:%02d  %7skg", tare_time / 100, tare_time % 100,
                            FormatFloat("###,##0", tare).c_str());
    }else{
        wsprintf(buff, "             %7skg", FormatFloat("###,##0", tare).c_str());
    }
    image.push_back(buff);

    // 正味重量
    wsprintf(buff, "             %7skg", FormatFloat("###,##0", ToInt(record["正味重量"])).c_str());
    image.push_back(buff);

    int gk_div = ToInt(record["現掛区分"]);
    int mon    = ToInt(record["金額"]) + ToInt(record["消費税額"]);

    // 金額
    if (gk_div == 2 && mon){
        wsprintf(buff, "           %9s円", FormatFloat("#,###,##0", mon).c_str());
    }else{
        lstrcpy(buff, "_");
    }
    image.push_back(buff);

    image.push_back("END");
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::PrintKeiryoData(int tag, int keiryo_id)
{
    NsRecordSet set;
    AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
    if (!DM->DBI.GetRecordSet(sql, set))
        return;

    if (IsThreadActive(tag)){
        DM->Log("print" + target_scale_name_, "1", 0);
        CreatePrintImage(ad85_params_.image, SET_TOP(set));
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmPrint, (LPARAM)&ad85_params_);
    }
}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::PrintKeiryoData(int tag, int keiryo_id, bool plan)
{
    NsRecordSet set;
    AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id);

    if (!DM->DBI.GetRecordSet(sql, set))
        return;

    if (IsThreadActive(tag)){
        DM->Log("print" + target_scale_name_, "2", 0);
        CreatePrintImage(ad85_params_.image, SET_TOP(set));
        PostThreadMessage(thread_id_, UM_AD4385_COMMAND, cmPrint2, (LPARAM)&ad85_params_);
    }

}
//---------------------------------------------------------------------------
void __fastcall TAD4385PostForm::PrintCopy(int keiryo_id)
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
void __fastcall TAD4385PostForm::ForceWeighing(int tag)
{
    OnExitWeighing(tag);
    cur_weight_ = 0;
}
//---------------------------------------------------------------------------

