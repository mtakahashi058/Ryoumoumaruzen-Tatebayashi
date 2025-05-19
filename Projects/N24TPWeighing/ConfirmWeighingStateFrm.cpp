//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfirmWeighingStateFrm.h"
#include "DMFrm.h"
#include "n24tp.h"
#include <mmsystem.h>
#include <cstdlib>
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfirmWeighingStateForm *ConfirmWeighingStateForm;
//---------------------------------------------------------------------------
__fastcall TConfirmWeighingStateForm::TConfirmWeighingStateForm(TComponent* Owner)
	: AbstractStateForm(Owner),current_weight_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::ConfirmWeighing, this);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::OnEnter()
{
	WarningMemo->Lines->Clear();
	ContinueButton->Enabled = true;
	CompleteButton->Enabled = true;

	SFM.AddLog("�v�ʊm�F��� �ԗ�ID/�Ԕ�: " + ToString(SFM.Stashed("�ԗ�ID")) + "/" + ToString(SFM.car_rec["�Ԕ�"]));

	///////////////////////////////////////////////
    int last_w;
    int curr_w = ToInt(SFM.Stashed("Weight"));

	DBGrid->Columns->Items[0]->Title->Caption = ToString(DM->CFG["�i�ڃ}�X�^����"]);

	// �v�ʓ��e Grid
	if (SFM.stash.find("�v��ID") != SFM.stash.end()){
		if (GridQuery->Active)
			GridQuery->Close();
		GridQuery->SQL->Text = " SELECT �i�ڗ���, �����d�� FROM V_�v��"
                               " WHERE �ԗ�ID = " + ToString(SFM.Stashed("�ԗ�ID")) + " AND �����敪 = 0 AND �����d�� > 0"
                               " ORDER BY �sNo";
		GridQuery->Open();
	}else{
		GridQuery->Close();
	}

    if (ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"])){
		MeigPanel->Visible         = true;
		MeigChangeButton->Visible  = true;
	}else{
		MeigPanel->Visible         = false;
		MeigChangeButton->Visible  = false;
    }

	if (ToBit(SFM.Stashed("1��v��"))){
		// 1��v��

		// �p���Ȃ��A�������m�F�ɕύX�A�O���b�h�Ȃ�
		ContinueButton->Enabled = false;
		ContinueButton->Visible = false;
		CompleteButton->Caption = "�m�F";

		if (!ToBit(SFM.Stashed("�i�ڑI��")))
            MeigChangeButton->Enabled = false;
        else
            MeigChangeButton->Enabled = true;

        last_w = ToInt(SFM.car_rec["��ԏd��"]);
	}else{
		if (ToBit(SFM.Stashed("�i�ڑI��"))){
			MeigChangeButton->Enabled  = true;
		}

        if (IsNull(SFM.remained_rec["�v�ʓ���2"])){       // �P���ז�
            last_w = ToInt(SFM.remained_rec["1��ڏd��"]);
        }else{
            last_w = ToInt(SFM.remained_rec["2��ڏd��"]);
        }

        int last_lineno = ToInt(SFM.remained_rec["�sNo"]);

		// [INI] Keiryo::MaxDetails
        int max_details = ToInt(DM->INI["Keiryo::MaxDetails"]) - 1;

        // [CFG]
        if (ToInt(DM->CFG["�P�i���i�敪"]) == 1)
            max_details = 0;

		if (last_lineno >= max_details){
			if (last_lineno == 0){
				CompleteButton->Caption = "�m�F";
			}else{
				CompleteButton->Caption = "����";
			}
			ContinueButton->Enabled = false;
			ContinueButton->Visible = false;
		}else{
			ContinueButton->Enabled = true;
			ContinueButton->Visible = true;
			CompleteButton->Caption = "����";
		}
	}

	int gross_w = std::max(last_w, curr_w);
	int tare_w  = std::min(last_w, curr_w);
	int net_w   = gross_w - tare_w;
    current_weight_ = curr_w;

	CarNoLabel->Caption = ToString(SFM.Stashed("�Ԕ�"));
    TokuLabel->Caption  = ToString(SFM.Stashed("���Ӑ旪��"));
	Item1Label->Caption = ToString(SFM.Stashed("����1����"));
	Item2Label->Caption = ToString(SFM.Stashed("����2����"));
	MeigPanel->Caption  = ToString(SFM.Stashed("�i�ڗ���"));

	NetWeightPanel->Caption = FormatFloat("###,##0 ", net_w);

	int limit_weight;
	limit_weight = ToInt(SFM.car_rec["�ԗ����d��"]);
	if (gross_w > limit_weight && limit_weight){
		WarningMemo->Lines->Append("���d�ʒ��߂ł��B�v�ʂł��܂���B");
		ContinueButton->Enabled = false;
		CompleteButton->Enabled = false;
		PlaySound(ToString(DM->Sounds["OverWeight"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

	    SFM.PatliteAlert(false, true);
	}
	limit_weight = ToInt(SFM.car_rec["�ő�ύڗ�"]);
	if (net_w > limit_weight && limit_weight){
		WarningMemo->Lines->Append("�����d�ʒ��߂ł��B�v�ʂł��܂���B");
		ContinueButton->Enabled = false;
		CompleteButton->Enabled = false;
		PlaySound(ToString(DM->Sounds["OverWeight"]).c_str(), 0, SND_ASYNC | SND_FILENAME);

	    SFM.PatliteAlert(false, true);
	}

	if (CompleteButton->Enabled)
		PlaySound(ToString(DM->Sounds["Weighing"]).c_str(), 0, SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::OnExit()
{
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::ContinueButtonClick(
	  TObject *Sender)
{
	try{
		DM->ADOConnection->BeginTrans();

        PostRecord(false);

		DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		DM->ADOConnection->RollbackTrans();
		AnsiString message = "DB�G���[: " + e.Message;
		SFM.SendStatus(message);

		SFM.PatliteAlert(false, true);
		return;
	}

	SFM.PatliteAlert(true, false);
	SFM.Transit(State::ConfirmContinuation);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::CompleteButtonClick(
	  TObject *Sender)
{
	try{
		DM->ADOConnection->BeginTrans();

		PostRecord(true);

		DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
		DM->ADOConnection->RollbackTrans();
		AnsiString message = "DB�G���[: " + e.Message;
		SFM.SendStatus(message);

		SFM.PatliteAlert(false, true);
		return;
	}

	SFM.PatliteAlert(true, false);
	SFM.Transit(State::ConfirmPrint);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::PostRecord(bool complete)
{
	// �g�����U�N�V�����͂��̏�ł�����

	if (!DM->ADOConnection->InTransaction)
		throw Exception("[PGE] �g�����U�N�V�������J�n����Ă��܂���");

	NsFieldSet fields;
	TDateTime now(Now());
	int date = now.FormatString("yyyymmdd").ToInt();

    int cur_weight = current_weight_;

    int keiryo_id = 0;
    int last_w;
    int toku_id;
    int meig_id;
    int item1_id;
    int item2_id;
    int net;
    int old_date, old_no;
    int lineno = 1;

	if (ToBit(SFM.Stashed("1��v��"))){
        old_date = date;
        old_no   = DM->GetTempKeiryoNo();
        last_w   = ToInt(SFM.car_rec["��ԏd��"]);
        toku_id  = ToInt(SFM.Stashed("���Ӑ�ID"));
        meig_id  = ToInt(SFM.Stashed("�i��ID"));
        item1_id = ToInt(SFM.Stashed("����1ID"));
        item2_id = ToInt(SFM.Stashed("����2ID"));

        ///// �ԗ��̃`�F�b�N
        int car_id = ToInt(SFM.Stashed("�ԗ�ID"));
        int car_no = ToInt(SFM.Stashed("�Ԕ�"));
        if (ToBit(SFM.Stashed("�V�ԗ�")) && car_no){
            AnsiString sql;
            NsRecordSet set;

            sql = " SELECT TOP 1 �ԗ�ID FROM M_�ԗ�"
                  " WHERE �Ԕ� = " + IntToStr(car_no) +
                  "   AND (�J�[�h�ԍ� = 0 OR �J�[�h�ԍ� IS NULL)";
            if (DM->DBI.GetRecordSet(sql, set)){
                car_id = ToInt(SET_TOP(set)["�ԗ�ID"]);
            }else{
                ///// �ԗ��}�X�^�o�^
                fields << NsField("[�Ԕ�]",     car_no)
                       << NsField("[�ԗ�����]", now.FormatString("mm/dd'�Ɏ����v��'"))
                       << NsField("[�X�V����]", now)
                       << NsField("[�쐬����]", now);
                DM->DBI.Insert("M_�ԗ�", fields);
                car_id = DM->DBI.GetLastID();
            }
        }

        fields.clear();
        fields
            << NsField("[�v�ʓ�]",       old_date)
            << NsField("[���_ID]",       N24TP::place_id)
            << NsField("[�`�[No]",       old_no)
            << NsField("[�sNo]",         1)
            << NsField("[�ԗ�ID]",       car_id)
            << NsField("[�J�[�h�ԗ�ID]", ToInt(SFM.Stashed("�J�[�h�ԗ�ID")))
            << NsField("[���Ӑ�ID]",     toku_id)
            << NsField("[���Ӑ於��]",   ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", toku_id,  "���Ӑ於��")))
            << NsField("[����1ID]",      item1_id)
            << NsField("[����1����]",    ToString(DM->DBI.Lookup("M_����1",  "����1ID",  item1_id, "����1����")))
            << NsField("[����2ID]",      item2_id)
            << NsField("[����2����]",    ToString(DM->DBI.Lookup("M_����2",  "����2ID",  item2_id, "����2����")))
            << NsField("[1��ڏd��]",    last_w)
            << NsField("[�v�ʓ���1]",    Variant())
            << NsField("[�쐬����]",     now)
            ;
        net = std::abs(cur_weight - last_w);

	}else{  // ���v�ʈȊO

        int last_w;

        old_date = ToInt(SFM.remained_rec["�v�ʓ�"]);
        old_no   = ToInt(SFM.remained_rec["�`�[No"]);

        //if (SFM.Stashed("�sNo") == 1){                  // �P���ז�
        if (IsNull(SFM.remained_rec["�v�ʓ���2"])){       // �P���ז�
            keiryo_id           = ToInt(SFM.Stashed("�v��ID"));
            last_w              = ToInt(SFM.remained_rec["1��ڏd��"]);
            SFM.stash["�V�sNo"] = ToInt(SFM.remained_rec["�sNo"]);
        }else{
            lineno = DM->GetNextDetailNo(ToInt(SFM.Stashed("�v��ID")));
            fields
                << NsField("[�v�ʓ�]",       ToInt(SFM.remained_rec["�v�ʓ�"]))
                << NsField("[���_ID]",       N24TP::place_id)
                << NsField("[�`�[No]",       ToInt(SFM.remained_rec["�`�[No"]))
                << NsField("[�sNo]",         lineno)
                << NsField("[�ԗ�ID]",       ToInt(SFM.remained_rec["�ԗ�ID"]))
                << NsField("[�J�[�h�ԗ�ID]", ToInt(SFM.Stashed("�J�[�h�ԗ�ID")))
                << NsField("[���Ӑ�ID]",     ToInt(SFM.remained_rec["���Ӑ�ID"]))
        		<< NsField("[���Ӑ於��]",   ToString(SFM.remained_rec["���Ӑ於��"]))
                << NsField("[����1ID]",      ToInt(SFM.remained_rec["����1ID"]))
                << NsField("[����1����]",    ToString(SFM.remained_rec["����1����"]))
                << NsField("[����2ID]",      ToInt(SFM.remained_rec["����2ID"]))
                << NsField("[����2����]",    ToString(SFM.remained_rec["����2����"]))
                << NsField("[1��ڏd��]",    ToInt(SFM.remained_rec["2��ڏd��"]))
                << NsField("[�v�ʓ���1]",    SFM.remained_rec["�v�ʓ���2"])
                << NsField("[�쐬����]",     now)
                ;
            last_w              = ToInt(SFM.remained_rec["2��ڏd��"]);
            SFM.stash["�V�sNo"] = lineno;
        }

        toku_id  = ToInt(SFM.remained_rec["���Ӑ�ID"]);
        meig_id  = ToInt(SFM.Stashed("�i��ID"));
        item1_id = ToInt(SFM.remained_rec["����1ID"]);
        item2_id = ToInt(SFM.remained_rec["����2ID"]);
        net = std::abs(cur_weight - last_w);
    }

    NsRecord toku_rec, item1_rec;
    DM->GetViewRec("���Ӑ�", toku_id,  toku_rec);
    DM->GetViewRec("����1",  item1_id, item1_rec);

	///// �d�ʒ�����
    Currency adj_per = 0;
    int adj_weight   = 0;

	adj_per    = ToCurrency(DM->DBI.Lookup("M_�i��", "�i��ID", meig_id, "�d�ʒ�����"));
	if (adj_per != 0){
	    adj_per   /= 100;

	    ///// �����[�������敪�̎擾
    	int cnv_div = -1;

	    if (!toku_rec.empty()){
    	    if (!IsNull(toku_rec["�����[�������敪"]))
        	    cnv_div = ToInt(toku_rec["�����[�������敪"]);
	    }
    	if (cnv_div == -1)
        	cnv_div = ToInt(DM->CFG["�����[�������敪"]);

   	    adj_weight = ExtendedRound(Currency(net) * adj_per, ToInt(DM->CFG["�����[����������"]), cnv_div);

        net -= adj_weight;
    }

    fields
        << NsField("[�i��ID]",     meig_id)
        << NsField("[�i�ږ���]",   ToString(DM->DBI.Lookup("M_�i��", "�i��ID", ToInt(SFM.Stashed("�i��ID")), "�i�ږ���")))
        << NsField("[�����o�敪]", ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", ToInt(SFM.Stashed("�i��ID")), "�����o�敪")))
        << NsField("[2��ڏd��]",  cur_weight)
        << NsField("[�v�ʓ���2]",  now)
        << NsField("[������]",     adj_per)
        << NsField("[�����d��]",   adj_weight)
        << NsField("[�����d��]",   net)
        << NsField("[�����敪]",   0)
        << NsField("[�X�V����]",   now)
        ;

    //////////////////////////////////////////////////////////////////////
    // �P�ʂ̎擾

    int tani_code = DM->GetKanzanCode(toku_id, meig_id);
    int tani_id = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", tani_code, "�P��ID"));
    fields << NsField("[�P��ID]",     tani_id);

    //////////////////////////////////////////////////////////////////////
    // ��������z���̌v�Z

	Currency quantity;
	if (tani_id == 3)
		quantity = Currency(net);
	else
		quantity = Currency(net) / Currency(1000);
	Currency cnv_ratio = DM->GetKanzan(toku_id, meig_id, tani_id);

    ///// ���Z�[�������敪�̎擾
    int cnv_div = -1;

    if (!toku_rec.empty()){
        if (!IsNull(toku_rec["���Z�[�������敪"]))
            cnv_div = ToInt(toku_rec["���Z�[�������敪"]);
    }
    if (cnv_div == -1)
        cnv_div = ToInt(DM->CFG["���Z�[�������敪"]);
    /////

    if (cnv_ratio == 0){
        quantity = ExtendedRound(quantity,             ToInt(DM->CFG["���Z�[����������"]), cnv_div);
    }else{
        quantity = ExtendedRound(quantity / cnv_ratio, ToInt(DM->CFG["���Z�[����������"]), cnv_div);
    }

    fields << NsField("[����]",     quantity);

    Currency tanka = DM->GetTanka(toku_id, meig_id, item1_id, item2_id, tani_id);
    int amount, tax;

    ///// ���z�[�������敪�̎擾
    int amount_div = -1;

    if (!toku_rec.empty()){
        if (!IsNull(toku_rec["���z�[�������敪"]))
            amount_div = ToInt(toku_rec["���z�[�������敪"]);
    }
    if (amount_div == -1)
        amount_div = ToInt(DM->CFG["���z�[�������敪"]);
    /////

    amount = ExtendedRound(quantity * tanka, 0, amount_div);

    Currency tax_rate = DM->GetSalesTax();			// ����ŗ�

    ///// ����Œ[�������敪�̎擾
    int tax_div = -1;

    if (!toku_rec.empty()){
        if (!IsNull(toku_rec["����Œ[�������敪"]))
            tax_div = ToInt(toku_rec["����Œ[�������敪"]);
    }
    if (tax_div == -1)
        tax_div = ToInt(DM->CFG["����Œ[�������敪"]);
    /////

    tax = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

    fields << NsField("[�P��]",         tanka)
           << NsField("[���z]",         amount)
           << NsField("[����Ŋz]",     tax)
           ;
           
    if (keiryo_id){
        DM->DBI.Update("D_�v��", "�v��ID", keiryo_id, fields);
    }else{
        DM->DBI.Insert("D_�v��", fields);
        keiryo_id = DM->DBI.GetLastID();
		SFM.stash["�v��ID"] = keiryo_id;	// 2012.07.13 �ǉ��i�쑺�j
    }

    {
        NsFieldSet keys;

        keys <<  NsField("�v�ʓ�", ToInt(SFM.remained_rec["�v�ʓ�"]))
             <<  NsField("���_ID", N24TP::place_id)
             <<  NsField("�`�[No", ToInt(SFM.remained_rec["�`�[No"]))
             <<  NsField("�sNo",   0);

        DM->DBI.Delete("D_�v��", keys);
    }

    if (!complete){     // �p��
        SFM.stash["�V�v��ID"] = keiryo_id;
    }else{              // ����
        NsFieldSet keys;
        keys << NsField("�v�ʓ�", old_date)
             << NsField("���_ID", N24TP::place_id)
             << NsField("�`�[No", old_no);

        // �v�ʓ��Ɠ`�[No, �`�[����ł͌v�ʊ�����ɍX�V��������
        int no = DM->GetNextKeiryoNo(date);
        fields.clear();
        fields << NsField("[�v�ʓ�]",       date)
               << NsField("[�`�[No]",       no)
               << NsField("[�`�[����Ŋz]", DM->GetTotalSalesTax(ToInt(SFM.remained_rec["�v�ʓ�"]), N24TP::place_id, ToInt(SFM.remained_rec["�`�[No"])))
               << NsField("[�����敪]",     1);

        int cnt = DM->DBI.Update("D_�v��", keys, fields);

        SFM.stash["�V�v��ID"] = DM->GetTopID(date, N24TP::place_id, no);

        CopyRecords(date, N24TP::place_id, no);
    }
}
//---------------------------------------------------------------------------
// �v�ʃf�[�^������f�[�^��
void __fastcall TConfirmWeighingStateForm::CopyRecords(int date, int place, int no)
{
    AnsiString sql = " SELECT * FROM D_�v��"
                     " WHERE �v�ʓ� = " + IntToStr(date) +
                     "   AND ���_ID = " + IntToStr(place) +
                     "   AND �`�[No = " + IntToStr(no);
    NsRecordSet set, meig_set;
    NsFieldSet fields;

    if (!DM->DBI.GetRecordSet(sql, set))
        return;

    int tran_div;
    int tran_no = DM->GetTransNo(ToInt(SET_TOP(set)["�v�ʓ�"]));
    TDateTime now(Now());
    for (unsigned int i = 0; i < set.size(); i++){
        sql = "SELECT ����敪 FROM M_�i�� WHERE �i��ID = " + IntToStr(ToInt(set[i]["�i��ID"]));
        if (!DM->DBI.GetRecordSet(sql, meig_set))
            tran_div = 1;
        else
            tran_div = ToInt(SET_TOP(meig_set)["����敪"]);

        fields.clear();
        fields
            << NsField("[�����]",       set[i]["�v�ʓ�"])
            << NsField("[���_ID]",       set[i]["���_ID"])
            << NsField("[�`�[No]",       tran_no)
            << NsField("[�v��ID]",       set[i]["�v��ID"])
            << NsField("[����敪]",     tran_div)
            << NsField("[�ԗ�ID]",       set[i]["�ԗ�ID"])
            << NsField("[���Ӑ�ID]",     set[i]["���Ӑ�ID"])
            << NsField("[���Ӑ於��]",   set[i]["���Ӑ於��"])
            << NsField("[����1ID]",      set[i]["����1ID"])
            << NsField("[����1����]",    set[i]["����1����"])
            << NsField("[����2ID]",      set[i]["����2ID"])
            << NsField("[����2����]",    set[i]["����2����"])
            << NsField("[���l]",         set[i]["���l"])
            << NsField("[�`�[����Ŋz]", set[i]["�`�[����Ŋz"])
            << NsField("[�sNo]",         set[i]["�sNo"])
            << NsField("[�i��ID]",       set[i]["�i��ID"])
            << NsField("[�i�ږ���]",     set[i]["�i�ږ���"])
            << NsField("[����]",         set[i]["����"])
            << NsField("[�P��ID]",       set[i]["�P��ID"])
            << NsField("[�P��]",         set[i]["�P��"])
            << NsField("[���z]",         set[i]["���z"])
            << NsField("[����Ŋz]",     set[i]["����Ŋz"])
            << NsField("[���ה��l]",     set[i]["���ה��l"])
            << NsField("[�����敪]",     set[i]["�����敪"])
            << NsField("[�X�V����]",     now)
            << NsField("[�쐬����]",     now)
            ;
        DM->DBI.Insert("D_���", fields);
    }
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::MeigChangeButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::SelectMeig);
}
//---------------------------------------------------------------------------
void __fastcall TConfirmWeighingStateForm::CancelButtonClick(
	  TObject *Sender)
{
	SFM.Transit(State::WaitCard);
}
//---------------------------------------------------------------------------


