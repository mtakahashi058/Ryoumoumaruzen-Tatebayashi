//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "AnbunFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TAnbunForm *AnbunForm;
//---------------------------------------------------------------------------
__fastcall TAnbunForm::TAnbunForm(TComponent* Owner)
	: TForm(Owner)
{
    rate[0]     = EditRate;         rate[1] = EditRate1; rate[2] = EditRate2; rate[3] = EditRate3; rate[4] = EditRate4; rate[5] = EditRate5; rate[6] = EditRate6;
    hincode[0]  = EditHinCode;   hincode[1] = EditHinCode1; hincode[2] = EditHinCode2; hincode[3] = EditHinCode3; hincode[4] = EditHinCode4; hincode[5] = EditHinCode5; hincode[6] = EditHinCode6;
    hinname[0]  = EditHinName;   hinname[1] = EditHinName1; hinname[2] = EditHinName2; hinname[3] = EditHinName3; hinname[4] = EditHinName4; hinname[5] = EditHinName5; hinname[6] = EditHinName6;
    choper[1] = EditChoseiPer1; choper[2] = EditChoseiPer2; choper[3] = EditChoseiPer3; choper[4] = EditChoseiPer4; choper[5] = EditChoseiPer5; choper[6] = EditChoseiPer6;
    choweight[0] = EditChoseiBiki; choweight[1] = EditChoseiBiki1; choweight[2] = EditChoseiBiki2; choweight[3] = EditChoseiBiki3; choweight[4] = EditChoseiBiki4; choweight[5] = EditChoseiBiki5; choweight[6] = EditChoseiBiki6;
    bikiweight[0] = EditJuryoBiki; bikiweight[1] = EditJuryoBiki1; bikiweight[2] = EditJuryoBiki2; bikiweight[3] = EditJuryoBiki3; bikiweight[4] = EditJuryoBiki4; bikiweight[5] = EditJuryoBiki5; bikiweight[6] = EditJuryoBiki6;
    shomi[0] = EditShomi; shomi[1] = EditShomi1; shomi[2] = EditShomi2; shomi[3] = EditShomi3; shomi[4] = EditShomi4; shomi[5] = EditShomi5; shomi[6] = EditShomi6;


	record_list = new TStringList();

	is_first = true;
}
//---------------------------------------------------------------------------
// 初期化
void __fastcall TAnbunForm::ResetName()
{
	PanelHinT1->Caption = DM->CFG["品目マスタ名称"];
	PanelHinT2->Caption = DM->CFG["品目マスタ名称"];

	is_first = false;
}
//---------------------------------------------------------------------------
void __fastcall TAnbunForm::FormShow(TObject *Sender)
{
	if (is_first)
		ResetName();

    //ClearForm();

    Panel4->Caption = ToString(DM->CFG["調整名称"]);
    Panel5->Caption = ToString(DM->CFG["重量引き名称"]);

	// １件目のデータに100％の数量を初期データとして入れ込む
	rate[1]->Text = "100";
	shomi[1]->Text = EditShomi->Text;

    //調整重量と重量引きのことは忘れる
	//edits[0][3]->Text = EditChoseiBiki->Text;
	//edits[0][4]->Text = EditJuryoBiki->Text;


    if (!ToBit(DM->CFG["重量引き使用区分"]))
    {
        for (int i = 1; i < 7; i++ ){
            bikiweight[i]->TabStop = false;
        }
    }
/*
	// スケール引きおよび風袋引きが０だったら入力項目に飛ばないようにする
	bool scale_zero, futai_zero;

	scale_zero = StrToCurrDef(EditChoseiBiki->Text, 0) == 0 ? true : false;

    for (int j = 0; j < 6; j++){
		edits[j][3]->TabStop = !scale_zero;
		edits[j][3]->ReadOnly = scale_zero;
	}

	futai_zero = StrToCurrDef(EditJuryoBiki->Text, 0) == 0 ? true : false;
	for (int j = 0; j < 6; j++){
		edits[j][4]->TabStop = !futai_zero;
		edits[j][4]->ReadOnly = futai_zero;
	}
*/


	CalcZan();

	// 明細件数によって増やせる明細を制限する
	max_record = 6 - (rec_count - 1);
	bool enabled;
	for (int i = 1; i < 7; i++){
		if (i <= max_record)
			enabled = true;
		else
			enabled = false;


        rate[i]->Enabled = enabled;
        hincode[i]->Enabled = enabled;
        hinname[i]->Enabled = enabled;
        choper[i]->Enabled = enabled;
        choweight[i]->Enabled = enabled;
        bikiweight[i]->Enabled = enabled;
        shomi[i]->Enabled = enabled;

        hinname[i]->Color = TColor(0x00E1E1E1);
        choweight[i]->Color = TColor(0x00E1E1E1);
	}

    EditChoseiBikiZan->Visible = false;
    EditJuryoBikiZan->Visible = false;

    rate[1]->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TAnbunForm::ClearForm()
{
	EditRate->Text = AnsiString();
	EditHinCode->Text = AnsiString();
	EditHinName->Text = AnsiString();
	EditChoseiBiki->Text = AnsiString();
	EditJuryoBiki->Text = AnsiString();
	EditShomi->Text = AnsiString();

	// フォームをクリア
	for (int i = 1; i < 7; i++){
        rate[i]->Text    = AnsiString();
		hincode[i]->Text = AnsiString();
        hinname[i]->Text = AnsiString();
        choper[i]->Text  = AnsiString();
        choweight[i]->Text = AnsiString();
        bikiweight[i]->Text = AnsiString();
        shomi[i]->Text = AnsiString();

    }
}
//---------------------------------------------------------------------------
// 残数量を計算する
void __fastcall TAnbunForm::CalcZan()
{
	EditRateZan->Text = StrToCurrDef(EditRate->Text, 0)
				- StrToCurrDef(EditRate1->Text, 0)
				- StrToCurrDef(EditRate2->Text, 0)
				- StrToCurrDef(EditRate3->Text, 0)
				- StrToCurrDef(EditRate4->Text, 0)
				- StrToCurrDef(EditRate5->Text, 0)
				- StrToCurrDef(EditRate6->Text, 0);
/*
	EditChoseiBikiZan->Text = StrToCurrDef(EditChoseiBiki->Text, 0)
				- StrToCurrDef(EditChoseiBiki1->Text, 0)
				- StrToCurrDef(EditChoseiBiki2->Text, 0)
				- StrToCurrDef(EditChoseiBiki3->Text, 0)
				- StrToCurrDef(EditChoseiBiki4->Text, 0)
				- StrToCurrDef(EditChoseiBiki5->Text, 0)
				- StrToCurrDef(EditChoseiBiki6->Text, 0);
	EditJuryoBikiZan->Text = StrToCurrDef(EditJuryoBiki->Text, 0)
				- StrToCurrDef(EditJuryoBiki1->Text, 0)
				- StrToCurrDef(EditJuryoBiki2->Text, 0)
				- StrToCurrDef(EditJuryoBiki3->Text, 0)
				- StrToCurrDef(EditJuryoBiki4->Text, 0)
				- StrToCurrDef(EditJuryoBiki5->Text, 0)
				- StrToCurrDef(EditJuryoBiki6->Text, 0);
*/
	EditShomiZan->Text = StrToCurrDef(EditShomi->Text, 0)
				- (StrToCurrDef(EditShomi1->Text, 0) + StrToCurrDef(EditChoseiBiki1->Text, 0) + StrToCurrDef(EditJuryoBiki1->Text, 0))
				- (StrToCurrDef(EditShomi2->Text, 0) + StrToCurrDef(EditChoseiBiki2->Text, 0) + StrToCurrDef(EditJuryoBiki2->Text, 0))
				- (StrToCurrDef(EditShomi3->Text, 0) + StrToCurrDef(EditChoseiBiki3->Text, 0) + StrToCurrDef(EditJuryoBiki3->Text, 0))
				- (StrToCurrDef(EditShomi4->Text, 0) + StrToCurrDef(EditChoseiBiki4->Text, 0) + StrToCurrDef(EditJuryoBiki4->Text, 0))
				- (StrToCurrDef(EditShomi5->Text, 0) + StrToCurrDef(EditChoseiBiki5->Text, 0) + StrToCurrDef(EditJuryoBiki5->Text, 0))
				- (StrToCurrDef(EditShomi6->Text, 0) + StrToCurrDef(EditChoseiBiki6->Text, 0) + StrToCurrDef(EditJuryoBiki6->Text, 0));
}
//---------------------------------------------------------------------------
void __fastcall TAnbunForm::ButtonHin1Click(TObject *Sender)
{
	SearchForm->based_sql = "SELECT 品目コード, 品目名称 FROM M_品目 WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY 品目コード ";
	SearchForm->table_name = "M_品目";
	//SearchForm->search_fields = "品目コード,品目名称,品目カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;

	int tag = ((TButton *)Sender)->Tag;
	hincode[tag]->Text = SearchForm->Query->FieldByName("品目コード")->AsString;
	hincode[tag]->OnChange(hincode[tag]);

	if (choper[tag]->TabStop)
		choper[tag]->SetFocus();
	else if (bikiweight[tag]->TabStop)
		bikiweight[tag]->SetFocus();
	else
		shomi[tag]->SetFocus();
}
//---------------------------------------------------------------------------
// 品目コード->OnChange
void __fastcall TAnbunForm::EditHinCode1Change(TObject *Sender)
{
	int tag = ((TButton *)Sender)->Tag;
	hinname[tag]->Text = DM->DBI.Lookup("M_品目", "品目コード", ((TCobEdit *)Sender)->Text.ToIntDef(0), "品目名称", "");
}
//---------------------------------------------------------------------------
// 割合->OnChange
void __fastcall TAnbunForm::EditRate1Change(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------
// 割合->OnExit
void __fastcall TAnbunForm::EditRate1Exit(TObject *Sender)
{
	// 割合から数量を算出
	int tag = ((TButton *)Sender)->Tag;
    Currency rateValue = StrToCurrDef(rate[tag]->Text, 0);

	Currency rate_sum = 0;
	for (int i = 1; i < 7; i++){
        rate_sum += StrToCurrDef(rate[i]->Text, 0);
    }

	if (rate_sum == 100){
		// 割合の合計が100％だったら、残りの数量を算出
        //shomi[tag]->Text = StrToCurrDef(EditShomi->Text, 0);
        //processingShomi_ = shomi[tag]->Text;
	}else if (rate_sum < 100){
		// 割合の合計が100％じゃなかったら、割合から各項目の数量を算出
        //processingShomi_ = ExtendedRound(StrToCurrDef(EditShomi->Text, 0) * rateValue / 100, ToInt(DM->CFG["按分端数処理桁"]), ToInt(DM->CFG["按分端数処理区分"]));
        //shomi[tag]->Text = processingShomi_;
        shomi[tag]->Text = ExtendedRound(StrToCurrDef(EditShomi->Text, 0) * rateValue / 100, ToInt(DM->CFG["按分端数処理桁"]), ToInt(DM->CFG["按分端数処理区分"]));
	}else{
		Application->MessageBox("割合合計が100％を超えています", "チェック", MB_OK | MB_ICONEXCLAMATION);
        rate[tag]->SetFocus();
		return;
	}

	CalcZan();
}
//---------------------------------------------------------------------------
// 正味重量->OnKeyDown
void __fastcall TAnbunForm::EditShomi1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	int tag = ((TButton *)Sender)->Tag;

	// 数量チェック
	if (!CheckSuryo(tag))
		return;

	// 残数量＝すべて０の場合、案分を実行する
	if (StrToCurrDef(EditShomiZan->Text, 0) == 0){
		ButtonExec->OnClick(NULL);
		return;
	}

	// 最終行で数量が不足している場合、警告を出して次の行へは移動しない
	if (max_record == tag){
		Application->MessageBox("数量が残っています\r\n残数量が０になるように調整してください", "案分処理", MB_OK | MB_ICONEXCLAMATION);
        rate[tag]->SetFocus();
		return;
	}

	// 残数量≠０の場合、残りの数量を次の行のデフォルト値として表示する
    rate[tag + 1]->Text         = EditRateZan->Text;
    shomi[tag + 1]->Text        = EditShomiZan->Text;
    rate[tag + 1]->SetFocus();
}
//---------------------------------------------------------------------------
// 数量が元の数量を超えていないかをチェック
bool __fastcall TAnbunForm::CheckSuryo(int tag)
{
	// 残数量を算出
	CalcZan();

	if (StrToCurrDef(EditRateZan->Text, 0) > 100){
		Application->MessageBox("割合合計が100％を超えています", "チェック", MB_OK | MB_ICONEXCLAMATION);
		//edits[tag - 1][0]->SetFocus();
        rate[tag]->SetFocus();
		return false;
	}
	if (StrToCurrDef(EditChoseiBikiZan->Text, 0) < 0){
		Application->MessageBox("スケール引きが元の数量を超えています", "チェック", MB_OK | MB_ICONEXCLAMATION);
		//edits[tag - 1][3]->SetFocus();
        choweight[tag]->SetFocus();
		return false;
	}
	if (StrToCurrDef(EditJuryoBikiZan->Text, 0) < 0){
		Application->MessageBox("風袋引きが元の数量を超えています", "チェック", MB_OK | MB_ICONEXCLAMATION);
		//edits[tag - 1][4]->SetFocus();
        bikiweight[tag]->SetFocus();
		return false;
	}
	if (StrToCurrDef(EditShomiZan->Text, 0) < 0){
		Application->MessageBox("正味重量が元の数量を超えています", "チェック", MB_OK | MB_ICONEXCLAMATION);
		//edits[tag - 1][5]->SetFocus();
        shomi[tag]->SetFocus();
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
// 品目参照
void __fastcall TAnbunForm::EditHinCode1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key != VK_F4)
		return;
	int tag = ((TButton *)Sender)->Tag;
	buttons[tag - 1]->OnClick(buttons[tag - 1]);
}
//---------------------------------------------------------------------------
// 案分実行
void __fastcall TAnbunForm::ButtonExecClick(TObject *Sender)
{
	// 数量チェック
	if (!CheckSuryo(1))
		return;
	if (Application->MessageBox("按分処理を実行しますか？", "按分処理", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;

	// 案分処理
	record_list->Clear();
    AnbunMap.clear();
	std::auto_ptr<TStringList> record(new TStringList);
    int AnbunCnt = 0;
	for (int i = 1; i < 7; i++){
		// 重量がすべて０だったら、読み飛ばし
        if (StrToCurrDef(choweight[i]->Text, 0) == 0 &&
            StrToCurrDef(bikiweight[i]->Text, 0) == 0 &&
            StrToCurrDef(shomi[i]->Text, 0) == 0){

            continue;
        }

        avalue.code         = ToInt(hincode[i]->Text);         // 品名コード
        avalue.name         = hinname[i]->Text;                // 品名
        avalue.choseiper    = ToCurrency(AnsiReplaceStr(choper[i]->Text, "%", ""));           // 調整率
        avalue.choseibiki   = ToCurrency(choweight[i]->Text);  // 調整引き
        avalue.juryobiki    = ToCurrency(bikiweight[i]->Text); // 重量引き
        avalue.shomi        = ToCurrency(shomi[i]->Text);      // 正味重量

        //AnbunMap[i - 1] = avalue;
        AnbunMap[AnbunCnt] = avalue;
        AnbunCnt++;
/*
		if (StrToCurrDef(edits[i][3]->Text, 0) == 0 &&
				StrToCurrDef(edits[i][4]->Text, 0) == 0 &&
				StrToCurrDef(edits[i][5]->Text, 0) == 0){
			continue;
		}

        avalue.code         = ToInt(edits[i][1]->Text);  //品名コード
        avalue.name         = edits[i][2]->Text;  //品名
        avalue.choseibiki    = ToCurrency(edits[i][3]->Text);  //スケール引き
        avalue.juryobiki    = ToCurrency(edits[i][4]->Text);  //風袋引き
        avalue.shomi        = ToCurrency(edits[i][5]->Text);  //正味重量
*/
	}

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TAnbunForm::EditHinCode1Exit(TObject *Sender)
{
    // 挿入行の特定
	int tag = ((TButton *)Sender)->Tag;
	// 重量調整率
	NsRecordSet set;
	AnsiString sql;

    //ShowMessage(edits[tag - 1][1]->Name);

	//sql = "SELECT * FROM M_品目 WHERE 品目コード = " + IntToStr(edits[tag - 1][1]->Text.ToIntDef(0));
    sql = "SELECT * FROM M_品目 WHERE 品目コード = " + IntToStr(hincode[tag]->Text.ToIntDef(0));
	if (DM->DBI.GetRecordSet(sql, set)){
		Currency coord_ratio = ToCurrency(SET_TOP(set)["重量調整率"]);

        if (StrToCurrDef(AnsiReplaceStr(choweight[tag]->Text, "%", ""), 0) != coord_ratio){
            choper[tag]->Text = ZeroSuppress(coord_ratio) + "%";
			CalcWeight(tag);
        }
        /*
		if (StrToCurrDef(AnsiReplaceStr(edits[tag - 1][3]->Text, "%", ""), 0) != coord_ratio){
			if (GetMode() == imMod)
				if (Application->MessageBox(("重量調整率が異なります。上書きしますか？\r\n登録調整率：" + FormatFloat("#,##0.0#", coord_ratio) + "%").c_str(), "品目変更", MB_YESNO | MB_ICONEXCLAMATION) != IDYES)
					return;
			edits[tag - 1][3]->Text = ZeroSuppress(coord_ratio);
			CalcWeight(tag - 1);
		}
        */
	}

}
//---------------------------------------------------------------------------
void __fastcall TAnbunForm::CalcWeight(int row)
{
    if (row < 0 || row > 6)
        return;

    Currency net = 0;
    Currency rateValue = StrToCurrDef(rate[row]->Text, 0);
	Currency rate_sum = 0;
    int last_row = 0;
	for (int i = 1; i < 7; i++){
        rate_sum += StrToCurrDef(rate[i]->Text, 0);
        if (rate_sum == 100){
            last_row = i;
            break;
        }
    }

    if (rate_sum == 100 && last_row == row){

        net = StrToCurrDef(EditShomi->Text, 0);

        for (int i = 1; i < row; i++)
        {
            net -= (StrToCurrDef(shomi[i]->Text, 0) + StrToCurrDef(choweight[i]->Text, 0) + StrToCurrDef(bikiweight[i]->Text, 0));
        }

    }else{
        net = ExtendedRound(StrToCurrDef(EditShomi->Text, 0) * rateValue / 100, ToInt(DM->CFG["按分端数処理桁"]), ToInt(DM->CFG["按分端数処理区分"]));
    }

    if (ToBit(DM->CFG["調整使用区分"])){
        Currency coord, coord_ratio;
        coord = StrToCurrDef(choweight[row]->Text, 0);

        //coord_ratio = StrToCurrDef(AnsiReplaceStr(edits[row][3]->Text, "%", ""), 0) / 100;
        coord_ratio = StrToCurrDef(AnsiReplaceStr(choper[row]->Text, "%", ""), 0) / 100;

        if (coord_ratio > 0){
            coord = ExtendedRound(net * coord_ratio, ToInt(DM->CFG["調整端数処理桁数"]), ToInt(DM->CFG["調整端数処理区分"]));
            //edits[row][4]->Text = coord;
            choweight[row]->Text = coord;
            choweight[row]->Text += "%";
        }else{
            coord = 0;
        }

        // 正味重量から調整重量をひく
        net -= int(coord);

        //edits[row][6]->Text = ToString(net);
        //shomi[row]->Text = ToString(net);
    }

    if (ToBit(DM->CFG["重量引き使用区分"])){
        Currency reduc = StrToCurrDef(bikiweight[row]->Text, 0);
        net -= reduc;
    }

    shomi[row]->Text = net;
}
//---------------------------------------------------------------------------

void __fastcall TAnbunForm::EditChoseiPer1Exit(TObject *Sender)
{
	int tag = ((TCobEdit *)Sender)->Tag;

    AnsiString result = choper[tag]->Text;

    if (result == "" || result == "%" || result == "0")
        choweight[tag]->Text = "";

    CalcWeight(tag);
}
//---------------------------------------------------------------------------


void __fastcall TAnbunForm::EditJuryoBiki1Exit(TObject *Sender)
{
    int tag = ((TCobEdit *)Sender)->Tag;

    CalcWeight(tag);
}
//---------------------------------------------------------------------------

