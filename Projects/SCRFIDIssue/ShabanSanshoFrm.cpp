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
	DBGrid->Columns->Items[3]->Title->Caption = ToString(DM->CFG["得意先マスタ名称"]);
	DBGrid->Columns->Items[4]->Title->Caption = ToString(DM->CFG["品目マスタ名称"]);
	DBGrid->Columns->Items[5]->Title->Caption = ToString(DM->CFG["項目1マスタ名称"]);
	DBGrid->Columns->Items[6]->Title->Caption = ToString(DM->CFG["項目2マスタ名称"]);

	DBGrid->SetFocus();
}
//---------------------------------------------------------------------------
int __fastcall TShabanSanshoForm::GetCarID()
{
	return car_id_;
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::NewButtonClick(TObject *Sender)
{
	car_id_   = 0;

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::OkButtonClick(TObject *Sender)
{
    TDataSet *Set = DBGrid->DataSource->DataSet;

	if (Set->Bof && Set->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	car_id_   = Set->FieldByName("車両ID")->AsInteger;

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TShabanSanshoForm::CancelButtonClick(TObject *Sender)
{
	ModalResult = mrCancel;
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

