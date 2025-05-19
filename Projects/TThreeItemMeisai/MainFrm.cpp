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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
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
		Application->MessageBox("���o���ڂ̂����ꂩ���d�����Ă��܂��B\r\n�ʁX�̒��o���ڂ�ݒ肵����ŁA�ēx���s���ĉ������B",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("������܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
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
		Application->MessageBox("���o���ڂ̂����ꂩ���d�����Ă��܂��B\r\n�ʁX�̒��o���ڂ�ݒ肵����ŁA�ēx���s���ĉ������B",
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
		Application->MessageBox("���o���ڂ̂����ꂩ���d�����Ă��܂��B\r\n�ʁX�̒��o���ڂ�ݒ肵����ŁA�ēx���s���ĉ������B",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("�o�͂��܂����H\r\n���o�͂��s���ɂ́A�}�C�N���\�t�g�Ђ̃G�N�Z�����K�v�ƂȂ�܂��B",
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

	Item1NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", Item1CodeEditF->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1SearchButtonFClick(TObject *Sender)
{
	if (Item1AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEditF->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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

	Item1NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", Item1CodeEditT->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1SearchButtonTClick(TObject *Sender)
{
	if (Item1AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem1ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEditT->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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

	Item2NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", Item2CodeEditF->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2SearchButtonFClick(TObject *Sender)
{
	if (Item2AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEditF->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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

	Item2NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", Item2CodeEditT->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2SearchButtonTClick(TObject *Sender)
{
	if (Item2AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem2ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEditT->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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

	Item3NameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", Item3CodeEditF->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item3SearchButtonFClick(TObject *Sender)
{
	if (Item3AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem3ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item3CodeEditF->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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

	Item3NameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", Item3CodeEditT->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item3SearchButtonTClick(TObject *Sender)
{
	if (Item3AllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItem3ComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item3CodeEditT->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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

	SpotNameEdit->Text = ToString(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_����", ""));
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
void __fastcall TMainForm::SetItems()
{
	SelectItem1ComboBox->Items->Clear();
	item_map_.clear();
	int index = 0;
	AnsiString buff;

	// ���Ӑ�ǉ�
	if (ToInt(DM->config_["���Ӑ�}�X�^�g�p�敪"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["���Ӑ�}�X�^����"]), " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "���Ӑ�";
		index++;
	}
	// �i�ڒǉ�
	if (ToInt(DM->config_["�i�ڃ}�X�^�g�p�敪"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]), " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "�i��";
		index++;

		// �i�ڕ��ޒǉ�
		buff = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]) + "����", " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "�i�ڕ���";
		index++;
	}

	// ����1�ǉ�
	if (ToInt(DM->config_["����1�}�X�^�g�p�敪"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["����1�}�X�^����"]), " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "����1";
		index++;
	}
	// ����2�ǉ�
	if (ToInt(DM->config_["����2�}�X�^�g�p�敪"]) != 0){
		buff = AnsiReplaceStr(ToString(DM->config_["����2�}�X�^����"]), " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItem1ComboBox->Items->Add(buff);
		item_map_[index] = "����2";
		index++;
	}
/*
	// �����o�敪
	if (ToInt(DM->config_["���o�Ɏg�p�敪"]) != 1){
		IoDivLabel->Visible = false;
		IoDivComboBox->Visible = false;
	}else{
		IoDivLabel->Visible = true;
		IoDivComboBox->Visible = true;
	}
*/
	SelectItem2ComboBox->Items->Text = SelectItem1ComboBox->Items->Text;
	SelectItem3ComboBox->Items->Text = SelectItem1ComboBox->Items->Text;

	// ���|�[�g�ݒ�
	if (ToInt(DM->config_["�P���g�p�敪"]) == 0){
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

	target_total1 = item_map_[SelectItem1ComboBox->ItemIndex] + "�R�[�h";
	target_code1  = item_map_[SelectItem1ComboBox->ItemIndex] + "�R�[�h";
	target_name1  = item_map_[SelectItem1ComboBox->ItemIndex] + "����";

	target_total2 = item_map_[SelectItem2ComboBox->ItemIndex] + "�R�[�h";
	target_code2  = item_map_[SelectItem2ComboBox->ItemIndex] + "�R�[�h";
	target_name2  = item_map_[SelectItem2ComboBox->ItemIndex] + "����";

	target_total3 = item_map_[SelectItem3ComboBox->ItemIndex] + "�R�[�h";
	target_code3  = item_map_[SelectItem3ComboBox->ItemIndex] + "�R�[�h";
	target_name3  = item_map_[SelectItem3ComboBox->ItemIndex] + "����";

	AnsiString where = " ����� BETWEEN " + FromDatePicker->Date.FormatString("yyyymmdd") + " AND " + ToDatePicker->Date.FormatString("yyyymmdd");

	if (!Item1AllCheckBox->Checked){
		if (Item1CodeEditF->Text == "" || Item1CodeEditT->Text == ""){
			Application->MessageBox("����1���ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND " + target_code1 + " >= " + Item1CodeEditF->Text + " AND " + target_code1 + " <= " + Item1CodeEditT->Text;
	}
	if (!Item2AllCheckBox->Checked){
		if (Item2CodeEditF->Text == "" || Item2CodeEditT->Text == ""){
			Application->MessageBox("����2���ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND " + target_code2 + " >= " + Item2CodeEditF->Text + " AND " + target_code2 + " <= " + Item2CodeEditT->Text;
	}
	if (!Item3AllCheckBox->Checked){
		if (Item3CodeEditF->Text == "" || Item3CodeEditT->Text == ""){
			Application->MessageBox("����3���ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND " + target_code3 + " >= " + Item3CodeEditF->Text + " AND " + target_code3 + " <= " + Item3CodeEditT->Text;
	}

	if (!SpotAllCheckBox->Checked){
		if (SpotCodeEdit->Text == ""){
			Application->MessageBox("���_���ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND ���_ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_ID", "")));
	}
/*
	if (IoDivComboBox->ItemIndex != 0){
		if (IoDivComboBox->ItemIndex == -1){
			Application->MessageBox("�����o�敪�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND �����o�敪 = " + IntToStr(IoDivComboBox->ItemIndex);
	}
*/
	if (TorihikiComboBox->ItemIndex > 0)
		where += " AND ����敪 = " + IntToStr(TorihikiComboBox->ItemIndex);

	if (GenkakeComboBox->ItemIndex != 0){
		if (GenkakeComboBox->ItemIndex == -1){
			Application->MessageBox("���|�敪�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND ���|�敪 = " + IntToStr(GenkakeComboBox->ItemIndex);
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
		Application->MessageBox(("�f�[�^�W�v�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	QRForm->ITEM1 = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex];
	QRForm->TitleLabel->Caption    = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "��" +
									 SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "��" +
									 SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "�ʖ��ו\";
	QRForm->Item2NameLabel->Caption    = SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex];
	QRForm->Item3NameLabel->Caption    = SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex];
	QRForm->SumItem1Label->Caption = "�y" + SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "�v�z";
	QRForm->SumItem2Label->Caption = "�y" + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "�v�z";
	QRForm->SumItem3Label->Caption = "�y" + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "�v�z";
	AnsiString range = "�o�͔͈́F" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date);
/*
	if (ToInt(DM->config_["���o�Ɏg�p�敪"]) == 1)
		range += "�@�����o�敪�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];
*/
	if (!SpotAllCheckBox->Checked)
		range += "�@���_�F" + SpotNameEdit->Text;

	range += "�@����敪�F" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
	range += "�@���|�敪�F" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];

	QRForm->RangeLabel->Caption = range;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExcelOut()
{
	// �t�H���_���肮��p�ϐ�
	AnsiString dir = ToString(DM->INI["Excel::SaveDirectory"]);
	AnsiString search_target = dir + "���3���ڕʖ��ו\" + Date().FormatString("yyyymmdd") + "*.xls";
	HANDLE find_handle;
	WIN32_FIND_DATA find_data;

	// �o�͐�̃f�B���N�g�����ɂ���o�͓��̃t�@�C����S�č폜����
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

	XlBook book(ExtractFilePath(Application->ExeName) + "���3���ڕʖ��ו\.xls");

	try{
		InfoPanel->Visible = true;

		Application->ProcessMessages();

		book.open(false);
		Variant app_obj = book.getAppObj();

		Cells cells;

		// �^�C�g���E���t�Ȃǖ��ߍ���
		cells[1][1] = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "��" + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "��" + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "�ʖ��ו\�y����z";
		buff = "�o�͔͈́F" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date);
/*
		if (ToInt(DM->config_["���o�Ɏg�p�敪"]) == 1)
			buff += "�@�����o�敪�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];
*/
		if (!SpotAllCheckBox->Checked)
			buff += "�@���_�F" + SpotNameEdit->Text;
		buff += "�@����敪�F" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
		buff += "�@���|�敪�F" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];
		cells[2][1] = buff;
		cells[5][1] = SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex];
		cells[5][2] = SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex];

		if (ToInt(DM->config_["�P�i���i�敪"]) == 2)
			cells[5][5]  = "�sNo";

		if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
			cells[5][7]  = "����";
			cells[5][8]  = "�P��";
			cells[5][9]  = "�P��";
			cells[5][10] = "���z";
		}

		book.setCellsToSheet("���^", cells);

		row = 6;
		AnsiString expr1 = AnsiString(), expr2 = AnsiString(), expr3 = AnsiString();
		while (!query->Eof){
			Application->ProcessMessages();

			if (old_item2 != query->FieldByName("���ڃR�[�h2")->AsInteger){
				cells[row][1]  = query->FieldByName("���ڃR�[�h2")->AsString + "�F" + query->FieldByName("���ڗ���2")->AsString;
				cells[row][2]  = query->FieldByName("���ڃR�[�h3")->AsString + "�F" + query->FieldByName("���ڗ���3")->AsString;
				cells[row][3]  = IntToDate(query->FieldByName("�����")->AsInteger);
			}else if (old_item3 != query->FieldByName("���ڃR�[�h3")->AsInteger){
				cells[row][2]  = query->FieldByName("���ڃR�[�h3")->AsString + "�F" + query->FieldByName("���ڗ���3")->AsString;
				cells[row][3]  = IntToDate(query->FieldByName("�����")->AsInteger);
			}else if (old_date != query->FieldByName("�����")->AsInteger){
				cells[row][3]  = IntToDate(query->FieldByName("�����")->AsInteger);
			}
			cells[row][4]  = query->FieldByName("�`�[No")->AsInteger;
			if (ToInt(DM->config_["�P�i���i�敪"]) == 2)
				cells[row][5]  = query->FieldByName("�sNo")->AsInteger;
			cells[row][6]  = query->FieldByName("�Ԕ�")->AsInteger;
			if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
				cells[row][7]  = FormatFloat("#,##0.0##", query->FieldByName("����")->AsCurrency);
				cells[row][8]  = query->FieldByName("�P�ʃ}�X�^����")->AsString;
				cells[row][9]  = FormatFloat("#,##0.###", query->FieldByName("�P��")->AsCurrency);
				cells[row][10] = FormatFloat("#,##0", query->FieldByName("���z")->AsCurrency);
			}
			sum_money1      += query->FieldByName("���z")->AsCurrency;
			sum_money2      += query->FieldByName("���z")->AsCurrency;
			sum_money3      += query->FieldByName("���z")->AsCurrency;
			sum_money_total += query->FieldByName("���z")->AsCurrency;

			detail_rows->Add(IntToStr(row));
			row++;

			old_item1 = query->FieldByName("���ڃR�[�h1")->AsInteger;
			old_item2 = query->FieldByName("���ڃR�[�h2")->AsInteger;
			old_item3 = query->FieldByName("���ڃR�[�h3")->AsInteger;
			old_date  = query->FieldByName("�����")->AsInteger;

			query->Next();

			if (query->Eof){
				item1_code = query->FieldByName("���ڃR�[�h1")->AsInteger;
				item1_name = ToString(DM->DBI.Lookup("M_" + item_map_[SelectItem1ComboBox->ItemIndex], item_map_[SelectItem1ComboBox->ItemIndex] + "�R�[�h", query->FieldByName("���ڃR�[�h1")->AsInteger, item_map_[SelectItem1ComboBox->ItemIndex] + "����"));
			}else if (old_item1 != query->FieldByName("���ڃR�[�h1")->AsInteger){
				item1_code = old_item1;
				item1_name = ToString(DM->DBI.Lookup("M_" + item_map_[SelectItem1ComboBox->ItemIndex], item_map_[SelectItem1ComboBox->ItemIndex] + "�R�[�h", old_item1, item_map_[SelectItem1ComboBox->ItemIndex] + "����"));
			}else if (old_item3 != query->FieldByName("���ڃR�[�h3")->AsInteger){
				if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
					cells[row][2]  = "�y " + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "�v �z";
					cells[row][10] = sum_money3;
					sum_money3 = 0;
					row++;
				}

				if (old_item2 != query->FieldByName("���ڃR�[�h2")->AsInteger){
					if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
						cells[row][2]  = "�y " + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "�v �z";
						cells[row][10] = sum_money2;
						sum_money2 = 0;
						row++;
					}
				}
			}else if (old_item2 != query->FieldByName("���ڃR�[�h2")->AsInteger){
				if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
					cells[row][2]  = "�y " + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "�v �z";
					cells[row][10] = sum_money2;
					sum_money2 = 0;
					row++;
				}
			}

			if (query->Eof || old_item1 != query->FieldByName("���ڃR�[�h1")->AsInteger){
				cells[4][1] = SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "�F" + item1_code + "  " + item1_name;

				if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
					cells[row][2]  = "�y " + SelectItem3ComboBox->Items->Strings[SelectItem3ComboBox->ItemIndex] + "�v �z";
					cells[row][10] = sum_money3;
					sum_money3 = 0;
					row++;
				}

				if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
					cells[row][2]  = "�y " + SelectItem2ComboBox->Items->Strings[SelectItem2ComboBox->ItemIndex] + "�v �z";
					cells[row][10] = sum_money2;
					sum_money2 = 0;
					row++;
				}

				if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
					cells[row][2]  = "�y " + SelectItem1ComboBox->Items->Strings[SelectItem1ComboBox->ItemIndex] + "�v �z";
					cells[row][10] = sum_money1;
					sum_money1 = 0;
					row++;
				}

				if (query->Eof){
					if (SumHinmokuCheckBox->Checked){
						row++;
						cells[row][1]  = "�y�����ʏW�v�z";
						while(!QRForm->MeigaraQuery->Eof){
							cells[row][2]  = QRForm->MeigaraQuery->FieldByName("�i�ږ���")->AsString;
							cells[row][7]  = QRForm->MeigaraQuery->FieldByName("����")->AsCurrency;
							cells[row][8]  = QRForm->MeigaraQuery->FieldByName("�P�ʖ���")->AsString;
							if (ToInt(DM->config_["�P���g�p�敪"]) == 1)
								cells[row][10] = QRForm->MeigaraQuery->FieldByName("���z")->AsCurrency;

							QRForm->MeigaraQuery->Next();
							meisum_rows->Add(IntToStr(row));
							row++;
						}
						row++;
					}

					row++;
					if (ToInt(DM->config_["�P���g�p�敪"]) == 1){
						cells[row][2]  = "�y ��    �v �z";
						cells[row][10] = sum_money_total;
						sum_money_total = 0;
					}
				}

				if (sheet_count == max_sheet){
					book.getAppObj().Exec(PropertyGet("ActiveWorkBook")).Exec(Procedure("SaveAs") << dir + "���3���ڕʖ��ו\" + Date().FormatString("yyyymmdd") + "_" +  IntToStr(book_count) + ".xls");
					book.quit();

					book.open(true);
					sheet_count = 1;
					book_count++;
				}
				sheet = book.getWorksheet("���^");
				book.copySheet(sheet, 1);

				sheet = book.getWorksheet(1);
				// �����K���ɔ����镶�����폜
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
				// sheet���ύX
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
		Application->MessageBox(("Excel�o�͂Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	InfoPanel->Visible = false;
	Application->MessageBox("�������܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	book.setVisible(true);
}
//---------------------------------------------------------------------------
