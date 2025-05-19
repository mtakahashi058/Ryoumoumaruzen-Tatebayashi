//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "ManualDotSlipFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TManualDotSlipForm *ManualDotSlipForm;
//---------------------------------------------------------------------------
__fastcall TManualDotSlipForm::TManualDotSlipForm(TComponent* Owner)
	: TForm(Owner)
{
	code_label_[0] = Item1CodeLabel;  name_label_[0] = Item1NameLabel;
	code_label_[1] = Item2CodeLabel;  name_label_[1] = Item2NameLabel;
	code_label_[2] = Item3CodeLabel;  name_label_[2] = Item3NameLabel;
	code_label_[3] = Item4CodeLabel;  name_label_[3] = Item4NameLabel;
}
//---------------------------------------------------------------------------
bool __fastcall TManualDotSlipForm::Print(int keiryo_id, bool hide_time)
{
	AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
	NsRecordSet set;

	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�󎚂���v�ʃf�[�^������܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	NoLabel->Caption     = ToInt(SET_TOP(set)["�`�[No"]);
	DateLabel->Caption   = IntToDate(ToInt(SET_TOP(set)["�v�ʓ�"]));
	ShabanLabel->Caption = ToInt(SET_TOP(set)["�Ԕ�"]);

	AnsiString item_order = ToString(DM->CFG["�h�b�g�`�[���ڏ�"]);
	for (int i = 0; i < 4; i++){
		switch (item_order.SubString(1, 1).ToInt()){
		case 1:
			code_label_[i]->Caption = ToString(SET_TOP(set)["���Ӑ�R�[�h"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["���Ӑ旪��"]);
			break;
		case 2:
			code_label_[i]->Caption = ToString(SET_TOP(set)["����1�R�[�h"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["����1����"]);
			break;
		case 3:
			code_label_[i]->Caption = ToString(SET_TOP(set)["����2�R�[�h"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["����2����"]);
			break;
		case 4:
			code_label_[i]->Caption = ToString(SET_TOP(set)["�i�ڃR�[�h"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["�i�ڗ���"]);
			break;
		}
		item_order.Delete(1, 1);
	}

	Currency gross_w, tare_w, first_w, second_w;
	TDateTime gross_t, tare_t;
	first_w  = ToCurrency(SET_TOP(set)["1��ڏd��"]);
	second_w = ToCurrency(SET_TOP(set)["2��ڏd��"]);
	if (first_w < second_w){
		GrossWeightLabel->Caption = FormatFloat("#,##0kg", second_w);
		TareWeightLabel->Caption  = FormatFloat("#,##0kg", first_w);
		if (!SET_TOP(set)["�v�ʓ���2"].IsNull())
			GrossTimeLabel->Caption = VarToDateTime(SET_TOP(set)["�v�ʓ���2"]).FormatString("hh:nn");
		else
			GrossTimeLabel->Caption = AnsiString();
		if (!SET_TOP(set)["�v�ʓ���1"].IsNull())
			TareTimeLabel->Caption  = VarToDateTime(SET_TOP(set)["�v�ʓ���1"]).FormatString("hh:nn");
		else
			TareTimeLabel->Caption  = AnsiString();
	}else{
		GrossWeightLabel->Caption = FormatFloat("#,##0kg", first_w);
		TareWeightLabel->Caption  = FormatFloat("#,##0kg", second_w);
		if (!SET_TOP(set)["�v�ʓ���1"].IsNull())
			GrossTimeLabel->Caption = VarToDateTime(SET_TOP(set)["�v�ʓ���1"]).FormatString("hh:nn");
		else
			GrossTimeLabel->Caption = AnsiString();
		if (!SET_TOP(set)["�v�ʓ���2"].IsNull())
			TareTimeLabel->Caption  = VarToDateTime(SET_TOP(set)["�v�ʓ���2"]).FormatString("hh:nn");
		else
			TareTimeLabel->Caption  = AnsiString();
	}
	NetWeightLabel->Caption = FormatFloat("#,##0kg", ToCurrency(SET_TOP(set)["�����d��"]));
	BikoLabel->Caption      = ToString(SET_TOP(set)["���l"]);

	// ���Ԉ󎚐ݒ蔽�f
	GrossTimeLabel->Enabled = !hide_time;
	TareTimeLabel->Enabled  = !hide_time;

	// ��Џ��}�X�^����Џ��֘A�}�X�^�Q��
	if (DM->CFG["�荷���h�b�g�`�[���󎚋敪"]){
		int printinfo_id = DM->GetPrintInfo(keiryo_id);
		if (!printinfo_id){
			Application->MessageBox("�`�[��񂪐ݒ肳��Ă��܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		sql = "SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(printinfo_id);
		set.clear();
		if (!DM->DBI.GetRecordSet(sql, set)){
			Application->MessageBox("�`�[��񂪖����ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		CompanyNameLabel->Caption  = ToString(SET_TOP(set)["��Ж�"]);
		CompanyInfoLabel1->Caption = ToString(SET_TOP(set)["��Џ��1"]);
		CompanyInfoLabel2->Caption = ToString(SET_TOP(set)["��Џ��2"]);
		CompanyInfoLabel3->Caption = ToString(SET_TOP(set)["��Џ��3"]);
		CompanyInfoLabel4->Caption = ToString(SET_TOP(set)["��Џ��4"]);
	}else{
		CompanyNameLabel->Caption  = AnsiString();
		CompanyInfoLabel1->Caption = AnsiString();
		CompanyInfoLabel2->Caption = AnsiString();
		CompanyInfoLabel3->Caption = AnsiString();
		CompanyInfoLabel4->Caption = AnsiString();
	}

	if (!SetPrinter(QuickRep, ToString(DM->INI["Printer::Slip"]))){
		Application->MessageBox("�`�[���s�p�Ɏw�肳�ꂽ�v�����^��������܂���B�ʏ�g���v�����^���g�p���܂�",
					Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}
	QuickRep->Page->LeftMargin = ToCurrency(DM->INI["Printer::SlipLeft"]);
	QuickRep->Page->TopMargin  = ToCurrency(DM->INI["Printer::SlipTop"]);

	QuickRep->Print();

	return true;
}
//---------------------------------------------------------------------------

