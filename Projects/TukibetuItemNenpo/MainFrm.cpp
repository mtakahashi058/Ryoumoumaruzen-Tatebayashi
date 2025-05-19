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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		Close();
	}

	DM->config_.Load(&DM->DBI);

	DM->kishu = ToInt(DM->config_["����"]);
	DM->kishu = DM->kishu == 0 ? 4 : DM->kishu; 

	SetItems();

	FromDatePicker->Date = GetKishuDate(Date(), DM->kishu);
	ToDatePicker->Date   = GetKimatuDate(Date(), DM->kishu);

	SelectItemComboBox->ItemIndex = 0;
	SelectItemComboBox->OnChange(NULL);
	ItemAllCheckBox->OnClick(NULL);

	SpotAllCheckBox->Checked = true;
	SpotCodeEdit->Text = AnsiString();
	SpotNameEdit->Text = AnsiString();
	SpotAllCheckBox->OnClick(NULL);

	IoDivComboBox->ItemIndex = 0;

	SetPrinter(QRForm->QuickRep, ToString(DM->ini_["Printer::Report"]));
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
/*	if (SelectItemComboBox->ItemIndex == 0){
		ItemSearchButtonF->Enabled  = false;
		ItemSearchButtonT->Enabled  = false;
	}else{
		ItemSearchButtonF->Enabled  = true;
		ItemSearchButtonT->Enabled  = true;
	}
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemAllCheckBoxClick(TObject *Sender)
{
	ItemCodeEditF->Enabled     = !ItemAllCheckBox->Checked;
	ItemNameEditF->Enabled     = !ItemAllCheckBox->Checked;
	ItemSearchButtonF->Enabled = !ItemAllCheckBox->Checked;

	ItemCodeEditT->Enabled     = !ItemAllCheckBox->Checked;
	ItemNameEditT->Enabled     = !ItemAllCheckBox->Checked;
	ItemSearchButtonT->Enabled = !ItemAllCheckBox->Checked;

	if (SelectItemComboBox->ItemIndex == 0){
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

	// �����o�敪
	if (ToInt(DM->config_["���o�Ɏg�p�敪"]) != 1){
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
	DM->ST_DT = FromDatePicker->Date;
	QRForm->Query->Close();
	QRForm->TotalQuery->Close();

	AnsiString item   = AnsiString();
	AnsiString target = AnsiString();
	AnsiString where  = AnsiString();
	item = item_map_[SelectItemComboBox->ItemIndex];

	if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "�ԗ�"){
		if (SharyoRadioButton->Checked){
			target = " 		�ԗ�ID AS ����ID, �Ԕ� AS ���ڃR�[�h, �ԗ����� AS ���ڗ���,";
			QRForm->ItemCodeText->Enabled = true;
		}else{
			target = " 		�Ԕ�   AS ����ID, �Ԕ� AS ���ڃR�[�h, CAST(�Ԕ� AS VARCHAR) AS ���ڗ���,";
			QRForm->ItemCodeText->Enabled = false;
		}
	}else{
		target = " 		" + item + "ID AS ����ID, " + item + "�R�[�h AS ���ڃR�[�h, " + item + "���� AS ���ڗ���,";
		QRForm->ItemCodeText->Enabled = true;
	}

	if (!ItemAllCheckBox->Checked){
		if (ItemCodeEditF->Text == "" || ItemCodeEditT->Text == ""){
			Application->MessageBox("���ڂ��ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		if (SelectItemComboBox->ItemIndex != 0)
			where += " AND " + item + "�R�[�h >= " + ItemCodeEditF->Text + " AND " + item + "�R�[�h <= " + ItemCodeEditT->Text;
		else
			where += " AND �Ԕ� >= " + ItemCodeEditF->Text + " AND �Ԕ� <= " + ItemCodeEditT->Text;
	}

	if (!SpotAllCheckBox->Checked){
		if (SpotCodeEdit->Text == ""){
			Application->MessageBox("���_���ݒ肳��Ă��܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND ���_ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", SpotCodeEdit->Text.ToIntDef(0), "���_ID", "")));
	}

	if (IoDivComboBox->ItemIndex != 0){
		if (IoDivComboBox->ItemIndex == -1){
			Application->MessageBox("�����o�敪�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		where += " AND �����o�敪 = " + IntToStr(IoDivComboBox->ItemIndex);
	}

	if (TorihikiComboBox->ItemIndex > 0)
		where += " AND ����敪 = " + IntToStr(TorihikiComboBox->ItemIndex);

	if (GenkakeComboBox->ItemIndex != 0)
		where += " AND ���|�敪 = " + IntToStr(GenkakeComboBox->ItemIndex);

	QRForm->Query->SQL->Text      = DM->GetReportSQL(target, where);
	QRForm->TotalQuery->SQL->Text = DM->GetTotalSQL(where);

	QRForm->Query->Parameters->ParamByName("DATE_FROM")->Value      = DateToInt(FromDatePicker->Date);
	QRForm->Query->Parameters->ParamByName("DATE_TO")->Value        = DateToInt(ToDatePicker->Date);
	QRForm->TotalQuery->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	QRForm->TotalQuery->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);


	RichEdit1->Lines->Text = QRForm->Query->SQL->Text;

	try{
		QRForm->Query->Open();
		QRForm->TotalQuery->Open();
	}catch (Exception &e){
		Application->MessageBox(("�f�[�^�W�v�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	if (QRForm->Query->Bof && QRForm->Query->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	QRForm->TitleLabel->Caption = "����" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�ʔN��";
	QRForm->ItemLabel->Caption  = SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex];
	QRForm->ItemTotalLabel->Caption = "�y " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�v �z";
	AnsiString range = "�o�͔͈́F" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date);
	if (ToInt(DM->config_["���o�Ɏg�p�敪"]) == 1)
		range += "�@�����o�敪�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];

	if (ItemAllCheckBox->Checked)
		range += " " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�F���ׂ�";
	else{
		if (SelectItemComboBox->ItemIndex != 0)
			range += " " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�F" + ItemNameEditF->Text + " �` " + ItemNameEditT->Text;
		else
			range += " " + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�F" + ItemCodeEditF->Text + " �` " + ItemCodeEditT->Text;
	}
	if (!SpotAllCheckBox->Checked)
		range += "�@���_�F" + SpotNameEdit->Text;
	else
		range += "�@���_�F���ׂ�";

	if (IoDivComboBox->ItemIndex != 0)
		range += "�@�����o�敪�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex];

	range += "�@����敪 = " + TorihikiComboBox->Items->Strings[TorihikiComboBox->ItemIndex];

	if (GenkakeComboBox->ItemIndex != 0)
		range += "�@���|�敪�F" + GenkakeComboBox->Items->Strings[GenkakeComboBox->ItemIndex];

	QRForm->RangeLabel->Caption = range;
	QRForm->dt_from = FromDatePicker->Date;

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
	int col = 2, max_col = ToString(DM->ini_["Excel::MaxCol"]).ToIntDef(250);
	int row = 3;
	int sheet_count = 1;
	AnsiString range = AnsiString();
	std::vector<int>::iterator itr;

	XlBook book(ExtractFilePath(Application->ExeName) + "���ʍ��ڕʔN��.xls");
	try{
		InfoPanel->Visible = true;

		Application->ProcessMessages();

		book.open(false);
		Variant sheet      = book.getWorksheet("���^");
		Variant page_setup = sheet.Exec(PropertyGet("PageSetup"));
		Variant app_obj    = book.getAppObj();
		Cells cells;

		// �V�[�g�w�b�_�ҏW
		buff = "����" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�ʔN��(" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date) +  ")";
		if (ItemAllCheckBox->Checked)
			buff += " [" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�F���ׂ�]";
		else
			buff += " [" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�F" + ItemNameEditF->Text + " �` " + ItemNameEditT->Text + "]";
		if (SpotAllCheckBox->Checked)
			buff += " [���_�F���ׂ�]";
		else
			buff += " [���_�F" + SpotNameEdit->Text + "]";
		if (ToInt(DM->config_["���o�Ɏg�p�敪"]) == 1)
			buff += " [�����o�敪�F" + IoDivComboBox->Items->Strings[IoDivComboBox->ItemIndex] + "]";

		page_setup.Exec(PropertySet("LeftHeader") << buff);
		page_setup.Exec(PropertySet("RightHeader") << "���s�� - &D  &T\nPage - &P");

		while (!query->Eof){
			Application->ProcessMessages();

			// �c���Z�b�g
			if (col == 2){
				cells[1][1] = item_map_[SelectItemComboBox->ItemIndex];
				cells[2][1] = "�N��";

				row = 3;
//				TDateTime dt = EncodeDate(WORD(Date().FormatString("yyyy").ToIntDef(0)), DM->kishu, 1);
				TDateTime dt = DM->ST_DT;
				for (int i = 1; i <= 12; i++){
					cells[row][1] = dt.FormatString("yy'�N'mm'��'");
					dt = IncMonth(dt, 1);
					row_map[i] = row;
					row++;
				}
				cells[row][1] = "���v";
			}

			// �����Z�b�g
			col_vec.push_back(col);
			if (SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] == "�ԗ�" && !SharyoRadioButton->Checked)
				cells[1][col] = query->FieldByName("���ڗ���")->AsString;
			else
				cells[1][col] = query->FieldByName("���ڃR�[�h")->AsString + ":" + query->FieldByName("���ڗ���")->AsString;
			cells[2][col]     = "����(��)";
			cells[2][col + 1] = "�d��(kg)";
			cells[2][col + 2] = "���z(�~)";

			for (int i = 1; i <= 12; i++){
				AnsiString k_field = "����" + FormatFloat("00", i);
				AnsiString w_field = "�d��" + FormatFloat("00", i);
				AnsiString m_field = "���z" + FormatFloat("00", i);
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
			cells[15][col]     = "=SUM(" + toXlColumnName(col) + "3:" + toXlColumnName(col) + "14)";
			cells[15][col + 1] = "=SUM(" + toXlColumnName(col + 1) + "3:" + toXlColumnName(col + 1) + "14)";
			cells[15][col + 2] = "=SUM(" + toXlColumnName(col + 2) + "3:" + toXlColumnName(col + 2) + "14)";

			col += 3;
			query->Next();

			if (col >= max_col || query->Eof){
				if (query->Eof){
					col_vec.push_back(col);
					cells[1][col] = "�y" + SelectItemComboBox->Items->Strings[SelectItemComboBox->ItemIndex] + "�v�z";
					cells[2][col]     = "����(��)";
					cells[2][col + 1] = "�d��(kg)";
					cells[2][col + 2] = "���z(�~)";
					for (int i = 1; i <= 12; i++){
						AnsiString k_field = "����" + FormatFloat("00", i);
						AnsiString w_field = "�d��" + FormatFloat("00", i);
						AnsiString m_field = "���z" + FormatFloat("00", i);
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
					cells[15][col]     = "=SUM(" + toXlColumnName(col) + "3:" + toXlColumnName(col) + "14)";
					cells[15][col + 1] = "=SUM(" + toXlColumnName(col + 1) + "3:" + toXlColumnName(col + 1) + "14)";
					cells[15][col + 2] = "=SUM(" + toXlColumnName(col + 2) + "3:" + toXlColumnName(col + 2) + "14)";
				}

				// �V�[�g�R�s�[ & �f�[�^�����o��
				Variant sheet = book.getWorksheet("���^");
				book.copySheet(sheet, 1);

				sheet = book.getWorksheet(1);
				book.changeSheetName(sheet, "�V�[�g" + IntToStr(sheet_count));

				book.setCellsToSheetObj(sheet, cells);

				itr = std::max_element(col_vec.begin(), col_vec.end());
				// �\��Z�� ���F����
				range = "A1:" + toXlColumnName(*itr + 2) + "2";
				sheet.Exec(PropertyGet("Range") << range).Exec(PropertyGet("Interior")).Exec(PropertySet("ColorIndex") << 15);
				// �f�[�^�Z�� ���F����
				for (int i = 3; i <= 14; i++){
					range = "A" + IntToStr(i) + ":" + toXlColumnName(*itr + 2) + IntToStr(i);
					if (i % 2)
						sheet.Exec(PropertyGet("Range") << range).Exec(PropertyGet("Interior")).Exec(PropertySet("ColorIndex") << 19);
				}
				// �c�v�Z�� ���F����
				range = "A15:" + toXlColumnName(*itr + 2) + "15";
				sheet.Exec(PropertyGet("Range") << range).Exec(PropertyGet("Interior")).Exec(PropertySet("ColorIndex") << 37);

				// �Z�� �}�[�W����
				for (std::vector<int>::iterator i = col_vec.begin(); i != col_vec.end(); i++){
					range = toXlColumnName(*i) + "1:" + toXlColumnName(*i + 2) + "1";
					sheet.Exec(PropertyGet("Range") << range).Exec(Function("Merge"));
					app_obj.Exec(PropertyGet("Range") << toXlColumnName(*i) + "1:" + toXlColumnName(*i) + "1").Exec(Function("Select"));
					app_obj.Exec(PropertyGet("Selection")).Exec(PropertySet("NumberFormatLocal") << "@");
				}

				book.run("�r��");

				col_vec.clear();
				cells.clear();
				sheet_count++;
				col = 2;
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

