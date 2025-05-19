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

	YearEdit->Text = Date().FormatString("yyyy");

	SelectItemComboBox->ItemIndex = 0;
	SelectItemComboBox->OnChange(NULL);
	ItemAllCheckBox->OnClick(NULL);

	SpotAllCheckBox->Checked = true;
	SpotCodeEdit->Text = AnsiString();
	SpotNameEdit->Text = AnsiString();
	SpotAllCheckBox->OnClick(NULL);

	IoDivComboBox->ItemIndex = 0;

	YearEdit->SetFocus();
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

	XlBook book(ExtractFilePath(Application->ExeName) + "月別集計表雛型.xls");
	try{
		book.open(true);
		Variant sheet = book.getWorksheet("データシート");
		Variant app_obj = book.getAppObj();
		Cells cells;

		// タイトル等の埋め込み
		cells[2][2] = YearEdit->Text + "年度";
		cells[2][5] = QRForm->RangeLabel->Caption;

		// データ埋め込み
		TDateTime dt = FromDatePicker->Date;
		int month;

		for (int i = 0; i < 12; i++){
			month = dt.FormatString("yyyymm").ToIntDef(0);
			cells[5 + i][1] = dt.FormatString("mm") + "月";

			if (q_shukei->Locate("年月", month, TLocateOptions())){
				cells[5 + i][2] = q_shukei->FieldByName("正味重量")->AsCurrency;
				cells[5 + i][3] = q_shukei->FieldByName("金額")->AsCurrency;
			}else{
				cells[5 + i][2] = "0";
				cells[5 + i][3] = "0";
			}

			dt = IncMonth(dt, 1);
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
// 各フィールドのフィールド名を取得する
AnsiString __fastcall TMainForm::GetFieldName(int index)
{
	AnsiString field_name;
	if (index == 0)
		field_name = "車番";
	else
		field_name = item_map_[index] + "コード";

	return field_name;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetQuery()
{
	QRForm->Query->Close();
	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);
	QRForm->RangeLabel->Caption = "出力範囲：" + DateToStr(FromDatePicker->Date) + "～" + DateToStr(ToDatePicker->Date);
	QRForm->start_date = FromDatePicker->Date;

	if (!ItemAllCheckBox->Checked){
		QRForm->Query->SQL->Strings[17] = "AND	" + GetFieldName(SelectItemComboBox->ItemIndex) + " >= " + IntToStr(ItemCodeEditF->Text.ToIntDef(0)) + " AND " + GetFieldName(SelectItemComboBox->ItemIndex) + " <= " + IntToStr(ItemCodeEditT->Text.ToIntDef(0));
		if (SelectItemComboBox->ItemIndex != 0)
			QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "：" + ItemNameEditF->Text + "～" + ItemNameEditT->Text;
		else
			QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "：" + ItemCodeEditF->Text + "～" + ItemCodeEditT->Text;
	}else{
		QRForm->Query->SQL->Strings[17] = "";
	}

	if (!SpotAllCheckBox->Checked && SpotCodeEdit->Text.ToIntDef(0) != 0){
		QRForm->Query->SQL->Strings[18] = "AND	拠点ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", SpotCodeEdit->Text.ToIntDef(0), "拠点ID")));
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  拠点：" + SpotNameEdit->Text;
	}else{
		QRForm->Query->SQL->Strings[18] = "";
	}

	if (IoDivComboBox->ItemIndex != 0){
		QRForm->Query->SQL->Strings[19] = "AND	搬入出区分 = " + IntToStr(IoDivComboBox->ItemIndex);
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  搬入出：" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];
	}else{
		QRForm->Query->SQL->Strings[19] = "";
	}

	if (TorihikiComboBox->ItemIndex != 0){
		QRForm->Query->SQL->Strings[20] = " AND 取引区分 = " + IntToStr(TorihikiComboBox->ItemIndex);
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
	}else{
		QRForm->Query->SQL->Strings[20] = AnsiString();
	}

	if (GenkakeComboBox->ItemIndex != 0){
		QRForm->Query->SQL->Strings[21] = " AND 現掛区分 = " + IntToStr(GenkakeComboBox->ItemIndex);
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];
	}else
		QRForm->Query->SQL->Strings[21] = "";

	QRForm->Query->Open();

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriorButtonClick(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, -1);
	YearEdit->Text = FromDatePicker->Date.FormatString("yyyy");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, 1);
	YearEdit->Text = FromDatePicker->Date.FormatString("yyyy");
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
	SearchForm->list_->CommaText = target + "コード," + target + "名称" + target + "カナ";
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
	SearchForm->list_->CommaText = target + "コード," + target + "名称" + target + "カナ";
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
// 年度->OnChange
void __fastcall TMainForm::YearEditChange(TObject *Sender)
{
	if (YearEdit->Text.ToIntDef(0) < 2000)
		return;

	WORD y, m, d;
	Date().DecodeDate(&y, &m, &d);

	y = YearEdit->Text.ToIntDef(0);
	m = ToString(DM->config_["期首月"]).ToIntDef(4);

	try{
		FromDatePicker->Date = EncodeDate(y, m, 1);
	}catch (...){
		FromDatePicker->Date = EncodeDate(y, 4, 1);
	}
	ToDatePicker->Date = IncYear(FromDatePicker->Date, 1) - 1;
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


