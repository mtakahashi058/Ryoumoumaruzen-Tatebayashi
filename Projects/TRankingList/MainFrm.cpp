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

	XlBook book(ExtractFilePath(Application->ExeName) + "������ʕ\���^.xls");
	try{
		book.open(true);
		Variant sheet = book.getWorksheet("�f�[�^�V�[�g");
		Variant app_obj = book.getAppObj();

		// �����{�v�Z���̃R�s�[
		if (QRForm->Query->RecordCount > 2){
			// ���^�V�[�g�̂Q�s�ڂ��R�s�[
			sheet.Exec(PropertyGet("Range") << sheet.Exec(PropertyGet("Cells") << 5 << 1) << sheet.Exec(PropertyGet("Cells") << 5 << 9)).Exec(Procedure("Select"));
			app_obj.Exec(PropertyGet("Selection")).Exec(Procedure("Copy"));
			// �f�[�^���ɉ����ăy�[�X�g
			sheet.Exec(PropertyGet("Range") << sheet.Exec(PropertyGet("Cells") << 6 << 1) << sheet.Exec(PropertyGet("Cells") << QRForm->Query->RecordCount + 4 << 9)).Exec(Procedure("Select"));
			sheet.Exec(Procedure("Paste"));
			// �R�s�[���[�h�I��
			app_obj.Exec(PropertySet("CutCopyMode") << "False");
		}

		Cells cells;

		// �^�C�g�����̖��ߍ���
		cells[2][1] = "�y�o�͔͈́z�@" + where_rep;

		// �����v
		NsRecordSet set;
		if (DM->DBI.GetRecordSet("SELECT SUM(" + orderby + ") AS ���v FROM V_��� WHERE ����� BETWEEN " + IntToStr(DateToInt(FromDatePicker->Date)) + " AND " + IntToStr(DateToInt(ToDatePicker->Date)) + where, set))
			cells[3][12] = ToString(set[0]["���v"]);

		// �f�[�^���ߍ���
		int row = 4;
		while (!q_shukei->Eof){
			cells[row][2] = q_shukei->FieldByName("���ڃR�[�h")->AsString;
			cells[row][3] = q_shukei->FieldByName("���ڗ���")->AsString;
			cells[row][4] = q_shukei->FieldByName("���z")->AsCurrency;
			row++;
			q_shukei->Next();
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
bool __fastcall TMainForm::SetQuery()
{
	where     = AnsiString();
	where_rep = AnsiString();

	QRForm->Query->Close();
	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);

	// TOP
	QRForm->Query->SQL->Strings[6] = "TOP " + IntToStr(MaxCountEdit->Text.ToIntDef(0));
	where_rep += "�o�͌�����" + MaxCountEdit->Text + "�ʂ܂�  ";

	// ORDER BY
	where_rep += "���z��ʏ�  ";
	orderby = "���z";

	if (SelectItemComboBox->ItemIndex == 0){
		// *** �ԗ��̏ꍇ ***
		// ���ږ��Z�b�g
		QRForm->Query->SQL->Strings[7] = "	�Ԕ� AS ���ڃR�[�h,";
		QRForm->Query->SQL->Strings[8] = "	MAX(�ԗ�����) AS ���ڗ���,";
		// GROUP BY �Z�b�g
		QRForm->Query->SQL->Strings[19] = "�ԗ�ID, �Ԕ�";

	}else{
		// ���ږ��Z�b�g
		QRForm->Query->SQL->Strings[7] = "	"     + item_map_[SelectItemComboBox->ItemIndex] + "�R�[�h AS ���ڃR�[�h,";
		QRForm->Query->SQL->Strings[8] = "	MAX(" + item_map_[SelectItemComboBox->ItemIndex] + "����) AS ���ڗ���,";
		// GROUP BY �Z�b�g
		QRForm->Query->SQL->Strings[19] = item_map_[SelectItemComboBox->ItemIndex] + "�R�[�h";
	}
	where_rep += "���ځF" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "  ";

	// *** WHERE ***
	// ����
	if (!ItemAllCheckBox->Checked){
		if (SelectItemComboBox->ItemIndex == 0){
			where += " AND �Ԕ� >= " + IntToStr(ItemCodeEditF->Text.ToIntDef(0)) + " AND �Ԕ� <= " + IntToStr(ItemCodeEditT->Text.ToIntDef(0));
			where_rep += "�ԔԁF" + ItemCodeEditF->Text + "�`" + ItemCodeEditT->Text + "  ";
		}else{
			where += " AND " + item_map_[SelectItemComboBox->ItemIndex] + "�R�[�h >= " + IntToStr(ItemCodeEditF->Text.ToIntDef(0)) + " AND " + item_map_[SelectItemComboBox->ItemIndex] + "�R�[�h <= " + IntToStr(ItemCodeEditT->Text.ToIntDef(0));
			where_rep += item_map_[SelectItemComboBox->ItemIndex] + "�F" + ItemNameEditF->Text + "�`" + ItemNameEditT->Text + "  ";
		}
	}
	// ���_
	if (!SpotAllCheckBox->Checked){
		where += " AND ���_ID = " + ToString(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_ID", ""));
		where_rep += "���_�F" + SpotNameEdit->Text + "  ";
	}
	// ����敪
	if (IoDivComboBox->ItemIndex > 0)
		where += " AND ����敪 = " + IntToStr(IoDivComboBox->ItemIndex);
	where_rep += "�����o�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex] + "  ";
	// ���|�敪
	if (GenkakeComboBox->ItemIndex != 0){
		where += " AND ���|�敪 = " + IntToStr(GenkakeComboBox->ItemIndex);
		where_rep += "���|�敪�F" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex] + "  ";
	}
	QRForm->Query->SQL->Strings[16] = where;
	QRForm->Query->SQL->Strings[21] = orderby + " DESC";
	QRForm->Query->Open();

	if (QRForm->Query->RecordCount == 0){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	// ���ڃ^�C�g�����Z�b�g
	QRForm->KomokuLabel->Caption = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];
	// �o�͏������Z�b�g
	QRForm->RangeLabel->Caption = "�y�o�͔͈́z " + where_rep;

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
	SearchForm->list_->CommaText = target + "�R�[�h," + target + "����," + target + "�J�i";
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

