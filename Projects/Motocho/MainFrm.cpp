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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
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
	if (ActiveControl == SpotAllCheckBox || ActiveControl == SpotCodeEdit || ActiveControl == SpotNameEdit)
		SpotSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintActionExecute(TObject *Sender)
{
	if (Application->MessageBox("������܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
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
	if (Application->MessageBox("�o�͂��܂����H",
			this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!OpenQuery())
		return;

	std::auto_ptr<TStringList> records(new TStringList());
	Table2Str(QRForm->Query, records.get(), true, true);
	//Table2Str(QRForm->Query, records.get(), true); // 2018/06/27 "use_displaytext = true"��ǉ�
	SaveDialog->FileName = "�v�ʌ���_" + Date().FormatString("yyyymmdd") + ".csv";
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

	m = ToInt(DM->config_["������t"]);

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
void __fastcall TMainForm::SetItems()
{
	// �����o�敪
	if (ToInt(DM->config_["���o�Ɏg�p�敪"]) != 1){
		IoDivLabel->Visible = false;
		IoDivComboBox->Visible = false;
	}else{
		IoDivLabel->Visible = true;
		IoDivComboBox->Visible = true;
	}

	AnsiString buff;

	if (ToInt(DM->config_["���Ӑ�}�X�^�g�p�敪"]) == 1){
//		QRForm->TokuisakiCodeLabel->Enabled = true;
		QRForm->TokuisakiNameLabel->Enabled = true;
		QRForm->TokuisakiCodeText->Enabled  = true;
		QRForm->TokuisakiNameText->Enabled  = true;

		buff = ToString(DM->config_["���Ӑ�}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		QRForm->TokuisakiNameLabel->Caption = buff;
	}else{
		QRForm->TokuisakiNameLabel->Enabled = false;
		QRForm->TokuisakiCodeText->Enabled  = false;
		QRForm->TokuisakiNameText->Enabled  = false;
	}

	if (ToInt(DM->config_["����1�}�X�^�g�p�敪"]) == 1){
//		QRForm->Item1CodeLabel->Enabled = true;
		QRForm->Item1NameLabel->Enabled = true;
		QRForm->Item1CodeText->Enabled  = true;
		QRForm->Item1NameText->Enabled  = true;

		buff = ToString(DM->config_["����1�}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		QRForm->Item1NameLabel->Caption = buff;
	}else{
		QRForm->Item1NameLabel->Enabled = false;
		QRForm->Item1CodeText->Enabled  = false;
		QRForm->Item1NameText->Enabled  = false;
	}

	if (ToInt(DM->config_["����2�}�X�^�g�p�敪"]) == 1){
//		QRForm->Item2CodeLabel->Enabled = true;
		QRForm->Item2NameLabel->Enabled = true;
		QRForm->Item2CodeText->Enabled  = true;
		QRForm->Item2NameText->Enabled  = true;

		buff = ToString(DM->config_["����2�}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		QRForm->Item2NameLabel->Caption = buff;
	}else{
		QRForm->Item2NameLabel->Enabled = false;
		QRForm->Item2CodeText->Enabled  = false;
		QRForm->Item2NameText->Enabled  = false;
	}

	if (ToInt(DM->config_["�i�ڃ}�X�^�g�p�敪"]) == 1){
		HinbunLabel->Visible        = true;
		HinbunAllCheckBox->Visible  = true;
		HinbunCodeEdit->Visible     = true;
		HinbunNameEdit->Visible     = true;
		HinbunSearchButton->Visible = true;

		buff = ToString(DM->config_["�i�ڃ}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		HinbunLabel->Caption        = buff + "���ށF";

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

	QRForm->IoLabel->Enabled = ToInt(DM->config_["���o�Ɏg�p�敪"]) == 1 ? true : false;
	QRForm->IoText->Enabled  = ToInt(DM->config_["���o�Ɏg�p�敪"]) == 1 ? true : false;

	if (ToInt(DM->config_["�d�ʈ����g�p�敪"]) == 1){
		QRForm->JuryobikiLabel->Enabled = true;
		QRForm->JuryobikiText->Enabled  = true;

		buff = ToString(DM->config_["�d�ʈ�������"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		QRForm->JuryobikiLabel->Caption = buff;
	}else{
		QRForm->JuryobikiLabel->Enabled = false;
		QRForm->JuryobikiText->Enabled  = false;
	}

	if (ToInt(DM->config_["�����g�p�敪"]) == 1){
		QRForm->ChoseiPLabel->Enabled = true;
		QRForm->ChoseiWLabel->Enabled = true;
		QRForm->ChoseiPText->Enabled  = true;
		QRForm->ChoseiWText->Enabled  = true;

		buff = ToString(DM->config_["��������"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		QRForm->ChoseiPText->Caption  = buff + "(%)";
		QRForm->ChoseiWText->Caption  = buff + "(kg)";
	}else{
		QRForm->ChoseiPLabel->Enabled = false;
		QRForm->ChoseiWLabel->Enabled = false;
		QRForm->ChoseiPText->Enabled  = false;
		QRForm->ChoseiWText->Enabled  = false;
	}

	if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
		QRForm->PriceLabel->Enabled     = true;
		QRForm->MoneyLabel->Enabled     = true;
		QRForm->SlipTaxLabel->Enabled   = true;
		QRForm->PriceText->Enabled      = true;
		QRForm->MoneyText->Enabled      = true;
		QRForm->SlipTaxText->Enabled    = true;
		if (ToInt(DM->config_["�P�i���i�敪"]) == 2){
			QRForm->DetailTaxLabel->Enabled = true;
			QRForm->DetailTaxText->Enabled  = true;
		}else{
			QRForm->DetailTaxLabel->Enabled = false;
			QRForm->DetailTaxText->Enabled  = false;
		}
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

	QRForm->DetailBikoLabel->Enabled = ToInt(DM->config_["�P�i���i�敪"]) == 1 ? false : true;
	QRForm->DetailBikoText->Enabled  = ToInt(DM->config_["�P�i���i�敪"]) == 1 ? false : true;
	QRForm->LineNoLabel->Enabled     = ToInt(DM->config_["�P�i���i�敪"]) == 1 ? false : true;
	QRForm->LineNoText->Enabled      = ToInt(DM->config_["�P�i���i�敪"]) == 1 ? false : true;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::OpenQuery()
{
	AnsiString where = AnsiString();

	if (!HinbunAllCheckBox->Checked && HinbunCodeEdit->Text != "")
		where += " AND �i�ڕ��ރR�[�h = " + HinbunCodeEdit->Text;

	if (!SpotAllCheckBox->Checked && SpotCodeEdit->Text != "")
		where += " AND ���_ID = " + ToString(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_ID", ""));

	if (IoDivComboBox->ItemIndex != 0)
		where += " AND �����o�敪 = " + IntToStr(IoDivComboBox->ItemIndex);

	QRForm->Query->Close();
	QRForm->Query->SQL->Text = DM->GetReportSQL(where);

	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value = FromDatePicker->Date.FormatString("yyyymmdd");
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value   = ToDatePicker->Date.FormatString("yyyymmdd");

	try{
		QRForm->Query->Open();
	}catch (Exception &e){
		Application->MessageBox(("�����f�[�^�̒��o�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	AnsiString range = AnsiString();
	range = "�o�͔͈́F" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date);
	if (ToInt(DM->config_["�i�ڃ}�X�^�g�p�敪"]) == 1){
		if (HinbunAllCheckBox->Checked)
			range += "�@�i�ڕ��ށF���ׂ�";
		else
			range += "�@�i�ڕ��ށF" + HinbunNameEdit->Text;
	}
	if (SpotAllCheckBox->Checked)
		range += "�@���_�F���ׂ�";
	else
		range += "�@���_�F" + SpotNameEdit->Text;
	if (IoDivComboBox->ItemIndex != 0)
		range += "�@�����o�敪�F���ׂ�";
	else
		range += "�@�����o�敪�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];
	QRForm->RangeLabel->Caption = range;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinbunAllCheckBoxClick(TObject *Sender)
{
	HinbunCodeEdit->Enabled = !HinbunAllCheckBox->Checked;
	HinbunNameEdit->Enabled = !HinbunAllCheckBox->Checked;
    HinbunSearchButton->Enabled = !HinbunAllCheckBox->Checked;
    if (!HinbunAllCheckBox->Checked)
    	HinbunCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpotAllCheckBoxClick(TObject *Sender)
{
	SpotCodeEdit->Enabled = !SpotAllCheckBox->Checked;
	SpotNameEdit->Enabled = !SpotAllCheckBox->Checked;
	SpotSearchButton->Enabled = !SpotAllCheckBox->Checked;
    if (!SpotAllCheckBox->Checked)
    	SpotCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinbunCodeEditChange(TObject *Sender)
{
	HinbunNameEdit->Text = ToString(DM->DBI.Lookup("M_�i�ڕ���", "�i�ڕ��ރR�[�h", HinbunCodeEdit->Text.ToIntDef(0), "�i�ڕ��ޖ���"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpotCodeEditChange(TObject *Sender)
{
	if (SpotCodeEdit->Text == ""){
		SpotNameEdit->Text = AnsiString();
		return;
	}

	SpotNameEdit->Text = ToString(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_����", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinbunSearchButtonClick(TObject *Sender)
{
	if (HinbunAllCheckBox->Checked)
		return;

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT �i�ڕ��ރR�[�h, �i�ڕ��ޖ��� FROM M_�i�ڕ��� ";
	SearchForm->orderby_sql = " ORDER BY �i�ڕ��ރR�[�h ";
	SearchForm->table_name = "M_�i�ڕ���";
	SearchForm->list_->CommaText = "�i�ڕ��ރR�[�h,�i�ڕ��ޖ���";
	if (SearchForm->ShowModal() != mrOk)
		return;
	HinbunCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڕ��ރR�[�h")->AsInteger;
	HinbunCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpotSearchButtonClick(TObject *Sender)
{
	if (SpotAllCheckBox->Checked)
		return;

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT ���_�R�[�h, ���_���� FROM M_���_ ";
	SearchForm->orderby_sql = " ORDER BY ���_�R�[�h ";
	SearchForm->table_name = "M_���_";
	SearchForm->list_->CommaText = "���_�R�[�h,���_����";
	if (SearchForm->ShowModal() != mrOk)
		return;
	SpotCodeEdit->Text = SearchForm->Query->FieldByName("���_�R�[�h")->AsInteger;
	SpotCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------

