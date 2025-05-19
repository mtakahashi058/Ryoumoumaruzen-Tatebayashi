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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
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
	if (Application->MessageBox("������܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
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

	XlBook book(ExtractFilePath(Application->ExeName) + "���ʏW�v�\���^.xls");
	try{
		book.open(true);
		Variant sheet = book.getWorksheet("�f�[�^�V�[�g");
		Variant app_obj = book.getAppObj();
		Cells cells;

		// �^�C�g�����̖��ߍ���
		cells[2][2] = YearEdit->Text + "�N�x";
		cells[2][5] = QRForm->RangeLabel->Caption;

		// �f�[�^���ߍ���
		TDateTime dt = FromDatePicker->Date;
		int month;

		for (int i = 0; i < 12; i++){
			month = dt.FormatString("yyyymm").ToIntDef(0);
			cells[5 + i][1] = dt.FormatString("mm") + "��";

			if (q_shukei->Locate("�N��", month, TLocateOptions())){
				cells[5 + i][2] = q_shukei->FieldByName("�����d��")->AsCurrency;
				cells[5 + i][3] = q_shukei->FieldByName("���z")->AsCurrency;
			}else{
				cells[5 + i][2] = "0";
				cells[5 + i][3] = "0";
			}

			dt = IncMonth(dt, 1);
		}

		// Excel��������
		book.setCellsToSheet("�f�[�^�V�[�g", cells);

		// �擪�Ƀt�H�[�J�X
		sheet.Exec(PropertyGet("Cells") << 1 << 1).Exec(Procedure("Select"));

	}catch (Exception &e){
		Application->MessageBox(("Excel�������ݒ��ɃG���[���������܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		book.quit();
	}

	Application->MessageBox("�������܂����B\r\n���̃t�@�C����ۑ�����ꍇ�́A[�t�@�C��]->[���O��t���ĕۑ�]���s���Ă�������", "�o��", MB_OK | MB_ICONINFORMATION | MB_TOPMOST);

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
// �e�t�B�[���h�̃t�B�[���h�����擾����
AnsiString __fastcall TMainForm::GetFieldName(int index)
{
	AnsiString field_name;
	if (index == 0)
		field_name = "�Ԕ�";
	else
		field_name = item_map_[index] + "�R�[�h";

	return field_name;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SetQuery()
{
	QRForm->Query->Close();
	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);
	QRForm->RangeLabel->Caption = "�o�͔͈́F" + DateToStr(FromDatePicker->Date) + "�`" + DateToStr(ToDatePicker->Date);
	QRForm->start_date = FromDatePicker->Date;

	if (!ItemAllCheckBox->Checked){
		QRForm->Query->SQL->Strings[17] = "AND	" + GetFieldName(SelectItemComboBox->ItemIndex) + " >= " + IntToStr(ItemCodeEditF->Text.ToIntDef(0)) + " AND " + GetFieldName(SelectItemComboBox->ItemIndex) + " <= " + IntToStr(ItemCodeEditT->Text.ToIntDef(0));
		if (SelectItemComboBox->ItemIndex != 0)
			QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�F" + ItemNameEditF->Text + "�`" + ItemNameEditT->Text;
		else
			QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�F" + ItemCodeEditF->Text + "�`" + ItemCodeEditT->Text;
	}else{
		QRForm->Query->SQL->Strings[17] = "";
	}

	if (!SpotAllCheckBox->Checked && SpotCodeEdit->Text.ToIntDef(0) != 0){
		QRForm->Query->SQL->Strings[18] = "AND	���_ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_ID")));
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  ���_�F" + SpotNameEdit->Text;
	}else{
		QRForm->Query->SQL->Strings[18] = "";
	}

	if (IoDivComboBox->ItemIndex != 0){
		QRForm->Query->SQL->Strings[19] = "AND	�����o�敪 = " + IntToStr(IoDivComboBox->ItemIndex);
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  �����o�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];
	}else{
		QRForm->Query->SQL->Strings[19] = "";
	}

	if (TorihikiComboBox->ItemIndex != 0){
		QRForm->Query->SQL->Strings[20] = " AND ����敪 = " + IntToStr(TorihikiComboBox->ItemIndex);
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  ����敪�F" + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];
	}else{
		QRForm->Query->SQL->Strings[20] = AnsiString();
	}

	if (GenkakeComboBox->ItemIndex != 0){
		QRForm->Query->SQL->Strings[21] = " AND ���|�敪 = " + IntToStr(GenkakeComboBox->ItemIndex);
		QRForm->RangeLabel->Caption = QRForm->RangeLabel->Caption + "  ���|�敪�F" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];
	}else
		QRForm->Query->SQL->Strings[21] = "";

	QRForm->Query->Open();

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
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

	ItemNameEditF->Text = ToString(DM->DBI.Lookup("M_" + target, target + "�R�[�h", ItemCodeEditF->Text.ToIntDef(0), target + "����", "�g�p�敪 = 1"));
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
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����" + target + "�J�i";
	if (SearchForm->ShowModal() != mrOk)
		return;
	ItemCodeEditF->Text = SearchForm->Query->FieldByName(target + "�R�[�h")->AsInteger;
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
	SearchForm->based_sql = "SELECT " + target + "�R�[�h, " + target + "���� FROM M_" + target + " WHERE �g�p�敪 = 1 ";
	SearchForm->orderby_sql = " ORDER BY " + target + "�R�[�h ";
	SearchForm->table_name = "M_" + target;
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����" + target + "�J�i";
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

	// �����o�敪
	if (ToInt(DM->config_["���o�Ɏg�p�敪"]) != 1){
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

	// �ԗ��ǉ�
	SelectItemComboBox->Items->Add("�ԗ�");
	item_map_[index] = "�ԗ�";
	index++;

	// ���Ӑ�ǉ�
	if (ToInt(DM->config_["���Ӑ�}�X�^�g�p�敪"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["���Ӑ�}�X�^����"]));
		item_map_[index] = "���Ӑ�";
		index++;
	}
	// �i�ڒǉ�
	if (ToInt(DM->config_["�i�ڃ}�X�^�g�p�敪"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["�i�ڃ}�X�^����"]));
		item_map_[index] = "�i��";
		index++;
	}

	// �i�ڕ��ޒǉ�
	SelectItemComboBox->Items->Add("�i�ڕ���");
	item_map_[index] = "�i�ڕ���";
	index++;

	// ����1�ǉ�
	if (ToInt(DM->config_["����1�}�X�^�g�p�敪"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["����1�}�X�^����"]));
		item_map_[index] = "����1";
		index++;
	}
	// ����2�ǉ�
	if (ToInt(DM->config_["����2�}�X�^�g�p�敪"]) != 0){
		SelectItemComboBox->Items->Add(ToString(DM->config_["����2�}�X�^����"]));
		item_map_[index] = "����2";
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
// �N�x->OnChange
void __fastcall TMainForm::YearEditChange(TObject *Sender)
{
	if (YearEdit->Text.ToIntDef(0) < 2000)
		return;

	WORD y, m, d;
	Date().DecodeDate(&y, &m, &d);

	y = YearEdit->Text.ToIntDef(0);
	m = ToString(DM->config_["����"]).ToIntDef(4);

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


