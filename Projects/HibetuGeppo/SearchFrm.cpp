//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TSearchForm *SearchForm;
//---------------------------------------------------------------------------
__fastcall TSearchForm::TSearchForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSearchForm::FormCreate(TObject *Sender)
{
	list_ = new TStringList();
}
//---------------------------------------------------------------------------
void __fastcall TSearchForm::FormDestroy(TObject *Sender)
{
	delete list_;
}
//---------------------------------------------------------------------------
void __fastcall TSearchForm::FormShow(TObject *Sender)
{
	SetButtonEnabled();

	cedtSearch->Text = "";
	btnSearch->OnClick(NULL);
	cedtSearch->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSearchForm::btnOkClick(TObject *Sender)
{
	if (Query->RecordCount == 0)
		return;
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
// 実行ボタン
void __fastcall TSearchForm::btnSearchClick(TObject *Sender)
{
	Query->Close();
	if (cedtSearch->Text == ""){
		Query->SQL->Text = based_sql + orderby_sql;
	}else{
		if (based_sql.Pos("WHERE") == 0)
			Query->SQL->Text = based_sql + " WHERE " + DM->DBI.FullSearchSQL(cedtSearch->Text, table_name.c_str(), true) + orderby_sql;
		else
			Query->SQL->Text = based_sql + " AND " + DM->DBI.FullSearchSQL(cedtSearch->Text, table_name.c_str(), true) + orderby_sql;
	}
	Query->Open();
	DBGrid->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSearchForm::cedtSearchKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_RETURN)
		btnSearch->OnClick(NULL);
	if (Key == VK_ESCAPE)
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TSearchForm::DBGridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	if (DBGrid->DataSource->DataSet->RecordCount == 0)
		return;
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TSearchForm::DBGridDrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
	// DBGrid で一行おきに色を変える
	if (DBGrid->SelectedRows->CurrentRowSelected)
		;
	else if ((State.Empty() || ActiveControl != DBGrid) && DBGrid->DataSource->DataSet->RecNo % 2 == 0)
		DBGrid->Canvas->Brush->Color = TColor(0x00EBEBEB);

	DBGrid->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------
// 最初へ
void __fastcall TSearchForm::FirstButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->First();
}
//---------------------------------------------------------------------------
// 前へ
void __fastcall TSearchForm::PriorButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Prior();
}
//---------------------------------------------------------------------------
// 次へ
void __fastcall TSearchForm::NextButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Next();
}
//---------------------------------------------------------------------------
// 最後へ
void __fastcall TSearchForm::LastButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Last();
}
//---------------------------------------------------------------------------
// レコード移動ボタン(Enabled)
void __fastcall TSearchForm::SetButtonEnabled()
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
void __fastcall TSearchForm::QueryAfterScroll(TDataSet *DataSet)
{
	SetButtonEnabled();
}
//---------------------------------------------------------------------------

