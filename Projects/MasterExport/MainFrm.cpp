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
	// データベースに接続

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
    if (Application->MessageBox("送信すると、指示計側の車両情報がすべてクリアされます！\r\n送信してよろしいですか？",
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
          "     V_車両.車番, V_車両.空車重量, V_車両.最大積載量,"
          "     V_車両.得意先コード, V_車両.項目1コード, V_車両.項目2コード, V_車両.品目コード"
          " FROM ("
          "     SELECT MAX(車両ID) AS 車両ID FROM M_車両"
          "     GROUP BY 車番"
          " ) AS MASTER"
          " INNER JOIN V_車両 ON V_車両.車両ID = MASTER.車両ID AND V_車両.使用区分 = 1"
          " ORDER BY V_車両.車番";
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("送信する車両情報がありません", Caption.c_str(), MB_OK | MB_ICONWARNING);

        CarsExportButton->Enabled = true;
        ItemExportButton->Enabled = true;
        CloseButton->Enabled      = true;

        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    // 指示計と ScaM の項目割り当てマッピング

    int item1_code, item2_code, item3_code, item4_code;
    typedef std::map<int, int *> CnvTable;
    CnvTable cnv_table;
    cnv_table[ToInt(DM->CFG["指示計項目１"])] = &item1_code;
    cnv_table[ToInt(DM->CFG["指示計項目２"])] = &item2_code;
    cnv_table[ToInt(DM->CFG["指示計項目３"])] = &item3_code;
    cnv_table[ToInt(DM->CFG["指示計項目４"])] = &item4_code;

    std::vector<AnsiString> raw_records;
    char wsbuff[100];
    for (unsigned int i = 0; i < set.size(); i++){
        item1_code = item2_code = item3_code = item4_code = 0;

        CnvTable::iterator ite;
        ite = cnv_table.find(1);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["得意先コード"]);
        ite = cnv_table.find(2);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["項目1コード"]);
        ite = cnv_table.find(3);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["項目2コード"]);
        ite = cnv_table.find(4);
        if (ite != cnv_table.end())
            *(ite->second) = ToInt(set[i]["品目コード"]);


        wsprintf(wsbuff, "  %-8d %03d %03d %03d %03d %06d %06d",
            ToInt(set[i]["車番"]),
            item1_code, item2_code, item3_code, item4_code,
            ToInt(set[i]["空車重量"]), ToInt(set[i]["最大積載量"])
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
    if (Application->MessageBox("送信すると、指示計側の項目情報がすべてクリアされます！\r\n送信してよろしいですか？",
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

    sql = " SELECT 1 AS 項目No, 得意先コード AS コード, 得意先名称 AS 名称 FROM M_得意先 WHERE 使用区分 = 1 AND 得意先コード < 1000"
          " UNION ALL"
          " SELECT 2 AS 項目No, 項目1コード AS コード,  項目1名称 AS 名称  FROM M_項目1  WHERE 使用区分 = 1 AND 項目1コード < 1000"
          " UNION ALL"
          " SELECT 3 AS 項目No, 項目2コード AS コード,  項目2名称 AS 名称  FROM M_項目2  WHERE 使用区分 = 1 AND 項目2コード < 1000"
          " UNION ALL"
          " SELECT 4 AS 項目No, 品目コード AS コード,   品目名称 AS 名称   FROM M_品目   WHERE 使用区分 = 1 AND 品目コード < 1000";
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("送信する項目情報がありません", Caption.c_str(), MB_OK | MB_ICONWARNING);

        CarsExportButton->Enabled = true;
        ItemExportButton->Enabled = true;
        CloseButton->Enabled      = true;

        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    // 指示計と ScaM の項目割り当てマッピング

    typedef std::map<int, int> CnvTable;
    CnvTable cnv_table;
    cnv_table[ToInt(DM->CFG["指示計項目１"])] = 1;
    cnv_table[ToInt(DM->CFG["指示計項目２"])] = 2;
    cnv_table[ToInt(DM->CFG["指示計項目３"])] = 3;
    cnv_table[ToInt(DM->CFG["指示計項目４"])] = 4;

    std::vector<AnsiString> raw_records;
    int item_no;
    char wsbuff[100];
    for (unsigned int i = 0; i < set.size(); i++){

        CnvTable::iterator ite;
        ite = cnv_table.find(ToInt(set[i]["項目No"]));
        if (ite == cnv_table.end())
            continue;
        item_no = ite->second;

        wsprintf(wsbuff, " %d %03d  %-28s    ",
            item_no, ToInt(set[i]["コード"]), AnsiSubString(ToString(set[i]["名称"]), 1, 28).c_str());
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
	StatusLabel->Caption = "完了しました";

    delete thread_;
    thread_ = 0;

    ProgressBar->Position = ProgressBar->Max;

    Application->MessageBox("送信が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    CarsExportButton->Enabled = true;
    ItemExportButton->Enabled = true;
	CloseButton->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnAborted(TMessage& message)
{
    delete thread_;
    thread_ = 0;

    Application->MessageBox("送信に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);

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

