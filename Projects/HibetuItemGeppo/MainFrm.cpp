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
#include <map>
#include <vector>
#include <algorithm>
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

	FromDatePicker->Date = GetFirstDate(Date());
	ToDatePicker->Date   = GetLastDate(Date());

	SelectItemComboBox->ItemIndex = 0;
	SelectItemComboBox->OnChange(NULL);
	ItemAllCheckBox->OnClick(NULL);

	SpotAllCheckBox->Checked = true;
	SpotCodeEdit->Text = AnsiString();
	SpotNameEdit->Text = AnsiString();
	SpotAllCheckBox->OnClick(NULL);

	IoDivComboBox->ItemIndex = 0;

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

	// 搬入出区分
	if (ToInt(DM->config_["入出庫使用区分"]) != 1){
		IoDivLabel->Visible = false;
		IoDivComboBox->Visible = false;
	}else{
		IoDivLabel->Visible = true;
		IoDivComboBox->Visible = true;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::OpenQuery()
{
	QRForm->Query->Close();
	QRForm->TotalQuery->Close();

	AnsiString item   = AnsiString();
	AnsiString target = AnsiString();
	AnsiString where  = AnsiString();
	item = item_map_[SelectItemComboBox->ItemIndex];

	if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "車両"){
		if (SharyoRadioButton->Checked){
			target = " 		車両ID AS 項目ID, 車番 AS 項目コード, 車両名称 AS 項目略称,";
			QRForm->ItemCodeText->Enabled = true;
		}else{
			target = " 		車番   AS 項目ID, 車番 AS 項目コード, CAST(車番 AS VARCHAR) AS 項目略称,";
			QRForm->ItemCodeText->Enabled = false;
		}
	}else{
		target = " 		" + item + "ID AS 項目ID, " + item + "コード AS 項目コード, " + item + "略称 AS 項目略称,";
		QRForm->ItemCodeText->Enabled = true;
	}

	if (!ItemAllCheckBox->Checked){
		if (ItemCodeEditF->Text == "" || ItemCodeEditT->Text == ""){
			Application->MessageBox("項目が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "車両")
			where += " AND 車番 >= " + ItemCodeEditF->Text + " AND 車番 <= " + ItemCodeEditT->Text;
		else
			where += " AND " + item + "コード >= " + ItemCodeEditF->Text + " AND " + item + "コード <= " + ItemCodeEditT->Text;
	}

	if (!SpotAllCheckBox->Checked){
		if (SpotCodeEdit->Text == ""){
			Application->MessageBox("拠点が設定されていません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND 拠点ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", SpotCodeEdit->Text.ToIntDef(0), "拠点ID", "")));
	}

	if (IoDivComboBox->ItemIndex != 0){
		if (IoDivComboBox->ItemIndex == -1){
			Application->MessageBox("搬入出区分が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND 搬入出区分 = " + IntToStr(IoDivComboBox->ItemIndex);
	}

	if (TorihikiComboBox->ItemIndex > 0)
		where += " AND 取引区分 = " + IntToStr(TorihikiComboBox->ItemIndex);

	if (GenkakeComboBox->ItemIndex != 0){
		if (GenkakeComboBox->ItemIndex == -1){
			Application->MessageBox("現掛区分が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND 現掛区分 = " + IntToStr(GenkakeComboBox->ItemIndex);
	}

	QRForm->Query->SQL->Text      = DM->GetReportSQL(target, where);
	QRForm->TotalQuery->SQL->Text = DM->GetTotalSQL(where);

	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value      = DateToInt(FromDatePicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value        = DateToInt(ToDatePicker->Date);
	QRForm->TotalQuery->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	QRForm->TotalQuery->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);

//	RichEdit1->Lines->Text = QRForm->Query->SQL->Text;

	try{
		QRForm->Query->Open();
		QRForm->TotalQuery->Open();
	}catch (Exception &e){
		Application->MessageBox(("データ集計に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	QRForm->TitleLabel->Caption = "日別" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "別月報";
	QRForm->ItemLabel->Caption  = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];
	QRForm->ItemTotalLabel->Caption = "【 " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "計 】";
	AnsiString range = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);
	if (ToInt(DM->config_["入出庫使用区分"]) == 1)
		range += "　搬入出区分：" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];

	if (ItemAllCheckBox->Checked)
		range += " " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "：すべて";
	else
		range += " " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "：" + ItemNameEditF->Text + " ～ " + ItemNameEditT->Text;
	if (!SpotAllCheckBox->Checked)
		range += "　拠点：" + SpotNameEdit->Text;
	else
		range += "　拠点：すべて";

	range += "　取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
	range += "　現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];

	QRForm->RangeLabel->Caption = range;

	QRForm->DT = GetFirstDate(FromDatePicker->Date);

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExcelOut()
{
	AnsiString buff        = AnsiString();
	std::map<int, int> row_map;
	std::vector<int> col_vec;
	TADOQuery *query       = QRForm->Query;
	TADOQuery *total_query = QRForm->TotalQuery;
	int col = 2;
	int max_col = ToInt(DM->ini_["Excel::MaxCol"]) == 0 ? 250 : ToInt(DM->ini_["Excel::MaxCol"]);
	int row = 3;
	int sheet_count = 1;
	AnsiString range = AnsiString();
	std::vector<int>::iterator itr;

	XlBook book(ExtractFilePath(Application->ExeName) + "日別項目別月報.xls");
	try{
		InfoPanel->Visible = true;

		Application->ProcessMessages();

		book.open(false);
		Variant sheet      = book.getWorksheet("雛型");
		Variant page_setup = sheet.Exec(PropertyGet("PageSetup"));
		Variant app_obj    = book.getAppObj();
		Cells cells;

		// シートヘッダ編集
		buff = "日付別" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "別月報(" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date) +  ")\n";
		if (ItemAllCheckBox->Checked)
			buff += " [" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "：すべて]";
		else
			buff += " [" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "：" + ItemNameEditF->Text + " ～ " + ItemNameEditT->Text + "]";
		if (SpotAllCheckBox->Checked)
			buff += " [拠点：すべて]";
		else
			buff += " [拠点：" + SpotNameEdit->Text + "]";
		if (ToInt(DM->config_["入出庫使用区分"]) == 1)
			buff += " [搬入出区分：" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex] + "]";
		buff += " [取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex] + "]";
		buff += " [現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex] + "]";

		page_setup.Exec(PropertySet("LeftHeader") << buff);
		page_setup.Exec(PropertySet("RightHeader") << "発行日 - &D  &T\nPage - &P");

		while (!query->Eof){
			Application->ProcessMessages();

			// 縦軸セット
			if (col == 2){
				cells[1][1] = item_map_[SelectItemComboBox->ItemIndex];
				cells[2][1] = "日 付";

				row = 3;
				TDateTime dt = GetFirstDate(FromDatePicker->Date);
				for (int i = 1; i <= 31; i++){
					if (dt.FormatString("d").ToIntDef(0) == i){
						cells[row][1] = dt.FormatString("d") + "日(" + QRForm->GetWeekStr(DayOfWeek(dt)) + ")";
						row_map[i]    = row;
					}else{
						cells[row][1] = AnsiString();
						row_map[i]    = NULL;
					}
					dt++;
					row++;
				}
				cells[row][1] = "合計";
			}

			// 横軸セット
			col_vec.push_back(col);
			if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "車両" && !SharyoRadioButton->Checked)
				cells[1][col] = query->FieldByName("項目略称")->AsString;
			else
				cells[1][col] = query->FieldByName("項目コード")->AsString + ":" + query->FieldByName("項目略称")->AsString;
			cells[2][col]     = "件数(件)";
			cells[2][col + 1] = "重量(kg)";
			cells[2][col + 2] = "金額(円)";

			for (int i = 1; i <= 31; i++){
				AnsiString k_field = "件数" + FormatFloat("00", i);
				AnsiString w_field = "重量" + FormatFloat("00", i);
				AnsiString m_field = "金額" + FormatFloat("00", i);
				if (query->FieldByName(k_field)->AsCurrency != 0 && row_map[i] != NULL){
					cells[row_map[i]][col]     = query->FieldByName(k_field)->AsCurrency;
					cells[row_map[i]][col + 1] = query->FieldByName(w_field)->AsCurrency;
					cells[row_map[i]][col + 2] = query->FieldByName(m_field)->AsCurrency;
				}else if (row_map[i] == NULL){
					;
				}else{
					cells[row_map[i]][col]     = AnsiString();
					cells[row_map[i]][col + 1] = AnsiString();
					cells[row_map[i]][col + 2] = AnsiString();
				}
			}
			cells[34][col]     = "=SUM(" + toXlColumnName(col) + "1:" + toXlColumnName(col) + "33)";
			cells[34][col + 1] = "=SUM(" + toXlColumnName(col + 1) + "1:" + toXlColumnName(col + 1) + "33)";
			cells[34][col + 2] = "=SUM(" + toXlColumnName(col + 2) + "1:" + toXlColumnName(col + 2) + "33)";

			col += 3;
			query->Next();

			if (col >= max_col || query->Eof){
				if (query->Eof){
					col_vec.push_back(col);
					cells[1][col] = "【" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "計】";
					cells[2][col]     = "件数(件)";
					cells[2][col + 1] = "重量(kg)";
					cells[2][col + 2] = "金額(円)";
					for (int i = 1; i <= 31; i++){
						AnsiString k_field = "件数" + FormatFloat("00", i);
						AnsiString w_field = "重量" + FormatFloat("00", i);
						AnsiString m_field = "金額" + FormatFloat("00", i);
						if (total_query->FieldByName(k_field)->AsCurrency != 0 && row_map[i] != NULL){
							cells[row_map[i]][col]     = total_query->FieldByName(k_field)->AsCurrency;
							cells[row_map[i]][col + 1] = total_query->FieldByName(w_field)->AsCurrency;
							cells[row_map[i]][col + 2] = total_query->FieldByName(m_field)->AsCurrency;
						}else if (row_map[i] == NULL){
							;
						}else{
							cells[row_map[i]][col]     = AnsiString();
							cells[row_map[i]][col + 1] = AnsiString();
							cells[row_map[i]][col + 2] = AnsiString();
						}
					}
					cells[34][col]     = "=SUM(" + toXlColumnName(col) + "1:" + toXlColumnName(col) + "33)";
					cells[34][col + 1] = "=SUM(" + toXlColumnName(col + 1) + "1:" + toXlColumnName(col + 1) + "33)";
					cells[34][col + 2] = "=SUM(" + toXlColumnName(col + 2) + "1:" + toXlColumnName(col + 2) + "33)";
				}

				// シートコピー & データ書き出し
				Variant sheet = book.getWorksheet("雛型");
				book.copySheet(sheet, 1);

				sheet = book.getWorksheet(1);
				book.changeSheetName(sheet, "シート" + IntToStr(sheet_count));

				book.setCellsToSheetObj(sheet, cells);

				itr = std::max_element(col_vec.begin(), col_vec.end());
				// 表題セル 着色処理
				range = "A1:" + toXlColumnName(*itr + 2) + "2";
				sheet.Exec(PropertyGet("Range") << range).Exec(PropertyGet("Interior")).Exec(PropertySet("ColorIndex") << 15);
				// データセル 着色処理
				for (int i = 3; i <= 33; i++){
					range = "A" + IntToStr(i) + ":" + toXlColumnName(*itr + 2) + IntToStr(i);
					if (i % 2)
						sheet.Exec(PropertyGet("Range") << range).Exec(PropertyGet("Interior")).Exec(PropertySet("ColorIndex") << 19);
				}
				// 縦計セル 着色処理
				range = "A34:" + toXlColumnName(*itr + 2) + "34";
				sheet.Exec(PropertyGet("Range") << range).Exec(PropertyGet("Interior")).Exec(PropertySet("ColorIndex") << 37);

				// セル マージ処理
				for (std::vector<int>::iterator i = col_vec.begin(); i != col_vec.end(); i++){
					range = toXlColumnName(*i) + "1:" + toXlColumnName(*i + 2) + "1";
					sheet.Exec(PropertyGet("Range") << range).Exec(Function("Merge"));
					app_obj.Exec(PropertyGet("Range") << toXlColumnName(*i) + "1:" + toXlColumnName(*i) + "1").Exec(Function("Select"));
					app_obj.Exec(PropertyGet("Selection")).Exec(PropertySet("NumberFormatLocal") << "@");
				}

				book.run("罫線");

				col_vec.clear();
				cells.clear();
				sheet_count++;
				col = 2;
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

