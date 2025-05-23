//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DisplayFrm.h"
#include "DMFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "CEdit"
#pragma link "CEdit"
#pragma resource "*.dfm"
TDisplayForm *DisplayForm;
//---------------------------------------------------------------------------
__fastcall TDisplayForm::TDisplayForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDisplayForm::FormCreate(TObject *Sender)
{
    SetWindowPos(Application->Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE + SWP_NOMOVE);

    Top = 0;
}
//---------------------------------------------------------------------------
void __fastcall TDisplayForm::FormShow(TObject *Sender)
{
	TokuButton->Caption      = ToString(DM->CFG["¾Óæ}X^¼Ì"]);
	Komoku1Button->Caption   = ToString(DM->CFG["Ú1}X^¼Ì"]);
	Komoku2Button->Caption   = ToString(DM->CFG["Ú2}X^¼Ì"]);
	HinButton->Caption       = ToString(DM->CFG["iÚ}X^¼Ì"]);
	ChoseiButton->Caption    = ToString(DM->CFG["²®¼Ì"]);
	JuryobikiButton->Caption = ToString(DM->CFG["dÊø«¼Ì"]);

	if (!ToBit(DM->CFG["¾Óæ}X^gpæª"])){
		TokuPanel->Visible            = false;
	}
	if (!ToBit(DM->CFG["Ú1}X^gpæª"])){
		Komoku1Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["Ú2}X^gpæª"])){
		Komoku2Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["iÚ}X^gpæª"])){
		HinPanel->Visible             = false;
	}
	if (!ToBit(DM->CFG["üoÉgpæª"])){
		HannyuCombo->Visible          = false;
	}
	if (!ToBit(DM->CFG["²®gpæª"])){
		ChoseiPanel->Visible          = false;
	}
	if (!ToBit(DM->CFG["dÊø«gpæª"])){
		JuryobikiPanel->Visible       = false;
	}
	if (!ToBit(DM->CFG["P¿gpæª"])){
		SuryoPanel->Visible           = false;
		TaniPanel->Visible            = false;
		TankaPanel->Visible           = false;
		KingakuPanel->Visible         = false;
		ShohizeiPanel->Visible        = false;
	}
	if (!ToBit(DM->CFG["dÊÒWæª"])){
		FirstWEdit->ReadOnly          = true;
		SecondWEdit->ReadOnly         = true;
	}
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDisplayForm::ZeroSuppress(Currency v)
{
	if (v == 0)
		return AnsiString();
	else
		return AnsiString(v);
}
//---------------------------------------------------------------------------
void __fastcall TDisplayForm::ClearForm()
{
    KeiryoDatePicker->Date   = Now();
    KeiryoNoEdit->Text       = AnsiString();
	ShabanEdit->Text         = AnsiString();
	TokuCodeEdit->Text       = AnsiString();
	TokuNameEdit->Text       = AnsiString();
	Komoku1CodeEdit->Text    = AnsiString();
	Komoku1NameEdit->Text    = AnsiString();
	Komoku2CodeEdit->Text    = AnsiString();
	Komoku2NameEdit->Text    = AnsiString();
	HinCodeEdit->Text        = AnsiString();
	HinNameEdit->Text        = AnsiString();
	HannyuCombo->ItemIndex   = -1;
	FirstWEdit->Text         = AnsiString();
	FirstTimeLabel->Caption  = AnsiString();
	SecondWEdit->Text        = AnsiString();
	SecondTimeLabel->Caption = AnsiString();
	ChoseirituEdit->Text     = AnsiString();
	ChoseiEdit->Text         = AnsiString();
	JuryobikiEdit->Text      = AnsiString();
	ShomiEdit->Text          = AnsiString();
	PureNetLabel->Caption    = AnsiString();
	SuryoEdit->Text          = AnsiString();
	TaniLabel->Caption       = "______";
	TaniCodeEdit->Text       = AnsiString();
    TaniNameEdit->Text       = AnsiString();
	TankaEdit->Text          = AnsiString();
	KingakuEdit->Text        = AnsiString();
	ShohizeiEdit->Text       = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TDisplayForm::ShowRecord(int id)
{
    ClearForm();

	AnsiString sql;
    NsRecordSet set;
	sql = " SELECT * FROM V_vÊ"
		  " WHERE vÊID = " + IntToStr(id) +
		  "   AND ®¹æª <> 9";					// _íÍÎÛO

	if (!DM->DBI.GetRecordSet(sql, set))
		return;

	KeiryoDatePicker->Date       = IntToDate(ToInt(SET_TOP(set)["vÊú"]));
	KeiryoNoEdit->Text           = ToInt(SET_TOP(set)["`[No"]);

	ShabanEdit->Text             = ToInt(SET_TOP(set)["ÔÔ"]);
	SharyoNameEdit->Text         = ToString(SET_TOP(set)["Ô¼¼Ì"]);
	
	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["¾ÓæR[h"]));
    TokuNameEdit->Text           = ToString(SET_TOP(set)["¾Óæ¼Ì"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["Ú1R[h"]));
    Komoku1NameEdit->Text        = ToString(SET_TOP(set)["Ú1¼Ì"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["Ú2R[h"]));
    Komoku2NameEdit->Text        = ToString(SET_TOP(set)["Ú2¼Ì"]);
	HinCodeEdit->Text            = ZeroSuppress(ToInt(SET_TOP(set)["iÚR[h"]));
    HinNameEdit->Text            = ToString(SET_TOP(set)["iÚ¼Ì"]);
	HannyuCombo->ItemIndex       = ToInt(SET_TOP(set)["Àüoæª"]) - 1;

	Currency w1                  = ToCurrency(SET_TOP(set)["1ñÚdÊ"]);
	Currency w2		 			 = ToCurrency(SET_TOP(set)["2ñÚdÊ"]);

	FirstWEdit->Text             = ZeroSuppress(w1);
	if (!SET_TOP(set)["vÊú1"].IsNull())
		FirstTimeLabel->Caption  = TDateTime(SET_TOP(set)["vÊú1"]).FormatString("yyyy'-'mm'-'dd hh:nn");
	SecondWEdit->Text            = ZeroSuppress(w2);
	if (!SET_TOP(set)["vÊú2"].IsNull())
		SecondTimeLabel->Caption = TDateTime(SET_TOP(set)["vÊú2"]).FormatString("yyyy'-'mm'-'dd hh:nn");

	ChoseiEdit->Text             = ZeroSuppress(ToCurrency(SET_TOP(set)["²®dÊ"]));
	ChoseirituEdit->Text         = ZeroSuppress(ToCurrency(SET_TOP(set)["²®¦"]));
	JuryobikiEdit->Text          = ZeroSuppress(ToCurrency(SET_TOP(set)["dÊø«"]));
	ShomiEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["³¡dÊ"]));

	PureNetLabel->Caption        = AnsiString(std::abs(w1 - w2)) + " kg";

	SuryoEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["Ê"]));
	TaniCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["PÊR[h"]));
    TaniNameEdit->Text           = ToString(SET_TOP(set)["PÊ}X^¼Ì"]);

	TankaEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["P¿"]));
	KingakuEdit->Text            = ZeroSuppress(ToInt(SET_TOP(set)["àz"]));
	ShohizeiEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["`[ÁïÅz"]));

	Show();
}
//---------------------------------------------------------------------------

