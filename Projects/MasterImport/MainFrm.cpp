//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include <memory>
#include <fstream>
#include <StrUtils.hpp>
#include <DateUtils.hpp>
#include "DMFrm.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner), thread_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
	ProgressBar->Max      = 5;
    ProgressBar->Step     = 1;

	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�

	if (!DM->Init())
		Close();

    port_ = ToInt(DM->INI["Batch::Port"]);
    def_  = ToString(DM->INI["Batch::Def"]);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CarsImportButtonClick(TObject *Sender)
{
    CarsImportButton->Enabled = false;
    ItemImportButton->Enabled = false;
    CloseButton->Enabled      = false;

	received_rec_.clear();

    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 5;
    ProgressBar->Step     = 1;

    target_ = itID;
    thread_ = new TN95ImportThread(false, port_, def_, Handle, target_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemImportButtonClick(TObject *Sender)
{
    CarsImportButton->Enabled = false;
    ItemImportButton->Enabled = false;
    CloseButton->Enabled      = false;

    received_rec_.clear();

    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 5;
    ProgressBar->Step     = 1;

    target_ = itItem;
    thread_ = new TN95ImportThread(false, port_, def_, Handle, target_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnCompleted(TMessage& message)
{
	StatusLabel->Caption = "�������܂���";

    delete thread_;
    thread_ = 0;

    AnsiString log_name;

    if (target_ == itID){
        log_name = "idimport.log";
    }else if (target_ == itItem){
        log_name = "itemimport.log";
    }else{
    }

    if (!log_name.IsEmpty()){
    	std::ofstream ofs(log_name.c_str());
    	for (unsigned int i = 0; i < received_rec_.size(); i++){
    		ofs << received_rec_[i].c_str() << std::endl;
    	}
    }

	// �f�[�^�R���o�[�g

    for (unsigned int i = 0; i < received_rec_.size(); i++){
        if (target_ == itID){
            PostRecordID(received_rec_[i]);
        }else if (target_ == itItem){
            PostRecordItem(received_rec_[i]);
        }else
            continue;
    }

	Application->MessageBox("��M���������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	CarsImportButton->Enabled = true;
	ItemImportButton->Enabled = true;
	CloseButton->Enabled      = true;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::PostRecordID(AnsiString record)
{
	int car_no, item1_code, item2_code, item3_code, item4_code, tare, max;
	AnsiString buff;
	int scm_toku, scm_item1, scm_item2, scm_meig, dummy;

	////////////////////////////////////////////////////////////////////////////
	// �w���v�� ScaM �̍��ڊ��蓖�ă}�b�s���O
	std::map<int, int> cnv_table;   // map<AD4385����, ScM�}�X�^>
	cnv_table[1] = ToInt(DM->CFG["�w���v���ڂP"]);
	cnv_table[2] = ToInt(DM->CFG["�w���v���ڂQ"]);
	cnv_table[3] = ToInt(DM->CFG["�w���v���ڂR"]);
	cnv_table[4] = ToInt(DM->CFG["�w���v���ڂS"]);
	for (int i = 1; i <= 4; i++){
		if (cnv_table[i] < 1 || cnv_table[i] > 4)
			cnv_table[i] = 0;
	}

	std::map<int, int *> scm_codes;
	scm_codes[0] = &dummy;
	scm_codes[1] = &scm_toku;
	scm_codes[2] = &scm_item1;
	scm_codes[3] = &scm_item2;
	scm_codes[4] = &scm_meig;

	TDateTime now(Now());
	NsFieldSet fields;

	///// rec 1
	buff       = AnsiSubString(record, 8, 40);
	car_no     = AnsiSubString(AnsiSubString(buff, 3, 8).Trim(), 1, 6).ToIntDef(0);
	buff       = AnsiReplaceStr(buff, " ", "0");
	item1_code = AnsiSubString(buff, 12, 3).ToIntDef(0);
	item2_code = AnsiSubString(buff, 16, 3).ToIntDef(0);
	item3_code = AnsiSubString(buff, 20, 3).ToIntDef(0);
	item4_code = AnsiSubString(buff, 24, 3).ToIntDef(0);
	tare       = AnsiSubString(buff, 28, 6).ToIntDef(0);
	max        = AnsiSubString(buff, 35, 6).ToIntDef(0);
	scm_toku   = 0;
	scm_item1  = 0;
	scm_item2  = 0;
	scm_meig   = 0;

	*(scm_codes[cnv_table[1]]) = item1_code;
	*(scm_codes[cnv_table[2]]) = item2_code;
	*(scm_codes[cnv_table[3]]) = item3_code;
	*(scm_codes[cnv_table[4]]) = item4_code;

	fields.clear();
	fields << NsField("[�Ԕ�]",       car_no)
		   << NsField("[�ԗ�����]",   IntToStr(car_no))
		   << NsField("[��ԏd��]",   tare)
		   << NsField("[�ԗ����d��]", max)
		   << NsField("[�J�[�h�ԍ�]", ToInt(DM->CFG["RFID�v��"]) ? Variant() : car_no)
		   << NsField("[���Ӑ�ID]",   DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", scm_toku,  "���Ӑ�ID"))
		   << NsField("[����1ID]",    DM->DBI.Lookup("M_����1",  "����1�R�[�h",  scm_item1, "����1ID"))
		   << NsField("[����2ID]",    DM->DBI.Lookup("M_����2",  "����2�R�[�h",  scm_item2, "����2ID"))
		   << NsField("[�i��ID]",     DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   scm_meig,  "�i��ID"))
		   << NsField("[�g�p�敪]",   1)
		   << NsField("[�X�V����]",   now)
		   << NsField("[�쐬����]",   now);

	if (!DM->DBI.IsExist("M_�ԗ�", "�Ԕ�", car_no) && car_no > 0)
		DM->DBI.Insert("M_�ԗ�", fields);

	///// rec 2
	buff       = AnsiSubString(record, 48, 40);
	car_no     = AnsiSubString(AnsiSubString(buff, 3, 8).Trim(), 1, 6).ToIntDef(0);
	buff       = AnsiReplaceStr(buff, " ", "0");
	item1_code = AnsiSubString(buff, 12, 3).ToIntDef(0);
	item2_code = AnsiSubString(buff, 16, 3).ToIntDef(0);
	item3_code = AnsiSubString(buff, 20, 3).ToIntDef(0);
	item4_code = AnsiSubString(buff, 24, 3).ToIntDef(0);
	tare       = AnsiSubString(buff, 28, 6).ToIntDef(0);
	max        = AnsiSubString(buff, 35, 6).ToIntDef(0);
	scm_toku   = 0;
	scm_item1  = 0;
	scm_item2  = 0;
	scm_meig   = 0;

	*(scm_codes[cnv_table[1]]) = item1_code;
	*(scm_codes[cnv_table[2]]) = item2_code;
	*(scm_codes[cnv_table[3]]) = item3_code;
	*(scm_codes[cnv_table[4]]) = item4_code;

	fields.clear();
	fields << NsField("[�Ԕ�]",       car_no)
		   << NsField("[�ԗ�����]",   IntToStr(car_no))
		   << NsField("[��ԏd��]",   tare)
		   << NsField("[�ԗ����d��]", max)
		   << NsField("[�J�[�h�ԍ�]", car_no)
		   << NsField("[���Ӑ�ID]",   DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", scm_toku,  "���Ӑ�ID"))
		   << NsField("[����1ID]",    DM->DBI.Lookup("M_����1",  "����1�R�[�h",  scm_item1, "����1ID"))
		   << NsField("[����2ID]",    DM->DBI.Lookup("M_����2",  "����2�R�[�h",  scm_item2, "����2ID"))
		   << NsField("[�i��ID]",     DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   scm_meig,  "�i��ID"))
		   << NsField("[�g�p�敪]",   1)
		   << NsField("[�X�V����]",   now)
		   << NsField("[�쐬����]",   now);

	if (!DM->DBI.IsExist("M_�ԗ�", "�Ԕ�", car_no) && car_no > 0)
		DM->DBI.Insert("M_�ԗ�", fields);

	///// rec 3
	buff       = AnsiSubString(record, 88, 40);
	car_no     = AnsiSubString(AnsiSubString(buff, 3, 8).Trim(), 1, 6).ToIntDef(0);
	buff       = AnsiReplaceStr(buff, " ", "0");
	item1_code = AnsiSubString(buff, 12, 3).ToIntDef(0);
	item2_code = AnsiSubString(buff, 16, 3).ToIntDef(0);
	item3_code = AnsiSubString(buff, 20, 3).ToIntDef(0);
	item4_code = AnsiSubString(buff, 24, 3).ToIntDef(0);
	tare       = AnsiSubString(buff, 28, 6).ToIntDef(0);
	max        = AnsiSubString(buff, 35, 6).ToIntDef(0);
	scm_toku   = 0;
	scm_item1  = 0;
	scm_item2  = 0;
	scm_meig   = 0;

	*(scm_codes[cnv_table[1]]) = item1_code;
	*(scm_codes[cnv_table[2]]) = item2_code;
	*(scm_codes[cnv_table[3]]) = item3_code;
	*(scm_codes[cnv_table[4]]) = item4_code;

	fields.clear();
	fields << NsField("[�Ԕ�]",       car_no)
		   << NsField("[�ԗ�����]",   IntToStr(car_no))
		   << NsField("[��ԏd��]",   tare)
		   << NsField("[�ԗ����d��]", max)
		   << NsField("[�J�[�h�ԍ�]", car_no)
		   << NsField("[���Ӑ�ID]",   DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", scm_toku,  "���Ӑ�ID"))
		   << NsField("[����1ID]",    DM->DBI.Lookup("M_����1",  "����1�R�[�h",  scm_item1, "����1ID"))
		   << NsField("[����2ID]",    DM->DBI.Lookup("M_����2",  "����2�R�[�h",  scm_item2, "����2ID"))
		   << NsField("[�i��ID]",     DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   scm_meig,  "�i��ID"))
		   << NsField("[�g�p�敪]",   1)
		   << NsField("[�X�V����]",   now)
		   << NsField("[�쐬����]",   now);

	if (!DM->DBI.IsExist("M_�ԗ�", "�Ԕ�", car_no) && car_no > 0)
		DM->DBI.Insert("M_�ԗ�", fields);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::PostRecordItem(AnsiString record)
{
	int item_no, item_code;
	AnsiString item_name;
	AnsiString table, buff;
	int scm_item_no;


	////////////////////////////////////////////////////////////////////////////
	// �w���v�� ScaM �̍��ڊ��蓖�ă}�b�s���O
	std::map<int, int> cnv_table;   // map<AD4385����, ScM�}�X�^>
	cnv_table[1] = ToInt(DM->CFG["�w���v���ڂP"]);
	cnv_table[2] = ToInt(DM->CFG["�w���v���ڂQ"]);
	cnv_table[3] = ToInt(DM->CFG["�w���v���ڂR"]);
	cnv_table[4] = ToInt(DM->CFG["�w���v���ڂS"]);

	scm_item_no = cnv_table[item_no];

	TDateTime now(Now());
	NsFieldSet fields;

	///// rec 1
	buff       = AnsiSubString(record, 8, 40);
	item_name  = AnsiSubString(buff, 9, 28).Trim();
	buff       = AnsiReplaceStr(buff, " ", "0");

	item_no     = AnsiSubString(buff, 2, 1).ToIntDef(0);
	scm_item_no = cnv_table[item_no];
	item_code   = AnsiSubString(buff, 4, 3).ToIntDef(0);

	if (scm_item_no == 1){
		table = "���Ӑ�";
	}else if (scm_item_no == 2){
		table = "����1";
	}else if (scm_item_no == 3){
		table = "����2";
	}else if (scm_item_no == 4){
		table = "�i��";
	}
	fields.clear();
	fields << NsField("[" + table + "�R�[�h]", item_code)
		   << NsField("[" + table + "����]",   item_name)
		   << NsField("[" + table + "����]",   AnsiSubString(item_name, 1, 20))
		   << NsField("[�g�p�敪]",   1)
		   << NsField("[�X�V����]",   now)
		   << NsField("[�쐬����]",   now);

    if (scm_item_no == 4)
        fields << NsField("[�����o�敪]", 1);

	if (!DM->DBI.IsExist("M_" + table, table + "�R�[�h", item_code) && !(table.IsEmpty()))
		DM->DBI.Insert("M_" + table, fields);

	///// rec 2
	buff       = AnsiSubString(record, 48, 40);
	item_name  = AnsiSubString(buff, 9, 28).Trim();
	buff       = AnsiReplaceStr(buff, " ", "0");

	item_no     = AnsiSubString(buff, 2, 1).ToIntDef(0);
	scm_item_no = cnv_table[item_no];
	item_code   = AnsiSubString(buff, 4, 3).ToIntDef(0);

	if (scm_item_no == 1){
		table = "���Ӑ�";
	}else if (scm_item_no == 2){
		table = "����1";
	}else if (scm_item_no == 3){
		table = "����2";
	}else if (scm_item_no == 4){
		table = "�i��";
	}
	fields.clear();
	fields << NsField("[" + table + "�R�[�h]", item_code)
		   << NsField("[" + table + "����]",   item_name)
		   << NsField("[" + table + "����]",   AnsiSubString(item_name, 1, 20))
		   << NsField("[�g�p�敪]",   1)
		   << NsField("[�X�V����]",   now)
		   << NsField("[�쐬����]",   now);

    if (scm_item_no == 4)
        fields << NsField("[�����o�敪]", 1);

	if (!DM->DBI.IsExist("M_" + table, table + "�R�[�h", item_code) && !(table.IsEmpty()))
		DM->DBI.Insert("M_" + table, fields);

	///// rec 3
	buff       = AnsiSubString(record, 88, 40);
	item_name   = AnsiSubString(buff, 9, 28).Trim();
	buff       = AnsiReplaceStr(buff, " ", "0");

	item_no     = AnsiSubString(buff, 2, 1).ToIntDef(0);
	scm_item_no = cnv_table[item_no];
	item_code   = AnsiSubString(buff, 4, 3).ToIntDef(0);

	if (scm_item_no == 1){
		table = "���Ӑ�";
	}else if (scm_item_no == 2){
		table = "����1";
	}else if (scm_item_no == 3){
		table = "����2";
	}else if (scm_item_no == 4){
		table = "�i��";
	}
	fields.clear();
	fields << NsField("[" + table + "�R�[�h]", item_code)
		   << NsField("[" + table + "����]",   item_name)
		   << NsField("[" + table + "����]",   AnsiSubString(item_name, 1, 20))
		   << NsField("[�g�p�敪]",   1)
		   << NsField("[�X�V����]",   now)
		   << NsField("[�쐬����]",   now);

    if (scm_item_no == 4)
        fields << NsField("[�����o�敪]", 1);

	if (!DM->DBI.IsExist("M_" + table, table + "�R�[�h", item_code) && !(table.IsEmpty()))
		DM->DBI.Insert("M_" + table, fields);

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnAborted(TMessage& message)
{
	Application->MessageBox("�f�[�^��M�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);

	CarsImportButton->Enabled = true;
	ItemImportButton->Enabled = true;
	CloseButton->Enabled      = true;

	delete thread_;
	thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnStatus(TMessage& message)
{
	StatusLabel->Caption = (LPCSTR)(message.LParam);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnDataReceived(TMessage& message)
{
	received_rec_.push_back((LPCSTR)(message.LParam));
	CountLabel->Caption = IntToStr(received_rec_.size());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnProcessStep(TMessage& message)
{
	ProgressBar->StepIt();
}
//---------------------------------------------------------------------------

