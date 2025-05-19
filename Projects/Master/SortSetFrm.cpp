//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SortSetFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSortSetForm *SortSetForm;
//---------------------------------------------------------------------------
__fastcall TSortSetForm::TSortSetForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSortSetForm::FormShow(TObject *Sender)
{
    // 初期設定
    ItemComboBox1->Clear();
    ItemComboBox2->Clear();
    ItemComboBox3->Clear();
    ItemComboBox1->Items->Add("");
    ItemComboBox2->Items->Add("");
    ItemComboBox3->Items->Add("");
    fields_map_[0] = "";

    for (int i = 0; i < grid_->Columns->Count; i++){
        if (grid_->Columns->Items[i]->Title->Caption != "*"){
            ItemComboBox1->Items->Add(grid_->Columns->Items[i]->Title->Caption);
            ItemComboBox2->Items->Add(grid_->Columns->Items[i]->Title->Caption);
            ItemComboBox3->Items->Add(grid_->Columns->Items[i]->Title->Caption);
        }else{
            ItemComboBox1->Items->Add(grid_->DataSource->DataSet->FieldByName(grid_->Columns->Items[i]->FieldName)->DisplayLabel);
            ItemComboBox2->Items->Add(grid_->DataSource->DataSet->FieldByName(grid_->Columns->Items[i]->FieldName)->DisplayLabel);
            ItemComboBox3->Items->Add(grid_->DataSource->DataSet->FieldByName(grid_->Columns->Items[i]->FieldName)->DisplayLabel);
        }

        fields_map_[i + 1] = grid_->Columns->Items[i]->FieldName;
    }

    ItemComboBox1->ItemIndex = 0;
    ItemComboBox2->ItemIndex = 0;
    ItemComboBox3->ItemIndex = 0;
    SortComboBox1->ItemIndex = 0;
    SortComboBox2->ItemIndex = 0;
    SortComboBox3->ItemIndex = 0;
}
//---------------------------------------------------------------------------
// F5 設定
void __fastcall TSortSetForm::Action5Execute(TObject *Sender)
{
    int index1, index2, index3;
    index1 = ItemComboBox1->ItemIndex;
    index2 = ItemComboBox2->ItemIndex;
    index3 = ItemComboBox3->ItemIndex;

    // ItemIndexが0以外で同じ項目が選択されていないかチェック
    if ((index1 == index2 && index1 != 0 && index2 != 0)
            || (index1 == index3 && index1 != 0 && index3 != 0)
            || (index2 == index3 && index2 != 0 && index3 != 0)){
        Application->MessageBox("同じ項目が選択されています\r\n別の項目を選択してください", "並び替え項目設定", MB_OK | MB_ICONWARNING);
        ItemComboBox1->SetFocus();
        return;
    }

    item1 = fields_map_[ItemComboBox1->ItemIndex];
    item2 = fields_map_[ItemComboBox2->ItemIndex];
    item3 = fields_map_[ItemComboBox3->ItemIndex];

    desc1 = SortComboBox1->ItemIndex;
    desc2 = SortComboBox1->ItemIndex;
    desc3 = SortComboBox1->ItemIndex;

    // ORDER文作成
    orderby_sql = AnsiString();
    if (item1 != ""){
        orderby_sql += item1;
        if (desc1)
            orderby_sql += " DESC";
    }

    if (item2 != ""){
        if (orderby_sql != "")
            orderby_sql += ", ";

        orderby_sql += item2;
        if (desc2)
            orderby_sql += " DESC";
    }

    if (item3 != ""){
        if (orderby_sql != "")
            orderby_sql += ", ";

        orderby_sql += item3;
        if (desc3)
            orderby_sql += " DESC";
    }

    if (orderby_sql != "")
        orderby_sql = " ORDER BY " + orderby_sql;

    ModalResult = mrYes;
}
//---------------------------------------------------------------------------
// F12 閉じる
void __fastcall TSortSetForm::Action12Execute(TObject *Sender)
{
    ModalResult = mrNo;
}
//---------------------------------------------------------------------------
void __fastcall TSortSetForm::SeikyushoPrintPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TSortSetForm::SeikyushoPrintPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

