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
	TokuButton->Caption      = ToString(DM->CFG["���Ӑ�}�X�^����"]);
	Komoku1Button->Caption   = ToString(DM->CFG["����1�}�X�^����"]);
	Komoku2Button->Caption   = ToString(DM->CFG["����2�}�X�^����"]);
	HinButton->Caption       = ToString(DM->CFG["�i�ڃ}�X�^����"]);
	ChoseiButton->Caption    = ToString(DM->CFG["��������"]);
	JuryobikiButton->Caption = ToString(DM->CFG["�d�ʈ�������"]);

	if (!ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
		TokuPanel->Visible            = false;
	}
	if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
		Komoku1Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
		Komoku2Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
		HinPanel->Visible             = false;
	}
	if (!ToBit(DM->CFG["���o�Ɏg�p�敪"])){
		HannyuCombo->Visible          = false;
	}
	if (!ToBit(DM->CFG["�����g�p�敪"])){
		ChoseiPanel->Visible          = false;
	}
	if (!ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
		JuryobikiPanel->Visible       = false;
	}
	if (!ToBit(DM->CFG["�P���g�p�敪"])){
		SuryoPanel->Visible           = false;
		TaniPanel->Visible            = false;
		TankaPanel->Visible           = false;
		KingakuPanel->Visible         = false;
		ShohizeiPanel->Visible        = false;
	}
	if (!ToBit(DM->CFG["�d�ʕҏW�敪"])){
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
	sql = " SELECT * FROM V_�v��"
		  " WHERE �v��ID = " + IntToStr(id) +
		  "   AND �����敪 <> 9";					// �_���폜�͑ΏۊO

	if (!DM->DBI.GetRecordSet(sql, set))
		return;

    if (ToInt(SET_TOP(set)["�����敪"]) == 0)
        HeaderPanel->Caption = "���ڌv�ʁ^���v�ʂ��������܂���";
    else
        HeaderPanel->Caption = "�J�[�h�v�ʂ��������܂���";

	KeiryoDatePicker->Date       = IntToDate(ToInt(SET_TOP(set)["�v�ʓ�"]));
	KeiryoNoEdit->Text           = ToInt(SET_TOP(set)["�`�[No"]);

	ShabanEdit->Text             = ToInt(SET_TOP(set)["�Ԕ�"]);
	SharyoNameEdit->Text         = ToString(SET_TOP(set)["�ԗ�����"]);
	
	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["���Ӑ�R�[�h"]));
    TokuNameEdit->Text           = ToString(SET_TOP(set)["���Ӑ於��"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["����1�R�[�h"]));
    Komoku1NameEdit->Text        = ToString(SET_TOP(set)["����1����"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["����2�R�[�h"]));
    Komoku2NameEdit->Text        = ToString(SET_TOP(set)["����2����"]);
	HinCodeEdit->Text            = ZeroSuppress(ToInt(SET_TOP(set)["�i�ڃR�[�h"]));
    HinNameEdit->Text            = ToString(SET_TOP(set)["�i�ږ���"]);
	HannyuCombo->ItemIndex       = ToInt(SET_TOP(set)["�����o�敪"]) - 1;

	Currency w1                  = ToCurrency(SET_TOP(set)["1��ڏd��"]);
	Currency w2		 			 = ToCurrency(SET_TOP(set)["2��ڏd��"]);

	FirstWEdit->Text             = ZeroSuppress(w1);
	if (!SET_TOP(set)["�v�ʓ���1"].IsNull())
		FirstTimeLabel->Caption  = TDateTime(SET_TOP(set)["�v�ʓ���1"]).FormatString("yyyy'-'mm'-'dd hh:nn");
	SecondWEdit->Text            = ZeroSuppress(w2);
	if (!SET_TOP(set)["�v�ʓ���2"].IsNull())
		SecondTimeLabel->Caption = TDateTime(SET_TOP(set)["�v�ʓ���2"]).FormatString("yyyy'-'mm'-'dd hh:nn");

	ChoseiEdit->Text             = ZeroSuppress(ToCurrency(SET_TOP(set)["�����d��"]));
	ChoseirituEdit->Text         = ZeroSuppress(ToCurrency(SET_TOP(set)["������"]));
	JuryobikiEdit->Text          = ZeroSuppress(ToCurrency(SET_TOP(set)["�d�ʈ���"]));
	ShomiEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["�����d��"]));

	PureNetLabel->Caption        = AnsiString(std::abs(w1 - w2)) + " kg";

	SuryoEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["����"]));
	TaniCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["�P�ʃR�[�h"]));
    TaniNameEdit->Text           = ToString(SET_TOP(set)["�P�ʃ}�X�^����"]);
	TankaEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(set)["�P��"]));
	KingakuEdit->Text            = ZeroSuppress(ToInt(SET_TOP(set)["���z"]));
	ShohizeiEdit->Text           = ZeroSuppress(ToInt(SET_TOP(set)["�`�[����Ŋz"]));

	Show();
}
//---------------------------------------------------------------------------

