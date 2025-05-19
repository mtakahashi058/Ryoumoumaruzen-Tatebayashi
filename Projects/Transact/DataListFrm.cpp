//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "DataListFrm.h"
#include "nsoftfunc.h"
#include <memory>
#include "MainFrm.h"
#include "SearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TDataListForm *DataListForm;
AnsiString GRID_CONFIG = "����O���b�h�z�u.txt";
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

        TokuButton->Caption  = ToString(DM->CFG["���Ӑ�}�X�^����"]);
        HinButton->Caption   = ToString(DM->CFG["�i�ڃ}�X�^����"]);
        Item1Button->Caption = ToString(DM->CFG["����1�}�X�^����"]);
        Item2Button->Caption = ToString(DM->CFG["����2�}�X�^����"]);

        DBGrid->Columns->Items[7]->Title->Caption  = ToString(DM->CFG["���Ӑ�}�X�^����"]);
        DBGrid->Columns->Items[9]->Title->Caption  = ToString(DM->CFG["����1�}�X�^����"]);
        DBGrid->Columns->Items[11]->Title->Caption = ToString(DM->CFG["����2�}�X�^����"]);
        DBGrid->Columns->Items[13]->Title->Caption = ToString(DM->CFG["�i�ڃ}�X�^����"]);

        ClearButton->Click();

        FilterShowButton->Caption = ">>";
        FilterPanel->Height = 61;

        first_ = false;
    }

   	Action5->Execute();
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
	if (DBGrid->SelectedRows->CurrentRowSelected || DBGrid->Columns->Items[DataCol]->Color != DBGrid->Color)
		;
	else if ((State.Empty() || ActiveControl != DBGrid) && DBGrid->DataSource->DataSet->RecNo % 2 == 0)
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
void __fastcall TDataListForm::Action5Execute(TObject *Sender)
{
	if (Q_Trans->Active)
		Q_Trans->Close();

	AnsiString sql;
	NsFilterSet filters;

	sql = " SELECT * FROM V_���";

	if (dtpDateFrom->Checked)
		filters << NsFilter("����� >= ", DateToInt(dtpDateFrom->Date));
	if (dtpDateTo->Checked)
		filters << NsFilter("����� <= ", DateToInt(dtpDateTo->Date));

    if (PlaceCombo->ItemIndex != 0){
        filters << NsFilter("���_ID = ", IntToStr(DM->PlaceIDMap[PlaceCombo->ItemIndex]));
    }
    
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

	sql += " WHERE " + ToFilter(filters, "AND");

	if (!cedtSearch->Text.IsEmpty()){
		sql += " AND " + DM->DBI.FullSearchSQL(cedtSearch->Text, "V_���");
	}

    if (UnitCombo->ItemIndex == 0)
        sql += " AND �sNo = 1";

	Q_Trans->SQL->Text = sql;

	Q_Trans->Open();

    if (rec_no_ >= 0){
        try{
            Q_Trans->RecNo = rec_no_;
        }catch(...){}
    }
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::btnOkClick(TObject *Sender)
{
	if (Q_Trans->Bof && Q_Trans->Eof)
		return;

    rec_no_ = Q_Trans->RecNo;

    int lineno = Q_Trans->FieldByName("�sNo")->AsInteger;
    if (lineno != 1){
        int date  = Q_Trans->FieldByName("�����")->AsInteger;
        int place = Q_Trans->FieldByName("���_ID")->AsInteger;
        int no    = Q_Trans->FieldByName("�`�[No")->AsInteger;

        NsFieldSet keys;
        keys << NsField("�����", date)
             << NsField("���_ID", place)
             << NsField("�`�[No", no)
             << NsField("�sNo",   1);

        selected_id = ToInt(DM->DBI.Lookup("D_���", keys, "���ID"));
    }else{
    	selected_id = Q_Trans->FieldByName("���ID")->AsInteger;
    }

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
void __fastcall TDataListForm::PriorDateButtonClick(TObject *Sender)
{
    bool checked_from = dtpDateFrom->Checked;
    bool checked_to   = dtpDateTo->Checked;

    dtpDateFrom->Checked = true;
    dtpDateTo->Checked   = true;

    ShiftDate(dtpDateFrom, dtpDateTo, -1);

    dtpDateFrom->Checked = checked_from;
    dtpDateTo->Checked   = checked_to;
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
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearGridButtonClick(TObject *Sender)
{
	AnsiString file = ExtractFilePath(Application->ExeName) + GRID_CONFIG;
	if (FileExists(file))
		DeleteFile(file);
	Application->MessageBox("����f�[�^���͂��ċN�����ĉ�����", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    grid_cleared_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TDataListForm::ClearButtonClick(TObject *Sender)
{
    TDateTime now(Now());
	dtpDateFrom->Date = now;
    dtpDateTo->Date   = now;

    place_id_       = MainForm->GetPlaceID();

    DM->PlaceIDMap.clear();
	PlaceCombo->Items->Clear();
    NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT ���_ID, ���_�R�[�h, ���_���� FROM M_���_", set)){
		Application->MessageBox("���_�}�X�^���ݒ肳��Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
    PlaceCombo->Items->Append("���ׂ�");
	for (unsigned int i = 0; i < set.size(); i++){
        DM->PlaceIDMap[i + 1] = ToInt(set[i]["���_ID"]);
		PlaceCombo->Items->Append(ToString(set[i]["���_����"]));
	}
    PlaceCombo->ItemIndex = 0;

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
        FilterPanel->Height = 136;
        FilterShowButton->Caption = "<<";
    }else{
        FilterPanel->Height = 61;
        FilterShowButton->Caption = ">>";
    }
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

