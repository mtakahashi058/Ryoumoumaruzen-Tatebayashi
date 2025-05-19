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
	seikyu_id_ = 0;
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

	SeikyusakiCodeEditF->Text = AnsiString();
	SeikyusakiCodeEditT->Text = AnsiString();

	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;

	MainForm->Resize();
	MonthPicker->Date = Date();
	MonthPicker->OnChange(NULL);
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
	MonthPicker->Date = IncMonth(GetFirstDate(MonthPicker->Date), -1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// 後範囲
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	MonthPicker->Date = IncMonth(GetFirstDate(MonthPicker->Date), 1);
	MonthPicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
// F9 印刷
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (Application->MessageBox("印刷しますか？", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	if (!CheckEdit())
		return;
	if (!SetRange())
		return;
	if (CreateDataComboBox->ItemIndex == 0)
		PostUrikake();

	QRForm->Query->Filter = "前月残高 <> 0 OR 当月入金額 <> 0 OR 当月売上額 <> 0";
	QRForm->Query->Filtered = true;

	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
// F10 プレビュー
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;
	if (!SetRange())
		return;
	if (CreateDataComboBox->ItemIndex == 0)
		PostUrikake();

	QRForm->Query->Filter = "前月残高 <> 0 OR 当月入金額 <> 0 OR 当月売上額 <> 0";
	QRForm->Query->Filtered = true;

	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
// 出力前チェック処理
bool __fastcall TMainForm::CheckEdit()
{
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT COUNT(*) AS 件数 FROM D_請求 WHERE 締切日 = " + IntToStr(DateToInt(GetLastDate(MonthPicker->Date))), set);
	if (ToInt(set[0]["件数"]) == 0){
		if (Application->MessageBox("末締め（締日＝99）の請求処理が行われていません\r\n請求処理を行わずに売上元帳を発行すると末締めの消費税が反映されません\r\n処理を続行しますか？", "請求チェック", MB_YESNO | MB_ICONEXCLAMATION | MB_DEFBUTTON2) != IDYES)
			return false;
	} 

	return true;
}
//---------------------------------------------------------------------------
// クエリの範囲設定
bool __fastcall TMainForm::SetRange()
{
	QRForm->Query->Close();
	QRForm->Query->Parameters->ParamByName("DATE_BEF")->Value   = DateToInt(GetLastDate(IncMonth(DateFromPicker->Date, -1)));
	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value  = DateToInt(DateFromPicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value    = DateToInt(DateToPicker->Date);
	QRForm->Query->Parameters->ParamByName("ZEIRITU")->Value    = DM->GetShohizeiritu(DateToInt(DateToPicker->Date));

	if (!AllCheckBox->Checked){
		QRForm->Query->Parameters->ParamByName("SEIKYU_FROM")->Value = SeikyusakiCodeEditF->Text.ToIntDef(0);
		QRForm->Query->Parameters->ParamByName("SEIKYU_TO")->Value   = SeikyusakiCodeEditT->Text.ToIntDef(0);
	}else{
		QRForm->Query->Parameters->ParamByName("SEIKYU_FROM")->Value = 0;
		QRForm->Query->Parameters->ParamByName("SEIKYU_TO")->Value   = 99999;
	}

	QRForm->Query->Filtered = false;
	QRForm->Query->Open();

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("データがありません", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	// 出力範囲
	QRForm->NendoLabel->Caption = DateFromPicker->Date.FormatString("yyyy'年'mm'月度'");

	// 処理件数クリア
	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;

	return true;
}
//---------------------------------------------------------------------------
// 売掛データを登録
bool __fastcall TMainForm::PostUrikake()
{
	try{
		DM->ADOConnection->BeginTrans();

		int sime = DateToInt(GetLastDate(MonthPicker->Date));	// 締切日

		int seikyu_from = SeikyusakiCodeEditF->Text.ToIntDef(0);
		int seikyu_to   = SeikyusakiCodeEditT->Text.ToIntDef(0);

		std::auto_ptr<TStringList> seikyu_id_list(new TStringList());

		NsRecordSet set;
		DM->DBI.GetRecordSet("SELECT 得意先ID FROM M_得意先 WHERE 得意先ID = 得意先ID AND 得意先コード BETWEEN " + IntToStr(seikyu_from) + " AND " + IntToStr(seikyu_to), set);
		for (unsigned int i = 0; i < set.size(); i++)
			seikyu_id_list->Add(ToString(set[i]["得意先ID"]));

		// 売掛データ削除
		AnsiString sql = "DELETE FROM D_売掛 WHERE 締切日 = " + IntToStr(sime);
		if (!AllCheckBox->Checked && seikyu_id_list->Count != 0)
			sql += " AND 請求先ID IN ( " + seikyu_id_list->CommaText + ") ";
		DM->DBI.Execute(sql);

		seikyu_id_ = 0;
		int count = 0;

		// 売掛データ作成
		NsFieldSet fields;
		while (!QRForm->Query->Eof){
			if (seikyu_id_ == QRForm->Query->FieldByName("請求先ID")->AsInteger){
				QRForm->Query->Next();
				continue;
			}
			seikyu_id_ = QRForm->Query->FieldByName("請求先ID")->AsInteger;

			fields.clear();
			fields	<< NsField("締切日", sime)
				<< NsField("請求先ID", seikyu_id_)
				<< NsField("開始日付", DateToInt(GetFirstDate(MonthPicker->Date)))
				<< NsField("終了日付", sime)
				<< NsField("前月残高",   QRForm->Query->FieldByName("前月残高")->AsCurrency)
				<< NsField("当月入金額", QRForm->Query->FieldByName("当月入金額")->AsCurrency)
				<< NsField("当月調整額", QRForm->Query->FieldByName("当月調整額")->AsCurrency)
				<< NsField("当月繰越額", QRForm->Query->FieldByName("当月繰越額")->AsCurrency)
				<< NsField("当月売上額", QRForm->Query->FieldByName("当月売上額")->AsCurrency)
				<< NsField("当月消費税額", QRForm->Query->FieldByName("当月消費税額")->AsCurrency)
				<< NsField("当月残高", QRForm->Query->FieldByName("当月繰越額")->AsCurrency + QRForm->Query->FieldByName("当月売上額")->AsCurrency + QRForm->Query->FieldByName("当月消費税額")->AsCurrency)
				<< NsField("更新日時", Now())
				<< NsField("作成日時", Now());
			DM->DBI.Insert("D_売掛", fields);

			count++;
			QRForm->Query->Next();
		}

		ShoriKensuLabel->Caption = "処理件数 ： " + FormatFloat("#,##0", count) + "件";
		SeikyuConfButton->Visible = true;
		Application->ProcessMessages();

		DM->ADOConnection->CommitTrans();

	}catch (Exception& e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("請求データの登録に失敗しました\r\n" + e.Message).c_str(), "請求データ登録", MB_OK | MB_ICONSTOP);
		return false;
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
void __fastcall TMainForm::SeikyusakiCodeEditFChange(TObject *Sender)
{
	SeikyusakiNameEditF->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEditF->Text.ToIntDef(0), "得意先名称", "得意先ID = 請求先ID"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiCodeEditTChange(TObject *Sender)
{
	SeikyusakiNameEditT->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEditT->Text.ToIntDef(0), "得意先名称", "得意先ID = 請求先ID"));
}
//---------------------------------------------------------------------------
// 得意先検索ボタン
void __fastcall TMainForm::SeikyusakiSearchButtonFClick(TObject *Sender)
{
	SearchForm->based_sql = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1";
	SearchForm->orderby_sql = "ORDER BY 得意先コード";
	SearchForm->table_name = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditF->Text = SearchForm->Query->FieldByName("得意先コード")->AsString;
	SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiSearchButtonTClick(TObject *Sender)
{
	SearchForm->based_sql = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1";
	SearchForm->orderby_sql = "ORDER BY 得意先コード";
	SearchForm->table_name = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditT->Text = SearchForm->Query->FieldByName("得意先コード")->AsString;
	SeikyusakiCodeEditT->SetFocus();
}
//---------------------------------------------------------------------------
// 請求データ作成区分
void __fastcall TMainForm::CreateDataComboBoxKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_NUMPAD1)
		CreateDataComboBox->ItemIndex = 0;
	else if (Key == VK_NUMPAD2)
		CreateDataComboBox->ItemIndex = 1;
}
//---------------------------------------------------------------------------
// 売掛データ確認ボタン
void __fastcall TMainForm::SeikyuConfButtonClick(TObject *Sender)
{
	// 売掛一覧呼出
	AnsiString path = ExtractFilePath(Application->Name) + "UrikakeDataMaintenance.exe " + IntToStr(DateToInt(GetLastDate(MonthPicker->Date)));

	if (!CreateProcess(path, true)){
		Application->MessageBox("売掛データメンテナンスを起動できませんでした",
						"請求データ確認", MB_OK | MB_ICONSTOP);
	}
}
//---------------------------------------------------------------------------
//exeファイル呼出に必要な処理
bool __fastcall TMainForm::CreateProcess(AnsiString exename, bool wait)
{
	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;
	if (!::CreateProcess(NULL, exename.c_str(), NULL, NULL, false,
			CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS,
			NULL, NULL, &stStartupInfo, &stProcessInfo))
		return false;
	if (wait)
		WaitForSingleObject(stProcessInfo.hProcess, INFINITE);
	return true;
}
//---------------------------------------------------------------------------
// 出力範囲すべて
void __fastcall TMainForm::AllCheckBoxClick(TObject *Sender)
{
	SiteiLabel->Font->Color = AllCheckBox->Checked ? clGray : clWindowText;
	SeikyusakiCodeEditF->Enabled = !AllCheckBox->Checked;
	SeikyusakiNameEditF->Enabled = !AllCheckBox->Checked;
	SeikyusakiSearchButtonF->Enabled = !AllCheckBox->Checked;
	SeikyusakiCodeEditT->Enabled = !AllCheckBox->Checked;
	SeikyusakiNameEditT->Enabled = !AllCheckBox->Checked;
	SeikyusakiSearchButtonT->Enabled = !AllCheckBox->Checked;
	if (!AllCheckBox->Checked)
		SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------

