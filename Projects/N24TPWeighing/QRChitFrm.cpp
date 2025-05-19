//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QRChitFrm.h"
#include "DMFrm.h"
#include "n24tp.h"
#include "StateConst.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRChitForm *QRChitForm;
//---------------------------------------------------------------------------
__fastcall TQRChitForm::TQRChitForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQRChitForm::Print(int keiryo_id)
{
    TokuTitleLabel->Caption  = DM->TrimSpace(ToString(DM->CFG["���Ӑ�}�X�^����"]));
    MeigTitleLabel->Caption  = DM->TrimSpace(ToString(DM->CFG["�i�ڃ}�X�^����"]));
    Item1TitleLabel->Caption = DM->TrimSpace(ToString(DM->CFG["����1�}�X�^����"]));
    Item2TitleLabel->Caption = DM->TrimSpace(ToString(DM->CFG["����2�}�X�^����"]));

	//////////////////////////////////////////////////
    int date, place_id, no;
    if (!DM->GetKeiryoKey(keiryo_id, date, place_id, no))
		throw Exception("�󎚃f�[�^������܂���");

	if (ChitQuery->Active)
		ChitQuery->Close();
	try{
		ChitQuery->SQL->Text = " SELECT * FROM V_�v��"
                               " WHERE �v�ʓ� = " + IntToStr(date) +
                               "   AND ���_ID = " + IntToStr(place_id) +
                               "   AND �`�[No = " + IntToStr(no) +
                               "   AND �����敪 = 1";
		ChitQuery->Open();
		if (ChitQuery->Eof)
			throw Exception("");
	}catch(...){
		throw Exception("�󎚃f�[�^������܂���");
	}


	//////////////////////////////////////////////////
	///// �`�[���̎擾�Ɛݒ�

    AnsiString titles[3];

	int print_info_id = DM->GetPrintInfo(keiryo_id);
	if (!print_info_id){
		Application->MessageBox("�`�[��񂪐ݒ肳��Ă��܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}
	AnsiString sql;
	NsRecordSet set;
	sql = "SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�`�[��񂪖����ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	int div = ChitQuery->FieldByName("�����o�敪")->AsInteger;
	if (div == 1){
		titles[0] = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��1"]);
		titles[1] = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��2"]);
		titles[2] = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��3"]);
	}else{
		titles[0] = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��1"]);
		titles[1] = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��2"]);
		titles[2] = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��3"]);
	}
	QRCompany->Caption = ToString(SET_TOP(set)["��Ж�"]);
	QRFooter1->Caption = ToString(SET_TOP(set)["��Џ��1"]);
    QRFooter2->Caption = ToString(SET_TOP(set)["��Џ��2"]);
	QRFooter3->Caption = ToString(SET_TOP(set)["��Џ��3"]);
	QRFooter4->Caption = ToString(SET_TOP(set)["��Џ��4"]);

	SetPrinter(QR, ToString(DM->INI["Chit::Printer"]));
	int copies = ToInt(DM->INI["Chit::PrintCopy"]);
    for (int i = 0; i < copies; i++){
        if (i < 3)
            QRTitle->Caption = titles[i];
        else
            QRTitle->Caption = titles[0];
        QR->Print();
    }
}
//---------------------------------------------------------------------------
void __fastcall TQRChitForm::ChitQueryCalcFields(TDataSet *DataSet)
{
    int w1, w2;
    w1 = DataSet->FieldByName("1��ڏd��")->AsInteger;
    w2 = DataSet->FieldByName("2��ڏd��")->AsInteger;

    DataSet->FieldByName("���d��")->AsInteger   = std::max(w1, w2);
    DataSet->FieldByName("��ԏd��")->AsInteger = std::min(w1, w2);
}
//---------------------------------------------------------------------------

