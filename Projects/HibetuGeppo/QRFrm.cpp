//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRForm *QRForm;
//---------------------------------------------------------------------------
__fastcall TQRForm::TQRForm(TComponent* Owner)
	: TForm(Owner)
{
	dt_label[0]  = DateLabel01;
	dt_label[1]  = DateLabel02;
	dt_label[2]  = DateLabel03;
	dt_label[3]  = DateLabel04;
	dt_label[4]  = DateLabel05;
	dt_label[5]  = DateLabel06;
	dt_label[6]  = DateLabel07;
	dt_label[7]  = DateLabel08;
	dt_label[8]  = DateLabel09;
	dt_label[9]  = DateLabel10;
	dt_label[10] = DateLabel11;
	dt_label[11] = DateLabel12;
	dt_label[12] = DateLabel13;
	dt_label[13] = DateLabel14;
	dt_label[14] = DateLabel15;
	dt_label[15] = DateLabel16;
	dt_label[16] = DateLabel17;
	dt_label[17] = DateLabel18;
	dt_label[18] = DateLabel19;
	dt_label[19] = DateLabel20;
	dt_label[20] = DateLabel21;
	dt_label[21] = DateLabel22;
	dt_label[22] = DateLabel23;
	dt_label[23] = DateLabel24;
	dt_label[24] = DateLabel25;
	dt_label[25] = DateLabel26;
	dt_label[26] = DateLabel27;
	dt_label[27] = DateLabel28;
	dt_label[28] = DateLabel29;
	dt_label[29] = DateLabel30;
	dt_label[30] = DateLabel31;
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QuickRepBeforePrint(TCustomQuickRep *Sender,
      bool &PrintReport)
{
	QRGroup1->Height = 0;
	DetailBand1->Height = 659;
	QRBand1->Height = 0;
	QRChildBand1->Height = 659;

	// 日付
    TDateTime tmp_dt = GetFirstDate(dt);
	for (int i = 1; i <= 31; i++){
		if (tmp_dt.FormatString("d") == IntToStr(i))
			dt_label[i - 1]->Caption = tmp_dt.FormatString("dd") + "日(" + GetWeekStr(DayOfWeek(tmp_dt)) + ")";
		else
			dt_label[i - 1]->Caption = AnsiString();
		tmp_dt++;
	}
}
//---------------------------------------------------------------------------
// 曜日インデックスから曜日(文字)を返す
AnsiString __fastcall TQRForm::GetWeekStr(int no)
{
	if (no == 1)
		return "日";
	else if (no == 2)
		return "月";
	else if (no == 3)
		return "火";
	else if (no == 4)
		return "水";
	else if (no == 5)
		return "木";
	else if (no == 6)
		return "金";
	else if (no == 7)
		return "土";
	else
		return AnsiString();
}
//---------------------------------------------------------------------------

