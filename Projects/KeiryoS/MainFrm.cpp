//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DataListFrm.h"
#include "MainFrm.h"
#include <mmsystem.h>
#include "LaserSlipPrintFrm.h"
#include "DotSlipPrintFrm.h"
#include "ManualDotSlipFrm.h"
#include "TrailerWeightFrm.h"
#include "ShabanSanshoFrm.h"
#include "nsoftfunc.h"
#include "QRChitFrm.h"
#include "BitField.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner),
        keiryo_id_(0), id_total_(0),
		cur_weight1_(0), old_weight1_(0), bdn_weight1_(0),
		cur_weight2_(0), old_weight2_(0), bdn_weight2_(0),
        rfid_thread_(0), last_card_no_(0)
{
    Application->OnMessage = MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	TDBGrid *Grid = 0;
	int gyo = 3;

	switch (Msg.message){
	case WM_MOUSEWHEEL:
		if (Msg.hwnd == DataListForm->DBGrid->Handle)
			Grid = DataListForm->DBGrid;
		if (Msg.hwnd == SearchForm->DBGrid->Handle)
			Grid = SearchForm->DBGrid;
		if (Msg.hwnd == ShabanSanshoForm->DBGrid->Handle)
			Grid = ShabanSanshoForm->DBGrid;

		if (!Grid)
			return;

		Grid->SetFocus();

		for (int i = 0; i < gyo; i++){
			if((short)HIWORD(Msg.wParam) > 0){
				Grid->DataSource->DataSet->Prior();
			}else{
				Grid->DataSource->DataSet->Next();
			}
		}
		Handled = true;
        break;
    }
}
//---------------------------------------------------------------------------
// MainForm->OnShow
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�

	if (!DM->Init())
		Close();

	ApplyConfig();

	///////////////////////////////////////////////
	// RFID
    if (ToInt(DM->CFG["���RFID�v��"])){
		int rfid_port = ToInt(DM->INI[L"RFID::DeskCommPort"]);
		rfid_thread_  = new THF04Thread(true, Handle, rfid_port);
		rfid_thread_->FreeOnTerminate = false;
		rfid_thread_->Resume();
    }

	weighing_border_ = ToInt(DM->INI["Weighing::SoundBorder"]);

	// ���ʁ��ڗ�
	DM->hyoryo_ = ToCurrency(DM->CFG["����"]);
	DM->meryo_  = ToCurrency(DM->CFG["�ڗ�"]);

	// �ؗ��e�[�u���I�[�v��
	try{
		Q_Tairyu->Open();
	}catch (Exception& e){
		Application->MessageBox(("�ؗ��ꗗ�f�[�^�̓ǂݍ��݂Ɏ��s���܂���\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

	///////////////////////////////////////////////
	// �d�ʎ�M
    if (ToInt(DM->INI["Weighing::WIUse1"])){
    	try{
	    	// [INI] Weighing::WIPort
		    ClientSocket1->Port = ToInt(DM->INI["Weighing::WIPort1"]);
    		// [INI] Weighing::WIServer
	    	ClientSocket1->Host = ToString(DM->INI["Weighing::WIServer1"]);

    		if (ClientSocket1->Active)
	    		ClientSocket1->Close();
		    ClientSocket1->Open();
    	}catch(Exception& e){
	    	AnsiString msg = "WI1 TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
		    Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
    	}
    	SocketReopenTimer1->Enabled = true;

        ScaleNameLabel1->Caption = ToString(DM->INI["Weighing::WIName11"]);
        ScaleNameLabel2->Caption = ToString(DM->INI["Weighing::WIName12"]);
        ScaleNameLabel3->Caption = ToString(DM->INI["Weighing::WIName13"]);
    }

    if (ToInt(DM->INI["Weighing::WIUse2"])){
        //WeightNamePanel2->Caption = ToString(DM->INI["Weighing::WIName2"]);
    	try{
	    	// [INI] Weighing::WIPort
		    ClientSocket2->Port = ToInt(DM->INI["Weighing::WIPort2"]);
    		// [INI] Weighing::WIServer
	    	ClientSocket2->Host = ToString(DM->INI["Weighing::WIServer2"]);

    		if (ClientSocket2->Active)
	    		ClientSocket2->Close();
		    ClientSocket2->Open();
    	}catch(Exception& e){
	    	AnsiString msg = "WI2 TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
		    Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
    	}
    	SocketReopenTimer2->Enabled = true;

        ScaleNameLabel4->Caption = ToString(DM->INI["Weighing::WIName21"]);
        ScaleNameLabel5->Caption = ToString(DM->INI["Weighing::WIName22"]);
        ScaleNameLabel6->Caption = ToString(DM->INI["Weighing::WIName23"]);
    }

    ///////////////////////////////////////////////
	// NP3411

    if (ToInt(DM->CFG["�`�[���s�v�����^"]) == 5) {
	    int port = ToInt(DM->INI["OuterPrinter::Port"]);
        cfginfo_.customer = DM->TrimSpace(ToString(DM->CFG["���Ӑ�}�X�^����"]));
        cfginfo_.items    = DM->TrimSpace(ToString(DM->CFG["�i�ڃ}�X�^����"]));
        cfginfo_.item1    = DM->TrimSpace(ToString(DM->CFG["����1�}�X�^����"]));
        cfginfo_.item2    = DM->TrimSpace(ToString(DM->CFG["����2�}�X�^����"]));
        cfginfo_.use_toku  = ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"]);
        cfginfo_.use_items = ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"]);
        cfginfo_.use_item1 = ToBit(DM->CFG["����1�}�X�^�g�p�敪"]);
        cfginfo_.use_item2 = ToBit(DM->CFG["����2�}�X�^�g�p�敪"]);
	    if (port){
		    printer_thread_ = new TNP3411Thread(false, port, ToString(DM->INI["OuterPrinter::Def"]), Handle, cfginfo_, ToInt(DM->INI["OuterPrinter::PrintCopy"]));
	    }else{
		    Application->MessageBox("�O���v�����^�Ƃ̒ʐM�͒�~���Ă��܂�", "�d�ʕ\����", MB_OK | MB_ICONWARNING);
	    }
    }

	Resize();

	TairyuTimer->Enabled = true;

	for (int i = 0; i < StatusBar->Panels->Count; i++)
		StatusBar->Panels->Items[i]->Text = AnsiString();

	if (ToString(DM->INI["Form::Maximized"]).ToIntDef(0) == 1)
		MainForm->WindowState = wsMaximized;

	Action1->Execute();
}
//---------------------------------------------------------------------------
// �ݒ���e���t�H�[���ɓK�p��
void __fastcall TMainForm::ApplyConfig()
{
	// DM->CFG.Debug();

	// [CFG]

	// MainForm
	TokuButton->Caption      = ToString(DM->CFG["���Ӑ�}�X�^����"]);
	Komoku1Button->Caption   = ToString(DM->CFG["����1�}�X�^����"]);
	Komoku2Button->Caption   = ToString(DM->CFG["����2�}�X�^����"]);
	HinButton->Caption       = ToString(DM->CFG["�i�ڃ}�X�^����"]);
	ChoseiButton->Caption    = ToString(DM->CFG["��������"]);
	JuryobikiButton->Caption = ToString(DM->CFG["�d�ʈ�������"]);

	DM->kname_toku_		= AnsiReplaceStr(AnsiReplaceStr(TokuButton->Caption,	"�@", ""), " ", "");
	DM->kname_hin_		= AnsiReplaceStr(AnsiReplaceStr(HinButton->Caption,		"�@", ""), " ", "");
	DM->kname_komoku1_	= AnsiReplaceStr(AnsiReplaceStr(Komoku1Button->Caption, "�@", ""), " ", "");
	DM->kname_komoku2_	= AnsiReplaceStr(AnsiReplaceStr(Komoku2Button->Caption, "�@", ""), " ", "");

	TairyuTokuisakiLabel->Caption = DM->kname_toku_;

	if (!ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
		TokuPanel->Visible            = false;

		TairyuTokuisakiLabel->Visible = false;
		TairyuTokuisakiText->Visible  = false;
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
		TrailerWeightForm->FirstWEdit->ReadOnly  = true;
		TrailerWeightForm->SecondWEdit->ReadOnly = true;
	}
	if (!ToBit(DM->CFG["�g���[���Ή�"])){
		TrailerWeight1Button->Visible = false;
		TrailerWeight2Button->Visible = false;
	}


	int default_index = 0;
	int place_code    = ToInt(DM->INI["Place::Code"]);
	PlaceCombo->Items->Clear();
	for (unsigned int i = 0; i < DM->PlaceSet.size(); i++){
		PlaceCombo->Items->Append(ToString(DM->PlaceSet[i]["���_����"]));
		if (ToInt(DM->PlaceSet[i]["���_�R�[�h"]) == place_code)
			default_index = i;
	}
	PlaceCombo->ItemIndex = default_index;

	AutoPrintCheck->Checked  = ToBit(DM->CFG["�`�[���s�����敪"]);
	DataDeleteCheck->Visible = ToBit(DM->CFG["��`�[���s�@�\"]);
	HideTimeCheck->Checked   = !(ToBit(DM->CFG["���Ԉ󎚏����敪"]));
	HideTimeCheck->Visible   = ToBit(DM->CFG["���ԋ󔒈󎚋@�\"]);

	int wild_code;

	wild_code = ToInt(DM->CFG["���Ӑ揔���R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_���Ӑ�", "���Ӑ�R�[�h", wild_code)){
		Application->MessageBox("���Ӑ揔���R�[�h�����Ӑ�}�X�^�ɓo�^����Ă��܂���B�v�ʑO�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["�i�ڔ��������R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_�i��", "�i�ڃR�[�h", wild_code)){
		Application->MessageBox("�i�ڔ��������R�[�h���i�ڃ}�X�^�ɓo�^����Ă��܂���B�v�ʑO�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["�i�ڔ��o�����R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_�i��", "�i�ڃR�[�h", wild_code)){
		Application->MessageBox("�i�ڔ��o�����R�[�h���i�ڃ}�X�^�ɓo�^����Ă��܂���B�v�ʑO�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["����1�����R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_����1", "����1�R�[�h", wild_code)){
		Application->MessageBox("����1�����R�[�h������1�}�X�^�ɓo�^����Ă��܂���B�v�ʑO�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["����2�����R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_����2", "����2�R�[�h", wild_code)){
		Application->MessageBox("����2�����R�[�h������2�}�X�^�ɓo�^����Ă��܂���B�v�ʑO�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

	// �q���g
	TokuCodeEdit->Hint    = DM->kname_toku_    + "�R�[�h����͂��Ă��������B(" + DM->kname_toku_    + "�{�^�� or [F4]���}�X�^�Q��)";
	HinCodeEdit->Hint     = DM->kname_hin_     + "�R�[�h����͂��Ă��������B(" + DM->kname_hin_     + "�{�^�� or [F4]���}�X�^�Q��)";
	Komoku1CodeEdit->Hint = DM->kname_komoku1_ + "�R�[�h����͂��Ă��������B(" + DM->kname_komoku1_ + "�{�^�� or [F4]���}�X�^�Q��)";
	Komoku2CodeEdit->Hint = DM->kname_komoku2_ + "�R�[�h����͂��Ă��������B(" + DM->kname_komoku2_ + "�{�^�� or [F4]���}�X�^�Q��)";
}
//---------------------------------------------------------------------------
// MainForm->OnClose
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (rfid_thread_){
    	rfid_thread_->Terminate();
        rfid_thread_->WaitFor();
        delete rfid_thread_;
    }

	try{
		if (MainForm->WindowState == wsMaximized)
			DM->INI.SaveSingle("Form", "Maximized", 1);
		else
			DM->INI.SaveSingle("Form", "Maximized", 0);
	}catch (...){}
}
//---------------------------------------------------------------------------
// �\�P�b�g�̐ؒf���Ď�
void __fastcall TMainForm::SocketReopenTimer1Timer(TObject *Sender)
{
    if (ClientSocket1->Active)
        return;

    try{
        ClientSocket1->Socket->Close();

        // [INI] Weighing::WIPort
        ClientSocket1->Port = ToInt(DM->INI["Weighing::WIPort"]);
        // [INI] Weighing::WIServer
        ClientSocket1->Host = ToString(DM->INI["Weighing::WIServer"]);

        ClientSocket1->Open();
    }catch(Exception& e){
        //AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
        //Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
        ;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SocketReopenTimer2Timer(TObject *Sender)
{
	if (ClientSocket2->Active)
		return;

	try{
        ClientSocket2->Socket->Close();

		// [INI] Weighing::WIPort
		ClientSocket2->Port = ToInt(DM->INI["Weighing::WIPort2"]);
		// [INI] Weighing::WIServer
        ClientSocket2->Host = ToString(DM->INI["Weighing::WIServer2"]);

        ClientSocket2->Open();
    }catch(Exception& e){
        //AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
        //Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
        ;
    }
}
//---------------------------------------------------------------------------
// ��Form �p�d�ʒ񋟃��\�b�h
Currency __fastcall TMainForm::GetWeight()
{
/*
    if (cur_weight1_ > 0 && cur_weight2_ == 0)
        return cur_weight1_;
    else if (cur_weight1_ == 0 && cur_weight2_ > 0)
        return cur_weight2_;
    else if (FWBasePanel->Color == TColor(0x008AF8FD))
        return cur_weight1_;
    else if (SWBasePanel->Color == TColor(0x008AF8FD))
        return cur_weight2_;
    else
        return 0;
*/
    bdn_weight1_ = cur_weight1_;
    bdn_weight2_ = cur_weight2_;

    return cur_weight1_ + cur_weight2_;
}
//---------------------------------------------------------------------------
// ���_�R���{�{�b�N�X���� ID ���擾
int __fastcall TMainForm::GetPlaceID()
{
    return ToInt(DM->PlaceSet[PlaceCombo->ItemIndex]["���_ID"]);
}
//---------------------------------------------------------------------------
// �t�H�[�����N���A
void __fastcall TMainForm::ClearForm()
{
    keiryo_id_ = 0;
    keiryo_set_.clear();

    toku_id_      = 0;
    toku_rec_.clear();

    new_car_      = false;
    car_id_       = 0;
    keiryo_count_ = 0;
    gross_limit_  = 0;
    net_limit_    = 0;

    TDateTime now(Now());
    
    KeiryoDatePicker->Date    = Date();
    KeiryoNoEdit->Text        = AnsiString();
    ShabanEdit->Text          = AnsiString();
    ShabanEdit->OnChange(NULL);
    TokuCodeEdit->Text        = AnsiString();
	TokuNameEdit->Text        = AnsiString();
	Komoku1CodeEdit->Text     = AnsiString();
	Komoku1NameEdit->Text     = AnsiString();
	Komoku2CodeEdit->Text     = AnsiString();
	Komoku2NameEdit->Text     = AnsiString();
	HinCodeEdit->Text         = AnsiString();
	HinNameEdit->Text         = AnsiString();
	HannyuCombo->ItemIndex    = -1;
	FirstWEdit->Text          = AnsiString();
	FirstDatePicker->Date     = now;
	FirstTimePicker->Time     = now;
	FirstDatePicker->Checked  = false;
	FirstTimePicker->Enabled  = false;
	FirstDatePicker->Format   = "''";
	FirstTimePicker->Format   = "''";
    BreakdownWLabel1->Caption = AnsiString();
    BreakdownWLabel2->Caption = AnsiString();
	SecondWEdit->Text         = AnsiString();
	SecondDatePicker->Date    = now;
	SecondTimePicker->Time    = now;
	SecondDatePicker->Checked = false;
	SecondTimePicker->Enabled = false;
	SecondDatePicker->Format  = "''";
	SecondTimePicker->Format  = "''";
    BreakdownWLabel3->Caption = AnsiString();
    BreakdownWLabel4->Caption = AnsiString();
	ChoseirituEdit->Text      = AnsiString();
	ChoseiEdit->Text          = AnsiString();
	JuryobikiEdit->Text       = AnsiString();
	ShomiEdit->Text           = AnsiString();
	PureNetLabel->Caption     = AnsiString();
	SuryoEdit->Text           = AnsiString();
	TaniCodeEdit->Text        = AnsiString();
	TaniLabel->Caption        = "______";
	TankaEdit->Text           = AnsiString();
	TankaEdit->Color          = TColor(0x00BEF4F5);
	KingakuEdit->Text         = AnsiString();
	ShohizeiEdit->Text        = AnsiString();
	BikoEdit->Text            = AnsiString();
	DefTankaLabel->Caption    = AnsiString();

	// �����N���A
	SetRireki(0);
}
//---------------------------------------------------------------------------
// �v��ID ���烌�R�[�h����ǂݍ���
bool __fastcall TMainForm::LoadFromID(int id)
{
	AnsiString sql;
	sql = " SELECT * FROM V_�v��"
		  " WHERE"
		  "     �v��ID = " + IntToStr(id) +
		  " AND"
		  "     �����敪 <> 9";                 // �_���폜�͑ΏۊO

	if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
		return false;

	KeiryoDatePicker->Date       = IntToDate(ToInt(SET_TOP(keiryo_set_)["�v�ʓ�"]));
	PlaceCombo->ItemIndex        = DM->FindPlaceIndexByID(ToInt(SET_TOP(keiryo_set_)["���_ID"]));
	KeiryoNoEdit->Text           = ToInt(SET_TOP(keiryo_set_)["�`�[No"]);

	car_id_                      = ToInt(SET_TOP(keiryo_set_)["�ԗ�ID"]);
	ShabanEdit->Text             = ToInt(SET_TOP(keiryo_set_)["�Ԕ�"]);
	SharyoNameEdit->Text         = ToString(SET_TOP(keiryo_set_)["�ԗ�����"]);

	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["���Ӑ�R�[�h"]));
	TokuNameEdit->Text           = ToString(SET_TOP(keiryo_set_)["���Ӑ於��"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����1�R�[�h"]));
	Komoku1NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["����1����"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����2�R�[�h"]));
	Komoku2NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["����2����"]);
	HinCodeEdit->Text            = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["�i�ڃR�[�h"]));
	HinNameEdit->Text            = ToString(SET_TOP(keiryo_set_)["�i�ږ���"]);
	HannyuCombo->ItemIndex       = ToInt(SET_TOP(keiryo_set_)["�����o�敪"]) - 1;

	Currency w1                  = ToCurrency(SET_TOP(keiryo_set_)["1��ڏd��"]);
	Currency w2                  = ToCurrency(SET_TOP(keiryo_set_)["2��ڏd��"]);

	TDateTime date;

	FirstWEdit->Text             = ZeroSuppress(w1);
	if (!SET_TOP(keiryo_set_)["�v�ʓ���1"].IsNull()){
		date = TDateTime(SET_TOP(keiryo_set_)["�v�ʓ���1"]);
		FirstDatePicker->Format    = "";
		FirstTimePicker->Format    = "HH:mm";

		FirstDatePicker->Date    = date;
		FirstDatePicker->Checked = true;
		FirstTimePicker->Time    = date;
		FirstTimePicker->Enabled = true;
	}else{
		date = Now();
		FirstDatePicker->Format    = "''";
		FirstTimePicker->Format    = "''";

		FirstDatePicker->Date    = date;
		FirstDatePicker->Checked = false;
		FirstTimePicker->Date    = date;
		FirstTimePicker->Enabled = false;
	}

	SecondWEdit->Text            = ZeroSuppress(w2);
	if (!SET_TOP(keiryo_set_)["�v�ʓ���2"].IsNull()){
		date = TDateTime(SET_TOP(keiryo_set_)["�v�ʓ���2"]);
		SecondDatePicker->Format    = "";
		SecondTimePicker->Format    = "HH:mm";

		SecondDatePicker->Date    = date;
		SecondDatePicker->Checked = true;
		SecondTimePicker->Time    = date;
		SecondTimePicker->Enabled = true;
	}else{
		date = Now();
		SecondDatePicker->Format    = "''";
		SecondTimePicker->Format    = "''";

		SecondDatePicker->Date    = date;
		SecondDatePicker->Checked = false;
		SecondTimePicker->Date    = date;
		SecondTimePicker->Enabled = false;
	}

	ChoseiEdit->Text             = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["�����d��"]));
	ChoseirituEdit->Text         = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["������"]));
	JuryobikiEdit->Text          = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["�d�ʈ���"]));
	ShomiEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["�����d��"]));

	PureNetLabel->Caption        = AnsiString(std::abs(w1 - w2)) + " kg";

	Currency tanka               = ToCurrency(SET_TOP(keiryo_set_)["�P��"]);

	SuryoEdit->Text              = ZeroSuppress(ToCurrency(SET_TOP(keiryo_set_)["����"]));
	TaniCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["�P�ʃR�[�h"]));
	TankaEdit->Text              = ZeroSuppress(tanka);
	KingakuEdit->Text            = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["���z"]));
	ShohizeiEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["�`�[����Ŋz"]));

	Currency deftanka            = DM->GetTanka(ToInt(SET_TOP(keiryo_set_)["���Ӑ�ID"]), ToInt(SET_TOP(keiryo_set_)["�i��ID"]),
										ToInt(SET_TOP(keiryo_set_)["����1ID"]), ToInt(SET_TOP(keiryo_set_)["����2ID"]), ToInt(SET_TOP(keiryo_set_)["�P��ID"]));
	DefTankaLabel->Caption       = deftanka;

	TankaEdit->Color = tanka == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

	BikoEdit->Text               = ToString(SET_TOP(keiryo_set_)["���l"]);

	// ����\��
	SetRireki(car_id_);

	return true;
}
//---------------------------------------------------------------------------
// �V�K�v�ʊJ�n
void __fastcall TMainForm::StartWeighing()
{
	ClearForm();

	SetMode(imFirst);

	/* ���_�؂�ւ���L���ɂ��邽�߂�
	int default_index = 0;
	int place_code    = ToInt(DM->INI["Place::Code"]);
	for (unsigned int i = 0; i < DM->PlaceSet.size(); i++){
		if (ToInt(DM->PlaceSet[i]["���_�R�[�h"]) == place_code)
			default_index = i;
	}
	PlaceCombo->ItemIndex = default_index;
	*/

	KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));

	ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// �p���i�ؗ��ԁj�v�ʊJ�n
void __fastcall TMainForm::ContinueWeighing(int id)
{
	ClearForm();
	SetMode(imSecond);
	ShabanEdit->SetFocus();

	keiryo_id_ = id;
	if (!LoadFromID(keiryo_id_)){
		Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	switch (ToInt(SET_TOP(keiryo_set_)["�����敪"])){
	case 0:             // �ؗ���
		break;
	case 1:             // ������
		Application->MessageBox("���̑ؗ��Ԃ͂��łɌv�ʂ���Ă��܂��B\r\n��PC�ȂǂŌv�ʂ���Ă��Ȃ����m�F���Ă��������B",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	default:                // �폜��
		Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    TNotifyEvent OnExit = ShabanEdit->OnExit;
    ShabanEdit->OnExit  = 0;

    //SecondWEdit->Text = cur_weight_;
    SecondWEdit->Text = GetWeight();
    BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
    BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";

    CalcWeight();

    if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
        TokuCodeEdit->SetFocus();
    else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
        HinCodeEdit->SetFocus();
    else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
        Komoku1CodeEdit->SetFocus();
    else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
        Komoku2CodeEdit->SetFocus();
    else
        SecondWEdit->SetFocus();

    ShabanEdit->OnExit  = OnExit;
}
//---------------------------------------------------------------------------
// �v�ʓo�^
void __fastcall TMainForm::PostWeighing()
{
    InputMode mode = GetMode();

    TDateTime now(Now());

    if (!CheckOverload())
        return;

    if (!ValidateForm())
        return;

    Currency w1  = StrToCurrDef(FirstWEdit->Text, 0);
    Currency w2  = StrToCurrDef(SecondWEdit->Text, 0);
    Currency net = StrToCurrDef(ShomiEdit->Text, 0);

    if (GetMode() == imFirst && w2 == 0){
        if (ActiveControl == FirstWEdit){
            if (Application->MessageBox("�ؗ��ԂƂ��ēo�^���܂����H", Caption.c_str(),
                            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) != IDYES){
            	SecondWEdit->SetFocus();
                return;
            }
        }else{
            if (Application->MessageBox("�ؗ��ԂƂ��ēo�^���܂����H", Caption.c_str(),
                            MB_YESNO | MB_ICONQUESTION) != IDYES)
                return;
        }
    }else{
        if (Application->MessageBox("�o�^���܂����H", Caption.c_str(),
                        MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) != IDYES)
            return;
    }

    int toku_id, hin_id, item1_id, item2_id;
    AnsiString toku_name, hin_name, item1_name, item2_name;

    toku_id    = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
    toku_name  = TokuNameEdit->Text;
    hin_id     = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i��ID"));
    hin_name   = HinNameEdit->Text;
    item1_id   = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
    item1_name = Komoku1NameEdit->Text;
    item2_id   = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
    item2_name = Komoku2NameEdit->Text;

    NsFieldSet fields;

    if (new_car_){
        //////////////////////////////////////////////////////////////////////
        // �V�K�ԗ��̏ꍇ�A�ԗ��}�X�^��o�^

        new_car_fields_
            << NsField("[�ԗ�����]",   SharyoNameEdit->Text)
            << NsField("[�g�p�敪]",   1)
            << NsField("[�X�V����]",   now)
            << NsField("[�쐬����]",   now)
            ;
        DM->DBI.Insert("M_�ԗ�", new_car_fields_);
        //DM->DBI.Update("M_�ԗ�", "�ԗ�ID", car_id_, new_car_fields_);

        car_id_ = DM->DBI.GetLastID();
    }

    fields.clear();
    fields
        << NsField("[�sNo]",         1)
        << NsField("[�ԗ�ID]",       car_id_)
        << NsField("[���Ӑ�ID]",     toku_id)
        << NsField("[���Ӑ於��]",   toku_name)
        << NsField("[�i��ID]",       hin_id)
        << NsField("[�i�ږ���]",     hin_name)
        << NsField("[����1ID]",      item1_id)
        << NsField("[����1����]",    item1_name)
        << NsField("[����2ID]",      item2_id)
        << NsField("[����2����]",    item2_name)
        << NsField("[�����o�敪]",   HannyuCombo->ItemIndex + 1)
        << NsField("[���l]",         BikoEdit->Text)

        << NsField("[������]",       StrToCurrDef(ChoseirituEdit->Text, 0))
        << NsField("[�����d��]",     StrToCurrDef(ChoseiEdit->Text, 0))
        << NsField("[�d�ʈ���]",     StrToCurrDef(JuryobikiEdit->Text, 0))

        << NsField("[�����d��]",     net)
        << NsField("[����]",         StrToCurrDef(SuryoEdit->Text, 0))
        << NsField("[�P��ID]",       ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID")))
        << NsField("[�P��]",         StrToCurrDef(TankaEdit->Text, 0))
        << NsField("[���z]",         KingakuEdit->Text.ToIntDef(0))
        << NsField("[����Ŋz]",     ShohizeiEdit->Text.ToIntDef(0))
        << NsField("[�`�[����Ŋz]", ShohizeiEdit->Text.ToIntDef(0))
        << NsField("[�X�V����]",     now)
        ;

    int cmp_kbn;
    bool print = false;                 // ������邩�ǂ����idef: false�j
    int print_id;                       // �������v��ID
    bool create_tran_data = false;      // ����f�[�^���쐬���邩�ǂ����idef: false�j
    int posted_id;                      // ����f�[�^�Ɉڍs����v�ʃf�[�^ID

    TDateTime dt1, dt2;
    if (FirstDatePicker->Checked)
        dt1 = CombineDateTime(FirstDatePicker->Date, FirstTimePicker->Time);
    else
        dt1 = now;
    if (SecondDatePicker->Checked)
        dt2 = CombineDateTime(SecondDatePicker->Date, SecondTimePicker->Time);
    else
        dt2 = now;

    try{
        DM->ADOConnection->BeginTrans();

        if (mode == imFirst){                   //***** ����v��
            fields << NsField("[�v�ʓ�]",    DateToInt(KeiryoDatePicker->Date))
                   << NsField("[���_ID]",    GetPlaceID())
                   << NsField("[�쐬����]",  now)
                   ;

            bool completed;

            if (w1 == 0 || w2 == 0){        // 1��ڌv��

                KeiryoNoEdit->Text = DM->GetTempNo(GetPlaceID());
                fields << NsField("[�`�[No]",    KeiryoNoEdit->Text.ToInt())
                       << NsField("[1��ڏd��]", std::max(w1, w2))
                       << NsField("[1��ڑ�яd��1]", bdn_weight1_)
                       << NsField("[1��ڑ�яd��2]", bdn_weight2_)
                       << NsField("[�v�ʓ���1]", dt1)
                       << NsField("[�����敪]",  0)
                       ;
                completed = false;
            }else{                              // �S�o�^
                KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
                fields << NsField("[�`�[No]",    KeiryoNoEdit->Text.ToInt())
                       << NsField("[1��ڏd��]", w1)
                       // << NsField("[�v�ʓ���1]", now)
                       << NsField("[1��ڑ�яd��1]", bdn_weight1_)
                       << NsField("[1��ڑ�яd��2]", bdn_weight2_)
                       << NsField("[2��ڏd��]", w2)
                       << NsField("[�v�ʓ���2]", dt2)
                       << NsField("[�����敪]",  1)
                       ;
                completed = true;
            }

            DM->DBI.Insert("D_�v��", fields);

            if (completed){
				//Application->MessageBox("�v�ʂ��������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "�o�^���܂��� (�v�ʓ�=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";

                create_tran_data = true;

                posted_id = print_id = DM->DBI.GetLastID();

                if (AutoPrintCheck->Checked)
                    print = true;
                
            }else{
				//Application->MessageBox("�ؗ��ԂƂ��ēo�^���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "�ؗ��Ԃ�o�^���܂��� (�Ԕ�=" + ShabanEdit->Text + ")";
			}

			Action1->Execute();

		}else if (mode == imSecond){            //***** �ؗ���
			if (w1 > 0 && w2 > 0){
				// �d�ʂ������Ă���΁A��������
				KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
				fields << NsField("[�v�ʓ�]",    DateToInt(KeiryoDatePicker->Date))
					   << NsField("[�`�[No]",    KeiryoNoEdit->Text.ToInt())
					   << NsField("[1��ڏd��]", w1)
					   //<< NsField("[�v�ʓ���1]", now)
					   << NsField("[2��ڏd��]", w2)
                       << NsField("[2��ڑ�яd��1]", bdn_weight1_)
                       << NsField("[2��ڑ�яd��2]", bdn_weight2_)
					   << NsField("[�v�ʓ���2]", dt2)
					   << NsField("[�����敪]",  1)
					   ;
				cmp_kbn = 1;
			}else{
				fields << NsField("[1��ڏd��]", w1)
					   << NsField("[2��ڏd��]", w2)
					   ;
				if (w1 > 0 && ToCurrency(SET_TOP(keiryo_set_)["1��ڏd��"]) < 1)
					   fields << NsField("[�v�ʓ���1]", dt1);
				if (w2 > 0 && ToCurrency(SET_TOP(keiryo_set_)["2��ڏd��"]) < 1)
					   fields << NsField("[�v�ʓ���2]", dt2);
				cmp_kbn = 0;
			}

			DM->DBI.Update("D_�v��", "�v��ID", keiryo_id_, fields);

			if (cmp_kbn){
				//Application->MessageBox("�v�ʂ��������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "�o�^���܂��� (�v�ʓ�=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";
			}else{
				//Application->MessageBox("�ؗ����̏C�����s���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "�ؗ��Ԃ��C�����܂��� (�Ԕ�=" + ShabanEdit->Text + ")";
			}

			if (cmp_kbn){
				create_tran_data = true;
				posted_id = print_id = keiryo_id_;
			}

			if (cmp_kbn && AutoPrintCheck->Checked)
				print = true;

			Action1->Execute();

		}else if (mode == imMod){               //***** �C��
			cmp_kbn = ToInt(SET_TOP(keiryo_set_)["�����敪"]);
			TDateTime date1, date2;

			if (FirstDatePicker->Checked)
				fields << NsField("[�v�ʓ���1]", dt1);
			if (SecondDatePicker->Checked)
				fields << NsField("[�v�ʓ���2]", dt2);

			fields << NsField("[1��ڏd��]", w1)
				   << NsField("[2��ڏd��]", w2)
				   ;
			if (cmp_kbn == 1){  // ���łɊ������Ă���ꍇ
				int date = DateToInt(KeiryoDatePicker->Date);
				if (date != ToInt(SET_TOP(keiryo_set_)["�v�ʓ�"])){
					ReplaceSetField(fields, "[�v�ʓ�]", date);
					KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), date);
					ReplaceSetField(fields, "[�`�[No]", KeiryoNoEdit->Text.ToInt());
				}
			}

			if (w1 > 0 && w2 > 0 && cmp_kbn == 0){
				int date = DateToInt(KeiryoDatePicker->Date);
				KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), date);
				ReplaceSetField(fields, "[�`�[No]", KeiryoNoEdit->Text.ToInt());
				fields << NsField("[�����敪]",  1);
				cmp_kbn = 1;
			}

			DM->DBI.Update("D_�v��", "�v��ID", keiryo_id_, fields);

			if (cmp_kbn == 0){
				//Application->MessageBox("�ؗ��f�[�^�̏C�����s���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "�ؗ��Ԃ��C�����܂��� (�Ԕ�=" + ShabanEdit->Text + ")";

			}else{
				//Application->MessageBox("�o�^���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
				StatusBar->Panels->Items[0]->Text = "�C�����܂��� (�v�ʓ�=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";

				posted_id = print_id = keiryo_id_;
				create_tran_data = ToInt(DM->CFG["����f�[�^�쐬"]) ? true : false;

				if (Application->MessageBox("�C�������`�[�𔭍s���܂����H",
						Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES){
					print = true;
				}
            }

            // Action1->Execute();

        }

        if (GetMode() != imMod && DataDeleteCheck->Checked){
            create_tran_data = false;
        }

        if (mode == imMod && create_tran_data && ToInt(DM->CFG["����f�[�^�쐬"])){
            if (Application->MessageBox("����f�[�^���C�����܂����H", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
                create_tran_data = false;
        }
        
        if (create_tran_data){
            //////////////////////////////////////////////////////////////////////
            // ����f�[�^

            NsRecordSet set;
            AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(posted_id);
            DM->DBI.GetRecordSet(sql, set);

            fields.clear();
            fields << NsField("[�����]",       SET_TOP(set)["�v�ʓ�"])
                   << NsField("[���_ID]",       SET_TOP(set)["���_ID"])
                   << NsField("[�v��ID]",       posted_id)
                   << NsField("[����敪]",     ToInt(SET_TOP(set)["����敪"]))
                   << NsField("[�ԗ�ID]",       SET_TOP(set)["�ԗ�ID"])
                   << NsField("[���Ӑ�ID]",     SET_TOP(set)["���Ӑ�ID"])
                   << NsField("[���Ӑ於��]",   SET_TOP(set)["���Ӑ於��"])
                   << NsField("[����1ID]",      SET_TOP(set)["����1ID"])
                   << NsField("[����1����]",    SET_TOP(set)["����1����"])
                   << NsField("[����2ID]",      SET_TOP(set)["����2ID"])
                   << NsField("[����2����]",    SET_TOP(set)["����2����"])
                   << NsField("[���l]",         SET_TOP(set)["���l"])
                   << NsField("[�`�[����Ŋz]", SET_TOP(set)["�`�[����Ŋz"])
                   << NsField("[�sNo]",         SET_TOP(set)["�sNo"])
                   << NsField("[�i��ID]",       SET_TOP(set)["�i��ID"])
                   << NsField("[�i�ږ���]",     SET_TOP(set)["�i�ږ���"])
                   << NsField("[����]",         SET_TOP(set)["����"])
                   << NsField("[�P��ID]",       SET_TOP(set)["�P��ID"])
                   << NsField("[�P��]",         SET_TOP(set)["�P��"])
                   << NsField("[���z]",         SET_TOP(set)["���z"])
                   << NsField("[����Ŋz]",     SET_TOP(set)["����Ŋz"])
                   << NsField("[���ה��l]",     SET_TOP(set)["���ה��l"])
                   << NsField("[�����敪]",     1)
                   << NsField("[�X�V����]",     now)
                   ;
            if (!DM->DBI.IsExist("D_���", "�v��ID", posted_id)){
                fields
                	<< NsField("[�`�[No]",    DM->GetTransNo(ToInt(SET_TOP(set)["���_ID"]), ToInt(SET_TOP(set)["�v�ʓ�"])))
                	<< NsField("[�쐬����]",  now);
                DM->DBI.Insert("D_���", fields);
            }else{
                DM->DBI.Update("D_���", "�v��ID", posted_id, fields);
            }
        }

		DM->ADOConnection->CommitTrans();

    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString msg = "�o�^���ɃG���[���������܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), "�o�^�G���[", MB_OK | MB_ICONWARNING);
        return;
    }

    if (print)
        Print(print_id);

    Q_Tairyu->Close();
    Q_Tairyu->Open();
}
//---------------------------------------------------------------------------
// �`�[���s
void __fastcall TMainForm::Print(int keiryo_id)
{
	int slip_type = ToInt(DM->CFG["�`�[���s�v�����^"]);

	if (slip_type == 1){
		// ���[�U�[
		if (!LaserSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;

	}else if (slip_type == 2){
		// �h�b�g(�A��)
		if (!DotSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;

	}else if (slip_type == 3){
		// �h�b�g(�荷��)
		if (!ManualDotSlipForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;

	}else if (slip_type == 4){
		// �T�[�}��
		QRChitForm->Print(keiryo_id);

	}else if (slip_type == 5){

        PrintKeiryoData(keiryo_id);

    }else{
        // nothing to do
    }

    if (GetMode() != imMod && DataDeleteCheck->Checked){
        NsFieldSet keys;
        keys << NsField("�v��ID", keiryo_id);
		DM->DBI.Delete("D_�v��", keys);
		Action1->Execute();
    }
}
//---------------------------------------------------------------------------
// �e���ڂ̒l�`�F�b�N
bool __fastcall TMainForm::ValidateForm()
{
    AnsiString sql;
    NsRecordSet set;
    int n;

    if (!new_car_){
        if (car_id_ < 1){
            Application->MessageBox("�ԗ��̑I���������ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }

        sql = "SELECT �ԗ����� FROM M_�ԗ� WHERE �ԗ�ID = " + IntToStr(car_id_);
        if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("�ԗ��̑I���������ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }
        if (ToString(SET_TOP(set)["�ԗ�����"]) != SharyoNameEdit->Text){
            Application->MessageBox("������x�ԗ��̑I�������Ă�������", Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return false;
        }
    }

    return true;
}
//---------------------------------------------------------------------------
// �ߐύڃ`�F�b�N
bool __fastcall TMainForm::CheckOverload()
{
    Currency w1  = StrToCurrDef(FirstWEdit->Text, 0);
    Currency w2  = StrToCurrDef(SecondWEdit->Text, 0);
    Currency net = StrToCurrDef(ShomiEdit->Text, 0);
    Currency max = std::max(w1, w2);
	AnsiString msg;

	gross_limit_ = ToCurrency(DM->DBI.Lookup("M_�ԗ�", "�ԗ�ID", car_id_, "�ԗ����d��"));
	net_limit_   = ToCurrency(DM->DBI.Lookup("M_�ԗ�", "�ԗ�ID", car_id_, "�ő�ύڗ�"));

	if (gross_limit_ > 0 && max > gross_limit_){
		msg = "�ԗ����d�ʂɑ΂���ߐύڂł�\r\n\r\n"
              "���݂̏d��: " + FormatFloat("###,##0.#' kg'", max) + "\r\n"
              "�ԗ����d��: " + FormatFloat("###,##0.#' kg'", gross_limit_);
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }

    if (net > 0 && net_limit_ > 0 && net > net_limit_){
        msg = "�ő�ύڗʂɑ΂���ߐύڂł�\r\n\r\n"
              "���݂̏d��: " + FormatFloat("###,##0.#' kg'", net) + "\r\n"
              "�ő�ύڗ�: " + FormatFloat("###,##0.#' kg'", net_limit_);
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------
// ���ʓ��Z�o�ɕK�v�ȏ����擾
void __fastcall TMainForm::GetCalcInfo()
{
    if (GetMode() == imMod)
        return;

    int meig_id  = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i��ID"));

    TaniCodeEdit->Text = DM->GetKanzanCode(toku_id_, meig_id);
}
//---------------------------------------------------------------------------
// �����d�ʂ̌v�Z
void __fastcall TMainForm::CalcWeight()
{
    Currency w1, w2, net;

    try{
        w1 = StrToCurr(FirstWEdit->Text);
        w2 = StrToCurr(SecondWEdit->Text);
    }catch(...){
        ShomiEdit->Text       = AnsiString();
        PureNetLabel->Caption = AnsiString();
        SuryoEdit->Text       = AnsiString();
        return;
    }

    net = std::abs(w1 - w2);
    PureNetLabel->Caption = AnsiString(net) + " kg";

    if (ToBit(DM->CFG["�����g�p�敪"])){
        Currency coord, coord_ratio;

        coord       = ChoseiEdit->Text.ToIntDef(0);
        coord_ratio = StrToCurrDef(ChoseirituEdit->Text, 0) / 100;

        if (coord_ratio > 0){       // �������g�p
            coord = ExtendedRound(net * coord_ratio, ToInt(DM->CFG["�����[����������"]),
                                                     ToInt(DM->CFG["�����[�������敪"]));
            ChoseiEdit->Text = coord;
        }else{
            coord = 0;
            ChoseiEdit->Text = coord;
        }

        net -= int(coord);
    }

    if (ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
        Currency reduc = StrToCurrDef(JuryobikiEdit->Text, 0);

        net -= reduc;
    }

    ShomiEdit->Text = net;

    if (TaniCodeEdit->Text.IsEmpty()){
        int default_code = ToInt(DM->CFG["�W���P��"]);
        if (!default_code)
            default_code = 3;
        TaniCodeEdit->Text = default_code;
    }

    int meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i��ID"));
    //int item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
    //int item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
    int tani_id  = ToInt(DM->DBI.Lookup("M_�P��",   "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID"));

    if (tani_id == 3)
        net = StrToCurrDef(net, 0);
    else
        net = Currency(net) / Currency(1000);

    Currency quantity;
    Currency cnv_ratio = DM->GetKanzan(toku_id_, meig_id, tani_id);

    ///// ���Z�[�������敪�̎擾
    int cnv_div = -1;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["���Z�[�������敪"]))
            cnv_div = ToInt(toku_rec_["���Z�[�������敪"]);
    }
    if (cnv_div == -1)
        cnv_div = ToInt(DM->CFG["���Z�[�������敪"]);
    /////

    if (cnv_ratio == 0){
        quantity = ExtendedRound(net,             ToInt(DM->CFG["���Z�[����������"]), cnv_div);
    }else{
        quantity = ExtendedRound(net / cnv_ratio, ToInt(DM->CFG["���Z�[����������"]), cnv_div);
    }

    if (quantity > ToCurrency(DM->CFG["���m3����"]) && TaniCodeEdit->Text.ToIntDef(0) == 2){
        quantity = ToCurrency(DM->CFG["���m3����"]);
    }

    SuryoEdit->Text = quantity;

    CalcAmount();
}
//---------------------------------------------------------------------------
// ���ʂƋ��z�̌v�Z
void __fastcall TMainForm::CalcAmount(bool update)
{
    //if (GetMode() == imMod)
    //  return;

    int meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i��ID"));
    int item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
    int item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
    int tani_id  = ToInt(DM->DBI.Lookup("M_�P��",   "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID"));

    Currency quantity = StrToCurrDef(SuryoEdit->Text, 0);

    if (!ToBit(DM->CFG["�P���g�p�敪"])){
        // �P���L�����̃f�[�^�������邩������Ȃ��̂ŃR�����^�E�g
        //TankaEdit->Text    = "0";
        //KingakuEdit->Text  = "0";
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency tanka    = StrToCurrDef(TankaEdit->Text, 0);
    Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
    if (GetMode() != imMod && update){
        tanka = deftanka;
    }
    DefTankaLabel->Caption = deftanka;
    TankaEdit->Color = tanka == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

    ///// ���z�[�������敪�̎擾
    int amount_div = -1;
    int amount_fig = 0;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["���z�[�������敪"]))
            amount_div = ToInt(toku_rec_["���z�[�������敪"]);
    }
    if (amount_div == -1)
        amount_div = ToInt(DM->CFG["���z�[�������敪"]);
    if (amount_fig == 0)
        amount_fig = ToInt(DM->CFG["���z�[����������"]);
    /////
    int amount = ExtendedRound(quantity * tanka, amount_fig, amount_div);

    TankaEdit->Text    = tanka;
    KingakuEdit->Text  = amount;

    CalcSalesTax();
}
//---------------------------------------------------------------------------
// ����ŎZ�o
void __fastcall TMainForm::CalcSalesTax()
{
    if (!ToBit(DM->CFG["�P���g�p�敪"])){
        // �P���L�����̃f�[�^�������邩������Ȃ��̂ŃR�����^�E�g
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));          // ����ŗ�

    ///// ����Œ[�������敪�̎擾
    int tax_fig = 0;
    int tax_div = -1;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["����Œ[�������敪"]))
            tax_div = ToInt(toku_rec_["����Œ[�������敪"]);
    }
    if (tax_div == -1)
        tax_div = ToInt(DM->CFG["����Œ[�������敪"]);
    if (tax_fig == 0)
        tax_fig = ToInt(DM->CFG["����Œ[����������"]);
    /////

    int amount, tax;
    amount = KingakuEdit->Text.ToIntDef(0);
    tax    = ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div);
    ShohizeiEdit->Text = tax;
}
//---------------------------------------------------------------------------
// ���[�h�֘A
//---------------------------------------------------------------------------
// ���[�h�ݒ�
void __fastcall TMainForm::SetMode(InputMode mode)
{
    switch (mode){
    case imFirst:       // �V�K
        ModePanel->Caption = "�V�K";
        ModePanel->Color   = TColor(0x00FDD8C6);

        KeiryoNoEdit->ReadOnly = false;
        break;
    case imSecond:      // �ؗ�
        ModePanel->Caption = "�ؗ�";
        ModePanel->Color   = TColor(0x00A6FFFF);

        KeiryoNoEdit->ReadOnly = true;
        break;
    case imMod:         // �C��
        ModePanel->Caption = "�C��";
        ModePanel->Color   = TColor(0x00CEF4D0);

        KeiryoNoEdit->ReadOnly = true;
        break;
/*
    case imDelete:      // �폜
        ModePanel->Caption = "�폜";
        ModePanel->Color   = TColor(0x009B9BFF);
        break;
*/
    }
}
//---------------------------------------------------------------------------
// ���[�h�擾
InputMode __fastcall TMainForm::GetMode()
{
    if (ModePanel->Caption == "�V�K")
        return imFirst;
    else if (ModePanel->Caption == "�ؗ�")
        return imSecond;
    else if (ModePanel->Caption == "�C��")
        return imMod;
/*
    else
        return imDelete;
*/
    return imFirst;
}
//---------------------------------------------------------------------------
// Control Event
//---------------------------------------------------------------------------
// Panel->OnEnter
void __fastcall TMainForm::SharyoPanelEnter(TObject *Sender)
{
    ((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
// Panel->OnExit
void __fastcall TMainForm::SharyoPanelExit(TObject *Sender)
{
    ((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------
// F1 �V�K
void __fastcall TMainForm::Action1Execute(TObject *Sender)
{
    Q_Tairyu->Close();
    Q_Tairyu->Open();

	StartWeighing();
}
//---------------------------------------------------------------------------
// F2 �C��
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	ClearForm();

	// ���ꋒ�_�̍ŏI���R�[�h���擾
	keiryo_id_ = DM->GetLastKeiryoID(GetPlaceID());

	if (keiryo_id_ < 1){
		Application->MessageBox("�C������f�[�^�͂���܂���",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	int kanryo = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id_, "�����敪"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

    if (!LoadFromID(keiryo_id_)){
        Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F3 �폜
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
    InputMode mode = GetMode();

    if (mode == imFirst || keiryo_id_ < 1)
        return;

    if (Application->MessageBox("���̓`�[���폜���܂����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    try{
        DM->ADOConnection->BeginTrans();

        NsFieldSet fields, keys;
        fields << NsField("[�`�[No]",   DM->GetTempNo(GetPlaceID()))
               << NsField("[�����敪]", 9);

        keys   << NsField("[�v��ID]",   keiryo_id_);

        DM->DBI.Update("D_�v��", keys, fields);

        ///// ����f�[�^��������

        // �v�ʃf�[�^���폜�����ꍇ�A�֘A�������f�[�^���폜������
        // �������A�i��ID�Ɛ��ʂ���v���郌�R�[�h�̂�
        AnsiString sql;
        NsRecordSet set;
        sql = "SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id_);
        if (DM->DBI.GetRecordSet(sql, set)){

            fields.clear();
            keys.clear();

            fields << NsField("[�`�[No]",   DM->GetTransTempNo(GetPlaceID()))
                   << NsField("[�����敪]", 9);

            keys   << NsField("[�v��ID]",   keiryo_id_)
                   << NsField("[�i��ID]",   ToInt(SET_TOP(set)["�i��ID"]))
                   << NsField("[����]",     ToCurrency(SET_TOP(set)["����"]));
            DM->DBI.Update("D_���", keys, fields);

            ///// �̔Ԃ��Ȃ���
            sql = " SELECT * FROM D_���"
                  " WHERE �v��ID = " + IntToStr(keiryo_id_) +
                  "   AND �����敪 = 1"
                  " ORDER BY �sNo";
            if (DM->DBI.GetRecordSet(sql, set)){
                int lineno;
                for (unsigned int i = 0; i < set.size(); i++){
                    lineno = ToInt(set[i]["�sNo"]);

                    fields.clear();
                    keys.clear();

                    fields << NsField("[�sNo]",   i + 1)
                           << NsField("[�v��ID]", Variant());
                    keys   << NsField("[���ID]", ToInt(set[i]["���ID"]));
                    DM->DBI.Update("D_���", keys, fields);
                }
            }
        }
        DM->ADOConnection->CommitTrans();
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString msg = "�폜���ɃG���[���������܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), "�v�ʃf�[�^�폜", MB_OK | MB_ICONWARNING);
        return;
    }

    if (mode == imSecond)
        Action1->Execute();
    else
        Action2->Execute();
}
//---------------------------------------------------------------------------
// F4 �Q��
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == ShabanEdit){
		SharyoButton->Click();
	}else if (ActiveControl == TokuCodeEdit){
        TokuButton->Click();
    }else if (ActiveControl == HinCodeEdit){
        HinButton->Click();
    }else if (ActiveControl == Komoku1CodeEdit){
        Komoku1Button->Click();
    }else if (ActiveControl == Komoku2CodeEdit){
        Komoku2Button->Click();
    }else if (ActiveControl == TaniCodeEdit){
        TaniButton->Click();
    }
}
//---------------------------------------------------------------------------
// F5 �o�^
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
    PostWeighing();
}
//---------------------------------------------------------------------------
// F6 �O��
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
    int id;

    if (keiryo_id_){    // �C���A�܂��͑ؗ����
        id = DM->GetPrevKeiryoID(GetPlaceID(),
            ToInt(SET_TOP(keiryo_set_)["�v�ʓ�"]),
            ToInt(SET_TOP(keiryo_set_)["�`�[No"]));
    }else{
        Action2->Execute();
        return;
    }

    if (id < 1)
        return;

    ClearForm();

	keiryo_id_ = id;

	int kanryo = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id_, "�����敪"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

    if (!LoadFromID(id)){
        Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F7 ����
void __fastcall TMainForm::Action7Execute(TObject *Sender)
{
    int id;

    if (keiryo_id_){    // �C���A�܂��͑ؗ����
        id = DM->GetNextKeiryoID(GetPlaceID(),
            ToInt(SET_TOP(keiryo_set_)["�v�ʓ�"]),
            ToInt(SET_TOP(keiryo_set_)["�`�[No"]));
    }else{
        Action2->Execute();
        return;
    }

    if (id < 1)
        return;

    ClearForm();

	keiryo_id_ = id;

	int kanryo = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id_, "�����敪"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

    if (!LoadFromID(id)){
        Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F8 �`�[���s
void __fastcall TMainForm::Action8Execute(TObject *Sender)
{
    if (GetMode() != imMod || keiryo_id_ < 1)
        return;

    if (Application->MessageBox("�`�[�𔭍s���܂����H", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    Print(keiryo_id_);
}
//---------------------------------------------------------------------------
// F9 ����
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (DataListForm->ShowModal() != mrOk)
		return;

	ClearForm();

	keiryo_id_ = DataListForm->selected_id;

	int kanryo = DataListForm->Q_Keiryo->FieldByName("�����敪")->AsInteger;
	//int kanryo = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id_, "�����敪"));

	if (kanryo == 1)
		SetMode(imMod);
	else
		SetMode(imSecond);

	if (!LoadFromID(keiryo_id_)){
        Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F10 �d�ʒl�擾
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	InputMode mode = GetMode();
	if (mode == imFirst){
		if (keiryo_count_ == 2 || keiryo_count_ == 0){
			//FirstWEdit->Text = cur_weight_;
			FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
			FirstWEdit->SetFocus();
		}else{
			//SecondWEdit->Text = cur_weight_;
			SecondWEdit->Text = GetWeight();
            BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
			SecondWEdit->SetFocus();
		}
	}else if (mode == imSecond){
		//SecondWEdit->Text = cur_weight_;
		SecondWEdit->Text = GetWeight();
        BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
        BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
		SecondWEdit->SetFocus();
	}

	CalcWeight();
}
//---------------------------------------------------------------------------
// F11 �����ďo
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (ToString(rireki_set_[0]["�v�ʓ�"]) == AnsiString())
		return;
	TokuCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["���Ӑ�R�[�h"]));
	TokuNameEdit->Text = ToString(rireki_set_[rireki_id_]["���Ӑ於��"]);
	HinCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["�i�ڃR�[�h"]));
	HinNameEdit->Text = ToString(rireki_set_[rireki_id_]["�i�ږ���"]);
	Komoku1CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["����1�R�[�h"]));
	Komoku1NameEdit->Text = ToString(rireki_set_[rireki_id_]["����1����"]);
	Komoku2CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["����2�R�[�h"]));
	Komoku2NameEdit->Text = ToString(rireki_set_[rireki_id_]["����2����"]);
}
//---------------------------------------------------------------------------
// F12 �I��
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
// ���Ӑ挟��
void __fastcall TMainForm::TokuButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT ���Ӑ�R�[�h, ���Ӑ旪�� FROM M_���Ӑ� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ���Ӑ�R�[�h ";
    SearchForm->table_name = "M_���Ӑ�";
    if (SearchForm->ShowModal() != mrOk)
        return;
    TokuCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
    TokuCodeEdit->OnChange(NULL);
    TokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// ����1����
void __fastcall TMainForm::Komoku1ButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT ����1�R�[�h, ����1���� FROM M_����1 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����1�R�[�h ";
    SearchForm->table_name = "M_����1";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Komoku1CodeEdit->Text = SearchForm->Query->FieldByName("����1�R�[�h")->AsInteger;
    Komoku1CodeEdit->OnChange(NULL);
    Komoku1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// ����2����
void __fastcall TMainForm::Komoku2ButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT ����2�R�[�h, ����2���� FROM M_����2 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����2�R�[�h ";
    SearchForm->table_name = "M_����2";
    if (SearchForm->ShowModal() != mrOk)
        return;
    Komoku2CodeEdit->Text = SearchForm->Query->FieldByName("����2�R�[�h")->AsInteger;
    Komoku2CodeEdit->OnChange(NULL);
    Komoku2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// �i�ڌ���
void __fastcall TMainForm::HinButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT �i�ڃR�[�h, �i�ڗ���, �����o�敪���� AS �����o, ����敪���� AS ����敪 FROM V_�i�� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
    SearchForm->table_name = "V_�i��";
    if (SearchForm->ShowModal() != mrOk)
        return;
    HinCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
    HinCodeEdit->OnChange(NULL);
    HinCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// �P�ʌ���
void __fastcall TMainForm::TaniButtonClick(TObject *Sender)
{
    SearchForm->Top = MainForm->Top;
    SearchForm->Left = MainForm->Left + 450;
    SearchForm->based_sql = "SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P�� ";
    SearchForm->orderby_sql = " ORDER BY �P�ʃR�[�h ";
    SearchForm->table_name = "M_�P��";
    if (SearchForm->ShowModal() != mrOk)
        return;
    TaniCodeEdit->Text = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
    TaniCodeEdit->OnChange(NULL);
    TaniCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// Form->Resize
void __fastcall TMainForm::FormResize(TObject *Sender)
{                                               
    int interval = 10;
    F1Button->Width = int((MainForm->Width - interval * 4) / 12);
    F2Button->Width = int((MainForm->Width - interval * 4) / 12);
    F3Button->Width = int((MainForm->Width - interval * 4) / 12);
    F4Button->Width = int((MainForm->Width - interval * 4) / 12);
    F5Button->Width = int((MainForm->Width - interval * 4) / 12);
    F6Button->Width = int((MainForm->Width - interval * 4) / 12);
    F7Button->Width = int((MainForm->Width - interval * 4) / 12);
    F8Button->Width = int((MainForm->Width - interval * 4) / 12);
    F9Button->Width = int((MainForm->Width - interval * 4) / 12);
    F10Button->Width = int((MainForm->Width - interval * 4) / 12);
    F11Button->Width = int((MainForm->Width - interval * 4) / 12);
    F12Button->Width = int((MainForm->Width - interval * 4) / 12);

    F1Button->Left = interval;
    F2Button->Left = F1Button->Left + F1Button->Width - 1;
    F3Button->Left = F2Button->Left + F2Button->Width - 1;
    F4Button->Left = F3Button->Left + F3Button->Width - 1;
    F5Button->Left = F4Button->Left + F4Button->Width - 1 + interval;
    F6Button->Left = F5Button->Left + F5Button->Width - 1;
    F7Button->Left = F6Button->Left + F6Button->Width - 1;
    F8Button->Left = F7Button->Left + F7Button->Width - 1;
    F9Button->Left = F8Button->Left + F8Button->Width - 1 + interval;
    F10Button->Left = F9Button->Left + F9Button->Width - 1;
    F11Button->Left = F10Button->Left + F10Button->Width - 1;
    F12Button->Left = F11Button->Left + F11Button->Width - 1;

    F1Panel->Left = F1Button->Left + 3;
    F2Panel->Left = F2Button->Left + 3;
    F3Panel->Left = F3Button->Left + 3;
    F4Panel->Left = F4Button->Left + 3;
    F5Panel->Left = F5Button->Left + 3;
    F6Panel->Left = F6Button->Left + 3;
    F7Panel->Left = F7Button->Left + 3;
    F8Panel->Left = F8Button->Left + 3;
    F9Panel->Left = F9Button->Left + 3;
    F10Panel->Left = F10Button->Left + 3;
    F11Panel->Left = F11Button->Left + 3;
    F12Panel->Left = F12Button->Left + 3;

    F1Panel->Width = F1Button->Width - 5;
    F2Panel->Width = F2Button->Width - 5;
    F3Panel->Width = F3Button->Width - 5;
    F4Panel->Width = F4Button->Width - 5;
    F5Panel->Width = F5Button->Width - 5;
    F6Panel->Width = F6Button->Width - 5;
    F7Panel->Width = F7Button->Width - 5;
    F8Panel->Width = F8Button->Width - 5;
    F9Panel->Width = F9Button->Width - 5;
    F10Panel->Width = F10Button->Width - 5;
    F11Panel->Width = F11Button->Width - 5;
    F12Panel->Width = F12Button->Width - 5;

    TairyuGrid->RowCount = int(TairyuGrid->Height / 69);

    // ���̃t�H�[���̃T�C�Y�����C���t�H�[���ɍ��킹��
    SearchForm->Height = MainForm->Height;
    DataListForm->Height = MainForm->Height - 33;
    DataListForm->Width  = MainForm->Width  - 24;
    DataListForm->Top  = MainForm->Top  + 16;
    DataListForm->Left = MainForm->Left + 12;
}
//---------------------------------------------------------------------------
// �Ԕ�->OnChange
void __fastcall TMainForm::ShabanEditChange(TObject *Sender)
{
    int no = ShabanEdit->Text.ToIntDef(0);
    if (no == 0){
        SharyoNameEdit->Text = AnsiString();
        return;
    }

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_�ԗ� WHERE �g�p�敪 = 1 AND �Ԕ� = " + IntToStr(no);
    if (!DM->DBI.GetRecordSet(sql, set)){
        SharyoNameEdit->Text = AnsiString();
        return;
    }

    if (set.size() == 1){
		SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
    }else{
        SharyoNameEdit->Text = "�����̎ԗ�������";
    }
}
//---------------------------------------------------------------------------
// ���Ӑ�R�[�h->OnChange
void __fastcall TMainForm::TokuCodeEditChange(TObject *Sender)
{
    int code = TokuCodeEdit->Text.ToIntDef(0);
	if (!code){
		TokuNameEdit->Text = AnsiString();
		return;
	}

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_���Ӑ� WHERE �g�p�敪 = 1 AND ���Ӑ�R�[�h = " + IntToStr(code);
    if (!DM->DBI.GetRecordSet(sql, set)){
        TokuNameEdit->Text = AnsiString();
        return;
    }

    toku_rec_ = SET_TOP(set);
    toku_id_  = ToInt(toku_rec_["���Ӑ�ID"]);

    if (code == ToInt(DM->CFG["���Ӑ揔���R�[�h"])){
        TokuNameEdit->ReadOnly = false;
        TokuNameEdit->TabStop  = true;
    }else{
        TokuNameEdit->Text = ToString(toku_rec_["���Ӑ於��"]);
        TokuNameEdit->ReadOnly = true;
        TokuNameEdit->TabStop  = false;
    }
}
//---------------------------------------------------------------------------
// ���Ӑ�R�[�h->OnExit
void __fastcall TMainForm::TokuCodeEditExit(TObject *Sender)
{
    int id = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
    int code;

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_���ڊ֘A WHERE ���ڔԍ� = 1 AND ����ID = " + IntToStr(id);

    if (DM->DBI.GetRecordSet(sql, set)){
        /*
        id   = ToInt(SET_TOP(set)["���Ӑ�ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", id, "���Ӑ�R�[�h"));
        if (code)
            TokuCodeEdit->Text = code;
        */

        id   = ToInt(SET_TOP(set)["����1ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����1", "����1ID", id, "����1�R�[�h"));
        if (code)
            Komoku1CodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["����2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����2", "����2ID", id, "����2�R�[�h"));
        if (code)
            Komoku2CodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["�i��ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", id, "�i�ڃR�[�h"));
        if (code)
            HinCodeEdit->Text = code;
    }

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// ����1�R�[�h->OnChange
void __fastcall TMainForm::Komoku1CodeEditChange(TObject *Sender)
{
    int code = Komoku1CodeEdit->Text.ToIntDef(0);
	if (!code){
		Komoku1NameEdit->Text = AnsiString();
		return;
	}

    if (code == ToInt(DM->CFG["����1�����R�[�h"])){
        Komoku1NameEdit->ReadOnly = false;
        Komoku1NameEdit->TabStop  = true;
    }else{
        Komoku1NameEdit->Text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", code, "����1����", "�g�p�敪 = 1"));
        Komoku1NameEdit->ReadOnly = true;
        Komoku1NameEdit->TabStop  = false;
    }
}
//---------------------------------------------------------------------------
// ����1�R�[�h->OnExit
void __fastcall TMainForm::Komoku1CodeEditExit(TObject *Sender)
{
    int id = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
    int code;

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_���ڊ֘A WHERE ���ڔԍ� = 2 AND ����ID = " + IntToStr(id);

    if (DM->DBI.GetRecordSet(sql, set)){
        id   = ToInt(SET_TOP(set)["���Ӑ�ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", id, "���Ӑ�R�[�h"));
        if (code)
            TokuCodeEdit->Text = code;

        /*
        id   = ToInt(SET_TOP(set)["����1ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����1", "����1ID", id, "����1�R�[�h"));
        if (code)
            Komoku1CodeEdit->Text = code;
        */

        id   = ToInt(SET_TOP(set)["����2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����2", "����2ID", id, "����2�R�[�h"));
        if (code)
            Komoku2CodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["�i��ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", id, "�i�ڃR�[�h"));
        if (code)
            HinCodeEdit->Text = code;
    }

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// ����2�R�[�h->OnChange
void __fastcall TMainForm::Komoku2CodeEditChange(TObject *Sender)
{
	int code = Komoku2CodeEdit->Text.ToIntDef(0);
	if (!code){
		Komoku2NameEdit->Text = AnsiString();
		return;
	}

    if (code == ToInt(DM->CFG["����2�����R�[�h"])){
        Komoku2NameEdit->ReadOnly = false;
        Komoku2NameEdit->TabStop  = true;
    }else{
        Komoku2NameEdit->Text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", code, "����2����", "�g�p�敪 = 1"));
        Komoku2NameEdit->ReadOnly = true;
        Komoku2NameEdit->TabStop  = false;
    }
}
//---------------------------------------------------------------------------
// ����2�R�[�h->OnExit
void __fastcall TMainForm::Komoku2CodeEditExit(TObject *Sender)
{
    int id = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
    int code;

    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_���ڊ֘A WHERE ���ڔԍ� = 3 AND ����ID = " + IntToStr(id);

    if (DM->DBI.GetRecordSet(sql, set)){
        id   = ToInt(SET_TOP(set)["���Ӑ�ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", id, "���Ӑ�R�[�h"));
        if (code)
            TokuCodeEdit->Text = code;

        id   = ToInt(SET_TOP(set)["����1ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����1", "����1ID", id, "����1�R�[�h"));
        if (code)
            Komoku1CodeEdit->Text = code;

        /*
        id   = ToInt(SET_TOP(set)["����2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����2", "����2ID", id, "����2�R�[�h"));
        if (code)
            Komoku2CodeEdit->Text = code;
        */

        id   = ToInt(SET_TOP(set)["�i��ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", id, "�i�ڃR�[�h"));
        if (code)
            HinCodeEdit->Text = code;
    }

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// �i�ڃR�[�h->OnChange
void __fastcall TMainForm::HinCodeEditChange(TObject *Sender)
{
	int code = HinCodeEdit->Text.ToIntDef(0);
	if (!code){
		HinNameEdit->Text = AnsiString();
		return;
	}

	AnsiString sql;
	NsRecordSet set;

	if (code == ToInt(DM->CFG["�i�ڔ��������R�[�h"]) || code == ToInt(DM->CFG["�i�ڔ��o�����R�[�h"])){
		sql = "SELECT �����o�敪 FROM M_�i�� WHERE �g�p�敪 = 1 AND �i�ڃR�[�h = " + IntToStr(code);
		if (DM->DBI.GetRecordSet(sql, set)){
			HannyuCombo->ItemIndex = ToInt(SET_TOP(set)["�����o�敪"]) - 1;
		}else{
			Application->MessageBox("�}�X�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
				Caption.c_str(), MB_OK | MB_ICONWARNING);
			return;
		}

		HinNameEdit->ReadOnly = false;
		HinNameEdit->TabStop  = true;
	}else{
		sql = "SELECT �i�ږ���, �����o�敪 FROM M_�i�� WHERE �g�p�敪 = 1 AND �i�ڃR�[�h = " + IntToStr(code);
		if (!DM->DBI.GetRecordSet(sql, set)){
			HinNameEdit->Text = AnsiString();
		}else{
			HinNameEdit->Text = ToString(SET_TOP(set)["�i�ږ���"]);
			HannyuCombo->ItemIndex = ToInt(SET_TOP(set)["�����o�敪"]) - 1;
		}
		HinNameEdit->ReadOnly = true;
		HinNameEdit->TabStop  = false;
	}
}
//---------------------------------------------------------------------------
// �i�ڃR�[�h->OnExit
void __fastcall TMainForm::HinCodeEditExit(TObject *Sender)
{
	// �d�ʒ�����
    NsRecordSet set;
	AnsiString sql;

	sql = "SELECT * FROM M_�i�� WHERE �i�ڃR�[�h = " + IntToStr(HinCodeEdit->Text.ToIntDef(0));
	if (DM->DBI.GetRecordSet(sql, set)){
		Currency coord_ratio = ToCurrency(SET_TOP(set)["�d�ʒ�����"]);

		if (StrToCurrDef(ChoseirituEdit->Text, 0) != coord_ratio){
			if (GetMode() == imMod)
				if (Application->MessageBox(("�d�ʒ��������قȂ�܂��B�㏑�����܂����H\r\n�o�^�������F" + FormatFloat("#,##0.0#", coord_ratio) + "%").c_str(), "�i�ڕύX", MB_YESNO | MB_ICONEXCLAMATION) != IDYES)
					return;
			ChoseirituEdit->Text = ZeroSuppress(coord_ratio);
			CalcWeight();
		}
	}


	int id = 0;
	int code;

	sql = "SELECT * FROM M_���ڊ֘A WHERE ���ڔԍ� = 4 AND ����ID = " + IntToStr(id);

	if (DM->DBI.GetRecordSet(sql, set)){
		id   = ToInt(SET_TOP(set)["���Ӑ�ID"]);
		code = 0;
		if (id)
			code = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", id, "���Ӑ�R�[�h"));
		if (code)
			TokuCodeEdit->Text = code;

		id   = ToInt(SET_TOP(set)["����1ID"]);
		code = 0;
		if (id)
			code = ToInt(DM->DBI.Lookup("M_����1", "����1ID", id, "����1�R�[�h"));
		if (code)
			Komoku1CodeEdit->Text = code;

		id   = ToInt(SET_TOP(set)["����2ID"]);
		code = 0;
		if (id)
			code = ToInt(DM->DBI.Lookup("M_����2", "����2ID", id, "����2�R�[�h"));
		if (code)
			Komoku2CodeEdit->Text = code;

        /*
        id   = ToInt(SET_TOP(set)["�i��ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", id, "�i�ڃR�[�h"));
        if (code)
            HinCodeEdit->Text = code;
        */
    }

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// �P�ʃR�[�h->OnChange
void __fastcall TMainForm::TaniCodeEditChange(TObject *Sender)
{
    TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P�ʖ���", ""));
    TaniLabel->Caption = TaniNameEdit->Text;
}
//---------------------------------------------------------------------------
// �����o�R���{->OnKeyDown
void __fastcall TMainForm::HannyuComboKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_ESCAPE)
        HannyuCombo->ItemIndex = -1;
    if (Key == VK_UP || Key == VK_DOWN)
        Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    switch (ErrorEvent){
    case eeReceive:
		StatusBar->Panels->Items[1]->Text = "�d�ʒl��M1: ��M�G���[";
		break;
	case eeConnect:
		StatusBar->Panels->Items[1]->Text = "�d�ʒl��M1: �ڑ��G���[";
		break;
	case eeDisconnect:
		StatusBar->Panels->Items[1]->Text = "�d�ʒl��M1: �ؒf�G���[";
		break;
	default:
        StatusBar->Panels->Items[1]->Text = "�d�ʒl��M1: �\�P�b�g�G���[";
        break;
    };

    ClientSocket1->Close();

    ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    int index;
    AnsiString weight = Socket->ReceiveText();

    std::auto_ptr<TStringList> RecList(new TStringList());
    RecList->Text = weight;
    if (RecList->Count < 1)
        return;
    weight = RecList->Strings[RecList->Count - 1];

	bool ol = false;
    int len = weight.Length();
    if (len < 2)                    return;
    switch (weight[1]){
    case 'S':   WeightPanel1->Font->Color = TColor(0x00CDF7A4);	break;
	case 'U':   WeightPanel1->Font->Color = TColor(0x008080FF);	break;
	case 'O':	WeightPanel1->Font->Color = clYellow;
				ol = true;
				break;
    default:
        return;
    }

    weight.Delete(1, 1);    // �X�e�[�^�X�L�����N�^�̍폜
    weight.Delete(weight.Length() - 1, 2);  // ������ \r\n ���폜
    Currency tmp_weight;
    try{
        tmp_weight = Currency(weight);
	}catch(...){return;}

	// �I�[�o�[���[�h�`�F�b�N
	if (DM->hyoryo_ != 0 && DM->meryo_ != 0)
		if (DM->hyoryo_ + DM->meryo_ * 9 < tmp_weight || DM->meryo_ * (-20) > tmp_weight)
			ol = true;

	if (ol){
		cur_weight1_ = 0;
		WeightPanel1->Caption = "OverLoad";
		return;
	}

	old_weight1_ = cur_weight1_;
	cur_weight1_ = tmp_weight;

	if (old_weight1_ < weighing_border_ && cur_weight1_ >= weighing_border_){
		PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
	}else if ((old_weight1_ >= weighing_border_) && (cur_weight1_ < weighing_border_)){
    	last_card_no_ = 0;
	}

	WeightPanel1->Caption = FormatFloat("###,##0", cur_weight1_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket2Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	switch (ErrorEvent){
	case eeReceive:
		StatusBar->Panels->Items[1]->Text = "�d�ʒl��M: ��M�G���[";
		break;
	case eeConnect:
		StatusBar->Panels->Items[1]->Text = "�d�ʒl��M: �ڑ��G���[";
		break;
	case eeDisconnect:
		StatusBar->Panels->Items[1]->Text = "�d�ʒl��M: �ؒf�G���[";
		break;
	default:
        StatusBar->Panels->Items[1]->Text = "�d�ʒl��M: �\�P�b�g�G���[";
        break;
    };

    ClientSocket1->Close();

    ErrorCode = 0;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocket2Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    int index;
    AnsiString weight = Socket->ReceiveText();

    std::auto_ptr<TStringList> RecList(new TStringList());
    RecList->Text = weight;
    if (RecList->Count < 1)
        return;
    weight = RecList->Strings[RecList->Count - 1];

	bool ol = false;
    int len = weight.Length();
    if (len < 2)                    return;
    switch (weight[1]){
    case 'S':   WeightPanel2->Font->Color = TColor(0x00CDF7A4);	break;
	case 'U':   WeightPanel2->Font->Color = TColor(0x008080FF);	break;
	case 'O':	WeightPanel2->Font->Color = clYellow;
				ol = true;
				break;
    default:
        return;
    }

    weight.Delete(1, 1);    // �X�e�[�^�X�L�����N�^�̍폜
    weight.Delete(weight.Length() - 1, 2);  // ������ \r\n ���폜
    Currency tmp_weight;
    try{
        tmp_weight = Currency(weight);
	}catch(...){return;}

	// �I�[�o�[���[�h�`�F�b�N
	if (DM->hyoryo_ != 0 && DM->meryo_ != 0)
		if (DM->hyoryo_ + DM->meryo_ * 9 < tmp_weight || DM->meryo_ * (-20) > tmp_weight)
			ol = true;

	if (ol){
		cur_weight2_ = 0;
		WeightPanel2->Caption = "OverLoad";
		return;
	}

	old_weight2_ = cur_weight2_;
	cur_weight2_ = tmp_weight;

	// [INI] Weighing::SoundBorder
/*
	int border = ToInt(DM->INI["Weighing::SoundBorder"]);

	if (old_weight_ < border && cur_weight_ >= border){
		// [INI] Weighing::SoundFile
		PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
	}
*/
    if (old_weight2_ < weighing_border_ && cur_weight2_ >= weighing_border_){
        PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
    }else if ((old_weight2_ >= weighing_border_) && (cur_weight2_ < weighing_border_)){
        last_card_no_ = 0;
    }

	WeightPanel2->Caption = FormatFloat("###,##0", cur_weight2_);
}
//---------------------------------------------------------------------------
/**
 * Implementation of NP3411 Event Handler
 */
//---------------------------------------------------------------------------
void __fastcall TMainForm::UMNiiAborted(TMessage& message)
{
	Application->MessageBox("�O���v�����^�̎g�p���ł��܂���", Caption.c_str(), MB_OK | MB_ICONWARNING | MB_TOPMOST);
	DM->Log("�O���v�����^", "�ʐM��~", 2);

	delete printer_thread_;
	printer_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UMNiiStatus(TMessage& message)
{
	NiiStatus status(*(reinterpret_cast<NiiStatus *>(message.LParam)));

    /*
        NiiStatus
        - comm_error
        - status
        - message

        status = -2
        �v�����^�X�e�[�^�X���擾�ł��܂���
        �󎚒����擾���邽��mdb�̗e�ʐߖ�̂��ߔ�\������

    */

	if (status.comm_error){
	   DM->Log("�O���v�����^", status.message, 1);
	}else if (status.status == -1){
       DM->Log("�O���v�����^", status.message, 1);
    }else{
        BF8 bf8;
        bf8.val = (char)(status.status);

        AnsiString msg;

        if (bf8.channels.ch1)
            msg = "���Ȃ�";
        if (bf8.channels.ch2)
            msg = "�w�b�h�J�o�[�I�[�v��";
        if (bf8.channels.ch3)
			msg = "���Ȃ�";
        if (bf8.channels.ch4)
            msg = "�w�b�h���x�ُ�܂��͔r�o�G���[";
        if (bf8.channels.ch5)
            msg = "�J�b�^�[�l��";

        if (!msg.IsEmpty()){
	       //DM->Log("�O���v�����^", status.message, 0);
           //NotifyForm->Notify("�O���v�����^: " + msg, true, 30000);
           StatusBar->Panels->Items[1]->Text = msg;
		}else{
           StatusBar->Panels->Items[1]->Text = "";
        }
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UMNiiReboot(TMessage& message)
{
	DM->Log("�O���v�����^", "�ċN���v��", 1);
}void __fastcall TMainForm::OnRFIDAborted(TMessage& message)
{
	delete rfid_thread_;
	rfid_thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDStatus(TMessage& message)
{
	bool is_fatal = message.WParam;
	AnsiString status(reinterpret_cast<LPCSTR>(message.LParam));

    StatusBar->Panels->Items[1]->Text = "RFID: " + status;
	if (is_fatal)
    	Application->MessageBox(("���RFID���[�_:" + status).c_str(), "���RFID��Q", MB_OK | MB_ICONSTOP);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDCard(TMessage& message)
{
	bool is_valid = message.WParam;
    int card_no = message.LParam;

	if (last_card_no_ == card_no){
	    StatusBar->Panels->Items[1]->Text = "RFID: �d���ǂݎ��";
        ::MessageBeep(MB_ICONEXCLAMATION);
		return;
	}
	if (!is_valid || card_no < 1){
	    StatusBar->Panels->Items[1]->Text = "RFID: �����ȃJ�[�h";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return;
	}
    //if (cur_weight_ < weighing_border_){
    if (GetWeight() < weighing_border_){
	    StatusBar->Panels->Items[1]->Text = "RFID: �ԗ��Ȃ�";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return;
    }

    last_card_no_ = card_no;

    if (!RFIDSharyoCheck(card_no))
    	return;

    if (ToInt(DM->CFG["���RFID�v�ʎ������o�^"]) == 1)
    	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDTimeout(TMessage& message)
{
	bool timeouted = message.WParam;
    if (timeouted)
		Application->MessageBox("���RFID���[�_���������ڑ�����Ă��Ȃ��\��������܂��i���[�_����̕ԓ��Ȃ��j", "���RFID��Q", MB_OK | MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch (Key){
    case VK_DOWN:
        if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_RETURN:
        if (ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_UP:
        if (ActiveControl->Tag != 1){
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_TAB, 0, 0, 0);
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
		break;
	case VK_PRIOR:
		ActionRirekiBefore->Execute();
		break;
	case VK_NEXT:
		ActionRirekiNext->Execute();
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Q_TairyuAfterOpen(TDataSet *DataSet)
{
	TairyuGrid->Visible = Q_Tairyu->RecordCount != 0;
	TairyuKensuLabel->Caption = "(" + IntToStr(Q_Tairyu->RecordCount) + ")";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnSelectTairyu(TObject *Sender)
{
    if (Q_Tairyu->Bof && Q_Tairyu->Eof)
        return;

    ContinueWeighing    (Q_Tairyu->FieldByName("�v��ID")->AsInteger);
}
//---------------------------------------------------------------------------
// ���_��ύX�����ꍇ
void __fastcall TMainForm::PlaceComboChange(TObject *Sender)
{
    Action1->Execute();     // ���̒��� Q_Tairyu �̍X�V�����Ă�
}
//---------------------------------------------------------------------------
// ���ڕύX�̉\��������ꍇ
void __fastcall TMainForm::OnItemsChanged(TObject *Sender)
{
    GetCalcInfo();
    CalcAmount();
}
//---------------------------------------------------------------------------
// �d�ʁA�������A�������v�Z����K�v������ꍇ
void __fastcall TMainForm::OnWeightRecalc(TObject *Sender)
{
    CalcWeight();
}
//---------------------------------------------------------------------------
// ���ʂ���z�����v�Z����K�v������ꍇ
void __fastcall TMainForm::OnAmountRecalc(TObject *Sender)
{
    CalcAmount();
}
//---------------------------------------------------------------------------
// �P��::OnExit
void __fastcall TMainForm::TankaEditExit(TObject *Sender)
{
    CalcAmount(false);
}
//---------------------------------------------------------------------------
// ����ł��v�Z����K�v������ꍇ
void __fastcall TMainForm::OnSalesTaxRecalc(TObject *Sender)
{
    CalcSalesTax();
}
//---------------------------------------------------------------------------
// �ؗ��ԃR���|�[�l���g���J���O
void __fastcall TMainForm::Q_TairyuBeforeOpen(TDataSet *DataSet)
{
    AnsiString sql;
    sql = " SELECT"
          "     �v��ID, �v�ʓ���1, �v�ʓ�, �`�[No,"
          "     �Ԕ�, �ԗ�����, ���Ӑ旪��"
          " FROM"
          "     V_�v��"
          " WHERE"
          "     �sNo = 1"
          " AND"
          "     �����敪 = 0"
          " AND"
          "     ���_ID = " + IntToStr(GetPlaceID()) +
          " ORDER BY �v�ʓ���1";
    Q_Tairyu->SQL->Text = sql;
}
//---------------------------------------------------------------------------
// �`�[No->KeyDown
void __fastcall TMainForm::KeiryoNoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    int place = GetPlaceID();
    int date  = DateToInt(KeiryoDatePicker->Date);
    int no    = KeiryoNoEdit->Text.ToIntDef(0);

    AnsiString sql;
    NsRecordSet set;

    sql = " SELECT �v��ID FROM D_�v��"
          " WHERE �v�ʓ� = " + IntToStr(date) + " AND ���_ID = " + IntToStr(place) +
          "     AND �`�[No = " + IntToStr(no);

    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("�Y������f�[�^��������܂���B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ClearForm();
    SetMode(imMod);

    keiryo_id_ = SET_TOP(set)["�v��ID"];

	if (!LoadFromID(keiryo_id_)){
        Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    ShabanEdit->SetFocus();

}
//---------------------------------------------------------------------------
// 1��ڏd�ʂ� KeyDown
void __fastcall TMainForm::FirstWEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    if (GetMode() != imFirst){
    	SecondWEdit->SetFocus();
        return;
    }

    Currency w2 = StrToCurrDef(SecondWEdit->Text, 0);
    if (w2 != 0){           // �V�K�ł�2��ڏd�ʂ����͍ςȂ炱���ł͓o�^���Ȃ�
    	SecondWEdit->SetFocus();
        return;
    }

    Action5->Execute();
}
//---------------------------------------------------------------------------
// ���l KeyDown
void __fastcall TMainForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Key = 0;
        
    Action5->Execute();
}
//---------------------------------------------------------------------------
// �g���[���v��->Click
void __fastcall TMainForm::TrailerWeightButtonClick(TObject *Sender)
{
    int tag = dynamic_cast<TComponent *>(Sender)->Tag;

    if (TrailerWeightForm->ShowModal() != mrOk)
        return;

    if (tag == 1){
        FirstWEdit->Text  = TrailerWeightForm->TotalWeight;
        FirstWEdit->SetFocus();
    }else if (tag == 2){
        SecondWEdit->Text = TrailerWeightForm->TotalWeight;
        SecondWEdit->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TairyuTimerTimer(TObject *Sender)
{
    TairyuTimer->Enabled = false;

    NsRecordSet set;
    AnsiString sql;
    int total = 0;

    sql = " SELECT SUM(�v��ID) AS �ؗ�ID���v"
          " FROM D_�v��"
          " WHERE �����敪 = 0"
          "   AND �sNo = 1";
    if (DM->DBI.GetRecordSet(sql, set)){
        total = ToInt(SET_TOP(set)["�ؗ�ID���v"]);
    }

    if (id_total_ != total){
        Q_Tairyu->Close();
        Q_Tairyu->Open();
    }

    id_total_ = total;

    TairyuTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WeighingDateTimePickerChange(TObject *Sender)
{
    TDateTimePicker *DatePicker = dynamic_cast<TDateTimePicker *>(Sender);
    TDateTimePicker *TimePicker;

    TimePicker = DatePicker->Tag == 1 ? FirstTimePicker : SecondTimePicker;

    TimePicker->Enabled = DatePicker->Checked;

    if (DatePicker->Checked){
        DatePicker->Format    = "";
        TimePicker->Format    = "HH:mm";

        TDateTime now(Now());
        DatePicker->Date = now;
        TimePicker->Time = now;
    }else{
        DatePicker->Format    = "''";
        TimePicker->Format    = "''";
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KeiryoDatePickerChange(TObject *Sender)
{
    if (GetMode() != imMod)
       KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShabanEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    if (!SharyoCheck())
        return;

    if (ActiveControl != ShabanEdit)
        return;

    if (GetMode() == imMod){
        TokuCodeEdit->SetFocus();
    }else{

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;

        if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
            TokuCodeEdit->SetFocus();
        else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
            HinCodeEdit->SetFocus();
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();
        else if (FirstWEdit->Text.IsEmpty())
            FirstWEdit->SetFocus();
        else
            SecondWEdit->SetFocus();

        ShabanEdit->OnExit = OnExit;
    }
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SharyoCheck()
{
	int car_no = ShabanEdit->Text.ToIntDef(0);
	if (car_no < 1){
		ShabanEdit->Text = AnsiString();
		return false;
	}

	AnsiString sql;
	NsRecordSet set;

	DM->SetShabanQuery(GetMode() != imMod, GetPlaceID());

	if (DM->Q_Shaban->Active)
		DM->Q_Shaban->Close();
	DM->Q_Shaban->Parameters->ParamByName("CARNO")->Value = car_no;
	DM->Q_Shaban->Open();

	new_car_ = false;		// ��U�N���A

	if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
		// �V�K�ԗ��o�^

		TDateTime now(Now());
		NsFieldSet fields;

		AnsiString name = IntToStr(car_no) + " (" + now.FormatString("mm/dd'�o�^'") + ")";
		new_car_fields_.clear();
		new_car_fields_
			   << NsField("[�Ԕ�]",     car_no)
			   //<< NsField("[�ԗ�����]", name)
			   //<< NsField("[�X�V����]", now)
			   //<< NsField("[�쐬����]", now)
			   ;

		// DM->DBI.Insert("M_�ԗ�", new_car_fields_);

		SharyoNameEdit->Text = name;

		//car_id_ = DM->DBI.GetLastID();

		keiryo_count_ = 2;

		if (GetMode() == imFirst){
			//FirstWEdit->Text = cur_weight_;
			FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
        }

		car_id_  = 0;
		new_car_ = true;
		SharyoNameEdit->ReadOnly = false;
		SharyoNameEdit->SetFocus();

		return true;
	}

	/** original **/
	/*
	if (GetMode() == imMod && DM->Q_Shaban->RecordCount == 1){
		int id = DM->Q_Shaban->FieldByName("�ԗ�ID")->AsInteger;
		if (id == car_id_)
			return true;
	}
	*/
	if (GetMode() == imMod){
		while (!DM->Q_Shaban->Eof){
			if (DM->Q_Shaban->FieldByName("�ԗ�ID")->AsInteger == car_id_)
				return true;
			DM->Q_Shaban->Next();
		}
	}

	// �ؗ��Ԃ������͊����ԗ��Ƀq�b�g�����ꍇ�A�I��������
	ShabanSanshoForm->TopPanel->Caption = "  �ԔԁF" + IntToStr(car_no);
	if (ShabanSanshoForm->ShowModal() != mrOk){
		return false;
	}

	car_id_      = ShabanSanshoForm->GetCarID();
	int mastered = ShabanSanshoForm->GetDataDiv();

	if (!car_id_){
		// �V�K�ԗ��i��Ɠ��������j

		NsFieldSet fields;
		TDateTime now(Now());

		AnsiString name = IntToStr(car_no) + " (" + now.FormatString("mm/dd'�o�^'") + ")";
		new_car_fields_.clear();
		new_car_fields_
			<< NsField("[�Ԕ�]",     car_no)
			//<< NsField("[�ԗ�����]", name)
			//<< NsField("[�X�V����]", now)
			//<< NsField("[�쐬����]", now)
			;

		//DM->DBI.Insert("M_�ԗ�", fields);

		//car_id_ = DM->DBI.GetLastID();

		SharyoNameEdit->Text = name;

		keiryo_count_ = 2;

		if (GetMode() == imFirst){
			//FirstWEdit->Text = cur_weight_;
            FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
        }

		car_id_  = 0;
		new_car_ = true;
		SharyoNameEdit->ReadOnly = false;
		TNotifyEvent OnExit = ShabanEdit->OnExit;
		ShabanEdit->OnExit = 0;
		SharyoNameEdit->SetFocus();
		ShabanEdit->OnExit = OnExit;

		return true;
	}

	if (mastered){
		// �ԗ��}�X�^����̑I��

		AnsiString sql;
		NsRecordSet set;

		sql = "SELECT * FROM V_�ԗ� WHERE �ԗ�ID = " + IntToStr(car_id_);
		if (!DM->DBI.GetRecordSet(sql, set)){
			Application->MessageBox("�I�����ꂽ�ԗ������݂��܂���B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
				Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}

		if (GetMode() != imMod){
			if (TokuCodeEdit->Text.IsEmpty())
				TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["���Ӑ�R�[�h"]));
			if (Komoku1CodeEdit->Text.IsEmpty())
				Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����1�R�[�h"]));
			if (Komoku2CodeEdit->Text.IsEmpty())
				Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����2�R�[�h"]));
			if (HinCodeEdit->Text.IsEmpty())
				HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["�i�ڃR�[�h"]));

			if (ToCurrency(SET_TOP(set)["��ԏd��"]) > 0){
				keiryo_count_ = 1;
				FirstWEdit->Text = ToCurrency(SET_TOP(set)["��ԏd��"]);
			}else{
				keiryo_count_ = 2;
			}
			gross_limit_ = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
			net_limit_   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

			SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);

			if (keiryo_count_ == 2){
				//FirstWEdit->Text = cur_weight_;
				FirstWEdit->Text = GetWeight();
                BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
			}else{
				//SecondWEdit->Text = cur_weight_;
				SecondWEdit->Text = GetWeight();
                BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
            }
		}else{
			SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
		}
	}else{
		// �ؗ��Ԃ���̑I��
		int keiryo_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);
		if (!keiryo_id){
			Application->MessageBox("�I�����ꂽ�ؗ���񂪑��݂��܂���B\r\n��PC�ȂǂŌv�ʂ���Ă��Ȃ����m�F���Ă��������B",
				Caption.c_str(), MB_OK | MB_ICONWARNING);
			return false;
		}

		//TNotifyEvent OnExit = ShabanEdit->OnExit;
		//ShabanEdit->OnExit  = 0;
		ContinueWeighing(keiryo_id);
		//ShabanEdit->OnExit  = OnExit;
	}

	if (keiryo_count_ == 1)
		CalcWeight();

	// ������\������
	SetRireki(car_id_);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::RFIDSharyoCheck(int card_no)
{
	new_car_ = false;

    NsRecordSet car_set;
    if (!DM->DBI.GetRecordSet("SELECT * FROM V_�ԗ� WHERE �J�[�h�ԍ� = " + IntToStr(card_no), car_set)){
	    StatusBar->Panels->Items[1]->Text = "RFID: �ԗ����Ȃ�";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return false;
    }

    if (ToInt(SET_TOP(car_set)["�g�p�敪"]) != 1){
	    StatusBar->Panels->Items[1]->Text = "RFID: �g�p���Ȃ��ԗ����";
        ::MessageBeep(MB_ICONEXCLAMATION);
        return false;
    }

	Action1->Execute();

    car_id_         = ToInt(SET_TOP(car_set)["�ԗ�ID"]);
	int remained_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);

	if (!remained_id){		// ����v��
		ShabanEdit->Text      = ZeroSuppress(ToInt(SET_TOP(car_set)["�Ԕ�"]));
		TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(car_set)["���Ӑ�R�[�h"]));
		HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(car_set)["�i�ڃR�[�h"]));
		Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(car_set)["����1�R�[�h"]));
		Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(car_set)["����2�R�[�h"]));

		if (ToCurrency(SET_TOP(car_set)["��ԏd��"]) > 0){
			keiryo_count_ = 1;
			FirstWEdit->Text = ToCurrency(SET_TOP(car_set)["��ԏd��"]);
		}else{
			keiryo_count_ = 2;
		}

		SharyoNameEdit->Text = ToString(SET_TOP(car_set)["�ԗ�����"]);

		if (keiryo_count_ == 2){
			//FirstWEdit->Text = cur_weight_;
			FirstWEdit->Text = GetWeight();
            BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
		}else{
			//SecondWEdit->Text = cur_weight_;
			SecondWEdit->Text = GetWeight();
            BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
            BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
        }

		CalcWeight();

		TNotifyEvent OnExit = ShabanEdit->OnExit;
		ShabanEdit->OnExit  = 0;

		if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
			TokuCodeEdit->SetFocus();
		else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
			HinCodeEdit->SetFocus();
		else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
			Komoku1CodeEdit->SetFocus();
		else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
			Komoku2CodeEdit->SetFocus();
		else if (keiryo_count_ == 2)
			FirstWEdit->SetFocus();
		else if (keiryo_count_ == 1)
			SecondWEdit->SetFocus();

		ShabanEdit->OnExit  = OnExit;

	}else{					// �ؗ���
		ContinueWeighing(remained_id);
	}

	gross_limit_    = ToCurrency(SET_TOP(car_set)["�ԗ����d��"]);
	net_limit_      = ToCurrency(SET_TOP(car_set)["�ő�ύڗ�"]);
	// ������\������
	SetRireki(car_id_);

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
	SharyoCheck();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SharyoButtonClick(TObject *Sender)
{
	DM->SetShabanQuery(GetMode() != imMod, GetPlaceID(), false);
	DM->Q_Shaban->Open();
	ShabanSanshoForm->TopPanel->Caption = AnsiString();
	if (ShabanSanshoForm->ShowModal() != mrOk){
		ShabanEdit->SetFocus();
		return;
    }

    car_id_      = ShabanSanshoForm->GetCarID();
    int car_no   = ShabanSanshoForm->GetCarNo();
    int mastered = ShabanSanshoForm->GetDataDiv();

    if (!car_id_){
        ShabanEdit->SetFocus();
        return;     // �V�K�ԗ��͓o�^�ł��Ȃ�
    }

    if (mastered){
        // �ԗ��}�X�^����̑I��

        AnsiString sql;
        NsRecordSet set;

        sql = "SELECT * FROM V_�ԗ� WHERE �ԗ�ID = " + IntToStr(car_id_);
        if (!DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("�I�����ꂽ�ԗ������݂��܂���B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return;
        }

        ShabanEdit->Text         = car_no;
        SharyoNameEdit->ReadOnly = true;
        
        if (GetMode() != imMod){
            if (TokuCodeEdit->Text.IsEmpty())
                TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["���Ӑ�R�[�h"]));
            if (Komoku1CodeEdit->Text.IsEmpty())
                Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����1�R�[�h"]));
            if (Komoku2CodeEdit->Text.IsEmpty())
                Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����2�R�[�h"]));
            if (HinCodeEdit->Text.IsEmpty())
                HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["�i�ڃR�[�h"]));

            if (ToCurrency(SET_TOP(set)["��ԏd��"]) > 0){
                keiryo_count_ = 1;
                FirstWEdit->Text = ToCurrency(SET_TOP(set)["��ԏd��"]);
            }else{
                keiryo_count_ = 2;
            }
            gross_limit_ = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
            net_limit_   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);

            if (keiryo_count_ == 2){
                //FirstWEdit->Text = cur_weight_;
                FirstWEdit->Text = GetWeight();
                BreakdownWLabel1->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel2->Caption = AnsiString(bdn_weight2_) + " kg";
            }else{
                //SecondWEdit->Text = cur_weight_;
                SecondWEdit->Text = GetWeight();
                BreakdownWLabel3->Caption = AnsiString(bdn_weight1_) + " kg";
                BreakdownWLabel4->Caption = AnsiString(bdn_weight2_) + " kg";
            }
        }else{
            SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
        }
    }else{
        // �ؗ��Ԃ���̑I��
        int keiryo_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);
        if (!keiryo_id){
            Application->MessageBox("�I�����ꂽ�ؗ���񂪑��݂��܂���B\r\n��PC�ȂǂŌv�ʂ���Ă��Ȃ����m�F���Ă��������B",
                Caption.c_str(), MB_OK | MB_ICONWARNING);
            ShabanEdit->SetFocus();
            return;
        }

        ShabanEdit->Text         = car_no;
        SharyoNameEdit->ReadOnly = true;

        //TNotifyEvent OnExit = ShabanEdit->OnExit;
        //ShabanEdit->OnExit  = 0;
        ContinueWeighing(keiryo_id);
        //ShabanEdit->OnExit  = OnExit;
    }

    if (keiryo_count_ == 1)
        CalcWeight();

	// ����
	SetRireki(car_id_);

    TokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// �����N�G���Z�b�g
void __fastcall TMainForm::SetRireki(int sharyo_id)
{
	rireki_set_.clear();
	ClearRireki();

	if (!DispRirekiCheckBox->Checked)
		return;
	Q_Rireki->SQL->Strings[12] = "	�ԗ�ID = " + IntToStr(sharyo_id);
	DM->DBI.GetRecordSet(Q_Rireki->SQL->Text, rireki_set_);
	rireki_id_ = 0;
	RirekiDisp();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RirekiDisp()
{
	RirekiDateLabel->Caption = "�ŏI�v�ʓ��F " + FormatFloat("0000/00/00;#;#", ToInt(rireki_set_[rireki_id_]["�v�ʓ�"]));
	RirekiTokuCodeLabel->Caption    = ToString(rireki_set_[rireki_id_]["���Ӑ�R�[�h"]);
	RirekiTokuNameLabel->Caption    = ToString(rireki_set_[rireki_id_]["���Ӑ於��"]);
	RirekiHinCodeLabel->Caption     = ToString(rireki_set_[rireki_id_]["�i�ڃR�[�h"]);
	RirekiHinNameLabel->Caption     = ToString(rireki_set_[rireki_id_]["�i�ږ���"]);
	RirekiKomoku1CodeLabel->Caption = ToString(rireki_set_[rireki_id_]["����1�R�[�h"]);
	RirekiKomoku1NameLabel->Caption = ToString(rireki_set_[rireki_id_]["����1����"]);
	RirekiKomoku2CodeLabel->Caption = ToString(rireki_set_[rireki_id_]["����2�R�[�h"]);
	RirekiKomoku2NameLabel->Caption = ToString(rireki_set_[rireki_id_]["����2����"]);

	if (ToString(rireki_set_[0]["�v�ʓ�"]) != AnsiString())
		RirekiOrderLabel->Caption = IntToStr(rireki_id_ + 1) + "/" + IntToStr(rireki_set_.size());
	else
		RirekiOrderLabel->Caption = AnsiString();
}
//---------------------------------------------------------------------------
// �O���� [PageUp]
void __fastcall TMainForm::ActionRirekiBeforeExecute(TObject *Sender)
{
	if (rireki_id_ <= 0)
		return;
	rireki_id_--;
	RirekiDisp();
}
//---------------------------------------------------------------------------
// �㗚�� [PageDown]
void __fastcall TMainForm::ActionRirekiNextExecute(TObject *Sender)
{
	if (rireki_id_ >= rireki_set_.size() - 1)
		return;
	rireki_id_++;
	RirekiDisp();
}
//---------------------------------------------------------------------------
// ����\��
void __fastcall TMainForm::DispRirekiCheckBoxClick(TObject *Sender)
{
	if (DispRirekiCheckBox->Checked)
		RirekiPanel->Height = 104;
	else
		RirekiPanel->Height = 16;
}
//---------------------------------------------------------------------------
// �����N���A
void __fastcall TMainForm::ClearRireki()
{
	RirekiDateLabel->Caption        = AnsiString();
	RirekiTokuCodeLabel->Caption    = AnsiString();
	RirekiTokuNameLabel->Caption    = AnsiString();
	RirekiHinCodeLabel->Caption     = AnsiString();
	RirekiHinNameLabel->Caption     = AnsiString();
	RirekiKomoku1CodeLabel->Caption = AnsiString();
	RirekiKomoku1NameLabel->Caption = AnsiString();
	RirekiKomoku2CodeLabel->Caption = AnsiString();
	RirekiKomoku2NameLabel->Caption = AnsiString();
	RirekiOrderLabel->Caption       = AnsiString();
}
//---------------------------------------------------------------------------
// Edit->OnEnter (���[�U�T�|�[�g����\��)
void __fastcall TMainForm::ShabanEditEnter(TObject *Sender)
{
	if (((TCobEdit *)Sender)->Hint == AnsiString())
		return;
	StatusBar->Panels->Items[2]->Text = ((TCobEdit *)Sender)->Hint;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintKeiryoData(int keiryo_id)
{
	if (printer_thread_){
        AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID =" + ToString(keiryo_id);

        keiryo_set_.clear();
        print_set_.clear();

        if (!DM->DBI.GetRecordSet(sql, keiryo_set_)){
            DM->Log("������","���擾���s���܂���", 2);
            return;
        }else{
            //ShowMessage(ToString(SET_TOP(printer_set_)["�v��ID"]));
        }

        int print_info_id = DM->GetPrintInfo(keiryo_id);

        if (!print_info_id){
            DM->Log("�`�[���s", "�`�[��񂪐ݒ肳��Ă��܂���", 2);
            return;
        }

        sql = "SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(print_info_id);

        if (!DM->DBI.GetRecordSet(sql, print_set_)){
            DM->Log("�`�[���s", "�`�[��񂪖����ł�", 2);
            return;
        }


   		//PostThreadMessage(printer_thread_->ThreadID, UM_NII_PRINT, keiryo_id, 0);
        PostThreadMessage(printer_thread_->ThreadID, UM_NII_PRINT, (WPARAM)&keiryo_set_, (LPARAM)&print_set_);


    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PrintCopy(int keiryo_id)
{
	int slip_type   = ToInt(DM->CFG["�`�[���s�v�����^"]);

    /***************************************************/
    /* ���ӁF �T���`�[�̏ꍇ�́A����͂̂ق��̎��Ԉ󎚐ݒ�����Ă��� */

    bool print_time = ToBit(DM->CFG["���Ԉ󎚏����敪"]);

	if (slip_type == 1){
		// ���[�U�[

		if (!LaserSlipPrintForm->Print(keiryo_id, !print_time))
			return;

	}else if (slip_type == 2){
		// �h�b�g

        if (!DotSlipPrintForm->Print(keiryo_id, !print_time))
            return;

	}else{
		// nothing to do
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectScale1(TObject *Sender)
{
    FWBasePanel->Color = TColor(0x008AF8FD);
    FWNamePanel->Color = TColor(0x008AF8FD);
    SWBasePanel->Color = clBtnFace;
    SWNamePanel->Color = clBtnFace;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectScale2(TObject *Sender)
{
    FWBasePanel->Color = clBtnFace;
    FWNamePanel->Color = clBtnFace;
    SWBasePanel->Color = TColor(0x008AF8FD);
    SWNamePanel->Color = TColor(0x008AF8FD);
}
//---------------------------------------------------------------------------

