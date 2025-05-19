//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CardReviewFrm.h"
#include "DMFrm.h"
#include <IniFiles.hpp>
#include <memory>
#include "nsoftfunc.h"
#include "n24TP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCardReviewForm *CardReviewForm;
//---------------------------------------------------------------------------
__fastcall TCardReviewForm::TCardReviewForm(TComponent* Owner)
	: TForm(Owner), rfid_thread_(0)
{
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::FormShow(TObject *Sender)
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
        TokuPanel->Visible       = false;
	}
	if (!ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
        HinPanel->Visible        = false;
	}
	if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
        Item1Panel->Visible      = false;
	}
	if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
        Item2Panel->Visible      = false;
	}

    int port = ToInt(DM->INI["RFID::DeskCommPort"]);

	ClearForm();

    /////////////////////////////////////////
    // �X�}�[�g�J�[�h������
    int reader_index = ToInt(DM->INI["SmartCard::ReaderIndex"]);

    if (!DM->cardService.CheckService()){
        Application->MessageBox("SmartCard�T�[�r�X���N�����Ă��܂���", Caption.c_str(), MB_OK | MB_ICONSTOP);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }

    DWORD dw_err;
    AnsiString err_text;
    SmartCardService::Readers readers;

    if (!DM->cardService.Establish()){
        DM->cardService.GetLastError(dw_err, err_text);
		Application->MessageBox(AnsiString("SmartCard �Ƃ̒ʐM�m���Ɏ��s���܂��� - " + err_text).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
    }

    if (!DM->cardService.EnumReaders(readers)){
		DM->cardService.GetLastError(dw_err, err_text);
		Application->MessageBox(AnsiString("SmartCard ���[�_���擾�ł��܂��� - " + err_text).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;

    }

	if (readers.empty()){
		Application->MessageBox("SmartCard ���[�_�����݂��܂���", Caption.c_str(), MB_OK | MB_ICONSTOP);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

    if (int(readers.empty()) >= reader_index + 1)
        DM->cardService.SetReader(readers[reader_index]);
    else
        DM->cardService.SetReader(readers[0]);
}

//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
//
}
//---------------------------------------------------------------------------
/**
 * Implementation of Private Method
 */
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::ClearForm()
{
	StatusMemo->Lines->Clear();
	StatusLabel->Caption     = AnsiString();
    CarNoPanel->Caption      = AnsiString();
    TokuPanel->Caption       = AnsiString();
    HinPanel->Caption        = AnsiString();
    Item1Panel->Caption      = AnsiString();
    Item2Panel->Caption      = AnsiString();
	TareWeightLabel->Caption = AnsiString();
	GrossLimitLabel->Caption = AnsiString();
	NetLimitLabel->Caption   = AnsiString();
	UseDateLabel->Caption    = AnsiString();
}
//---------------------------------------------------------------------------
/**
 * Implementation of Message Handler
 */
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
	// Application->MessageBox("RFID���j�b�g�Ƃ̒ʐM���ł��܂���", Caption.c_str(),
	//		MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	StatusLabel->Caption = status;
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;

	ClearForm();

	if (!is_valid){
		// �����ȃJ�[�h
		StatusMemo->Lines->Append("�J�[�h�`���������ł��B");
		StatusMemo->Lines->Append("���̃J�[�h�́A���V�X�e���ł͎g�p�ł��܂���B");
		StatusMemo->Lines->Append(reinterpret_cast<LPCSTR>(message.LParam));
		return;
	}

	// �L���ȃJ�[�h
	int card_no = message.LParam;

	if (card_no == N24TP::ADMIN_CARD_NO){
		StatusMemo->Lines->Append("N-24TP�p�Ǘ��J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}
	if (card_no == N24TP::SET_ZERO_CARD_NO){
		StatusMemo->Lines->Append("N-24TP�p�d�ʃ[���ݒ�J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}
	if (card_no == N24TP::CLR_ZERO_CARD_NO){
		StatusMemo->Lines->Append("N-24TP�p�d�ʃ[������J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�ԗ� WHERE �J�[�h�ԍ� = " + IntToStr(card_no) + " AND �g�p�敪 = 1";
	if (!DM->DBI.GetRecordSet(sql, set)){
		StatusMemo->Lines->Append("�J�[�h��񂪖����ł��B");
		StatusMemo->Lines->Append("���s���̏�񂪑��݂��܂���B");
		StatusMemo->Lines->Append("���̃J�[�h�́A���V�X�e���ł͎g�p�ł��܂���B");
		return;
	}

    CarNoPanel->Caption = ToInt(SET_TOP(set)["�Ԕ�"]) < 1    ? AnsiString(" �w��Ȃ�")
                                                             : AnsiString(" ") + ToString(SET_TOP(set)["�Ԕ�"]) + " " + ToString(SET_TOP(set)["�ԗ�����"]);
    TokuPanel->Caption  = SET_TOP(set)["���Ӑ旪��"].IsNull() ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["���Ӑ旪��"]);
    HinPanel->Caption   = SET_TOP(set)["�i�ڗ���"].IsNull()   ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["�i�ڗ���"]);
    Item1Panel->Caption = SET_TOP(set)["����1����"].IsNull()  ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["����1����"]);
    Item2Panel->Caption = SET_TOP(set)["����2����"].IsNull()  ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["����2����"]);

	TareWeightLabel->Caption = ToInt(SET_TOP(set)["��ԏd��"])   ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["��ԏd��"]))
																 : AnsiString();
	GrossLimitLabel->Caption = ToInt(SET_TOP(set)["�ԗ����d��"]) ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["�ԗ����d��"]))
																 : AnsiString();
	NetLimitLabel->Caption   = ToInt(SET_TOP(set)["�ő�ύڗ�"]) ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["�ő�ύڗ�"]))
																 : AnsiString();

    sql = "SELECT TOP 1 �v�ʓ� FROM D_�v�� WHERE �ԗ�ID = " + ToString(SET_TOP(set)["�ԗ�ID"]) + " ORDER BY �v�ʓ� DESC";
    if (DM->DBI.GetRecordSet(sql, set)){
        try{
    		UseDateLabel->Caption   = IntToDate(ToInt(SET_TOP(set)["�v�ʓ�"])).FormatString("yyyy/mm/dd");
        }catch(...){}
    }
}
//---------------------------------------------------------------------------
/**
 * Implementation of Control Event
 */
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::ActivateTimerTimer(TObject *Sender)
{
	ActivateTimer->Enabled = false;
	SetForegroundWindow(Handle);

    DWORD dw_err;
    AnsiString err_text;
    DWORD dw_event;

    if (!DM->cardService.GetStatusChange(dw_event)){
        DM->cardService.GetLastError(dw_err, err_text);
        return;
    }

    if (dw_event & SCARD_STATE_EMPTY){
        ClearForm();
    } else if (dw_event & SCARD_STATE_PRESENT){
        ClearForm();
        OnCardPresent();
    }

    ActivateTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TCardReviewForm::OnCardPresent()
{
    DWORD dw_err;
    AnsiString err_text;
    if (!DM->cardService.ConnectCard(&DM->card_)){
        DM->cardService.GetLastError(dw_err, err_text);
        StatusMemo->Lines->Append("�G���[: " + err_text);
        return;
    }

    BYTE sw1, sw2;
    BYTE key[6];

    ZeroMemory(key, sizeof(key));
    HexStringToBytes(DM->CardKey.c_str(), key);

    CardImage image;
    try {
        ReadImageFromSmartCard_ultra(&DM->card_, &image);

    }catch(Exception& e){
        StatusMemo->Lines->Append(e.Message);
        return;
    }

    DM->card_.Disconnect();

/*
    ///////////////////////////////////////////////////
    // Mifare UltraLight�̓J�[�h�F�ؕs��

    if (!image.card_key_valid){
        StatusLabel->Caption = "���̃J�[�h�͎g�p�ł��܂���";
        StatusMemo->Lines->Append("���V�X�e���O�̃J�[�h�ł�");
        return;
    }

    if (!image.system_key_valid){
        StatusLabel->Caption = "���̃J�[�h�͎g�p�ł��܂���";
        StatusMemo->Lines->Append("�ʃV�X�e���̃J�[�h�ł�");
        return;
    }
*/

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM V_�ԗ� where �J�[�h�ԍ� = " + IntToStr(image.card_id) + " AND �g�p�敪 = 1";

    if (!DM->DBI.GetRecordSet(sql, set)){
        StatusMemo->Lines->Append("�J�[�h��񂪖����ł�");
        StatusMemo->Lines->Append("���s���̏�񂪑��݂��܂���");
        StatusMemo->Lines->Append("���̃J�[�h�́A���V�X�e���ł͎g�p�ł��܂���");
        return;
    }

    CarNoPanel->Caption = ToInt(SET_TOP(set)["�Ԕ�"]) < 1    ? AnsiString(" �w��Ȃ�")
                                                             : AnsiString(" ") + ToString(SET_TOP(set)["�Ԕ�"]) + " " + ToString(SET_TOP(set)["�ԗ�����"]);

    TokuPanel->Caption  = SET_TOP(set)["���Ӑ旪��"].IsNull() ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["���Ӑ旪��"]);
    HinPanel->Caption   = SET_TOP(set)["�i�ڗ���"].IsNull()   ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["�i�ڗ���"]);
    Item1Panel->Caption = SET_TOP(set)["����1����"].IsNull()  ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["����1����"]);
    Item2Panel->Caption = SET_TOP(set)["����2����"].IsNull()  ? AnsiString(" �w��Ȃ�")
                                                              : AnsiString(" ") + ToString(SET_TOP(set)["����2����"]);

	TareWeightLabel->Caption = ToInt(SET_TOP(set)["��ԏd��"])   ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["��ԏd��"]))
																 : AnsiString();
	GrossLimitLabel->Caption = ToInt(SET_TOP(set)["�ԗ����d��"]) ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["�ԗ����d��"]))
																 : AnsiString();
	NetLimitLabel->Caption   = ToInt(SET_TOP(set)["�ő�ύڗ�"]) ? FormatFloat("###,##0' kg'", ToInt(SET_TOP(set)["�ő�ύڗ�"]))
																 : AnsiString();

    sql = "SELECT TOP 1 �v�ʓ� FROM D_�v�� WHERE �ԗ�ID = " + ToString(SET_TOP(set)["�ԗ�ID"]) + " ORDER BY �v�ʓ� DESC";
    if (DM->DBI.GetRecordSet(sql, set)){
        try{
    		UseDateLabel->Caption   = IntToDate(ToInt(SET_TOP(set)["�v�ʓ�"])).FormatString("yyyy/mm/dd");
        }catch(...){}
    }

}
//---------------------------------------------------------------------------

