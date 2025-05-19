//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "DataListFrm.h"
#include "nsoftfunc.h"
#include <memory>
#include "MainFrm.h"
#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TDataListForm *DataListForm;
AnsiString GRID_CONFIG = "取引グリッド配置.txt";
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

        TokuButton->Caption  = ToString(DM->CFG["得意先マスタ名称"]);
        HinButton->Caption   = ToString(DM->CFG["品目マスタ名称"]);
        Item1Button->Caption = ToString(DM->CFG["項目1マスタ名称"]);
        Item2Button->Caption = ToString(DM->CFG["項目2マスタ名称"]);

        DBGrid->Columns->Items[7]->Title->Caption  = ToString(DM->CFG["得意先マスタ名称"]);
        DBGrid->Columns->Items[9]->Title->Caption  = ToString(DM->CFG["項目1マスタ名称"]);
        DBGrid->Columns->Items[11]->Title->Caption = ToString(DM->CFG["項目2マスタ名称"]);
        DBGrid->Columns->Items[13]->Title->Caption = ToString(DM->CFG["品目マスタ名称"]);

        ClearButton->Click();

        FilterShowButton->Caption = ">>";
        FilterPanel->Height = 61;

        first_ = false;
    }

   	Action5->Execute();
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
	if (DBGrid->SelectedRows->CurrentRowSelected || DBGrid->Columns->Items[DataCol]->Color != DBGrid->Color)
		;
	else if ((State.Empty() || ActiveControl != DBGrid) && DBGrid->DataSource->DataSet->RecNo % 2 == 0)
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
void __fastcall TDataListForm::Action5Execute(TObject *Sender)
{
	if (Q_Trans->Active)
		Q_Trans->Close();

	AnsiString sql;
	NsFilterSet filters;

	sql = " SELECT * FROM V_取引";

	if (dtpDateFrom->Checked)
		filters << NsFilter("取引日 >= ", DateToInt(dtpDateFrom->Date));
	if (dtpDateTo->Checked)
		filters << NsFilter("取引日 <= ", DateToInt(dtpDateTo->Date));

    if (PlaceCombo->ItemIndex != 0){
        filters << NsFilter("拠点ID = ", IntToStr(DM->PlaceIDMap[PlaceCombo->ItemIndex]));
    }
    
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

	sql += " WHERE " + ToFilter(filters, "AND");

	if (!cedtSearch->Text.IsEmpty()){
		sql += " AND " + DM->DBI.FullSearchSQL(cedtSearch->Text, "V_取引");
	}

    if (UnitCombo->ItemIndex == 0)
        sql += " AND 行No = 1";

	Q_Trans->SQL->Text = sql;

	Q_Trans->Open();

    if (rec_no_ >= 0){
        try{
            Q_Trans->RecNo = rec_no_;
        }catch(...){}
    }
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnOkClick(TObject *Sender)
{
	if (Q_Trans->Bof && Q_Trans->Eof)
		return;

    rec_no_ = Q_Trans->RecNo;

    int lineno = Q_Trans->FieldByName("行No")->AsInteger;
    if (lineno != 1){
        int date  = Q_Trans->FieldByName("取引日")->AsInteger;
        int place = Q_Trans->FieldByName("拠点ID")->AsInteger;
        int no    = Q_Trans->FieldByName("伝票No")->AsInteger;

        NsFieldSet keys;
        keys << NsField("取引日", date)
             << NsField("拠点ID", place)
             << NsField("伝票No", no)
             << NsField("行No",   1);

        selected_id = ToInt(DM->DBI.Lookup("D_取引", keys, "取引ID"));
    }else{
    	selected_id = Q_Trans->FieldByName("取引ID")->AsInteger;
    }

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
void __fastcall TDataListForm::PriorDateButtonClick(TObject *Sender)
{
    bool checked_from = dtpDateFrom->Checked;
    bool checked_to   = dtpDateTo->Checked;

    dtpDateFrom->Checked = true;
    dtpDateTo->Checked   = true;

    ShiftDate(dtpDateFrom, dtpDateTo, -1);

    dtpDateFrom->Checked = checked_from;
    dtpDateTo->Checked   = checked_to;
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
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearGridButtonClick(TObject *Sender)
{
	AnsiString file = ExtractFilePath(Application->ExeName) + GRID_CONFIG;
	if (FileExists(file))
		DeleteFile(file);
	Application->MessageBox("取引データ入力を再起動して下さい", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    grid_cleared_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearButtonClick(TObject *Sender)
{
    TDateTime now(Now());
	dtpDateFrom->Date = now;
    dtpDateTo->Date   = now;

    place_id_       = MainForm->GetPlaceID();

    DM->PlaceIDMap.clear();
	PlaceCombo->Items->Clear();
    NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT 拠点ID, 拠点コード, 拠点名称 FROM M_拠点", set)){
		Application->MessageBox("拠点マスタが設定されていません。入力前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
    PlaceCombo->Items->Append("すべて");
	for (unsigned int i = 0; i < set.size(); i++){
        DM->PlaceIDMap[i + 1] = ToInt(set[i]["拠点ID"]);
		PlaceCombo->Items->Append(ToString(set[i]["拠点名称"]));
	}
    PlaceCombo->ItemIndex = 0;

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
        FilterPanel->Height = 136;
        FilterShowButton->Caption = "<<";
    }else{
        FilterPanel->Height = 61;
        FilterShowButton->Caption = ">>";
    }
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

