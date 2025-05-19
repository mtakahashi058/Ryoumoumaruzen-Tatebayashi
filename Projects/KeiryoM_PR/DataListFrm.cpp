//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "DataListFrm.h"
#include "nsoftfunc.h"
#include <memory>
#include "QRLedgerFrm.h"
#include "MainFrm.h"
#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TDataListForm *DataListForm;
AnsiString GRID_CONFIG = "計量グリッド配置.txt";
//---------------------------------------------------------------------------
__fastcall TDataListForm::TDataListForm(TComponent* Owner)
	: TForm(Owner), first_(true), rec_no_(-1), grid_cleared_(false)
{
}
//---------------------------------------------------------------------------
// Form->OnShow
void __fastcall TDataListForm::FormShow(TObject *Sender)
{
    if (first_){
    	try{
    		DBGrid->Columns->LoadFromFile(ExtractFilePath(Application->ExeName) + GRID_CONFIG); // 読み込み対象ファイルをフルパスで指定
    	}catch (...){ ; }

		ClearButton->Click();

		TokuButton->Caption  = ToString(DM->CFG["得意先マスタ名称"]);
		HinButton->Caption   = ToString(DM->CFG["品目マスタ名称"]);
		Item1Button->Caption = ToString(DM->CFG["項目1マスタ名称"]);
		Item2Button->Caption = ToString(DM->CFG["項目2マスタ名称"]);

		TokuLabel->Caption   = ToString(DM->CFG["得意先マスタ名称"]) + "：";
		Item1Label->Caption  = ToString(DM->CFG["項目1マスタ名称"]) + "：";
		Item2Label->Caption  = ToString(DM->CFG["項目2マスタ名称"]) + "：";
		MeigLabel->Caption   = ToString(DM->CFG["品目マスタ名称"]) + "：";
		CoordLabel->Caption  = ToString(DM->CFG["調整名称"]) + "：";
		ReduceLabel->Caption = ToString(DM->CFG["重量引き名称"]) + "：";

		DBGrid->Columns->Items[7]->Title->Caption  = ToString(DM->CFG["得意先マスタ名称"]);
		DBGrid->Columns->Items[9]->Title->Caption  = ToString(DM->CFG["品目マスタ名称"]);
		DBGrid->Columns->Items[10]->Visible        = false;
		DBGrid->Columns->Items[11]->Title->Caption = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->CFG["品目マスタ名称"]), "　", ""), " ", "") + "分類";
		DBGrid->Columns->Items[13]->Title->Caption = ToString(DM->CFG["項目1マスタ名称"]);
		DBGrid->Columns->Items[15]->Title->Caption = ToString(DM->CFG["項目2マスタ名称"]);

		if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
			DBGrid->Columns->Items[6]->Visible = false;
			DBGrid->Columns->Items[7]->Visible = false;
		}
		if (!ToBit(DM->CFG["品目マスタ使用区分"])){
			DBGrid->Columns->Items[8]->Visible = false;
			DBGrid->Columns->Items[9]->Visible = false;
		}
		if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
			DBGrid->Columns->Items[12]->Visible = false;
			DBGrid->Columns->Items[13]->Visible = false;
		}
		if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
			DBGrid->Columns->Items[14]->Visible = false;
			DBGrid->Columns->Items[15]->Visible = false;
		}
		if (!ToBit(DM->CFG["調整使用区分"])){
			DBGrid->Columns->Items[18]->Visible = false;
			DBGrid->Columns->Items[19]->Visible = false;
		}
		if (!ToBit(DM->CFG["重量引き使用区分"])){
			DBGrid->Columns->Items[20]->Visible = false;
		}
		if (!ToBit(DM->CFG["単価使用区分"])){
			DBGrid->Columns->Items[24]->Visible = false;
			DBGrid->Columns->Items[25]->Visible = false;
		}

        FilterShowButton->Caption = ">>";
		FilterPanel->Height = 61;

		OrderComboBox->Items->Strings[3] = AnsiReplaceStr(AnsiReplaceStr(TokuButton->Caption, "　", ""), " ", "");
		OrderComboBox->Items->Strings[4] = AnsiReplaceStr(AnsiReplaceStr(HinButton->Caption, "　", ""), " ", "");
		OrderComboBox->Items->Strings[5] = AnsiReplaceStr(AnsiReplaceStr(Item1Button->Caption, "　", ""), " ", "");
		OrderComboBox->Items->Strings[6] = AnsiReplaceStr(AnsiReplaceStr(Item2Button->Caption, "　", ""), " ", "");

		first_ = false;
	}

	Action5->Execute();

	SetButtonEnabled();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if (!grid_cleared_)
    	DBGrid->Columns->SaveToFile(ExtractFilePath(Application->ExeName) + GRID_CONFIG); // 保存するファイル名をフルパスで指定
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::DBGridDrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
	// DBGrid で一行おきに色を変える
	if (DBGrid->SelectedRows->CurrentRowSelected)
		;
	else if (DataCol == 0){
		if (DBGrid->DataSource->DataSet->FieldByName("完了区分")->AsInteger == 1)
			DBGrid->Canvas->Brush->Color = TColor(0x00D2FDD2);
		else
			DBGrid->Canvas->Brush->Color = TColor(0x00A6FFFF);

	}else if (DBGrid->DataSource->DataSet->FieldByName("完了区分")->AsInteger == 0){
		DBGrid->Canvas->Brush->Color = TColor(0x00A6FFFF);

	}else if ((State.Empty() || ActiveControl != DBGrid) && DBGrid->DataSource->DataSet->RecNo % 2 == 0)
		DBGrid->Canvas->Brush->Color = TColor(0x00EBEBEB);

	DBGrid->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------
// 最初へ
void __fastcall TDataListForm::FirstButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->First();
	//SetButtonEnabled();
}
//---------------------------------------------------------------------------
// 前へ
void __fastcall TDataListForm::PriorButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Prior();
	//SetButtonEnabled();
}
//---------------------------------------------------------------------------
// 次へ
void __fastcall TDataListForm::NextButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Next();
	//SetButtonEnabled();
}
//---------------------------------------------------------------------------
// 最後へ
void __fastcall TDataListForm::LastButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Last();
}
//---------------------------------------------------------------------------
// レコード移動ボタン(Enabled)
void __fastcall TDataListForm::SetButtonEnabled()
{
	if (!DBGrid->DataSource->DataSet->Active){
		FirstButton->Enabled = false;
		PriorButton->Enabled = false;
		NextButton->Enabled = false;
		LastButton->Enabled = false;
		return;
	}

	FirstButton->Enabled = true;
	PriorButton->Enabled = true;
	NextButton->Enabled = true;
	LastButton->Enabled = true;

	if (DBGrid->DataSource->DataSet->RecNo == 1){
		FirstButton->Enabled = false;
		PriorButton->Enabled = false;
	}else if (DBGrid->DataSource->DataSet->RecNo == DBGrid->DataSource->DataSet->RecordCount){
		NextButton->Enabled = false;
		LastButton->Enabled = false;
	}
}
//---------------------------------------------------------------------------
// DBGrid->AfterScroll
void __fastcall TDataListForm::Q_KeiryoAfterScroll(TDataSet *DataSet)
{
	SetButtonEnabled();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::DispMeisaiCheckBoxClick(TObject *Sender)
{
	if (DispMeisaiCheckBox->Checked)
		MeisaiPanel->Height = 189;
	else
		MeisaiPanel->Height = 16;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Action5Execute(TObject *Sender)
{
	try{
	IngPanel->Visible = true;
	Application->ProcessMessages();

	if (Q_Keiryo->Active)
		Q_Keiryo->Close();

	AnsiString sql;
	NsFilterSet filters;

	sql = " SELECT * FROM V_計量";

	if (dtpDateFrom->Checked)
		filters << NsFilter("計量日 >= ", DateToInt(dtpDateFrom->Date));
	if (dtpDateTo->Checked)
		filters << NsFilter("計量日 <= ", DateToInt(dtpDateTo->Date));
	if (StateCombo->ItemIndex == 0)
		filters << NsFilter("完了区分 <> ", 9);
	else if (StateCombo->ItemIndex == 1)
		filters << NsFilter("完了区分 = ", 0);
	else if (StateCombo->ItemIndex == 2)
		filters << NsFilter("完了区分 = ", 1);

	int n;

	n = CarNoEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("車番 = ", n);

	n = TokuCodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("得意先コード = ", n);

	n = HinCodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("品目コード = ", n);

	n = Item1CodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("項目1コード = ", n);

	n = Item2CodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("項目2コード = ", n);

	if (PlaceCombo->ItemIndex != 0){
		filters << NsFilter("拠点ID = ", IntToStr(ToInt(DM->PlaceSet[PlaceCombo->ItemIndex - 1]["拠点ID"])));
		DBGrid->Columns->Items[1]->Visible = false;
	}else{
		DBGrid->Columns->Items[1]->Visible = true;
	}

	sql += " WHERE " + ToFilter(filters, "AND");

	if (!cedtSearch->Text.IsEmpty()){
		sql += " AND " + DM->DBI.FullSearchSQL(cedtSearch->Text, "V_計量");
	}

	if (UnitCombo->ItemIndex == 0)
		sql += " AND 行No = 1";

	if (!KoujunCheckBox->Checked){	// 昇順
		if (OrderComboBox->ItemIndex == 0)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 1)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 伝票No";
		else if (OrderComboBox->ItemIndex == 2)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 車番, 車両ID, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 3)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 得意先コード, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 4)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 品目コード, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 5)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 項目1コード, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 6)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 項目2コード, 計量日, 伝票No";
		else
			Q_Keiryo->SQL->Text = sql + " ORDER BY 計量日, 伝票No";

	}else{	// 降順
		if (OrderComboBox->ItemIndex == 0)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 計量日 DESC, 伝票No";
		else if (OrderComboBox->ItemIndex == 1)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 伝票No DESC";
		else if (OrderComboBox->ItemIndex == 2)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 車番 DESC, 車両ID, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 3)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 得意先コード DESC, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 4)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 品目コード DESC, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 5)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 項目1コード DESC, 計量日, 伝票No";
		else if (OrderComboBox->ItemIndex == 6)
			Q_Keiryo->SQL->Text = sql + " ORDER BY 項目2コード DESC, 計量日, 伝票No";
		else
			Q_Keiryo->SQL->Text = sql + " ORDER BY 計量日 DESC, 伝票No";
	}

	Q_Keiryo->Open();

	NsRecordSet sum_set;
	AnsiString sum_sql = sql;
	sum_sql = AnsiReplaceStr(sum_sql, "SELECT *", "SELECT COUNT(*) AS 件数, SUM(正味重量) AS 正味重量, SUM(金額) AS 金額");
	sum_sql = sum_sql + " AND 完了区分 = 1";
	DM->DBI.GetRecordSet(sum_sql, sum_set);
	SumLabel->Caption = "件数：" + FormatFloat("#,##0", ToInt(sum_set[0]["件数"])) + "件  重量：" + FormatFloat("#,##0", ToCurrency(sum_set[0]["正味重量"])) + "kg  金額：" + FormatFloat("#,##0", ToCurrency(sum_set[0]["金額"])) + "円"; 

	}__finally{
		IngPanel->Visible = false;
	}

	if (rec_no_ >= 0){
		try{
			Q_Keiryo->RecNo = rec_no_;
		}catch(...){}
	}
	DBGrid->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnOkClick(TObject *Sender)
{
	if (Q_Keiryo->Bof && Q_Keiryo->Eof)
		return;

    rec_no_ = Q_Keiryo->RecNo;

    int date  = Q_Keiryo->FieldByName("計量日")->AsInteger;
    int place = Q_Keiryo->FieldByName("拠点ID")->AsInteger;
    int no    = Q_Keiryo->FieldByName("伝票No")->AsInteger;

    NsFieldSet keys;
    keys << NsField("計量日", date)
         << NsField("拠点ID", place)
         << NsField("伝票No", no)
             //<< NsField("行No",   1)
         ;

    selected_id = ToInt(DM->DBI.Lookup("D_計量", keys, "計量ID"));

    if (selected_id < 1){
        Application->MessageBox("伝票の１行目明細が見つかりません", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnCancelClick(TObject *Sender)
{
	selected_id = 0;
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::DBGridDblClick(TObject *Sender)
{
	btnOk->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnSaveClick(TObject *Sender)
{
	if (Q_Keiryo->RecordCount == 0)
		return;
	SaveDialog->FileName = "計量一覧_" + Date().FormatString("yyyymmdd出力") + ".csv";
	if (!SaveDialog->Execute())
		return;
	std::auto_ptr<TStringList> Records(new TStringList());
	Table2Str(Q_Keiryo, Records.get(), true);
	Records->SaveToFile(SaveDialog->FileName);
	Application->MessageBox("完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::PriorDateButtonClick(TObject *Sender)
{
    bool checked_from = dtpDateFrom->Checked;
    bool checked_to   = dtpDateTo->Checked;

    dtpDateFrom->Checked = true;
    dtpDateTo->Checked   = true;

    ShiftDate(dtpDateFrom, dtpDateTo, -1);

    dtpDateFrom->Checked = checked_from;
	dtpDateTo->Checked   = checked_to;

	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::NextDateButtonClick(TObject *Sender)
{
	bool checked_from = dtpDateFrom->Checked;
	bool checked_to   = dtpDateTo->Checked;

	dtpDateFrom->Checked = true;
	dtpDateTo->Checked   = true;

	ShiftDate(dtpDateFrom, dtpDateTo, 1);

	dtpDateFrom->Checked = checked_from;
	dtpDateTo->Checked   = checked_to;

	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearGridButtonClick(TObject *Sender)
{
	if (Application->MessageBox("データ一覧の表幅を初期化しますか？", "表幅初期化", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	AnsiString file = ExtractFilePath(Application->ExeName) + GRID_CONFIG;
	if (FileExists(file))
		DeleteFile(file);
	Application->MessageBox("計量処理を再起動して下さい", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    grid_cleared_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearButtonClick(TObject *Sender)
{
    TDateTime now(Now());
	dtpDateFrom->Date = now;
    dtpDateTo->Date   = now;

    place_id_       = MainForm->GetPlaceID();

	PlaceCombo->Items->Clear();
    PlaceCombo->Items->Append("すべて");

    int id;
    int index = 0;
    for (unsigned int i = 0; i < DM->PlaceSet.size(); i++){
        id = ToInt(DM->PlaceSet[i]["拠点ID"]);
		PlaceCombo->Items->Append(ToString(DM->PlaceSet[i]["拠点名称"]));

        if (place_id_ == id)
            index = i + 1;
	}
    PlaceCombo->ItemIndex = index;

    cedtSearch->Text = AnsiString();

    TokuCodeEdit->Text  = AnsiString();
    TokuNameEdit->Text  = AnsiString();
    HinCodeEdit->Text   = AnsiString();
    HinNameEdit->Text   = AnsiString();
    Item1CodeEdit->Text = AnsiString();
    Item1NameEdit->Text = AnsiString();
    Item2CodeEdit->Text = AnsiString();
    Item2NameEdit->Text = AnsiString();

   	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::FilterShowButtonClick(TObject *Sender)
{
    if (FilterShowButton->Caption == ">>"){
        FilterPanel->Height = 121;
        FilterShowButton->Caption = "<<";
    }else{
        FilterPanel->Height = 61;
        FilterShowButton->Caption = ">>";
    }
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::TokuCodeEditChange(TObject *Sender)
{
    TokuNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "得意先略称"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::HinCodeEditChange(TObject *Sender)
{
    HinNameEdit->Text = ToString(DM->DBI.Lookup("M_品目", "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目略称"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item1CodeEditChange(TObject *Sender)
{
    Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1略称"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item2CodeEditChange(TObject *Sender)
{
    Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2略称"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::TokuButtonClick(TObject *Sender)
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
void __fastcall TDataListForm::HinButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 品目コード, 品目略称, 搬入出区分名称 AS 搬入出, 取引区分名称 AS 取引区分 FROM V_品目 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 品目コード ";
    SearchForm->table_name = "M_品目";
    if (SearchForm->ShowModal() != mrOk)
        return;
    HinCodeEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
    HinCodeEdit->OnChange(NULL);
    HinCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item1ButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 項目1コード, 項目1略称 FROM M_項目1 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目1コード ";
    SearchForm->table_name = "M_項目1";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item1CodeEdit->Text = SearchForm->Query->FieldByName("項目1コード")->AsInteger;
    Item1CodeEdit->OnChange(NULL);
    Item1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item2ButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT 項目2コード, 項目2略称 FROM M_項目2 WHERE 使用区分 = 1";
    SearchForm->orderby_sql = " ORDER BY 項目2コード ";
    SearchForm->table_name = "M_項目2";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item2CodeEdit->Text = SearchForm->Query->FieldByName("項目2コード")->AsInteger;
    Item2CodeEdit->OnChange(NULL);
    Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Q_KeiryoCalcFields(TDataSet *DataSet)
{
	if (Q_Keiryo->FieldByName("伝票No")->AsInteger >= 900000000)
		Q_Keiryo->FieldByName("表示用伝票No")->AsString = "滞留";
	else
		Q_Keiryo->FieldByName("表示用伝票No")->AsString = Q_Keiryo->FieldByName("伝票No")->AsString;
}
//---------------------------------------------------------------------------
// 検索項目->OnKeyDown
void __fastcall TDataListForm::cedtSearchKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	Action5->Execute();
}
//---------------------------------------------------------------------------
// DBGrid->OnKeyDown
void __fastcall TDataListForm::DBGridKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	btnOk->OnClick(NULL);
}
//---------------------------------------------------------------------------
// 並び順、昇降順->OnChange
void __fastcall TDataListForm::OrderComboBoxChange(TObject *Sender)
{
	Action5->Execute();
}
//---------------------------------------------------------------------------
// Form->OnKeyDown
void __fastcall TDataListForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_ESCAPE)
		btnCancel->Click();	
}
//---------------------------------------------------------------------------

