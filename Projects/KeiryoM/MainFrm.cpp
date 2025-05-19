//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DataListFrm.h"
#include "MainFrm.h"
#include <mmsystem.h>
#include "LaserSlipPrintFrm.h"
#include "LaserSlipPrintM_GenkinFrm.h"
#include "LaserSlipPrintM_KakeFrm.h"
#include "DotSlipPrintFrm.h"
#include "TrailerWeightFrm.h"
#include "ShabanSanshoFrm.h"
#include "PostConfFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "StrCGrid"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner),
        keiryo_id_(0),
        cur_weight_(0), old_weight_(0),
        id_total_(0), item_relate_hin_id_(0),
        delete_flag_(false)
{
    Application->OnMessage = MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
    TDBGrid *Grid = 0;

    switch (Msg.message){
    case WM_MOUSEWHEEL:
        if (Msg.hwnd == DataListForm->DBGrid->Handle)
            Grid = DataListForm->DBGrid;
        if (Msg.hwnd == SearchForm->DBGrid->Handle)
            Grid = SearchForm->DBGrid;
        if (Msg.hwnd == ShabanSanshoForm->DBGrid->Handle)
            Grid = ShabanSanshoForm->DBGrid;

        if (!Grid)
            return;

        Grid->SetFocus();

        if((short)HIWORD(Msg.wParam) > 0){
            Grid->DataSource->DataSet->Prior();
        }else{
            Grid->DataSource->DataSet->Next();
        }
        Handled = true;
        break;
    }
}
//---------------------------------------------------------------------------
// MainForm->OnShow
void __fastcall TMainForm::FormShow(TObject *Sender)
{

    ///////////////////////////////////////////////
    // データベースに接続

    if (!DM->Init())
        Close();

    ApplyConfig();

    // 滞留テーブルオープン
    try{
        Q_Tairyu->Open();
    }catch (Exception& e){
        Application->MessageBox(("滞留一覧データの読み込みに失敗しました\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
        Close();
    }

	// 秤量＆目量
	DM->hyoryo_ = ToCurrency(DM->CFG["秤量"]);
	DM->meryo_  = ToCurrency(DM->CFG["目量"]);

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
        Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONINFORMATION);
    }

    SocketReopenTimer->Enabled = true;

    Resize();

    TairyuTimer->Enabled = true;

    // 明細グリッド初期化
    SetGridTitle();

    Action1->Execute();
}
//---------------------------------------------------------------------------
// 設定内容をフォームに適用等
void __fastcall TMainForm::ApplyConfig()
{
    // DM->CFG.Debug();

    // [CFG]

    // MainForm
    TokuButton->Caption      = ToString(DM->CFG["得意先マスタ名称"]);
    Komoku1Button->Caption   = ToString(DM->CFG["項目1マスタ名称"]);
    Komoku2Button->Caption   = ToString(DM->CFG["項目2マスタ名称"]);

    TairyuTokuisakiLabel->Caption = ToString(DM->CFG["得意先マスタ名称"]);

    if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
        TokuPanel->Visible            = false;
        TairyuTokuisakiLabel->Visible = false;
        TairyuTokuisakiText->Visible  = false;
    }

    if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        Komoku1Panel->Visible = false;
    }

    if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
        Komoku2Panel->Visible = false;
    }

    if (!ToBit(DM->CFG["入出庫使用区分"])){
        HannyuCombo->Visible  = false;
        RecalcButton->Visible = false;
    }

    PlaceCombo->Items->Clear();
    if (!DM->DBI.GetRecordSet("SELECT 拠点ID, 拠点コード, 拠点名称 FROM M_拠点", kyoten_set_)){
        Application->MessageBox("拠点マスタが設定されていません。計量前に設定してください",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }
    default_index = 0;
    int place_code    = ToInt(DM->INI["Place::Code"]);
    for (unsigned int i = 0; i < kyoten_set_.size(); i++){
        PlaceCombo->Items->Append(ToString(kyoten_set_[i]["拠点名称"]));
        if (ToInt(kyoten_set_[i]["拠点コード"]) == place_code)
            default_index = i;
    }
    PlaceCombo->ItemIndex = default_index;

    AutoPrintCheck->Checked  = ToBit(DM->CFG["伝票発行初期区分"]);
    DataDeleteCheck->Visible = ToBit(DM->CFG["空伝票発行機能"]);
    HideTimeCheck->Checked   = !(ToBit(DM->CFG["時間印字初期区分"]));
    HideTimeCheck->Visible   = ToBit(DM->CFG["時間空白印字機能"]);

    int wild_code;

    wild_code = ToInt(DM->CFG["得意先諸口コード"]);
    if (wild_code && !DM->DBI.IsExist("M_得意先", "得意先コード", wild_code)){
        Application->MessageBox("得意先諸口コードが得意先マスタに登録されていません。計量前に設定してください",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }
    wild_code = ToInt(DM->CFG["品目搬入諸口コード"]);
    if (wild_code && !DM->DBI.IsExist("M_品目", "品目コード", wild_code)){
        Application->MessageBox("品目搬入諸口コードが品目マスタに登録されていません。計量前に設定してください",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }
    wild_code = ToInt(DM->CFG["品目搬出諸口コード"]);
    if (wild_code && !DM->DBI.IsExist("M_品目", "品目コード", wild_code)){
        Application->MessageBox("品目搬出諸口コードが品目マスタに登録されていません。計量前に設定してください",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }
    wild_code = ToInt(DM->CFG["項目1諸口コード"]);
    if (wild_code && !DM->DBI.IsExist("M_項目1", "項目1コード", wild_code)){
        Application->MessageBox("項目1諸口コードが項目1マスタに登録されていません。計量前に設定してください",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }
    wild_code = ToInt(DM->CFG["項目2諸口コード"]);
    if (wild_code && !DM->DBI.IsExist("M_項目2", "項目2コード", wild_code)){
        Application->MessageBox("項目2諸口コードが項目2マスタに登録されていません。計量前に設定してください",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }


    standard_tani_code_ = ToInt(DM->CFG["標準単位"]);
    money_print_div_    = ToInt(DM->CFG["伝票金額印字"]);
}
//---------------------------------------------------------------------------
// ソケットの切断を監視
void __fastcall TMainForm::SocketReopenTimerTimer(TObject *Sender)
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
    }
}
//---------------------------------------------------------------------------
// 別Form 用重量提供メソッド
Currency __fastcall TMainForm::GetWeight()
{
    return cur_weight_;
}
//---------------------------------------------------------------------------
// 拠点コンボボックスから ID を取得
int __fastcall TMainForm::GetPlaceID()
{
    return ToInt(kyoten_set_[PlaceCombo->ItemIndex]["拠点ID"]);
}
//---------------------------------------------------------------------------
// ゼロ抑制
AnsiString __fastcall TMainForm::ZeroSuppress(Currency v)
{
    if (v == 0)
        return AnsiString();
    else
        return AnsiString(v);
}
//---------------------------------------------------------------------------
// フォームをクリア
void __fastcall TMainForm::ClearForm()
{
    keiryo_id_    = 0;
    keiryo_set_.clear();

    toku_id_      = 0;
    toku_rec_.clear();

    new_car_      = false;
    car_id_       = 0;
    keiryo_count_ = 0;
    gross_limit_  = 0;
    net_limit_    = 0;

    item_relate_hin_id_ = 0;
    slip_tax_           = 0;

    TDateTime now = Now();

    KeiryoDatePicker->Date    = now;
    KeiryoNoEdit->Text        = AnsiString();
    KeiryoTimePicker->Time    = now;
    PlaceCombo->ItemIndex     = default_index;
    ShabanEdit->Text          = AnsiString();
    ShabanEdit->OnChange(NULL);
    TokuCodeEdit->Text        = AnsiString();
    TokuNameEdit->Text        = AnsiString();
    Komoku1CodeEdit->Text     = AnsiString();
    Komoku1NameEdit->Text     = AnsiString();
    Komoku2CodeEdit->Text     = AnsiString();
    Komoku2NameEdit->Text     = AnsiString();
    BikoEdit->Text            = AnsiString();
    HannyuCombo->ItemIndex    = -1;
}
//---------------------------------------------------------------------------
// 行追加用の関数
void __fastcall TMainForm::Line_Add()
{
    // 表示されている最大行No取得
    int row_no = 0;
    for (int r = detail_line; r < SCGrid->RowCount; r += detail_line){
        if (!SCGrid->Cells[0][r].IsEmpty())
        row_no = SCGrid->Cells[0][r].ToIntDef(0);
    }

    int line_no = row_no + 1;
    if (line_no * detail_line >= max_row) // max_rowを超えるようなら追加処理中断
        return;

    SCGrid->Cells[0][line_no * detail_line] = line_no;

    for (int i = 0; i < detail_line; i++)
        row_lineno_map_[(line_no * detail_line) + i] = line_no;

    SCGrid->Col = 1;
    SCGrid->Row = line_no * detail_line;

    // グリッドを編集可にする
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;

    SCGrid->SetFocus();
}
//---------------------------------------------------------------------------
// 行挿入用の関数その2
void __fastcall TMainForm::Line_Insert(int line_no)
{
    // 空白の行がある場合はそこに移動する
    for (int i = detail_line; i < SCGrid->RowCount - detail_line; i += detail_line){
        int line_no, id;
        line_no = row_lineno_map_[i];
        id      = row_id_map_[i];

        if (line_no == 6){
            return;
        }else if (line_no != 0 && id == 0 && SCGrid->Cells[GetColNo("品目コード")][CalcRowNo("品目コード", i)].ToIntDef(0) == 0){
            SCGrid->Col = GetColNo("品目コード");
            SCGrid->Row = CalcRowNo("品目コード", i);
            SCGrid->SetFocus();
            return;
        }
    }

    // line_noから下の行をdetail_line分ずらす
    int calc_row = line_no * detail_line;
    for (int i = SCGrid->RowCount - detail_line; i >= calc_row; i--){
        SCGrid->Rows[i + detail_line] = SCGrid->Rows[i];
        SCGrid->Rows[i]->Clear();
        row_id_map_[i + detail_line]  = row_id_map_[i];
        row_id_map_[i] = 0;
    }

    int old_id  = row_id_map_[detail_line];
    int no      = 1;
    row_lineno_map_.clear();
    for (int i = detail_line; i < SCGrid->RowCount; i++){
        if (old_id != row_id_map_[i])
            no++;

        // mapにidがなかったら処理終了
        if (row_id_map_[i] == 0 && line_no != no)
        //if (row_id_map_[i] == 0)
            break;

        if (i % detail_line == 0)
            SCGrid->Cells[0][i] = no;

        row_lineno_map_[i] = no;
        old_id = row_id_map_[i];
    }

    SCGrid->SetFocus();
    SCGrid->Col = 1;
    //SCGrid->Row = (no - 1) * detail_line;
    SCGrid->Row = calc_row;

    // グリッドを編集可にする
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;
}
//---------------------------------------------------------------------------
// 行挿入用の関数
bool __fastcall TMainForm::LoadFromID_Insert(int id, int insert_line_no)
{
    AnsiString sql;
    Currency   slip_no;
    int        date;

    slip_no = ToCurrency(DM->DBI.Lookup("D_計量", "計量ID", id, "伝票No"));
    date    = ToInt(DM->DBI.Lookup("D_計量", "計量ID", id, "計量日"));

    sql = " SELECT * FROM V_計量"
          " WHERE"
          "     計量日 = " + IntToStr(date) +
          " AND"
          "     伝票No = " + CurrToStr(slip_no) +
          " AND"
          "     完了区分 <> 9" // 論理削除は対象外
          " ORDER BY"
          "     行No";

    if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
        return false;

    KeiryoDatePicker->Date = IntToDate(ToInt(SET_TOP(keiryo_set_)["計量日"]));
    KeiryoNoEdit->Text     = ToInt(SET_TOP(keiryo_set_)["伝票No"]);

    car_id_                = ToInt(SET_TOP(keiryo_set_)["車両ID"]);
    ShabanEdit->Text       = ToInt(SET_TOP(keiryo_set_)["車番"]);
    SharyoNameEdit->Text   = ToString(SET_TOP(keiryo_set_)["車両名称"]);

    TokuCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["得意先コード"]));
    TokuNameEdit->Text     = ToString(SET_TOP(keiryo_set_)["得意先名称"]);
    Komoku1CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目1コード"]));
    Komoku1NameEdit->Text  = ToString(SET_TOP(keiryo_set_)["項目1名称"]);
    Komoku2CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目2コード"]));
    Komoku2NameEdit->Text  = ToString(SET_TOP(keiryo_set_)["項目2名称"]);
    BikoEdit->Text         = ToString(SET_TOP(keiryo_set_)["備考"]);
    HannyuCombo->ItemIndex = ToInt(SET_TOP(keiryo_set_)["搬入出区分"]) - 1;

    // 明細グリッドクリア
    ClearDetailGrid();

    // 明細表示
    CoordToNameMap::iterator ctnm;
    int row     = detail_line;
    int line_no = 0;

    for (unsigned int r = 0; r < keiryo_set_.size(); r++){
        line_no++;

        // 挿入行にきたら行Noを表示する
        if (r + 1 == (unsigned int)insert_line_no){
            SCGrid->Cells[0][row] = line_no;
            row += detail_line;
            line_no++;
        }

        // 1行目
        for (int col = 0; col < SCGrid->ColCount; col++){
            col_row_map_.clear();
            col_row_map_[col] = 1;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == col_row_map_.end()){ // セルに該当項目表示とRowに対して計量IDを入れておく
                SCGrid->Cells[col][row] = AnsiString();
                row_id_map_[row]        = 0;
            }else{
                if (col == 0) // 行No
                    SCGrid->Cells[col][row] = line_no;
                else if (ctnm->second == "品目マスタ名称" || ctnm->second == "明細備考")
                    SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                else
                    SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                row_id_map_[row]          = ToInt(keiryo_set_[r]["計量ID"]);
                row_lineno_map_[row]      = line_no;
            }
        }

        if (detail_line == 2){
            row++;
            keiryo_set_.clear();
            DM->DBI.GetRecordSet(sql, keiryo_set_);

            // 2行目
            for (int col = 0; col < SCGrid->ColCount; col++){
                col_row_map_.clear();
                col_row_map_[col] = 2;
                ctnm = coord_name_map_.find(col_row_map_);
                if (ctnm == coord_name_map_.end()){
                    SCGrid->Cells[col][row] = AnsiString();
                    row_id_map_[row]     = 0;
                }else{
                    if (ctnm->second == "明細備考" || ctnm->second == "単位マスタ名称")
                        SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                    else
                        SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                    row_id_map_[row]          = ToInt(keiryo_set_[r]["計量ID"]);
                    row_lineno_map_[row]      = line_no;
                }
            }
        }
        row++;
    }

    SCGrid->Col        = 1;
    SCGrid->Row        = insert_line_no * detail_line;
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;
    SCGrid->SetFocus();

    return true;
}
//---------------------------------------------------------------------------
// 計量IDからレコードをを読み込み
bool __fastcall TMainForm::LoadFromID(int id)
{
    AnsiString sql, place_name;
    Currency   slip_no;
    int        date, place_id;

    slip_no  = ToCurrency(DM->DBI.Lookup("D_計量", "計量ID", id, "伝票No"));
    date     = ToInt(DM->DBI.Lookup("D_計量", "計量ID", id, "計量日"));
    place_id = ToInt(DM->DBI.Lookup("D_計量", "計量ID", id, "拠点ID"));
    place_name = ToString(DM->DBI.Lookup("M_拠点", "拠点ID", place_id, "拠点名称"));

    sql = " SELECT * FROM V_計量"
          " WHERE"
          "     計量日 = " + IntToStr(date) +
          " AND"
          "     伝票No = " + CurrToStr(slip_no) +
          " AND"
          "     拠点ID = " + IntToStr(place_id) +
          " AND"
          "     完了区分 <> 9" // 論理削除は対象外
          " ORDER BY"
          "     行No";

    if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
        return false;

    KeiryoDatePicker->Date = IntToDate(ToInt(SET_TOP(keiryo_set_)["計量日"]));
    KeiryoNoEdit->Text     = ToInt(SET_TOP(keiryo_set_)["伝票No"]);

    // 完了データ以外は今の時間を表示
    if (ToInt(SET_TOP(keiryo_set_)["完了区分"]) == 1)
        KeiryoTimePicker->Time = GetLastKeiryoTime(date, slip_no, place_id);
    else
        KeiryoTimePicker->Time = Now();

    PlaceCombo->ItemIndex  = PlaceCombo->Items->IndexOf(place_name);

    car_id_                = ToInt(SET_TOP(keiryo_set_)["車両ID"]);
    ShabanEdit->Text       = ToInt(SET_TOP(keiryo_set_)["車番"]);
    SharyoNameEdit->Text   = ToString(SET_TOP(keiryo_set_)["車両名称"]);

    TokuCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["得意先コード"]));
    TokuNameEdit->Text     = ToString(SET_TOP(keiryo_set_)["得意先名称"]);
	Komoku1CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目1コード"]));
    Komoku2CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目2コード"]));
    BikoEdit->Text         = ToString(SET_TOP(keiryo_set_)["備考"]);
    HannyuCombo->ItemIndex = ToInt(SET_TOP(keiryo_set_)["搬入出区分"]) - 1;

    // 明細グリッドクリア
    ClearDetailGrid();

    // 明細表示
    CoordToNameMap::iterator ctnm;
    int row = detail_line;
    row_id_map_.clear();

    for (unsigned int r = 0; r < keiryo_set_.size(); r++){

        // 1行目
        //for (int col = 0; col < SCGrid->ColCount; col++){
        for (int col = 0; col <= line_colcount_map_[1]; col++){
            col_row_map_.clear();
            col_row_map_[col] = 1;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == col_row_map_.end()){ // セルに該当項目表示とRowに対して計量IDを入れておく
                SCGrid->Cells[col][row] = AnsiString();
                row_id_map_[row]        = 0;
            }else{
                if (col == 0) // 行No
                    SCGrid->Cells[col][row] = r + 1;
                else if (ctnm->second == "品目マスタ名称" || ctnm->second == "明細備考")
                    SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                else
                    SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                row_id_map_[row]     = ToInt(keiryo_set_[r]["計量ID"]);
                row_lineno_map_[row] = r + 1;
            }
        }

        if (detail_line == 2){
            row++;
            keiryo_set_.clear();
            DM->DBI.GetRecordSet(sql, keiryo_set_);

            // 2行目
            //for (int col = 0; col < SCGrid->ColCount; col++){
            for (int col = 0; col <= line_colcount_map_[2]; col++){
                col_row_map_.clear();
                col_row_map_[col] = 2;
                ctnm = coord_name_map_.find(col_row_map_);
                if (ctnm == coord_name_map_.end()){
                    SCGrid->Cells[col][row] = AnsiString();
                    row_id_map_[row]        = 0;
                }else{
                    if (ctnm->second == "明細備考" || ctnm->second == "単位マスタ名称")
                        SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                    else
                        SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                    row_id_map_[row]     = ToInt(keiryo_set_[r]["計量ID"]);
                    row_lineno_map_[row] = r + 1;
                }
            }
        }
        row++;
    }

    // 合計欄の更新
    TotalWeightLabel->Caption = FormatFloat("#,##0 kg", GetTotalWeight());
    GetTotalMoney();

    return true;
}
//---------------------------------------------------------------------------
// 新規計量開始
void __fastcall TMainForm::StartWeighing()
{
    ClearForm();

    SetMode(imFirst);

    KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// 継続（滞留車）計量開始
void __fastcall TMainForm::ContinueWeighing(int id)
{
    ClearForm();
    SetMode(imSecond);
    ShabanEdit->SetFocus();

    keiryo_id_ = id;
    if (!LoadFromID(keiryo_id_)){
        Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    switch (ToInt(SET_TOP(keiryo_set_)["完了区分"])){
    case 0:  // 滞留車
        break;
    case 1:  // 完了済
        Application->MessageBox("この滞留車はすでに計量されています。\r\n別PCなどで計量されていないか確認してください。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    default: // 削除済
        Application->MessageBox("滞留データの読み込みに失敗しました。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    TNotifyEvent OnExit = ShabanEdit->OnExit;
    ShabanEdit->OnExit  = 0;

    //SecondWEdit->Text = cur_weight_;

    //CalcWeight();

    int meisai_max_no = keiryo_set_.size();
    if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible){
        TokuCodeEdit->SetFocus();
    }else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible){
        Komoku1CodeEdit->SetFocus();
    }else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible){
        Komoku2CodeEdit->SetFocus();
    //}else if (ToInt(keiryo_set_[keiryo_set_.size()]["2回目重量"]) != 0){
    }else if (ToInt(keiryo_set_[meisai_max_no - 1]["2回目重量"]) != 0){
        MeisaiAddButton->OnClick(NULL);
    }else if (ToInt(keiryo_set_[meisai_max_no - 1]["品目コード"]) == 0){
        int row = keiryo_set_.size() * detail_line;

        SCGrid->SetFocus();
        SCGrid->Row = row;
        SCGrid->Col = GetColNo("品目コード");
        SCGrid->Options = SCGrid->Options << goEditing;
    }else{
        int row = keiryo_set_.size() * detail_line;

        SCGrid->SetFocus();
        SCGrid->Row     = row;
        SCGrid->Col     = GetColNo("2回目重量");
        SCGrid->Cells[GetColNo("2回目重量")][row] = cur_weight_;
        //Sleep(100);
        SCGrid->Options = SCGrid->Options << goEditing;
    }

    ShabanEdit->OnExit  = OnExit;
}
//---------------------------------------------------------------------------
// 列ごとにデータ変更があったかチェック
void __fastcall TMainForm::UpdateCheck()
{
    // row_id_map_  … 行No毎のIDを格納
    // id_edit_map_ … ID毎にデータ変更(1:あり,0:なし)を格納

    int show_max_line_no = GetMaxLineNo();

    // 各行各セルごとに呼出時と違うデータあるかチェックする
    int row = detail_line;
    CoordToNameMap::iterator ctnm;
    id_edit_map_.clear(); // 編集Map初期化
    for (int i = 0; i < show_max_line_no; i++){

        // 1行目
        for (int c = 0; c < SCGrid->ColCount; c++){
            col_row_map_.clear();
            col_row_map_[c] = 1;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == coord_name_map_.end())
                break;

            if (ctnm->second == "品目マスタ名称" || ctnm->second == "単位マスタ名称" || ctnm->second == "明細備考"){
                if (SCGrid->Cells[c][row] != ToString(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }else{
                if (StrToCurrDef(SCGrid->Cells[c][row], 0) != ToCurrency(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }
        }
        row++;

        // 行表示が1行 又は 1行目に変更項目があったら次のループ
        if (detail_line < 2 || id_edit_map_[row_id_map_[row - 1]] == 1)
            continue;


        // 2行目
        for (int c = 0; c < SCGrid->ColCount; c++){
            col_row_map_.clear();
            col_row_map_[c] = 2;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == coord_name_map_.end())
                break;

            if (ctnm->second == "明細備考"){
                if (SCGrid->Cells[c][row] != ToString(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }else{
                if (StrToCurrDef(SCGrid->Cells[c][row], 0) != ToCurrency(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }
        }
        row++;
    }
}
//---------------------------------------------------------------------------
// 入力データチェック
bool __fastcall TMainForm::CheckEdit()
{
    int row_no;

    // 表示されている最大行数取得からRow取得
    for (int r = detail_line; r < max_row; r += detail_line){
        if (!SCGrid->Cells[0][r].IsEmpty())
            row_no = SCGrid->Cells[0][r].ToIntDef(0);
    }
    row_no = row_no * detail_line;

    // 20120614 新規で1回目重量登録の場合は、車番と1回目重量に数値が入っていれば登録可にする
    if (row_no == detail_line && GetMode() == imFirst){
        Currency f_weight = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", row_no)], 0);
        if (f_weight > 0)
            return true;
    }
/*
    CellsMap::iterator   cm;
    ColInfoMap::iterator cim;
    for (int row = detail_line; row <= row_no; row += detail_line){

        // 品目コードチェック
        if (SCGrid->Cells[GetColNo("品目コード")][CalcRowNo("品目コード", row)].ToIntDef(0) == 0){
            Application->MessageBox("品目コードを入力してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SCGrid->SetFocus();
            SCGrid->Col = GetColNo("品目コード");
            SCGrid->Row = CalcRowNo("品目コード", row);
            return false;
        }

        // 明細備考は20byteで強制的に切り詰める
        SCGrid->Cells[GetColNo("明細備考")][CalcRowNo("明細備考", row)] = DM->AdjustString(SCGrid->Cells[GetColNo("明細備考")][CalcRowNo("明細備考", row)], 20);
    }
*/
    for (int row = detail_line; row <= row_no; row += detail_line){
        // 明細備考は20byteで強制的に切り詰める
        SCGrid->Cells[GetColNo("明細備考")][CalcRowNo("明細備考", row)] = DM->AdjustString(SCGrid->Cells[GetColNo("明細備考")][CalcRowNo("明細備考", row)], 20);
    }

    return true;
}
//---------------------------------------------------------------------------
// 計量登録
void __fastcall TMainForm::PostWeighing()
{
    ///// 明細のデータ登録条件は、銘柄が選択されていたら登録対象
    // 20120614追加
    // 1明細目の1回目重量の登録は銘柄選択なしでも登録する

    InputMode mode = GetMode();

    TDateTime now(Now());
    int place_id = ToInt(DM->DBI.Lookup("M_拠点", "拠点名称", PlaceCombo->Items->Strings[PlaceCombo->ItemIndex], "拠点ID"));
    int print_id; // 印刷する計量ID

    if (!CheckOverload())
        return;

    if (!ValidateForm())
        return;

    // 登録対象の最大行No取得(銘柄コードで判別)
    int max_meisai_no = GetMaxLineNo_M();

    Currency w1, w2, net;
    w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", SCGrid->Row)], 0);
    w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", SCGrid->Row)], 0);
    net = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", SCGrid->Row)],  0);

    bool comp;
    int  value;

    // 登録する明細行が最大行かをチェック
    PostConfForm->ButtonKeizoku->Enabled = true;
    if (max_meisai_no == max_line_no_)
        PostConfForm->ButtonKeizoku->Enabled = false;

    value = PostConfForm->ShowModal();
    if (value == IDYES)     // 完了ボタン
        comp = true;
    else if (value == IDNO) // 継続ボタン
        comp = false;
    else                    // キャンセルボタン
        return;

    int toku_id, hin_id, item1_id, item2_id, slip_tax;
    AnsiString toku_name, hin_name, item1_name, item2_name;
    AnsiString msg;

    toku_id    = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0),    "得意先ID"));
    toku_name  = TokuNameEdit->Text;
    item1_id   = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード",   Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    item1_name = Komoku1NameEdit->Text;
    item2_id   = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード",   Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    item2_name = Komoku2NameEdit->Text;

    // 明細の数だけ登録
    int row = detail_line;
    int register_keiryo_no  = 0;
    int line_no;
    //int torihiki_slip_no    = DM->GetTransNo(place_id, DateToInt(KeiryoDatePicker->Date)); // 取引伝票No取得しておく
    int before_slip_no      = KeiryoNoEdit->Text.ToIntDef(0);
    int post_slip_no        = 0;
    TDateTime old_second_time; // 前の明細の計量時間2
    bool create_tran_data   = false;


    NsFieldSet fields;
    if (new_car_){
        //////////////////////////////////////////////////////////////////////
        // 新規車両の場合、車両マスタを更新

        new_car_fields_
            << NsField("[車両名称]",   SharyoNameEdit->Text)
            << NsField("[使用区分]",   1)
            << NsField("[更新日時]",   now)
            << NsField("[作成日時]",   now)
            ;
        DM->DBI.Insert("M_車両", new_car_fields_);
        //DM->DBI.Update("M_車両", "車両ID", car_id_, fields);

        car_id_ = DM->DBI.GetLastID();
    }

    fields.clear();

    DM->ADOConnection->BeginTrans();
    // 明細削除があった場合は、明細を削除してから登録する
    if (delete_flag_){
        NsFieldSet keys;
        keys << NsField("[計量日]", DateToInt(KeiryoDatePicker->Date))
             << NsField("[伝票No]", IntToStr(before_slip_no))
             << NsField("[拠点ID]", place_id);
        try{
            DM->DBI.Delete("D_計量", keys);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("明細データ削除に失敗しました\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
    }
    delete_flag_ = false;

    for (int i = 1; i <= max_meisai_no; i++){ // iはRowNoに割り当て

        w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (row * i))], 0);
        w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (row * i))], 0);
        net = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", (row * i))],   0);

        line_no  = i;
        hin_id   = ToInt(DM->DBI.Lookup("M_品目", "品目コード", SCGrid->Cells[GetColNo("品目コード")][CalcRowNo("品目コード", (row * i))].ToIntDef(0), "品目ID"));
        hin_name = SCGrid->Cells[GetColNo("品目マスタ名称")][CalcRowNo("品目マスタ名称", (row * i))];

        NsFieldSet torihiki_fields;
        fields.clear();
        fields << NsField("[車両ID]",     car_id_)
               << NsField("[得意先ID]",   toku_id)
               << NsField("[得意先名称]", toku_name)
               << NsField("[項目1ID]",    item1_id)
               << NsField("[項目1名称]",  item1_name)
               << NsField("[項目2ID]",    item2_id)
               << NsField("[項目2名称]",  item2_name)
               << NsField("[備考]",       BikoEdit->Text)

               // 明細データ
               << NsField("[行No]",       line_no)
               << NsField("[品目ID]",     hin_id)
               << NsField("[品目名称]",   hin_name)
               //<< NsField("[搬入出区分]", HannyuCombo->ItemIndex + 1)
        ;

        // 20120530 制御マスタの入出庫使用区分の処理
        // 入出庫使用区分を「使用しない」にした場合は全て1:搬入で登録
        if (ToBit(DM->CFG["入出庫使用区分"]))
            fields << NsField("[搬入出区分]", HannyuCombo->ItemIndex + 1);
        else
            fields << NsField("[搬入出区分]", 1);

        // 計量IDを取得
        NsRecordSet set;
        AnsiString  sql;
        sql = " SELECT"
              "     *"
              " FROM"
              "     D_計量"
              " WHERE"
              "     計量日 = " + KeiryoDatePicker->Date.FormatString("yyyymmdd") +
              " AND"
              "     拠点ID = " + IntToStr(place_id) +
              " AND"
              "     伝票No = " + IntToStr(before_slip_no) + // 登録前に伝票番号をEditに上書きするので変数にした
              " AND"
              "     行No = "   + IntToStr(line_no) +
              " AND"
              "     完了区分 <> 9";
        if (!DM->DBI.GetRecordSet(sql, set)){
            keiryo_id_ = 0;
        }else{
            keiryo_id_ = ToInt(SET_TOP(set)["計量ID"]);

            if (ToString(SET_TOP(set)["計量日時2"]) == "")
                old_second_time = now;
            else
                old_second_time = ToString(SET_TOP(set)["計量日時2"]);
        }

        if (!ToBit(DM->CFG["調整使用区分"])){
            fields << NsField("[調整率]",   0)
                   << NsField("[調整重量]", 0);
        }else{
            fields << NsField("[調整率]",   StrToCurrDef(SCGrid->Cells[GetColNo("調整率")][CalcRowNo("調整率", (row * i))], 0))
                   << NsField("[調整重量]", StrToCurrDef(SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", (row * i))], 0));
        }

        if (!ToBit(DM->CFG["重量引き使用区分"]))
            fields << NsField("[重量引き]", 0);
        else
            fields << NsField("[重量引き]", StrToCurrDef(SCGrid->Cells[GetColNo("重量引き")][CalcRowNo("重量引き", (row * i))], 0));

        fields << NsField("[正味重量]", net)
               << NsField("[明細備考]", SCGrid->Cells[GetColNo("明細備考")][CalcRowNo("明細備考", (row * i))]);

        if (!ToBit(DM->CFG["単価使用区分"])){
            fields << NsField("[単位ID]",       0)
                   << NsField("[数量]",         0)
                   << NsField("[単価]",         0)
                   << NsField("[金額]",         0)
                   << NsField("[消費税額]",     0)
                   << NsField("[伝票消費税額]", 0);
        }else{
            fields << NsField("[単位ID]",       ToInt(DM->DBI.Lookup("M_単位", "単位コード", SCGrid->Cells[GetColNo("単位コード")][CalcRowNo("単位コード", (row * i))].ToIntDef(0), "単位ID")))
                   << NsField("[数量]",         StrToCurrDef(SCGrid->Cells[GetColNo("数量")][CalcRowNo("数量", (row * i))], 0))
                   << NsField("[単価]",         StrToCurrDef(SCGrid->Cells[GetColNo("単価")][CalcRowNo("単価", (row * i))], 0))
                   << NsField("[金額]",         SCGrid->Cells[GetColNo("金額")][CalcRowNo("金額", (row * i))].ToIntDef(0))
                   << NsField("[消費税額]",     SCGrid->Cells[GetColNo("消費税額")][CalcRowNo("消費税額", (row * i))].ToIntDef(0))
                   << NsField("[伝票消費税額]", slip_tax_);
        }

        int cmp_kbn;

        try{

            if (mode == imFirst){  //***** 初回計量
                fields << NsField("[計量日]",   DateToInt(KeiryoDatePicker->Date))
                       << NsField("[拠点ID]",   place_id)
                       << NsField("[更新日時]", now)
                       << NsField("[作成日時]", now)
                ;

                if (!comp){        // 1回目計量
                    if (post_slip_no == 0){
                        KeiryoNoEdit->Text = DM->GetTempNo(place_id);
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    fields << NsField("[伝票No]",    post_slip_no)
                           << NsField("[1回目重量]", w1)
                           << NsField("[計量日時1]", now)
                           << NsField("[完了区分]",  0)
                    ;

                    if (w2 != 0){  // 2回目重量が0以外なら登録する
                        fields << NsField("[2回目重量]", w2)
                               << NsField("[計量日時2]", now);
                    }

                    msg = "滞留車として登録しました";
                }else{             // 全登録
                    if (post_slip_no == 0){
                        KeiryoNoEdit->Text = DM->GetKeiryoNo(place_id, DateToInt(KeiryoDatePicker->Date));
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    fields << NsField("[伝票No]",    post_slip_no)
                           << NsField("[1回目重量]", w1)
                           << NsField("[2回目重量]", w2)
                           << NsField("[計量日時1]", now)
                           << NsField("[計量日時2]", now)
                           << NsField("[完了区分]",  1)
                    ;
                    msg = "計量が完了しました";
                    create_tran_data = ToInt(DM->CFG["取引データ作成"]) ? true : false;
                }

                DM->DBI.Insert("D_計量", fields);
                keiryo_id_ = DM->DBI.GetLastID();

            }else if (mode == imSecond){            //***** 滞留車
                if (!comp){ // 滞留車登録
                    fields << NsField("[1回目重量]", w1)
                           << NsField("[2回目重量]", w2)
                           << NsField("[完了区分]",  0);
                    msg = "滞留情報を更新しました";
                }else{      // 完了登録
                    if (register_keiryo_no == 0)
                        register_keiryo_no = DM->GetKeiryoNo(place_id, DateToInt(KeiryoDatePicker->Date));

                    fields << NsField("[計量日]",    DateToInt(KeiryoDatePicker->Date))
                           << NsField("[拠点ID]",    place_id)
                           << NsField("[伝票No]",    register_keiryo_no)
                           << NsField("[1回目重量]", w1)
                           << NsField("[2回目重量]", w2)
                           << NsField("[完了区分]",  1);
                    msg = "計量が完了しました";
                    create_tran_data = ToInt(DM->CFG["取引データ作成"]) ? true : false;
                }

                // 計量IDが0だったら計量日時1,2を登録
                if (keiryo_id_ == 0){
                    fields << NsField("[計量日時1]", old_second_time);

                    old_second_time = now;
                    fields << NsField("[計量日時2]", old_second_time);
                }

                // 行NoからID取得して、変更があったら更新日時登録
                if (id_edit_map_[row_id_map_[row * i]] != 0)
                    fields << NsField("[更新日時]", now);

                if (keiryo_id_ != 0){
                    // 1明細目で2回目重量が0以外の時は計量日時2を登録
                    if (max_meisai_no == 1 && line_no == 1 && w2 != 0){
                        old_second_time = now;
                        fields << NsField("[計量日時2]", GetTimePicker_ZeroSec());
                    }

                    DM->DBI.Update("D_計量", "計量ID", keiryo_id_, fields);
                }else if (comp){
                    fields << NsField("[作成日時]",  now);

                    DM->DBI.Insert("D_計量", fields);
                    keiryo_id_ = DM->DBI.GetLastID();
                }else{
                    if (register_keiryo_no == 0)
                        register_keiryo_no = before_slip_no;

                    fields << NsField("[計量日]",   DateToInt(KeiryoDatePicker->Date))
                           << NsField("[拠点ID]",   place_id)
                           << NsField("[伝票No]",   register_keiryo_no)
                           << NsField("[作成日時]", now);
                    DM->DBI.Insert("D_計量", fields);
                    keiryo_id_ = DM->DBI.GetLastID();
                }

            }else if (mode == imMod){               //***** 修正
                cmp_kbn = ToInt(keiryo_set_[i - 1]["完了区分"]);
                TDateTime date1, date2;

                fields << NsField("[1回目重量]", w1)
                       << NsField("[2回目重量]", w2);

                if (id_edit_map_[row_id_map_[row * i]] != 0)
                    fields << NsField("[更新日時]", now);

                int date = DateToInt(KeiryoDatePicker->Date);
                if (comp){
                    ///// 完了区分 /////
                    if (post_slip_no == 0 && cmp_kbn == 0){ // 完了区分が登録前と違う時、計量No取得
                        int no = DM->GetKeiryoNo(place_id, date);
                        KeiryoNoEdit->Text = no;
                        post_slip_no = no;
                    }else if (post_slip_no == 0){
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    if (cmp_kbn == 0 && keiryo_id_ != 0){
                        fields << NsField("[計量日]",   date)
                               << NsField("[拠点ID]",   place_id)
                               << NsField("[伝票No]",   post_slip_no);
                    }
                    fields << NsField("[完了区分]", 1);
                    create_tran_data = ToInt(DM->CFG["取引データ作成"]) ? true : false;
                }else{
                    ///// 滞留車登録 /////
                    if (post_slip_no == 0 && cmp_kbn == 1){ // 完了区分が登録前と違う時、計量No取得
                        KeiryoNoEdit->Text = DM->GetTempNo(place_id);
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }else if (post_slip_no == 0){
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    if (cmp_kbn == 1 && keiryo_id_ != 0){
                        fields << NsField("[計量日]",   date)
                               << NsField("[拠点ID]",   place_id)
                               << NsField("[伝票No]",   post_slip_no);
                    }
                    fields << NsField("[完了区分]", 0);
                    create_tran_data = false;
                }

                // 修正モードで新たに作成した行の処理
                if (keiryo_id_ == 0){
                    fields << NsField("[計量日]",    date)
                           << NsField("[拠点ID]",    place_id)
                           << NsField("[伝票No]",    post_slip_no)
                           << NsField("[計量日時1]", now)
                           << NsField("[作成日時]",  now);

                    if (max_meisai_no == i)
                        fields << NsField("[計量日時2]", GetTimePicker_ZeroSec());
                    else
                        fields << NsField("[計量日時2]", now);
                }

                // 最後の明細データの計量時間2に印字計量時間を上書きする
                if (keiryo_id_ != 0 && max_meisai_no == i)
                    fields << NsField("[計量日時2]", GetTimePicker_ZeroSec());

                msg = "登録しました";

                if (keiryo_id_ != 0){
                    DM->DBI.Update("D_計量", "計量ID", keiryo_id_, fields);
                }else{
                    DM->DBI.Insert("D_計量", fields);
                    keiryo_id_ = DM->DBI.GetLastID();
                }

            }else{
                return;
            }

            ///// 取引データ作成
            if (mode == imMod && create_tran_data && ToInt(DM->CFG["取引データ作成"])){
	    		if (Application->MessageBox("売上データも登録/修正しますか？", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
                    create_tran_data = false;
            }

            if (create_tran_data){

                NsRecordSet set;
                AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id_);
                DM->DBI.GetRecordSet(sql, set);

                fields.clear();
                fields << NsField("[取引日]",       SET_TOP(set)["計量日"])
                       << NsField("[拠点ID]",       SET_TOP(set)["拠点ID"])
                       << NsField("[伝票No]",       DM->GetTransNo(ToInt(SET_TOP(set)["拠点ID"]), ToInt(SET_TOP(set)["計量日"])))
                       << NsField("[計量ID]",       keiryo_id_)
                       << NsField("[取引区分]",     ToInt(SET_TOP(set)["取引区分"]))
                       << NsField("[車両ID]",       SET_TOP(set)["車両ID"])
                       << NsField("[得意先ID]",     SET_TOP(set)["得意先ID"])
                       << NsField("[得意先名称]",   SET_TOP(set)["得意先名称"])
                       << NsField("[項目1ID]",      SET_TOP(set)["項目1ID"])
                       << NsField("[項目1名称]",    SET_TOP(set)["項目1名称"])
                       << NsField("[項目2ID]",      SET_TOP(set)["項目2ID"])
                       << NsField("[項目2名称]",    SET_TOP(set)["項目2名称"])
                       << NsField("[備考]",         SET_TOP(set)["備考"])
                       << NsField("[伝票消費税額]", SET_TOP(set)["伝票消費税額"])
                       << NsField("[行No]",         SET_TOP(set)["行No"])
                       << NsField("[品目ID]",       SET_TOP(set)["品目ID"])
                       << NsField("[品目名称]",     SET_TOP(set)["品目名称"])
                       << NsField("[数量]",         SET_TOP(set)["数量"])
                       << NsField("[単位ID]",       SET_TOP(set)["単位ID"])
                       << NsField("[単価]",         SET_TOP(set)["単価"])
                       << NsField("[金額]",         SET_TOP(set)["金額"])
                       << NsField("[消費税額]",     SET_TOP(set)["消費税額"])
                       << NsField("[明細備考]",     SET_TOP(set)["明細備考"])
                       << NsField("[完了区分]",     1)
                       << NsField("[更新日時]",     now)
                       ;
                if (!DM->DBI.IsExist("D_取引", "計量ID", keiryo_id_)){
                    fields << NsField("[作成日時]", now);
                    DM->DBI.Insert("D_取引", fields);
                }else{
                    DM->DBI.Update("D_取引", "計量ID", keiryo_id_, fields);
                }
            }
        }catch(Exception& e){
            DM->ADOConnection->RollbackTrans();
            AnsiString msg = "登録時にエラーが発生しました - " + e.Message;
            Application->MessageBox(msg.c_str(), "登録エラー", MB_OK | MB_ICONWARNING);
            return;
        }
    }
    DM->ADOConnection->CommitTrans();

    // 滞留車情報更新
    Q_Tairyu->Close();
    Q_Tairyu->Open();

    // 登録メッセージ
    // 各登録部分にメッセージ変数入れてここで表示する
    Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    print_id = GetHeaderID(keiryo_id_);

    if (mode != imMod){
        if (comp && AutoPrintCheck->Checked)
            Print(print_id);
    }else{
        if (!comp){
            LoadFromID(keiryo_id_);
            return;
        }

        if (AutoPrintCheck->Checked){
            if (Application->MessageBox("修正した伝票を発行しますか？", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES)
                Print(print_id);
        }
    }

    Action1->Execute();
}
//---------------------------------------------------------------------------
// 伝票発行
// 制御マスタの金額印字区分(money_print_div_に格納)
// 0:印字しない 1:現金のみ 2:掛のみ 3:常に印字する
void __fastcall TMainForm::Print(int keiryo_id)
{
    int slip_type    = ToInt(DM->CFG["伝票発行プリンタ"]);
    //int tokuisaki_id = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id, "得意先ID"));
    //int pay_div      = ToInt(DM->DBI.Lookup("M_得意先", "得意先ID", tokuisaki_id, "現掛区分")); // 1:掛 2:現金

    if (slip_type == 1){
        // レーザー

        int slip_info_id = DM->GetPrintInfo(keiryo_id);
        NsRecordSet set;
        if (!DM->DBI.GetRecordSet("SELECT * FROM M_伝票情報 WHERE 伝票情報ID = " + IntToStr(slip_info_id), set)){
            // 伝票情報マスタがない場合は、金額印字なし
            if (LaserSlipPrintM_KakeForm->Print(keiryo_id, HideTimeCheck->Checked))
                return;
        }

        // 伝票情報マスタの金額印字区分が全てfalseだったら金額枠無しのフォームで印字
        if (!ToBit(SET_TOP(set)["金額印字区分1"]) && !ToBit(SET_TOP(set)["金額印字区分2"])
                && !ToBit(SET_TOP(set)["金額印字区分3"])){
            if (LaserSlipPrintM_KakeForm->Print(keiryo_id, HideTimeCheck->Checked))
                return;
        }else{
            if (LaserSlipPrintM_GenkinForm->Print(keiryo_id, HideTimeCheck->Checked))
                return;
        }

    }else if (slip_type == 2){
        // ドット

        if (!DotSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
            return;

    }else{
        // nothing to do
    }

    if (GetMode() != imMod && DataDeleteCheck->Checked){
        NsRecordSet set;
        AnsiString  sql;
        int date, place_id, slip_no;

        if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id), set)){
            Application->MessageBox("データ呼出に失敗しました\r\n手動でデータを削除してください", Caption.c_str(), MB_OK | MB_ICONWARNING);
                return;
        }

        date     = ToInt(SET_TOP(set)["計量日"]);
        place_id = ToInt(SET_TOP(set)["拠点ID"]);
        slip_no  = ToInt(SET_TOP(set)["伝票No"]);
        sql = " DELETE"
              "     FROM D_計量"
              " WHERE"
              "     計量日 = " + IntToStr(date) +
              " AND"
              "     拠点ID = " + IntToStr(place_id) +
              " AND"
              "     伝票No = " + IntToStr(slip_no);
        DM->ADOConnection->BeginTrans();
        if (!DM->DBI.Execute(sql)){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox("データ削除に失敗しました\r\n手動でデータを削除してください", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
        DM->ADOConnection->CommitTrans();
    }
}
//---------------------------------------------------------------------------
// 各項目の値チェック
bool __fastcall TMainForm::ValidateForm()
{
    AnsiString sql;
    NsRecordSet set;
    int n;

    if (!new_car_){
        if (car_id_ < 1){
            Application->MessageBox("車両の選択が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }

        sql = "SELECT 車両名称 FROM M_車両 WHERE 車両ID = " + IntToStr(car_id_);
        if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("車両の選択が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }
        if (ToString(SET_TOP(set)["車両名称"]) != SharyoNameEdit->Text){
            Application->MessageBox("もう一度車両の選択をしてください", Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }
    }

    return true;
}
//---------------------------------------------------------------------------
// 過積載チェック
bool __fastcall TMainForm::CheckOverload()
{
    //Currency w1  = StrToCurrDef(FirstWEdit->Text, 0);
    //Currency w2  = StrToCurrDef(SecondWEdit->Text, 0);
    //Currency net = StrToCurrDef(ShomiEdit->Text, 0);
    //Currency max = std::max(w1, w2);
    Currency w1, w2, net, max, car_gross_weight = 0, max_net_weight = 0;

    int line_no = GetMaxLineNo_M() + 1;
    for (int i = 1; i < line_no; i++){
        w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (detail_line * i))], 0);
        w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (detail_line * i))], 0);
        net = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", (detail_line * i))],   0);
        max = std::max(w1, w2);

        if (max > car_gross_weight)
            car_gross_weight = max;

        if (net > max_net_weight)
            max_net_weight = net;
    }

    AnsiString msg;

    if (gross_limit_ > 0 && max > gross_limit_){
        msg = "車両総重量に対する過積載です\r\n\r\n"
              "現在の重量: " + FormatFloat("###,##0.#' kg'", max) + "\r\n"
              "車両総重量: " + FormatFloat("###,##0.#' kg'", gross_limit_);
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }

    if (net > 0 && net_limit_ > 0 && net > net_limit_){
        msg = "最大積載量に対する過積載です\r\n\r\n"
              "現在の重量: " + FormatFloat("###,##0.#' kg'", net) + "\r\n"
              "最大積載量: " + FormatFloat("###,##0.#' kg'", net_limit_);
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------
// 数量等算出に必要な情報を取得
void __fastcall TMainForm::GetCalcInfo()
{
/*
    if (GetMode() == imMod)
        return;

    int meig_id  = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目ID"));

    TaniCodeEdit->Text = DM->GetKanzanCode(toku_id_, meig_id);
*/
}
//---------------------------------------------------------------------------
// 正味重量計算
void __fastcall TMainForm::CalcWeight(int row)
{
    // 明細グリッドのタイトルが消えてしまうので
    // detail_lineより小さいrowはreturn
    if (row < detail_line)
        return;

    int w1, w2, net;

    try{
        w1 = StrToCurr(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", row)]);
        w2 = StrToCurr(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", row)]);
    }catch(...){
        SCGrid->Cells[GetColNo("正味重量")][row] = AnsiString();

        if (ToBit(DM->CFG["単価使用区分"]))
            SCGrid->Cells[GetColNo("数量")][row] = AnsiString();

        return;
    }

    net = std::abs(w1 - w2);

    if (ToBit(DM->CFG["調整使用区分"])){
        Currency coord, coord_ratio;

        coord       = SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", row)].ToIntDef(0);
        coord_ratio = StrToCurrDef(SCGrid->Cells[GetColNo("調整率")][CalcRowNo("調整率", row)], 0) / 100;

        if (coord_ratio > 0){ // 調整率使用
            coord = ExtendedRound(net * coord_ratio, ToInt(DM->CFG["調整端数処理桁数"]), ToInt(DM->CFG["調整端数処理区分"]));
            SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", row)] = coord;
        }else{
            // 調整率0以下の場合は調整重量を0にするように
            coord = 0;
            SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", row)] = 0;
        }

        net -= int(coord);
    }

    if (ToBit(DM->CFG["重量引き使用区分"])){
        Currency reduc = StrToCurrDef(SCGrid->Cells[GetColNo("重量引き")][CalcRowNo("重量引き", row)], 0);
        net -= int(reduc);
    }

    SCGrid->Cells[GetColNo("正味重量")][row] = net;

    if (ToBit(DM->CFG["単価使用区分"]) && SCGrid->Cells[GetColNo("単位コード")][CalcRowNo("単位コード", row)].ToIntDef(0) == 0){
        SCGrid->Cells[GetColNo("単位コード")][CalcRowNo("単位コード", row)]     = standard_tani_code_;
        SCGrid->Cells[GetColNo("単位マスタ名称")][CalcRowNo("単位コード", row)] = ToString(DM->DBI.Lookup("M_単位", "単位コード", standard_tani_code_, "単位名称"));
    }

    // 合計重量計算
    TotalWeightLabel->Caption = FormatFloat("#,##0 kg", GetTotalWeight());

    if (ToBit(DM->CFG["単価使用区分"]))
        CalcAmount(row);
}
//---------------------------------------------------------------------------
// 数量と金額の計算
void __fastcall TMainForm::CalcAmount(int row)
{
    //if (GetMode() == imMod)
        //return;

    Currency net = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", row)], 0);
    int meig_id  = ToInt(DM->DBI.Lookup("M_品目",  "品目コード",  SCGrid->Cells[GetColNo("品目コード")][CalcRowNo("品目コード", row)].ToIntDef(0), "品目ID"));
    int item1_id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    int item2_id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    tani_id_     = 0;
    AnsiString tani_name = AnsiString();

    if (detail_line == 2){

        // 単位コードが0の場合は標準単位を入れる
        int tani_code = SCGrid->Cells[GetColNo("単位コード")][CalcRowNo("単位コード", row)].ToIntDef(0);
        if (tani_code == 0){
            int default_code = ToInt(DM->CFG["標準単位"]);

            if (!default_code)
                default_code = 3;

            SCGrid->Cells[GetColNo("単位コード")][CalcRowNo("単位コード", row)] = default_code;
        }

        tani_id_  = ToInt(DM->DBI.Lookup("M_単位", "単位コード", SCGrid->Cells[GetColNo("単位コード")][CalcRowNo("単位コード", row)].ToIntDef(0), "単位ID"));
        tani_name = ToString(DM->DBI.Lookup("M_単位", "単位ID", tani_id_, "単位名称"));
    }

    if (tani_id_ != 3)
        net = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", row)], 0) / Currency(1000);

    Currency quantity;
    Currency cnv_ratio = DM->GetKanzan(toku_id_, meig_id, tani_id_);

    ///// 換算端数処理区分の取得
    int cnv_div = -1;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["換算端数処理区分"]))
            cnv_div = ToInt(toku_rec_["換算端数処理区分"]);
    }
    if (cnv_div == -1)
        cnv_div = ToInt(DM->CFG["換算端数処理区分"]);
    /////

    if (cnv_ratio == 0){
        quantity = ExtendedRound(net,             ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
    }else{
        quantity = ExtendedRound(net / cnv_ratio, ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
    }

    if (quantity > ToCurrency(DM->CFG["上限m3数量"])
            && SCGrid->Cells[GetColNo("単位コード")][CalcRowNo("単位コード", row)].ToIntDef(0) == 2){
        quantity = ToCurrency(DM->CFG["上限m3数量"]);
    }

    SCGrid->Cells[GetColNo("数量")][CalcRowNo("数量", row)] = quantity;

    if (!ToBit(DM->CFG["単価使用区分"])){
        // 単価有効時のデータをいじるかもしれないのでコメンタウト
        //TankaEdit->Text    = "0";
        //KingakuEdit->Text  = "0";
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency tanka = StrToCurrDef(SCGrid->Cells[GetColNo("単価")][CalcRowNo("単価", row)], 0);
    tanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id_);

    ///// 金額端数処理区分の取得
    int amount_div = -1;
    int amount_fig = 0;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["金額端数処理区分"]))
            amount_div = ToInt(toku_rec_["金額端数処理区分"]);
    }
    if (amount_div == -1)
        amount_div = ToInt(DM->CFG["金額端数処理区分"]);
    if (amount_fig == 0)
        amount_fig = ToInt(DM->CFG["金額端数処理桁数"]);
    /////
    int amount = ExtendedRound(quantity * tanka, amount_fig, amount_div);


    //SCGrid->Cells[GetColNo("単価")][CalcRowNo("数量", row)] = tanka;
    //SCGrid->Cells[GetColNo("金額")][CalcRowNo("数量", row)] = amount;
    SCGrid->Cells[GetColNo("単価")][CalcRowNo("単価", row)] = tanka;
    SCGrid->Cells[GetColNo("金額")][CalcRowNo("金額", row)] = amount;

    CalcSalesTax(row);
}
//---------------------------------------------------------------------------
// 消費税算出
void __fastcall TMainForm::CalcSalesTax(int row)
{
    if (!ToBit(DM->CFG["単価使用区分"])){
        // 単価有効時のデータをいじるかもしれないのでコメンタウト
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency quantity, tanka;
    quantity = StrToCurrDef(SCGrid->Cells[GetColNo("数量")][CalcRowNo("数量", row)], 0);
    tanka    = StrToCurrDef(SCGrid->Cells[GetColNo("単価")][CalcRowNo("単価", row)], 0);
    ///// 金額端数処理区分の取得
    int amount_div = -1;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["金額端数処理区分"]))
            amount_div = ToInt(toku_rec_["金額端数処理区分"]);
    }
    if (amount_div == -1)
        amount_div = ToInt(DM->CFG["金額端数処理区分"]);
    /////

    int amount = ExtendedRound(quantity * tanka, 0, amount_div);

    SCGrid->Cells[GetColNo("単価")][CalcRowNo("数量", row)] = tanka;
    SCGrid->Cells[GetColNo("金額")][CalcRowNo("数量", row)] = amount;

	Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));          // 消費税率

    ///// 消費税端数処理区分の取得
    int tax_div = -1;
    int tax_fig = 0;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["消費税端数処理区分"]))
            tax_div = ToInt(toku_rec_["消費税端数処理区分"]);
    }
    if (tax_div == -1)
        tax_div = ToInt(DM->CFG["消費税端数処理区分"]);
    if (tax_fig == 0)
        tax_fig = ToInt(DM->CFG["消費税端数処理桁数"]);
    /////

    //int amount, tax;
    int tax;
    amount = SCGrid->Cells[GetColNo("金額")][CalcRowNo("金額", row)].ToIntDef(0);
    tax    = ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div);

    SCGrid->Cells[GetColNo("消費税額")][CalcRowNo("消費税額", row)] = tax;

    GetTotalMoney();
}
//---------------------------------------------------------------------------
// モード関連
//---------------------------------------------------------------------------
// モード設定
void __fastcall TMainForm::SetMode(InputMode mode)
{
    switch (mode){
    case imFirst:       // 新規
        ModePanel->Caption = "新規";
        ModePanel->Color   = TColor(0x00FDD8C6);

        KeiryoNoEdit->ReadOnly = false;
        break;
    case imSecond:      // 滞留
        ModePanel->Caption = "滞留";
        ModePanel->Color   = TColor(0x00A6FFFF);

        KeiryoNoEdit->ReadOnly = true;
        break;
    case imMod:         // 修正
        ModePanel->Caption = "修正";
        ModePanel->Color   = TColor(0x00CEF4D0);

        KeiryoNoEdit->ReadOnly = true;
        break;
/*
    case imDelete:      // 削除
        ModePanel->Caption = "削除";
        ModePanel->Color   = TColor(0x009B9BFF);
        break;
*/
    }
}
//---------------------------------------------------------------------------
// モード取得
InputMode __fastcall TMainForm::GetMode()
{
    if (ModePanel->Caption == "新規")
        return imFirst;
    else if (ModePanel->Caption == "滞留")
        return imSecond;
    else if (ModePanel->Caption == "修正")
        return imMod;
/*
    else
        return imDelete;
*/
    return imFirst;
}
//---------------------------------------------------------------------------
// Control Event
//---------------------------------------------------------------------------
// Panel->OnEnter
void __fastcall TMainForm::SharyoPanelEnter(TObject *Sender)
{
    ((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
// Panel->OnExit
void __fastcall TMainForm::SharyoPanelExit(TObject *Sender)
{
    ((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------
// F1 新規
void __fastcall TMainForm::Action1Execute(TObject *Sender)
{
    Q_Tairyu->Close();
    Q_Tairyu->Open();

    StartWeighing();
    ClearDetailGrid();
}
//---------------------------------------------------------------------------
// F2 修正
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
    ClearForm();
    SetMode(imMod);

    // 同一拠点の最終レコードを取得
    keiryo_id_ = DM->GetLastKeiryoID(GetPlaceID());

    if (keiryo_id_ < 1){
        Application->MessageBox("修正するデータはありません",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    if (!LoadFromID(keiryo_id_)){
        Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F3 削除
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
    InputMode mode = GetMode();

    if (mode == imFirst || keiryo_id_ < 1)
        return;

    if (Application->MessageBox("この伝票を削除しますか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    NsRecordSet set;
    AnsiString  sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     D_計量"
          " WHERE"
          "     計量ID = " + IntToStr(keiryo_id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("データ抽出に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    NsFieldSet fields, key;
    fields << NsField("[伝票No]",   DM->GetTempNo(GetPlaceID()))
           << NsField("[完了区分]", 9);

    key    << NsField("[計量日]",   ToInt(SET_TOP(set)["計量日"]))
           << NsField("[伝票No]",   ToInt(SET_TOP(set)["伝票No"]))
           << NsField("[拠点ID]",   ToInt(SET_TOP(set)["拠点ID"]));

    DM->DBI.Update("D_計量", key, fields);

    if (mode == imSecond)
        Action1->Execute();
    else
        Action2->Execute();
}
//---------------------------------------------------------------------------
// F4
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
    if (ActiveControl != SCGrid){
    	if (ActiveControl == ShabanEdit)
	    	SharyoButton->Click();
    	else if (ActiveControl == TokuCodeEdit)
            TokuButton->Click();
        else if (ActiveControl == Komoku1CodeEdit)
            Komoku1Button->Click();
        else if (ActiveControl == Komoku2CodeEdit)
            Komoku2Button->Click();

        return;
    }

    AnsiString cell_name = GetCellName(SCGrid->Col, SCGrid->Row);
    if (cell_name == "品目コード" || cell_name == "品目マスタ名称"){
        // 品目マスタ参照
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT 品目コード, 品目名称 FROM M_品目 WHERE 使用区分 = 1";
        SearchForm->orderby_sql = " ORDER BY 品目コード ";
        SearchForm->table_name  = "M_品目";

        if (SearchForm->ShowModal() != mrOk){
            if (cell_name == "品目マスタ名称") // フォーカスが名称ならコードに移動する
                SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("品目コード")][SCGrid->Row]     = SearchForm->Query->FieldByName("品目コード")->AsInteger;
        SCGrid->Cells[GetColNo("品目マスタ名称")][SCGrid->Row] = SearchForm->Query->FieldByName("品目名称")->AsString;
        SCGrid->Col = GetColNo("品目コード");
        SetImeMode(SCGrid->Handle, imClose);
    }else if (cell_name == "単位コード" || cell_name == "単位マスタ名称"){
        // 単位マスタ参照
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT 単位コード, 単位名称 FROM M_単位";
        SearchForm->orderby_sql = " ORDER BY 単位コード ";
        SearchForm->table_name  = "M_単位";

        if (SearchForm->ShowModal() != mrOk){
            if (cell_name == "単位マスタ名称") // フォーカスが名称ならコードに移動する
                SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("単位コード")][SCGrid->Row]     = SearchForm->Query->FieldByName("単位コード")->AsInteger;
        SCGrid->Cells[GetColNo("単位マスタ名称")][SCGrid->Row] = SearchForm->Query->FieldByName("単位名称")->AsString;
        SCGrid->Col = GetColNo("単位コード");
        SetImeMode(SCGrid->Handle, imClose);
    }
}
//---------------------------------------------------------------------------
// F5 登録
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
    if (!CheckEdit())
        return;

    UpdateCheck();

    GetTotalMoney();
    PostWeighing();
}
//---------------------------------------------------------------------------
// F6 前へ
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
    int id;

    if (keiryo_id_){ // 修正、または滞留状態
        id = DM->GetPrevKeiryoID(GetPlaceID(),
            ToInt(SET_TOP(keiryo_set_)["計量日"]),
            ToInt(SET_TOP(keiryo_set_)["伝票No"]));
    }else{
        Action2->Execute();
        return;
    }

    if (id < 1)
        return;

    ClearForm();
    SetMode(imMod);

    keiryo_id_ = id;

    if (!LoadFromID(id)){
        Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F7 次へ
void __fastcall TMainForm::Action7Execute(TObject *Sender)
{
    int id;

    if (keiryo_id_){    // 修正、または滞留状態
        id = DM->GetNextKeiryoID(GetPlaceID(),
            ToInt(SET_TOP(keiryo_set_)["計量日"]),
            ToInt(SET_TOP(keiryo_set_)["伝票No"]));
    }else{
        Action2->Execute();
        return;
    }

    if (id < 1)
        return;

    ClearForm();
    SetMode(imMod);

    keiryo_id_ = id;

    if (!LoadFromID(id)){
        Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F8 伝票発行
void __fastcall TMainForm::Action8Execute(TObject *Sender)
{
    if (GetMode() != imMod || keiryo_id_ < 1)
        return;

    if (Application->MessageBox("伝票を発行しますか？", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    Print(keiryo_id_);
}
//---------------------------------------------------------------------------
// F9 検索
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
    if (DataListForm->ShowModal() != mrOk)
        return;

    ClearForm();
    SetMode(imMod);

    keiryo_id_ = DataListForm->selected_id;

    if (!LoadFromID(keiryo_id_)){
        Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F10 重量値取得
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
/*
    InputMode mode = GetMode();
    if (mode == imFirst){
        if (keiryo_count_ == 2 || keiryo_count_ == 0){
            FirstWEdit->Text = cur_weight_;
            FirstWEdit->SetFocus();
        }else{
            SecondWEdit->Text = cur_weight_;
            SecondWEdit->SetFocus();
        }
    }else if (mode == imSecond){
        SecondWEdit->Text = cur_weight_;
        SecondWEdit->SetFocus();
    }

    CalcWeight();
*/
    //if (SCGrid->Cells[0][detail_line].IsEmpty())
        //return;
    if (ShabanEdit->Text.ToIntDef(0) == 0)
        return;

    int current_row;
    InputMode mode = GetMode();
    if (mode == imFirst){
        // 新規

        // 1明細目に明細Noが出ていなかったら明細追加処理
        if (SCGrid->Cells[0][detail_line].IsEmpty())
            MeisaiAddButton->OnClick(NULL);

        current_row = detail_line;
        if (keiryo_count_ == 2 || keiryo_count_ == 0){
            SCGrid->Cells[3][detail_line] = cur_weight_; // 1回目重量に入れる
            SCGrid->SetFocus();
            SCGrid->Col = 3;
            SCGrid->Row = detail_line;
        }else{
            SCGrid->Cells[4][detail_line] = cur_weight_; // 2回目重量に入れる
            SCGrid->SetFocus();
            SCGrid->Col = 4;
            SCGrid->Row = detail_line;
        }
    }else if (mode == imSecond){
        // 滞留
/*
        current_row = 0;
        for (int i = detail_line; i < max_row; i += detail_line){
            if (!SCGrid->Cells[0][i].IsEmpty()){
                current_row = i;
            }else{
                break;
            }
        }

        // current_rowとdetail_lineが同じ場合、1明細目に2回目重量が入っていたら明細を追加する
        if (current_row == detail_line && StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][detail_line], 0) > 0){
            current_row = CalcNextRow(keiryo_id_);
            MeisaiAddButton->OnClick(NULL);
        }
*/
        current_row = CalcNextRow(keiryo_id_);
        if (SCGrid->Cells[0][current_row].IsEmpty())
            MeisaiAddButton->OnClick(NULL);

        SCGrid->Cells[4][current_row] = cur_weight_; // 2回目重量に入れる
        SCGrid->SetFocus();
        SCGrid->Col = 4;
        SCGrid->Row = current_row;
    }

    CalcWeight(current_row);
}
//---------------------------------------------------------------------------
// F12 終了
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
// 得意先検索
void __fastcall TMainForm::TokuButtonClick(TObject *Sender)
{
    SearchForm->Top         = MainForm->Top;
    SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
    SearchForm->based_sql   = "SELECT 得意先コード, 得意先略称 FROM M_得意先 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 得意先コード ";
    SearchForm->table_name  = "M_得意先";
    if (SearchForm->ShowModal() != mrOk)
        return;
    TokuCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
    TokuCodeEdit->OnChange(NULL);
    TokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// 項目1検索
void __fastcall TMainForm::Komoku1ButtonClick(TObject *Sender)
{
    SearchForm->Top         = MainForm->Top;
    SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
    SearchForm->based_sql   = "SELECT 項目1コード, 項目1略称 FROM M_項目1 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目1コード ";
    SearchForm->table_name  = "M_項目1";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Komoku1CodeEdit->Text = SearchForm->Query->FieldByName("項目1コード")->AsInteger;
    Komoku1CodeEdit->OnChange(NULL);
    Komoku1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// 項目2検索
void __fastcall TMainForm::Komoku2ButtonClick(TObject *Sender)
{
    SearchForm->Top         = MainForm->Top;
    SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
    SearchForm->based_sql   = "SELECT 項目2コード, 項目2略称 FROM M_項目2 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目2コード ";
    SearchForm->table_name  = "M_項目2";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Komoku2CodeEdit->Text = SearchForm->Query->FieldByName("項目2コード")->AsInteger;
    Komoku2CodeEdit->OnChange(NULL);
    Komoku2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// Form->Resize
void __fastcall TMainForm::FormResize(TObject *Sender)
{
    // WindwsのVersionでコンポーネント配置を変更する？
    // とりあえずVista以降はコンポーネントをずらしておく
    major_version = Win32MajorVersion;
    minor_version = Win32MinorVersion;
    //int platform     = Win32Platform;

    if (major_version < 6){ // XP以前
        int interval = 10;
        F1Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F2Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F3Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F4Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F5Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F6Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F7Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F8Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F9Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F10Button->Width = int((MainForm->Width - interval * 4) / 12);
        F11Button->Width = int((MainForm->Width - interval * 4) / 12);
        F12Button->Width = int((MainForm->Width - interval * 4) / 12);

        F1Button->Left  = interval;
        F2Button->Left  = F1Button->Left + F1Button->Width - 1;
        F3Button->Left  = F2Button->Left + F2Button->Width - 1;
        F4Button->Left  = F3Button->Left + F3Button->Width - 1;
        F5Button->Left  = F4Button->Left + F4Button->Width - 1 + interval;
        F6Button->Left  = F5Button->Left + F5Button->Width - 1;
        F7Button->Left  = F6Button->Left + F6Button->Width - 1;
        F8Button->Left  = F7Button->Left + F7Button->Width - 1;
        F9Button->Left  = F8Button->Left + F8Button->Width - 1 + interval;
        F10Button->Left = F9Button->Left + F9Button->Width - 1;
        F11Button->Left = F10Button->Left + F10Button->Width - 1;
        F12Button->Left = F11Button->Left + F11Button->Width - 1;

        F1Panel->Left  = F1Button->Left + 3;
        F2Panel->Left  = F2Button->Left + 3;
        F3Panel->Left  = F3Button->Left + 3;
        F4Panel->Left  = F4Button->Left + 3;
        F5Panel->Left  = F5Button->Left + 3;
        F6Panel->Left  = F6Button->Left + 3;
        F7Panel->Left  = F7Button->Left + 3;
        F8Panel->Left  = F8Button->Left + 3;
        F9Panel->Left  = F9Button->Left + 3;
        F10Panel->Left = F10Button->Left + 3;
        F11Panel->Left = F11Button->Left + 3;
        F12Panel->Left = F12Button->Left + 3;

        F1Panel->Width  = F1Button->Width - 5;
        F2Panel->Width  = F2Button->Width - 5;
        F3Panel->Width  = F3Button->Width - 5;
        F4Panel->Width  = F4Button->Width - 5;
        F5Panel->Width  = F5Button->Width - 5;
        F6Panel->Width  = F6Button->Width - 5;
        F7Panel->Width  = F7Button->Width - 5;
        F8Panel->Width  = F8Button->Width - 5;
        F9Panel->Width  = F9Button->Width - 5;
        F10Panel->Width = F10Button->Width - 5;
        F11Panel->Width = F11Button->Width - 5;
        F12Panel->Width = F12Button->Width - 5;

        TairyuGrid->RowCount = int(TairyuGrid->Height / 63);

        // 他のフォームのサイズもメインフォームに合わせる
        SearchForm->Height   = MainForm->Height;
        DataListForm->Height = MainForm->Height - 33;
        DataListForm->Width  = MainForm->Width  - 24;
        DataListForm->Top    = MainForm->Top    + 16;
        DataListForm->Left   = MainForm->Left   + 12;
    }else{                 // Vista以降
        int interval = 6;
        int frame    = 2;
        int mainform_width = MainForm->Width - frame;

        // TopPanel
        KyotenLabel->Left = KyotenLabel->Left - frame;
        PlaceCombo->Left  = PlaceCombo->Left - frame;
        WeightPanel->Left = WeightPanel->Left - frame;
        kgPanel->Left     = kgPanel->Left - frame;

        if (minor_version == 0) // Vista
            ScrollBox->Width = SharyoPanel->Width + 10;
        else                    // 7以降
            ScrollBox->Width = SharyoPanel->Width + 8;
        MeisaiScrollBox->Width = SharyoPanel->Width + frame;

        // MeisaiScrollBox
        HannyuCombo->Left = HannyuCombo->Left - 10;

        // TotalPanel
        TotalWeightTitle->Left = TotalWeightTitle->Left - frame;
        TotalWeightLabel->Left = TotalWeightLabel->Left - frame;
        TotalWeightShape->Left = TotalWeightShape->Left - frame;
        MoneyTitle->Left       = MoneyTitle->Left - frame;
        MoneyLabel->Left       = MoneyLabel->Left - frame;
        MoneyShape->Left       = MoneyShape->Left - frame;
        TaxTitle->Left         = TaxTitle->Left - frame;
        TaxLabel->Left         = TaxLabel->Left - frame;
        TaxShape->Left         = TaxShape->Left - frame;
        TotalMoneyTitle->Left  = TotalMoneyTitle->Left - frame;
        TotalMoneyLabel->Left  = TotalMoneyLabel->Left - frame;
        TotalMoneyShape->Left  = TotalMoneyShape->Left - frame;

        // KeyPanel
        KeyPanel->Height = 54;

        F1Button->Width  = int((mainform_width - interval * 4) / 12);
        F2Button->Width  = int((mainform_width - interval * 4) / 12);
        F3Button->Width  = int((mainform_width - interval * 4) / 12);
        F4Button->Width  = int((mainform_width - interval * 4) / 12);
        F5Button->Width  = int((mainform_width - interval * 4) / 12);
        F6Button->Width  = int((mainform_width - interval * 4) / 12);
        F7Button->Width  = int((mainform_width - interval * 4) / 12);
        F8Button->Width  = int((mainform_width - interval * 4) / 12);
        F9Button->Width  = int((mainform_width - interval * 4) / 12);
        F10Button->Width = int((mainform_width - interval * 4) / 12);
        F11Button->Width = int((mainform_width - interval * 4) / 12);
        F12Button->Width = int((mainform_width - interval * 4) / 12);

        F1Button->Left  = interval;
        F2Button->Left  = F1Button->Left + F1Button->Width - 1;
        F3Button->Left  = F2Button->Left + F2Button->Width - 1;
        F4Button->Left  = F3Button->Left + F3Button->Width - 1;
        F5Button->Left  = F4Button->Left + F4Button->Width - 1 + interval;
        F6Button->Left  = F5Button->Left + F5Button->Width - 1;
        F7Button->Left  = F6Button->Left + F6Button->Width - 1;
        F8Button->Left  = F7Button->Left + F7Button->Width - 1;
        F9Button->Left  = F8Button->Left + F8Button->Width - 1 + interval;
        F10Button->Left = F9Button->Left + F9Button->Width - 1;
        F11Button->Left = F10Button->Left + F10Button->Width - 1;
        F12Button->Left = F11Button->Left + F11Button->Width - 1;

        F1Panel->Left  = F1Button->Left + 3;
        F2Panel->Left  = F2Button->Left + 3;
        F3Panel->Left  = F3Button->Left + 3;
        F4Panel->Left  = F4Button->Left + 3;
        F5Panel->Left  = F5Button->Left + 3;
        F6Panel->Left  = F6Button->Left + 3;
        F7Panel->Left  = F7Button->Left + 3;
        F8Panel->Left  = F8Button->Left + 3;
        F9Panel->Left  = F9Button->Left + 3;
        F10Panel->Left = F10Button->Left + 3;
        F11Panel->Left = F11Button->Left + 3;
        F12Panel->Left = F12Button->Left + 3;

        F1Panel->Width  = F1Button->Width - 5;
        F2Panel->Width  = F2Button->Width - 5;
        F3Panel->Width  = F3Button->Width - 5;
        F4Panel->Width  = F4Button->Width - 5;
        F5Panel->Width  = F5Button->Width - 5;
        F6Panel->Width  = F6Button->Width - 5;
        F7Panel->Width  = F7Button->Width - 5;
        F8Panel->Width  = F8Button->Width - 5;
        F9Panel->Width  = F9Button->Width - 5;
        F10Panel->Width = F10Button->Width - 5;
        F11Panel->Width = F11Button->Width - 5;
        F12Panel->Width = F12Button->Width - 5;

        TairyuGrid->RowCount = int(TairyuGrid->Height / 63);

        // 他のフォームのサイズもメインフォームに合わせる
        SearchForm->Height   = MainForm->Height;
        DataListForm->Height = MainForm->Height - 33;
        DataListForm->Width  = mainform_width   - 24;
        DataListForm->Top    = MainForm->Top    + 16;
        DataListForm->Left   = MainForm->Left   + 12;
    }
}
//---------------------------------------------------------------------------
// 車番ボタン->OnClick
void __fastcall TMainForm::SharyoButtonClick(TObject *Sender)
{
    DM->SetShabanQuery(GetMode() != imMod, GetPlaceID(), false);
    DM->Q_Shaban->Open();
    ShabanSanshoForm->TopPanel->Caption = AnsiString();
    if (ShabanSanshoForm->ShowModal() != mrOk){
        ShabanEdit->SetFocus();
        return;
    }

    car_id_      = ShabanSanshoForm->GetCarID();
    int car_no   = ShabanSanshoForm->GetCarNo();
    int mastered = ShabanSanshoForm->GetDataDiv();

    if (!car_id_){
        ShabanEdit->SetFocus();
        return;     // 新規車両は登録できない
    }

    if (mastered){
        // 車両マスタからの選択

        AnsiString sql;
        NsRecordSet set;

        sql = "SELECT * FROM V_車両 WHERE 車両ID = " + IntToStr(car_id_);
        if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("選択された車両が存在しません。\r\n別PCなどで削除されていないか確認してください。",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return;
        }

        ShabanEdit->Text         = car_no;
        SharyoNameEdit->ReadOnly = true;
        
        if (GetMode() != imMod){
            if (TokuCodeEdit->Text.IsEmpty())
                TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["得意先コード"]));
            if (Komoku1CodeEdit->Text.IsEmpty())
                Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目1コード"]));
            if (Komoku2CodeEdit->Text.IsEmpty())
                Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目2コード"]));

            if (ToCurrency(SET_TOP(set)["空車重量"]) > 0){
                keiryo_count_ = 1;
            }else{
                keiryo_count_ = 2;
            }
            gross_limit_ = ToCurrency(SET_TOP(set)["車両総重量"]);
            net_limit_   = ToCurrency(SET_TOP(set)["最大積載量"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
        }else{
            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
        }

        TokuCodeEdit->SetFocus();
    }else{
        // 滞留車からの選択
        int keiryo_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);
        if (!keiryo_id){
            Application->MessageBox("選択された滞留情報が存在しません。\r\n別PCなどで計量されていないか確認してください。",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return;
        }

        ShabanEdit->Text         = car_no;
        SharyoNameEdit->ReadOnly = true;

        ContinueWeighing(keiryo_id);
    }
}
//---------------------------------------------------------------------------
// 車番->OnChange
void __fastcall TMainForm::ShabanEditChange(TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_車両 WHERE 車番 = " + IntToStr(ShabanEdit->Text.ToIntDef(0)) + " AND 使用区分 = 1";
    if (!DM->DBI.GetRecordSet(sql, set)){
        SharyoNameEdit->Text = AnsiString();
        return;
    }

    if (set.size() == 1)
        SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
    else
        SharyoNameEdit->Text = "複数の車両が存在";
}
//---------------------------------------------------------------------------
// 車番->KeyDown
void __fastcall TMainForm::ShabanEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    if (!SharyoCheck())
        return;

    if (ActiveControl != ShabanEdit)
        return;

    if (GetMode() == imMod){
        TokuCodeEdit->SetFocus();
    }else{

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;

        if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
            TokuCodeEdit->SetFocus();
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();
        else
            BikoEdit->SetFocus();

        ShabanEdit->OnExit = OnExit;
    }
}
//---------------------------------------------------------------------------
// 車番->OnExit
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
    SharyoCheck();
/*
    int car_no = ShabanEdit->Text.ToIntDef(0);
    if (car_no < 1){
        ShabanEdit->Text = AnsiString();
        return;
    }

    AnsiString sql;
    NsRecordSet set;

    if (GetMode() == imMod){
        sql = "SELECT 車両名称 FROM M_車両 WHERE 車両ID = " + IntToStr(car_id_);
        if (DM->DBI.GetRecordSet(sql, set)){
            if (ToString(SET_TOP(set)["車両名称"]) == SharyoNameEdit->Text)
                return;
        }
    }

    DM->SetShabanQuery(GetMode() != imMod, GetPlaceID());

    if (DM->Q_Shaban->Active)
        DM->Q_Shaban->Close();
    DM->Q_Shaban->Parameters->ParamByName("CARNO")->Value = car_no;
    DM->Q_Shaban->Open();

    if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
        // 新規車両登録

        TDateTime now(Now());
        NsFieldSet fields;

        AnsiString name = now.FormatString("mm/dd' に自動登録'");
        fields << NsField("[車番]",     car_no)
               << NsField("[車両名称]", name)
               << NsField("[更新日時]", now)
               << NsField("[作成日時]", now);

        DM->DBI.Insert("M_車両", fields);

        SharyoNameEdit->Text = name;

        car_id_ = DM->DBI.GetLastID();

        keiryo_count_ = 2;

        //if (GetMode() == imFirst)
            //FirstWEdit->Text = cur_weight_;

        return;
    }

    // 滞留車もしくは既存車両にヒットした場合、選択させる
    ShabanSanshoForm->TopPanel->Caption = "  車番：" + IntToStr(car_no);
    if (ShabanSanshoForm->ShowModal() != mrOk){
        ShabanEdit->SetFocus();
        return;
    }

    car_id_      = ShabanSanshoForm->GetCarID();
    int mastered = ShabanSanshoForm->GetDataDiv();

    if (!car_id_){
        // 新規車両（上と同じ処理）
        NsFieldSet fields;
        TDateTime  now(Now());
        AnsiString name = now.FormatString("mm/dd' に自動登録'");

        fields << NsField("[車番]",     car_no)
               << NsField("[車両名称]", name)
               << NsField("[更新日時]", now)
               << NsField("[作成日時]", now);

        DM->DBI.Insert("M_車両", fields);

        car_id_ = DM->DBI.GetLastID();

        SharyoNameEdit->Text = name;

        keiryo_count_ = 2;

        return;
    }

    if (mastered){
        // 車両マスタからの選択

        AnsiString sql;
        NsRecordSet set;

        sql = "SELECT * FROM V_車両 WHERE 車両ID = " + IntToStr(car_id_);
        if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("選択された車両が存在しません。\r\n別PCなどで削除されていないか確認してください。",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return;
        }

        if (GetMode() != imMod){
            if (TokuCodeEdit->Text.IsEmpty())
                TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["得意先コード"]));
            if (Komoku1CodeEdit->Text.IsEmpty())
                Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目1コード"]));
            if (Komoku2CodeEdit->Text.IsEmpty())
                Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目2コード"]));

            if (ToCurrency(SET_TOP(set)["空車重量"]) > 0)
                keiryo_count_ = 1;
            else
                keiryo_count_ = 2;

            gross_limit_ = ToCurrency(SET_TOP(set)["車両総重量"]);
            net_limit_   = ToCurrency(SET_TOP(set)["最大積載量"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
        }
    }else{
        // 滞留車からの選択
        int keiryo_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);
        if (!keiryo_id){
            Application->MessageBox("選択された滞留情報が存在しません。\r\n別PCなどで計量されていないか確認してください。",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return;
        }

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit  = 0;
        ContinueWeighing(keiryo_id);
        ShabanEdit->OnExit  = OnExit;
    }
*/
}
//---------------------------------------------------------------------------
// 得意先コード->OnChange
void __fastcall TMainForm::TokuCodeEditChange(TObject *Sender)
{
    int code = TokuCodeEdit->Text.ToIntDef(0);
    if (!code){
        TokuNameEdit->Text = AnsiString();
        return;
    }

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_得意先 WHERE 得意先コード = " + IntToStr(code);
    if (!DM->DBI.GetRecordSet(sql, set)){
        TokuNameEdit->Text = AnsiString();
        return;
    }

    toku_rec_ = SET_TOP(set);
    toku_id_  = ToInt(toku_rec_["得意先ID"]);

    if (code == ToInt(DM->CFG["得意先諸口コード"])){
        TokuNameEdit->ReadOnly = false;
        TokuNameEdit->TabStop  = true;
    }else{
        TokuNameEdit->Text = ToString(toku_rec_["得意先名称"]);
        TokuNameEdit->ReadOnly = true;
        TokuNameEdit->TabStop  = false;
    }
}
//---------------------------------------------------------------------------
// 得意先コード->OnExit
void __fastcall TMainForm::TokuCodeEditExit(TObject *Sender)
{
    // 項目関連マスタの処理
    int id = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "得意先ID"));
    int code;

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_項目関連 WHERE 項目番号 = 1 AND 項目ID = " + IntToStr(id);

    if (DM->DBI.GetRecordSet(sql, set)){
        id   = ToInt(SET_TOP(set)["項目1ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_項目1", "項目1ID", id, "項目1コード"));
        if (code)
            Komoku1CodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["項目2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_項目2", "項目2ID", id, "項目2コード"));
        if (code)
            Komoku2CodeEdit->Text = code;

        item_relate_hin_id_ = ToInt(SET_TOP(set)["品目ID"]);
    }
}
//---------------------------------------------------------------------------
// 項目1コード->OnChange
void __fastcall TMainForm::Komoku1CodeEditChange(TObject *Sender)
{
    int code = Komoku1CodeEdit->Text.ToIntDef(0);
    if (!code){
        Komoku1NameEdit->Text = AnsiString();
        return;
    }

    if (code == ToInt(DM->CFG["項目1諸口コード"])){
        Komoku1NameEdit->ReadOnly = false;
        Komoku1NameEdit->TabStop  = true;
    }else{
        Komoku1NameEdit->Text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", code, "項目1名称", ""));
        Komoku1NameEdit->ReadOnly = true;
        Komoku1NameEdit->TabStop  = false;
    }
}
//---------------------------------------------------------------------------
// 項目1コード->OnExit
void __fastcall TMainForm::Komoku1CodeEditExit(TObject *Sender)
{
    int id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    int code;

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_項目関連 WHERE 項目番号 = 2 AND 項目ID = " + IntToStr(id);

    if (DM->DBI.GetRecordSet(sql, set)){
        id   = ToInt(SET_TOP(set)["得意先ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_得意先", "得意先ID", id, "得意先コード"));
        if (code)
            TokuCodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["項目2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_項目2", "項目2ID", id, "項目2コード"));
        if (code)
            Komoku2CodeEdit->Text = code;

        item_relate_hin_id_ = ToInt(SET_TOP(set)["品目ID"]);
    }
}
//---------------------------------------------------------------------------
// 項目2コード->OnChange
void __fastcall TMainForm::Komoku2CodeEditChange(TObject *Sender)
{
    int code = Komoku2CodeEdit->Text.ToIntDef(0);
    if (!code){
        Komoku2NameEdit->Text = AnsiString();
        return;
    }

    if (code == ToInt(DM->CFG["項目2諸口コード"])){
        Komoku2NameEdit->ReadOnly = false;
        Komoku2NameEdit->TabStop  = true;
    }else{
        Komoku2NameEdit->Text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", code, "項目2名称", ""));
        Komoku2NameEdit->ReadOnly = true;
        Komoku2NameEdit->TabStop  = false;
    }
}
//---------------------------------------------------------------------------
// 項目2コード->OnExit
void __fastcall TMainForm::Komoku2CodeEditExit(TObject *Sender)
{
    int id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    int code;

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_項目関連 WHERE 項目番号 = 3 AND 項目ID = " + IntToStr(id);

    if (DM->DBI.GetRecordSet(sql, set)){
        id   = ToInt(SET_TOP(set)["得意先ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_得意先", "得意先ID", id, "得意先コード"));
        if (code)
            TokuCodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["項目1ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_項目1", "項目1ID", id, "項目1コード"));
        if (code)
            Komoku1CodeEdit->Text = code;

        item_relate_hin_id_ = ToInt(SET_TOP(set)["品目ID"]);
    }
}
//---------------------------------------------------------------------------
// 搬入出コンボ->OnKeyDown
void __fastcall TMainForm::HannyuComboKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_ESCAPE || Key == VK_DELETE)
        HannyuCombo->ItemIndex = -1;
    if (Key == VK_UP || Key == VK_DOWN)
        Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocketError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
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

    ClientSocket->Close();

    ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
    int index;
    AnsiString weight = Socket->ReceiveText();

    std::auto_ptr<TStringList> RecList(new TStringList());
    RecList->Text = weight;
    if (RecList->Count < 1)
        return;
    weight = RecList->Strings[RecList->Count - 1];

    bool ol = false;
    int len = weight.Length();
    if (len < 2)                    return;
    switch (weight[1]){
    case 'S':   WeightPanel->Font->Color = TColor(0x00CDF7A4); break;
    case 'U':   WeightPanel->Font->Color = TColor(0x008080FF); break;
    case 'O':   WeightPanel->Font->Color = clYellow;
                ol = true;
                break;
    default:
        return;
    }

    weight.Delete(1, 1);    // ステータスキャラクタの削除
    weight.Delete(weight.Length() - 1, 2);  // 末尾の \r\n を削除
    Currency tmp_weight;
    try{
        tmp_weight = Currency(weight);
    }catch(...){return;}

	// オーバーロードチェック
	if (DM->hyoryo_ != 0 && DM->meryo_ != 0)
		if (DM->hyoryo_ + DM->meryo_ * 9 < tmp_weight || DM->meryo_ * (-20) > tmp_weight)
			ol = true;

	if (ol){
		cur_weight_ = 0;
		WeightPanel->Caption = "OverLoad";
		return;
	}

    old_weight_ = cur_weight_;
    cur_weight_ = tmp_weight;

    // [INI] Weighing::SoundBorder
    int border = ToInt(DM->INI["Weighing::SoundBorder"]);

    if (old_weight_ < border && cur_weight_ >= border){
        // [INI] Weighing::SoundFile
        PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
    }

    WeightPanel->Caption = FormatFloat("###,##0", cur_weight_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch (Key){
    case VK_DOWN:
        if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl->Tag != 888
                && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_RETURN:
        if (ActiveControl->Tag != 999 && ActiveControl->Tag != 888 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_UP:
        if (ActiveControl->Tag != 1 && ActiveControl->Tag != 888){
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_TAB, 0, 0, 0);
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Q_TairyuAfterOpen(TDataSet *DataSet)
{
    TairyuGrid->Visible = Q_Tairyu->RecordCount != 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnSelectTairyu(TObject *Sender)
{
    if (Q_Tairyu->Bof && Q_Tairyu->Eof)
        return;

    ContinueWeighing(Q_Tairyu->FieldByName("計量ID")->AsInteger);
}
//---------------------------------------------------------------------------
// 拠点を変更した場合
void __fastcall TMainForm::PlaceComboChange(TObject *Sender)
{
    Action1->Execute();     // この中で Q_Tairyu の更新もしてる
}
//---------------------------------------------------------------------------
// 項目変更の可能性がある場合
void __fastcall TMainForm::OnItemsChanged(TObject *Sender)
{
    GetCalcInfo();
    //CalcAmount();
}
//---------------------------------------------------------------------------
// 重量、調整等、正味を計算する必要がある場合
void __fastcall TMainForm::OnWeightRecalc(TObject *Sender)
{
    //CalcWeight();
}
//---------------------------------------------------------------------------
// 数量や金額等を計算する必要がある場合
void __fastcall TMainForm::OnAmountRecalc(TObject *Sender)
{
    //CalcAmount();
}
//---------------------------------------------------------------------------
// 消費税を計算する必要がある場合
void __fastcall TMainForm::OnSalesTaxRecalc(TObject *Sender)
{
    //CalcSalesTax();
}
//---------------------------------------------------------------------------
// 滞留車コンポーネントを開く前
void __fastcall TMainForm::Q_TairyuBeforeOpen(TDataSet *DataSet)
{
    AnsiString sql;
    sql = " SELECT"
          "     計量ID, 計量日時1, 計量日, 伝票No,"
          "     車番, 車両名称, 得意先略称"
          " FROM"
          "     V_計量"
          " WHERE"
          "     行No = 1"
          " AND"
          "     完了区分 = 0"
          " AND"
          "     拠点ID = " + IntToStr(GetPlaceID());
    Q_Tairyu->SQL->Text = sql;
}
//---------------------------------------------------------------------------
// 伝票No->KeyDown
void __fastcall TMainForm::KeiryoNoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    int place = GetPlaceID();
    int date  = DateToInt(KeiryoDatePicker->Date);
    int no    = KeiryoNoEdit->Text.ToIntDef(0);

    AnsiString sql;
    NsRecordSet set;

    sql = " SELECT 計量ID FROM D_計量"
          " WHERE 計量日 = " + IntToStr(date) + " AND 拠点ID = " + IntToStr(place) +
          "     AND 伝票No = " + IntToStr(no);

    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("該当するデータが見つかりません。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ClearForm();
    SetMode(imMod);

    keiryo_id_ = SET_TOP(set)["計量ID"];

    if (!LoadFromID(keiryo_id_)){
        Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();

}
//---------------------------------------------------------------------------
// 1回目重量の KeyDown
void __fastcall TMainForm::FirstWEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
/*
    if (Key != VK_RETURN)
        return;

    if (GetMode() != imFirst)
        return;

    Currency w2 = StrToCurrDef(SecondWEdit->Text, 0);
    if (w2 != 0)            // 新規でも2回目重量が入力済ならここでは登録しない
        return;

    Action5->Execute();
*/
}
//---------------------------------------------------------------------------
// 備考->KeyDown
void __fastcall TMainForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Key = 0;

    if (GetMode() != imSecond){
        // 1回目計量と修正モード
        if (!SCGrid->Cells[0][detail_line].IsEmpty()){
            SCGrid->Options = SCGrid->Options << goEditing;
            SCGrid->Col = 1;
            SCGrid->Row = detail_line;
            SCGrid->SetFocus();
            return;
        }

        MeisaiAddButton->OnClick(NULL);
    }else{
        // 滞留車
        int row = keiryo_set_.size() * detail_line;
        int meisai_max_no = keiryo_set_.size();

        // rowが2の場合
        // 1明細目の2回目重量が0だったら、1明細目の2回目重量に重量値を入れる
        // 1明細目の2回目重量が1以上だったら、明細追加処理
        if (row == 2){
            Currency w_second = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", SCGrid->Row)], 0);
            if (w_second > 0){
                MeisaiAddButton->OnClick(NULL);
                return;
            }else{
                SCGrid->Options = SCGrid->Options << goEditing;
                SCGrid->SetFocus();
                SCGrid->Col     = GetColNo("2回目重量");
                SCGrid->Row     = row;
                SCGrid->Cells[GetColNo("2回目重量")][row] = cur_weight_;
            }
        }else if (ToInt(keiryo_set_[meisai_max_no - 1]["2回目重量"]) != 0){
            MeisaiAddButton->OnClick(NULL);
        }
    }
}
//---------------------------------------------------------------------------
// 備考->KeyPress
void __fastcall TMainForm::BikoEditKeyPress(TObject *Sender, char &Key)
{
    if (BikoEdit->Text.Length() >= 40){
        if (Key != VK_RETURN && Key != VK_BACK && Key != VK_DELETE)
            Key = 0;
    }
}
//---------------------------------------------------------------------------
// トレーラ計量->Click
void __fastcall TMainForm::TrailerWeightButtonClick(TObject *Sender)
{
/*
    int tag = dynamic_cast<TComponent *>(Sender)->Tag;

    if (TrailerWeightForm->ShowModal() != mrOk)
        return;

    if (tag == 1){
        FirstWEdit->Text  = TrailerWeightForm->TotalWeight;
        FirstWEdit->SetFocus();
    }else if (tag == 2){
        SecondWEdit->Text = TrailerWeightForm->TotalWeight;
        SecondWEdit->SetFocus();
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TairyuTimerTimer(TObject *Sender)
{
    TairyuTimer->Enabled = false;

    NsRecordSet set;
    AnsiString sql;
    int total = 0;

    sql = " SELECT SUM(計量ID) AS 滞留ID合計"
          " FROM D_計量"
          " WHERE 完了区分 = 0"
          " AND 行No = 1";
    if (DM->DBI.GetRecordSet(sql, set)){
        total = ToInt(SET_TOP(set)["滞留ID合計"]);
    }

    if (id_total_ != total){
        Q_Tairyu->Close();
        Q_Tairyu->Open();
    }

    id_total_ = total;

    TairyuTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WeighingDateTimePickerChange(TObject *Sender)
{
/*
    TDateTimePicker *DatePicker = dynamic_cast<TDateTimePicker *>(Sender);
    TDateTimePicker *TimePicker;

    TimePicker = DatePicker->Tag == 1 ? FirstTimePicker : SecondTimePicker;

    TimePicker->Enabled = DatePicker->Checked;

    if (DatePicker->Checked){
        DatePicker->Format    = "";
        TimePicker->Format    = "HH:mm";
    }else{
        DatePicker->Format    = "''";
        TimePicker->Format    = "''";
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KeiryoDatePickerChange(TObject *Sender)
{
    if (GetMode() != imMod)
       KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
}
//---------------------------------------------------------------------------
// 明細追加ボタン
void __fastcall TMainForm::MeisaiAddButtonClick(TObject *Sender)
{
    int line_no = row_lineno_map_[SCGrid->Row];

    if (GetMode() == imMod && line_no != 0) // 修正モードの場合は行挿入があるので別処理
        Line_Insert(line_no);
    else
        Line_Add();
}
//---------------------------------------------------------------------------
// 明細削除ボタン
void __fastcall TMainForm::MeisaiDeleteButtonClick(TObject *Sender)
{
    int row     = SCGrid->Row;
    int line_no = row_lineno_map_[row];
    if (row_lineno_map_[row] == 0)
        return;

    // 行が1行の場合は伝票削除の処理にする
    int meisai_count = 0;
    for (int i = detail_line; i < SCGrid->RowCount; i += detail_line){
        if (row_id_map_[i] != 0)
            meisai_count++;
    }

    if (meisai_count == 1){
        Action3->OnExecute(NULL);
        return;
    }

    // 複数行ある場合の処理
    if (Application->MessageBox(("行No" + IntToStr(line_no) + " を削除してもよろしいですか？").c_str(),
            this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    // 行削除
    // SCGrid上の値を移動
    int calc_row  = line_no * detail_line;
    int row_count = SCGrid->RowCount;
    for (int i = calc_row; i < row_count; i++){
        SCGrid->Rows[i] = SCGrid->Rows[i + detail_line];
        SCGrid->Rows[i + detail_line]->Clear();
        row_id_map_[i]  = row_id_map_[i + detail_line];
        row_id_map_[i + detail_line]  = 0;
    }

    int old_id = row_id_map_[detail_line];
    line_no = 1;
    row_lineno_map_.clear();
    for (int i = detail_line; i < SCGrid->RowCount; i++){
        if (row_id_map_[i] == 0)
            continue;

        if (old_id != row_id_map_[i])
            line_no++;

        if (i % detail_line == 0)
            SCGrid->Cells[0][i] = line_no;

        row_lineno_map_[i] = line_no;
        old_id = row_id_map_[i];
    }

    if (GetMode() != imFirst)
        delete_flag_ = true;

    SCGrid->SetFocus();
/*
    int keiryo_id    = row_id_map_[row];
    int net          = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id, "正味重量"));
    Currency slip_no = ToCurrency(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id, "伝票No"));
    int date         = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id, "計量日"));

    DM->ADOConnection->BeginTrans();
    try{
        NsFieldSet keys;
        keys << NsField("計量ID", keiryo_id);
        DM->DBI.Delete("D_計量",  keys);
    }catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
        Application->MessageBox(("データの削除に失敗しました\r\n" + e.Message).c_str(), this->Caption.c_str(),
                MB_OK | MB_ICONWARNING);
        return;
    }
    DM->ADOConnection->CommitTrans();

    AnsiString sql;
    sql = " SELECT * FROM V_計量"
          " WHERE"
          "     計量日 = " + IntToStr(date) +
          " AND"
          "     伝票No = " + CurrToStr(slip_no) +
          " AND"
          "     完了区分 <> 9" // 論理削除は対象外
          " ORDER BY"
          "     行No";

    keiryo_set_.clear();
    if (!DM->DBI.GetRecordSet(sql, keiryo_set_)){
        Action1->Execute();
        return;
    }

    // 複数行の間の行Noを削除した場合、削除した分の正味は再計算する？しない？

    LoadFromID(ToInt(SET_TOP(keiryo_set_)["計量ID"]));
*/
}
//---------------------------------------------------------------------------
// 再計算ボタン
//
// 搬入の場合は、最終的に行No1の1回目重量を増減して調整する
// 搬出の場合は、最終的に最終行の2回目重量を増減して調整する
void __fastcall TMainForm::RecalcButtonClick(TObject *Sender)
{
    if (SCGrid->Cells[GetColNo("品目コード")][detail_line].ToIntDef(0) == 0)
        return;

    if (Application->MessageBox("再計算を行いますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    Currency w1, w2, net, adjust, reduc;
    int io_div = HannyuCombo->ItemIndex + 1;

    if (io_div == 1){
        // 搬入
        // 最終行から見ていく
        int max_line_no       = GetMaxLineNo();
        Currency first_weight = 0;

        for (int i = max_line_no; i >= 1; i--){
            w1     = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))], 0);
            w2     = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))], 0);
            net    = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", (i * detail_line))], 0);
            adjust = StrToCurrDef(SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", (i * detail_line))], 0);
            reduc  = StrToCurrDef(SCGrid->Cells[GetColNo("重量引き")][CalcRowNo("重量引き", (i * detail_line))], 0);

            if (w1 == 0 && w2 == 0) // 対象データかチェック
                continue;

            if (first_weight != 0){
                w2 = first_weight;
                SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))] = first_weight;
            }

            if (w1 - w2 - adjust - reduc != net){
                first_weight = w2 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))] = first_weight;
            }else{
                first_weight = w1;
            }
        }
    }else if (io_div == 2){
        // 搬出
        // 最初の行から見ていく
        int first_line_no      = 1;
        Currency second_weight = 0;

        for (int i = first_line_no; i <= GetMaxLineNo(); i++){
            w1     = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))], 0);
            w2     = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))], 0);
            net    = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", (i * detail_line))], 0);
            adjust = StrToCurrDef(SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", (i * detail_line))], 0);
            reduc  = StrToCurrDef(SCGrid->Cells[GetColNo("重量引き")][CalcRowNo("重量引き", (i * detail_line))], 0);

            if (w1 == 0 && w2 == 0) // 対象データかチェック
                continue;

            if (second_weight != 0){
                w1 = second_weight;
                SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))] = second_weight;
            }

            if (w2 - w1 - adjust - reduc != net){
                second_weight = w1 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))] = second_weight;
            }else{
                second_weight = w2;
            }
        }
    }

    SCGrid->SetFocus();
    Application->MessageBox("再計算が完了しました", this->Caption.c_str(), MB_OK | MB_ICONQUESTION);
}
//---------------------------------------------------------------------------
// 確認メッセージなしで再計算処理
void __fastcall TMainForm::Recalc_NoMsg()
{
    Currency w1, w2, net, adjust, reduc;
    int io_div = HannyuCombo->ItemIndex + 1;

    if (io_div == 1){
        // 搬入
        // 最終行から見ていく
        int max_line_no       = GetMaxLineNo();
        Currency first_weight = 0;

        for (int i = max_line_no; i >= 1; i--){
            w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))], 0);
            w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))], 0);
            net = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", (i * detail_line))], 0);

            if (ToBit(DM->CFG["調整使用区分"]))
                adjust = StrToCurrDef(SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", (i * detail_line))], 0);
            else
                adjust = 0;

            if (ToBit(DM->CFG["重量引き使用区分"]))
                reduc = StrToCurrDef(SCGrid->Cells[GetColNo("重量引き")][CalcRowNo("重量引き", (i * detail_line))], 0);
            else
                reduc = 0;

            if (w1 == 0 && w2 == 0) // 対象データかチェック
                continue;

            if (first_weight != 0){
                w2 = first_weight;
                SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))] = first_weight;
            }

            if (w1 - w2 - adjust - reduc != net){
                first_weight = w2 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))] = first_weight;
            }else{
                first_weight = w1;
            }
        }
    }else if (io_div == 2){
        // 搬出
        // 最初の行から見ていく
        int first_line_no      = 1;
        Currency second_weight = 0;

        for (int i = first_line_no; i <= GetMaxLineNo(); i++){
            w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))], 0);
            w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))], 0);
            net = StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", (i * detail_line))], 0);

            if (ToBit(DM->CFG["調整使用区分"]))
                adjust = StrToCurrDef(SCGrid->Cells[GetColNo("調整重量")][CalcRowNo("調整重量", (i * detail_line))], 0);
            else
                adjust = 0;

            if (ToBit(DM->CFG["重量引き使用区分"]))
                reduc = StrToCurrDef(SCGrid->Cells[GetColNo("重量引き")][CalcRowNo("重量引き", (i * detail_line))], 0);
            else
                reduc = 0;

            if (w1 == 0 && w2 == 0) // 対象データかチェック
                continue;

            if (second_weight != 0){
                w1 = second_weight;
                SCGrid->Cells[GetColNo("1回目重量")][CalcRowNo("1回目重量", (i * detail_line))] = second_weight;
            }

            if (w2 - w1 - adjust - reduc != net){
                second_weight = w1 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", (i * detail_line))] = second_weight;
            }else{
                second_weight = w2;
            }
        }
    }

    SCGrid->SetFocus();
}
//---------------------------------------------------------------------------
// SCGrid->OnClick
void __fastcall TMainForm::SCGridClick(TObject *Sender)
{
/*  ///// 入力規制有り /////
    if (row_lineno_map_[SCGrid->Row] > GetMaxLineNo() || row_lineno_map_[SCGrid->Row] == 0){
        SCGrid->Options    = SCGrid->Options >> goEditing;
        SCGrid->EditorMode = false;
    }else if (GetMode() == imSecond && row_lineno_map_[SCGrid->Row] != GetMaxLineNo()){
        SCGrid->Options    = SCGrid->Options >> goEditing;
        SCGrid->EditorMode = false;
    }else{
        SCGrid->Options    = SCGrid->Options << goEditing;
        SCGrid->EditorMode = true;

        // 全範囲選択
		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
		ie->SelStart     = 0;
        ie->SelectAll();
    }
*/
    if (SCGrid->EditorMode && GetCellName(SCGrid->Col, SCGrid->Row) == "品目マスタ名称"){
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT 品目コード, 品目名称 FROM M_品目 WHERE 使用区分 = 1";
        SearchForm->orderby_sql = " ORDER BY 品目コード ";
        SearchForm->table_name  = "M_品目";

        if (SearchForm->ShowModal() != mrOk){
            SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("品目コード")][SCGrid->Row]     = SearchForm->Query->FieldByName("品目コード")->AsInteger;
        SCGrid->Cells[GetColNo("品目マスタ名称")][SCGrid->Row] = SearchForm->Query->FieldByName("品目名称")->AsString;
        SCGrid->Col = SCGrid->Col - 1;
    }else if (SCGrid->EditorMode && GetCellName(SCGrid->Col, SCGrid->Row) == "単位マスタ名称"){
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT 単位コード, 単位名称 FROM M_単位";
        SearchForm->orderby_sql = " ORDER BY 単位コード ";
        SearchForm->table_name  = "M_単位";

        if (SearchForm->ShowModal() != mrOk){
            SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("単位コード")][SCGrid->Row]     = SearchForm->Query->FieldByName("単位コード")->AsInteger;
        SCGrid->Cells[GetColNo("単位マスタ名称")][SCGrid->Row] = SearchForm->Query->FieldByName("単位名称")->AsString;
        SCGrid->Col = SCGrid->Col - 1;
    }

    ///// 入力規制無し /////
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;

    // 全範囲選択
    TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
    ie->SelStart     = 0;
    ie->SelectAll();
}
//---------------------------------------------------------------------------
// SCGrid->OnColChanged
void __fastcall TMainForm::SCGridCellChanged(TObject *Sender, int AOldCol,
      int AOldRow, int ANewCol, int ANewRow)
{
    AnsiString old_item_name = GetCellName(AOldCol, AOldRow);

    if (old_item_name == "品目コード" || old_item_name == "1回目重量" || old_item_name == "2回目重量" || old_item_name == "調整率"
            || old_item_name == "調整重量" || old_item_name == "重量引き"){

        // 品目コードorマスタ名称で調整率を使用する場合は品目マスタの重量調整率を取りに行く
        if ((old_item_name == "品目コード" || old_item_name == "品目マスタ名称") && ToBit(DM->CFG["調整使用区分"])){
            int hin_code = SCGrid->Cells[AOldCol][AOldRow].ToIntDef(0);
            Currency coord_rate = ToCurrency(DM->DBI.Lookup("M_品目", "品目コード", hin_code, "重量調整率"));
            SCGrid->Cells[GetColNo("調整率")][AOldRow] = FormatFloat("#", coord_rate);
        }

        CalcWeight(AOldRow);
    }

    if (ToBit(DM->CFG["単価使用区分"]) && (old_item_name == "正味重量" || old_item_name == "単位コード"))
        CalcAmount(AOldRow);

    if (ToBit(DM->CFG["単価使用区分"]) && (old_item_name == "数量" || old_item_name == "単価" || old_item_name == "金額"))
        CalcSalesTax(AOldRow);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridDblClick(TObject *Sender)
{
    // ダブルクリックで編集可になるのを防止
}
//---------------------------------------------------------------------------
// Cellの値が編集された時のイベント
void __fastcall TMainForm::SCGridSetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
    if (GetCellName(ACol, ARow) == "品目コード"){
        SCGrid->Cells[GetColNo("品目マスタ名称")][ARow] = ToString(DM->DBI.Lookup("M_品目", "品目コード", SCGrid->Cells[ACol][ARow].ToIntDef(0), "品目名称"));

        if (GetMode() == imFirst && row_lineno_map_[ARow] == 1)
            // 1回目計量で1行目だったら搬入区分を変更する
            HannyuCombo->ItemIndex = ToInt(DM->DBI.Lookup("M_品目", "品目コード", SCGrid->Cells[ACol][ARow].ToIntDef(0), "搬入出区分")) - 1;
        else if (GetMode() != imFirst && row_lineno_map_[ARow] == 1 && HannyuCombo->ItemIndex == -1)
            // 新規以外で搬入出が選択されていない場合、1行目の品目マスタの搬入出区分を反映する
            HannyuCombo->ItemIndex = ToInt(DM->DBI.Lookup("M_品目", "品目コード", SCGrid->Cells[ACol][ARow].ToIntDef(0), "搬入出区分")) - 1;

        // 品目コードが0じゃなくて、行Noが無かった場合行No入れる
        if (SCGrid->Cells[ACol][ARow].ToIntDef(0) != 0 && SCGrid->Cells[GetColNo("行No")][CalcRowNo("行No", ARow)].ToIntDef(0) == 0)
            Line_Add();

    }else if (GetCellName(ACol, ARow) == "単位コード"){
        SCGrid->Cells[GetColNo("単位マスタ名称")][ARow] = ToString(DM->DBI.Lookup("M_単位", "単位コード", SCGrid->Cells[ACol][ARow].ToIntDef(0), "単位名称"));
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN){
        SCGrid->EditorMode = false;
/*
        明細に並べる項目
        -- 1行目 --
        1,行No
        2,品目コード
        3,品目名称
        4,1回目重量
        5,2回目重量
        6,調整率
        7,調整重量
        8,重量引き
        9,正味重量

        -- 2行目 --
        10,明細備考
        11,数量
        12,単位コード
        13,単位名称
        14,単価
        15,金額
        16,消費税額
*/
        if (SCGrid->Col == line_colcount_map_[GetLineNo(SCGrid->Row, detail_line)] && detail_line == 1){
            ///// 1行表示の最後のCol
            if (SCGrid->Cells[0][SCGrid->Row + 1].IsEmpty() && !PostMessageCheck->Checked){
                // 次の行Noが表示されてなくて登録メッセージありだったら登録処理へ
                Action5->OnExecute(NULL);
            }else if (SCGrid->Row == max_row){
                // 最大行の場合は登録処理
                Action5->OnExecute(NULL);
            }else{
                // 次の行へ移動
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 1;
            }
        }else if (SCGrid->Col == line_colcount_map_[GetLineNo(SCGrid->Row, detail_line)] && detail_line == 2){
            ///// 2行表示の最後のCol
            if (SCGrid->Row % 2 != 0 && SCGrid->Cells[0][SCGrid->Row + 1].IsEmpty() && !PostMessageCheck->Checked){
                // 2行目で次の行Noが表示されてなくて登録メッセージありだったら登録処理へ
                Action5->OnExecute(NULL);
            }else if (SCGrid->Row == max_row - 1){
                // 最大行の場合は登録処理
                Action5->OnExecute(NULL);
            }else if (SCGrid->Row % 2 == 0){
                // 1行目から2行目に移動
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 2;
            }else{
                // 次の行へ移動
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 1;
            }
        }else if (GetCellName(SCGrid->Col, SCGrid->Row) == "品目コード" || GetCellName(SCGrid->Col, SCGrid->Row) == "単位コード"
                || GetCellName(SCGrid->Col, SCGrid->Row) == "調整率"){
            SCGrid->Col = SCGrid->Col + 2;
        }else if (GetCellName(SCGrid->Col, SCGrid->Row) == "1回目重量" && GetMode() == imFirst){
            ///// 新規の1回目重量のイベント
            if (SCGrid->Cells[GetColNo("2回目重量")][CalcRowNo("2回目重量", SCGrid->Row)].ToIntDef(0) == 0){
                if (!PostMessageCheck->Checked)
                    Action5->OnExecute(NULL);
                else
                    SCGrid->Col = SCGrid->Col + 1;
            }else{
                SCGrid->Col = SCGrid->Col + 1;
            }
        }else if (SCGrid->Col == line_end_col){
            if (detail_line == 1)
                Action5->OnExecute(NULL);

            if ((SCGrid->Row + 1) % detail_line == 0)
                Action5->OnExecute(NULL);

        }else if (SCGrid->Col < SCGrid->ColCount - 1){
            SCGrid->Col = SCGrid->Col + 1;
        }

        // 移動した先のセル名が無かったら、次行へ移動する
        if (GetCellName(SCGrid->Col, SCGrid->Row) == ""){
            if (detail_line == 1){
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 1;
            }else if (detail_line == 2){
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 2;
            }
        }

        // 全範囲選択
		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
		ie->SelStart = 0;
    }else if (Key == VK_LEFT){
        AnsiString name = GetCellName(SCGrid->Col - 1, SCGrid->Row);
        if (name == "品目マスタ名称" || name == "単位マスタ名称" || name == "調整重量"){
            TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
            if (ie->SelStart == 0 && ie->SelLength == 0){
                Key = 0;
                SCGrid->Col = SCGrid->Col - 2;
            }
        }
    }else if (Key == VK_RIGHT){
        AnsiString name = GetCellName(SCGrid->Col + 1, SCGrid->Row);
        if (name == "品目マスタ名称" || name == "単位マスタ名称" || name == "調整重量"){
    		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
            if ((ie->SelStart == ie->Text.Length() && ie->SelLength == 0) || (ie->Text.Length() == ie->SelLength)){
                Key = 0;
                SCGrid->Col = SCGrid->Col + 2;
            }
        }
    }else if (Key == VK_UP){
        AnsiString name = GetCellName(SCGrid->Col, SCGrid->Row - 1);
        if (name == "品目マスタ名称" || name == "単位マスタ名称" || name == "調整重量"){
            Key = 0;
            if (SCGrid->Row - 2 > detail_line - 1)
                SCGrid->Row = SCGrid->Row - 2;
        }
    }else if (Key == VK_DOWN){
        AnsiString name = GetCellName(SCGrid->Col, SCGrid->Row + 1);
        if (name == "品目マスタ名称" || name == "単位マスタ名称" || name == "調整重量"){
            Key = 0;
            if (SCGrid->Row + 2 < max_row)
                SCGrid->Row = SCGrid->Row + 2;
        }
    }

    if (!SCGrid->EditorMode)
        SCGrid->EditorMode = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridKeyPress(TObject *Sender, char &Key)
{
    int col = SCGrid->Col;
    int row = SCGrid->Row;
    AnsiString name = GetCellName(col, row);
    if (name == "明細備考"){
        if (SCGrid->Cells[SCGrid->Col][SCGrid->Row].Length() >= 20 && (Key != VK_RETURN && Key != VK_BACK && Key != VK_DELETE))
            Key = 0;
    }else if (name == "1回目重量" || name == "2回目重量" || name == "正味重量"){
        if (ToInt(DM->CFG["重量編集区分"]) == 0)
            Key = 0;
    }else if (name == "調整重量" || name == ""){
        if (Key != VK_RETURN && Key != VK_UP && Key != VK_DOWN && Key != VK_LEFT && Key != VK_RIGHT)
            Key = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    // 処理対象外の項目にフォーカスがある場合はここでreturnする
    if (GetMode() == imFirst && (row_lineno_map_[SCGrid->Row] != 1)){
        return;
    }else if (GetMode() == imSecond && row_lineno_map_[SCGrid->Row] > GetMaxLineNo()){
        return;
    }else if (col_row_map_.empty()){
        return;
    }

    AnsiString item_name = GetCellName(ACol, ARow);

    // IMEモード切替
    if (item_name == "明細備考")
        SetImeMode(SCGrid->Handle, imHira);
    else
        SetImeMode(SCGrid->Handle, imClose);

    // 重量関係の処理
    int empty_weight = 0;
    if (car_id_ != 0)
         empty_weight = ToInt(DM->DBI.Lookup("M_車両", "車両ID", car_id_, "空車重量"));

    if (item_name == "1回目重量" && GetMode() == imFirst && empty_weight != 0){
        SCGrid->Cells[ACol][ARow]                  = cur_weight_;
        SCGrid->Cells[GetColNo("2回目重量")][ARow] = empty_weight;
    }else if (item_name == "1回目重量" && GetMode() == imFirst){
        SCGrid->Cells[ACol][ARow] = cur_weight_;
    //}else if (item_name == "1回目重量" && GetMode() != imFirst && GetMaxLineNo() == row_lineno_map_[SCGrid->Row] && GetMaxLineNo() != 1){
    }else if (item_name == "1回目重量" && GetMode() != imFirst && GetMaxLineNo() == row_lineno_map_[ARow] && GetMaxLineNo() != 1){
        SCGrid->Cells[ACol][ARow] = SCGrid->Cells[GetColNo("2回目重量")][ARow - detail_line];
    }else if (item_name == "2回目重量" && GetMode() == imSecond && GetMaxLineNo() == row_lineno_map_[ARow]){
        if (SCGrid->Cells[GetColNo("1回目重量")][ARow].IsEmpty())
            SCGrid->Cells[GetColNo("1回目重量")][ARow] = SCGrid->Cells[GetColNo("2回目重量")][ARow - detail_line];

        SCGrid->Cells[ACol][ARow] = cur_weight_;
    }else if (item_name == "2回目重量" && GetMode() == imMod){ // この条件は何だっけ？
        //SCGrid->Cells[ACol][ARow] = 0;
    }

    if (item_name == "数量")
        SCGrid->Cells[ACol][ARow] = GetSuryoCellValue(SCGrid->Cells[ACol][ARow]);

    if (item_name == "品目コード" && SCGrid->Cells[ACol][ARow].ToIntDef(0) == 0 && GetMode() != imMod){
        SCGrid->Cells[ACol][ARow] = FormatFloat("#,##0;#,##0;#", ToInt(DM->DBI.Lookup("M_品目", "品目ID", item_relate_hin_id_, "品目コード")));
        SCGrid->Cells[GetColNo("品目マスタ名称")][CalcRowNo("品目マスタ名称", ARow)] = ToString(DM->DBI.Lookup("M_品目", "品目ID", item_relate_hin_id_, "品目名称"));
    }

    if (item_name == "調整率"){
        // 新規もしくは滞留車モードで調整率が0だったら品目マスタの重量調整率を見る
        Currency value = StrToCurrDef(SCGrid->Cells[ACol][ARow], 0);
        if (GetMode() == imFirst || (GetMode() == imSecond && value == 0)){
            int hinmoku_code     = SCGrid->Cells[GetColNo("品目コード")][CalcRowNo("品目コード", ARow)].ToIntDef(0);
            Currency adjust_rate = ToCurrency(DM->DBI.Lookup("M_品目", "品目コード", hinmoku_code, "重量調整率"));

            if (adjust_rate != 0)
                SCGrid->Cells[ACol][ARow] = adjust_rate;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if (ACol < SCGrid->FixedCols || ARow < SCGrid->FixedRows)
        SCGrid->Canvas->Brush->Color = SCGrid->FixedColor;
    else if (detail_line == 2 && ARow % 4 < 2)
        SCGrid->Canvas->Brush->Color = clWhite;
    else if (detail_line == 1 && ARow % 2 == 0)
        SCGrid->Canvas->Brush->Color = clWhite;
    else
        SCGrid->Canvas->Brush->Color = clCream;

    SCGrid->Canvas->FillRect(Rect); // 描画

    // 罫線描画
    if (detail_line == 1){
        if (ACol >= SCGrid->FixedCols && ARow >= SCGrid->FixedRows){
            SCGrid->Canvas->Pen->Color = clSilver;
            SCGrid->Canvas->Pen->Width = 2;
            SCGrid->Canvas->MoveTo(Rect.Left,  Rect.Bottom);
            SCGrid->Canvas->LineTo(Rect.Right, Rect.Bottom);
            SCGrid->Canvas->Pen->Width = 1;
        }
    }else if (detail_line == 2){
        if (ARow % 2 == 1 && ACol >= SCGrid->FixedCols && ARow >= SCGrid->FixedRows){
            SCGrid->Canvas->Pen->Color = clSilver;
            SCGrid->Canvas->Pen->Width = 2;
            SCGrid->Canvas->MoveTo(Rect.Left,  Rect.Bottom);
            SCGrid->Canvas->LineTo(Rect.Right, Rect.Bottom);
            SCGrid->Canvas->Pen->Width = 1;
        }else if (ACol >= SCGrid->FixedCols && ARow >= SCGrid->FixedRows){
            SCGrid->Canvas->Pen->Color = clSilver;
            SCGrid->Canvas->Pen->Style = psDot;
            SCGrid->Canvas->MoveTo(Rect.Left,  Rect.Bottom);
            SCGrid->Canvas->LineTo(Rect.Right, Rect.Bottom);
        }
    }

/*  // 標準の埋め潰しカーソルではなくて太枠カーソルに変更
    if(State.Contains(gdSelected)){
        Grid->Canvas->Brush->Style = bsClear;
        Grid->Canvas->Pen->Width = 2;
        Grid->Canvas->Pen->Color = clBlack;
        Grid->Canvas->Rectangle(R.left+1,R.top+1,R.right,R.bottom);
    }
*/
    // 品目マスタ名称と単位マスタ名称は左寄せ
    // それ以外は右寄せ
    if (ACol < SCGrid->FixedCols || ARow < SCGrid->FixedRows){ // 固定項目

        //立体枠の描画
        //if(State.Contains(gdFixed))
            //DrawEdge(SCGrid->Canvas->Handle, &Rect, BDR_SUNKEN, BF_TOP);

        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[ACol][ARow].c_str(), SCGrid->Cells[ACol][ARow].Length(), &Rect, DT_CENTER | DT_SINGLELINE); //中央寄せ
    }else if (GetCellName(ACol, ARow) ==  "品目マスタ名称" || GetCellName(ACol, ARow) == "単位マスタ名称" || GetCellName(ACol, ARow) == "明細備考"){
        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[ACol][ARow].c_str(), SCGrid->Cells[ACol][ARow].Length(), &Rect, DT_LEFT | DT_SINGLELINE);   //左寄せ
    }else{
        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[ACol][ARow].c_str(), SCGrid->Cells[ACol][ARow].Length(), &Rect, DT_RIGHT | DT_SINGLELINE);  //右寄せ
    }

    // 選択されているセルの背景色変更
    if (!SCGrid->ComponentCount)
        return;

    TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
    if (ie != NULL){
        TBrush *br = ie->Brush;
        br->Color  = TColor(0x00E4DDFF);
        br->Style  = bsSolid;
    }
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::GetHeaderID(int keiryo_id)
{
    NsRecordSet set;
    AnsiString  sql;
    int date, place, slip_no;

    if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id), set))
        return 0;

    date    = ToInt(SET_TOP(set)["計量日"]);
    place   = ToInt(SET_TOP(set)["拠点ID"]);
    slip_no = ToInt(SET_TOP(set)["伝票No"]);

    sql = " SELECT"
          "     *"
          " FROM"
          "     D_計量"
          " WHERE"
          "     計量日 = " + IntToStr(date) +
          " AND"
          "     拠点ID = " + IntToStr(place) +
          " AND"
          "     伝票No = " + IntToStr(slip_no) +
          " AND"
          "     行No = 1"
          " AND"
          "     完了区分 <> 9";
    if (!DM->DBI.GetRecordSet(sql, set))
        return 0;

    return ToInt(SET_TOP(set)["計量ID"]);
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::GetTotalWeight()
{
    int max_no, total_weight;
    max_no = GetMaxLineNo();
    total_weight = 0;
    for (int i = 1; i <= max_no; i++)
        total_weight += SCGrid->Cells[GetColNo("正味重量")][CalcRowNo("正味重量", i * detail_line)].ToIntDef(0);

    return total_weight;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetTotalMoney()
{
    if (!ToBit(DM->CFG["単価使用区分"]))
        return;

    int max_no, sum_money, sum_tax;
    max_no    = GetMaxLineNo();
    sum_money = 0;
    sum_tax = 0;
    for (int i = 1; i <= max_no; i++){
        sum_money += SCGrid->Cells[GetColNo("金額")][CalcRowNo("金額", i * detail_line)].ToIntDef(0);
        sum_tax   += SCGrid->Cells[GetColNo("消費税額")][CalcRowNo("消費税額", i * detail_line)].ToIntDef(0);
    }

	if (ToString(DM->CFG["多段時消費税計算区分"]).ToIntDef(1) == 1){
		Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date)); // 消費税率取得
		///// 消費税端数処理区分の取得
		int tax_div = -1;
		if (!toku_rec_.empty()){
			if (!IsNull(toku_rec_["消費税端数処理区分"]))
				tax_div = ToInt(toku_rec_["消費税端数処理区分"]);
		}

		if (tax_div == -1)
			tax_div = ToInt(DM->CFG["消費税端数処理区分"]);

		///// 伝票消費税の計算
		sum_tax   = ExtendedRound(Currency(sum_money) * tax_rate, 0, tax_div);
	}

    slip_tax_ = sum_tax;

    MoneyLabel->Caption = FormatFloat("\\ #,##0", sum_money);
    TaxLabel->Caption   = FormatFloat("\\ #,##0", sum_tax);
    TotalMoneyLabel->Caption = FormatFloat("\\ #,##0", sum_money + sum_tax);
}
//---------------------------------------------------------------------------
//      明細グリッド関係
//---------------------------------------------------------------------------
// 明細タイトル設定
void __fastcall TMainForm::SetGridTitle()
{
/*
        明細に並べる項目
        -- 1行目 --
        1,行No
        2,品目コード
        3,品目名称
        4,1回目重量
        5,2回目重量
        6,調整率
        7,調整重量
        8,重量引き
        9,正味重量

        -- 2行目 --
        10,明細備考
        11,単位コード
        12,単位名称
        13,数量
        14,単価
        15,金額
        16,消費税額
*/
    line_colcount_map_.clear();

    ///// 行No
    col_row_map_.clear();
    col_row_map_[0]               = 1;
    name_coord_map_["行No"]       = col_row_map_;
    coord_name_map_[col_row_map_] = "行No";
    col_width_map_["行No"]        = 32;

    ///// 品目コード
    col_row_map_.clear();
    col_row_map_[1]               = 1;
    name_coord_map_["品目コード"] = col_row_map_;
    coord_name_map_[col_row_map_] = "品目コード";;
    col_width_map_["品目コード"]  = 50;

    ///// 品目名称
    col_row_map_.clear();
    col_row_map_[2]                   = 1;
    name_coord_map_["品目マスタ名称"] = col_row_map_;
    coord_name_map_[col_row_map_]     = "品目マスタ名称";
    col_width_map_["品目マスタ名称"]  = 330;

    ///// 1回目重量
    col_row_map_.clear();
    col_row_map_[3]               = 1;
    name_coord_map_["1回目重量"]  = col_row_map_;
    coord_name_map_[col_row_map_] = "1回目重量";
    col_width_map_["1回目重量"]   = 90;

    ///// 2回目重量
    col_row_map_.clear();
    col_row_map_[4]               = 1;
    name_coord_map_["2回目重量"]  = col_row_map_;
    coord_name_map_[col_row_map_] = "2回目重量";
    col_width_map_["2回目重量"]   = 90;

    int col_no = 4;
    int row_no = 1; // 何行目か

    ///// 調整率, 調整重量
    if (ToBit(DM->CFG["調整使用区分"])){
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["調整率"]     = col_row_map_;
        coord_name_map_[col_row_map_] = "調整率";
        col_width_map_["調整率"]      = 90;

        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["調整重量"]   = col_row_map_;
        coord_name_map_[col_row_map_] = "調整重量";
        col_width_map_["調整重量"]    = 90;
    }

    ///// 重量引き
    if (ToBit(DM->CFG["重量引き使用区分"])){
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["重量引き"]   = col_row_map_;
        coord_name_map_[col_row_map_] = "重量引き";
        col_width_map_["重量引き"]    = 90;
    }

    ///// 正味重量
    col_row_map_.clear();
    col_no++;
    col_row_map_[col_no]          = row_no;
    name_coord_map_["正味重量"]   = col_row_map_;
    coord_name_map_[col_row_map_] = "正味重量";
    col_width_map_["正味重量"]    = 90;


    ///// 明細備考
    if (!ToBit(DM->CFG["調整使用区分"]) && !ToBit(DM->CFG["重量引き使用区分"]) && !ToBit(DM->CFG["単価使用区分"])){
        col_no++;
    }else{
        line_colcount_map_[row_no] = col_no;
        row_no++;
        col_no = 2;
    }

    col_row_map_.clear();
    col_row_map_[col_no]          = row_no;
    name_coord_map_["明細備考"]   = col_row_map_;
    coord_name_map_[col_row_map_] = "明細備考";
    col_width_map_["明細備考"]    = 170;

    ///// 単価
    if (ToBit(DM->CFG["単価使用区分"])){

        ///// 単位コード
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["単位コード"] = col_row_map_;
        coord_name_map_[col_row_map_] = "単位コード";
        col_width_map_["単位コード"]  = 32;

        ///// 単位名称
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]              = row_no;
        name_coord_map_["単位マスタ名称"] = col_row_map_;
        coord_name_map_[col_row_map_]     = "単位マスタ名称";
        col_width_map_["単位マスタ名称"]  = 80;

        ///// 数量
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["数量"]       = col_row_map_;
        coord_name_map_[col_row_map_] = "数量";
        if (major_version >= 6)
            col_width_map_["数量"] = 95;
        else
            col_width_map_["数量"] = 100;

        ///// 単価
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["単価"]       = col_row_map_;
        coord_name_map_[col_row_map_] = "単価";
        if (major_version >= 6)
            col_width_map_["単価"] = 95;
        else
            col_width_map_["単価"] = 100;

        ///// 金額
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["金額"]       = col_row_map_;
        coord_name_map_[col_row_map_] = "金額";
        if (major_version >= 6)
            col_width_map_["金額"] = 95;
        else
            col_width_map_["金額"] = 100;

        ///// 消費税額
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["消費税額"]   = col_row_map_;
        coord_name_map_[col_row_map_] = "消費税額";
        if (major_version >= 6)
            col_width_map_["消費税額"] = 95;
        else
            col_width_map_["消費税額"] = 100;
    }

    // 1明細の最終項目Colの位置情報
    line_end_col = col_no;
    line_colcount_map_[row_no] = col_no;

    // 1計量に対する計量明細の行数設定
    int col_count = 6;
    if (!ToBit(DM->CFG["調整使用区分"]) && !ToBit(DM->CFG["重量引き使用区分"]) && !ToBit(DM->CFG["単価使用区分"])){
        detail_line      = 1;
        col_count++;
        SCGrid->ColCount = col_count;
    }else{
        detail_line      = 2;

        if (ToBit(DM->CFG["調整使用区分"]))
            col_count += 2;

        if (ToBit(DM->CFG["重量引き使用区分"]))
            col_count++;

        if (ToBit(DM->CFG["単価使用区分"]))
            col_count = 9;

        SCGrid->ColCount = col_count;
    }

    // 明細の最大行数設定
    max_line_no_ = 6;

    // グリッド初期設定
    SCGrid->FixedRows = detail_line;
    SCGrid->FixedCols = 1;
    SCGrid->DefaultColWidth = 10;

    // 項目名をクリア
    for (int r = 0; r < detail_line; r++){
        for (int c = 0; c < SCGrid->ColCount; c++)
            SCGrid->Cells[c][r] = AnsiString();
    }

    // 項目名のセット
    for (int r = 0; r < detail_line; r++){
        for (int c = 0; c < SCGrid->ColCount; c++){
            CoordToNameMap::iterator ctnm;

            col_row_map_.clear();
            col_row_map_[c] = r + 1; // col_row_map_のrowは1行目からなので + 1する
            ctnm = coord_name_map_.find(col_row_map_);

            if (ctnm == coord_name_map_.end()){
                SCGrid->Cells[c][r] = AnsiString();

                if (SCGrid->ColWidths[c] < 10)
                    SCGrid->ColWidths[c] = 10;
            }else{
                SCGrid->Cells[c][r] = GetColName(ctnm);

                if (SCGrid->ColWidths[c] < col_width_map_[ctnm->second])
                    SCGrid->ColWidths[c] = col_width_map_[ctnm->second];
            }

        }
    }

    if (detail_line == 2)
        max_row = 14;
    else
        max_row = 7;

    SCGrid->RowCount = max_row;

    TRect rect;
    int c = 0;
    int r = 0;
    for (int i = 0; i < detail_col; i++){
        if (SCGrid->Cells[c][r] == "明細備考" && detail_line == 2){
            r = 2;
            c = 2;
        }

        rect.Left   = c;
        rect.Top    = r;
        rect.Right  = c;
        rect.Bottom = r;
        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[c][r].c_str(), SCGrid->Cells[c][r].Length(), &rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE); //中央寄せ

        c++;
    }

    // グリッドの縦幅調整
    if (detail_line == 2){
        SCGrid->Height       = 311;
        MeisaiScrollBox->Top = 288;
        SCGrid->Col          = 1;
        SCGrid->Row          = 2;
    }else{
        SCGrid->Height       = 157;
        MeisaiScrollBox->Top = 442;
        SCGrid->Col          = 1;
        SCGrid->Row          = 1;
    }
}
//---------------------------------------------------------------------------
// 明細グリッドクリア
void __fastcall TMainForm::ClearDetailGrid()
{
    // DataColumnクリア
    // Cells[col][row]？
    // SCGrid->Cells[12][12]

    row_lineno_map_.clear(); // 行No情報クリア

    //SCGrid->Col = (int)1;
    //SCGrid->Row = (int)detail_line;

    for (int r = detail_line; r < SCGrid->RowCount; r++){
        for (int c = 0; c < SCGrid->ColCount; c++)
            SCGrid->Cells[c][r] = AnsiString();
    }

    // 合計パネルクリア
    TotalWeightLabel->Caption = AnsiString();
    MoneyLabel->Caption       = AnsiString();
    TaxLabel->Caption         = AnsiString();
    TotalMoneyLabel->Caption  = AnsiString();

    SCGrid->Options    = SCGrid->Options >> goEditing;
    SCGrid->EditorMode = false;
}
//---------------------------------------------------------------------------
// 明細グリッドのセルの範囲指定
void __fastcall TMainForm::SCGrid_SelectCell(TStrColGrid *grid, int left, int top, int right, int bottom)
{
    TGridRect r;

    r.Left   = left;
    r.Top    = top;
    r.Right  = right;
    r.Bottom = bottom;

    grid->Selection = r;
}
//---------------------------------------------------------------------------
// 項目名セット
AnsiString __fastcall TMainForm::GetColName(CoordToNameMap::iterator ctnm)
{
    if (ctnm->second == "品目コード" || ctnm->second == "単位コード")
        return "*";
    else if (ctnm->second == "品目マスタ名称")
        return DM->TrimString(ToString(DM->CFG["品目マスタ名称"]));
    else if (ctnm->second == "単位マスタ名称")
        return "単位";
    else
        return ctnm->second;
}
//---------------------------------------------------------------------------
// 項目名からColを取得
int __fastcall TMainForm::GetColNo(AnsiString name)
{
    NameToCoordMap::iterator ntcm;
    IntIntMap::iterator      iim;

    ntcm = name_coord_map_.find(name);
    if (ntcm == name_coord_map_.end()){
        return -1;
    }else{
        iim = ntcm->second.begin();
        return iim->first;
    }
}
//---------------------------------------------------------------------------
// 項目名から何行目かを取得
int __fastcall TMainForm::GetRowNo(AnsiString name)
{
    NameToCoordMap::iterator ntcm;
    IntIntMap::iterator      iim;

    ntcm = name_coord_map_.find(name);
    if (ntcm == name_coord_map_.end()){
        return -1;
    }else{
        iim = ntcm->second.begin();
        return iim->second;
    }
}
//---------------------------------------------------------------------------
// 2行以上の場合使う関数
// 項目名と現在のRowを渡して、項目名に対応したRowを返す
// 戻り値の行数は0スタートの行数
int __fastcall TMainForm::CalcRowNo(AnsiString name, int row)
{
    if (detail_line == 1)
        return row;

    int item_row_no = GetRowNo(name);

    if (item_row_no == 1 && row % 2 == 0)
        return row;
    else if (item_row_no == 1 && row % 2 == 1)
        return row - 1;
    else if (item_row_no == 2 && row % 2 == 0)
        return row + 1;
    else if (item_row_no == 2 && row % 2 == 1)
        return row;
    else
        return row;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetCellName(int col, int row)
{
    CoordToNameMap::iterator ctnm;

    col_row_map_.clear();
    col_row_map_[col] = (row % detail_line) + 1;
    ctnm = coord_name_map_.find(col_row_map_);
    if (ctnm == coord_name_map_.end())
        return AnsiString();

    return ctnm->second;
}
//---------------------------------------------------------------------------
// 行数取得
int __fastcall TMainForm::GetLineNo(int row, int detail_line)
{
    int line_no = (row % detail_line) + 1;
    return line_no; 
}
//---------------------------------------------------------------------------
// 表示されている最大行数取得
int __fastcall TMainForm::GetMaxLineNo()
{
    int no = 0;
    for (int r = detail_line; r < max_row; r += detail_line){
        if (!SCGrid->Cells[0][r].IsEmpty())
            no = SCGrid->Cells[0][r].ToIntDef(0);
    }

    return no;
}
//---------------------------------------------------------------------------
// 表示されている最大行数取得 銘柄コードで判別
int __fastcall TMainForm::GetMaxLineNo_M()
{
    int no = 0;

    if (StrToCurrDef(SCGrid->Cells[GetColNo("1回目重量")][detail_line], 0) > 0)
        no = SCGrid->Cells[0][detail_line].ToIntDef(0);

    for (int r = detail_line; r < max_row; r += detail_line){
        if (StrToCurrDef(SCGrid->Cells[GetColNo("2回目重量")][r], 0) > 0 || StrToCurrDef(SCGrid->Cells[GetColNo("正味重量")][r], 0) > 0)
            no = SCGrid->Cells[0][r].ToIntDef(0);
    }

    return no;
}
//---------------------------------------------------------------------------
// 数量セルの単位なしの値を取得
Currency __fastcall TMainForm::GetSuryoCellValue(AnsiString cell)
{
    if (tani_id_ == 0)
        return StrToCurrDef(cell, 0);

    AnsiString tani_name = ToString(DM->DBI.Lookup("M_単位", "単位ID", tani_id_, "単位名称"));

    int index;
    while ((index = cell.AnsiPos(" ")) > 0)
        cell.Delete(index, 1);

    while ((index = cell.AnsiPos(tani_name)) > 0)
        cell.Delete(index, tani_name.Length());

    return StrToCurrDef(cell, 0);
}
//---------------------------------------------------------------------------
// 伝票Noの最後の明細の計量時間2を取得
TDateTime __fastcall TMainForm::GetLastKeiryoTime(int date, int slip_no, int place_id)
{
    NsRecordSet set;
    AnsiString  sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     V_計量"
          " WHERE"
          "     計量日 = " + IntToStr(date) +
          " AND"
          "     伝票No = " + IntToStr(slip_no) +
          " AND"
          "     拠点ID = " + IntToStr(place_id) +
          " ORDER BY"
          "     行No DESC";
    if (!DM->DBI.GetRecordSet(sql, set))
        return Now();

    if (SET_TOP(set)["計量日時2"].IsNull() && SET_TOP(set)["計量日時1"].IsNull())
        return Now();
    else if (SET_TOP(set)["計量日時2"].IsNull())
        return TDateTime(SET_TOP(set)["計量日時1"]);
    else
        return TDateTime(SET_TOP(set)["計量日時2"]);
}
//---------------------------------------------------------------------------
// 現在表示されているKeiryoTimePickerの時間を秒数00で取得
TDateTime __fastcall TMainForm::GetTimePicker_ZeroSec()
{
    TDateTime dt, keiryo_time;
    AnsiString time = KeiryoTimePicker->Time.FormatString("hh:nn:ss");
    time = time.SubString(1, 6);
    keiryo_time = StrToTime(time + "00");
    dt = CombineDateTime(KeiryoDatePicker->Date, keiryo_time);

    return dt;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SharyoCheck()
{
    int car_no = ShabanEdit->Text.ToIntDef(0);
    if (car_no < 1){
        ShabanEdit->Text = AnsiString();
        return false;
    }

    AnsiString sql;
    NsRecordSet set;

    DM->SetShabanQuery(GetMode() != imMod, GetPlaceID());

    if (DM->Q_Shaban->Active)
        DM->Q_Shaban->Close();
    DM->Q_Shaban->Parameters->ParamByName("CARNO")->Value = car_no;
    DM->Q_Shaban->Open();

    if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
        // 新規車両登録

        TDateTime now(Now());
        NsFieldSet fields;

        AnsiString name = IntToStr(car_no) + " (" + now.FormatString("mm/dd'登録'") + ")";
        new_car_fields_.clear();
        new_car_fields_
               << NsField("[車番]",     car_no)
               //<< NsField("[車両名称]", name)
               //<< NsField("[更新日時]", now)
               //<< NsField("[作成日時]", now)
               ;

        // DM->DBI.Insert("M_車両", new_car_fields_);

        SharyoNameEdit->Text = name;

        //car_id_ = DM->DBI.GetLastID();

        keiryo_count_ = 2;

        // 多段は処理しない
        //if (GetMode() == imFirst)
            //FirstWEdit->Text = cur_weight_;

        car_id_  = 0;
        new_car_ = true;
        SharyoNameEdit->ReadOnly = false;
        SharyoNameEdit->SetFocus();

        return true;
    }

    /** original **/
    /*
    if (GetMode() == imMod && DM->Q_Shaban->RecordCount == 1){
        int id = DM->Q_Shaban->FieldByName("車両ID")->AsInteger;
        if (id == car_id_)
            return true;
    }
    */
    if (GetMode() == imMod){
        while (!DM->Q_Shaban->Eof){
            if (DM->Q_Shaban->FieldByName("車両ID")->AsInteger == car_id_)
                return true;
            DM->Q_Shaban->Next();
        }
    }

    // 滞留車もしくは既存車両にヒットした場合、選択させる
    ShabanSanshoForm->TopPanel->Caption = "  車番：" + IntToStr(car_no);
    if (ShabanSanshoForm->ShowModal() != mrOk){
        ShabanEdit->SetFocus();
        return false;
    }

    car_id_      = ShabanSanshoForm->GetCarID();
    int mastered = ShabanSanshoForm->GetDataDiv();

    if (!car_id_){
        // 新規車両（上と同じ処理）
        NsFieldSet fields;
        TDateTime  now(Now());

        AnsiString name = IntToStr(car_no) + " (" + now.FormatString("mm/dd'登録'") + ")";
        new_car_fields_.clear();
        new_car_fields_
            << NsField("[車番]",     car_no)
            //<< NsField("[車両名称]", name)
            //<< NsField("[更新日時]", now)
            //<< NsField("[作成日時]", now)
            ;

        //DM->DBI.Insert("M_車両", fields);

        //car_id_ = DM->DBI.GetLastID();

        SharyoNameEdit->Text = name;

        keiryo_count_ = 2;

        // 多段は処理しない
        //if (GetMode() == imFirst)
            //FirstWEdit->Text = cur_weight_;

        car_id_  = 0;
        new_car_ = true;
        SharyoNameEdit->ReadOnly = false;
        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;
        SharyoNameEdit->SetFocus();
        ShabanEdit->OnExit = OnExit;

        return true;
    }

    if (mastered){
        // 車両マスタからの選択

        AnsiString sql;
        NsRecordSet set;

        sql = "SELECT * FROM V_車両 WHERE 車両ID = " + IntToStr(car_id_);
        if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("選択された車両が存在しません。\r\n別PCなどで削除されていないか確認してください。",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }

        if (GetMode() != imMod){
            if (TokuCodeEdit->Text.IsEmpty())
                TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["得意先コード"]));
            if (Komoku1CodeEdit->Text.IsEmpty())
                Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目1コード"]));
            if (Komoku2CodeEdit->Text.IsEmpty())
                Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目2コード"]));
            //if (HinCodeEdit->Text.IsEmpty())
                //HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["品目コード"]));

            if (ToCurrency(SET_TOP(set)["空車重量"]) > 0)
                keiryo_count_ = 1;
            else
                keiryo_count_ = 2;

            gross_limit_ = ToCurrency(SET_TOP(set)["車両総重量"]);
            net_limit_   = ToCurrency(SET_TOP(set)["最大積載量"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);

            /* 多段計量は処理しない
            if (keiryo_count_ == 2)
                FirstWEdit->Text = cur_weight_;
            else
                SecondWEdit->Text = cur_weight_;
            */
        }else{
            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
        }
    }else{
        // 滞留車からの選択
        int keiryo_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);
        if (!keiryo_id){
            Application->MessageBox("選択された滞留情報が存在しません。\r\n別PCなどで計量されていないか確認してください。",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }

        //TNotifyEvent OnExit = ShabanEdit->OnExit;
        //ShabanEdit->OnExit  = 0;
        ContinueWeighing(keiryo_id);
        //ShabanEdit->OnExit  = OnExit;
    }

    //if (keiryo_count_ == 1)
        //CalcWeight();

    return true;
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::CalcNextRow(int keiryo_id)
{
    NsRecordSet set;
    AnsiString  sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     D_計量"
          " WHERE"
          "     計量ID = " + IntToStr(keiryo_id);
          " ORDER BY"
          "     行No ASC";
    if (!DM->DBI.GetRecordSet(sql, set))
        return 0;

    // 1明細目の2回目重量が0以下だったら1明細目
    if (ToInt(SET_TOP(set)["2回目重量"]) <= 0)
        return detail_line;

    return (set.size() + 1) * detail_line;
}
//---------------------------------------------------------------------------

