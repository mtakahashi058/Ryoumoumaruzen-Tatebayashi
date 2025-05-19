//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "DataListFrm.h"
#include "nsoftfunc.h"
#include <memory>
#include "QRLedgerFrm.h"
#include "MainFrm.h"
#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TDataListForm *DataListForm;
AnsiString GRID_CONFIG = "�v�ʃO���b�h�z�u.txt";
//---------------------------------------------------------------------------
__fastcall TDataListForm::TDataListForm(TComponent* Owner)
	: TForm(Owner), first_(true), rec_no_(-1), grid_cleared_(false)
{
}
//---------------------------------------------------------------------------
// Form->OnShow
void __fastcall TDataListForm::FormShow(TObject *Sender)
{
    if (first_){
    	try{
    		DBGrid->Columns->LoadFromFile(ExtractFilePath(Application->ExeName) + GRID_CONFIG); // �ǂݍ��ݑΏۃt�@�C�����t���p�X�Ŏw��
    	}catch (...){ ; }

		ClearButton->Click();

		TokuButton->Caption  = ToString(DM->CFG["���Ӑ�}�X�^����"]);
		HinButton->Caption   = ToString(DM->CFG["�i�ڃ}�X�^����"]);
		Item1Button->Caption = ToString(DM->CFG["����1�}�X�^����"]);
		Item2Button->Caption = ToString(DM->CFG["����2�}�X�^����"]);

		TokuLabel->Caption   = ToString(DM->CFG["���Ӑ�}�X�^����"]) + "�F";
		Item1Label->Caption  = ToString(DM->CFG["����1�}�X�^����"]) + "�F";
		Item2Label->Caption  = ToString(DM->CFG["����2�}�X�^����"]) + "�F";
		MeigLabel->Caption   = ToString(DM->CFG["�i�ڃ}�X�^����"]) + "�F";
		CoordLabel->Caption  = ToString(DM->CFG["��������"]) + "�F";
		ReduceLabel->Caption = ToString(DM->CFG["�d�ʈ�������"]) + "�F";

		DBGrid->Columns->Items[7]->Title->Caption  = ToString(DM->CFG["���Ӑ�}�X�^����"]);
		DBGrid->Columns->Items[9]->Title->Caption  = ToString(DM->CFG["�i�ڃ}�X�^����"]);
		DBGrid->Columns->Items[10]->Visible        = false;
		DBGrid->Columns->Items[11]->Title->Caption = AnsiReplaceStr(AnsiReplaceStr(ToString(DM->CFG["�i�ڃ}�X�^����"]), "�@", ""), " ", "") + "����";
		DBGrid->Columns->Items[13]->Title->Caption = ToString(DM->CFG["����1�}�X�^����"]);
		DBGrid->Columns->Items[15]->Title->Caption = ToString(DM->CFG["����2�}�X�^����"]);

		if (!ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
			DBGrid->Columns->Items[6]->Visible = false;
			DBGrid->Columns->Items[7]->Visible = false;
		}
		if (!ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
			DBGrid->Columns->Items[8]->Visible = false;
			DBGrid->Columns->Items[9]->Visible = false;
		}
		if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
			DBGrid->Columns->Items[12]->Visible = false;
			DBGrid->Columns->Items[13]->Visible = false;
		}
		if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
			DBGrid->Columns->Items[14]->Visible = false;
			DBGrid->Columns->Items[15]->Visible = false;
		}
		if (!ToBit(DM->CFG["�����g�p�敪"])){
			DBGrid->Columns->Items[18]->Visible = false;
			DBGrid->Columns->Items[19]->Visible = false;
		}
		if (!ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
			DBGrid->Columns->Items[20]->Visible = false;
		}
		if (!ToBit(DM->CFG["�P���g�p�敪"])){
			DBGrid->Columns->Items[24]->Visible = false;
			DBGrid->Columns->Items[25]->Visible = false;
		}

        FilterShowButton->Caption = ">>";
		FilterPanel->Height = 61;

		OrderComboBox->Items->Strings[3] = AnsiReplaceStr(AnsiReplaceStr(TokuButton->Caption, "�@", ""), " ", "");
		OrderComboBox->Items->Strings[4] = AnsiReplaceStr(AnsiReplaceStr(HinButton->Caption, "�@", ""), " ", "");
		OrderComboBox->Items->Strings[5] = AnsiReplaceStr(AnsiReplaceStr(Item1Button->Caption, "�@", ""), " ", "");
		OrderComboBox->Items->Strings[6] = AnsiReplaceStr(AnsiReplaceStr(Item2Button->Caption, "�@", ""), " ", "");

		first_ = false;
	}

	Action5->Execute();

	SetButtonEnabled();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    if (!grid_cleared_)
    	DBGrid->Columns->SaveToFile(ExtractFilePath(Application->ExeName) + GRID_CONFIG); // �ۑ�����t�@�C�������t���p�X�Ŏw��
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::DBGridDrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
	// DBGrid �ň�s�����ɐF��ς���
	if (DBGrid->SelectedRows->CurrentRowSelected)
		;
	else if (DataCol == 0){
		if (DBGrid->DataSource->DataSet->FieldByName("�����敪")->AsInteger == 1)
			DBGrid->Canvas->Brush->Color = TColor(0x00D2FDD2);
		else
			DBGrid->Canvas->Brush->Color = TColor(0x00A6FFFF);

	}else if (DBGrid->DataSource->DataSet->FieldByName("�����敪")->AsInteger == 0){
		DBGrid->Canvas->Brush->Color = TColor(0x00A6FFFF);

	}else if ((State.Empty() || ActiveControl != DBGrid) && DBGrid->DataSource->DataSet->RecNo % 2 == 0)
		DBGrid->Canvas->Brush->Color = TColor(0x00EBEBEB);

	DBGrid->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------
// �ŏ���
void __fastcall TDataListForm::FirstButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->First();
	//SetButtonEnabled();
}
//---------------------------------------------------------------------------
// �O��
void __fastcall TDataListForm::PriorButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Prior();
	//SetButtonEnabled();
}
//---------------------------------------------------------------------------
// ����
void __fastcall TDataListForm::NextButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Next();
	//SetButtonEnabled();
}
//---------------------------------------------------------------------------
// �Ō��
void __fastcall TDataListForm::LastButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->Last();
}
//---------------------------------------------------------------------------
// ���R�[�h�ړ��{�^��(Enabled)
void __fastcall TDataListForm::SetButtonEnabled()
{
	if (!DBGrid->DataSource->DataSet->Active){
		FirstButton->Enabled = false;
		PriorButton->Enabled = false;
		NextButton->Enabled = false;
		LastButton->Enabled = false;
		return;
	}

	FirstButton->Enabled = true;
	PriorButton->Enabled = true;
	NextButton->Enabled = true;
	LastButton->Enabled = true;

	if (DBGrid->DataSource->DataSet->RecNo == 1){
		FirstButton->Enabled = false;
		PriorButton->Enabled = false;
	}else if (DBGrid->DataSource->DataSet->RecNo == DBGrid->DataSource->DataSet->RecordCount){
		NextButton->Enabled = false;
		LastButton->Enabled = false;
	}
}
//---------------------------------------------------------------------------
// DBGrid->AfterScroll
void __fastcall TDataListForm::Q_KeiryoAfterScroll(TDataSet *DataSet)
{
	SetButtonEnabled();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::DispMeisaiCheckBoxClick(TObject *Sender)
{
	if (DispMeisaiCheckBox->Checked)
		MeisaiPanel->Height = 189;
	else
		MeisaiPanel->Height = 16;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Action5Execute(TObject *Sender)
{
	try{
	IngPanel->Visible = true;
	Application->ProcessMessages();

	if (Q_Keiryo->Active)
		Q_Keiryo->Close();

	AnsiString sql;
	NsFilterSet filters;

	sql = " SELECT * FROM V_�v��";

	if (dtpDateFrom->Checked)
		filters << NsFilter("�v�ʓ� >= ", DateToInt(dtpDateFrom->Date));
	if (dtpDateTo->Checked)
		filters << NsFilter("�v�ʓ� <= ", DateToInt(dtpDateTo->Date));
	if (StateCombo->ItemIndex == 0)
		filters << NsFilter("�����敪 <> ", 9);
	else if (StateCombo->ItemIndex == 1)
		filters << NsFilter("�����敪 = ", 0);
	else if (StateCombo->ItemIndex == 2)
		filters << NsFilter("�����敪 = ", 1);

	int n;

	n = CarNoEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("�Ԕ� = ", n);

	n = TokuCodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("���Ӑ�R�[�h = ", n);

	n = HinCodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("�i�ڃR�[�h = ", n);

	n = Item1CodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("����1�R�[�h = ", n);

	n = Item2CodeEdit->Text.ToIntDef(0);
	if (n)
		filters << NsFilter("����2�R�[�h = ", n);

	if (PlaceCombo->ItemIndex != 0){
		filters << NsFilter("���_ID = ", IntToStr(ToInt(DM->PlaceSet[PlaceCombo->ItemIndex - 1]["���_ID"])));
		DBGrid->Columns->Items[1]->Visible = false;
	}else{
		DBGrid->Columns->Items[1]->Visible = true;
	}

	sql += " WHERE " + ToFilter(filters, "AND");

	if (!cedtSearch->Text.IsEmpty()){
		sql += " AND " + DM->DBI.FullSearchSQL(cedtSearch->Text, "V_�v��");
	}

	if (UnitCombo->ItemIndex == 0)
		sql += " AND �sNo = 1";

	if (!KoujunCheckBox->Checked){	// ����
		if (OrderComboBox->ItemIndex == 0)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 1)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �`�[No";
		else if (OrderComboBox->ItemIndex == 2)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �Ԕ�, �ԗ�ID, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 3)
			Q_Keiryo->SQL->Text = sql + " ORDER BY ���Ӑ�R�[�h, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 4)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �i�ڃR�[�h, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 5)
			Q_Keiryo->SQL->Text = sql + " ORDER BY ����1�R�[�h, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 6)
			Q_Keiryo->SQL->Text = sql + " ORDER BY ����2�R�[�h, �v�ʓ�, �`�[No";
		else
			Q_Keiryo->SQL->Text = sql + " ORDER BY �v�ʓ�, �`�[No";

	}else{	// �~��
		if (OrderComboBox->ItemIndex == 0)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �v�ʓ� DESC, �`�[No";
		else if (OrderComboBox->ItemIndex == 1)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �`�[No DESC";
		else if (OrderComboBox->ItemIndex == 2)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �Ԕ� DESC, �ԗ�ID, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 3)
			Q_Keiryo->SQL->Text = sql + " ORDER BY ���Ӑ�R�[�h DESC, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 4)
			Q_Keiryo->SQL->Text = sql + " ORDER BY �i�ڃR�[�h DESC, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 5)
			Q_Keiryo->SQL->Text = sql + " ORDER BY ����1�R�[�h DESC, �v�ʓ�, �`�[No";
		else if (OrderComboBox->ItemIndex == 6)
			Q_Keiryo->SQL->Text = sql + " ORDER BY ����2�R�[�h DESC, �v�ʓ�, �`�[No";
		else
			Q_Keiryo->SQL->Text = sql + " ORDER BY �v�ʓ� DESC, �`�[No";
	}

	Q_Keiryo->Open();

	NsRecordSet sum_set;
	AnsiString sum_sql = sql;
	sum_sql = AnsiReplaceStr(sum_sql, "SELECT *", "SELECT COUNT(*) AS ����, SUM(�����d��) AS �����d��, SUM(���z) AS ���z");
	sum_sql = sum_sql + " AND �����敪 = 1";
	DM->DBI.GetRecordSet(sum_sql, sum_set);
	SumLabel->Caption = "�����F" + FormatFloat("#,##0", ToInt(sum_set[0]["����"])) + "��  �d�ʁF" + FormatFloat("#,##0", ToCurrency(sum_set[0]["�����d��"])) + "kg  ���z�F" + FormatFloat("#,##0", ToCurrency(sum_set[0]["���z"])) + "�~"; 

	}__finally{
		IngPanel->Visible = false;
	}

	if (rec_no_ >= 0){
		try{
			Q_Keiryo->RecNo = rec_no_;
		}catch(...){}
	}
	DBGrid->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnOkClick(TObject *Sender)
{
	if (Q_Keiryo->Bof && Q_Keiryo->Eof)
		return;

    rec_no_ = Q_Keiryo->RecNo;

    int date  = Q_Keiryo->FieldByName("�v�ʓ�")->AsInteger;
    int place = Q_Keiryo->FieldByName("���_ID")->AsInteger;
    int no    = Q_Keiryo->FieldByName("�`�[No")->AsInteger;

    NsFieldSet keys;
    keys << NsField("�v�ʓ�", date)
         << NsField("���_ID", place)
         << NsField("�`�[No", no)
             //<< NsField("�sNo",   1)
         ;

    selected_id = ToInt(DM->DBI.Lookup("D_�v��", keys, "�v��ID"));

    if (selected_id < 1){
        Application->MessageBox("�`�[�̂P�s�ږ��ׂ�������܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnCancelClick(TObject *Sender)
{
	selected_id = 0;
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::DBGridDblClick(TObject *Sender)
{
	btnOk->Click();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnSaveClick(TObject *Sender)
{
	if (Q_Keiryo->RecordCount == 0)
		return;
	SaveDialog->FileName = "�v�ʈꗗ_" + Date().FormatString("yyyymmdd�o��") + ".csv";
	if (!SaveDialog->Execute())
		return;
	std::auto_ptr<TStringList> Records(new TStringList());
	Table2Str(Q_Keiryo, Records.get(), true);
	Records->SaveToFile(SaveDialog->FileName);
	Application->MessageBox("�������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::PriorDateButtonClick(TObject *Sender)
{
    bool checked_from = dtpDateFrom->Checked;
    bool checked_to   = dtpDateTo->Checked;

    dtpDateFrom->Checked = true;
    dtpDateTo->Checked   = true;

    ShiftDate(dtpDateFrom, dtpDateTo, -1);

    dtpDateFrom->Checked = checked_from;
	dtpDateTo->Checked   = checked_to;

	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::NextDateButtonClick(TObject *Sender)
{
	bool checked_from = dtpDateFrom->Checked;
	bool checked_to   = dtpDateTo->Checked;

	dtpDateFrom->Checked = true;
	dtpDateTo->Checked   = true;

	ShiftDate(dtpDateFrom, dtpDateTo, 1);

	dtpDateFrom->Checked = checked_from;
	dtpDateTo->Checked   = checked_to;

	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearGridButtonClick(TObject *Sender)
{
	if (Application->MessageBox("�f�[�^�ꗗ�̕\�������������܂����H", "�\��������", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	AnsiString file = ExtractFilePath(Application->ExeName) + GRID_CONFIG;
	if (FileExists(file))
		DeleteFile(file);
	Application->MessageBox("�v�ʏ������ċN�����ĉ�����", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    grid_cleared_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearButtonClick(TObject *Sender)
{
    TDateTime now(Now());
	dtpDateFrom->Date = now;
    dtpDateTo->Date   = now;

    place_id_       = MainForm->GetPlaceID();

	PlaceCombo->Items->Clear();
    PlaceCombo->Items->Append("���ׂ�");

    int id;
    int index = 0;
    for (unsigned int i = 0; i < DM->PlaceSet.size(); i++){
        id = ToInt(DM->PlaceSet[i]["���_ID"]);
		PlaceCombo->Items->Append(ToString(DM->PlaceSet[i]["���_����"]));

        if (place_id_ == id)
            index = i + 1;
	}
    PlaceCombo->ItemIndex = index;

    cedtSearch->Text = AnsiString();

    TokuCodeEdit->Text  = AnsiString();
    TokuNameEdit->Text  = AnsiString();
    HinCodeEdit->Text   = AnsiString();
    HinNameEdit->Text   = AnsiString();
    Item1CodeEdit->Text = AnsiString();
    Item1NameEdit->Text = AnsiString();
    Item2CodeEdit->Text = AnsiString();
    Item2NameEdit->Text = AnsiString();

   	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::FilterShowButtonClick(TObject *Sender)
{
    if (FilterShowButton->Caption == ">>"){
        FilterPanel->Height = 121;
        FilterShowButton->Caption = "<<";
    }else{
        FilterPanel->Height = 61;
        FilterShowButton->Caption = ">>";
    }
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::TokuCodeEditChange(TObject *Sender)
{
    TokuNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0), "���Ӑ旪��"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::HinCodeEditChange(TObject *Sender)
{
    HinNameEdit->Text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i�ڗ���"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item1CodeEditChange(TObject *Sender)
{
    Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1����"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item2CodeEditChange(TObject *Sender)
{
    Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2����"));
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::TokuButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ旪�� FROM M_���Ӑ� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ���Ӑ�R�[�h ";
    SearchForm->table_name = "M_���Ӑ�";
    if (SearchForm->ShowModal() != mrOk)
        return;
    TokuCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
    TokuCodeEdit->OnChange(NULL);
    TokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::HinButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT �i�ڃR�[�h, �i�ڗ���, �����o�敪���� AS �����o, ����敪���� AS ����敪 FROM V_�i�� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
    SearchForm->table_name = "M_�i��";
    if (SearchForm->ShowModal() != mrOk)
        return;
    HinCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
    HinCodeEdit->OnChange(NULL);
    HinCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item1ButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT ����1�R�[�h, ����1���� FROM M_����1 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����1�R�[�h ";
    SearchForm->table_name = "M_����1";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item1CodeEdit->Text = SearchForm->Query->FieldByName("����1�R�[�h")->AsInteger;
    Item1CodeEdit->OnChange(NULL);
    Item1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Item2ButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT ����2�R�[�h, ����2���� FROM M_����2 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����2�R�[�h ";
    SearchForm->table_name = "M_����2";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item2CodeEdit->Text = SearchForm->Query->FieldByName("����2�R�[�h")->AsInteger;
    Item2CodeEdit->OnChange(NULL);
    Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::Q_KeiryoCalcFields(TDataSet *DataSet)
{
	if (Q_Keiryo->FieldByName("�`�[No")->AsInteger >= 900000000)
		Q_Keiryo->FieldByName("�\���p�`�[No")->AsString = "�ؗ�";
	else
		Q_Keiryo->FieldByName("�\���p�`�[No")->AsString = Q_Keiryo->FieldByName("�`�[No")->AsString;
}
//---------------------------------------------------------------------------
// ��������->OnKeyDown
void __fastcall TDataListForm::cedtSearchKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	Action5->Execute();
}
//---------------------------------------------------------------------------
// DBGrid->OnKeyDown
void __fastcall TDataListForm::DBGridKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	btnOk->OnClick(NULL);
}
//---------------------------------------------------------------------------
// ���я��A���~��->OnChange
void __fastcall TDataListForm::OrderComboBoxChange(TObject *Sender)
{
	Action5->Execute();
}
//---------------------------------------------------------------------------
// Form->OnKeyDown
void __fastcall TDataListForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_ESCAPE)
		btnCancel->Click();	
}
//---------------------------------------------------------------------------

