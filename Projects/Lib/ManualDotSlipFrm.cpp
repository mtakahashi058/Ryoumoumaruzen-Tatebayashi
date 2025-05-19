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
	AnsiString sql = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
	NsRecordSet set;

	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("印字する計量データがありません", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	NoLabel->Caption     = ToInt(SET_TOP(set)["伝票No"]);
	DateLabel->Caption   = IntToDate(ToInt(SET_TOP(set)["計量日"]));
	ShabanLabel->Caption = ToInt(SET_TOP(set)["車番"]);

	AnsiString item_order = ToString(DM->CFG["ドット伝票項目順"]);
	for (int i = 0; i < 4; i++){
		switch (item_order.SubString(1, 1).ToInt()){
		case 1:
			code_label_[i]->Caption = ToString(SET_TOP(set)["得意先コード"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["得意先略称"]);
			break;
		case 2:
			code_label_[i]->Caption = ToString(SET_TOP(set)["項目1コード"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["項目1略称"]);
			break;
		case 3:
			code_label_[i]->Caption = ToString(SET_TOP(set)["項目2コード"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["項目2略称"]);
			break;
		case 4:
			code_label_[i]->Caption = ToString(SET_TOP(set)["品目コード"]);
			name_label_[i]->Caption = ToString(SET_TOP(set)["品目略称"]);
			break;
		}
		item_order.Delete(1, 1);
	}

	Currency gross_w, tare_w, first_w, second_w;
	TDateTime gross_t, tare_t;
	first_w  = ToCurrency(SET_TOP(set)["1回目重量"]);
	second_w = ToCurrency(SET_TOP(set)["2回目重量"]);
	if (first_w < second_w){
		GrossWeightLabel->Caption = FormatFloat("#,##0kg", second_w);
		TareWeightLabel->Caption  = FormatFloat("#,##0kg", first_w);
		if (!SET_TOP(set)["計量日時2"].IsNull())
			GrossTimeLabel->Caption = VarToDateTime(SET_TOP(set)["計量日時2"]).FormatString("hh:nn");
		else
			GrossTimeLabel->Caption = AnsiString();
		if (!SET_TOP(set)["計量日時1"].IsNull())
			TareTimeLabel->Caption  = VarToDateTime(SET_TOP(set)["計量日時1"]).FormatString("hh:nn");
		else
			TareTimeLabel->Caption  = AnsiString();
	}else{
		GrossWeightLabel->Caption = FormatFloat("#,##0kg", first_w);
		TareWeightLabel->Caption  = FormatFloat("#,##0kg", second_w);
		if (!SET_TOP(set)["計量日時1"].IsNull())
			GrossTimeLabel->Caption = VarToDateTime(SET_TOP(set)["計量日時1"]).FormatString("hh:nn");
		else
			GrossTimeLabel->Caption = AnsiString();
		if (!SET_TOP(set)["計量日時2"].IsNull())
			TareTimeLabel->Caption  = VarToDateTime(SET_TOP(set)["計量日時2"]).FormatString("hh:nn");
		else
			TareTimeLabel->Caption  = AnsiString();
	}
	NetWeightLabel->Caption = FormatFloat("#,##0kg", ToCurrency(SET_TOP(set)["正味重量"]));
	BikoLabel->Caption      = ToString(SET_TOP(set)["備考"]);

	// 時間印字設定反映
	GrossTimeLabel->Enabled = !hide_time;
	TareTimeLabel->Enabled  = !hide_time;

	// 会社情報マスタ＆会社情報関連マスタ参照
	if (DM->CFG["手差しドット伝票情報印字区分"]){
		int printinfo_id = DM->GetPrintInfo(keiryo_id);
		if (!printinfo_id){
			Application->MessageBox("伝票情報が設定されていません", Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		sql = "SELECT * FROM M_伝票情報 WHERE 伝票情報ID = " + IntToStr(printinfo_id);
		set.clear();
		if (!DM->DBI.GetRecordSet(sql, set)){
			Application->MessageBox("伝票情報が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}
		CompanyNameLabel->Caption  = ToString(SET_TOP(set)["会社名"]);
		CompanyInfoLabel1->Caption = ToString(SET_TOP(set)["会社情報1"]);
		CompanyInfoLabel2->Caption = ToString(SET_TOP(set)["会社情報2"]);
		CompanyInfoLabel3->Caption = ToString(SET_TOP(set)["会社情報3"]);
		CompanyInfoLabel4->Caption = ToString(SET_TOP(set)["会社情報4"]);
	}else{
		CompanyNameLabel->Caption  = AnsiString();
		CompanyInfoLabel1->Caption = AnsiString();
		CompanyInfoLabel2->Caption = AnsiString();
		CompanyInfoLabel3->Caption = AnsiString();
		CompanyInfoLabel4->Caption = AnsiString();
	}

	if (!SetPrinter(QuickRep, ToString(DM->INI["Printer::Slip"]))){
		Application->MessageBox("伝票発行用に指定されたプリンタが見つかりません。通常使うプリンタを使用します",
					Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}
	QuickRep->Page->LeftMargin = ToCurrency(DM->INI["Printer::SlipLeft"]);
	QuickRep->Page->TopMargin  = ToCurrency(DM->INI["Printer::SlipTop"]);

	QuickRep->Print();

	return true;
}
//---------------------------------------------------------------------------

