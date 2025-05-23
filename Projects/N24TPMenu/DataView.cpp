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

	DBGrid->Columns->Items[0]->Title->Caption = ToString(DM->CFG["¾Óæ}X^¼Ì"]);
	DBGrid->Columns->Items[2]->Title->Caption = ToString(DM->CFG["Ú1}X^¼Ì"]);
	DBGrid->Columns->Items[3]->Title->Caption = ToString(DM->CFG["Ú2}X^¼Ì"]);
	DBGrid->Columns->Items[1]->Title->Caption = ToString(DM->CFG["iÚ}X^¼Ì"]);

	CloseButton->SetFocus();

	if (ADOQuery->Active)
		ADOQuery->Close();

	ADOQuery->SQL->Text = " SELECT"
						  " 	¾ÓæR[h, MAX(¾ÓæªÌ) AS ¾ÓæªÌ,"
						  " 	Ú1R[h,  MAX(Ú1ªÌ)  AS Ú1ªÌ,"
						  " 	Ú2R[h,  MAX(Ú2ªÌ)  AS Ú2ªÌ,"
						  " 	iÚR[h,   MAX(iÚªÌ)   AS iÚªÌ,"
						  " 	COUNT(vÊID) AS , SUM(³¡dÊ) AS vdÊ"
						  " FROM V_vÊ"
						  " WHERE vÊú = " + Now().FormatString("yyyymmdd") +
                          "   AND _ID = " + IntToStr(N24TP::place_id) +
                          "   AND ®¹æª = 1"
						  " GROUP BY ¾ÓæR[h, Ú1R[h, Ú2R[h, iÚR[h"
						  " ORDER BY ¾ÓæR[h, Ú1R[h, Ú2R[h, iÚR[h";
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

