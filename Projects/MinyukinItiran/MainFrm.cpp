//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Connected = false;

	try{
		DM->ADOConnection->Connected = true;
	}catch (Exception& e){
		Application->MessageBox(("データベースへの接続に失敗しました\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

	MainForm->Resize();
	MonthPicker->Date    = GetFirstDate(Date());
	DateFromPicker->Date = GetFirstDate(Date());
	DateToPicker->Date   = GetLastDate(Date());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MonthPickerChange(TObject *Sender)
{
	DateFromPicker->Date = GetFirstDate(MonthPicker->Date);
	DateToPicker->Date   = GetLastDate(MonthPicker->Date);
}
//---------------------------------------------------------------------------
// 前範囲
void __fastcall TMainForm::PrevButtonClick(TObject *Sender)
{
	MonthPicker->Date = IncMonth(MonthPicker->Date, -1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// 後範囲
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	MonthPicker->Date = IncMonth(MonthPicker->Date, 1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// MainForm->Resize
void __fastcall TMainForm::FormResize(TObject *Sender)
{
	int interval = 10;
	btnF1->Width = int((MainForm->Width - interval * 4) / 12);
	btnF2->Width = int((MainForm->Width - interval * 4) / 12);
	btnF3->Width = int((MainForm->Width - interval * 4) / 12);
	btnF4->Width = int((MainForm->Width - interval * 4) / 12);
	btnF5->Width = int((MainForm->Width - interval * 4) / 12);
	btnF6->Width = int((MainForm->Width - interval * 4) / 12);
	btnF7->Width = int((MainForm->Width - interval * 4) / 12);
	btnF8->Width = int((MainForm->Width - interval * 4) / 12);
	btnF9->Width = int((MainForm->Width - interval * 4) / 12);
	btnF10->Width = int((MainForm->Width - interval * 4) / 12);
	btnF11->Width = int((MainForm->Width - interval * 4) / 12);
	btnF12->Width = int((MainForm->Width - interval * 4) / 12);

	btnF1->Left = interval;
	btnF2->Left = btnF1->Left + btnF1->Width - 1;
	btnF3->Left = btnF2->Left + btnF2->Width - 1;
	btnF4->Left = btnF3->Left + btnF3->Width - 1;
	btnF5->Left = btnF4->Left + btnF4->Width - 1 + interval;
	btnF6->Left = btnF5->Left + btnF5->Width - 1;
	btnF7->Left = btnF6->Left + btnF6->Width - 1;
	btnF8->Left = btnF7->Left + btnF7->Width - 1;
	btnF9->Left = btnF8->Left + btnF8->Width - 1 + interval;
	btnF10->Left = btnF9->Left + btnF9->Width - 1;
	btnF11->Left = btnF10->Left + btnF10->Width - 1;
	btnF12->Left = btnF11->Left + btnF11->Width - 1;
}
//---------------------------------------------------------------------------
// F9 印刷
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (Application->MessageBox("印刷しますか？", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	if (!SetRange())
		return;
	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
// F10 プレビュー
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (!SetRange())
		return;
	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetNyukinQuery(int date, int id)
{
	return
		" SELECT"
		" 	請求先ID,"
		" 	SUM(現金) + SUM(振込) + SUM(手数料) + SUM(小切手) + SUM(手形) + SUM(相殺) + SUM(値引き) + SUM(調整) + SUM(その他) AS 入金額"
		" FROM"
		" 	D_入金"
		" WHERE"
		" 	入金日 > " + IntToStr(date) +
		" AND"
		" 	請求先ID = " + IntToStr(id) +
		" GROUP BY"
		" 	請求先ID";
}
//---------------------------------------------------------------------------
// クエリの範囲設定
bool __fastcall TMainForm::SetRange()
{
	NsRecordSet set, nyukin_set;
	try{
		QRForm->Query->Close();

		// 一時テーブルが存在する場合DROPする
		set.clear();
		DM->DBI.GetRecordSet("SELECT CASE WHEN object_id('tempdb..#MINYULIST', 'U') IS NOT NULL THEN 1 ELSE 0 END AS FLAG", set);
		if (ToBit(set[0]["FLAG"]))
			DM->DBI.Execute("DROP TABLE #MINYULIST");

		// 仮想計算項目「入金額」「不足額」を含む一時テーブルを作成
		AnsiString sql =
			" DECLARE @DATE_FROM AS [DECIMAL]"
			" DECLARE @DATE_TO   AS [DECIMAL]"
			" SET @DATE_FROM = " + DateFromPicker->Date.FormatString("yyyymmdd") +
			" SET @DATE_TO   = " + DateToPicker->Date.FormatString("yyyymmdd") +
			" "
			" SELECT"
			" 	請求ID,"
			" 	請求先ID, 請求先コード, 請求先名称,"
			" 	締切日,"
			" 	入金予定日,"
			" 	今回請求額,"
			" 	CAST(NULL AS DECIMAL) AS 入金額,"
			" 	CAST(NULL AS DECIMAL) AS 不足額"
			" INTO	#MINYULIST"
			" FROM"
			" 	("
			" 	SELECT"
			" 		請求ID,"
			" 		請求先ID, 得意先コード AS 請求先コード, 得意先名称 AS 請求先名称,"
			" 		締切日, 入金予定日, 今回請求額"
			" 	FROM"
			" 		V_請求"
			" 	WHERE"
			" 		入金予定日 BETWEEN @DATE_FROM AND @DATE_TO"
			" 	) AS  X";

		// 一時テーブル作成
		DM->DBI.Execute(sql);

		set.clear();
		if (!DM->DBI.GetRecordSet("SELECT * FROM #MINYULIST", set)){
			Application->MessageBox("該当範囲の未入金データがありません",
				this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}

		// 仮想計算項目を補完
		for (unsigned int i = 0; i < set.size(); i++){
			nyukin_set.clear();
			if (!DM->DBI.GetRecordSet(GetNyukinQuery(ToInt(set[i]["締切日"]), ToInt(set[i]["請求先ID"])), nyukin_set)){
				sql = "UPDATE #MINYULIST SET 入金額 = 0, 不足額 = " + CurrToStr(ToCurrency(set[i]["今回請求額"])) +
					  " WHERE 請求ID = " + IntToStr(ToInt(set[i]["請求ID"]));
			}else{
				sql = "UPDATE #MINYULIST SET 入金額 = " + CurrToStr(ToCurrency(nyukin_set[0]["入金額"])) +
					  ", 不足額 = " + CurrToStr(ToCurrency(set[i]["今回請求額"]) - ToCurrency(nyukin_set[0]["入金額"])) +
					  " WHERE 請求ID = " + IntToStr(ToInt(set[i]["請求ID"]));
			}
			DM->DBI.Execute(sql);
		}

		QRForm->Query->Open();

	}catch (Exception &e){
		Application->MessageBox(("未入金データの集計に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("データがありません", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	// 出力範囲
	QRForm->RangeLabel->Caption = DateFromPicker->Date.FormatString("yyyy'年'mm'月分'");

	return true;
}
//---------------------------------------------------------------------------
// F12 終了
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

