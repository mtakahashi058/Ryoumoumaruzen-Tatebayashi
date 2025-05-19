//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QRChitFrm.h"
#include "DMFrm.h"
#include "n24tp.h"
#include "StateConst.h"
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
    TokuTitleLabel->Caption  = DM->TrimSpace(ToString(DM->CFG["“¾ˆÓæƒ}ƒXƒ^–¼Ì"]));
    MeigTitleLabel->Caption  = DM->TrimSpace(ToString(DM->CFG["•i–Úƒ}ƒXƒ^–¼Ì"]));
    Item1TitleLabel->Caption = DM->TrimSpace(ToString(DM->CFG["€–Ú1ƒ}ƒXƒ^–¼Ì"]));
    Item2TitleLabel->Caption = DM->TrimSpace(ToString(DM->CFG["€–Ú2ƒ}ƒXƒ^–¼Ì"]));

	//////////////////////////////////////////////////
    int date, place_id, no;
    if (!DM->GetKeiryoKey(keiryo_id, date, place_id, no))
		throw Exception("ˆóŽšƒf[ƒ^‚ª‚ ‚è‚Ü‚¹‚ñ");

	if (ChitQuery->Active)
		ChitQuery->Close();
	try{
		ChitQuery->SQL->Text = " SELECT * FROM V_Œv—Ê"
                               " WHERE Œv—Ê“ú = " + IntToStr(date) +
                               "   AND ‹’“_ID = " + IntToStr(place_id) +
                               "   AND “`•[No = " + IntToStr(no) +
                               "   AND Š®—¹‹æ•ª = 1";
		ChitQuery->Open();
		if (ChitQuery->Eof)
			throw Exception("");
	}catch(...){
		throw Exception("ˆóŽšƒf[ƒ^‚ª‚ ‚è‚Ü‚¹‚ñ");
	}


	//////////////////////////////////////////////////
	///// “`•[î•ñ‚ÌŽæ“¾‚ÆÝ’è

    AnsiString titles[3];

	int print_info_id = DM->GetPrintInfo(keiryo_id);
	if (!print_info_id){
		Application->MessageBox("“`•[î•ñ‚ªÝ’è‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}
	AnsiString sql;
	NsRecordSet set;
	sql = "SELECT * FROM M_“`•[î•ñ WHERE “`•[î•ñID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("“`•[î•ñ‚ª–³Œø‚Å‚·", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	int div = ChitQuery->FieldByName("”À“üo‹æ•ª")->AsInteger;
	if (div == 1){
		titles[0] = ToString(SET_TOP(set)["“üŒÉ“`•[ƒ^ƒCƒgƒ‹1"]);
		titles[1] = ToString(SET_TOP(set)["“üŒÉ“`•[ƒ^ƒCƒgƒ‹2"]);
		titles[2] = ToString(SET_TOP(set)["“üŒÉ“`•[ƒ^ƒCƒgƒ‹3"]);
	}else{
		titles[0] = ToString(SET_TOP(set)["oŒÉ“`•[ƒ^ƒCƒgƒ‹1"]);
		titles[1] = ToString(SET_TOP(set)["oŒÉ“`•[ƒ^ƒCƒgƒ‹2"]);
		titles[2] = ToString(SET_TOP(set)["oŒÉ“`•[ƒ^ƒCƒgƒ‹3"]);
	}
	QRCompany->Caption = ToString(SET_TOP(set)["‰ïŽÐ–¼"]);
	QRFooter1->Caption = ToString(SET_TOP(set)["‰ïŽÐî•ñ1"]);
    QRFooter2->Caption = ToString(SET_TOP(set)["‰ïŽÐî•ñ2"]);
	QRFooter3->Caption = ToString(SET_TOP(set)["‰ïŽÐî•ñ3"]);
	QRFooter4->Caption = ToString(SET_TOP(set)["‰ïŽÐî•ñ4"]);

	SetPrinter(QR, ToString(DM->INI["Chit::Printer"]));
	int copies = ToInt(DM->INI["Chit::PrintCopy"]);
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
    w1 = DataSet->FieldByName("1‰ñ–Úd—Ê")->AsInteger;
    w2 = DataSet->FieldByName("2‰ñ–Úd—Ê")->AsInteger;

    DataSet->FieldByName("‘d—Ê")->AsInteger   = std::max(w1, w2);
    DataSet->FieldByName("‹óŽÔd—Ê")->AsInteger = std::min(w1, w2);
}
//---------------------------------------------------------------------------

