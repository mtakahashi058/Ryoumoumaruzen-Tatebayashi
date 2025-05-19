//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DisplayFrm.h"
#include "DMFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
	TokuButton->Caption      = ToString(DM->CFG["得意先マスタ名称"]);
	Komoku1Button->Caption   = ToString(DM->CFG["項目1マスタ名称"]);
	Komoku2Button->Caption   = ToString(DM->CFG["項目2マスタ名称"]);
	HinButton->Caption       = ToString(DM->CFG["品目マスタ名称"]);
	ChoseiButton->Caption    = ToString(DM->CFG["調整名称"]);
	JuryobikiButton->Caption = ToString(DM->CFG["重量引き名称"]);

	if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
		TokuPanel->Visible            = false;
	}
	if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
		Komoku1Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
		Komoku2Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["品目マスタ使用区分"])){
		HinPanel->Visible             = false;
	}
	if (!ToBit(DM->CFG["入出庫使用区分"])){
		HannyuCombo->Visible          = false;
	}
	if (!ToBit(DM->CFG["調整使用区分"])){
		ChoseiPanel->Visible          = false;
	}
	if (!ToBit(DM->CFG["重量引き使用区分"])){
		JuryobikiPanel->Visible       = false;
	}
	if (!ToBit(DM->CFG["単価使用区分"])){
		SuryoPanel->Visible           = false;
		TaniPanel->Visible            = false;
		TankaPanel->Visible           = false;
		KingakuPanel->Visible         = false;
		ShohizeiPanel->Visible        = false;
	}
	if (!ToBit(DM->CFG["重量編集区分"])){
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
	sql = " SELECT * FROM V_計量"
		  " WHERE 計量ID = " + IntToStr(id) +
		  "   AND 完了区分 <> 9";					// 論理削除は対象外

	if (!DM->DBI.GetRecordSet(sql, set))
		return;

    if (ToInt(SET_TOP(set)["完了区分"]) == 0)
        HeaderPanel->Caption = "一回目計量／二回計量が完了しました";
    else
        HeaderPanel->Caption = "カード計量を完了しました";

	KeiryoDatePicker->Date       = IntToDate(ToInt(SET_TOP(set)["計量日"]));
	KeiryoNoEdit->Text           = ToInt(SET_TOP(set)["伝票No"]);

	ShabanEdit->Text             = ToInt(SET_TOP(set)["車番"]);
	SharyoNameEdit->Text         = ToString(SET_TOP(set)["車両名称"]);
	
	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["得意先コード"]));
    TokuNameEdit->Text           = ToString(SET_TOP(set)["得意先名称"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["項目1コード"]));
    Komoku1NameEdit->Text        = ToString(SET_TOP(set)["項目1名称"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["項目2コード"]));
    Komoku2NameEdit->Text        = ToString(SET_TOP(set)["項目2名称"]);
	HinCodeEdit->Text            = ZeroSuppress(ToInt(SET_TOP(set)["品目コード"]));
    HinNameEdit->Text            = ToString(SET_TOP(set)["品目名称"]);
	HannyuCombo->ItemIndex       = ToInt(SET_TOP(set)["搬入出区分"]) - 1;

	Currency w1                  = ToCurrency(SET_TOP(set)["1回目重量"]);
	Currency w2		 			 = ToCurrency(SET_TOP(set)["2回目重量"]);

	FirstWEdit->Text             = ZeroSuppress(w1);
	if (!SET_TOP(set)["計量日時1"].IsNull())
		FirstTimeLabel->Caption  = TDateTime(SET_TOP(set)["計量日時1"]).FormatString("yyyy'-'mm'-'dd hh:nn");
	SecondWEdit->Text            = ZeroSuppress(w2);
	if (!SET_TOP(set)["計量日時2"].IsNull())
		SecondTimeLabel->Caption = TDateTime(SET_TOP(set)["計量日時2"]).FormatString("yyyy'-'mm'-'dd hh:nn");

	ChoseiEdit->Text             = ZeroSuppress(ToCurrency(SET_TOP(set)["調整重量"]));
	ChoseirituEdit->Text         = ZeroSuppress(ToCurrency(SET_TOP(set)["調整率"]));
	JuryobikiEdit->Text          = ZeroSuppress(ToCurrency(SET_TOP(set)["重量引き"]));
	ShomiEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["正味重量"]));

	PureNetLabel->Caption        = AnsiString(std::abs(w1 - w2)) + " kg";

	SuryoEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["数量"]));
	TaniCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["単位コード"]));
    TaniNameEdit->Text           = ToString(SET_TOP(set)["単位マスタ名称"]);
	TankaEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["単価"]));
	KingakuEdit->Text            = ZeroSuppress(ToInt(SET_TOP(set)["金額"]));
	ShohizeiEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["伝票消費税額"]));

	Show();
}
//---------------------------------------------------------------------------

