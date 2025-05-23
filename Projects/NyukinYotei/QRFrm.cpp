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
	field_name[0][0] = "売上0";
	field_name[0][1] = "売上1";
	field_name[0][2] = "売上2";
	field_name[0][3] = "売上3";
	field_name[0][4] = "売上4";
	field_name[0][5] = "売上5";
	field_name[0][6] = "残高6";

	field_name[1][0] = "売掛残0";
	field_name[1][1] = "売掛残1";
	field_name[1][2] = "売掛残2";
	field_name[1][3] = "売掛残3";
	field_name[1][4] = "売掛残4";
	field_name[1][5] = "売掛残5";
	field_name[1][6] = "売掛残6";
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::Query_CalcFields(TDataSet *DataSet)
{
/*
	if (Query->FieldByName("得意先コード")->AsString == "000058")
		kuri[0] = 0;
*/
/*
	// 得意先名称分割
	AnsiString toku_name = Query->FieldByName("得意先名称")->AsString;
	Query->FieldByName("得意先名称1")->AsString = AnsiDivide(&toku_name, 26);
	Query->FieldByName("得意先名称2")->AsString = toku_name;

	// 残高
	int sime = Query->FieldByName("締切日")->AsInteger;
	if (sime == 0)
		sime = DateToInt(GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	// 最終締切日が６ヵ月前でない場合、６ヵ月間で最初の締切日の売上額に繰越額を足す
	for (int i = 0; i < 6; i++)
		kuri[i] = 0;
	int edate6 = DateToInt(GetLastDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	if (sime > edate6){
		NsFieldSet keys;
		keys	<< NsField("請求先ID", Query->FieldByName("得意先ID")->AsInteger)
			<< NsField("締切日",   sime);

		if      (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -5)))
			kuri[5] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -4)))
			kuri[4] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -3)))
			kuri[3] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -2)))
			kuri[2] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -1)))
			kuri[1] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(MainForm->DateFromPicker->Date))
			kuri[0] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
	}

	// 入金
	AnsiString sql =	"SELECT SUM(現金) + SUM(振込) + SUM(手数料) + SUM(小切手) + SUM(手形) + SUM(相殺) + SUM(値引き) + SUM(調整) + SUM(その他) AS 入金計 "
				"FROM D_入金 "
				"WHERE 入金日 BETWEEN " + IntToStr(sime) + " AND " + IntToStr(DateToInt(MainForm->DateToPicker->Date)) + " "
				"AND 請求先ID = " + IntToStr(Query->FieldByName("得意先ID")->AsInteger);
	NsRecordSet set;
	Currency nyukin = 0;
	if (DM->DBI.GetRecordSet(sql, set))
		nyukin = ToCurrency(set[0]["入金計"]);

	// 売掛額算出
	Currency kake;
	for (int i = 6; i >= 0; i--){
		kake = Query->FieldByName(field_name[0][i])->AsCurrency;

		if (i != 6)	// ６ヵ月前の請求額がない場合、最初の締切日の繰越額をプラスする
			kake += kuri[i];

		if (kake <= nyukin){
			Query->FieldByName(field_name[1][i])->AsCurrency = 0;
			nyukin = nyukin - kake;
		}else{
			Query->FieldByName(field_name[1][i])->AsCurrency = kake - nyukin;
			nyukin = 0;
		}
	}

	// 回収予定額
	Currency kaishu = 0;
	for (int i = 6; i >= Query->FieldByName("入金サイト")->AsInteger; i--)
		kaishu += Query->FieldByName(field_name[1][i])->AsCurrency;
	Query->FieldByName("回収予定額")->AsCurrency = kaishu;
*/
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QueryCalcFields(TDataSet *DataSet)
{
	// 得意先名称分割
	AnsiString toku_name = Query->FieldByName("得意先名称")->AsString;
	Query->FieldByName("得意先名称1")->AsString = AnsiDivide(&toku_name, 26);
	Query->FieldByName("得意先名称2")->AsString = toku_name;

	// 残高
	int sime = Query->FieldByName("締切日")->AsInteger;
	if (sime == 0)
		sime = DateToInt(GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	// 最終締切日が６ヵ月前でない場合、６ヵ月間で最初の締切日の売上額に繰越額を足す
	for (int i = 0; i < 6; i++)
		kuri[i] = 0;
	int edate6 = DateToInt(GetLastDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	if (sime > edate6){
		NsFieldSet keys;
		keys	<< NsField("請求先ID", Query->FieldByName("得意先ID")->AsInteger)
			<< NsField("締切日",   sime);

		if      (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -5)))
			kuri[5] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -4)))
			kuri[4] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -3)))
			kuri[3] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -2)))
			kuri[2] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -1)))
			kuri[1] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(MainForm->DateFromPicker->Date))
			kuri[0] = ToCurrency(DM->DBI.Lookup("D_請求", keys, "今回繰越額"));
	}

	// 入金
	AnsiString sql =	"SELECT SUM(現金) + SUM(振込) + SUM(手数料) + SUM(小切手) + SUM(手形) + SUM(相殺) + SUM(値引き) + SUM(調整) + SUM(その他) AS 入金計 "
						"FROM D_入金 "
						"WHERE 入金日 > " + IntToStr(sime) + " "
						//"WHERE 入金日 BETWEEN " + IntToStr(sime) + " AND " + IntToStr(DateToInt(MainForm->DateToPicker->Date)) + " "
						"AND 請求先ID = " + IntToStr(Query->FieldByName("得意先ID")->AsInteger);
	NsRecordSet set;
	Currency nyukin = 0;
	if (DM->DBI.GetRecordSet(sql, set))
		nyukin = ToCurrency(set[0]["入金計"]);

	// 売掛額算出
	Currency kake;
	for (int i = 6; i >= 0; i--){
		kake = Query->FieldByName(field_name[0][i])->AsCurrency;

		if (i != 6)	// ６ヵ月前の請求額がない場合、最初の締切日の繰越額をプラスする
			kake += kuri[i];

		if (kake <= nyukin){
			Query->FieldByName(field_name[1][i])->AsCurrency = 0;
			nyukin = nyukin - kake;
		}else{
			Query->FieldByName(field_name[1][i])->AsCurrency = kake - nyukin;
			nyukin = 0;
		}
	}

	// 回収予定額
	Currency kaishu = 0;
	for (int i = 6; i >= Query->FieldByName("入金サイト")->AsInteger; i--)
		kaishu += Query->FieldByName(field_name[1][i])->AsCurrency;
	Query->FieldByName("回収予定額")->AsCurrency = kaishu;
}
//---------------------------------------------------------------------------

void __fastcall TQRForm::DetailBand1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	// 未入金の場合、金額に色付け
	int site_month = Query->FieldByName("入金サイト")->AsInteger;
	int site_date  = Query->FieldByName("入金日")->AsInteger;

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
	AnsiString fname = "売掛残" + IntToStr(label_no);
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

