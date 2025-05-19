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
	Q_Slip->SQL->Text = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
	Q_Slip->Open();
	if (Q_Slip->Eof && Q_Slip->Bof){
		Application->MessageBox("印字する計量データがありません", Caption.c_str(), MB_OK | MB_ICONWARNING);
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

    AnsiString item_order = ToString(DM->CFG["ドット伝票項目順"]);
    int no;
    for (int i = 1; i <= 4; i++){
        if (item_order.IsEmpty()){
            continue;
        }
        no = item_order.SubString(1, 1).ToIntDef(0);
        item_order.Delete(1, 1);

        if (no == 1){
        	Labels[i]->Caption  = ToString(DM->CFG["得意先マスタ名称"]);
            Texts[i]->DataField = "得意先名称";

		    if (!ToInt(DM->CFG["得意先マスタ使用区分"])){
		        Labels[i]->Enabled = false;
		    }
        }else if (no == 2){
        	// 項目1
        	Labels[i]->Caption  = ToString(DM->CFG["項目1マスタ名称"]);
            Texts[i]->DataField = "項目1名称";

		    if (!ToInt(DM->CFG["項目1マスタ使用区分"])){
		        Labels[i]->Enabled = false;
		    }
        }else if (no == 3){
        	// 項目2
        	Labels[i]->Caption  = ToString(DM->CFG["項目2マスタ名称"]);
            Texts[i]->DataField = "項目2名称";

		    if (!ToInt(DM->CFG["項目2マスタ使用区分"])){
		        Labels[i]->Enabled = false;
		    }
        }else if (no == 4){
        	Labels[i]->Caption  = ToString(DM->CFG["品目マスタ名称"]);
            Texts[i]->DataField = "品目名称";

		    if (!ToInt(DM->CFG["品目マスタ使用区分"])){
		        Labels[i]->Enabled = false;
		    }
        }
    }

	//////////////////////////////////////////////////
	///// 入出庫使用の設定
	IoShape1A->Enabled = ToBit(DM->CFG["入出庫使用区分"]);
	IoShape2A->Enabled = ToBit(DM->CFG["入出庫使用区分"]);
	lblIoA->Enabled    = ToBit(DM->CFG["入出庫使用区分"]);
	dbtxtIoA->Enabled  = ToBit(DM->CFG["入出庫使用区分"]);

	IoShape1B->Enabled = ToBit(DM->CFG["入出庫使用区分"]);
	IoShape2B->Enabled = ToBit(DM->CFG["入出庫使用区分"]);
	lblIoB->Enabled    = ToBit(DM->CFG["入出庫使用区分"]);
	dbtxtIoB->Enabled  = ToBit(DM->CFG["入出庫使用区分"]);

	IoShape1C->Enabled = ToBit(DM->CFG["入出庫使用区分"]);
	IoShape2C->Enabled = ToBit(DM->CFG["入出庫使用区分"]);
	lblIoC->Enabled    = ToBit(DM->CFG["入出庫使用区分"]);
	dbtxtIoC->Enabled  = ToBit(DM->CFG["入出庫使用区分"]);

	///// 項目名の設定
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

	Coord1Label->Caption = ToString(DM->CFG["調整名称"]);
	Coord2Label->Caption = Coord1Label->Caption;
	Coord3Label->Caption = Coord1Label->Caption;
	Reduc1Label->Caption = ToString(DM->CFG["重量引き名称"]);
	Reduc2Label->Caption = Reduc1Label->Caption;
	Reduc3Label->Caption = Reduc1Label->Caption;

	if (ToBit(DM->CFG["単価使用区分"])){
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
	///// 時間の印字設定
    GTime1DBText->Enabled = !hide_time;
    GTime2DBText->Enabled = !hide_time;
    GTime3DBText->Enabled = !hide_time;
    TTime1DBText->Enabled = !hide_time;
    TTime2DBText->Enabled = !hide_time;
    TTime3DBText->Enabled = !hide_time;

	//////////////////////////////////////////////////
	///// 伝票情報の取得と設定

	int print_info_id = DM->GetPrintInfo(keiryo_id);
	if (!print_info_id){
		Application->MessageBox("伝票情報が設定されていません", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
	AnsiString sql;
	NsRecordSet set;
	sql = "SELECT * FROM M_伝票情報 WHERE 伝票情報ID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("伝票情報が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	int div = Q_Slip->FieldByName("搬入出区分")->AsInteger;
	if (div == 1){
		Title1Label->Caption = ToString(SET_TOP(set)["入庫伝票タイトル1"]);
		Title2Label->Caption = ToString(SET_TOP(set)["入庫伝票タイトル2"]);
		Title3Label->Caption = ToString(SET_TOP(set)["入庫伝票タイトル3"]);
	}else{
		Title1Label->Caption = ToString(SET_TOP(set)["出庫伝票タイトル1"]);
		Title2Label->Caption = ToString(SET_TOP(set)["出庫伝票タイトル2"]);
		Title3Label->Caption = ToString(SET_TOP(set)["出庫伝票タイトル3"]);
	}

    QRCover1->Height = Title1Label->Caption.IsEmpty() ? 861 : 1;
    QRCover2->Height = Title2Label->Caption.IsEmpty() ? 861 : 1;
    QRCover3->Height = Title3Label->Caption.IsEmpty() ? 861 : 1;

	Company1Label->Caption = ToString(SET_TOP(set)["会社名"]);
	Company2Label->Caption = Company1Label->Caption;
	Company3Label->Caption = Company1Label->Caption;
	Info11Label->Caption   = ToString(SET_TOP(set)["会社情報1"]);
	Info12Label->Caption   = Info11Label->Caption;
	Info13Label->Caption   = Info11Label->Caption;
	Info21Label->Caption   = ToString(SET_TOP(set)["会社情報2"]);
	Info22Label->Caption   = Info21Label->Caption;
	Info23Label->Caption   = Info21Label->Caption;
	Info31Label->Caption   = ToString(SET_TOP(set)["会社情報3"]);
	Info32Label->Caption   = Info31Label->Caption;
	Info33Label->Caption   = Info31Label->Caption;
	Info41Label->Caption   = ToString(SET_TOP(set)["会社情報4"]);
	Info42Label->Caption   = Info41Label->Caption;
	Info43Label->Caption   = Info41Label->Caption;

    if (IsNull(SET_TOP(set)["金額印字区分1"]))
        kingaku_print1_ = true;     // 過去互換
    else
        kingaku_print1_ = ToBit(SET_TOP(set)["金額印字区分1"]);
        
    if (IsNull(SET_TOP(set)["金額印字区分2"]))
        kingaku_print2_ = true;     // 過去互換
    else
        kingaku_print2_ = ToBit(SET_TOP(set)["金額印字区分2"]);

    if (IsNull(SET_TOP(set)["金額印字区分3"]))
        kingaku_print3_ = true;     // 過去互換
    else
        kingaku_print3_ = ToBit(SET_TOP(set)["金額印字区分3"]);

	if (!SetPrinter(QuickRep, ToString(DM->INI["Printer::Slip"]))){
		Application->MessageBox("伝票発行用に指定されたプリンタが見つかりません。通常使うプリンタを使用します",
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
	w1 = Q_Slip->FieldByName("1回目重量")->AsCurrency;
	w2 = Q_Slip->FieldByName("2回目重量")->AsCurrency;
	if (w1 > w2){
		Gross1DBText->DataField = "1回目重量";
		Gross2DBText->DataField = "1回目重量";
		Gross3DBText->DataField = "1回目重量";
		Tare1DBText->DataField  = "2回目重量";
		Tare2DBText->DataField  = "2回目重量";
		Tare3DBText->DataField  = "2回目重量";
		GTime1DBText->DataField = "計量日時1";
		GTime2DBText->DataField = "計量日時1";
		GTime3DBText->DataField = "計量日時1";
		TTime1DBText->DataField = "計量日時2";
		TTime2DBText->DataField = "計量日時2";
		TTime3DBText->DataField = "計量日時2";
	}else{
		Gross1DBText->DataField = "2回目重量";
		Gross2DBText->DataField = "2回目重量";
		Gross3DBText->DataField = "2回目重量";
		Tare1DBText->DataField  = "1回目重量";
		Tare2DBText->DataField  = "1回目重量";
		Tare3DBText->DataField  = "1回目重量";
		GTime1DBText->DataField = "計量日時2";
		GTime2DBText->DataField = "計量日時2";
		GTime3DBText->DataField = "計量日時2";
		TTime1DBText->DataField = "計量日時1";
		TTime2DBText->DataField = "計量日時1";
		TTime3DBText->DataField = "計量日時1";
	}

	Currency coord_per, coord;
	coord_per = Q_Slip->FieldByName("調整率")->AsCurrency;
	coord     = Q_Slip->FieldByName("調整重量")->AsCurrency;
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

	Currency reduce = Q_Slip->FieldByName("重量引き")->AsCurrency;
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

	int tani_id = Q_Slip->FieldByName("単位ID")->AsInteger;
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
	int gk_div = Q_Slip->FieldByName("現掛区分")->AsInteger;
    int kingaku_div = ToInt(DM->CFG["伝票金額印字"]);

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
	int mon = Q_Slip->FieldByName("金額")->AsInteger;
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


