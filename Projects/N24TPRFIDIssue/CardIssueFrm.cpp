//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "n24tp.h"
#include "PageState.h"
#include "CardIssueFrm.h"
#include "DMFrm.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "CEdit"
#pragma resource "*.dfm"
TCardIssueForm *CardIssueForm;
//---------------------------------------------------------------------------
__fastcall TCardIssueForm::TCardIssueForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	std::auto_ptr<TIniFile> ini(new TIniFile(ExtractFilePath(Application->ExeName) + N24TP::INI_NAME));

	AnsiString udl_file = ini->ReadString("ADO", "UDL", "");

	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Close();
	try{
		DM->ADOConnection->ConnectionString = "FILE NAME=" + udl_file;

		DM->ADOConnection->Open();

        DM->CFG.Load(&(DM->DBI));
	}catch(Exception& e){
		Application->MessageBox(AnsiString("�f�[�^�x�[�X�ɐڑ��ł��܂��� - \r\n" + e.Message).c_str(),
			Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

    AnsiString toku_master  = DM->TrimSpace(ToString(DM->CFG["���Ӑ�}�X�^����"]));
    AnsiString meig_master  = DM->TrimSpace(ToString(DM->CFG["�i�ڃ}�X�^����"]));
    AnsiString item1_master = DM->TrimSpace(ToString(DM->CFG["����1�}�X�^����"]));
    AnsiString item2_master = DM->TrimSpace(ToString(DM->CFG["����2�}�X�^����"]));

    TokuTitlePanel->Caption  = " " + toku_master;
    MeigTitlePanel->Caption  = " " + meig_master;
    Item1TitlePanel->Caption = " " + item1_master;
    Item2TitlePanel->Caption = " " + item2_master;
	TokuConfirmTitlePanel->Caption  = "  " + toku_master;
	MeigConfirmTitlePanel->Caption  = "  " + meig_master;
	Item1ConfirmTitlePanel->Caption = "  " + item1_master;
	Item2ConfirmTitlePanel->Caption = "  " + item2_master;
	AnonyTokuButton->Caption  = toku_master + "���w�肵�Ȃ�";
	AnonyMeigButton->Caption  = meig_master + "���w�肵�Ȃ�";
	AnonyItem1Button->Caption = item1_master + "���w�肵�Ȃ�";
	AnonyItem2Button->Caption = item2_master + "���w�肵�Ȃ�";

    rfid_port_ = ini->ReadInteger("RFID", "CommPort", 1);

	current_state_ = &stateStartup;

	InitKanaTable();

	stateStartup.connectEvent(evConfirm, &stateSelectToku);

	stateSelectToku.connectEvent(evTokuSelect, &stateSelectMeig);
	stateSelectToku.connectEvent(evAdminCards, &stateAdminIssue);
	stateSelectToku.Initialize();

	stateSelectMeig.connectEvent(evMeigSelect, &stateSelectItem1);
	stateSelectMeig.connectEvent(evBack, &stateSelectToku);
	stateSelectMeig.Initialize();

	stateSelectItem1.connectEvent(evItem1Select, &stateSelectItem2);
	stateSelectItem1.connectEvent(evBack, &stateSelectMeig);
	stateSelectItem1.Initialize();

	stateSelectItem2.connectEvent(evItem2Select, &stateInputCarNo);
	stateSelectItem2.connectEvent(evBack, &stateSelectItem1);
	stateSelectItem2.Initialize();

	stateInputCarNo.connectEvent(evCarNoInput, &stateConfirm);
	stateInputCarNo.connectEvent(evBack, &stateSelectItem2);

	stateConfirm.connectEvent(evConfirm, &stateIssue);
	stateConfirm.connectEvent(evBack, &stateInputCarNo);

	stateIssue.connectEvent(evWrite, &stateSelectToku);
	stateIssue.connectEvent(evBack, &stateConfirm);

	stateAdminIssue.connectEvent(evWrite, &stateSelectToku);
	stateAdminIssue.connectEvent(evBack, &stateSelectToku);

	current_state_ = current_state_->transit(evConfirm);
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
    //
}
//---------------------------------------------------------------------------
/**
 * Implementation of Private Method
 */
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::InitKanaTable()
{
	// ���Ȍ����p�e�[�u���쐬
	kana_table_[0][1] = "�";
	kana_table_[0][2] = "�";
	kana_table_[0][3] = "�";
	kana_table_[0][4] = "�";
	kana_table_[0][5] = "�";
	kana_table_[1][1] = "�";
	kana_table_[1][2] = "�";
	kana_table_[1][3] = "�";
	kana_table_[1][4] = "�";
	kana_table_[1][5] = "�";
	kana_table_[2][1] = "�";
	kana_table_[2][2] = "�";
	kana_table_[2][3] = "�";
	kana_table_[2][4] = "�";
	kana_table_[2][5] = "�";
	kana_table_[3][1] = "�";
	kana_table_[3][2] = "�";
	kana_table_[3][3] = "�";
	kana_table_[3][4] = "�";
	kana_table_[3][5] = "�";
	kana_table_[4][1] = "�";
	kana_table_[4][2] = "�";
	kana_table_[4][3] = "�";
	kana_table_[4][4] = "�";
	kana_table_[4][5] = "�";
	kana_table_[5][1] = "�";
	kana_table_[5][2] = "�";
	kana_table_[5][3] = "�";
	kana_table_[5][4] = "�";
	kana_table_[5][5] = "�";
	kana_table_[6][1] = "�";
	kana_table_[6][2] = "�";
	kana_table_[6][3] = "�";
	kana_table_[6][4] = "�";
	kana_table_[6][5] = "�";
	kana_table_[7][1] = "�";
	kana_table_[7][2] = AnsiString();
	kana_table_[7][3] = "�";
	kana_table_[7][4] = AnsiString();
	kana_table_[7][5] = "�";
	kana_table_[8][1] = "�";
	kana_table_[8][2] = "�";
	kana_table_[8][3] = "�";
	kana_table_[8][4] = "�";
	kana_table_[8][5] = "�";
	kana_table_[9][1] = "�";
	kana_table_[9][2] = AnsiString();
	kana_table_[9][3] = "�";
	kana_table_[9][4] = AnsiString();
	kana_table_[9][5] = "�";
}
//---------------------------------------------------------------------------
int __fastcall TCardIssueForm::SearchLineIndex(const AnsiString& kana)
{
	for (KanaTable::iterator i = kana_table_.begin(); i != kana_table_.end(); i++)
		for (KanaOnTable::iterator j = i->second.begin(); j != i->second.end(); j++)
			if (j->second == kana)
				return i->first;
	return -1;
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
// ����y�߂�z
void __fastcall TCardIssueForm::BackButtonClick(TObject *Sender)
{
	current_state_ = current_state_->transit(evBack);
}
//---------------------------------------------------------------------------
// �Ǘ��J�[�h���s
void __fastcall TCardIssueForm::AdminCardIssueButtonClick(TObject *Sender)
{
	current_state_ = current_state_->transit(evAdminCards);
}
//---------------------------------------------------------------------------
// ���e�m�F�{�^��
void __fastcall TCardIssueForm::ContentsConfirmButtonClick(TObject *Sender)
{
	current_state_ = current_state_->transit(evConfirm);
}
//---------------------------------------------------------------------------
// �J�[�h��������
void __fastcall TCardIssueForm::WriteButtonClick(TObject *Sender)
{
	PageState *state = static_cast<PageState *>(current_state_);
	if (!state)	return;

	TMemo *Status;
	int Tag = static_cast<TComponent *>(Sender)->Tag;

	int fixed_card_no = 0;
	switch (Tag){
	case 2: //AdminIssueButton->Tag
		Status        = AdminCardIssueStatus;
		fixed_card_no = N24TP::ADMIN_CARD_NO;
		break;
	case 3: //ZeroSetIssueButton->Tag
		Status        = AdminCardIssueStatus;
		fixed_card_no = N24TP::SET_ZERO_CARD_NO;
		break;
	case 4: //ZeroCancelIssueButton->Tag
		Status        = AdminCardIssueStatus;
		fixed_card_no = N24TP::CLR_ZERO_CARD_NO;
		break;
	default:
		Status  = CardIssueStatus;
	}

	NsRecordSet set;
	NsFieldSet fields;

	WriteButton->Enabled           = false;
	AdminIssueButton->Enabled      = false;
	ZeroSetIssueButton->Enabled    = false;
	ZeroCancelIssueButton->Enabled = false;

	try{
        DM->ADOConnection->BeginTrans();
        if (fixed_card_no){
            // �Ǘ��p�Œ�J�[�h

            HF04Issuer HF04(rfid_port_);
            HF04.IssueCard(fixed_card_no);
        }else{
            // �ԗ��J�[�h


            // �����U��o���J�[�h�ԍ�
            AnsiString sql;
    		sql = "SELECT IsNull(MAX(�J�[�h�ԍ�), 0) + 1 AS �J�[�h�ԍ� FROM M_�ԗ�"
		    	  " WHERE �J�[�h�ԍ� < 500000";
    		DM->DBI.GetRecordSet(sql, set);

	    	int card_no = ToInt(SET_TOP(set)["�J�[�h�ԍ�"]);
            int car_id  = state->GetCarID();
            int car_no  = state->GetCarNo();
            TDateTime now(Now());
            bool insert = false;

            if (state->IsNewCar()){
                ///// �V�K�ԗ��o�^
                fields << NsField("[�Ԕ�]",     car_no)
                       << NsField("[�ԗ�����]", now.FormatString("mm/dd'�ɃJ�[�h���s'"))
                       << NsField("[�쐬����]", now);
                insert = true;
            }

    		fields << NsField("[�J�[�h�ԍ�]",   card_no)
                   << NsField("[���Ӑ�ID]",     state->GetTokuID())
                   << NsField("[�i��ID]",       state->GetMeigID())
                   << NsField("[����1ID]",      state->GetItem1ID())
                   << NsField("[����2ID]",      state->GetItem2ID())
                   << NsField("[�g�p�敪]",     1)
                   << NsField("[�X�V����]",     now);

            if (insert)
        		DM->DBI.Insert("M_�ԗ�", fields);
            else
                DM->DBI.Update("M_�ԗ�", "�ԗ�ID", car_id, fields);

            HF04Issuer HF04(rfid_port_);
            HF04.IssueCard(card_no);

	    	DM->ADOConnection->CommitTrans();
        }

		::MessageBeep(MB_ICONASTERISK);
	}catch(ERFIDError & e){
		DM->ADOConnection->RollbackTrans();
		Status->Lines->Insert(0, e.Message);

		WriteButton->Enabled           = true;
		AdminIssueButton->Enabled      = true;
		ZeroSetIssueButton->Enabled    = true;
		ZeroCancelIssueButton->Enabled = true;
		return;
	}catch(Exception& e){
		DM->ADOConnection->RollbackTrans();
		Status->Lines->Insert(0, AnsiString("DB�G���[: ") + e.Message);

		WriteButton->Enabled           = true;
		AdminIssueButton->Enabled      = true;
		ZeroSetIssueButton->Enabled    = true;
		ZeroCancelIssueButton->Enabled = true;
		return;
	}

	Status->Lines->Text = "�J�[�h�𔭍s���܂���";
	Application->ProcessMessages();
	Sleep(1000);

	BackButton->Enabled = false;

	current_state_ = current_state_->transit(evWrite);
}
//---------------------------------------------------------------------------
// ���Ӑ�ꗗ��X�N���[��
void __fastcall TCardIssueForm::TokuScrollUpButtonClick(TObject *Sender)
{
	int top = stateSelectToku.GetCurrentTop();
	top -= 3;
	top = (top < 0) ? 0 : top;
	stateSelectToku.SetupButtons(top);
}
//---------------------------------------------------------------------------
// ���Ӑ�ꗗ���X�N���[��
void __fastcall TCardIssueForm::TokuScrollDownButtonClick(TObject *Sender)
{
	int top = stateSelectToku.GetCurrentTop();
	top += 3;
	stateSelectToku.SetupButtons(top);
	if (stateSelectToku.GetEnabledButtons() < 1)	// �\��������̂��Ȃ��ꍇ
		TokuScrollUpButtonClick(Sender);	// ��ɃX�N���[��
}
//---------------------------------------------------------------------------
// ���Ӑ�I��
void __fastcall TCardIssueForm::Toku1ButtonClick(TObject *Sender)
{
	NsRecord record;
	record["���Ӑ�ID"]   = dynamic_cast<TButton *>(Sender)->Tag;
	record["���Ӑ於��"] = dynamic_cast<TButton *>(Sender)->Caption;
	current_state_ = current_state_->transit(evTokuSelect, &record);
}
//---------------------------------------------------------------------------
// ���Ӑ�w��Ȃ�
void __fastcall TCardIssueForm::AnonyTokuButtonClick(TObject *Sender)
{
	NsRecord record;
	record["���Ӑ�ID"]   = 0;
	record["���Ӑ於��"] = "�w��Ȃ�";
	current_state_ = current_state_->transit(evTokuSelect, &record);
}
//---------------------------------------------------------------------------
// ���Ӑ�J�i�{�^��
void __fastcall TCardIssueForm::TokuKana1ButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;

	AnsiString kana;
	enum KanaDisplayMode {kdmAll, kdmLine, kdmSingle} kana_mode;

	if (TokuKana10Button->Visible)
		kana_mode = kdmAll;
	else if (TokuKana5Button->Visible)
		kana_mode = kdmLine;
	else
		kana_mode = kdmSingle;

	if (tag != 99){
		kana = dynamic_cast<TButton *>(Sender)->Caption;
		if (kana.IsEmpty())
			return;
	}

	// �P���\���Ŗ߂�{�^���ȊO�̏ꍇ�́A����
	if (kana_mode == kdmSingle && tag != 99)
		return;

	if (tag == 99){		// �߂�{�^��
		if (kana_mode == kdmLine){
			TokuKana1Button->Caption = "�";
			TokuKana2Button->Caption = "�";
			TokuKana3Button->Caption = "�";
			TokuKana4Button->Caption = "�";
			TokuKana5Button->Caption = "�";
			TokuKana6Button->Caption = "�";
			TokuKana7Button->Caption = "�";
			TokuKana8Button->Caption = "�";
			TokuKana9Button->Caption = "�";
			TokuKana10Button->Caption = "�";
			TokuKana1Button->Visible = true;
			TokuKana2Button->Visible = true;
			TokuKana3Button->Visible = true;
			TokuKana4Button->Visible = true;
			TokuKana5Button->Visible = true;
			TokuKana6Button->Visible = true;
			TokuKana7Button->Visible = true;
			TokuKana8Button->Visible = true;
			TokuKana9Button->Visible = true;
			TokuKana10Button->Visible = true;
			TokuKanaBackButton->Visible = false;
			stateSelectToku.SetKana(AnsiString(), AnsiString());
			stateSelectToku.SetupButtons(0);
		}else if (kana_mode == kdmSingle){
			int line = SearchLineIndex(TokuKana1Button->Caption);
			TokuKana1Button->Caption = kana_table_[line][1];
			TokuKana2Button->Caption = kana_table_[line][2];
			TokuKana3Button->Caption = kana_table_[line][3];
			TokuKana4Button->Caption = kana_table_[line][4];
			TokuKana5Button->Caption = kana_table_[line][5];
			TokuKana1Button->Visible = true;
			TokuKana2Button->Visible = true;
			TokuKana3Button->Visible = true;
			TokuKana4Button->Visible = true;
			TokuKana5Button->Visible = true;
			stateSelectToku.SetKana(kana_table_[line][1], kana_table_[line][5]);
			stateSelectToku.SetupButtons(0);
		}
		return;
	}

	if (kana_mode == kdmAll){
		int line = SearchLineIndex(kana);
		TokuKana1Button->Caption = kana_table_[line][1];
		TokuKana2Button->Caption = kana_table_[line][2];
		TokuKana3Button->Caption = kana_table_[line][3];
		TokuKana4Button->Caption = kana_table_[line][4];
		TokuKana5Button->Caption = kana_table_[line][5];
		TokuKana6Button->Caption = AnsiString();
		TokuKana7Button->Caption = AnsiString();
		TokuKana8Button->Caption = AnsiString();
		TokuKana9Button->Caption = AnsiString();
		TokuKana10Button->Caption = AnsiString();
		TokuKana1Button->Visible = true;
		TokuKana2Button->Visible = true;
		TokuKana3Button->Visible = true;
		TokuKana4Button->Visible = true;
		TokuKana5Button->Visible = true;
		TokuKana6Button->Visible = false;
		TokuKana7Button->Visible = false;
		TokuKana8Button->Visible = false;
		TokuKana9Button->Visible = false;
		TokuKana10Button->Visible = false;
		TokuKanaBackButton->Visible = true;
		stateSelectToku.SetKana(kana_table_[line][1], kana_table_[line][5]);
		stateSelectToku.SetupButtons(0);
	}else if (kana_mode == kdmLine){
		TokuKana1Button->Caption = kana;
		TokuKana2Button->Caption = AnsiString();
		TokuKana3Button->Caption = AnsiString();
		TokuKana4Button->Caption = AnsiString();
		TokuKana5Button->Caption = AnsiString();
		TokuKana6Button->Caption = AnsiString();
		TokuKana7Button->Caption = AnsiString();
		TokuKana8Button->Caption = AnsiString();
		TokuKana9Button->Caption = AnsiString();
		TokuKana10Button->Caption = AnsiString();
		TokuKana1Button->Visible = true;
		TokuKana2Button->Visible = false;
		TokuKana3Button->Visible = false;
		TokuKana4Button->Visible = false;
		TokuKana5Button->Visible = false;
		TokuKana6Button->Visible = false;
		TokuKana7Button->Visible = false;
		TokuKana8Button->Visible = false;
		TokuKana9Button->Visible = false;
		TokuKana10Button->Visible = false;
		TokuKanaBackButton->Visible = true;
		stateSelectToku.SetKana(kana, AnsiString());
		stateSelectToku.SetupButtons(0);
	}
}
//---------------------------------------------------------------------------
// �i�ڈꗗ��X�N���[��
void __fastcall TCardIssueForm::MeigScrollUpButtonClick(TObject *Sender)
{
	int top = stateSelectMeig.GetCurrentTop();
	top -= 3;
	top = (top < 0) ? 0 : top;
	stateSelectMeig.SetupButtons(top);
}
//---------------------------------------------------------------------------
// �i�ڈꗗ���X�N���[��
void __fastcall TCardIssueForm::MeigScrollDownButtonClick(TObject *Sender)
{
	int top = stateSelectMeig.GetCurrentTop();
	top += 3;
	stateSelectMeig.SetupButtons(top);
	if (stateSelectMeig.GetEnabledButtons() < 1)	// �\��������̂��Ȃ��ꍇ
		MeigScrollUpButtonClick(Sender);	// ��ɃX�N���[��
}
//---------------------------------------------------------------------------
// �i�ڑI��
void __fastcall TCardIssueForm::Meig1ButtonClick(TObject *Sender)
{
	NsRecord record;
	record["�i��ID"]   = dynamic_cast<TButton *>(Sender)->Tag;
	record["�i�ږ���"] = dynamic_cast<TButton *>(Sender)->Caption;
	current_state_ = current_state_->transit(evMeigSelect, &record);
}
//---------------------------------------------------------------------------
// �i�ڑI���Ȃ�
void __fastcall TCardIssueForm::AnonyMeigButtonClick(TObject *Sender)
{
	NsRecord record;
	record["�i��ID"]   = 0;
	record["�i�ږ���"] = "�w��Ȃ�";
	current_state_ = current_state_->transit(evMeigSelect, &record);
}
//---------------------------------------------------------------------------
// �i�ڃJ�i�{�^��
void __fastcall TCardIssueForm::MeigKana1ButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;

	AnsiString kana;
	enum KanaDisplayMode {kdmAll, kdmLine, kdmSingle} kana_mode;

	if (MeigKana10Button->Visible)
		kana_mode = kdmAll;
	else if (MeigKana5Button->Visible)
		kana_mode = kdmLine;
	else
		kana_mode = kdmSingle;

	if (tag != 99){
		kana = dynamic_cast<TButton *>(Sender)->Caption;
		if (kana.IsEmpty())
			return;
	}

	// �P���\���Ŗ߂�{�^���ȊO�̏ꍇ�́A����
	if (kana_mode == kdmSingle && tag != 99)
		return;

	if (tag == 99){		// �߂�{�^��
		if (kana_mode == kdmLine){
			MeigKana1Button->Caption = "�";
			MeigKana2Button->Caption = "�";
			MeigKana3Button->Caption = "�";
			MeigKana4Button->Caption = "�";
			MeigKana5Button->Caption = "�";
			MeigKana6Button->Caption = "�";
			MeigKana7Button->Caption = "�";
			MeigKana8Button->Caption = "�";
			MeigKana9Button->Caption = "�";
			MeigKana10Button->Caption = "�";
			MeigKana1Button->Visible = true;
			MeigKana2Button->Visible = true;
			MeigKana3Button->Visible = true;
			MeigKana4Button->Visible = true;
			MeigKana5Button->Visible = true;
			MeigKana6Button->Visible = true;
			MeigKana7Button->Visible = true;
			MeigKana8Button->Visible = true;
			MeigKana9Button->Visible = true;
			MeigKana10Button->Visible = true;
			MeigKanaBackButton->Visible = false;
			stateSelectMeig.SetKana(AnsiString(), AnsiString());
			stateSelectMeig.SetupButtons(0);
		}else if (kana_mode == kdmSingle){
			int line = SearchLineIndex(MeigKana1Button->Caption);
			MeigKana1Button->Caption = kana_table_[line][1];
			MeigKana2Button->Caption = kana_table_[line][2];
			MeigKana3Button->Caption = kana_table_[line][3];
			MeigKana4Button->Caption = kana_table_[line][4];
			MeigKana5Button->Caption = kana_table_[line][5];
			MeigKana1Button->Visible = true;
			MeigKana2Button->Visible = true;
			MeigKana3Button->Visible = true;
			MeigKana4Button->Visible = true;
			MeigKana5Button->Visible = true;
			stateSelectMeig.SetKana(kana_table_[line][1], kana_table_[line][5]);
			stateSelectMeig.SetupButtons(0);
		}
		return;
	}

	if (kana_mode == kdmAll){
		int line = SearchLineIndex(kana);
		MeigKana1Button->Caption = kana_table_[line][1];
		MeigKana2Button->Caption = kana_table_[line][2];
		MeigKana3Button->Caption = kana_table_[line][3];
		MeigKana4Button->Caption = kana_table_[line][4];
		MeigKana5Button->Caption = kana_table_[line][5];
		MeigKana6Button->Caption = AnsiString();
		MeigKana7Button->Caption = AnsiString();
		MeigKana8Button->Caption = AnsiString();
		MeigKana9Button->Caption = AnsiString();
		MeigKana10Button->Caption = AnsiString();
		MeigKana1Button->Visible = true;
		MeigKana2Button->Visible = true;
		MeigKana3Button->Visible = true;
		MeigKana4Button->Visible = true;
		MeigKana5Button->Visible = true;
		MeigKana6Button->Visible = false;
		MeigKana7Button->Visible = false;
		MeigKana8Button->Visible = false;
		MeigKana9Button->Visible = false;
		MeigKana10Button->Visible = false;
		MeigKanaBackButton->Visible = true;
		stateSelectMeig.SetKana(kana_table_[line][1], kana_table_[line][5]);
		stateSelectMeig.SetupButtons(0);
	}else if (kana_mode == kdmLine){
		MeigKana1Button->Caption = kana;
		MeigKana2Button->Caption = AnsiString();
		MeigKana3Button->Caption = AnsiString();
		MeigKana4Button->Caption = AnsiString();
		MeigKana5Button->Caption = AnsiString();
		MeigKana6Button->Caption = AnsiString();
		MeigKana7Button->Caption = AnsiString();
		MeigKana8Button->Caption = AnsiString();
		MeigKana9Button->Caption = AnsiString();
		MeigKana10Button->Caption = AnsiString();
		MeigKana1Button->Visible = true;
		MeigKana2Button->Visible = false;
		MeigKana3Button->Visible = false;
		MeigKana4Button->Visible = false;
		MeigKana5Button->Visible = false;
		MeigKana6Button->Visible = false;
		MeigKana7Button->Visible = false;
		MeigKana8Button->Visible = false;
		MeigKana9Button->Visible = false;
		MeigKana10Button->Visible = false;
		MeigKanaBackButton->Visible = true;
		stateSelectMeig.SetKana(kana, AnsiString());
		stateSelectMeig.SetupButtons(0);
	}
}
//---------------------------------------------------------------------------
// ����1�ꗗ��X�N���[��
void __fastcall TCardIssueForm::Item1ScrollUpButtonClick(
	  TObject *Sender)
{
	int top = stateSelectItem1.GetCurrentTop();
	top -= 3;
	top = (top < 0) ? 0 : top;
	stateSelectItem1.SetupButtons(top);
}
//---------------------------------------------------------------------------
// ����1�ꗗ���X�N���[��
void __fastcall TCardIssueForm::Item1ScrollDownButtonClick(
	  TObject *Sender)
{
	int top = stateSelectItem1.GetCurrentTop();
	top += 3;
	stateSelectItem1.SetupButtons(top);
	if (stateSelectItem1.GetEnabledButtons() < 1)	// �\��������̂��Ȃ��ꍇ
		Item1ScrollUpButtonClick(Sender);	// ��ɃX�N���[��
}
//---------------------------------------------------------------------------
// ����1�I��
void __fastcall TCardIssueForm::Item11ButtonClick(TObject *Sender)
{
	NsRecord record;
	record["����1ID"]   = dynamic_cast<TButton *>(Sender)->Tag;
	record["����1����"] = dynamic_cast<TButton *>(Sender)->Caption;
	current_state_ = current_state_->transit(evItem1Select, &record);
}
//---------------------------------------------------------------------------
// ����1�w��Ȃ�
void __fastcall TCardIssueForm::AnonyItem1ButtonClick(TObject *Sender)
{
	NsRecord record;
	record["����1ID"]   = 0;
	record["����1����"] = "�w��Ȃ�";
	current_state_ = current_state_->transit(evItem1Select, &record);
}
//---------------------------------------------------------------------------
// �J�i�{�^��
void __fastcall TCardIssueForm::Item1Kana1ButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;

	AnsiString kana;
	enum KanaDisplayMode {kdmAll, kdmLine, kdmSingle} kana_mode;

	if (Item1Kana10Button->Visible)
		kana_mode = kdmAll;
	else if (Item1Kana5Button->Visible)
		kana_mode = kdmLine;
	else
		kana_mode = kdmSingle;

	if (tag != 99){
		kana = dynamic_cast<TButton *>(Sender)->Caption;
		if (kana.IsEmpty())
			return;
	}

	// �P���\���Ŗ߂�{�^���ȊO�̏ꍇ�́A����
	if (kana_mode == kdmSingle && tag != 99)
		return;

	if (tag == 99){		// �߂�{�^��
		if (kana_mode == kdmLine){
			Item1Kana1Button->Caption = "�";
			Item1Kana2Button->Caption = "�";
			Item1Kana3Button->Caption = "�";
			Item1Kana4Button->Caption = "�";
			Item1Kana5Button->Caption = "�";
			Item1Kana6Button->Caption = "�";
			Item1Kana7Button->Caption = "�";
			Item1Kana8Button->Caption = "�";
			Item1Kana9Button->Caption = "�";
			Item1Kana10Button->Caption = "�";
			Item1Kana1Button->Visible = true;
			Item1Kana2Button->Visible = true;
			Item1Kana3Button->Visible = true;
			Item1Kana4Button->Visible = true;
			Item1Kana5Button->Visible = true;
			Item1Kana6Button->Visible = true;
			Item1Kana7Button->Visible = true;
			Item1Kana8Button->Visible = true;
			Item1Kana9Button->Visible = true;
			Item1Kana10Button->Visible = true;
			Item1KanaBackButton->Visible = false;
			stateSelectItem1.SetKana(AnsiString(), AnsiString());
			stateSelectItem1.SetupButtons(0);
		}else if (kana_mode == kdmSingle){
			int line = SearchLineIndex(Item1Kana1Button->Caption);
			Item1Kana1Button->Caption = kana_table_[line][1];
			Item1Kana2Button->Caption = kana_table_[line][2];
			Item1Kana3Button->Caption = kana_table_[line][3];
			Item1Kana4Button->Caption = kana_table_[line][4];
			Item1Kana5Button->Caption = kana_table_[line][5];
			Item1Kana1Button->Visible = true;
			Item1Kana2Button->Visible = true;
			Item1Kana3Button->Visible = true;
			Item1Kana4Button->Visible = true;
			Item1Kana5Button->Visible = true;
			stateSelectItem1.SetKana(kana_table_[line][1], kana_table_[line][5]);
			stateSelectItem1.SetupButtons(0);
		}
		return;
	}

	if (kana_mode == kdmAll){
		int line = SearchLineIndex(kana);
		Item1Kana1Button->Caption = kana_table_[line][1];
		Item1Kana2Button->Caption = kana_table_[line][2];
		Item1Kana3Button->Caption = kana_table_[line][3];
		Item1Kana4Button->Caption = kana_table_[line][4];
		Item1Kana5Button->Caption = kana_table_[line][5];
		Item1Kana6Button->Caption = AnsiString();
		Item1Kana7Button->Caption = AnsiString();
		Item1Kana8Button->Caption = AnsiString();
		Item1Kana9Button->Caption = AnsiString();
		Item1Kana10Button->Caption = AnsiString();
		Item1Kana1Button->Visible = true;
		Item1Kana2Button->Visible = true;
		Item1Kana3Button->Visible = true;
		Item1Kana4Button->Visible = true;
		Item1Kana5Button->Visible = true;
		Item1Kana6Button->Visible = false;
		Item1Kana7Button->Visible = false;
		Item1Kana8Button->Visible = false;
		Item1Kana9Button->Visible = false;
		Item1Kana10Button->Visible = false;
		Item1KanaBackButton->Visible = true;
		stateSelectItem1.SetKana(kana_table_[line][1], kana_table_[line][5]);
		stateSelectItem1.SetupButtons(0);
	}else if (kana_mode == kdmLine){
		Item1Kana1Button->Caption = kana;
		Item1Kana2Button->Caption = AnsiString();
		Item1Kana3Button->Caption = AnsiString();
		Item1Kana4Button->Caption = AnsiString();
		Item1Kana5Button->Caption = AnsiString();
		Item1Kana6Button->Caption = AnsiString();
		Item1Kana7Button->Caption = AnsiString();
		Item1Kana8Button->Caption = AnsiString();
		Item1Kana9Button->Caption = AnsiString();
		Item1Kana10Button->Caption = AnsiString();
		Item1Kana1Button->Visible = true;
		Item1Kana2Button->Visible = false;
		Item1Kana3Button->Visible = false;
		Item1Kana4Button->Visible = false;
		Item1Kana5Button->Visible = false;
		Item1Kana6Button->Visible = false;
		Item1Kana7Button->Visible = false;
		Item1Kana8Button->Visible = false;
		Item1Kana9Button->Visible = false;
		Item1Kana10Button->Visible = false;
		Item1KanaBackButton->Visible = true;
		stateSelectItem1.SetKana(kana, AnsiString());
		stateSelectItem1.SetupButtons(0);
	}

}
//---------------------------------------------------------------------------
// ����2�ꗗ��X�N���[��
void __fastcall TCardIssueForm::Item2ScrollUpButtonClick(TObject *Sender)
{
	int top = stateSelectItem2.GetCurrentTop();
	top -= 3;
	top = (top < 0) ? 0 : top;
	stateSelectItem2.SetupButtons(top);
}
//---------------------------------------------------------------------------
// ����2�ꗗ���X�N���[��
void __fastcall TCardIssueForm::Item2ScrollDownButtonClick(TObject *Sender)
{
	int top = stateSelectItem2.GetCurrentTop();
	top += 3;
	stateSelectItem2.SetupButtons(top);
	if (stateSelectItem2.GetEnabledButtons() < 1)	// �\��������̂��Ȃ��ꍇ
		Item2ScrollUpButtonClick(Sender);	// ��ɃX�N���[��
}
//---------------------------------------------------------------------------
// ����2�I��
void __fastcall TCardIssueForm::Item21ButtonClick(TObject *Sender)
{
	NsRecord record;
	record["����2ID"]   = dynamic_cast<TButton *>(Sender)->Tag;
	record["����2����"] = dynamic_cast<TButton *>(Sender)->Caption;
	current_state_ = current_state_->transit(evItem2Select, &record);
}
//---------------------------------------------------------------------------
// ����2�w��Ȃ�
void __fastcall TCardIssueForm::AnonyItem2ButtonClick(TObject *Sender)
{
	NsRecord record;
	record["����2ID"]   = 0;
	record["����2����"] = "�w��Ȃ�";
	current_state_ = current_state_->transit(evItem2Select, &record);
}
//---------------------------------------------------------------------------
// ����2�J�i�{�^��
void __fastcall TCardIssueForm::Item2Kana1ButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;

	AnsiString kana;
	enum KanaDisplayMode {kdmAll, kdmLine, kdmSingle} kana_mode;

	if (Item2Kana10Button->Visible)
		kana_mode = kdmAll;
	else if (Item2Kana5Button->Visible)
		kana_mode = kdmLine;
	else
		kana_mode = kdmSingle;

	if (tag != 99){
		kana = dynamic_cast<TButton *>(Sender)->Caption;
		if (kana.IsEmpty())
			return;
	}

	// �P���\���Ŗ߂�{�^���ȊO�̏ꍇ�́A����
	if (kana_mode == kdmSingle && tag != 99)
		return;

	if (tag == 99){		// �߂�{�^��
		if (kana_mode == kdmLine){
			Item2Kana1Button->Caption = "�";
			Item2Kana2Button->Caption = "�";
			Item2Kana3Button->Caption = "�";
			Item2Kana4Button->Caption = "�";
			Item2Kana5Button->Caption = "�";
			Item2Kana6Button->Caption = "�";
			Item2Kana7Button->Caption = "�";
			Item2Kana8Button->Caption = "�";
			Item2Kana9Button->Caption = "�";
			Item2Kana10Button->Caption = "�";
			Item2Kana1Button->Visible = true;
			Item2Kana2Button->Visible = true;
			Item2Kana3Button->Visible = true;
			Item2Kana4Button->Visible = true;
			Item2Kana5Button->Visible = true;
			Item2Kana6Button->Visible = true;
			Item2Kana7Button->Visible = true;
			Item2Kana8Button->Visible = true;
			Item2Kana9Button->Visible = true;
			Item2Kana10Button->Visible = true;
			Item2KanaBackButton->Visible = false;
			stateSelectItem2.SetKana(AnsiString(), AnsiString());
			stateSelectItem2.SetupButtons(0);
		}else if (kana_mode == kdmSingle){
			int line = SearchLineIndex(Item2Kana1Button->Caption);
			Item2Kana1Button->Caption = kana_table_[line][1];
			Item2Kana2Button->Caption = kana_table_[line][2];
			Item2Kana3Button->Caption = kana_table_[line][3];
			Item2Kana4Button->Caption = kana_table_[line][4];
			Item2Kana5Button->Caption = kana_table_[line][5];
			Item2Kana1Button->Visible = true;
			Item2Kana2Button->Visible = true;
			Item2Kana3Button->Visible = true;
			Item2Kana4Button->Visible = true;
			Item2Kana5Button->Visible = true;
			stateSelectItem2.SetKana(kana_table_[line][1], kana_table_[line][5]);
			stateSelectItem2.SetupButtons(0);
		}
		return;
	}
	
	if (kana_mode == kdmAll){
		int line = SearchLineIndex(kana);
		Item2Kana1Button->Caption = kana_table_[line][1];
		Item2Kana2Button->Caption = kana_table_[line][2];
		Item2Kana3Button->Caption = kana_table_[line][3];
		Item2Kana4Button->Caption = kana_table_[line][4];
		Item2Kana5Button->Caption = kana_table_[line][5];
		Item2Kana6Button->Caption = AnsiString();
		Item2Kana7Button->Caption = AnsiString();
		Item2Kana8Button->Caption = AnsiString();
		Item2Kana9Button->Caption = AnsiString();
		Item2Kana10Button->Caption = AnsiString();
		Item2Kana1Button->Visible = true;
		Item2Kana2Button->Visible = true;
		Item2Kana3Button->Visible = true;
		Item2Kana4Button->Visible = true;
		Item2Kana5Button->Visible = true;
		Item2Kana6Button->Visible = false;
		Item2Kana7Button->Visible = false;
		Item2Kana8Button->Visible = false;
		Item2Kana9Button->Visible = false;
		Item2Kana10Button->Visible = false;
		Item2KanaBackButton->Visible = true;
		stateSelectItem2.SetKana(kana_table_[line][1], kana_table_[line][5]);
		stateSelectItem2.SetupButtons(0);
	}else if (kana_mode == kdmLine){
		Item2Kana1Button->Caption = kana;
		Item2Kana2Button->Caption = AnsiString();
		Item2Kana3Button->Caption = AnsiString();
		Item2Kana4Button->Caption = AnsiString();
		Item2Kana5Button->Caption = AnsiString();
		Item2Kana6Button->Caption = AnsiString();
		Item2Kana7Button->Caption = AnsiString();
		Item2Kana8Button->Caption = AnsiString();
		Item2Kana9Button->Caption = AnsiString();
		Item2Kana10Button->Caption = AnsiString();
		Item2Kana1Button->Visible = true;
		Item2Kana2Button->Visible = false;
		Item2Kana3Button->Visible = false;
		Item2Kana4Button->Visible = false;
		Item2Kana5Button->Visible = false;
		Item2Kana6Button->Visible = false;
		Item2Kana7Button->Visible = false;
		Item2Kana8Button->Visible = false;
		Item2Kana9Button->Visible = false;
		Item2Kana10Button->Visible = false;
		Item2KanaBackButton->Visible = true;
		stateSelectItem2.SetKana(kana, AnsiString());
		stateSelectItem2.SetupButtons(0);
	}
}
//---------------------------------------------------------------------------
// �Ԕԓ��͗p�e���L�[
void __fastcall TCardIssueForm::Input7ButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;
	if (tag == 10){
		// ����
		if (!CarNoInputEdit->Text.IsEmpty()){
			AnsiString buff = CarNoInputEdit->Text;
			buff.Delete(CarNoInputEdit->Text.Length(), 1);
			CarNoInputEdit->Text = buff;
		}
	}else if (tag == 11){
		CarNoInputEdit->Text = AnsiString();
	}else{
		if (CarNoInputEdit->Text.Length() != 6){
			AnsiString buff = CarNoInputEdit->Text;
			buff += IntToStr(tag);
			CarNoInputEdit->Text = buff;
		}
	}
}
//---------------------------------------------------------------------------
// �Ԕ�OnChange
void __fastcall TCardIssueForm::CarNoInputEditChange(TObject *Sender)
{
    Q_Syaryo->Close();
    
    int car_no = CarNoInputEdit->Text.ToIntDef(0);
    if (car_no < 1){
        CarNoSelectButton->Enabled = false;
        CarNoAddButton->Enabled    = false;
    }else{
        Q_Syaryo->SQL->Text = " SELECT * FROM M_�ԗ�"
                              " WHERE �Ԕ� = " + IntToStr(car_no) +
                              "   AND �g�p�敪 = 1"
                              " ORDER BY �X�V���� DESC";
        Q_Syaryo->Open();

        if (Q_Syaryo->Eof && Q_Syaryo->Bof){
            CarNoSelectButton->Enabled = false;
        }else{
            CarNoSelectButton->Enabled = true;
        }
        CarNoAddButton->Enabled = true;
    }
}
//---------------------------------------------------------------------------
// �ԗ��I��
void __fastcall TCardIssueForm::CarNoSelectButtonClick(TObject *Sender)
{
	int car_no = CarNoInputEdit->Text.ToIntDef(0);
    int car_id = Q_Syaryo->FieldByName("�ԗ�ID")->AsInteger;
	if (car_no < 1 || car_id < 1){
		return;
	}
	NsRecord record;
    record["�ԗ�ID"]   = car_id;
	record["�Ԕ�"]     = car_no;
    record["�ԗ��ǉ�"] = false;
	current_state_     = current_state_->transit(evCarNoInput, &record);
}
//---------------------------------------------------------------------------
// �V�K�ԗ��ǉ�
void __fastcall TCardIssueForm::CarNoAddButtonClick(TObject *Sender)
{
	int car_no = CarNoInputEdit->Text.ToIntDef(0);
	NsRecord record;
    record["�ԗ�ID"]   = 0;
	record["�Ԕ�"]     = car_no;
    record["�ԗ��ǉ�"] = true;
	current_state_     = current_state_->transit(evCarNoInput, &record);
}
//---------------------------------------------------------------------------
// �ԔԎw��Ȃ�
void __fastcall TCardIssueForm::AnonyCarNoButtonClick(TObject *Sender)
{
	NsRecord record;
    record["�ԗ�ID"]   = 0;
	record["�Ԕ�"]     = 0;
    record["�ԗ��ǉ�"] = true;
	current_state_     = current_state_->transit(evCarNoInput, &record);
}
//---------------------------------------------------------------------------
void __fastcall TCardIssueForm::ActivateTimerTimer(TObject *Sender)
{
	ActivateTimer->Enabled = false;
	SetForegroundWindow(Handle);
}
//---------------------------------------------------------------------------


