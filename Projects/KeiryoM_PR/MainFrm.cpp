//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "AnbunFrm.h"
#include "DataListFrm.h"
#include "MainFrm.h"
#include <mmsystem.h>
#include "LaserSlipPrintFrm.h"
#include "LaserSlipPrintM_GenkinFrm.h"
#include "LaserSlipPrintM_KakeFrm.h"
#include "DotSlipPrintFrm.h"
#include "TrailerWeightFrm.h"
#include "ShabanSanshoFrm.h"
#include "PostConfFrm.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner),
		keiryo_id_(0),
		cur_weight_(0), old_weight_(0),
		id_total_(0),
        rfid_thread_(0), last_card_no_(0)
{
	Application->OnMessage = MessageProc;

	gyo[0] = GyoTitleEdit;				gyo[1] = GyoEdit1;					gyo[2] = GyoEdit2;					gyo[3] = GyoEdit3;					gyo[4] = GyoEdit4;					gyo[5] = GyoEdit5;					gyo[6] = GyoEdit6;
	hincode[0] = HinCodeTitleEdit;		hincode[1] = HinCodeEdit1;			hincode[2] = HinCodeEdit2;			hincode[3] = HinCodeEdit3;			hincode[4] = HinCodeEdit4;			hincode[5] = HinCodeEdit5;			hincode[6] = HinCodeEdit6;
	hinname[0] = HinNameTitleEdit;		hinname[1] = HinNameEdit1;			hinname[2] = HinNameEdit2;			hinname[3] = HinNameEdit3;			hinname[4] = HinNameEdit4;			hinname[5] = HinNameEdit5;			hinname[6] = HinNameEdit6;
	weight1[0] = WeightTitleEdit1;		weight1[1] = WeightEdit11;			weight1[2] = WeightEdit21;			weight1[3] = WeightEdit31;			weight1[4] = WeightEdit41;			weight1[5] = WeightEdit51;			weight1[6] = WeightEdit61;
	weight2[0] = WeightTitleEdit2;		weight2[1] = WeightEdit12;			weight2[2] = WeightEdit22;			weight2[3] = WeightEdit32;			weight2[4] = WeightEdit42;			weight2[5] = WeightEdit52;			weight2[6] = WeightEdit62;
	choritu[0] = ChoseiTitleEdit;		choritu[1] = ChoseiPerEdit1;		choritu[2] = ChoseiPerEdit2;		choritu[3] = ChoseiPerEdit3;		choritu[4] = ChoseiPerEdit4;		choritu[5] = ChoseiPerEdit5;		choritu[6] = ChoseiPerEdit6;
	/* �����^�C�g������ */				choweight[1] = ChoseiWeightEdit1;	choweight[2] = ChoseiWeightEdit2;	choweight[3] = ChoseiWeightEdit3;	choweight[4] = ChoseiWeightEdit4;	choweight[5] = ChoseiWeightEdit5;	choweight[6] = ChoseiWeightEdit6;
	bikiweight[0] = BikiWeightTitleEdit;bikiweight[1] = BikiWeightEdit1;	bikiweight[2] = BikiWeightEdit2;	bikiweight[3] = BikiWeightEdit3;	bikiweight[4] = BikiWeightEdit4;	bikiweight[5] = BikiWeightEdit5;	bikiweight[6] = BikiWeightEdit6;
	shomi[0] = ShomiTitleEdit;			shomi[1] = ShomiEdit1;				shomi[2] = ShomiEdit2;				shomi[3] = ShomiEdit3;				shomi[4] = ShomiEdit4;				shomi[5] = ShomiEdit5;				shomi[6] = ShomiEdit6;
	suryo[0] = SuryoTitleEdit;			suryo[1] = SuryoEdit1;				suryo[2] = SuryoEdit2;				suryo[3] = SuryoEdit3;				suryo[4] = SuryoEdit4;				suryo[5] = SuryoEdit5;				suryo[6] = SuryoEdit6;
	tanicode[0] = TaniTitleEdit;		tanicode[1] = TaniCodeEdit1;		tanicode[2] = TaniCodeEdit2;		tanicode[3] = TaniCodeEdit3;		tanicode[4] = TaniCodeEdit4;		tanicode[5] = TaniCodeEdit5;		tanicode[6] = TaniCodeEdit6;
	/* �P�ʃ^�C�g������ */				taniname[1] = TaniNameEdit1;		taniname[2] = TaniNameEdit2;		taniname[3] = TaniNameEdit3;		taniname[4] = TaniNameEdit4;		taniname[5] = TaniNameEdit5;		taniname[6] = TaniNameEdit6;
	tanka[0] = TankaTitleEdit;			tanka[1] = TankaEdit1;				tanka[2] = TankaEdit2;				tanka[3] = TankaEdit3;				tanka[4] = TankaEdit4;				tanka[5] = TankaEdit5;				tanka[6] = TankaEdit6;
	kingaku[0] = KingakuTitleEdit;		kingaku[1] = KingakuEdit1;			kingaku[2] = KingakuEdit2;			kingaku[3] = KingakuEdit3;			kingaku[4] = KingakuEdit4;			kingaku[5] = KingakuEdit5;			kingaku[6] = KingakuEdit6;
    shouhi[0] = ShouhizeiTitleEdit;     shouhi[1] = ShouhizeiEdit1;         shouhi[2] = ShouhizeiEdit2;         shouhi[3] = ShouhizeiEdit3;         shouhi[4] = ShouhizeiEdit4;          shouhi[5] = ShouhizeiEdit5;         shouhi[6] = ShouhizeiEdit6;
	biko[0] = BikoTitleEdit;			biko[1] = BikoEdit1;				biko[2] = BikoEdit2;				biko[3] = BikoEdit3;				biko[4] = BikoEdit4;				biko[5] = BikoEdit5;				biko[6] = BikoEdit6;
    //limit_line_ �̓w�b�_�t�@�C���Œ�`�ς�
    //weighing1time[0] = {0}; weighing1time[1] = {0}; weighing1time[2] = {0}; weighing1time[3] = {0}; weighing1time[4] = {0}; weighing1time[5] = {0}; weighing1time[6] = {0}; weighing1time[7] = {0};
    //weighing2time[0] = {0}; weighing2time[1] = {0}; weighing2time[2] = {0}; weighing2time[3] = {0}; weighing2time[4] = {0}; weighing2time[5] = {0}; weighing2time[6] = {0}; weighing2time[7] = {0};
    memset(weighing1time, 0,sizeof(weighing1time));

	max_line_ = 1;
	delete_id_list_ = new TStringList();
    shomi_total_ = 0;
    kingaku_total_ = 0;
    tax_total_ = 0;

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

    // RFID
    if (ToInt(DM->CFG["���RFID�v��"])){
        int rfid_port   =   ToInt(DM->INI[L"RFID::DeskCommPort"]);
        rfid_thread_    =   new THF04Thread(true, Handle, rfid_port);
        rfid_thread_->FreeOnTerminate = false;
        rfid_thread_->Resume();
    }

    weighing_border_ = ToInt(DM->INI["Weighing::SoundBorder"]);

	// �ؗ��e�[�u���I�[�v��
	try{
		Q_Tairyu->Open();
	}catch (Exception& e){
		Application->MessageBox(("�ؗ��ꗗ�f�[�^�̓ǂݍ��݂Ɏ��s���܂���\r\n" + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
		Close();
	}

	// ���ʁ��ڗ�
	DM->hyoryo_ = ToCurrency(DM->CFG["����"]);
	DM->meryo_  = ToCurrency(DM->CFG["�ڗ�"]);

	///////////////////////////////////////////////
	// �d�ʎ�M
	try{
		// [INI] Weighing::WIPort
		ClientSocket->Port = ToInt(DM->INI["Weighing::WIPort"]);
		// [INI] Weighing::WIServer
		ClientSocket->Host = ToString(DM->INI["Weighing::WIServer"]);

		if (ClientSocket->Active)
			ClientSocket->Close();
		ClientSocket->Open();
	}catch(Exception& e){
		AnsiString msg = "TCP/IP�ʐM���ł��܂���: \r\n" + e.Message;
		Application->MessageBox(msg.c_str(), "�l�b�g���[�N�G���[", MB_OK | MB_ICONINFORMATION);
	}

	SocketReopenTimer->Enabled = true;

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
	TokuButton->Caption    = ToString(DM->CFG["���Ӑ�}�X�^����"]);
	Komoku1Button->Caption = ToString(DM->CFG["����1�}�X�^����"]);
	Komoku2Button->Caption = ToString(DM->CFG["����2�}�X�^����"]);
	hinname[0]->Text       = ToString(DM->CFG["�i�ڃ}�X�^����"]);
	choritu[0]->Text       = ToString(DM->CFG["��������"]);
	bikiweight[0]->Text    = ToString(DM->CFG["�d�ʈ�������"]);

	DM->kname_toku_		= AnsiReplaceStr(AnsiReplaceStr(TokuButton->Caption,	"�@", ""), " ", "");
	DM->kname_hin_		= AnsiReplaceStr(AnsiReplaceStr(hinname[0]->Text,		"�@", ""), " ", "");
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
		// ���i�ŕi�ڂ͕K�{�Ƃ���
		//HinPanel->Visible             = false;
	}
    if (!ToBit(DM->CFG["���o�Ɏg�p�敪"])){
        HannyuPanel->Visible = false;
		RecalcButton->Visible = false;

	}
	if (!ToBit(DM->CFG["�����g�p�敪"])){
		choritu[0]->Visible = false;
	}
	if (!ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
		bikiweight[0]->Visible = false;
	}
	if (!ToBit(DM->CFG["�P���g�p�敪"])){
		suryo[0]->Visible    = false;
		tanicode[0]->Visible = false;
		//taniname[0]->Visible = false;
		tanka[0]->Visible    = false;
		kingaku[0]->Visible  = false;
        //20160606
        shouhi[0]->Visible   = false;
	}
	if (!ToBit(DM->CFG["�d�ʕҏW�敪"])){
		for (int i = 1; i < 7; i++){
			weight1[i]->ReadOnly = true;
			weight2[i]->ReadOnly = true;
		}
	}
    //���i������Ōv�Z�敪
    if (ToString(DM->CFG["���i������Ōv�Z�敪"]).ToIntDef(1) == 1){
        shouhi[0]->Visible = false;
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
	Komoku1CodeEdit->Hint = DM->kname_komoku1_ + "�R�[�h����͂��Ă��������B(" + DM->kname_komoku1_ + "�{�^�� or [F4]���}�X�^�Q��)";
	Komoku2CodeEdit->Hint = DM->kname_komoku2_ + "�R�[�h����͂��Ă��������B(" + DM->kname_komoku2_ + "�{�^�� or [F4]���}�X�^�Q��)";
	for (int i = 1; i < limit_line_ + 1; i++)
		hincode[i]->Hint     = DM->kname_hin_     + "�R�[�h����͂��Ă��������B(" + DM->kname_hin_     + "�{�^�� or [F4]���}�X�^�Q��)";

	// �O���b�h�i���ד��͕����j�̐��` ++++++++++++++++++++++++++++++++++++++++++
	int left = weight2[0]->Left + weight2[0]->Width + 3;
	// ����
	if (choritu[0]->Visible)
		left = choritu[0]->Left + choritu[0]->Width + 3;
	else{
		for (int i = 1; i < limit_line_ + 1; i++){
			choritu[i]->Visible   = false;
			choweight[i]->Visible = false;
		}
	}
	// �d�ʈ���
	if (bikiweight[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			bikiweight[i]->Left = left;
		left = bikiweight[0]->Left + bikiweight[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			bikiweight[i]->Visible = false;
	}
	// �����d��
	if (shomi[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			shomi[i]->Left = left;
		WeightSumTitleLabel->Left = left - 52;
		ShomiSumEdit->Left = left;
		left = shomi[0]->Left + shomi[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			shomi[i]->Visible = false;
		WeightSumTitleLabel->Visible = false;
		ShomiSumEdit->Visible        = false;
	}
	// ����
	if (suryo[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			suryo[i]->Left = left;
		left = suryo[0]->Left + suryo[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			suryo[i]->Visible = false;
	}
	// �P��
	if (tanicode[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++){
			tanicode[i]->Left = left;
			if (i > 0)
				taniname[i]->Left = tanicode[i]->Left + tanicode[i]->Width + 3;
		}
		left = tanicode[0]->Left + tanicode[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++){
			tanicode[i]->Visible = false;
			taniname[i]->Visible = false;
		}
	}
	// �P��
	if (tanka[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			tanka[i]->Left = left;
		left = tanka[0]->Left + tanka[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			tanka[i]->Visible = false;
	}
	// ���z
	if (kingaku[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			kingaku[i]->Left = left;
		KingakuSumTitleLabel->Left = left - 90;
		KingakuSumEdit->Left = left;
		ShohizeiTitleLabel->Left = left + 100;
		ShohizeiEdit->Left = left + 148;
		left = kingaku[0]->Left + kingaku[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			kingaku[i]->Visible       = false;
		KingakuSumTitleLabel->Visible = false;
		KingakuSumEdit->Visible       = false;
		ShohizeiTitleLabel->Visible   = false;
		ShohizeiEdit->Visible         = false;
        KingakuPanel->Visible         = false;
	}
    //�����
    if (shouhi[0]->Visible){
        for (int i = 0; i < limit_line_ + 1; i++)
            shouhi[i]->Left + shouhi[0]->Width + 3;
        left = shouhi[0]->Left + shouhi[0]->Width + 3;
    }else{
        for (int i = 0; i < limit_line_ + 1; i++)
            shouhi[i]->Visible = false;
    }
	// ���ה��l
	if (biko[0]->Visible){
		for (int i = 0; i < limit_line_ + 1; i++)
			biko[i]->Left = left;
		left = biko[0]->Left + biko[0]->Width + 3;
	}else{
		for (int i = 1; i < limit_line_ + 1; i++)
			biko[i]->Visible = false;
	}
	MeisaiScrollBox2->HorzScrollBar->Position = 0;
}
//---------------------------------------------------------------------------
// MainForm->OnClose
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete delete_id_list_;

	try{
		if (MainForm->WindowState == wsMaximized)
			DM->INI.SaveSingle("Form", "Maximized", 1);
		else
			DM->INI.SaveSingle("Form", "Maximized", 0);
	}catch (...){}
}
//---------------------------------------------------------------------------
// �\�P�b�g�̐ؒf���Ď�
void __fastcall TMainForm::SocketReopenTimerTimer(TObject *Sender)
{
	if (ClientSocket->Active)
		return;

	try{
		// [INI] Weighing::WIPort
		ClientSocket->Port = ToInt(DM->INI["Weighing::WIPort"]);
		// [INI] Weighing::WIServer
        ClientSocket->Host = ToString(DM->INI["Weighing::WIServer"]);

        ClientSocket->Open();
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
    return cur_weight_;
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
    KeiryoTimePicker->Time    = now;
    KeiryoNoEdit->Text        = AnsiString();
    ShabanEdit->Text          = AnsiString();
    ShabanEdit->OnChange(NULL);
    TokuCodeEdit->Text        = AnsiString();
	TokuNameEdit->Text        = AnsiString();
	Komoku1CodeEdit->Text     = AnsiString();
	Komoku1NameEdit->Text     = AnsiString();
	Komoku2CodeEdit->Text     = AnsiString();
	Komoku2NameEdit->Text     = AnsiString();
    //�����R���{d
	HannyuCombo->ItemIndex    = -1;
	BikoEdit->Text            = AnsiString();

	// ���׃O���b�h
	for (int i = 1; i < limit_line_ + 1; i++){
		hincode[i]->Text = AnsiString();
		hinname[i]->Text = AnsiString();
		weight1[i]->Text = AnsiString();
		weight2[i]->Text = AnsiString();
		choritu[i]->Text = AnsiString();
		choweight[i]->Text = AnsiString();
		bikiweight[i]->Text = AnsiString();
		shomi[i]->Text = AnsiString();
		suryo[i]->Text = AnsiString();
		tanicode[i]->Text = AnsiString();
		taniname[i]->Text = AnsiString();
		tanka[i]->Text = AnsiString();
		kingaku[i]->Text = AnsiString();
        shouhi[i]->Text  = AnsiString();
		biko[i]->Text = AnsiString();
        tanka[i]->Color = clWindow;
		StringGridID->Cells[0][i] = AnsiString();
	}
	ShomiSumEdit->Text = AnsiString();
	KingakuSumEdit->Text = AnsiString();
	ShohizeiEdit->Text = AnsiString();
	ZeikomiEdit->Text = AnsiString();
	max_line_ = 1;
	MeisaiScrollBox2->HorzScrollBar->Position = 0;
	keiryo_kaisu_ = 0;

	// �����N���A
	SetRireki(0);
    //�����d�ʃN���A
    shomi_total_ = 0;
    //���z(�Ŕ���)�N���A
    kingaku_total_ = 0;
    //�Ŋz
    tax_total_ = 0;
}
//---------------------------------------------------------------------------
// �v��ID ���烌�R�[�h����ǂݍ���
bool __fastcall TMainForm::LoadFromID(int id)
{
	AnsiString sql;
	sql = " SELECT * FROM V_�v��"
		  " WHERE"
		  "		�v�ʓ� IN ( SELECT �v�ʓ� FROM D_�v�� WHERE �v��ID = " + IntToStr(id) + ") "
		  " AND"
		  "		���_ID IN ( SELECT ���_ID FROM D_�v�� WHERE �v��ID = " + IntToStr(id) + ") "
		  " AND"
		  "     �`�[No IN ( SELECT �`�[No FROM D_�v�� WHERE �v��ID = " + IntToStr(id) + ") "
		  " AND"
		  "     �����敪 <> 9"                 // �_���폜�͑ΏۊO
          " ORDER BY"
          "     �v�ʓ�, �`�[No, �sNo";

	if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
		return false;

	KeiryoDatePicker->Date       = IntToDate(ToInt(SET_TOP(keiryo_set_)["�v�ʓ�"]));
	PlaceCombo->ItemIndex        = DM->FindPlaceIndexByID(ToInt(SET_TOP(keiryo_set_)["���_ID"]));
	KeiryoNoEdit->Text           = ToInt(SET_TOP(keiryo_set_)["�`�[No"]);

    // �����f�[�^�ȊO�͍��̎��Ԃ�\��
    if (ToInt(SET_TOP(keiryo_set_)["�����敪"]) == 1)
        KeiryoTimePicker->Time = GetLastKeiryoTime(DateToInt(KeiryoDatePicker->Date), StrToInt(KeiryoNoEdit->Text), ToInt(SET_TOP(keiryo_set_)["���_ID"]));
        //KeiryoTimePicker->Time = ToInt(SET_TOP(keiryo_set_)["�v�ʎ���"]);
    else
        KeiryoTimePicker->Time = Now();

	car_id_                      = ToInt(SET_TOP(keiryo_set_)["�ԗ�ID"]);
	ShabanEdit->Text             = ToInt(SET_TOP(keiryo_set_)["�Ԕ�"]);
	SharyoNameEdit->Text         = ToString(SET_TOP(keiryo_set_)["�ԗ�����"]);

	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["���Ӑ�R�[�h"]));
	TokuNameEdit->Text           = ToString(SET_TOP(keiryo_set_)["���Ӑ於��"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����1�R�[�h"]));
	Komoku1NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["����1����"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����2�R�[�h"]));
	Komoku2NameEdit->Text        = ToString(SET_TOP(keiryo_set_)["����2����"]);
    BikoEdit->Text               = ToString(SET_TOP(keiryo_set_)["���l"]);

    //20160624 �������ǉ�
    HannyuCombo->ItemIndex       = ToInt(SET_TOP(keiryo_set_)["�����o�敪"]) - 1;

	ShohizeiEdit->Text = ToCurrency(SET_TOP(keiryo_set_)["�`�[����Ŋz"]);

	// ����
	for (unsigned int i = 0; i < keiryo_set_.size(); i++){
		hincode[i+1]->Text    = ToInt(keiryo_set_[i]["�i�ڃR�[�h"]);
		hinname[i+1]->Text    = ToString(keiryo_set_[i]["�i�ږ���"]);
		weight1[i+1]->Text    = ZeroSuppress(ToCurrency(keiryo_set_[i]["1��ڏd��"]));
		weight2[i+1]->Text    = ZeroSuppress(ToCurrency(keiryo_set_[i]["2��ڏd��"]));
		choritu[i+1]->Text    = FormatFloat("#.##%", ToCurrency(keiryo_set_[i]["������"]));
		choweight[i+1]->Text  = ZeroSuppress(ToCurrency(keiryo_set_[i]["�����d��"]));
		bikiweight[i+1]->Text = ZeroSuppress(ToCurrency(keiryo_set_[i]["�d�ʈ���"]));
		shomi[i+1]->Text      = ZeroSuppress(ToCurrency(keiryo_set_[i]["�����d��"]));
		suryo[i+1]->Text      = ZeroSuppress(ToCurrency(keiryo_set_[i]["����"]));
		tanicode[i+1]->Text   = ZeroSuppress(ToCurrency(keiryo_set_[i]["�P�ʃR�[�h"]));
		taniname[i+1]->Text   = ToString(keiryo_set_[i]["�P�ʃ}�X�^����"]);
		tanka[i+1]->Text      = ZeroSuppress(ToCurrency(keiryo_set_[i]["�P��"]));
        biko[i+1]->Text       = ToString(keiryo_set_[i]["���ה��l"]);
        // �P����"NULL"�̂Ƃ��̓Z����0�\��
        if (tanka[i+1]->Text == ""){
            tanka[i+1]->Text = "0";
        }
        TankaCheck(i+1);
		kingaku[i+1]->Text    = ZeroSuppress(ToCurrency(keiryo_set_[i]["���z"]));
        // ���z��"NULL"�̂Ƃ��̓Z����0�\��
        if (kingaku[i+1]->Text == ""){
            kingaku[i+1]->Text = "0";
        }
        shouhi[i+1]->Text     = ZeroSuppress(ToCurrency(keiryo_set_[i]["����Ŋz"]));
		biko[i+1]->Text       = ToString(keiryo_set_[i]["���ה��l"]);
		StringGridID->Cells[0][i+1] = ToString(keiryo_set_[i]["�v��ID"]);

		if (ToCurrency(keiryo_set_[i]["2��ڏd��"]) == 0)
			keiryo_kaisu_ = i + 1;
		else
			keiryo_kaisu_ = i + 2;

        //���z�v(�ŕ�) �v�Z
//        kingaku_total_ += ToInt(keiryo_set_[i]["���z"]);
	}
	max_line_ = keiryo_set_.size();

	// ����\��
	SetRireki(car_id_);

    //�ŕʋ��z�\��
//    KingakuSumEdit->Text = IntToStr(kingaku_total_);
    CalcKingaku();
    //����ŕ\��
    CalcSalesTax();
    //�����d�ʍ��v
    CalcShomiTotal();

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
//	ShabanEdit->SetFocus();

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

	int mei_cnt = keiryo_set_.size();
	if (mei_cnt == 1 && StrToCurrDef(weight2[mei_cnt]->Text, 0) == 0){
		weight2[mei_cnt]->Text = cur_weight_;
        weight2[mei_cnt]->SetFocus();
	}else{
        //���s��
        mei_cnt += 1;
	}

    if (mei_cnt != 1)
        CalcWeight();
/*
    20160519
    ���lEdit��keydownEvent�Ɉړ�����
	Action10->OnExecute(NULL);
*/
/*
*/
	if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
		TokuCodeEdit->SetFocus();
	else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
		Komoku1CodeEdit->SetFocus();
	else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
		Komoku2CodeEdit->SetFocus();
    else if (mei_cnt == 1){     //1���זڂ�2��ڏd�ʐ�p
        weight2[mei_cnt]->SetFocus();
    }else{
        hincode[mei_cnt]->SetFocus();
        Action10->Execute();
    }

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

	bool comp;
	int  value;

	// �o�^���閾�׍s���ő�s�����`�F�b�N
	PostConfForm->ButtonKeizoku->Enabled = true;
    max_line_ = keiryo_set_.size();

    if (GetRowNo() == 6){
        max_line_ = 6;
    }

    int row_no = GetRowNo();


	if (max_line_ == 6)
		PostConfForm->ButtonKeizoku->Enabled = false;

	value = PostConfForm->ShowModal();
	if (value == IDYES)     // �����{�^��
		comp = true;
	else if (value == IDNO){ // �p���{�^��
        comp = false;
        ShudoCheckBox->Checked = false;
    }else                    // �L�����Z���{�^��
        return;

    // �蓮���͎��̂� �d�ʍČv�Z���s��
    if (ShudoCheckBox->Checked){
        RecalcButton->Click();
    }


	int toku_id, hin_id, item1_id, item2_id;
	AnsiString toku_name, hin_name, item1_name, item2_name;
	int zei_hasu;

	toku_id    = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
	toku_name  = TokuNameEdit->Text;
	//hin_id     = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i��ID"));
	//hin_name   = HinNameEdit->Text;
	item1_id   = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
	item1_name = Komoku1NameEdit->Text;
	item2_id   = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
	item2_name = Komoku2NameEdit->Text;

	zei_hasu   = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0), "����Œ[�������敪"));
	if (zei_hasu)
		zei_hasu = ToInt(DM->CFG["����Œ[�������敪"]);
	Currency zeiritu = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date)); // ����ŗ��擾

	int kyoten_id = GetPlaceID();
    TDateTime old_second_time; //�O�̖��ׂ̌v�ʎ���2

	NsFieldSet keys, fields;

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
		car_id_ = DM->DBI.GetLastID();
	}
try{

	DM->ADOConnection->BeginTrans();

	if (comp && mode != imMod){		// �����o�^�ŏC�����[�h����Ȃ��ꍇ
		KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
	}else if (mode == imFirst){		// �ؗ��o�^
		KeiryoNoEdit->Text = DM->GetTempNo(GetPlaceID());
	}

	// ���דo�^
	for (int i = 1; i < limit_line_ + 1; i++){
    /*
		if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
			continue;
    */
        if (i > 1 && hincode[i]->Text.IsEmpty())
            continue;

        //�sNo 20160525
        now = Now();
		hin_id   = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hincode[i]->Text.ToIntDef(0), "�i��ID"));
		hin_name = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hincode[i]->Text.ToIntDef(0), "�i�ږ���"));

		keys.clear();
		fields.clear();


		keys << NsField("[�v��ID]", StringGridID->Cells[0][i].ToIntDef(0));

		fields
			<< NsField("[�v�ʓ�]",       DateToInt(KeiryoDatePicker->Date))
			<< NsField("[���_ID]",       kyoten_id)
			<< NsField("[�`�[No]",       StrToCurrDef(KeiryoNoEdit->Text, 0))
			<< NsField("[�ԗ�ID]",       car_id_)
			<< NsField("[���Ӑ�ID]",     toku_id)
			<< NsField("[���Ӑ於��]",   toku_name)
			<< NsField("[����1ID]",      item1_id)
			<< NsField("[����1����]",    item1_name)
			<< NsField("[����2ID]",      item2_id)
			<< NsField("[����2����]",    item2_name)
			<< NsField("[���l]",         BikoEdit->Text)
            //20160607
			//<< NsField("[�`�[����Ŋz]", ExtendedRound(StrToCurrDef(KingakuSumEdit->Text, 0) * zeiritu, 0, zei_hasu))
            << NsField("[�`�[����Ŋz]", slip_tax_)

			<< NsField("[�sNo]",         i)
			<< NsField("[�i��ID]",       hin_id)
			<< NsField("[�i�ږ���]",     hin_name)
			<< NsField("[1��ڏd��]",    StrToCurrDef(weight1[i]->Text, 0))
			<< NsField("[2��ڏd��]",    StrToCurrDef(weight2[i]->Text, 0))
			<< NsField("[������]",       StrToCurrDef(AnsiReplaceStr(choritu[i]->Text, "%", ""), 0))
			<< NsField("[�����d��]",     StrToCurrDef(choweight[i]->Text, 0))
			<< NsField("[�d�ʈ���]",     StrToCurrDef(bikiweight[i]->Text, 0))
			<< NsField("[�����d��]",     StrToCurrDef(shomi[i]->Text, 0))
			<< NsField("[����]",         StrToCurrDef(suryo[i]->Text, 0))
			<< NsField("[�P��ID]",       ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tanicode[i]->Text.ToIntDef(0), "�P��ID")))
			<< NsField("[�P��]",         StrToCurrDef(tanka[i]->Text, 0))
			<< NsField("[���z]",         StrToCurrDef(kingaku[i]->Text, 0))
			//<< NsField("[����Ŋz]",     ExtendedRound(StrToCurrDef(kingaku[i]->Text, 0) * zeiritu, 0, zei_hasu))
            << NsField("[����Ŋz]",     StrToCurrDef(shouhi[i]->Text, 0))
			<< NsField("[���ה��l]",     biko[i]->Text)
			<< NsField("[�����敪]",     comp ? 1 : 0)
			<< NsField("[�X�V����]",     now)
			//<< NsField("[�쐬����]",  )
			;

		// ����}�X�^::���o�Ɏg�p�敪
		if (ToBit(DM->CFG["���o�Ɏg�p�敪"]))
			fields << NsField("[�����o�敪]", HannyuCombo->ItemIndex + 1);
		else
			fields << NsField("[�����o�敪]", 1);

        //�v��ID�擾
        NsRecordSet set;
        AnsiString sql;
        //���ԃe�X�g�ϐ�
        int new_int_time;

        //�v��ID
        int chk_keiryoID = StringGridID->Cells[0][i].ToIntDef(0);

        sql =   " SELECT"
                "       *"
                " FROM"
                "       D_�v��"
                " WHERE"
                "   �v��ID = " + IntToStr(chk_keiryoID);

        if (ShudoCheckBox->Checked){
            now = KeiryoTimePicker->Time;
        }


        if(DM->DBI.GetRecordSet(sql, set)){
            if (ToString(SET_TOP(set)["�v�ʓ���2"]) == ""){
                old_second_time = now;
            }else{
                old_second_time = ToString(SET_TOP(set)["�v�ʓ���2"]);
            }
        }

        if (mode == imFirst){
            if(!comp){
                fields  <<  NsField("[�v�ʓ���1]", now);

                //2��ڏd�ʂ�0�ȊO�Ȃ�o�^����
                if (StrToCurrDef(weight2[i]->Text, 0) != 0){
                    fields  <<  NsField("[�v�ʓ���2]", now);
                }
            }else{ // �S�o�^
                fields  <<  NsField("[�v�ʓ���1]", now)
                        <<  NsField("[�v�ʓ���2]", now);
            }
        }else if(mode == imSecond){
            //�v��ID == 0 ����1,����2��o�^
            if(chk_keiryoID == 0){
                fields  <<  NsField("[�v�ʓ���1]", old_second_time)
                        <<  NsField("[�v�ʓ���2]", now);
            }

            // �v��ID != 0
            if (chk_keiryoID != 0){
                if (i == 1 && StrToCurrDef(weight2[i]->Text, 0) != 0){
                    if(hincode[2]->Text == ""){
                        fields  <<  NsField("[�v�ʓ���2]", GetTimePicker_ZeroSec());
                        //old_second_time = now;
                        old_second_time = GetTimePicker_ZeroSec();
                    }
                }
            }

        }else if (mode == imMod){
            // �C�����[�h�ŐV���ɍ쐬�����s�̏���
            if (chk_keiryoID == 0){
                if (max_line_ == i){
                    fields  <<  NsField("[�v�ʓ���2]", GetTimePicker_ZeroSec());
                }else{
                    fields  <<  NsField("�v�ʓ���2", now);
                }
            }

            // �Ō�̖��׃f�[�^�̌v�ʎ���2�Ɉ󎚌v�ʎ��Ԃ��㏑������
            if (chk_keiryoID != 0 && max_line_ == i){
                fields  <<  NsField("[�v�ʓ���2]", GetTimePicker_ZeroSec());
            }
        }else{
            return;
        }

//		if (!DM->DBI.IsExist("D_�v��", keys)){
		if (!chk_keiryoID || !DM->DBI.IsExist("D_�v��", keys)){
			fields << NsField("[�쐬����]",  now);
			DM->DBI.Insert("D_�v��", fields);
            //����p
            keiryo_id_ = DM->DBI.GetLastID();
		}else
			DM->DBI.Update("D_�v��", keys, fields);
	}


	int cmp_kbn;
	bool print = false;                 // ������邩�ǂ����idef: false�j
	bool create_tran_data = true;      // ����f�[�^���쐬���邩�ǂ����idef: false�j

	if (comp){
		StatusBar->Panels->Items[0]->Text = "�o�^���܂��� (�v�ʓ�=" + DateToStr(KeiryoDatePicker->Date) + " No=" + KeiryoNoEdit->Text + ")";

		if (AutoPrintCheck->Checked && mode != imMod)
			print = true;

	}else{
		StatusBar->Panels->Items[0]->Text = "�ؗ��Ԃ�o�^���܂��� (�Ԕ�=" + ShabanEdit->Text + ")";
        //������̏C������ؗ��֖߂����Ƃ��ɘA���o�^��h������
        SetMode(imSecond);
        mode = GetMode();
	}

    if (mode == imMod){
        if(Application->MessageBox("�C�������`�[�𔭍s���܂���?", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES){
            print = true;
        }
    }


	if (!DataDeleteCheck->Checked)
    	create_tran_data = ToInt(DM->CFG["����f�[�^�쐬"]) ? true : false;

    //�f�[�^���c���Ȃ�
    if (GetMode() != imMod && DataDeleteCheck->Checked){
        create_tran_data = false;
    }

	if (create_tran_data){
		//////////////////////////////////////////////////////////////////////
		// ����f�[�^

		std::auto_ptr<TStringList> gyo_no_list(new TStringList());

		NsRecordSet set;
		AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID IN ( "
									"SELECT �v��ID FROM D_�v�� "
									"WHERE �v�ʓ� = " + IntToStr(DateToInt(KeiryoDatePicker->Date)) + " "
									"AND   ���_ID = " + IntToStr(kyoten_id) + " "
									"AND   �`�[No = " + CurrToStr(StrToCurrDef(KeiryoNoEdit->Text, 0)) + ") "
                                    "ORDER BY �v�ʓ�,���_ID, �`�[No, �sNo";
		DM->DBI.GetRecordSet(sql, set);

        int slip_no = DM->GetTransNo(ToInt(SET_TOP(set)["���_ID"]), ToInt(SET_TOP(set)["�v�ʓ�"]));
        if (DM->DBI.IsExist("D_���", "�v��ID", ToInt(SET_TOP(set)["�v��ID"])))
            slip_no = ToInt(DM->DBI.Lookup("D_���", "�v��ID", ToInt(SET_TOP(set)["�v��ID"]), "�`�[No"));
        else
            slip_no = DM->GetTransNo(ToInt(SET_TOP(set)["���_ID"]), ToInt(SET_TOP(set)["�v�ʓ�"]));

		for (unsigned int i = 0; i < set.size(); i++){
			keys.clear();
			keys	<< NsField("[�v��ID]",       ToInt(set[i]["�v��ID"]));

			fields.clear();
			fields	<< NsField("[�����]",       ToInt(set[i]["�v�ʓ�"]))
					<< NsField("[���_ID]",       ToInt(set[i]["���_ID"]))
                    << NsField("[�`�[No]",       slip_no)
					<< NsField("[�v��ID]",       ToInt(set[i]["�v��ID"]))
					<< NsField("[����敪]",     ToInt(set[i]["����敪"]))
					<< NsField("[�ԗ�ID]",       ToInt(set[i]["�ԗ�ID"]))
					<< NsField("[���Ӑ�ID]",     ToInt(set[i]["���Ӑ�ID"]))
					<< NsField("[���Ӑ於��]",   ToString(set[i]["���Ӑ於��"]))
					<< NsField("[����1ID]",      ToInt(set[i]["����1ID"]))
					<< NsField("[����1����]",    ToString(set[i]["����1����"]))
					<< NsField("[����2ID]",      ToInt(set[i]["����2ID"]))
					<< NsField("[����2����]",    ToString(set[i]["����2����"]))
					<< NsField("[���l]",         ToString(set[i]["���l"]))
					<< NsField("[�`�[����Ŋz]", ToCurrency(set[i]["�`�[����Ŋz"]))
					<< NsField("[�sNo]",         ToInt(set[i]["�sNo"]))
					<< NsField("[�i��ID]",       ToInt(set[i]["�i��ID"]))
					<< NsField("[�i�ږ���]",     ToString(set[i]["�i�ږ���"]))
					<< NsField("[����]",         ToCurrency(set[i]["����"]))
					<< NsField("[�P��ID]",       ToInt(set[i]["�P��ID"]))
					<< NsField("[�P��]",         ToCurrency(set[i]["�P��"]))
					<< NsField("[���z]",         ToCurrency(set[i]["���z"]))
					<< NsField("[����Ŋz]",     ToCurrency(set[i]["����Ŋz"]))
					<< NsField("[���ה��l]",     ToString(set[i]["���ה��l"]))
					<< NsField("[�����敪]",     1)
					<< NsField("[�X�V����]",     now)
					;
			if (!DM->DBI.IsExist("D_���", keys)){
				fields << NsField("[�쐬����]",  now);
				DM->DBI.Insert("D_���", fields);
			}else{
				DM->DBI.Update("D_���", keys, fields);
			}
			gyo_no_list->Add(ToString(set[i]["�sNo"]));
		}

        if (keiryo_id_ == 0){
            keiryo_id_ = ToInt(SET_TOP(set)["�v��ID"]);
        }
	}

	DM->ADOConnection->CommitTrans();


	// �����`�[���s
	if (print){
        Print(keiryo_id_);
    }

}catch (Exception& e){
	DM->ADOConnection->RollbackTrans();
	AnsiString msg = "�o�^���ɃG���[���������܂��� - " + e.Message;
	Application->MessageBox(msg.c_str(), "�o�^�G���[", MB_OK | MB_ICONWARNING);
	return;
}

    //"�f�[�^���c���Ȃ�"�p��if����ǉ�
    if (!DataDeleteCheck->Checked){
        Application->MessageBox("�o�^���������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    }

	Q_Tairyu->Close();
	Q_Tairyu->Open();

    if(mode != imMod)
        Action1->Execute();
    else{
        //LoadFromID(keiryo_id_);
        int date = DateToInt(KeiryoDatePicker->Date);
        int kyo  = GetPlaceID();
        int denpyo  = KeiryoNoEdit->Text.ToIntDef(0);

        NsRecordSet set;
        AnsiString sql;
        sql =  " SELECT �v��ID FROM D_�v��"
               " WHERE  �v�ʓ� = " + IntToStr(date) + " AND ���_ID = " + IntToStr(kyo) +
               " AND    �`�[No = " + IntToStr(denpyo);

        DM->DBI.GetRecordSet(sql, set);
        keiryo_id_ = SET_TOP(set)["�v��ID"];
        //ClearForm();
        LoadFromID(keiryo_id_);
    }
}
//---------------------------------------------------------------------------
// �`�[���s
void __fastcall TMainForm::Print(int keiryo_id)
{
	int slip_type = ToInt(DM->CFG["�`�[���s�v�����^"]);

	if (slip_type == 1){
		// ���[�U�[
/*
		if (!LaserSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
			return;
*/
        //20160519
        int slip_info_id = DM->GetPrintInfo(keiryo_id);
        NsRecordSet set;
        if (!DM->DBI.GetRecordSet("SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(slip_info_id), set)){
            // �`�[���}�X�^���Ȃ��ꍇ�́A���z�󎚂Ȃ�
            if (LaserSlipPrintM_KakeForm->Print(keiryo_id, HideTimeCheck->Checked))
                return;
        }


        // �`�[���}�X�^�̋��z�󎚋敪���S��false����������z�g�����̃t�H�[���ň�
        if (!ToBit(SET_TOP(set)["���z�󎚋敪1"]) && !ToBit(SET_TOP(set)["���z�󎚋敪2"])
                && !ToBit(SET_TOP(set)["���z�󎚋敪3"])){
            if (LaserSlipPrintM_KakeForm->Print(keiryo_id, HideTimeCheck->Checked))
                if(!DataDeleteCheck->Checked)
                    return;
        }else{
            if (LaserSlipPrintM_GenkinForm->Print(keiryo_id, HideTimeCheck->Checked))
                if(!DataDeleteCheck->Checked)
                    return;
        }


	}else if (slip_type == 2){
		// �h�b�g

		if (!DotSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
            if(!DataDeleteCheck->Checked)
    			return;

    }else{
        // nothing to do
    }

    if (GetMode() != imMod && DataDeleteCheck->Checked){
        NsRecordSet set;
        AnsiString sql;
        int date, place_id, slip_no;

        if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id), set)){
            Application->MessageBox("�f�[�^�Ăяo���Ɏ��s���܂���\r\n�蓮�Ńf�[�^���폜���Ă�������", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }

        date        =   ToInt(SET_TOP(set)["�v�ʓ�"]);
        place_id    =   ToInt(SET_TOP(set)["���_ID"]);
        slip_no     =   ToInt(SET_TOP(set)["�`�[No"]);

        sql =   " DELETE"
                "       FROM D_�v��"
                " WHERE"
                "       �v�ʓ� = " + IntToStr(date) +
                " AND"
                "       ���_ID = " + IntToStr(place_id) +
                " AND"
                "       �`�[No = " + IntToStr(slip_no);

        try{
            DM->ADOConnection->BeginTrans();

            DM->DBI.Execute(sql);

            DM->ADOConnection->CommitTrans();

        }catch(Exception& e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox("�f�[�^�폜�Ɏ��s���܂���\r\n�蓮�Ńf�[�^���폜���Ă�������", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
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
	Currency max = 0;
	for (int i = 1; i < limit_line_ + 1; i++){
		if (StrToCurrDef(weight1[i]->Text, 0) > max)
			max = StrToCurrDef(weight1[i]->Text, 0);
		if (StrToCurrDef(weight2[i]->Text, 0) > max)
			max = StrToCurrDef(weight2[i]->Text, 0);
	}

	AnsiString msg;

	if (gross_limit_ > 0 && max > gross_limit_){
		msg = "�ԗ����d�ʂɑ΂���ߐύڂł�\r\n\r\n"
			  "���݂̏d��: " + FormatFloat("###,##0.#' kg'", max) + "\r\n"
			  "�ԗ����d��: " + FormatFloat("###,##0.#' kg'", gross_limit_);
		Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
/*
	if (net > 0 && net_limit_ > 0 && net > net_limit_){
		msg = "�ő�ύڗʂɑ΂���ߐύڂł�\r\n\r\n"
			  "���݂̏d��: " + FormatFloat("###,##0.#' kg'", net) + "\r\n"
			  "�ő�ύڗ�: " + FormatFloat("###,##0.#' kg'", net_limit_);
		Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
*/
    return true;
}
//---------------------------------------------------------------------------
// ���ʓ��Z�o�ɕK�v�ȏ����擾
void __fastcall TMainForm::GetCalcInfo()
{
/*
	if (GetMode() == imMod)
		return;

	int meig_id  = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i��ID"));

	TaniCodeEdit->Text = DM->GetKanzanCode(toku_id_, meig_id);
*/
}
//---------------------------------------------------------------------------
// �����d�ʂ̌v�Z
void __fastcall TMainForm::CalcWeight(int row)
{
	if (row == 9)
		row = GetRowNo();
	if (row == 0)
		return;

	Currency w1, w2, net;

	w1 = StrToCurrDef(weight1[row]->Text, 0);
	w2 = StrToCurrDef(weight2[row]->Text, 0);

	if (w1 >= w2)
		net = w1 - w2;
	else
		net = w2 - w1;

	if (ToBit(DM->CFG["�����g�p�敪"])){
		Currency coord, coord_ratio;
		coord       = StrToCurrDef(choweight[row]->Text, 0);

		coord_ratio = StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0) / 100;

		if (coord_ratio > 0){       // �������g�p
			coord = ExtendedRound(net * coord_ratio, ToInt(DM->CFG["�����[����������"]), ToInt(DM->CFG["�����[�������敪"]));
			choweight[row]->Text = coord;
		}else{
			coord = 0;
			//choweight[row]->Text = coord;
            //0��������󔒂�
		}

		net -= int(coord);
	}

	if (ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
		Currency reduc = StrToCurrDef(bikiweight[row]->Text, 0);
		net -= reduc;
	}

	shomi[row]->Text = net;

    //  �f�t�H���g�̒P�ʂ��w�� kg
	if (tanicode[row]->Text.IsEmpty()){
		int default_code = ToInt(DM->CFG["�W���P��"]);
		if (!default_code)
			default_code = 3;
		tanicode[row]->Text = default_code;
        taniname[row]->Text = DM->DBI.Lookup("M_�P��","�P�ʃR�[�h", default_code, "�P�ʖ���");
	}

	int meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h", hincode[row]->Text.ToIntDef(0), "�i��ID"));
	//int item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
	//int item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
	int tani_id  = ToInt(DM->DBI.Lookup("M_�P��",   "�P�ʃR�[�h", tanicode[row]->Text.ToIntDef(0), "�P��ID"));

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

	if (cnv_ratio == 0)
		quantity = ExtendedRound(net,             ToInt(DM->CFG["���Z�[����������"]), cnv_div);
	else
		quantity = ExtendedRound(net / cnv_ratio, ToInt(DM->CFG["���Z�[����������"]), cnv_div);

	if (quantity > ToCurrency(DM->CFG["���m3����"]) && tanicode[row]->Text.ToIntDef(0) == 2)
		quantity = ToCurrency(DM->CFG["���m3����"]);

	suryo[row]->Text = quantity;

	CalcAmount();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AnbunAfterChousei(int row)
{
    if (row == 9)
        row = GetRowNo();
    if (row == 0)
        return;

    Currency net = ToCurrency(shomi[row]->Text);

    //�f�t�H���g�̒P�ʂ��w��
    if (tanicode[row]->Text.IsEmpty()){
        int default_code = ToInt(DM->CFG["�W���P��"]);
        if (!default_code) 
            default_code = 3;
            tanicode[row]->Text = default_code;
            taniname[row]->Text = DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h",default_code, "�P�ʖ���");
    }

    //�i��ID���擾
    int meig_id = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hincode[row]->Text.ToIntDef(0),"�i��ID"));
    int tani_id = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tanicode[row]->Text.ToIntDef(0),"�P��ID"));

    if (tani_id == 3)
        net = StrToCurrDef(net, 0);
    else    
        net = Currency(net) / Currency(1000);

    Currency quantity;
    Currency cnv_ratio = DM->GetKanzan(toku_id_, meig_id, tani_id);

    // ���Z�[�������敪�̎擾
    int cnv_div = -1;

    if (!toku_rec_.empty()) {
        if (!IsNull(toku_rec_["���Z�[�������敪"]))
            cnv_div = ToInt(toku_rec_["���Z�[�������敪"]);
    }

    if (cnv_div == -1)
        cnv_div = ToInt(DM->CFG["���Z�[�������敪"]);
    if (cnv_ratio == 0)
        quantity = ExtendedRound(net,ToInt(DM->CFG["���Z�[����������"]), cnv_div);
    else
        quantity = ExtendedRound(net / cnv_ratio, ToInt(DM->CFG["���Z�[����������"]),cnv_div);

    if (quantity > ToCurrency(DM->CFG["���m3����"]) && tanicode[row]->Text.ToIntDef(0) == 2)
        quantity = ToCurrency(DM->CFG["���m3����"]);

    suryo[row]->Text = quantity;

}
//---------------------------------------------------------------------------
// �P���𒲂ׂĕԂ� 20160627
void __fastcall TMainForm::CallTanka()
{

/*    int row = GetRowNo();

    if (row != 0){

        int meig_id     = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hincode[row]->Text.ToIntDef(0), "�i��ID"));
        int item1_id    = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
        int item2_id    = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
        int tani_id     = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tanicode[row]->Text.ToIntDef(0), "�P��ID"));

        Currency quantity   = StrToCurrDef(suryo[row]->Text, 0);

        if (!ToBit(DM->CFG["�P���g�p�敪"])){
            return;
        }

        Currency tankacode  =   StrToCurrDef(tanka[row]->Text, 0);
        Currency deftanka   =   DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);

        //�W���P���ƈقȂ鐔�l�Ȃ�Ԃɂ���
        //tanka[row]->Color   =   tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

        if (tankacode == deftanka){
            tanka[row]->Color = TColor(0x00BEF4F5);
        }else{
            tanka[row]->Color = TColor(0x008080FF);
        }

        tanka[row]->Text    =   deftanka;
    }


*/

}
//---------------------------------------------------------------------------
// ���ʂƋ��z�̌v�Z
void __fastcall TMainForm::CalcAmount(bool update)
{
    int row = GetRowNo();

    if (row != 0){

        int meig_id  = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hincode[row]->Text.ToIntDef(0), "�i��ID"));
        int item1_id = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
        int item2_id = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
        int tani_id  = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tanicode[row]->Text.ToIntDef(0), "�P��ID"));

        Currency quantity = StrToCurrDef(suryo[row]->Text, 0);

        if (!ToBit(DM->CFG["�P���g�p�敪"])){

            return;
        }

	    Currency tankacode = StrToCurrDef(tanka[row]->Text, 0);
	    Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
        if (GetMode() != imMod && update){
            tankacode = deftanka;
        }

        int chk_keiryoID = StringGridID->Cells[0][row].ToIntDef(0);

        //�C�����[�h�ŐV�K���גǉ�����Ƃ�
        //if (GetMode() == imMod && chk_keiryoID == 0 && !chk_addflag_){
/*
        if (GetMode() == imMod && chk_keiryoID == 0     ){
            tankacode = deftanka;
        }
*/

        //�C�����[�h�Ŗ��ב}���ǉ�����Ƃ�
        if (GetMode() == imMod && tanka[row]->Text == 0){
            tankacode = deftanka;
        }

        tanka[row]->Color = tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

        // ���z�[�������敪�̎擾
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
        ////
        int amount = ExtendedRound(quantity * tankacode, amount_fig, amount_div);

        tanka[row]->Text   = tankacode;
        kingaku[row]->Text = amount;

        CalcSalesTax();

    }
}
//---------------------------------------------------------------------------
// ����ŎZ�o
void __fastcall TMainForm::CalcSalesTax()
{
    int row = GetRowNo();

    if (!ToBit(DM->CFG["�P���g�p�敪"])){
        return;
    }

	Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));  //�����

    int sum_money = 0;
    int sum_tax = 0;
    //// ����Œ[�������敪�̎擾
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
    ////

    int amount = 0 ;
    tax_total_ = 0;
    for (int i = 1; i < 7; i++){
        if (kingaku[i]->Text == ""){
            continue;
        }

        amount       = StrToIntDef(kingaku[i]->Text, 0);
        tax_total_   = int(ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div));

        if (shouhi[0]->Visible == true){
            shouhi[i]->Text = IntToStr(tax_total_);
        }
    }

    GetTotalMoney();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetTotalMoney()
{
    if (!ToBit(DM->CFG["�P���g�p�敪"]))
        return;

    int sum_money, sum_tax;
    sum_money = 0;
    sum_tax   = 0;
    slip_tax_ = 0;

    for (int i = 1; i <= limit_line_; i++){
        if (kingaku[i]->Text == "")
            continue;
        sum_money += kingaku[i]->Text.ToIntDef(0);
    }

    //�`�[���Ƃ̏���
    if (ToString(DM->CFG["���i������Ōv�Z�敪"]).ToIntDef(1) == 1){
		Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));
        ////����ŏ����敪�̎擾
        int tax_div = -1;
        if (!toku_rec_.empty())
            if(IsNull(toku_rec_["����Œ[�������敪"]))
                tax_div = ToInt(toku_rec_["����Œ[�������敪"]);
        if (tax_div == -1)
            tax_div = ToInt(DM->CFG["����Œ[�������敪"]);

        // �`�[����ł̌v�Z
        sum_tax = ExtendedRound(Currency(sum_money) * tax_rate, 0, tax_div);
    }else{
        for (int i = 1; i <= limit_line_; i++){
            if(shouhi[i]->Text == "")
                continue;
            sum_tax += shouhi[i]->Text.ToIntDef(0);
        }
    }

    slip_tax_ = sum_tax;

    KingakuSumEdit->Text = FormatFloat("\\ #,##0", sum_money);
    ShohizeiEdit->Text   = FormatFloat("\\ #,##0", sum_tax);
    ZeikomiEdit->Text    = FormatFloat("\\ #,##0", sum_money + sum_tax);

    Currency chk_zei = StrToCurrDef(ShohizeiEdit->Text, 0);
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

	if (Application->MessageBox("���̓`�[���폜���܂����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
		return;

	try{
		DM->ADOConnection->BeginTrans();

		NsFieldSet fields, keys;
		fields << NsField("[�`�[No]",   DM->GetTempNo(GetPlaceID()))
			   << NsField("[�����敪]", 9);

		NsRecordSet set;
		if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id_), set)){
			Application->MessageBox("�폜�f�[�^�̒��o�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
			return;
		}
		keys	<< NsField("[�v�ʓ�]", ToInt(set[0]["�v�ʓ�"]))
				<< NsField("[�`�[No]", ToInt(set[0]["�`�[No"]))
				<< NsField("[���_ID]", ToInt(SET_TOP(set)["���_ID"]));

		DM->DBI.Update("D_�v��", keys, fields);

		///// ����f�[�^��������
		fields.clear();
		keys.clear();

		fields	<< NsField("[�`�[No]",   DM->GetTransTempNo(GetPlaceID()))
				<< NsField("[�����敪]", 9);

		set.clear();
		if (DM->DBI.GetRecordSet("SELECT * FROM D_��� WHERE �v��ID = " + IntToStr(keiryo_id_), set)){
			keys	<< NsField("[�����]", ToInt(set[0]["�����"]))
					<< NsField("[�`�[No]", ToInt(set[0]["�`�[No"]))
					<< NsField("[���_ID]", ToInt(SET_TOP(set)["���_ID"]));
	//		keys	<< NsField("[�v��ID]",   keiryo_id_);
			DM->DBI.Update("D_���", keys, fields);
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
	}else if (ActiveControl == Komoku1CodeEdit){
		Komoku1Button->Click();
	}else if (ActiveControl == Komoku2CodeEdit){
		Komoku2Button->Click();
	}else if (ActiveControl == hincode[GetRowNo()]){
        GetHinmoku();
		//HinNameTitleEdit->OnClick(NULL);
	//}else if (ActiveControl == TaniCodeEdit){
        //TaniButton->Click();
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
    if (ActiveControl == ShabanEdit || ActiveControl == TokuCodeEdit || ActiveControl == Komoku1CodeEdit || ActiveControl == Komoku2CodeEdit || ActiveControl == BikoEdit)
        return;

    int row = GetRowNo();
	InputMode mode = GetMode();
    if (mode == imFirst){
		weight1[1]->Text = cur_weight_;
		weight1[1]->SetFocus();
	}else if (ActiveControl == weight2[cur_w2_row_] && weight1[cur_w2_row_]->Text == weight2[cur_w2_row_]->Text){
        weight2[cur_w2_row_]->Text = cur_weight_;
        weight2[cur_w2_row_]->SetFocus();

    }else{
        // 20160610
        //
        if (keiryo_kaisu_ > 1 && shomi[1]->Text == ""){
            //weight2[1]->Text = cur_weight_;
            keiryo_kaisu_ = 1;
        }else{
		    weight2[keiryo_kaisu_]->Text = cur_weight_;
		    if (keiryo_kaisu_ > 1)
			    weight1[keiryo_kaisu_]->Text = weight2[keiryo_kaisu_ - 1]->Text;
        }
	}

	CalcWeight(keiryo_kaisu_);
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
    ////////////////////////////////
    //
/*
    WeightSumTitleLabel->Width  = int((MainForm->Width - interval * 4) / 12);
    ShomiSumEdit->Width         = int((MainForm->Width - interval * 4) / 12);
    KingakuSumTitleLabel->Width = int((MainForm->Width - interval * 4) / 12);
    KingakuSumEdit->Width       = int((MainForm->Width - interval * 4) / 12);
    ShohizeiTitleLabel->Width   = int((MainForm->Width - interval * 4) / 12);
    ShohizeiEdit->Width         = int((MainForm->Width - interval * 4) / 12);
*/
    WeightSumTitleLabel->Left   = 500;
    ShomiSumEdit->Left          = WeightSumTitleLabel->Left + WeightSumTitleLabel->Width - 1 + interval;
    KingakuSumTitleLabel->Left  = ShomiSumEdit->Left + ShomiSumEdit->Width - 1 + interval;
    KingakuSumEdit->Left        = KingakuSumTitleLabel->Left + KingakuSumTitleLabel->Width - 1 + interval;
    ShohizeiTitleLabel->Left    = KingakuSumEdit->Left + KingakuSumEdit->Width - 1 + interval;
    ShohizeiEdit->Left          = ShohizeiTitleLabel->Left + ShohizeiTitleLabel->Width - 1 + interval;
    ////////////////////////////////
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

    TairyuGrid->RowCount = int(TairyuGrid->Height / 61);

    // ���̃t�H�[���̃T�C�Y�����C���t�H�[���ɍ��킹��
    SearchForm->Height = MainForm->Height;
    DataListForm->Height = MainForm->Height - 33;
    DataListForm->Width  = MainForm->Width  - 24;
    DataListForm->Top  = MainForm->Top  + 16;
	DataListForm->Left = MainForm->Left + 12;

	MeisaiScrollBox2->Left = 426;
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
    AnsiString sql = "SELECT * FROM M_�ԗ� WHERE �Ԕ� = " + IntToStr(no);
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

    }

    ((TEdit *)Sender)->Color = clCream;

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


        id   = ToInt(SET_TOP(set)["����2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����2", "����2ID", id, "����2�R�[�h"));
        if (code)
            Komoku2CodeEdit->Text = code;
	}

    ((TEdit *)Sender)->Color = clCream;

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

    }

    ((TEdit *)Sender)->Color = clCream;

    OnItemsChanged(Sender);
}
//---------------------------------------------------------------------------
// �����o�R���{->OnKeyDown
void __fastcall TMainForm::HannyuCombo_KeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key == VK_ESCAPE)
		HannyuCombo->ItemIndex = -1;
	if (Key == VK_UP || Key == VK_DOWN)
		Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocketError(TObject *Sender,
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

    ClientSocket->Close();

    ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientSocketRead(TObject *Sender,
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
    case 'S':   WeightPanel->Font->Color = TColor(0x00CDF7A4);	break;
	case 'U':   WeightPanel->Font->Color = TColor(0x008080FF);	break;
	case 'O':	WeightPanel->Font->Color = clYellow;
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
		cur_weight_ = 0;
		WeightPanel->Caption = "OverLoad";
		return;
	}

	old_weight_ = cur_weight_;
	cur_weight_ = tmp_weight;

	// [INI] Weighing::SoundBorder
/*
	int border = ToInt(DM->INI["Weighing::SoundBorder"]);

	if (old_weight_ < border && cur_weight_ >= border){
		// [INI] Weighing::SoundFile
		PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
	}
*/
    if (old_weight_ < weighing_border_ && cur_weight_ >= weighing_border_){
        PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
    }else if ((old_weight_ >= weighing_border_) && (cur_weight_ < weighing_border_)){
        last_card_no_ = 0;
    }

	WeightPanel->Caption = FormatFloat("###,##0", cur_weight_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnRFIDAborted(TMessage& message)
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
        Application->MessageBox(("���RFID���[�_:" + status).c_str(), "���RFID��Q",  MB_OK | MB_ICONSTOP);
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

    // �d�ʃ{�[�_�[���d�ʂ��Ⴂ��
    if (cur_weight_ < weighing_border_){
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
	int row = GetRowNo();

	switch (Key){
	case VK_DOWN:
		if (ActiveControl == hincode[row] || ActiveControl == hinname[row] || ActiveControl == biko[row])
			return;
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_RETURN:
		if (ActiveControl == hincode[row] || ActiveControl == hinname[row] || ActiveControl == biko[row])
			return;
        if (ActiveControl == BikoEdit)
            return;

        if (GetMode() == imFirst && ActiveControl == WeightEdit11 && WeightEdit12->Text.IsEmpty())
            return;

        if (ActiveControl->Tag != 999 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_UP:
		if (ActiveControl == hincode[row] || ActiveControl == weight1[row])
			return;
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

    ContinueWeighing(Q_Tairyu->FieldByName("�v��ID")->AsInteger);
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

    //Exit��ʂ�Ȃ����߁A�����ɎԔ�Exit����������
    ((TEdit *)Sender)->Color = clCream;

    if (ActiveControl != ShabanEdit)
        return;

    if (GetMode() == imMod){
        TokuCodeEdit->SetFocus();
    }else{

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;


        if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
            TokuCodeEdit->SetFocus();
		//else if (HinCodeEdit->Text.IsEmpty() && HinPanel->Visible)
            //HinCodeEdit->SetFocus();
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();
        else
            BikoEdit->SetFocus();
		//else if (FirstWEdit->Text.IsEmpty())
			//FirstWEdit->SetFocus();
		//else
            //SecondWEdit->SetFocus();

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
			   ;

		SharyoNameEdit->Text = name;

		keiryo_count_ = 2;

		if (GetMode() == imFirst && !ShudoCheckBox->Checked)
			weight1[1]->Text = cur_weight_;

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

		if (GetMode() == imFirst)
			weight1[1]->Text = cur_weight_;

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

 			if (ToCurrency(SET_TOP(set)["��ԏd��"]) > 0){
				keiryo_count_ = 1;
				weight2[1]->Text = ToCurrency(SET_TOP(set)["��ԏd��"]);
			}else{
				keiryo_count_ = 2;
			}


			gross_limit_ = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
			net_limit_   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

			SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);

            if (!ShudoCheckBox->Checked){
			    weight1[1]->Text = cur_weight_;
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

    if (ToInt(SET_TOP(car_set)["�g�p�敪"]) != 1)
        StatusBar->Panels->Items[1]->Text = "RFID: �g�p���Ȃ��ԗ����";

    Action1->Execute();

    int row = GetRowNo();

    car_id_ =   ToInt(SET_TOP(car_set)["�ԗ�ID"]);
    int remained_id = DM->GetRemainedKeiryoID(GetPlaceID(), car_id_);

    if (!remained_id){
        ShabanEdit->Text    =   ZeroSuppress(ToInt(SET_TOP(car_set)["�Ԕ�"]));
        TokuCodeEdit->Text  =   ZeroSuppress(ToInt(SET_TOP(car_set)["���Ӑ�R�[�h"]));
        hincode[row]->Text  =   ZeroSuppress(ToInt(SET_TOP(car_set)["�i�ڃR�[�h"]));
        Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(car_set)["����1�R�[�h"]));
        Komoku2CodeEdit->Text = ZeroSuppress(ZeroSuppress(SET_TOP(car_set)["����2�R�[�h"]));

        if (ToCurrency(SET_TOP(car_set)["��ԏd��"]) > 0){
            keiryo_count_ = 1;
            weight1[1]->Text = ToCurrency(SET_TOP(car_set)["��ԏd��"]);
        }else{
            keiryo_count_ = 2;
        }

        gross_limit_    =   ToCurrency(SET_TOP(car_set)["�ԗ����d��"]);
        net_limit_      =   ToCurrency(SET_TOP(car_set)["�ő�ύڗ�"]);

        SharyoNameEdit->Text    =   ToString(SET_TOP(car_set)["�ԗ�����"]);

        if (keiryo_count_ == 2){
            weight1[row]->Text = cur_weight_;
        }else{
            weight2[row]->Text = cur_weight_;
        }

        CalcWeight();

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit = 0;

        if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible)
            TokuCodeEdit->SetFocus();
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();

        ShabanEdit->OnExit = OnExit;

    }else{
        ContinueWeighing(remained_id);
    }

    // ������\������
    SetRireki(car_id_);

    return true;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
    //Exit��ʂ�Ȃ����߁A�����ɎԔ�Exit����������
    ((TEdit *)Sender)->Color = clCream;

    // 20160623���݁@���̊֐��͒ʂ�Ȃ�
    //	SharyoCheck();
    //  Exit�Ŕw�i��W���ɖ߂�
    //((TEdit *)Sender)->Color = clCream;
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
			//if (HinCodeEdit->Text.IsEmpty())
                //HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["�i�ڃR�[�h"]));

			if (ToCurrency(SET_TOP(set)["��ԏd��"]) > 0){
				keiryo_count_ = 1;
				weight2[1]->Text = ToCurrency(SET_TOP(set)["��ԏd��"]);
			}else{
				keiryo_count_ = 2;
			}
            gross_limit_ = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
            net_limit_   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);

			weight1[1]->Text = cur_weight_;
			//if (keiryo_count_ == 2)
				//FirstWEdit->Text = cur_weight_;
			//else
				//SecondWEdit->Text = cur_weight_;
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
	//RirekiHinCodeLabel->Caption     = ToString(rireki_set_[rireki_id_]["�i�ڃR�[�h"]);
	//RirekiHinNameLabel->Caption     = ToString(rireki_set_[rireki_id_]["�i�ږ���"]);
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
// F11 �����ďo
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (ToString(rireki_set_[0]["�v�ʓ�"]) == AnsiString())
		return;
	TokuCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["���Ӑ�R�[�h"]));
	TokuNameEdit->Text = ToString(rireki_set_[rireki_id_]["���Ӑ於��"]);
	//HinCodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["�i�ڃR�[�h"]));
	//HinNameEdit->Text = ToString(rireki_set_[rireki_id_]["�i�ږ���"]);
	Komoku1CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["����1�R�[�h"]));
	Komoku1NameEdit->Text = ToString(rireki_set_[rireki_id_]["����1����"]);
	Komoku2CodeEdit->Text = FormatFloat("#", ToInt(rireki_set_[rireki_id_]["����2�R�[�h"]));
	Komoku2NameEdit->Text = ToString(rireki_set_[rireki_id_]["����2����"]);
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
	//RirekiHinCodeLabel->Caption     = AnsiString();
	//RirekiHinNameLabel->Caption     = AnsiString();
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
    ((TEdit *)Sender)->Color = clGradientActiveCaption; //TColor(0x00FFF1F0);

	if (((TCobEdit *)Sender)->Hint == AnsiString())
		return;
	StatusBar->Panels->Items[2]->Text = ((TCobEdit *)Sender)->Hint;
}
//---------------------------------------------------------------------------
// ���גǉ�
// ���׍폜
// �d�ʍČv�Z
// �i�ڃR�[�h->OnExit
void __fastcall TMainForm::HinCodeEdit1Exit(TObject *Sender)
{
	int row = GetRowNo();

    ((TEdit *)Sender)->Color = clWindow;

    //�V�K���� �蓮�`�F�b�N�{�b�N�X����Ȃ�
    if (GetMode() == imFirst && !ShudoCheckBox->Checked)
        return;

	// �d�ʒ�����
	NsRecordSet set;
	AnsiString sql;

	sql = "SELECT * FROM M_�i�� WHERE �i�ڃR�[�h = " + IntToStr(hincode[row]->Text.ToIntDef(0));
	if (DM->DBI.GetRecordSet(sql, set)){
		Currency coord_ratio = ToCurrency(SET_TOP(set)["�d�ʒ�����"]);

		if (StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0) != coord_ratio){
			if (GetMode() == imMod)
				if (Application->MessageBox(("�d�ʒ��������قȂ�܂��B�㏑�����܂����H\r\n�o�^�������F" + FormatFloat("#,##0.0#", coord_ratio) + "%").c_str(), "�i�ڕύX", MB_YESNO | MB_ICONEXCLAMATION) != IDYES)
					return;
			choritu[row]->Text = ZeroSuppress(coord_ratio);
			CalcWeight();
		}
	}

}
//---------------------------------------------------------------------------
// �d��->OnExit
void __fastcall TMainForm::WeightEdit11Exit(TObject *Sender)
{
	int row = GetRowNo();

    //Edit�̔w�i�F�����ɖ߂�
    ((TEdit *)Sender)->Color = clWindow;

    // 2��ڏd�ʂ��󔒂Ȃ�Όv�Z���Ȃ�
    if (weight2[row]->Text == ""){
        return;
    }

	if ((TCobEdit *)Sender == choritu[row])
		choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));

	CalcWeight();
    //�����z
    CalcKingakuTotal();
    //�������d��
    CalcShomiTotal();
    //�����
    CalcSalesTax();
}
//---------------------------------------------------------------------------
// �P�ʌ���
void __fastcall TMainForm::TaniTitleEditClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P�� ";
	SearchForm->orderby_sql = " ORDER BY �P�ʃR�[�h ";
	SearchForm->table_name = "M_�P��";
	if (SearchForm->ShowModal() != mrOk)
		return;
	int row = GetRowNo();
	if (row == 0)
		return;
	tanicode[row]->Text = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
	tanicode[row]->OnChange(NULL);
	tanicode[row]->SetFocus();
}
//---------------------------------------------------------------------------
// �i�ڌ���
void __fastcall TMainForm::HinNameTitleEditClick(TObject *Sender)
{
/*
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT �i�ڃR�[�h, �i�ڗ���, �����o�敪���� AS �����o, ����敪���� AS ����敪 FROM V_�i�� WHERE �g�p�敪 = 1";
	SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
	SearchForm->table_name = "V_�i��";
	if (SearchForm->ShowModal() != mrOk)
		return;
	int row = GetRowNo();
	if (row == 0)
		return;
	hincode[row]->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
	hincode[row]->OnChange(NULL);
	hincode[row]->SetFocus();
*/

}
//---------------------------------------------------------------------------
int __fastcall TMainForm::GetRowNo()
{
	if (ActiveControl == hincode[1] || ActiveControl == hinname[1] || ActiveControl == weight1[1] || ActiveControl == weight2[1] || ActiveControl == choritu[1] || ActiveControl == choweight[1] || ActiveControl == bikiweight[1] || ActiveControl == shomi[1] || ActiveControl == suryo[1] || ActiveControl == tanicode[1] || ActiveControl == taniname[1] || ActiveControl == tanka[1] | ActiveControl == kingaku[1] || ActiveControl == shouhi[1] || ActiveControl == biko[1])
		return 1;
	else if (ActiveControl == hincode[2] || ActiveControl == hinname[2] || ActiveControl == weight1[2] || ActiveControl == weight2[2] || ActiveControl == choritu[2] || ActiveControl == choweight[2] || ActiveControl == bikiweight[2] || ActiveControl == shomi[2] || ActiveControl == suryo[2] || ActiveControl == tanicode[2] || ActiveControl == taniname[2] || ActiveControl == tanka[2] | ActiveControl == kingaku[2] || ActiveControl == shouhi[2] || ActiveControl == biko[2])
		return 2;
	else if (ActiveControl == hincode[3] || ActiveControl == hinname[3] || ActiveControl == weight1[3] || ActiveControl == weight2[3] || ActiveControl == choritu[3] || ActiveControl == choweight[3] || ActiveControl == bikiweight[3] || ActiveControl == shomi[3] || ActiveControl == suryo[3] || ActiveControl == tanicode[3] || ActiveControl == taniname[3] || ActiveControl == tanka[3] | ActiveControl == kingaku[3] || ActiveControl == shouhi[3] || ActiveControl == biko[3])
		return 3;
	else if (ActiveControl == hincode[4] || ActiveControl == hinname[4] || ActiveControl == weight1[4] || ActiveControl == weight2[4] || ActiveControl == choritu[4] || ActiveControl == choweight[4] || ActiveControl == bikiweight[4] || ActiveControl == shomi[4] || ActiveControl == suryo[4] || ActiveControl == tanicode[4] || ActiveControl == taniname[4] || ActiveControl == tanka[4] | ActiveControl == kingaku[4] || ActiveControl == shouhi[4] || ActiveControl == biko[4])
		return 4;
	else if (ActiveControl == hincode[5] || ActiveControl == hinname[5] || ActiveControl == weight1[5] || ActiveControl == weight2[5] || ActiveControl == choritu[5] || ActiveControl == choweight[5] || ActiveControl == bikiweight[5] || ActiveControl == shomi[5] || ActiveControl == suryo[5] || ActiveControl == tanicode[5] || ActiveControl == taniname[5] || ActiveControl == tanka[5] | ActiveControl == kingaku[5] || ActiveControl == shouhi[5] || ActiveControl == biko[5])
		return 5;
	else if (ActiveControl == hincode[6] || ActiveControl == hinname[6] || ActiveControl == weight1[6] || ActiveControl == weight2[6] || ActiveControl == choritu[6] || ActiveControl == choweight[6] || ActiveControl == bikiweight[6] || ActiveControl == shomi[6] || ActiveControl == suryo[6] || ActiveControl == tanicode[6] || ActiveControl == taniname[6] || ActiveControl == tanka[6] | ActiveControl == kingaku[6] || ActiveControl == shouhi[6] || ActiveControl == biko[6])
		return 6;
	else
		return 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinCodeEdit1Change(TObject *Sender)
{
	int row = GetRowNo();
	if (row == 0)
		return;
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT * FROM V_�i�� WHERE �g�p�敪 = 1 AND �i�ڃR�[�h = " + IntToStr(hincode[row]->Text.ToIntDef(0)), set);
	hinname[row]->Text      = ToString(set[0]["�i�ږ���"]);

    if (hincode[row]->Text == "0"){
        hinname[row]->Text = "�����͂œo�^����܂�";
    }

    if(row == 1){
        HannyuCombo->ItemIndex  = ToInt(set[0]["�����o�敪"]) - 1;
    }
    CallTanka();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinCodeEdit1KeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{

	int row = GetRowNo();
	if (row == 0)
		return;
/*
    if (hincode[row]->Text == ""){
        return;
    }
*/
	// �����v�ʁ�����v�ʁ�1��ڏd��->ENTER�œo�^
	if (!ShudoCheckBox->Checked && Key == VK_RETURN && GetMode() == imFirst && ActiveControl == weight1[1] && weight2[1]->Text.IsEmpty()){
		PostConfForm->ButtonKeizoku->Enabled = true;
		Action5->Execute();
	}else{
        //weight2[row]->SetFocus();
    }

	if (Key == VK_RETURN || Key == VK_TAB){
		if (ActiveControl == hincode[row] && hinname[row]->TabStop){
			Key = 0;
			hinname[row]->SetFocus();
		}
        if (ActiveControl == weight1[row] && weight1[row]->Text != "" && ShudoCheckBox->Checked){
            if (row == 1){
                weight2[row]->SetFocus();
            }
            return;
        }
		if (ActiveControl == hincode[row] && !hinname[row]->TabStop || ActiveControl == hinname[row]){
			Key = 0;
			weight1[row]->SetFocus();
		}
        if (ActiveControl == weight1[row]){
            CalcAmount();

        }
        //
		if (ActiveControl == biko[row]){
			Key = 0;
            // �蓮���͂�checked�Ȃ�
            if (ShudoCheckBox->Checked && row != limit_line_){
                hincode[row + 1]->SetFocus();
                return;
            }
            // �i�ږ��̂����,�d��1 > 0 , �d��2 > 0 �̂Ƃ�
            if (hinname[row] != NULL && weight1[row] > 0 && weight2[row] > 0){
                Action5->Execute();
                // �m�F��ʃL�����Z���Ŗ߂����Ƃ���
                //hincode[row + 1]->SetFocus(); a
                if (hincode[row]->Text != ""){
                    hincode[row + 1]->SetFocus();
                }
                return;
            }
			if (row < limit_line_)
				hincode[row + 1]->SetFocus();
		}
	}
	if (Key == VK_UP){
		if (ActiveControl == hincode[row]){
			Key = 0;
			if (row > 1)
				biko[row - 1]->SetFocus();
		}
		if (ActiveControl == weight1[row]){
			Key = 0;
			if (hinname[row]->TabStop)
				hinname[row]->SetFocus();
			else
				hincode[row]->SetFocus();
		}
	}


	if (ActiveControl == biko[limit_line_] && Key == VK_RETURN){
		Key = 0;
		Action5->Execute();
        ShabanEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChoseiPerEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
	((TCobEdit *)Sender)->Text = AnsiReplaceStr(((TCobEdit *)Sender)->Text, "%", "");
	((TCobEdit *)Sender)->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Key = 0;

    if (GetMode() != imSecond){
        HinCodeEdit1->SetFocus();
        return;

    }else{

        // 20160519�ǉ�
        // 1��ڏd�ʂ�2��ڏd�ʂ��������͌v�ʊ������Ă��Ȃ��̂Ŏ��̍s�ւ����Ȃ�
        // �����������͂̏ꍇ�͌v�ʊ������Ă��Ȃ��̂Ŏ��̍s�ւ����Ȃ�
        if (tanka[1]->Text == "" || kingaku[1]->Text == "" || shomi[1]->Text == ""){
                hincode[1]->SetFocus();
                ;
        }else if (tanka[2]->Text == "" || kingaku[2]->Text == "" ){
            if (weight2[1]->Text == "0"){
                weight2[1]->SetFocus();
            }else
            hincode[2]->SetFocus();
        }else if (tanka[3]->Text == "" || kingaku[3]->Text == ""){
            if (weight2[2]->Text == "0"){
                weight2[2]->SetFocus();
            }else
            hincode[3]->SetFocus();
        }else if (tanka[4]->Text == "" || kingaku[4]->Text == ""){
            if (weight2[3]->Text == "0"){
                weight2[3]->SetFocus();
            }else
            hincode[4]->SetFocus();
        }else if (tanka[5]->Text == "" || kingaku[5]->Text == ""){
            if (weight2[4]->Text == "0"){
                weight2[4]->SetFocus();
            }else
            hincode[5]->SetFocus();
        }else if (tanka[6]->Text == "" || kingaku[6]->Text == ""){
            if (weight2[5]->Text == "0"){
                weight2[5]->SetFocus();
            }else
            hincode[6]->SetFocus();
        }else{
            Application->MessageBox("���ׂ�}���ł���s������܂���\r\n�o�^���s���Ă�������", this->Caption.c_str(), MB_OK);
        }
        //20160519 �ǉ�
    	Action10->OnExecute(NULL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TaniCodeEdit1Change(TObject *Sender)
{
    int num = GetRowNo();

    taniname[num]->Text = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tanicode[num]->Text.ToIntDef(0), "�P�ʖ���", ""));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CalcShomiTotal()
{
    shomi_total_ = 0;
    ShomiSumEdit->Text = AnsiString();
    int total = 0;

    for(int i = 1; i < 7; i++){
        if(shomi[i]->Text == ""){
            continue;
        }

        shomi_total_ += StrToIntDef(shomi[i]->Text, 0);
        total += shomi[i]->Text.ToIntDef(0);
    }
    ShomiSumEdit->Text = ToString(shomi_total_);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ShomiEdit1Change(TObject *Sender)
{
/*    //20160628
    int row = GetRowNo();

    if (row == 0){
        return;
    }

    Currency shom =  StrToCurrDef(shomi[row]->Text, 0);
    Currency w1   =  StrToCurrDef(weight1[row]->Text, 0);
    Currency total = shom + w1;
    weight2[row]->Text = CurrToStr(total);

    CalcShomiTotal();
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcKingakuTotal()
{
    int kingaku = 0, shohizei = 0;
    kingaku  = KingakuSumEdit->Text.ToIntDef(0);
    shohizei = ShohizeiEdit->Text.ToIntDef(0);
//    sum_total_ = (KingakuSumEdit->Text.ToIntDef(0)) + (ShohizeiEdit->Text.ToIntDef(0));
    ZeikomiEdit->Text =  sum_total_ = kingaku + shohizei;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcKingaku()
{
    kingaku_total_ = 0;
    KingakuSumEdit->Text = AnsiString();

    for (int i = 1; i < 7; i++){
        kingaku_total_ += StrToIntDef(kingaku[i]->Text, 0);
    }

    KingakuSumEdit->Text = ToString(kingaku_total_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SuryoEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clWindow;
}
//---------------------------------------------------------------------------
// ���ݕ\������Ă���KeiryoTimePicker�̎��Ԃ�b��00�Ŏ擾
TDateTime __fastcall TMainForm::GetTimePicker_ZeroSec()
{
    TDateTime dt, keiryo_time;
    AnsiString time = KeiryoTimePicker->Time.FormatString("hh:nn:ss");
    time = time.SubString(1, 6);
    keiryo_time = StrToTime(time + "00");
    dt = CombineDateTime(KeiryoDatePicker->Date, keiryo_time);

    return dt;
}
//---------------------------------------------------------------------------
// �`�[No�̍Ō�̖��ׂ̌v�ʎ���2���擾
TDateTime __fastcall TMainForm::GetLastKeiryoTime(int date, int slip_no, int place_id)
{
    NsRecordSet set;
    AnsiString  sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     V_�v��"
          " WHERE"
          "     �v�ʓ� = " + IntToStr(date) +
          " AND"
          "     �`�[No = " + IntToStr(slip_no) +
          " AND"
          "     ���_ID = " + IntToStr(place_id) +
          " ORDER BY"
          "     �sNo DESC";

    if (!DM->DBI.GetRecordSet(sql, set))
        return Now();

    if (SET_TOP(set)["�v�ʓ���2"].IsNull() && SET_TOP(set)["�v�ʓ���1"].IsNull())
        return Now();
    else if (SET_TOP(set)["�v�ʓ���2"].IsNull())
        return TDateTime(SET_TOP(set)["�v�ʓ���1"]);
    else
        return TDateTime(SET_TOP(set)["�v�ʓ���2"]);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MeisaiAddButtonClick(TObject *Sender)
{
    if (hincode[limit_line_]->Text != ""){
        Application->MessageBox("���גǉ�����ɂ͋�s���K�v�ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }
    //���݃t�H�[�J�X����Ă���s�����擾
    int i = GetRowNo();

    //�t�H�[�J�X�s��6�s�ڂȂ�
    if(i == limit_line_){
        return;
    }

    //���ה�t�H�[�J�X���̏���
    if (i == 0){
        return;
    }
/*
    //�t�H�[�J�X�s�̎��s���󔒂Ȃ��,���s���͂�
    if (hincode[i + 1]->Text == ""){
        hincode[i + 1]->SetFocus();
        return;
    }
*/
    for(int cnt = 6; cnt > 0; cnt--){
        if (i > cnt){
            continue;
        }

        if(hincode[cnt]->Text == ""){
            continue;
        }

        hincode[cnt + 1]->Text    =   hincode[cnt]->Text;
        hinname[cnt + 1]->Text    =   hinname[cnt]->Text;
        weight1[cnt + 1]->Text    =   weight1[cnt]->Text;
        //weight2[cnt + 1]->Text    =   StrToCurrDef(weight1[]->Text, 0) + StrToCurrDef(shomi[cnt]->Text, 0);
        weight2[cnt + 1]->Text    =   weight2[cnt]->Text;
        choritu[cnt + 1]->Text    =   choritu[cnt]->Text;
        choweight[cnt + 1]->Text  =   choweight[cnt]->Text;
        bikiweight[cnt + 1]->Text =   bikiweight[cnt]->Text;
        shomi[cnt + 1]->Text      =   shomi[cnt]->Text;
        suryo[cnt + 1]->Text      =   suryo[cnt]->Text;
        tanicode[cnt + 1]->Text   =   tanicode[cnt]->Text;
        taniname[cnt + 1]->Text   =   taniname[cnt]->Text;
        tanka[cnt + 1]->Text      =   tanka[cnt]->Text;
        kingaku[cnt + 1]->Text    =   kingaku[cnt]->Text;
        shouhi[cnt + 1]->Text     =   shouhi[cnt]->Text;
        biko[cnt + 1]->Text       =   biko[cnt]->Text;

        //20160624
        //�s�ǉ������Ƃ���ID�܂ňړ������邱�ƂȂ�
        //StringGridID->Cells[0][cnt + 1] = StringGridID->Cells[0][cnt];

    }

    //�s���ړ�������I�������s���N���A
    hincode[i]->Text = AnsiString();
    hinname[i]->Text = AnsiString();
    weight1[i]->Text = AnsiString();
    weight2[i]->Text = AnsiString();
   	choritu[i]->Text = AnsiString();
    choweight[i]->Text = AnsiString();
   	bikiweight[i]->Text = AnsiString();
    shomi[i]->Text = AnsiString();
   	suryo[i]->Text = AnsiString();
    tanicode[i]->Text = AnsiString();
   	taniname[i]->Text = AnsiString();
   	tanka[i]->Text = AnsiString();
    kingaku[i]->Text = AnsiString();
    shouhi[i]->Text  = AnsiString();
   	biko[i]->Text = AnsiString();
    //20160624
    //ID�ȊO���㏑������
    //StringGridID->Cells[0][i] = AnsiString();

    //���גǉ��t���Otrue
    chk_addflag_ = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MeisakiDeleteButtonClick(TObject *Sender)
{
    //�I���s��ϐ���
    int i = GetRowNo();
    //�I������Ă���s��ID��ϐ���
    int chk_keiryoID = StringGridID->Cells[0][i].ToIntDef(0);

    if (i <= 0 || i > 6){
        Application->MessageBox("�폜���閾�ׂ̍s��I��ł�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    // 1�s�������݂��Ȃ��Ƃ�
    // �`�[���̂��̂��폜����
    if (hincode[1]->Text != "" && hinname[2]->Text == "" ){
        Action3->Execute();
        return;
    }

    AnsiString gyo_no = ToString(i);

    // �����s����ꍇ�̏���
    if (Application->MessageBox(("�sNo" + IntToStr(i) + " ���폜���Ă���낵���ł����H\r\n���̏����Ŏ��ۂ̃f�[�^���폜����܂�").c_str(),
            this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES){
        return;
    }

    try{
        DM->ADOConnection->BeginTrans();

        NsFieldSet keys;
        NsRecordSet set;
        if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(chk_keiryoID), set)){
            Application->MessageBox("�폜�f�[�^�̒��o�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }

        keys    <<  NsField("[�v�ʓ�]",     ToInt(set[0]["�v�ʓ�"]))
                <<  NsField("[���_ID]",     ToInt(set[0]["���_ID"]))
                <<  NsField("[�`�[No]",   ToInt(set[0]["�`�[No"]))
                <<  NsField("[�sNo]",       ToInt(set[0]["�sNo"]));

        DM->DBI.Delete("D_�v��", keys);

        //����f�[�^��������
        keys.clear();

        if (!DM->DBI.GetRecordSet("SELECT * FROM D_��� WHERE �v��ID = " + IntToStr(chk_keiryoID), set)){
            Application->MessageBox("����폜�f�[�^�̒��o�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }

        keys    <<  NsField("[�v��ID]", chk_keiryoID);

        DM->DBI.Delete("D_���", keys);

        //���Ȃ���΍폜��������������
        DM->ADOConnection->CommitTrans();
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "�폜���ɃG���[���������܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), "�v�ʃf�[�^�폜", MB_OK | MB_ICONWARNING);
        return;
    }

    for(i; i < limit_line_; i++){
        if (i > 1 && hincode[i]->Text.ToIntDef(0) ==0){
            continue;
        }

        if (hincode[i + 1]->Text == ""){
        	hincode[i]->Text = AnsiString();
	        hinname[i]->Text = AnsiString();
	        weight1[i]->Text = AnsiString();
	        weight2[i]->Text = AnsiString();
        	choritu[i]->Text = AnsiString();
        	choweight[i]->Text = AnsiString();
        	bikiweight[i]->Text = AnsiString();
        	shomi[i]->Text = AnsiString();
        	suryo[i]->Text = AnsiString();
        	tanicode[i]->Text = AnsiString();
        	taniname[i]->Text = AnsiString();
        	tanka[i]->Text = AnsiString();
        	kingaku[i]->Text = AnsiString();
            shouhi[i]->Text  = AnsiString();
        	biko[i]->Text = AnsiString();
        	StringGridID->Cells[0][i] = AnsiString();
            continue;
        }

        hincode[i]->Text    =   hincode[i + 1]->Text;
        hinname[i]->Text    =   hinname[i + 1]->Text;
        weight1[i]->Text    =   weight2[i - 1]->Text;
        weight2[i]->Text    =   StrToCurrDef(weight1[i]->Text, 0) + StrToCurrDef(shomi[i + 1]->Text, 0);
        choritu[i]->Text    =   choritu[i + 1]->Text;
        choweight[i]->Text  =   choweight[i + 1]->Text;
        bikiweight[i]->Text =   bikiweight[i + 1]->Text;
        shomi[i]->Text      =   shomi[i + 1]->Text;
        suryo[i]->Text      =   suryo[i + 1]->Text;
        tanicode[i]->Text   =   tanicode[i + 1]->Text;
        taniname[i]->Text   =   taniname[i + 1]->Text;
        tanka[i]->Text      =   tanka[i + 1]->Text;
        kingaku[i]->Text    =   kingaku[i + 1]->Text;
        shouhi[i]->Text     =   shouhi[i + 1]->Text;
        biko[i]->Text       =   biko[i + 1]->Text;
        StringGridID->Cells[0][i] = StringGridID->Cells[0][i + 1];
    }

    NsFieldSet keys, fields;

    try{
        DM->ADOConnection->BeginTrans();

        //���דo�^
        for (int i = 1; i <= limit_line_ + 1; i++){
            if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                continue;

            keys.clear();
            fields.clear();

            keys    <<  NsField("[�v��ID]", StringGridID->Cells[0][i].ToIntDef(0));

            fields  <<  NsField("[1��ڏd��]", StrToCurrDef(weight1[i]->Text, 0))
                    <<  NsField("[2��ڏd��]", StrToCurrDef(weight2[i]->Text, 0))
                    <<  NsField("[�sNo]", i);

            if(!DM->DBI.IsExist("D_�v��", keys)){
                DM->DBI.Insert("D_�v��", fields);
            }else{
                DM->DBI.Update("D_�v��", keys, fields);
            }
        }


        //����f�[�^�o�^
        for (unsigned int i = 1; i <= limit_line_ + 1; i++){
            if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                continue;

            keys.clear();
            fields.clear();

            keys    <<  NsField("[�v��ID]", StringGridID->Cells[0][i].ToIntDef(0));
            //fields  <<  NsField("[�sNo]",   ToInt(set[i]["�sNo"]));
            fields  <<  NsField("[�sNo]",   i);

            if (!DM->DBI.IsExist("D_���", keys)){
                DM->DBI.Insert("D_���", fields);
            }else{
                DM->DBI.Update("D_���", keys, fields);
            }
        }

        DM->ADOConnection->CommitTrans();


    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "�o�^���ɃG���[���������܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), "�o�^�G���[", MB_OK | MB_ICONWARNING);
        return;
    }

    Q_Tairyu->Close();
    Q_Tairyu->Open();


}
//---------------------------------------------------------------------------
// �d�ʍČv�Z�{�^��
//
void __fastcall TMainForm::RecalcButtonClick(TObject *Sender)
{
    //2�s�ڂȂ��Ŏ��s���Ȃ�
    if(hincode[2]->Text == "")
        return;

    if (Application->MessageBox("�Čv�Z���s���܂���?", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    Currency w1, w2, net, adjust, reduc;
    int io_div = HannyuCombo->ItemIndex + 1;

    if (io_div <1 || io_div >2){
        Application->MessageBox("�����o�敪���ݒ肳��Ă��܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    if (io_div == 1){

        //����
        //�ŏI�s����
        // limit_line_      .h�ɋL�q
        Currency first_weight = 0;

        for (int i = limit_line_; i > 0; i--){
            if(hincode[i]->Text == ""){
                continue;
            }
            w1  =   StrToCurrDef(weight1[i]->Text, 0);
            w2  =   StrToCurrDef(weight2[i]->Text, 0);
            net =   StrToCurrDef(shomi[i]->Text, 0);
            adjust  =   StrToCurrDef(choweight[i]->Text, 0);
            reduc   =   StrToCurrDef(bikiweight[i]->Text, 0);

            if (w1 == 0 && w2 == 0){ //
                continue;
            }

            if (first_weight != 0){
                w2                  =   first_weight;
                weight2[i]->Text    =   first_weight;
            }

            if (w1 - w2 - adjust - reduc != net){
                first_weight        = ToString(w2 + adjust + reduc + net);
                weight1[i]->Text    = first_weight;
            }else{
                first_weight = w1;
            }
        }

    }else if (io_div == 2){
        //���o
        Currency second_weight = 0;

        for(int i = 0; i <= limit_line_; i++){
            if (hincode[i]->Text == ""){
                continue;
            }

            w1      =   StrToCurrDef(weight1[i]->Text, 0);
            w2      =   StrToCurrDef(weight2[i]->Text, 0);
            net     =   StrToCurrDef(shomi[i]->Text, 0);
            adjust  =   StrToCurrDef(choweight[i]->Text, 0);
            reduc   =   StrToCurrDef(bikiweight[i]->Text, 0);

            if (w1 == 0 && w2 == 0)
                continue;

            if (second_weight != 0){
                w1  =   second_weight;
                weight1[i]->Text = AnsiString(second_weight);
            }

            if (w2 - w1 - adjust - reduc != net){
                second_weight = w1 + adjust + reduc + net;
                weight2[i]->Text = AnsiString(second_weight);
            }else{
                second_weight = w2;
            }
        }
    }

    Application->MessageBox("�Čv�Z���������܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MeisaiAddWeightRecieve()
{
//
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::TankaEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;
    CalcAmount(false);
}
//---------------------------------------------------------------------------
// �P�����o�^�P�����ǂ������`�F�b�N���邾��
void __fastcall TMainForm::TankaCheck(int row)
{
    int meig_id  = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hincode[row]->Text.ToIntDef(0), "�i��ID"));
    int item1_id = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
    int item2_id = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
    int tani_id  = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tanicode[row]->Text.ToIntDef(0), "�P��ID"));

	Currency tankacode = StrToCurrDef(tanka[row]->Text, 0);
	Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);

    //�o�^�P�� = ���F ����ȊO = ��
    tanka[row]->Color = tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

}
//---------------------------------------------------------------------------
//���׍폜
void __fastcall TMainForm::SpeedButton2Click(TObject *Sender)
{
    //�I���s��ϐ���
    int row = GetRowNo();
    int i = row;

    //�I���s�̌v��ID ��ێ�
    //1���ׂ����Ȃ��Ƃ��͓`�[�폜�ɂȂ�
    //�폜�ɂ�keiryo_id_�ɓ��ꂽ�����s�����悢
    keiryo_id_ = StringGridID->Cells[0][i].ToIntDef(0);

    //�s���I������ĂȂ���΁Areturn;
    if (row <= 0 || row > 6){
        Application->MessageBox("�폜���閾�׍s��I��ł�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    NsFieldSet  keys;
    NsRecordSet set;

    //�@�v��ID����̌Ăяo��
    if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id_), set)){
        DeleteSingleRow(row);
        return;
    }


    // ���ׂ�1�s�����Ȃ��Ƃ���
    // F3�폜����
    if (hincode[1]->Text != "" && hincode[2]->Text == ""){
        Action3->Execute();
        return;
    }

    AnsiString gyo_no = ToString(i);
    //�폜�O�m�F���b�Z�[�W
    if (Application->MessageBox(("�sNo" + IntToStr(i) + " ���폜���Ă���낵���ł����H\r\n���̏����Ńf�[�^���폜����܂�\r\n���ɖ߂����Ƃ͂ł��܂���").c_str(),
            this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES){
        return;
    }

    try{
        DM->ADOConnection->BeginTrans();
/*
        NsFieldSet  keys;
        NsRecordSet set;

        //�v��ID����f�[�^�̌Ăяo��
        if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id_), set)){
            //���o���s����
            Application->MessageBox("�v�ʃf�[�^�̒��o�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
*/
        //D_�v�� 1���׍폜
        keys    <<  NsField("[�v�ʓ�]", ToInt(set[0]["�v�ʓ�"]))
                <<  NsField("[���_ID]", ToInt(set[0]["���_ID"]))
                <<  NsField("[�`�[No]", ToInt(set[0]["�`�[No"]))
                <<  NsField("[�sNo]",   ToInt(set[0]["�sNo"]));

        DM->DBI.Delete("D_�v��", keys);

        int date = DateToInt(KeiryoDatePicker->Date);
        int kyo  = GetPlaceID();
        int denpyo  = KeiryoNoEdit->Text.ToIntDef(0);

        AnsiString sql;
        sql =  " SELECT �v��ID FROM D_�v��"
               " WHERE  �v�ʓ� = " + IntToStr(date) + " AND ���_ID = " + IntToStr(kyo) +
               " AND    �`�[No = " + IntToStr(denpyo);

        DM->DBI.GetRecordSet(sql, set);

        int del_keiryo_id = keiryo_id_;
        ClearForm();
        keiryo_id_ = SET_TOP(set)["�v��ID"];
        LoadFromID(keiryo_id_);

/*        // �폜�����s�ɂȂɂ�����Ȃ�������w�肵��1�s�N���A
        if (hincode[row]->Text == ""){
            DeleteSingleRow(row);
        }
*/
        //���דo�^�p
        NsFieldSet fields;

        //���דo�^
        for (int i = 1; i <= limit_line_ + 1; i++){
            if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                continue;

            keys.clear();
            fields.clear();

            keys    <<  NsField("[�v��ID]", StringGridID->Cells[0][i].ToIntDef(0));

            fields  <<  NsField("[1��ڏd��]", StrToCurrDef(weight1[i]->Text, 0))
                    <<  NsField("[2��ڏd��]", StrToCurrDef(weight2[i]->Text, 0))
                    <<  NsField("[�sNo]", i);

            if(!DM->DBI.IsExist("D_�v��", keys)){
                DM->DBI.Insert("D_�v��", fields);
            }else{
                DM->DBI.Update("D_�v��", keys, fields);
            }
        }

        //////////////////////////////
        // ����f�[�^����

        keys.clear();

        if (DM->DBI.GetRecordSet("SELECT * FROM D_��� WHERE �v��ID = " + IntToStr(keiryo_id_), set)){
            keys << NsField("[�v��ID]", del_keiryo_id);

            DM->DBI.Delete("D_���", keys);

            //����f�[�^�o�^
            for (unsigned int i = 1; i <= limit_line_ + 1; i++){
                if (i > 1 && hincode[i]->Text.ToIntDef(0) == 0)
                    continue;

                keys.clear();
                fields.clear();

                keys    <<  NsField("[�v��ID]", StringGridID->Cells[0][i].ToIntDef(0));
                //fields  <<  NsField("[�sNo]",   ToInt(set[i]["�sNo"]));
                fields  <<  NsField("[�sNo]",   i);

                if (!DM->DBI.IsExist("D_���", keys)){
                    DM->DBI.Insert("D_���", fields);
                }else{
                    DM->DBI.Update("D_���", keys, fields);
                }
            }
        }

        DM->ADOConnection->CommitTrans();
        AnsiString compmsg = "�폜���������܂���";
        Application->MessageBox(compmsg.c_str(), Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "���׍폜�����ɃG���[���������܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), "���׍폜�G���[", MB_OK | MB_ICONWARNING);
        return;
    }


    Q_Tairyu->Close();
    Q_Tairyu->Open();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WeightEdit12KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key != VK_RETURN){
        return;
    }

    

    CalcAmount();

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DeleteSingleRow(int row)
{
    hincode[row]->Text  =  AnsiString();
    hinname[row]->Text  =  AnsiString();
    weight1[row]->Text  =  AnsiString();
    weight2[row]->Text  =  AnsiString();
    choritu[row]->Text  =  AnsiString();
    choweight[row]->Text    =  AnsiString();
    bikiweight[row]->Text   =  AnsiString();
    shomi[row]->Text    =  AnsiString();
    suryo[row]->Text    =  AnsiString();
    tanicode[row]->Text =  AnsiString();
    taniname[row]->Text =  AnsiString();
    tanka[row]->Text    =  AnsiString();
    kingaku[row]->Text  =  AnsiString();
    shouhi[row]->Text   =  AnsiString();
    biko[row]->Text     =  AnsiString();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ChoseiPerEdit1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
/*    if (Key != VK_RETURN)
        return;

	int row = GetRowNo();

	if ((TCobEdit *)Sender == choritu[row])
		choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));


	CalcWeight();
    //�����z
    CalcKingakuTotal();
    //�������d��
    CalcShomiTotal();
    //�����
    CalcSalesTax();
*/
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SuryoEdit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    int row = GetRowNo();

    if ((TCobEdit *)Sender == choritu[row])
        choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));

    CalcAmount();

}
//---------------------------------------------------------------------------




void __fastcall TMainForm::ChoseiPerEdit1Exit(TObject *Sender)
{
	int row = GetRowNo();

    //Edit�̔w�i�F�����Ƃɖ߂�
    ((TEdit *)Sender)->Color = clWindow;

	if ((TCobEdit *)Sender == choritu[row])
		choritu[row]->Text = FormatFloat("#.##%", StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0));


	CalcWeight();
    //�����z
    CalcKingakuTotal();
    //�������d��
    CalcShomiTotal();
    //�����
    CalcSalesTax();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::KingakuEdit1Exit(TObject *Sender)
{
    //Exit�Ŕw�i�F�����ɖ߂�
    ((TEdit *)Sender)->Color = clCream;

    CalcKingaku();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ShudoCheckBoxClick(TObject *Sender)
{
    if (ShudoCheckBox->Checked){
        ShudoCheckBox->Color = TColor(0x0076EBE6);  //true�Ȃ�A �Z�����F
    }else{
        ShudoCheckBox->Color = TColor(0x00FCB998);  //false�Ȃ�A���W��
    }

    if (ShabanEdit->Text == "")
        ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WeightEdit11Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;

    int row = GetRowNo();

    if (choritu[row]->Text != "" || !ShudoCheckBox->Checked){
        return;
    }


	// �d�ʒ�����
	NsRecordSet set;
	AnsiString  sql;

	sql = "SELECT * FROM M_�i�� WHERE �i�ڃR�[�h = " + IntToStr(hincode[row]->Text.ToIntDef(0));
	if (DM->DBI.GetRecordSet(sql, set)){
		Currency coord_ratio = ToCurrency(SET_TOP(set)["�d�ʒ�����"]);

		if (StrToCurrDef(AnsiReplaceStr(choritu[row]->Text, "%", ""), 0) != coord_ratio){
			if (GetMode() == imMod)
				if (Application->MessageBox(("�d�ʒ��������قȂ�܂��B�㏑�����܂����H\r\n�o�^�������F" + FormatFloat("#,##0.0#", coord_ratio) + "%").c_str(), "�i�ڕύX", MB_YESNO | MB_ICONEXCLAMATION) != IDYES)
					return;
			choritu[row]->Text = ZeroSuppress(coord_ratio);
			CalcWeight();
		}
	}
}
//---------------------------------------------------------------------------
// 1�s�ڂ�2��ڂ̌v�ʂɂ�����,���������擾�ł��Ȃ������̂�
// 2��ڏd�ʂ�1�s�ڂɌ�����,���������擾���鏈����ǉ�

// ����ȊO��2��ڏd�ʂɂ��ẮAWeightEdit22Enter�����L����

void __fastcall TMainForm::WeightEdit12Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
    cur_w2_row_ = GetRowNo();

    // 20160624
    if(ActiveControl == weight2[1]){
        NsRecordSet set;
        AnsiString  sql;

        sql = "SELECT * FROM M_�i�� WHERE �i�ڃR�[�h = "  + IntToStr(hincode[1]->Text.ToIntDef(0));
        if (DM->DBI.GetRecordSet(sql, set)){
            Currency coord_ratio = ToCurrency(SET_TOP(set)["�d�ʒ�����"]);
            choritu[1]->Text = ZeroSuppress(coord_ratio);
        }
    }
}
//---------------------------------------------------------------------------
//
void __fastcall TMainForm::WeightEdit22Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
    cur_w2_row_ = GetRowNo();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEditExit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;    
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::TaniCodeEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ShouhizeiEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clWindow;    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEdit1Exit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clWindow;    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HinCodeEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;

    int row = GetRowNo();
    if (GetMode() == imSecond && row >= 2){
        if (weight1[row]->Text.IsEmpty() && weight2[row]->Text.IsEmpty()){
            weight1[row]->Text = weight2[row - 1]->Text;
            weight2[row]->Text = cur_weight_;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikiWeightEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SuryoEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TaniCodeEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TankaEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::KingakuEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShouhizeiEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;    
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BikoEdit1Enter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SharyoNameEditEnter(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clGradientActiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SharyoNameEditExit(TObject *Sender)
{
    ((TEdit *)Sender)->Color = clCream;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChoseiPerEdit1Change(TObject *Sender)
{
    if (AnbunFlag_){
        return;
    }

    int row = GetRowNo();


    if (choritu[row]->Text == ""){
        choweight[row]->Text = AnsiString();
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShomiEdit1Exit(TObject *Sender)
{
/*    int row = GetRowNo();

    Currency shom = StrToCurrDef(shomi[row]->Text, 0);
    Currency w1   = StrToCurrDef(weight1[row]->Text, 0);
    Currency total = shom + w1;
    if (!choweight[row]->Text.IsEmpty()){
        total += StrToCurrDef(choweight[row]->Text, 0);
    }

    weight2[row]->Text = CurrToStr(total);

//    CalcWeight(row);
//    CalcShomiTotal();
*/
}
//---------------------------------------------------------------------------
// ��
void __fastcall TMainForm::AnbunButtonClick(TObject *Sender)
{
    //�I�����s��ϐ���
    int row = GetRowNo();

    if (row == 6)
    {
        Application->MessageBoxA("���׍s�s���̂��߈��ł��܂���", this->Caption.c_str(), MB_OK);
    }

    int i = row;
    int sumRow = 0;
    int carryflag = ToInt(DM->DBI.Lookup("M_�i��","�i�ڃR�[�h",ToInt(hincode[1]->Text),"�����o�敪"));

    //���t���O��ON ������change�̒����d�ʃN���A�����Ȃ�����
    AnbunFlag_ = 1;

    //�����s���s���I������ĂȂ�������
    if (row <= 0 || row > 6){
        Application->MessageBox("�����閾�׍s��I�����Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    //�v�ʃf�[�^�����݂��邩�ǂ���
    int chk_keiryoID = StringGridID->Cells[0][row].ToIntDef(0);
/*
    NsRecordSet set;
	AnsiString sql;
	sql = " SELECT * FROM V_�v��"
		  " WHERE"
		  "		�v�ʓ� IN ( SELECT �v�ʓ� FROM D_�v�� WHERE �v��ID = " + IntToStr(chk_keiryoID) + ") "
		  " AND"
		  "		���_ID IN ( SELECT ���_ID FROM D_�v�� WHERE �v��ID = " + IntToStr(chk_keiryoID) + ") "
		  " AND"
		  "     �`�[No IN ( SELECT �`�[No FROM D_�v�� WHERE �v��ID = " + IntToStr(chk_keiryoID) + ") "
		  " AND"
		  "     �����敪 <> 9";                 // �_���폜�͑ΏۊO

    if (!DM->DBI.GetRecordSet(sql, set)){
        //�f�o�b�N�p�߂���
        ShowMessage("���s��");
        //
        return;
    }
*/
    for (int i = 1; i <= 6; i++){
        if (!hincode[i]->Text.IsEmpty()){
            sumRow++;
        }else{
            break;
        }
    }
/*
    if (set.size() >= limit_line_){
        Application->MessageBox("���׌������ő匏��(6��)�ɂȂ��Ă��邽��,���ł��܂���", "��", MB_OK | MB_ICONWARNING);
        return;
    }
*/
    if (sumRow >= limit_line_) {
        Application->MessageBox("���׌������ő匏���ɂȂ��Ă��邽�߁A���ł��܂���", "��", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString weight1temp = weight1[row]->Text;
    AnsiString weight2temp = weight2[row]->Text;

    AnbunForm->ClearForm();
    AnbunForm->EditRate->Text       = "100";

    AnbunForm->EditHinCode->Text    = hincode[row]->Text;
    AnbunForm->EditHinName->Text    = hinname[row]->Text;
    AnbunForm->EditChoseiBiki->Text  = choweight[row]->Text;
    AnbunForm->EditJuryoBiki->Text  = bikiweight[row]->Text;
    AnbunForm->EditShomi->Text      = shomi[row]->Text;

//    AnbunForm->rec_count = set.size();
    AnbunForm->rec_count = sumRow;
    //�o�^�s�����i�[
//    int setsize = set.size();

    //���ōs�ړ����K�v�ȍs�����i�[
//    int moveCnt = setsize - row;
    int moveCnt = sumRow - row;

    if (AnbunForm->ShowModal() == mrOk){

        //�����ꂽ�s��
        int AnbunItemCount = AnbunForm->AnbunMap.size();


        //�����Ȃ��s���ړ�����
        for (int i = 0; i < moveCnt; i++){
            if (hincode[row + 1 + i]->Text.IsEmpty()){
                continue;
            }
            weight1[row + AnbunItemCount + i]->Text     = weight1[row + 1 + i]->Text;
            weight2[row + AnbunItemCount + i]->Text     = weight2[row + 1 + i]->Text;
            hincode[row + AnbunItemCount + i]->Text     = hincode[row + 1 + i]->Text;
            hincode[row + AnbunItemCount + i]->Text     = hincode[row + 1 + i]->Text;
            hincode[row + AnbunItemCount + i]->Text     = hincode[row + 1 + i]->Text;
            hinname[row + AnbunItemCount + i]->Text     = hinname[row + 1 + i]->Text;
            choritu[row + AnbunItemCount + i]->Text     = choritu[row + 1 + i]->Text;
            choweight[row + AnbunItemCount + i]->Text   = choweight[row + 1 + i]->Text;
            bikiweight[row + AnbunItemCount + i]->Text  = bikiweight[row + 1 + i]->Text;
            shomi[row + AnbunItemCount + i]->Text       = shomi[row + 1 + i]->Text;
            suryo[row + AnbunItemCount + i]->Text       = suryo[row + 1 + i]->Text;
            tanicode[row + AnbunItemCount + i]->Text    = tanicode[row + 1 + i]->Text;
            taniname[row + AnbunItemCount + i]->Text    = taniname[row + 1 + i]->Text;
            tanka[row + AnbunItemCount + i]->Text       = tanka[row + 1 + i]->Text;
            kingaku[row + AnbunItemCount + i]->Text     = kingaku[row + 1 + i]->Text;
            shouhi[row + AnbunItemCount + i]->Text      = shouhi[row + 1 + i]->Text;
            biko[row + AnbunItemCount + i]->Text        = biko[row + 1 + i]->Text;
        }

        //�����������s��}������
        for (int i = 0; i < AnbunItemCount; i++){
            hincode[row]->Text      = AnsiString(AnbunForm->AnbunMap[i].code);
            hinname[row]->Text      = AnsiString(AnbunForm->AnbunMap[i].name);
            choritu[row]->Text      = AnsiString();
            choritu[row]->Text      = AnsiString(AnbunForm->AnbunMap[i].choseiper);
            choweight[row]->Text    = AnsiString(AnbunForm->AnbunMap[i].choseibiki);
            bikiweight[row]->Text   = AnsiString(AnbunForm->AnbunMap[i].juryobiki);
            shomi[row]->Text        = AnsiString(AnbunForm->AnbunMap[i].shomi);
            suryo[row]->Text        = AnsiString();
            tanicode[row]->Text     = AnsiString();
            taniname[row]->Text     = AnsiString();
            tanka[row]->Text        = AnsiString();
            kingaku[row]->Text      = AnsiString();
            shouhi[row]->Text       = AnsiString();
            biko[row]->Text         = AnsiString();
            AnbunCalcChousei(row, carryflag);
            AnbunAfterChousei(row);
            //(��)�P���A���z�A����ł�\��
            AnbunCalcAmountTax(row);

            row++;
        }

        GetTotalMoney();
    }

    //������change(���̎w��Ȃ���΃N���A�@�\)���g�p�\�ɂ���
    AnbunFlag_ = 0;

    if (!hincode[6]->Text.IsEmpty() && !shomi[6]->Text.IsEmpty())
    {
        // GetRowNo()�������Ƃ��ɖ��׍s���ő�ł��邱�Ƃ���������
        // �t�H�[�J�X���ő�s�ɂ��Ă���
        hincode[6]->SetFocus();
        if (Application->MessageBox("���׍s���ő�ł�\r\n�o�^���Ă���낵���ł���?", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDNO)
        {
            PostWeighing();
        }
    }

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AnbunCalcAmountTax(int row)
{
   if (row != 0){
        int meig_id  = ToInt(DM->DBI.Lookup("M_�i��","�i�ڃR�[�h", hincode[row]->Text.ToIntDef(0), "�i��ID"));
        int item1_id = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
        int item2_id = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
        int tani_id  = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tanicode[row]->Text.ToIntDef(0), "�P��ID"));

        Currency quantity = StrToCurrDef(suryo[row]->Text, 0);

        if (!ToBit(DM->CFG["�P���g�p�敪"])){
            return;
        }

        Currency tankacode = StrToCurrDef(tanka[row]->Text, 0);
        Currency deftanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);

        if (tanka[row]->Text.IsEmpty()){
            tankacode = deftanka;
        }

        tanka[row]->Color = tankacode == deftanka ? TColor(0x00BEF4F5) : TColor(0x008080FF);

        //���z�[�������敪�̎擾
        int amount_div = -1;
        int amount_fig = 0;

        if (!toku_rec_.empty()){
            if (!IsNull(toku_rec_["���z�[�������敪"]))
                amount_div = ToInt(toku_rec_["���z�[�������敪"]);
        }

        if (amount_div == -1){
            amount_div = ToInt(DM->CFG["���z�[�������敪"]);
        }
        if (amount_fig == 0)
            amount_fig = ToInt(DM->CFG["���z�[����������"]);

        int amount = ExtendedRound(quantity * tankacode, amount_fig, amount_div);

        tanka[row]->Text   = tankacode;
        kingaku[row]->Text = amount;

        //////////////////////////////////////////////////////////////
        //�����

        Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));

        int sum_money = 0;
        int sum_tax   = 0;
        //����Œ[�������敪�̎擾
        int tax_fig = 0;
        int tax_div = -1;

        if (!toku_rec_.empty()) {
            if (!IsNull(toku_rec_["����Œ[�������敪"]))
                tax_div = ToInt(toku_rec_["����Œ[�������敪"]);
        }

        amount = 0;
        tax_total_ = 0;

        for (int i = 1; i < 7; i++){
            if (kingaku[i]->Text == "") {
                continue;
            }

            amount      =   StrToIntDef(kingaku[i]->Text, 0);
            tax_total_  =   int(ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div));

            if (shouhi[0]->Visible == true){
                shouhi[i]->Text = IntToStr(tax_total_);
            }
        }

    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AnbunCalcChousei(int row, int carrytype)
{
    Currency Shomi   =   StrToCurrDef(shomi[row]->Text,0);
    Currency Weight1 =   StrToCurrDef(weight1[row]->Text,0);
    Currency Chosei  =   StrToCurrDef(choweight[row]->Text, 0);
    Currency Bikiweight   =   StrToCurrDef(bikiweight[row]->Text, 0);
    Currency result  = 0;

    // ���� = 1, ���o = 2
    if (carrytype == 1){//����
        result = (Weight1 - (Shomi + Chosei + Bikiweight));
    }else if (carrytype == 2){//���o
        result = (Weight1 + (Shomi + Chosei + Bikiweight));
    }

    weight2[row]->Text      = AnsiString(result);
    weight1[row + 1]->Text  = AnsiString(result);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetHinmoku()
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT �i�ڃR�[�h, �i�ڗ���, �����o�敪���� AS �����o, ����敪���� AS ����敪 FROM V_�i�� WHERE �g�p�敪 = 1";
	SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
	SearchForm->table_name = "V_�i��";
	if (SearchForm->ShowModal() != mrOk)
		return;
	int row = GetRowNo();
	if (row == 0)
		return;
	hincode[row]->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
	hincode[row]->OnChange(NULL);
	hincode[row]->SetFocus();
}
//---------------------------------------------------------------------------

