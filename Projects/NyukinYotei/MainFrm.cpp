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
	toku_list_ = new TStringList();
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
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete toku_list_;
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
// 期首日付を取得
TDateTime __fastcall TMainForm::GetKishuDate(TDateTime date)
{
	int nYear = DateToInt(date) / 10000;
	int nMonth = DateToStr(date).SubString(6, 2).ToIntDef(0);
	if (nMonth >= 1 && nMonth <= 3){
		nYear--;
	}
	return IntToDate(nYear * 10000 + 401);
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
	if (!SetRange(true))
		return;
	if (!SetRange(false))
		return;
	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
// F10 プレビュー
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (!SetRange(true))
		return;
	if (!SetRange(false))
		return;
	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
// クエリの範囲設定
bool __fastcall TMainForm::SetRange(bool toku_search)
{
	QRForm->Query->Close();
	if (toku_search)
		QRForm->Query_->SQL->Strings[134] = AnsiString();
	else
		QRForm->Query_->SQL->Strings[134] = " AND TK.得意先コード IN (" + toku_list_->CommaText + ")";
	QRForm->Query->CommandText = QRForm->Query_->SQL->Text;

	QRForm->Query->Parameters->ParamByName("DT_FROM6")->Value = DateToInt(GetFirstDate(IncMonth(DateFromPicker->Date, -6)));
	QRForm->Query->Parameters->ParamByName("DT_TO6")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -6)));
	QRForm->Query->Parameters->ParamByName("DT_FROM5")->Value = DateToInt(GetFirstDate(IncMonth(DateFromPicker->Date, -5)));
	QRForm->Query->Parameters->ParamByName("DT_TO5")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -5)));
	QRForm->Query->Parameters->ParamByName("DT_FROM4")->Value = DateToInt(GetFirstDate(IncMonth(DateFromPicker->Date, -4)));
	QRForm->Query->Parameters->ParamByName("DT_TO4")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -4)));
	QRForm->Query->Parameters->ParamByName("DT_FROM3")->Value = DateToInt(GetFirstDate(IncMonth(DateFromPicker->Date, -3)));
	QRForm->Query->Parameters->ParamByName("DT_TO3")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -3)));
	QRForm->Query->Parameters->ParamByName("DT_FROM2")->Value = DateToInt(GetFirstDate(IncMonth(DateFromPicker->Date, -2)));
	QRForm->Query->Parameters->ParamByName("DT_TO2")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -2)));
	QRForm->Query->Parameters->ParamByName("DT_FROM1")->Value = DateToInt(GetFirstDate(IncMonth(DateFromPicker->Date, -1)));
	QRForm->Query->Parameters->ParamByName("DT_TO1")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -1)));
	QRForm->Query->Parameters->ParamByName("DT_FROM")->Value  = DateToInt(DateFromPicker->Date);
	QRForm->Query->Parameters->ParamByName("DT_TO")->Value    = DateToInt(DateToPicker->Date);
	QRForm->Query->Open();

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("データがありません", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	if (toku_search){
		toku_list_->Clear();
		for (int i = 0; i < QRForm->Query->RecordCount; i++){
			if (	QRForm->Query->FieldByName("売掛残6")->AsCurrency == 0 &&
					QRForm->Query->FieldByName("売掛残5")->AsCurrency == 0 &&
					QRForm->Query->FieldByName("売掛残4")->AsCurrency == 0 &&
					QRForm->Query->FieldByName("売掛残3")->AsCurrency == 0 &&
					QRForm->Query->FieldByName("売掛残2")->AsCurrency == 0 &&
					QRForm->Query->FieldByName("売掛残1")->AsCurrency == 0 &&
					QRForm->Query->FieldByName("売掛残0")->AsCurrency == 0){
				QRForm->Query->Next();
				continue;
			}
			toku_list_->Add(QRForm->Query->FieldByName("得意先コード")->AsString);
			QRForm->Query->Next();
		}

	}else{
		QRForm->MonthLabel1->Caption = "<= " + IncMonth(DateFromPicker->Date, -6).FormatString("yyyy/mm");
		QRForm->MonthLabel2->Caption =         IncMonth(DateFromPicker->Date, -5).FormatString("yyyy/mm");
		QRForm->MonthLabel3->Caption =         IncMonth(DateFromPicker->Date, -4).FormatString("yyyy/mm");
		QRForm->MonthLabel4->Caption =         IncMonth(DateFromPicker->Date, -3).FormatString("yyyy/mm");
		QRForm->MonthLabel5->Caption =         IncMonth(DateFromPicker->Date, -2).FormatString("yyyy/mm");
		QRForm->MonthLabel6->Caption =         IncMonth(DateFromPicker->Date, -1).FormatString("yyyy/mm");
		QRForm->MonthLabel7->Caption =                  DateFromPicker->Date.FormatString("yyyy/mm");

		// 出力範囲
		QRForm->RangeLabel->Caption = DateFromPicker->Date.FormatString("yyyy'年'mm'月分'");
	}

	return true;
}
//---------------------------------------------------------------------------
// F12 終了
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

