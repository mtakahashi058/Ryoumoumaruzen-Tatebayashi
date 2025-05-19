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

	HinbunCodeEdit->Text = AnsiString();
	HinbunNameEdit->Text = AnsiString();
	HinbunAllCheckBox->Checked = true;
	HinbunAllCheckBox->OnClick(NULL);

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
	if (ActiveControl == SpotAllCheckBox || ActiveControl == SpotCodeEdit || ActiveControl == SpotNameEdit)
		SpotSearchButton->OnClick(NULL);
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
	if (Application->MessageBox("出力しますか？",
			this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!OpenQuery())
		return;

	std::auto_ptr<TStringList> records(new TStringList());
	Table2Str(QRForm->Query, records.get(), true);
	SaveDialog->FileName = "取引元帳_" + Date().FormatString("yyyymmdd") + ".csv";
	if (SaveDialog->Execute())
		records->SaveToFile(SaveDialog->FileName);
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
void __fastcall TMainForm::HinbunAllCheckBoxClick(TObject *Sender)
{
	HinbunCodeEdit->Enabled = !HinbunAllCheckBox->Checked;
	HinbunNameEdit->Enabled = !HinbunAllCheckBox->Checked;
	HinbunSearchButton->Enabled = !HinbunAllCheckBox->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinbunCodeEditChange(TObject *Sender)
{
	if (HinbunCodeEdit->Text == ""){
		HinbunNameEdit->Text = AnsiString();
		return;
	}

	HinbunNameEdit->Text = ToString(DM->DBI.Lookup("M_品目分類", "品目分類コード", HinbunCodeEdit->Text.ToIntDef(0), "品目分類名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinbunSearchButtonClick(TObject *Sender)
{
	if (HinbunAllCheckBox->Checked)
		return;

	AnsiString buff = ToString(DM->config_["品目マスタ名称"]);
	buff = AnsiReplaceStr(buff, " ", "");
	buff = AnsiReplaceStr(buff, "　", "");
	buff = buff + "分類";

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 品目分類コード AS " + buff + "コード, 品目分類名称 AS " + buff + "名称 FROM M_品目分類 ";
	SearchForm->orderby_sql = " ORDER BY 品目分類コード ";
	SearchForm->table_name = "M_品目分類";
	SearchForm->list_->CommaText = "品目分類コード,品目分類名称,品目分類カナ";
	if (SearchForm->ShowModal() != mrOk)
		return;
	HinbunCodeEdit->Text = SearchForm->Query->FieldByName(buff + "コード")->AsInteger;
	HinbunCodeEdit->SetFocus();
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
	AnsiString buff;

	if (ToInt(DM->config_["得意先マスタ使用区分"]) == 1){
//		QRForm->TokuisakiCodeLabel->Enabled = true;
		QRForm->TokuisakiNameLabel->Enabled = true;
		QRForm->TokuisakiCodeText->Enabled  = true;
		QRForm->TokuisakiNameText->Enabled  = true;

		buff = ToString(DM->config_["得意先マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		QRForm->TokuisakiNameLabel->Caption = buff;
	}else{
		QRForm->TokuisakiNameLabel->Enabled = false;
		QRForm->TokuisakiCodeText->Enabled  = false;
		QRForm->TokuisakiNameText->Enabled  = false;
	}

	if (ToInt(DM->config_["項目1マスタ使用区分"]) == 1){
//		QRForm->Item1CodeLabel->Enabled = true;
		QRForm->Item1NameLabel->Enabled = true;
		QRForm->Item1CodeText->Enabled  = true;
		QRForm->Item1NameText->Enabled  = true;

		buff = ToString(DM->config_["項目1マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		QRForm->Item1NameLabel->Caption = buff;
	}else{
		QRForm->Item1NameLabel->Enabled = false;
		QRForm->Item1CodeText->Enabled  = false;
		QRForm->Item1NameText->Enabled  = false;
	}

	if (ToInt(DM->config_["項目2マスタ使用区分"]) == 1){
//		QRForm->Item2CodeLabel->Enabled = true;
		QRForm->Item2NameLabel->Enabled = true;
		QRForm->Item2CodeText->Enabled  = true;
		QRForm->Item2NameText->Enabled  = true;

		buff = ToString(DM->config_["項目2マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		QRForm->Item2NameLabel->Caption = buff;
	}else{
		QRForm->Item2NameLabel->Enabled = false;
		QRForm->Item2CodeText->Enabled  = false;
		QRForm->Item2NameText->Enabled  = false;
	}

	if (ToInt(DM->config_["品目マスタ使用区分"]) == 1){
		HinbunLabel->Visible        = true;
		HinbunAllCheckBox->Visible  = true;
		HinbunCodeEdit->Visible     = true;
		HinbunNameEdit->Visible     = true;
		HinbunSearchButton->Visible = true;

		buff = ToString(DM->config_["品目マスタ名称"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "　", "");
		HinbunLabel->Caption        = buff + "分類：";

//		QRForm->HinmokuCodeLabel->Enabled = true;
		QRForm->HinmokuNameLabel->Enabled = true;
		QRForm->HinmokuCodeText->Enabled  = true;
		QRForm->HinmokuNameText->Enabled  = true;

		QRForm->HinmokuNameLabel->Caption = buff;
	}else{
		HinbunLabel->Visible        = false;
		HinbunAllCheckBox->Visible  = false;
		HinbunCodeEdit->Visible     = false;
		HinbunNameEdit->Visible     = false;
		HinbunSearchButton->Visible = false;

		QRForm->HinmokuNameLabel->Enabled = false;
		QRForm->HinmokuCodeText->Enabled  = false;
		QRForm->HinmokuNameText->Enabled  = false;
	}
/*
	if (ToInt(DM->config_["単価使用区分"]) == 1){
		QRForm->PriceLabel->Enabled     = true;
		QRForm->MoneyLabel->Enabled     = true;
		QRForm->SlipTaxLabel->Enabled   = true;
		QRForm->PriceText->Enabled      = true;
		QRForm->MoneyText->Enabled      = true;
		QRForm->SlipTaxText->Enabled    = true;
		QRForm->DetailTaxLabel->Enabled = true;
		QRForm->DetailTaxText->Enabled  = true;
	}else{
		QRForm->PriceLabel->Enabled     = false;
		QRForm->MoneyLabel->Enabled     = false;
		QRForm->DetailTaxLabel->Enabled = false;
		QRForm->SlipTaxLabel->Enabled   = false;
		QRForm->PriceText->Enabled      = false;
		QRForm->MoneyText->Enabled      = false;
		QRForm->SlipTaxText->Enabled    = false;
		QRForm->DetailTaxText->Enabled  = false;
	}
*/
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::OpenQuery()
{
	AnsiString where = AnsiString();

	if (!HinbunAllCheckBox->Checked && HinbunCodeEdit->Text != "")
		where += " AND 品目分類コード = " + HinbunCodeEdit->Text;

	if (!SpotAllCheckBox->Checked && SpotCodeEdit->Text != "")
		where += " AND 拠点ID = " + ToString(DM->DBI.Lookup("M_拠点", "拠点コード", SpotCodeEdit->Text.ToIntDef(0), "拠点ID", ""));

	if (TorihikiComboBox->ItemIndex > 0)
		where += " AND 取引区分 = " + IntToStr(TorihikiComboBox->ItemIndex);

	if (GenkakeComboBox->ItemIndex != 0)
		where += " AND 現掛区分 = " + IntToStr(GenkakeComboBox->ItemIndex);

	QRForm->Query->Close();
	QRForm->Query->SQL->Text = DM->GetReportSQL(where);

	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value = FromDatePicker->Date.FormatString("yyyymmdd");
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value   = ToDatePicker->Date.FormatString("yyyymmdd");

	try{
		QRForm->Query->Open();
	}catch (Exception &e){
		Application->MessageBox(("元帳データの抽出に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	AnsiString range = AnsiString();
	range = "出力範囲：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);
	if (ToInt(DM->config_["品目マスタ使用区分"]) == 1){
		if (HinbunAllCheckBox->Checked)
			range += "　品目分類：すべて";
		else
			range += "　品目分類：" + HinbunNameEdit->Text;
	}
	if (SpotAllCheckBox->Checked)
		range += "　拠点：すべて";
	else
		range += "　拠点：" + SpotNameEdit->Text;

	range += "　取引区分：" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];

	if (GenkakeComboBox->ItemIndex != 0)
		range += "　現掛区分：すべて";
	else
		range += "　現掛区分：" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];

	QRForm->RangeLabel->Caption = range;

	return true;
}
//---------------------------------------------------------------------------

