//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
#include "SearchFrm.h"
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
	try{
		DM->ADOConnection->Connected = true;
	}catch (Exception& e){
		Application->MessageBox(("データベースへの接続に失敗しました\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

    bunrui_map_.clear();
    DivCombo->Items->Clear();
    DivCombo->Items->Append("指定なし");

    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT 品目分類ID, 品目分類略称 FROM V_品目分類 WHERE 使用区分 = 1", set);
    for (unsigned int i = 0; i < set.size(); i++){
        bunrui_map_[i + 1] = ToInt(set[i]["品目分類ID"]);
        DivCombo->Items->Append(ToString(set[i]["品目分類略称"]));
    }
    DivCombo->ItemIndex = 0;
    if (DivCombo->Items->Count > 1)
        DivCombo->ItemIndex = 1;

	TokuCodeEdit->Text = AnsiString();
	MainForm->Resize();
	rbMonth->OnClick(NULL);
}
//---------------------------------------------------------------------------
// 日
void __fastcall TMainForm::rbDayClick(TObject *Sender)
{
	DateFromPicker->Date = Date();
	DateToPicker->Date = Date();
}
//---------------------------------------------------------------------------
// 月
void __fastcall TMainForm::rbMonthClick(TObject *Sender)
{
	DateFromPicker->Date = GetFirstDate(Date());
	DateToPicker->Date = GetLastDate(Date());
}
//---------------------------------------------------------------------------
// 年
void __fastcall TMainForm::rbYearClick(TObject *Sender)
{

	DateFromPicker->Date = GetKishuDate(Date());
	DateToPicker->Date = IncMonth(DateFromPicker->Date, 12) - 1;
}
//---------------------------------------------------------------------------
// 前範囲
void __fastcall TMainForm::PrevButtonClick(TObject *Sender)
{
	ShiftDate(DateFromPicker, DateToPicker, -1);
}
//---------------------------------------------------------------------------
// 後範囲
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(DateFromPicker, DateToPicker, 1);
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
// F11 出力
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (!SetRange())
		return;

	std::auto_ptr<TStringList> StrList(new TStringList());
	Table2Str(QRForm->Query, StrList.get(), true);

	SaveDialog->FileName = "帳票データ.csv";
	if (!SaveDialog->Execute())
		return;

	StrList->SaveToFile(SaveDialog->FileName);
	Application->MessageBox("出力が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
// クエリの範囲設定
bool __fastcall TMainForm::SetRange()
{
	QRForm->Query->Close();
	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(DateFromPicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(DateToPicker->Date);
	if (TokuCodeEdit->Text.ToIntDef(0) != 0)
		QRForm->Query->SQL->Strings[145] = "AND 得意先コード = " + IntToStr(TokuCodeEdit->Text.ToIntDef(0));

    if (DivCombo->ItemIndex == 1){
        QRForm->Query->SQL->Strings[146] = " AND 品目コード < 5 ";
    }else if (DivCombo->ItemIndex == 2){
        QRForm->Query->SQL->Strings[146] = " AND 品目コード >= 5 ";
    }


	QRForm->Query->Open();

	QRForm->dt = DateFromPicker->Date;

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("データがありません", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	// 出力範囲
	QRForm->RangeLabel->Caption = DateToStr(DateFromPicker->Date) + " ～ " + DateToStr(DateToPicker->Date);
	if (TokuCodeEdit->Text.ToIntDef(0) != 0)
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  得意先：" + TokuNameEdit->Text + "のみ";

	return true;
}
//---------------------------------------------------------------------------
// F12 終了
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuCodeEditChange(TObject *Sender)
{
	TokuNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "得意先名称"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuSearchButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 得意先コード, 得意先名称 FROM M_得意先 WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY 得意先コード ";
	SearchForm->table_name = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称";
	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	TokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------

