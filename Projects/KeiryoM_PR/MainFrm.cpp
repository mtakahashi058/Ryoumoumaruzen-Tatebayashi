//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "AnbunFrm.h"
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
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner),
		keiryo_id_(0),
		cur_weight_(0), old_weight_(0),
		id_total_(0),
        rfid_thread_(0), last_card_no_(0)
{
	Application->OnMessage = MessageProc;

	gyo[0] = GyoTitleEdit;				gyo[1] = GyoEdit1;					gyo[2] = GyoEdit2;					gyo[3] = GyoEdit3;					gyo[4] = GyoEdit4;					gyo[5] = GyoEdit5;					gyo[6] = GyoEdit6;
	hincode[0] = HinCodeTitleEdit;		hincode[1] = HinCodeEdit1;			hincode[2] = HinCodeEdit2;			hincode[3] = HinCodeEdit3;			hincode[4] = HinCodeEdit4;			hincode[5] = HinCodeEdit5;			hincode[6] = HinCodeEdit6;
	hinname[0] = HinNameTitleEdit;		hinname[1] = HinNameEdit1;			hinname[2] = HinNameEdit2;			hinname[3] = HinNameEdit3;			hinname[4] = HinNameEdit4;			hinname[5] = HinNameEdit5;			hinname[6] = HinNameEdit6;
	weight1[0] = WeightTitleEdit1;		weight1[1] = WeightEdit11;			weight1[2] = WeightEdit21;			weight1[3] = WeightEdit31;			weight1[4] = WeightEdit41;			weight1[5] = WeightEdit51;			weight1[6] = WeightEdit61;
	weight2[0] = WeightTitleEdit2;		weight2[1] = WeightEdit12;			weight2[2] = WeightEdit22;			weight2[3] = WeightEdit32;			weight2[4] = WeightEdit42;			weight2[5] = WeightEdit52;			weight2[6] = WeightEdit62;
	choritu[0] = ChoseiTitleEdit;		choritu[1] = ChoseiPerEdit1;		choritu[2] = ChoseiPerEdit2;		choritu[3] = ChoseiPerEdit3;		choritu[4] = ChoseiPerEdit4;		choritu[5] = ChoseiPerEdit5;		choritu[6] = ChoseiPerEdit6;
	/* 調整タイトル共通 */				choweight[1] = ChoseiWeightEdit1;	choweight[2] = ChoseiWeightEdit2;	choweight[3] = ChoseiWeightEdit3;	choweight[4] = ChoseiWeightEdit4;	choweight[5] = ChoseiWeightEdit5;	choweight[6] = ChoseiWeightEdit6;
	bikiweight[0] = BikiWeightTitleEdit;bikiweight[1] = BikiWeightEdit1;	bikiweight[2] = BikiWeightEdit2;	bikiweight[3] = BikiWeightEdit3;	bikiweight[4] = BikiWeightEdit4;	bikiweight[5] = BikiWeightEdit5;	bikiweight[6] = BikiWeightEdit6;
	shomi[0] = ShomiTitleEdit;			shomi[1] = ShomiEdit1;				shomi[2] = ShomiEdit2;				shomi[3] = ShomiEdit3;				shomi[4] = ShomiEdit4;				shomi[5] = ShomiEdit5;				shomi[6] = ShomiEdit6;
	suryo[0] = SuryoTitleEdit;			suryo[1] = SuryoEdit1;				suryo[2] = SuryoEdit2;				suryo[3] = SuryoEdit3;				suryo[4] = SuryoEdit4;				suryo[5] = SuryoEdit5;				suryo[6] = SuryoEdit6;
	tanicode[0] = TaniTitleEdit;		tanicode[1] = TaniCodeEdit1;		tanicode[2] = TaniCodeEdit2;		tanicode[3] = TaniCodeEdit3;		tanicode[4] = TaniCodeEdit4;		tanicode[5] = TaniCodeEdit5;		tanicode[6] = TaniCodeEdit6;
	/* 単位タイトル共通 */				taniname[1] = TaniNameEdit1;		taniname[2] = TaniNameEdit2;		taniname[3] = TaniNameEdit3;		taniname[4] = TaniNameEdit4;		taniname[5] = TaniNameEdit5;		taniname[6] = TaniNameEdit6;
	tanka[0] = TankaTitleEdit;			tanka[1] = TankaEdit1;				tanka[2] = TankaEdit2;				tanka[3] = TankaEdit3;				tanka[4] = TankaEdit4;				tanka[5] = TankaEdit5;				tanka[6] = TankaEdit6;
	kingaku[0] = KingakuTitleEdit;		kingaku[1] = KingakuEdit1;			kingaku[2] = KingakuEdit2;			kingaku[3] = KingakuEdit3;			kingaku[4] = KingakuEdit4;			kingaku[5] = KingakuEdit5;			kingaku[6] = KingakuEdit6;
    shouhi[0] = ShouhizeiTitleEdit;     shouhi[1] = ShouhizeiEdit1;         shouhi[2] = ShouhizeiEdit2;         shouhi[3] = ShouhizeiEdit3;         shouhi[4] = ShouhizeiEdit4;          shouhi[5] = ShouhizeiEdit5;         shouhi[6] = ShouhizeiEdit6;
	biko[0] = BikoTitleEdit;			biko[1] = BikoEdit1;				biko[2] = BikoEdit2;				biko[3] = BikoEdit3;				biko[4] = BikoEdit4;				biko[5] = BikoEdit5;				biko[6] = BikoEdit6;
    //limit_line_ はヘッダファイルで定義済み
    //weighing1time[0] = {0}; weighing1time[1] = {0}; weighing1time[2] = {0}; weighing1time[3] = {0}; weighing1time[4] = {0}; weighing1time[5] = {0}; weighing1time[6] = {0}; weighing1time[7] = {0};
    //weighing2time[0] = {0}; weighing2time[1] = {0}; weighing2time[2] = {0}; weighing2time[3] = {0}; weighing2time[4] = {0}; weighing2time[5] = {0}; weighing2time[6] = {0}; weighing2time[7] = {0};
    memset(weighing1time, 0,sizeof(weighing1time));

	max_line_ = 1;
	delete_id_list_ = new TStringList();
    shomi_total_ = 0;
    kingaku_total_ = 0;
    tax_total_ = 0;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	TDBGrid *Grid = 0;
	int gyo = 3;

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

		for (int i = 0; i < gyo; i++){
			if((short)HIWORD(Msg.wParam) > 0){
				Grid->DataSource->DataSet->Prior();
			}else{
				Grid->DataSource->DataSet->Next();
			}
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

    // RFID
    if (ToInt(DM->CFG["卓上RFID計量"])){
        int rfid_port   =   ToInt(DM->INI[L"RFID::DeskCommPort"]);
        rfid_thread_    =   new THF04Thread(true, Handle, rfid_port);
        rfid_thread_->FreeOnTerminate = false;
        rfid_thread_->Resume();
    }

    weighing_border_ = ToInt(DM->INI["Weighing::SoundBorder"]);

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

	for (int i = 0; i < StatusBar->Panels->Count; i++)
		StatusBar->Panels->Items[i]->Text = AnsiString();

	if (ToString(DM->INI["Form::Maximized"]).ToIntDef(0) == 1)
		MainForm->WindowState = wsMaximized;

	Action1->Execute();
}
//---------------------------------------------------------------------------
// 設定内容をフォームに適用等
void __fastcall TMainForm::ApplyConfig()
{
	// DM->CFG.Debug();

	// [CFG]

	// MainForm
	TokuButton->Caption    = ToString(DM->CFG["得意先マスタ名称"]);
	Komoku1Button->Caption = ToString(DM->CFG["項目1マスタ名称"]);
	Komoku2Button->Caption = ToString(DM->CFG["項目2マスタ名称"]);
	hinname[0]->Text       = ToString(DM->CFG["品目マスタ名称"]);
	choritu[0]->Text       = ToString(DM->CFG["調整名称"]);
	bikiweight[0]->Text    = ToString(DM->CFG["重量引き名称"]);

	DM->kname_toku_		= AnsiReplaceStr(AnsiReplaceStr(TokuButton->Caption,	"　", ""), " ", "");
	DM->kname_hin_		= AnsiReplaceStr(AnsiReplaceStr(hinname[0]->Text,		"　", ""), " ", "");
	DM->kname_komoku1_	= AnsiReplaceStr(AnsiReplaceStr(Komoku1Button->Caption, "　", ""), " ", "");
	DM->kname_komoku2_	= AnsiReplaceStr(AnsiReplaceStr(Komoku2Button->Caption, "　", ""), " ", "");

	TairyuTokuisakiLabel->Caption = DM->kname_toku_;

	if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
		TokuPanel->Visible            = false;

		TairyuTokuisakiLabel->Visible = false;
		TairyuTokuisakiText->Visible  = false;
	}
	if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
		Komoku1Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
		Komoku2Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["品目マスタ使用区分"])){
		// 多段で品目は必須とする
		//HinPanel->Visible             = false;
	}
    if (!ToBit(DM->CFG["入出庫使用区分"])){
        HannyuPanel->Visible = false;
		RecalcButton->Visible = false;

	}
	if (!ToBit(DM->CFG["調整使用区分"])){
		choritu[0]->Visible = false;
	}
	if (!ToBit(DM->CFG["重量引き使用区分"])){
		bikiweight[0]->Visible = false;
	}
	if (!ToBit(DM->CFG["単価使用区分"])){
		suryo[0]->Visible    = false;
		tanicode[0]->Visible = false;
		//taniname[0]->Visible = false;
		tanka[0]->Visible    = false;
		kingaku[0]->Visible  = false;
        //20160606
        shouhi[0]->Visible   = false;
	}
	if (!ToBit(DM->CFG["重量編集区分"])){
		for (int i = 1; i < 7; i++){
			weight1[i]->ReadOnly = true;
			weight2[i]->ReadOnly = true;
		}
	}
    //多段時消費税計算区分
    if (ToString(DM->CFG["多段時消費税計算区分"]).ToIntDef(1) == 1){
        shouhi[0]->Visible = false;
    }

	int default_index = 0;
	int place_code    = ToInt(DM->INI["Place::Code"]);
	PlaceCombo->Items->Clear();
	for (unsigned int i = 0; i < DM->PlaceSet.size(); i++){
		PlaceCombo->Items->Append(ToString(DM->PlaceSet[i]["拠点名称"]));
		if (ToInt(DM->PlaceSet[i]["拠点コード"]) == place_code)
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

	// ヒント
	TokuCodeEdit->Hint    = DM->kname_toku_    + "コードを入力してください。(" + DM->kname_toku_    + "ボタン or [F4]→マスタ参照)";
	Komoku1CodeEdit->Hint = DM->kname_komoku1_ + "コードを入力してください。(" + DM->kname_komoku1_ + "ボタン or [F4]→マスタ参照)";
	Komoku2CodeEdit->Hint = DM->kname_komoku2_ + "コードを入力してください。(" + DM->kname_komoku2_ + "ボタン or [F4]→マスタ参照)";
	for (int i = 1; i < limit_line_ + 1; i++)
		hincode[i]->Hint     = DM->kname_hin_     + "コードを入力してください。(" + DM->kname_hin_     + "ボタン or [F4]→マスタ参照)";

	// グリッド（明細入力部分）の整形 ++++++++++++++++++++++++++++++++++++++++++
	int left = weight2[0]->Left + weight2[0]->Width + 3;
	// 調整
	if (choritu[0]->Visible)
		left = choritu[0]->Left + choritu[0]->Width + 3;
	else{
		for (int i = 1; i < limit_line_ + 1; i++){
			choritu[i]->Visible   = false;
			choweight[i]->Visible = false;
		}
	}
	// 重量引き
	if (bikiweight[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			bikiweight[i]->Left = left;
		left = bikiweight[0]->Left + bikiweight[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			bikiweight[i]->Visible = false;
	}
	// 正味重量
	if (shomi[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			shomi[i]->Left = left;
		WeightSumTitleLabel->Left = left - 52;
		ShomiSumEdit->Left = left;
		left = shomi[0]->Left + shomi[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			shomi[i]->Visible = false;
		WeightSumTitleLabel->Visible = false;
		ShomiSumEdit->Visible        = false;
	}
	// 数量
	if (suryo[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			suryo[i]->Left = left;
		left = suryo[0]->Left + suryo[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			suryo[i]->Visible = false;
	}
	// 単位
	if (tanicode[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++){
			tanicode[i]->Left = left;
			if (i > 0)
				taniname[i]->Left = tanicode[i]->Left + tanicode[i]->Width + 3;
		}
		left = tanicode[0]->Left + tanicode[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++){
			tanicode[i]->Visible = false;
			taniname[i]->Visible = false;
		}
	}
	// 単価
	if (tanka[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			tanka[i]->Left = left;
		left = tanka[0]->Left + tanka[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			tanka[i]->Visible = false;
	}
	// 金額
	if (kingaku[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			kingaku[i]->Left = left;
		KingakuSumTitleLabel->Left = left - 90;
		KingakuSumEdit->Left = left;
		ShohizeiTitleLabel->Left = left + 100;
		ShohizeiEdit->Left = left + 148;
		left = kingaku[0]->Left + kingaku[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			kingaku[i]->Visible       = false;
		KingakuSumTitleLabel->Visible = false;
		KingakuSumEdit->Visible       = false;
		ShohizeiTitleLabel->Visible   = false;
		ShohizeiEdit->Visible         = false;
        KingakuPanel->Visible         = false;
	}
    //消費税
    if (shouhi[0]->Visible){
        for (int i = 0; i < limit_line_ + 1; i++)
            shouhi[i]->Left + shouhi[0]->Width + 3;
        left = shouhi[0]->Left + shouhi[0]->Width + 3;
    }else{
        for (int i = 0; i < limit_line_ + 1; i++)
            shouhi[i]->Visible = false;
    }
	// 明細備考
	if (biko[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			biko[i]->Left = left;
		left = biko[0]->Left + biko[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			biko[i]->Visible = false;
	}
	MeisaiScrollBox2->HorzScrollBar->Position = 0;
}
//---------------------------------------------------------------------------
// MainForm->OnClose
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete delete_id_list_;

	try{
		if (MainForm->WindowState == wsMaximized)
			DM->INI.SaveSingle("Form", "Maximized", 1);
		else
			DM->INI.SaveSingle("Form", "Maximized", 0);
	}catch (...){}
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
    return ToInt(DM->PlaceSet[PlaceCombo->ItemIndex]["拠点ID"]);
}
//---------------------------------------------------------------------------
// フォームをクリア
void __fastcall TMainForm::ClearForm()
{
    keiryo_id_ = 0;
    keiryo_set_.clear();

    toku_id_      = 0;
    toku_rec_.clear();

    new_car_      = false;
    car_id_       = 0;
    keiryo_count_ = 0;
    gross_limit_  = 0;
    net_limit_    = 0;

    TDateTime now(Now());

    KeiryoDatePicker->Date    = Date();
    KeiryoTimePicker->Time    = now;
    KeiryoNoEdit->Text        = AnsiString();
    ShabanEdit->Text          = AnsiString();
    ShabanEdit->OnChange(NULL);
    TokuCodeEdit->Text        = AnsiString();
	TokuNameEdit->Text        = AnsiString();
	Komoku1CodeEdit->Text     = AnsiString();
	Komoku1NameEdit->Text     = AnsiString();
	Komoku2CodeEdit->Text     = AnsiString();
	Komoku2NameEdit->Text     = AnsiString();
    //搬入コンボd
	HannyuCombo->ItemIndex    = -1;
	BikoEdit->Text            = AnsiString();

	// 明細グリッド
	for (int i = 1; i < limit_line_ + 1; i++){
		hincode[i]->Text = AnsiString();
		hinname[i]->Text = AnsiString();
		weight1[i]->Text = AnsiString();
		weight2[i]->Text = AnsiString();
		choritu[i]->Text = AnsiString();
		choweight[i]->Text = AnsiString();
		bikiweight[i]->Text = AnsiString();
		shomi[i]->Text = AnsiString();
		suryo[i]->Text = AnsiString();
		tanicode[i]->Text = AnsiString();
		taniname[i]->Text = AnsiString();
		tanka[i]->Text = AnsiString();
		kingaku[i]->Text = AnsiString();
        shouhi[i]->Text  = AnsiString();
		biko[i]->Text = AnsiString();
        tanka[i]->Color = clWindow;
		StringGridID->Cells[0][i] = AnsiString();
	}
	ShomiSumEdit->Text = AnsiString();
	KingakuSumEdit->Text = AnsiString();
	ShohizeiEdit->Text = AnsiString();
	ZeikomiEdit->Text = AnsiString();
	max_line_ = 1;
	MeisaiScrollBox2->HorzScrollBar->Position = 0;
	keiryo_kaisu_ = 0;

	// 履歴クリア
	SetRireki(0);
    //正味重量クリア
    shomi_total_ = 0;
    //金額(税抜き)クリア
    kingaku_total_ = 0;
    //税額
    tax_total_ = 0;
}
//---------------------------------------------------------------------------
// 計量ID からレコードをを読み込み
bool __fastcall TMainForm::LoadFromID(int id)
{
	AnsiString sql;
	sql = " SELECT * FROM V_計量"
		  " WHERE"
		  "		計量日 IN ( SELECT 計量日 FROM D_計量 WHERE 計量ID = " + IntToStr(id) + ") "
		  " AND"
		  "		拠点ID IN ( SELECT 拠点ID FROM D_計量 WHERE 計量ID = " + IntToStr(id) + ") "
		  " AND"
		  "     伝票No IN ( SELECT 伝票No FROM D_計量 WHERE 計量ID = " + IntToStr(id) + ") "
		  " AND"
		  "     完了区分 <> 9"                 // 論理削除は対象外
          " ORDER BY"
          "     計量日, 伝票No, 行No";

	if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
		return false;

	KeiryoDatePicker->Date       = IntToDate(ToInt(SET_TOP(keiryo_set_)["計量日"]));
	PlaceCombo->ItemIndex        = DM->FindPlaceIndexByID(ToInt(SET_TOP(keiryo_set_)["拠点ID"]));
	KeiryoNoEdit->Text           = ToInt(SET_TOP(keiryo_set_)["伝票No"]);

    // 完了データ以外は今の時間を表示
    if (ToInt(SET_TOP(keiryo_set_)["完了区分"]) == 1)
        KeiryoTimePicker->Time = GetLastKeiryoTime(DateToInt(KeiryoDatePicker->Date), StrToInt(KeiryoNoEdit->Text), ToInt(SET_TOP(keiryo_set_)["拠点ID"]));
        //KeiryoTimePicker->Time = ToInt(SET_TOP(keiryo_set_)["計量時間"]);
    else
        KeiryoTimePicker->Time = Now();

	car_id_                      = ToInt(SET_TOP(keiryo_set_)["車両ID"]);
	ShabanEdit->Text             = ToInt(SET_TOP(keiryo_set_)["車番"]);
	SharyoNameEdit->Text         = ToString(SET_TOP(keiryo_set_)["車両名称"]);

	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["得意先コード"]));
	TokuNameEdit->Text           = ToString(SET_TOP(keiryo_set_)["得意先名称"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目1コード"]));
	Komoku1NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["項目1名称"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目2コード"]));
	Komoku2NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["項目2名称"]);
    BikoEdit->Text               = ToString(SET_TOP(keiryo_set_)["備考"]);

    //20160624 搬入分追加
    HannyuCombo->ItemIndex       = ToInt(SET_TOP(keiryo_set_)["搬入出区分"]) - 1;

	ShohizeiEdit->Text = ToCurrency(SET_TOP(keiryo_set_)["伝票消費税額"]);

	// 明細
	for (unsigned int i = 0; i < keiryo_set_.size(); i++){
		hincode[i+1]->Text    = ToInt(keiryo_set_[i]["品目コード"]);
		hinname[i+1]->Text    = ToString(keiryo_set_[i]["品目名称"]);
		weight1[i+1]->Text    = ZeroSuppress(ToCurrency(keiryo_set_[i]["1回目重量"]));
		weight2[i+1]->Text    = ZeroSuppress(ToCurrency(keiryo_set_[i]["2回目重量"]));
		choritu[i+1]->Text    = FormatFloat("#.##%", ToCurrency(keiryo_set_[i]["調整率"]));
		choweight[i+1]->Text  = ZeroSuppress(ToCurrency(keiryo_set_[i]["調整重量"]));
		bikiweight[i+1]->Text = ZeroSuppress(ToCurrency(keiryo_set_[i]["重量引き"]));
		shomi[i+1]->Text      = ZeroSuppress(ToCurrency(keiryo_set_[i]["正味重量"]));
		suryo[i+1]->Text      = ZeroSuppress(ToCurrency(keiryo_set_[i]["数量"]));
		tanicode[i+1]->Text   = ZeroSuppress(ToCurrency(keiryo_set_[i]["単位コード"]));
		taniname[i+1]->Text   = ToString(keiryo_set_[i]["単位マスタ名称"]);
		tanka[i+1]->Text      = ZeroSuppress(ToCurrency(keiryo_set_[i]["単価"]));
        biko[i+1]->Text       = ToString(keiryo_set_[i]["明細備考"]);
        // 単価が"NULL"のときはセルに0表示
        if (tanka[i+1]->Text == ""){
            tanka[i+1]->Text = "0";
        }
        TankaCheck(i+1);
		kingaku[i+1]->Text    = ZeroSuppress(ToCurrency(keiryo_set_[i]["金額"]));
        // 金額が"NULL"のときはセルに0表示
        if (kingaku[i+1]->Text == ""){
            kingaku[i+1]->Text = "0";
        }
        shouhi[i+1]->Text     = ZeroSuppress(ToCurrency(keiryo_set_[i]["消費税額"]));
		biko[i+1]->Text       = ToString(keiryo_set_[i]["明細備考"]);
		StringGridID->Cells[0][i+1] = ToString(keiryo_set_[i]["計量ID"]);

		if (ToCurrency(keiryo_set_[i]["2回目重量"]) == 0)
			keiryo_kaisu_ = i + 1;
		else
			keiryo_kaisu_ = i + 2;

        //金額計(税別) 計算
//        kingaku_total_ += ToInt(keiryo_set_[i]["金額"]);
	}
	max_line_ = keiryo_set_.size();

	// 履歴表示
	SetRireki(car_id_);

    //税別金額表示
//    KingakuSumEdit->Text = IntToStr(kingaku_total_);
    CalcKingaku();
    //消費税表示
    CalcSalesTax();
    //正味重量合計
    CalcShomiTotal();

	return true;
}
//---------------------------------------------------------------------------
// 新規計量開始
void __fastcall TMainForm::StartWeighing()
{
	ClearForm();

	SetMode(imFirst);

	/* 拠点切り替えを有効にするために
	int default_index = 0;
	int place_code    = ToInt(DM->INI["Place::Code"]);
	for (unsigned int i = 0; i < DM->PlaceSet.size(); i++){
		if (ToInt(DM->PlaceSet[i]["拠点コード"]) == place_code)
			default_index = i;
	}
	PlaceCombo->ItemIndex = default_index;
	*/

	KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));

	ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// 継続（滞留車）計量開始
void __fastcall TMainForm::ContinueWeighing(int id)
{
	ClearForm();
	SetMode(imSecond);
//	ShabanEdit->SetFocus();

	keiryo_id_ = id;
	if (!LoadFromID(keiryo_id_)){
		Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	switch (ToInt(SET_TOP(keiryo_set_)["完了区分"])){
	case 0:             // 滞留車
		break;
	case 1:             // 完了済
		Application->MessageBox("この滞留車はすでに計量されています。\r\n別PCなどで計量されていないか確認してください。",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	default:                // 削除済
		Application->MessageBox("滞留データの読み込みに失敗しました。",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	TNotifyEvent OnExit = ShabanEdit->OnExit;
	ShabanEdit->OnExit  = 0;

	int mei_cnt = keiryo_set_.size();
	if (mei_cnt == 1 && StrToCurrDef(weight2[mei_cnt]->Text, 0) == 0){
		weight2[mei_cnt]->Text = cur_weight_;
        weight2[mei_cnt]->SetFocus();
	}else{
        //次行へ
        mei_cnt += 1;
	}

    if (mei_cnt != 1)
        CalcWeight();
/*
    20160519
    備考EditのkeydownEventに移動する
	Action10->OnExecute(NULL);
*/
/*
*/
	if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
		TokuCodeEdit->SetFocus();
	else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
		Komoku1CodeEdit->SetFocus();
	else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
		Komoku2CodeEdit->SetFocus();
    else if (mei_cnt == 1){     //1明細目の2回目重量専用
        weight2[mei_cnt]->SetFocus();
    }else{
        hincode[mei_cnt]->SetFocus();
        Action10->Execute();
    }

	ShabanEdit->OnExit  = OnExit;
}
//---------------------------------------------------------------------------
// 計量登録
void __fastcall TMainForm::PostWeighing()
{
	InputMode mode = GetMode();

	TDateTime now(Now());

	if (!CheckOverload())
		return;

	if (!ValidateForm())
		return;

	bool comp;
	int  value;

	// 登録する明細行が最大行かをチェック
	PostConfForm->ButtonKeizoku->Enabled = true;
    max_line_ = keiryo_set_.size();

    if (GetRowNo() == 6){
        max_line_ = 6;
    }

    int row_no = GetRowNo();


	if (max_line_ == 6)
		PostConfForm->ButtonKeizoku->Enabled = false;

	value = PostConfForm->ShowModal();
	if (value == IDYES)     // 完了ボタン
		comp = true;
	else if (value == IDNO){ // 継続ボタン
        comp = false;
        ShudoCheckBox->Checked = false;
    }else                    // キャンセルボタン
        return;

    // 手動入力時のみ 重量再計算を行う
    if (ShudoCheckBox->Checked){
        RecalcButton->Click();
    }


	int toku_id, hin_id, item1_id, item2_id;
	AnsiString toku_name, hin_name, item1_name, item2_name;
	int zei_hasu;

	toku_id    = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "得意先ID"));
	toku_name  = TokuNameEdit->Text;
	//hin_id     = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目ID"));
	//hin_name   = HinNameEdit->Text;
	item1_id   = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
	item1_name = Komoku1NameEdit->Text;
	item2_id   = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
	item2_name = Komoku2NameEdit->Text;

	zei_hasu   = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "消費税端数処理区分"));
	if (zei_hasu)
		zei_hasu = ToInt(DM->CFG["消費税端数処理区分"]);
	Currency zeiritu = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date)); // 消費税率取得

	int kyoten_id = GetPlaceID();
    TDateTime old_second_time; //前の明細の計量時間2

	NsFieldSet keys, fields;

	if (new_car_){
		//////////////////////////////////////////////////////////////////////
		// 新規車両の場合、車両マスタを登録
		new_car_fields_
			<< NsField("[車両名称]",   SharyoNameEdit->Text)
			<< NsField("[使用区分]",   1)
			<< NsField("[更新日時]",   now)
			<< NsField("[作成日時]",   now)
			;
		DM->DBI.Insert("M_車両", new_car_fields_);
		car_id_ = DM->DBI.GetLastID();
	}
try{

	DM->ADOConnection->BeginTrans();

	if (comp && mode != imMod){		// 完了登録で修正モードじゃない場合
		KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
	}else if (mode == imFirst){		// 滞留登録
		KeiryoNoEdit->Text = DM->GetTempNo(GetPlaceID());
	}

	// 明細登録
	for (int i = 1; i < limit_line_ + 1; i++){
    /*
		if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
			continue;
    */
        if (i > 1 && hincode[i]->Text.IsEmpty())
            continue;

        //行No 20160525
        now = Now();
		hin_id   = ToInt(DM->DBI.Lookup("M_品目", "品目コード", hincode[i]->Text.ToIntDef(0), "品目ID"));
		hin_name = ToString(DM->DBI.Lookup("M_品目", "品目コード", hincode[i]->Text.ToIntDef(0), "品目名称"));

		keys.clear();
		fields.clear();


		keys << NsField("[計量ID]", StringGridID->Cells[0][i].ToIntDef(0));

		fields
			<< NsField("[計量日]",       DateToInt(KeiryoDatePicker->Date))
			<< NsField("[拠点ID]",       kyoten_id)
			<< NsField("[伝票No]",       StrToCurrDef(KeiryoNoEdit->Text, 0))
			<< NsField("[車両ID]",       car_id_)
			<< NsField("[得意先ID]",     toku_id)
			<< NsField("[得意先名称]",   toku_name)
			<< NsField("[項目1ID]",      item1_id)
			<< NsField("[項目1名称]",    item1_name)
			<< NsField("[項目2ID]",      item2_id)
			<< NsField("[項目2名称]",    item2_name)
			<< NsField("[備考]",         BikoEdit->Text)
            //20160607
			//<< NsField("[伝票消費税額]", ExtendedRound(StrToCurrDef(KingakuSumEdit->Text, 0) * zeiritu, 0, zei_hasu))
            << NsField("[伝票消費税額]", slip_tax_)

			<< NsField("[行No]",         i)
			<< NsField("[品目ID]",       hin_id)
			<< NsField("[品目名称]",     hin_name)
			<< NsField("[1回目重量]",    StrToCurrDef(weight1[i]->Text, 0))
			<< NsField("[2回目重量]",    StrToCurrDef(weight2[i]->Text, 0))
			<< NsField("[調整率]",       StrToCurrDef(AnsiReplaceStr(choritu[i]->Text, "%", ""), 0))
			<< NsField("[調整重量]",     StrToCurrDef(choweight[i]->Text, 0))
			<< NsField("[重量引き]",     StrToCurrDef(bikiweight[i]->Text, 0))
			<< NsField("[正味重量]",     StrToCurrDef(shomi[i]->Text, 0))
			<< NsField("[数量]",         StrToCurrDef(suryo[i]->Text, 0))
			<< NsField("[単位ID]",       ToInt(DM->DBI.Lookup("M_単位", "単位コード", tanicode[i]->Text.ToIntDef(0), "単位ID")))
			<< NsField("[単価]",         StrToCurrDef(tanka[i]->Text, 0))
			<< NsField("[金額]",         StrToCurrDef(kingaku[i]->Text, 0))
			//<< NsField("[消費税額]",     ExtendedRound(StrToCurrDef(kingaku[i]->Text, 0) * zeiritu, 0, zei_hasu))
            << NsField("[消費税額]",     StrToCurrDef(shouhi[i]->Text, 0))
			<< NsField("[明細備考]",     biko[i]->Text)
			<< NsField("[完了区分]",     comp ? 1 : 0)
			<< NsField("[更新日時]",     now)
			//<< NsField("[作成日時]",  )
			;

		// 制御マスタ::入出庫使用区分
		if (ToBit(DM->CFG["入出庫使用区分"]))
			fields << NsField("[搬入出区分]", HannyuCombo->ItemIndex + 1);
		else
			fields << NsField("[搬入出区分]", 1);

        //計量ID取得
        NsRecordSet set;
        AnsiString sql;
        //時間テスト変数
        int new_int_time;

        //計量ID
        int chk_keiryoID = StringGridID->Cells[0][i].ToIntDef(0);

        sql =   " SELECT"
                "       *"
                " FROM"
                "       D_計量"
                " WHERE"
                "   計量ID = " + IntToStr(chk_keiryoID);

        if (ShudoCheckBox->Checked){
            now = KeiryoTimePicker->Time;
        }


        if(DM->DBI.GetRecordSet(sql, set)){
            if (ToString(SET_TOP(set)["計量日時2"]) == ""){
                old_second_time = now;
            }else{
                old_second_time = ToString(SET_TOP(set)["計量日時2"]);
            }
        }

        if (mode == imFirst){
            if(!comp){
                fields  <<  NsField("[計量日時1]", now);

                //2回目重量が0以外なら登録する
                if (StrToCurrDef(weight2[i]->Text, 0) != 0){
                    fields  <<  NsField("[計量日時2]", now);
                }
            }else{ // 全登録
                fields  <<  NsField("[計量日時1]", now)
                        <<  NsField("[計量日時2]", now);
            }
        }else if(mode == imSecond){
            //計量ID == 0 日時1,日時2を登録
            if(chk_keiryoID == 0){
                fields  <<  NsField("[計量日時1]", old_second_time)
                        <<  NsField("[計量日時2]", now);
            }

            // 計量ID != 0
            if (chk_keiryoID != 0){
                if (i == 1 && StrToCurrDef(weight2[i]->Text, 0) != 0){
                    if(hincode[2]->Text == ""){
                        fields  <<  NsField("[計量日時2]", GetTimePicker_ZeroSec());
                        //old_second_time = now;
                        old_second_time = GetTimePicker_ZeroSec();
                    }
                }
            }

        }else if (mode == imMod){
            // 修正モードで新たに作成した行の処理
            if (chk_keiryoID == 0){
                if (max_line_ == i){
                    fields  <<  NsField("[計量日時2]", GetTimePicker_ZeroSec());
                }else{
                    fields  <<  NsField("計量日時2", now);
                }
            }

            // 最後の明細データの計量時間2に印字計量時間を上書きする
            if (chk_keiryoID != 0 && max_line_ == i){
                fields  <<  NsField("[計量日時2]", GetTimePicker_ZeroSec());
            }
        }else{
            return;
        }

//		if (!DM->DBI.IsExist("D_計量", keys)){
		if (!chk_keiryoID || !DM->DBI.IsExist("D_計量", keys)){
			fields << NsField("[作成日時]",  now);
			DM->DBI.Insert("D_計量", fields);
            //印刷用
            keiryo_id_ = DM->DBI.GetLastID();
		}else
			DM->DBI.Update("D_計量", keys, fields);
	}


	int cmp_kbn;
	bool print = false;                 // 印刷するかどうか（def: false）
	bool create_tran_data = true;      // 売上データを作成するかどうか（def: false）

	if (comp){
		StatusBar->Panels->Items[0]->Text = "登録しました (計量日=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";

		if (AutoPrintCheck->Checked && mode != imMod)
			print = true;

	}else{
		StatusBar->Panels->Items[0]->Text = "滞留車を登録しました (車番=" + ShabanEdit->Text + ")";
        //完了後の修正から滞留へ戻したときに連続登録を防ぐため
        SetMode(imSecond);
        mode = GetMode();
	}

    if (mode == imMod){
        if(Application->MessageBox("修正した伝票を発行しますか?", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES){
            print = true;
        }
    }


	if (!DataDeleteCheck->Checked)
    	create_tran_data = ToInt(DM->CFG["取引データ作成"]) ? true : false;

    //データを残さない
    if (GetMode() != imMod && DataDeleteCheck->Checked){
        create_tran_data = false;
    }

	if (create_tran_data){
		//////////////////////////////////////////////////////////////////////
		// 売上データ

		std::auto_ptr<TStringList> gyo_no_list(new TStringList());

		NsRecordSet set;
		AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID IN ( "
									"SELECT 計量ID FROM D_計量 "
									"WHERE 計量日 = " + IntToStr(DateToInt(KeiryoDatePicker->Date)) + " "
									"AND   拠点ID = " + IntToStr(kyoten_id) + " "
									"AND   伝票No = " + CurrToStr(StrToCurrDef(KeiryoNoEdit->Text, 0)) + ") "
                                    "ORDER BY 計量日,拠点ID, 伝票No, 行No";
		DM->DBI.GetRecordSet(sql, set);

        int slip_no = DM->GetTransNo(ToInt(SET_TOP(set)["拠点ID"]), ToInt(SET_TOP(set)["計量日"]));
        if (DM->DBI.IsExist("D_取引", "計量ID", ToInt(SET_TOP(set)["計量ID"])))
            slip_no = ToInt(DM->DBI.Lookup("D_取引", "計量ID", ToInt(SET_TOP(set)["計量ID"]), "伝票No"));
        else
            slip_no = DM->GetTransNo(ToInt(SET_TOP(set)["拠点ID"]), ToInt(SET_TOP(set)["計量日"]));

		for (unsigned int i = 0; i < set.size(); i++){
			keys.clear();
			keys	<< NsField("[計量ID]",       ToInt(set[i]["計量ID"]));

			fields.clear();
			fields	<< NsField("[取引日]",       ToInt(set[i]["計量日"]))
					<< NsField("[拠点ID]",       ToInt(set[i]["拠点ID"]))
                    << NsField("[伝票No]",       slip_no)
					<< NsField("[計量ID]",       ToInt(set[i]["計量ID"]))
					<< NsField("[取引区分]",     ToInt(set[i]["取引区分"]))
					<< NsField("[車両ID]",       ToInt(set[i]["車両ID"]))
					<< NsField("[得意先ID]",     ToInt(set[i]["得意先ID"]))
					<< NsField("[得意先名称]",   ToString(set[i]["得意先名称"]))
					<< NsField("[項目1ID]",      ToInt(set[i]["項目1ID"]))
					<< NsField("[項目1名称]",    ToString(set[i]["項目1名称"]))
					<< NsField("[項目2ID]",      ToInt(set[i]["項目2ID"]))
					<< NsField("[項目2名称]",    ToString(set[i]["項目2名称"]))
					<< NsField("[備考]",         ToString(set[i]["備考"]))
					<< NsField("[伝票消費税額]", ToCurrency(set[i]["伝票消費税額"]))
					<< NsField("[行No]",         ToInt(set[i]["行No"]))
					<< NsField("[品目ID]",       ToInt(set[i]["品目ID"]))
					<< NsField("[品目名称]",     ToString(set[i]["品目名称"]))
					<< NsField("[数量]",         ToCurrency(set[i]["数量"]))
					<< NsField("[単位ID]",       ToInt(set[i]["単位ID"]))
					<< NsField("[単価]",         ToCurrency(set[i]["単価"]))
					<< NsField("[金額]",         ToCurrency(set[i]["金額"]))
					<< NsField("[消費税額]",     ToCurrency(set[i]["消費税額"]))
					<< NsField("[明細備考]",     ToString(set[i]["明細備考"]))
					<< NsField("[完了区分]",     1)
					<< NsField("[更新日時]",     now)
					;
			if (!DM->DBI.IsExist("D_取引", keys)){
				fields << NsField("[作成日時]",  now);
				DM->DBI.Insert("D_取引", fields);
			}else{
				DM->DBI.Update("D_取引", keys, fields);
			}
			gyo_no_list->Add(ToString(set[i]["行No"]));
		}

        if (keiryo_id_ == 0){
            keiryo_id_ = ToInt(SET_TOP(set)["計量ID"]);
        }
	}

	DM->ADOConnection->CommitTrans();


	// 自動伝票発行
	if (print){
        Print(keiryo_id_);
    }

}catch (Exception& e){
	DM->ADOConnection->RollbackTrans();
	AnsiString msg = "登録時にエラーが発生しました - " + e.Message;
	Application->MessageBox(msg.c_str(), "登録エラー", MB_OK | MB_ICONWARNING);
	return;
}

    //"データを残さない"用にif文を追加
    if (!DataDeleteCheck->Checked){
        Application->MessageBox("登録が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    }

	Q_Tairyu->Close();
	Q_Tairyu->Open();

    if(mode != imMod)
        Action1->Execute();
    else{
        //LoadFromID(keiryo_id_);
        int date = DateToInt(KeiryoDatePicker->Date);
        int kyo  = GetPlaceID();
        int denpyo  = KeiryoNoEdit->Text.ToIntDef(0);

        NsRecordSet set;
        AnsiString sql;
        sql =  " SELECT 計量ID FROM D_計量"
               " WHERE  計量日 = " + IntToStr(date) + " AND 拠点ID = " + IntToStr(kyo) +
               " AND    伝票No = " + IntToStr(denpyo);

        DM->DBI.GetRecordSet(sql, set);
        keiryo_id_ = SET_TOP(set)["計量ID"];
        //ClearForm();
        LoadFromID(keiryo_id_);
    }
}
//---------------------------------------------------------------------------
// 伝票発行
void __fastcall TMainForm::Print(int keiryo_id)
{
	int slip_type = ToInt(DM->CFG["伝票発行プリンタ"]);

	if (slip_type == 1){
		// レーザー
/*
		if (!LaserSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;
*/
        //20160519
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
                if(!DataDeleteCheck->Checked)
                    return;
        }else{
            if (LaserSlipPrintM_GenkinForm->Print(keiryo_id, HideTimeCheck->Checked))
                if(!DataDeleteCheck->Checked)
                    return;
        }


	}else if (slip_type == 2){
		// ドット

		if (!DotSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
            if(!DataDeleteCheck->Checked)
    			return;

    }else{
        // nothing to do
    }

    if (GetMode() != imMod && DataDeleteCheck->Checked){
        NsRecordSet set;
        AnsiString sql;
        int date, place_id, slip_no;

        if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id), set)){
            Application->MessageBox("データ呼び出しに失敗しました\r\n手動でデータを削除してください", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }

        date        =   ToInt(SET_TOP(set)["計量日"]);
        place_id    =   ToInt(SET_TOP(set)["拠点ID"]);
        slip_no     =   ToInt(SET_TOP(set)["伝票No"]);

        sql =   " DELETE"
                "       FROM D_計量"
                " WHERE"
                "       計量日 = " + IntToStr(date) +
                " AND"
                "       拠点ID = " + IntToStr(place_id) +
                " AND"
                "       伝票No = " + IntToStr(slip_no);

        try{
            DM->ADOConnection->BeginTrans();

            DM->DBI.Execute(sql);

            DM->ADOConnection->CommitTrans();

        }catch(Exception& e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox("データ削除に失敗しました\r\n手動でデータを削除してください", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
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
	Currency max = 0;
	for (int i = 1; i < limit_line_ + 1; i++){
		if (StrToCurrDef(weight1[i]->Text, 0) > max)
			max = StrToCurrDef(weight1[i]->Text, 0);
		if (StrToCurrDef(weight2[i]->Text, 0) > max)
			max = StrToCurrDef(weight2[i]->Text, 0);
	}

	AnsiString msg;

	if (gross_limit_ > 0 && max > gross_limit_){
		msg = "車両総重量に対する過積載です\r\n\r\n"
			  "現在の重量: " + FormatFloat("###,##0.#' kg'", max) + "\r\n"
			  "車両総重量: " + FormatFloat("###,##0.#' kg'", gross_limit_);
		Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
/*
	if (net > 0 && net_limit_ > 0 && net > net_limit_){
		msg = "最大積載量に対する過積載です\r\n\r\n"
			  "現在の重量: " + FormatFloat("###,##0.#' kg'", net) + "\r\n"
			  "最大積載量: " + FormatFloat("###,##0.#' kg'", net_limit_);
		Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
*/
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
// 正味重量の計算
void __fastcall TMainForm::CalcWeight(int row)
{
	if (row == 9)
		row = GetRowNo();
	if (row == 0)
		return;

	Currency w1, w2, net;

	w1 = StrToCurrDef(weight1[row]->Text, 0);
	w2 = StrToCurrDef(weight2[row]->Text, 0);

	if (w1 >= w2)
		net = w1 - w2;
	else
		net = w2 - w1;

	if (ToBit(DM->CFG["調整使用区分"])){
		Currency coord, coord_ratio;
		coord       = StrToCurrDef(choweight[row]->Text, 0);

		coord_ratio = StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0) / 100;

		if (coord_ratio > 0){       // 調整率使用
			coord = ExtendedRound(net * coord_ratio, ToInt(DM->CFG["調整端数処理桁数"]), ToInt(DM->CFG["調整端数処理区分"]));
			choweight[row]->Text = coord;
		}else{
			coord = 0;
			//choweight[row]->Text = coord;
            //0だったら空白を
		}

		net -= int(coord);
	}

	if (ToBit(DM->CFG["重量引き使用区分"])){
		Currency reduc = StrToCurrDef(bikiweight[row]->Text, 0);
		net -= reduc;
	}

	shomi[row]->Text = net;

    //  デフォルトの単位を指定 kg
	if (tanicode[row]->Text.IsEmpty()){
		int default_code = ToInt(DM->CFG["標準単位"]);
		if (!default_code)
			default_code = 3;
		tanicode[row]->Text = default_code;
        taniname[row]->Text = DM->DBI.Lookup("M_単位","単位コード", default_code, "単位名称");
	}

	int meig_id  = ToInt(DM->DBI.Lookup("M_品目",   "品目コード", hincode[row]->Text.ToIntDef(0), "品目ID"));
	//int item1_id = ToInt(DM->DBI.Lookup("M_項目1",  "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
	//int item2_id = ToInt(DM->DBI.Lookup("M_項目2",  "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
	int tani_id  = ToInt(DM->DBI.Lookup("M_単位",   "単位コード", tanicode[row]->Text.ToIntDef(0), "単位ID"));

	if (tani_id == 3)
		net = StrToCurrDef(net, 0);
	else
		net = Currency(net) / Currency(1000);

	Currency quantity;
	Currency cnv_ratio = DM->GetKanzan(toku_id_, meig_id, tani_id);

	///// 換算端数処理区分の取得
	int cnv_div = -1;

	if (!toku_rec_.empty()){
		if (!IsNull(toku_rec_["換算端数処理区分"]))
			cnv_div = ToInt(toku_rec_["換算端数処理区分"]);
	}
	if (cnv_div == -1)
		cnv_div = ToInt(DM->CFG["換算端数処理区分"]);
	/////

	if (cnv_ratio == 0)
		quantity = ExtendedRound(net,             ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
	else
		quantity = ExtendedRound(net / cnv_ratio, ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);

	if (quantity > ToCurrency(DM->CFG["上限m3数量"]) && tanicode[row]->Text.ToIntDef(0) == 2)
		quantity = ToCurrency(DM->CFG["上限m3数量"]);

	suryo[row]->Text = quantity;

	CalcAmount();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AnbunAfterChousei(int row)
{
    if (row == 9)
        row = GetRowNo();
    if (row == 0)
        return;

    Currency net = ToCurrency(shomi[row]->Text);

    //デフォルトの単位を指定
    if (tanicode[row]->Text.IsEmpty()){
        int default_code = ToInt(DM->CFG["標準単位"]);
        if (!default_code) 
            default_code = 3;
            tanicode[row]->Text = default_code;
            taniname[row]->Text = DM->DBI.Lookup("M_単位", "単位コード",default_code, "単位名称");
    }

    //品目IDを取得
    int meig_id = ToInt(DM->DBI.Lookup("M_品目", "品目コード", hincode[row]->Text.ToIntDef(0),"品目ID"));
    int tani_id = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tanicode[row]->Text.ToIntDef(0),"単位ID"));

    if (tani_id == 3)
        net = StrToCurrDef(net, 0);
    else    
        net = Currency(net) / Currency(1000);

    Currency quantity;
    Currency cnv_ratio = DM->GetKanzan(toku_id_, meig_id, tani_id);

    // 換算端数処理区分の取得
    int cnv_div = -1;

    if (!toku_rec_.empty()) {
        if (!IsNull(toku_rec_["換算端数処理区分"]))
            cnv_div = ToInt(toku_rec_["換算端数処理区分"]);
    }

    if (cnv_div == -1)
        cnv_div = ToInt(DM->CFG["換算端数処理区分"]);
    if (cnv_ratio == 0)
        quantity = ExtendedRound(net,ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
    else
        quantity = ExtendedRound(net / cnv_ratio, ToInt(DM->CFG["換算端数処理桁数"]),cnv_div);

    if (quantity > ToCurrency(DM->CFG["上限m3数量"]) && tanicode[row]->Text.ToIntDef(0) == 2)
        quantity = ToCurrency(DM->CFG["上限m3数量"]);

    suryo[row]->Text = quantity;

}
//---------------------------------------------------------------------------
// 単価を調べて返す 20160627
void __fastcall TMainForm::CallTanka()
{

/*    int row = GetRowNo();

    if (row != 0){

        int meig_id     = ToInt(DM->DBI.Lookup("M_品目", "品目コード", hincode[row]->Text.ToIntDef(0), "品目ID"));
        int item1_id    = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
        int item2_id    = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
        int tani_id     = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tanicode[row]->Text.ToIntDef(0), "単位ID"));

        Currency quantity   = StrToCurrDef(suryo[row]->Text, 0);

        if (!ToBit(DM->CFG["単価使用区分"])){
            return;
        }

        Currency tankacode  =   StrToCurrDef(tanka[row]->Text, 0);
        Currency deftanka   =   DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);

        //標準単価と異なる数値なら赤にする
        //tanka[row]->Color   =   tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

        if (tankacode == deftanka){
            tanka[row]->Color = TColor(0x00BEF4F5);
        }else{
            tanka[row]->Color = TColor(0x008080FF);
        }

        tanka[row]->Text    =   deftanka;
    }


*/

}
//---------------------------------------------------------------------------
// 数量と金額の計算
void __fastcall TMainForm::CalcAmount(bool update)
{
    int row = GetRowNo();

    if (row != 0){

        int meig_id  = ToInt(DM->DBI.Lookup("M_品目", "品目コード", hincode[row]->Text.ToIntDef(0), "品目ID"));
        int item1_id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
        int item2_id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
        int tani_id  = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tanicode[row]->Text.ToIntDef(0), "単位ID"));

        Currency quantity = StrToCurrDef(suryo[row]->Text, 0);

        if (!ToBit(DM->CFG["単価使用区分"])){

            return;
        }

	    Currency tankacode = StrToCurrDef(tanka[row]->Text, 0);
	    Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
        if (GetMode() != imMod && update){
            tankacode = deftanka;
        }

        int chk_keiryoID = StringGridID->Cells[0][row].ToIntDef(0);

        //修正モードで新規明細追加するとき
        //if (GetMode() == imMod && chk_keiryoID == 0 && !chk_addflag_){
/*
        if (GetMode() == imMod && chk_keiryoID == 0     ){
            tankacode = deftanka;
        }
*/

        //修正モードで明細挿入追加するとき
        if (GetMode() == imMod && tanka[row]->Text == 0){
            tankacode = deftanka;
        }

        tanka[row]->Color = tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

        // 金額端数処理区分の取得
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
        ////
        int amount = ExtendedRound(quantity * tankacode, amount_fig, amount_div);

        tanka[row]->Text   = tankacode;
        kingaku[row]->Text = amount;

        CalcSalesTax();

    }
}
//---------------------------------------------------------------------------
// 消費税算出
void __fastcall TMainForm::CalcSalesTax()
{
    int row = GetRowNo();

    if (!ToBit(DM->CFG["単価使用区分"])){
        return;
    }

	Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));  //消費税

    int sum_money = 0;
    int sum_tax = 0;
    //// 消費税端数処理区分の取得
    int tax_fig = 0;
    int tax_div = -1;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["消費税端数処理区分"]))
            tax_div = ToInt(toku_rec_["消費税端数処理区分"]);
    }

    if (tax_div == -1)
        tax_div = ToInt(DM->CFG["消費税端数処理区分"]);
    if (tax_fig == 0)
        tax_fig = ToInt(DM->CFG["消費税端数処理桁数"]);
    ////

    int amount = 0 ;
    tax_total_ = 0;
    for (int i = 1; i < 7; i++){
        if (kingaku[i]->Text == ""){
            continue;
        }

        amount       = StrToIntDef(kingaku[i]->Text, 0);
        tax_total_   = int(ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div));

        if (shouhi[0]->Visible == true){
            shouhi[i]->Text = IntToStr(tax_total_);
        }
    }

    GetTotalMoney();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetTotalMoney()
{
    if (!ToBit(DM->CFG["単価使用区分"]))
        return;

    int sum_money, sum_tax;
    sum_money = 0;
    sum_tax   = 0;
    slip_tax_ = 0;

    for (int i = 1; i <= limit_line_; i++){
        if (kingaku[i]->Text == "")
            continue;
        sum_money += kingaku[i]->Text.ToIntDef(0);
    }

    //伝票ごとの処理
    if (ToString(DM->CFG["多段時消費税計算区分"]).ToIntDef(1) == 1){
		Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));
        ////消費税処理区分の取得
        int tax_div = -1;
        if (!toku_rec_.empty())
            if(IsNull(toku_rec_["消費税端数処理区分"]))
                tax_div = ToInt(toku_rec_["消費税端数処理区分"]);
        if (tax_div == -1)
            tax_div = ToInt(DM->CFG["消費税端数処理区分"]);

        // 伝票消費税の計算
        sum_tax = ExtendedRound(Currency(sum_money) * tax_rate, 0, tax_div);
    }else{
        for (int i = 1; i <= limit_line_; i++){
            if(shouhi[i]->Text == "")
                continue;
            sum_tax += shouhi[i]->Text.ToIntDef(0);
        }
    }

    slip_tax_ = sum_tax;

    KingakuSumEdit->Text = FormatFloat("\\ #,##0", sum_money);
    ShohizeiEdit->Text   = FormatFloat("\\ #,##0", sum_tax);
    ZeikomiEdit->Text    = FormatFloat("\\ #,##0", sum_money + sum_tax);

    Currency chk_zei = StrToCurrDef(ShohizeiEdit->Text, 0);
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
}
//---------------------------------------------------------------------------
// F2 修正
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	ClearForm();

	// 同一拠点の最終レコードを取得
	keiryo_id_ = DM->GetLastKeiryoID(GetPlaceID());

	if (keiryo_id_ < 1){
		Application->MessageBox("修正するデータはありません",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	int kanryo = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id_, "完了区分"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

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

	if (Application->MessageBox("この伝票を削除しますか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
		return;

	try{
		DM->ADOConnection->BeginTrans();

		NsFieldSet fields, keys;
		fields << NsField("[伝票No]",   DM->GetTempNo(GetPlaceID()))
			   << NsField("[完了区分]", 9);

		NsRecordSet set;
		if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id_), set)){
			Application->MessageBox("削除データの抽出に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);
			return;
		}
		keys	<< NsField("[計量日]", ToInt(set[0]["計量日"]))
				<< NsField("[伝票No]", ToInt(set[0]["伝票No"]))
				<< NsField("[拠点ID]", ToInt(SET_TOP(set)["拠点ID"]));

		DM->DBI.Update("D_計量", keys, fields);

		///// 取引データも同処理
		fields.clear();
		keys.clear();

		fields	<< NsField("[伝票No]",   DM->GetTransTempNo(GetPlaceID()))
				<< NsField("[完了区分]", 9);

		set.clear();
		if (DM->DBI.GetRecordSet("SELECT * FROM D_取引 WHERE 計量ID = " + IntToStr(keiryo_id_), set)){
			keys	<< NsField("[取引日]", ToInt(set[0]["取引日"]))
					<< NsField("[伝票No]", ToInt(set[0]["伝票No"]))
					<< NsField("[拠点ID]", ToInt(SET_TOP(set)["拠点ID"]));
	//		keys	<< NsField("[計量ID]",   keiryo_id_);
			DM->DBI.Update("D_取引", keys, fields);
		}

		DM->ADOConnection->CommitTrans();

    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString msg = "削除時にエラーが発生しました - " + e.Message;
        Application->MessageBox(msg.c_str(), "計量データ削除", MB_OK | MB_ICONWARNING);
        return;
    }

    if (mode == imSecond)
        Action1->Execute();
    else
        Action2->Execute();
}
//---------------------------------------------------------------------------
// F4 参照
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == ShabanEdit){
		SharyoButton->Click();
	}else if (ActiveControl == TokuCodeEdit){
        TokuButton->Click();
	}else if (ActiveControl == Komoku1CodeEdit){
		Komoku1Button->Click();
	}else if (ActiveControl == Komoku2CodeEdit){
		Komoku2Button->Click();
	}else if (ActiveControl == hincode[GetRowNo()]){
        GetHinmoku();
		//HinNameTitleEdit->OnClick(NULL);
	//}else if (ActiveControl == TaniCodeEdit){
        //TaniButton->Click();
    }
}
//---------------------------------------------------------------------------
// F5 登録
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
    PostWeighing();
}
//---------------------------------------------------------------------------
// F6 前へ
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
    int id;

    if (keiryo_id_){    // 修正、または滞留状態
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

	keiryo_id_ = id;

	int kanryo = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id_, "完了区分"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

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

	keiryo_id_ = id;

	int kanryo = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id_, "完了区分"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

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

	keiryo_id_ = DataListForm->selected_id;

	int kanryo = DataListForm->Q_Keiryo->FieldByName("完了区分")->AsInteger;
	//int kanryo = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id_, "完了区分"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

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
    if (ActiveControl == ShabanEdit || ActiveControl == TokuCodeEdit || ActiveControl == Komoku1CodeEdit || ActiveControl == Komoku2CodeEdit || ActiveControl == BikoEdit)
        return;

    int row = GetRowNo();
	InputMode mode = GetMode();
    if (mode == imFirst){
		weight1[1]->Text = cur_weight_;
		weight1[1]->SetFocus();
	}else if (ActiveControl == weight2[cur_w2_row_] && weight1[cur_w2_row_]->Text == weight2[cur_w2_row_]->Text){
        weight2[cur_w2_row_]->Text = cur_weight_;
        weight2[cur_w2_row_]->SetFocus();

    }else{
        // 20160610
        //
        if (keiryo_kaisu_ > 1 && shomi[1]->Text == ""){
            //weight2[1]->Text = cur_weight_;
            keiryo_kaisu_ = 1;
        }else{
		    weight2[keiryo_kaisu_]->Text = cur_weight_;
		    if (keiryo_kaisu_ > 1)
			    weight1[keiryo_kaisu_]->Text = weight2[keiryo_kaisu_ - 1]->Text;
        }
	}

	CalcWeight(keiryo_kaisu_);
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
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 得意先コード, 得意先略称 FROM M_得意先 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 得意先コード ";
    SearchForm->table_name = "M_得意先";
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
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 項目1コード, 項目1略称 FROM M_項目1 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目1コード ";
    SearchForm->table_name = "M_項目1";
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
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 項目2コード, 項目2略称 FROM M_項目2 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目2コード ";
    SearchForm->table_name = "M_項目2";
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
    int interval = 10;
    F1Button->Width = int((MainForm->Width - interval * 4) / 12);
    F2Button->Width = int((MainForm->Width - interval * 4) / 12);
    F3Button->Width = int((MainForm->Width - interval * 4) / 12);
    F4Button->Width = int((MainForm->Width - interval * 4) / 12);
    F5Button->Width = int((MainForm->Width - interval * 4) / 12);
    F6Button->Width = int((MainForm->Width - interval * 4) / 12);
    F7Button->Width = int((MainForm->Width - interval * 4) / 12);
    F8Button->Width = int((MainForm->Width - interval * 4) / 12);
    F9Button->Width = int((MainForm->Width - interval * 4) / 12);
    F10Button->Width = int((MainForm->Width - interval * 4) / 12);
    F11Button->Width = int((MainForm->Width - interval * 4) / 12);
    F12Button->Width = int((MainForm->Width - interval * 4) / 12);
    ////////////////////////////////
    //
/*
    WeightSumTitleLabel->Width  = int((MainForm->Width - interval * 4) / 12);
    ShomiSumEdit->Width         = int((MainForm->Width - interval * 4) / 12);
    KingakuSumTitleLabel->Width = int((MainForm->Width - interval * 4) / 12);
    KingakuSumEdit->Width       = int((MainForm->Width - interval * 4) / 12);
    ShohizeiTitleLabel->Width   = int((MainForm->Width - interval * 4) / 12);
    ShohizeiEdit->Width         = int((MainForm->Width - interval * 4) / 12);
*/
    WeightSumTitleLabel->Left   = 500;
    ShomiSumEdit->Left          = WeightSumTitleLabel->Left + WeightSumTitleLabel->Width - 1 + interval;
    KingakuSumTitleLabel->Left  = ShomiSumEdit->Left + ShomiSumEdit->Width - 1 + interval;
    KingakuSumEdit->Left        = KingakuSumTitleLabel->Left + KingakuSumTitleLabel->Width - 1 + interval;
    ShohizeiTitleLabel->Left    = KingakuSumEdit->Left + KingakuSumEdit->Width - 1 + interval;
    ShohizeiEdit->Left          = ShohizeiTitleLabel->Left + ShohizeiTitleLabel->Width - 1 + interval;
    ////////////////////////////////
    F1Button->Left = interval;
    F2Button->Left = F1Button->Left + F1Button->Width - 1;
    F3Button->Left = F2Button->Left + F2Button->Width - 1;
    F4Button->Left = F3Button->Left + F3Button->Width - 1;
    F5Button->Left = F4Button->Left + F4Button->Width - 1 + interval;
    F6Button->Left = F5Button->Left + F5Button->Width - 1;
    F7Button->Left = F6Button->Left + F6Button->Width - 1;
    F8Button->Left = F7Button->Left + F7Button->Width - 1;
    F9Button->Left = F8Button->Left + F8Button->Width - 1 + interval;
    F10Button->Left = F9Button->Left + F9Button->Width - 1;
    F11Button->Left = F10Button->Left + F10Button->Width - 1;
    F12Button->Left = F11Button->Left + F11Button->Width - 1;

    F1Panel->Left = F1Button->Left + 3;
    F2Panel->Left = F2Button->Left + 3;
    F3Panel->Left = F3Button->Left + 3;
    F4Panel->Left = F4Button->Left + 3;
    F5Panel->Left = F5Button->Left + 3;
    F6Panel->Left = F6Button->Left + 3;
    F7Panel->Left = F7Button->Left + 3;
    F8Panel->Left = F8Button->Left + 3;
    F9Panel->Left = F9Button->Left + 3;
    F10Panel->Left = F10Button->Left + 3;
    F11Panel->Left = F11Button->Left + 3;
    F12Panel->Left = F12Button->Left + 3;

    F1Panel->Width = F1Button->Width - 5;
    F2Panel->Width = F2Button->Width - 5;
    F3Panel->Width = F3Button->Width - 5;
    F4Panel->Width = F4Button->Width - 5;
    F5Panel->Width = F5Button->Width - 5;
    F6Panel->Width = F6Button->Width - 5;
    F7Panel->Width = F7Button->Width - 5;
    F8Panel->Width = F8Button->Width - 5;
    F9Panel->Width = F9Button->Width - 5;
    F10Panel->Width = F10Button->Width - 5;
    F11Panel->Width = F11Button->Width - 5;
    F12Panel->Width = F12Button->Width - 5;

    TairyuGrid->RowCount = int(TairyuGrid->Height / 61);

    // 他のフォームのサイズもメインフォームに合わせる
    SearchForm->Height = MainForm->Height;
    DataListForm->Height = MainForm->Height - 33;
    DataListForm->Width  = MainForm->Width  - 24;
    DataListForm->Top  = MainForm->Top  + 16;
	DataListForm->Left = MainForm->Left + 12;

	MeisaiScrollBox2->Left = 426;
}
//---------------------------------------------------------------------------
// 車番->OnChange
void __fastcall TMainForm::ShabanEditChange(TObject *Sender)
{
    int no = ShabanEdit->Text.ToIntDef(0);
    if (no == 0){
        SharyoNameEdit->Text = AnsiString();
        return;
    }

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_車両 WHERE 車番 = " + IntToStr(no);
    if (!DM->DBI.GetRecordSet(sql, set)){
        SharyoNameEdit->Text = AnsiString();
        return;
    }

    if (set.size() == 1){
		SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
    }else{
        SharyoNameEdit->Text = "複数の車両が存在";
    }
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
    AnsiString sql = "SELECT * FROM M_得意先 WHERE 使用区分 = 1 AND 得意先コード = " + IntToStr(code);
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

    }

    ((TEdit *)Sender)->Color = clCream;

    OnItemsChanged(Sender);
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
        Komoku1NameEdit->Text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", code, "項目1名称", "使用区分 = 1"));
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
	}

    ((TEdit *)Sender)->Color = clCream;

    OnItemsChanged(Sender);
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
        Komoku2NameEdit->Text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", code, "項目2名称", "使用区分 = 1"));
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

    }

    ((TEdit *)Sender)->Color = clCream;

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// 搬入出コンボ->OnKeyDown
void __fastcall TMainForm::HannyuCombo_KeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key == VK_ESCAPE)
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
		StatusBar->Panels->Items[1]->Text = "重量値受信: 受信エラー";
		break;
	case eeConnect:
		StatusBar->Panels->Items[1]->Text = "重量値受信: 接続エラー";
		break;
	case eeDisconnect:
		StatusBar->Panels->Items[1]->Text = "重量値受信: 切断エラー";
		break;
	default:
        StatusBar->Panels->Items[1]->Text = "重量値受信: ソケットエラー";
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
    case 'S':   WeightPanel->Font->Color = TColor(0x00CDF7A4);	break;
	case 'U':   WeightPanel->Font->Color = TColor(0x008080FF);	break;
	case 'O':	WeightPanel->Font->Color = clYellow;
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
/*
	int border = ToInt(DM->INI["Weighing::SoundBorder"]);

	if (old_weight_ < border && cur_weight_ >= border){
		// [INI] Weighing::SoundFile
		PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
	}
*/
    if (old_weight_ < weighing_border_ && cur_weight_ >= weighing_border_){
        PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
    }else if ((old_weight_ >= weighing_border_) && (cur_weight_ < weighing_border_)){
        last_card_no_ = 0;
    }

	WeightPanel->Caption = FormatFloat("###,##0", cur_weight_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDAborted(TMessage& message)
{
    delete rfid_thread_;
    rfid_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDStatus(TMessage& message)
{
    bool is_fatal = message.WParam;
    AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    StatusBar->Panels->Items[1]->Text = "RFID: " + status;

    if (is_fatal)
        Application->MessageBox(("卓上RFIDリーダ:" + status).c_str(), "卓上RFID障害",  MB_OK | MB_ICONSTOP);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;
    int card_no = message.LParam;

	if (last_card_no_ == card_no){
	    StatusBar->Panels->Items[1]->Text = "RFID: 重複読み取り";
        ::MessageBeep(MB_ICONEXCLAMATION);
		return;
	}
	if (!is_valid || card_no < 1){
	    StatusBar->Panels->Items[1]->Text = "RFID: 無効なカード";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return;
	}

    // 重量ボーダーより重量が低いと
    if (cur_weight_ < weighing_border_){
	    StatusBar->Panels->Items[1]->Text = "RFID: 車両なし";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return;
    }

    last_card_no_ = card_no;

    if (!RFIDSharyoCheck(card_no))
    	return;

    if (ToInt(DM->CFG["卓上RFID計量時自動登録"]) == 1)
    	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDTimeout(TMessage& message)
{
	bool timeouted = message.WParam;
    if (timeouted)
		Application->MessageBox("卓上RFIDリーダが正しく接続されていない可能性があります（リーダからの返答なし）", "卓上RFID障害", MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	int row = GetRowNo();

	switch (Key){
	case VK_DOWN:
		if (ActiveControl == hincode[row] || ActiveControl == hinname[row] || ActiveControl == biko[row])
			return;
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_RETURN:
		if (ActiveControl == hincode[row] || ActiveControl == hinname[row] || ActiveControl == biko[row])
			return;
        if (ActiveControl == BikoEdit)
            return;

        if (GetMode() == imFirst && ActiveControl == WeightEdit11 && WeightEdit12->Text.IsEmpty())
            return;

        if (ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_UP:
		if (ActiveControl == hincode[row] || ActiveControl == weight1[row])
			return;
		if (ActiveControl->Tag != 1){
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_TAB, 0, 0, 0);
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
		break;
	case VK_PRIOR:
		ActionRirekiBefore->Execute();
		break;
	case VK_NEXT:
		ActionRirekiNext->Execute();
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Q_TairyuAfterOpen(TDataSet *DataSet)
{
	TairyuGrid->Visible = Q_Tairyu->RecordCount != 0;
	TairyuKensuLabel->Caption = "(" + IntToStr(Q_Tairyu->RecordCount) + ")";
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
    CalcAmount();
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
          "     拠点ID = " + IntToStr(GetPlaceID()) +
          " ORDER BY 計量日時1";
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
void __fastcall TMainForm::TairyuTimerTimer(TObject *Sender)
{
    TairyuTimer->Enabled = false;

    NsRecordSet set;
    AnsiString sql;
    int total = 0;

    sql = " SELECT SUM(計量ID) AS 滞留ID合計"
          " FROM D_計量"
          " WHERE 完了区分 = 0"
          "   AND 行No = 1";
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
void __fastcall TMainForm::KeiryoDatePickerChange(TObject *Sender)
{
    if (GetMode() != imMod)
       KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShabanEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    if (!SharyoCheck())
        return;

    //Exitを通らないため、ここに車番Exit処理を書く
    ((TEdit *)Sender)->Color = clCream;

    if (ActiveControl != ShabanEdit)
        return;

    if (GetMode() == imMod){
        TokuCodeEdit->SetFocus();
    }else{

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;


        if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
            TokuCodeEdit->SetFocus();
		//else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
            //HinCodeEdit->SetFocus();
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();
        else
            BikoEdit->SetFocus();
		//else if (FirstWEdit->Text.IsEmpty())
			//FirstWEdit->SetFocus();
		//else
            //SecondWEdit->SetFocus();

        ShabanEdit->OnExit = OnExit;
    }
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

	new_car_ = false;		// 一旦クリア

	if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
		// 新規車両登録

		TDateTime now(Now());
		NsFieldSet fields;

		AnsiString name = IntToStr(car_no) + " (" + now.FormatString("mm/dd'登録'") + ")";
		new_car_fields_.clear();
		new_car_fields_
			   << NsField("[車番]",     car_no)
			   ;

		SharyoNameEdit->Text = name;

		keiryo_count_ = 2;

		if (GetMode() == imFirst && !ShudoCheckBox->Checked)
			weight1[1]->Text = cur_weight_;

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
		return false;
	}

	car_id_      = ShabanSanshoForm->GetCarID();
	int mastered = ShabanSanshoForm->GetDataDiv();

	if (!car_id_){
		// 新規車両（上と同じ処理）

		NsFieldSet fields;
		TDateTime now(Now());

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

		if (GetMode() == imFirst)
			weight1[1]->Text = cur_weight_;

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
			return false;
		}

		if (GetMode() != imMod){
			if (TokuCodeEdit->Text.IsEmpty())
				TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["得意先コード"]));
			if (Komoku1CodeEdit->Text.IsEmpty())
				Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目1コード"]));
			if (Komoku2CodeEdit->Text.IsEmpty())
				Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["項目2コード"]));

 			if (ToCurrency(SET_TOP(set)["空車重量"]) > 0){
				keiryo_count_ = 1;
				weight2[1]->Text = ToCurrency(SET_TOP(set)["空車重量"]);
			}else{
				keiryo_count_ = 2;
			}


			gross_limit_ = ToCurrency(SET_TOP(set)["車両総重量"]);
			net_limit_   = ToCurrency(SET_TOP(set)["最大積載量"]);

			SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);

            if (!ShudoCheckBox->Checked){
			    weight1[1]->Text = cur_weight_;
            }

		}else{
			SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
		}
	}else{
		// 滞留車からの選択
		int keiryo_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);
		if (!keiryo_id){
			Application->MessageBox("選択された滞留情報が存在しません。\r\n別PCなどで計量されていないか確認してください。",
				Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}

		//TNotifyEvent OnExit = ShabanEdit->OnExit;
		//ShabanEdit->OnExit  = 0;
		ContinueWeighing(keiryo_id);
		//ShabanEdit->OnExit  = OnExit;
	}

	if (keiryo_count_ == 1)
		CalcWeight();

	// 履歴を表示する
	SetRireki(car_id_);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::RFIDSharyoCheck(int card_no)
{
    new_car_ = false;

    NsRecordSet car_set;
    if (!DM->DBI.GetRecordSet("SELECT * FROM V_車両 WHERE カード番号 = " + IntToStr(card_no), car_set)){
        StatusBar->Panels->Items[1]->Text = "RFID: 車両情報なし";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return false;
    }

    if (ToInt(SET_TOP(car_set)["使用区分"]) != 1)
        StatusBar->Panels->Items[1]->Text = "RFID: 使用しない車両情報";

    Action1->Execute();

    int row = GetRowNo();

    car_id_ =   ToInt(SET_TOP(car_set)["車両ID"]);
    int remained_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);

    if (!remained_id){
        ShabanEdit->Text    =   ZeroSuppress(ToInt(SET_TOP(car_set)["車番"]));
        TokuCodeEdit->Text  =   ZeroSuppress(ToInt(SET_TOP(car_set)["得意先コード"]));
        hincode[row]->Text  =   ZeroSuppress(ToInt(SET_TOP(car_set)["品目コード"]));
        Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(car_set)["項目1コード"]));
        Komoku2CodeEdit->Text = ZeroSuppress(ZeroSuppress(SET_TOP(car_set)["項目2コード"]));

        if (ToCurrency(SET_TOP(car_set)["空車重量"]) > 0){
            keiryo_count_ = 1;
            weight1[1]->Text = ToCurrency(SET_TOP(car_set)["空車重量"]);
        }else{
            keiryo_count_ = 2;
        }

        gross_limit_    =   ToCurrency(SET_TOP(car_set)["車両総重量"]);
        net_limit_      =   ToCurrency(SET_TOP(car_set)["最大積載量"]);

        SharyoNameEdit->Text    =   ToString(SET_TOP(car_set)["車両名称"]);

        if (keiryo_count_ == 2){
            weight1[row]->Text = cur_weight_;
        }else{
            weight2[row]->Text = cur_weight_;
        }

        CalcWeight();

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;

        if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
            TokuCodeEdit->SetFocus();
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();

        ShabanEdit->OnExit = OnExit;

    }else{
        ContinueWeighing(remained_id);
    }

    // 履歴を表示する
    SetRireki(car_id_);

    return true;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
    //Exitを通らないため、ここに車番Exit処理を書く
    ((TEdit *)Sender)->Color = clCream;

    // 20160623現在　この関数は通らない
    //	SharyoCheck();
    //  Exitで背景を標準に戻す
    //((TEdit *)Sender)->Color = clCream;
}
//---------------------------------------------------------------------------
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
			//if (HinCodeEdit->Text.IsEmpty())
                //HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["品目コード"]));

			if (ToCurrency(SET_TOP(set)["空車重量"]) > 0){
				keiryo_count_ = 1;
				weight2[1]->Text = ToCurrency(SET_TOP(set)["空車重量"]);
			}else{
				keiryo_count_ = 2;
			}
            gross_limit_ = ToCurrency(SET_TOP(set)["車両総重量"]);
            net_limit_   = ToCurrency(SET_TOP(set)["最大積載量"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);

			weight1[1]->Text = cur_weight_;
			//if (keiryo_count_ == 2)
				//FirstWEdit->Text = cur_weight_;
			//else
				//SecondWEdit->Text = cur_weight_;
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
            return;
        }

        ShabanEdit->Text         = car_no;
        SharyoNameEdit->ReadOnly = true;

        //TNotifyEvent OnExit = ShabanEdit->OnExit;
        //ShabanEdit->OnExit  = 0;
        ContinueWeighing(keiryo_id);
        //ShabanEdit->OnExit  = OnExit;
    }

    if (keiryo_count_ == 1)
        CalcWeight();

	// 履歴
	SetRireki(car_id_);

    TokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// 履歴クエリセット
void __fastcall TMainForm::SetRireki(int sharyo_id)
{
	rireki_set_.clear();
	ClearRireki();

	if (!DispRirekiCheckBox->Checked)
		return;
	Q_Rireki->SQL->Strings[12] = "	車両ID = " + IntToStr(sharyo_id);
	DM->DBI.GetRecordSet(Q_Rireki->SQL->Text, rireki_set_);
	rireki_id_ = 0;
	RirekiDisp();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RirekiDisp()
{
	RirekiDateLabel->Caption = "最終計量日： " + FormatFloat("0000/00/00;#;#", ToInt(rireki_set_[rireki_id_]["計量日"]));
	RirekiTokuCodeLabel->Caption    = ToString(rireki_set_[rireki_id_]["得意先コード"]);
	RirekiTokuNameLabel->Caption    = ToString(rireki_set_[rireki_id_]["得意先名称"]);
	//RirekiHinCodeLabel->Caption     = ToString(rireki_set_[rireki_id_]["品目コード"]);
	//RirekiHinNameLabel->Caption     = ToString(rireki_set_[rireki_id_]["品目名称"]);
	RirekiKomoku1CodeLabel->Caption = ToString(rireki_set_[rireki_id_]["項目1コード"]);
	RirekiKomoku1NameLabel->Caption = ToString(rireki_set_[rireki_id_]["項目1名称"]);
	RirekiKomoku2CodeLabel->Caption = ToString(rireki_set_[rireki_id_]["項目2コード"]);
	RirekiKomoku2NameLabel->Caption = ToString(rireki_set_[rireki_id_]["項目2名称"]);

	if (ToString(rireki_set_[0]["計量日"]) != AnsiString())
		RirekiOrderLabel->Caption = IntToStr(rireki_id_ + 1) + "/" + IntToStr(rireki_set_.size());
	else
		RirekiOrderLabel->Caption = AnsiString();
}
//---------------------------------------------------------------------------
// 前履歴 [PageUp]
void __fastcall TMainForm::ActionRirekiBeforeExecute(TObject *Sender)
{
	if (rireki_id_ <= 0)
		return;
	rireki_id_--;
	RirekiDisp();
}
//---------------------------------------------------------------------------
// 後履歴 [PageDown]
void __fastcall TMainForm::ActionRirekiNextExecute(TObject *Sender)
{
	if (rireki_id_ >= rireki_set_.size() - 1)
		return;
	rireki_id_++;
	RirekiDisp();
}
//---------------------------------------------------------------------------
// F11 履歴呼出
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (ToString(rireki_set_[0]["計量日"]) == AnsiString())
		return;
	TokuCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["得意先コード"]));
	TokuNameEdit->Text = ToString(rireki_set_[rireki_id_]["得意先名称"]);
	//HinCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["品目コード"]));
	//HinNameEdit->Text = ToString(rireki_set_[rireki_id_]["品目名称"]);
	Komoku1CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["項目1コード"]));
	Komoku1NameEdit->Text = ToString(rireki_set_[rireki_id_]["項目1名称"]);
	Komoku2CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["項目2コード"]));
	Komoku2NameEdit->Text = ToString(rireki_set_[rireki_id_]["項目2名称"]);
}
//---------------------------------------------------------------------------
// 履歴表示
void __fastcall TMainForm::DispRirekiCheckBoxClick(TObject *Sender)
{
	if (DispRirekiCheckBox->Checked)
		RirekiPanel->Height = 104;
	else
		RirekiPanel->Height = 16;
}
//---------------------------------------------------------------------------
// 履歴クリア
void __fastcall TMainForm::ClearRireki()
{
	RirekiDateLabel->Caption        = AnsiString();
	RirekiTokuCodeLabel->Caption    = AnsiString();
	RirekiTokuNameLabel->Caption    = AnsiString();
	//RirekiHinCodeLabel->Caption     = AnsiString();
	//RirekiHinNameLabel->Caption     = AnsiString();
	RirekiKomoku1CodeLabel->Caption = AnsiString();
	RirekiKomoku1NameLabel->Caption = AnsiString();
	RirekiKomoku2CodeLabel->Caption = AnsiString();
	RirekiKomoku2NameLabel->Caption = AnsiString();
	RirekiOrderLabel->Caption       = AnsiString();
}
//---------------------------------------------------------------------------
// Edit->OnEnter (ユーザサポート情報を表示)
void __fastcall TMainForm::ShabanEditEnter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption; //TColor(0x00FFF1F0);

	if (((TCobEdit *)Sender)->Hint == AnsiString())
		return;
	StatusBar->Panels->Items[2]->Text = ((TCobEdit *)Sender)->Hint;
}
//---------------------------------------------------------------------------
// 明細追加
// 明細削除
// 重量再計算
// 品目コード->OnExit
void __fastcall TMainForm::HinCodeEdit1Exit(TObject *Sender)
{
	int row = GetRowNo();

    ((TEdit *)Sender)->Color = clWindow;

    //新規かつ 手動チェックボックスが非なら
    if (GetMode() == imFirst && !ShudoCheckBox->Checked)
        return;

	// 重量調整率
	NsRecordSet set;
	AnsiString sql;

	sql = "SELECT * FROM M_品目 WHERE 品目コード = " + IntToStr(hincode[row]->Text.ToIntDef(0));
	if (DM->DBI.GetRecordSet(sql, set)){
		Currency coord_ratio = ToCurrency(SET_TOP(set)["重量調整率"]);

		if (StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0) != coord_ratio){
			if (GetMode() == imMod)
				if (Application->MessageBox(("重量調整率が異なります。上書きしますか？\r\n登録調整率：" + FormatFloat("#,##0.0#", coord_ratio) + "%").c_str(), "品目変更", MB_YESNO | MB_ICONEXCLAMATION) != IDYES)
					return;
			choritu[row]->Text = ZeroSuppress(coord_ratio);
			CalcWeight();
		}
	}

}
//---------------------------------------------------------------------------
// 重量->OnExit
void __fastcall TMainForm::WeightEdit11Exit(TObject *Sender)
{
	int row = GetRowNo();

    //Editの背景色を元に戻す
    ((TEdit *)Sender)->Color = clWindow;

    // 2回目重量が空白ならば計算しない
    if (weight2[row]->Text == ""){
        return;
    }

	if ((TCobEdit *)Sender == choritu[row])
		choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));

	CalcWeight();
    //総金額
    CalcKingakuTotal();
    //総正味重量
    CalcShomiTotal();
    //消費税
    CalcSalesTax();
}
//---------------------------------------------------------------------------
// 単位検索
void __fastcall TMainForm::TaniTitleEditClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 単位コード, 単位名称 FROM M_単位 ";
	SearchForm->orderby_sql = " ORDER BY 単位コード ";
	SearchForm->table_name = "M_単位";
	if (SearchForm->ShowModal() != mrOk)
		return;
	int row = GetRowNo();
	if (row == 0)
		return;
	tanicode[row]->Text = SearchForm->Query->FieldByName("単位コード")->AsInteger;
	tanicode[row]->OnChange(NULL);
	tanicode[row]->SetFocus();
}
//---------------------------------------------------------------------------
// 品目検索
void __fastcall TMainForm::HinNameTitleEditClick(TObject *Sender)
{
/*
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 品目コード, 品目略称, 搬入出区分名称 AS 搬入出, 取引区分名称 AS 取引区分 FROM V_品目 WHERE 使用区分 = 1";
	SearchForm->orderby_sql = " ORDER BY 品目コード ";
	SearchForm->table_name = "V_品目";
	if (SearchForm->ShowModal() != mrOk)
		return;
	int row = GetRowNo();
	if (row == 0)
		return;
	hincode[row]->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
	hincode[row]->OnChange(NULL);
	hincode[row]->SetFocus();
*/

}
//---------------------------------------------------------------------------
int __fastcall TMainForm::GetRowNo()
{
	if (ActiveControl == hincode[1] || ActiveControl == hinname[1] || ActiveControl == weight1[1] || ActiveControl == weight2[1] || ActiveControl == choritu[1] || ActiveControl == choweight[1] || ActiveControl == bikiweight[1] || ActiveControl == shomi[1] || ActiveControl == suryo[1] || ActiveControl == tanicode[1] || ActiveControl == taniname[1] || ActiveControl == tanka[1] | ActiveControl == kingaku[1] || ActiveControl == shouhi[1] || ActiveControl == biko[1])
		return 1;
	else if (ActiveControl == hincode[2] || ActiveControl == hinname[2] || ActiveControl == weight1[2] || ActiveControl == weight2[2] || ActiveControl == choritu[2] || ActiveControl == choweight[2] || ActiveControl == bikiweight[2] || ActiveControl == shomi[2] || ActiveControl == suryo[2] || ActiveControl == tanicode[2] || ActiveControl == taniname[2] || ActiveControl == tanka[2] | ActiveControl == kingaku[2] || ActiveControl == shouhi[2] || ActiveControl == biko[2])
		return 2;
	else if (ActiveControl == hincode[3] || ActiveControl == hinname[3] || ActiveControl == weight1[3] || ActiveControl == weight2[3] || ActiveControl == choritu[3] || ActiveControl == choweight[3] || ActiveControl == bikiweight[3] || ActiveControl == shomi[3] || ActiveControl == suryo[3] || ActiveControl == tanicode[3] || ActiveControl == taniname[3] || ActiveControl == tanka[3] | ActiveControl == kingaku[3] || ActiveControl == shouhi[3] || ActiveControl == biko[3])
		return 3;
	else if (ActiveControl == hincode[4] || ActiveControl == hinname[4] || ActiveControl == weight1[4] || ActiveControl == weight2[4] || ActiveControl == choritu[4] || ActiveControl == choweight[4] || ActiveControl == bikiweight[4] || ActiveControl == shomi[4] || ActiveControl == suryo[4] || ActiveControl == tanicode[4] || ActiveControl == taniname[4] || ActiveControl == tanka[4] | ActiveControl == kingaku[4] || ActiveControl == shouhi[4] || ActiveControl == biko[4])
		return 4;
	else if (ActiveControl == hincode[5] || ActiveControl == hinname[5] || ActiveControl == weight1[5] || ActiveControl == weight2[5] || ActiveControl == choritu[5] || ActiveControl == choweight[5] || ActiveControl == bikiweight[5] || ActiveControl == shomi[5] || ActiveControl == suryo[5] || ActiveControl == tanicode[5] || ActiveControl == taniname[5] || ActiveControl == tanka[5] | ActiveControl == kingaku[5] || ActiveControl == shouhi[5] || ActiveControl == biko[5])
		return 5;
	else if (ActiveControl == hincode[6] || ActiveControl == hinname[6] || ActiveControl == weight1[6] || ActiveControl == weight2[6] || ActiveControl == choritu[6] || ActiveControl == choweight[6] || ActiveControl == bikiweight[6] || ActiveControl == shomi[6] || ActiveControl == suryo[6] || ActiveControl == tanicode[6] || ActiveControl == taniname[6] || ActiveControl == tanka[6] | ActiveControl == kingaku[6] || ActiveControl == shouhi[6] || ActiveControl == biko[6])
		return 6;
	else
		return 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinCodeEdit1Change(TObject *Sender)
{
	int row = GetRowNo();
	if (row == 0)
		return;
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT * FROM V_品目 WHERE 使用区分 = 1 AND 品目コード = " + IntToStr(hincode[row]->Text.ToIntDef(0)), set);
	hinname[row]->Text      = ToString(set[0]["品目名称"]);

    if (hincode[row]->Text == "0"){
        hinname[row]->Text = "未入力で登録されます";
    }

    if(row == 1){
        HannyuCombo->ItemIndex  = ToInt(set[0]["搬入出区分"]) - 1;
    }
    CallTanka();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinCodeEdit1KeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{

	int row = GetRowNo();
	if (row == 0)
		return;
/*
    if (hincode[row]->Text == ""){
        return;
    }
*/
	// 自動計量＆初回計量＆1回目重量->ENTERで登録
	if (!ShudoCheckBox->Checked && Key == VK_RETURN && GetMode() == imFirst && ActiveControl == weight1[1] && weight2[1]->Text.IsEmpty()){
		PostConfForm->ButtonKeizoku->Enabled = true;
		Action5->Execute();
	}else{
        //weight2[row]->SetFocus();
    }

	if (Key == VK_RETURN || Key == VK_TAB){
		if (ActiveControl == hincode[row] && hinname[row]->TabStop){
			Key = 0;
			hinname[row]->SetFocus();
		}
        if (ActiveControl == weight1[row] && weight1[row]->Text != "" && ShudoCheckBox->Checked){
            if (row == 1){
                weight2[row]->SetFocus();
            }
            return;
        }
		if (ActiveControl == hincode[row] && !hinname[row]->TabStop || ActiveControl == hinname[row]){
			Key = 0;
			weight1[row]->SetFocus();
		}
        if (ActiveControl == weight1[row]){
            CalcAmount();

        }
        //
		if (ActiveControl == biko[row]){
			Key = 0;
            // 手動入力がcheckedなら
            if (ShudoCheckBox->Checked && row != limit_line_){
                hincode[row + 1]->SetFocus();
                return;
            }
            // 品目名称が非空白,重量1 > 0 , 重量2 > 0 のとき
            if (hinname[row] != NULL && weight1[row] > 0 && weight2[row] > 0){
                Action5->Execute();
                // 確認画面キャンセルで戻ったときは
                //hincode[row + 1]->SetFocus(); a
                if (hincode[row]->Text != ""){
                    hincode[row + 1]->SetFocus();
                }
                return;
            }
			if (row < limit_line_)
				hincode[row + 1]->SetFocus();
		}
	}
	if (Key == VK_UP){
		if (ActiveControl == hincode[row]){
			Key = 0;
			if (row > 1)
				biko[row - 1]->SetFocus();
		}
		if (ActiveControl == weight1[row]){
			Key = 0;
			if (hinname[row]->TabStop)
				hinname[row]->SetFocus();
			else
				hincode[row]->SetFocus();
		}
	}


	if (ActiveControl == biko[limit_line_] && Key == VK_RETURN){
		Key = 0;
		Action5->Execute();
        ShabanEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChoseiPerEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
	((TCobEdit *)Sender)->Text = AnsiReplaceStr(((TCobEdit *)Sender)->Text, "%", "");
	((TCobEdit *)Sender)->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Key = 0;

    if (GetMode() != imSecond){
        HinCodeEdit1->SetFocus();
        return;

    }else{

        // 20160519追加
        // 1回目重量と2回目重量が同じ時は計量完了していないので次の行へいかない
        // 正味が未入力の場合は計量完了していないので次の行へいかない
        if (tanka[1]->Text == "" || kingaku[1]->Text == "" || shomi[1]->Text == ""){
                hincode[1]->SetFocus();
                ;
        }else if (tanka[2]->Text == "" || kingaku[2]->Text == "" ){
            if (weight2[1]->Text == "0"){
                weight2[1]->SetFocus();
            }else
            hincode[2]->SetFocus();
        }else if (tanka[3]->Text == "" || kingaku[3]->Text == ""){
            if (weight2[2]->Text == "0"){
                weight2[2]->SetFocus();
            }else
            hincode[3]->SetFocus();
        }else if (tanka[4]->Text == "" || kingaku[4]->Text == ""){
            if (weight2[3]->Text == "0"){
                weight2[3]->SetFocus();
            }else
            hincode[4]->SetFocus();
        }else if (tanka[5]->Text == "" || kingaku[5]->Text == ""){
            if (weight2[4]->Text == "0"){
                weight2[4]->SetFocus();
            }else
            hincode[5]->SetFocus();
        }else if (tanka[6]->Text == "" || kingaku[6]->Text == ""){
            if (weight2[5]->Text == "0"){
                weight2[5]->SetFocus();
            }else
            hincode[6]->SetFocus();
        }else{
            Application->MessageBox("明細を挿入できる行がありません\r\n登録を行ってください", this->Caption.c_str(), MB_OK);
        }
        //20160519 追加
    	Action10->OnExecute(NULL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TaniCodeEdit1Change(TObject *Sender)
{
    int num = GetRowNo();

    taniname[num]->Text = ToString(DM->DBI.Lookup("M_単位", "単位コード", tanicode[num]->Text.ToIntDef(0), "単位名称", ""));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CalcShomiTotal()
{
    shomi_total_ = 0;
    ShomiSumEdit->Text = AnsiString();
    int total = 0;

    for(int i = 1; i < 7; i++){
        if(shomi[i]->Text == ""){
            continue;
        }

        shomi_total_ += StrToIntDef(shomi[i]->Text, 0);
        total += shomi[i]->Text.ToIntDef(0);
    }
    ShomiSumEdit->Text = ToString(shomi_total_);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ShomiEdit1Change(TObject *Sender)
{
/*    //20160628
    int row = GetRowNo();

    if (row == 0){
        return;
    }

    Currency shom =  StrToCurrDef(shomi[row]->Text, 0);
    Currency w1   =  StrToCurrDef(weight1[row]->Text, 0);
    Currency total = shom + w1;
    weight2[row]->Text = CurrToStr(total);

    CalcShomiTotal();
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcKingakuTotal()
{
    int kingaku = 0, shohizei = 0;
    kingaku  = KingakuSumEdit->Text.ToIntDef(0);
    shohizei = ShohizeiEdit->Text.ToIntDef(0);
//    sum_total_ = (KingakuSumEdit->Text.ToIntDef(0)) + (ShohizeiEdit->Text.ToIntDef(0));
    ZeikomiEdit->Text =  sum_total_ = kingaku + shohizei;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcKingaku()
{
    kingaku_total_ = 0;
    KingakuSumEdit->Text = AnsiString();

    for (int i = 1; i < 7; i++){
        kingaku_total_ += StrToIntDef(kingaku[i]->Text, 0);
    }

    KingakuSumEdit->Text = ToString(kingaku_total_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SuryoEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clWindow;
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

void __fastcall TMainForm::MeisaiAddButtonClick(TObject *Sender)
{
    if (hincode[limit_line_]->Text != ""){
        Application->MessageBox("明細追加するには空行が必要です", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }
    //現在フォーカスされている行数を取得
    int i = GetRowNo();

    //フォーカス行が6行目なら
    if(i == limit_line_){
        return;
    }

    //明細非フォーカス時の処理
    if (i == 0){
        return;
    }
/*
    //フォーカス行の次行が空白ならば,次行入力へ
    if (hincode[i + 1]->Text == ""){
        hincode[i + 1]->SetFocus();
        return;
    }
*/
    for(int cnt = 6; cnt > 0; cnt--){
        if (i > cnt){
            continue;
        }

        if(hincode[cnt]->Text == ""){
            continue;
        }

        hincode[cnt + 1]->Text    =   hincode[cnt]->Text;
        hinname[cnt + 1]->Text    =   hinname[cnt]->Text;
        weight1[cnt + 1]->Text    =   weight1[cnt]->Text;
        //weight2[cnt + 1]->Text    =   StrToCurrDef(weight1[]->Text, 0) + StrToCurrDef(shomi[cnt]->Text, 0);
        weight2[cnt + 1]->Text    =   weight2[cnt]->Text;
        choritu[cnt + 1]->Text    =   choritu[cnt]->Text;
        choweight[cnt + 1]->Text  =   choweight[cnt]->Text;
        bikiweight[cnt + 1]->Text =   bikiweight[cnt]->Text;
        shomi[cnt + 1]->Text      =   shomi[cnt]->Text;
        suryo[cnt + 1]->Text      =   suryo[cnt]->Text;
        tanicode[cnt + 1]->Text   =   tanicode[cnt]->Text;
        taniname[cnt + 1]->Text   =   taniname[cnt]->Text;
        tanka[cnt + 1]->Text      =   tanka[cnt]->Text;
        kingaku[cnt + 1]->Text    =   kingaku[cnt]->Text;
        shouhi[cnt + 1]->Text     =   shouhi[cnt]->Text;
        biko[cnt + 1]->Text       =   biko[cnt]->Text;

        //20160624
        //行追加したときにIDまで移動させることない
        //StringGridID->Cells[0][cnt + 1] = StringGridID->Cells[0][cnt];

    }

    //行を移動したら選択した行をクリア
    hincode[i]->Text = AnsiString();
    hinname[i]->Text = AnsiString();
    weight1[i]->Text = AnsiString();
    weight2[i]->Text = AnsiString();
   	choritu[i]->Text = AnsiString();
    choweight[i]->Text = AnsiString();
   	bikiweight[i]->Text = AnsiString();
    shomi[i]->Text = AnsiString();
   	suryo[i]->Text = AnsiString();
    tanicode[i]->Text = AnsiString();
   	taniname[i]->Text = AnsiString();
   	tanka[i]->Text = AnsiString();
    kingaku[i]->Text = AnsiString();
    shouhi[i]->Text  = AnsiString();
   	biko[i]->Text = AnsiString();
    //20160624
    //ID以外を上書きする
    //StringGridID->Cells[0][i] = AnsiString();

    //明細追加フラグtrue
    chk_addflag_ = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MeisakiDeleteButtonClick(TObject *Sender)
{
    //選択行を変数に
    int i = GetRowNo();
    //選択されている行のIDを変数に
    int chk_keiryoID = StringGridID->Cells[0][i].ToIntDef(0);

    if (i <= 0 || i > 6){
        Application->MessageBox("削除する明細の行を選んでください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    // 1行しか存在しないとき
    // 伝票そのものを削除する
    if (hincode[1]->Text != "" && hinname[2]->Text == "" ){
        Action3->Execute();
        return;
    }

    AnsiString gyo_no = ToString(i);

    // 複数行ある場合の処理
    if (Application->MessageBox(("行No" + IntToStr(i) + " を削除してもよろしいですか？\r\nこの処理で実際のデータが削除されます").c_str(),
            this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES){
        return;
    }

    try{
        DM->ADOConnection->BeginTrans();

        NsFieldSet keys;
        NsRecordSet set;
        if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(chk_keiryoID), set)){
            Application->MessageBox("削除データの抽出に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }

        keys    <<  NsField("[計量日]",     ToInt(set[0]["計量日"]))
                <<  NsField("[拠点ID]",     ToInt(set[0]["拠点ID"]))
                <<  NsField("[伝票No]",   ToInt(set[0]["伝票No"]))
                <<  NsField("[行No]",       ToInt(set[0]["行No"]));

        DM->DBI.Delete("D_計量", keys);

        //取引データも同処理
        keys.clear();

        if (!DM->DBI.GetRecordSet("SELECT * FROM D_取引 WHERE 計量ID = " + IntToStr(chk_keiryoID), set)){
            Application->MessageBox("取引削除データの抽出に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }

        keys    <<  NsField("[計量ID]", chk_keiryoID);

        DM->DBI.Delete("D_取引", keys);

        //問題なければ削除処理を完了する
        DM->ADOConnection->CommitTrans();
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "削除時にエラーが発生しました - " + e.Message;
        Application->MessageBox(msg.c_str(), "計量データ削除", MB_OK | MB_ICONWARNING);
        return;
    }

    for(i; i < limit_line_; i++){
        if (i > 1 && hincode[i]->Text.ToIntDef(0) ==0){
            continue;
        }

        if (hincode[i + 1]->Text == ""){
        	hincode[i]->Text = AnsiString();
	        hinname[i]->Text = AnsiString();
	        weight1[i]->Text = AnsiString();
	        weight2[i]->Text = AnsiString();
        	choritu[i]->Text = AnsiString();
        	choweight[i]->Text = AnsiString();
        	bikiweight[i]->Text = AnsiString();
        	shomi[i]->Text = AnsiString();
        	suryo[i]->Text = AnsiString();
        	tanicode[i]->Text = AnsiString();
        	taniname[i]->Text = AnsiString();
        	tanka[i]->Text = AnsiString();
        	kingaku[i]->Text = AnsiString();
            shouhi[i]->Text  = AnsiString();
        	biko[i]->Text = AnsiString();
        	StringGridID->Cells[0][i] = AnsiString();
            continue;
        }

        hincode[i]->Text    =   hincode[i + 1]->Text;
        hinname[i]->Text    =   hinname[i + 1]->Text;
        weight1[i]->Text    =   weight2[i - 1]->Text;
        weight2[i]->Text    =   StrToCurrDef(weight1[i]->Text, 0) + StrToCurrDef(shomi[i + 1]->Text, 0);
        choritu[i]->Text    =   choritu[i + 1]->Text;
        choweight[i]->Text  =   choweight[i + 1]->Text;
        bikiweight[i]->Text =   bikiweight[i + 1]->Text;
        shomi[i]->Text      =   shomi[i + 1]->Text;
        suryo[i]->Text      =   suryo[i + 1]->Text;
        tanicode[i]->Text   =   tanicode[i + 1]->Text;
        taniname[i]->Text   =   taniname[i + 1]->Text;
        tanka[i]->Text      =   tanka[i + 1]->Text;
        kingaku[i]->Text    =   kingaku[i + 1]->Text;
        shouhi[i]->Text     =   shouhi[i + 1]->Text;
        biko[i]->Text       =   biko[i + 1]->Text;
        StringGridID->Cells[0][i] = StringGridID->Cells[0][i + 1];
    }

    NsFieldSet keys, fields;

    try{
        DM->ADOConnection->BeginTrans();

        //明細登録
        for (int i = 1; i <= limit_line_ + 1; i++){
            if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                continue;

            keys.clear();
            fields.clear();

            keys    <<  NsField("[計量ID]", StringGridID->Cells[0][i].ToIntDef(0));

            fields  <<  NsField("[1回目重量]", StrToCurrDef(weight1[i]->Text, 0))
                    <<  NsField("[2回目重量]", StrToCurrDef(weight2[i]->Text, 0))
                    <<  NsField("[行No]", i);

            if(!DM->DBI.IsExist("D_計量", keys)){
                DM->DBI.Insert("D_計量", fields);
            }else{
                DM->DBI.Update("D_計量", keys, fields);
            }
        }


        //取引データ登録
        for (unsigned int i = 1; i <= limit_line_ + 1; i++){
            if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                continue;

            keys.clear();
            fields.clear();

            keys    <<  NsField("[計量ID]", StringGridID->Cells[0][i].ToIntDef(0));
            //fields  <<  NsField("[行No]",   ToInt(set[i]["行No"]));
            fields  <<  NsField("[行No]",   i);

            if (!DM->DBI.IsExist("D_取引", keys)){
                DM->DBI.Insert("D_取引", fields);
            }else{
                DM->DBI.Update("D_取引", keys, fields);
            }
        }

        DM->ADOConnection->CommitTrans();


    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "登録時にエラーが発生しました - " + e.Message;
        Application->MessageBox(msg.c_str(), "登録エラー", MB_OK | MB_ICONWARNING);
        return;
    }

    Q_Tairyu->Close();
    Q_Tairyu->Open();


}
//---------------------------------------------------------------------------
// 重量再計算ボタン
//
void __fastcall TMainForm::RecalcButtonClick(TObject *Sender)
{
    //2行目なしで実行しない
    if(hincode[2]->Text == "")
        return;

    if (Application->MessageBox("再計算を行いますか?", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    Currency w1, w2, net, adjust, reduc;
    int io_div = HannyuCombo->ItemIndex + 1;

    if (io_div <1 || io_div >2){
        Application->MessageBox("搬入出区分が設定されていません", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    if (io_div == 1){

        //搬入
        //最終行から
        // limit_line_      .hに記述
        Currency first_weight = 0;

        for (int i = limit_line_; i > 0; i--){
            if(hincode[i]->Text == ""){
                continue;
            }
            w1  =   StrToCurrDef(weight1[i]->Text, 0);
            w2  =   StrToCurrDef(weight2[i]->Text, 0);
            net =   StrToCurrDef(shomi[i]->Text, 0);
            adjust  =   StrToCurrDef(choweight[i]->Text, 0);
            reduc   =   StrToCurrDef(bikiweight[i]->Text, 0);

            if (w1 == 0 && w2 == 0){ //
                continue;
            }

            if (first_weight != 0){
                w2                  =   first_weight;
                weight2[i]->Text    =   first_weight;
            }

            if (w1 - w2 - adjust - reduc != net){
                first_weight        = ToString(w2 + adjust + reduc + net);
                weight1[i]->Text    = first_weight;
            }else{
                first_weight = w1;
            }
        }

    }else if (io_div == 2){
        //搬出
        Currency second_weight = 0;

        for(int i = 0; i <= limit_line_; i++){
            if (hincode[i]->Text == ""){
                continue;
            }

            w1      =   StrToCurrDef(weight1[i]->Text, 0);
            w2      =   StrToCurrDef(weight2[i]->Text, 0);
            net     =   StrToCurrDef(shomi[i]->Text, 0);
            adjust  =   StrToCurrDef(choweight[i]->Text, 0);
            reduc   =   StrToCurrDef(bikiweight[i]->Text, 0);

            if (w1 == 0 && w2 == 0)
                continue;

            if (second_weight != 0){
                w1  =   second_weight;
                weight1[i]->Text = AnsiString(second_weight);
            }

            if (w2 - w1 - adjust - reduc != net){
                second_weight = w1 + adjust + reduc + net;
                weight2[i]->Text = AnsiString(second_weight);
            }else{
                second_weight = w2;
            }
        }
    }

    Application->MessageBox("再計算が完了しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MeisaiAddWeightRecieve()
{
//
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::TankaEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;
    CalcAmount(false);
}
//---------------------------------------------------------------------------
// 単価が登録単価かどうかをチェックするだけ
void __fastcall TMainForm::TankaCheck(int row)
{
    int meig_id  = ToInt(DM->DBI.Lookup("M_品目", "品目コード", hincode[row]->Text.ToIntDef(0), "品目ID"));
    int item1_id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    int item2_id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    int tani_id  = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tanicode[row]->Text.ToIntDef(0), "単位ID"));

	Currency tankacode = StrToCurrDef(tanka[row]->Text, 0);
	Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);

    //登録単価 = 黄色 それ以外 = 赤
    tanka[row]->Color = tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

}
//---------------------------------------------------------------------------
//明細削除
void __fastcall TMainForm::SpeedButton2Click(TObject *Sender)
{
    //選択行を変数に
    int row = GetRowNo();
    int i = row;

    //選択行の計量ID を保持
    //1明細しかないときは伝票削除になる
    //削除にはkeiryo_id_に入れた方が都合がよい
    keiryo_id_ = StringGridID->Cells[0][i].ToIntDef(0);

    //行が選択されてなければ、return;
    if (row <= 0 || row > 6){
        Application->MessageBox("削除する明細行を選んでください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    NsFieldSet  keys;
    NsRecordSet set;

    //　計量IDからの呼び出し
    if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id_), set)){
        DeleteSingleRow(row);
        return;
    }


    // 明細が1行しかないときは
    // F3削除する
    if (hincode[1]->Text != "" && hincode[2]->Text == ""){
        Action3->Execute();
        return;
    }

    AnsiString gyo_no = ToString(i);
    //削除前確認メッセージ
    if (Application->MessageBox(("行No" + IntToStr(i) + " を削除してもよろしいですか？\r\nこの処理でデータが削除されます\r\n元に戻すことはできません").c_str(),
            this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES){
        return;
    }

    try{
        DM->ADOConnection->BeginTrans();
/*
        NsFieldSet  keys;
        NsRecordSet set;

        //計量IDからデータの呼び出し
        if (!DM->DBI.GetRecordSet("SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id_), set)){
            //抽出失敗処理
            Application->MessageBox("計量データの抽出に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
*/
        //D_計量 1明細削除
        keys    <<  NsField("[計量日]", ToInt(set[0]["計量日"]))
                <<  NsField("[拠点ID]", ToInt(set[0]["拠点ID"]))
                <<  NsField("[伝票No]", ToInt(set[0]["伝票No"]))
                <<  NsField("[行No]",   ToInt(set[0]["行No"]));

        DM->DBI.Delete("D_計量", keys);

        int date = DateToInt(KeiryoDatePicker->Date);
        int kyo  = GetPlaceID();
        int denpyo  = KeiryoNoEdit->Text.ToIntDef(0);

        AnsiString sql;
        sql =  " SELECT 計量ID FROM D_計量"
               " WHERE  計量日 = " + IntToStr(date) + " AND 拠点ID = " + IntToStr(kyo) +
               " AND    伝票No = " + IntToStr(denpyo);

        DM->DBI.GetRecordSet(sql, set);

        int del_keiryo_id = keiryo_id_;
        ClearForm();
        keiryo_id_ = SET_TOP(set)["計量ID"];
        LoadFromID(keiryo_id_);

/*        // 削除した行になにも入らなかったら指定した1行クリア
        if (hincode[row]->Text == ""){
            DeleteSingleRow(row);
        }
*/
        //明細登録用
        NsFieldSet fields;

        //明細登録
        for (int i = 1; i <= limit_line_ + 1; i++){
            if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                continue;

            keys.clear();
            fields.clear();

            keys    <<  NsField("[計量ID]", StringGridID->Cells[0][i].ToIntDef(0));

            fields  <<  NsField("[1回目重量]", StrToCurrDef(weight1[i]->Text, 0))
                    <<  NsField("[2回目重量]", StrToCurrDef(weight2[i]->Text, 0))
                    <<  NsField("[行No]", i);

            if(!DM->DBI.IsExist("D_計量", keys)){
                DM->DBI.Insert("D_計量", fields);
            }else{
                DM->DBI.Update("D_計量", keys, fields);
            }
        }

        //////////////////////////////
        // 取引データ処理

        keys.clear();

        if (DM->DBI.GetRecordSet("SELECT * FROM D_取引 WHERE 計量ID = " + IntToStr(keiryo_id_), set)){
            keys << NsField("[計量ID]", del_keiryo_id);

            DM->DBI.Delete("D_取引", keys);

            //取引データ登録
            for (unsigned int i = 1; i <= limit_line_ + 1; i++){
                if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                    continue;

                keys.clear();
                fields.clear();

                keys    <<  NsField("[計量ID]", StringGridID->Cells[0][i].ToIntDef(0));
                //fields  <<  NsField("[行No]",   ToInt(set[i]["行No"]));
                fields  <<  NsField("[行No]",   i);

                if (!DM->DBI.IsExist("D_取引", keys)){
                    DM->DBI.Insert("D_取引", fields);
                }else{
                    DM->DBI.Update("D_取引", keys, fields);
                }
            }
        }

        DM->ADOConnection->CommitTrans();
        AnsiString compmsg = "削除が完了しました";
        Application->MessageBox(compmsg.c_str(), Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "明細削除時時にエラーが発生しました - " + e.Message;
        Application->MessageBox(msg.c_str(), "明細削除エラー", MB_OK | MB_ICONWARNING);
        return;
    }


    Q_Tairyu->Close();
    Q_Tairyu->Open();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WeightEdit12KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key != VK_RETURN){
        return;
    }

    

    CalcAmount();

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteSingleRow(int row)
{
    hincode[row]->Text  =  AnsiString();
    hinname[row]->Text  =  AnsiString();
    weight1[row]->Text  =  AnsiString();
    weight2[row]->Text  =  AnsiString();
    choritu[row]->Text  =  AnsiString();
    choweight[row]->Text    =  AnsiString();
    bikiweight[row]->Text   =  AnsiString();
    shomi[row]->Text    =  AnsiString();
    suryo[row]->Text    =  AnsiString();
    tanicode[row]->Text =  AnsiString();
    taniname[row]->Text =  AnsiString();
    tanka[row]->Text    =  AnsiString();
    kingaku[row]->Text  =  AnsiString();
    shouhi[row]->Text   =  AnsiString();
    biko[row]->Text     =  AnsiString();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ChoseiPerEdit1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
/*    if (Key != VK_RETURN)
        return;

	int row = GetRowNo();

	if ((TCobEdit *)Sender == choritu[row])
		choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));


	CalcWeight();
    //総金額
    CalcKingakuTotal();
    //総正味重量
    CalcShomiTotal();
    //消費税
    CalcSalesTax();
*/
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SuryoEdit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    int row = GetRowNo();

    if ((TCobEdit *)Sender == choritu[row])
        choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));

    CalcAmount();

}
//---------------------------------------------------------------------------




void __fastcall TMainForm::ChoseiPerEdit1Exit(TObject *Sender)
{
	int row = GetRowNo();

    //Editの背景色をもとに戻す
    ((TEdit *)Sender)->Color = clWindow;

	if ((TCobEdit *)Sender == choritu[row])
		choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));


	CalcWeight();
    //総金額
    CalcKingakuTotal();
    //総正味重量
    CalcShomiTotal();
    //消費税
    CalcSalesTax();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::KingakuEdit1Exit(TObject *Sender)
{
    //Exitで背景色を元に戻す
    ((TEdit *)Sender)->Color = clCream;

    CalcKingaku();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ShudoCheckBoxClick(TObject *Sender)
{
    if (ShudoCheckBox->Checked){
        ShudoCheckBox->Color = TColor(0x0076EBE6);  //trueなら、 濃い黄色
    }else{
        ShudoCheckBox->Color = TColor(0x00FCB998);  //falseなら、青い標準
    }

    if (ShabanEdit->Text == "")
        ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WeightEdit11Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;

    int row = GetRowNo();

    if (choritu[row]->Text != "" || !ShudoCheckBox->Checked){
        return;
    }


	// 重量調整率
	NsRecordSet set;
	AnsiString  sql;

	sql = "SELECT * FROM M_品目 WHERE 品目コード = " + IntToStr(hincode[row]->Text.ToIntDef(0));
	if (DM->DBI.GetRecordSet(sql, set)){
		Currency coord_ratio = ToCurrency(SET_TOP(set)["重量調整率"]);

		if (StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0) != coord_ratio){
			if (GetMode() == imMod)
				if (Application->MessageBox(("重量調整率が異なります。上書きしますか？\r\n登録調整率：" + FormatFloat("#,##0.0#", coord_ratio) + "%").c_str(), "品目変更", MB_YESNO | MB_ICONEXCLAMATION) != IDYES)
					return;
			choritu[row]->Text = ZeroSuppress(coord_ratio);
			CalcWeight();
		}
	}
}
//---------------------------------------------------------------------------
// 1行目の2回目の計量において,調整率を取得できなかったので
// 2回目重量の1行目に限って,調整率を取得する処理を追加

// それ以外の2回目重量については、WeightEdit22Enterを共有する

void __fastcall TMainForm::WeightEdit12Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
    cur_w2_row_ = GetRowNo();

    // 20160624
    if(ActiveControl == weight2[1]){
        NsRecordSet set;
        AnsiString  sql;

        sql = "SELECT * FROM M_品目 WHERE 品目コード = "  + IntToStr(hincode[1]->Text.ToIntDef(0));
        if (DM->DBI.GetRecordSet(sql, set)){
            Currency coord_ratio = ToCurrency(SET_TOP(set)["重量調整率"]);
            choritu[1]->Text = ZeroSuppress(coord_ratio);
        }
    }
}
//---------------------------------------------------------------------------
//
void __fastcall TMainForm::WeightEdit22Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
    cur_w2_row_ = GetRowNo();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEditExit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;    
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::TaniCodeEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ShouhizeiEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clWindow;    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clWindow;    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HinCodeEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;

    int row = GetRowNo();
    if (GetMode() == imSecond && row >= 2){
        if (weight1[row]->Text.IsEmpty() && weight2[row]->Text.IsEmpty()){
            weight1[row]->Text = weight2[row - 1]->Text;
            weight2[row]->Text = cur_weight_;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikiWeightEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SuryoEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TaniCodeEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TankaEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::KingakuEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShouhizeiEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SharyoNameEditEnter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SharyoNameEditExit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChoseiPerEdit1Change(TObject *Sender)
{
    if (AnbunFlag_){
        return;
    }

    int row = GetRowNo();


    if (choritu[row]->Text == ""){
        choweight[row]->Text = AnsiString();
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShomiEdit1Exit(TObject *Sender)
{
/*    int row = GetRowNo();

    Currency shom = StrToCurrDef(shomi[row]->Text, 0);
    Currency w1   = StrToCurrDef(weight1[row]->Text, 0);
    Currency total = shom + w1;
    if (!choweight[row]->Text.IsEmpty()){
        total += StrToCurrDef(choweight[row]->Text, 0);
    }

    weight2[row]->Text = CurrToStr(total);

//    CalcWeight(row);
//    CalcShomiTotal();
*/
}
//---------------------------------------------------------------------------
// 按分
void __fastcall TMainForm::AnbunButtonClick(TObject *Sender)
{
    //選択按分行を変数へ
    int row = GetRowNo();

    if (row == 6)
    {
        Application->MessageBoxA("明細行不足のため按分できません", this->Caption.c_str(), MB_OK);
    }

    int i = row;
    int sumRow = 0;
    int carryflag = ToInt(DM->DBI.Lookup("M_品目","品目コード",ToInt(hincode[1]->Text),"搬入出区分"));

    //按分フラグをON 調整率changeの調整重量クリアさせないため
    AnbunFlag_ = 1;

    //按分を行う行が選択されてなかったら
    if (row <= 0 || row > 6){
        Application->MessageBox("按分する明細行を選択してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    //計量データが存在するかどうか
    int chk_keiryoID = StringGridID->Cells[0][row].ToIntDef(0);
/*
    NsRecordSet set;
	AnsiString sql;
	sql = " SELECT * FROM V_計量"
		  " WHERE"
		  "		計量日 IN ( SELECT 計量日 FROM D_計量 WHERE 計量ID = " + IntToStr(chk_keiryoID) + ") "
		  " AND"
		  "		拠点ID IN ( SELECT 拠点ID FROM D_計量 WHERE 計量ID = " + IntToStr(chk_keiryoID) + ") "
		  " AND"
		  "     伝票No IN ( SELECT 伝票No FROM D_計量 WHERE 計量ID = " + IntToStr(chk_keiryoID) + ") "
		  " AND"
		  "     完了区分 <> 9";                 // 論理削除は対象外

    if (!DM->DBI.GetRecordSet(sql, set)){
        //デバック用めせじ
        ShowMessage("按分不可");
        //
        return;
    }
*/
    for (int i = 1; i <= 6; i++){
        if (!hincode[i]->Text.IsEmpty()){
            sumRow++;
        }else{
            break;
        }
    }
/*
    if (set.size() >= limit_line_){
        Application->MessageBox("明細件数が最大件数(6件)になっているため,按分できません", "按分", MB_OK | MB_ICONWARNING);
        return;
    }
*/
    if (sumRow >= limit_line_) {
        Application->MessageBox("明細件数が最大件数になっているため、按分できません", "按分", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString weight1temp = weight1[row]->Text;
    AnsiString weight2temp = weight2[row]->Text;

    AnbunForm->ClearForm();
    AnbunForm->EditRate->Text       = "100";

    AnbunForm->EditHinCode->Text    = hincode[row]->Text;
    AnbunForm->EditHinName->Text    = hinname[row]->Text;
    AnbunForm->EditChoseiBiki->Text  = choweight[row]->Text;
    AnbunForm->EditJuryoBiki->Text  = bikiweight[row]->Text;
    AnbunForm->EditShomi->Text      = shomi[row]->Text;

//    AnbunForm->rec_count = set.size();
    AnbunForm->rec_count = sumRow;
    //登録行数を格納
//    int setsize = set.size();

    //按分で行移動が必要な行数を格納
//    int moveCnt = setsize - row;
    int moveCnt = sumRow - row;

    if (AnbunForm->ShowModal() == mrOk){

        //按分された行数
        int AnbunItemCount = AnbunForm->AnbunMap.size();


        //按分しない行を移動する
        for (int i = 0; i < moveCnt; i++){
            if (hincode[row + 1 + i]->Text.IsEmpty()){
                continue;
            }
            weight1[row + AnbunItemCount + i]->Text     = weight1[row + 1 + i]->Text;
            weight2[row + AnbunItemCount + i]->Text     = weight2[row + 1 + i]->Text;
            hincode[row + AnbunItemCount + i]->Text     = hincode[row + 1 + i]->Text;
            hincode[row + AnbunItemCount + i]->Text     = hincode[row + 1 + i]->Text;
            hincode[row + AnbunItemCount + i]->Text     = hincode[row + 1 + i]->Text;
            hinname[row + AnbunItemCount + i]->Text     = hinname[row + 1 + i]->Text;
            choritu[row + AnbunItemCount + i]->Text     = choritu[row + 1 + i]->Text;
            choweight[row + AnbunItemCount + i]->Text   = choweight[row + 1 + i]->Text;
            bikiweight[row + AnbunItemCount + i]->Text  = bikiweight[row + 1 + i]->Text;
            shomi[row + AnbunItemCount + i]->Text       = shomi[row + 1 + i]->Text;
            suryo[row + AnbunItemCount + i]->Text       = suryo[row + 1 + i]->Text;
            tanicode[row + AnbunItemCount + i]->Text    = tanicode[row + 1 + i]->Text;
            taniname[row + AnbunItemCount + i]->Text    = taniname[row + 1 + i]->Text;
            tanka[row + AnbunItemCount + i]->Text       = tanka[row + 1 + i]->Text;
            kingaku[row + AnbunItemCount + i]->Text     = kingaku[row + 1 + i]->Text;
            shouhi[row + AnbunItemCount + i]->Text      = shouhi[row + 1 + i]->Text;
            biko[row + AnbunItemCount + i]->Text        = biko[row + 1 + i]->Text;
        }

        //按分処理した行を挿入する
        for (int i = 0; i < AnbunItemCount; i++){
            hincode[row]->Text      = AnsiString(AnbunForm->AnbunMap[i].code);
            hinname[row]->Text      = AnsiString(AnbunForm->AnbunMap[i].name);
            choritu[row]->Text      = AnsiString();
            choritu[row]->Text      = AnsiString(AnbunForm->AnbunMap[i].choseiper);
            choweight[row]->Text    = AnsiString(AnbunForm->AnbunMap[i].choseibiki);
            bikiweight[row]->Text   = AnsiString(AnbunForm->AnbunMap[i].juryobiki);
            shomi[row]->Text        = AnsiString(AnbunForm->AnbunMap[i].shomi);
            suryo[row]->Text        = AnsiString();
            tanicode[row]->Text     = AnsiString();
            taniname[row]->Text     = AnsiString();
            tanka[row]->Text        = AnsiString();
            kingaku[row]->Text      = AnsiString();
            shouhi[row]->Text       = AnsiString();
            biko[row]->Text         = AnsiString();
            AnbunCalcChousei(row, carryflag);
            AnbunAfterChousei(row);
            //(按分)単価、金額、消費税を表示
            AnbunCalcAmountTax(row);

            row++;
        }

        GetTotalMoney();
    }

    //調整率change(率の指定なければクリア機能)を使用可能にする
    AnbunFlag_ = 0;

    if (!hincode[6]->Text.IsEmpty() && !shomi[6]->Text.IsEmpty())
    {
        // GetRowNo()をしたときに明細行が最大であることを示すため
        // フォーカスを最大行にしておく
        hincode[6]->SetFocus();
        if (Application->MessageBox("明細行が最大です\r\n登録してもよろしいですか?", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDNO)
        {
            PostWeighing();
        }
    }

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AnbunCalcAmountTax(int row)
{
   if (row != 0){
        int meig_id  = ToInt(DM->DBI.Lookup("M_品目","品目コード", hincode[row]->Text.ToIntDef(0), "品目ID"));
        int item1_id = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
        int item2_id = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
        int tani_id  = ToInt(DM->DBI.Lookup("M_単位", "単位コード", tanicode[row]->Text.ToIntDef(0), "単位ID"));

        Currency quantity = StrToCurrDef(suryo[row]->Text, 0);

        if (!ToBit(DM->CFG["単価使用区分"])){
            return;
        }

        Currency tankacode = StrToCurrDef(tanka[row]->Text, 0);
        Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);

        if (tanka[row]->Text.IsEmpty()){
            tankacode = deftanka;
        }

        tanka[row]->Color = tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

        //金額端数処理区分の取得
        int amount_div = -1;
        int amount_fig = 0;

        if (!toku_rec_.empty()){
            if (!IsNull(toku_rec_["金額端数処理区分"]))
                amount_div = ToInt(toku_rec_["金額端数処理区分"]);
        }

        if (amount_div == -1){
            amount_div = ToInt(DM->CFG["金額端数処理区分"]);
        }
        if (amount_fig == 0)
            amount_fig = ToInt(DM->CFG["金額端数処理桁数"]);

        int amount = ExtendedRound(quantity * tankacode, amount_fig, amount_div);

        tanka[row]->Text   = tankacode;
        kingaku[row]->Text = amount;

        //////////////////////////////////////////////////////////////
        //消費税

        Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));

        int sum_money = 0;
        int sum_tax   = 0;
        //消費税端数処理区分の取得
        int tax_fig = 0;
        int tax_div = -1;

        if (!toku_rec_.empty()) {
            if (!IsNull(toku_rec_["消費税端数処理区分"]))
                tax_div = ToInt(toku_rec_["消費税端数処理区分"]);
        }

        amount = 0;
        tax_total_ = 0;

        for (int i = 1; i < 7; i++){
            if (kingaku[i]->Text == "") {
                continue;
            }

            amount      =   StrToIntDef(kingaku[i]->Text, 0);
            tax_total_  =   int(ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div));

            if (shouhi[0]->Visible == true){
                shouhi[i]->Text = IntToStr(tax_total_);
            }
        }

    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AnbunCalcChousei(int row, int carrytype)
{
    Currency Shomi   =   StrToCurrDef(shomi[row]->Text,0);
    Currency Weight1 =   StrToCurrDef(weight1[row]->Text,0);
    Currency Chosei  =   StrToCurrDef(choweight[row]->Text, 0);
    Currency Bikiweight   =   StrToCurrDef(bikiweight[row]->Text, 0);
    Currency result  = 0;

    // 搬入 = 1, 搬出 = 2
    if (carrytype == 1){//搬入
        result = (Weight1 - (Shomi + Chosei + Bikiweight));
    }else if (carrytype == 2){//搬出
        result = (Weight1 + (Shomi + Chosei + Bikiweight));
    }

    weight2[row]->Text      = AnsiString(result);
    weight1[row + 1]->Text  = AnsiString(result);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetHinmoku()
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 品目コード, 品目略称, 搬入出区分名称 AS 搬入出, 取引区分名称 AS 取引区分 FROM V_品目 WHERE 使用区分 = 1";
	SearchForm->orderby_sql = " ORDER BY 品目コード ";
	SearchForm->table_name = "V_品目";
	if (SearchForm->ShowModal() != mrOk)
		return;
	int row = GetRowNo();
	if (row == 0)
		return;
	hincode[row]->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
	hincode[row]->OnChange(NULL);
	hincode[row]->SetFocus();
}
//---------------------------------------------------------------------------

