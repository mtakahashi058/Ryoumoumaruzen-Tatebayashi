//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DataListFrm.h"
#include "MainFrm.h"
#include <mmsystem.h>
#include "ShabanSanshoFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "StrCGrid"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner), trans_id_(0)
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

        if (!Grid){
            TWinControl *wc;
            for (int i = 0; i < DataListForm->FilterPanel->ControlCount; i++){
                wc = dynamic_cast<TWinControl *>(DataListForm->FilterPanel->Controls[i]);
                if (!wc)
                    continue;
                if (wc->Handle == Msg.hwnd){
                    Grid = DataListForm->DBGrid;
                    break;
                }
            }
        }
        if (!Grid){
            TWinControl *wc;
            for (int i = 0; i < SearchForm->FilterPanel->ControlCount; i++){
                wc = dynamic_cast<TWinControl *>(SearchForm->FilterPanel->Controls[i]);
                if (!wc)
                    continue;
                if (wc->Handle == Msg.hwnd){
                    Grid = SearchForm->DBGrid;
                    break;
                }
            }
        }

        if (!Grid)
            return;

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

	Resize();

    // DetailGrid の設定
    DetailGrid->ColWidths[0] = 28;
    DetailGrid->Cells[0][1] = "1";
    DetailGrid->Cells[0][2] = "2";
    DetailGrid->Cells[0][3] = "3";
    DetailGrid->Cells[0][4] = "4";
    DetailGrid->Cells[0][5] = "5";
    DetailGrid->Cells[0][6] = "6";
    DetailGrid->ColWidths[1] = 48;
    DetailGrid->ColWidths[2] = 58;
    DetailGrid->ColWidths[3] = 282;
    DetailGrid->ColWidths[4] = 64;
    DetailGrid->ColWidths[5] = 42;
    DetailGrid->ColWidths[6] = 64;
    DetailGrid->ColWidths[7] = 97;
    DetailGrid->ColWidths[8] = 97;
    DetailGrid->ColWidths[9] = 154;

    KeiryoGrid->ColWidths[0] = 28;
    KeiryoGrid->Cells[0][1] = "1";
    KeiryoGrid->Cells[0][2] = "2";
    KeiryoGrid->Cells[0][3] = "3";
    KeiryoGrid->Cells[0][4] = "4";
    KeiryoGrid->Cells[0][5] = "5";
    KeiryoGrid->Cells[0][6] = "6";
    KeiryoGrid->ColWidths[1] = 58;

    int left = 2;
    for (int i = 0; i < 8; i++)
        left += DetailGrid->ColWidths[i] + 1;
    TankaUpdateButton->Left = left - TankaUpdateButton->Width - 1;

    DefTankaGrid->Cells[0][1] = "1";
    DefTankaGrid->Cells[0][2] = "2";
    DefTankaGrid->Cells[0][3] = "3";
    DefTankaGrid->Cells[0][4] = "4";
    DefTankaGrid->Cells[0][5] = "5";
    DefTankaGrid->Cells[0][6] = "6";

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
//	HinButton->Caption       = ToString(DM->CFG["品目マスタ名称"]);

	if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
		Komoku1Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
		Komoku2Panel->Visible         = false;
	}

/** deleted
	if (!ToBit(DM->CFG["調整使用区分"])){
		ChoseiPanel->Visible          = false;
	}
	if (!ToBit(DM->CFG["重量引き使用区分"])){
		JuryobikiPanel->Visible       = false;
	}
*/

	PlaceCombo->Items->Clear();
	if (!DM->DBI.GetRecordSet("SELECT 拠点ID, 拠点コード, 拠点名称 FROM M_拠点", kyoten_set_)){
		Application->MessageBox("拠点マスタが設定されていません。入力前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	for (unsigned int i = 0; i < kyoten_set_.size(); i++){
		PlaceCombo->Items->Append(ToString(kyoten_set_[i]["拠点名称"]));
	}

	int wild_code;

	wild_code = ToInt(DM->CFG["得意先諸口コード"]);
	if (wild_code && !DM->DBI.IsExist("M_得意先", "得意先コード", wild_code)){
		Application->MessageBox("得意先諸口コードが得意先マスタに登録されていません。入力前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["品目搬入諸口コード"]);
	if (wild_code && !DM->DBI.IsExist("M_品目", "品目コード", wild_code)){
		Application->MessageBox("品目搬入諸口コードが品目マスタに登録されていません。入力前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["品目搬出諸口コード"]);
	if (wild_code && !DM->DBI.IsExist("M_品目", "品目コード", wild_code)){
		Application->MessageBox("品目搬出諸口コードが品目マスタに登録されていません。入力前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["項目1諸口コード"]);
	if (wild_code && !DM->DBI.IsExist("M_項目1", "項目1コード", wild_code)){
		Application->MessageBox("項目1諸口コードが項目1マスタに登録されていません。入力前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["項目2諸口コード"]);
	if (wild_code && !DM->DBI.IsExist("M_項目2", "項目2コード", wild_code)){
		Application->MessageBox("項目2諸口コードが項目2マスタに登録されていません。入力前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

}
//---------------------------------------------------------------------------
// 拠点コンボボックスから ID を取得
int __fastcall TMainForm::GetPlaceID()
{
	return ToInt(kyoten_set_[PlaceCombo->ItemIndex]["拠点ID"]);
}
//---------------------------------------------------------------------------
// 拠点コンボボックスから拠点名を取得
AnsiString __fastcall TMainForm::GetPlaceText()
{
    return PlaceCombo->Items->Strings[PlaceCombo->ItemIndex];
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
    trans_id_  = 0;
    trans_set_.clear();
    keiryo_id_ = 0;

	toku_id_      = 0;
	toku_rec_.clear();

	car_id_       = 0;

    total_zei_    = 0;
    deftanka_table_.clear();
    zei_table_.clear();
    sundry_table_.clear();

    TDateTime now(Now());
	int place_code  = ToInt(DM->INI["Default::PlaceCode"]);
    int place_index = 0;
    for (NsRecordSet::iterator i = kyoten_set_.begin(); i != kyoten_set_.end(); i++){
		if (ToInt((i->second)["拠点コード"]) == place_code){
			place_index = i->first;
        }
	}
	PlaceCombo->ItemIndex = place_index;

	DatePicker->Date          = now;
	NoEdit->Text              = AnsiString();
	ShabanEdit->Text          = AnsiString();
	ShabanEdit->OnChange(NULL);
	TokuCodeEdit->Text        = AnsiString();
	TokuNameEdit->Text        = AnsiString();
	Komoku1CodeEdit->Text     = AnsiString();
	Komoku1NameEdit->Text     = AnsiString();
	Komoku2CodeEdit->Text     = AnsiString();
	Komoku2NameEdit->Text     = AnsiString();
	BikoEdit->Text            = AnsiString();

	KeiryoDate->Text          = AnsiString();
	KeiryoNo->Text            = AnsiString();

    DetailGrid->Col = 1;
    DetailGrid->Row = 1;

    for (int i = 0; i < 6; i++){
        DetailGrid->Cells[1][i + 1] = AnsiString();
        DetailGrid->Cells[2][i + 1] = AnsiString();
        DetailGrid->Cells[3][i + 1] = AnsiString();
        DetailGrid->Cells[4][i + 1] = AnsiString();
        DetailGrid->Cells[5][i + 1] = AnsiString();
        DetailGrid->Cells[6][i + 1] = AnsiString();
        DetailGrid->Cells[7][i + 1] = AnsiString();
        DetailGrid->Cells[8][i + 1] = AnsiString();
        DetailGrid->Cells[9][i + 1] = AnsiString();

        KeiryoGrid->Cells[1][i + 1] = AnsiString();
        KeiryoGrid->Cells[2][i + 1] = AnsiString();
        KeiryoGrid->Cells[3][i + 1] = AnsiString();
        KeiryoGrid->Cells[4][i + 1] = AnsiString();
        KeiryoGrid->Cells[5][i + 1] = AnsiString();
        KeiryoGrid->Cells[6][i + 1] = AnsiString();
        KeiryoGrid->Cells[7][i + 1] = AnsiString();
        KeiryoGrid->Cells[8][i + 1] = AnsiString();
    }
    DetailGrid->Col = 2;
    DetailGrid->Row = 1;
    DetailGrid->Invalidate();

    DefTankaGrid->Col = 1;
    DefTankaGrid->Row = 1;
    for (int i = 0; i < 6; i++){
        DefTankaGrid->Cells[1][i + 1] = AnsiString();
    }
    DefTankaGrid->Col = 1;
    DefTankaGrid->Row = 2;

    PageControl->ActivePage = TransSheet;

    UAmountLabel->Caption      = AnsiString();
    UTotalZeiLabel->Caption    = AnsiString();
    SAmountLabel->Caption      = AnsiString();
    STotalZeiLabel->Caption    = AnsiString();
}
//---------------------------------------------------------------------------
// 取引ID からレコードをを読み込み
bool __fastcall TMainForm::LoadFromID(int id)
{
	AnsiString sql;
    NsRecordSet set;
	sql = " SELECT 取引日, 拠点ID, 伝票No FROM V_取引"
		  " WHERE"
		  " 	取引ID = " + IntToStr(id) +
		  " AND"
		  " 	完了区分 <> 9";					// 論理削除は対象外
    if (!DM->DBI.GetRecordSet(sql, set))
        return false;

    sql = " SELECT * FROM V_取引"
          " WHERE"
          "     取引日 = " + ToString(SET_TOP(set)["取引日"]) +
          " AND"
          "     拠点ID = " + ToString(SET_TOP(set)["拠点ID"]) +
          " AND"
          "     伝票No = " + ToString(SET_TOP(set)["伝票No"]) +
          " AND"
          "     完了区分 <> 9"
          " ORDER BY 行No";
	if (!DM->DBI.GetRecordSet(sql, trans_set_))
		return false;

	DatePicker->Date             = IntToDate(ToInt(SET_TOP(trans_set_)["取引日"]));
	NoEdit->Text                 = ToInt(SET_TOP(trans_set_)["伝票No"]);

	car_id_                      = ToInt(SET_TOP(trans_set_)["車両ID"]);
	ShabanEdit->Text             = ZeroSuppress(ToInt(SET_TOP(trans_set_)["車番"]));
	SharyoNameEdit->Text         = ToString(SET_TOP(trans_set_)["車両名称"]);

	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(trans_set_)["得意先コード"]));
    TokuNameEdit->Text           = ToString(SET_TOP(trans_set_)["得意先名称"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(trans_set_)["項目1コード"]));
    Komoku1NameEdit->Text        = ToString(SET_TOP(trans_set_)["項目1名称"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(trans_set_)["項目2コード"]));
    Komoku2NameEdit->Text        = ToString(SET_TOP(trans_set_)["項目2名称"]);

	BikoEdit->Text               = ToString(SET_TOP(trans_set_)["備考"]);

    keiryo_id_ = ToInt(SET_TOP(trans_set_)["計量ID"]);

    if (keiryo_id_){
        int date, place_id, no;
        if (!DM->GetKeiryoKey(keiryo_id_, date, place_id, no)){
            Application->MessageBox("計量データの読み込みに失敗しました", "取引データ読み込み", MB_OK | MB_ICONWARNING);
        }else{
            sql = " SELECT * FROM V_計量"
                  " WHERE 計量日 = " + IntToStr(date) +
                  "   AND 拠点ID = " + IntToStr(place_id) +
                  "   AND 伝票No = " + IntToStr(no);
            DM->DBI.GetRecordSet(sql, set);

            KeiryoDate->Text = IntToDate(ToInt(SET_TOP(set)["計量日"])).FormatString("yyyy/mm/dd");
            KeiryoNo->Text   = ToInt(SET_TOP(set)["伝票No"]);

            for (unsigned int i = 0; i < set.size(); i++){
                KeiryoGrid->Cells[1][i + 1] = ToInt(set[i]["品目コード"]);
                KeiryoGrid->Cells[2][i + 1] = ToString(set[i]["品目名称"]);
                KeiryoGrid->Cells[3][i + 1] = ToCurrency(set[i]["数量"]);
                KeiryoGrid->Cells[4][i + 1] = ToInt(set[i]["単位コード"]);
                KeiryoGrid->Cells[5][i + 1] = ToString(set[i]["単位マスタ名称"]);
                KeiryoGrid->Cells[6][i + 1] = ToCurrency(set[i]["単価"]);
                KeiryoGrid->Cells[7][i + 1] = ToInt(set[i]["金額"]);
                KeiryoGrid->Cells[8][i + 1] = ToString(set[i]["明細備考"]);
            }
        }
    }

    int row;
    int code;
    for (NsRecordSet::iterator i = trans_set_.begin(); i != trans_set_.end(); i++){
        row = ToInt(i->second["行No"]);
        if (row < 1 || row > 6)
            continue;

        code = ToInt(i->second["品目コード"]);

        if (code == ToInt(DM->CFG["品目搬入諸口コード"]) || code == ToInt(DM->CFG["品目搬出諸口コード"])){
            sundry_table_[row] = true;
        }else{
            sundry_table_[row] = false;
        }

        DetailGrid->Cells[1][row] = ToString(i->second["取引区分名称"]);
        DetailGrid->Cells[2][row] = code;
        DetailGrid->Cells[3][row] = ToString(i->second["品目名称"]);
        DetailGrid->Cells[4][row] = ToCurrency(i->second["数量"]);
        DetailGrid->Cells[5][row] = ToInt(i->second["単位コード"]);
        DetailGrid->Cells[6][row] = ToString(i->second["単位マスタ名称"]);
        DetailGrid->Cells[7][row] = ToCurrency(i->second["単価"]);
        DetailGrid->Cells[8][row] = ToInt(i->second["金額"]);
        DetailGrid->Cells[9][row] = ToString(i->second["明細備考"]);

        Currency deftanka = DM->GetTanka(ToInt(i->second["得意先ID"]), ToInt(i->second["品目ID"]),
                            ToInt(i->second["項目1ID"]), ToInt(i->second["項目2ID"]), ToInt(i->second["単位ID"]));
        deftanka_table_[row] = std::abs(ToCurrency(i->second["単価"]) - deftanka);
        DefTankaGrid->Cells[1][row] = deftanka;
    }

    CalcTotal();

	return true;
}
//---------------------------------------------------------------------------
// 取引登録
void __fastcall TMainForm::PostRecords()
{
	InputMode mode = GetMode();

	TDateTime now(Now());
	int place_id = GetPlaceID();

	if (!ValidateForm())
		return;

    if (Application->MessageBox("登録しますか？", Caption.c_str(),
	    	MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) != IDYES)
		return;

    if (mode != imMod){
        NoEdit->Text = DM->GetTransNo(place_id, DateToInt(DatePicker->Date));
    }

    int date, no;
	int toku_id, unpan_id, hin_code, hin_id, item1_id, item2_id;
	AnsiString toku_name, hin_name, item1_name, item2_name;

    date       = DateToInt(DatePicker->Date);
    no         = NoEdit->Text.ToIntDef(0);

	toku_id    = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "得意先ID"));
	toku_name  = TokuNameEdit->Text;
    // 手入力対応
    if (Komoku1CodeEdit->Text.ToIntDef(0) == 0){
        item1_id   = 0;
        item1_name = Komoku1NameEdit->Text;
    }else{
   		item1_id   = ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0), "項目1ID"));
   		item1_name = Komoku1NameEdit->Text;
    }
	item2_id   = ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0), "項目2ID"));
	item2_name = Komoku2NameEdit->Text;


    DM->ADOConnection->BeginTrans();

    try{
        bool create = (trans_id_ < 1);

        if (!create){
        	AnsiString sql;
            NsRecordSet set;
    	    sql = " SELECT 取引日, 拠点ID, 伝票No FROM D_取引"
        		  " WHERE"
        		  " 	取引ID = " + IntToStr(trans_id_);
            if (!DM->DBI.GetRecordSet(sql, set))
                throw Exception("修正データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。");

            NsFieldSet keys;
            keys << NsField("[取引日]", SET_TOP(set)["取引日"])
                 << NsField("[拠点ID]", SET_TOP(set)["拠点ID"])
                 << NsField("[伝票No]", SET_TOP(set)["伝票No"])
                 ;
            DM->DBI.Delete("D_取引", keys);
        }

        NsFieldSet fields;
        NsRecordSet hin_set;
        int row = 1;
        bool hin_exists;

        for (int i = 1; i < DetailGrid->RowCount; i++){
            hin_code = DetailGrid->Cells[2][i].ToIntDef(0);
            hin_name = DetailGrid->Cells[3][i];
            hin_exists = DM->DBI.GetRecordSet("SELECT * FROM M_品目 WHERE 品目コード = " + IntToStr(hin_code), hin_set);
            if (!hin_exists && DetailGrid->Cells[4][i].ToIntDef(0) == 0)
                continue;

            fields.clear();
            fields
                << NsField("[取引日]",           date)
                << NsField("[拠点ID]",           place_id)
                << NsField("[伝票No]",           no)
                << NsField("[取引区分]",         ToInt(SET_TOP(hin_set)["取引区分"]))
                << NsField("[計量ID]",           keiryo_id_)
        		<< NsField("[車両ID]",           car_id_)
        		<< NsField("[得意先ID]",         toku_id)
        		<< NsField("[得意先名称]",       toku_name)
        		<< NsField("[項目1ID]",          item1_id)
        		<< NsField("[項目1名称]",        item1_name)
        		<< NsField("[項目2ID]",          item2_id)
        		<< NsField("[項目2名称]",        item2_name)
        		<< NsField("[備考]",             BikoEdit->Text)
                << NsField("[伝票消費税額]",     total_zei_)
                << NsField("[行No]",             row)
                << NsField("[品目ID]",           ToInt(SET_TOP(hin_set)["品目ID"]))
                //<< NsField("[品目名称]",         ToString(SET_TOP(hin_set)["品目名称"]))
                << NsField("[品目名称]",         hin_name)

                << NsField("[数量]",             StrToCurrDef(DetailGrid->Cells[4][i], 0))
                << NsField("[単位ID]",           ToInt(DM->DBI.Lookup("M_単位", "単位コード", DetailGrid->Cells[5][i].ToIntDef(0), "単位ID", "")))
                << NsField("[単価]",             StrToCurrDef(DetailGrid->Cells[7][i], 0))
                << NsField("[金額]",             DetailGrid->Cells[8][i].ToIntDef(0))
                << NsField("[消費税額]",         zei_table_[i])
                << NsField("[明細備考]",         DetailGrid->Cells[9][i])

                << NsField("[完了区分]",         1)
        		<< NsField("[更新日時]",         now)
                << NsField("[作成日時]",         now);
                ;

            DM->DBI.Insert("D_取引", fields);

            row++;
        }

        DM->ADOConnection->CommitTrans();
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        Application->MessageBoxA(AnsiString("登録時にエラーが発生しました - " + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
        return;
    }

    bool print    = false;
    int  print_id = 0;

    if (print)
        Print(print_id);

    Application->MessageBox("登録しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    if (mode == imNew)
        Action1->Execute();
    else
        ShabanEdit->SetFocus();

}
//---------------------------------------------------------------------------
// 伝票発行
void __fastcall TMainForm::Print(int record_id)
{
/*
	if (!B5SlipPrintForm->Print(record_id))
		return;
*/
}
//---------------------------------------------------------------------------
// 各項目の値チェック
bool __fastcall TMainForm::ValidateForm()
{
	AnsiString sql;
	NsRecordSet set;
	int n;

	if (car_id_ < 1){
		//Application->MessageBox("車両の選択が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
		//ShabanEdit->SetFocus();
		//return false;
        return true;
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

	return true;
}
//---------------------------------------------------------------------------
// モード関連
//---------------------------------------------------------------------------
// モード設定
void __fastcall TMainForm::SetMode(InputMode mode)
{
	switch (mode){
	case imNew: 		// 新規
		ModePanel->Caption = "新規";
		ModePanel->Color   = TColor(0x00FDD8C6);

		NoEdit->ReadOnly = false;
		break;
	case imMod:			// 修正
		ModePanel->Caption = "修正";
		ModePanel->Color   = TColor(0x00CEF4D0);

		NoEdit->ReadOnly = true;
		break;
	}
}
//---------------------------------------------------------------------------
// モード取得
InputMode __fastcall TMainForm::GetMode()
{
	if (ModePanel->Caption == "新規")
		return imNew;
	else if (ModePanel->Caption == "修正")
		return imMod;
	return imNew;
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
	ClearForm();

	SetMode(imNew);

	NoEdit->Text = DM->GetTransNo(GetPlaceID(), DateToInt(DatePicker->Date));

	ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F2 修正
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	ClearForm();
	SetMode(imMod);

	// 同一拠点の最終レコードを取得
	trans_id_ = DM->GetLastTransID(GetPlaceID());

	if (trans_id_ < 1){
		Application->MessageBox("修正するデータはありません",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	if (!LoadFromID(trans_id_)){
		Application->MessageBox("データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
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

	if (mode == imNew || trans_id_ < 1)
		return;

	if (Application->MessageBox("この伝票を削除しますか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
		return;

    try{
        DM->ADOConnection->BeginTrans();

        AnsiString sql;
        NsRecordSet set;
    	sql = " SELECT 取引日, 拠点ID, 伝票No FROM D_取引"
        	  " WHERE"
        	  " 	取引ID = " + IntToStr(trans_id_);
        if (!DM->DBI.GetRecordSet(sql, set))
            throw Exception("修正データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。");

        int no = DM->GetTempNo(GetPlaceID());

    	NsFieldSet fields, keys;
    	fields << NsField("[伝票No]",   no)
    		   << NsField("[完了区分]", 9);

        keys << NsField("[取引日]", SET_TOP(set)["取引日"])
             << NsField("[拠点ID]", SET_TOP(set)["拠点ID"])
             << NsField("[伝票No]", SET_TOP(set)["伝票No"]);

    	DM->DBI.Update("D_取引", keys, fields);

        DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

		AnsiString msg = "削除時にエラーが発生しました - " + e.Message;
		Application->MessageBox(msg.c_str(), "削除エラー", MB_OK | MB_ICONWARNING);
		return;
	}

	Action2->Execute();
}
//---------------------------------------------------------------------------
// F4 参照
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
    if (ActiveControl == TokuCodeEdit){
        TokuButton->Click();
    }else if (ActiveControl == Komoku1CodeEdit){
        Komoku1Button->Click();
    }else if (ActiveControl == Komoku2CodeEdit){
        Komoku2Button->Click();
    }else if (ActiveControl == DetailGrid){
        if (DetailGrid->Col == 2){
        	SearchForm->Top = MainForm->Top;
        	SearchForm->Left = MainForm->Left + 450;
            SearchForm->based_sql = "SELECT 品目コード, 品目略称, 搬入出区分名称 AS 搬入出, 取引区分名称 AS 取引区分 FROM V_品目 WHERE 使用区分 = 1";
        	SearchForm->orderby_sql = " ORDER BY 品目コード ";
        	SearchForm->table_name = "V_品目";
            SearchForm->list_->CommaText = " 品目コード,品目略称,品目カナ";
        	if (SearchForm->ShowModal() != mrOk)
        		return;
            DetailGrid->Cells[2][DetailGrid->Row] = SearchForm->Query->FieldByName("品目コード")->AsInteger;
        }else if (DetailGrid->Col == 5){
        	SearchForm->Top = MainForm->Top;
        	SearchForm->Left = MainForm->Left + 450;
        	SearchForm->based_sql = "SELECT 単位コード, 単位名称 FROM M_単位 ";
        	SearchForm->orderby_sql = " ORDER BY 単位コード ";
        	SearchForm->table_name = "M_単位";
            SearchForm->list_->CommaText = " 単位コード,単位名称";
        	if (SearchForm->ShowModal() != mrOk)
        		return;
            DetailGrid->Cells[5][DetailGrid->Row] = SearchForm->Query->FieldByName("単位コード")->AsInteger;
        }
    }
}
//---------------------------------------------------------------------------
// F5 登録
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
	PostRecords();
}
//---------------------------------------------------------------------------
// F6 前へ
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
	int id;

	if (trans_id_){	// 修正、または滞留状態
		id = DM->GetPrevTransID(GetPlaceID(),
			ToInt(SET_TOP(trans_set_)["取引日"]),
			ToInt(SET_TOP(trans_set_)["伝票No"]));
	}else{
		Action2->Execute();
		return;
	}

	if (id < 1)
		return;

	ClearForm();
	SetMode(imMod);

	trans_id_ = id;

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

	if (trans_id_){	// 修正、または滞留状態
		id = DM->GetNextTransID(GetPlaceID(),
			ToInt(SET_TOP(trans_set_)["取引日"]),
			ToInt(SET_TOP(trans_set_)["伝票No"]));
	}else{
		Action2->Execute();
		return;
	}

	if (id < 1)
		return;

	ClearForm();
	SetMode(imMod);

	trans_id_ = id;

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
	if (GetMode() == imMod || trans_id_ < 1)
		return;

	if (Application->MessageBox("伝票を発行しますか？", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;

	Print(trans_id_);
}
//---------------------------------------------------------------------------
// F9 検索
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (DataListForm->ShowModal() != mrOk)
		return;

	ClearForm();
	SetMode(imMod);

	trans_id_ = DataListForm->selected_id;

	if (!LoadFromID(trans_id_)){
		Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	ShabanEdit->SetFocus();
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
	SearchForm->list_->CommaText = " 得意先コード,得意先略称,得意先カナ,住所1,住所2,電話番号";
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
    SearchForm->list_->CommaText = " 項目1コード,項目1略称,項目1カナ";
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
    SearchForm->list_->CommaText = " 項目2コード,項目2略称,項目2カナ";
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
/*
	ItemSearchForm->Top = MainForm->Top;
	ItemSearchForm->Left = MainForm->Left + 450;
    ItemSearchForm->UnitID = 1;
	if (ItemSearchForm->ShowModal() != mrOk)
		return;
	HinCodeEdit->Text = ItemSearchForm->Query->FieldByName("品目コード")->AsInteger;
	HinCodeEdit->OnChange(NULL);
	HinCodeEdit->SetFocus();
*/
}
//---------------------------------------------------------------------------
// 単位検索
void __fastcall TMainForm::TaniButtonClick(TObject *Sender)
{
/*
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
*/
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

	// 他のフォームのサイズもメインフォームに合わせる
	SearchForm->Height = MainForm->Height;
/*
	DataListForm->Height = MainForm->Height - 33;
	DataListForm->Width  = MainForm->Width  - 24;
	DataListForm->Top  = MainForm->Top  + 16;
	DataListForm->Left = MainForm->Left + 12;
*/
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
	AnsiString sql = "SELECT * FROM M_車両 WHERE 車番 = " + IntToStr(ShabanEdit->Text.ToIntDef(0));
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
// 車番->OnExit
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
	int car_no = ShabanEdit->Text.ToIntDef(0);
	if (car_no < 1){
		ShabanEdit->Text = AnsiString();
        car_id_ = 0;
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

	DM->SetShabanQuery(false, GetPlaceID(), true);

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
		TDateTime now(Now());
		AnsiString name = now.FormatString("mm/dd' に自動登録'");

		fields << NsField("[車番]",     car_no)
			   << NsField("[車両名称]", name)
			   << NsField("[更新日時]", now)
			   << NsField("[作成日時]", now);

		DM->DBI.Insert("M_車両", fields);

		car_id_ = DM->DBI.GetLastID();

        SharyoNameEdit->Text = name;

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

            SharyoNameEdit->Text = ToString(SET_TOP(set)["車両名称"]);
		}
	}

}
//---------------------------------------------------------------------------
// 得意先コード->OnChange
void __fastcall TMainForm::TokuCodeEditChange(TObject *Sender)
{
	int code = TokuCodeEdit->Text.ToIntDef(0);
	if (!code)
		return;

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

	}

}
//---------------------------------------------------------------------------
// 項目1コード->OnChange
void __fastcall TMainForm::Komoku1CodeEditChange(TObject *Sender)
{
	int code = Komoku1CodeEdit->Text.ToIntDef(0);
	if (!code)
		return;

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

	}
/*
    if (Komoku1CodeEdit->Text.ToIntDef(0) == 0){
        Komoku1NameEdit->ReadOnly = false;
        Komoku1NameEdit->SetFocus();
    }else{
        Komoku1NameEdit->ReadOnly = true;
    }
*/
}
//---------------------------------------------------------------------------
// 項目2コード->OnChange
void __fastcall TMainForm::Komoku2CodeEditChange(TObject *Sender)
{
	int code = Komoku2CodeEdit->Text.ToIntDef(0);
	if (!code)
		return;

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

		/*
		id   = ToInt(SET_TOP(set)["項目2ID"]);
		code = 0;
		if (id)
			code = ToInt(DM->DBI.Lookup("M_項目2", "項目2ID", id, "項目2コード"));
		if (code)
			Komoku2CodeEdit->Text = code;
		*/

	}

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl->Tag != 9999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 999 && ActiveControl->Tag != 9999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 9999){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
// 拠点を変更した場合
void __fastcall TMainForm::PlaceComboChange(TObject *Sender)
{
	Action1->Execute();
}
//---------------------------------------------------------------------------
// 伝票No->KeyDown
void __fastcall TMainForm::NoEditKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	int place = GetPlaceID();
	int date  = DateToInt(DatePicker->Date);
	int no    = NoEdit->Text.ToIntDef(0);

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT 取引ID FROM D_取引"
		  " WHERE 取引日 = " + IntToStr(date) + " AND 拠点ID = " + IntToStr(place) +
		  " 	AND 伝票No = " + IntToStr(no);

	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータが見つかりません。",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	ClearForm();
	SetMode(imMod);

	trans_id_ = SET_TOP(set)["取引ID"];

	if (!LoadFromID(trans_id_)){
		Application->MessageBox("滞留データの読み込みに失敗しました。\r\n別PCなどで削除されていないか確認してください。",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	ShabanEdit->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DatePickerChange(TObject *Sender)
{
    // どうする？

    //if (GetMode() == imMod)
       NoEdit->Text = DM->GetTransNo(GetPlaceID(), DateToInt(DatePicker->Date));
}
//---------------------------------------------------------------------------
// 取引明細グリッド描画
void __fastcall TMainForm::DetailGridDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
   RECT rect;
    rect.left   = Rect.Left;
    rect.top    = Rect.Top;
    rect.right  = Rect.Right;
    rect.bottom = Rect.Bottom;

    int active_col = DetailGrid->Col;

    if (ACol == 1 && ARow > 0){
        AnsiString caption = DetailGrid->Cells[ACol][ARow];
        if (caption == "売上")
            DetailGrid->Canvas->Brush->Color = TColor(0x00FDC8AE);
        else if (caption == "仕入")
            DetailGrid->Canvas->Brush->Color = TColor(0x00AFC7FC);
        else
            DetailGrid->Canvas->Brush->Color = clWindow;
        DetailGrid->Canvas->FillRect(Rect);
        ::DrawText(DetailGrid->Canvas->Handle, caption.c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    }

    if (ACol == 7 && ARow > 0){
        AnsiString caption = DetailGrid->Cells[ACol][ARow];
        DetailGrid->Canvas->Brush->Color = deftanka_table_[ARow] == 0 ? clWindow : TColor(0x008080FF);
        DetailGrid->Canvas->FillRect(Rect);
        ::DrawText(DetailGrid->Canvas->Handle, caption.c_str(), -1, &rect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
    }

    if (ARow == DetailGrid->Row && !State.Contains(gdFixed)){
//        DetailGrid->Canvas->Brush->Color = TColor(0x00E6FFFF);
//        DetailGrid->Canvas->FillRect(Rect);
/*
        if (ACol == active_col && !State.Contains(gdFocused)){
    		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(DetailGrid->Components[0]);
    		if (ie){
                ie->Brush->Color = TColor(0x00E6FFFF);
            }
        }
*/
    }

/*
    if (State.Contains(gdFixed)){
        DrawEdge(DetailGrid->Canvas->Handle, &rect, EDGE_SUNKEN, BF_RECT | BF_ADJUST);
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    if (ACol != 9)
        ::SetImeMode(DetailGrid->Handle, imDisable);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_LEFT){
        int col = DetailGrid->Col;
        if (col == 4 && sundry_table_[DetailGrid->Row]){
            DetailGrid->Col = col - 1;
            Key = 0;
            return;
        }
        if (col == 4 || col == 7){
            DetailGrid->Col = col - 2;
            Key = 0;
            return;
        }
    }
    if (Key == VK_RIGHT){
        int col = DetailGrid->Col;
        if (col == 2 && sundry_table_[DetailGrid->Row]){
            DetailGrid->Col = col + 1;
            Key = 0;
            return;
        }
        if (col == 2 || col == 5){
            DetailGrid->Col = col + 2;
            Key = 0;
            return;
        }
    }

    if (Key == VK_RETURN){
        int col = DetailGrid->Col;
        int row = DetailGrid->Row;
        bool last_cell = false;

        switch (col){
        case 2:
            if (sundry_table_[row])
                col++;
            else
                col += 2;
            break;
        case 5:
        case 7:
            col += 2;
            break;
        case 9:
            col = 2;
            row++;
            break;
        default:
            col++;
        };

        if (row > 6){
            col = 2;
            row = 6;
            last_cell = true;
        }

        DetailGrid->Row = row;
        DetailGrid->Col = col;

		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(DetailGrid->Components[0]);
		if (ie){
            ie->SelStart = 0;
        }

    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridSetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
    int code;
    Currency val;
    AnsiString name = AnsiString();

    AnsiString sql;
    NsRecordSet set;

    switch (ACol){
    case 2:
        code = Value.ToIntDef(0);
        sql = "SELECT * FROM V_品目 WHERE 品目コード = " + IntToStr(code);
        if (DM->DBI.GetRecordSet(sql, set)){
            DetailGrid->Cells[1][ARow] = ToString(SET_TOP(set)["取引区分名称"]);
            DetailGrid->Cells[3][ARow] = ToString(SET_TOP(set)["品目名称"]);

            if (code == ToInt(DM->CFG["品目搬入諸口コード"]) || code == ToInt(DM->CFG["品目搬出諸口コード"])){
                sundry_table_[ARow] = true;
                TGridOptions opt = DetailGrid->CellParams->Items[3]->Options;
                opt <<  goEditing << goAlwaysShowEditor;
                DetailGrid->CellParams->Items[13]->Options = opt;
            }else{
                sundry_table_[ARow] = false;
                TGridOptions opt = DetailGrid->CellParams->Items[3]->Options;
                opt >>  goEditing >> goAlwaysShowEditor;
                DetailGrid->CellParams->Items[13]->Options = opt;
            }

        }else{
            sundry_table_[ARow] = false;

            TGridOptions opt = DetailGrid->CellParams->Items[3]->Options;
            opt >>  goEditing >> goAlwaysShowEditor;
            DetailGrid->CellParams->Items[13]->Options = opt;

            DetailGrid->Cells[1][ARow] = AnsiString();
            DetailGrid->Cells[3][ARow] = AnsiString();
            /*
            DetailGrid->Cells[4][ARow] = AnsiString();
            DetailGrid->Cells[5][ARow] = AnsiString();
            DetailGrid->Cells[6][ARow] = AnsiString();
            DetailGrid->Cells[7][ARow] = AnsiString();
            DetailGrid->Cells[8][ARow] = AnsiString();
            DetailGrid->Cells[9][ARow] = AnsiString();
            */
        }
        break;
    case 5:
        code = Value.ToIntDef(0);
        DetailGrid->Cells[6][ARow] = ToString(DM->DBI.Lookup("M_単位", "単位コード", code, "単位名称", ""));
        break;
    };
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridCellChanged(TObject *Sender,
      int AOldCol, int AOldRow, int ANewCol, int ANewRow)
{
    switch (AOldCol){
    case 2:
        GetCalcInfo(AOldRow);
        CalcAmount(AOldRow);
        break;
    case 4:
    case 5:
    case 7:
        CalcAmount(AOldRow, false);
        break;
    };
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetCalcInfo(int row)
{
	if (GetMode() == imMod)
		return;

    int code     = DetailGrid->Cells[2][row].ToIntDef(0);
    if (code){
      	int meig_id  = ToInt(DM->DBI.Lookup("M_品目", "品目コード", code, "品目ID"));
        code = DM->GetDefaultTanka(toku_id_, meig_id);
        DetailGrid->Cells[5][row] = code;
        DetailGrid->Cells[6][row] = ToString(DM->DBI.Lookup("M_単位", "単位コード", code, "単位名称", ""));
    }
    CalcAmount(row);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcAmount(int row, bool update)
{
	Currency qty = StrToCurrDef(DetailGrid->Cells[4][row], 0);

	int meig_id  = ToInt(DM->DBI.Lookup("M_品目",   "品目コード",  DetailGrid->Cells[2][row].ToIntDef(0), "品目ID"));
	int item1_id = ToInt(DM->DBI.Lookup("M_項目1",  "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0),     "項目1ID"));
	int item2_id = ToInt(DM->DBI.Lookup("M_項目2",  "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0),     "項目2ID"));
	int tani_id  = ToInt(DM->DBI.Lookup("M_単位",   "単位コード",  DetailGrid->Cells[5][row].ToIntDef(0), "単位ID"));

    Currency def_tanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
	Currency tanka     = StrToCurrDef(DetailGrid->Cells[7][row], 0);
	if (GetMode() != imMod && update){
        tanka = def_tanka;
    }
    DefTankaGrid->Cells[1][row] = def_tanka;
    deftanka_table_[row] = std::abs(tanka - def_tanka);
    DetailGrid->Invalidate();

	///// 金額端数処理区分の取得
	int amount_div = -1;

	if (!toku_rec_.empty()){
		if (!IsNull(toku_rec_["金額端数処理区分"]))
			amount_div = ToInt(toku_rec_["金額端数処理区分"]);
	}
	if (amount_div == -1)
		amount_div = ToInt(DM->CFG["金額端数処理区分"]);
	/////

   	int amount = ExtendedRound(qty * tanka, 0, amount_div);

	DetailGrid->Cells[7][row] = tanka;
	DetailGrid->Cells[8][row] = amount;

    CalcTotal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcTotal()
{
	Currency tax_rate = DM->GetSalesTax();			// 消費税率

	///// 消費税端数処理区分の取得
	int tax_div = -1;

	if (!toku_rec_.empty()){
		if (!IsNull(toku_rec_["消費税端数処理区分"]))
			tax_div = ToInt(toku_rec_["消費税端数処理区分"]);
	}
	if (tax_div == -1)
		tax_div = ToInt(DM->CFG["消費税端数処理区分"]);
	/////

    zei_table_.clear();

    int u_total     = 0;
    int u_total_zei = 0;
    int s_total     = 0;
    int s_total_zei = 0;
    int row_amount;
    int row_zei;
    int code;
    AnsiString div;
    int *total, *total_zei;
    for (int row = 1; row < DetailGrid->RowCount; row++){
        code     = DetailGrid->Cells[2][row].ToIntDef(0);
        if (!code)
            continue;
        div      = DetailGrid->Cells[1][row];
        if (div == "売上"){
            total     = &u_total;
            total_zei = &u_total_zei;
        }else if (div == "仕入"){
            total     = &s_total;
            total_zei = &s_total_zei;
        }else
            continue;

        row_amount = DetailGrid->Cells[8][row].ToIntDef(0);
        row_zei    = ExtendedRound(Currency(row_amount) * tax_rate, 0, tax_div);

        *total         += row_amount;
        *total_zei     += row_zei;
        zei_table_[row] = row_zei;
    }

    UAmountLabel->Caption   = FormatFloat("###,###,###,##0", u_total);
	UTotalZeiLabel->Caption = FormatFloat("###,###,##0",     u_total_zei);
    SAmountLabel->Caption   = FormatFloat("###,###,###,##0", s_total);
	STotalZeiLabel->Caption = FormatFloat("###,###,##0",     s_total_zei);

    total_zei_ = u_total_zei + s_total_zei;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControlEnter(TObject *Sender)
{
    if (PageControl->ActivePage == TransSheet){
        DetailGrid->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControlChange(TObject *Sender)
{
    if (PageControl->ActivePage == TransSheet){
        RowDeleteButton->Enabled = true;
        RowInsertButton->Enabled = true;
    }else{
        RowDeleteButton->Enabled = false;
        RowInsertButton->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RowInsertButtonClick(TObject *Sender)
{
    int row = DetailGrid->Row;

    if (row < 1)
        return;

    if (!DetailGrid->Cells[1][6].IsEmpty()){
        Application->MessageBox("明細6行目まで入力されています。余分な行を削除してからもう一度行って下さい", "取引データ明細挿入", MB_OK | MB_ICONWARNING);
        return;
    }

    for (int i = 6; i >= row; i--){
        DetailGrid->Cells[1][i] = DetailGrid->Cells[1][i - 1];
        DetailGrid->Cells[2][i] = DetailGrid->Cells[2][i - 1];
        DetailGrid->Cells[3][i] = DetailGrid->Cells[3][i - 1];
        DetailGrid->Cells[4][i] = DetailGrid->Cells[4][i - 1];
        DetailGrid->Cells[5][i] = DetailGrid->Cells[5][i - 1];
        DetailGrid->Cells[6][i] = DetailGrid->Cells[6][i - 1];
        DetailGrid->Cells[7][i] = DetailGrid->Cells[7][i - 1];
        DetailGrid->Cells[8][i] = DetailGrid->Cells[8][i - 1];
        DetailGrid->Cells[9][i] = DetailGrid->Cells[9][i - 1];
    }
    DetailGrid->Cells[1][row] = AnsiString();
    DetailGrid->Cells[2][row] = AnsiString();
    DetailGrid->Cells[3][row] = AnsiString();
    DetailGrid->Cells[4][row] = AnsiString();
    DetailGrid->Cells[5][row] = AnsiString();
    DetailGrid->Cells[6][row] = AnsiString();
    DetailGrid->Cells[7][row] = AnsiString();
    DetailGrid->Cells[8][row] = AnsiString();
    DetailGrid->Cells[9][row] = AnsiString();

    DetailGrid->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RowDeleteButtonClick(TObject *Sender)
{
    int row = DetailGrid->Row;

    if (row < 1)
        return;

    AnsiString msg = "行No: " + IntToStr(row) + " の明細を削除してよろしいですか？";
    if (Application->MessageBox(msg.c_str(), "取引データ明細削除", MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    for (int i = row; i < 6; i++){
        DetailGrid->Cells[1][i] = DetailGrid->Cells[1][i + 1];
        DetailGrid->Cells[2][i] = DetailGrid->Cells[2][i + 1];
        DetailGrid->Cells[3][i] = DetailGrid->Cells[3][i + 1];
        DetailGrid->Cells[4][i] = DetailGrid->Cells[4][i + 1];
        DetailGrid->Cells[5][i] = DetailGrid->Cells[5][i + 1];
        DetailGrid->Cells[6][i] = DetailGrid->Cells[6][i + 1];
        DetailGrid->Cells[7][i] = DetailGrid->Cells[7][i + 1];
        DetailGrid->Cells[8][i] = DetailGrid->Cells[8][i + 1];
        DetailGrid->Cells[9][i] = DetailGrid->Cells[9][i + 1];
    }
    DetailGrid->Cells[1][6] = AnsiString();
    DetailGrid->Cells[2][6] = AnsiString();
    DetailGrid->Cells[3][6] = AnsiString();
    DetailGrid->Cells[4][6] = AnsiString();
    DetailGrid->Cells[5][6] = AnsiString();
    DetailGrid->Cells[6][6] = AnsiString();
    DetailGrid->Cells[7][6] = AnsiString();
    DetailGrid->Cells[8][6] = AnsiString();
    DetailGrid->Cells[9][6] = AnsiString();

    DetailGrid->SetFocus();
}
//---------------------------------------------------------------------------
// 単価更新
void __fastcall TMainForm::TankaUpdateButtonClick(TObject *Sender)
{
    int row = DetailGrid->Row;

	int meig_id  = ToInt(DM->DBI.Lookup("M_品目",   "品目コード",  DetailGrid->Cells[2][row].ToIntDef(0), "品目ID"));
	int item1_id = ToInt(DM->DBI.Lookup("M_項目1",  "項目1コード", Komoku1CodeEdit->Text.ToIntDef(0),     "項目1ID"));
	int item2_id = ToInt(DM->DBI.Lookup("M_項目2",  "項目2コード", Komoku2CodeEdit->Text.ToIntDef(0),     "項目2ID"));
	int tani_id  = ToInt(DM->DBI.Lookup("M_単位",   "単位コード",  DetailGrid->Cells[5][row].ToIntDef(0), "単位ID"));

	Currency tanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
    DetailGrid->Cells[7][DetailGrid->Row] = tanka;
    CalcAmount(row);
    DetailGrid->SetFocus();
}
//---------------------------------------------------------------------------


