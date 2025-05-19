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
	StatusLabel->Caption = "完了しました";

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

	// データコンバート

    for (unsigned int i = 0; i < received_rec_.size(); i++){
        if (target_ == itID){
            PostRecordID(received_rec_[i]);
        }else if (target_ == itItem){
            PostRecordItem(received_rec_[i]);
        }else
            continue;
    }

	Application->MessageBox("受信が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

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
	// 指示計と ScaM の項目割り当てマッピング
	std::map<int, int> cnv_table;   // map<AD4385項目, ScMマスタ>
	cnv_table[1] = ToInt(DM->CFG["指示計項目１"]);
	cnv_table[2] = ToInt(DM->CFG["指示計項目２"]);
	cnv_table[3] = ToInt(DM->CFG["指示計項目３"]);
	cnv_table[4] = ToInt(DM->CFG["指示計項目４"]);
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
	fields << NsField("[車番]",       car_no)
		   << NsField("[車両名称]",   IntToStr(car_no))
		   << NsField("[空車重量]",   tare)
		   << NsField("[車両総重量]", max)
		   << NsField("[カード番号]", ToInt(DM->CFG["RFID計量"]) ? Variant() : car_no)
		   << NsField("[得意先ID]",   DM->DBI.Lookup("M_得意先", "得意先コード", scm_toku,  "得意先ID"))
		   << NsField("[項目1ID]",    DM->DBI.Lookup("M_項目1",  "項目1コード",  scm_item1, "項目1ID"))
		   << NsField("[項目2ID]",    DM->DBI.Lookup("M_項目2",  "項目2コード",  scm_item2, "項目2ID"))
		   << NsField("[品目ID]",     DM->DBI.Lookup("M_品目",   "品目コード",   scm_meig,  "品目ID"))
		   << NsField("[使用区分]",   1)
		   << NsField("[更新日時]",   now)
		   << NsField("[作成日時]",   now);

	if (!DM->DBI.IsExist("M_車両", "車番", car_no) && car_no > 0)
		DM->DBI.Insert("M_車両", fields);

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
	fields << NsField("[車番]",       car_no)
		   << NsField("[車両名称]",   IntToStr(car_no))
		   << NsField("[空車重量]",   tare)
		   << NsField("[車両総重量]", max)
		   << NsField("[カード番号]", car_no)
		   << NsField("[得意先ID]",   DM->DBI.Lookup("M_得意先", "得意先コード", scm_toku,  "得意先ID"))
		   << NsField("[項目1ID]",    DM->DBI.Lookup("M_項目1",  "項目1コード",  scm_item1, "項目1ID"))
		   << NsField("[項目2ID]",    DM->DBI.Lookup("M_項目2",  "項目2コード",  scm_item2, "項目2ID"))
		   << NsField("[品目ID]",     DM->DBI.Lookup("M_品目",   "品目コード",   scm_meig,  "品目ID"))
		   << NsField("[使用区分]",   1)
		   << NsField("[更新日時]",   now)
		   << NsField("[作成日時]",   now);

	if (!DM->DBI.IsExist("M_車両", "車番", car_no) && car_no > 0)
		DM->DBI.Insert("M_車両", fields);

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
	fields << NsField("[車番]",       car_no)
		   << NsField("[車両名称]",   IntToStr(car_no))
		   << NsField("[空車重量]",   tare)
		   << NsField("[車両総重量]", max)
		   << NsField("[カード番号]", car_no)
		   << NsField("[得意先ID]",   DM->DBI.Lookup("M_得意先", "得意先コード", scm_toku,  "得意先ID"))
		   << NsField("[項目1ID]",    DM->DBI.Lookup("M_項目1",  "項目1コード",  scm_item1, "項目1ID"))
		   << NsField("[項目2ID]",    DM->DBI.Lookup("M_項目2",  "項目2コード",  scm_item2, "項目2ID"))
		   << NsField("[品目ID]",     DM->DBI.Lookup("M_品目",   "品目コード",   scm_meig,  "品目ID"))
		   << NsField("[使用区分]",   1)
		   << NsField("[更新日時]",   now)
		   << NsField("[作成日時]",   now);

	if (!DM->DBI.IsExist("M_車両", "車番", car_no) && car_no > 0)
		DM->DBI.Insert("M_車両", fields);

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
	// 指示計と ScaM の項目割り当てマッピング
	std::map<int, int> cnv_table;   // map<AD4385項目, ScMマスタ>
	cnv_table[1] = ToInt(DM->CFG["指示計項目１"]);
	cnv_table[2] = ToInt(DM->CFG["指示計項目２"]);
	cnv_table[3] = ToInt(DM->CFG["指示計項目３"]);
	cnv_table[4] = ToInt(DM->CFG["指示計項目４"]);

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
		table = "得意先";
	}else if (scm_item_no == 2){
		table = "項目1";
	}else if (scm_item_no == 3){
		table = "項目2";
	}else if (scm_item_no == 4){
		table = "品目";
	}
	fields.clear();
	fields << NsField("[" + table + "コード]", item_code)
		   << NsField("[" + table + "名称]",   item_name)
		   << NsField("[" + table + "略称]",   AnsiSubString(item_name, 1, 20))
		   << NsField("[使用区分]",   1)
		   << NsField("[更新日時]",   now)
		   << NsField("[作成日時]",   now);

    if (scm_item_no == 4)
        fields << NsField("[搬入出区分]", 1);

	if (!DM->DBI.IsExist("M_" + table, table + "コード", item_code) && !(table.IsEmpty()))
		DM->DBI.Insert("M_" + table, fields);

	///// rec 2
	buff       = AnsiSubString(record, 48, 40);
	item_name  = AnsiSubString(buff, 9, 28).Trim();
	buff       = AnsiReplaceStr(buff, " ", "0");

	item_no     = AnsiSubString(buff, 2, 1).ToIntDef(0);
	scm_item_no = cnv_table[item_no];
	item_code   = AnsiSubString(buff, 4, 3).ToIntDef(0);

	if (scm_item_no == 1){
		table = "得意先";
	}else if (scm_item_no == 2){
		table = "項目1";
	}else if (scm_item_no == 3){
		table = "項目2";
	}else if (scm_item_no == 4){
		table = "品目";
	}
	fields.clear();
	fields << NsField("[" + table + "コード]", item_code)
		   << NsField("[" + table + "名称]",   item_name)
		   << NsField("[" + table + "略称]",   AnsiSubString(item_name, 1, 20))
		   << NsField("[使用区分]",   1)
		   << NsField("[更新日時]",   now)
		   << NsField("[作成日時]",   now);

    if (scm_item_no == 4)
        fields << NsField("[搬入出区分]", 1);

	if (!DM->DBI.IsExist("M_" + table, table + "コード", item_code) && !(table.IsEmpty()))
		DM->DBI.Insert("M_" + table, fields);

	///// rec 3
	buff       = AnsiSubString(record, 88, 40);
	item_name   = AnsiSubString(buff, 9, 28).Trim();
	buff       = AnsiReplaceStr(buff, " ", "0");

	item_no     = AnsiSubString(buff, 2, 1).ToIntDef(0);
	scm_item_no = cnv_table[item_no];
	item_code   = AnsiSubString(buff, 4, 3).ToIntDef(0);

	if (scm_item_no == 1){
		table = "得意先";
	}else if (scm_item_no == 2){
		table = "項目1";
	}else if (scm_item_no == 3){
		table = "項目2";
	}else if (scm_item_no == 4){
		table = "品目";
	}
	fields.clear();
	fields << NsField("[" + table + "コード]", item_code)
		   << NsField("[" + table + "名称]",   item_name)
		   << NsField("[" + table + "略称]",   AnsiSubString(item_name, 1, 20))
		   << NsField("[使用区分]",   1)
		   << NsField("[更新日時]",   now)
		   << NsField("[作成日時]",   now);

    if (scm_item_no == 4)
        fields << NsField("[搬入出区分]", 1);

	if (!DM->DBI.IsExist("M_" + table, table + "コード", item_code) && !(table.IsEmpty()))
		DM->DBI.Insert("M_" + table, fields);

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnAborted(TMessage& message)
{
	Application->MessageBox("データ受信に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);

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

