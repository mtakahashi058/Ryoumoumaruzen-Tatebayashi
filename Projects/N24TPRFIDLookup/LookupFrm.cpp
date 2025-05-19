//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "n24tp.h"
#include "LookupFrm.h"
#include "DMFrm.h"
#include <IniFiles.hpp>
#include <memory>
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLookupForm *LookupForm;
//---------------------------------------------------------------------------
__fastcall TLookupForm::TLookupForm(TComponent* Owner)
	: TForm(Owner), rfid_thread_(0)
{
}
//---------------------------------------------------------------------------
/**
 * Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TLookupForm::FormShow(TObject *Sender)
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

	TokuTitlePanel->Caption  = "  " + ToString(DM->CFG["���Ӑ�}�X�^����"]);
	MeigTitlePanel->Caption  = "  " + ToString(DM->CFG["�i�ڃ}�X�^����"]);
	Item1TitlePanel->Caption = "  " + ToString(DM->CFG["����1�}�X�^����"]);
	Item2TitlePanel->Caption = "  " + ToString(DM->CFG["����2�}�X�^����"]);

    if (!ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
		TokuTitlePanel->Visible = false;
		TokuPanel->Visible = false;
    }
    if (!ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
		MeigTitlePanel->Visible = false;
		MeigPanel->Visible = false;
    }
    if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
		Item1TitlePanel->Visible = false;
		Item1Panel->Visible = false;
    }
    if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
		Item2TitlePanel->Visible = false;
		Item2Panel->Visible = false;
    }

    int port = ini->ReadInteger("RFID", "CommPort", 1);

	ClearForm();

	// RFID�X���b�h�̊J�n
	rfid_thread_ = new THF04Thread(false, Handle, port);
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (rfid_thread_){
		rfid_thread_->Terminate();
		rfid_thread_->WaitFor();
		delete rfid_thread_;
	}
}
//---------------------------------------------------------------------------
/**
 * Implementation of Private Method
 */
//---------------------------------------------------------------------------
void __fastcall TLookupForm::ClearForm()
{
	StatusMemo->Lines->Clear();
	StatusLabel->Caption     = AnsiString();
    TokuPanel->Caption       = AnsiString();
    MeigPanel->Caption       = AnsiString();
	Item1Panel->Caption      = AnsiString();
	Item2Panel->Caption      = AnsiString();
	CarNoPanel->Caption      = AnsiString();
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
void __fastcall TLookupForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
	// Application->MessageBox("RFID���j�b�g�Ƃ̒ʐM���ł��܂���", Caption.c_str(),
	//		MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::OnRFIDStatus(TMessage& message)
{
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

	StatusLabel->Caption = status;
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::OnRFIDCard(TMessage& message)
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
		StatusMemo->Lines->Append("�Ǘ��J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}
	if (card_no == N24TP::SET_ZERO_CARD_NO){
		StatusMemo->Lines->Append("�d�ʃ[���ݒ�J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}
	if (card_no == N24TP::CLR_ZERO_CARD_NO){
		StatusMemo->Lines->Append("�d�ʃ[������J�[�h�ł��B");
		StatusMemo->Lines->Append(" ");
		StatusMemo->Lines->Append("���̃J�[�h�͎g�p�\�ł��B");
		return;
	}

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�ԗ� WHERE �J�[�h�ԍ� = " + IntToStr(card_no);
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
    MeigPanel->Caption  = SET_TOP(set)["�i�ڗ���"].IsNull()   ? AnsiString(" �w��Ȃ�")
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
void __fastcall TLookupForm::CloseButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TLookupForm::ActivateTimerTimer(TObject *Sender)
{
	ActivateTimer->Enabled = false;
	SetForegroundWindow(Handle);
}
//---------------------------------------------------------------------------

