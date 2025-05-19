//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include <memory>
#include <fstream>
#include <StrUtils.hpp>
#include <DateUtils.hpp>
#include "DMFrm.h"
#include "nsoftfunc.h"
#include "N95BatchThread.h"
#include "DivideDateFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner), thread_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 5;
    ProgressBar->Step     = 1;

	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�

	if (!DM->Init())
		Close();

    port_ = ToInt(DM->INI["Batch::Port"]);
    def_  = ToString(DM->INI["Batch::Def"]);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseButtonClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ImportButtonClick(TObject *Sender)
{
    // ��M�J�n

    ImportButton->Enabled = false;
    CloseButton->Enabled  = false;

    received_rec_.clear();
    CountLabel->Caption   = "0";
    ProgressBar->Position = 0;
    ProgressBar->Max      = 5;
    ProgressBar->Step     = 1;
    
    thread_ = new TN95BatchThread(false, port_, def_, Handle);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnCompleted(TMessage& message)
{
	StatusLabel->Caption = "�������܂���";

    delete thread_;
    thread_ = 0;

	std::ofstream ofs("batchimport.log");
	for (unsigned int i = 0; i < received_rec_.size(); i++){
		ofs << received_rec_[i].c_str() << std::endl;
	}

    // �`�[�ԍ����o
    no_date_map_.clear();
    int no;
    int today = Now().FormatString("yyyymmdd").ToInt();
    for (unsigned int i = 0; i < received_rec_.size(); i++){
    	no = AnsiString(received_rec_[i].c_str()).SubString(9, 3).ToIntDef(0);
		no_date_map_[no] = today;
    }

    int r1from = 0, r1to = 0;
    int r2from = 0, r2to = 0;
    if (no_date_map_.find(999) != no_date_map_.end()){		// 999 ������

    	// 999 �ȉ��ōŏ��̐���T��
    	for (int i = 999; i > 0; i--){
			if (no_date_map_.find(i) == no_date_map_.end())
            	break;
            r1from = i;
        }

		r1to   = 999;
        r2from = 1;

        // 1�ȏ�ōő�̐���T��
        for (int i = 1; i < 1000; i++){
        	if (no_date_map_.find(i) == no_date_map_.end())
            	break;
            r2to = i;
        }
    }else{
    	r1from = no_date_map_.begin()->first;
        std::map <int, int>::iterator last = no_date_map_.end();
        last--;
        r1to   = last->first;
    }

    // ���t���͉��
    DivideDateForm->SetNoRange(r1from, r1to, r2from, r2to);
    if (DivideDateForm->ShowModal() != mrOk){
    	CloseButton->Enabled = true;
    	return;
    }

    // �`�[�ԍ��Ɠ��t�̊֘A�e�[�u���쐬
    no_date_map_.clear();
    for (NRDates::iterator i = DivideDateForm->NoRangeDates.begin(); i != DivideDateForm->NoRangeDates.end(); i++){
    	for (int no = i->from; no <= i->to; no++){
        	no_date_map_[no] = i->date;
        }
    }

    // �f�[�^�R���o�[�g
    for (unsigned int i = 0; i < received_rec_.size(); i++){
        PostRecord(received_rec_[i]);
    }

    Application->MessageBox("��M���������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	CloseButton->Enabled = true;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::PostRecord(AnsiString record)
{
    AnsiString sql;

    TDateTime now(Now());

    int place_id = ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", ToInt(DM->INI["Place::Code"]), "���_ID"));

    NsFieldSet fields, keys;
    NsRecordSet set;

    AnsiString buff = record;

    int car_no     = buff.SubString(14, 6).Trim().ToIntDef(0);

    buff = AnsiReplaceStr(record, " ", "0");

    int no         = buff.SubString( 9, 3).ToIntDef(0);
    int item1_code = buff.SubString(21, 3).ToIntDef(0);
    int item2_code = buff.SubString(25, 3).ToIntDef(0);
    int item3_code = buff.SubString(29, 3).ToIntDef(0);
    int item4_code = buff.SubString(33, 3).ToIntDef(0);
    int weight1    = buff.SubString(36, 8).ToIntDef(0);
    int hhnn1      = buff.SubString(44, 4).ToIntDef(0);
    int weight2    = buff.SubString(48, 8).ToIntDef(0);
    int hhnn2      = buff.SubString(56, 4).ToIntDef(0);
    int net        = buff.SubString(73, 7).ToIntDef(0);

    int date = no_date_map_[no];
    if (!date)
    	return false;

    keys.clear();
    keys << NsField("�v�ʓ�", date)
         << NsField("���_ID", place_id)
         << NsField("�`�[No", no);

    if (DM->DBI.IsExist("D_�v��", keys))
        return true;

    ////////////////////////////////////////////////////////////////////////////
    // �w���v�� ScaM �̍��ڊ��蓖�ă}�b�s���O
    std::map<int, int> cnv_table;   // map<AD4385����, ScM�}�X�^>
    cnv_table[1] = ToInt(DM->CFG["�w���v���ڂP"]);
    cnv_table[2] = ToInt(DM->CFG["�w���v���ڂQ"]);
    cnv_table[3] = ToInt(DM->CFG["�w���v���ڂR"]);
    cnv_table[4] = ToInt(DM->CFG["�w���v���ڂS"]);
    for (int i = 1; i <= 4; i++){
        if (cnv_table[i] < 1 || cnv_table[i] > 4)
            cnv_table[i] = 0;
    }

    std::map<int, int *> scm_codes;
    int dummy, scm_toku_cd, scm_item1_cd, scm_item2_cd, scm_meig_cd;
    scm_codes[0] = &dummy;
    scm_codes[1] = &scm_toku_cd;
    scm_codes[2] = &scm_item1_cd;
    scm_codes[3] = &scm_item2_cd;
    scm_codes[4] = &scm_meig_cd;

    *(scm_codes[cnv_table[1]]) = item1_code;
    *(scm_codes[cnv_table[2]]) = item2_code;
    *(scm_codes[cnv_table[3]]) = item3_code;
    *(scm_codes[cnv_table[4]]) = item4_code;

    ////////////////////////////////////////////////////////////////////////////
    // �}�X�^����
    int scm_toku_id, scm_item1_id, scm_item2_id, scm_meig_id;
    NsRecordSet toku_set, item1_set, item2_set, meig_set;

    sql = "SELECT * FROM V_���Ӑ� WHERE ���Ӑ�R�[�h = " + IntToStr(scm_toku_cd);
    if (DM->DBI.GetRecordSet(sql, toku_set))
        scm_toku_id = ToInt(SET_TOP(toku_set)["���Ӑ�ID"]);
    else
        scm_toku_id = 0;
    sql = "SELECT * FROM V_����1 WHERE ����1�R�[�h = " + IntToStr(scm_item1_cd);
    if (DM->DBI.GetRecordSet(sql, item1_set))
        scm_item1_id = ToInt(SET_TOP(item1_set)["����1ID"]);
    else
        scm_item1_id = 0;
    sql = "SELECT * FROM V_����2 WHERE ����2�R�[�h = " + IntToStr(scm_item2_cd);
    if (DM->DBI.GetRecordSet(sql, item2_set))
        scm_item2_id = ToInt(SET_TOP(item2_set)["����2ID"]);
    else
        scm_item2_id = 0;
    sql = "SELECT * FROM V_�i�� WHERE �i�ڃR�[�h = " + IntToStr(scm_meig_cd);
    if (DM->DBI.GetRecordSet(sql, meig_set))
        scm_meig_id = ToInt(SET_TOP(meig_set)["�i��ID"]);
    else
        scm_meig_id = 0;

    ////////////////////////////////////////////////////////////////////////////
    // �ԗ��̌����i�Ȃ���΍쐬�j
    int car_id;
    sql = " SELECT �ԗ�ID FROM M_�ԗ� WHERE �Ԕ� = " + IntToStr(car_no) + " AND �g�p�敪 = 1";
    if (DM->DBI.GetRecordSet(sql, set)){
        car_id = ToInt(SET_TOP(set)["�ԗ�ID"]);
    }else{
        fields.clear();
        fields << NsField("[�Ԕ�]",     car_no)
               << NsField("[�ԗ�����]", "��M�������o�^")
               << NsField("[�g�p�敪]", 1)
               << NsField("[�X�V����]", now)
               << NsField("[�쐬����]", now);
        DM->DBI.Insert("M_�ԗ�", fields);
        car_id = DM->DBI.GetLastID();
    }

    ////////////////////////////////////////////////////////////////////////////
    // �v�ʓ����̎擾
    TDateTime time1 = EncodeDateTime(date / 10000, (date % 10000) / 100, date % 100, hhnn1 / 100, hhnn1 % 100, 0, 0);
    TDateTime time2 = EncodeDateTime(date / 10000, (date % 10000) / 100, date % 100, hhnn2 / 100, hhnn2 % 100, 0, 0);

    ////////////////////////////////////////////////////////////////////////////
    // �P�ʁA���ʁA���z

    int tani_id   = DM->GetKanzanID(scm_toku_id, scm_meig_id);
    int tani_code = DM->DBI.Lookup("M_�P��", "�P��ID", tani_id, "�P�ʃR�[�h");
	Currency net_ton = Currency(net) / Currency(1000);
	Currency quantity;
	Currency cnv_ratio = DM->GetKanzan(scm_toku_id, scm_meig_id, tani_id);

	int cnv_div = -1;
	if (!toku_set.empty()){
		if (!IsNull(SET_TOP(toku_set)["���Z�[�������敪"]))
			cnv_div = ToInt(SET_TOP(toku_set)["���Z�[�������敪"]);
	}
	if (cnv_div == -1)
		cnv_div = ToInt(DM->CFG["���Z�[�������敪"]);

	if (cnv_ratio == 0){
		quantity = ExtendedRound(net_ton,             ToInt(DM->CFG["���Z�[����������"]), cnv_div);
	}else{
		quantity = ExtendedRound(net_ton / cnv_ratio, ToInt(DM->CFG["���Z�[����������"]), cnv_div);
	}

    if (quantity > ToCurrency(DM->CFG["���m3����"]) && tani_code == 2){
        quantity = ToCurrency(DM->CFG["���m3����"]);
    }

	Currency tanka    = DM->GetTanka(scm_toku_id, scm_meig_id, scm_item1_id, scm_item2_id, tani_id);

	int amount_div = -1;
	if (!toku_set.empty()){
		if (!IsNull(SET_TOP(toku_set)["���z�[�������敪"]))
			amount_div = ToInt(SET_TOP(toku_set)["���z�[�������敪"]);
	}
	if (amount_div == -1)
		amount_div = ToInt(DM->CFG["���z�[�������敪"]);

	int amount = ExtendedRound(quantity * tanka, 0, amount_div);

	Currency tax_rate = DM->GetSalesTax();			// ����ŗ�

	int tax_div = -1;
	if (!toku_set.empty()){
		if (!IsNull(SET_TOP(toku_set)["����Œ[�������敪"]))
			tax_div = ToInt(SET_TOP(toku_set)["����Œ[�������敪"]);
	}
	if (tax_div == -1)
		tax_div = ToInt(DM->CFG["����Œ[�������敪"]);

	int tax    = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

    AnsiString null;

    /////
    try{
    /////

    DM->ADOConnection->BeginTrans();

    fields.clear();
    fields << NsField("[�v�ʓ�]",       date)
           << NsField("[���_ID]",       place_id)
           << NsField("[�`�[No]",       no)
           << NsField("[�����o�敪]",   scm_meig_id ? ToInt(SET_TOP(meig_set)["�����o�敪"]) : 0)
           << NsField("[�ԗ�ID]",       car_id)
           << NsField("[���Ӑ�ID]",     scm_toku_id)
           << NsField("[���Ӑ於��]",   scm_toku_id ? ToString(SET_TOP(toku_set)["���Ӑ於��"]) : null)
           << NsField("[����1ID]",      scm_item1_id)
           << NsField("[����1����]",    scm_item1_id ? ToString(SET_TOP(item1_set)["����1����"]) : null)
           << NsField("[����2ID]",      scm_item2_id)
           << NsField("[����2����]",    scm_item2_id ? ToString(SET_TOP(item2_set)["����2����"]) : null)
           << NsField("[�sNo]",         1)
           << NsField("[�i��ID]",       scm_meig_id)
           << NsField("[�i�ږ���]",     scm_meig_id ? ToString(SET_TOP(meig_set)["�i�ږ���"]) : null)
           << NsField("[1��ڏd��]",    weight1)
           << NsField("[�v�ʓ���1]",    time1)
           << NsField("[2��ڏd��]",    weight2)
           << NsField("[�v�ʓ���2]",    time2)
           << NsField("[�����d��]",     net)
           << NsField("[����]",         quantity)
           << NsField("[�P��ID]",       tani_id)
           << NsField("[�P��]",         tanka)
           << NsField("[���z]",         amount)
           << NsField("[�`�[����Ŋz]", tax)
           << NsField("[����Ŋz]",     tax)
           << NsField("[�����敪]",     1)
           << NsField("[�X�V����]",     now)
           << NsField("[�쐬����]",     now)
           ;

    DM->DBI.Insert("D_�v��", fields);

    int keiryo_id = DM->DBI.GetLastID();

    // ����f�[�^�쐬
    keys.clear();
    keys << NsField("�����", date)
         << NsField("���_ID", place_id)
         << NsField("�`�[No", no);

    if (!DM->DBI.IsExist("D_���", keys)){
        fields.clear();
        fields << NsField("[�����]",       date)
               << NsField("[���_ID]",       place_id)
               << NsField("[�`�[No]",       no)
               << NsField("[�v��ID]",       keiryo_id)
               << NsField("[����敪]",     ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", scm_meig_id, "����敪")))
               << NsField("[�ԗ�ID]",       car_id)
               << NsField("[���Ӑ�ID]",     scm_toku_id)
               << NsField("[���Ӑ於��]",   scm_toku_id ? ToString(SET_TOP(toku_set)["���Ӑ於��"]) : null)
               << NsField("[����1ID]",      scm_item1_id)
               << NsField("[����1����]",    scm_item1_id ? ToString(SET_TOP(item1_set)["����1����"]) : null)
               << NsField("[����2ID]",      scm_item2_id)
               << NsField("[����2����]",    scm_item2_id ? ToString(SET_TOP(item2_set)["����2����"]) : null)
               << NsField("[�sNo]",         1)
               << NsField("[�i��ID]",       scm_meig_id)
               << NsField("[�i�ږ���]",     scm_meig_id ? ToString(SET_TOP(meig_set)["�i�ږ���"]) : null)
               << NsField("[����]",         quantity)
               << NsField("[�P��ID]",       tani_id)
               << NsField("[�P��]",         tanka)
               << NsField("[���z]",         amount)
               << NsField("[�`�[����Ŋz]", tax)
               << NsField("[����Ŋz]",     tax)
               << NsField("[�����敪]",     1)
               << NsField("[�X�V����]",     now)
               << NsField("[�쐬����]",     now)
               ;

        DM->DBI.Insert("D_���", fields);
    }

    DM->ADOConnection->CommitTrans();
    /////
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();
        AnsiString msg = "�f�[�^�o�^���ɃG���[���������܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
        return false;
    }
    /////
    return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnAborted(TMessage& message)
{
    Application->MessageBox("�f�[�^��M�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);

    ImportButton->Enabled = true;
	CloseButton->Enabled = true;

    delete thread_;
    thread_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnStatus(TMessage& message)
{
	StatusLabel->Caption = (LPCSTR)(message.LParam);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnDataReceived(TMessage& message)
{
	received_rec_.push_back((LPCSTR)(message.LParam));
	CountLabel->Caption = IntToStr(received_rec_.size());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OnProcessStep(TMessage& message)
{
    ProgressBar->StepIt();
}
//---------------------------------------------------------------------------

