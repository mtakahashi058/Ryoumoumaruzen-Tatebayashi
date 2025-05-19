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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
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

	ItemNameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", ItemCodeEditF->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemSearchButtonFClick(TObject *Sender)
{
	if (SelectItemComboBox->ItemIndex == 0 || ItemAllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItemComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	ItemCodeEditF->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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

	ItemNameEditT->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", ItemCodeEditT->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemSearchButtonTClick(TObject *Sender)
{
	if (SelectItemComboBox->ItemIndex == 0 || ItemAllCheckBox->Checked)
		return;

	AnsiString target = item_map_[SelectItemComboBox->ItemIndex];

	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	ItemCodeEditT->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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
	SelectItemComboBox->Items->Clear();
	item_map_.clear();
	int index = 0;
	AnsiString buff;

	// �ԗ��ǉ�
	SelectItemComboBox->Items->Add("�ԗ�");
	item_map_[index] = "�ԗ�";
	index++;

	// ���Ӑ�ǉ�
	if (ToInt(DM->config_["���Ӑ�}�X�^�g�p�敪"]) != 0){
		buff = ToString(DM->config_["���Ӑ�}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "���Ӑ�";
		index++;
	}
	// �i�ڒǉ�
	if (ToInt(DM->config_["�i�ڃ}�X�^�g�p�敪"]) != 0){
		buff = ToString(DM->config_["�i�ڃ}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "�i��";
		index++;

		// �i�ڕ��ޒǉ�
		buff = ToString(DM->config_["�i�ڃ}�X�^����"]) + "����";
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "�i�ڕ���";
		index++;
	}

	// ����1�ǉ�
	if (ToInt(DM->config_["����1�}�X�^�g�p�敪"]) != 0){
		buff = ToString(DM->config_["����1�}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "����1";
		index++;
	}

	// ����2�ǉ�
	if (ToInt(DM->config_["����2�}�X�^�g�p�敪"]) != 0){
		buff = ToString(DM->config_["����2�}�X�^����"]);
		buff = AnsiReplaceStr(buff, " ", "");
		buff = AnsiReplaceStr(buff, "�@", "");
		SelectItemComboBox->Items->Add(buff);
		item_map_[index] = "����2";
		index++;
	}
/*
	// ���|�[�g�ݒ�
	if (ToInt(DM->config_["�P���g�p�敪"]) == 0){
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
	if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "�ԗ�"){
		if (SharyoRadioButton->Checked){
			target_total = "�ԗ�ID";
			QRForm->ItemText->Enabled = true;
		}else{
			target_total = "�Ԕ�";
			QRForm->ItemText->Enabled = false;
		}
		target_code = "�Ԕ�";
		target_name = "�ԗ�����";
	}else{
		QRForm->ItemText->Enabled = true;
		target_total = item_map_[SelectItemComboBox->ItemIndex] + "�R�[�h";
		target_code = item_map_[SelectItemComboBox->ItemIndex] + "�R�[�h";
		target_name = item_map_[SelectItemComboBox->ItemIndex] + "����";
	}
	AnsiString where = " V.����� BETWEEN " + FromDatePicker->Date.FormatString("yyyymmdd") + " AND " + ToDatePicker->Date.FormatString("yyyymmdd");

	if (!ItemAllCheckBox->Checked){
		if (ItemCodeEditF->Text == "" || ItemCodeEditT->Text == ""){
			Application->MessageBox("���ڂ��ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND V." + target_code + " >= " + ItemCodeEditF->Text + " AND V." + target_code + "<= " + ItemCodeEditT->Text;
	}

	if (!SpotAllCheckBox->Checked){
		if (SpotCodeEdit->Text == ""){
			Application->MessageBox("���_���ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND V.���_ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_ID", "")));
	}

	if (TorihikiComboBox->ItemIndex > 0)
		where += " AND V.����敪 = " + IntToStr(TorihikiComboBox->ItemIndex);

	if (GenkakeComboBox->ItemIndex != 0)
		where += " AND V.���|�敪 = " + IntToStr(GenkakeComboBox->ItemIndex);

	QRForm->Query->Close();
	QRForm->Query->SQL->Text = DM->GetReportSQL(target_total, target_code, target_name, where);

	try{
		QRForm->Query->Open();
	}catch (Exception &e){
		Application->MessageBox(("�f�[�^�W�v�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
/*
	QRForm->TitleLabel->Caption = item_map_[SelectItemComboBox->ItemIndex] + "�ʏW�v�\";
	QRForm->ItemLabel->Caption = item_map_[SelectItemComboBox->ItemIndex];
*/
	QRForm->TitleLabel->Caption = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�ʏW�v�\�y����z";
	QRForm->ItemLabel->Caption  = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];
	AnsiString range = "�o�͔͈́F" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date);

	if (!SpotAllCheckBox->Checked)
		range += "�@���_�F" + SpotNameEdit->Text;

	range += "�@����敪�F" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];

	if (GenkakeComboBox->ItemIndex != -1)
		range += "�@���|�敪�F" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];

	QRForm->RangeLabel->Caption = range;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExcelOut()
{
	AnsiString buff = AnsiString();
	TADOQuery *query = QRForm->Query;
	int row;

	XlBook book(ExtractFilePath(Application->ExeName) + "������ڕʏW�v�\.xls");
	try{
		InfoPanel->Visible = true;

		Application->ProcessMessages();

		book.open(false);
		Variant app_obj = book.getAppObj();

		Cells cells;

		// �^�C�g���E���t�Ȃǖ��ߍ���
		cells[1][1] = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�ʏW�v�\�y����z";
		buff = "�o�͔͈́F" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date);
		if (!SpotAllCheckBox->Checked)
			buff += "�@���_�F" + SpotNameEdit->Text;
		buff += "�@����敪�F" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
		if (GenkakeComboBox->ItemIndex != -1)
			buff += "�@���|�敪�F" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];
		cells[2][1] = buff;
		cells[4][1] = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];

		row = 5;
		while (!query->Eof){
			Application->ProcessMessages();

			if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "�ԗ�" && !SharyoRadioButton->Checked)
				cells[row][1] = query->FieldByName("���ڃR�[�h")->AsString;
			else
				cells[row][1] = query->FieldByName("���ڃR�[�h")->AsString + "�F" + query->FieldByName("���ڗ���")->AsString;
			cells[row][2] = FormatFloat("#,##0", query->FieldByName("��")->AsInteger);
			cells[row][3] = FormatFloat("#,##0.0##", query->FieldByName("���v����")->AsCurrency);
			cells[row][4] = query->FieldByName("�P��")->AsString;
			cells[row][5] = FormatFloat("#,##0", query->FieldByName("���v���z")->AsCurrency);

			row++;
			query->Next();
		}

		// ���v
		cells[row][1] = "�y �� �v �z";
		cells[row][2] = "=SUM(B5:B" + IntToStr(row - 1) + ")";
		cells[row][5] = "=SUM(E5:E" + IntToStr(row - 1) + ")";

		book.setCellsToSheet("���^", cells);

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

