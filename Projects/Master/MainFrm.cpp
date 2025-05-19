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
	/*		初期設定		*/
	/****************************************/
	// MainFrm.h(参照) : TADOQuery *query[10];
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

	// MainFrm.h(参照) : TDBGrid *grid[10];
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

	// MainFrm.h(参照) : AnsiString keyfield[10];
	keyfield[0]  = "得意先ID";
	keyfield[1]  = "項目1ID";
	keyfield[2]  = "項目2ID";
	keyfield[3]  = "品目分類ID";
	keyfield[4]  = "品目ID";
	keyfield[5]  = "車両ID";
	keyfield[6]  = "換算ID";
	keyfield[7]  = "拠点ID";
	keyfield[8]  = "単位ID";
	keyfield[9]  = "単価ID";
	keyfield[10] = "伝票情報ID";
	keyfield[11] = "伝票情報関連ID";
	keyfield[12] = "銀行ID";
	keyfield[13] = AnsiString();
	keyfield[14] = AnsiString();
	keyfield[15] = "開始日付";
	keyfield[16] = "項目関連ID";

	// MainFrm.h(参照) : TQuickReport *report[10];
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

	// MainFrm.h(参照) : TCobEdit *search_edit[10];
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

	// MainFrm.h(参照) : TCheckBox check_box[10];
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

	// MainFrm.h(参照) : AnsiString master_name_[10];
	master_name_[0]  = "得意先マスタ";
	master_name_[1]  = "項目1マスタ";
	master_name_[2]  = "項目2マスタ";
	master_name_[3]  = "品目分類マスタ";
	master_name_[4]  = "品目マスタ";
	master_name_[5]  = "車両マスタ";
	master_name_[6]  = "換算マスタ";
	master_name_[7]  = "拠点マスタ";
	master_name_[8]  = "単位マスタ";
	master_name_[9]  = "単価マスタ";
	master_name_[10] = "伝票情報マスタ";
	master_name_[11] = "伝票情報関連マスタ";
	master_name_[12] = "銀行マスタ";
	master_name_[13] = AnsiString();
	master_name_[14] = AnsiString();
	master_name_[15] = "消費税マスタ";
	master_name_[16] = "項目関連マスタ";

	// MainFrm.h(参照) : AnsiString talbe_name_[10];
	table_name_[0]  = "M_得意先";
	table_name_[1]  = "M_項目1";
	table_name_[2]  = "M_項目2";
	table_name_[3]  = "M_品目分類";
	table_name_[4]  = "M_品目";
	table_name_[5]  = "M_車両";
	table_name_[6]  = "M_換算";
	table_name_[7]  = "M_拠点";
	table_name_[8]  = "M_単位";
	table_name_[9]  = "M_単価";
	table_name_[10] = "M_伝票情報";
	table_name_[11] = "M_伝票情報関連";
	table_name_[12] = "M_銀行";
	table_name_[13] = AnsiString();
	table_name_[14] = AnsiString();
	table_name_[15] = "M_消費税";
	table_name_[16] = "M_項目関連";

	// MainFrm.h(参照) : int page_count;
	page_count = 17;

	/*************初期設定終了***************/

	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Connected = false;

	// コンポーネント初期化
	for (int i = 0; i < page_count; i++){
        if (search_edit[i])
    		search_edit[i]->Text  = AnsiString();
		if (check_box[i])
			check_box[i]->Checked = false;
	}

	try{
		// ADO接続
		DM->ADOConnection->Connected = true;
	}catch (Exception& e){
		message_ = "データベース接続に失敗しました\r\n" + e.Message + "\r\n接続ファイルパス：" + DM->ADOConnection->ConnectionString;
		Application->MessageBox(message_.c_str(), "DBエラー", MB_OK | MB_ICONSTOP);
		Close();
	}

	// NsConfig 初期化
	DM->config_.Load(&DM->DBI);

	// 項目名称設定
	SetItem();

	TokuisakiEditForm->StatusBar->Font->Size = 11;

	MainForm->Width  = 1024;
	MainForm->Height = 768;

	MainForm->Resize();

	PageControl->ActivePage = PageControl->Pages[0];
	PageControl->OnChange(PageControl);
	grid[page]->SetFocus();

	PageControl->OnChange(NULL);

	// パラメータによるタブの表示切替
	if (ParamCount() < 1){
		try{
			// テーブルオープン
			for (int i = 0; i < page_count; i++)
				//OpenQuery(i);
				OpenQuery(i, "");
		}catch (Exception& e){
			message_ = "テーブルオープンに失敗しました\r\n" + e.Message;
			Application->MessageBox(message_.c_str(), "DBエラー", MB_OK | MB_ICONSTOP);
			Close();
		}

		// Printer設定 //////////////////////////////////
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
// 新規
void __fastcall TMainForm::Action1Execute(TObject *Sender)
{
	if (page == 0){       // 得意先
		if (TokuisakiEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 1){ // 項目1
		if (Item1EditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 2){ // 項目2
		if (Item2EditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 3){ // 品目分類
		if (HinBunruiEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 4){ // 品目
		if (HinmokuEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 5){ // 車両
		if (SharyoEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 6){ // 換算
		if (KanzanEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 7){ // 拠点
		if (KyotenEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 8){ // 単位
		if (TaniEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 9){ // 単価
		if (TankaEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 10){ // 伝票情報
		if (SlipInfoEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 11){ // 伝票情報関連
		if (SlipInfoRelateEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
        OpenQuery(10, ""); // 20100804 伝票情報も更新できるようにしたので
                           // マスタも更新しておく
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 12){ // 銀行
		if (BankEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
/*
	}else if (page == 13){ // 科目
		if (KamokuEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 14){ // 補助簿
		if (HojoboEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
*/
	}else if (page == 15){ // 消費税
		if (TaxEditForm->ShowModalWithId(0) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 16){ // 項目関連
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
// 修正
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	if (query[page]->Bof && query[page]->Eof){
		Application->MessageBox("修正するデータがありません",
			"修正", MB_OK | MB_ICONINFORMATION);
		return;
	}

	if (page == 0){       // 得意先
		if (TokuisakiEditForm->ShowModalWithId(query[page]->FieldByName("得意先ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 1){ // 項目1
		if (Item1EditForm->ShowModalWithId(query[page]->FieldByName("項目1ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 2){ // 項目2
		if (Item2EditForm->ShowModalWithId(query[page]->FieldByName("項目2ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 3){ // 品目分類
		if (HinBunruiEditForm->ShowModalWithId(query[page]->FieldByName("品目分類ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 4){ // 品目
		if (HinmokuEditForm->ShowModalWithId(query[page]->FieldByName("品目ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 5){ // 車両
		if (SharyoEditForm->ShowModalWithId(query[page]->FieldByName("車両ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 6){ // 換算
		if (KanzanEditForm->ShowModalWithId(query[page]->FieldByName("換算ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 7){ // 拠点
		if (KyotenEditForm->ShowModalWithId(query[page]->FieldByName("拠点ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 8){ // 単位
		if (TaniEditForm->ShowModalWithId(query[page]->FieldByName("単位ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 9){ // 単価
		if (TankaEditForm->ShowModalWithId(query[page]->FieldByName("単価ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 10){ // 伝票情報
		if (SlipInfoEditForm->ShowModalWithId(query[page]->FieldByName("伝票情報ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 11){ // 伝票情報関連
		if (SlipInfoRelateEditForm->ShowModalWithId(query[page]->FieldByName("伝票情報関連ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
        OpenQuery(10, ""); // 20100804 伝票情報も更新できるようにしたので
                           // マスタも更新しておく
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 12){ // 銀行
		if (BankEditForm->ShowModalWithId(query[page]->FieldByName("銀行ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
/*
	}else if (page == 13){ // 科目
		if (KamokuEditForm->ShowModalWithId(query[page]->FieldByName("科目ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 14){ // 補助簿
		if (HojoboEditForm->ShowModalWithId(query[page]->FieldByName("補助簿ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page);
		Application->OnMessage = this->MessageProc;
		return;
*/
	}else if (page == 15){ // 消費税
		if (TaxEditForm->ShowModalWithId(query[page]->FieldByName("開始日付")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}else if (page == 16){ // 項目関連
		if (ItemRelateEditForm->ShowModalWithId(query[page]->FieldByName("項目関連ID")->AsInteger) != mrOk){
			Application->OnMessage = this->MessageProc;
			return;
		}
		OpenQuery(page, "");
		Application->OnMessage = this->MessageProc;
		return;
	}
}
//---------------------------------------------------------------------------
// 削除
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
	NsFieldSet fields, keys;
	try{
        if (page == 10){ // 伝票情報マスタ
            int slipinfo_id = query[page]->FieldByName("伝票情報ID")->AsInteger;

            if (slipinfo_id == 1){
                Application->MessageBox("このデータは削除できません", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
                return;
            }
        }

        if (page == 11){ // 伝票情報関連マスタ
            int item_no     = query[page]->FieldByName("項目番号")->AsInteger;
            int item_id     = query[page]->FieldByName("項目ID")->AsInteger;
            int slipinfo_id = query[page]->FieldByName("伝票情報ID")->AsInteger;

            if (item_no == 0 && item_id == 0 && slipinfo_id == 1){
                Application->MessageBox("このデータは削除できません", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
                return;
            }
        }

        //if (page == 6 || page == 7 || page == 8 || page == 9){ // 換算・拠点・単位・単価の時
        if (page >= 6){ //////// 換算・拠点・単位・単価の時

            if (Application->MessageBox("本当に削除してもよろしいですか？", "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
                return;

            if (grid[page]->SelectedRows->Count == 0){
                // １件削除
                keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
                DM->DBI.Delete(table_name_[page], keys);
            }else{
                // 複数削除
                for (int count = 0; count < grid[page]->SelectedRows->Count; count++){
                    grid[page]->DataSource->DataSet->GotoBookmark((void *)grid[page]->SelectedRows->Items[count].c_str());

                    keys.clear();
                    keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
                    DM->DBI.Delete(table_name_[page], keys);
                }
            }
            Application->MessageBox("削除しました", "削除", MB_OK | MB_ICONINFORMATION);

        }else{      //////// その他マスタの時

            if (query[page]->FieldByName("使用区分")->AsInteger == 1){
                if (Application->MessageBox("このデータを使用出来なくなります。よろしいですか？\r\nなお、本当に削除する場合は一度この処理を行なった後\r\nもう一度削除ボタンをクリックして下さい",
					"削除", MB_YESNO | MB_ICONQUESTION) == IDNO)
					return;
				if (grid[page]->SelectedRows->Count == 0){
					try{
						fields << NsField("[使用区分]", 0);
						DM->DBI.Update(table_name_[page], keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger, fields);
					}catch (Exception &e){
						Application->MessageBox(("更新に失敗しました\r\n" + e.Message).c_str(),
							"削除", MB_OK | MB_ICONINFORMATION);
						return;
					}
				}else{
					for (int count = 0; count < grid[page]->SelectedRows->Count; count++){
						grid[page]->DataSource->DataSet->GotoBookmark((void *)grid[page]->SelectedRows->Items[count].c_str());

						fields.clear();
						fields << NsField("[使用区分]", 0);
						DM->DBI.Update(table_name_[page], keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger, fields);
					}
				}
				Application->MessageBox("使用区分を変更しました\r\n再度使用する際には使用区分を変更して下さい",
					"削除", MB_OK | MB_ICONINFORMATION);
			}else{
				if (Application->MessageBox("本当に削除してもよろしいですか？",
					"削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
					return;
				if (grid[page]->SelectedRows->Count == 0){
					// １件削除
					keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
					DM->DBI.Delete(table_name_[page], keys);

                    // 得意先、項目1、項目2、品目マスタのみ処理
                    if (page == 0 || page == 1 || page == 2 || page == 4)
                        DM->DeleteRelateMaster(page, keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
				}else{
					// 複数削除
					for (int count = 0; count < grid[page]->SelectedRows->Count; count++){
						grid[page]->DataSource->DataSet->GotoBookmark((void *)grid[page]->SelectedRows->Items[count].c_str());

						keys.clear();
						keys << NsField(keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
						DM->DBI.Delete(table_name_[page], keys);

                        // 得意先、項目1、項目2、品目マスタのみ処理
                        if (page == 0 || page == 1 || page == 2 || page == 4)
                            DM->DeleteRelateMaster(page, keyfield[page], query[page]->FieldByName(keyfield[page])->AsInteger);
                    }
				}
			    Application->MessageBox("削除しました", "削除", MB_OK | MB_ICONINFORMATION);
			}
		}
	}catch (Exception &e){
		Application->MessageBox(("削除に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
	}
	OpenQuery(page, "");
}
//---------------------------------------------------------------------------
// 参照
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
// ソート設定
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
// 印刷
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (Application->MessageBox("印刷しますか？", "印刷", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	if (report[page] == NULL)
		return;
	report[page]->Print();
}
//---------------------------------------------------------------------------
// プレビュー
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (report[page] == NULL)
		return;
	report[page]->Preview();
}
//---------------------------------------------------------------------------
// 出力
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (Application->MessageBox("出力しますか？", "出力", MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;
	if (query[page]->Bof && query[page]->Eof){
		Application->MessageBox("データがありません", "出力処理", MB_OK | MB_ICONINFORMATION);
		return;
	}

	std::auto_ptr<TStringList> Records(new TStringList());
	Table2Str(query[page], Records.get(), true);
	SaveDialog->FileName = master_name_[page] + "_" + Date().FormatString("yyyymmdd") + ".csv";
	if (SaveDialog->Execute()){
		Records->SaveToFile(SaveDialog->FileName);
		Application->MessageBox("完了しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}else{
		Application->MessageBox("キャンセルされました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------
// 終了
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
// 項目ソートは実装したいなぁ
void __fastcall TMainForm::DBGrid1TitleClick(TColumn *Column)
{
    //
}
//---------------------------------------------------------------------------
// Windowリサイズ
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
// 前のタブ
void __fastcall TMainForm::PagePriorExecute(TObject *Sender)
{
	if (PageControl->ActivePageIndex == 0)
		PageControl->ActivePageIndex = PageControl->PageCount - 1;
	else
		PageControl->ActivePageIndex--;
	PageControl->OnChange(PageControl);
}
//---------------------------------------------------------------------------
// 次のタブ
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
			//ホイールマウスのイベントで上下に動くように設定
			if((short)HIWORD(Msg.wParam) > 0){
				grid[page]->DataSource->DataSet->Prior();
			}else{
				grid[page]->DataSource->DataSet->Next();
			}
			//処理はここでストップさせる
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
	case 0:  // 得意先
		query[p]->SQL->Text = DM->GetTokuisakiQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 1:  // 項目1
		query[p]->SQL->Text = DM->GetItem1Query(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 2:  // 現場2
		query[p]->SQL->Text = DM->GetItem2Query(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 3:  // 品目分類
		query[p]->SQL->Text = DM->GetHinBunruiQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 4:  // 品目
		query[p]->SQL->Text = DM->GetHinmokuQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 5:  // 車両
		query[p]->SQL->Text = DM->GetSharyoQuery(search_edit[p]->Text, check_box[p]->Checked, order);
		break;
	case 6:  // 換算
		query[p]->SQL->Text = DM->GetKanzanQuery(search_edit[p]->Text, order);
		break;
	case 7:  // 拠点
		query[p]->SQL->Text = DM->GetKyotenQuery(search_edit[p]->Text, order);
		break;
	case 8:  // 単位
		query[p]->SQL->Text = DM->GetTaniQuery(search_edit[p]->Text, order);
		break;
	case 9:  // 単価
		query[p]->SQL->Text = DM->GetTankaQuery(search_edit[p]->Text, order);
		break;
	case 10:  // 伝票情報
		query[p]->SQL->Text = DM->GetSlipInfoQuery(search_edit[p]->Text, order);
		break;
	case 11:  // 伝票情報関連
		query[p]->SQL->Text = DM->GetSlipInfoRelateQuery(search_edit[p]->Text, order);
		break;
	case 12:  // 銀行
		query[p]->SQL->Text = DM->GetBankQuery(search_edit[p]->Text, order);
		break;
/*
	case 13:  // 科目
		query[p]->SQL->Text = DM->GetKamokuQuery(search_edit[p]->Text, order);
		break;
	case 14:  // 補助簿
		query[p]->SQL->Text = DM->GetHojoboQuery(search_edit[p]->Text, order);
		break;
*/
	case 15:  // 消費税
		query[p]->SQL->Text = DM->GetTaxQuery(search_edit[p]->Text, order);
		break;
	case 16:  // 項目関連
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
	// 得意先
	AnsiString toku = AnsiReplaceStr(ToString(DM->config_["得意先マスタ名称"]), " ", "");
	toku = AnsiReplaceStr(toku, "　", "");
	toku_ = toku;
	if (ToString(DM->config_["得意先マスタ使用区分"]) == "1"){
		TabSheet1->Caption = ToString(DM->config_["得意先マスタ名称"]);
		DBGrid1->Columns->Items[0]->Title->Caption  = toku + "コード";
		DBGrid1->Columns->Items[1]->Title->Caption  = toku + "名称";
		DBGrid1->Columns->Items[2]->Title->Caption  = toku + "略称";
		DBGrid1->Columns->Items[3]->Title->Caption  = toku + "カナ";
		DBGrid6->Columns->Items[6]->Title->Caption  = toku + "略称";
		DBGrid7->Columns->Items[1]->Title->Caption  = toku + "略称";
		DBGrid10->Columns->Items[1]->Title->Caption = toku + "略称";
		DBGrid17->Columns->Items[4]->Title->Caption = toku + "コード";
		DBGrid17->Columns->Items[5]->Title->Caption = toku + "略称";

		TokuisakiEditForm->Caption = toku + "登録／修正";
		QRTokuisakiForm->TitleLabel->Caption = toku + "マスタ一覧";
		QRSharyoForm->TokuisakiLabel->Caption = toku;
		QRKanzanForm->TokuisakiLabel->Caption = toku;
		QRTankaForm->TokuisakiLabel->Caption = toku;
		KanzanEditForm->TokuisakiLabel->Caption = toku;
		SharyoEditForm->TokuisakiLabel->Caption = toku;
		TankaEditForm->TokuisakiLabel->Caption  = toku;
        ItemRelateEditForm->TokuisakiLabel->Caption = toku;
        QRItemRelateForm->TokuisakiNameLabel->Caption = toku;

		DM->M_Tokuisaki->Fields->Fields[0]->DisplayLabel = toku + "ID";
		DM->M_Tokuisaki->Fields->Fields[1]->DisplayLabel = toku + "コード";
		DM->M_Tokuisaki->Fields->Fields[2]->DisplayLabel = toku + "名称";
		DM->M_Tokuisaki->Fields->Fields[3]->DisplayLabel = toku + "略称";
		DM->M_Tokuisaki->Fields->Fields[4]->DisplayLabel = toku + "カナ";

		DM->M_Sharyo->Fields->Fields[6]->DisplayLabel = toku + "ID";
		DM->M_Sharyo->Fields->Fields[7]->DisplayLabel = toku + "コード";
		DM->M_Sharyo->Fields->Fields[8]->DisplayLabel = toku + "名称";
		DM->M_Sharyo->Fields->Fields[9]->DisplayLabel = toku + "略称";

		DM->M_Kanzan->Fields->Fields[1]->DisplayLabel = toku + "ID";
		DM->M_Kanzan->Fields->Fields[2]->DisplayLabel = toku + "コード";
		DM->M_Kanzan->Fields->Fields[3]->DisplayLabel = toku + "名称";
		DM->M_Kanzan->Fields->Fields[4]->DisplayLabel = toku + "略称";

		DM->M_Tanka->Fields->Fields[1]->DisplayLabel = toku + "ID";
		DM->M_Tanka->Fields->Fields[2]->DisplayLabel = toku + "コード";
		DM->M_Tanka->Fields->Fields[3]->DisplayLabel = toku + "名称";
		DM->M_Tanka->Fields->Fields[4]->DisplayLabel = toku + "略称";

        DM->M_ItemRelate->Fields->Fields[7]->DisplayLabel  = toku + "ID";
        DM->M_ItemRelate->Fields->Fields[8]->DisplayLabel  = toku + "コード";
        DM->M_ItemRelate->Fields->Fields[9]->DisplayLabel  = toku + "名称";
        DM->M_ItemRelate->Fields->Fields[10]->DisplayLabel = toku + "略称";
	}else{
		TabSheet1->Caption = "未使用";
		DBGrid1->Columns->Items[0]->Title->Caption  = "未使用";
		DBGrid1->Columns->Items[1]->Title->Caption  = "未使用";
		DBGrid1->Columns->Items[2]->Title->Caption  = "未使用";
		DBGrid1->Columns->Items[3]->Title->Caption  = "未使用";
		DBGrid6->Columns->Items[6]->Title->Caption  = "未使用";
		DBGrid7->Columns->Items[1]->Title->Caption  = "未使用";
		DBGrid10->Columns->Items[1]->Title->Caption = "未使用";
        DBGrid17->Columns->Items[4]->Title->Caption = "未使用";
        DBGrid17->Columns->Items[5]->Title->Caption = "未使用";

		TokuisakiEditForm->Caption                = "未使用";
		QRTokuisakiForm->TitleLabel->Caption      = "未使用";
		QRSharyoForm->TokuisakiLabel->Caption     = "未使用";
		QRKanzanForm->TokuisakiLabel->Caption     = "未使用";
		QRTankaForm->TokuisakiLabel->Caption      = "未使用";
		KanzanEditForm->TokuisakiLabel->Caption   = "未使用";
		SharyoEditForm->TokuisakiLabel->Caption   = "未使用";
		TankaEditForm->TokuisakiLabel->Caption    = "未使用";
        ItemRelateEditForm->TokuisakiLabel->Caption   = "未使用";
        QRItemRelateForm->TokuisakiNameLabel->Caption = "未使用";

		DM->M_Tokuisaki->Fields->Fields[0]->DisplayLabel = "未使用";
		DM->M_Tokuisaki->Fields->Fields[1]->DisplayLabel = "未使用";
		DM->M_Tokuisaki->Fields->Fields[2]->DisplayLabel = "未使用";
		DM->M_Tokuisaki->Fields->Fields[3]->DisplayLabel = "未使用";
		DM->M_Tokuisaki->Fields->Fields[4]->DisplayLabel = "未使用";

		DM->M_Sharyo->Fields->Fields[6]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[7]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[8]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[9]->DisplayLabel = "未使用";

		DM->M_Kanzan->Fields->Fields[1]->DisplayLabel = "未使用";
		DM->M_Kanzan->Fields->Fields[2]->DisplayLabel = "未使用";
		DM->M_Kanzan->Fields->Fields[3]->DisplayLabel = "未使用";
		DM->M_Kanzan->Fields->Fields[4]->DisplayLabel = "未使用";

		DM->M_Tanka->Fields->Fields[1]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[2]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[3]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[4]->DisplayLabel = "未使用";

        DM->M_ItemRelate->Fields->Fields[7]->DisplayLabel  = "未使用";
        DM->M_ItemRelate->Fields->Fields[8]->DisplayLabel  = "未使用";
        DM->M_ItemRelate->Fields->Fields[9]->DisplayLabel  = "未使用";
        DM->M_ItemRelate->Fields->Fields[10]->DisplayLabel = "未使用";
	}

	// 項目1
	AnsiString item1 = AnsiReplaceStr(ToString(DM->config_["項目1マスタ名称"]), " ", "");
	item1 = AnsiReplaceStr(item1, "　", "");
    item1_= item1;
	if (ToString(DM->config_["項目1マスタ使用区分"]) == "1"){
		TabSheet2->Caption = ToString(DM->config_["項目1マスタ名称"]);
		DBGrid2->Columns->Items[0]->Title->Caption  = item1 + "コード";
		DBGrid2->Columns->Items[1]->Title->Caption  = item1 + "名称";
		DBGrid2->Columns->Items[2]->Title->Caption  = item1 + "略称";
		DBGrid2->Columns->Items[3]->Title->Caption  = item1 + "カナ";
		DBGrid6->Columns->Items[8]->Title->Caption  = item1 + "略称";
		DBGrid10->Columns->Items[5]->Title->Caption = item1 + "略称";
        DBGrid17->Columns->Items[6]->Title->Caption = item1 + "コード";
        DBGrid17->Columns->Items[7]->Title->Caption = item1 + "略称";

		Item1EditForm->Caption = item1 + "登録／修正";
		QRItem1Form->TitleLabel->Caption = item1 + "マスタ一覧";
		QRSharyoForm->Item1Label->Caption = item1;
		QRTankaForm->Item1Label->Caption = item1;
		SharyoEditForm->Item1Label->Caption = item1;
		TankaEditForm->Item1Label->Caption  = item1;
        ItemRelateEditForm->Item1Label->Caption = item1;
        QRItemRelateForm->Item1NameLabel->Caption = item1;

		DM->M_Item1->Fields->Fields[0]->DisplayLabel = item1 + "ID";
		DM->M_Item1->Fields->Fields[1]->DisplayLabel = item1 + "コード";
		DM->M_Item1->Fields->Fields[2]->DisplayLabel = item1 + "名称";
		DM->M_Item1->Fields->Fields[3]->DisplayLabel = item1 + "略称";
		DM->M_Item1->Fields->Fields[4]->DisplayLabel = item1 + "カナ";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = item1 + "ID";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = item1 + "コード";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = item1 + "名称";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = item1 + "略称";

		DM->M_Tanka->Fields->Fields[9]->DisplayLabel  = item1 + "ID";
		DM->M_Tanka->Fields->Fields[10]->DisplayLabel = item1 + "コード";
		DM->M_Tanka->Fields->Fields[11]->DisplayLabel = item1 + "名称";
		DM->M_Tanka->Fields->Fields[12]->DisplayLabel = item1 + "略称";

        DM->M_ItemRelate->Fields->Fields[11]->DisplayLabel = item1 + "ID";
        DM->M_ItemRelate->Fields->Fields[12]->DisplayLabel = item1 + "コード";
        DM->M_ItemRelate->Fields->Fields[13]->DisplayLabel = item1 + "名称";
        DM->M_ItemRelate->Fields->Fields[14]->DisplayLabel = item1 + "略称";
	}else{
		TabSheet2->Caption = "未使用";
		DBGrid2->Columns->Items[0]->Title->Caption  = "未使用";
		DBGrid2->Columns->Items[1]->Title->Caption  = "未使用";
		DBGrid2->Columns->Items[2]->Title->Caption  = "未使用";
		DBGrid2->Columns->Items[3]->Title->Caption  = "未使用";
		DBGrid6->Columns->Items[8]->Title->Caption  = "未使用";
		DBGrid10->Columns->Items[5]->Title->Caption = "未使用";
        DBGrid17->Columns->Items[6]->Title->Caption = "未使用";
        DBGrid17->Columns->Items[7]->Title->Caption = "未使用";

		Item1EditForm->Caption = "未使用";
		QRItem1Form->TitleLabel->Caption = "未使用";
		QRSharyoForm->Item1Label->Caption = "未使用";
		QRTankaForm->Item1Label->Caption = "未使用";
		SharyoEditForm->Item1Label->Caption = "未使用";
		TankaEditForm->Item1Label->Caption  = "未使用";
        ItemRelateEditForm->Item1Label->Caption = "未使用";
        QRItemRelateForm->Item1NameLabel->Caption = "未使用";

		DM->M_Item1->Fields->Fields[0]->DisplayLabel = "未使用";
		DM->M_Item1->Fields->Fields[1]->DisplayLabel = "未使用";
		DM->M_Item1->Fields->Fields[2]->DisplayLabel = "未使用";
		DM->M_Item1->Fields->Fields[3]->DisplayLabel = "未使用";
		DM->M_Item1->Fields->Fields[4]->DisplayLabel = "未使用";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = "未使用";

		DM->M_Tanka->Fields->Fields[9]->DisplayLabel  = "未使用";
		DM->M_Tanka->Fields->Fields[10]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[11]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[12]->DisplayLabel = "未使用";

        DM->M_ItemRelate->Fields->Fields[11]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[12]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[13]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[14]->DisplayLabel = "未使用";
	}

	// 項目2
	AnsiString item2 = AnsiReplaceStr(ToString(DM->config_["項目2マスタ名称"]), " ", "");
	item2 = AnsiReplaceStr(item2, "　", "");
      item2_ = item2;
	if (ToString(DM->config_["項目2マスタ使用区分"]) == "1"){
		TabSheet3->Caption = ToString(DM->config_["項目2マスタ名称"]);
		DBGrid3->Columns->Items[0]->Title->Caption  = item2 + "コード";
		DBGrid3->Columns->Items[1]->Title->Caption  = item2 + "名称";
		DBGrid3->Columns->Items[2]->Title->Caption  = item2 + "略称";
		DBGrid3->Columns->Items[3]->Title->Caption  = item2 + "カナ";
		DBGrid6->Columns->Items[10]->Title->Caption = item2 + "略称";
		DBGrid10->Columns->Items[7]->Title->Caption = item2 + "略称";
        DBGrid17->Columns->Items[8]->Title->Caption = item2 + "コード";
        DBGrid17->Columns->Items[9]->Title->Caption = item2 + "略称";

		Item2EditForm->Caption = item2 + "登録／修正";
		QRItem2Form->TitleLabel->Caption = item2 + "マスタ一覧";
		QRSharyoForm->Item2Label->Caption = item2;
		QRTankaForm->Item2Label->Caption = item2;
		SharyoEditForm->Item2Label->Caption = item2;
		TankaEditForm->Item2Label->Caption  = item2;
        ItemRelateEditForm->Item2Label->Caption = item2;
        QRItemRelateForm->Item2NameLabel->Caption = item2;

		DM->M_Item2->Fields->Fields[0]->DisplayLabel = item2 + "ID";
		DM->M_Item2->Fields->Fields[1]->DisplayLabel = item2 + "コード";
		DM->M_Item2->Fields->Fields[2]->DisplayLabel = item2 + "名称";
		DM->M_Item2->Fields->Fields[3]->DisplayLabel = item2 + "略称";
		DM->M_Item2->Fields->Fields[4]->DisplayLabel = item2 + "カナ";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = item2 + "ID";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = item2 + "コード";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = item2 + "名称";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = item2 + "略称";

		DM->M_Tanka->Fields->Fields[13]->DisplayLabel = item2 + "ID";
		DM->M_Tanka->Fields->Fields[14]->DisplayLabel = item2 + "コード";
		DM->M_Tanka->Fields->Fields[15]->DisplayLabel = item2 + "名称";
		DM->M_Tanka->Fields->Fields[16]->DisplayLabel = item2 + "略称";

        DM->M_ItemRelate->Fields->Fields[15]->DisplayLabel = item2 + "ID";
        DM->M_ItemRelate->Fields->Fields[16]->DisplayLabel = item2 + "コード";
        DM->M_ItemRelate->Fields->Fields[17]->DisplayLabel = item2 + "名称";
        DM->M_ItemRelate->Fields->Fields[18]->DisplayLabel = item2 + "略称";
	}else{
		TabSheet3->Caption = "未使用";
		DBGrid3->Columns->Items[0]->Title->Caption = "未使用";
		DBGrid3->Columns->Items[1]->Title->Caption = "未使用";
		DBGrid3->Columns->Items[2]->Title->Caption = "未使用";
		DBGrid3->Columns->Items[3]->Title->Caption = "未使用";
		DBGrid6->Columns->Items[10]->Title->Caption = "未使用";
		DBGrid10->Columns->Items[7]->Title->Caption = "未使用";
        DBGrid17->Columns->Items[8]->Title->Caption = "未使用";
        DBGrid17->Columns->Items[9]->Title->Caption = "未使用";

		Item2EditForm->Caption = "未使用";
		QRItem2Form->TitleLabel->Caption = "未使用";
		QRSharyoForm->Item2Label->Caption = "未使用";
		QRTankaForm->Item2Label->Caption = "未使用";
		SharyoEditForm->Item2Label->Caption = "未使用";
		TankaEditForm->Item2Label->Caption  = "未使用";
        ItemRelateEditForm->Item2Label->Caption = "未使用";
        QRItemRelateForm->Item2NameLabel->Caption = "未使用";

		DM->M_Item2->Fields->Fields[0]->DisplayLabel = "未使用";
		DM->M_Item2->Fields->Fields[1]->DisplayLabel = "未使用";
		DM->M_Item2->Fields->Fields[2]->DisplayLabel = "未使用";
		DM->M_Item2->Fields->Fields[3]->DisplayLabel = "未使用";
		DM->M_Item2->Fields->Fields[4]->DisplayLabel = "未使用";

		DM->M_Sharyo->Fields->Fields[10]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[11]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[12]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[13]->DisplayLabel = "未使用";

		DM->M_Tanka->Fields->Fields[13]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[14]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[15]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[16]->DisplayLabel = "未使用";

        DM->M_ItemRelate->Fields->Fields[15]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[16]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[17]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[18]->DisplayLabel = "未使用";
	}

	// 品目分類
	AnsiString hinbun = AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]), " ", "");
	hinbun = AnsiReplaceStr(hinbun, "　", "");
      hinbun_ = hinbun;
	if (ToString(DM->config_["品目マスタ使用区分"]) == "1"){
		TabSheet4->Caption = hinbun + "分類";
		DBGrid4->Columns->Items[0]->Title->Caption = hinbun + "分類コード";
		DBGrid4->Columns->Items[1]->Title->Caption = hinbun + "分類名称";
		DBGrid4->Columns->Items[2]->Title->Caption = hinbun + "分類略称";
		DBGrid4->Columns->Items[3]->Title->Caption = hinbun + "分類カナ";
		DBGrid5->Columns->Items[7]->Title->Caption = hinbun + "分類";

		HinBunruiEditForm->Caption = hinbun + "分類登録／修正";
		QRHinBunruiForm->TitleLabel->Caption = hinbun + "分類マスタ一覧";
		QRHinmokuForm->HinBunruiLabel->Caption = hinbun + "分類";
		HinmokuEditForm->HinBunruiLabel->Caption = hinbun + "分類";

		DM->M_HinBunrui->Fields->Fields[0]->DisplayLabel = hinbun + "分類ID";
		DM->M_HinBunrui->Fields->Fields[1]->DisplayLabel = hinbun + "分類コード";
		DM->M_HinBunrui->Fields->Fields[2]->DisplayLabel = hinbun + "分類名称";
		DM->M_HinBunrui->Fields->Fields[3]->DisplayLabel = hinbun + "分類略称";
		DM->M_HinBunrui->Fields->Fields[4]->DisplayLabel = hinbun + "分類カナ";

		DM->M_Hinmoku->Fields->Fields[7]->DisplayLabel = hinbun + "分類ID";
		DM->M_Hinmoku->Fields->Fields[8]->DisplayLabel = hinbun + "分類コード";
		DM->M_Hinmoku->Fields->Fields[9]->DisplayLabel = hinbun + "分類名称";
		DM->M_Hinmoku->Fields->Fields[10]->DisplayLabel = hinbun + "分類略称";
	}else{
		TabSheet4->Caption = "未使用";
		DBGrid4->Columns->Items[0]->Title->Caption = "未使用";
		DBGrid4->Columns->Items[1]->Title->Caption = "未使用";
		DBGrid4->Columns->Items[2]->Title->Caption = "未使用";
		DBGrid4->Columns->Items[3]->Title->Caption = "未使用";
		DBGrid5->Columns->Items[7]->Title->Caption = "未使用";

		HinBunruiEditForm->Caption = "未使用";
		QRHinBunruiForm->TitleLabel->Caption = "未使用";
		QRHinmokuForm->HinBunruiLabel->Caption = "未使用";
		HinmokuEditForm->HinBunruiLabel->Caption = "未使用";

		DM->M_HinBunrui->Fields->Fields[0]->DisplayLabel = "未使用";
		DM->M_HinBunrui->Fields->Fields[1]->DisplayLabel = "未使用";
		DM->M_HinBunrui->Fields->Fields[2]->DisplayLabel = "未使用";
		DM->M_HinBunrui->Fields->Fields[3]->DisplayLabel = "未使用";
		DM->M_HinBunrui->Fields->Fields[4]->DisplayLabel = "未使用";

		DM->M_Hinmoku->Fields->Fields[7]->DisplayLabel = "未使用";
		DM->M_Hinmoku->Fields->Fields[8]->DisplayLabel = "未使用";
		DM->M_Hinmoku->Fields->Fields[9]->DisplayLabel = "未使用";
		DM->M_Hinmoku->Fields->Fields[10]->DisplayLabel = "未使用";
	}

	// 品目
	AnsiString hin = AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]), " ", "");
	hin  = AnsiReplaceStr(hin, "　", "");
    hin_ = hin;
	if (ToString(DM->config_["品目マスタ使用区分"]) == "1"){
		TabSheet5->Caption = ToString(DM->config_["品目マスタ名称"]);
		DBGrid5->Columns->Items[0]->Title->Caption   = hin + "コード";
		DBGrid5->Columns->Items[1]->Title->Caption   = hin + "名称";
		DBGrid5->Columns->Items[2]->Title->Caption   = hin + "略称";
		DBGrid5->Columns->Items[3]->Title->Caption   = hin + "カナ";
		DBGrid6->Columns->Items[12]->Title->Caption  = hin + "略称";
		DBGrid7->Columns->Items[3]->Title->Caption   = hin + "略称";
		DBGrid10->Columns->Items[3]->Title->Caption  = hin + "略称";
        DBGrid17->Columns->Items[10]->Title->Caption = hin + "コード";
        DBGrid17->Columns->Items[11]->Title->Caption = hin + "略称";

		HinmokuEditForm->Caption = hin + "登録／修正";
		QRHinmokuForm->TitleLabel->Caption = hin + "マスタ一覧";
		QRSharyoForm->HinmokuLabel->Caption = hin;
		QRKanzanForm->HinmokuLabel->Caption = hin;
		QRTankaForm->HinmokuLabel->Caption = hin;
		KanzanEditForm->HinmokuLabel->Caption = hin;
		SharyoEditForm->HinmokuLabel->Caption = hin;
		TankaEditForm->HinmokuLabel->Caption  = hin;
        ItemRelateEditForm->HinmokuLabel->Caption = hin;
        QRItemRelateForm->HinmokuNameLabel->Caption = hin;

		DM->M_Hinmoku->Fields->Fields[0]->DisplayLabel = hin + "ID";
		DM->M_Hinmoku->Fields->Fields[1]->DisplayLabel = hin + "コード";
		DM->M_Hinmoku->Fields->Fields[2]->DisplayLabel = hin + "名称";
		DM->M_Hinmoku->Fields->Fields[3]->DisplayLabel = hin + "略称";
		DM->M_Hinmoku->Fields->Fields[4]->DisplayLabel = hin + "カナ";

		DM->M_Sharyo->Fields->Fields[18]->DisplayLabel = hin + "ID";
		DM->M_Sharyo->Fields->Fields[19]->DisplayLabel = hin + "コード";
		DM->M_Sharyo->Fields->Fields[20]->DisplayLabel = hin + "名称";
		DM->M_Sharyo->Fields->Fields[21]->DisplayLabel = hin + "略称";

		DM->M_Kanzan->Fields->Fields[5]->DisplayLabel = hin + "ID";
		DM->M_Kanzan->Fields->Fields[6]->DisplayLabel = hin + "コード";
		DM->M_Kanzan->Fields->Fields[7]->DisplayLabel = hin + "名称";
		DM->M_Kanzan->Fields->Fields[8]->DisplayLabel = hin + "略称";

		DM->M_Tanka->Fields->Fields[5]->DisplayLabel = hin + "ID";
		DM->M_Tanka->Fields->Fields[6]->DisplayLabel = hin + "コード";
		DM->M_Tanka->Fields->Fields[7]->DisplayLabel = hin + "名称";
		DM->M_Tanka->Fields->Fields[8]->DisplayLabel = hin + "略称";

        DM->M_ItemRelate->Fields->Fields[19]->DisplayLabel = hin + "ID";
        DM->M_ItemRelate->Fields->Fields[20]->DisplayLabel = hin + "コード";
        DM->M_ItemRelate->Fields->Fields[21]->DisplayLabel = hin + "名称";
        DM->M_ItemRelate->Fields->Fields[22]->DisplayLabel = hin + "略称";
	}else{
		TabSheet5->Caption = "未使用";
		DBGrid5->Columns->Items[0]->Title->Caption   = "未使用";
		DBGrid5->Columns->Items[1]->Title->Caption   = "未使用";
		DBGrid5->Columns->Items[2]->Title->Caption   = "未使用";
		DBGrid5->Columns->Items[3]->Title->Caption   = "未使用";
		DBGrid6->Columns->Items[12]->Title->Caption  = "未使用";
		DBGrid7->Columns->Items[3]->Title->Caption   = "未使用";
		DBGrid10->Columns->Items[3]->Title->Caption  = "未使用";
        DBGrid17->Columns->Items[10]->Title->Caption = "未使用";
        DBGrid17->Columns->Items[11]->Title->Caption = "未使用";

		HinmokuEditForm->Caption = "未使用";
		QRHinmokuForm->TitleLabel->Caption = "未使用";
		QRSharyoForm->HinmokuLabel->Caption = "未使用";
		QRKanzanForm->HinmokuLabel->Caption = "未使用";
		QRTankaForm->HinmokuLabel->Caption = "未使用";
		KanzanEditForm->HinmokuLabel->Caption = "未使用";
		SharyoEditForm->HinmokuLabel->Caption = "未使用";
		TankaEditForm->HinmokuLabel->Caption  = "未使用";
        ItemRelateEditForm->HinmokuLabel->Caption = "未使用";
        QRItemRelateForm->HinmokuNameLabel->Caption = "未使用";

		DM->M_Hinmoku->Fields->Fields[0]->DisplayLabel = "未使用";
		DM->M_Hinmoku->Fields->Fields[1]->DisplayLabel = "未使用";
		DM->M_Hinmoku->Fields->Fields[2]->DisplayLabel = "未使用";
		DM->M_Hinmoku->Fields->Fields[3]->DisplayLabel = "未使用";
		DM->M_Hinmoku->Fields->Fields[4]->DisplayLabel = "未使用";

		DM->M_Sharyo->Fields->Fields[18]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[19]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[20]->DisplayLabel = "未使用";
		DM->M_Sharyo->Fields->Fields[21]->DisplayLabel = "未使用";

		DM->M_Kanzan->Fields->Fields[5]->DisplayLabel = "未使用";
		DM->M_Kanzan->Fields->Fields[6]->DisplayLabel = "未使用";
		DM->M_Kanzan->Fields->Fields[7]->DisplayLabel = "未使用";
		DM->M_Kanzan->Fields->Fields[8]->DisplayLabel = "未使用";

		DM->M_Tanka->Fields->Fields[5]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[6]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[7]->DisplayLabel = "未使用";
		DM->M_Tanka->Fields->Fields[8]->DisplayLabel = "未使用";

        DM->M_ItemRelate->Fields->Fields[19]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[20]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[21]->DisplayLabel = "未使用";
        DM->M_ItemRelate->Fields->Fields[22]->DisplayLabel = "未使用";
	}
}
//---------------------------------------------------------------------------
// ページ切り替えの際にページ情報をセット
void __fastcall TMainForm::SetPageInfo(int page)
{
	// 使用しないデータを表示の件数をセット
	if (page != 0 && page != 1 && page != 2 && page != 3 && page != 4 && page != 5)
		return;
	AnsiString sql = "SELECT COUNT(*) AS 件数 FROM " + table_name_[page] + " WHERE 使用区分 = 0";
	NsRecordSet set;
	DM->DBI.GetRecordSet(sql, set);
	int kensu = ToInt(set[0]["件数"]);
	AnsiString caption = "使用しないデータを表示(" + FormatFloat("#,##0", kensu) + "件)";
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
	else if (page == 6 && (DataCol == 2 || DataCol == 4))	// 換算マスタ
		;
	else if (page == 9 && (DataCol == 2 || DataCol == 4 || DataCol == 6 || DataCol == 8))	// 単価マスタ
		;
	else if (page >= 0 && page <= 5 && DataCol == 0){
		// 車両マスタから換算マスタにキーボードを使用してページを切替えた際に「使用区分が見つからない」というエラーが出る(※実運用上支障がないので放置)
		if (((TDBGrid *)Sender)->DataSource->DataSet->FieldByName("使用区分")->AsInteger == 0)
			((TDBGrid *)Sender)->Canvas->Brush->Color = TColor(0x00CDCCFB);
	}else if ((State.Empty() || ActiveControl != ((TDBGrid *)Sender)) && ((TDBGrid *)Sender)->DataSource->DataSet->RecNo % 2 == 0)
		((TDBGrid *)Sender)->Canvas->Brush->Color = TColor(0x00E6E6E6);

	((TDBGrid *)Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

