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

	DBGrid->Columns->Items[0]->Title->Caption = ToString(DM->CFG["���Ӑ�}�X�^����"]);
	DBGrid->Columns->Items[2]->Title->Caption = ToString(DM->CFG["����1�}�X�^����"]);
	DBGrid->Columns->Items[3]->Title->Caption = ToString(DM->CFG["����2�}�X�^����"]);
	DBGrid->Columns->Items[1]->Title->Caption = ToString(DM->CFG["�i�ڃ}�X�^����"]);

	CloseButton->SetFocus();

	if (ADOQuery->Active)
		ADOQuery->Close();

	ADOQuery->SQL->Text = " SELECT"
						  " 	���Ӑ�R�[�h, MAX(���Ӑ旪��) AS ���Ӑ旪��,"
						  " 	����1�R�[�h,  MAX(����1����)  AS ����1����,"
						  " 	����2�R�[�h,  MAX(����2����)  AS ����2����,"
						  " 	�i�ڃR�[�h,   MAX(�i�ڗ���)   AS �i�ڗ���,"
						  " 	COUNT(�v��ID) AS ����, SUM(�����d��) AS ���v�d��"
						  " FROM V_�v��"
						  " WHERE �v�ʓ� = " + Now().FormatString("yyyymmdd") +
                          "   AND ���_ID = " + IntToStr(N24TP::place_id) +
                          "   AND �����敪 = 1"
						  " GROUP BY ���Ӑ�R�[�h, ����1�R�[�h, ����2�R�[�h, �i�ڃR�[�h"
						  " ORDER BY ���Ӑ�R�[�h, ����1�R�[�h, ����2�R�[�h, �i�ڃR�[�h";
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

