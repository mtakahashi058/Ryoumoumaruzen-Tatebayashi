//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"

#include "TokuisakiEditFrm.h"
#include "Item1EditFrm.h"
#include "Item2EditFrm.h"
#include "HinBnruiEditFrm.h"
#include "HinmokuEditFrm.h"
#include "SharyoEditFrm.h"
#include "KanzanEditFrm.h"
#include "KyotenEditFrm.h"
#include "TaniEditFrm.h"
#include "TankaEditFrm.h"
#include "SlipInfoEditFrm.h"
#include "SlipInfoRelateEditFrm.h"
#include "ItemRelateEditFrm.h"
#include "BankEditFrm.h"
#include "TaxEditFrm.h"

#include "QRTokuisakiFrm.h"
#include "QRItem1Frm.h"
#include "QRItem2Frm.h"
#include "QRHinBunruiFrm.h"
#include "QRHinmokuFrm.h"
#include "QRSharyoFrm.h"
#include "QRKanzanFrm.h"
#include "QRKyotenFrm.h"
#include "QRTaniFrm.h"
#include "QRTankaFrm.h"
#include "QRSlipInfoFrm.h"
#include "QRSlipInfoRelateFrm.h"
#include "QRItemRelateFrm.h"
#include "QRBankFrm.h"
#include "QRTaxFrm.h"

#include "SortSetFrm.h"

#include "MainFrm.h"

#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "NotPanel"
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
	TabSheet14->TabVisible = false;
	TabSheet15->TabVisible = false;

	/****************************************/
	/*		�����ݒ�		*/
	/****************************************/
	// MainFrm.h(�Q��) : TADOQuery *query[10];
	query[0]  = DM->M_Tokuisaki;
	query[1]  = DM->M_Item1;
	query[2]  = DM->M_Item2;
	query[3]  = DM->M_HinBunrui;
	query[4]  = DM->M_Hinmoku;
	query[5]  = DM->M_Sharyo;
	query[6]  = DM->M_Kanzan;
	query[7]  = DM->M_Kyoten;
	query[8]  = DM->M_Tani;
	query[9]  = DM->M_Tanka;
	query[10] = DM->M_SlipInfo;
	query[11] = DM->M_SlipInfoRelate;
	query[12] = DM->M_Bank;
	query[13] = 0;
	query[14] = 0;
	query[15] = DM->M_Tax;
	query[16] = DM->M_ItemRelate;

	// MainFrm.h(�Q��) : TDBGrid *grid[10];
	grid[0]  = DBGrid1;
	grid[1]  = DBGrid2;
	grid[2]  = DBGrid3;
	grid[3]  = DBGrid4;
	grid[4]  = DBGrid5;
	grid[5]  = DBGrid6;
	grid[6]  = DBGrid7;
	grid[7]  = DBGrid8;
	grid[8]  = DBGrid9;
	grid[9]  = DBGrid10;
	grid[10] = DBGrid11;
	grid[11] = DBGrid12;
	grid[12] = DBGrid13;
	grid[13] = 0;
	grid[14] = 0;
	grid[15] = DBGrid16;
	grid[16] = DBGrid17;

	// MainFrm.h(�Q��) : AnsiString keyfield[10];
	keyfield[0]  = "���Ӑ�ID";
	keyfield[1]  = "����1ID";
	keyfield[2]  = "����2ID";
	keyfield[3]  = "�i�ڕ���ID";
	keyfield[4]  = "�i��ID";
	keyfield[5]  = "�ԗ�ID";
	keyfield[6]  = "���ZID";
	keyfield[7]  = "���_ID";
	keyfield[8]  = "�P��ID";
	keyfield[9]  = "�P��ID";
	keyfield[10] = "�`�[���ID";
	keyfield[11] = "�`�[���֘AID";
	keyfield[12] = "��sID";
	keyfield[13] = AnsiString();
	keyfield[14] = AnsiString();
	keyfield[15] = "�J�n���t";
	keyfield[16] = "���ڊ֘AID";

	// MainFrm.h(�Q��) : TQuickReport *report[10];
	report[0]  = QRTokuisakiForm->QuickRep;
	report[1]  = QRItem1Form->QuickRep;
	report[2]  = QRItem2Form->QuickRep;
	report[3]  = QRHinBunruiForm->QuickRep;
	report[4]  = QRHinmokuForm->QuickRep;
	report[5]  = QRSharyoForm->QuickRep;
	report[6]  = QRKanzanForm->QuickRep;
	report[7]  = QRKyotenForm->QuickRep;
	report[8]  = QRTaniForm->QuickRep;
	report[9]  = QRTankaForm->QuickRep;
	report[10] = QRSlipInfoForm->QuickRep;
	report[11] = QRSlipInfoRelateForm->QuickRep;
	report[12] = QRBankForm->QuickRep;
	report[13] = 0;
	report[14] = 0;
	report[15] = QRTaxForm->QuickRep;
	report[16] = QRItemRelateForm->QuickRep;

	// MainFrm.h(�Q��) : TCobEdit *search_edit[10];
	search_edit[0]  = SearchEdit1;
	search_edit[1]  = SearchEdit2;
	search_edit[2]  = SearchEdit3;
	search_edit[3]  = SearchEdit4;
	search_edit[4]  = SearchEdit5;
	search_edit[5]  = SearchEdit6;
	search_edit[6]  = SearchEdit7;
	search_edit[7]  = SearchEdit8;
	search_edit[8]  = SearchEdit9;
	search_edit[9]  = SearchEdit10;
	search_edit[10] = SearchEdit11;
	search_edit[11] = SearchEdit12;
	search_edit[12] = SearchEdit13;
	search_edit[13] = 0;
	search_edit[14] = 0;
	search_edit[15] = SearchEdit16;
	search_edit[16] = SearchEdit17;

	// MainFrm.h(�Q��) : TCheckBox check_box[10];
	check_box[0]  = AllDataShowCheckBox1;
	check_box[1]  = AllDataShowCheckBox2;
	check_box[2]  = AllDataShowCheckBox3;
	check_box[3]  = AllDataShowCheckBox4;
	check_box[4]  = AllDataShowCheckBox5;
	check_box[5]  = AllDataShowCheckBox6;
	check_box[6]  = NULL;
	check_box[7]  = NULL;
	check_box[8]  = NULL;
	check_box[9]  = NULL;
	check_box[10] = NULL;
	check_box[11] = NULL;
	check_box[12] = NULL;
	check_box[13] = NULL;
	check_box[14] = NULL;
	check_box[15] = NULL;
	check_box[16] = NULL;

	// MainFrm.h(�Q��) : AnsiString master_name_[10];
	master_name_[0]  = "���Ӑ�}�X�^";
	master_name_[1]  = "����1�}�X�^";
	master_name_[2]  = "����2�}�X�^";
	master_name_[3]  = "�i�ڕ��ރ}�X�^";
	master_name_[4]  = "�i�ڃ}�X�^";
	master_name_[5]  = "�ԗ��}�X�^";
	master_name_[6]  = "���Z�}�X�^";
	master_name_[7]  = "���_�}�X�^";
	master_name_[8]  = "�P�ʃ}�X�^";
	master_name_[9]  = "�P���}�X�^";
	master_name_[10] = "�`�[���}�X�^";
	master_name_[11] = "�`�[���֘A�}�X�^";
	master_name_[12] = "��s�}�X�^";
	master_name_[13] = AnsiString();
	master_name_[14] = AnsiString();
	master_name_[15] = "����Ń}�X�^";
	master_name_[16] = "���ڊ֘A�}�X�^";

	// MainFrm.h(�Q��) : AnsiString talbe_name_[10];
	table_name_[0]  = "M_���Ӑ�";
	table_name_[1]  = "M_����1";
	table_name_[2]  = "M_����2";
	table_name_[3]  = "M_�i�ڕ���";
	table_name_[4]  = "M_�i��";
	table_name_[5]  = "M_�ԗ�";
	table_name_[6]  = "M_���Z";
	table_name_[7]  = "M_���_";
	table_name_[8]  = "M_�P��";
	table_name_[9]  = "M_�P��";
	table_name_[10] = "M_�`�[���";
	table_name_[11] = "M_�`�[���֘A";
	table_name_[12] = "M_��s";
	table_name_[13] = AnsiString();
	table_name_[14] = AnsiString();
	table_name_[15] = "M_�����";
	table_name_[16] = "M_���ڊ֘A";

	// MainFrm.h(�Q��) : int page_count;
	page_count = 17;

	/*************�����ݒ�I��***************/

	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Connected = false;

	// �R���|�[�l���g������
	for (int i = 0; i < page_count; i++){
        if (search_edit[i])
    		search_edit[i]->Text  = AnsiString();
		if (check_box[i])
			check_box[i]->Checked = false;
	}

	try{
		// ADO�ڑ�
		DM->ADOConnection->Connected = true;
	}catch (Exception& e){
		message_ = "�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message + "\r\n�ڑ��t�@�C���p�X�F" + DM->ADOConnection->ConnectionString;
		Application->MessageBox(message_.c_str(), "DB�G���[", MB_OK | MB_ICONSTOP);
		Close();
	}

	// NsConfig ������
	DM->config_.Load(&DM->DBI);

	// ���ږ��̐ݒ�
	SetItem();

	TokuisakiEditForm->StatusBar->Font->Size = 11;

	MainForm->Width  = 1024;
	MainForm->Height = 768;

	MainForm->Resize();

	PageControl->ActivePage = PageControl->Pages[0];
	PageControl->OnChange(PageControl);
	grid[page]->SetFocus();

	PageControl->OnChange(NULL);

	// �p�����[�^�ɂ��^�u�̕\���ؑ�
	if (ParamCount() < 1){
		try{
			// �e�[�u���I�[�v��
			for (int i = 0; i < page_count; i++)
				//OpenQuery(i);
				OpenQuery(i, "");
		}catch (Exception& e){
			message_ = "�e�[�u���I�[�v���Ɏ��s���܂���\r\n" + e.Message;
			Application->MessageBox(message_.c_str(), "DB�G���[", MB_OK | MB_ICONSTOP);
			Close();
		}

		// Printer�ݒ� //////////////////////////////////
		for (int i = 0; i < page_count; i++){
			if (report[i])
				SetPrinter(report[i], DM->INI["Printer::LaserPrinter"]);
		}
		/////////////////////////////////////////////////

		return;
	}

	TabSheet1->TabVisible   = false;
	TabSheet2->TabVisible   = false;
	TabSheet3->TabVisible   = false;
	TabSheet4->TabVisible   = false;
	TabSheet5->TabVisible   = false;
	TabSheet6->TabVisible   = false;
	TabSheet7->TabVisible   = false;
	TabSheet8->TabVisible   = false;
	TabSheet9->TabVisible   = false;
	TabSheet10->TabVisible  = false;
	TabSheet11->TabVisible  = false;
	TabSheet12->TabVisible  = false;
	TabSheet13->TabVisible  = false;
	TabSheet14->TabVisible  = false;
	TabSheet15->TabVisible  = false;
	TabSheet16->TabVisible  = false;
	TabSheet17->TabVisible  = false;

	switch (ParamStr(1).ToIntDef(0)){
	case 0:
		TabSheet1->TabVisible  = true;
		OpenQuery(0, "");
		SetPrinter(report[0], DM->INI["Printer::LaserPrinter"]);
		break;
	case 1:
		TabSheet2->TabVisible  = true;
		OpenQuery(1, "");
		SetPrinter(report[1], DM->INI["Printer::LaserPrinter"]);
		break;
	case 2:
		TabSheet3->TabVisible  = true;
		OpenQuery(2, "");
		SetPrinter(report[2], DM->INI["Printer::LaserPrinter"]);
		break;
	case 3:
		TabSheet4->TabVisible  = true;
		OpenQuery(3, "");
		SetPrinter(report[3], DM->INI["Printer::LaserPrinter"]);
		break;
	case 4:
		TabSheet5->TabVisible  = true;
		OpenQuery(4, "");
		SetPrinter(report[4], DM->INI["Printer::LaserPrinter"]);
		break;
	case 5:
		TabSheet6->TabVisible  = true;
		OpenQuery(5, "");
		SetPrinter(report[5], DM->INI["Printer::LaserPrinter"]);
		break;
	case 6:
		TabSheet7->TabVisible  = true;
		OpenQuery(6, "");
		SetPrinter(report[6], DM->INI["Printer::LaserPrinter"]);
		break;
	case 7:
		TabSheet8->TabVisible  = true;
		OpenQuery(7, "");
		SetPrinter(report[7], DM->INI["Printer::LaserPrinter"]);
		break;
	case 8:
		TabSheet9->TabVisible  = true;
		OpenQuery(8, "");
		SetPrinter(report[8], DM->INI["Printer::LaserPrinter"]);
		break;
	case 9:
		TabSheet10->TabVisible = true;
		OpenQuery(9, "");
		SetPrinter(report[9], DM->INI["Printer::LaserPrinter"]);
		break;
	case 10:
		TabSheet11->TabVisible = true;
		OpenQuery(10, "");
		SetPrinter(report[10], DM->INI["Printer::LaserPrinter"]);
		break;
	case 11:
		TabSheet12->TabVisible = true;
		OpenQuery(11, "");
		SetPrinter(report[11], DM->INI["Printer::LaserPrinter"]);
		break;
	case 12:
		TabSheet13->TabVisible = true;
		OpenQuery(12, "");
		SetPrinter(report[12], DM->INI["Printer::LaserPrinter"]);
		break;
    /*
	case 13:
		TabSheet14->TabVisible = true;
		OpenQuery(13);
		SetPrinter(report[13], DM->INI["Printer::LaserPrinter"]);
		break;
	case 14:
		TabSheet15->TabVisible = true;
		OpenQuery(14);
		SetPrinter(report[14], DM->INI["Printer::LaserPrinter"]);
		break;
    */
	case 15:
		TabSheet16->TabVisible = true;
		OpenQuery(15, "");
		SetPrinter(report[15], DM->INI["Printer::LaserPrinter"]);
		break;
	case 16:
		TabSheet17->TabVisible = true;
		OpenQuery(16, "");
		SetPrinter(report[16], DM->INI["Printer::LaserPrinter"]);
		break;
	}

	PageControl->OnChange(NULL);
}
//---------------------------------------------------------------------------
// �V�K
void __fastcall TMainForm::Action1Execute(TObject *Sender)
{
	if (page == 0){       // ���Ӑ�
		if (TokuisakiEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 1){ // ����1
		if (Item1EditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 2){ // ����2
		if (Item2EditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 3){ // �i�ڕ���
		if (HinBunruiEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 4){ // �i��
		if (HinmokuEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 5){ // �ԗ�
		if (SharyoEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 6){ // ���Z
		if (KanzanEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 7){ // ���_
		if (KyotenEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 8){ // �P��
		if (TaniEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 9){ // �P��
		if (TankaEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 10){ // �`�[���
		if (SlipInfoEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 11){ // �`�[���֘A
		if (SlipInfoRelateEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
        OpenQuery(10, ""); // 20100804 �`�[�����X�V�ł���悤�ɂ����̂�
                           // �}�X�^���X�V���Ă���
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 12){ // ��s
		if (BankEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
/*
	}else if (page == 13){ // �Ȗ�
		if (KamokuEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 14){ // �⏕��
		if (HojoboEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
*/
	}else if (page == 15){ // �����
		if (TaxEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 16){ // ���ڊ֘A
		if (ItemRelateEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}
}
//---------------------------------------------------------------------------
// �C��
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	if (query[page]->Bof && query[page]->Eof){
		Application->MessageBox("�C������f�[�^������܂���",
			"�C��", MB_OK | MB_ICONINFORMATION);
		return;
	}

	if (page == 0){       // ���Ӑ�
		if (TokuisakiEditForm->ShowModalWithId(query[page]->FieldByName("���Ӑ�ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 1){ // ����1
		if (Item1EditForm->ShowModalWithId(query[page]->FieldByName("����1ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 2){ // ����2
		if (Item2EditForm->ShowModalWithId(query[page]->FieldByName("����2ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 3){ // �i�ڕ���
		if (HinBunruiEditForm->ShowModalWithId(query[page]->FieldByName("�i�ڕ���ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 4){ // �i��
		if (HinmokuEditForm->ShowModalWithId(query[page]->FieldByName("�i��ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 5){ // �ԗ�
		if (SharyoEditForm->ShowModalWithId(query[page]->FieldByName("�ԗ�ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 6){ // ���Z
		if (KanzanEditForm->ShowModalWithId(query[page]->FieldByName("���ZID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 7){ // ���_
		if (KyotenEditForm->ShowModalWithId(query[page]->FieldByName("���_ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 8){ // �P��
		if (TaniEditForm->ShowModalWithId(query[page]->FieldByName("�P��ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 9){ // �P��
		if (TankaEditForm->ShowModalWithId(query[page]->FieldByName("�P��ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 10){ // �`�[���
		if (SlipInfoEditForm->ShowModalWithId(query[page]->FieldByName("�`�[���ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 11){ // �`�[���֘A
		if (SlipInfoRelateEditForm->ShowModalWithId(query[page]->FieldByName("�`�[���֘AID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
        OpenQuery(10, ""); // 20100804 �`�[�����X�V�ł���悤�ɂ����̂�
                           // �}�X�^���X�V���Ă���
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 12){ // ��s
		if (BankEditForm->ShowModalWithId(query[page]->FieldByName("��sID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
/*
	}else if (page == 13){ // �Ȗ�
		if (KamokuEditForm->ShowModalWithId(query[page]->FieldByName("�Ȗ�ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 14){ // �⏕��
		if (HojoboEditForm->ShowModalWithId(query[page]->FieldByName("�⏕��ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
*/
	}else if (page == 15){ // �����
		if (TaxEditForm->ShowModalWithId(query[page]->FieldByName("�J�n���t")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 16){ // ���ڊ֘A
		if (ItemRelateEditForm->ShowModalWithId(query[page]->FieldByName("���ڊ֘AID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}
}
//---------------------------------------------------------------------------
// �폜
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
	NsFieldSet fields, keys;
	try{
        if (page == 10){ // �`�[���}�X�^
            int slipinfo_id = query[page]->FieldByName("�`�[���ID")->AsInteger;

            if (slipinfo_id == 1){
                Application->MessageBox("���̃f�[�^�͍폜�ł��܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
                return;
            }
        }

        if (page == 11){ // �`�[���֘A�}�X�^
            int item_no     = query[page]->FieldByName("���ڔԍ�")->AsInteger;
            int item_id     = query[page]->FieldByName("����ID")->AsInteger;
            int slipinfo_id = query[page]->FieldByName("�`�[���ID")->AsInteger;

            if (item_no == 0 && item_id == 0 && slipinfo_id == 1){
                Application->MessageBox("���̃f�[�^�͍폜�ł��܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
                return;
            }
        }

        //if (page == 6 || page == 7 || page == 8 || page == 9){ // ���Z�E���_�E�P�ʁE�P���̎�
        if (page >= 6){ //////// ���Z�E���_�E�P�ʁE�P���̎�

            if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H", "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
                return;

            if (grid[page]->SelectedRows->Count == 0){
                // �P���폜
                keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
                DM->DBI.Delete(table_name_[page], keys);
            }else{
                // �����폜
                for (int count = 0; count < grid[page]->SelectedRows->Count; count++){
                    grid[page]->DataSource->DataSet->GotoBookmark((void *)grid[page]->SelectedRows->Items[count].c_str());

                    keys.clear();
                    keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
                    DM->DBI.Delete(table_name_[page], keys);
                }
            }
            Application->MessageBox("�폜���܂���", "�폜", MB_OK | MB_ICONINFORMATION);

        }else{      //////// ���̑��}�X�^�̎�

            if (query[page]->FieldByName("�g�p�敪")->AsInteger == 1){
                if (Application->MessageBox("���̃f�[�^���g�p�o���Ȃ��Ȃ�܂��B��낵���ł����H\r\n�Ȃ��A�{���ɍ폜����ꍇ�͈�x���̏������s�Ȃ�����\r\n������x�폜�{�^�����N���b�N���ĉ�����",
					"�폜", MB_YESNO | MB_ICONQUESTION) == IDNO)
					return;
				if (grid[page]->SelectedRows->Count == 0){
					try{
						fields << NsField("[�g�p�敪]", 0);
						DM->DBI.Update(table_name_[page], keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger, fields);
					}catch (Exception &e){
						Application->MessageBox(("�X�V�Ɏ��s���܂���\r\n" + e.Message).c_str(),
							"�폜", MB_OK | MB_ICONINFORMATION);
						return;
					}
				}else{
					for (int count = 0; count < grid[page]->SelectedRows->Count; count++){
						grid[page]->DataSource->DataSet->GotoBookmark((void *)grid[page]->SelectedRows->Items[count].c_str());

						fields.clear();
						fields << NsField("[�g�p�敪]", 0);
						DM->DBI.Update(table_name_[page], keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger, fields);
					}
				}
				Application->MessageBox("�g�p�敪��ύX���܂���\r\n�ēx�g�p����ۂɂ͎g�p�敪��ύX���ĉ�����",
					"�폜", MB_OK | MB_ICONINFORMATION);
			}else{
				if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H",
					"�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
					return;
				if (grid[page]->SelectedRows->Count == 0){
					// �P���폜
					keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
					DM->DBI.Delete(table_name_[page], keys);

                    // ���Ӑ�A����1�A����2�A�i�ڃ}�X�^�̂ݏ���
                    if (page == 0 || page == 1 || page == 2 || page == 4)
                        DM->DeleteRelateMaster(page, keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
				}else{
					// �����폜
					for (int count = 0; count < grid[page]->SelectedRows->Count; count++){
						grid[page]->DataSource->DataSet->GotoBookmark((void *)grid[page]->SelectedRows->Items[count].c_str());

						keys.clear();
						keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
						DM->DBI.Delete(table_name_[page], keys);

                        // ���Ӑ�A����1�A����2�A�i�ڃ}�X�^�̂ݏ���
                        if (page == 0 || page == 1 || page == 2 || page == 4)
                            DM->DeleteRelateMaster(page, keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
                    }
				}
			    Application->MessageBox("�폜���܂���", "�폜", MB_OK | MB_ICONINFORMATION);
			}
		}
	}catch (Exception &e){
		Application->MessageBox(("�폜�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
	}
	OpenQuery(page, "");
}
//---------------------------------------------------------------------------
// �Q��
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
	if (grid[page]->SelectedField->FieldKind != fkLookup)
		return;
	if (grid[page]->SelectedField->ReadOnly)
		return;
	if (!grid[page]->EditorMode)
		grid[page]->EditorMode = true;
	grid[page]->SetFocus();
	keybd_event(VK_MENU, 0, 0, 0);
	keybd_event(VK_DOWN, 0, 0, 0);
	keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
// �\�[�g�ݒ�
void __fastcall TMainForm::Action7Execute(TObject *Sender)
{
    SortSetForm->grid_ = grid[page];

    int value;

    value = SortSetForm->ShowModal();

    if (value == mrNo)
        return;

    order_ = SortSetForm->orderby_sql;

    OpenQuery(page, order_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action8Execute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
// ���
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (Application->MessageBox("������܂����H", "���", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	if (report[page] == NULL)
		return;
	report[page]->Print();
}
//---------------------------------------------------------------------------
// �v���r���[
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (report[page] == NULL)
		return;
	report[page]->Preview();
}
//---------------------------------------------------------------------------
// �o��
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (Application->MessageBox("�o�͂��܂����H", "�o��", MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;
	if (query[page]->Bof && query[page]->Eof){
		Application->MessageBox("�f�[�^������܂���", "�o�͏���", MB_OK | MB_ICONINFORMATION);
		return;
	}

	std::auto_ptr<TStringList> Records(new TStringList());
	Table2Str(query[page], Records.get(), true);
	SaveDialog->FileName = master_name_[page] + "_" + Date().FormatString("yyyymmdd") + ".csv";
	if (SaveDialog->Execute()){
		Records->SaveToFile(SaveDialog->FileName);
		Application->MessageBox("�������܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}else{
		Application->MessageBox("�L�����Z������܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------
// �I��
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
// PageControl->OnChange
void __fastcall TMainForm::PageControlChange(TObject *Sender)
{
	page   = PageControl->ActivePageIndex;
	order_ = AnsiString();
	SetPageInfo(page);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGrid1CellClick(TColumn *Column)
{
    Application->OnMessage = this->MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGrid1DblClick(TObject *Sender)
{
    Action2->OnExecute(NULL);
}
//---------------------------------------------------------------------------
// ���ڃ\�[�g�͎����������Ȃ�
void __fastcall TMainForm::DBGrid1TitleClick(TColumn *Column)
{
    //
}
//---------------------------------------------------------------------------
// Window���T�C�Y
void __fastcall TMainForm::FormResize(TObject *Sender)
{
	//PageControl->TabWidth = int(MainForm->Width / PageControl->PageCount) - 6;

	int interval  = 10;
	btnF1->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF2->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF3->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF4->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF5->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF6->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF7->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF8->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF9->Width  = int((MainForm->Width - interval * 4) / 12);
	btnF10->Width = int((MainForm->Width - interval * 4) / 12);
	btnF11->Width = int((MainForm->Width - interval * 4) / 12);
	btnF12->Width = int((MainForm->Width - interval * 4) / 12);

	btnF1->Left  = interval;
	btnF2->Left  = btnF1->Left + btnF1->Width - 1;
	btnF3->Left  = btnF2->Left + btnF2->Width - 1;
	btnF4->Left  = btnF3->Left + btnF3->Width - 1;
	btnF5->Left  = btnF4->Left + btnF4->Width - 1 + interval;
	btnF6->Left  = btnF5->Left + btnF5->Width - 1;
	btnF7->Left  = btnF6->Left + btnF6->Width - 1;
	btnF8->Left  = btnF7->Left + btnF7->Width - 1;
	btnF9->Left  = btnF8->Left + btnF8->Width - 1 + interval;
	btnF10->Left = btnF9->Left + btnF9->Width - 1;
	btnF11->Left = btnF10->Left + btnF10->Width - 1;
	btnF12->Left = btnF11->Left + btnF11->Width - 1;
}
//---------------------------------------------------------------------------
// �O�̃^�u
void __fastcall TMainForm::PagePriorExecute(TObject *Sender)
{
	if (PageControl->ActivePageIndex == 0)
		PageControl->ActivePageIndex = PageControl->PageCount - 1;
	else
		PageControl->ActivePageIndex--;
	PageControl->OnChange(PageControl);
}
//---------------------------------------------------------------------------
// ���̃^�u
void __fastcall TMainForm::PageNextExecute(TObject *Sender)
{
	if (PageControl->ActivePageIndex == PageControl->PageCount - 1)
		PageControl->ActivePageIndex = 0;
	else
		PageControl->ActivePageIndex++;
	PageControl->OnChange(PageControl);
}
//---------------------------------------------------------------------------
// MainForm->OnKeyDown
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Shift.Contains(ssCtrl) && Key == VK_PRIOR)
		PagePrior->Execute();
	if (Shift.Contains(ssCtrl) && Key == VK_NEXT)
		PageNext->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	if (grid[page] == NULL)
		return;

	switch(Msg.message){
		case WM_MOUSEWHEEL:
		if(Msg.hwnd == grid[page]->Handle){
			//�z�C�[���}�E�X�̃C�x���g�ŏ㉺�ɓ����悤�ɐݒ�
			if((short)HIWORD(Msg.wParam) > 0){
				grid[page]->DataSource->DataSet->Prior();
			}else{
				grid[page]->DataSource->DataSet->Next();
			}
			//�����͂����ŃX�g�b�v������
			Handled = true;
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SearchEdit1KeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	OpenQuery(page, order_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OpenQuery(int p, AnsiString order)
{
    if (!query[p])
        return;

	TBookmark save_place;
	save_place = query[p]->GetBookmark();
	query[p]->Close();

	switch (p){
	case 0:  // ���Ӑ�
		query[p]->SQL->Text = DM->GetTokuisakiQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 1:  // ����1
		query[p]->SQL->Text = DM->GetItem1Query(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 2:  // ����2
		query[p]->SQL->Text = DM->GetItem2Query(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 3:  // �i�ڕ���
		query[p]->SQL->Text = DM->GetHinBunruiQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 4:  // �i��
		query[p]->SQL->Text = DM->GetHinmokuQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 5:  // �ԗ�
		query[p]->SQL->Text = DM->GetSharyoQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 6:  // ���Z
		query[p]->SQL->Text = DM->GetKanzanQuery(search_edit[p]->Text, order);
		break;
	case 7:  // ���_
		query[p]->SQL->Text = DM->GetKyotenQuery(search_edit[p]->Text, order);
		break;
	case 8:  // �P��
		query[p]->SQL->Text = DM->GetTaniQuery(search_edit[p]->Text, order);
		break;
	case 9:  // �P��
		query[p]->SQL->Text = DM->GetTankaQuery(search_edit[p]->Text, order);
		break;
	case 10:  // �`�[���
		query[p]->SQL->Text = DM->GetSlipInfoQuery(search_edit[p]->Text, order);
		break;
	case 11:  // �`�[���֘A
		query[p]->SQL->Text = DM->GetSlipInfoRelateQuery(search_edit[p]->Text, order);
		break;
	case 12:  // ��s
		query[p]->SQL->Text = DM->GetBankQuery(search_edit[p]->Text, order);
		break;
/*
	case 13:  // �Ȗ�
		query[p]->SQL->Text = DM->GetKamokuQuery(search_edit[p]->Text, order);
		break;
	case 14:  // �⏕��
		query[p]->SQL->Text = DM->GetHojoboQuery(search_edit[p]->Text, order);
		break;
*/
	case 15:  // �����
		query[p]->SQL->Text = DM->GetTaxQuery(search_edit[p]->Text, order);
		break;
	case 16:  // ���ڊ֘A
		query[p]->SQL->Text = DM->GetItemRelateQuery(search_edit[p]->Text, order);
		break;
	}

	query[p]->Open();
	try{
		query[p]->GotoBookmark(save_place);
	}catch(...){}
	query[p]->FreeBookmark(save_place);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AllDataShowCheckBox1Click(TObject *Sender)
{
	OpenQuery(page, order_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetItem()
{
	// ���Ӑ�
	AnsiString toku = AnsiReplaceStr(ToString(DM->config_["���Ӑ�}�X�^����"]), " ", "");
	toku = AnsiReplaceStr(toku, "�@", "");
	toku_ = toku;
	if (ToString(DM->config_["���Ӑ�}�X�^�g�p�敪"]) == "1"){
		TabSheet1->Caption = ToString(DM->config_["���Ӑ�}�X�^����"]);
		DBGrid1->Columns->Items[0]->Title->Caption  = toku + "�R�[�h";
		DBGrid1->Columns->Items[1]->Title->Caption  = toku + "����";
		DBGrid1->Columns->Items[2]->Title->Caption  = toku + "����";
		DBGrid1->Columns->Items[3]->Title->Caption  = toku + "�J�i";
		DBGrid6->Columns->Items[6]->Title->Caption  = toku + "����";
		DBGrid7->Columns->Items[1]->Title->Caption  = toku + "����";
		DBGrid10->Columns->Items[1]->Title->Caption = toku + "����";
		DBGrid17->Columns->Items[4]->Title->Caption = toku + "�R�[�h";
		DBGrid17->Columns->Items[5]->Title->Caption = toku + "����";

		TokuisakiEditForm->Caption = toku + "�o�^�^�C��";
		QRTokuisakiForm->TitleLabel->Caption = toku + "�}�X�^�ꗗ";
		QRSharyoForm->TokuisakiLabel->Caption = toku;
		QRKanzanForm->TokuisakiLabel->Caption = toku;
		QRTankaForm->TokuisakiLabel->Caption = toku;
		KanzanEditForm->TokuisakiLabel->Caption = toku;
		SharyoEditForm->TokuisakiLabel->Caption = toku;
		TankaEditForm->TokuisakiLabel->Caption  = toku;
        ItemRelateEditForm->TokuisakiLabel->Caption = toku;
        QRItemRelateForm->TokuisakiNameLabel->Caption = toku;

		DM->M_Tokuisaki->Fields->Fields[0]->DisplayLabel = toku + "ID";
		DM->M_Tokuisaki->Fields->Fields[1]->DisplayLabel = toku + "�R�[�h";
		DM->M_Tokuisaki->Fields->Fields[2]->DisplayLabel = toku + "����";
		DM->M_Tokuisaki->Fields->Fields[3]->DisplayLabel = toku + "����";
		DM->M_Tokuisaki->Fields->Fields[4]->DisplayLabel = toku + "�J�i";

		DM->M_Sharyo->Fields->Fields[6]->DisplayLabel = toku + "ID";
		DM->M_Sharyo->Fields->Fields[7]->DisplayLabel = toku + "�R�[�h";
		DM->M_Sharyo->Fields->Fields[8]->DisplayLabel = toku + "����";
		DM->M_Sharyo->Fields->Fields[9]->DisplayLabel = toku + "����";

		DM->M_Kanzan->Fields->Fields[1]->DisplayLabel = toku + "ID";
		DM->M_Kanzan->Fields->Fields[2]->DisplayLabel = toku + "�R�[�h";
		DM->M_Kanzan->Fields->Fields[3]->DisplayLabel = toku + "����";
		DM->M_Kanzan->Fields->Fields[4]->DisplayLabel = toku + "����";

		DM->M_Tanka->Fields->Fields[1]->DisplayLabel = toku + "ID";
		DM->M_Tanka->Fields->Fields[2]->DisplayLabel = toku + "�R�[�h";
		DM->M_Tanka->Fields->Fields[3]->DisplayLabel = toku + "����";
		DM->M_Tanka->Fields->Fields[4]->DisplayLabel = toku + "����";

        DM->M_ItemRelate->Fields->Fields[7]->DisplayLabel  = toku + "ID";
        DM->M_ItemRelate->Fields->Fields[8]->DisplayLabel  = toku + "�R�[�h";
        DM->M_ItemRelate->Fields->Fields[9]->DisplayLabel  = toku + "����";
        DM->M_ItemRelate->Fields->Fields[10]->DisplayLabel = toku + "����";
	}else{
		TabSheet1->Caption = "���g�p";
		DBGrid1->Columns->Items[0]->Title->Caption  = "���g�p";
		DBGrid1->Columns->Items[1]->Title->Caption  = "���g�p";
		DBGrid1->Columns->Items[2]->Title->Caption  = "���g�p";
		DBGrid1->Columns->Items[3]->Title->Caption  = "���g�p";
		DBGrid6->Columns->Items[6]->Title->Caption  = "���g�p";
		DBGrid7->Columns->Items[1]->Title->Caption  = "���g�p";
		DBGrid10->Columns->Items[1]->Title->Caption = "���g�p";
        DBGrid17->Columns->Items[4]->Title->Caption = "���g�p";
        DBGrid17->Columns->Items[5]->Title->Caption = "���g�p";

		TokuisakiEditForm->Caption                = "���g�p";
		QRTokuisakiForm->TitleLabel->Caption      = "���g�p";
		QRSharyoForm->TokuisakiLabel->Caption     = "���g�p";
		QRKanzanForm->TokuisakiLabel->Caption     = "���g�p";
		QRTankaForm->TokuisakiLabel->Caption      = "���g�p";
		KanzanEditForm->TokuisakiLabel->Caption   = "���g�p";
		SharyoEditForm->TokuisakiLabel->Caption   = "���g�p";
		TankaEditForm->TokuisakiLabel->Caption    = "���g�p";
        ItemRelateEditForm->TokuisakiLabel->Caption   = "���g�p";
        QRItemRelateForm->TokuisakiNameLabel->Caption = "���g�p";

		DM->M_Tokuisaki->Fields->Fields[0]->DisplayLabel = "���g�p";
		DM->M_Tokuisaki->Fields->Fields[1]->DisplayLabel = "���g�p";
		DM->M_Tokuisaki->Fields->Fields[2]->DisplayLabel = "���g�p";
		DM->M_Tokuisaki->Fields->Fields[3]->DisplayLabel = "���g�p";
		DM->M_Tokuisaki->Fields->Fields[4]->DisplayLabel = "���g�p";

		DM->M_Sharyo->Fields->Fields[6]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[7]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[8]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[9]->DisplayLabel = "���g�p";

		DM->M_Kanzan->Fields->Fields[1]->DisplayLabel = "���g�p";
		DM->M_Kanzan->Fields->Fields[2]->DisplayLabel = "���g�p";
		DM->M_Kanzan->Fields->Fields[3]->DisplayLabel = "���g�p";
		DM->M_Kanzan->Fields->Fields[4]->DisplayLabel = "���g�p";

		DM->M_Tanka->Fields->Fields[1]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[2]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[3]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[4]->DisplayLabel = "���g�p";

        DM->M_ItemRelate->Fields->Fields[7]->DisplayLabel  = "���g�p";
        DM->M_ItemRelate->Fields->Fields[8]->DisplayLabel  = "���g�p";
        DM->M_ItemRelate->Fields->Fields[9]->DisplayLabel  = "���g�p";
        DM->M_ItemRelate->Fields->Fields[10]->DisplayLabel = "���g�p";
	}

	// ����1
	AnsiString item1 = AnsiReplaceStr(ToString(DM->config_["����1�}�X�^����"]), " ", "");
	item1 = AnsiReplaceStr(item1, "�@", "");
    item1_= item1;
	if (ToString(DM->config_["����1�}�X�^�g�p�敪"]) == "1"){
		TabSheet2->Caption = ToString(DM->config_["����1�}�X�^����"]);
		DBGrid2->Columns->Items[0]->Title->Caption  = item1 + "�R�[�h";
		DBGrid2->Columns->Items[1]->Title->Caption  = item1 + "����";
		DBGrid2->Columns->Items[2]->Title->Caption  = item1 + "����";
		DBGrid2->Columns->Items[3]->Title->Caption  = item1 + "�J�i";
		DBGrid6->Columns->Items[8]->Title->Caption  = item1 + "����";
		DBGrid10->Columns->Items[5]->Title->Caption = item1 + "����";
        DBGrid17->Columns->Items[6]->Title->Caption = item1 + "�R�[�h";
        DBGrid17->Columns->Items[7]->Title->Caption = item1 + "����";

		Item1EditForm->Caption = item1 + "�o�^�^�C��";
		QRItem1Form->TitleLabel->Caption = item1 + "�}�X�^�ꗗ";
		QRSharyoForm->Item1Label->Caption = item1;
		QRTankaForm->Item1Label->Caption = item1;
		SharyoEditForm->Item1Label->Caption = item1;
		TankaEditForm->Item1Label->Caption  = item1;
        ItemRelateEditForm->Item1Label->Caption = item1;
        QRItemRelateForm->Item1NameLabel->Caption = item1;

		DM->M_Item1->Fields->Fields[0]->DisplayLabel = item1 + "ID";
		DM->M_Item1->Fields->Fields[1]->DisplayLabel = item1 + "�R�[�h";
		DM->M_Item1->Fields->Fields[2]->DisplayLabel = item1 + "����";
		DM->M_Item1->Fields->Fields[3]->DisplayLabel = item1 + "����";
		DM->M_Item1->Fields->Fields[4]->DisplayLabel = item1 + "�J�i";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = item1 + "ID";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = item1 + "�R�[�h";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = item1 + "����";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = item1 + "����";

		DM->M_Tanka->Fields->Fields[9]->DisplayLabel  = item1 + "ID";
		DM->M_Tanka->Fields->Fields[10]->DisplayLabel = item1 + "�R�[�h";
		DM->M_Tanka->Fields->Fields[11]->DisplayLabel = item1 + "����";
		DM->M_Tanka->Fields->Fields[12]->DisplayLabel = item1 + "����";

        DM->M_ItemRelate->Fields->Fields[11]->DisplayLabel = item1 + "ID";
        DM->M_ItemRelate->Fields->Fields[12]->DisplayLabel = item1 + "�R�[�h";
        DM->M_ItemRelate->Fields->Fields[13]->DisplayLabel = item1 + "����";
        DM->M_ItemRelate->Fields->Fields[14]->DisplayLabel = item1 + "����";
	}else{
		TabSheet2->Caption = "���g�p";
		DBGrid2->Columns->Items[0]->Title->Caption  = "���g�p";
		DBGrid2->Columns->Items[1]->Title->Caption  = "���g�p";
		DBGrid2->Columns->Items[2]->Title->Caption  = "���g�p";
		DBGrid2->Columns->Items[3]->Title->Caption  = "���g�p";
		DBGrid6->Columns->Items[8]->Title->Caption  = "���g�p";
		DBGrid10->Columns->Items[5]->Title->Caption = "���g�p";
        DBGrid17->Columns->Items[6]->Title->Caption = "���g�p";
        DBGrid17->Columns->Items[7]->Title->Caption = "���g�p";

		Item1EditForm->Caption = "���g�p";
		QRItem1Form->TitleLabel->Caption = "���g�p";
		QRSharyoForm->Item1Label->Caption = "���g�p";
		QRTankaForm->Item1Label->Caption = "���g�p";
		SharyoEditForm->Item1Label->Caption = "���g�p";
		TankaEditForm->Item1Label->Caption  = "���g�p";
        ItemRelateEditForm->Item1Label->Caption = "���g�p";
        QRItemRelateForm->Item1NameLabel->Caption = "���g�p";

		DM->M_Item1->Fields->Fields[0]->DisplayLabel = "���g�p";
		DM->M_Item1->Fields->Fields[1]->DisplayLabel = "���g�p";
		DM->M_Item1->Fields->Fields[2]->DisplayLabel = "���g�p";
		DM->M_Item1->Fields->Fields[3]->DisplayLabel = "���g�p";
		DM->M_Item1->Fields->Fields[4]->DisplayLabel = "���g�p";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = "���g�p";

		DM->M_Tanka->Fields->Fields[9]->DisplayLabel  = "���g�p";
		DM->M_Tanka->Fields->Fields[10]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[11]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[12]->DisplayLabel = "���g�p";

        DM->M_ItemRelate->Fields->Fields[11]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[12]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[13]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[14]->DisplayLabel = "���g�p";
	}

	// ����2
	AnsiString item2 = AnsiReplaceStr(ToString(DM->config_["����2�}�X�^����"]), " ", "");
	item2 = AnsiReplaceStr(item2, "�@", "");
      item2_ = item2;
	if (ToString(DM->config_["����2�}�X�^�g�p�敪"]) == "1"){
		TabSheet3->Caption = ToString(DM->config_["����2�}�X�^����"]);
		DBGrid3->Columns->Items[0]->Title->Caption  = item2 + "�R�[�h";
		DBGrid3->Columns->Items[1]->Title->Caption  = item2 + "����";
		DBGrid3->Columns->Items[2]->Title->Caption  = item2 + "����";
		DBGrid3->Columns->Items[3]->Title->Caption  = item2 + "�J�i";
		DBGrid6->Columns->Items[10]->Title->Caption = item2 + "����";
		DBGrid10->Columns->Items[7]->Title->Caption = item2 + "����";
        DBGrid17->Columns->Items[8]->Title->Caption = item2 + "�R�[�h";
        DBGrid17->Columns->Items[9]->Title->Caption = item2 + "����";

		Item2EditForm->Caption = item2 + "�o�^�^�C��";
		QRItem2Form->TitleLabel->Caption = item2 + "�}�X�^�ꗗ";
		QRSharyoForm->Item2Label->Caption = item2;
		QRTankaForm->Item2Label->Caption = item2;
		SharyoEditForm->Item2Label->Caption = item2;
		TankaEditForm->Item2Label->Caption  = item2;
        ItemRelateEditForm->Item2Label->Caption = item2;
        QRItemRelateForm->Item2NameLabel->Caption = item2;

		DM->M_Item2->Fields->Fields[0]->DisplayLabel = item2 + "ID";
		DM->M_Item2->Fields->Fields[1]->DisplayLabel = item2 + "�R�[�h";
		DM->M_Item2->Fields->Fields[2]->DisplayLabel = item2 + "����";
		DM->M_Item2->Fields->Fields[3]->DisplayLabel = item2 + "����";
		DM->M_Item2->Fields->Fields[4]->DisplayLabel = item2 + "�J�i";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = item2 + "ID";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = item2 + "�R�[�h";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = item2 + "����";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = item2 + "����";

		DM->M_Tanka->Fields->Fields[13]->DisplayLabel = item2 + "ID";
		DM->M_Tanka->Fields->Fields[14]->DisplayLabel = item2 + "�R�[�h";
		DM->M_Tanka->Fields->Fields[15]->DisplayLabel = item2 + "����";
		DM->M_Tanka->Fields->Fields[16]->DisplayLabel = item2 + "����";

        DM->M_ItemRelate->Fields->Fields[15]->DisplayLabel = item2 + "ID";
        DM->M_ItemRelate->Fields->Fields[16]->DisplayLabel = item2 + "�R�[�h";
        DM->M_ItemRelate->Fields->Fields[17]->DisplayLabel = item2 + "����";
        DM->M_ItemRelate->Fields->Fields[18]->DisplayLabel = item2 + "����";
	}else{
		TabSheet3->Caption = "���g�p";
		DBGrid3->Columns->Items[0]->Title->Caption = "���g�p";
		DBGrid3->Columns->Items[1]->Title->Caption = "���g�p";
		DBGrid3->Columns->Items[2]->Title->Caption = "���g�p";
		DBGrid3->Columns->Items[3]->Title->Caption = "���g�p";
		DBGrid6->Columns->Items[10]->Title->Caption = "���g�p";
		DBGrid10->Columns->Items[7]->Title->Caption = "���g�p";
        DBGrid17->Columns->Items[8]->Title->Caption = "���g�p";
        DBGrid17->Columns->Items[9]->Title->Caption = "���g�p";

		Item2EditForm->Caption = "���g�p";
		QRItem2Form->TitleLabel->Caption = "���g�p";
		QRSharyoForm->Item2Label->Caption = "���g�p";
		QRTankaForm->Item2Label->Caption = "���g�p";
		SharyoEditForm->Item2Label->Caption = "���g�p";
		TankaEditForm->Item2Label->Caption  = "���g�p";
        ItemRelateEditForm->Item2Label->Caption = "���g�p";
        QRItemRelateForm->Item2NameLabel->Caption = "���g�p";

		DM->M_Item2->Fields->Fields[0]->DisplayLabel = "���g�p";
		DM->M_Item2->Fields->Fields[1]->DisplayLabel = "���g�p";
		DM->M_Item2->Fields->Fields[2]->DisplayLabel = "���g�p";
		DM->M_Item2->Fields->Fields[3]->DisplayLabel = "���g�p";
		DM->M_Item2->Fields->Fields[4]->DisplayLabel = "���g�p";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = "���g�p";

		DM->M_Tanka->Fields->Fields[13]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[14]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[15]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[16]->DisplayLabel = "���g�p";

        DM->M_ItemRelate->Fields->Fields[15]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[16]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[17]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[18]->DisplayLabel = "���g�p";
	}

	// �i�ڕ���
	AnsiString hinbun = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]), " ", "");
	hinbun = AnsiReplaceStr(hinbun, "�@", "");
      hinbun_ = hinbun;
	if (ToString(DM->config_["�i�ڃ}�X�^�g�p�敪"]) == "1"){
		TabSheet4->Caption = hinbun + "����";
		DBGrid4->Columns->Items[0]->Title->Caption = hinbun + "���ރR�[�h";
		DBGrid4->Columns->Items[1]->Title->Caption = hinbun + "���ޖ���";
		DBGrid4->Columns->Items[2]->Title->Caption = hinbun + "���ޗ���";
		DBGrid4->Columns->Items[3]->Title->Caption = hinbun + "���ރJ�i";
		DBGrid5->Columns->Items[7]->Title->Caption = hinbun + "����";

		HinBunruiEditForm->Caption = hinbun + "���ޓo�^�^�C��";
		QRHinBunruiForm->TitleLabel->Caption = hinbun + "���ރ}�X�^�ꗗ";
		QRHinmokuForm->HinBunruiLabel->Caption = hinbun + "����";
		HinmokuEditForm->HinBunruiLabel->Caption = hinbun + "����";

		DM->M_HinBunrui->Fields->Fields[0]->DisplayLabel = hinbun + "����ID";
		DM->M_HinBunrui->Fields->Fields[1]->DisplayLabel = hinbun + "���ރR�[�h";
		DM->M_HinBunrui->Fields->Fields[2]->DisplayLabel = hinbun + "���ޖ���";
		DM->M_HinBunrui->Fields->Fields[3]->DisplayLabel = hinbun + "���ޗ���";
		DM->M_HinBunrui->Fields->Fields[4]->DisplayLabel = hinbun + "���ރJ�i";

		DM->M_Hinmoku->Fields->Fields[7]->DisplayLabel = hinbun + "����ID";
		DM->M_Hinmoku->Fields->Fields[8]->DisplayLabel = hinbun + "���ރR�[�h";
		DM->M_Hinmoku->Fields->Fields[9]->DisplayLabel = hinbun + "���ޖ���";
		DM->M_Hinmoku->Fields->Fields[10]->DisplayLabel = hinbun + "���ޗ���";
	}else{
		TabSheet4->Caption = "���g�p";
		DBGrid4->Columns->Items[0]->Title->Caption = "���g�p";
		DBGrid4->Columns->Items[1]->Title->Caption = "���g�p";
		DBGrid4->Columns->Items[2]->Title->Caption = "���g�p";
		DBGrid4->Columns->Items[3]->Title->Caption = "���g�p";
		DBGrid5->Columns->Items[7]->Title->Caption = "���g�p";

		HinBunruiEditForm->Caption = "���g�p";
		QRHinBunruiForm->TitleLabel->Caption = "���g�p";
		QRHinmokuForm->HinBunruiLabel->Caption = "���g�p";
		HinmokuEditForm->HinBunruiLabel->Caption = "���g�p";

		DM->M_HinBunrui->Fields->Fields[0]->DisplayLabel = "���g�p";
		DM->M_HinBunrui->Fields->Fields[1]->DisplayLabel = "���g�p";
		DM->M_HinBunrui->Fields->Fields[2]->DisplayLabel = "���g�p";
		DM->M_HinBunrui->Fields->Fields[3]->DisplayLabel = "���g�p";
		DM->M_HinBunrui->Fields->Fields[4]->DisplayLabel = "���g�p";

		DM->M_Hinmoku->Fields->Fields[7]->DisplayLabel = "���g�p";
		DM->M_Hinmoku->Fields->Fields[8]->DisplayLabel = "���g�p";
		DM->M_Hinmoku->Fields->Fields[9]->DisplayLabel = "���g�p";
		DM->M_Hinmoku->Fields->Fields[10]->DisplayLabel = "���g�p";
	}

	// �i��
	AnsiString hin = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]), " ", "");
	hin  = AnsiReplaceStr(hin, "�@", "");
    hin_ = hin;
	if (ToString(DM->config_["�i�ڃ}�X�^�g�p�敪"]) == "1"){
		TabSheet5->Caption = ToString(DM->config_["�i�ڃ}�X�^����"]);
		DBGrid5->Columns->Items[0]->Title->Caption   = hin + "�R�[�h";
		DBGrid5->Columns->Items[1]->Title->Caption   = hin + "����";
		DBGrid5->Columns->Items[2]->Title->Caption   = hin + "����";
		DBGrid5->Columns->Items[3]->Title->Caption   = hin + "�J�i";
		DBGrid6->Columns->Items[12]->Title->Caption  = hin + "����";
		DBGrid7->Columns->Items[3]->Title->Caption   = hin + "����";
		DBGrid10->Columns->Items[3]->Title->Caption  = hin + "����";
        DBGrid17->Columns->Items[10]->Title->Caption = hin + "�R�[�h";
        DBGrid17->Columns->Items[11]->Title->Caption = hin + "����";

		HinmokuEditForm->Caption = hin + "�o�^�^�C��";
		QRHinmokuForm->TitleLabel->Caption = hin + "�}�X�^�ꗗ";
		QRSharyoForm->HinmokuLabel->Caption = hin;
		QRKanzanForm->HinmokuLabel->Caption = hin;
		QRTankaForm->HinmokuLabel->Caption = hin;
		KanzanEditForm->HinmokuLabel->Caption = hin;
		SharyoEditForm->HinmokuLabel->Caption = hin;
		TankaEditForm->HinmokuLabel->Caption  = hin;
        ItemRelateEditForm->HinmokuLabel->Caption = hin;
        QRItemRelateForm->HinmokuNameLabel->Caption = hin;

		DM->M_Hinmoku->Fields->Fields[0]->DisplayLabel = hin + "ID";
		DM->M_Hinmoku->Fields->Fields[1]->DisplayLabel = hin + "�R�[�h";
		DM->M_Hinmoku->Fields->Fields[2]->DisplayLabel = hin + "����";
		DM->M_Hinmoku->Fields->Fields[3]->DisplayLabel = hin + "����";
		DM->M_Hinmoku->Fields->Fields[4]->DisplayLabel = hin + "�J�i";

		DM->M_Sharyo->Fields->Fields[18]->DisplayLabel = hin + "ID";
		DM->M_Sharyo->Fields->Fields[19]->DisplayLabel = hin + "�R�[�h";
		DM->M_Sharyo->Fields->Fields[20]->DisplayLabel = hin + "����";
		DM->M_Sharyo->Fields->Fields[21]->DisplayLabel = hin + "����";

		DM->M_Kanzan->Fields->Fields[5]->DisplayLabel = hin + "ID";
		DM->M_Kanzan->Fields->Fields[6]->DisplayLabel = hin + "�R�[�h";
		DM->M_Kanzan->Fields->Fields[7]->DisplayLabel = hin + "����";
		DM->M_Kanzan->Fields->Fields[8]->DisplayLabel = hin + "����";

		DM->M_Tanka->Fields->Fields[5]->DisplayLabel = hin + "ID";
		DM->M_Tanka->Fields->Fields[6]->DisplayLabel = hin + "�R�[�h";
		DM->M_Tanka->Fields->Fields[7]->DisplayLabel = hin + "����";
		DM->M_Tanka->Fields->Fields[8]->DisplayLabel = hin + "����";

        DM->M_ItemRelate->Fields->Fields[19]->DisplayLabel = hin + "ID";
        DM->M_ItemRelate->Fields->Fields[20]->DisplayLabel = hin + "�R�[�h";
        DM->M_ItemRelate->Fields->Fields[21]->DisplayLabel = hin + "����";
        DM->M_ItemRelate->Fields->Fields[22]->DisplayLabel = hin + "����";
	}else{
		TabSheet5->Caption = "���g�p";
		DBGrid5->Columns->Items[0]->Title->Caption   = "���g�p";
		DBGrid5->Columns->Items[1]->Title->Caption   = "���g�p";
		DBGrid5->Columns->Items[2]->Title->Caption   = "���g�p";
		DBGrid5->Columns->Items[3]->Title->Caption   = "���g�p";
		DBGrid6->Columns->Items[12]->Title->Caption  = "���g�p";
		DBGrid7->Columns->Items[3]->Title->Caption   = "���g�p";
		DBGrid10->Columns->Items[3]->Title->Caption  = "���g�p";
        DBGrid17->Columns->Items[10]->Title->Caption = "���g�p";
        DBGrid17->Columns->Items[11]->Title->Caption = "���g�p";

		HinmokuEditForm->Caption = "���g�p";
		QRHinmokuForm->TitleLabel->Caption = "���g�p";
		QRSharyoForm->HinmokuLabel->Caption = "���g�p";
		QRKanzanForm->HinmokuLabel->Caption = "���g�p";
		QRTankaForm->HinmokuLabel->Caption = "���g�p";
		KanzanEditForm->HinmokuLabel->Caption = "���g�p";
		SharyoEditForm->HinmokuLabel->Caption = "���g�p";
		TankaEditForm->HinmokuLabel->Caption  = "���g�p";
        ItemRelateEditForm->HinmokuLabel->Caption = "���g�p";
        QRItemRelateForm->HinmokuNameLabel->Caption = "���g�p";

		DM->M_Hinmoku->Fields->Fields[0]->DisplayLabel = "���g�p";
		DM->M_Hinmoku->Fields->Fields[1]->DisplayLabel = "���g�p";
		DM->M_Hinmoku->Fields->Fields[2]->DisplayLabel = "���g�p";
		DM->M_Hinmoku->Fields->Fields[3]->DisplayLabel = "���g�p";
		DM->M_Hinmoku->Fields->Fields[4]->DisplayLabel = "���g�p";

		DM->M_Sharyo->Fields->Fields[18]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[19]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[20]->DisplayLabel = "���g�p";
		DM->M_Sharyo->Fields->Fields[21]->DisplayLabel = "���g�p";

		DM->M_Kanzan->Fields->Fields[5]->DisplayLabel = "���g�p";
		DM->M_Kanzan->Fields->Fields[6]->DisplayLabel = "���g�p";
		DM->M_Kanzan->Fields->Fields[7]->DisplayLabel = "���g�p";
		DM->M_Kanzan->Fields->Fields[8]->DisplayLabel = "���g�p";

		DM->M_Tanka->Fields->Fields[5]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[6]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[7]->DisplayLabel = "���g�p";
		DM->M_Tanka->Fields->Fields[8]->DisplayLabel = "���g�p";

        DM->M_ItemRelate->Fields->Fields[19]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[20]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[21]->DisplayLabel = "���g�p";
        DM->M_ItemRelate->Fields->Fields[22]->DisplayLabel = "���g�p";
	}
}
//---------------------------------------------------------------------------
// �y�[�W�؂�ւ��̍ۂɃy�[�W�����Z�b�g
void __fastcall TMainForm::SetPageInfo(int page)
{
	// �g�p���Ȃ��f�[�^��\���̌������Z�b�g
	if (page != 0 && page != 1 && page != 2 && page != 3 && page != 4 && page != 5)
		return;
	AnsiString sql = "SELECT COUNT(*) AS ���� FROM " + table_name_[page] + " WHERE �g�p�敪 = 0";
	NsRecordSet set;
	DM->DBI.GetRecordSet(sql, set);
	int kensu = ToInt(set[0]["����"]);
	AnsiString caption = "�g�p���Ȃ��f�[�^��\��(" + FormatFloat("#,##0", kensu) + "��)";
	TCheckBox *checkbox;

	if (page == 0)
		checkbox = AllDataShowCheckBox1;
	else if (page == 1)
		checkbox = AllDataShowCheckBox2;
	else if (page == 2)
		checkbox = AllDataShowCheckBox3;
	else if (page == 3)
		checkbox = AllDataShowCheckBox4;
	else if (page == 4)
		checkbox = AllDataShowCheckBox5;
	else if (page == 5)
		checkbox = AllDataShowCheckBox6;

	checkbox->Caption = caption;
	if (kensu == 0)
		checkbox->Color = clBtnFace;
	else
		checkbox->Color = TColor(0x00CDCCFB);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGrid1DrawColumnCell(TObject *Sender,
	  const TRect &Rect, int DataCol, TColumn *Column,
	  TGridDrawState State)
{
	if (((TDBGrid *)Sender)->SelectedRows->CurrentRowSelected || (page > 5 && DataCol == 0))
		;
	else if (page == 6 && (DataCol == 2 || DataCol == 4))	// ���Z�}�X�^
		;
	else if (page == 9 && (DataCol == 2 || DataCol == 4 || DataCol == 6 || DataCol == 8))	// �P���}�X�^
		;
	else if (page >= 0 && page <= 5 && DataCol == 0){
		// �ԗ��}�X�^���犷�Z�}�X�^�ɃL�[�{�[�h���g�p���ăy�[�W��ؑւ����ۂɁu�g�p�敪��������Ȃ��v�Ƃ����G���[���o��(�����^�p��x�Ⴊ�Ȃ��̂ŕ��u)
		if (((TDBGrid *)Sender)->DataSource->DataSet->FieldByName("�g�p�敪")->AsInteger == 0)
			((TDBGrid *)Sender)->Canvas->Brush->Color = TColor(0x00CDCCFB);
	}else if ((State.Empty() || ActiveControl != ((TDBGrid *)Sender)) && ((TDBGrid *)Sender)->DataSource->DataSet->RecNo % 2 == 0)
		((TDBGrid *)Sender)->Canvas->Brush->Color = TColor(0x00E6E6E6);

	((TDBGrid *)Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

