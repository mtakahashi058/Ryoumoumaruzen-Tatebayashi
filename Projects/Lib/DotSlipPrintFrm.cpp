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
	if (ToBit(DM->CFG["単価使用区分"])){
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

    AnsiString item_order = ToString(DM->CFG["ドット伝票項目順"]);
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
            CodeText->DataField = "得意先コード";
            NameText->DataField = "得意先略称";
        }else if (no == 2){
            CodeText->DataField = "項目1コード";
            NameText->DataField = "項目1略称";
        }else if (no == 3){
            CodeText->DataField = "項目2コード";
            NameText->DataField = "項目2略称";
        }else if (no == 4){
            CodeText->DataField = "品目コード";
            NameText->DataField = "品目略称";
        }
    }

	if (Q_Slip->Active)
		Q_Slip->Close();
	Q_Slip->SQL->Text = "SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
	Q_Slip->Open();
	if (Q_Slip->Eof && Q_Slip->Bof){
		Application->MessageBox("印字する計量データがありません", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

	//int gk_div = Q_Slip->FieldByName("現掛区分")->AsInteger;

	Currency w1, w2;
	w1 = Q_Slip->FieldByName("1回目重量")->AsCurrency;
	w2 = Q_Slip->FieldByName("2回目重量")->AsCurrency;
	if (w1 > w2){
        GrossTimeText->DataField = "計量日時1";
        GrossWText->DataField    = "1回目重量";
        TareTimeText->DataField  = "計量日時2";
        TareWText->DataField     = "2回目重量";
	}else{
        GrossTimeText->DataField = "計量日時2";
        GrossWText->DataField    = "2回目重量";
        TareTimeText->DataField  = "計量日時1";
        TareWText->DataField     = "1回目重量";
	}

	//int mon = Q_Slip->FieldByName("金額")->AsInteger;

    /*
    int kingaku_div = ToInt(DM->CFG["伝票金額印字"]);
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

    if (IsNull(SET_TOP(set)["金額印字区分1"]))
        kingaku_print1_ = true;     // 過去互換
    else
        kingaku_print1_ = ToBit(SET_TOP(set)["金額印字区分1"]);

    AmountText->Enabled = kingaku_print1_;
    YenLabel->Enabled   = kingaku_print1_;

    if (Q_Slip->FieldByName("数量")->AsInteger == 0){
        QuantityText->Enabled = false;
        UnitText->Enabled     = false;
    }
    if (Q_Slip->FieldByName("金額")->AsInteger == 0){
        AmountText->Enabled = false;
        YenLabel->Enabled   = false;
    }

	//////////////////////////////////////////////////
	///// 時間の印字設定
    GrossTimeText->Enabled = !hide_time;
    TareTimeText->Enabled  = !hide_time;

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
