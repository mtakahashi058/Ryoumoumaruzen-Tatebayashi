//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QRChitFrm.h"
#include "DMFrm.h"
#include "n24tp.h"
//#include "StateConst.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQRChitForm *QRChitForm;
//---------------------------------------------------------------------------
__fastcall TQRChitForm::TQRChitForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TQRChitForm::Print(int keiryo_id)
{
    TokuTitleLabel->Caption  = DM->TrimSpace(ToString(DM->CFG["得意先マスタ名称"]));
    MeigTitleLabel->Caption  = DM->TrimSpace(ToString(DM->CFG["品目マスタ名称"]));
    Item1TitleLabel->Caption = DM->TrimSpace(ToString(DM->CFG["項目1マスタ名称"]));
    Item2TitleLabel->Caption = DM->TrimSpace(ToString(DM->CFG["項目2マスタ名称"]));

	QR->Page->LeftMargin = ToCurrency(DM->INI["Printer::SlipLeft"]);
	QR->Page->TopMargin  = ToCurrency(DM->INI["Printer::SlipTop"]);

	//////////////////////////////////////////////////
    int date, place_id, no;
    if (!DM->GetKeiryoKey(keiryo_id, date, place_id, no))
		throw Exception("印字データがありません");

	if (ChitQuery->Active)
		ChitQuery->Close();
	try{
		ChitQuery->SQL->Text = " SELECT * FROM V_計量"
                               " WHERE 計量日 = " + IntToStr(date) +
                               "   AND 拠点ID = " + IntToStr(place_id) +
                               "   AND 伝票No = " + IntToStr(no) +
                               "   AND 完了区分 = 1";
		ChitQuery->Open();
		if (ChitQuery->Eof)
			throw Exception("");
	}catch(...){
		throw Exception("印字データがありません");
	}


	//////////////////////////////////////////////////
	///// 伝票情報の取得と設定

    AnsiString titles[3];

	int print_info_id = DM->GetPrintInfo(keiryo_id);
	if (!print_info_id){
		Application->MessageBox("伝票情報が設定されていません", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}
	AnsiString sql;
	NsRecordSet set;
	sql = "SELECT * FROM M_伝票情報 WHERE 伝票情報ID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("伝票情報が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	int div = ChitQuery->FieldByName("搬入出区分")->AsInteger;
	if (div == 1){
		titles[0] = ToString(SET_TOP(set)["入庫伝票タイトル1"]);
		titles[1] = ToString(SET_TOP(set)["入庫伝票タイトル2"]);
		titles[2] = ToString(SET_TOP(set)["入庫伝票タイトル3"]);
	}else{
		titles[0] = ToString(SET_TOP(set)["出庫伝票タイトル1"]);
		titles[1] = ToString(SET_TOP(set)["出庫伝票タイトル2"]);
		titles[2] = ToString(SET_TOP(set)["出庫伝票タイトル3"]);
	}
	QRCompany->Caption = ToString(SET_TOP(set)["会社名"]);
	QRFooter1->Caption = ToString(SET_TOP(set)["会社情報1"]);
    QRFooter2->Caption = ToString(SET_TOP(set)["会社情報2"]);
	QRFooter3->Caption = ToString(SET_TOP(set)["会社情報3"]);
	QRFooter4->Caption = ToString(SET_TOP(set)["会社情報4"]);

//	SetPrinter(QR, ToString(DM->INI["Chit::Printer"]));
	if (!SetPrinter(QR, ToString(DM->INI["Printer::Slip"]))){
		Application->MessageBox("伝票発行用に指定されたプリンタが見つかりません。通常使うプリンタを使用します",
					Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}

	int copies = ToString(DM->INI["Chit::PrintCopy"]).ToIntDef(1);
    for (int i = 0; i < copies; i++){
        if (i < 3)
            QRTitle->Caption = titles[i];
        else
            QRTitle->Caption = titles[0];
        QR->Print();
    }
}
//---------------------------------------------------------------------------
void __fastcall TQRChitForm::ChitQueryCalcFields(TDataSet *DataSet)
{
    int w1, w2;
    w1 = DataSet->FieldByName("1回目重量")->AsInteger;
    w2 = DataSet->FieldByName("2回目重量")->AsInteger;

    DataSet->FieldByName("総重量")->AsInteger   = std::max(w1, w2);
    DataSet->FieldByName("空車重量")->AsInteger = std::min(w1, w2);
}
//---------------------------------------------------------------------------

