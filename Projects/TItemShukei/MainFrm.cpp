//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
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

	SelectItemComboBox->ItemIndex = 0;
	SelectItemComboBox->OnChange(NULL);
	ItemAllCheckBox->OnClick(NULL);

	SpotAllCheckBox->Checked = true;
	SpotCodeEdit->Text = AnsiString();
	SpotNameEdit->Text = AnsiString();
	SpotAllCheckBox->OnClick(NULL);

	TorihikiComboBox->ItemIndex = 1;
	GenkakeComboBox->ItemIndex  = 0;

	SetPrinter(QRForm->QuickRep, ToString(DM->ini_["Printer::Report"]));

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
        SelectItemComboBox->ItemIndex = ParamStr(2).ToIntDef(0);
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
	if (ActiveControl == ItemCodeEditF || ActiveControl == ItemNameEditF){
		if (SelectItemComboBox->ItemIndex == 0)
			return;
		ItemSearchButtonF->OnClick(NULL);
	}else if (ActiveControl == ItemCodeEditT || ActiveControl == ItemNameEditT){
		if (SelectItemComboBox->ItemIndex == 0)
			return;
		ItemSearchButtonT->OnClick(NULL);
	}else if (ActiveControl == SpotAllCheckBox || ActiveControl == SpotCodeEdit || ActiveControl == SpotNameEdit){
		SpotSearchButton->OnClick(NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintActionExecute(TObject *Sender)
{
	if (Application->MessageBox("印刷しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!OpenQuery())
		return;

	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PreviewActionExecute(TObject *Sender)
{
	if (!OpenQuery())
		return;

	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OutputActionExecute(TObject *Sender)
{
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
void __fastcall TMainForm::SelectItemComboBoxChange(TObject *Sender)
{
	ItemAllCheckBox->Checked = true;
	ItemCodeEditF->Text = AnsiString();
	ItemNameEditF->Text = AnsiString();
	ItemCodeEditT->Text = AnsiString();
	ItemNameEditT->Text = AnsiString();

	ShabanPanel->Visible = SelectItemComboBox->ItemIndex == 0 ? true : false;
/*
	if (SelectItemComboBox->ItemIndex == 0){
		ItemAllCheckBox->Enabled = false;
		ItemCodeEditF->Enabled = false;
		ItemNameEditF->Enabled = false;
		ItemSearchButtonF->Enabled  =false;
		ItemCodeEditT->Enabled = false;
		ItemNameEditT->Enabled = false;
		ItemSearchButtonT->Enabled  =false;
	}else{
		ItemAllCheckBox->Enabled = true;
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemAllCheckBoxClick(TObject *Sender)
{
	ItemCodeEditF->Enabled     = !ItemAllCheckBox->Checked;
	ItemNameEditF->Enabled     = !ItemAllCheckBox->Checked;
	ItemCodeEditT->Enabled     = !ItemAllCheckBox->Checked;
	ItemNameEditT->Enabled     = !ItemAllCheckBox->Checked;
	if (SelectItemComboBox->ItemIndex != 0){
		ItemSearchButtonF->Enabled = !ItemAllCheckBox->Checked;
		ItemSearchButtonT->Enabled = !ItemAllCheckBox->Checked;
	}else{
		ItemSearchButtonF->Enabled = false;
		ItemSearchButtonT->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemCodeEditFChange(TObject *Sender)
{
	if (SelectItemComboBox->ItemIndex == 0 || ItemCodeEditF->Text == ""){
		ItemNameEditF->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItemComboBox->ItemIndex];

	ItemNameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", ItemCodeEditF->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemSearchButtonFClick(TObject *Sender)
{
	if (SelectItemComboBox->ItemIndex == 0 || ItemAllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItemComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	ItemCodeEditF->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	ItemCodeEditF->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemCodeEditTChange(TObject *Sender)
{
	if (SelectItemComboBox->ItemIndex == 0 || ItemCodeEditT->Text == ""){
		ItemNameEditT->Text = AnsiString();
		return;
	}

	AnsiString target = item_map_[SelectItemComboBox->ItemIndex];

	ItemNameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "コード", ItemCodeEditT->Text.ToIntDef(0), target + "名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemSearchButtonTClick(TObject *Sender)
{
	if (SelectItemComboBox->ItemIndex == 0 || ItemAllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItemComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "コード, " + target + "名称 FROM M_" + target + " WHERE 使用区分 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "コード ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "コード," + target + "名称," + target + "カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	ItemCodeEditT->Text = SearchForm->Query->FieldByName(target + "コード")->AsInteger;
	ItemCodeEditT->SetFocus();
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
	SelectItemComboBox->Items->Clear();
	item_map_.clear();
	int index = 0;
	AnsiString buff;

	// 車両追加
	SelectItemComboBox->Items->Add("車両");
	item_map_[index] = "車両";
	index++;

	// 得意先追加
	if (ToInt(DM->config_["得意先マスタ使用区分"]) != 0){
		buff = ToString(DM->config_["得意先マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "得意先";
		index++;
	}
	// 品目追加
	if (ToInt(DM->config_["品目マスタ使用区分"]) != 0){
		buff = ToString(DM->config_["品目マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "品目";
		index++;

		// 品目分類追加
		buff = ToString(DM->config_["品目マスタ名称"]) + "分類";
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "品目分類";
		index++;
	}

	// 項目1追加
	if (ToInt(DM->config_["項目1マスタ使用区分"]) != 0){
		buff = ToString(DM->config_["項目1マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "項目1";
		index++;
	}

	// 項目2追加
	if (ToInt(DM->config_["項目2マスタ使用区分"]) != 0){
		buff = ToString(DM->config_["項目2マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "項目2";
		index++;
	}
/*
	// レポート設定
	if (ToInt(DM->config_["単価使用区分"]) == 0){
		QRForm->MoneyLabel->Enabled = false;
		QRForm->MoneyText->Enabled = false;
		QRForm->MoneyExpr->Enabled = false;
	}else{
		QRForm->MoneyLabel->Enabled = true;
		QRForm->MoneyText->Enabled = true;
		QRForm->MoneyExpr->Enabled = true;
	}
*/
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::OpenQuery()
{
	AnsiString target_total;
	AnsiString target_code;
	AnsiString target_name;
	if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "車両"){
		if (SharyoRadioButton->Checked){
			target_total = "車両ID";
			QRForm->ItemText->Enabled = true;
		}else{
			target_total = "車番";
			QRForm->ItemText->Enabled = false;
		}
		target_code = "車番";
		target_name = "車両名称";
	}else{
		QRForm->ItemText->Enabled = true;
		target_total = item_map_[SelectItemComboBox->ItemIndex] + "コード";
		target_code = item_map_[SelectItemComboBox->ItemIndex] + "コード";
		target_name = item_map_[SelectItemComboBox->ItemIndex] + "略称";
	}
	AnsiString where = " V.取引日 BETWEEN " + FromDatePicker->Date.FormatString("yyyymmdd") + " AND " + ToDatePicker->Date.FormatString("yyyymmdd");

	if (!ItemAllCheckBox->Checked){
		if (ItemCodeEditF->Text == "" || ItemCodeEditT->Text == ""){
			Application->MessageBox("項目が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND V." + target_code + " >= " + ItemCodeEditF->Text + " AND V." + target_code + "<= " + ItemCodeEditT->Text;
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

	if (GenkakeComboBox->ItemIndex != 0)
		where += " AND V.現掛区分 = " + IntToStr(GenkakeComboBox->ItemIndex);

	QRForm->Query->Close();
	QRForm->Query->SQL->Text = DM->GetReportSQL(target_total, target_code, target_name, where);

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
	QRForm->TitleLabel->Caption = item_map_[SelectItemComboBox->ItemIndex] + "別集計表";
	QRForm->ItemLabel->Caption = item_map_[SelectItemComboBox->ItemIndex];
*/
	QRForm->TitleLabel->Caption = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "別集計表【取引】";
	QRForm->ItemLabel->Caption  = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];
	AnsiString range = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);

	if (!SpotAllCheckBox->Checked)
		range += "　拠点：" + SpotNameEdit->Text;

	range += "　取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];

	if (GenkakeComboBox->ItemIndex != -1)
		range += "　現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];

	QRForm->RangeLabel->Caption = range;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExcelOut()
{
	AnsiString buff = AnsiString();
	TADOQuery *query = QRForm->Query;
	int row;

	XlBook book(ExtractFilePath(Application->ExeName) + "取引項目別集計表.xls");
	try{
		InfoPanel->Visible = true;

		Application->ProcessMessages();

		book.open(false);
		Variant app_obj = book.getAppObj();

		Cells cells;

		// タイトル・日付など埋め込み
		cells[1][1] = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "別集計表【取引】";
		buff = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);
		if (!SpotAllCheckBox->Checked)
			buff += "　拠点：" + SpotNameEdit->Text;
		buff += "　取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
		if (GenkakeComboBox->ItemIndex != -1)
			buff += "　現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];
		cells[2][1] = buff;
		cells[4][1] = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];

		row = 5;
		while (!query->Eof){
			Application->ProcessMessages();

			if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "車両" && !SharyoRadioButton->Checked)
				cells[row][1] = query->FieldByName("項目コード")->AsString;
			else
				cells[row][1] = query->FieldByName("項目コード")->AsString + "：" + query->FieldByName("項目略称")->AsString;
			cells[row][2] = FormatFloat("#,##0", query->FieldByName("回数")->AsInteger);
			cells[row][3] = FormatFloat("#,##0.0##", query->FieldByName("合計数量")->AsCurrency);
			cells[row][4] = query->FieldByName("単位")->AsString;
			cells[row][5] = FormatFloat("#,##0", query->FieldByName("合計金額")->AsCurrency);

			row++;
			query->Next();
		}

		// 合計
		cells[row][1] = "【 合 計 】";
		cells[row][2] = "=SUM(B5:B" + IntToStr(row - 1) + ")";
		cells[row][5] = "=SUM(E5:E" + IntToStr(row - 1) + ")";

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

