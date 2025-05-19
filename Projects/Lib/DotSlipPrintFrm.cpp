//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "DotSlipPrintFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDotSlipPrintForm *DotSlipPrintForm;
//---------------------------------------------------------------------------
__fastcall TDotSlipPrintForm::TDotSlipPrintForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool __fastcall TDotSlipPrintForm::Print(int keiryo_id, bool hide_time)
{
	if (ToBit(DM->CFG["�P���g�p�敪"])){
        AmountText->Enabled   = true;
        QuantityText->Enabled = true;
        UnitText->Enabled     = true;
        YenLabel->Enabled     = true;
	}else{
        AmountText->Enabled   = false;
        QuantityText->Enabled = false;
        UnitText->Enabled     = false;
        YenLabel->Enabled     = false;
	}

    AnsiString item_order = ToString(DM->CFG["�h�b�g�`�[���ڏ�"]);
    int no;
    TQRDBText *CodeText, *NameText;
    for (int i = 1; i <= 4; i++){
        if (item_order.IsEmpty())
            break;
        no = item_order.SubString(1, 1).ToIntDef(0);
        if (i == 1){
            CodeText = Row1CodeText;
            NameText = Row1NameText;
        }else if (i == 2){
            CodeText = Row2CodeText;
            NameText = Row2NameText;
        }else if (i == 3){
            CodeText = Row3CodeText;
            NameText = Row3NameText;
        }else if (i == 4){
            CodeText = Row4CodeText;
            NameText = Row4NameText;
        }else
            break;
        item_order.Delete(1, 1);

        if (no == 1){
            CodeText->DataField = "���Ӑ�R�[�h";
            NameText->DataField = "���Ӑ旪��";
        }else if (no == 2){
            CodeText->DataField = "����1�R�[�h";
            NameText->DataField = "����1����";
        }else if (no == 3){
            CodeText->DataField = "����2�R�[�h";
            NameText->DataField = "����2����";
        }else if (no == 4){
            CodeText->DataField = "�i�ڃR�[�h";
            NameText->DataField = "�i�ڗ���";
        }
    }

	if (Q_Slip->Active)
		Q_Slip->Close();
	Q_Slip->SQL->Text = "SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
	Q_Slip->Open();
	if (Q_Slip->Eof && Q_Slip->Bof){
		Application->MessageBox("�󎚂���v�ʃf�[�^������܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	//int gk_div = Q_Slip->FieldByName("���|�敪")->AsInteger;

	Currency w1, w2;
	w1 = Q_Slip->FieldByName("1��ڏd��")->AsCurrency;
	w2 = Q_Slip->FieldByName("2��ڏd��")->AsCurrency;
	if (w1 > w2){
        GrossTimeText->DataField = "�v�ʓ���1";
        GrossWText->DataField    = "1��ڏd��";
        TareTimeText->DataField  = "�v�ʓ���2";
        TareWText->DataField     = "2��ڏd��";
	}else{
        GrossTimeText->DataField = "�v�ʓ���2";
        GrossWText->DataField    = "2��ڏd��";
        TareTimeText->DataField  = "�v�ʓ���1";
        TareWText->DataField     = "1��ڏd��";
	}

	//int mon = Q_Slip->FieldByName("���z")->AsInteger;

    /*
    int kingaku_div = ToInt(DM->CFG["�`�[���z��"]);
    if (kingaku_div == 0 || !mon){
        AmountText->Enabled = false;
        YenLabel->Enabled   = false;
    }else if (kingaku_div == 1 && gk_div == 2){
        AmountText->Enabled = true;
        YenLabel->Enabled   = true;
    }else if (kingaku_div == 2 && gk_div == 1){
        AmountText->Enabled = true;
        YenLabel->Enabled   = true;
    }else if (kingaku_div == 3){
        AmountText->Enabled = true;
        YenLabel->Enabled   = true;
    }
    */

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

    if (IsNull(SET_TOP(set)["���z�󎚋敪1"]))
        kingaku_print1_ = true;     // �ߋ��݊�
    else
        kingaku_print1_ = ToBit(SET_TOP(set)["���z�󎚋敪1"]);

    AmountText->Enabled = kingaku_print1_;
    YenLabel->Enabled   = kingaku_print1_;

    if (Q_Slip->FieldByName("����")->AsInteger == 0){
        QuantityText->Enabled = false;
        UnitText->Enabled     = false;
    }
    if (Q_Slip->FieldByName("���z")->AsInteger == 0){
        AmountText->Enabled = false;
        YenLabel->Enabled   = false;
    }

	//////////////////////////////////////////////////
	///// ���Ԃ̈󎚐ݒ�
    GrossTimeText->Enabled = !hide_time;
    TareTimeText->Enabled  = !hide_time;

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
