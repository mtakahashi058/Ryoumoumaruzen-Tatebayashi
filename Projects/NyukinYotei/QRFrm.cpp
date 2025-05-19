//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include "QRFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRForm *QRForm;
//---------------------------------------------------------------------------
__fastcall TQRForm::TQRForm(TComponent* Owner)
	: TForm(Owner)
{
	field_name[0][0] = "”„ã0";
	field_name[0][1] = "”„ã1";
	field_name[0][2] = "”„ã2";
	field_name[0][3] = "”„ã3";
	field_name[0][4] = "”„ã4";
	field_name[0][5] = "”„ã5";
	field_name[0][6] = "c‚6";

	field_name[1][0] = "”„Š|c0";
	field_name[1][1] = "”„Š|c1";
	field_name[1][2] = "”„Š|c2";
	field_name[1][3] = "”„Š|c3";
	field_name[1][4] = "”„Š|c4";
	field_name[1][5] = "”„Š|c5";
	field_name[1][6] = "”„Š|c6";
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::Query_CalcFields(TDataSet *DataSet)
{
/*
	if (Query->FieldByName("“¾ˆÓæƒR[ƒh")->AsString == "000058")
		kuri[0] = 0;
*/
/*
	// “¾ˆÓæ–¼Ì•ªŠ„
	AnsiString toku_name = Query->FieldByName("“¾ˆÓæ–¼Ì")->AsString;
	Query->FieldByName("“¾ˆÓæ–¼Ì1")->AsString = AnsiDivide(&toku_name, 26);
	Query->FieldByName("“¾ˆÓæ–¼Ì2")->AsString = toku_name;

	// c‚
	int sime = Query->FieldByName("’÷Ø“ú")->AsInteger;
	if (sime == 0)
		sime = DateToInt(GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	// ÅI’÷Ø“ú‚ª‚Uƒ•Œ‘O‚Å‚È‚¢ê‡A‚Uƒ•ŒŠÔ‚ÅÅ‰‚Ì’÷Ø“ú‚Ì”„ãŠz‚ÉŒJ‰zŠz‚ğ‘«‚·
	for (int i = 0; i < 6; i++)
		kuri[i] = 0;
	int edate6 = DateToInt(GetLastDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	if (sime > edate6){
		NsFieldSet keys;
		keys	<< NsField("¿‹æID", Query->FieldByName("“¾ˆÓæID")->AsInteger)
			<< NsField("’÷Ø“ú",   sime);

		if      (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -5)))
			kuri[5] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -4)))
			kuri[4] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -3)))
			kuri[3] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -2)))
			kuri[2] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -1)))
			kuri[1] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(MainForm->DateFromPicker->Date))
			kuri[0] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
	}

	// “ü‹à
	AnsiString sql =	"SELECT SUM(Œ»‹à) + SUM(U) + SUM(è”—¿) + SUM(¬Øè) + SUM(èŒ`) + SUM(‘ŠE) + SUM(’lˆø‚«) + SUM(’²®) + SUM(‚»‚Ì‘¼) AS “ü‹àŒv "
				"FROM D_“ü‹à "
				"WHERE “ü‹à“ú BETWEEN " + IntToStr(sime) + " AND " + IntToStr(DateToInt(MainForm->DateToPicker->Date)) + " "
				"AND ¿‹æID = " + IntToStr(Query->FieldByName("“¾ˆÓæID")->AsInteger);
	NsRecordSet set;
	Currency nyukin = 0;
	if (DM->DBI.GetRecordSet(sql, set))
		nyukin = ToCurrency(set[0]["“ü‹àŒv"]);

	// ”„Š|ŠzZo
	Currency kake;
	for (int i = 6; i >= 0; i--){
		kake = Query->FieldByName(field_name[0][i])->AsCurrency;

		if (i != 6)	// ‚Uƒ•Œ‘O‚Ì¿‹Šz‚ª‚È‚¢ê‡AÅ‰‚Ì’÷Ø“ú‚ÌŒJ‰zŠz‚ğƒvƒ‰ƒX‚·‚é
			kake += kuri[i];

		if (kake <= nyukin){
			Query->FieldByName(field_name[1][i])->AsCurrency = 0;
			nyukin = nyukin - kake;
		}else{
			Query->FieldByName(field_name[1][i])->AsCurrency = kake - nyukin;
			nyukin = 0;
		}
	}

	// ‰ñû—\’èŠz
	Currency kaishu = 0;
	for (int i = 6; i >= Query->FieldByName("“ü‹àƒTƒCƒg")->AsInteger; i--)
		kaishu += Query->FieldByName(field_name[1][i])->AsCurrency;
	Query->FieldByName("‰ñû—\’èŠz")->AsCurrency = kaishu;
*/
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QueryCalcFields(TDataSet *DataSet)
{
	// “¾ˆÓæ–¼Ì•ªŠ„
	AnsiString toku_name = Query->FieldByName("“¾ˆÓæ–¼Ì")->AsString;
	Query->FieldByName("“¾ˆÓæ–¼Ì1")->AsString = AnsiDivide(&toku_name, 26);
	Query->FieldByName("“¾ˆÓæ–¼Ì2")->AsString = toku_name;

	// c‚
	int sime = Query->FieldByName("’÷Ø“ú")->AsInteger;
	if (sime == 0)
		sime = DateToInt(GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	// ÅI’÷Ø“ú‚ª‚Uƒ•Œ‘O‚Å‚È‚¢ê‡A‚Uƒ•ŒŠÔ‚ÅÅ‰‚Ì’÷Ø“ú‚Ì”„ãŠz‚ÉŒJ‰zŠz‚ğ‘«‚·
	for (int i = 0; i < 6; i++)
		kuri[i] = 0;
	int edate6 = DateToInt(GetLastDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	if (sime > edate6){
		NsFieldSet keys;
		keys	<< NsField("¿‹æID", Query->FieldByName("“¾ˆÓæID")->AsInteger)
			<< NsField("’÷Ø“ú",   sime);

		if      (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -5)))
			kuri[5] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -4)))
			kuri[4] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -3)))
			kuri[3] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -2)))
			kuri[2] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -1)))
			kuri[1] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(MainForm->DateFromPicker->Date))
			kuri[0] = ToCurrency(DM->DBI.Lookup("D_¿‹", keys, "¡‰ñŒJ‰zŠz"));
	}

	// “ü‹à
	AnsiString sql =	"SELECT SUM(Œ»‹à) + SUM(U) + SUM(è”—¿) + SUM(¬Øè) + SUM(èŒ`) + SUM(‘ŠE) + SUM(’lˆø‚«) + SUM(’²®) + SUM(‚»‚Ì‘¼) AS “ü‹àŒv "
						"FROM D_“ü‹à "
						"WHERE “ü‹à“ú > " + IntToStr(sime) + " "
						//"WHERE “ü‹à“ú BETWEEN " + IntToStr(sime) + " AND " + IntToStr(DateToInt(MainForm->DateToPicker->Date)) + " "
						"AND ¿‹æID = " + IntToStr(Query->FieldByName("“¾ˆÓæID")->AsInteger);
	NsRecordSet set;
	Currency nyukin = 0;
	if (DM->DBI.GetRecordSet(sql, set))
		nyukin = ToCurrency(set[0]["“ü‹àŒv"]);

	// ”„Š|ŠzZo
	Currency kake;
	for (int i = 6; i >= 0; i--){
		kake = Query->FieldByName(field_name[0][i])->AsCurrency;

		if (i != 6)	// ‚Uƒ•Œ‘O‚Ì¿‹Šz‚ª‚È‚¢ê‡AÅ‰‚Ì’÷Ø“ú‚ÌŒJ‰zŠz‚ğƒvƒ‰ƒX‚·‚é
			kake += kuri[i];

		if (kake <= nyukin){
			Query->FieldByName(field_name[1][i])->AsCurrency = 0;
			nyukin = nyukin - kake;
		}else{
			Query->FieldByName(field_name[1][i])->AsCurrency = kake - nyukin;
			nyukin = 0;
		}
	}

	// ‰ñû—\’èŠz
	Currency kaishu = 0;
	for (int i = 6; i >= Query->FieldByName("“ü‹àƒTƒCƒg")->AsInteger; i--)
		kaishu += Query->FieldByName(field_name[1][i])->AsCurrency;
	Query->FieldByName("‰ñû—\’èŠz")->AsCurrency = kaishu;
}
//---------------------------------------------------------------------------

void __fastcall TQRForm::DetailBand1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	// –¢“ü‹à‚Ìê‡A‹àŠz‚ÉF•t‚¯
	int site_month = Query->FieldByName("“ü‹àƒTƒCƒg")->AsInteger;
	int site_date  = Query->FieldByName("“ü‹à“ú")->AsInteger;

	QRDBTextZan6->Color = GetLabelColor(6, site_month, site_date);
	QRDBTextZan5->Color = GetLabelColor(5, site_month, site_date);
	QRDBTextZan4->Color = GetLabelColor(4, site_month, site_date);
	QRDBTextZan3->Color = GetLabelColor(3, site_month, site_date);
	QRDBTextZan2->Color = GetLabelColor(2, site_month, site_date);
	QRDBTextZan1->Color = GetLabelColor(1, site_month, site_date);
	QRDBTextZan0->Color = GetLabelColor(0, site_month, site_date);
}
//---------------------------------------------------------------------------
TColor __fastcall TQRForm::GetLabelColor(int label_no, int site_month, int site_date)
{
	AnsiString fname = "”„Š|c" + IntToStr(label_no);
	if (Query->FieldByName(fname)->AsCurrency == 0)
		return clWhite;

	int today_date = Date().FormatString("d").ToIntDef(0);

	if (label_no > site_month)
		return clSilver;
	else if (label_no < site_month)
		return clWhite;
	else if (site_date <= today_date)
		return clSilver;
	else
		return clWhite;
}
//---------------------------------------------------------------------------

