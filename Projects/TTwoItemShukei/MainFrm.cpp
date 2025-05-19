//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
#include <memory>
//---------------------------------------------------------------------------
#include <DateUtils.hpp>
#include <SysUtils.hpp>
#include <StrUtils.hpp>
#include "XlWrap.h"
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
	}catch (Exception &e){
		Application->MessageBox(("データベース接続に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		Close();
	}

	DM->config_.Load(&DM->DBI);

	SetItems();

	DayRadioButton->Checked = true;
	DayRadioButton->OnClick(NULL);

	SelectItem1ComboBox->ItemIndex = 0;
	SelectItem1ComboBox->OnChange(NULL);
	Item1AllCheckBox->OnClick(NULL);

	SelectItem2ComboBox->ItemIndex = 0;
	SelectItem2ComboBox->OnChange(NULL);
	Item2AllCheckBox->OnClick(NULL);

	SpotAllCheckBox->Checked = true;
	SpotCodeEdit->Text = AnsiString();
	SpotNameEdit->Text = AnsiString();
	SpotAllCheckBox->OnClick(NULL);

	TorihikiComboBox->ItemIndex = 1;
	GenkakeComboBox->ItemIndex  = 0;

	SetPrinter(QRForm->QuickRep, ToString(DM->ini_["Printer::Report"]));

	FromDatePicker->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 99 && ActiveControl->Tag != 2 && ActiveControl->Tag != 0){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 99){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag != 0 && ActiveControl->Tag != 2 && ActiveControl->Tag != 99){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SanshoActionExecute(TObject *Sender)
{
	if (ActiveControl == Item1CodeEditF || ActiveControl == Item1NameEditF){
		if (SelectItem1ComboBox->ItemIndex == 0)
			return;
		Item1SearchButtonF->OnClick(NULL);
	}else if (ActiveControl == Item1CodeEditT || ActiveControl == Item1NameEditT){
		if (SelectItem1ComboBox->ItemIndex == 0)
			return;
		Item1SearchButtonT->OnClick(NULL);
	}else if (ActiveControl == Item2CodeEditF || ActiveControl == Item2NameEditF){
		if (SelectItem2ComboBox->ItemIndex == 0)
			return;
		Item2SearchButtonF->OnClick(NULL);
	}else if (ActiveControl == Item2CodeEditT || ActiveControl == Item2NameEditT){
		if (SelectItem2ComboBox->ItemIndex == 0)
			return;
		Item2SearchButtonT->OnClick(NULL);
	}else if (ActiveControl == SpotAllCheckBox || ActiveControl == SpotCodeEdit || ActiveControl == SpotNameEdit){
		SpotSearchButton->OnClick(NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintActionExecute(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == SelectItem2ComboBox->ItemIndex){
		Application->MessageBox("集計項目1と集計項目2が重複しています。\r\n別々の集計項目を設定した上で、再度実行して下さい。",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("印刷しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!OpenQuery())
		return;

	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PreviewActionExecute(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == SelectItem2ComboBox->ItemIndex){
		Application->MessageBox("集計項目1と集計項目2が重複しています。\r\n別々の集計項目を設定した上で、再度実行して下さい。",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (!OpenQuery())
		return;

	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OutputActionExecute(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == SelectItem2ComboBox->ItemIndex){
		Application->MessageBox("集計項目1と集計項目2が重複しています。\r\n別々の集計項目を設定した上で、再度実行して下さい。",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("出力しますか？\r\n※出力を行うには、マイクロソフト社のエクセルが必要となります。",
			this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!OpenQuery())
		return;

	ExcelOut();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndActionExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DayRadioButtonClick(TObject *Sender)
{
	FromDatePicker->Date = Date();
	ToDatePicker->Date = Date();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MonthRadioButtonClick(TObject *Sender)
{
	FromDatePicker->Date = GetFirstDate(Date());
	ToDatePicker->Date = GetLastDate(Date());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::YearRadioButtonClick(TObject *Sender)
{
	WORD y, m, d;
	Date().DecodeDate(&y, &m, &d);

	m = ToInt(DM->config_["期首日付"]);

	try{
		FromDatePicker->Date = EncodeDate(y, m, 1);
	}catch (...){
		FromDatePicker->Date = EncodeDate(y, 4, 1);
	}
	ToDatePicker->Date = IncYear(FromDatePicker->Date, 1) - 1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriorButtonClick(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, -1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, 1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectItem1ComboBoxChange(TObject *Sender)
{
	Item1AllCheckBox->Checked = true;
	Item1CodeEditF->Text = AnsiString();
	Item1NameEditF->Text = AnsiString();
	Item1CodeEditT->Text = AnsiString();
	Item1NameEditT->Text = AnsiString();

	ShabanPanel1->Visible = SelectItem1ComboBox->ItemIndex == 0 ? true : false;
/*
	if (SelectItem1ComboBox->ItemIndex == 0){
		Item1AllCheckBox->Enabled = false;
		Item1CodeEditF->Enabled = false;
		Item1NameEditF->Enabled = false;
		Item1SearchButtonF->Enabled  =false;
		Item1CodeEditT->Enabled = false;
		Item1NameEditT->Enabled = false;
		Item1SearchButtonT->Enabled  =false;
	}else{
		Item1AllCheckBox->Enabled = true;
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1AllCheckBoxClick(TObject *Sender)
{
	Item1CodeEditF->Enabled     = !Item1AllCheckBox->Checked;
	Item1NameEditF->Enabled     = !Item1AllCheckBox->Checked;
	Item1CodeEditT->Enabled     = !Item1AllCheckBox->Checked;
	Item1NameEditT->Enabled     = !Item1AllCheckBox->Checked;
	if (SelectItem1ComboBox->ItemIndex != 0){
		Item1SearchButtonF->Enabled = !Item1AllCheckBox->Checked;
		Item1SearchButtonT->Enabled = !Item1AllCheckBox->Checked;
	}else{
		Item1SearchButtonF->Enabled = false;
		Item1SearchButtonT->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1CodeEditFChange(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == 0 || Item1CodeEditF->Text == ""){
		Item1NameEditF->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	Item1NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item1CodeEditF->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1SearchButtonFClick(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == 0 || Item1AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEditF->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	Item1CodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1CodeEditTChange(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == 0 || Item1CodeEditT->Text == ""){
		Item1NameEditT->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	Item1NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item1CodeEditT->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1SearchButtonTClick(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == 0 || Item1AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEditT->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	Item1CodeEditT->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectItem2ComboBoxChange(TObject *Sender)
{
	Item2AllCheckBox->Checked = true;
	Item2CodeEditF->Text = AnsiString();
	Item2NameEditF->Text = AnsiString();
	Item2CodeEditT->Text = AnsiString();
	Item2NameEditT->Text = AnsiString();

	ShabanPanel2->Visible = SelectItem2ComboBox->ItemIndex == 0 ? true : false;
/*
	if (SelectItem2ComboBox->ItemIndex == 0){
		Item2AllCheckBox->Enabled = false;
		Item2CodeEditF->Enabled = false;
		Item2NameEditF->Enabled = false;
		Item2SearchButtonF->Enabled  =false;
		Item2CodeEditT->Enabled = false;
		Item2NameEditT->Enabled = false;
		Item2SearchButtonT->Enabled  =false;
	}else{
		Item2AllCheckBox->Enabled = true;
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2AllCheckBoxClick(TObject *Sender)
{
	Item2CodeEditF->Enabled     = !Item2AllCheckBox->Checked;
	Item2NameEditF->Enabled     = !Item2AllCheckBox->Checked;
	Item2CodeEditT->Enabled     = !Item2AllCheckBox->Checked;
	Item2NameEditT->Enabled     = !Item2AllCheckBox->Checked;
	if (SelectItem2ComboBox->ItemIndex != 0){
		Item2SearchButtonF->Enabled = !Item2AllCheckBox->Checked;
		Item2SearchButtonT->Enabled = !Item2AllCheckBox->Checked;
	}else{
		Item2SearchButtonF->Enabled = false;
		Item2SearchButtonT->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2CodeEditFChange(TObject *Sender)
{
	if (SelectItem2ComboBox->ItemIndex == 0 || Item2CodeEditF->Text == ""){
		Item2NameEditF->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	Item2NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item2CodeEditF->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2SearchButtonFClick(TObject *Sender)
{
	if (SelectItem2ComboBox->ItemIndex == 0 || Item2AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEditF->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	Item2CodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2CodeEditTChange(TObject *Sender)
{
	if (SelectItem2ComboBox->ItemIndex == 0 || Item2CodeEditT->Text == ""){
		Item2NameEditT->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	Item2NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item2CodeEditT->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2SearchButtonTClick(TObject *Sender)
{
	if (SelectItem2ComboBox->ItemIndex == 0 || Item2AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEditT->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	Item2CodeEditT->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpotAllCheckBoxClick(TObject *Sender)
{
	SpotCodeEdit->Enabled = !SpotAllCheckBox->Checked;
	SpotNameEdit->Enabled = !SpotAllCheckBox->Checked;
	SpotSearchButton->Enabled = !SpotAllCheckBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpotCodeEditChange(TObject *Sender)
{
	if (SpotCodeEdit->Text == ""){
		SpotNameEdit->Text = AnsiString();
		return;
	}

	SpotNameEdit->Text = ToString(DM->DBI.Lookup("M_拠点", "拠点コード", SpotCodeEdit->Text.ToIntDef(0), "拠点名称", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpotSearchButtonClick(TObject *Sender)
{
	if (SpotAllCheckBox->Checked)
		return;

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 拠点コード, 拠点名称 FROM M_拠点 ";
	SearchForm->orderby_sql = " ORDER BY 拠点コード ";
	SearchForm->table_name = "M_拠点";
	SearchForm->list_->CommaText = "拠点コード,拠点名称";
	if (SearchForm->ShowModal() != mrOk)
		return;
	SpotCodeEdit->Text = SearchForm->Query->FieldByName("拠点コード")->AsInteger;
	SpotCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetItems()
{
	SelectItem1ComboBox->Items->Clear();
	item_map_.clear();
	int index = 0;
	AnsiString buff;

	// 請求先追加
	SelectItem1ComboBox->Items->Add("請求先");
	item_map_[index] = "請求先";
	index++;

	// 車両追加
	SelectItem1ComboBox->Items->Add("車両");
	item_map_[index] = "車両";
	index++;

	// 得意先追加
	if (ToInt(DM->config_["得意先マスタ使用区分"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["得意先マスタ名称"]), " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "得意先";
		index++;
	}
	// 品目追加
	if (ToInt(DM->config_["品目マスタ使用区分"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]), " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "品目";
		index++;

		// 品目分類追加
		buff = AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]) + "分類", " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "品目分類";
		index++;
	}

	// 項目1追加
	if (ToInt(DM->config_["項目1マスタ使用区分"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["項目1マスタ名称"]), " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "項目1";
		index++;
	}
	// 項目2追加
	if (ToInt(DM->config_["項目2マスタ使用区分"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["項目2マスタ名称"]), " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "項目2";
		index++;
	}
/*
	// 搬入出区分
	if (ToInt(DM->config_["入出庫使用区分"]) != 1){
		IoDivLabel->Visible = false;
		IoDivComboBox->Visible = false;
	}else{
		IoDivLabel->Visible = true;
		IoDivComboBox->Visible = true;
	}
*/
	SelectItem2ComboBox->Items->Text = SelectItem1ComboBox->Items->Text;
/*
	// レポート設定
	if (ToInt(DM->config_["単価使用区分"]) == 0){
		QRForm->MoneyLabel->Enabled     = false;
		QRForm->MoneyText->Enabled      = false;
		QRForm->MoneyExpr->Enabled      = false;
		QRForm->Item1MoneyExpr->Enabled = false;
	}else{
		QRForm->MoneyLabel->Enabled     = true;
		QRForm->MoneyText->Enabled      = true;
		QRForm->MoneyExpr->Enabled      = true;
		QRForm->Item1MoneyExpr->Enabled = true;
	}
*/
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::OpenQuery()
{
	AnsiString target_total1, target_code1, target_name1;
	AnsiString target_total2, target_code2, target_name2;
	if (SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] == "車両"){
		if (SharyoRadioButton1->Checked){
			target_total1 = "車両ID";
			QRForm->ItemText1->Enabled = true;
		}else{
			target_total1 = "車番";
			QRForm->ItemText1->Enabled = false;
		}
		target_code1  = "車番";
		target_name1  = "車両名称";
	}else{
		QRForm->ItemText1->Enabled = true;
		target_total1 = item_map_[SelectItem1ComboBox->ItemIndex] + "コード";
		target_code1  = item_map_[SelectItem1ComboBox->ItemIndex] + "コード";
		target_name1  = item_map_[SelectItem1ComboBox->ItemIndex] + "略称";
	}
	if (SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] == "車両"){
		if (SharyoRadioButton2->Checked){
			target_total2 = "車両ID";
			QRForm->ItemText2->Enabled = true;
		}else{
			target_total2 = "車番";
			QRForm->ItemText2->Enabled = false;
		}
		target_code2  = "車番";
		target_name2  = "車両名称";
	}else{
		QRForm->ItemText2->Enabled = true;
		target_total2 = item_map_[SelectItem2ComboBox->ItemIndex] + "コード";
		target_code2  = item_map_[SelectItem2ComboBox->ItemIndex] + "コード";
		target_name2  = item_map_[SelectItem2ComboBox->ItemIndex] + "略称";
	}
	AnsiString where = " V.取引日 BETWEEN " + FromDatePicker->Date.FormatString("yyyymmdd") + " AND " + ToDatePicker->Date.FormatString("yyyymmdd");

	if (!Item1AllCheckBox->Checked){
		if (Item1CodeEditF->Text == "" || Item1CodeEditT->Text == ""){
			Application->MessageBox("項目が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND V." + target_code1 + " >= " + Item1CodeEditF->Text + " AND V." + target_code1 + " <= " + Item1CodeEditT->Text;
	}
	if (!Item2AllCheckBox->Checked){
		if (Item2CodeEditF->Text == "" || Item2CodeEditT->Text == ""){
			Application->MessageBox("項目が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND V." + target_code2 + " >= " + Item2CodeEditF->Text + " AND V." + target_code2 + " <= " + Item2CodeEditT->Text;
	}

	if (!SpotAllCheckBox->Checked){
		if (SpotCodeEdit->Text == ""){
			Application->MessageBox("拠点が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND V.拠点ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", SpotCodeEdit->Text.ToIntDef(0), "拠点ID", "")));
	}

	if (TorihikiComboBox->ItemIndex > 0)
		where += " AND V.取引区分 = " + IntToStr(TorihikiComboBox->ItemIndex);

	if (GenkakeComboBox->ItemIndex != 0){
		if (GenkakeComboBox->ItemIndex == -1){
			Application->MessageBox("現掛区分が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND V.現掛区分 = " + IntToStr(GenkakeComboBox->ItemIndex);
	}

	QRForm->Query->Close();
	QRForm->Query->SQL->Text = DM->GetReportSQL(target_total1, target_code1, target_name1,
												target_total2, target_code2, target_name2, where);
    //RichEdit1->Text = QRForm->Query->SQL->Text;
	try{
		QRForm->Query->Open();
	}catch (Exception &e){
		Application->MessageBox(("データ集計に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
/*
	QRForm->TitleLabel->Caption    = item_map_[SelectItem1ComboBox->ItemIndex] + "別" + item_map_[SelectItem2ComboBox->ItemIndex] + "別集計表";
	QRForm->Item1Label->Caption    = item_map_[SelectItem1ComboBox->ItemIndex];
	QRForm->Item2Label->Caption    = item_map_[SelectItem2ComboBox->ItemIndex];
	QRForm->SumItem1Label->Caption = "【" + item_map_[SelectItem1ComboBox->ItemIndex] + "計】";
*/
	QRForm->TitleLabel->Caption    = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "別" + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "別集計表【取引】";
	QRForm->Item1Label->Caption    = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex];
	QRForm->Item2Label->Caption    = SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex];
	QRForm->SumItem1Label->Caption = "【" + SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "計】";
	AnsiString range = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);

	if (!SpotAllCheckBox->Checked)
		range += "　拠点：" + SpotNameEdit->Text;

	range += "　取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
	range += "　現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];

	QRForm->RangeLabel->Caption = range;
	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExcelOut()
{
	AnsiString buff = AnsiString();
	TADOQuery *query = QRForm->Query;
	int row, start_row, old_item1_id = 0;
	std::auto_ptr<TStringList> row_list(new TStringList());

	XlBook book(ExtractFilePath(Application->ExeName) + "取引2項目別集計表.xls");
	try{
		InfoPanel->Visible = true;

		Application->ProcessMessages();

		book.open(false);
		Variant app_obj = book.getAppObj();

		Cells cells;

		// タイトル・日付など埋め込み
		cells[1][1] = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "別" + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "別集計表【取引】";
		buff = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);
		if (!SpotAllCheckBox->Checked)
			buff += "　拠点：" + SpotNameEdit->Text;
		buff += "　取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
		buff += "　現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];
		cells[2][1] = buff;
		cells[4][1] = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex];
		cells[4][2] = SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex];

		row = 5;
		start_row = 5;
		while (!query->Eof){
			Application->ProcessMessages();

			if (SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] == "車両" && !SharyoRadioButton1->Checked)
				cells[row][1] = query->FieldByName("項目コード1")->AsString;
			else
				cells[row][1] = query->FieldByName("項目コード1")->AsString + "：" + query->FieldByName("項目略称1")->AsString;
			if (SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] == "車両" && !SharyoRadioButton2->Checked)
				cells[row][2] = query->FieldByName("項目コード2")->AsString;
			else
				cells[row][2] = query->FieldByName("項目コード2")->AsString + "：" + query->FieldByName("項目略称2")->AsString;
			cells[row][3] = FormatFloat("#,##0", query->FieldByName("回数")->AsInteger);
			cells[row][4] = FormatFloat("#,##0.0##", query->FieldByName("合計数量")->AsCurrency);
			cells[row][5] = query->FieldByName("単位")->AsString;
			cells[row][6] = FormatFloat("#,##0", query->FieldByName("合計金額")->AsCurrency);

			row++;

			old_item1_id = query->FieldByName("項目ID1")->AsInteger;

			query->Next();

			if (query->Eof || old_item1_id != query->FieldByName("項目ID1")->AsInteger){
				cells[row][2] = "【 " + SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "計 】";
				cells[row][3] = "=SUM(C" + IntToStr(start_row) + ":C" + IntToStr(row - 1) + ")";
				cells[row][6] = "=SUM(F" + IntToStr(start_row) + ":F" + IntToStr(row - 1) + ")";

				row_list->Add(IntToStr(row));
				row++;
				start_row = row;
			}
		}

		// 合計
		cells[row][1] = "【 合 計 】";
		AnsiString expr1 = AnsiString(), expr2 = AnsiString(), expr3 = AnsiString();
		for (int i = 0; i < row_list->Count; i++){
			if (expr1 != "")
				expr1 += " + ";
			else
				expr1 += "=";
			expr1 += "C" + row_list->Strings[i];

			if (expr3 != "")
				expr3 += " + ";
			else
				expr3 += "=";
			expr3 += "F" + row_list->Strings[i];
		}
		cells[row][3] = expr1;
		cells[row][4] = expr2;
		cells[row][6] = expr3;

		book.setCellsToSheet("雛型", cells);

	}catch (Exception &e){
		Application->MessageBox(("Excel出力に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	InfoPanel->Visible = false;
	Application->MessageBox("完了しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	book.setVisible(true);
}
//---------------------------------------------------------------------------

