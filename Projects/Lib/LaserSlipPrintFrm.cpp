//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include "LaserSlipPrintFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLaserSlipPrintForm *LaserSlipPrintForm;
//---------------------------------------------------------------------------
__fastcall TLaserSlipPrintForm::TLaserSlipPrintForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool __fastcall TLaserSlipPrintForm::Print(int keiryo_id, bool hide_time)
{
	if (Q_Slip->Active)
		Q_Slip->Close();
	Q_Slip->SQL->Text = "SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
	Q_Slip->Open();
	if (Q_Slip->Eof && Q_Slip->Bof){
		Application->MessageBox("�󎚂���v�ʃf�[�^������܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	TQRLabel *Labels[5];
    TQRDBText *Texts[5];

    Labels[1] = Field1Label1;
    Labels[2] = Field2Label1;
    Labels[3] = Field3Label1;
    Labels[4] = Field4Label1;
    Texts[1]  = Field1Text1;
    Texts[2]  = Field2Text1;
    Texts[3]  = Field3Text1;
    Texts[4]  = Field4Text1;

    AnsiString item_order = ToString(DM->CFG["�h�b�g�`�[���ڏ�"]);
    int no;
    for (int i = 1; i <= 4; i++){
        if (item_order.IsEmpty()){
            continue;
        }
        no = item_order.SubString(1, 1).ToIntDef(0);
        item_order.Delete(1, 1);

        if (no == 1){
        	Labels[i]->Caption  = ToString(DM->CFG["���Ӑ�}�X�^����"]);
            Texts[i]->DataField = "���Ӑ於��";

		    if (!ToInt(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
		        Labels[i]->Enabled = false;
		    }
        }else if (no == 2){
        	// ����1
        	Labels[i]->Caption  = ToString(DM->CFG["����1�}�X�^����"]);
            Texts[i]->DataField = "����1����";

		    if (!ToInt(DM->CFG["����1�}�X�^�g�p�敪"])){
		        Labels[i]->Enabled = false;
		    }
        }else if (no == 3){
        	// ����2
        	Labels[i]->Caption  = ToString(DM->CFG["����2�}�X�^����"]);
            Texts[i]->DataField = "����2����";

		    if (!ToInt(DM->CFG["����2�}�X�^�g�p�敪"])){
		        Labels[i]->Enabled = false;
		    }
        }else if (no == 4){
        	Labels[i]->Caption  = ToString(DM->CFG["�i�ڃ}�X�^����"]);
            Texts[i]->DataField = "�i�ږ���";

		    if (!ToInt(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
		        Labels[i]->Enabled = false;
		    }
        }
    }

	//////////////////////////////////////////////////
	///// ���o�Ɏg�p�̐ݒ�
	IoShape1A->Enabled = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	IoShape2A->Enabled = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	lblIoA->Enabled    = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	dbtxtIoA->Enabled  = ToBit(DM->CFG["���o�Ɏg�p�敪"]);

	IoShape1B->Enabled = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	IoShape2B->Enabled = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	lblIoB->Enabled    = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	dbtxtIoB->Enabled  = ToBit(DM->CFG["���o�Ɏg�p�敪"]);

	IoShape1C->Enabled = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	IoShape2C->Enabled = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	lblIoC->Enabled    = ToBit(DM->CFG["���o�Ɏg�p�敪"]);
	dbtxtIoC->Enabled  = ToBit(DM->CFG["���o�Ɏg�p�敪"]);

	///// ���ږ��̐ݒ�
    Field1Label2->Caption = Field1Label1->Caption;
    Field1Label3->Caption = Field1Label1->Caption;
    Field2Label2->Caption = Field2Label1->Caption;
    Field2Label3->Caption = Field2Label1->Caption;
    Field3Label2->Caption = Field3Label1->Caption;
    Field3Label3->Caption = Field3Label1->Caption;
    Field4Label2->Caption = Field4Label1->Caption;
    Field4Label3->Caption = Field4Label1->Caption;

    Field1Label2->Enabled = Field1Label1->Enabled;
    Field1Label3->Enabled = Field1Label1->Enabled;
    Field2Label2->Enabled = Field2Label1->Enabled;
    Field2Label3->Enabled = Field2Label1->Enabled;
    Field3Label2->Enabled = Field3Label1->Enabled;
    Field3Label3->Enabled = Field3Label1->Enabled;
    Field4Label2->Enabled = Field4Label1->Enabled;
    Field4Label3->Enabled = Field4Label1->Enabled;

    Field1Text2->DataField = Field1Text1->DataField;
    Field1Text3->DataField = Field1Text1->DataField;
    Field2Text2->DataField = Field2Text1->DataField;
    Field2Text3->DataField = Field2Text1->DataField;
    Field3Text2->DataField = Field3Text1->DataField;
    Field3Text3->DataField = Field3Text1->DataField;
    Field4Text2->DataField = Field4Text1->DataField;
    Field4Text3->DataField = Field4Text1->DataField;

	Coord1Label->Caption = ToString(DM->CFG["��������"]);
	Coord2Label->Caption = Coord1Label->Caption;
	Coord3Label->Caption = Coord1Label->Caption;
	Reduc1Label->Caption = ToString(DM->CFG["�d�ʈ�������"]);
	Reduc2Label->Caption = Reduc1Label->Caption;
	Reduc3Label->Caption = Reduc1Label->Caption;

	if (ToBit(DM->CFG["�P���g�p�敪"])){
		lblConversionValueA->Enabled = true;
		dbtxtQuantityA->Enabled      = true;
		Tani1DBText->Enabled         = true;
		lblConversionValueB->Enabled = true;
		dbtxtQuantityB->Enabled      = true;
		Tani2DBText->Enabled         = true;
		lblConversionValueC->Enabled = true;
		dbtxtQuantityC->Enabled      = true;
		Tani3DBText->Enabled         = true;
	}else{
		lblConversionValueA->Enabled = false;
		dbtxtQuantityA->Enabled      = false;
		Tani1DBText->Enabled         = false;
		lblConversionValueB->Enabled = false;
		dbtxtQuantityB->Enabled      = false;
		Tani2DBText->Enabled         = false;
		lblConversionValueC->Enabled = false;
		dbtxtQuantityC->Enabled      = false;
		Tani3DBText->Enabled         = false;
	}

	//////////////////////////////////////////////////
	///// ���Ԃ̈󎚐ݒ�
    GTime1DBText->Enabled = !hide_time;
    GTime2DBText->Enabled = !hide_time;
    GTime3DBText->Enabled = !hide_time;
    TTime1DBText->Enabled = !hide_time;
    TTime2DBText->Enabled = !hide_time;
    TTime3DBText->Enabled = !hide_time;

	//////////////////////////////////////////////////
	///// �`�[���̎擾�Ɛݒ�

	int print_info_id = DM->GetPrintInfo(keiryo_id);
	if (!print_info_id){
		Application->MessageBox("�`�[��񂪐ݒ肳��Ă��܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
	AnsiString sql;
	NsRecordSet set;
	sql = "SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�`�[��񂪖����ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	int div = Q_Slip->FieldByName("�����o�敪")->AsInteger;
	if (div == 1){
		Title1Label->Caption = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��1"]);
		Title2Label->Caption = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��2"]);
		Title3Label->Caption = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��3"]);
	}else{
		Title1Label->Caption = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��1"]);
		Title2Label->Caption = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��2"]);
		Title3Label->Caption = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��3"]);
	}

    QRCover1->Height = Title1Label->Caption.IsEmpty() ? 861 : 1;
    QRCover2->Height = Title2Label->Caption.IsEmpty() ? 861 : 1;
    QRCover3->Height = Title3Label->Caption.IsEmpty() ? 861 : 1;

	Company1Label->Caption = ToString(SET_TOP(set)["��Ж�"]);
	Company2Label->Caption = Company1Label->Caption;
	Company3Label->Caption = Company1Label->Caption;
	Info11Label->Caption   = ToString(SET_TOP(set)["��Џ��1"]);
	Info12Label->Caption   = Info11Label->Caption;
	Info13Label->Caption   = Info11Label->Caption;
	Info21Label->Caption   = ToString(SET_TOP(set)["��Џ��2"]);
	Info22Label->Caption   = Info21Label->Caption;
	Info23Label->Caption   = Info21Label->Caption;
	Info31Label->Caption   = ToString(SET_TOP(set)["��Џ��3"]);
	Info32Label->Caption   = Info31Label->Caption;
	Info33Label->Caption   = Info31Label->Caption;
	Info41Label->Caption   = ToString(SET_TOP(set)["��Џ��4"]);
	Info42Label->Caption   = Info41Label->Caption;
	Info43Label->Caption   = Info41Label->Caption;

    if (IsNull(SET_TOP(set)["���z�󎚋敪1"]))
        kingaku_print1_ = true;     // �ߋ��݊�
    else
        kingaku_print1_ = ToBit(SET_TOP(set)["���z�󎚋敪1"]);
        
    if (IsNull(SET_TOP(set)["���z�󎚋敪2"]))
        kingaku_print2_ = true;     // �ߋ��݊�
    else
        kingaku_print2_ = ToBit(SET_TOP(set)["���z�󎚋敪2"]);

    if (IsNull(SET_TOP(set)["���z�󎚋敪3"]))
        kingaku_print3_ = true;     // �ߋ��݊�
    else
        kingaku_print3_ = ToBit(SET_TOP(set)["���z�󎚋敪3"]);

	if (!SetPrinter(QuickRep, ToString(DM->INI["Printer::Slip"]))){
		Application->MessageBox("�`�[���s�p�Ɏw�肳�ꂽ�v�����^��������܂���B�ʏ�g���v�����^���g�p���܂�",
					Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}

	QuickRep->Page->LeftMargin = ToCurrency(DM->INI["Printer::SlipLeft"]);
	QuickRep->Page->TopMargin  = ToCurrency(DM->INI["Printer::SlipTop"]);

    int bin = ToInt(DM->INI["Printer::SlipOutputBin"]);
    switch (bin){
    case  1:
        QuickRep->PrinterSettings->OutputBin = First;
        break;
    case  2:
        QuickRep->PrinterSettings->OutputBin = Upper;
        break;
    case  3:
        QuickRep->PrinterSettings->OutputBin = Lower;
        break;
    case  4:
        QuickRep->PrinterSettings->OutputBin = Middle;
        break;
    case  5:
        QuickRep->PrinterSettings->OutputBin = Manual;
        break;
    case  6:
        QuickRep->PrinterSettings->OutputBin = Envelope;
        break;
    case  7:
        QuickRep->PrinterSettings->OutputBin = EnvManual;
        break;
    case  8:
        QuickRep->PrinterSettings->OutputBin = Tractor;
        break;
    case  9:
        QuickRep->PrinterSettings->OutputBin = SmallFormat;
        break;
    case 10:
        QuickRep->PrinterSettings->OutputBin = LargeFormat;
        break;
    case 11:
        QuickRep->PrinterSettings->OutputBin = LargeCapacity;
        break;
    case 12:
        QuickRep->PrinterSettings->OutputBin = Cassette;
        break;
    case 13:
        QuickRep->PrinterSettings->OutputBin = Last;
        break;
    default:
        QuickRep->PrinterSettings->OutputBin = Auto;
    }

	//QuickRep->Preview();
	QuickRep->Print();

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TLaserSlipPrintForm::QuickRepBeforePrint(
	  TCustomQuickRep *Sender, bool &PrintReport)
{
	Currency w1, w2;
	w1 = Q_Slip->FieldByName("1��ڏd��")->AsCurrency;
	w2 = Q_Slip->FieldByName("2��ڏd��")->AsCurrency;
	if (w1 > w2){
		Gross1DBText->DataField = "1��ڏd��";
		Gross2DBText->DataField = "1��ڏd��";
		Gross3DBText->DataField = "1��ڏd��";
		Tare1DBText->DataField  = "2��ڏd��";
		Tare2DBText->DataField  = "2��ڏd��";
		Tare3DBText->DataField  = "2��ڏd��";
		GTime1DBText->DataField = "�v�ʓ���1";
		GTime2DBText->DataField = "�v�ʓ���1";
		GTime3DBText->DataField = "�v�ʓ���1";
		TTime1DBText->DataField = "�v�ʓ���2";
		TTime2DBText->DataField = "�v�ʓ���2";
		TTime3DBText->DataField = "�v�ʓ���2";
	}else{
		Gross1DBText->DataField = "2��ڏd��";
		Gross2DBText->DataField = "2��ڏd��";
		Gross3DBText->DataField = "2��ڏd��";
		Tare1DBText->DataField  = "1��ڏd��";
		Tare2DBText->DataField  = "1��ڏd��";
		Tare3DBText->DataField  = "1��ڏd��";
		GTime1DBText->DataField = "�v�ʓ���2";
		GTime2DBText->DataField = "�v�ʓ���2";
		GTime3DBText->DataField = "�v�ʓ���2";
		TTime1DBText->DataField = "�v�ʓ���1";
		TTime2DBText->DataField = "�v�ʓ���1";
		TTime3DBText->DataField = "�v�ʓ���1";
	}

	Currency coord_per, coord;
	coord_per = Q_Slip->FieldByName("������")->AsCurrency;
	coord     = Q_Slip->FieldByName("�����d��")->AsCurrency;
	if (coord_per != 0 || coord != 0){
		Coord1Label->Enabled   = true;
		CrdPer1DBText->Enabled = true;
		Per1Label->Enabled     = true;
		Coord1DBText->Enabled  = true;
		CrdUnit1Label->Enabled = true;
		Coord2Label->Enabled   = true;
		CrdPer2DBText->Enabled = true;
		Per2Label->Enabled     = true;
		Coord2DBText->Enabled  = true;
		CrdUnit2Label->Enabled = true;
		Coord3Label->Enabled   = true;
		CrdPer3DBText->Enabled = true;
		Per3Label->Enabled     = true;
		Coord3DBText->Enabled  = true;
		CrdUnit3Label->Enabled = true;
	}else{
		Coord1Label->Enabled   = false;
		CrdPer1DBText->Enabled = false;
		Per1Label->Enabled     = false;
		Coord1DBText->Enabled  = false;
		CrdUnit1Label->Enabled = false;
		Coord2Label->Enabled   = false;
		CrdPer2DBText->Enabled = false;
		Per2Label->Enabled     = false;
		Coord2DBText->Enabled  = false;
		CrdUnit2Label->Enabled = false;
		Coord3Label->Enabled   = false;
		CrdPer3DBText->Enabled = false;
		Per3Label->Enabled     = false;
		Coord3DBText->Enabled  = false;
		CrdUnit3Label->Enabled = false;
	}

	Currency reduce = Q_Slip->FieldByName("�d�ʈ���")->AsCurrency;
	if (reduce != 0){
		Reduc1Label->Enabled   = true;
		Reduc1DBText->Enabled  = true;
		RdcUnit1Label->Enabled = true;
		Reduc2Label->Enabled   = true;
		Reduc2DBText->Enabled  = true;
		RdcUnit2Label->Enabled = true;
		Reduc3Label->Enabled   = true;
		Reduc3DBText->Enabled  = true;
		RdcUnit3Label->Enabled = true;
	}else{
		Reduc1Label->Enabled   = false;
		Reduc1DBText->Enabled  = false;
		RdcUnit1Label->Enabled = false;
		Reduc2Label->Enabled   = false;
		Reduc2DBText->Enabled  = false;
		RdcUnit2Label->Enabled = false;
		Reduc3Label->Enabled   = false;
		Reduc3DBText->Enabled  = false;
		RdcUnit3Label->Enabled = false;
	}

	int tani_id = Q_Slip->FieldByName("�P��ID")->AsInteger;
    if (tani_id == 1 || tani_id == 3){
        lblConversionValueA->Enabled = false;
        dbtxtQuantityA->Enabled      = false;
        Tani1DBText->Enabled         = false;
        lblConversionValueB->Enabled = false;
        dbtxtQuantityB->Enabled      = false;
        Tani2DBText->Enabled         = false;
        lblConversionValueC->Enabled = false;
        dbtxtQuantityC->Enabled      = false;
        Tani3DBText->Enabled         = false;
    }

/*
	int gk_div = Q_Slip->FieldByName("���|�敪")->AsInteger;
    int kingaku_div = ToInt(DM->CFG["�`�[���z��"]);

    if (kingaku_div == 0 || !mon){
		lblPriceA->Enabled     = false;
		lblPriceYenA ->Enabled = false;
		dbtxtPriceA->Enabled   = false;
		lblMoneyA->Enabled     = false;
		lblMoneyYenA->Enabled  = false;
		dbtxtMoneyA->Enabled   = false;
		lblTaxA->Enabled       = false;
		lblTaxYenA->Enabled    = false;
		dbtxtTaxA->Enabled     = false;
		lblTotalA->Enabled     = false;
		lblTotalYenA->Enabled  = false;
		exTotalA->Enabled      = false;
		lblPriceB->Enabled     = false;
		lblPriceYenB ->Enabled = false;
		dbtxtPriceB->Enabled   = false;
		lblMoneyB->Enabled     = false;
		lblMoneyYenB->Enabled  = false;
		dbtxtMoneyB->Enabled   = false;
		lblTaxB->Enabled       = false;
		lblTaxYenB->Enabled    = false;
		dbtxtTaxB->Enabled     = false;
		lblTotalB->Enabled     = false;
		lblTotalYenB->Enabled  = false;
		exTotalB->Enabled      = false;
		lblPriceC->Enabled     = false;
		lblPriceYenC ->Enabled = false;
		dbtxtPriceC->Enabled   = false;
		lblMoneyC->Enabled     = false;
		lblMoneyYenC->Enabled  = false;
		dbtxtMoneyC->Enabled   = false;
		lblTaxC->Enabled       = false;
		lblTaxYenC->Enabled    = false;
		dbtxtTaxC->Enabled     = false;
		lblTotalC->Enabled     = false;
		lblTotalYenC->Enabled  = false;
		exTotalC->Enabled      = false;
    }else if (kingaku_div == 1 && gk_div == 2 && mon){
		lblPriceA->Enabled     = true;
		lblPriceYenA ->Enabled = true;
		dbtxtPriceA->Enabled   = true;
		lblMoneyA->Enabled     = true;
		lblMoneyYenA->Enabled  = true;
		dbtxtMoneyA->Enabled   = true;
		lblTaxA->Enabled       = true;
		lblTaxYenA->Enabled    = true;
		dbtxtTaxA->Enabled     = true;
		lblTotalA->Enabled     = true;
		lblTotalYenA->Enabled  = true;
		exTotalA->Enabled      = true;
		lblPriceB->Enabled     = true;
		lblPriceYenB ->Enabled = true;
		dbtxtPriceB->Enabled   = true;
		lblMoneyB->Enabled     = true;
		lblMoneyYenB->Enabled  = true;
		dbtxtMoneyB->Enabled   = true;
		lblTaxB->Enabled       = true;
		lblTaxYenB->Enabled    = true;
		dbtxtTaxB->Enabled     = true;
		lblTotalB->Enabled     = true;
		lblTotalYenB->Enabled  = true;
		exTotalB->Enabled      = true;
		lblPriceC->Enabled     = true;
		lblPriceYenC ->Enabled = true;
		dbtxtPriceC->Enabled   = true;
		lblMoneyC->Enabled     = true;
		lblMoneyYenC->Enabled  = true;
		dbtxtMoneyC->Enabled   = true;
		lblTaxC->Enabled       = true;
		lblTaxYenC->Enabled    = true;
		dbtxtTaxC->Enabled     = true;
		lblTotalC->Enabled     = true;
		lblTotalYenC->Enabled  = true;
		exTotalC->Enabled      = true;
    }else if (kingaku_div == 2 && gk_div == 1 && mon){
		lblPriceA->Enabled     = true;
		lblPriceYenA ->Enabled = true;
		dbtxtPriceA->Enabled   = true;
		lblMoneyA->Enabled     = true;
		lblMoneyYenA->Enabled  = true;
		dbtxtMoneyA->Enabled   = true;
		lblTaxA->Enabled       = true;
		lblTaxYenA->Enabled    = true;
		dbtxtTaxA->Enabled     = true;
		lblTotalA->Enabled     = true;
		lblTotalYenA->Enabled  = true;
		exTotalA->Enabled      = true;
		lblPriceB->Enabled     = true;
		lblPriceYenB ->Enabled = true;
		dbtxtPriceB->Enabled   = true;
		lblMoneyB->Enabled     = true;
		lblMoneyYenB->Enabled  = true;
		dbtxtMoneyB->Enabled   = true;
		lblTaxB->Enabled       = true;
		lblTaxYenB->Enabled    = true;
		dbtxtTaxB->Enabled     = true;
		lblTotalB->Enabled     = true;
		lblTotalYenB->Enabled  = true;
		exTotalB->Enabled      = true;
		lblPriceC->Enabled     = true;
		lblPriceYenC ->Enabled = true;
		dbtxtPriceC->Enabled   = true;
		lblMoneyC->Enabled     = true;
		lblMoneyYenC->Enabled  = true;
		dbtxtMoneyC->Enabled   = true;
		lblTaxC->Enabled       = true;
		lblTaxYenC->Enabled    = true;
		dbtxtTaxC->Enabled     = true;
		lblTotalC->Enabled     = true;
		lblTotalYenC->Enabled  = true;
		exTotalC->Enabled      = true;
    }else if (kingaku_div == 3 && mon){
		lblPriceA->Enabled     = true;
		lblPriceYenA ->Enabled = true;
		dbtxtPriceA->Enabled   = true;
		lblMoneyA->Enabled     = true;
		lblMoneyYenA->Enabled  = true;
		dbtxtMoneyA->Enabled   = true;
		lblTaxA->Enabled       = true;
		lblTaxYenA->Enabled    = true;
		dbtxtTaxA->Enabled     = true;
		lblTotalA->Enabled     = true;
		lblTotalYenA->Enabled  = true;
		exTotalA->Enabled      = true;
		lblPriceB->Enabled     = true;
		lblPriceYenB ->Enabled = true;
		dbtxtPriceB->Enabled   = true;
		lblMoneyB->Enabled     = true;
		lblMoneyYenB->Enabled  = true;
		dbtxtMoneyB->Enabled   = true;
		lblTaxB->Enabled       = true;
		lblTaxYenB->Enabled    = true;
		dbtxtTaxB->Enabled     = true;
		lblTotalB->Enabled     = true;
		lblTotalYenB->Enabled  = true;
		exTotalB->Enabled      = true;
		lblPriceC->Enabled     = true;
		lblPriceYenC ->Enabled = true;
		dbtxtPriceC->Enabled   = true;
		lblMoneyC->Enabled     = true;
		lblMoneyYenC->Enabled  = true;
		dbtxtMoneyC->Enabled   = true;
		lblTaxC->Enabled       = true;
		lblTaxYenC->Enabled    = true;
		dbtxtTaxC->Enabled     = true;
		lblTotalC->Enabled     = true;
		lblTotalYenC->Enabled  = true;
		exTotalC->Enabled      = true;
    }
*/
	int mon = Q_Slip->FieldByName("���z")->AsInteger;
    if (mon < 1){
        kingaku_print1_ = kingaku_print2_ = kingaku_print3_ = false;
    }

    lblPriceA->Enabled     = kingaku_print1_;
    lblPriceYenA ->Enabled = kingaku_print1_;
    dbtxtPriceA->Enabled   = kingaku_print1_;
    lblMoneyA->Enabled     = kingaku_print1_;
    lblMoneyYenA->Enabled  = kingaku_print1_;
    dbtxtMoneyA->Enabled   = kingaku_print1_;
    lblTaxA->Enabled       = kingaku_print1_;
    lblTaxYenA->Enabled    = kingaku_print1_;
    dbtxtTaxA->Enabled     = kingaku_print1_;
    lblTotalA->Enabled     = kingaku_print1_;
    lblTotalYenA->Enabled  = kingaku_print1_;
    exTotalA->Enabled      = kingaku_print1_;

    lblPriceB->Enabled     = kingaku_print2_;
    lblPriceYenB ->Enabled = kingaku_print2_;
    dbtxtPriceB->Enabled   = kingaku_print2_;
    lblMoneyB->Enabled     = kingaku_print2_;
    lblMoneyYenB->Enabled  = kingaku_print2_;
    dbtxtMoneyB->Enabled   = kingaku_print2_;
    lblTaxB->Enabled       = kingaku_print2_;
    lblTaxYenB->Enabled    = kingaku_print2_;
    dbtxtTaxB->Enabled     = kingaku_print2_;
    lblTotalB->Enabled     = kingaku_print2_;
    lblTotalYenB->Enabled  = kingaku_print2_;
    exTotalB->Enabled      = kingaku_print2_;

    lblPriceC->Enabled     = kingaku_print3_;
    lblPriceYenC ->Enabled = kingaku_print3_;
    dbtxtPriceC->Enabled   = kingaku_print3_;
    lblMoneyC->Enabled     = kingaku_print3_;
    lblMoneyYenC->Enabled  = kingaku_print3_;
    dbtxtMoneyC->Enabled   = kingaku_print3_;
    lblTaxC->Enabled       = kingaku_print3_;
    lblTaxYenC->Enabled    = kingaku_print3_;
    dbtxtTaxC->Enabled     = kingaku_print3_;
    lblTotalC->Enabled     = kingaku_print3_;
    lblTotalYenC->Enabled  = kingaku_print3_;
    exTotalC->Enabled      = kingaku_print3_;
}
//---------------------------------------------------------------------------


