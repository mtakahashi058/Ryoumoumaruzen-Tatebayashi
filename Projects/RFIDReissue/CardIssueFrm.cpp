//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CardIssueFrm.h"
#include "DMFrm.h"
#include <memory>
#include "RFIDWriteFrm.h"
#include <vector>
#include "ShabanSanshoFrm.h"
#include "nsoftfunc.h"
#include "SearchFrm.h"
#include "N24TPCardsFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TCardIssueForm *CardIssueForm;
//---------------------------------------------------------------------------
__fastcall TCardIssueForm::TCardIssueForm(TComponent* Owner)
	: TForm(Owner)
{
    Application->OnMessage = MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::MessageProc(tagMSG &Msg, bool &Handled)
{
    TDBGrid *Grid = 0;

    switch (Msg.message){
    case WM_MOUSEWHEEL:
        if (Msg.hwnd == ShabanSanshoForm->DBGrid->Handle)
            Grid = ShabanSanshoForm->DBGrid;
        if (Msg.hwnd == SearchForm->DBGrid->Handle)
            Grid = SearchForm->DBGrid;

        if (!Grid)
            return;

        Grid->SetFocus();

        if((short)HIWORD(Msg.wParam) > 0){
            Grid->DataSource->DataSet->Prior();
        }else{
            Grid->DataSource->DataSet->Next();
        }
        Handled = true;
        break;
    }
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormShow(TObject *Sender)
{
	if (!DM->Init()){
		Close();
        return;
    }

	TokuTitlePanel->Caption  = "  " + ToString(DM->CFG["���Ӑ�}�X�^����"]);
	HinTitlePanel->Caption   = "  " + ToString(DM->CFG["�i�ڃ}�X�^����"]);
	Item1TitlePanel->Caption = "  " + ToString(DM->CFG["����1�}�X�^����"]);
	Item2TitlePanel->Caption = "  " + ToString(DM->CFG["����2�}�X�^����"]);

	if (!ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
        TokuEdit->Enabled       = false;
        TokuNameEdit->Enabled   = false;
	}
	if (!ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
        HinEdit->Enabled        = false;
        HinNameEdit->Enabled    = false;
	}
	if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
        Item1Edit->Enabled      = false;
        Item1NameEdit->Enabled  = false;
	}
	if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
        Item2Edit->Enabled      = false;
        Item2NameEdit->Enabled  = false;
	}

    rfid_comm_port_ = ToInt(DM->INI["RFID::DeskCommPort"]);

	ClearForm();
	PageControl->ActivePage = CardSheet;

	CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
	case VK_RETURN:
		if (ActiveControl->Tag != 999 && ActiveControl->Tag > 0){
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag > 1){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB,   0, 0, 0);
			keybd_event(VK_TAB,   0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
/**
 * Implementation of Private Method
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::ClearForm()
{
    car_id_ = 0;

	CarNoEdit->Text      = AnsiString();
    CarNameEdit->Text    = AnsiString();
    TokuEdit->Text       = AnsiString();
    TokuNameEdit->Text   = AnsiString();
    HinEdit->Text        = AnsiString();
    HinNameEdit->Text    = AnsiString();
    Item1Edit->Text      = AnsiString();
    Item1NameEdit->Text  = AnsiString();
    Item2Edit->Text      = AnsiString();
    Item2NameEdit->Text  = AnsiString();
	TareEdit->Text       = AnsiString();
	GrossLimitEdit->Text = AnsiString();
	NetLimitEdit->Text   = AnsiString();
}
//---------------------------------------------------------------------------
bool __fastcall TCardIssueForm::IsValidForm()
{
	return true;
}
//---------------------------------------------------------------------------
/**
 * Implementation of Control Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarNoEditChange(TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_�ԗ� WHERE �Ԕ� = " + IntToStr(CarNoEdit->Text.ToIntDef(0));
    if (!DM->DBI.GetRecordSet(sql, set)){
        CarNameEdit->Text = AnsiString();
        return;
    }

    if (set.size() == 1){
        CarNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
    }else{
        CarNameEdit->Text = "�����̎ԗ�������";
    }
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarNoEditExit(TObject *Sender)
{
    if (ActiveControl == CloseButton)
        return;

    CarNameEdit->TabStop  = false;
    CarNameEdit->ReadOnly = true;
    CarNameEdit->Color    = clSilver;

    int car_no = CarNoEdit->Text.ToIntDef(0);
    if (car_no < 1){
        ClearForm();
        return;
    }

    AnsiString sql;
    NsRecordSet set;

    sql = "SELECT �ԗ����� FROM M_�ԗ� WHERE �ԗ�ID = " + IntToStr(car_id_);
    if (DM->DBI.GetRecordSet(sql, set)){
        if (ToString(SET_TOP(set)["�ԗ�����"]) == CarNameEdit->Text)
            return;
    }

    if (DM->Q_Shaban->Active)
        DM->Q_Shaban->Close();
    DM->Q_Shaban->SQL->Text = " SELECT"
                              "     �ԗ�ID, �Ԕ�, �ԗ�����, ��ԏd��, ���Ӑ旪��, �i�ڗ���, ����1����, ����2����"
                              " FROM V_�ԗ�"
                              " WHERE"
                              "     �g�p�敪 = 1"
                              " AND"
                              "     �Ԕ� = " + IntToStr(car_no);
    DM->Q_Shaban->Open();

    if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
        CarNoEdit->Text = AnsiString();
        CarNoEdit->SetFocus();
        return;
    }

    // �����ԗ��Ƀq�b�g�����ꍇ�A�I��������
    ShabanSanshoForm->TopPanel->Caption = "  �ԔԁF" + IntToStr(car_no);
    if (ShabanSanshoForm->ShowModal() != mrOk){
        CarNoEdit->SetFocus();
        return;
    }

    car_id_      = ShabanSanshoForm->GetCarID();

    if (!car_id_){
        CarNoEdit->Text = AnsiString();
        CarNoEdit->SetFocus();
        return;
    }

    // �ԗ��}�X�^����̑I��

    sql = "SELECT * FROM V_�ԗ� WHERE �ԗ�ID = " + IntToStr(car_id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("�I�����ꂽ�ԗ������݂��܂���B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
            Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    CarNameEdit->Text    = ToString(SET_TOP(set)["�ԗ�����"]);
    TokuEdit->Text       = ZeroSuppress(ToInt(SET_TOP(set)["���Ӑ�R�[�h"]));
    HinEdit->Text        = ZeroSuppress(ToInt(SET_TOP(set)["�i�ڃR�[�h"]));
    Item1Edit->Text      = ZeroSuppress(ToInt(SET_TOP(set)["����1�R�[�h"]));
    Item2Edit->Text      = ZeroSuppress(ToInt(SET_TOP(set)["����2�R�[�h"]));
    TareEdit->Text       = ToCurrency(SET_TOP(set)["��ԏd��"]);
    GrossLimitEdit->Text = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
    NetLimitEdit->Text   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarRefButtonClick(TObject *Sender)
{
    if (DM->Q_Shaban->Active)
        DM->Q_Shaban->Close();
    DM->Q_Shaban->SQL->Text = " SELECT"
                              "     �ԗ�ID, �Ԕ�, �ԗ�����, ��ԏd��, ���Ӑ旪��, �i�ڗ���, ����1����, ����2����"
                              " FROM V_�ԗ�"
                              " WHERE"
                              "     �g�p�敪 = 1";
    DM->Q_Shaban->Open();
    ShabanSanshoForm->TopPanel->Caption = "  �ԔԁF���ׂ�";
    if (ShabanSanshoForm->ShowModal() != mrOk){
        return;
    }

    car_id_ = ShabanSanshoForm->GetCarID();
    AnsiString sql = " SELECT"
                     "  �ԗ�ID, �Ԕ�, �ԗ�����, ��ԏd��, �ԗ����d��, �ő�ύڗ�, "
                     "  ���Ӑ�R�[�h, �i�ڃR�[�h, ����1�R�[�h, ����2�R�[�h"
                     " FROM V_�ԗ�"
                     " WHERE"
                     "  �g�p�敪 = 1"
                     " AND"
                     "  �ԗ�ID = " + IntToStr(car_id_);
    NsRecordSet set;
    if (!DM->DBI.GetRecordSet(sql, set)){
        return;
    }

    CarNoEdit->Text      = ToInt(SET_TOP(set)["�Ԕ�"]);
    CarNameEdit->Text    = ToString(SET_TOP(set)["�ԗ�����"]);
    if (ToInt(SET_TOP(set)["���Ӑ�R�[�h"]))
        TokuEdit->Text   = ZeroSuppress(ToInt(SET_TOP(set)["���Ӑ�R�[�h"]));
    if (ToInt(SET_TOP(set)["�i�ڃR�[�h"]))
        HinEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["�i�ڃR�[�h"]));
    if (ToInt(SET_TOP(set)["����1�R�[�h"]))
        Item1Edit->Text  = ZeroSuppress(ToInt(SET_TOP(set)["����1�R�[�h"]));
    if (ToInt(SET_TOP(set)["����2�R�[�h"]))
        Item2Edit->Text  = ZeroSuppress(ToInt(SET_TOP(set)["����2�R�[�h"]));
    TareEdit->Text       = ToCurrency(SET_TOP(set)["��ԏd��"]);
    GrossLimitEdit->Text = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
    NetLimitEdit->Text   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

    ReissueButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarNoEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		CarRefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::ReissueButtonClick(TObject *Sender)
{
    if (car_id_ < 1)
        return;

	if (!IsValidForm())
		return;
	ReissueButton->Enabled = false;

	AnsiString sql;
	NsRecordSet set;
	NsFieldSet fields;
	bool succeeded = true;

	try{
        int card_no = ToInt(DM->DBI.Lookup("M_�ԗ�", "�ԗ�ID", car_id_, "�J�[�h�ԍ�"));

		RFIDIssueForm->SetCommPort(rfid_comm_port_);
        RFIDIssueForm->SetCardNo(card_no);
		if (RFIDIssueForm->ShowModal() != mrOk)
			throw Exception("���s�𒆎~���܂���");

		//DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		//DM->ADOConnection->RollbackTrans();

		AnsiString message = "�G���[���������܂��� - " + e.Message;

		Application->MessageBox(message.c_str(), "�Ĕ��s�G���[", MB_OK | MB_ICONSTOP);

		succeeded = false;
	}

	ReissueButton->Enabled = true;

	if (!succeeded)
		return;

	Application->MessageBox("�Ĕ��s���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	ClearForm();
	CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::TokuEditChange(TObject *Sender)
{
	int code = TokuEdit->Text.ToIntDef(0);

	NsRecordSet set;
	AnsiString sql = "SELECT ���Ӑ旪�� FROM M_���Ӑ� WHERE ���Ӑ�R�[�h = " + IntToStr(code);
	if (DM->DBI.GetRecordSet(sql, set)){
		TokuEdit->Text     = code;
		TokuNameEdit->Text = ToString(SET_TOP(set)["���Ӑ旪��"]);
	}else
		TokuNameEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::HinEditChange(TObject *Sender)
{
    int code = HinEdit->Text.ToIntDef(0);
    if (!code){
        HinNameEdit->Text = AnsiString();
        return;
    }

    AnsiString sql;
    NsRecordSet set;

    sql = "SELECT �i�ږ��� FROM M_�i�� WHERE �i�ڃR�[�h = " + IntToStr(code);
    if (!DM->DBI.GetRecordSet(sql, set)){
        HinNameEdit->Text = AnsiString();
    }else{
        HinNameEdit->Text = ToString(SET_TOP(set)["�i�ږ���"]);
    }

}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item1EditChange(TObject *Sender)
{
	int code = Item1Edit->Text.ToIntDef(0);

	NsRecordSet set;
	AnsiString sql = "SELECT ����1���� FROM M_����1 WHERE ����1�R�[�h = " + IntToStr(code);
	if (DM->DBI.GetRecordSet(sql, set)){
		Item1Edit->Text     = code;
		Item1NameEdit->Text = ToString(SET_TOP(set)["����1����"]);
	}else
		Item1NameEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item2EditChange(TObject *Sender)
{
	int code = Item2Edit->Text.ToIntDef(0);

	NsRecordSet set;
	AnsiString sql = "SELECT ����2���� FROM M_����2 WHERE ����2�R�[�h = " + IntToStr(code);
	if (DM->DBI.GetRecordSet(sql, set)){
		Item2Edit->Text     = code;
		Item2NameEdit->Text = ToString(SET_TOP(set)["����2����"]);
	}else
		Item2NameEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::ClearButtonClick(TObject *Sender)
{
    ClearForm();
    CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
