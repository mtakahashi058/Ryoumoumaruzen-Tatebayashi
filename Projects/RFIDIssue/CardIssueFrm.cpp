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
        TokuRefButton->Enabled  = false;
	}
	if (!ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
        HinEdit->Enabled        = false;
        HinNameEdit->Enabled    = false;
        HinRefButton->Enabled   = false;
	}
	if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
        Item1Edit->Enabled      = false;
        Item1NameEdit->Enabled  = false;
        Item1RefButton->Enabled = false;
	}
	if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
        Item2Edit->Enabled      = false;
        Item2NameEdit->Enabled  = false;
        Item2RefButton->Enabled = false;
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
	int val;

    /** �܂��󂯎葤�ł̎������ł��Ă��Ȃ����A�ԗ��w��Ȃ����\��
    if (car_id_ == 0){
        Application->MessageBox("�ԗ��̑I���������ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
        CarNoEdit->SetFocus();
        return false;
    }
    **/

    if (!TokuEdit->Text.IsEmpty() && TokuNameEdit->Text.IsEmpty()){
        AnsiString message = ToString(DM->CFG["���Ӑ�}�X�^����"]) + "�������ł�";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		TokuEdit->Text = AnsiString();
		TokuEdit->SetFocus();
		return false;
    }
    if (!HinEdit->Text.IsEmpty() && HinNameEdit->Text.IsEmpty()){
        AnsiString message = ToString(DM->CFG["�i�ڃ}�X�^����"]) + "�������ł�";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		HinEdit->Text = AnsiString();
		HinEdit->SetFocus();
		return false;
    }
	if (!Item1Edit->Text.IsEmpty() && Item1NameEdit->Text.IsEmpty()){
		AnsiString message = ToString(DM->CFG["����1�}�X�^����"]) + "�������ł�";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		Item1Edit->Text = AnsiString();
		Item1Edit->SetFocus();
		return false;
	}
	if (!Item2Edit->Text.IsEmpty() && Item2NameEdit->Text.IsEmpty()){
		AnsiString message = ToString(DM->CFG["����2�}�X�^����"]) + "�������ł�";
		Application->MessageBox(message.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		Item2Edit->Text = AnsiString();
		Item2Edit->SetFocus();
		return false;
	}

	if (!TareEdit->Text.IsEmpty() && TareEdit->Text != "0"){
		val = TareEdit->Text.ToIntDef(0);
		if (val < 1){
			Application->MessageBox("��ԏd�ʂ������ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
			TareEdit->Text = AnsiString();
			TareEdit->SetFocus();
			return false;
		}
	}
	if (!GrossLimitEdit->Text.IsEmpty() && GrossLimitEdit->Text != "0"){
		val = GrossLimitEdit->Text.ToIntDef(0);
		if (val < 1){
			Application->MessageBox("���d�ʏ���������ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
			GrossLimitEdit->Text = AnsiString();
			GrossLimitEdit->SetFocus();
			return false;
		}
	}
	if (!NetLimitEdit->Text.IsEmpty() && NetLimitEdit->Text != "0"){
		val = NetLimitEdit->Text.ToIntDef(0);
		if (val < 1){
			Application->MessageBox("�����d�ʏ���������ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
			NetLimitEdit->Text = AnsiString();
			NetLimitEdit->SetFocus();
			return false;
		}
	}

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
        CarNoEdit->Text = AnsiString();
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
        // �V�K�ԗ��o�^

        car_id_ = -1;
        CarNameEdit->TabStop  = true;
        CarNameEdit->ReadOnly = false;
        CarNameEdit->Color    = clWindow;
        CarNameEdit->Text     = AnsiString(); //"�ԗ���";
        CarNameEdit->SetFocus();

        return;
    }

    // �����ԗ��Ƀq�b�g�����ꍇ�A�I��������
    ShabanSanshoForm->TopPanel->Caption = "  �ԔԁF" + IntToStr(car_no);
    ShabanSanshoForm->NewButton->Visible = true;
    if (ShabanSanshoForm->ShowModal() != mrOk){
        CarNoEdit->SetFocus();
        return;
    }

    car_id_      = ShabanSanshoForm->GetCarID();

    if (!car_id_){
        // �V�K�ԗ��i��Ɠ��������j

        car_id_ = -1;
        CarNameEdit->TabStop  = true;
        CarNameEdit->ReadOnly = false;
        CarNameEdit->Color    = clWindow;
        CarNameEdit->Text  = "�ԗ���";
        CarNameEdit->SetFocus();

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
    ShabanSanshoForm->NewButton->Visible = false;
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

    TokuEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::TokuRefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ旪�� FROM M_���Ӑ� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ���Ӑ�R�[�h ";
    SearchForm->table_name = "M_���Ӑ�";
    if (SearchForm->ShowModal() != mrOk)
        return;
    TokuEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
    TokuEdit->OnChange(NULL);
    TokuEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::HinRefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT �i�ڃR�[�h, �i�ڗ��� FROM M_�i�� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
    SearchForm->table_name = "M_�i��";
    if (SearchForm->ShowModal() != mrOk)
        return;
    HinEdit->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
    HinEdit->OnChange(NULL);
    HinEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item1RefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT ����1�R�[�h, ����1���� FROM M_����1 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����1�R�[�h ";
    SearchForm->table_name = "M_����1";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item1Edit->Text = SearchForm->Query->FieldByName("����1�R�[�h")->AsInteger;
    Item1Edit->OnChange(0);
    Item1Edit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item2RefButtonClick(TObject *Sender)
{
    SearchForm->Top = Top;
    SearchForm->Left = Left + 450;
    SearchForm->based_sql = "SELECT ����2�R�[�h, ����2���� FROM M_����2 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����2�R�[�h ";
    SearchForm->table_name = "M_����2";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Item2Edit->Text = SearchForm->Query->FieldByName("����2�R�[�h")->AsInteger;
    Item2Edit->OnChange(0);
    Item2Edit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::CarNoEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		CarRefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::TokuEditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		TokuRefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::HinEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_F4)
		HinRefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item1EditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		Item1RefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::Item2EditKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_F4)
		Item2RefButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::IssueButtonClick(TObject *Sender)
{
	if (!IsValidForm())
		return;
	IssueButton->Enabled = false;

	AnsiString sql;
	NsRecordSet set;
	NsFieldSet fields;
	bool succeeded = true;

	try{
		//DM->ADOConnection->BeginTrans();

        bool insert = car_id_ < 1 ? true : false;

        // �����U��o���J�[�h�ԍ�
		sql = "SELECT IsNull(MAX(�J�[�h�ԍ�), 500000) + 1 AS �J�[�h�ԍ� FROM M_�ԗ�"
			  " WHERE �J�[�h�ԍ� > 500000";
		DM->DBI.GetRecordSet(sql, set);
		int card_no = ToInt(SET_TOP(set)["�J�[�h�ԍ�"]);

        TDateTime now(Now());

        if (insert){
            fields << NsField("[�Ԕ�]",     CarNoEdit->Text.ToIntDef(0))
                   << NsField("[�쐬����]", now);
        }

		fields << NsField("[�J�[�h�ԍ�]",   card_no)
			   << NsField("[�ԗ�����]",     CarNameEdit->Text)
               << NsField("[��ԏd��]",     TareEdit->Text.ToIntDef(0))
               << NsField("[�ő�ύڗ�]",   NetLimitEdit->Text.ToIntDef(0))
               << NsField("[�ԗ����d��]",   GrossLimitEdit->Text.ToIntDef(0))
               << NsField("[���Ӑ�ID]",     ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuEdit->Text.ToIntDef(0),  "���Ӑ�ID")))
               << NsField("[�i��ID]",       ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   HinEdit->Text.ToIntDef(0),   "�i��ID")))
               << NsField("[����1ID]",      ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h",  Item1Edit->Text.ToIntDef(0), "����1ID")))
               << NsField("[����2ID]",      ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h",  Item2Edit->Text.ToIntDef(0), "����2ID")))
               << NsField("[�g�p�敪]",     1)
               << NsField("[�X�V����]",     now);
        if (insert)
    		DM->DBI.Insert("M_�ԗ�", fields);
        else
            DM->DBI.Update("M_�ԗ�", "�ԗ�ID", car_id_, fields);

		RFIDIssueForm->SetCommPort(rfid_comm_port_);
        RFIDIssueForm->SetCardNo(card_no);
		if (RFIDIssueForm->ShowModal() != mrOk)
			throw Exception("���s�𒆎~���܂���");

		//DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		//DM->ADOConnection->RollbackTrans();

		AnsiString message = "�G���[���������܂��� - " + e.Message;

		Application->MessageBox(message.c_str(), "�J�[�h���s�G���[", MB_OK | MB_ICONSTOP);

		succeeded = false;
	}

	IssueButton->Enabled = true;

	if (!succeeded)
		return;

	Application->MessageBox("�J�[�h�𔭍s���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	ClearForm();
	CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::N24TPCardsButtonClick(TObject *Sender)
{
    int no = N24TPCardsForm->ShowModal();
    if (no < 90000000)
        return;

    RFIDIssueForm->SetCommPort(rfid_comm_port_);
    RFIDIssueForm->SetCardNo(no);
    if (RFIDIssueForm->ShowModal() != mrOk){
		Application->MessageBox("���s�𒆎~���܂���", "�J�[�h���s�G���[", MB_OK | MB_ICONSTOP);
        return;
    }
	Application->MessageBox("�J�[�h�𔭍s���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::ClearButtonClick(TObject *Sender)
{
    ClearForm();
    CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------

