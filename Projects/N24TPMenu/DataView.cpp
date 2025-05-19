//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataView.h"
#include "DMFrm.h"
#include "n24tp.h"
#include <string>
#include <fstream>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataViewForm *DataViewForm;
//---------------------------------------------------------------------------
__fastcall TDataViewForm::TDataViewForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	DBGrid->Columns->Items[0]->Title->Caption = ToString(DM->CFG["得意先マスタ名称"]);
	DBGrid->Columns->Items[2]->Title->Caption = ToString(DM->CFG["項目1マスタ名称"]);
	DBGrid->Columns->Items[3]->Title->Caption = ToString(DM->CFG["項目2マスタ名称"]);
	DBGrid->Columns->Items[1]->Title->Caption = ToString(DM->CFG["品目マスタ名称"]);

	CloseButton->SetFocus();

	if (ADOQuery->Active)
		ADOQuery->Close();

	ADOQuery->SQL->Text = " SELECT"
						  " 	得意先コード, MAX(得意先略称) AS 得意先略称,"
						  " 	項目1コード,  MAX(項目1略称)  AS 項目1略称,"
						  " 	項目2コード,  MAX(項目2略称)  AS 項目2略称,"
						  " 	品目コード,   MAX(品目略称)   AS 品目略称,"
						  " 	COUNT(計量ID) AS 件数, SUM(正味重量) AS 合計重量"
						  " FROM V_計量"
						  " WHERE 計量日 = " + Now().FormatString("yyyymmdd") +
                          "   AND 拠点ID = " + IntToStr(N24TP::place_id) +
                          "   AND 完了区分 = 1"
						  " GROUP BY 得意先コード, 項目1コード, 項目2コード, 品目コード"
						  " ORDER BY 得意先コード, 項目1コード, 項目2コード, 品目コード";
	ADOQuery->Open();
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::CloseButtonClick(TObject *Sender)
{
	ADOQuery->Open();
	
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::DBGridDrawColumnCell(TObject *Sender,
	  const TRect &Rect, int DataCol, TColumn *Column,
	  TGridDrawState State)
{
	bool custom_draw = false;

	if (State.Empty() || ActiveControl != DBGrid){
		custom_draw = true;
	}

	if (custom_draw){
		int rec_no = DBGrid->DataSource->DataSet->RecNo;
		if (rec_no % 2 == 1)
			DBGrid->Canvas->Brush->Color = TColor(0x00fbf7f6);
	}

	DBGrid->DefaultDrawColumnCell(Rect, DataCol, Column, State);

	if (custom_draw){
		DBGrid->Canvas->Pen->Color = clSilver;
		DBGrid->Canvas->Pen->Style = psSolid;
		DBGrid->Canvas->MoveTo(Rect.Left, Rect.Top);
		DBGrid->Canvas->LineTo(Rect.Right, Rect.Top);
		DBGrid->Canvas->Pen->Style = psSolid;
	}

	if (DBGrid->DataSource->DataSet->RecNo == DBGrid->DataSource->DataSet->RecordCount){
		DBGrid->Canvas->Pen->Color = clSilver;
		DBGrid->Canvas->Pen->Style = psSolid;
		DBGrid->Canvas->MoveTo(Rect.Left, Rect.Bottom - 1);
		DBGrid->Canvas->LineTo(Rect.Right, Rect.Bottom  -1);
		DBGrid->Canvas->Pen->Style = psSolid;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::PriorButtonClick(TObject *Sender)
{
	try{ADOQuery->Prior();}catch(...){}
}
//---------------------------------------------------------------------------
void __fastcall TDataViewForm::NextButtonClick(TObject *Sender)
{
	try{ADOQuery->Next();}catch(...){}
}
//---------------------------------------------------------------------------

