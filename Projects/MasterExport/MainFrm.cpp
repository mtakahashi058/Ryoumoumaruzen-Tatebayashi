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
char CalcBCC(LPCSTR text) {
    char bcc = 0x00;
    while (*text != '\0')
        bcc ^= *text++;
    return bcc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CarsExportButtonClick(TObject *Sender)
{
    if (Application->MessageBox("���M����ƁA�w���v���̎ԗ���񂪂��ׂăN���A����܂��I\r\n���M���Ă�낵���ł����H",
            CarsExportButton->Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    CarsExportButton->Enabled = false;
    ItemExportButton->Enabled = false;
    CloseButton->Enabled      = false;

    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 6;
    ProgressBar->Step     = 1;

    AnsiString sql;
    NsRecordSet set;

    sql = " SELECT"
          "     V_�ԗ�.�Ԕ�, V_�ԗ�.��ԏd��, V_�ԗ�.�ő�ύڗ�,"
          "     V_�ԗ�.���Ӑ�R�[�h, V_�ԗ�.����1�R�[�h, V_�ԗ�.����2�R�[�h, V_�ԗ�.�i�ڃR�[�h"
          " FROM ("
          "     SELECT MAX(�ԗ�ID) AS �ԗ�ID FROM M_�ԗ�"
          "     GROUP BY �Ԕ�"
          " ) AS MASTER"
          " INNER JOIN V_�ԗ� ON V_�ԗ�.�ԗ�ID = MASTER.�ԗ�ID AND V_�ԗ�.�g�p�敪 = 1"
          " ORDER BY V_�ԗ�.�Ԕ�";
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("���M����ԗ���񂪂���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);

        CarsExportButton->Enabled = true;
        ItemExportButton->Enabled = true;
        CloseButton->Enabled      = true;

        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    // �w���v�� ScaM �̍��ڊ��蓖�ă}�b�s���O

    int item1_code, item2_code, item3_code, item4_code;
    typedef std::map<int, int *> CnvTable;
    CnvTable cnv_table;
    cnv_table[ToInt(DM->CFG["�w���v���ڂP"])] = &item1_code;
    cnv_table[ToInt(DM->CFG["�w���v���ڂQ"])] = &item2_code;
    cnv_table[ToInt(DM->CFG["�w���v���ڂR"])] = &item3_code;
    cnv_table[ToInt(DM->CFG["�w���v���ڂS"])] = &item4_code;

    std::vector<AnsiString> raw_records;
    char wsbuff[100];
    for (unsigned int i = 0; i < set.size(); i++){
        item1_code = item2_code = item3_code = item4_code = 0;

        CnvTable::iterator ite;
        ite = cnv_table.find(1);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["���Ӑ�R�[�h"]);
        ite = cnv_table.find(2);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["����1�R�[�h"]);
        ite = cnv_table.find(3);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["����2�R�[�h"]);
        ite = cnv_table.find(4);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["�i�ڃR�[�h"]);


        wsprintf(wsbuff, "  %-8d %03d %03d %03d %03d %06d %06d",
            ToInt(set[i]["�Ԕ�"]),
            item1_code, item2_code, item3_code, item4_code,
            ToInt(set[i]["��ԏd��"]), ToInt(set[i]["�ő�ύڗ�"])
            );
        raw_records.push_back(wsbuff);
    }

    records_.clear();

    AnsiString buff;
    char bcc;
    for (unsigned int i = 0; i < raw_records.size(); i++){
        if (i % 3 == 0){
            buff = AnsiString();
            buff = "* ID.  ";
        }

        buff += raw_records[i];

        if (i % 3 == 2){
            buff += "*";

            buff[1] = 0x02;             // STX
            buff[buff.Length()] = 0x03; // ETX
            bcc = CalcBCC(buff.c_str() + 1);
            buff += "*";
            buff[buff.Length()] = bcc;

            records_.push_back(buff);
        }
    }

    int remained = 3 - (raw_records.size() % 3);
    if (remained == 2)
        buff += "                                        ";
    if (remained == 2 || remained == 1){
        buff += "                                        ";
        buff += "*";

        buff[1] = 0x02;             // STX
        buff[buff.Length()] = 0x03; // ETX
        bcc = CalcBCC(buff.c_str() + 1);
        buff += "*";
        buff[buff.Length()] = bcc;

        records_.push_back(buff);
    }

    wsprintf(wsbuff, "* END  %04d%04d%112s*",
        records_.size() + 1, raw_records.size(), "  ");

    buff = wsbuff;
    buff[1] = 0x02;             // STX
    buff[buff.Length()] = 0x03; // ETX
    bcc = CalcBCC(buff.c_str() + 1);
    buff += "*";
    buff[buff.Length()] = bcc;
    records_.push_back(buff);


	std::ofstream ofs("idexport.log");
    for (unsigned int i = 0; i < records_.size(); i++)
        ofs << records_[i].c_str() << std::endl;

    thread_ = new TN95ExportThread(false, port_, def_, Handle, etID, records_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItemExportButtonClick(TObject *Sender)
{
    if (Application->MessageBox("���M����ƁA�w���v���̍��ڏ�񂪂��ׂăN���A����܂��I\r\n���M���Ă�낵���ł����H",
            ItemExportButton->Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    CarsExportButton->Enabled = false;
    ItemExportButton->Enabled = false;
    CloseButton->Enabled  = false;

    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 6;
    ProgressBar->Step     = 1;

    AnsiString sql;
    NsRecordSet set;

    sql = " SELECT 1 AS ����No, ���Ӑ�R�[�h AS �R�[�h, ���Ӑ於�� AS ���� FROM M_���Ӑ� WHERE �g�p�敪 = 1 AND ���Ӑ�R�[�h < 1000"
          " UNION ALL"
          " SELECT 2 AS ����No, ����1�R�[�h AS �R�[�h,  ����1���� AS ����  FROM M_����1  WHERE �g�p�敪 = 1 AND ����1�R�[�h < 1000"
          " UNION ALL"
          " SELECT 3 AS ����No, ����2�R�[�h AS �R�[�h,  ����2���� AS ����  FROM M_����2  WHERE �g�p�敪 = 1 AND ����2�R�[�h < 1000"
          " UNION ALL"
          " SELECT 4 AS ����No, �i�ڃR�[�h AS �R�[�h,   �i�ږ��� AS ����   FROM M_�i��   WHERE �g�p�敪 = 1 AND �i�ڃR�[�h < 1000";
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("���M���鍀�ڏ�񂪂���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);

        CarsExportButton->Enabled = true;
        ItemExportButton->Enabled = true;
        CloseButton->Enabled      = true;

        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    // �w���v�� ScaM �̍��ڊ��蓖�ă}�b�s���O

    typedef std::map<int, int> CnvTable;
    CnvTable cnv_table;
    cnv_table[ToInt(DM->CFG["�w���v���ڂP"])] = 1;
    cnv_table[ToInt(DM->CFG["�w���v���ڂQ"])] = 2;
    cnv_table[ToInt(DM->CFG["�w���v���ڂR"])] = 3;
    cnv_table[ToInt(DM->CFG["�w���v���ڂS"])] = 4;

    std::vector<AnsiString> raw_records;
    int item_no;
    char wsbuff[100];
    for (unsigned int i = 0; i < set.size(); i++){

        CnvTable::iterator ite;
        ite = cnv_table.find(ToInt(set[i]["����No"]));
        if (ite == cnv_table.end())
            continue;
        item_no = ite->second;

        wsprintf(wsbuff, " %d %03d  %-28s    ",
            item_no, ToInt(set[i]["�R�[�h"]), AnsiSubString(ToString(set[i]["����"]), 1, 28).c_str());
        raw_records.push_back(wsbuff);
    }

    records_.clear();
    
    AnsiString buff;
    char bcc;
    for (unsigned int i = 0; i < raw_records.size(); i++){
        if (i % 3 == 0){
            buff = AnsiString();
            buff = "* CODE ";
        }

        buff += raw_records[i];

        if (i % 3 == 2){
            buff += "*";

            buff[1] = 0x02;             // STX
            buff[buff.Length()] = 0x03; // ETX
            bcc = CalcBCC(buff.c_str() + 1);
            buff += "*";
            buff[buff.Length()] = bcc;

            records_.push_back(buff);
        }
    }

    int remained = 3 - (raw_records.size() % 3);
    if (remained == 2)
        buff += "                                        ";
    if (remained == 2 || remained == 1){
        buff += "                                        ";
        buff += "*";

        buff[1] = 0x02;             // STX
        buff[buff.Length()] = 0x03; // ETX
        bcc = CalcBCC(buff.c_str() + 1);
        buff += "*";
        buff[buff.Length()] = bcc;

        records_.push_back(buff);
    }

    wsprintf(wsbuff, "* END  %04d%04d%112s*",
        records_.size() + 1, raw_records.size(), "  ");

    buff = wsbuff;
    buff[1] = 0x02;             // STX
    buff[buff.Length()] = 0x03; // ETX
    bcc = CalcBCC(buff.c_str() + 1);
    buff += "*";
    buff[buff.Length()] = bcc;
    records_.push_back(buff);

	std::ofstream ofs("itemexport.log");
    for (unsigned int i = 0; i < records_.size(); i++)
        ofs << records_[i].c_str() << std::endl;

    thread_ = new TN95ExportThread(false, port_, def_, Handle, etItem, records_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnCompleted(TMessage& message)
{
	StatusLabel->Caption = "�������܂���";

    delete thread_;
    thread_ = 0;

    ProgressBar->Position = ProgressBar->Max;

    Application->MessageBox("���M���������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    CarsExportButton->Enabled = true;
    ItemExportButton->Enabled = true;
	CloseButton->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnAborted(TMessage& message)
{
    delete thread_;
    thread_ = 0;

    Application->MessageBox("���M�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);

    CarsExportButton->Enabled = true;
    ItemExportButton->Enabled = true;
	CloseButton->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnStatus(TMessage& message)
{
	StatusLabel->Caption = (LPCSTR)(message.LParam);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnDataSended(TMessage& message)
{
	CountLabel->Caption = IntToStr(message.LParam);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnProcessStep(TMessage& message)
{
    ProgressBar->StepIt();
}
//---------------------------------------------------------------------------

