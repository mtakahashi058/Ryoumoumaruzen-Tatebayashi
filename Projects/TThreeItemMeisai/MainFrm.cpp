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

	SelectItem3ComboBox->ItemIndex = 0;
	SelectItem3ComboBox->OnChange(NULL);
	Item3AllCheckBox->OnClick(NULL);

	SpotAllCheckBox->Checked = true;
	SpotCodeEdit->Text = AnsiString();
	SpotNameEdit->Text = AnsiString();
	SpotAllCheckBox->OnClick(NULL);

//	IoDivComboBox->ItemIndex = 0;

	SetPrinter(QRForm->QuickRep, ToString(DM->INI["Printer::Report"]));

	FromDatePicker->SetFocus();

    if (ParamCount() < 1)
        return;

    switch (ParamStr(1).ToIntDef(0)){
        case 1:
            DayRadioButton->Checked = true;
            DayRadioButton->OnClick(NULL);
            break;
        case 2:
            MonthRadioButton->Checked = true;
            MonthRadioButton->OnClick(NULL);
            break;
        case 3:
            YearRadioButton->Checked = true;
            YearRadioButton->OnClick(NULL);
            break;
    }

    if (ParamStr(2).ToIntDef(0) < 4)
        SelectItem1ComboBox->ItemIndex = ParamStr(2).ToIntDef(0);

    if (ParamStr(3).ToIntDef(0) < 4)
        SelectItem2ComboBox->ItemIndex = ParamStr(3).ToIntDef(0);

    if (ParamStr(4).ToIntDef(0) < 4)
        SelectItem3ComboBox->ItemIndex = ParamStr(4).ToIntDef(0);
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
	}else if (ActiveControl == Item3CodeEditF || ActiveControl == Item3NameEditF){
		if (SelectItem3ComboBox->ItemIndex == 0)
			return;
		Item3SearchButtonF->OnClick(NULL);
	}else if (ActiveControl == Item3CodeEditT || ActiveControl == Item3NameEditT){
		if (SelectItem3ComboBox->ItemIndex == 0)
			return;
		Item3SearchButtonT->OnClick(NULL);
	}else if (ActiveControl == SpotCodeEdit || ActiveControl == SpotNameEdit){
		SpotSearchButton->OnClick(NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintActionExecute(TObject *Sender)
{
	if (SelectItem1ComboBox->ItemIndex == SelectItem2ComboBox->ItemIndex ||
		SelectItem1ComboBox->ItemIndex == SelectItem3ComboBox->ItemIndex ||
		SelectItem2ComboBox->ItemIndex == SelectItem3ComboBox->ItemIndex){
		Application->MessageBox("抽出項目のいずれかが重複しています。\r\n別々の抽出項目を設定した上で、再度実行して下さい。",
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
	if (SelectItem1ComboBox->ItemIndex == SelectItem2ComboBox->ItemIndex ||
		SelectItem1ComboBox->ItemIndex == SelectItem3ComboBox->ItemIndex ||
		SelectItem2ComboBox->ItemIndex == SelectItem3ComboBox->ItemIndex){
		Application->MessageBox("抽出項目のいずれかが重複しています。\r\n別々の抽出項目を設定した上で、再度実行して下さい。",
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
	if (SelectItem1ComboBox->ItemIndex == SelectItem2ComboBox->ItemIndex ||
		SelectItem1ComboBox->ItemIndex == SelectItem3ComboBox->ItemIndex ||
		SelectItem2ComboBox->ItemIndex == SelectItem3ComboBox->ItemIndex){
		Application->MessageBox("抽出項目のいずれかが重複しています。\r\n別々の抽出項目を設定した上で、再度実行して下さい。",
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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1AllCheckBoxClick(TObject *Sender)
{
	Item1CodeEditF->Enabled     = !Item1AllCheckBox->Checked;
	Item1NameEditF->Enabled     = !Item1AllCheckBox->Checked;
	Item1CodeEditT->Enabled     = !Item1AllCheckBox->Checked;
	Item1NameEditT->Enabled     = !Item1AllCheckBox->Checked;

	Item1SearchButtonF->Enabled = !Item1AllCheckBox->Checked;
	Item1SearchButtonT->Enabled = !Item1AllCheckBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1CodeEditFChange(TObject *Sender)
{
	if (Item1CodeEditF->Text == ""){
		Item1NameEditF->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	Item1NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item1CodeEditF->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1SearchButtonFClick(TObject *Sender)
{
	if (Item1AllCheckBox->Checked)
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
	if (Item1CodeEditT->Text == ""){
		Item1NameEditT->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	Item1NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item1CodeEditT->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1SearchButtonTClick(TObject *Sender)
{
	if (Item1AllCheckBox->Checked)
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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2AllCheckBoxClick(TObject *Sender)
{
	Item2CodeEditF->Enabled     = !Item2AllCheckBox->Checked;
	Item2NameEditF->Enabled     = !Item2AllCheckBox->Checked;
	Item2CodeEditT->Enabled     = !Item2AllCheckBox->Checked;
	Item2NameEditT->Enabled     = !Item2AllCheckBox->Checked;

	Item2SearchButtonF->Enabled = !Item2AllCheckBox->Checked;
	Item2SearchButtonT->Enabled = !Item2AllCheckBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2CodeEditFChange(TObject *Sender)
{
	if (Item2CodeEditF->Text == ""){
		Item2NameEditF->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	Item2NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item2CodeEditF->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2SearchButtonFClick(TObject *Sender)
{
	if (Item2AllCheckBox->Checked)
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
	if (Item2CodeEditT->Text == ""){
		Item2NameEditT->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	Item2NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item2CodeEditT->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2SearchButtonTClick(TObject *Sender)
{
	if (Item2AllCheckBox->Checked)
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
void __fastcall TMainForm::SelectItem3ComboBoxChange(TObject *Sender)
{
	Item3AllCheckBox->Checked = true;
	Item3CodeEditF->Text = AnsiString();
	Item3NameEditF->Text = AnsiString();
	Item3CodeEditT->Text = AnsiString();
	Item3NameEditT->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item3AllCheckBoxClick(TObject *Sender)
{
	Item3CodeEditF->Enabled     = !Item3AllCheckBox->Checked;
	Item3NameEditF->Enabled     = !Item3AllCheckBox->Checked;
	Item3CodeEditT->Enabled     = !Item3AllCheckBox->Checked;
	Item3NameEditT->Enabled     = !Item3AllCheckBox->Checked;

	Item3SearchButtonF->Enabled = !Item3AllCheckBox->Checked;
	Item3SearchButtonT->Enabled = !Item3AllCheckBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item3CodeEditFChange(TObject *Sender)
{
	if (Item3CodeEditF->Text == ""){
		Item3NameEditF->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem3ComboBox->ItemIndex];

	Item3NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item3CodeEditF->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item3SearchButtonFClick(TObject *Sender)
{
	if (Item3AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem3ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item3CodeEditF->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	Item3CodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item3CodeEditTChange(TObject *Sender)
{
	if (Item3CodeEditT->Text == ""){
		Item3NameEditT->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItem3ComboBox->ItemIndex];

	Item3NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", Item3CodeEditT->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item3SearchButtonTClick(TObject *Sender)
{
	if (Item3AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem3ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item3CodeEditT->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	Item3CodeEditT->SetFocus();
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
	SelectItem3ComboBox->Items->Text = SelectItem1ComboBox->Items->Text;

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
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::OpenQuery()
{
	AnsiString target_total1, target_code1, target_name1;
	AnsiString target_total2, target_code2, target_name2;
	AnsiString target_total3, target_code3, target_name3;

	target_total1 = item_map_[SelectItem1ComboBox->ItemIndex] + "コード";
	target_code1  = item_map_[SelectItem1ComboBox->ItemIndex] + "コード";
	target_name1  = item_map_[SelectItem1ComboBox->ItemIndex] + "略称";

	target_total2 = item_map_[SelectItem2ComboBox->ItemIndex] + "コード";
	target_code2  = item_map_[SelectItem2ComboBox->ItemIndex] + "コード";
	target_name2  = item_map_[SelectItem2ComboBox->ItemIndex] + "略称";

	target_total3 = item_map_[SelectItem3ComboBox->ItemIndex] + "コード";
	target_code3  = item_map_[SelectItem3ComboBox->ItemIndex] + "コード";
	target_name3  = item_map_[SelectItem3ComboBox->ItemIndex] + "略称";

	AnsiString where = " 取引日 BETWEEN " + FromDatePicker->Date.FormatString("yyyymmdd") + " AND " + ToDatePicker->Date.FormatString("yyyymmdd");

	if (!Item1AllCheckBox->Checked){
		if (Item1CodeEditF->Text == "" || Item1CodeEditT->Text == ""){
			Application->MessageBox("項目1が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND " + target_code1 + " >= " + Item1CodeEditF->Text + " AND " + target_code1 + " <= " + Item1CodeEditT->Text;
	}
	if (!Item2AllCheckBox->Checked){
		if (Item2CodeEditF->Text == "" || Item2CodeEditT->Text == ""){
			Application->MessageBox("項目2が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND " + target_code2 + " >= " + Item2CodeEditF->Text + " AND " + target_code2 + " <= " + Item2CodeEditT->Text;
	}
	if (!Item3AllCheckBox->Checked){
		if (Item3CodeEditF->Text == "" || Item3CodeEditT->Text == ""){
			Application->MessageBox("項目3が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND " + target_code3 + " >= " + Item3CodeEditF->Text + " AND " + target_code3 + " <= " + Item3CodeEditT->Text;
	}

	if (!SpotAllCheckBox->Checked){
		if (SpotCodeEdit->Text == ""){
			Application->MessageBox("拠点が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND 拠点ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", SpotCodeEdit->Text.ToIntDef(0), "拠点ID", "")));
	}
/*
	if (IoDivComboBox->ItemIndex != 0){
		if (IoDivComboBox->ItemIndex == -1){
			Application->MessageBox("搬入出区分が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND 搬入出区分 = " + IntToStr(IoDivComboBox->ItemIndex);
	}
*/
	if (TorihikiComboBox->ItemIndex > 0)
		where += " AND 取引区分 = " + IntToStr(TorihikiComboBox->ItemIndex);

	if (GenkakeComboBox->ItemIndex != 0){
		if (GenkakeComboBox->ItemIndex == -1){
			Application->MessageBox("現掛区分が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND 現掛区分 = " + IntToStr(GenkakeComboBox->ItemIndex);
	}

	QRForm->Query->Close();
	QRForm->Query->SQL->Text = DM->GetReportSQL(target_total1, target_code1, target_name1,
												target_total2, target_code2, target_name2,
												target_total3, target_code3, target_name3, where);

	QRForm->MeigaraQuery->Close();
	QRForm->MeigaraQuery->SQL->Text = DM->GetHinShukeiSQL(where);
//	RichEdit1->Lines->Text = QRForm->Query->SQL->Text;

	try{
		QRForm->Query->Open();
		QRForm->MeigaraQuery->Open();
	}catch (Exception &e){
		Application->MessageBox(("データ集計に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	QRForm->ITEM1 = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex];
	QRForm->TitleLabel->Caption    = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "別" +
									 SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "別" +
									 SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "別明細表";
	QRForm->Item2NameLabel->Caption    = SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex];
	QRForm->Item3NameLabel->Caption    = SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex];
	QRForm->SumItem1Label->Caption = "【" + SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "計】";
	QRForm->SumItem2Label->Caption = "【" + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "計】";
	QRForm->SumItem3Label->Caption = "【" + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "計】";
	AnsiString range = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);
/*
	if (ToInt(DM->config_["入出庫使用区分"]) == 1)
		range += "　搬入出区分：" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];
*/
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
	// フォルダぐりぐり用変数
	AnsiString dir = ToString(DM->INI["Excel::SaveDirectory"]);
	AnsiString search_target = dir + "取引3項目別明細表" + Date().FormatString("yyyymmdd") + "*.xls";
	HANDLE find_handle;
	WIN32_FIND_DATA find_data;

	// 出力先のディレクトリ内にある出力日のファイルを全て削除する
	find_handle = FindFirstFile(search_target.c_str(), &find_data);
	do {
		if (find_handle == INVALID_HANDLE_VALUE)
			break;

		if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			continue;

		if (!DeleteFile(dir + find_data.cFileName))
			continue;
	} while(FindNextFile(find_handle, &find_data));

	AnsiString buff = AnsiString();
	TADOQuery *query = QRForm->Query;
	int row, old_item1 = -1, old_item2 = -1, old_item3 = -1, old_date = -1;
	int sheet_count = 1, book_count = 1;
	Currency sum_net1   = 0, sum_net2   = 0, sum_net3   = 0, sum_net_total   = 0;
	Currency sum_money1 = 0, sum_money2 = 0, sum_money3 = 0, sum_money_total = 0;
	int max_sheet = ToInt(DM->INI["Excel::MaxSheet"]);
	AnsiString item1_code, item1_name;
	Variant sheet, exBorders;
	int index;
	AnsiString line_cells;
	std::auto_ptr<TStringList> detail_rows (new TStringList());
	std::auto_ptr<TStringList> meisum_rows (new TStringList());

	XlBook book(ExtractFilePath(Application->ExeName) + "取引3項目別明細表.xls");

	try{
		InfoPanel->Visible = true;

		Application->ProcessMessages();

		book.open(false);
		Variant app_obj = book.getAppObj();

		Cells cells;

		// タイトル・日付など埋め込み
		cells[1][1] = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "別" + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "別" + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "別明細表【取引】";
		buff = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);
/*
		if (ToInt(DM->config_["入出庫使用区分"]) == 1)
			buff += "　搬入出区分：" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];
*/
		if (!SpotAllCheckBox->Checked)
			buff += "　拠点：" + SpotNameEdit->Text;
		buff += "　取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
		buff += "　現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];
		cells[2][1] = buff;
		cells[5][1] = SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex];
		cells[5][2] = SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex];

		if (ToInt(DM->config_["単品多段区分"]) == 2)
			cells[5][5]  = "行No";

		if (ToInt(DM->config_["単価使用区分"]) == 1){
			cells[5][7]  = "数量";
			cells[5][8]  = "単位";
			cells[5][9]  = "単価";
			cells[5][10] = "金額";
		}

		book.setCellsToSheet("雛型", cells);

		row = 6;
		AnsiString expr1 = AnsiString(), expr2 = AnsiString(), expr3 = AnsiString();
		while (!query->Eof){
			Application->ProcessMessages();

			if (old_item2 != query->FieldByName("項目コード2")->AsInteger){
				cells[row][1]  = query->FieldByName("項目コード2")->AsString + "：" + query->FieldByName("項目略称2")->AsString;
				cells[row][2]  = query->FieldByName("項目コード3")->AsString + "：" + query->FieldByName("項目略称3")->AsString;
				cells[row][3]  = IntToDate(query->FieldByName("取引日")->AsInteger);
			}else if (old_item3 != query->FieldByName("項目コード3")->AsInteger){
				cells[row][2]  = query->FieldByName("項目コード3")->AsString + "：" + query->FieldByName("項目略称3")->AsString;
				cells[row][3]  = IntToDate(query->FieldByName("取引日")->AsInteger);
			}else if (old_date != query->FieldByName("取引日")->AsInteger){
				cells[row][3]  = IntToDate(query->FieldByName("取引日")->AsInteger);
			}
			cells[row][4]  = query->FieldByName("伝票No")->AsInteger;
			if (ToInt(DM->config_["単品多段区分"]) == 2)
				cells[row][5]  = query->FieldByName("行No")->AsInteger;
			cells[row][6]  = query->FieldByName("車番")->AsInteger;
			if (ToInt(DM->config_["単価使用区分"]) == 1){
				cells[row][7]  = FormatFloat("#,##0.0##", query->FieldByName("数量")->AsCurrency);
				cells[row][8]  = query->FieldByName("単位マスタ名称")->AsString;
				cells[row][9]  = FormatFloat("#,##0.###", query->FieldByName("単価")->AsCurrency);
				cells[row][10] = FormatFloat("#,##0", query->FieldByName("金額")->AsCurrency);
			}
			sum_money1      += query->FieldByName("金額")->AsCurrency;
			sum_money2      += query->FieldByName("金額")->AsCurrency;
			sum_money3      += query->FieldByName("金額")->AsCurrency;
			sum_money_total += query->FieldByName("金額")->AsCurrency;

			detail_rows->Add(IntToStr(row));
			row++;

			old_item1 = query->FieldByName("項目コード1")->AsInteger;
			old_item2 = query->FieldByName("項目コード2")->AsInteger;
			old_item3 = query->FieldByName("項目コード3")->AsInteger;
			old_date  = query->FieldByName("取引日")->AsInteger;

			query->Next();

			if (query->Eof){
				item1_code = query->FieldByName("項目コード1")->AsInteger;
				item1_name = ToString(DM->DBI.Lookup("M_" + item_map_[SelectItem1ComboBox->ItemIndex], item_map_[SelectItem1ComboBox->ItemIndex] + "コード", query->FieldByName("項目コード1")->AsInteger, item_map_[SelectItem1ComboBox->ItemIndex] + "略称"));
			}else if (old_item1 != query->FieldByName("項目コード1")->AsInteger){
				item1_code = old_item1;
				item1_name = ToString(DM->DBI.Lookup("M_" + item_map_[SelectItem1ComboBox->ItemIndex], item_map_[SelectItem1ComboBox->ItemIndex] + "コード", old_item1, item_map_[SelectItem1ComboBox->ItemIndex] + "略称"));
			}else if (old_item3 != query->FieldByName("項目コード3")->AsInteger){
				if (ToInt(DM->config_["単価使用区分"]) == 1){
					cells[row][2]  = "【 " + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "計 】";
					cells[row][10] = sum_money3;
					sum_money3 = 0;
					row++;
				}

				if (old_item2 != query->FieldByName("項目コード2")->AsInteger){
					if (ToInt(DM->config_["単価使用区分"]) == 1){
						cells[row][2]  = "【 " + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "計 】";
						cells[row][10] = sum_money2;
						sum_money2 = 0;
						row++;
					}
				}
			}else if (old_item2 != query->FieldByName("項目コード2")->AsInteger){
				if (ToInt(DM->config_["単価使用区分"]) == 1){
					cells[row][2]  = "【 " + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "計 】";
					cells[row][10] = sum_money2;
					sum_money2 = 0;
					row++;
				}
			}

			if (query->Eof || old_item1 != query->FieldByName("項目コード1")->AsInteger){
				cells[4][1] = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "：" + item1_code + "  " + item1_name;

				if (ToInt(DM->config_["単価使用区分"]) == 1){
					cells[row][2]  = "【 " + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "計 】";
					cells[row][10] = sum_money3;
					sum_money3 = 0;
					row++;
				}

				if (ToInt(DM->config_["単価使用区分"]) == 1){
					cells[row][2]  = "【 " + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "計 】";
					cells[row][10] = sum_money2;
					sum_money2 = 0;
					row++;
				}

				if (ToInt(DM->config_["単価使用区分"]) == 1){
					cells[row][2]  = "【 " + SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "計 】";
					cells[row][10] = sum_money1;
					sum_money1 = 0;
					row++;
				}

				if (query->Eof){
					if (SumHinmokuCheckBox->Checked){
						row++;
						cells[row][1]  = "【銘柄別集計】";
						while(!QRForm->MeigaraQuery->Eof){
							cells[row][2]  = QRForm->MeigaraQuery->FieldByName("品目名称")->AsString;
							cells[row][7]  = QRForm->MeigaraQuery->FieldByName("数量")->AsCurrency;
							cells[row][8]  = QRForm->MeigaraQuery->FieldByName("単位名称")->AsString;
							if (ToInt(DM->config_["単価使用区分"]) == 1)
								cells[row][10] = QRForm->MeigaraQuery->FieldByName("金額")->AsCurrency;

							QRForm->MeigaraQuery->Next();
							meisum_rows->Add(IntToStr(row));
							row++;
						}
						row++;
					}

					row++;
					if (ToInt(DM->config_["単価使用区分"]) == 1){
						cells[row][2]  = "【 合    計 】";
						cells[row][10] = sum_money_total;
						sum_money_total = 0;
					}
				}

				if (sheet_count == max_sheet){
					book.getAppObj().Exec(PropertyGet("ActiveWorkBook")).Exec(Procedure("SaveAs") << dir + "取引3項目別明細表" + Date().FormatString("yyyymmdd") + "_" +  IntToStr(book_count) + ".xls");
					book.quit();

					book.open(true);
					sheet_count = 1;
					book_count++;
				}
				sheet = book.getWorksheet("雛型");
				book.copySheet(sheet, 1);

				sheet = book.getWorksheet(1);
				// 命名規則に反する文字を削除
				if (item1_name.AnsiPos(":") != 0){
					index = item1_name.AnsiPos(":");
					item1_name.Delete(index, 1);
				}
				if (item1_name.AnsiPos("\\") != 0){
					index = item1_name.AnsiPos("\\");
					item1_name.Delete(index, 1);
				}
				if (item1_name.AnsiPos("/") != 0){
					index = item1_name.AnsiPos("/");
					item1_name.Delete(index, 1);
				}
				if (item1_name.AnsiPos("?") != 0){
					index = item1_name.AnsiPos("?");
					item1_name.Delete(index, 1);
				}
				if (item1_name.AnsiPos("*") != 0){
					index = item1_name.AnsiPos("*");
					item1_name.Delete(index, 1);
				}
				if (item1_name.AnsiPos("[") != 0){
					index = item1_name.AnsiPos("[");
					item1_name.Delete(index, 1);
				}
				if (item1_name.AnsiPos("]") != 0){
					index = item1_name.AnsiPos("]");
					item1_name.Delete(index, 1);
				}
				// sheet名変更
				book.changeSheetName(sheet, item1_code + "_" + item1_name);

				book.setCellsToSheetObj(sheet, cells);

				for (int i = 0; i < detail_rows->Count; i++){
					line_cells = "A" + detail_rows->Strings[i] + ":J" + detail_rows->Strings[i];
					exBorders = sheet.Exec(PropertyGet("Range") << line_cells).Exec(PropertyGet("Borders") << 9);
					exBorders.Exec(PropertySet("LineStyle") << 2);
				}

				for (int i = 0; i < meisum_rows->Count; i++){
					line_cells = "B" + meisum_rows->Strings[i] + ":J" + meisum_rows->Strings[i];
					exBorders = sheet.Exec(PropertyGet("Range") << line_cells).Exec(PropertyGet("Borders") << 9);
					exBorders.Exec(PropertySet("LineStyle") << 2);
				}

				if (query->Eof){
					line_cells = "A" + IntToStr(row) + ":J" + IntToStr(row);
					exBorders = sheet.Exec(PropertyGet("Range") << line_cells).Exec(PropertyGet("Borders") << 9);
					exBorders.Exec(PropertySet("LineStyle") << 1);
				}

				old_item1 = -1;
				old_item2 = -1;
				old_item3 = -1;
				old_date  = -1;
				detail_rows->Clear();

				row = 6;
				sheet_count++;
				cells.clear();
			}
		}
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
