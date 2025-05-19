//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "ShabanSanshoFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TShabanSanshoForm *ShabanSanshoForm;
//---------------------------------------------------------------------------
__fastcall TShabanSanshoForm::TShabanSanshoForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::FormShow(TObject *Sender)
{
	DBGrid->Columns->Items[4]->Title->Caption  = ToString(DM->CFG["得意先マスタ名称"]);
	DBGrid->Columns->Items[5]->Title->Caption  = ToString(DM->CFG["項目1マスタ名称"]);
	DBGrid->Columns->Items[6]->Title->Caption = ToString(DM->CFG["項目2マスタ名称"]);
	DBGrid->Columns->Items[7]->Title->Caption = ToString(DM->CFG["品目マスタ名称"]);

    if (TopPanel->Caption.IsEmpty())
        DBGrid->Columns->Items[1]->Visible = true;
    else
        DBGrid->Columns->Items[1]->Visible = false;

	DBGrid->SetFocus();
}
//---------------------------------------------------------------------------
int __fastcall TShabanSanshoForm::GetCarID()
{
	return car_id_;
}
//---------------------------------------------------------------------------
int __fastcall TShabanSanshoForm::GetCarNo()
{
	return car_no_;
}
//---------------------------------------------------------------------------
int __fastcall TShabanSanshoForm::GetDataDiv()
{
	return data_div_;
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::OkButtonClick(TObject *Sender)
{
	if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	car_id_   = DM->Q_Shaban->FieldByName("車両ID")->AsInteger;
    car_no_   = DM->Q_Shaban->FieldByName("車番")->AsInteger;
	data_div_ = DM->Q_Shaban->FieldByName("車両分類コード")->AsInteger;

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::CancelButtonClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::NewButtonClick(TObject *Sender)
{
	car_id_   = 0;
    car_no_   = 0;
	data_div_ = 0;

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::DBGridDblClick(TObject *Sender)
{
	OkButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::DBGridKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	OkButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::DBGridDrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
	// DBGrid で一行おきに色を変える
	if (DBGrid->SelectedRows->CurrentRowSelected) //|| DBGrid->Columns->Items[DataCol]->Color != DBGrid->Color)
		;
	else if (DBGrid->DataSource->DataSet->FieldByName("車両分類名")->AsString == "滞留"){
		DBGrid->Canvas->Brush->Color = TColor(0x00A6FFFF);

	}else if ((State.Empty() || ActiveControl != DBGrid) && DBGrid->DataSource->DataSet->RecNo % 2 == 0)
		DBGrid->Canvas->Brush->Color = TColor(0x00EBEBEB);

	DBGrid->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_F1)
		NewButton->Click();
	else if (Key == VK_ESCAPE)
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

