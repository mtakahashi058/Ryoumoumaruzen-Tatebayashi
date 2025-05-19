//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include "QRFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRForm *QRForm;
//---------------------------------------------------------------------------
__fastcall TQRForm::TQRForm(TComponent* Owner)
	: TForm(Owner)
{
	field_name[0][0] = "����0";
	field_name[0][1] = "����1";
	field_name[0][2] = "����2";
	field_name[0][3] = "����3";
	field_name[0][4] = "����4";
	field_name[0][5] = "����5";
	field_name[0][6] = "�c��6";

	field_name[1][0] = "���|�c0";
	field_name[1][1] = "���|�c1";
	field_name[1][2] = "���|�c2";
	field_name[1][3] = "���|�c3";
	field_name[1][4] = "���|�c4";
	field_name[1][5] = "���|�c5";
	field_name[1][6] = "���|�c6";
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::Query_CalcFields(TDataSet *DataSet)
{
/*
	if (Query->FieldByName("���Ӑ�R�[�h")->AsString == "000058")
		kuri[0] = 0;
*/
/*
	// ���Ӑ於�̕���
	AnsiString toku_name = Query->FieldByName("���Ӑ於��")->AsString;
	Query->FieldByName("���Ӑ於��1")->AsString = AnsiDivide(&toku_name, 26);
	Query->FieldByName("���Ӑ於��2")->AsString = toku_name;

	// �c��
	int sime = Query->FieldByName("���ؓ�")->AsInteger;
	if (sime == 0)
		sime = DateToInt(GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	// �ŏI���ؓ����U�����O�łȂ��ꍇ�A�U�����Ԃōŏ��̒��ؓ��̔���z�ɌJ�z�z�𑫂�
	for (int i = 0; i < 6; i++)
		kuri[i] = 0;
	int edate6 = DateToInt(GetLastDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	if (sime > edate6){
		NsFieldSet keys;
		keys	<< NsField("������ID", Query->FieldByName("���Ӑ�ID")->AsInteger)
			<< NsField("���ؓ�",   sime);

		if      (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -5)))
			kuri[5] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -4)))
			kuri[4] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -3)))
			kuri[3] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -2)))
			kuri[2] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -1)))
			kuri[1] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(MainForm->DateFromPicker->Date))
			kuri[0] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
	}

	// ����
	AnsiString sql =	"SELECT SUM(����) + SUM(�U��) + SUM(�萔��) + SUM(���؎�) + SUM(��`) + SUM(���E) + SUM(�l����) + SUM(����) + SUM(���̑�) AS �����v "
				"FROM D_���� "
				"WHERE ������ BETWEEN " + IntToStr(sime) + " AND " + IntToStr(DateToInt(MainForm->DateToPicker->Date)) + " "
				"AND ������ID = " + IntToStr(Query->FieldByName("���Ӑ�ID")->AsInteger);
	NsRecordSet set;
	Currency nyukin = 0;
	if (DM->DBI.GetRecordSet(sql, set))
		nyukin = ToCurrency(set[0]["�����v"]);

	// ���|�z�Z�o
	Currency kake;
	for (int i = 6; i >= 0; i--){
		kake = Query->FieldByName(field_name[0][i])->AsCurrency;

		if (i != 6)	// �U�����O�̐����z���Ȃ��ꍇ�A�ŏ��̒��ؓ��̌J�z�z���v���X����
			kake += kuri[i];

		if (kake <= nyukin){
			Query->FieldByName(field_name[1][i])->AsCurrency = 0;
			nyukin = nyukin - kake;
		}else{
			Query->FieldByName(field_name[1][i])->AsCurrency = kake - nyukin;
			nyukin = 0;
		}
	}

	// ����\��z
	Currency kaishu = 0;
	for (int i = 6; i >= Query->FieldByName("�����T�C�g")->AsInteger; i--)
		kaishu += Query->FieldByName(field_name[1][i])->AsCurrency;
	Query->FieldByName("����\��z")->AsCurrency = kaishu;
*/
}
//---------------------------------------------------------------------------
void __fastcall TQRForm::QueryCalcFields(TDataSet *DataSet)
{
	// ���Ӑ於�̕���
	AnsiString toku_name = Query->FieldByName("���Ӑ於��")->AsString;
	Query->FieldByName("���Ӑ於��1")->AsString = AnsiDivide(&toku_name, 26);
	Query->FieldByName("���Ӑ於��2")->AsString = toku_name;

	// �c��
	int sime = Query->FieldByName("���ؓ�")->AsInteger;
	if (sime == 0)
		sime = DateToInt(GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	// �ŏI���ؓ����U�����O�łȂ��ꍇ�A�U�����Ԃōŏ��̒��ؓ��̔���z�ɌJ�z�z�𑫂�
	for (int i = 0; i < 6; i++)
		kuri[i] = 0;
	int edate6 = DateToInt(GetLastDate(IncMonth(MainForm->DateFromPicker->Date, -6)));

	if (sime > edate6){
		NsFieldSet keys;
		keys	<< NsField("������ID", Query->FieldByName("���Ӑ�ID")->AsInteger)
			<< NsField("���ؓ�",   sime);

		if      (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -5)))
			kuri[5] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -4)))
			kuri[4] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -3)))
			kuri[3] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -2)))
			kuri[2] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(IncMonth(MainForm->DateFromPicker->Date, -1)))
			kuri[1] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
		else if (GetFirstDate(IntToDate(sime)) == GetFirstDate(MainForm->DateFromPicker->Date))
			kuri[0] = ToCurrency(DM->DBI.Lookup("D_����", keys, "����J�z�z"));
	}

	// ����
	AnsiString sql =	"SELECT SUM(����) + SUM(�U��) + SUM(�萔��) + SUM(���؎�) + SUM(��`) + SUM(���E) + SUM(�l����) + SUM(����) + SUM(���̑�) AS �����v "
						"FROM D_���� "
						"WHERE ������ > " + IntToStr(sime) + " "
						//"WHERE ������ BETWEEN " + IntToStr(sime) + " AND " + IntToStr(DateToInt(MainForm->DateToPicker->Date)) + " "
						"AND ������ID = " + IntToStr(Query->FieldByName("���Ӑ�ID")->AsInteger);
	NsRecordSet set;
	Currency nyukin = 0;
	if (DM->DBI.GetRecordSet(sql, set))
		nyukin = ToCurrency(set[0]["�����v"]);

	// ���|�z�Z�o
	Currency kake;
	for (int i = 6; i >= 0; i--){
		kake = Query->FieldByName(field_name[0][i])->AsCurrency;

		if (i != 6)	// �U�����O�̐����z���Ȃ��ꍇ�A�ŏ��̒��ؓ��̌J�z�z���v���X����
			kake += kuri[i];

		if (kake <= nyukin){
			Query->FieldByName(field_name[1][i])->AsCurrency = 0;
			nyukin = nyukin - kake;
		}else{
			Query->FieldByName(field_name[1][i])->AsCurrency = kake - nyukin;
			nyukin = 0;
		}
	}

	// ����\��z
	Currency kaishu = 0;
	for (int i = 6; i >= Query->FieldByName("�����T�C�g")->AsInteger; i--)
		kaishu += Query->FieldByName(field_name[1][i])->AsCurrency;
	Query->FieldByName("����\��z")->AsCurrency = kaishu;
}
//---------------------------------------------------------------------------

void __fastcall TQRForm::DetailBand1BeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
	// �������̏ꍇ�A���z�ɐF�t��
	int site_month = Query->FieldByName("�����T�C�g")->AsInteger;
	int site_date  = Query->FieldByName("������")->AsInteger;

	QRDBTextZan6->Color = GetLabelColor(6, site_month, site_date);
	QRDBTextZan5->Color = GetLabelColor(5, site_month, site_date);
	QRDBTextZan4->Color = GetLabelColor(4, site_month, site_date);
	QRDBTextZan3->Color = GetLabelColor(3, site_month, site_date);
	QRDBTextZan2->Color = GetLabelColor(2, site_month, site_date);
	QRDBTextZan1->Color = GetLabelColor(1, site_month, site_date);
	QRDBTextZan0->Color = GetLabelColor(0, site_month, site_date);
}
//---------------------------------------------------------------------------
TColor __fastcall TQRForm::GetLabelColor(int label_no, int site_month, int site_date)
{
	AnsiString fname = "���|�c" + IntToStr(label_no);
	if (Query->FieldByName(fname)->AsCurrency == 0)
		return clWhite;

	int today_date = Date().FormatString("d").ToIntDef(0);

	if (label_no > site_month)
		return clSilver;
	else if (label_no < site_month)
		return clWhite;
	else if (site_date <= today_date)
		return clSilver;
	else
		return clWhite;
}
//---------------------------------------------------------------------------

