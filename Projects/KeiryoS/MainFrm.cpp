//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DataListFrm.h"
#include "MainFrm.h"
#include <mmsystem.h>
#include "LaserSlipPrintFrm.h"
#include "DotSlipPrintFrm.h"
#include "ManualDotSlipFrm.h"
#include "TrailerWeightFrm.h"
#include "ShabanSanshoFrm.h"
#include "nsoftfunc.h"
#include "QRChitFrm.h"
#include "BitField.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner),
        keiryo_id_(0), id_total_(0),
		cur_weight1_(0), old_weight1_(0), bdn_weight1_(0),
		cur_weight2_(0), old_weight2_(0), bdn_weight2_(0),
        rfid_thread_(0), last_card_no_(0)
{
    Application->OnMessage = MessageProc;
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

	///////////////////////////////////////////////
	// RFID
    if (ToInt(DM->CFG["卓上RFID計量"])){
		int rfid_port = ToInt(DM->INI[L"RFID::DeskCommPort"]);
		rfid_thread_  = new THF04Thread(true, Handle, rfid_port);
		rfid_thread_->FreeOnTerminate = false;
		rfid_thread_->Resume();
    }

	weighing_border_ = ToInt(DM->INI["Weighing::SoundBorder"]);

	// 秤量＆目量
	DM->hyoryo_ = ToCurrency(DM->CFG["秤量"]);
	DM->meryo_  = ToCurrency(DM->CFG["目量"]);

	// 滞留テーブルオープン
	try{
		Q_Tairyu->Open();
	}catch (Exception& e){
		Application->MessageBox(("滞留一覧データの読み込みに失敗しました\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

	///////////////////////////////////////////////
	// 重量受信
    if (ToInt(DM->INI["Weighing::WIUse1"])){
    	try{
	    	// [INI] Weighing::WIPort
		    ClientSocket1->Port = ToInt(DM->INI["Weighing::WIPort1"]);
    		// [INI] Weighing::WIServer
	    	ClientSocket1->Host = ToString(DM->INI["Weighing::WIServer1"]);

    		if (ClientSocket1->Active)
	    		ClientSocket1->Close();
		    ClientSocket1->Open();
    	}catch(Exception& e){
	    	AnsiString msg = "WI1 TCP/IP通信ができません: \r\n" + e.Message;
		    Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONINFORMATION);
    	}
    	SocketReopenTimer1->Enabled = true;

        ScaleNameLabel1->Caption = ToString(DM->INI["Weighing::WIName11"]);
        ScaleNameLabel2->Caption = ToString(DM->INI["Weighing::WIName12"]);
        ScaleNameLabel3->Caption = ToString(DM->INI["Weighing::WIName13"]);
    }

    if (ToInt(DM->INI["Weighing::WIUse2"])){
        //WeightNamePanel2->Caption = ToString(DM->INI["Weighing::WIName2"]);
    	try{
	    	// [INI] Weighing::WIPort
		    ClientSocket2->Port = ToInt(DM->INI["Weighing::WIPort2"]);
    		// [INI] Weighing::WIServer
	    	ClientSocket2->Host = ToString(DM->INI["Weighing::WIServer2"]);

    		if (ClientSocket2->Active)
	    		ClientSocket2->Close();
		    ClientSocket2->Open();
    	}catch(Exception& e){
	    	AnsiString msg = "WI2 TCP/IP通信ができません: \r\n" + e.Message;
		    Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONINFORMATION);
    	}
    	SocketReopenTimer2->Enabled = true;

        ScaleNameLabel4->Caption = ToString(DM->INI["Weighing::WIName21"]);
        ScaleNameLabel5->Caption = ToString(DM->INI["Weighing::WIName22"]);
        ScaleNameLabel6->Caption = ToString(DM->INI["Weighing::WIName23"]);
    }

    ///////////////////////////////////////////////
	// NP3411

    if (ToInt(DM->CFG["伝票発行プリンタ"]) == 5) {
	    int port = ToInt(DM->INI["OuterPrinter::Port"]);
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
    }

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
	TokuButton->Caption      = ToString(DM->CFG["得意先マスタ名称"]);
	Komoku1Button->Caption   = ToString(DM->CFG["項目1マスタ名称"]);
	Komoku2Button->Caption   = ToString(DM->CFG["項目2マスタ名称"]);
	HinButton->Caption       = ToString(DM->CFG["品目マスタ名称"]);
	ChoseiButton->Caption    = ToString(DM->CFG["調整名称"]);
	JuryobikiButton->Caption = ToString(DM->CFG["重量引き名称"]);

	DM->kname_toku_		= AnsiReplaceStr(AnsiReplaceStr(TokuButton->Caption,	"　", ""), " ", "");
	DM->kname_hin_		= AnsiReplaceStr(AnsiReplaceStr(HinButton->Caption,		"　", ""), " ", "");
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
		HinPanel->Visible             = false;
	}
	if (!ToBit(DM->CFG["入出庫使用区分"])){
		HannyuCombo->Visible          = false;
	}
	if (!ToBit(DM->CFG["調整使用区分"])){
		ChoseiPanel->Visible          = false;
	}
	if (!ToBit(DM->CFG["重量引き使用区分"])){
		JuryobikiPanel->Visible       = false;
	}
	if (!ToBit(DM->CFG["単価使用区分"])){
		SuryoPanel->Visible           = false;
		TaniPanel->Visible            = false;
		TankaPanel->Visible           = false;
		KingakuPanel->Visible         = false;
		ShohizeiPanel->Visible        = false;
	}
	if (!ToBit(DM->CFG["重量編集区分"])){
		FirstWEdit->ReadOnly          = true;
		SecondWEdit->ReadOnly         = true;
		TrailerWeightForm->FirstWEdit->ReadOnly  = true;
		TrailerWeightForm->SecondWEdit->ReadOnly = true;
	}
	if (!ToBit(DM->CFG["トレーラ対応"])){
		TrailerWeight1Button->Visible = false;
		TrailerWeight2Button->Visible = false;
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
	HinCodeEdit->Hint     = DM->kname_hin_     + "コードを入力してください。(" + DM->kname_hin_     + "ボタン or [F4]→マスタ参照)";
	Komoku1CodeEdit->Hint = DM->kname_komoku1_ + "コードを入力してください。(" + DM->kname_komoku1_ + "ボタン or [F4]→マスタ参照)";
	Komoku2CodeEdit->Hint = DM->kname_komoku2_ + "コードを入力してください。(" + DM->kname_komoku2_ + "ボタン or [F4]→マスタ参照)";
}
//---------------------------------------------------------------------------
// MainForm->OnClose
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (rfid_thread_){
    	rfid_thread_->Terminate();
        rfid_thread_->WaitFor();
        delete rfid_thread_;
    }

	try{
		if (MainForm->WindowState == wsMaximized)
			DM->INI.SaveSingle("Form", "Maximized", 1);
		else
			DM->INI.SaveSingle("Form", "Maximized", 0);
	}catch (...){}
}
//---------------------------------------------------------------------------
// ソケットの切断を監視
void __fastcall TMainForm::SocketReopenTimer1Timer(TObject *Sender)
{
    if (ClientSocket1->Active)
        return;

    try{
        ClientSocket1->Socket->Close();

        // [INI] Weighing::WIPort
        ClientSocket1->Port = ToInt(DM->INI["Weighing::WIPort"]);
        // [INI] Weighing::WIServer
        ClientSocket1->Host = ToString(DM->INI["Weighing::WIServer"]);

        ClientSocket1->Open();
    }catch(Exception& e){
        //AnsiString msg = "TCP/IP通信ができません: \r\n" + e.Message;
        //Application->MessageBox(msg.c_str(), "ネットワークエラー", MB_OK | MB_ICONINFORMATION);
        ;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SocketReopenTimer2Timer(TObject *Sender)
{
	if (ClientSocket2->Active)
		return;

	try{
        ClientSocket2->Socket->Close();

		// [INI] Weighing::WIPort
		ClientSocket2->Port = ToInt(DM->INI["Weighing::WIPort2"]);
		// [INI] Weighing::WIServer
        ClientSocket2->Host = ToString(DM->INI["Weighing::WIServer2"]);

        ClientSocket2->Open();
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
/*
    if (cur_weight1_ > 0 && cur_weight2_ == 0)
        return cur_weight1_;
    else if (cur_weight1_ == 0 && cur_weight2_ > 0)
        return cur_weight2_;
    else if (FWBasePanel->Color == TColor(0x008AF8FD))
        return cur_weight1_;
    else if (SWBasePanel->Color == TColor(0x008AF8FD))
        return cur_weight2_;
    else
        return 0;
*/
    bdn_weight1_ = cur_weight1_;
    bdn_weight2_ = cur_weight2_;

    return cur_weight1_ + cur_weight2_;
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
    KeiryoNoEdit->Text        = AnsiString();
    ShabanEdit->Text          = AnsiString();
    ShabanEdit->OnChange(NULL);
    TokuCodeEdit->Text        = AnsiString();
	TokuNameEdit->Text        = AnsiString();
	Komoku1CodeEdit->Text     = AnsiString();
	Komoku1NameEdit->Text     = AnsiString();
	Komoku2CodeEdit->Text     = AnsiString();
	Komoku2NameEdit->Text     = AnsiString();
	HinCodeEdit->Text         = AnsiString();
	HinNameEdit->Text         = AnsiString();
	HannyuCombo->ItemIndex    = -1;
	FirstWEdit->Text          = AnsiString();
	FirstDatePicker->Date     = now;
	FirstTimePicker->Time     = now;
	FirstDatePicker->Checked  = false;
	FirstTimePicker->Enabled  = false;
	FirstDatePicker->Format   = "''";
	FirstTimePicker->Format   = "''";
    BreakdownWLabel1->Caption = AnsiString();
    BreakdownWLabel2->Caption = AnsiString();
	SecondWEdit->Text         = AnsiString();
	SecondDatePicker->Date    = now;
	SecondTimePicker->Time    = now;
	SecondDatePicker->Checked = false;
	SecondTimePicker->Enabled = false;
	SecondDatePicker->Format  = "''";
	SecondTimePicker->Format  = "''";
    BreakdownWLabel3->Caption = AnsiString();
    BreakdownWLabel4->Caption = AnsiString();
	ChoseirituEdit->Text      = AnsiString();
	ChoseiEdit->Text          = AnsiString();
	JuryobikiEdit->Text       = AnsiString();
	ShomiEdit->Text           = AnsiString();
	PureNetLabel->Caption     = AnsiString();
	SuryoEdit->Text           = AnsiString();
	TaniCodeEdit->Text        = AnsiString();
	TaniLabel->Caption        = "______";
	TankaEdit->Text           = AnsiString();
	TankaEdit->Color          = TColor(0x00BEF4F5);
	KingakuEdit->Text         = AnsiString();
	ShohizeiEdit->Text        = AnsiString();
	BikoEdit->Text            = AnsiString();
	DefTankaLabel->Caption    = AnsiString();

	// 履歴クリア
	SetRireki(0);
}
//---------------------------------------------------------------------------
// 計量ID からレコードをを読み込み
bool __fastcall TMainForm::LoadFromID(int id)
{
	AnsiString sql;
	sql = " SELECT * FROM V_計量"
		  " WHERE"
		  "     計量ID = " + IntToStr(id) +
		  " AND"
		  "     完了区分 <> 9";                 // 論理削除は対象外

	if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
		return false;

	KeiryoDatePicker->Date       = IntToDate(ToInt(SET_TOP(keiryo_set_)["計量日"]));
	PlaceCombo->ItemIndex        = DM->FindPlaceIndexByID(ToInt(SET_TOP(keiryo_set_)["拠点ID"]));
	KeiryoNoEdit->Text           = ToInt(SET_TOP(keiryo_set_)["伝票No"]);

	car_id_                      = ToInt(SET_TOP(keiryo_set_)["車両ID"]);
	ShabanEdit->Text             = ToInt(SET_TOP(keiryo_set_)["車番"]);
	SharyoNameEdit->Text         = ToString(SET_TOP(keiryo_set_)["車両名称"]);

	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["得意先コード"]));
	TokuNameEdit->Text           = ToString(SET_TOP(keiryo_set_)["得意先名称"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目1コード"]));
	Komoku1NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["項目1名称"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["項目2コード"]));
	Komoku2NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["項目2名称"]);
	HinCodeEdit->Text            = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["品目コード"]));
	HinNameEdit->Text            = ToString(SET_TOP(keiryo_set_)["品目名称"]);
	HannyuCombo->ItemIndex       = ToInt(SET_TOP(keiryo_set_)["搬入出区分"]) - 1;

	Currency w1                  = ToCurrency(SET_TOP(keiryo_set_)["1回目重量"]);
	Currency w2                  = ToCurrency(SET_TOP(keiryo_set_)["2回目重量"]);

	TDateTime date;

	FirstWEdit->Text             = ZeroSuppress(w1);
	if (!SET_TOP(keiryo_set_)["計量日時1"].IsNull()){
		date = TDateTime(SET_TOP(keiryo_set_)["計量日時1"]);
		FirstDatePicker->Format    = "";
		FirstTimePicker->Format    = "HH:mm";

		FirstDatePicker->Date    = date;
		FirstDatePicker->Checked = true;
		FirstTimePicker->Time    = date;
		FirstTimePicker->Enabled = true;
	}else{
		date = Now();
		FirstDatePicker->Format    = "''";
		FirstTimePicker->Format    = "''";

		FirstDatePicker->Date    = date;
		FirstDatePicker->Checked = false;
		FirstTimePicker->Date    = date;
		FirstTimePicker->Enabled = false;
	}

	SecondWEdit->Text            = ZeroSuppress(w2);
	if (!SET_TOP(keiryo_set_)["計量日時2"].IsNull()){
		date = TDateTime(SET_TOP(keiryo_set_)["計量日時2"]);
		SecondDatePicker->Format    = "";
		SecondTimePicker->Format    = "HH:mm";

		SecondDatePicker->Date    = date;
		SecondDatePicker->Checked = true;
		SecondTimePicker->Time    = date;
		SecondTimePicker->Enabled = true;
	}else{
		date = Now();
		SecondDatePicker->Format    = "''";
		SecondTimePicker->Format    = "''";

		SecondDatePicker->Date    = date;
		SecondDatePicker->Checked = false;
		SecondTimePicker->Date    = date;
		SecondTimePicker->Enabled = false;
	}

	ChoseiEdit->Text             = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["調整重量"]));
	ChoseirituEdit->Text         = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["調整率"]));
	JuryobikiEdit->Text          = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["重量引き"]));
	ShomiEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["正味重量"]));

	PureNetLabel->Caption        = AnsiString(std::abs(w1 - w2)) + " kg";

	Currency tanka               = ToCurrency(SET_TOP(keiryo_set_)["単価"]);

	SuryoEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["数量"]));
	TaniCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["単位コード"]));
	TankaEdit->Text              = ZeroSuppress(tanka);
	KingakuEdit->Text            = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["金額"]));
	ShohizeiEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["伝票消費税額"]));

	Currency deftanka            = DM->GetTanka(ToInt(SET_TOP(keiryo_set_)["得意先ID"]), ToInt(SET_TOP(keiryo_set_)["品目ID"]),
										ToInt(SET_TOP(keiryo_set_)["項目1ID"]), ToInt(SET_TOP(keiryo_set_)["項目2ID"]), ToInt(SET_TOP(keiryo_set_)["単位ID"]));
	DefTankaLabel->Caption       = deftanka;

	TankaEdit->Color = tanka == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

	BikoEdit->Text               = ToString(SET_TOP(keiryo_set_)["備考"]);

	// 履歴表示
	SetRireki(car_id_);

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
	ShabanEdit->SetFocus();

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

    //SecondWEdit->Text = cur_weight_;
    SecondWEdit->Text = GetWeight();
    BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
    BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";

    CalcWeight();

    if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
        TokuCodeEdit->SetFocus();
    else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
        HinCodeEdit->SetFocus();
    else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
        Komoku1CodeEdit->SetFocus();
    else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
        Komoku2CodeEdit->SetFocus();
    else
        SecondWEdit->SetFocus();

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

    Currency w1  = StrToCurrDef(FirstWEdit->Text, 0);
    Currency w2  = StrToCurrDef(SecondWEdit->Text, 0);
    Currency net = StrToCurrDef(ShomiEdit->Text, 0);

    if (GetMode() == imFirst && w2 == 0){
        if (ActiveControl == FirstWEdit){
            if (Application->MessageBox("滞留車として登録しますか？", Caption.c_str(),
                            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) != IDYES){
            	SecondWEdit->SetFocus();
                return;
            }
        }else{
            if (Application->MessageBox("滞留車として登録しますか？", Caption.c_str(),
                            MB_YESNO | MB_ICONQUESTION) != IDYES)
                return;
        }
    }else{
        if (Application->MessageBox("登録しますか？", Caption.c_str(),
                        MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) != IDYES)
            return;
    }

    int toku_id, hin_id, item1_id, item2_id;
    AnsiString toku_name, hin_name, item1_name, item2_name;

    toku_id    = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "得意先ID"));
    toku_name  = TokuNameEdit->Text;
    hin_id     = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目ID"));
    hin_name   = HinNameEdit->Text;
    item1_id   = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    item1_name = Komoku1NameEdit->Text;
    item2_id   = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    item2_name = Komoku2NameEdit->Text;

    NsFieldSet fields;

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
        //DM->DBI.Update("M_車両", "車両ID", car_id_, new_car_fields_);

        car_id_ = DM->DBI.GetLastID();
    }

    fields.clear();
    fields
        << NsField("[行No]",         1)
        << NsField("[車両ID]",       car_id_)
        << NsField("[得意先ID]",     toku_id)
        << NsField("[得意先名称]",   toku_name)
        << NsField("[品目ID]",       hin_id)
        << NsField("[品目名称]",     hin_name)
        << NsField("[項目1ID]",      item1_id)
        << NsField("[項目1名称]",    item1_name)
        << NsField("[項目2ID]",      item2_id)
        << NsField("[項目2名称]",    item2_name)
        << NsField("[搬入出区分]",   HannyuCombo->ItemIndex + 1)
        << NsField("[備考]",         BikoEdit->Text)

        << NsField("[調整率]",       StrToCurrDef(ChoseirituEdit->Text, 0))
        << NsField("[調整重量]",     StrToCurrDef(ChoseiEdit->Text, 0))
        << NsField("[重量引き]",     StrToCurrDef(JuryobikiEdit->Text, 0))

        << NsField("[正味重量]",     net)
        << NsField("[数量]",         StrToCurrDef(SuryoEdit->Text, 0))
        << NsField("[単位ID]",       ToInt(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID")))
        << NsField("[単価]",         StrToCurrDef(TankaEdit->Text, 0))
        << NsField("[金額]",         KingakuEdit->Text.ToIntDef(0))
        << NsField("[消費税額]",     ShohizeiEdit->Text.ToIntDef(0))
        << NsField("[伝票消費税額]", ShohizeiEdit->Text.ToIntDef(0))
        << NsField("[更新日時]",     now)
        ;

    int cmp_kbn;
    bool print = false;                 // 印刷するかどうか（def: false）
    int print_id;                       // 印刷する計量ID
    bool create_tran_data = false;      // 売上データを作成するかどうか（def: false）
    int posted_id;                      // 売上データに移行する計量データID

    TDateTime dt1, dt2;
    if (FirstDatePicker->Checked)
        dt1 = CombineDateTime(FirstDatePicker->Date, FirstTimePicker->Time);
    else
        dt1 = now;
    if (SecondDatePicker->Checked)
        dt2 = CombineDateTime(SecondDatePicker->Date, SecondTimePicker->Time);
    else
        dt2 = now;

    try{
        DM->ADOConnection->BeginTrans();

        if (mode == imFirst){                   //***** 初回計量
            fields << NsField("[計量日]",    DateToInt(KeiryoDatePicker->Date))
                   << NsField("[拠点ID]",    GetPlaceID())
                   << NsField("[作成日時]",  now)
                   ;

            bool completed;

            if (w1 == 0 || w2 == 0){        // 1回目計量

                KeiryoNoEdit->Text = DM->GetTempNo(GetPlaceID());
                fields << NsField("[伝票No]",    KeiryoNoEdit->Text.ToInt())
                       << NsField("[1回目重量]", std::max(w1, w2))
                       << NsField("[1回目台貫重量1]", bdn_weight1_)
                       << NsField("[1回目台貫重量2]", bdn_weight2_)
                       << NsField("[計量日時1]", dt1)
                       << NsField("[完了区分]",  0)
                       ;
                completed = false;
            }else{                              // 全登録
                KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
                fields << NsField("[伝票No]",    KeiryoNoEdit->Text.ToInt())
                       << NsField("[1回目重量]", w1)
                       // << NsField("[計量日時1]", now)
                       << NsField("[1回目台貫重量1]", bdn_weight1_)
                       << NsField("[1回目台貫重量2]", bdn_weight2_)
                       << NsField("[2回目重量]", w2)
                       << NsField("[計量日時2]", dt2)
                       << NsField("[完了区分]",  1)
                       ;
                completed = true;
            }

            DM->DBI.Insert("D_計量", fields);

            if (completed){
				//Application->MessageBox("計量が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "登録しました (計量日=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";

                create_tran_data = true;

                posted_id = print_id = DM->DBI.GetLastID();

                if (AutoPrintCheck->Checked)
                    print = true;
                
            }else{
				//Application->MessageBox("滞留車として登録しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "滞留車を登録しました (車番=" + ShabanEdit->Text + ")";
			}

			Action1->Execute();

		}else if (mode == imSecond){            //***** 滞留車
			if (w1 > 0 && w2 > 0){
				// 重量が入っていれば、完了扱い
				KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
				fields << NsField("[計量日]",    DateToInt(KeiryoDatePicker->Date))
					   << NsField("[伝票No]",    KeiryoNoEdit->Text.ToInt())
					   << NsField("[1回目重量]", w1)
					   //<< NsField("[計量日時1]", now)
					   << NsField("[2回目重量]", w2)
                       << NsField("[2回目台貫重量1]", bdn_weight1_)
                       << NsField("[2回目台貫重量2]", bdn_weight2_)
					   << NsField("[計量日時2]", dt2)
					   << NsField("[完了区分]",  1)
					   ;
				cmp_kbn = 1;
			}else{
				fields << NsField("[1回目重量]", w1)
					   << NsField("[2回目重量]", w2)
					   ;
				if (w1 > 0 && ToCurrency(SET_TOP(keiryo_set_)["1回目重量"]) < 1)
					   fields << NsField("[計量日時1]", dt1);
				if (w2 > 0 && ToCurrency(SET_TOP(keiryo_set_)["2回目重量"]) < 1)
					   fields << NsField("[計量日時2]", dt2);
				cmp_kbn = 0;
			}

			DM->DBI.Update("D_計量", "計量ID", keiryo_id_, fields);

			if (cmp_kbn){
				//Application->MessageBox("計量が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "登録しました (計量日=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";
			}else{
				//Application->MessageBox("滞留情報の修正を行いました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "滞留車を修正しました (車番=" + ShabanEdit->Text + ")";
			}

			if (cmp_kbn){
				create_tran_data = true;
				posted_id = print_id = keiryo_id_;
			}

			if (cmp_kbn && AutoPrintCheck->Checked)
				print = true;

			Action1->Execute();

		}else if (mode == imMod){               //***** 修正
			cmp_kbn = ToInt(SET_TOP(keiryo_set_)["完了区分"]);
			TDateTime date1, date2;

			if (FirstDatePicker->Checked)
				fields << NsField("[計量日時1]", dt1);
			if (SecondDatePicker->Checked)
				fields << NsField("[計量日時2]", dt2);

			fields << NsField("[1回目重量]", w1)
				   << NsField("[2回目重量]", w2)
				   ;
			if (cmp_kbn == 1){  // すでに完了している場合
				int date = DateToInt(KeiryoDatePicker->Date);
				if (date != ToInt(SET_TOP(keiryo_set_)["計量日"])){
					ReplaceSetField(fields, "[計量日]", date);
					KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), date);
					ReplaceSetField(fields, "[伝票No]", KeiryoNoEdit->Text.ToInt());
				}
			}

			if (w1 > 0 && w2 > 0 && cmp_kbn == 0){
				int date = DateToInt(KeiryoDatePicker->Date);
				KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), date);
				ReplaceSetField(fields, "[伝票No]", KeiryoNoEdit->Text.ToInt());
				fields << NsField("[完了区分]",  1);
				cmp_kbn = 1;
			}

			DM->DBI.Update("D_計量", "計量ID", keiryo_id_, fields);

			if (cmp_kbn == 0){
				//Application->MessageBox("滞留データの修正を行いました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "滞留車を修正しました (車番=" + ShabanEdit->Text + ")";

			}else{
				//Application->MessageBox("登録しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "修正しました (計量日=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";

				posted_id = print_id = keiryo_id_;
				create_tran_data = ToInt(DM->CFG["取引データ作成"]) ? true : false;

				if (Application->MessageBox("修正した伝票を発行しますか？",
						Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES){
					print = true;
				}
            }

            // Action1->Execute();

        }

        if (GetMode() != imMod && DataDeleteCheck->Checked){
            create_tran_data = false;
        }

        if (mode == imMod && create_tran_data && ToInt(DM->CFG["取引データ作成"])){
            if (Application->MessageBox("取引データも修正しますか？", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
                create_tran_data = false;
        }
        
        if (create_tran_data){
            //////////////////////////////////////////////////////////////////////
            // 売上データ

            NsRecordSet set;
            AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(posted_id);
            DM->DBI.GetRecordSet(sql, set);

            fields.clear();
            fields << NsField("[取引日]",       SET_TOP(set)["計量日"])
                   << NsField("[拠点ID]",       SET_TOP(set)["拠点ID"])
                   << NsField("[計量ID]",       posted_id)
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
            if (!DM->DBI.IsExist("D_取引", "計量ID", posted_id)){
                fields
                	<< NsField("[伝票No]",    DM->GetTransNo(ToInt(SET_TOP(set)["拠点ID"]), ToInt(SET_TOP(set)["計量日"])))
                	<< NsField("[作成日時]",  now);
                DM->DBI.Insert("D_取引", fields);
            }else{
                DM->DBI.Update("D_取引", "計量ID", posted_id, fields);
            }
        }

		DM->ADOConnection->CommitTrans();

    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString msg = "登録時にエラーが発生しました - " + e.Message;
        Application->MessageBox(msg.c_str(), "登録エラー", MB_OK | MB_ICONWARNING);
        return;
    }

    if (print)
        Print(print_id);

    Q_Tairyu->Close();
    Q_Tairyu->Open();
}
//---------------------------------------------------------------------------
// 伝票発行
void __fastcall TMainForm::Print(int keiryo_id)
{
	int slip_type = ToInt(DM->CFG["伝票発行プリンタ"]);

	if (slip_type == 1){
		// レーザー
		if (!LaserSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;

	}else if (slip_type == 2){
		// ドット(連帳)
		if (!DotSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;

	}else if (slip_type == 3){
		// ドット(手差し)
		if (!ManualDotSlipForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;

	}else if (slip_type == 4){
		// サーマル
		QRChitForm->Print(keiryo_id);

	}else if (slip_type == 5){

        PrintKeiryoData(keiryo_id);

    }else{
        // nothing to do
    }

    if (GetMode() != imMod && DataDeleteCheck->Checked){
        NsFieldSet keys;
        keys << NsField("計量ID", keiryo_id);
		DM->DBI.Delete("D_計量", keys);
		Action1->Execute();
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
    Currency w1  = StrToCurrDef(FirstWEdit->Text, 0);
    Currency w2  = StrToCurrDef(SecondWEdit->Text, 0);
    Currency net = StrToCurrDef(ShomiEdit->Text, 0);
    Currency max = std::max(w1, w2);
	AnsiString msg;

	gross_limit_ = ToCurrency(DM->DBI.Lookup("M_車両", "車両ID", car_id_, "車両総重量"));
	net_limit_   = ToCurrency(DM->DBI.Lookup("M_車両", "車両ID", car_id_, "最大積載量"));

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
    if (GetMode() == imMod)
        return;

    int meig_id  = ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目ID"));

    TaniCodeEdit->Text = DM->GetKanzanCode(toku_id_, meig_id);
}
//---------------------------------------------------------------------------
// 正味重量の計算
void __fastcall TMainForm::CalcWeight()
{
    Currency w1, w2, net;

    try{
        w1 = StrToCurr(FirstWEdit->Text);
        w2 = StrToCurr(SecondWEdit->Text);
    }catch(...){
        ShomiEdit->Text       = AnsiString();
        PureNetLabel->Caption = AnsiString();
        SuryoEdit->Text       = AnsiString();
        return;
    }

    net = std::abs(w1 - w2);
    PureNetLabel->Caption = AnsiString(net) + " kg";

    if (ToBit(DM->CFG["調整使用区分"])){
        Currency coord, coord_ratio;

        coord       = ChoseiEdit->Text.ToIntDef(0);
        coord_ratio = StrToCurrDef(ChoseirituEdit->Text, 0) / 100;

        if (coord_ratio > 0){       // 調整率使用
            coord = ExtendedRound(net * coord_ratio, ToInt(DM->CFG["調整端数処理桁数"]),
                                                     ToInt(DM->CFG["調整端数処理区分"]));
            ChoseiEdit->Text = coord;
        }else{
            coord = 0;
            ChoseiEdit->Text = coord;
        }

        net -= int(coord);
    }

    if (ToBit(DM->CFG["重量引き使用区分"])){
        Currency reduc = StrToCurrDef(JuryobikiEdit->Text, 0);

        net -= reduc;
    }

    ShomiEdit->Text = net;

    if (TaniCodeEdit->Text.IsEmpty()){
        int default_code = ToInt(DM->CFG["標準単位"]);
        if (!default_code)
            default_code = 3;
        TaniCodeEdit->Text = default_code;
    }

    int meig_id  = ToInt(DM->DBI.Lookup("M_品目",   "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目ID"));
    //int item1_id = ToInt(DM->DBI.Lookup("M_項目1",  "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    //int item2_id = ToInt(DM->DBI.Lookup("M_項目2",  "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    int tani_id  = ToInt(DM->DBI.Lookup("M_単位",   "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID"));

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

    if (cnv_ratio == 0){
        quantity = ExtendedRound(net,             ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
    }else{
        quantity = ExtendedRound(net / cnv_ratio, ToInt(DM->CFG["換算端数処理桁数"]), cnv_div);
    }

    if (quantity > ToCurrency(DM->CFG["上限m3数量"]) && TaniCodeEdit->Text.ToIntDef(0) == 2){
        quantity = ToCurrency(DM->CFG["上限m3数量"]);
    }

    SuryoEdit->Text = quantity;

    CalcAmount();
}
//---------------------------------------------------------------------------
// 数量と金額の計算
void __fastcall TMainForm::CalcAmount(bool update)
{
    //if (GetMode() == imMod)
    //  return;

    int meig_id  = ToInt(DM->DBI.Lookup("M_品目",   "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目ID"));
    int item1_id = ToInt(DM->DBI.Lookup("M_項目1",  "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
    int item2_id = ToInt(DM->DBI.Lookup("M_項目2",  "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
    int tani_id  = ToInt(DM->DBI.Lookup("M_単位",   "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位ID"));

    Currency quantity = StrToCurrDef(SuryoEdit->Text, 0);

    if (!ToBit(DM->CFG["単価使用区分"])){
        // 単価有効時のデータをいじるかもしれないのでコメンタウト
        //TankaEdit->Text    = "0";
        //KingakuEdit->Text  = "0";
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency tanka    = StrToCurrDef(TankaEdit->Text, 0);
    Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
    if (GetMode() != imMod && update){
        tanka = deftanka;
    }
    DefTankaLabel->Caption = deftanka;
    TankaEdit->Color = tanka == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

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

    TankaEdit->Text    = tanka;
    KingakuEdit->Text  = amount;

    CalcSalesTax();
}
//---------------------------------------------------------------------------
// 消費税算出
void __fastcall TMainForm::CalcSalesTax()
{
    if (!ToBit(DM->CFG["単価使用区分"])){
        // 単価有効時のデータをいじるかもしれないのでコメンタウト
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));          // 消費税率

    ///// 消費税端数処理区分の取得
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
    /////

    int amount, tax;
    amount = KingakuEdit->Text.ToIntDef(0);
    tax    = ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div);
    ShohizeiEdit->Text = tax;
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

    if (Application->MessageBox("この伝票を削除しますか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    try{
        DM->ADOConnection->BeginTrans();

        NsFieldSet fields, keys;
        fields << NsField("[伝票No]",   DM->GetTempNo(GetPlaceID()))
               << NsField("[完了区分]", 9);

        keys   << NsField("[計量ID]",   keiryo_id_);

        DM->DBI.Update("D_計量", keys, fields);

        ///// 取引データも同処理

        // 計量データを削除した場合、関連する取引データも削除をする
        // ただし、品目IDと数量が一致するレコードのみ
        AnsiString sql;
        NsRecordSet set;
        sql = "SELECT * FROM D_計量 WHERE 計量ID = " + IntToStr(keiryo_id_);
        if (DM->DBI.GetRecordSet(sql, set)){

            fields.clear();
            keys.clear();

            fields << NsField("[伝票No]",   DM->GetTransTempNo(GetPlaceID()))
                   << NsField("[完了区分]", 9);

            keys   << NsField("[計量ID]",   keiryo_id_)
                   << NsField("[品目ID]",   ToInt(SET_TOP(set)["品目ID"]))
                   << NsField("[数量]",     ToCurrency(SET_TOP(set)["数量"]));
            DM->DBI.Update("D_取引", keys, fields);

            ///// 採番しなおし
            sql = " SELECT * FROM D_取引"
                  " WHERE 計量ID = " + IntToStr(keiryo_id_) +
                  "   AND 完了区分 = 1"
                  " ORDER BY 行No";
            if (DM->DBI.GetRecordSet(sql, set)){
                int lineno;
                for (unsigned int i = 0; i < set.size(); i++){
                    lineno = ToInt(set[i]["行No"]);

                    fields.clear();
                    keys.clear();

                    fields << NsField("[行No]",   i + 1)
                           << NsField("[計量ID]", Variant());
                    keys   << NsField("[取引ID]", ToInt(set[i]["取引ID"]));
                    DM->DBI.Update("D_取引", keys, fields);
                }
            }
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
    }else if (ActiveControl == HinCodeEdit){
        HinButton->Click();
    }else if (ActiveControl == Komoku1CodeEdit){
        Komoku1Button->Click();
    }else if (ActiveControl == Komoku2CodeEdit){
        Komoku2Button->Click();
    }else if (ActiveControl == TaniCodeEdit){
        TaniButton->Click();
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
	InputMode mode = GetMode();
	if (mode == imFirst){
		if (keiryo_count_ == 2 || keiryo_count_ == 0){
			//FirstWEdit->Text = cur_weight_;
			FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
			FirstWEdit->SetFocus();
		}else{
			//SecondWEdit->Text = cur_weight_;
			SecondWEdit->Text = GetWeight();
            BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
			SecondWEdit->SetFocus();
		}
	}else if (mode == imSecond){
		//SecondWEdit->Text = cur_weight_;
		SecondWEdit->Text = GetWeight();
        BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
        BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
		SecondWEdit->SetFocus();
	}

	CalcWeight();
}
//---------------------------------------------------------------------------
// F11 履歴呼出
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (ToString(rireki_set_[0]["計量日"]) == AnsiString())
		return;
	TokuCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["得意先コード"]));
	TokuNameEdit->Text = ToString(rireki_set_[rireki_id_]["得意先名称"]);
	HinCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["品目コード"]));
	HinNameEdit->Text = ToString(rireki_set_[rireki_id_]["品目名称"]);
	Komoku1CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["項目1コード"]));
	Komoku1NameEdit->Text = ToString(rireki_set_[rireki_id_]["項目1名称"]);
	Komoku2CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["項目2コード"]));
	Komoku2NameEdit->Text = ToString(rireki_set_[rireki_id_]["項目2名称"]);
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
// 品目検索
void __fastcall TMainForm::HinButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 品目コード, 品目略称, 搬入出区分名称 AS 搬入出, 取引区分名称 AS 取引区分 FROM V_品目 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 品目コード ";
    SearchForm->table_name = "V_品目";
    if (SearchForm->ShowModal() != mrOk)
        return;
    HinCodeEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
    HinCodeEdit->OnChange(NULL);
    HinCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// 単位検索
void __fastcall TMainForm::TaniButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 単位コード, 単位名称 FROM M_単位 ";
    SearchForm->orderby_sql = " ORDER BY 単位コード ";
    SearchForm->table_name = "M_単位";
    if (SearchForm->ShowModal() != mrOk)
        return;
    TaniCodeEdit->Text = SearchForm->Query->FieldByName("単位コード")->AsInteger;
    TaniCodeEdit->OnChange(NULL);
    TaniCodeEdit->SetFocus();
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

    TairyuGrid->RowCount = int(TairyuGrid->Height / 69);

    // 他のフォームのサイズもメインフォームに合わせる
    SearchForm->Height = MainForm->Height;
    DataListForm->Height = MainForm->Height - 33;
    DataListForm->Width  = MainForm->Width  - 24;
    DataListForm->Top  = MainForm->Top  + 16;
    DataListForm->Left = MainForm->Left + 12;
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
    AnsiString sql = "SELECT * FROM M_車両 WHERE 使用区分 = 1 AND 車番 = " + IntToStr(no);
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
        /*
        id   = ToInt(SET_TOP(set)["得意先ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_得意先", "得意先ID", id, "得意先コード"));
        if (code)
            TokuCodeEdit->Text = code;
        */

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

        id   = ToInt(SET_TOP(set)["品目ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_品目", "品目ID", id, "品目コード"));
        if (code)
            HinCodeEdit->Text = code;
    }

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

        /*
        id   = ToInt(SET_TOP(set)["項目1ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_項目1", "項目1ID", id, "項目1コード"));
        if (code)
            Komoku1CodeEdit->Text = code;
        */

        id   = ToInt(SET_TOP(set)["項目2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_項目2", "項目2ID", id, "項目2コード"));
        if (code)
            Komoku2CodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["品目ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_品目", "品目ID", id, "品目コード"));
        if (code)
            HinCodeEdit->Text = code;
    }

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

        /*
        id   = ToInt(SET_TOP(set)["項目2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_項目2", "項目2ID", id, "項目2コード"));
        if (code)
            Komoku2CodeEdit->Text = code;
        */

        id   = ToInt(SET_TOP(set)["品目ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_品目", "品目ID", id, "品目コード"));
        if (code)
            HinCodeEdit->Text = code;
    }

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// 品目コード->OnChange
void __fastcall TMainForm::HinCodeEditChange(TObject *Sender)
{
	int code = HinCodeEdit->Text.ToIntDef(0);
	if (!code){
		HinNameEdit->Text = AnsiString();
		return;
	}

	AnsiString sql;
	NsRecordSet set;

	if (code == ToInt(DM->CFG["品目搬入諸口コード"]) || code == ToInt(DM->CFG["品目搬出諸口コード"])){
		sql = "SELECT 搬入出区分 FROM M_品目 WHERE 使用区分 = 1 AND 品目コード = " + IntToStr(code);
		if (DM->DBI.GetRecordSet(sql, set)){
			HannyuCombo->ItemIndex = ToInt(SET_TOP(set)["搬入出区分"]) - 1;
		}else{
			Application->MessageBox("マスタの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
				Caption.c_str(), MB_OK | MB_ICONWARNING);
			return;
		}

		HinNameEdit->ReadOnly = false;
		HinNameEdit->TabStop  = true;
	}else{
		sql = "SELECT 品目名称, 搬入出区分 FROM M_品目 WHERE 使用区分 = 1 AND 品目コード = " + IntToStr(code);
		if (!DM->DBI.GetRecordSet(sql, set)){
			HinNameEdit->Text = AnsiString();
		}else{
			HinNameEdit->Text = ToString(SET_TOP(set)["品目名称"]);
			HannyuCombo->ItemIndex = ToInt(SET_TOP(set)["搬入出区分"]) - 1;
		}
		HinNameEdit->ReadOnly = true;
		HinNameEdit->TabStop  = false;
	}
}
//---------------------------------------------------------------------------
// 品目コード->OnExit
void __fastcall TMainForm::HinCodeEditExit(TObject *Sender)
{
	// 重量調整率
    NsRecordSet set;
	AnsiString sql;

	sql = "SELECT * FROM M_品目 WHERE 品目コード = " + IntToStr(HinCodeEdit->Text.ToIntDef(0));
	if (DM->DBI.GetRecordSet(sql, set)){
		Currency coord_ratio = ToCurrency(SET_TOP(set)["重量調整率"]);

		if (StrToCurrDef(ChoseirituEdit->Text, 0) != coord_ratio){
			if (GetMode() == imMod)
				if (Application->MessageBox(("重量調整率が異なります。上書きしますか？\r\n登録調整率：" + FormatFloat("#,##0.0#", coord_ratio) + "%").c_str(), "品目変更", MB_YESNO | MB_ICONEXCLAMATION) != IDYES)
					return;
			ChoseirituEdit->Text = ZeroSuppress(coord_ratio);
			CalcWeight();
		}
	}


	int id = 0;
	int code;

	sql = "SELECT * FROM M_項目関連 WHERE 項目番号 = 4 AND 項目ID = " + IntToStr(id);

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

		id   = ToInt(SET_TOP(set)["項目2ID"]);
		code = 0;
		if (id)
			code = ToInt(DM->DBI.Lookup("M_項目2", "項目2ID", id, "項目2コード"));
		if (code)
			Komoku2CodeEdit->Text = code;

        /*
        id   = ToInt(SET_TOP(set)["品目ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_品目", "品目ID", id, "品目コード"));
        if (code)
            HinCodeEdit->Text = code;
        */
    }

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// 単位コード->OnChange
void __fastcall TMainForm::TaniCodeEditChange(TObject *Sender)
{
    TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位名称", ""));
    TaniLabel->Caption = TaniNameEdit->Text;
}
//---------------------------------------------------------------------------
// 搬入出コンボ->OnKeyDown
void __fastcall TMainForm::HannyuComboKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_ESCAPE)
        HannyuCombo->ItemIndex = -1;
    if (Key == VK_UP || Key == VK_DOWN)
        Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    switch (ErrorEvent){
    case eeReceive:
		StatusBar->Panels->Items[1]->Text = "重量値受信1: 受信エラー";
		break;
	case eeConnect:
		StatusBar->Panels->Items[1]->Text = "重量値受信1: 接続エラー";
		break;
	case eeDisconnect:
		StatusBar->Panels->Items[1]->Text = "重量値受信1: 切断エラー";
		break;
	default:
        StatusBar->Panels->Items[1]->Text = "重量値受信1: ソケットエラー";
        break;
    };

    ClientSocket1->Close();

    ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket1Read(TObject *Sender,
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
    case 'S':   WeightPanel1->Font->Color = TColor(0x00CDF7A4);	break;
	case 'U':   WeightPanel1->Font->Color = TColor(0x008080FF);	break;
	case 'O':	WeightPanel1->Font->Color = clYellow;
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
		cur_weight1_ = 0;
		WeightPanel1->Caption = "OverLoad";
		return;
	}

	old_weight1_ = cur_weight1_;
	cur_weight1_ = tmp_weight;

	if (old_weight1_ < weighing_border_ && cur_weight1_ >= weighing_border_){
		PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
	}else if ((old_weight1_ >= weighing_border_) && (cur_weight1_ < weighing_border_)){
    	last_card_no_ = 0;
	}

	WeightPanel1->Caption = FormatFloat("###,##0", cur_weight1_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket2Error(TObject *Sender,
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

    ClientSocket1->Close();

    ErrorCode = 0;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket2Read(TObject *Sender,
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
    case 'S':   WeightPanel2->Font->Color = TColor(0x00CDF7A4);	break;
	case 'U':   WeightPanel2->Font->Color = TColor(0x008080FF);	break;
	case 'O':	WeightPanel2->Font->Color = clYellow;
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
		cur_weight2_ = 0;
		WeightPanel2->Caption = "OverLoad";
		return;
	}

	old_weight2_ = cur_weight2_;
	cur_weight2_ = tmp_weight;

	// [INI] Weighing::SoundBorder
/*
	int border = ToInt(DM->INI["Weighing::SoundBorder"]);

	if (old_weight_ < border && cur_weight_ >= border){
		// [INI] Weighing::SoundFile
		PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
	}
*/
    if (old_weight2_ < weighing_border_ && cur_weight2_ >= weighing_border_){
        PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
    }else if ((old_weight2_ >= weighing_border_) && (cur_weight2_ < weighing_border_)){
        last_card_no_ = 0;
    }

	WeightPanel2->Caption = FormatFloat("###,##0", cur_weight2_);
}
//---------------------------------------------------------------------------
/**
 * Implementation of NP3411 Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TMainForm::UMNiiAborted(TMessage& message)
{
	Application->MessageBox("外部プリンタの使用ができません", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("外部プリンタ", "通信停止", 2);

	delete printer_thread_;
	printer_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UMNiiStatus(TMessage& message)
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
           //NotifyForm->Notify("外部プリンタ: " + msg, true, 30000);
           StatusBar->Panels->Items[1]->Text = msg;
		}else{
           StatusBar->Panels->Items[1]->Text = "";
        }
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UMNiiReboot(TMessage& message)
{
	DM->Log("外部プリンタ", "再起動要求", 1);
}void __fastcall TMainForm::OnRFIDAborted(TMessage& message)
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
    	Application->MessageBox(("卓上RFIDリーダ:" + status).c_str(), "卓上RFID障害", MB_OK | MB_ICONSTOP);
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
    //if (cur_weight_ < weighing_border_){
    if (GetWeight() < weighing_border_){
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
    switch (Key){
    case VK_DOWN:
        if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_RETURN:
        if (ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_UP:
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

    ContinueWeighing    (Q_Tairyu->FieldByName("計量ID")->AsInteger);
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
// 重量、調整等、正味を計算する必要がある場合
void __fastcall TMainForm::OnWeightRecalc(TObject *Sender)
{
    CalcWeight();
}
//---------------------------------------------------------------------------
// 数量や金額等を計算する必要がある場合
void __fastcall TMainForm::OnAmountRecalc(TObject *Sender)
{
    CalcAmount();
}
//---------------------------------------------------------------------------
// 単価::OnExit
void __fastcall TMainForm::TankaEditExit(TObject *Sender)
{
    CalcAmount(false);
}
//---------------------------------------------------------------------------
// 消費税を計算する必要がある場合
void __fastcall TMainForm::OnSalesTaxRecalc(TObject *Sender)
{
    CalcSalesTax();
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
// 1回目重量の KeyDown
void __fastcall TMainForm::FirstWEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    if (GetMode() != imFirst){
    	SecondWEdit->SetFocus();
        return;
    }

    Currency w2 = StrToCurrDef(SecondWEdit->Text, 0);
    if (w2 != 0){           // 新規でも2回目重量が入力済ならここでは登録しない
    	SecondWEdit->SetFocus();
        return;
    }

    Action5->Execute();
}
//---------------------------------------------------------------------------
// 備考 KeyDown
void __fastcall TMainForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Key = 0;
        
    Action5->Execute();
}
//---------------------------------------------------------------------------
// トレーラ計量->Click
void __fastcall TMainForm::TrailerWeightButtonClick(TObject *Sender)
{
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
void __fastcall TMainForm::WeighingDateTimePickerChange(TObject *Sender)
{
    TDateTimePicker *DatePicker = dynamic_cast<TDateTimePicker *>(Sender);
    TDateTimePicker *TimePicker;

    TimePicker = DatePicker->Tag == 1 ? FirstTimePicker : SecondTimePicker;

    TimePicker->Enabled = DatePicker->Checked;

    if (DatePicker->Checked){
        DatePicker->Format    = "";
        TimePicker->Format    = "HH:mm";

        TDateTime now(Now());
        DatePicker->Date = now;
        TimePicker->Time = now;
    }else{
        DatePicker->Format    = "''";
        TimePicker->Format    = "''";
    }
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

    if (ActiveControl != ShabanEdit)
        return;

    if (GetMode() == imMod){
        TokuCodeEdit->SetFocus();
    }else{

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;

        if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
            TokuCodeEdit->SetFocus();
        else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
            HinCodeEdit->SetFocus();
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();
        else if (FirstWEdit->Text.IsEmpty())
            FirstWEdit->SetFocus();
        else
            SecondWEdit->SetFocus();

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
			   //<< NsField("[車両名称]", name)
			   //<< NsField("[更新日時]", now)
			   //<< NsField("[作成日時]", now)
			   ;

		// DM->DBI.Insert("M_車両", new_car_fields_);

		SharyoNameEdit->Text = name;

		//car_id_ = DM->DBI.GetLastID();

		keiryo_count_ = 2;

		if (GetMode() == imFirst){
			//FirstWEdit->Text = cur_weight_;
			FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
        }

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

		if (GetMode() == imFirst){
			//FirstWEdit->Text = cur_weight_;
            FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
        }

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
			if (HinCodeEdit->Text.IsEmpty())
				HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["品目コード"]));

			if (ToCurrency(SET_TOP(set)["空車重量"]) > 0){
				keiryo_count_ = 1;
				FirstWEdit->Text = ToCurrency(SET_TOP(set)["空車重量"]);
			}else{
				keiryo_count_ = 2;
			}
			gross_limit_ = ToCurrency(SET_TOP(set)["車両総重量"]);
			net_limit_   = ToCurrency(SET_TOP(set)["最大積載量"]);

			SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);

			if (keiryo_count_ == 2){
				//FirstWEdit->Text = cur_weight_;
				FirstWEdit->Text = GetWeight();
                BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
			}else{
				//SecondWEdit->Text = cur_weight_;
				SecondWEdit->Text = GetWeight();
                BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
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

    if (ToInt(SET_TOP(car_set)["使用区分"]) != 1){
	    StatusBar->Panels->Items[1]->Text = "RFID: 使用しない車両情報";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return false;
    }

	Action1->Execute();

    car_id_         = ToInt(SET_TOP(car_set)["車両ID"]);
	int remained_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);

	if (!remained_id){		// 初回計量
		ShabanEdit->Text      = ZeroSuppress(ToInt(SET_TOP(car_set)["車番"]));
		TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(car_set)["得意先コード"]));
		HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(car_set)["品目コード"]));
		Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(car_set)["項目1コード"]));
		Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(car_set)["項目2コード"]));

		if (ToCurrency(SET_TOP(car_set)["空車重量"]) > 0){
			keiryo_count_ = 1;
			FirstWEdit->Text = ToCurrency(SET_TOP(car_set)["空車重量"]);
		}else{
			keiryo_count_ = 2;
		}

		SharyoNameEdit->Text = ToString(SET_TOP(car_set)["車両名称"]);

		if (keiryo_count_ == 2){
			//FirstWEdit->Text = cur_weight_;
			FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
		}else{
			//SecondWEdit->Text = cur_weight_;
			SecondWEdit->Text = GetWeight();
            BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
        }

		CalcWeight();

		TNotifyEvent OnExit = ShabanEdit->OnExit;
		ShabanEdit->OnExit  = 0;

		if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
			TokuCodeEdit->SetFocus();
		else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
			HinCodeEdit->SetFocus();
		else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
			Komoku1CodeEdit->SetFocus();
		else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
			Komoku2CodeEdit->SetFocus();
		else if (keiryo_count_ == 2)
			FirstWEdit->SetFocus();
		else if (keiryo_count_ == 1)
			SecondWEdit->SetFocus();

		ShabanEdit->OnExit  = OnExit;

	}else{					// 滞留車
		ContinueWeighing(remained_id);
	}

	gross_limit_    = ToCurrency(SET_TOP(car_set)["車両総重量"]);
	net_limit_      = ToCurrency(SET_TOP(car_set)["最大積載量"]);
	// 履歴を表示する
	SetRireki(car_id_);

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
	SharyoCheck();
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
            if (HinCodeEdit->Text.IsEmpty())
                HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["品目コード"]));

            if (ToCurrency(SET_TOP(set)["空車重量"]) > 0){
                keiryo_count_ = 1;
                FirstWEdit->Text = ToCurrency(SET_TOP(set)["空車重量"]);
            }else{
                keiryo_count_ = 2;
            }
            gross_limit_ = ToCurrency(SET_TOP(set)["車両総重量"]);
            net_limit_   = ToCurrency(SET_TOP(set)["最大積載量"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);

            if (keiryo_count_ == 2){
                //FirstWEdit->Text = cur_weight_;
                FirstWEdit->Text = GetWeight();
                BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
            }else{
                //SecondWEdit->Text = cur_weight_;
                SecondWEdit->Text = GetWeight();
                BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
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
	RirekiHinCodeLabel->Caption     = ToString(rireki_set_[rireki_id_]["品目コード"]);
	RirekiHinNameLabel->Caption     = ToString(rireki_set_[rireki_id_]["品目名称"]);
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
	RirekiHinCodeLabel->Caption     = AnsiString();
	RirekiHinNameLabel->Caption     = AnsiString();
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
	if (((TCobEdit *)Sender)->Hint == AnsiString())
		return;
	StatusBar->Panels->Items[2]->Text = ((TCobEdit *)Sender)->Hint;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintKeiryoData(int keiryo_id)
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

void __fastcall TMainForm::PrintCopy(int keiryo_id)
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
void __fastcall TMainForm::SelectScale1(TObject *Sender)
{
    FWBasePanel->Color = TColor(0x008AF8FD);
    FWNamePanel->Color = TColor(0x008AF8FD);
    SWBasePanel->Color = clBtnFace;
    SWNamePanel->Color = clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectScale2(TObject *Sender)
{
    FWBasePanel->Color = clBtnFace;
    FWNamePanel->Color = clBtnFace;
    SWBasePanel->Color = TColor(0x008AF8FD);
    SWNamePanel->Color = TColor(0x008AF8FD);
}
//---------------------------------------------------------------------------

