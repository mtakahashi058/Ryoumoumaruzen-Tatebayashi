//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
#include <DateUtils.hpp>
#include <SysUtils.hpp>
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

	IoDivComboBox->ItemIndex = 1;
	GenkakeComboBox->ItemIndex = 0;

	MaxCountEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SanshoActionExecute(TObject *Sender)
{
	if (ActiveControl == ItemCodeEditF || ActiveControl == ItemNameEditF)
		ItemSearchButtonF->OnClick(NULL);
	else if (ActiveControl == ItemCodeEditT || ActiveControl == ItemNameEditT)
		ItemSearchButtonT->OnClick(NULL);
	else if (ActiveControl == SpotAllCheckBox || ActiveControl == SpotCodeEdit || ActiveControl == SpotNameEdit)
		SpotSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintActionExecute(TObject *Sender)
{
	if (Application->MessageBox("印刷しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;
	if (!SetQuery())
		return;
	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PreviewActionExecute(TObject *Sender)
{
	if (!SetQuery())
		return;
	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OutputActionExecute(TObject *Sender)
{
	if (!SetQuery())
		return;

	TADOQuery *q_shukei = QRForm->Query;

	XlBook book(ExtractFilePath(Application->ExeName) + "取引順位表雛型.xls");
	try{
		book.open(true);
		Variant sheet = book.getWorksheet("データシート");
		Variant app_obj = book.getAppObj();

		// 書式＋計算式のコピー
		if (QRForm->Query->RecordCount > 2){
			// 雛型シートの２行目をコピー
			sheet.Exec(PropertyGet("Range") << sheet.Exec(PropertyGet("Cells") << 5 << 1) << sheet.Exec(PropertyGet("Cells") << 5 << 9)).Exec(Procedure("Select"));
			app_obj.Exec(PropertyGet("Selection")).Exec(Procedure("Copy"));
			// データ数に応じてペースト
			sheet.Exec(PropertyGet("Range") << sheet.Exec(PropertyGet("Cells") << 6 << 1) << sheet.Exec(PropertyGet("Cells") << QRForm->Query->RecordCount + 4 << 9)).Exec(Procedure("Select"));
			sheet.Exec(Procedure("Paste"));
			// コピーモード終了
			app_obj.Exec(PropertySet("CutCopyMode") << "False");
		}

		Cells cells;

		// タイトル等の埋め込み
		cells[2][1] = "【出力範囲】　" + where_rep;

		// 総合計
		NsRecordSet set;
		if (DM->DBI.GetRecordSet("SELECT SUM(" + orderby + ") AS 合計 FROM V_取引 WHERE 取引日 BETWEEN " + IntToStr(DateToInt(FromDatePicker->Date)) + " AND " + IntToStr(DateToInt(ToDatePicker->Date)) + where, set))
			cells[3][12] = ToString(set[0]["合計"]);

		// データ埋め込み
		int row = 4;
		while (!q_shukei->Eof){
			cells[row][2] = q_shukei->FieldByName("項目コード")->AsString;
			cells[row][3] = q_shukei->FieldByName("項目略称")->AsString;
			cells[row][4] = q_shukei->FieldByName("金額")->AsCurrency;
			row++;
			q_shukei->Next();
		}

		// Excel書き込み
		book.setCellsToSheet("データシート", cells);

		// 先頭にフォーカス
		sheet.Exec(PropertyGet("Cells") << 1 << 1).Exec(Procedure("Select"));

	}catch (Exception &e){
		Application->MessageBox(("Excel書き込み中にエラーが発生しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		book.quit();
	}

	Application->MessageBox("完了しました。\r\nこのファイルを保存する場合は、[ファイル]->[名前を付けて保存]を行ってください", "出力", MB_OK | MB_ICONINFORMATION | MB_TOPMOST);

	try{
		keybd_event(VK_MENU, 0, 0, 0);
		keybd_event(VK_TAB, 0, 0, 0);
		keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
	}catch (...){
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndActionExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetQuery()
{
	where     = AnsiString();
	where_rep = AnsiString();

	QRForm->Query->Close();
	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);

	// TOP
	QRForm->Query->SQL->Strings[6] = "TOP " + IntToStr(MaxCountEdit->Text.ToIntDef(0));
	where_rep += "出力件数＝" + MaxCountEdit->Text + "位まで  ";

	// ORDER BY
	where_rep += "金額上位順  ";
	orderby = "金額";

	if (SelectItemComboBox->ItemIndex == 0){
		// *** 車両の場合 ***
		// 項目名セット
		QRForm->Query->SQL->Strings[7] = "	車番 AS 項目コード,";
		QRForm->Query->SQL->Strings[8] = "	MAX(車両名称) AS 項目略称,";
		// GROUP BY セット
		QRForm->Query->SQL->Strings[19] = "車両ID, 車番";

	}else{
		// 項目名セット
		QRForm->Query->SQL->Strings[7] = "	"     + item_map_[SelectItemComboBox->ItemIndex] + "コード AS 項目コード,";
		QRForm->Query->SQL->Strings[8] = "	MAX(" + item_map_[SelectItemComboBox->ItemIndex] + "略称) AS 項目略称,";
		// GROUP BY セット
		QRForm->Query->SQL->Strings[19] = item_map_[SelectItemComboBox->ItemIndex] + "コード";
	}
	where_rep += "項目：" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "  ";

	// *** WHERE ***
	// 項目
	if (!ItemAllCheckBox->Checked){
		if (SelectItemComboBox->ItemIndex == 0){
			where += " AND 車番 >= " + IntToStr(ItemCodeEditF->Text.ToIntDef(0)) + " AND 車番 <= " + IntToStr(ItemCodeEditT->Text.ToIntDef(0));
			where_rep += "車番：" + ItemCodeEditF->Text + "～" + ItemCodeEditT->Text + "  ";
		}else{
			where += " AND " + item_map_[SelectItemComboBox->ItemIndex] + "コード >= " + IntToStr(ItemCodeEditF->Text.ToIntDef(0)) + " AND " + item_map_[SelectItemComboBox->ItemIndex] + "コード <= " + IntToStr(ItemCodeEditT->Text.ToIntDef(0));
			where_rep += item_map_[SelectItemComboBox->ItemIndex] + "：" + ItemNameEditF->Text + "～" + ItemNameEditT->Text + "  ";
		}
	}
	// 拠点
	if (!SpotAllCheckBox->Checked){
		where += " AND 拠点ID = " + ToString(DM->DBI.Lookup("M_拠点", "拠点コード", SpotCodeEdit->Text.ToIntDef(0), "拠点ID", ""));
		where_rep += "拠点：" + SpotNameEdit->Text + "  ";
	}
	// 取引区分
	if (IoDivComboBox->ItemIndex > 0)
		where += " AND 取引区分 = " + IntToStr(IoDivComboBox->ItemIndex);
	where_rep += "搬入出：" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex] + "  ";
	// 現掛区分
	if (GenkakeComboBox->ItemIndex != 0){
		where += " AND 現掛区分 = " + IntToStr(GenkakeComboBox->ItemIndex);
		where_rep += "現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex] + "  ";
	}
	QRForm->Query->SQL->Strings[16] = where;
	QRForm->Query->SQL->Strings[21] = orderby + " DESC";
	QRForm->Query->Open();

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	// 項目タイトルをセット
	QRForm->KomokuLabel->Caption = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];
	// 出力条件をセット
	QRForm->RangeLabel->Caption = "【出力範囲】 " + where_rep;

	return true;
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
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemAllCheckBoxClick(TObject *Sender)
{
	ItemCodeEditF->Enabled = !ItemAllCheckBox->Checked;
	ItemNameEditF->Enabled = !ItemAllCheckBox->Checked;
	ItemSearchButtonF->Enabled = !ItemAllCheckBox->Checked;

	ItemCodeEditT->Enabled = !ItemAllCheckBox->Checked;
	ItemNameEditT->Enabled = !ItemAllCheckBox->Checked;
	ItemSearchButtonT->Enabled = !ItemAllCheckBox->Checked;
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
	SelectItemComboBox->Items->Clear();
	item_map_.clear();
	int index = 0;

	// 車両追加
	SelectItemComboBox->Items->Add("車両");
	item_map_[index] = "車両";
	index++;

	// 得意先追加
	if (ToInt(DM->config_["得意先マスタ使用区分"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["得意先マスタ名称"]));
		item_map_[index] = "得意先";
		index++;
	}
	// 品目追加
	if (ToInt(DM->config_["品目マスタ使用区分"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["品目マスタ名称"]));
		item_map_[index] = "品目";
		index++;
	}

	// 品目分類追加
	SelectItemComboBox->Items->Add("品目分類");
	item_map_[index] = "品目分類";
	index++;

	// 項目1追加
	if (ToInt(DM->config_["項目1マスタ使用区分"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["項目1マスタ名称"]));
		item_map_[index] = "項目1";
		index++;
	}
	// 項目2追加
	if (ToInt(DM->config_["項目2マスタ使用区分"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["項目2マスタ名称"]));
		item_map_[index] = "項目2";
		index++;
	}
*/
}
//---------------------------------------------------------------------------
// TPanel->OnEnter
void __fastcall TMainForm::Panel4Enter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
// TPanel->OnExit
void __fastcall TMainForm::Panel4Exit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if ((Key == VK_RETURN || Key == VK_DOWN) && ActiveControl->Tag != 99)
		keybd_event(VK_TAB, 0, 0, 0);
	else if (Key == VK_UP && ActiveControl->Tag != 1){
		keybd_event(VK_SHIFT, 0, 0, 0);
		keybd_event(VK_TAB, 0, 0, 0);
		keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	}
}
//---------------------------------------------------------------------------

