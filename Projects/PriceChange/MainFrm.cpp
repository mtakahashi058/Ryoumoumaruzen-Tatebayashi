//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	Application->OnMessage = this->MessageProc;
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

	DM->CFG.Load(&DM->DBI);

	SetItem();

	DayRadioButton->Checked = true;
	DayRadioButton->OnClick(NULL);
	TokuCodeEdit->Text  = AnsiString();
	HinCodeEdit->Text   = AnsiString();
	Item1CodeEdit->Text = AnsiString();
	Item2CodeEdit->Text = AnsiString();
	TaniCodeEdit->Text  = AnsiString();

	DM->Q_Itiran->Close();

	PriceEdit->Text     = AnsiString();

	FromDatePicker->SetFocus();
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

	m = ToInt(DM->CFG["������t"]);

	try{
		FromDatePicker->Date = EncodeDate(y, m, 1);
	}catch (...){
		FromDatePicker->Date = EncodeDate(y, 4, 1);
	}
	ToDatePicker->Date = IncYear(FromDatePicker->Date, 1) - 1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuCodeEditChange(TObject *Sender)
{
	if (TokuCodeEdit->Text == ""){
		TokuNameEdit->Text = AnsiString();
		return;
	}
	TokuNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuButtonClick(TObject *Sender)
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
void __fastcall TMainForm::HinCodeEditChange(TObject *Sender)
{
	if (HinCodeEdit->Text == ""){
		HinNameEdit->Text = AnsiString();
		return;
	}
	HinNameEdit->Text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i�ږ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT �i�ڃR�[�h, �i�ڗ���, ����敪���� AS ����敪 FROM V_�i�� WHERE �g�p�敪 = 1";
	SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
	SearchForm->table_name = "M_�i��";
	if (SearchForm->ShowModal() != mrOk)
		return;
	HinCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
	HinCodeEdit->OnChange(NULL);
	HinCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1CodeEditChange(TObject *Sender)
{
	if (Item1CodeEdit->Text == ""){
		Item1NameEdit->Text = AnsiString();
		return;
	}
	Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1ButtonClick(TObject *Sender)
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
void __fastcall TMainForm::Item2CodeEditChange(TObject *Sender)
{
	if (Item2CodeEdit->Text == ""){
		Item2NameEdit->Text = AnsiString();
		return;
	}
	Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2ButtonClick(TObject *Sender)
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
void __fastcall TMainForm::TaniCodeEditChange(TObject *Sender)
{
	if (TaniCodeEdit->Text == ""){
		TaniNameEdit->Text = AnsiString();
		return;
	}
	TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P�ʖ���", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TaniButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P�� ";
	SearchForm->orderby_sql = " ORDER BY �P�ʃR�[�h ";
	SearchForm->table_name = "M_�P��";
	if (SearchForm->ShowModal() != mrOk)
		return;
	TaniCodeEdit->Text = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
	TaniCodeEdit->OnChange(NULL);
	TaniCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// �}�X�^����ꊇ�X�V
void __fastcall TMainForm::UpdateAllButtonClick(TObject *Sender)
{
    if (Application->MessageBox("�w��͈͂̃f�[�^��S�čX�V���܂��B�{���Ɏ��s���Ă�낵���ł����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    UpdateAllButton->Enabled  = false;
    ExtractionButton->Enabled = false;
    RunButton->Enabled        = false;

    try{
        DM->ADOConnection->BeginTrans();

        int count = UpdateAllFromMaster();

        DM->ADOConnection->CommitTrans();

        AnsiString msg = "�v��/����� " + IntToStr(count) + "���̃f�[�^���X�V���܂���";
        Application->MessageBox(msg.c_str(), UpdateAllButton->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString msg = "�X�V���ɃG���[���������܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), UpdateAllButton->Caption.c_str(), MB_OK | MB_ICONSTOP);
    }

    UpdateAllButton->Enabled  = true;
    ExtractionButton->Enabled = true;
    RunButton->Enabled        = true;
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::UpdateAllFromMaster()
{
    int date_from = FromDatePicker->Date.FormatString("yyyymmdd").ToInt();
    int date_to   = ToDatePicker->Date.FormatString("yyyymmdd").ToInt();
    TDateTime now(Now());

    AnsiString sql;
    NsRecordSet set;
    NsRecordSet toku_set;
    NsFieldSet fields;

    int date, toku_id, meig_id, item1_id, item2_id, tani_id;
    Currency qty, tanka;
    Currency tax_rate;
    int amount, amount_div, tax, tax_div;
    int count = 0;

    ///// �v�ʃf�[�^�X�V
    sql = "SELECT * FROM D_�v�� WHERE �v�ʓ� >= " + IntToStr(date_from) + " AND �v�ʓ� <= " + IntToStr(date_to) + " AND �����敪 = 1";
    DM->DBI.GetRecordSet(sql, set);
    for (unsigned int i = 0; i < set.size(); i++){
        date     = ToInt(set[i]["�v�ʓ�"]);
        toku_id  = ToInt(set[i]["���Ӑ�ID"]);
        meig_id  = ToInt(set[i]["�i��ID"]);
        item1_id = ToInt(set[i]["����1ID"]);
        item2_id = ToInt(set[i]["����2ID"]);
        tani_id  = ToInt(set[i]["�P��ID"]);
        qty      = ToCurrency(set[i]["����"]);
        tanka    = DM->GetTanka(toku_id, meig_id, item1_id, item2_id, tani_id);

        DM->DBI.GetRecordSet("SELECT * FROM M_���Ӑ� WHERE ���Ӑ�ID = " + IntToStr(toku_id), toku_set);

    	amount_div = -1;
	    if (!toku_set.empty()){
		    if (!IsNull(SET_TOP(toku_set)["���z�[�������敪"]))
			    amount_div = ToInt(SET_TOP(toku_set)["���z�[�������敪"]);
	    }
	    if (amount_div == -1)
		    amount_div = ToInt(DM->CFG["���z�[�������敪"]);

        amount = ExtendedRound(qty * tanka, 0, amount_div);

	    tax_rate = DM->GetSalesTax(date);			// ����ŗ�

	    tax_div = -1;
    	if (!toku_set.empty()){
	    	if (!IsNull(SET_TOP(toku_set)["����Œ[�������敪"]))
		    	tax_div = ToInt(SET_TOP(toku_set)["����Œ[�������敪"]);
    	}
	    if (tax_div == -1)
		    tax_div = ToInt(DM->CFG["����Œ[�������敪"]);

    	tax    = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

        fields.clear();
        fields << NsField("[�P��]",     tanka)
               << NsField("[���z]",     amount)
               << NsField("[����Ŋz]", tax)
               << NsField("[�X�V����]", now);
        DM->DBI.Update("D_�v��", "�v��ID", ToInt(set[i]["�v��ID"]), fields);


        count++;
    }

    ///// ����f�[�^�X�V
    sql = "SELECT * FROM D_��� WHERE ����� >= " + IntToStr(date_from) + " AND ����� <= " + IntToStr(date_to) + " AND �����敪 = 1";
    DM->DBI.GetRecordSet(sql, set);
    for (unsigned int i = 0; i < set.size(); i++){
        date     = ToInt(set[i]["�����"]);
        toku_id  = ToInt(set[i]["���Ӑ�ID"]);
        meig_id  = ToInt(set[i]["�i��ID"]);
        item1_id = ToInt(set[i]["����1ID"]);
        item2_id = ToInt(set[i]["����2ID"]);
        tani_id  = ToInt(set[i]["�P��ID"]);
        qty      = ToCurrency(set[i]["����"]);
        tanka    = DM->GetTanka(toku_id, meig_id, item1_id, item2_id, tani_id);

        DM->DBI.GetRecordSet("SELECT * FROM M_���Ӑ� WHERE ���Ӑ�ID = " + IntToStr(toku_id), toku_set);

    	amount_div = -1;
	    if (!toku_set.empty()){
		    if (!IsNull(SET_TOP(toku_set)["���z�[�������敪"]))
			    amount_div = ToInt(SET_TOP(toku_set)["���z�[�������敪"]);
	    }
	    if (amount_div == -1)
		    amount_div = ToInt(DM->CFG["���z�[�������敪"]);

        amount = ExtendedRound(qty * tanka, 0, amount_div);

	    tax_rate = DM->GetSalesTax(date);			// ����ŗ�

	    tax_div = -1;
    	if (!toku_set.empty()){
	    	if (!IsNull(SET_TOP(toku_set)["����Œ[�������敪"]))
		    	tax_div = ToInt(SET_TOP(toku_set)["����Œ[�������敪"]);
    	}
	    if (tax_div == -1)
		    tax_div = ToInt(DM->CFG["����Œ[�������敪"]);

    	tax    = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

        fields.clear();
        fields << NsField("[�P��]",     tanka)
               << NsField("[���z]",     amount)
               << NsField("[����Ŋz]", tax)
               << NsField("[�X�V����]", now);
        DM->DBI.Update("D_���", "���ID", ToInt(set[i]["���ID"]), fields);


        count++;
    }
    return count;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExtractionButtonClick(TObject *Sender)
{
	DM->Q_Itiran->Close();

	AnsiString where = AnsiString();

	if (TokuCodeEdit->Text != "")
		where += " AND ���Ӑ�R�[�h = " + TokuCodeEdit->Text;

	if (HinCodeEdit->Text != "")
		where += " AND �i�ڃR�[�h = " + HinCodeEdit->Text;

	if (Item1CodeEdit->Text != "")
		where += " AND ����1�R�[�h = " + Item1CodeEdit->Text;

	if (Item2CodeEdit->Text != "")
		where += " AND ����2�R�[�h = " + Item2CodeEdit->Text;

	if (TaniCodeEdit->Text != "")
		where += " AND �P�ʃR�[�h = " + TaniCodeEdit->Text;

	DM->Q_Itiran->SQL->Text = DM->GetExtractionQuery(where);

	DM->Q_Itiran->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	DM->Q_Itiran->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);
	DM->Q_Itiran->Parameters->ParamByName("GENKAKE")->Value   = GenkakeComboBox->ItemIndex + 1;

	try{
		DM->Q_Itiran->Open();
	}catch (Exception &e){
		Application->MessageBox(("�ύX�Ώۃf�[�^�̒��o�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
	}

	Application->OnMessage = this->MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->First();
	for (int i = 0; i < DBGrid->DataSource->DataSet->RecordCount; i++){
		DBGrid->SelectedRows->CurrentRowSelected = true;
		DBGrid->DataSource->DataSet->Next();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReleaseButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->First();
	for (int i = 0; i < DBGrid->DataSource->DataSet->RecordCount; i++){
		DBGrid->SelectedRows->CurrentRowSelected = false;
		DBGrid->DataSource->DataSet->Next();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RunButtonClick(TObject *Sender)
{
	int c = 0;
	DataMap data_map;

	try{
		DM->ADOConnection->BeginTrans();

		data_map.clear();
		DBGrid->DataSource->DataSet->First();
		while(!DBGrid->DataSource->DataSet->Eof){
			if (!DBGrid->SelectedRows->CurrentRowSelected){
				DBGrid->DataSource->DataSet->Next();
				continue;
			}
			data_map[c].div       = DBGrid->DataSource->DataSet->FieldByName("�f�[�^�敪")->AsInteger;
			data_map[c].id        = DBGrid->DataSource->DataSet->FieldByName("ID")->AsInteger;
			data_map[c].base      = DBGrid->DataSource->DataSet->FieldByName("���_ID")->AsInteger;
			data_map[c].date      = DBGrid->DataSource->DataSet->FieldByName("���t")->AsInteger;
			data_map[c].slip_no   = DBGrid->DataSource->DataSet->FieldByName("�`�[No")->AsInteger;
			data_map[c].toku_code = DBGrid->DataSource->DataSet->FieldByName("���Ӑ�R�[�h")->AsInteger;
			data_map[c].amount    = DBGrid->DataSource->DataSet->FieldByName("����")->AsCurrency;

			c++;
			DBGrid->DataSource->DataSet->Next();
		}

		if (c <= 0){
			Application->MessageBox("�ύX�Ώۃf�[�^���I������Ă��܂���B\r\n�f�[�^�I����A�ēx���s���Ă��������B",
				this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			DM->ADOConnection->RollbackTrans();
			return;
		}

		int fraction;
		NsFieldSet fields, keys;
		NsRecordSet set;
		AnsiString sql = AnsiString();
		for (DataMap::iterator i = data_map.begin(); i != data_map.end(); i++){
			fraction = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", i->second.toku_code, "���z�[�������敪", ""));
			fields.clear();
			Currency money = ExtendedRound(StrToCurrDef(PriceEdit->Text, 0) * i->second.amount, 0, fraction);
			Currency tax_rate = GetTaxRate(i->second.date);
			fields << NsField("[�P��]", StrToCurrDef(PriceEdit->Text, 0))
				   << NsField("[���z]", money)
				   << NsField("[����Ŋz]", ExtendedRound(money * tax_rate, 0, fraction));

			switch (i->second.div){
			case 1: // �v��
				DM->DBI.Update("D_�v��", "�v��ID", i->second.id, fields);

				sql = "SELECT SUM(���z) AS �`�[���z FROM V_�v�� WHERE ���_ID = " + IntToStr(i->second.base)
															  + " AND �v�ʓ� = " + IntToStr(i->second.date)
															  + " AND �`�[No = " + IntToStr(i->second.slip_no);
				keys.clear();
				keys << NsField("���_ID", i->second.base)
					 << NsField("�v�ʓ�", i->second.date)
					 << NsField("�`�[No", i->second.slip_no);

				set.clear();
				DM->DBI.GetRecordSet(sql, set);

				fields.clear();
				if (ToCurrency(set[0]["�`�[���z"]) == 0)
					fields << NsField("[�`�[����Ŋz]", 0);
				else
					fields << NsField("[�`�[����Ŋz]", ExtendedRound(ToCurrency(set[0]["�`�[���z"]) * tax_rate, 0, fraction));

				DM->DBI.Update("D_�v��", keys, fields);
				break;
			case 2: // ���
				DM->DBI.Update("D_���", "���ID", i->second.id, fields);

				sql = "SELECT SUM(���z) AS �`�[���z FROM V_��� WHERE ���_ID = " + IntToStr(i->second.base)
															  + " AND ����� = " + IntToStr(i->second.date)
															  + " AND �`�[No = " + IntToStr(i->second.slip_no);

				keys.clear();
				keys << NsField("���_ID", i->second.base)
					 << NsField("�����", i->second.date)
					 << NsField("�`�[No", i->second.slip_no);

				set.clear();
				DM->DBI.GetRecordSet(sql, set);

				fields.clear();
				if (ToCurrency(set[0]["�`�[���z"]) == 0)
					fields << NsField("[�`�[����Ŋz]", 0);
				else
					fields << NsField("[�`�[����Ŋz]", ExtendedRound(ToCurrency(set[0]["�`�[���z"]) * tax_rate, 0, fraction));

				DM->DBI.Update("D_���", keys, fields);
				break;
			}
		}

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("�P���̕ύX�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	Application->MessageBox("�P���ύX���������܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	ExtractionButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetItem()
{
	AnsiString cap = ToString(DM->CFG["���Ӑ�}�X�^����"]);
	if (ToString(DM->CFG["���Ӑ�}�X�^�g�p�敪"]) == "1"){
		TokuLabel->Caption = cap;
		DBGrid->Columns->Items[4]->Title->Caption  = cap;
	}else{
		TokuLabel->Caption = "���g�p";
		DBGrid->Columns->Items[4]->Title->Caption  = "���g�p";
	}

	cap = ToString(DM->CFG["�i�ڃ}�X�^����"]);
	if (ToString(DM->CFG["�i�ڃ}�X�^�g�p�敪"]) == "1"){
		HinLabel->Caption = cap;
		DBGrid->Columns->Items[6]->Title->Caption  = cap;
	}else{
		HinLabel->Caption = "���g�p";
		DBGrid->Columns->Items[6]->Title->Caption  = "���g�p";
	}

	cap = ToString(DM->CFG["����1�}�X�^����"]);
	if (ToString(DM->CFG["����1�}�X�^�g�p�敪"]) == "1"){
		Item1Label->Caption = cap;
		DBGrid->Columns->Items[12]->Title->Caption  = cap;
	}else{
		Item1Label->Caption = "���g�p";
		DBGrid->Columns->Items[12]->Title->Caption  = "���g�p";
	}

	cap = ToString(DM->CFG["����2�}�X�^����"]);
	if (ToString(DM->CFG["����2�}�X�^�g�p�敪"]) == "1"){
		Item2Label->Caption = cap;
		DBGrid->Columns->Items[14]->Title->Caption  = cap;
	}else{
		Item2Label->Caption = "���g�p";
		DBGrid->Columns->Items[14]->Title->Caption  = "���g�p";
	}
}
//---------------------------------------------------------------------------
Currency __fastcall TMainForm::GetTaxRate(int date)
{
	if (!date)
		date = Now().FormatString("yyyymmdd").ToInt();

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 ����ŗ� FROM M_�����"
		  " WHERE"
		  " 	�J�n���t <= " + IntToStr(date) +
		  " ORDER BY �J�n���t DESC";
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0.05;
	int n = ToInt(SET_TOP(set)["����ŗ�"]);
	return n / Currency(100);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	switch(Msg.message){
		case WM_MOUSEWHEEL:
		if(Msg.hwnd == DBGrid->Handle){
			//�z�C�[���}�E�X�̃C�x���g�ŏ㉺�ɓ����悤�ɐݒ�
			if((short)HIWORD(Msg.wParam) > 0){
				DBGrid->DataSource->DataSet->Prior();
			}else{
				DBGrid->DataSource->DataSet->Next();
			}
			//�����͂����ŃX�g�b�v������
			Handled = true;
		}
		if(Msg.hwnd == SearchForm->DBGrid->Handle){
			//�z�C�[���}�E�X�̃C�x���g�ŏ㉺�ɓ����悤�ɐݒ�
			if((short)HIWORD(Msg.wParam) > 0){
				SearchForm->DBGrid->DataSource->DataSet->Prior();
			}else{
				SearchForm->DBGrid->DataSource->DataSet->Next();
			}
			//�����͂����ŃX�g�b�v������
			Handled = true;
		}
		break;
	}
}
//---------------------------------------------------------------------------

