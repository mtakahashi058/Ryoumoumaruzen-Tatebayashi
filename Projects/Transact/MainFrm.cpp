//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DataListFrm.h"
#include "MainFrm.h"
#include <mmsystem.h>
#include "ShabanSanshoFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "StrCGrid"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner), trans_id_(0)
{
    Application->OnMessage = MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
    TDBGrid *Grid = 0;
    
    switch (Msg.message){
    case WM_MOUSEWHEEL:
        if (Msg.hwnd == DataListForm->DBGrid->Handle)
            Grid = DataListForm->DBGrid;
        if (Msg.hwnd == SearchForm->DBGrid->Handle)
            Grid = SearchForm->DBGrid;
        if (Msg.hwnd == ShabanSanshoForm->DBGrid->Handle)
            Grid = ShabanSanshoForm->DBGrid;

        if (!Grid){
            TWinControl *wc;
            for (int i = 0; i < DataListForm->FilterPanel->ControlCount; i++){
                wc = dynamic_cast<TWinControl *>(DataListForm->FilterPanel->Controls[i]);
                if (!wc)
                    continue;
                if (wc->Handle == Msg.hwnd){
                    Grid = DataListForm->DBGrid;
                    break;
                }
            }
        }
        if (!Grid){
            TWinControl *wc;
            for (int i = 0; i < SearchForm->FilterPanel->ControlCount; i++){
                wc = dynamic_cast<TWinControl *>(SearchForm->FilterPanel->Controls[i]);
                if (!wc)
                    continue;
                if (wc->Handle == Msg.hwnd){
                    Grid = SearchForm->DBGrid;
                    break;
                }
            }
        }

        if (!Grid)
            return;

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
// MainForm->OnShow
void __fastcall TMainForm::FormShow(TObject *Sender)
{

	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�

	if (!DM->Init())
		Close();

	ApplyConfig();

	Resize();

    // DetailGrid �̐ݒ�
    DetailGrid->ColWidths[0] = 28;
    DetailGrid->Cells[0][1] = "1";
    DetailGrid->Cells[0][2] = "2";
    DetailGrid->Cells[0][3] = "3";
    DetailGrid->Cells[0][4] = "4";
    DetailGrid->Cells[0][5] = "5";
    DetailGrid->Cells[0][6] = "6";
    DetailGrid->ColWidths[1] = 48;
    DetailGrid->ColWidths[2] = 58;
    DetailGrid->ColWidths[3] = 282;
    DetailGrid->ColWidths[4] = 64;
    DetailGrid->ColWidths[5] = 42;
    DetailGrid->ColWidths[6] = 64;
    DetailGrid->ColWidths[7] = 97;
    DetailGrid->ColWidths[8] = 97;
    DetailGrid->ColWidths[9] = 154;

    KeiryoGrid->ColWidths[0] = 28;
    KeiryoGrid->Cells[0][1] = "1";
    KeiryoGrid->Cells[0][2] = "2";
    KeiryoGrid->Cells[0][3] = "3";
    KeiryoGrid->Cells[0][4] = "4";
    KeiryoGrid->Cells[0][5] = "5";
    KeiryoGrid->Cells[0][6] = "6";
    KeiryoGrid->ColWidths[1] = 58;

    int left = 2;
    for (int i = 0; i < 8; i++)
        left += DetailGrid->ColWidths[i] + 1;
    TankaUpdateButton->Left = left - TankaUpdateButton->Width - 1;

    DefTankaGrid->Cells[0][1] = "1";
    DefTankaGrid->Cells[0][2] = "2";
    DefTankaGrid->Cells[0][3] = "3";
    DefTankaGrid->Cells[0][4] = "4";
    DefTankaGrid->Cells[0][5] = "5";
    DefTankaGrid->Cells[0][6] = "6";

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
//	HinButton->Caption       = ToString(DM->CFG["�i�ڃ}�X�^����"]);

	if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
		Komoku1Panel->Visible         = false;
	}
	if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
		Komoku2Panel->Visible         = false;
	}

/** deleted
	if (!ToBit(DM->CFG["�����g�p�敪"])){
		ChoseiPanel->Visible          = false;
	}
	if (!ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
		JuryobikiPanel->Visible       = false;
	}
*/

	PlaceCombo->Items->Clear();
	if (!DM->DBI.GetRecordSet("SELECT ���_ID, ���_�R�[�h, ���_���� FROM M_���_", kyoten_set_)){
		Application->MessageBox("���_�}�X�^���ݒ肳��Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	for (unsigned int i = 0; i < kyoten_set_.size(); i++){
		PlaceCombo->Items->Append(ToString(kyoten_set_[i]["���_����"]));
	}

	int wild_code;

	wild_code = ToInt(DM->CFG["���Ӑ揔���R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_���Ӑ�", "���Ӑ�R�[�h", wild_code)){
		Application->MessageBox("���Ӑ揔���R�[�h�����Ӑ�}�X�^�ɓo�^����Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["�i�ڔ��������R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_�i��", "�i�ڃR�[�h", wild_code)){
		Application->MessageBox("�i�ڔ��������R�[�h���i�ڃ}�X�^�ɓo�^����Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["�i�ڔ��o�����R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_�i��", "�i�ڃR�[�h", wild_code)){
		Application->MessageBox("�i�ڔ��o�����R�[�h���i�ڃ}�X�^�ɓo�^����Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["����1�����R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_����1", "����1�R�[�h", wild_code)){
		Application->MessageBox("����1�����R�[�h������1�}�X�^�ɓo�^����Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	wild_code = ToInt(DM->CFG["����2�����R�[�h"]);
	if (wild_code && !DM->DBI.IsExist("M_����2", "����2�R�[�h", wild_code)){
		Application->MessageBox("����2�����R�[�h������2�}�X�^�ɓo�^����Ă��܂���B���͑O�ɐݒ肵�Ă�������",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}

}
//---------------------------------------------------------------------------
// ���_�R���{�{�b�N�X���� ID ���擾
int __fastcall TMainForm::GetPlaceID()
{
	return ToInt(kyoten_set_[PlaceCombo->ItemIndex]["���_ID"]);
}
//---------------------------------------------------------------------------
// ���_�R���{�{�b�N�X���狒�_�����擾
AnsiString __fastcall TMainForm::GetPlaceText()
{
    return PlaceCombo->Items->Strings[PlaceCombo->ItemIndex];
}
//---------------------------------------------------------------------------
// �[���}��
AnsiString __fastcall TMainForm::ZeroSuppress(Currency v)
{
	if (v == 0)
		return AnsiString();
	else
		return AnsiString(v);
}
//---------------------------------------------------------------------------
// �t�H�[�����N���A
void __fastcall TMainForm::ClearForm()
{
    trans_id_  = 0;
    trans_set_.clear();
    keiryo_id_ = 0;

	toku_id_      = 0;
	toku_rec_.clear();

	car_id_       = 0;

    total_zei_    = 0;
    deftanka_table_.clear();
    zei_table_.clear();
    sundry_table_.clear();

    TDateTime now(Now());
	int place_code  = ToInt(DM->INI["Default::PlaceCode"]);
    int place_index = 0;
    for (NsRecordSet::iterator i = kyoten_set_.begin(); i != kyoten_set_.end(); i++){
		if (ToInt((i->second)["���_�R�[�h"]) == place_code){
			place_index = i->first;
        }
	}
	PlaceCombo->ItemIndex = place_index;

	DatePicker->Date          = now;
	NoEdit->Text              = AnsiString();
	ShabanEdit->Text          = AnsiString();
	ShabanEdit->OnChange(NULL);
	TokuCodeEdit->Text        = AnsiString();
	TokuNameEdit->Text        = AnsiString();
	Komoku1CodeEdit->Text     = AnsiString();
	Komoku1NameEdit->Text     = AnsiString();
	Komoku2CodeEdit->Text     = AnsiString();
	Komoku2NameEdit->Text     = AnsiString();
	BikoEdit->Text            = AnsiString();

	KeiryoDate->Text          = AnsiString();
	KeiryoNo->Text            = AnsiString();

    DetailGrid->Col = 1;
    DetailGrid->Row = 1;

    for (int i = 0; i < 6; i++){
        DetailGrid->Cells[1][i + 1] = AnsiString();
        DetailGrid->Cells[2][i + 1] = AnsiString();
        DetailGrid->Cells[3][i + 1] = AnsiString();
        DetailGrid->Cells[4][i + 1] = AnsiString();
        DetailGrid->Cells[5][i + 1] = AnsiString();
        DetailGrid->Cells[6][i + 1] = AnsiString();
        DetailGrid->Cells[7][i + 1] = AnsiString();
        DetailGrid->Cells[8][i + 1] = AnsiString();
        DetailGrid->Cells[9][i + 1] = AnsiString();

        KeiryoGrid->Cells[1][i + 1] = AnsiString();
        KeiryoGrid->Cells[2][i + 1] = AnsiString();
        KeiryoGrid->Cells[3][i + 1] = AnsiString();
        KeiryoGrid->Cells[4][i + 1] = AnsiString();
        KeiryoGrid->Cells[5][i + 1] = AnsiString();
        KeiryoGrid->Cells[6][i + 1] = AnsiString();
        KeiryoGrid->Cells[7][i + 1] = AnsiString();
        KeiryoGrid->Cells[8][i + 1] = AnsiString();
    }
    DetailGrid->Col = 2;
    DetailGrid->Row = 1;
    DetailGrid->Invalidate();

    DefTankaGrid->Col = 1;
    DefTankaGrid->Row = 1;
    for (int i = 0; i < 6; i++){
        DefTankaGrid->Cells[1][i + 1] = AnsiString();
    }
    DefTankaGrid->Col = 1;
    DefTankaGrid->Row = 2;

    PageControl->ActivePage = TransSheet;

    UAmountLabel->Caption      = AnsiString();
    UTotalZeiLabel->Caption    = AnsiString();
    SAmountLabel->Caption      = AnsiString();
    STotalZeiLabel->Caption    = AnsiString();
}
//---------------------------------------------------------------------------
// ���ID ���烌�R�[�h����ǂݍ���
bool __fastcall TMainForm::LoadFromID(int id)
{
	AnsiString sql;
    NsRecordSet set;
	sql = " SELECT �����, ���_ID, �`�[No FROM V_���"
		  " WHERE"
		  " 	���ID = " + IntToStr(id) +
		  " AND"
		  " 	�����敪 <> 9";					// �_���폜�͑ΏۊO
    if (!DM->DBI.GetRecordSet(sql, set))
        return false;

    sql = " SELECT * FROM V_���"
          " WHERE"
          "     ����� = " + ToString(SET_TOP(set)["�����"]) +
          " AND"
          "     ���_ID = " + ToString(SET_TOP(set)["���_ID"]) +
          " AND"
          "     �`�[No = " + ToString(SET_TOP(set)["�`�[No"]) +
          " AND"
          "     �����敪 <> 9"
          " ORDER BY �sNo";
	if (!DM->DBI.GetRecordSet(sql, trans_set_))
		return false;

	DatePicker->Date             = IntToDate(ToInt(SET_TOP(trans_set_)["�����"]));
	NoEdit->Text                 = ToInt(SET_TOP(trans_set_)["�`�[No"]);

	car_id_                      = ToInt(SET_TOP(trans_set_)["�ԗ�ID"]);
	ShabanEdit->Text             = ZeroSuppress(ToInt(SET_TOP(trans_set_)["�Ԕ�"]));
	SharyoNameEdit->Text         = ToString(SET_TOP(trans_set_)["�ԗ�����"]);

	TokuCodeEdit->Text           = ZeroSuppress(ToInt(SET_TOP(trans_set_)["���Ӑ�R�[�h"]));
    TokuNameEdit->Text           = ToString(SET_TOP(trans_set_)["���Ӑ於��"]);
	Komoku1CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(trans_set_)["����1�R�[�h"]));
    Komoku1NameEdit->Text        = ToString(SET_TOP(trans_set_)["����1����"]);
	Komoku2CodeEdit->Text        = ZeroSuppress(ToInt(SET_TOP(trans_set_)["����2�R�[�h"]));
    Komoku2NameEdit->Text        = ToString(SET_TOP(trans_set_)["����2����"]);

	BikoEdit->Text               = ToString(SET_TOP(trans_set_)["���l"]);

    keiryo_id_ = ToInt(SET_TOP(trans_set_)["�v��ID"]);

    if (keiryo_id_){
        int date, place_id, no;
        if (!DM->GetKeiryoKey(keiryo_id_, date, place_id, no)){
            Application->MessageBox("�v�ʃf�[�^�̓ǂݍ��݂Ɏ��s���܂���", "����f�[�^�ǂݍ���", MB_OK | MB_ICONWARNING);
        }else{
            sql = " SELECT * FROM V_�v��"
                  " WHERE �v�ʓ� = " + IntToStr(date) +
                  "   AND ���_ID = " + IntToStr(place_id) +
                  "   AND �`�[No = " + IntToStr(no);
            DM->DBI.GetRecordSet(sql, set);

            KeiryoDate->Text = IntToDate(ToInt(SET_TOP(set)["�v�ʓ�"])).FormatString("yyyy/mm/dd");
            KeiryoNo->Text   = ToInt(SET_TOP(set)["�`�[No"]);

            for (unsigned int i = 0; i < set.size(); i++){
                KeiryoGrid->Cells[1][i + 1] = ToInt(set[i]["�i�ڃR�[�h"]);
                KeiryoGrid->Cells[2][i + 1] = ToString(set[i]["�i�ږ���"]);
                KeiryoGrid->Cells[3][i + 1] = ToCurrency(set[i]["����"]);
                KeiryoGrid->Cells[4][i + 1] = ToInt(set[i]["�P�ʃR�[�h"]);
                KeiryoGrid->Cells[5][i + 1] = ToString(set[i]["�P�ʃ}�X�^����"]);
                KeiryoGrid->Cells[6][i + 1] = ToCurrency(set[i]["�P��"]);
                KeiryoGrid->Cells[7][i + 1] = ToInt(set[i]["���z"]);
                KeiryoGrid->Cells[8][i + 1] = ToString(set[i]["���ה��l"]);
            }
        }
    }

    int row;
    int code;
    for (NsRecordSet::iterator i = trans_set_.begin(); i != trans_set_.end(); i++){
        row = ToInt(i->second["�sNo"]);
        if (row < 1 || row > 6)
            continue;

        code = ToInt(i->second["�i�ڃR�[�h"]);

        if (code == ToInt(DM->CFG["�i�ڔ��������R�[�h"]) || code == ToInt(DM->CFG["�i�ڔ��o�����R�[�h"])){
            sundry_table_[row] = true;
        }else{
            sundry_table_[row] = false;
        }

        DetailGrid->Cells[1][row] = ToString(i->second["����敪����"]);
        DetailGrid->Cells[2][row] = code;
        DetailGrid->Cells[3][row] = ToString(i->second["�i�ږ���"]);
        DetailGrid->Cells[4][row] = ToCurrency(i->second["����"]);
        DetailGrid->Cells[5][row] = ToInt(i->second["�P�ʃR�[�h"]);
        DetailGrid->Cells[6][row] = ToString(i->second["�P�ʃ}�X�^����"]);
        DetailGrid->Cells[7][row] = ToCurrency(i->second["�P��"]);
        DetailGrid->Cells[8][row] = ToInt(i->second["���z"]);
        DetailGrid->Cells[9][row] = ToString(i->second["���ה��l"]);

        Currency deftanka = DM->GetTanka(ToInt(i->second["���Ӑ�ID"]), ToInt(i->second["�i��ID"]),
                            ToInt(i->second["����1ID"]), ToInt(i->second["����2ID"]), ToInt(i->second["�P��ID"]));
        deftanka_table_[row] = std::abs(ToCurrency(i->second["�P��"]) - deftanka);
        DefTankaGrid->Cells[1][row] = deftanka;
    }

    CalcTotal();

	return true;
}
//---------------------------------------------------------------------------
// ����o�^
void __fastcall TMainForm::PostRecords()
{
	InputMode mode = GetMode();

	TDateTime now(Now());
	int place_id = GetPlaceID();

	if (!ValidateForm())
		return;

    if (Application->MessageBox("�o�^���܂����H", Caption.c_str(),
	    	MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) != IDYES)
		return;

    if (mode != imMod){
        NoEdit->Text = DM->GetTransNo(place_id, DateToInt(DatePicker->Date));
    }

    int date, no;
	int toku_id, unpan_id, hin_code, hin_id, item1_id, item2_id;
	AnsiString toku_name, hin_name, item1_name, item2_name;

    date       = DateToInt(DatePicker->Date);
    no         = NoEdit->Text.ToIntDef(0);

	toku_id    = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
	toku_name  = TokuNameEdit->Text;
    // ����͑Ή�
    if (Komoku1CodeEdit->Text.ToIntDef(0) == 0){
        item1_id   = 0;
        item1_name = Komoku1NameEdit->Text;
    }else{
   		item1_id   = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
   		item1_name = Komoku1NameEdit->Text;
    }
	item2_id   = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
	item2_name = Komoku2NameEdit->Text;


    DM->ADOConnection->BeginTrans();

    try{
        bool create = (trans_id_ < 1);

        if (!create){
        	AnsiString sql;
            NsRecordSet set;
    	    sql = " SELECT �����, ���_ID, �`�[No FROM D_���"
        		  " WHERE"
        		  " 	���ID = " + IntToStr(trans_id_);
            if (!DM->DBI.GetRecordSet(sql, set))
                throw Exception("�C���f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B");

            NsFieldSet keys;
            keys << NsField("[�����]", SET_TOP(set)["�����"])
                 << NsField("[���_ID]", SET_TOP(set)["���_ID"])
                 << NsField("[�`�[No]", SET_TOP(set)["�`�[No"])
                 ;
            DM->DBI.Delete("D_���", keys);
        }

        NsFieldSet fields;
        NsRecordSet hin_set;
        int row = 1;
        bool hin_exists;

        for (int i = 1; i < DetailGrid->RowCount; i++){
            hin_code = DetailGrid->Cells[2][i].ToIntDef(0);
            hin_name = DetailGrid->Cells[3][i];
            hin_exists = DM->DBI.GetRecordSet("SELECT * FROM M_�i�� WHERE �i�ڃR�[�h = " + IntToStr(hin_code), hin_set);
            if (!hin_exists && DetailGrid->Cells[4][i].ToIntDef(0) == 0)
                continue;

            fields.clear();
            fields
                << NsField("[�����]",           date)
                << NsField("[���_ID]",           place_id)
                << NsField("[�`�[No]",           no)
                << NsField("[����敪]",         ToInt(SET_TOP(hin_set)["����敪"]))
                << NsField("[�v��ID]",           keiryo_id_)
        		<< NsField("[�ԗ�ID]",           car_id_)
        		<< NsField("[���Ӑ�ID]",         toku_id)
        		<< NsField("[���Ӑ於��]",       toku_name)
        		<< NsField("[����1ID]",          item1_id)
        		<< NsField("[����1����]",        item1_name)
        		<< NsField("[����2ID]",          item2_id)
        		<< NsField("[����2����]",        item2_name)
        		<< NsField("[���l]",             BikoEdit->Text)
                << NsField("[�`�[����Ŋz]",     total_zei_)
                << NsField("[�sNo]",             row)
                << NsField("[�i��ID]",           ToInt(SET_TOP(hin_set)["�i��ID"]))
                //<< NsField("[�i�ږ���]",         ToString(SET_TOP(hin_set)["�i�ږ���"]))
                << NsField("[�i�ږ���]",         hin_name)

                << NsField("[����]",             StrToCurrDef(DetailGrid->Cells[4][i], 0))
                << NsField("[�P��ID]",           ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", DetailGrid->Cells[5][i].ToIntDef(0), "�P��ID", "")))
                << NsField("[�P��]",             StrToCurrDef(DetailGrid->Cells[7][i], 0))
                << NsField("[���z]",             DetailGrid->Cells[8][i].ToIntDef(0))
                << NsField("[����Ŋz]",         zei_table_[i])
                << NsField("[���ה��l]",         DetailGrid->Cells[9][i])

                << NsField("[�����敪]",         1)
        		<< NsField("[�X�V����]",         now)
                << NsField("[�쐬����]",         now);
                ;

            DM->DBI.Insert("D_���", fields);

            row++;
        }

        DM->ADOConnection->CommitTrans();
    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        Application->MessageBoxA(AnsiString("�o�^���ɃG���[���������܂��� - " + e.Message).c_str(), Caption.c_str(), MB_OK | MB_ICONSTOP);
        return;
    }

    bool print    = false;
    int  print_id = 0;

    if (print)
        Print(print_id);

    Application->MessageBox("�o�^���܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    if (mode == imNew)
        Action1->Execute();
    else
        ShabanEdit->SetFocus();

}
//---------------------------------------------------------------------------
// �`�[���s
void __fastcall TMainForm::Print(int record_id)
{
/*
	if (!B5SlipPrintForm->Print(record_id))
		return;
*/
}
//---------------------------------------------------------------------------
// �e���ڂ̒l�`�F�b�N
bool __fastcall TMainForm::ValidateForm()
{
	AnsiString sql;
	NsRecordSet set;
	int n;

	if (car_id_ < 1){
		//Application->MessageBox("�ԗ��̑I���������ł�", Caption.c_str(), MB_OK | MB_ICONWARNING);
		//ShabanEdit->SetFocus();
		//return false;
        return true;
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

	return true;
}
//---------------------------------------------------------------------------
// ���[�h�֘A
//---------------------------------------------------------------------------
// ���[�h�ݒ�
void __fastcall TMainForm::SetMode(InputMode mode)
{
	switch (mode){
	case imNew: 		// �V�K
		ModePanel->Caption = "�V�K";
		ModePanel->Color   = TColor(0x00FDD8C6);

		NoEdit->ReadOnly = false;
		break;
	case imMod:			// �C��
		ModePanel->Caption = "�C��";
		ModePanel->Color   = TColor(0x00CEF4D0);

		NoEdit->ReadOnly = true;
		break;
	}
}
//---------------------------------------------------------------------------
// ���[�h�擾
InputMode __fastcall TMainForm::GetMode()
{
	if (ModePanel->Caption == "�V�K")
		return imNew;
	else if (ModePanel->Caption == "�C��")
		return imMod;
	return imNew;
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
	ClearForm();

	SetMode(imNew);

	NoEdit->Text = DM->GetTransNo(GetPlaceID(), DateToInt(DatePicker->Date));

	ShabanEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F2 �C��
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	ClearForm();
	SetMode(imMod);

	// ���ꋒ�_�̍ŏI���R�[�h���擾
	trans_id_ = DM->GetLastTransID(GetPlaceID());

	if (trans_id_ < 1){
		Application->MessageBox("�C������f�[�^�͂���܂���",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	if (!LoadFromID(trans_id_)){
		Application->MessageBox("�f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
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

	if (mode == imNew || trans_id_ < 1)
		return;

	if (Application->MessageBox("���̓`�[���폜���܂����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
		return;

    try{
        DM->ADOConnection->BeginTrans();

        AnsiString sql;
        NsRecordSet set;
    	sql = " SELECT �����, ���_ID, �`�[No FROM D_���"
        	  " WHERE"
        	  " 	���ID = " + IntToStr(trans_id_);
        if (!DM->DBI.GetRecordSet(sql, set))
            throw Exception("�C���f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B");

        int no = DM->GetTempNo(GetPlaceID());

    	NsFieldSet fields, keys;
    	fields << NsField("[�`�[No]",   no)
    		   << NsField("[�����敪]", 9);

        keys << NsField("[�����]", SET_TOP(set)["�����"])
             << NsField("[���_ID]", SET_TOP(set)["���_ID"])
             << NsField("[�`�[No]", SET_TOP(set)["�`�[No"]);

    	DM->DBI.Update("D_���", keys, fields);

        DM->ADOConnection->CommitTrans();
	}catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

		AnsiString msg = "�폜���ɃG���[���������܂��� - " + e.Message;
		Application->MessageBox(msg.c_str(), "�폜�G���[", MB_OK | MB_ICONWARNING);
		return;
	}

	Action2->Execute();
}
//---------------------------------------------------------------------------
// F4 �Q��
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
    if (ActiveControl == TokuCodeEdit){
        TokuButton->Click();
    }else if (ActiveControl == Komoku1CodeEdit){
        Komoku1Button->Click();
    }else if (ActiveControl == Komoku2CodeEdit){
        Komoku2Button->Click();
    }else if (ActiveControl == DetailGrid){
        if (DetailGrid->Col == 2){
        	SearchForm->Top = MainForm->Top;
        	SearchForm->Left = MainForm->Left + 450;
            SearchForm->based_sql = "SELECT �i�ڃR�[�h, �i�ڗ���, �����o�敪���� AS �����o, ����敪���� AS ����敪 FROM V_�i�� WHERE �g�p�敪 = 1";
        	SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
        	SearchForm->table_name = "V_�i��";
            SearchForm->list_->CommaText = " �i�ڃR�[�h,�i�ڗ���,�i�ڃJ�i";
        	if (SearchForm->ShowModal() != mrOk)
        		return;
            DetailGrid->Cells[2][DetailGrid->Row] = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
        }else if (DetailGrid->Col == 5){
        	SearchForm->Top = MainForm->Top;
        	SearchForm->Left = MainForm->Left + 450;
        	SearchForm->based_sql = "SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P�� ";
        	SearchForm->orderby_sql = " ORDER BY �P�ʃR�[�h ";
        	SearchForm->table_name = "M_�P��";
            SearchForm->list_->CommaText = " �P�ʃR�[�h,�P�ʖ���";
        	if (SearchForm->ShowModal() != mrOk)
        		return;
            DetailGrid->Cells[5][DetailGrid->Row] = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
        }
    }
}
//---------------------------------------------------------------------------
// F5 �o�^
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
	PostRecords();
}
//---------------------------------------------------------------------------
// F6 �O��
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
	int id;

	if (trans_id_){	// �C���A�܂��͑ؗ����
		id = DM->GetPrevTransID(GetPlaceID(),
			ToInt(SET_TOP(trans_set_)["�����"]),
			ToInt(SET_TOP(trans_set_)["�`�[No"]));
	}else{
		Action2->Execute();
		return;
	}

	if (id < 1)
		return;

	ClearForm();
	SetMode(imMod);

	trans_id_ = id;

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

	if (trans_id_){	// �C���A�܂��͑ؗ����
		id = DM->GetNextTransID(GetPlaceID(),
			ToInt(SET_TOP(trans_set_)["�����"]),
			ToInt(SET_TOP(trans_set_)["�`�[No"]));
	}else{
		Action2->Execute();
		return;
	}

	if (id < 1)
		return;

	ClearForm();
	SetMode(imMod);

	trans_id_ = id;

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
	if (GetMode() == imMod || trans_id_ < 1)
		return;

	if (Application->MessageBox("�`�[�𔭍s���܂����H", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;

	Print(trans_id_);
}
//---------------------------------------------------------------------------
// F9 ����
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (DataListForm->ShowModal() != mrOk)
		return;

	ClearForm();
	SetMode(imMod);

	trans_id_ = DataListForm->selected_id;

	if (!LoadFromID(trans_id_)){
		Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	ShabanEdit->SetFocus();
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
	SearchForm->list_->CommaText = " ���Ӑ�R�[�h,���Ӑ旪��,���Ӑ�J�i,�Z��1,�Z��2,�d�b�ԍ�";
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
    SearchForm->list_->CommaText = " ����1�R�[�h,����1����,����1�J�i";
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
    SearchForm->list_->CommaText = " ����2�R�[�h,����2����,����2�J�i";
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
/*
	ItemSearchForm->Top = MainForm->Top;
	ItemSearchForm->Left = MainForm->Left + 450;
    ItemSearchForm->UnitID = 1;
	if (ItemSearchForm->ShowModal() != mrOk)
		return;
	HinCodeEdit->Text = ItemSearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
	HinCodeEdit->OnChange(NULL);
	HinCodeEdit->SetFocus();
*/
}
//---------------------------------------------------------------------------
// �P�ʌ���
void __fastcall TMainForm::TaniButtonClick(TObject *Sender)
{
/*
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
*/
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

	// ���̃t�H�[���̃T�C�Y�����C���t�H�[���ɍ��킹��
	SearchForm->Height = MainForm->Height;
/*
	DataListForm->Height = MainForm->Height - 33;
	DataListForm->Width  = MainForm->Width  - 24;
	DataListForm->Top  = MainForm->Top  + 16;
	DataListForm->Left = MainForm->Left + 12;
*/
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
	AnsiString sql = "SELECT * FROM M_�ԗ� WHERE �Ԕ� = " + IntToStr(ShabanEdit->Text.ToIntDef(0));
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
// �Ԕ�->OnExit
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
	int car_no = ShabanEdit->Text.ToIntDef(0);
	if (car_no < 1){
		ShabanEdit->Text = AnsiString();
        car_id_ = 0;
		return;
	}

	AnsiString sql;
	NsRecordSet set;

	if (GetMode() == imMod){
		sql = "SELECT �ԗ����� FROM M_�ԗ� WHERE �ԗ�ID = " + IntToStr(car_id_);
		if (DM->DBI.GetRecordSet(sql, set)){
			if (ToString(SET_TOP(set)["�ԗ�����"]) == SharyoNameEdit->Text)
				return;
		}
	}

	DM->SetShabanQuery(false, GetPlaceID(), true);

	if (DM->Q_Shaban->Active)
		DM->Q_Shaban->Close();
	DM->Q_Shaban->Parameters->ParamByName("CARNO")->Value = car_no;
	DM->Q_Shaban->Open();

	if (DM->Q_Shaban->Bof && DM->Q_Shaban->Eof){
		// �V�K�ԗ��o�^

		TDateTime now(Now());
		NsFieldSet fields;

		AnsiString name = now.FormatString("mm/dd' �Ɏ����o�^'");
		fields << NsField("[�Ԕ�]",     car_no)
			   << NsField("[�ԗ�����]", name)
			   << NsField("[�X�V����]", now)
			   << NsField("[�쐬����]", now);

		DM->DBI.Insert("M_�ԗ�", fields);

		SharyoNameEdit->Text = name;

		car_id_ = DM->DBI.GetLastID();

		return;
	}

	// �ؗ��Ԃ������͊����ԗ��Ƀq�b�g�����ꍇ�A�I��������
	ShabanSanshoForm->TopPanel->Caption = "  �ԔԁF" + IntToStr(car_no);
	if (ShabanSanshoForm->ShowModal() != mrOk){
		ShabanEdit->SetFocus();
		return;
	}

	car_id_      = ShabanSanshoForm->GetCarID();
	int mastered = ShabanSanshoForm->GetDataDiv();

	if (!car_id_){
		// �V�K�ԗ��i��Ɠ��������j

		NsFieldSet fields;
		TDateTime now(Now());
		AnsiString name = now.FormatString("mm/dd' �Ɏ����o�^'");

		fields << NsField("[�Ԕ�]",     car_no)
			   << NsField("[�ԗ�����]", name)
			   << NsField("[�X�V����]", now)
			   << NsField("[�쐬����]", now);

		DM->DBI.Insert("M_�ԗ�", fields);

		car_id_ = DM->DBI.GetLastID();

        SharyoNameEdit->Text = name;

		return;
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

		if (GetMode() != imMod){
			if (TokuCodeEdit->Text.IsEmpty())
				TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["���Ӑ�R�[�h"]));
			if (Komoku1CodeEdit->Text.IsEmpty())
				Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����1�R�[�h"]));
			if (Komoku2CodeEdit->Text.IsEmpty())
				Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����2�R�[�h"]));

            SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
		}
	}

}
//---------------------------------------------------------------------------
// ���Ӑ�R�[�h->OnChange
void __fastcall TMainForm::TokuCodeEditChange(TObject *Sender)
{
	int code = TokuCodeEdit->Text.ToIntDef(0);
	if (!code)
		return;

	NsRecordSet set;
	AnsiString sql = "SELECT * FROM M_���Ӑ� WHERE ���Ӑ�R�[�h = " + IntToStr(code);
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

	}

}
//---------------------------------------------------------------------------
// ����1�R�[�h->OnChange
void __fastcall TMainForm::Komoku1CodeEditChange(TObject *Sender)
{
	int code = Komoku1CodeEdit->Text.ToIntDef(0);
	if (!code)
		return;

	if (code == ToInt(DM->CFG["����1�����R�[�h"])){
		Komoku1NameEdit->ReadOnly = false;
		Komoku1NameEdit->TabStop  = true;
	}else{
		Komoku1NameEdit->Text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", code, "����1����", ""));
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

	}
/*
    if (Komoku1CodeEdit->Text.ToIntDef(0) == 0){
        Komoku1NameEdit->ReadOnly = false;
        Komoku1NameEdit->SetFocus();
    }else{
        Komoku1NameEdit->ReadOnly = true;
    }
*/
}
//---------------------------------------------------------------------------
// ����2�R�[�h->OnChange
void __fastcall TMainForm::Komoku2CodeEditChange(TObject *Sender)
{
	int code = Komoku2CodeEdit->Text.ToIntDef(0);
	if (!code)
		return;

	if (code == ToInt(DM->CFG["����2�����R�[�h"])){
		Komoku2NameEdit->ReadOnly = false;
		Komoku2NameEdit->TabStop  = true;
	}else{
		Komoku2NameEdit->Text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", code, "����2����", ""));
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

	}

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl->Tag != 9999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 999 && ActiveControl->Tag != 9999){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 9999){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
// ���_��ύX�����ꍇ
void __fastcall TMainForm::PlaceComboChange(TObject *Sender)
{
	Action1->Execute();
}
//---------------------------------------------------------------------------
// �`�[No->KeyDown
void __fastcall TMainForm::NoEditKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	int place = GetPlaceID();
	int date  = DateToInt(DatePicker->Date);
	int no    = NoEdit->Text.ToIntDef(0);

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT ���ID FROM D_���"
		  " WHERE ����� = " + IntToStr(date) + " AND ���_ID = " + IntToStr(place) +
		  " 	AND �`�[No = " + IntToStr(no);

	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^��������܂���B",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	ClearForm();
	SetMode(imMod);

	trans_id_ = SET_TOP(set)["���ID"];

	if (!LoadFromID(trans_id_)){
		Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B\r\n��PC�Ȃǂō폜����Ă��Ȃ����m�F���Ă��������B",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Action1->Execute();
		return;
	}

	ShabanEdit->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DatePickerChange(TObject *Sender)
{
    // �ǂ�����H

    //if (GetMode() == imMod)
       NoEdit->Text = DM->GetTransNo(GetPlaceID(), DateToInt(DatePicker->Date));
}
//---------------------------------------------------------------------------
// ������׃O���b�h�`��
void __fastcall TMainForm::DetailGridDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
   RECT rect;
    rect.left   = Rect.Left;
    rect.top    = Rect.Top;
    rect.right  = Rect.Right;
    rect.bottom = Rect.Bottom;

    int active_col = DetailGrid->Col;

    if (ACol == 1 && ARow > 0){
        AnsiString caption = DetailGrid->Cells[ACol][ARow];
        if (caption == "����")
            DetailGrid->Canvas->Brush->Color = TColor(0x00FDC8AE);
        else if (caption == "�d��")
            DetailGrid->Canvas->Brush->Color = TColor(0x00AFC7FC);
        else
            DetailGrid->Canvas->Brush->Color = clWindow;
        DetailGrid->Canvas->FillRect(Rect);
        ::DrawText(DetailGrid->Canvas->Handle, caption.c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    }

    if (ACol == 7 && ARow > 0){
        AnsiString caption = DetailGrid->Cells[ACol][ARow];
        DetailGrid->Canvas->Brush->Color = deftanka_table_[ARow] == 0 ? clWindow : TColor(0x008080FF);
        DetailGrid->Canvas->FillRect(Rect);
        ::DrawText(DetailGrid->Canvas->Handle, caption.c_str(), -1, &rect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
    }

    if (ARow == DetailGrid->Row && !State.Contains(gdFixed)){
//        DetailGrid->Canvas->Brush->Color = TColor(0x00E6FFFF);
//        DetailGrid->Canvas->FillRect(Rect);
/*
        if (ACol == active_col && !State.Contains(gdFocused)){
    		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(DetailGrid->Components[0]);
    		if (ie){
                ie->Brush->Color = TColor(0x00E6FFFF);
            }
        }
*/
    }

/*
    if (State.Contains(gdFixed)){
        DrawEdge(DetailGrid->Canvas->Handle, &rect, EDGE_SUNKEN, BF_RECT | BF_ADJUST);
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    if (ACol != 9)
        ::SetImeMode(DetailGrid->Handle, imDisable);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_LEFT){
        int col = DetailGrid->Col;
        if (col == 4 && sundry_table_[DetailGrid->Row]){
            DetailGrid->Col = col - 1;
            Key = 0;
            return;
        }
        if (col == 4 || col == 7){
            DetailGrid->Col = col - 2;
            Key = 0;
            return;
        }
    }
    if (Key == VK_RIGHT){
        int col = DetailGrid->Col;
        if (col == 2 && sundry_table_[DetailGrid->Row]){
            DetailGrid->Col = col + 1;
            Key = 0;
            return;
        }
        if (col == 2 || col == 5){
            DetailGrid->Col = col + 2;
            Key = 0;
            return;
        }
    }

    if (Key == VK_RETURN){
        int col = DetailGrid->Col;
        int row = DetailGrid->Row;
        bool last_cell = false;

        switch (col){
        case 2:
            if (sundry_table_[row])
                col++;
            else
                col += 2;
            break;
        case 5:
        case 7:
            col += 2;
            break;
        case 9:
            col = 2;
            row++;
            break;
        default:
            col++;
        };

        if (row > 6){
            col = 2;
            row = 6;
            last_cell = true;
        }

        DetailGrid->Row = row;
        DetailGrid->Col = col;

		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(DetailGrid->Components[0]);
		if (ie){
            ie->SelStart = 0;
        }

    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridSetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
    int code;
    Currency val;
    AnsiString name = AnsiString();

    AnsiString sql;
    NsRecordSet set;

    switch (ACol){
    case 2:
        code = Value.ToIntDef(0);
        sql = "SELECT * FROM V_�i�� WHERE �i�ڃR�[�h = " + IntToStr(code);
        if (DM->DBI.GetRecordSet(sql, set)){
            DetailGrid->Cells[1][ARow] = ToString(SET_TOP(set)["����敪����"]);
            DetailGrid->Cells[3][ARow] = ToString(SET_TOP(set)["�i�ږ���"]);

            if (code == ToInt(DM->CFG["�i�ڔ��������R�[�h"]) || code == ToInt(DM->CFG["�i�ڔ��o�����R�[�h"])){
                sundry_table_[ARow] = true;
                TGridOptions opt = DetailGrid->CellParams->Items[3]->Options;
                opt <<  goEditing << goAlwaysShowEditor;
                DetailGrid->CellParams->Items[13]->Options = opt;
            }else{
                sundry_table_[ARow] = false;
                TGridOptions opt = DetailGrid->CellParams->Items[3]->Options;
                opt >>  goEditing >> goAlwaysShowEditor;
                DetailGrid->CellParams->Items[13]->Options = opt;
            }

        }else{
            sundry_table_[ARow] = false;

            TGridOptions opt = DetailGrid->CellParams->Items[3]->Options;
            opt >>  goEditing >> goAlwaysShowEditor;
            DetailGrid->CellParams->Items[13]->Options = opt;

            DetailGrid->Cells[1][ARow] = AnsiString();
            DetailGrid->Cells[3][ARow] = AnsiString();
            /*
            DetailGrid->Cells[4][ARow] = AnsiString();
            DetailGrid->Cells[5][ARow] = AnsiString();
            DetailGrid->Cells[6][ARow] = AnsiString();
            DetailGrid->Cells[7][ARow] = AnsiString();
            DetailGrid->Cells[8][ARow] = AnsiString();
            DetailGrid->Cells[9][ARow] = AnsiString();
            */
        }
        break;
    case 5:
        code = Value.ToIntDef(0);
        DetailGrid->Cells[6][ARow] = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", code, "�P�ʖ���", ""));
        break;
    };
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DetailGridCellChanged(TObject *Sender,
      int AOldCol, int AOldRow, int ANewCol, int ANewRow)
{
    switch (AOldCol){
    case 2:
        GetCalcInfo(AOldRow);
        CalcAmount(AOldRow);
        break;
    case 4:
    case 5:
    case 7:
        CalcAmount(AOldRow, false);
        break;
    };
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetCalcInfo(int row)
{
	if (GetMode() == imMod)
		return;

    int code     = DetailGrid->Cells[2][row].ToIntDef(0);
    if (code){
      	int meig_id  = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", code, "�i��ID"));
        code = DM->GetDefaultTanka(toku_id_, meig_id);
        DetailGrid->Cells[5][row] = code;
        DetailGrid->Cells[6][row] = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", code, "�P�ʖ���", ""));
    }
    CalcAmount(row);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcAmount(int row, bool update)
{
	Currency qty = StrToCurrDef(DetailGrid->Cells[4][row], 0);

	int meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",  DetailGrid->Cells[2][row].ToIntDef(0), "�i��ID"));
	int item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0),     "����1ID"));
	int item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0),     "����2ID"));
	int tani_id  = ToInt(DM->DBI.Lookup("M_�P��",   "�P�ʃR�[�h",  DetailGrid->Cells[5][row].ToIntDef(0), "�P��ID"));

    Currency def_tanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
	Currency tanka     = StrToCurrDef(DetailGrid->Cells[7][row], 0);
	if (GetMode() != imMod && update){
        tanka = def_tanka;
    }
    DefTankaGrid->Cells[1][row] = def_tanka;
    deftanka_table_[row] = std::abs(tanka - def_tanka);
    DetailGrid->Invalidate();

	///// ���z�[�������敪�̎擾
	int amount_div = -1;

	if (!toku_rec_.empty()){
		if (!IsNull(toku_rec_["���z�[�������敪"]))
			amount_div = ToInt(toku_rec_["���z�[�������敪"]);
	}
	if (amount_div == -1)
		amount_div = ToInt(DM->CFG["���z�[�������敪"]);
	/////

   	int amount = ExtendedRound(qty * tanka, 0, amount_div);

	DetailGrid->Cells[7][row] = tanka;
	DetailGrid->Cells[8][row] = amount;

    CalcTotal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CalcTotal()
{
	Currency tax_rate = DM->GetSalesTax();			// ����ŗ�

	///// ����Œ[�������敪�̎擾
	int tax_div = -1;

	if (!toku_rec_.empty()){
		if (!IsNull(toku_rec_["����Œ[�������敪"]))
			tax_div = ToInt(toku_rec_["����Œ[�������敪"]);
	}
	if (tax_div == -1)
		tax_div = ToInt(DM->CFG["����Œ[�������敪"]);
	/////

    zei_table_.clear();

    int u_total     = 0;
    int u_total_zei = 0;
    int s_total     = 0;
    int s_total_zei = 0;
    int row_amount;
    int row_zei;
    int code;
    AnsiString div;
    int *total, *total_zei;
    for (int row = 1; row < DetailGrid->RowCount; row++){
        code     = DetailGrid->Cells[2][row].ToIntDef(0);
        if (!code)
            continue;
        div      = DetailGrid->Cells[1][row];
        if (div == "����"){
            total     = &u_total;
            total_zei = &u_total_zei;
        }else if (div == "�d��"){
            total     = &s_total;
            total_zei = &s_total_zei;
        }else
            continue;

        row_amount = DetailGrid->Cells[8][row].ToIntDef(0);
        row_zei    = ExtendedRound(Currency(row_amount) * tax_rate, 0, tax_div);

        *total         += row_amount;
        *total_zei     += row_zei;
        zei_table_[row] = row_zei;
    }

    UAmountLabel->Caption   = FormatFloat("###,###,###,##0", u_total);
	UTotalZeiLabel->Caption = FormatFloat("###,###,##0",     u_total_zei);
    SAmountLabel->Caption   = FormatFloat("###,###,###,##0", s_total);
	STotalZeiLabel->Caption = FormatFloat("###,###,##0",     s_total_zei);

    total_zei_ = u_total_zei + s_total_zei;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControlEnter(TObject *Sender)
{
    if (PageControl->ActivePage == TransSheet){
        DetailGrid->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PageControlChange(TObject *Sender)
{
    if (PageControl->ActivePage == TransSheet){
        RowDeleteButton->Enabled = true;
        RowInsertButton->Enabled = true;
    }else{
        RowDeleteButton->Enabled = false;
        RowInsertButton->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RowInsertButtonClick(TObject *Sender)
{
    int row = DetailGrid->Row;

    if (row < 1)
        return;

    if (!DetailGrid->Cells[1][6].IsEmpty()){
        Application->MessageBox("����6�s�ڂ܂œ��͂���Ă��܂��B�]���ȍs���폜���Ă��������x�s���ĉ�����", "����f�[�^���ב}��", MB_OK | MB_ICONWARNING);
        return;
    }

    for (int i = 6; i >= row; i--){
        DetailGrid->Cells[1][i] = DetailGrid->Cells[1][i - 1];
        DetailGrid->Cells[2][i] = DetailGrid->Cells[2][i - 1];
        DetailGrid->Cells[3][i] = DetailGrid->Cells[3][i - 1];
        DetailGrid->Cells[4][i] = DetailGrid->Cells[4][i - 1];
        DetailGrid->Cells[5][i] = DetailGrid->Cells[5][i - 1];
        DetailGrid->Cells[6][i] = DetailGrid->Cells[6][i - 1];
        DetailGrid->Cells[7][i] = DetailGrid->Cells[7][i - 1];
        DetailGrid->Cells[8][i] = DetailGrid->Cells[8][i - 1];
        DetailGrid->Cells[9][i] = DetailGrid->Cells[9][i - 1];
    }
    DetailGrid->Cells[1][row] = AnsiString();
    DetailGrid->Cells[2][row] = AnsiString();
    DetailGrid->Cells[3][row] = AnsiString();
    DetailGrid->Cells[4][row] = AnsiString();
    DetailGrid->Cells[5][row] = AnsiString();
    DetailGrid->Cells[6][row] = AnsiString();
    DetailGrid->Cells[7][row] = AnsiString();
    DetailGrid->Cells[8][row] = AnsiString();
    DetailGrid->Cells[9][row] = AnsiString();

    DetailGrid->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RowDeleteButtonClick(TObject *Sender)
{
    int row = DetailGrid->Row;

    if (row < 1)
        return;

    AnsiString msg = "�sNo: " + IntToStr(row) + " �̖��ׂ��폜���Ă�낵���ł����H";
    if (Application->MessageBox(msg.c_str(), "����f�[�^���׍폜", MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    for (int i = row; i < 6; i++){
        DetailGrid->Cells[1][i] = DetailGrid->Cells[1][i + 1];
        DetailGrid->Cells[2][i] = DetailGrid->Cells[2][i + 1];
        DetailGrid->Cells[3][i] = DetailGrid->Cells[3][i + 1];
        DetailGrid->Cells[4][i] = DetailGrid->Cells[4][i + 1];
        DetailGrid->Cells[5][i] = DetailGrid->Cells[5][i + 1];
        DetailGrid->Cells[6][i] = DetailGrid->Cells[6][i + 1];
        DetailGrid->Cells[7][i] = DetailGrid->Cells[7][i + 1];
        DetailGrid->Cells[8][i] = DetailGrid->Cells[8][i + 1];
        DetailGrid->Cells[9][i] = DetailGrid->Cells[9][i + 1];
    }
    DetailGrid->Cells[1][6] = AnsiString();
    DetailGrid->Cells[2][6] = AnsiString();
    DetailGrid->Cells[3][6] = AnsiString();
    DetailGrid->Cells[4][6] = AnsiString();
    DetailGrid->Cells[5][6] = AnsiString();
    DetailGrid->Cells[6][6] = AnsiString();
    DetailGrid->Cells[7][6] = AnsiString();
    DetailGrid->Cells[8][6] = AnsiString();
    DetailGrid->Cells[9][6] = AnsiString();

    DetailGrid->SetFocus();
}
//---------------------------------------------------------------------------
// �P���X�V
void __fastcall TMainForm::TankaUpdateButtonClick(TObject *Sender)
{
    int row = DetailGrid->Row;

	int meig_id  = ToInt(DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",  DetailGrid->Cells[2][row].ToIntDef(0), "�i��ID"));
	int item1_id = ToInt(DM->DBI.Lookup("M_����1",  "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0),     "����1ID"));
	int item2_id = ToInt(DM->DBI.Lookup("M_����2",  "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0),     "����2ID"));
	int tani_id  = ToInt(DM->DBI.Lookup("M_�P��",   "�P�ʃR�[�h",  DetailGrid->Cells[5][row].ToIntDef(0), "�P��ID"));

	Currency tanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id);
    DetailGrid->Cells[7][DetailGrid->Row] = tanka;
    CalcAmount(row);
    DetailGrid->SetFocus();
}
//---------------------------------------------------------------------------


