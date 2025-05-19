//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SeikyushoFrm.h"
#include "MainFrm.h"
#include "SearchFrm.h"
#include "SettingsFrm.h"
#include "ConfirmFrm.h"
#include <memory>
#include <vcl\Clipbrd.hpp>
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

	MainForm->Resize();

	DM->config_.Load(&DM->DBI);

	// 締日セット
	SimeComboBox->Items->Clear();
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT 締日 FROM V_得意先 WHERE 締日 IS NOT NULL GROUP BY 締日 ORDER BY 締日", set);
	for (int i = 0; i < (int)set.size(); i++)
		SimeComboBox->Items->Append(set[i]["締日"]);

	DateFromPicker->Date = GetFirstDate(Date());
	DateToPicker->Date   = GetLastDate(Date());

	SeikyusakiCodeEditF->Text = AnsiString();
	SeikyusakiCodeEditT->Text = AnsiString();
	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;

	// 設定適用
	SettingsForm->SetSeikyusho();

	// プリンタ指定
	//DM->SetPrinter(SeikyushoForm->QuickRep, DM->ini_["Printer::SeikyuPrinter"]);
}
//---------------------------------------------------------------------------
// 日付
void __fastcall TMainForm::SetDate()
{
	SimekiriEdit->Text = SimekiriDatePicker->Date.FormatString("yyyy/mm/dd");
	DateFromEdit->Text = DateFromPicker->Date.FormatString("yyyy/mm/dd");
	DateToEdit->Text   = DateToPicker->Date.FormatString("yyyy/mm/dd");
}
//---------------------------------------------------------------------------
// 締日->OnChange
void __fastcall TMainForm::SimeComboBoxChange(TObject *Sender)
{
	int day = SimeComboBox->Items->Strings[SimeComboBox->ItemIndex].ToIntDef(0);
	DateFromPicker->Date = DM->GetDateFrom(day);
	DateToPicker->Date   = DM->GetDateTo(day);
	SimekiriDatePicker->Date = DateToPicker->Date;
	SetDate();

	// 最終締切日
	NsRecordSet set;
	AnsiString sql = "SELECT TOP 2 締切日 FROM V_請求 WHERE 締日 = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] + " GROUP BY 締切日 ORDER BY 締切日 DESC";
	DM->DBI.GetRecordSet(sql, set);

	LastSimeLabel->Caption       = "前回締切日   ： ----/--/--";
	BeforeLastSimeLabel->Caption = "前々回締切日 ： ----/--/--";

	try{
		LastSimeLabel->Caption       = "前回締切日   ： " + IntToDate(ToInt(set[0]["締切日"])).FormatString("yyyy/mm/dd");
		BeforeLastSimeLabel->Caption = "前々回締切日 ： " + IntToDate(ToInt(set[1]["締切日"])).FormatString("yyyy/mm/dd");
	}catch (...){
	}

	// 得意先件数
	sql = "SELECT COUNT(*) AS 件数 FROM M_得意先 WHERE 締日 = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] + " AND 得意先ID = 請求先ID";
	if (DM->DBI.GetRecordSet(sql, set))
		TokuKensuLabel->Caption = "得意先件数 ： " + FormatFloat("#,##0", ToInt(set[0]["件数"])) + " 件";
	else
		TokuKensuLabel->Caption = "得意先件数 ：   件";

	TokuKensuLabel->Hint = AnsiString();
	sql = "SELECT 得意先コード, 得意先名称 FROM M_得意先 WHERE 締日 = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] +  + " AND 得意先ID = 請求先ID ORDER BY 得意先コード";
	if (DM->DBI.GetRecordSet(sql, set)){
		for (unsigned int i = 0; i < set.size(); i++)
			TokuKensuLabel->Hint += FormatFloat("00000", ToInt(set[i]["得意先コード"])) + " : " + ToString(set[0]["得意先名称"]) + "\r\n";
	}
}
//---------------------------------------------------------------------------
// 前範囲
void __fastcall TMainForm::PrevButtonClick(TObject *Sender)
{
	ShiftDate(DateFromPicker, DateToPicker, -1);
	SimekiriDatePicker->Date = DateToPicker->Date;
	SetDate();
}
//---------------------------------------------------------------------------
// 後範囲
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(DateFromPicker, DateToPicker, 1);
	SimekiriDatePicker->Date = DateToPicker->Date;
	SetDate();
}
//---------------------------------------------------------------------------
// F4 参照
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == SeikyusakiCodeEditF)
		SeikyusakiSearchButtonF->OnClick(NULL);
	else if (ActiveControl == SeikyusakiCodeEditT)
		SeikyusakiSearchButtonT->OnClick(NULL);
}
//---------------------------------------------------------------------------
// F9 印刷 / F10 プレビュー
void __fastcall TMainForm::btnF9Click(TObject *Sender)
{
	if (!InputCheck())
		return;

	DM->zeiritu = GetShohizeiritu(DateToInt(DateToPicker->Date));
		
	// 請求処理内容確認フォーム
	int seikyu = CreateSeikyuComboBox->ItemIndex == 0 ? 1 : 0;
	int hikae  = HikaeComboBox->ItemIndex        == 0 ? 1 : 0;
	int print  = Sender == btnF9                      ? 1 : 0;
	SetSimeCheckRange();
	if (ConfirmForm->ShowModalWith(seikyu, hikae, print) != mrOk)
		return;
	ShoriKensuLabel->Caption = AnsiString();
	SeikyuConfButton->Visible = false;
	if (CreateSeikyuComboBox->ItemIndex == 0){
		// 請求データを作成する
		if (!SetRange(true))
			return;
		if (!CreateSeikyuData())
			return;
	}
	if (!SetRange(false))
		return;
	if (print)
		SettingsForm->report->Print();
	else
		SettingsForm->report->Preview();
}
//---------------------------------------------------------------------------
// 締切日チェック用クエリ範囲設定
void __fastcall TMainForm::SetSimeCheckRange()
{
	DM->Q_SimeCheck->Close();
	DM->Q_SimeCheck->Parameters->ParamByName("LAST_SIME")->Value = DateToInt(DateFromPicker->Date - 1);
	DM->Q_SimeCheck->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(DateFromPicker->Date);
	DM->Q_SimeCheck->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(DateToPicker->Date);
	DM->Q_SimeCheck->Parameters->ParamByName("SIME")->Value      = SimeComboBox->Items->Strings[SimeComboBox->ItemIndex].ToIntDef(0);
	DM->Q_SimeCheck->Open();
}
//---------------------------------------------------------------------------
// クエリの範囲設定
bool __fastcall TMainForm::SetRange(bool create_data)
{
	try{
		JunbiPanel->Left = 300;
		JunbiPanel->Top  = 212;
		JunbiPanel->Visible = true;
		Application->ProcessMessages();

		DM->Q_Seikyu->Close();
		DM->Q_Seikyu->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(DateFromPicker->Date);
		DM->Q_Seikyu->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(DateToPicker->Date);
		DM->Q_Seikyu->Parameters->ParamByName("SIME")->Value      = SimeComboBox->Items->Strings[SimeComboBox->ItemIndex].ToIntDef(0);
		DM->Q_Seikyu->Parameters->ParamByName("TAX_RATE")->Value  = DM->zeiritu;

		// 指定請求先のみ
		if (!AllCheckBox->Checked && SeikyusakiCodeEditF->Text.ToIntDef(0) != 0 && SeikyusakiCodeEditT->Text.ToIntDef(0) != 0){
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_FROM")->Value = SeikyusakiCodeEditF->Text.ToIntDef(0);
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_TO")->Value   = SeikyusakiCodeEditT->Text.ToIntDef(0);
		}else{
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_FROM")->Value = 0;
			DM->Q_Seikyu->Parameters->ParamByName("SEIKYU_TO")->Value   = 99999;
		}

		if (create_data){
			// データ作成用
			DM->Q_Seikyu->SQL->Strings[266] = "	(ISNULL(C.今回売上額, 0) > 0 OR ISNULL(A.前回請求額, 0) <> 0 OR ISNULL(B.今回入金額, 0) <> 0 OR ISNULL(B.今回調整額, 0) <> 0)";
			DM->Q_Seikyu->SQL->Strings[267] = AnsiString();
		}else{
			// 請求書発行用
			DM->Q_Seikyu->SQL->Strings[266] = AnsiString();
			DM->Q_Seikyu->SQL->Strings[267] = "	ISNULL(A.前回請求額, 0) - (ISNULL(B.今回入金額, 0) + ISNULL(B.今回調整額, 0)) + ISNULL(C.今回売上額, 0) + ISNULL(C.今回消費税額, 0) <> 0";
		}

		RichEdit1->Lines->Text = DM->Q_Seikyu->SQL->Text;

		DM->Q_Seikyu->Open();

		if (DM->Q_Seikyu->RecordCount == 0){
			Application->MessageBox("対象となるデータがありません", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
			return false;
		}

		if (!create_data){
			// 請求書タイトル変更
			if (HikaeComboBox->ItemIndex == 1)
				SettingsForm->title_label->Caption = "請 求 書 (控)";
			else
				SettingsForm->title_label->Caption = "請　求　書";

			// 出力日＝締切日
			SettingsForm->date_label->Caption = FormatFloat("0000年00月00日", DateToInt(DateToPicker->Date));
		}
	}__finally{
		JunbiPanel->Visible = false;
	}

	return true;
}
//---------------------------------------------------------------------------
// 入力チェック
bool __fastcall TMainForm::InputCheck()
{
	if (SimeComboBox->ItemIndex == -1){
		Application->MessageBox("締日を選択してください", "入力チェック", MB_OK | MB_ICONEXCLAMATION);
		SimeComboBox->SetFocus();
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
// 請求データの作成
bool __fastcall TMainForm::CreateSeikyuData()
{
	if (CreateSeikyuComboBox->ItemIndex != 0)
		return true;

	try{
		CreatePanel->Left = 300;
		CreatePanel->Top  = 212;
		KensuLabel->Caption = "  件";
		ShoriKensuLabel->Caption = AnsiString();
		SeikyuConfButton->Visible = false;
		CreatePanel->Visible = true;
		Application->ProcessMessages();

		AnsiString toku_code_f = IntToStr(SeikyusakiCodeEditF->Text.ToIntDef(0));
		AnsiString toku_code_t = IntToStr(SeikyusakiCodeEditT->Text.ToIntDef(0));

		try{
			DM->ADOConnection->BeginTrans();

			NsFieldSet keys, fields;

			// 既存請求データの削除
			AnsiString sql = "DELETE FROM D_請求 WHERE 締切日 = " + DateToPicker->Date.FormatString("yyyymmdd") + " AND EXISTS (SELECT * FROM M_得意先 WHERE 締日 = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex] + " AND 請求先ID = 得意先ID)";
			if (!AllCheckBox->Checked)      // 請求先指定の場合
				sql += " AND 請求先ID IN ( SELECT 請求先ID FROM M_得意先 WHERE 得意先コード BETWEEN " + toku_code_f + " AND " + toku_code_t + ")";

			DM->DBI.Execute(sql);

			// 請求データ作成
			bool is_exist;

			int seikyu_bef = 0;
			create_cnt = 0;

			while (!DM->Q_Seikyu->Eof){
				if (DM->Q_Seikyu->FieldByName("請求先ID")->AsInteger == seikyu_bef){
					DM->Q_Seikyu->Next();
					continue;
				}
				seikyu_bef = DM->Q_Seikyu->FieldByName("請求先ID")->AsInteger;

				keys.clear();
				keys << NsField("締切日",   DM->Q_Seikyu->FieldByName("締切日")->AsInteger);
				keys << NsField("請求先ID", DM->Q_Seikyu->FieldByName("請求先ID")->AsInteger);
				if (DM->DBI.IsExist("D_請求", keys))
					is_exist = true;
				else
					is_exist = false;

				fields.clear();
				if (!is_exist){
					fields << NsField("[締切日]",   DM->Q_Seikyu->FieldByName("締切日")->AsInteger);
					fields << NsField("[請求先ID]", DM->Q_Seikyu->FieldByName("請求先ID")->AsInteger);
				}
				fields << NsField("[開始日付]",     DM->Q_Seikyu->FieldByName("開始日付")->AsInteger);
				fields << NsField("[終了日付]",     DM->Q_Seikyu->FieldByName("終了日付")->AsInteger);
				fields << NsField("[前回請求額]",   DM->Q_Seikyu->FieldByName("前回請求額")->AsInteger);
				fields << NsField("[今回入金額]",   DM->Q_Seikyu->FieldByName("今回入金額")->AsInteger);
				fields << NsField("[今回調整額]",       DM->Q_Seikyu->FieldByName("今回調整額")->AsInteger);
				fields << NsField("[今回繰越額]",       DM->Q_Seikyu->FieldByName("今回繰越額")->AsInteger);
				fields << NsField("[今回売上額]",   DM->Q_Seikyu->FieldByName("今回売上額")->AsInteger);
				fields << NsField("[今回消費税額]", DM->Q_Seikyu->FieldByName("今回消費税額")->AsInteger);
				fields << NsField("[今回請求額]",   DM->Q_Seikyu->FieldByName("今回請求額")->AsInteger);
				fields << NsField("[入金予定日]",   DateToInt(DM->GetNyukinYotei(DateToPicker->Date, DM->Q_Seikyu->FieldByName("入金サイト")->AsInteger, DM->Q_Seikyu->FieldByName("入金日")->AsInteger)));
				fields << NsField("[更新日時]",     Now());
				if (!is_exist)
					fields << NsField("[作成日時]", Now());

				if (is_exist)
					DM->DBI.Update("D_請求", keys, fields);
				else
					DM->DBI.Insert("D_請求", fields);

				KensuLabel->Caption = FormatFloat("#,##0", create_cnt++) + " 件";
				Application->ProcessMessages();
				DM->Q_Seikyu->Next();
			}
			ShoriKensuLabel->Caption = "処理件数 ： " + KensuLabel->Caption;
			SeikyuConfButton->Visible = true;

			DM->ADOConnection->CommitTrans();

		}catch (Exception& e){
			DM->ADOConnection->RollbackTrans();
			Application->MessageBox(("請求データの登録に失敗しました\r\n" + e.Message).c_str(), "請求データ登録", MB_OK | MB_ICONSTOP);
			return false;
		}
	}__finally{
		CreatePanel->Visible = false;
	}

	return true;
}
//---------------------------------------------------------------------------
// F11 ラベル印字
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (!InputCheck())
		return;
	if (!SetRange(false))
		return;

	// ラベル印字呼出
	AnsiString path = ExtractFilePath(Application->Name) + "PrintLabel.exe ";

	std::auto_ptr<TStringList> code_list(new TStringList());
	int code = 0;
	while (!DM->Q_Seikyu->Eof){
		if (code == DM->Q_Seikyu->FieldByName("請求先コード")->AsInteger){
			DM->Q_Seikyu->Next();
			continue;
		}
		code = DM->Q_Seikyu->FieldByName("請求先コード")->AsInteger;
		code_list->Add(DM->Q_Seikyu->FieldByName("請求先コード")->AsString);
		DM->Q_Seikyu->Next();
	}

	path = path + code_list->CommaText;

	if (!CreateProcess(path, true)){
		Application->MessageBox("ラベル印字を起動できませんでした", "ラベル印字", MB_OK | MB_ICONSTOP);
	}
}
//---------------------------------------------------------------------------
// F12 終了
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
// 消費税率取得
int __fastcall TMainForm::GetShohizeiritu(int date)
{
	AnsiString sql = AnsiString();
	sql =	" SELECT * FROM M_消費税 WHERE 開始日付 <= " + IntToStr(date);
	NsRecordSet set;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0;
	else
		return ToInt(set[set.size() - 1]["消費税率"]);
}
//---------------------------------------------------------------------------
// 出力範囲すべて
void __fastcall TMainForm::AllCheckBoxClick(TObject *Sender)
{
	SeikyusakiCodeEditF->Enabled     = !AllCheckBox->Checked;
	SeikyusakiNameEditF->Enabled     = !AllCheckBox->Checked;
	SeikyusakiSearchButtonF->Enabled = !AllCheckBox->Checked;

	SeikyusakiCodeEditT->Enabled     = !AllCheckBox->Checked;
	SeikyusakiNameEditT->Enabled     = !AllCheckBox->Checked;
	SeikyusakiSearchButtonT->Enabled = !AllCheckBox->Checked;

	if (!AllCheckBox->Checked)
		SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
// 得意先コード(From)->OnChange
void __fastcall TMainForm::SeikyusakiCodeEditFChange(TObject *Sender)
{
	if (SeikyusakiCodeEditF->Text == ""){
		SeikyusakiNameEditF->Text = AnsiString();
		return;
	}
	SeikyusakiNameEditF->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEditF->Text, "得意先名称", "得意先ID = 請求先ID"));
	if (SeikyusakiCodeEditT->Text == AnsiString())
		SeikyusakiCodeEditT->Text = SeikyusakiCodeEditF->Text;
}
//---------------------------------------------------------------------------
// 得意先(From)検索ボタン
void __fastcall TMainForm::SeikyusakiSearchButtonFClick(TObject *Sender)
{
	if (SimeComboBox->ItemIndex == -1)
		SearchForm->based_sql = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1";
	else
		SearchForm->based_sql = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1 AND 締日 = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex];
	SearchForm->orderby_sql = "ORDER BY 得意先コード";
	SearchForm->table_name = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditF->Text = SearchForm->Query->FieldByName("得意先コード")->AsString;
	SeikyusakiCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
// 得意先コード(To)->OnChange
void __fastcall TMainForm::SeikyusakiCodeEditTChange(TObject *Sender)
{
	if (SeikyusakiCodeEditT->Text == ""){
		SeikyusakiNameEditT->Text = AnsiString();
		return;
	}
	SeikyusakiNameEditT->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEditT->Text, "得意先名称", "得意先ID = 請求先ID"));
}
//---------------------------------------------------------------------------
// 得意先(To)検索ボタン
void __fastcall TMainForm::SeikyusakiSearchButtonTClick(TObject *Sender)
{
	if (SimeComboBox->ItemIndex == -1)
		SearchForm->based_sql = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1";
	else
		SearchForm->based_sql = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1 AND 締日 = " + SimeComboBox->Items->Strings[SimeComboBox->ItemIndex];
	SearchForm->orderby_sql = "ORDER BY 得意先コード";
	SearchForm->table_name = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEditT->Text = SearchForm->Query->FieldByName("得意先コード")->AsString;
	SeikyusakiCodeEditT->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (ActiveControl->Tag != 9 && (Key == VK_RETURN || Key == VK_DOWN)){
		keybd_event(VK_TAB, 0, 0, 0);

	}else if (ActiveControl->Tag != 1 && (Key == VK_UP)){
		keybd_event(VK_SHIFT, 0, 0, 0);
		keybd_event(VK_TAB, 0, 0, 0);
		keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	}

	if (Key == VK_F9)
		btnF9->OnClick(btnF9);
	else if (Key == VK_F10)
		btnF10->OnClick(btnF10);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShosikiButtonClick(TObject *Sender)
{
	SettingsForm->ShowModal();	
}
//---------------------------------------------------------------------------
// 個別範囲設定
void __fastcall TMainForm::KobetuCheckBoxClick(TObject *Sender)
{
	SimekiriDatePicker->Enabled = KobetuCheckBox->Checked;
	DateFromPicker->Enabled     = KobetuCheckBox->Checked;
	DateToPicker->Enabled       = KobetuCheckBox->Checked;
	SimekiriEdit->Visible       = !KobetuCheckBox->Checked;
	DateFromEdit->Visible       = !KobetuCheckBox->Checked;
	DateToEdit->Visible         = !KobetuCheckBox->Checked;
}
//---------------------------------------------------------------------------
// DatePicker->OnChange
void __fastcall TMainForm::SimekiriDatePickerChange(TObject *Sender)
{
	SetDate();
}
//---------------------------------------------------------------------------
// ComboBox->OnKeyDown
void __fastcall TMainForm::CreateSeikyuComboBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key == VK_NUMPAD1)
		((TComboBox *)Sender)->ItemIndex = 0;
	else if (Key == VK_NUMPAD2)
		((TComboBox *)Sender)->ItemIndex = 1;
}
//---------------------------------------------------------------------------
// 請求データ確認ボタン
void __fastcall TMainForm::SeikyuConfButtonClick(TObject *Sender)
{
	// 請求一覧呼出
	AnsiString path = ExtractFilePath(Application->Name) + "SeikyuDataMaintenance.exe " + IntToStr(DateToInt(SimekiriDatePicker->Date));

	if (!CreateProcess(path, true)){
		Application->MessageBox("請求データメンテナンスを起動できませんでした",
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

