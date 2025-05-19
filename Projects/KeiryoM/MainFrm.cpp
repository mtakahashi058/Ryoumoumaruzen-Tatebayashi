//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "StrCGrid"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner),
        keiryo_id_(0),
        cur_weight_(0), old_weight_(0),
        id_total_(0), item_relate_hin_id_(0),
        delete_flag_(false)
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
// MainForm->OnShow
void __fastcall TMainForm::FormShow(TObject *Sender)
{

    ///////////////////////////////////////////////
    // �f�[�^�x�[�X�ɐڑ�

    if (!DM->Init())
        Close();

    ApplyConfig();

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

    // ���׃O���b�h������
    SetGridTitle();

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

    TairyuTokuisakiLabel->Caption = ToString(DM->CFG["���Ӑ�}�X�^����"]);

    if (!ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"])){
        TokuPanel->Visible            = false;
        TairyuTokuisakiLabel->Visible = false;
        TairyuTokuisakiText->Visible  = false;
    }

    if (!ToBit(DM->CFG["����1�}�X�^�g�p�敪"])){
        Komoku1Panel->Visible = false;
    }

    if (!ToBit(DM->CFG["����2�}�X�^�g�p�敪"])){
        Komoku2Panel->Visible = false;
    }

    if (!ToBit(DM->CFG["���o�Ɏg�p�敪"])){
        HannyuCombo->Visible  = false;
        RecalcButton->Visible = false;
    }

    PlaceCombo->Items->Clear();
    if (!DM->DBI.GetRecordSet("SELECT ���_ID, ���_�R�[�h, ���_���� FROM M_���_", kyoten_set_)){
        Application->MessageBox("���_�}�X�^���ݒ肳��Ă��܂���B�v�ʑO�ɐݒ肵�Ă�������",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }
    default_index = 0;
    int place_code    = ToInt(DM->INI["Place::Code"]);
    for (unsigned int i = 0; i < kyoten_set_.size(); i++){
        PlaceCombo->Items->Append(ToString(kyoten_set_[i]["���_����"]));
        if (ToInt(kyoten_set_[i]["���_�R�[�h"]) == place_code)
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


    standard_tani_code_ = ToInt(DM->CFG["�W���P��"]);
    money_print_div_    = ToInt(DM->CFG["�`�[���z��"]);
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
    return ToInt(kyoten_set_[PlaceCombo->ItemIndex]["���_ID"]);
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
    keiryo_id_    = 0;
    keiryo_set_.clear();

    toku_id_      = 0;
    toku_rec_.clear();

    new_car_      = false;
    car_id_       = 0;
    keiryo_count_ = 0;
    gross_limit_  = 0;
    net_limit_    = 0;

    item_relate_hin_id_ = 0;
    slip_tax_           = 0;

    TDateTime now = Now();

    KeiryoDatePicker->Date    = now;
    KeiryoNoEdit->Text        = AnsiString();
    KeiryoTimePicker->Time    = now;
    PlaceCombo->ItemIndex     = default_index;
    ShabanEdit->Text          = AnsiString();
    ShabanEdit->OnChange(NULL);
    TokuCodeEdit->Text        = AnsiString();
    TokuNameEdit->Text        = AnsiString();
    Komoku1CodeEdit->Text     = AnsiString();
    Komoku1NameEdit->Text     = AnsiString();
    Komoku2CodeEdit->Text     = AnsiString();
    Komoku2NameEdit->Text     = AnsiString();
    BikoEdit->Text            = AnsiString();
    HannyuCombo->ItemIndex    = -1;
}
//---------------------------------------------------------------------------
// �s�ǉ��p�̊֐�
void __fastcall TMainForm::Line_Add()
{
    // �\������Ă���ő�sNo�擾
    int row_no = 0;
    for (int r = detail_line; r < SCGrid->RowCount; r += detail_line){
        if (!SCGrid->Cells[0][r].IsEmpty())
        row_no = SCGrid->Cells[0][r].ToIntDef(0);
    }

    int line_no = row_no + 1;
    if (line_no * detail_line >= max_row) // max_row�𒴂���悤�Ȃ�ǉ��������f
        return;

    SCGrid->Cells[0][line_no * detail_line] = line_no;

    for (int i = 0; i < detail_line; i++)
        row_lineno_map_[(line_no * detail_line) + i] = line_no;

    SCGrid->Col = 1;
    SCGrid->Row = line_no * detail_line;

    // �O���b�h��ҏW�ɂ���
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;

    SCGrid->SetFocus();
}
//---------------------------------------------------------------------------
// �s�}���p�̊֐�����2
void __fastcall TMainForm::Line_Insert(int line_no)
{
    // �󔒂̍s������ꍇ�͂����Ɉړ�����
    for (int i = detail_line; i < SCGrid->RowCount - detail_line; i += detail_line){
        int line_no, id;
        line_no = row_lineno_map_[i];
        id      = row_id_map_[i];

        if (line_no == 6){
            return;
        }else if (line_no != 0 && id == 0 && SCGrid->Cells[GetColNo("�i�ڃR�[�h")][CalcRowNo("�i�ڃR�[�h", i)].ToIntDef(0) == 0){
            SCGrid->Col = GetColNo("�i�ڃR�[�h");
            SCGrid->Row = CalcRowNo("�i�ڃR�[�h", i);
            SCGrid->SetFocus();
            return;
        }
    }

    // line_no���牺�̍s��detail_line�����炷
    int calc_row = line_no * detail_line;
    for (int i = SCGrid->RowCount - detail_line; i >= calc_row; i--){
        SCGrid->Rows[i + detail_line] = SCGrid->Rows[i];
        SCGrid->Rows[i]->Clear();
        row_id_map_[i + detail_line]  = row_id_map_[i];
        row_id_map_[i] = 0;
    }

    int old_id  = row_id_map_[detail_line];
    int no      = 1;
    row_lineno_map_.clear();
    for (int i = detail_line; i < SCGrid->RowCount; i++){
        if (old_id != row_id_map_[i])
            no++;

        // map��id���Ȃ������珈���I��
        if (row_id_map_[i] == 0 && line_no != no)
        //if (row_id_map_[i] == 0)
            break;

        if (i % detail_line == 0)
            SCGrid->Cells[0][i] = no;

        row_lineno_map_[i] = no;
        old_id = row_id_map_[i];
    }

    SCGrid->SetFocus();
    SCGrid->Col = 1;
    //SCGrid->Row = (no - 1) * detail_line;
    SCGrid->Row = calc_row;

    // �O���b�h��ҏW�ɂ���
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;
}
//---------------------------------------------------------------------------
// �s�}���p�̊֐�
bool __fastcall TMainForm::LoadFromID_Insert(int id, int insert_line_no)
{
    AnsiString sql;
    Currency   slip_no;
    int        date;

    slip_no = ToCurrency(DM->DBI.Lookup("D_�v��", "�v��ID", id, "�`�[No"));
    date    = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", id, "�v�ʓ�"));

    sql = " SELECT * FROM V_�v��"
          " WHERE"
          "     �v�ʓ� = " + IntToStr(date) +
          " AND"
          "     �`�[No = " + CurrToStr(slip_no) +
          " AND"
          "     �����敪 <> 9" // �_���폜�͑ΏۊO
          " ORDER BY"
          "     �sNo";

    if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
        return false;

    KeiryoDatePicker->Date = IntToDate(ToInt(SET_TOP(keiryo_set_)["�v�ʓ�"]));
    KeiryoNoEdit->Text     = ToInt(SET_TOP(keiryo_set_)["�`�[No"]);

    car_id_                = ToInt(SET_TOP(keiryo_set_)["�ԗ�ID"]);
    ShabanEdit->Text       = ToInt(SET_TOP(keiryo_set_)["�Ԕ�"]);
    SharyoNameEdit->Text   = ToString(SET_TOP(keiryo_set_)["�ԗ�����"]);

    TokuCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["���Ӑ�R�[�h"]));
    TokuNameEdit->Text     = ToString(SET_TOP(keiryo_set_)["���Ӑ於��"]);
    Komoku1CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����1�R�[�h"]));
    Komoku1NameEdit->Text  = ToString(SET_TOP(keiryo_set_)["����1����"]);
    Komoku2CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����2�R�[�h"]));
    Komoku2NameEdit->Text  = ToString(SET_TOP(keiryo_set_)["����2����"]);
    BikoEdit->Text         = ToString(SET_TOP(keiryo_set_)["���l"]);
    HannyuCombo->ItemIndex = ToInt(SET_TOP(keiryo_set_)["�����o�敪"]) - 1;

    // ���׃O���b�h�N���A
    ClearDetailGrid();

    // ���ו\��
    CoordToNameMap::iterator ctnm;
    int row     = detail_line;
    int line_no = 0;

    for (unsigned int r = 0; r < keiryo_set_.size(); r++){
        line_no++;

        // �}���s�ɂ�����sNo��\������
        if (r + 1 == (unsigned int)insert_line_no){
            SCGrid->Cells[0][row] = line_no;
            row += detail_line;
            line_no++;
        }

        // 1�s��
        for (int col = 0; col < SCGrid->ColCount; col++){
            col_row_map_.clear();
            col_row_map_[col] = 1;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == col_row_map_.end()){ // �Z���ɊY�����ڕ\����Row�ɑ΂��Čv��ID�����Ă���
                SCGrid->Cells[col][row] = AnsiString();
                row_id_map_[row]        = 0;
            }else{
                if (col == 0) // �sNo
                    SCGrid->Cells[col][row] = line_no;
                else if (ctnm->second == "�i�ڃ}�X�^����" || ctnm->second == "���ה��l")
                    SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                else
                    SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                row_id_map_[row]          = ToInt(keiryo_set_[r]["�v��ID"]);
                row_lineno_map_[row]      = line_no;
            }
        }

        if (detail_line == 2){
            row++;
            keiryo_set_.clear();
            DM->DBI.GetRecordSet(sql, keiryo_set_);

            // 2�s��
            for (int col = 0; col < SCGrid->ColCount; col++){
                col_row_map_.clear();
                col_row_map_[col] = 2;
                ctnm = coord_name_map_.find(col_row_map_);
                if (ctnm == coord_name_map_.end()){
                    SCGrid->Cells[col][row] = AnsiString();
                    row_id_map_[row]     = 0;
                }else{
                    if (ctnm->second == "���ה��l" || ctnm->second == "�P�ʃ}�X�^����")
                        SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                    else
                        SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                    row_id_map_[row]          = ToInt(keiryo_set_[r]["�v��ID"]);
                    row_lineno_map_[row]      = line_no;
                }
            }
        }
        row++;
    }

    SCGrid->Col        = 1;
    SCGrid->Row        = insert_line_no * detail_line;
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;
    SCGrid->SetFocus();

    return true;
}
//---------------------------------------------------------------------------
// �v��ID���烌�R�[�h����ǂݍ���
bool __fastcall TMainForm::LoadFromID(int id)
{
    AnsiString sql, place_name;
    Currency   slip_no;
    int        date, place_id;

    slip_no  = ToCurrency(DM->DBI.Lookup("D_�v��", "�v��ID", id, "�`�[No"));
    date     = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", id, "�v�ʓ�"));
    place_id = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", id, "���_ID"));
    place_name = ToString(DM->DBI.Lookup("M_���_", "���_ID", place_id, "���_����"));

    sql = " SELECT * FROM V_�v��"
          " WHERE"
          "     �v�ʓ� = " + IntToStr(date) +
          " AND"
          "     �`�[No = " + CurrToStr(slip_no) +
          " AND"
          "     ���_ID = " + IntToStr(place_id) +
          " AND"
          "     �����敪 <> 9" // �_���폜�͑ΏۊO
          " ORDER BY"
          "     �sNo";

    if (!DM->DBI.GetRecordSet(sql, keiryo_set_))
        return false;

    KeiryoDatePicker->Date = IntToDate(ToInt(SET_TOP(keiryo_set_)["�v�ʓ�"]));
    KeiryoNoEdit->Text     = ToInt(SET_TOP(keiryo_set_)["�`�[No"]);

    // �����f�[�^�ȊO�͍��̎��Ԃ�\��
    if (ToInt(SET_TOP(keiryo_set_)["�����敪"]) == 1)
        KeiryoTimePicker->Time = GetLastKeiryoTime(date, slip_no, place_id);
    else
        KeiryoTimePicker->Time = Now();

    PlaceCombo->ItemIndex  = PlaceCombo->Items->IndexOf(place_name);

    car_id_                = ToInt(SET_TOP(keiryo_set_)["�ԗ�ID"]);
    ShabanEdit->Text       = ToInt(SET_TOP(keiryo_set_)["�Ԕ�"]);
    SharyoNameEdit->Text   = ToString(SET_TOP(keiryo_set_)["�ԗ�����"]);

    TokuCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["���Ӑ�R�[�h"]));
    TokuNameEdit->Text     = ToString(SET_TOP(keiryo_set_)["���Ӑ於��"]);
	Komoku1CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����1�R�[�h"]));
    Komoku2CodeEdit->Text  = ZeroSuppress(ToInt(SET_TOP(keiryo_set_)["����2�R�[�h"]));
    BikoEdit->Text         = ToString(SET_TOP(keiryo_set_)["���l"]);
    HannyuCombo->ItemIndex = ToInt(SET_TOP(keiryo_set_)["�����o�敪"]) - 1;

    // ���׃O���b�h�N���A
    ClearDetailGrid();

    // ���ו\��
    CoordToNameMap::iterator ctnm;
    int row = detail_line;
    row_id_map_.clear();

    for (unsigned int r = 0; r < keiryo_set_.size(); r++){

        // 1�s��
        //for (int col = 0; col < SCGrid->ColCount; col++){
        for (int col = 0; col <= line_colcount_map_[1]; col++){
            col_row_map_.clear();
            col_row_map_[col] = 1;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == col_row_map_.end()){ // �Z���ɊY�����ڕ\����Row�ɑ΂��Čv��ID�����Ă���
                SCGrid->Cells[col][row] = AnsiString();
                row_id_map_[row]        = 0;
            }else{
                if (col == 0) // �sNo
                    SCGrid->Cells[col][row] = r + 1;
                else if (ctnm->second == "�i�ڃ}�X�^����" || ctnm->second == "���ה��l")
                    SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                else
                    SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                row_id_map_[row]     = ToInt(keiryo_set_[r]["�v��ID"]);
                row_lineno_map_[row] = r + 1;
            }
        }

        if (detail_line == 2){
            row++;
            keiryo_set_.clear();
            DM->DBI.GetRecordSet(sql, keiryo_set_);

            // 2�s��
            //for (int col = 0; col < SCGrid->ColCount; col++){
            for (int col = 0; col <= line_colcount_map_[2]; col++){
                col_row_map_.clear();
                col_row_map_[col] = 2;
                ctnm = coord_name_map_.find(col_row_map_);
                if (ctnm == coord_name_map_.end()){
                    SCGrid->Cells[col][row] = AnsiString();
                    row_id_map_[row]        = 0;
                }else{
                    if (ctnm->second == "���ה��l" || ctnm->second == "�P�ʃ}�X�^����")
                        SCGrid->Cells[col][row] = ToString(keiryo_set_[r][ctnm->second]);
                    else
                        SCGrid->Cells[col][row] = ToCurrency(keiryo_set_[r][ctnm->second]);

                    row_id_map_[row]     = ToInt(keiryo_set_[r]["�v��ID"]);
                    row_lineno_map_[row] = r + 1;
                }
            }
        }
        row++;
    }

    // ���v���̍X�V
    TotalWeightLabel->Caption = FormatFloat("#,##0 kg", GetTotalWeight());
    GetTotalMoney();

    return true;
}
//---------------------------------------------------------------------------
// �V�K�v�ʊJ�n
void __fastcall TMainForm::StartWeighing()
{
    ClearForm();

    SetMode(imFirst);

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
    case 0:  // �ؗ���
        break;
    case 1:  // ������
        Application->MessageBox("���̑ؗ��Ԃ͂��łɌv�ʂ���Ă��܂��B\r\n��PC�ȂǂŌv�ʂ���Ă��Ȃ����m�F���Ă��������B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    default: // �폜��
        Application->MessageBox("�ؗ��f�[�^�̓ǂݍ��݂Ɏ��s���܂����B",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

    TNotifyEvent OnExit = ShabanEdit->OnExit;
    ShabanEdit->OnExit  = 0;

    //SecondWEdit->Text = cur_weight_;

    //CalcWeight();

    int meisai_max_no = keiryo_set_.size();
    if (TokuCodeEdit->Text.IsEmpty() && TokuPanel->Visible){
        TokuCodeEdit->SetFocus();
    }else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible){
        Komoku1CodeEdit->SetFocus();
    }else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible){
        Komoku2CodeEdit->SetFocus();
    //}else if (ToInt(keiryo_set_[keiryo_set_.size()]["2��ڏd��"]) != 0){
    }else if (ToInt(keiryo_set_[meisai_max_no - 1]["2��ڏd��"]) != 0){
        MeisaiAddButton->OnClick(NULL);
    }else if (ToInt(keiryo_set_[meisai_max_no - 1]["�i�ڃR�[�h"]) == 0){
        int row = keiryo_set_.size() * detail_line;

        SCGrid->SetFocus();
        SCGrid->Row = row;
        SCGrid->Col = GetColNo("�i�ڃR�[�h");
        SCGrid->Options = SCGrid->Options << goEditing;
    }else{
        int row = keiryo_set_.size() * detail_line;

        SCGrid->SetFocus();
        SCGrid->Row     = row;
        SCGrid->Col     = GetColNo("2��ڏd��");
        SCGrid->Cells[GetColNo("2��ڏd��")][row] = cur_weight_;
        //Sleep(100);
        SCGrid->Options = SCGrid->Options << goEditing;
    }

    ShabanEdit->OnExit  = OnExit;
}
//---------------------------------------------------------------------------
// �񂲂ƂɃf�[�^�ύX�����������`�F�b�N
void __fastcall TMainForm::UpdateCheck()
{
    // row_id_map_  �c �sNo����ID���i�[
    // id_edit_map_ �c ID���Ƀf�[�^�ύX(1:����,0:�Ȃ�)���i�[

    int show_max_line_no = GetMaxLineNo();

    // �e�s�e�Z�����ƂɌďo���ƈႤ�f�[�^���邩�`�F�b�N����
    int row = detail_line;
    CoordToNameMap::iterator ctnm;
    id_edit_map_.clear(); // �ҏWMap������
    for (int i = 0; i < show_max_line_no; i++){

        // 1�s��
        for (int c = 0; c < SCGrid->ColCount; c++){
            col_row_map_.clear();
            col_row_map_[c] = 1;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == coord_name_map_.end())
                break;

            if (ctnm->second == "�i�ڃ}�X�^����" || ctnm->second == "�P�ʃ}�X�^����" || ctnm->second == "���ה��l"){
                if (SCGrid->Cells[c][row] != ToString(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }else{
                if (StrToCurrDef(SCGrid->Cells[c][row], 0) != ToCurrency(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }
        }
        row++;

        // �s�\����1�s ���� 1�s�ڂɕύX���ڂ��������玟�̃��[�v
        if (detail_line < 2 || id_edit_map_[row_id_map_[row - 1]] == 1)
            continue;


        // 2�s��
        for (int c = 0; c < SCGrid->ColCount; c++){
            col_row_map_.clear();
            col_row_map_[c] = 2;
            ctnm = coord_name_map_.find(col_row_map_);
            if (ctnm == coord_name_map_.end())
                break;

            if (ctnm->second == "���ה��l"){
                if (SCGrid->Cells[c][row] != ToString(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }else{
                if (StrToCurrDef(SCGrid->Cells[c][row], 0) != ToCurrency(keiryo_set_[i][ctnm->second])){
                    id_edit_map_[row_id_map_[row]] = 1;
                    break;
                }
            }
        }
        row++;
    }
}
//---------------------------------------------------------------------------
// ���̓f�[�^�`�F�b�N
bool __fastcall TMainForm::CheckEdit()
{
    int row_no;

    // �\������Ă���ő�s���擾����Row�擾
    for (int r = detail_line; r < max_row; r += detail_line){
        if (!SCGrid->Cells[0][r].IsEmpty())
            row_no = SCGrid->Cells[0][r].ToIntDef(0);
    }
    row_no = row_no * detail_line;

    // 20120614 �V�K��1��ڏd�ʓo�^�̏ꍇ�́A�ԔԂ�1��ڏd�ʂɐ��l�������Ă���Γo�^�ɂ���
    if (row_no == detail_line && GetMode() == imFirst){
        Currency f_weight = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", row_no)], 0);
        if (f_weight > 0)
            return true;
    }
/*
    CellsMap::iterator   cm;
    ColInfoMap::iterator cim;
    for (int row = detail_line; row <= row_no; row += detail_line){

        // �i�ڃR�[�h�`�F�b�N
        if (SCGrid->Cells[GetColNo("�i�ڃR�[�h")][CalcRowNo("�i�ڃR�[�h", row)].ToIntDef(0) == 0){
            Application->MessageBox("�i�ڃR�[�h����͂��Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SCGrid->SetFocus();
            SCGrid->Col = GetColNo("�i�ڃR�[�h");
            SCGrid->Row = CalcRowNo("�i�ڃR�[�h", row);
            return false;
        }

        // ���ה��l��20byte�ŋ����I�ɐ؂�l�߂�
        SCGrid->Cells[GetColNo("���ה��l")][CalcRowNo("���ה��l", row)] = DM->AdjustString(SCGrid->Cells[GetColNo("���ה��l")][CalcRowNo("���ה��l", row)], 20);
    }
*/
    for (int row = detail_line; row <= row_no; row += detail_line){
        // ���ה��l��20byte�ŋ����I�ɐ؂�l�߂�
        SCGrid->Cells[GetColNo("���ה��l")][CalcRowNo("���ה��l", row)] = DM->AdjustString(SCGrid->Cells[GetColNo("���ה��l")][CalcRowNo("���ה��l", row)], 20);
    }

    return true;
}
//---------------------------------------------------------------------------
// �v�ʓo�^
void __fastcall TMainForm::PostWeighing()
{
    ///// ���ׂ̃f�[�^�o�^�����́A�������I������Ă�����o�^�Ώ�
    // 20120614�ǉ�
    // 1���זڂ�1��ڏd�ʂ̓o�^�͖����I���Ȃ��ł��o�^����

    InputMode mode = GetMode();

    TDateTime now(Now());
    int place_id = ToInt(DM->DBI.Lookup("M_���_", "���_����", PlaceCombo->Items->Strings[PlaceCombo->ItemIndex], "���_ID"));
    int print_id; // �������v��ID

    if (!CheckOverload())
        return;

    if (!ValidateForm())
        return;

    // �o�^�Ώۂ̍ő�sNo�擾(�����R�[�h�Ŕ���)
    int max_meisai_no = GetMaxLineNo_M();

    Currency w1, w2, net;
    w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", SCGrid->Row)], 0);
    w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", SCGrid->Row)], 0);
    net = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", SCGrid->Row)],  0);

    bool comp;
    int  value;

    // �o�^���閾�׍s���ő�s�����`�F�b�N
    PostConfForm->ButtonKeizoku->Enabled = true;
    if (max_meisai_no == max_line_no_)
        PostConfForm->ButtonKeizoku->Enabled = false;

    value = PostConfForm->ShowModal();
    if (value == IDYES)     // �����{�^��
        comp = true;
    else if (value == IDNO) // �p���{�^��
        comp = false;
    else                    // �L�����Z���{�^��
        return;

    int toku_id, hin_id, item1_id, item2_id, slip_tax;
    AnsiString toku_name, hin_name, item1_name, item2_name;
    AnsiString msg;

    toku_id    = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuCodeEdit->Text.ToIntDef(0),    "���Ӑ�ID"));
    toku_name  = TokuNameEdit->Text;
    item1_id   = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h",   Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
    item1_name = Komoku1NameEdit->Text;
    item2_id   = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h",   Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
    item2_name = Komoku2NameEdit->Text;

    // ���ׂ̐������o�^
    int row = detail_line;
    int register_keiryo_no  = 0;
    int line_no;
    //int torihiki_slip_no    = DM->GetTransNo(place_id, DateToInt(KeiryoDatePicker->Date)); // ����`�[No�擾���Ă���
    int before_slip_no      = KeiryoNoEdit->Text.ToIntDef(0);
    int post_slip_no        = 0;
    TDateTime old_second_time; // �O�̖��ׂ̌v�ʎ���2
    bool create_tran_data   = false;


    NsFieldSet fields;
    if (new_car_){
        //////////////////////////////////////////////////////////////////////
        // �V�K�ԗ��̏ꍇ�A�ԗ��}�X�^���X�V

        new_car_fields_
            << NsField("[�ԗ�����]",   SharyoNameEdit->Text)
            << NsField("[�g�p�敪]",   1)
            << NsField("[�X�V����]",   now)
            << NsField("[�쐬����]",   now)
            ;
        DM->DBI.Insert("M_�ԗ�", new_car_fields_);
        //DM->DBI.Update("M_�ԗ�", "�ԗ�ID", car_id_, fields);

        car_id_ = DM->DBI.GetLastID();
    }

    fields.clear();

    DM->ADOConnection->BeginTrans();
    // ���׍폜���������ꍇ�́A���ׂ��폜���Ă���o�^����
    if (delete_flag_){
        NsFieldSet keys;
        keys << NsField("[�v�ʓ�]", DateToInt(KeiryoDatePicker->Date))
             << NsField("[�`�[No]", IntToStr(before_slip_no))
             << NsField("[���_ID]", place_id);
        try{
            DM->DBI.Delete("D_�v��", keys);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("���׃f�[�^�폜�Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
    }
    delete_flag_ = false;

    for (int i = 1; i <= max_meisai_no; i++){ // i��RowNo�Ɋ��蓖��

        w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (row * i))], 0);
        w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (row * i))], 0);
        net = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (row * i))],   0);

        line_no  = i;
        hin_id   = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", SCGrid->Cells[GetColNo("�i�ڃR�[�h")][CalcRowNo("�i�ڃR�[�h", (row * i))].ToIntDef(0), "�i��ID"));
        hin_name = SCGrid->Cells[GetColNo("�i�ڃ}�X�^����")][CalcRowNo("�i�ڃ}�X�^����", (row * i))];

        NsFieldSet torihiki_fields;
        fields.clear();
        fields << NsField("[�ԗ�ID]",     car_id_)
               << NsField("[���Ӑ�ID]",   toku_id)
               << NsField("[���Ӑ於��]", toku_name)
               << NsField("[����1ID]",    item1_id)
               << NsField("[����1����]",  item1_name)
               << NsField("[����2ID]",    item2_id)
               << NsField("[����2����]",  item2_name)
               << NsField("[���l]",       BikoEdit->Text)

               // ���׃f�[�^
               << NsField("[�sNo]",       line_no)
               << NsField("[�i��ID]",     hin_id)
               << NsField("[�i�ږ���]",   hin_name)
               //<< NsField("[�����o�敪]", HannyuCombo->ItemIndex + 1)
        ;

        // 20120530 ����}�X�^�̓��o�Ɏg�p�敪�̏���
        // ���o�Ɏg�p�敪���u�g�p���Ȃ��v�ɂ����ꍇ�͑S��1:�����œo�^
        if (ToBit(DM->CFG["���o�Ɏg�p�敪"]))
            fields << NsField("[�����o�敪]", HannyuCombo->ItemIndex + 1);
        else
            fields << NsField("[�����o�敪]", 1);

        // �v��ID���擾
        NsRecordSet set;
        AnsiString  sql;
        sql = " SELECT"
              "     *"
              " FROM"
              "     D_�v��"
              " WHERE"
              "     �v�ʓ� = " + KeiryoDatePicker->Date.FormatString("yyyymmdd") +
              " AND"
              "     ���_ID = " + IntToStr(place_id) +
              " AND"
              "     �`�[No = " + IntToStr(before_slip_no) + // �o�^�O�ɓ`�[�ԍ���Edit�ɏ㏑������̂ŕϐ��ɂ���
              " AND"
              "     �sNo = "   + IntToStr(line_no) +
              " AND"
              "     �����敪 <> 9";
        if (!DM->DBI.GetRecordSet(sql, set)){
            keiryo_id_ = 0;
        }else{
            keiryo_id_ = ToInt(SET_TOP(set)["�v��ID"]);

            if (ToString(SET_TOP(set)["�v�ʓ���2"]) == "")
                old_second_time = now;
            else
                old_second_time = ToString(SET_TOP(set)["�v�ʓ���2"]);
        }

        if (!ToBit(DM->CFG["�����g�p�敪"])){
            fields << NsField("[������]",   0)
                   << NsField("[�����d��]", 0);
        }else{
            fields << NsField("[������]",   StrToCurrDef(SCGrid->Cells[GetColNo("������")][CalcRowNo("������", (row * i))], 0))
                   << NsField("[�����d��]", StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (row * i))], 0));
        }

        if (!ToBit(DM->CFG["�d�ʈ����g�p�敪"]))
            fields << NsField("[�d�ʈ���]", 0);
        else
            fields << NsField("[�d�ʈ���]", StrToCurrDef(SCGrid->Cells[GetColNo("�d�ʈ���")][CalcRowNo("�d�ʈ���", (row * i))], 0));

        fields << NsField("[�����d��]", net)
               << NsField("[���ה��l]", SCGrid->Cells[GetColNo("���ה��l")][CalcRowNo("���ה��l", (row * i))]);

        if (!ToBit(DM->CFG["�P���g�p�敪"])){
            fields << NsField("[�P��ID]",       0)
                   << NsField("[����]",         0)
                   << NsField("[�P��]",         0)
                   << NsField("[���z]",         0)
                   << NsField("[����Ŋz]",     0)
                   << NsField("[�`�[����Ŋz]", 0);
        }else{
            fields << NsField("[�P��ID]",       ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", SCGrid->Cells[GetColNo("�P�ʃR�[�h")][CalcRowNo("�P�ʃR�[�h", (row * i))].ToIntDef(0), "�P��ID")))
                   << NsField("[����]",         StrToCurrDef(SCGrid->Cells[GetColNo("����")][CalcRowNo("����", (row * i))], 0))
                   << NsField("[�P��]",         StrToCurrDef(SCGrid->Cells[GetColNo("�P��")][CalcRowNo("�P��", (row * i))], 0))
                   << NsField("[���z]",         SCGrid->Cells[GetColNo("���z")][CalcRowNo("���z", (row * i))].ToIntDef(0))
                   << NsField("[����Ŋz]",     SCGrid->Cells[GetColNo("����Ŋz")][CalcRowNo("����Ŋz", (row * i))].ToIntDef(0))
                   << NsField("[�`�[����Ŋz]", slip_tax_);
        }

        int cmp_kbn;

        try{

            if (mode == imFirst){  //***** ����v��
                fields << NsField("[�v�ʓ�]",   DateToInt(KeiryoDatePicker->Date))
                       << NsField("[���_ID]",   place_id)
                       << NsField("[�X�V����]", now)
                       << NsField("[�쐬����]", now)
                ;

                if (!comp){        // 1��ڌv��
                    if (post_slip_no == 0){
                        KeiryoNoEdit->Text = DM->GetTempNo(place_id);
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    fields << NsField("[�`�[No]",    post_slip_no)
                           << NsField("[1��ڏd��]", w1)
                           << NsField("[�v�ʓ���1]", now)
                           << NsField("[�����敪]",  0)
                    ;

                    if (w2 != 0){  // 2��ڏd�ʂ�0�ȊO�Ȃ�o�^����
                        fields << NsField("[2��ڏd��]", w2)
                               << NsField("[�v�ʓ���2]", now);
                    }

                    msg = "�ؗ��ԂƂ��ēo�^���܂���";
                }else{             // �S�o�^
                    if (post_slip_no == 0){
                        KeiryoNoEdit->Text = DM->GetKeiryoNo(place_id, DateToInt(KeiryoDatePicker->Date));
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    fields << NsField("[�`�[No]",    post_slip_no)
                           << NsField("[1��ڏd��]", w1)
                           << NsField("[2��ڏd��]", w2)
                           << NsField("[�v�ʓ���1]", now)
                           << NsField("[�v�ʓ���2]", now)
                           << NsField("[�����敪]",  1)
                    ;
                    msg = "�v�ʂ��������܂���";
                    create_tran_data = ToInt(DM->CFG["����f�[�^�쐬"]) ? true : false;
                }

                DM->DBI.Insert("D_�v��", fields);
                keiryo_id_ = DM->DBI.GetLastID();

            }else if (mode == imSecond){            //***** �ؗ���
                if (!comp){ // �ؗ��ԓo�^
                    fields << NsField("[1��ڏd��]", w1)
                           << NsField("[2��ڏd��]", w2)
                           << NsField("[�����敪]",  0);
                    msg = "�ؗ������X�V���܂���";
                }else{      // �����o�^
                    if (register_keiryo_no == 0)
                        register_keiryo_no = DM->GetKeiryoNo(place_id, DateToInt(KeiryoDatePicker->Date));

                    fields << NsField("[�v�ʓ�]",    DateToInt(KeiryoDatePicker->Date))
                           << NsField("[���_ID]",    place_id)
                           << NsField("[�`�[No]",    register_keiryo_no)
                           << NsField("[1��ڏd��]", w1)
                           << NsField("[2��ڏd��]", w2)
                           << NsField("[�����敪]",  1);
                    msg = "�v�ʂ��������܂���";
                    create_tran_data = ToInt(DM->CFG["����f�[�^�쐬"]) ? true : false;
                }

                // �v��ID��0��������v�ʓ���1,2��o�^
                if (keiryo_id_ == 0){
                    fields << NsField("[�v�ʓ���1]", old_second_time);

                    old_second_time = now;
                    fields << NsField("[�v�ʓ���2]", old_second_time);
                }

                // �sNo����ID�擾���āA�ύX����������X�V�����o�^
                if (id_edit_map_[row_id_map_[row * i]] != 0)
                    fields << NsField("[�X�V����]", now);

                if (keiryo_id_ != 0){
                    // 1���זڂ�2��ڏd�ʂ�0�ȊO�̎��͌v�ʓ���2��o�^
                    if (max_meisai_no == 1 && line_no == 1 && w2 != 0){
                        old_second_time = now;
                        fields << NsField("[�v�ʓ���2]", GetTimePicker_ZeroSec());
                    }

                    DM->DBI.Update("D_�v��", "�v��ID", keiryo_id_, fields);
                }else if (comp){
                    fields << NsField("[�쐬����]",  now);

                    DM->DBI.Insert("D_�v��", fields);
                    keiryo_id_ = DM->DBI.GetLastID();
                }else{
                    if (register_keiryo_no == 0)
                        register_keiryo_no = before_slip_no;

                    fields << NsField("[�v�ʓ�]",   DateToInt(KeiryoDatePicker->Date))
                           << NsField("[���_ID]",   place_id)
                           << NsField("[�`�[No]",   register_keiryo_no)
                           << NsField("[�쐬����]", now);
                    DM->DBI.Insert("D_�v��", fields);
                    keiryo_id_ = DM->DBI.GetLastID();
                }

            }else if (mode == imMod){               //***** �C��
                cmp_kbn = ToInt(keiryo_set_[i - 1]["�����敪"]);
                TDateTime date1, date2;

                fields << NsField("[1��ڏd��]", w1)
                       << NsField("[2��ڏd��]", w2);

                if (id_edit_map_[row_id_map_[row * i]] != 0)
                    fields << NsField("[�X�V����]", now);

                int date = DateToInt(KeiryoDatePicker->Date);
                if (comp){
                    ///// �����敪 /////
                    if (post_slip_no == 0 && cmp_kbn == 0){ // �����敪���o�^�O�ƈႤ���A�v��No�擾
                        int no = DM->GetKeiryoNo(place_id, date);
                        KeiryoNoEdit->Text = no;
                        post_slip_no = no;
                    }else if (post_slip_no == 0){
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    if (cmp_kbn == 0 && keiryo_id_ != 0){
                        fields << NsField("[�v�ʓ�]",   date)
                               << NsField("[���_ID]",   place_id)
                               << NsField("[�`�[No]",   post_slip_no);
                    }
                    fields << NsField("[�����敪]", 1);
                    create_tran_data = ToInt(DM->CFG["����f�[�^�쐬"]) ? true : false;
                }else{
                    ///// �ؗ��ԓo�^ /////
                    if (post_slip_no == 0 && cmp_kbn == 1){ // �����敪���o�^�O�ƈႤ���A�v��No�擾
                        KeiryoNoEdit->Text = DM->GetTempNo(place_id);
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }else if (post_slip_no == 0){
                        post_slip_no = KeiryoNoEdit->Text.ToIntDef(0);
                    }

                    if (cmp_kbn == 1 && keiryo_id_ != 0){
                        fields << NsField("[�v�ʓ�]",   date)
                               << NsField("[���_ID]",   place_id)
                               << NsField("[�`�[No]",   post_slip_no);
                    }
                    fields << NsField("[�����敪]", 0);
                    create_tran_data = false;
                }

                // �C�����[�h�ŐV���ɍ쐬�����s�̏���
                if (keiryo_id_ == 0){
                    fields << NsField("[�v�ʓ�]",    date)
                           << NsField("[���_ID]",    place_id)
                           << NsField("[�`�[No]",    post_slip_no)
                           << NsField("[�v�ʓ���1]", now)
                           << NsField("[�쐬����]",  now);

                    if (max_meisai_no == i)
                        fields << NsField("[�v�ʓ���2]", GetTimePicker_ZeroSec());
                    else
                        fields << NsField("[�v�ʓ���2]", now);
                }

                // �Ō�̖��׃f�[�^�̌v�ʎ���2�Ɉ󎚌v�ʎ��Ԃ��㏑������
                if (keiryo_id_ != 0 && max_meisai_no == i)
                    fields << NsField("[�v�ʓ���2]", GetTimePicker_ZeroSec());

                msg = "�o�^���܂���";

                if (keiryo_id_ != 0){
                    DM->DBI.Update("D_�v��", "�v��ID", keiryo_id_, fields);
                }else{
                    DM->DBI.Insert("D_�v��", fields);
                    keiryo_id_ = DM->DBI.GetLastID();
                }

            }else{
                return;
            }

            ///// ����f�[�^�쐬
            if (mode == imMod && create_tran_data && ToInt(DM->CFG["����f�[�^�쐬"])){
	    		if (Application->MessageBox("����f�[�^���o�^/�C�����܂����H", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
                    create_tran_data = false;
            }

            if (create_tran_data){

                NsRecordSet set;
                AnsiString sql = "SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id_);
                DM->DBI.GetRecordSet(sql, set);

                fields.clear();
                fields << NsField("[�����]",       SET_TOP(set)["�v�ʓ�"])
                       << NsField("[���_ID]",       SET_TOP(set)["���_ID"])
                       << NsField("[�`�[No]",       DM->GetTransNo(ToInt(SET_TOP(set)["���_ID"]), ToInt(SET_TOP(set)["�v�ʓ�"])))
                       << NsField("[�v��ID]",       keiryo_id_)
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
                if (!DM->DBI.IsExist("D_���", "�v��ID", keiryo_id_)){
                    fields << NsField("[�쐬����]", now);
                    DM->DBI.Insert("D_���", fields);
                }else{
                    DM->DBI.Update("D_���", "�v��ID", keiryo_id_, fields);
                }
            }
        }catch(Exception& e){
            DM->ADOConnection->RollbackTrans();
            AnsiString msg = "�o�^���ɃG���[���������܂��� - " + e.Message;
            Application->MessageBox(msg.c_str(), "�o�^�G���[", MB_OK | MB_ICONWARNING);
            return;
        }
    }
    DM->ADOConnection->CommitTrans();

    // �ؗ��ԏ��X�V
    Q_Tairyu->Close();
    Q_Tairyu->Open();

    // �o�^���b�Z�[�W
    // �e�o�^�����Ƀ��b�Z�[�W�ϐ�����Ă����ŕ\������
    Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    print_id = GetHeaderID(keiryo_id_);

    if (mode != imMod){
        if (comp && AutoPrintCheck->Checked)
            Print(print_id);
    }else{
        if (!comp){
            LoadFromID(keiryo_id_);
            return;
        }

        if (AutoPrintCheck->Checked){
            if (Application->MessageBox("�C�������`�[�𔭍s���܂����H", Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDYES)
                Print(print_id);
        }
    }

    Action1->Execute();
}
//---------------------------------------------------------------------------
// �`�[���s
// ����}�X�^�̋��z�󎚋敪(money_print_div_�Ɋi�[)
// 0:�󎚂��Ȃ� 1:�����̂� 2:�|�̂� 3:��Ɉ󎚂���
void __fastcall TMainForm::Print(int keiryo_id)
{
    int slip_type    = ToInt(DM->CFG["�`�[���s�v�����^"]);
    //int tokuisaki_id = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id, "���Ӑ�ID"));
    //int pay_div      = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", tokuisaki_id, "���|�敪")); // 1:�| 2:����

    if (slip_type == 1){
        // ���[�U�[

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
                return;
        }else{
            if (LaserSlipPrintM_GenkinForm->Print(keiryo_id, HideTimeCheck->Checked))
                return;
        }

    }else if (slip_type == 2){
        // �h�b�g

        if (!DotSlipPrintForm->Print(keiryo_id, HideTimeCheck->Checked))
            return;

    }else{
        // nothing to do
    }

    if (GetMode() != imMod && DataDeleteCheck->Checked){
        NsRecordSet set;
        AnsiString  sql;
        int date, place_id, slip_no;

        if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id), set)){
            Application->MessageBox("�f�[�^�ďo�Ɏ��s���܂���\r\n�蓮�Ńf�[�^���폜���Ă�������", Caption.c_str(), MB_OK | MB_ICONWARNING);
                return;
        }

        date     = ToInt(SET_TOP(set)["�v�ʓ�"]);
        place_id = ToInt(SET_TOP(set)["���_ID"]);
        slip_no  = ToInt(SET_TOP(set)["�`�[No"]);
        sql = " DELETE"
              "     FROM D_�v��"
              " WHERE"
              "     �v�ʓ� = " + IntToStr(date) +
              " AND"
              "     ���_ID = " + IntToStr(place_id) +
              " AND"
              "     �`�[No = " + IntToStr(slip_no);
        DM->ADOConnection->BeginTrans();
        if (!DM->DBI.Execute(sql)){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox("�f�[�^�폜�Ɏ��s���܂���\r\n�蓮�Ńf�[�^���폜���Ă�������", Caption.c_str(), MB_OK | MB_ICONWARNING);
            return;
        }
        DM->ADOConnection->CommitTrans();
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
    //Currency w1  = StrToCurrDef(FirstWEdit->Text, 0);
    //Currency w2  = StrToCurrDef(SecondWEdit->Text, 0);
    //Currency net = StrToCurrDef(ShomiEdit->Text, 0);
    //Currency max = std::max(w1, w2);
    Currency w1, w2, net, max, car_gross_weight = 0, max_net_weight = 0;

    int line_no = GetMaxLineNo_M() + 1;
    for (int i = 1; i < line_no; i++){
        w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (detail_line * i))], 0);
        w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (detail_line * i))], 0);
        net = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (detail_line * i))],   0);
        max = std::max(w1, w2);

        if (max > car_gross_weight)
            car_gross_weight = max;

        if (net > max_net_weight)
            max_net_weight = net;
    }

    AnsiString msg;

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
/*
    if (GetMode() == imMod)
        return;

    int meig_id  = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinCodeEdit->Text.ToIntDef(0), "�i��ID"));

    TaniCodeEdit->Text = DM->GetKanzanCode(toku_id_, meig_id);
*/
}
//---------------------------------------------------------------------------
// �����d�ʌv�Z
void __fastcall TMainForm::CalcWeight(int row)
{
    // ���׃O���b�h�̃^�C�g���������Ă��܂��̂�
    // detail_line��菬����row��return
    if (row < detail_line)
        return;

    int w1, w2, net;

    try{
        w1 = StrToCurr(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", row)]);
        w2 = StrToCurr(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", row)]);
    }catch(...){
        SCGrid->Cells[GetColNo("�����d��")][row] = AnsiString();

        if (ToBit(DM->CFG["�P���g�p�敪"]))
            SCGrid->Cells[GetColNo("����")][row] = AnsiString();

        return;
    }

    net = std::abs(w1 - w2);

    if (ToBit(DM->CFG["�����g�p�敪"])){
        Currency coord, coord_ratio;

        coord       = SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", row)].ToIntDef(0);
        coord_ratio = StrToCurrDef(SCGrid->Cells[GetColNo("������")][CalcRowNo("������", row)], 0) / 100;

        if (coord_ratio > 0){ // �������g�p
            coord = ExtendedRound(net * coord_ratio, ToInt(DM->CFG["�����[����������"]), ToInt(DM->CFG["�����[�������敪"]));
            SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", row)] = coord;
        }else{
            // ������0�ȉ��̏ꍇ�͒����d�ʂ�0�ɂ���悤��
            coord = 0;
            SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", row)] = 0;
        }

        net -= int(coord);
    }

    if (ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
        Currency reduc = StrToCurrDef(SCGrid->Cells[GetColNo("�d�ʈ���")][CalcRowNo("�d�ʈ���", row)], 0);
        net -= int(reduc);
    }

    SCGrid->Cells[GetColNo("�����d��")][row] = net;

    if (ToBit(DM->CFG["�P���g�p�敪"]) && SCGrid->Cells[GetColNo("�P�ʃR�[�h")][CalcRowNo("�P�ʃR�[�h", row)].ToIntDef(0) == 0){
        SCGrid->Cells[GetColNo("�P�ʃR�[�h")][CalcRowNo("�P�ʃR�[�h", row)]     = standard_tani_code_;
        SCGrid->Cells[GetColNo("�P�ʃ}�X�^����")][CalcRowNo("�P�ʃR�[�h", row)] = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", standard_tani_code_, "�P�ʖ���"));
    }

    // ���v�d�ʌv�Z
    TotalWeightLabel->Caption = FormatFloat("#,##0 kg", GetTotalWeight());

    if (ToBit(DM->CFG["�P���g�p�敪"]))
        CalcAmount(row);
}
//---------------------------------------------------------------------------
// ���ʂƋ��z�̌v�Z
void __fastcall TMainForm::CalcAmount(int row)
{
    //if (GetMode() == imMod)
        //return;

    Currency net = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", row)], 0);
    int meig_id  = ToInt(DM->DBI.Lookup("M_�i��",  "�i�ڃR�[�h",  SCGrid->Cells[GetColNo("�i�ڃR�[�h")][CalcRowNo("�i�ڃR�[�h", row)].ToIntDef(0), "�i��ID"));
    int item1_id = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Komoku1CodeEdit->Text.ToIntDef(0), "����1ID"));
    int item2_id = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Komoku2CodeEdit->Text.ToIntDef(0), "����2ID"));
    tani_id_     = 0;
    AnsiString tani_name = AnsiString();

    if (detail_line == 2){

        // �P�ʃR�[�h��0�̏ꍇ�͕W���P�ʂ�����
        int tani_code = SCGrid->Cells[GetColNo("�P�ʃR�[�h")][CalcRowNo("�P�ʃR�[�h", row)].ToIntDef(0);
        if (tani_code == 0){
            int default_code = ToInt(DM->CFG["�W���P��"]);

            if (!default_code)
                default_code = 3;

            SCGrid->Cells[GetColNo("�P�ʃR�[�h")][CalcRowNo("�P�ʃR�[�h", row)] = default_code;
        }

        tani_id_  = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", SCGrid->Cells[GetColNo("�P�ʃR�[�h")][CalcRowNo("�P�ʃR�[�h", row)].ToIntDef(0), "�P��ID"));
        tani_name = ToString(DM->DBI.Lookup("M_�P��", "�P��ID", tani_id_, "�P�ʖ���"));
    }

    if (tani_id_ != 3)
        net = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", row)], 0) / Currency(1000);

    Currency quantity;
    Currency cnv_ratio = DM->GetKanzan(toku_id_, meig_id, tani_id_);

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

    if (quantity > ToCurrency(DM->CFG["���m3����"])
            && SCGrid->Cells[GetColNo("�P�ʃR�[�h")][CalcRowNo("�P�ʃR�[�h", row)].ToIntDef(0) == 2){
        quantity = ToCurrency(DM->CFG["���m3����"]);
    }

    SCGrid->Cells[GetColNo("����")][CalcRowNo("����", row)] = quantity;

    if (!ToBit(DM->CFG["�P���g�p�敪"])){
        // �P���L�����̃f�[�^�������邩������Ȃ��̂ŃR�����^�E�g
        //TankaEdit->Text    = "0";
        //KingakuEdit->Text  = "0";
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency tanka = StrToCurrDef(SCGrid->Cells[GetColNo("�P��")][CalcRowNo("�P��", row)], 0);
    tanka = DM->GetTanka(toku_id_, meig_id, item1_id, item2_id, tani_id_);

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


    //SCGrid->Cells[GetColNo("�P��")][CalcRowNo("����", row)] = tanka;
    //SCGrid->Cells[GetColNo("���z")][CalcRowNo("����", row)] = amount;
    SCGrid->Cells[GetColNo("�P��")][CalcRowNo("�P��", row)] = tanka;
    SCGrid->Cells[GetColNo("���z")][CalcRowNo("���z", row)] = amount;

    CalcSalesTax(row);
}
//---------------------------------------------------------------------------
// ����ŎZ�o
void __fastcall TMainForm::CalcSalesTax(int row)
{
    if (!ToBit(DM->CFG["�P���g�p�敪"])){
        // �P���L�����̃f�[�^�������邩������Ȃ��̂ŃR�����^�E�g
        //ShohizeiEdit->Text = "0";
        return;
    }

    Currency quantity, tanka;
    quantity = StrToCurrDef(SCGrid->Cells[GetColNo("����")][CalcRowNo("����", row)], 0);
    tanka    = StrToCurrDef(SCGrid->Cells[GetColNo("�P��")][CalcRowNo("�P��", row)], 0);
    ///// ���z�[�������敪�̎擾
    int amount_div = -1;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["���z�[�������敪"]))
            amount_div = ToInt(toku_rec_["���z�[�������敪"]);
    }
    if (amount_div == -1)
        amount_div = ToInt(DM->CFG["���z�[�������敪"]);
    /////

    int amount = ExtendedRound(quantity * tanka, 0, amount_div);

    SCGrid->Cells[GetColNo("�P��")][CalcRowNo("����", row)] = tanka;
    SCGrid->Cells[GetColNo("���z")][CalcRowNo("����", row)] = amount;

	Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date));          // ����ŗ�

    ///// ����Œ[�������敪�̎擾
    int tax_div = -1;
    int tax_fig = 0;

    if (!toku_rec_.empty()){
        if (!IsNull(toku_rec_["����Œ[�������敪"]))
            tax_div = ToInt(toku_rec_["����Œ[�������敪"]);
    }
    if (tax_div == -1)
        tax_div = ToInt(DM->CFG["����Œ[�������敪"]);
    if (tax_fig == 0)
        tax_fig = ToInt(DM->CFG["����Œ[����������"]);
    /////

    //int amount, tax;
    int tax;
    amount = SCGrid->Cells[GetColNo("���z")][CalcRowNo("���z", row)].ToIntDef(0);
    tax    = ExtendedRound(Currency(amount) * tax_rate, tax_fig, tax_div);

    SCGrid->Cells[GetColNo("����Ŋz")][CalcRowNo("����Ŋz", row)] = tax;

    GetTotalMoney();
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
    ClearDetailGrid();
}
//---------------------------------------------------------------------------
// F2 �C��
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
    ClearForm();
    SetMode(imMod);

    // ���ꋒ�_�̍ŏI���R�[�h���擾
    keiryo_id_ = DM->GetLastKeiryoID(GetPlaceID());

    if (keiryo_id_ < 1){
        Application->MessageBox("�C������f�[�^�͂���܂���",
                                Caption.c_str(), MB_OK | MB_ICONWARNING);
        Action1->Execute();
        return;
    }

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

    NsRecordSet set;
    AnsiString  sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     D_�v��"
          " WHERE"
          "     �v��ID = " + IntToStr(keiryo_id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("�f�[�^���o�Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    NsFieldSet fields, key;
    fields << NsField("[�`�[No]",   DM->GetTempNo(GetPlaceID()))
           << NsField("[�����敪]", 9);

    key    << NsField("[�v�ʓ�]",   ToInt(SET_TOP(set)["�v�ʓ�"]))
           << NsField("[�`�[No]",   ToInt(SET_TOP(set)["�`�[No"]))
           << NsField("[���_ID]",   ToInt(SET_TOP(set)["���_ID"]));

    DM->DBI.Update("D_�v��", key, fields);

    if (mode == imSecond)
        Action1->Execute();
    else
        Action2->Execute();
}
//---------------------------------------------------------------------------
// F4
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
    if (ActiveControl != SCGrid){
    	if (ActiveControl == ShabanEdit)
	    	SharyoButton->Click();
    	else if (ActiveControl == TokuCodeEdit)
            TokuButton->Click();
        else if (ActiveControl == Komoku1CodeEdit)
            Komoku1Button->Click();
        else if (ActiveControl == Komoku2CodeEdit)
            Komoku2Button->Click();

        return;
    }

    AnsiString cell_name = GetCellName(SCGrid->Col, SCGrid->Row);
    if (cell_name == "�i�ڃR�[�h" || cell_name == "�i�ڃ}�X�^����"){
        // �i�ڃ}�X�^�Q��
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT �i�ڃR�[�h, �i�ږ��� FROM M_�i�� WHERE �g�p�敪 = 1";
        SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
        SearchForm->table_name  = "M_�i��";

        if (SearchForm->ShowModal() != mrOk){
            if (cell_name == "�i�ڃ}�X�^����") // �t�H�[�J�X�����̂Ȃ�R�[�h�Ɉړ�����
                SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("�i�ڃR�[�h")][SCGrid->Row]     = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
        SCGrid->Cells[GetColNo("�i�ڃ}�X�^����")][SCGrid->Row] = SearchForm->Query->FieldByName("�i�ږ���")->AsString;
        SCGrid->Col = GetColNo("�i�ڃR�[�h");
        SetImeMode(SCGrid->Handle, imClose);
    }else if (cell_name == "�P�ʃR�[�h" || cell_name == "�P�ʃ}�X�^����"){
        // �P�ʃ}�X�^�Q��
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P��";
        SearchForm->orderby_sql = " ORDER BY �P�ʃR�[�h ";
        SearchForm->table_name  = "M_�P��";

        if (SearchForm->ShowModal() != mrOk){
            if (cell_name == "�P�ʃ}�X�^����") // �t�H�[�J�X�����̂Ȃ�R�[�h�Ɉړ�����
                SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("�P�ʃR�[�h")][SCGrid->Row]     = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
        SCGrid->Cells[GetColNo("�P�ʃ}�X�^����")][SCGrid->Row] = SearchForm->Query->FieldByName("�P�ʖ���")->AsString;
        SCGrid->Col = GetColNo("�P�ʃR�[�h");
        SetImeMode(SCGrid->Handle, imClose);
    }
}
//---------------------------------------------------------------------------
// F5 �o�^
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
    if (!CheckEdit())
        return;

    UpdateCheck();

    GetTotalMoney();
    PostWeighing();
}
//---------------------------------------------------------------------------
// F6 �O��
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
    int id;

    if (keiryo_id_){ // �C���A�܂��͑ؗ����
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
    SetMode(imMod);

    keiryo_id_ = id;

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
    SetMode(imMod);

    keiryo_id_ = id;

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
    SetMode(imMod);

    keiryo_id_ = DataListForm->selected_id;

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
/*
    InputMode mode = GetMode();
    if (mode == imFirst){
        if (keiryo_count_ == 2 || keiryo_count_ == 0){
            FirstWEdit->Text = cur_weight_;
            FirstWEdit->SetFocus();
        }else{
            SecondWEdit->Text = cur_weight_;
            SecondWEdit->SetFocus();
        }
    }else if (mode == imSecond){
        SecondWEdit->Text = cur_weight_;
        SecondWEdit->SetFocus();
    }

    CalcWeight();
*/
    //if (SCGrid->Cells[0][detail_line].IsEmpty())
        //return;
    if (ShabanEdit->Text.ToIntDef(0) == 0)
        return;

    int current_row;
    InputMode mode = GetMode();
    if (mode == imFirst){
        // �V�K

        // 1���זڂɖ���No���o�Ă��Ȃ������疾�גǉ�����
        if (SCGrid->Cells[0][detail_line].IsEmpty())
            MeisaiAddButton->OnClick(NULL);

        current_row = detail_line;
        if (keiryo_count_ == 2 || keiryo_count_ == 0){
            SCGrid->Cells[3][detail_line] = cur_weight_; // 1��ڏd�ʂɓ����
            SCGrid->SetFocus();
            SCGrid->Col = 3;
            SCGrid->Row = detail_line;
        }else{
            SCGrid->Cells[4][detail_line] = cur_weight_; // 2��ڏd�ʂɓ����
            SCGrid->SetFocus();
            SCGrid->Col = 4;
            SCGrid->Row = detail_line;
        }
    }else if (mode == imSecond){
        // �ؗ�
/*
        current_row = 0;
        for (int i = detail_line; i < max_row; i += detail_line){
            if (!SCGrid->Cells[0][i].IsEmpty()){
                current_row = i;
            }else{
                break;
            }
        }

        // current_row��detail_line�������ꍇ�A1���זڂ�2��ڏd�ʂ������Ă����疾�ׂ�ǉ�����
        if (current_row == detail_line && StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][detail_line], 0) > 0){
            current_row = CalcNextRow(keiryo_id_);
            MeisaiAddButton->OnClick(NULL);
        }
*/
        current_row = CalcNextRow(keiryo_id_);
        if (SCGrid->Cells[0][current_row].IsEmpty())
            MeisaiAddButton->OnClick(NULL);

        SCGrid->Cells[4][current_row] = cur_weight_; // 2��ڏd�ʂɓ����
        SCGrid->SetFocus();
        SCGrid->Col = 4;
        SCGrid->Row = current_row;
    }

    CalcWeight(current_row);
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
    SearchForm->Top         = MainForm->Top;
    SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
    SearchForm->based_sql   = "SELECT ���Ӑ�R�[�h, ���Ӑ旪�� FROM M_���Ӑ� WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ���Ӑ�R�[�h ";
    SearchForm->table_name  = "M_���Ӑ�";
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
    SearchForm->Top         = MainForm->Top;
    SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
    SearchForm->based_sql   = "SELECT ����1�R�[�h, ����1���� FROM M_����1 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����1�R�[�h ";
    SearchForm->table_name  = "M_����1";
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
    SearchForm->Top         = MainForm->Top;
    SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
    SearchForm->based_sql   = "SELECT ����2�R�[�h, ����2���� FROM M_����2 WHERE �g�p�敪 = 1";
    SearchForm->orderby_sql = " ORDER BY ����2�R�[�h ";
    SearchForm->table_name  = "M_����2";
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
    // Windws��Version�ŃR���|�[�l���g�z�u��ύX����H
    // �Ƃ肠����Vista�ȍ~�̓R���|�[�l���g�����炵�Ă���
    major_version = Win32MajorVersion;
    minor_version = Win32MinorVersion;
    //int platform     = Win32Platform;

    if (major_version < 6){ // XP�ȑO
        int interval = 10;
        F1Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F2Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F3Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F4Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F5Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F6Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F7Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F8Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F9Button->Width  = int((MainForm->Width - interval * 4) / 12);
        F10Button->Width = int((MainForm->Width - interval * 4) / 12);
        F11Button->Width = int((MainForm->Width - interval * 4) / 12);
        F12Button->Width = int((MainForm->Width - interval * 4) / 12);

        F1Button->Left  = interval;
        F2Button->Left  = F1Button->Left + F1Button->Width - 1;
        F3Button->Left  = F2Button->Left + F2Button->Width - 1;
        F4Button->Left  = F3Button->Left + F3Button->Width - 1;
        F5Button->Left  = F4Button->Left + F4Button->Width - 1 + interval;
        F6Button->Left  = F5Button->Left + F5Button->Width - 1;
        F7Button->Left  = F6Button->Left + F6Button->Width - 1;
        F8Button->Left  = F7Button->Left + F7Button->Width - 1;
        F9Button->Left  = F8Button->Left + F8Button->Width - 1 + interval;
        F10Button->Left = F9Button->Left + F9Button->Width - 1;
        F11Button->Left = F10Button->Left + F10Button->Width - 1;
        F12Button->Left = F11Button->Left + F11Button->Width - 1;

        F1Panel->Left  = F1Button->Left + 3;
        F2Panel->Left  = F2Button->Left + 3;
        F3Panel->Left  = F3Button->Left + 3;
        F4Panel->Left  = F4Button->Left + 3;
        F5Panel->Left  = F5Button->Left + 3;
        F6Panel->Left  = F6Button->Left + 3;
        F7Panel->Left  = F7Button->Left + 3;
        F8Panel->Left  = F8Button->Left + 3;
        F9Panel->Left  = F9Button->Left + 3;
        F10Panel->Left = F10Button->Left + 3;
        F11Panel->Left = F11Button->Left + 3;
        F12Panel->Left = F12Button->Left + 3;

        F1Panel->Width  = F1Button->Width - 5;
        F2Panel->Width  = F2Button->Width - 5;
        F3Panel->Width  = F3Button->Width - 5;
        F4Panel->Width  = F4Button->Width - 5;
        F5Panel->Width  = F5Button->Width - 5;
        F6Panel->Width  = F6Button->Width - 5;
        F7Panel->Width  = F7Button->Width - 5;
        F8Panel->Width  = F8Button->Width - 5;
        F9Panel->Width  = F9Button->Width - 5;
        F10Panel->Width = F10Button->Width - 5;
        F11Panel->Width = F11Button->Width - 5;
        F12Panel->Width = F12Button->Width - 5;

        TairyuGrid->RowCount = int(TairyuGrid->Height / 63);

        // ���̃t�H�[���̃T�C�Y�����C���t�H�[���ɍ��킹��
        SearchForm->Height   = MainForm->Height;
        DataListForm->Height = MainForm->Height - 33;
        DataListForm->Width  = MainForm->Width  - 24;
        DataListForm->Top    = MainForm->Top    + 16;
        DataListForm->Left   = MainForm->Left   + 12;
    }else{                 // Vista�ȍ~
        int interval = 6;
        int frame    = 2;
        int mainform_width = MainForm->Width - frame;

        // TopPanel
        KyotenLabel->Left = KyotenLabel->Left - frame;
        PlaceCombo->Left  = PlaceCombo->Left - frame;
        WeightPanel->Left = WeightPanel->Left - frame;
        kgPanel->Left     = kgPanel->Left - frame;

        if (minor_version == 0) // Vista
            ScrollBox->Width = SharyoPanel->Width + 10;
        else                    // 7�ȍ~
            ScrollBox->Width = SharyoPanel->Width + 8;
        MeisaiScrollBox->Width = SharyoPanel->Width + frame;

        // MeisaiScrollBox
        HannyuCombo->Left = HannyuCombo->Left - 10;

        // TotalPanel
        TotalWeightTitle->Left = TotalWeightTitle->Left - frame;
        TotalWeightLabel->Left = TotalWeightLabel->Left - frame;
        TotalWeightShape->Left = TotalWeightShape->Left - frame;
        MoneyTitle->Left       = MoneyTitle->Left - frame;
        MoneyLabel->Left       = MoneyLabel->Left - frame;
        MoneyShape->Left       = MoneyShape->Left - frame;
        TaxTitle->Left         = TaxTitle->Left - frame;
        TaxLabel->Left         = TaxLabel->Left - frame;
        TaxShape->Left         = TaxShape->Left - frame;
        TotalMoneyTitle->Left  = TotalMoneyTitle->Left - frame;
        TotalMoneyLabel->Left  = TotalMoneyLabel->Left - frame;
        TotalMoneyShape->Left  = TotalMoneyShape->Left - frame;

        // KeyPanel
        KeyPanel->Height = 54;

        F1Button->Width  = int((mainform_width - interval * 4) / 12);
        F2Button->Width  = int((mainform_width - interval * 4) / 12);
        F3Button->Width  = int((mainform_width - interval * 4) / 12);
        F4Button->Width  = int((mainform_width - interval * 4) / 12);
        F5Button->Width  = int((mainform_width - interval * 4) / 12);
        F6Button->Width  = int((mainform_width - interval * 4) / 12);
        F7Button->Width  = int((mainform_width - interval * 4) / 12);
        F8Button->Width  = int((mainform_width - interval * 4) / 12);
        F9Button->Width  = int((mainform_width - interval * 4) / 12);
        F10Button->Width = int((mainform_width - interval * 4) / 12);
        F11Button->Width = int((mainform_width - interval * 4) / 12);
        F12Button->Width = int((mainform_width - interval * 4) / 12);

        F1Button->Left  = interval;
        F2Button->Left  = F1Button->Left + F1Button->Width - 1;
        F3Button->Left  = F2Button->Left + F2Button->Width - 1;
        F4Button->Left  = F3Button->Left + F3Button->Width - 1;
        F5Button->Left  = F4Button->Left + F4Button->Width - 1 + interval;
        F6Button->Left  = F5Button->Left + F5Button->Width - 1;
        F7Button->Left  = F6Button->Left + F6Button->Width - 1;
        F8Button->Left  = F7Button->Left + F7Button->Width - 1;
        F9Button->Left  = F8Button->Left + F8Button->Width - 1 + interval;
        F10Button->Left = F9Button->Left + F9Button->Width - 1;
        F11Button->Left = F10Button->Left + F10Button->Width - 1;
        F12Button->Left = F11Button->Left + F11Button->Width - 1;

        F1Panel->Left  = F1Button->Left + 3;
        F2Panel->Left  = F2Button->Left + 3;
        F3Panel->Left  = F3Button->Left + 3;
        F4Panel->Left  = F4Button->Left + 3;
        F5Panel->Left  = F5Button->Left + 3;
        F6Panel->Left  = F6Button->Left + 3;
        F7Panel->Left  = F7Button->Left + 3;
        F8Panel->Left  = F8Button->Left + 3;
        F9Panel->Left  = F9Button->Left + 3;
        F10Panel->Left = F10Button->Left + 3;
        F11Panel->Left = F11Button->Left + 3;
        F12Panel->Left = F12Button->Left + 3;

        F1Panel->Width  = F1Button->Width - 5;
        F2Panel->Width  = F2Button->Width - 5;
        F3Panel->Width  = F3Button->Width - 5;
        F4Panel->Width  = F4Button->Width - 5;
        F5Panel->Width  = F5Button->Width - 5;
        F6Panel->Width  = F6Button->Width - 5;
        F7Panel->Width  = F7Button->Width - 5;
        F8Panel->Width  = F8Button->Width - 5;
        F9Panel->Width  = F9Button->Width - 5;
        F10Panel->Width = F10Button->Width - 5;
        F11Panel->Width = F11Button->Width - 5;
        F12Panel->Width = F12Button->Width - 5;

        TairyuGrid->RowCount = int(TairyuGrid->Height / 63);

        // ���̃t�H�[���̃T�C�Y�����C���t�H�[���ɍ��킹��
        SearchForm->Height   = MainForm->Height;
        DataListForm->Height = MainForm->Height - 33;
        DataListForm->Width  = mainform_width   - 24;
        DataListForm->Top    = MainForm->Top    + 16;
        DataListForm->Left   = MainForm->Left   + 12;
    }
}
//---------------------------------------------------------------------------
// �Ԕԃ{�^��->OnClick
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

            if (ToCurrency(SET_TOP(set)["��ԏd��"]) > 0){
                keiryo_count_ = 1;
            }else{
                keiryo_count_ = 2;
            }
            gross_limit_ = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
            net_limit_   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
        }else{
            SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
        }

        TokuCodeEdit->SetFocus();
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

        ContinueWeighing(keiryo_id);
    }
}
//---------------------------------------------------------------------------
// �Ԕ�->OnChange
void __fastcall TMainForm::ShabanEditChange(TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql = "SELECT * FROM M_�ԗ� WHERE �Ԕ� = " + IntToStr(ShabanEdit->Text.ToIntDef(0)) + " AND �g�p�敪 = 1";
    if (!DM->DBI.GetRecordSet(sql, set)){
        SharyoNameEdit->Text = AnsiString();
        return;
    }

    if (set.size() == 1)
        SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);
    else
        SharyoNameEdit->Text = "�����̎ԗ�������";
}
//---------------------------------------------------------------------------
// �Ԕ�->KeyDown
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
        else if (Komoku1CodeEdit->Text.IsEmpty() && Komoku1Panel->Visible)
            Komoku1CodeEdit->SetFocus();
        else if (Komoku2CodeEdit->Text.IsEmpty() && Komoku2Panel->Visible)
            Komoku2CodeEdit->SetFocus();
        else
            BikoEdit->SetFocus();

        ShabanEdit->OnExit = OnExit;
    }
}
//---------------------------------------------------------------------------
// �Ԕ�->OnExit
void __fastcall TMainForm::ShabanEditExit(TObject *Sender)
{
    SharyoCheck();
/*
    int car_no = ShabanEdit->Text.ToIntDef(0);
    if (car_no < 1){
        ShabanEdit->Text = AnsiString();
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

    DM->SetShabanQuery(GetMode() != imMod, GetPlaceID());

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

        keiryo_count_ = 2;

        //if (GetMode() == imFirst)
            //FirstWEdit->Text = cur_weight_;

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
        TDateTime  now(Now());
        AnsiString name = now.FormatString("mm/dd' �Ɏ����o�^'");

        fields << NsField("[�Ԕ�]",     car_no)
               << NsField("[�ԗ�����]", name)
               << NsField("[�X�V����]", now)
               << NsField("[�쐬����]", now);

        DM->DBI.Insert("M_�ԗ�", fields);

        car_id_ = DM->DBI.GetLastID();

        SharyoNameEdit->Text = name;

        keiryo_count_ = 2;

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

            if (ToCurrency(SET_TOP(set)["��ԏd��"]) > 0)
                keiryo_count_ = 1;
            else
                keiryo_count_ = 2;

            gross_limit_ = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
            net_limit_   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

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

        TNotifyEvent OnExit = ShabanEdit->OnExit;
        ShabanEdit->OnExit  = 0;
        ContinueWeighing(keiryo_id);
        ShabanEdit->OnExit  = OnExit;
    }
*/
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
    // ���ڊ֘A�}�X�^�̏���
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

        item_relate_hin_id_ = ToInt(SET_TOP(set)["�i��ID"]);
    }
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

        id   = ToInt(SET_TOP(set)["����2ID"]);
        code = 0;
        if (id)
            code = ToInt(DM->DBI.Lookup("M_����2", "����2ID", id, "����2�R�[�h"));
        if (code)
            Komoku2CodeEdit->Text = code;

        item_relate_hin_id_ = ToInt(SET_TOP(set)["�i��ID"]);
    }
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

        item_relate_hin_id_ = ToInt(SET_TOP(set)["�i��ID"]);
    }
}
//---------------------------------------------------------------------------
// �����o�R���{->OnKeyDown
void __fastcall TMainForm::HannyuComboKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_ESCAPE || Key == VK_DELETE)
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
        StatusBar->SimpleText = "�d�ʒl��M: ��M�G���[";
        break;
    case eeConnect:
        StatusBar->SimpleText = "�d�ʒl��M: �ڑ��G���[";
        break;
    case eeDisconnect:
        StatusBar->SimpleText = "�d�ʒl��M: �ؒf�G���[";
        break;
    default:
        StatusBar->SimpleText = "�d�ʒl��M: �\�P�b�g�G���[";
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
    case 'S':   WeightPanel->Font->Color = TColor(0x00CDF7A4); break;
    case 'U':   WeightPanel->Font->Color = TColor(0x008080FF); break;
    case 'O':   WeightPanel->Font->Color = clYellow;
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
    int border = ToInt(DM->INI["Weighing::SoundBorder"]);

    if (old_weight_ < border && cur_weight_ >= border){
        // [INI] Weighing::SoundFile
        PlaySound(ToString(DM->INI["Weighing::SoundFile"]).c_str(), 0, SND_ASYNC);
    }

    WeightPanel->Caption = FormatFloat("###,##0", cur_weight_);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch (Key){
    case VK_DOWN:
        if (ActiveControl->Tag != 1 && ActiveControl->Tag != 999 && ActiveControl->Tag != 888
                && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_RETURN:
        if (ActiveControl->Tag != 999 && ActiveControl->Tag != 888 && ActiveControl != ShabanEdit){
            keybd_event(VK_TAB, 0, 0, 0);
        }
        break;
    case VK_UP:
        if (ActiveControl->Tag != 1 && ActiveControl->Tag != 888){
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_TAB, 0, 0, 0);
            keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Q_TairyuAfterOpen(TDataSet *DataSet)
{
    TairyuGrid->Visible = Q_Tairyu->RecordCount != 0;
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
    //CalcAmount();
}
//---------------------------------------------------------------------------
// �d�ʁA�������A�������v�Z����K�v������ꍇ
void __fastcall TMainForm::OnWeightRecalc(TObject *Sender)
{
    //CalcWeight();
}
//---------------------------------------------------------------------------
// ���ʂ���z�����v�Z����K�v������ꍇ
void __fastcall TMainForm::OnAmountRecalc(TObject *Sender)
{
    //CalcAmount();
}
//---------------------------------------------------------------------------
// ����ł��v�Z����K�v������ꍇ
void __fastcall TMainForm::OnSalesTaxRecalc(TObject *Sender)
{
    //CalcSalesTax();
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
          "     ���_ID = " + IntToStr(GetPlaceID());
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
/*
    if (Key != VK_RETURN)
        return;

    if (GetMode() != imFirst)
        return;

    Currency w2 = StrToCurrDef(SecondWEdit->Text, 0);
    if (w2 != 0)            // �V�K�ł�2��ڏd�ʂ����͍ςȂ炱���ł͓o�^���Ȃ�
        return;

    Action5->Execute();
*/
}
//---------------------------------------------------------------------------
// ���l->KeyDown
void __fastcall TMainForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Key = 0;

    if (GetMode() != imSecond){
        // 1��ڌv�ʂƏC�����[�h
        if (!SCGrid->Cells[0][detail_line].IsEmpty()){
            SCGrid->Options = SCGrid->Options << goEditing;
            SCGrid->Col = 1;
            SCGrid->Row = detail_line;
            SCGrid->SetFocus();
            return;
        }

        MeisaiAddButton->OnClick(NULL);
    }else{
        // �ؗ���
        int row = keiryo_set_.size() * detail_line;
        int meisai_max_no = keiryo_set_.size();

        // row��2�̏ꍇ
        // 1���זڂ�2��ڏd�ʂ�0��������A1���זڂ�2��ڏd�ʂɏd�ʒl������
        // 1���זڂ�2��ڏd�ʂ�1�ȏゾ������A���גǉ�����
        if (row == 2){
            Currency w_second = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", SCGrid->Row)], 0);
            if (w_second > 0){
                MeisaiAddButton->OnClick(NULL);
                return;
            }else{
                SCGrid->Options = SCGrid->Options << goEditing;
                SCGrid->SetFocus();
                SCGrid->Col     = GetColNo("2��ڏd��");
                SCGrid->Row     = row;
                SCGrid->Cells[GetColNo("2��ڏd��")][row] = cur_weight_;
            }
        }else if (ToInt(keiryo_set_[meisai_max_no - 1]["2��ڏd��"]) != 0){
            MeisaiAddButton->OnClick(NULL);
        }
    }
}
//---------------------------------------------------------------------------
// ���l->KeyPress
void __fastcall TMainForm::BikoEditKeyPress(TObject *Sender, char &Key)
{
    if (BikoEdit->Text.Length() >= 40){
        if (Key != VK_RETURN && Key != VK_BACK && Key != VK_DELETE)
            Key = 0;
    }
}
//---------------------------------------------------------------------------
// �g���[���v��->Click
void __fastcall TMainForm::TrailerWeightButtonClick(TObject *Sender)
{
/*
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
*/
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
          " AND �sNo = 1";
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
/*
    TDateTimePicker *DatePicker = dynamic_cast<TDateTimePicker *>(Sender);
    TDateTimePicker *TimePicker;

    TimePicker = DatePicker->Tag == 1 ? FirstTimePicker : SecondTimePicker;

    TimePicker->Enabled = DatePicker->Checked;

    if (DatePicker->Checked){
        DatePicker->Format    = "";
        TimePicker->Format    = "HH:mm";
    }else{
        DatePicker->Format    = "''";
        TimePicker->Format    = "''";
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KeiryoDatePickerChange(TObject *Sender)
{
    if (GetMode() != imMod)
       KeiryoNoEdit->Text = DM->GetKeiryoNo(GetPlaceID(), DateToInt(KeiryoDatePicker->Date));
}
//---------------------------------------------------------------------------
// ���גǉ��{�^��
void __fastcall TMainForm::MeisaiAddButtonClick(TObject *Sender)
{
    int line_no = row_lineno_map_[SCGrid->Row];

    if (GetMode() == imMod && line_no != 0) // �C�����[�h�̏ꍇ�͍s�}��������̂ŕʏ���
        Line_Insert(line_no);
    else
        Line_Add();
}
//---------------------------------------------------------------------------
// ���׍폜�{�^��
void __fastcall TMainForm::MeisaiDeleteButtonClick(TObject *Sender)
{
    int row     = SCGrid->Row;
    int line_no = row_lineno_map_[row];
    if (row_lineno_map_[row] == 0)
        return;

    // �s��1�s�̏ꍇ�͓`�[�폜�̏����ɂ���
    int meisai_count = 0;
    for (int i = detail_line; i < SCGrid->RowCount; i += detail_line){
        if (row_id_map_[i] != 0)
            meisai_count++;
    }

    if (meisai_count == 1){
        Action3->OnExecute(NULL);
        return;
    }

    // �����s����ꍇ�̏���
    if (Application->MessageBox(("�sNo" + IntToStr(line_no) + " ���폜���Ă���낵���ł����H").c_str(),
            this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    // �s�폜
    // SCGrid��̒l���ړ�
    int calc_row  = line_no * detail_line;
    int row_count = SCGrid->RowCount;
    for (int i = calc_row; i < row_count; i++){
        SCGrid->Rows[i] = SCGrid->Rows[i + detail_line];
        SCGrid->Rows[i + detail_line]->Clear();
        row_id_map_[i]  = row_id_map_[i + detail_line];
        row_id_map_[i + detail_line]  = 0;
    }

    int old_id = row_id_map_[detail_line];
    line_no = 1;
    row_lineno_map_.clear();
    for (int i = detail_line; i < SCGrid->RowCount; i++){
        if (row_id_map_[i] == 0)
            continue;

        if (old_id != row_id_map_[i])
            line_no++;

        if (i % detail_line == 0)
            SCGrid->Cells[0][i] = line_no;

        row_lineno_map_[i] = line_no;
        old_id = row_id_map_[i];
    }

    if (GetMode() != imFirst)
        delete_flag_ = true;

    SCGrid->SetFocus();
/*
    int keiryo_id    = row_id_map_[row];
    int net          = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id, "�����d��"));
    Currency slip_no = ToCurrency(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id, "�`�[No"));
    int date         = ToInt(DM->DBI.Lookup("D_�v��", "�v��ID", keiryo_id, "�v�ʓ�"));

    DM->ADOConnection->BeginTrans();
    try{
        NsFieldSet keys;
        keys << NsField("�v��ID", keiryo_id);
        DM->DBI.Delete("D_�v��",  keys);
    }catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
        Application->MessageBox(("�f�[�^�̍폜�Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(),
                MB_OK | MB_ICONWARNING);
        return;
    }
    DM->ADOConnection->CommitTrans();

    AnsiString sql;
    sql = " SELECT * FROM V_�v��"
          " WHERE"
          "     �v�ʓ� = " + IntToStr(date) +
          " AND"
          "     �`�[No = " + CurrToStr(slip_no) +
          " AND"
          "     �����敪 <> 9" // �_���폜�͑ΏۊO
          " ORDER BY"
          "     �sNo";

    keiryo_set_.clear();
    if (!DM->DBI.GetRecordSet(sql, keiryo_set_)){
        Action1->Execute();
        return;
    }

    // �����s�̊Ԃ̍sNo���폜�����ꍇ�A�폜�������̐����͍Čv�Z����H���Ȃ��H

    LoadFromID(ToInt(SET_TOP(keiryo_set_)["�v��ID"]));
*/
}
//---------------------------------------------------------------------------
// �Čv�Z�{�^��
//
// �����̏ꍇ�́A�ŏI�I�ɍsNo1��1��ڏd�ʂ𑝌����Ē�������
// ���o�̏ꍇ�́A�ŏI�I�ɍŏI�s��2��ڏd�ʂ𑝌����Ē�������
void __fastcall TMainForm::RecalcButtonClick(TObject *Sender)
{
    if (SCGrid->Cells[GetColNo("�i�ڃR�[�h")][detail_line].ToIntDef(0) == 0)
        return;

    if (Application->MessageBox("�Čv�Z���s���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    Currency w1, w2, net, adjust, reduc;
    int io_div = HannyuCombo->ItemIndex + 1;

    if (io_div == 1){
        // ����
        // �ŏI�s���猩�Ă���
        int max_line_no       = GetMaxLineNo();
        Currency first_weight = 0;

        for (int i = max_line_no; i >= 1; i--){
            w1     = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))], 0);
            w2     = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))], 0);
            net    = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);
            adjust = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);
            reduc  = StrToCurrDef(SCGrid->Cells[GetColNo("�d�ʈ���")][CalcRowNo("�d�ʈ���", (i * detail_line))], 0);

            if (w1 == 0 && w2 == 0) // �Ώۃf�[�^���`�F�b�N
                continue;

            if (first_weight != 0){
                w2 = first_weight;
                SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))] = first_weight;
            }

            if (w1 - w2 - adjust - reduc != net){
                first_weight = w2 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))] = first_weight;
            }else{
                first_weight = w1;
            }
        }
    }else if (io_div == 2){
        // ���o
        // �ŏ��̍s���猩�Ă���
        int first_line_no      = 1;
        Currency second_weight = 0;

        for (int i = first_line_no; i <= GetMaxLineNo(); i++){
            w1     = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))], 0);
            w2     = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))], 0);
            net    = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);
            adjust = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);
            reduc  = StrToCurrDef(SCGrid->Cells[GetColNo("�d�ʈ���")][CalcRowNo("�d�ʈ���", (i * detail_line))], 0);

            if (w1 == 0 && w2 == 0) // �Ώۃf�[�^���`�F�b�N
                continue;

            if (second_weight != 0){
                w1 = second_weight;
                SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))] = second_weight;
            }

            if (w2 - w1 - adjust - reduc != net){
                second_weight = w1 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))] = second_weight;
            }else{
                second_weight = w2;
            }
        }
    }

    SCGrid->SetFocus();
    Application->MessageBox("�Čv�Z���������܂���", this->Caption.c_str(), MB_OK | MB_ICONQUESTION);
}
//---------------------------------------------------------------------------
// �m�F���b�Z�[�W�Ȃ��ōČv�Z����
void __fastcall TMainForm::Recalc_NoMsg()
{
    Currency w1, w2, net, adjust, reduc;
    int io_div = HannyuCombo->ItemIndex + 1;

    if (io_div == 1){
        // ����
        // �ŏI�s���猩�Ă���
        int max_line_no       = GetMaxLineNo();
        Currency first_weight = 0;

        for (int i = max_line_no; i >= 1; i--){
            w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))], 0);
            w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))], 0);
            net = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);

            if (ToBit(DM->CFG["�����g�p�敪"]))
                adjust = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);
            else
                adjust = 0;

            if (ToBit(DM->CFG["�d�ʈ����g�p�敪"]))
                reduc = StrToCurrDef(SCGrid->Cells[GetColNo("�d�ʈ���")][CalcRowNo("�d�ʈ���", (i * detail_line))], 0);
            else
                reduc = 0;

            if (w1 == 0 && w2 == 0) // �Ώۃf�[�^���`�F�b�N
                continue;

            if (first_weight != 0){
                w2 = first_weight;
                SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))] = first_weight;
            }

            if (w1 - w2 - adjust - reduc != net){
                first_weight = w2 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))] = first_weight;
            }else{
                first_weight = w1;
            }
        }
    }else if (io_div == 2){
        // ���o
        // �ŏ��̍s���猩�Ă���
        int first_line_no      = 1;
        Currency second_weight = 0;

        for (int i = first_line_no; i <= GetMaxLineNo(); i++){
            w1  = StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))], 0);
            w2  = StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))], 0);
            net = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);

            if (ToBit(DM->CFG["�����g�p�敪"]))
                adjust = StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", (i * detail_line))], 0);
            else
                adjust = 0;

            if (ToBit(DM->CFG["�d�ʈ����g�p�敪"]))
                reduc = StrToCurrDef(SCGrid->Cells[GetColNo("�d�ʈ���")][CalcRowNo("�d�ʈ���", (i * detail_line))], 0);
            else
                reduc = 0;

            if (w1 == 0 && w2 == 0) // �Ώۃf�[�^���`�F�b�N
                continue;

            if (second_weight != 0){
                w1 = second_weight;
                SCGrid->Cells[GetColNo("1��ڏd��")][CalcRowNo("1��ڏd��", (i * detail_line))] = second_weight;
            }

            if (w2 - w1 - adjust - reduc != net){
                second_weight = w1 + adjust + reduc + net;
                SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", (i * detail_line))] = second_weight;
            }else{
                second_weight = w2;
            }
        }
    }

    SCGrid->SetFocus();
}
//---------------------------------------------------------------------------
// SCGrid->OnClick
void __fastcall TMainForm::SCGridClick(TObject *Sender)
{
/*  ///// ���͋K���L�� /////
    if (row_lineno_map_[SCGrid->Row] > GetMaxLineNo() || row_lineno_map_[SCGrid->Row] == 0){
        SCGrid->Options    = SCGrid->Options >> goEditing;
        SCGrid->EditorMode = false;
    }else if (GetMode() == imSecond && row_lineno_map_[SCGrid->Row] != GetMaxLineNo()){
        SCGrid->Options    = SCGrid->Options >> goEditing;
        SCGrid->EditorMode = false;
    }else{
        SCGrid->Options    = SCGrid->Options << goEditing;
        SCGrid->EditorMode = true;

        // �S�͈͑I��
		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
		ie->SelStart     = 0;
        ie->SelectAll();
    }
*/
    if (SCGrid->EditorMode && GetCellName(SCGrid->Col, SCGrid->Row) == "�i�ڃ}�X�^����"){
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT �i�ڃR�[�h, �i�ږ��� FROM M_�i�� WHERE �g�p�敪 = 1";
        SearchForm->orderby_sql = " ORDER BY �i�ڃR�[�h ";
        SearchForm->table_name  = "M_�i��";

        if (SearchForm->ShowModal() != mrOk){
            SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("�i�ڃR�[�h")][SCGrid->Row]     = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
        SCGrid->Cells[GetColNo("�i�ڃ}�X�^����")][SCGrid->Row] = SearchForm->Query->FieldByName("�i�ږ���")->AsString;
        SCGrid->Col = SCGrid->Col - 1;
    }else if (SCGrid->EditorMode && GetCellName(SCGrid->Col, SCGrid->Row) == "�P�ʃ}�X�^����"){
        SearchForm->Top         = MainForm->Top;
        SearchForm->Left        = MainForm->Left + (MainForm->Width - SearchForm->Width);
        SearchForm->based_sql   = " SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P��";
        SearchForm->orderby_sql = " ORDER BY �P�ʃR�[�h ";
        SearchForm->table_name  = "M_�P��";

        if (SearchForm->ShowModal() != mrOk){
            SCGrid->Col = SCGrid->Col - 1;
            return;
        }

        SCGrid->Cells[GetColNo("�P�ʃR�[�h")][SCGrid->Row]     = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
        SCGrid->Cells[GetColNo("�P�ʃ}�X�^����")][SCGrid->Row] = SearchForm->Query->FieldByName("�P�ʖ���")->AsString;
        SCGrid->Col = SCGrid->Col - 1;
    }

    ///// ���͋K������ /////
    SCGrid->Options    = SCGrid->Options << goEditing;
    SCGrid->EditorMode = true;

    // �S�͈͑I��
    TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
    ie->SelStart     = 0;
    ie->SelectAll();
}
//---------------------------------------------------------------------------
// SCGrid->OnColChanged
void __fastcall TMainForm::SCGridCellChanged(TObject *Sender, int AOldCol,
      int AOldRow, int ANewCol, int ANewRow)
{
    AnsiString old_item_name = GetCellName(AOldCol, AOldRow);

    if (old_item_name == "�i�ڃR�[�h" || old_item_name == "1��ڏd��" || old_item_name == "2��ڏd��" || old_item_name == "������"
            || old_item_name == "�����d��" || old_item_name == "�d�ʈ���"){

        // �i�ڃR�[�hor�}�X�^���̂Œ��������g�p����ꍇ�͕i�ڃ}�X�^�̏d�ʒ����������ɍs��
        if ((old_item_name == "�i�ڃR�[�h" || old_item_name == "�i�ڃ}�X�^����") && ToBit(DM->CFG["�����g�p�敪"])){
            int hin_code = SCGrid->Cells[AOldCol][AOldRow].ToIntDef(0);
            Currency coord_rate = ToCurrency(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hin_code, "�d�ʒ�����"));
            SCGrid->Cells[GetColNo("������")][AOldRow] = FormatFloat("#", coord_rate);
        }

        CalcWeight(AOldRow);
    }

    if (ToBit(DM->CFG["�P���g�p�敪"]) && (old_item_name == "�����d��" || old_item_name == "�P�ʃR�[�h"))
        CalcAmount(AOldRow);

    if (ToBit(DM->CFG["�P���g�p�敪"]) && (old_item_name == "����" || old_item_name == "�P��" || old_item_name == "���z"))
        CalcSalesTax(AOldRow);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridDblClick(TObject *Sender)
{
    // �_�u���N���b�N�ŕҏW�ɂȂ�̂�h�~
}
//---------------------------------------------------------------------------
// Cell�̒l���ҏW���ꂽ���̃C�x���g
void __fastcall TMainForm::SCGridSetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
    if (GetCellName(ACol, ARow) == "�i�ڃR�[�h"){
        SCGrid->Cells[GetColNo("�i�ڃ}�X�^����")][ARow] = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", SCGrid->Cells[ACol][ARow].ToIntDef(0), "�i�ږ���"));

        if (GetMode() == imFirst && row_lineno_map_[ARow] == 1)
            // 1��ڌv�ʂ�1�s�ڂ�����������敪��ύX����
            HannyuCombo->ItemIndex = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", SCGrid->Cells[ACol][ARow].ToIntDef(0), "�����o�敪")) - 1;
        else if (GetMode() != imFirst && row_lineno_map_[ARow] == 1 && HannyuCombo->ItemIndex == -1)
            // �V�K�ȊO�Ŕ����o���I������Ă��Ȃ��ꍇ�A1�s�ڂ̕i�ڃ}�X�^�̔����o�敪�𔽉f����
            HannyuCombo->ItemIndex = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", SCGrid->Cells[ACol][ARow].ToIntDef(0), "�����o�敪")) - 1;

        // �i�ڃR�[�h��0����Ȃ��āA�sNo�����������ꍇ�sNo�����
        if (SCGrid->Cells[ACol][ARow].ToIntDef(0) != 0 && SCGrid->Cells[GetColNo("�sNo")][CalcRowNo("�sNo", ARow)].ToIntDef(0) == 0)
            Line_Add();

    }else if (GetCellName(ACol, ARow) == "�P�ʃR�[�h"){
        SCGrid->Cells[GetColNo("�P�ʃ}�X�^����")][ARow] = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", SCGrid->Cells[ACol][ARow].ToIntDef(0), "�P�ʖ���"));
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_RETURN){
        SCGrid->EditorMode = false;
/*
        ���ׂɕ��ׂ鍀��
        -- 1�s�� --
        1,�sNo
        2,�i�ڃR�[�h
        3,�i�ږ���
        4,1��ڏd��
        5,2��ڏd��
        6,������
        7,�����d��
        8,�d�ʈ���
        9,�����d��

        -- 2�s�� --
        10,���ה��l
        11,����
        12,�P�ʃR�[�h
        13,�P�ʖ���
        14,�P��
        15,���z
        16,����Ŋz
*/
        if (SCGrid->Col == line_colcount_map_[GetLineNo(SCGrid->Row, detail_line)] && detail_line == 1){
            ///// 1�s�\���̍Ō��Col
            if (SCGrid->Cells[0][SCGrid->Row + 1].IsEmpty() && !PostMessageCheck->Checked){
                // ���̍sNo���\������ĂȂ��ēo�^���b�Z�[�W���肾������o�^������
                Action5->OnExecute(NULL);
            }else if (SCGrid->Row == max_row){
                // �ő�s�̏ꍇ�͓o�^����
                Action5->OnExecute(NULL);
            }else{
                // ���̍s�ֈړ�
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 1;
            }
        }else if (SCGrid->Col == line_colcount_map_[GetLineNo(SCGrid->Row, detail_line)] && detail_line == 2){
            ///// 2�s�\���̍Ō��Col
            if (SCGrid->Row % 2 != 0 && SCGrid->Cells[0][SCGrid->Row + 1].IsEmpty() && !PostMessageCheck->Checked){
                // 2�s�ڂŎ��̍sNo���\������ĂȂ��ēo�^���b�Z�[�W���肾������o�^������
                Action5->OnExecute(NULL);
            }else if (SCGrid->Row == max_row - 1){
                // �ő�s�̏ꍇ�͓o�^����
                Action5->OnExecute(NULL);
            }else if (SCGrid->Row % 2 == 0){
                // 1�s�ڂ���2�s�ڂɈړ�
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 2;
            }else{
                // ���̍s�ֈړ�
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 1;
            }
        }else if (GetCellName(SCGrid->Col, SCGrid->Row) == "�i�ڃR�[�h" || GetCellName(SCGrid->Col, SCGrid->Row) == "�P�ʃR�[�h"
                || GetCellName(SCGrid->Col, SCGrid->Row) == "������"){
            SCGrid->Col = SCGrid->Col + 2;
        }else if (GetCellName(SCGrid->Col, SCGrid->Row) == "1��ڏd��" && GetMode() == imFirst){
            ///// �V�K��1��ڏd�ʂ̃C�x���g
            if (SCGrid->Cells[GetColNo("2��ڏd��")][CalcRowNo("2��ڏd��", SCGrid->Row)].ToIntDef(0) == 0){
                if (!PostMessageCheck->Checked)
                    Action5->OnExecute(NULL);
                else
                    SCGrid->Col = SCGrid->Col + 1;
            }else{
                SCGrid->Col = SCGrid->Col + 1;
            }
        }else if (SCGrid->Col == line_end_col){
            if (detail_line == 1)
                Action5->OnExecute(NULL);

            if ((SCGrid->Row + 1) % detail_line == 0)
                Action5->OnExecute(NULL);

        }else if (SCGrid->Col < SCGrid->ColCount - 1){
            SCGrid->Col = SCGrid->Col + 1;
        }

        // �ړ�������̃Z����������������A���s�ֈړ�����
        if (GetCellName(SCGrid->Col, SCGrid->Row) == ""){
            if (detail_line == 1){
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 1;
            }else if (detail_line == 2){
                SCGrid->Row = SCGrid->Row + 1;
                SCGrid->Col = 2;
            }
        }

        // �S�͈͑I��
		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
		ie->SelStart = 0;
    }else if (Key == VK_LEFT){
        AnsiString name = GetCellName(SCGrid->Col - 1, SCGrid->Row);
        if (name == "�i�ڃ}�X�^����" || name == "�P�ʃ}�X�^����" || name == "�����d��"){
            TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
            if (ie->SelStart == 0 && ie->SelLength == 0){
                Key = 0;
                SCGrid->Col = SCGrid->Col - 2;
            }
        }
    }else if (Key == VK_RIGHT){
        AnsiString name = GetCellName(SCGrid->Col + 1, SCGrid->Row);
        if (name == "�i�ڃ}�X�^����" || name == "�P�ʃ}�X�^����" || name == "�����d��"){
    		TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
            if ((ie->SelStart == ie->Text.Length() && ie->SelLength == 0) || (ie->Text.Length() == ie->SelLength)){
                Key = 0;
                SCGrid->Col = SCGrid->Col + 2;
            }
        }
    }else if (Key == VK_UP){
        AnsiString name = GetCellName(SCGrid->Col, SCGrid->Row - 1);
        if (name == "�i�ڃ}�X�^����" || name == "�P�ʃ}�X�^����" || name == "�����d��"){
            Key = 0;
            if (SCGrid->Row - 2 > detail_line - 1)
                SCGrid->Row = SCGrid->Row - 2;
        }
    }else if (Key == VK_DOWN){
        AnsiString name = GetCellName(SCGrid->Col, SCGrid->Row + 1);
        if (name == "�i�ڃ}�X�^����" || name == "�P�ʃ}�X�^����" || name == "�����d��"){
            Key = 0;
            if (SCGrid->Row + 2 < max_row)
                SCGrid->Row = SCGrid->Row + 2;
        }
    }

    if (!SCGrid->EditorMode)
        SCGrid->EditorMode = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridKeyPress(TObject *Sender, char &Key)
{
    int col = SCGrid->Col;
    int row = SCGrid->Row;
    AnsiString name = GetCellName(col, row);
    if (name == "���ה��l"){
        if (SCGrid->Cells[SCGrid->Col][SCGrid->Row].Length() >= 20 && (Key != VK_RETURN && Key != VK_BACK && Key != VK_DELETE))
            Key = 0;
    }else if (name == "1��ڏd��" || name == "2��ڏd��" || name == "�����d��"){
        if (ToInt(DM->CFG["�d�ʕҏW�敪"]) == 0)
            Key = 0;
    }else if (name == "�����d��" || name == ""){
        if (Key != VK_RETURN && Key != VK_UP && Key != VK_DOWN && Key != VK_LEFT && Key != VK_RIGHT)
            Key = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    // �����ΏۊO�̍��ڂɃt�H�[�J�X������ꍇ�͂�����return����
    if (GetMode() == imFirst && (row_lineno_map_[SCGrid->Row] != 1)){
        return;
    }else if (GetMode() == imSecond && row_lineno_map_[SCGrid->Row] > GetMaxLineNo()){
        return;
    }else if (col_row_map_.empty()){
        return;
    }

    AnsiString item_name = GetCellName(ACol, ARow);

    // IME���[�h�ؑ�
    if (item_name == "���ה��l")
        SetImeMode(SCGrid->Handle, imHira);
    else
        SetImeMode(SCGrid->Handle, imClose);

    // �d�ʊ֌W�̏���
    int empty_weight = 0;
    if (car_id_ != 0)
         empty_weight = ToInt(DM->DBI.Lookup("M_�ԗ�", "�ԗ�ID", car_id_, "��ԏd��"));

    if (item_name == "1��ڏd��" && GetMode() == imFirst && empty_weight != 0){
        SCGrid->Cells[ACol][ARow]                  = cur_weight_;
        SCGrid->Cells[GetColNo("2��ڏd��")][ARow] = empty_weight;
    }else if (item_name == "1��ڏd��" && GetMode() == imFirst){
        SCGrid->Cells[ACol][ARow] = cur_weight_;
    //}else if (item_name == "1��ڏd��" && GetMode() != imFirst && GetMaxLineNo() == row_lineno_map_[SCGrid->Row] && GetMaxLineNo() != 1){
    }else if (item_name == "1��ڏd��" && GetMode() != imFirst && GetMaxLineNo() == row_lineno_map_[ARow] && GetMaxLineNo() != 1){
        SCGrid->Cells[ACol][ARow] = SCGrid->Cells[GetColNo("2��ڏd��")][ARow - detail_line];
    }else if (item_name == "2��ڏd��" && GetMode() == imSecond && GetMaxLineNo() == row_lineno_map_[ARow]){
        if (SCGrid->Cells[GetColNo("1��ڏd��")][ARow].IsEmpty())
            SCGrid->Cells[GetColNo("1��ڏd��")][ARow] = SCGrid->Cells[GetColNo("2��ڏd��")][ARow - detail_line];

        SCGrid->Cells[ACol][ARow] = cur_weight_;
    }else if (item_name == "2��ڏd��" && GetMode() == imMod){ // ���̏����͉��������H
        //SCGrid->Cells[ACol][ARow] = 0;
    }

    if (item_name == "����")
        SCGrid->Cells[ACol][ARow] = GetSuryoCellValue(SCGrid->Cells[ACol][ARow]);

    if (item_name == "�i�ڃR�[�h" && SCGrid->Cells[ACol][ARow].ToIntDef(0) == 0 && GetMode() != imMod){
        SCGrid->Cells[ACol][ARow] = FormatFloat("#,##0;#,##0;#", ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", item_relate_hin_id_, "�i�ڃR�[�h")));
        SCGrid->Cells[GetColNo("�i�ڃ}�X�^����")][CalcRowNo("�i�ڃ}�X�^����", ARow)] = ToString(DM->DBI.Lookup("M_�i��", "�i��ID", item_relate_hin_id_, "�i�ږ���"));
    }

    if (item_name == "������"){
        // �V�K�������͑ؗ��ԃ��[�h�Œ�������0��������i�ڃ}�X�^�̏d�ʒ�����������
        Currency value = StrToCurrDef(SCGrid->Cells[ACol][ARow], 0);
        if (GetMode() == imFirst || (GetMode() == imSecond && value == 0)){
            int hinmoku_code     = SCGrid->Cells[GetColNo("�i�ڃR�[�h")][CalcRowNo("�i�ڃR�[�h", ARow)].ToIntDef(0);
            Currency adjust_rate = ToCurrency(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", hinmoku_code, "�d�ʒ�����"));

            if (adjust_rate != 0)
                SCGrid->Cells[ACol][ARow] = adjust_rate;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SCGridDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if (ACol < SCGrid->FixedCols || ARow < SCGrid->FixedRows)
        SCGrid->Canvas->Brush->Color = SCGrid->FixedColor;
    else if (detail_line == 2 && ARow % 4 < 2)
        SCGrid->Canvas->Brush->Color = clWhite;
    else if (detail_line == 1 && ARow % 2 == 0)
        SCGrid->Canvas->Brush->Color = clWhite;
    else
        SCGrid->Canvas->Brush->Color = clCream;

    SCGrid->Canvas->FillRect(Rect); // �`��

    // �r���`��
    if (detail_line == 1){
        if (ACol >= SCGrid->FixedCols && ARow >= SCGrid->FixedRows){
            SCGrid->Canvas->Pen->Color = clSilver;
            SCGrid->Canvas->Pen->Width = 2;
            SCGrid->Canvas->MoveTo(Rect.Left,  Rect.Bottom);
            SCGrid->Canvas->LineTo(Rect.Right, Rect.Bottom);
            SCGrid->Canvas->Pen->Width = 1;
        }
    }else if (detail_line == 2){
        if (ARow % 2 == 1 && ACol >= SCGrid->FixedCols && ARow >= SCGrid->FixedRows){
            SCGrid->Canvas->Pen->Color = clSilver;
            SCGrid->Canvas->Pen->Width = 2;
            SCGrid->Canvas->MoveTo(Rect.Left,  Rect.Bottom);
            SCGrid->Canvas->LineTo(Rect.Right, Rect.Bottom);
            SCGrid->Canvas->Pen->Width = 1;
        }else if (ACol >= SCGrid->FixedCols && ARow >= SCGrid->FixedRows){
            SCGrid->Canvas->Pen->Color = clSilver;
            SCGrid->Canvas->Pen->Style = psDot;
            SCGrid->Canvas->MoveTo(Rect.Left,  Rect.Bottom);
            SCGrid->Canvas->LineTo(Rect.Right, Rect.Bottom);
        }
    }

/*  // �W���̖��ߒׂ��J�[�\���ł͂Ȃ��đ��g�J�[�\���ɕύX
    if(State.Contains(gdSelected)){
        Grid->Canvas->Brush->Style = bsClear;
        Grid->Canvas->Pen->Width = 2;
        Grid->Canvas->Pen->Color = clBlack;
        Grid->Canvas->Rectangle(R.left+1,R.top+1,R.right,R.bottom);
    }
*/
    // �i�ڃ}�X�^���̂ƒP�ʃ}�X�^���͍̂���
    // ����ȊO�͉E��
    if (ACol < SCGrid->FixedCols || ARow < SCGrid->FixedRows){ // �Œ荀��

        //���̘g�̕`��
        //if(State.Contains(gdFixed))
            //DrawEdge(SCGrid->Canvas->Handle, &Rect, BDR_SUNKEN, BF_TOP);

        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[ACol][ARow].c_str(), SCGrid->Cells[ACol][ARow].Length(), &Rect, DT_CENTER | DT_SINGLELINE); //������
    }else if (GetCellName(ACol, ARow) ==  "�i�ڃ}�X�^����" || GetCellName(ACol, ARow) == "�P�ʃ}�X�^����" || GetCellName(ACol, ARow) == "���ה��l"){
        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[ACol][ARow].c_str(), SCGrid->Cells[ACol][ARow].Length(), &Rect, DT_LEFT | DT_SINGLELINE);   //����
    }else{
        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[ACol][ARow].c_str(), SCGrid->Cells[ACol][ARow].Length(), &Rect, DT_RIGHT | DT_SINGLELINE);  //�E��
    }

    // �I������Ă���Z���̔w�i�F�ύX
    if (!SCGrid->ComponentCount)
        return;

    TInplaceEdit *ie = dynamic_cast<TInplaceEdit *>(SCGrid->Components[0]);
    if (ie != NULL){
        TBrush *br = ie->Brush;
        br->Color  = TColor(0x00E4DDFF);
        br->Style  = bsSolid;
    }
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::GetHeaderID(int keiryo_id)
{
    NsRecordSet set;
    AnsiString  sql;
    int date, place, slip_no;

    if (!DM->DBI.GetRecordSet("SELECT * FROM D_�v�� WHERE �v��ID = " + IntToStr(keiryo_id), set))
        return 0;

    date    = ToInt(SET_TOP(set)["�v�ʓ�"]);
    place   = ToInt(SET_TOP(set)["���_ID"]);
    slip_no = ToInt(SET_TOP(set)["�`�[No"]);

    sql = " SELECT"
          "     *"
          " FROM"
          "     D_�v��"
          " WHERE"
          "     �v�ʓ� = " + IntToStr(date) +
          " AND"
          "     ���_ID = " + IntToStr(place) +
          " AND"
          "     �`�[No = " + IntToStr(slip_no) +
          " AND"
          "     �sNo = 1"
          " AND"
          "     �����敪 <> 9";
    if (!DM->DBI.GetRecordSet(sql, set))
        return 0;

    return ToInt(SET_TOP(set)["�v��ID"]);
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::GetTotalWeight()
{
    int max_no, total_weight;
    max_no = GetMaxLineNo();
    total_weight = 0;
    for (int i = 1; i <= max_no; i++)
        total_weight += SCGrid->Cells[GetColNo("�����d��")][CalcRowNo("�����d��", i * detail_line)].ToIntDef(0);

    return total_weight;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetTotalMoney()
{
    if (!ToBit(DM->CFG["�P���g�p�敪"]))
        return;

    int max_no, sum_money, sum_tax;
    max_no    = GetMaxLineNo();
    sum_money = 0;
    sum_tax = 0;
    for (int i = 1; i <= max_no; i++){
        sum_money += SCGrid->Cells[GetColNo("���z")][CalcRowNo("���z", i * detail_line)].ToIntDef(0);
        sum_tax   += SCGrid->Cells[GetColNo("����Ŋz")][CalcRowNo("����Ŋz", i * detail_line)].ToIntDef(0);
    }

	if (ToString(DM->CFG["���i������Ōv�Z�敪"]).ToIntDef(1) == 1){
		Currency tax_rate = DM->GetSalesTax(DateToInt(KeiryoDatePicker->Date)); // ����ŗ��擾
		///// ����Œ[�������敪�̎擾
		int tax_div = -1;
		if (!toku_rec_.empty()){
			if (!IsNull(toku_rec_["����Œ[�������敪"]))
				tax_div = ToInt(toku_rec_["����Œ[�������敪"]);
		}

		if (tax_div == -1)
			tax_div = ToInt(DM->CFG["����Œ[�������敪"]);

		///// �`�[����ł̌v�Z
		sum_tax   = ExtendedRound(Currency(sum_money) * tax_rate, 0, tax_div);
	}

    slip_tax_ = sum_tax;

    MoneyLabel->Caption = FormatFloat("\\ #,##0", sum_money);
    TaxLabel->Caption   = FormatFloat("\\ #,##0", sum_tax);
    TotalMoneyLabel->Caption = FormatFloat("\\ #,##0", sum_money + sum_tax);
}
//---------------------------------------------------------------------------
//      ���׃O���b�h�֌W
//---------------------------------------------------------------------------
// ���׃^�C�g���ݒ�
void __fastcall TMainForm::SetGridTitle()
{
/*
        ���ׂɕ��ׂ鍀��
        -- 1�s�� --
        1,�sNo
        2,�i�ڃR�[�h
        3,�i�ږ���
        4,1��ڏd��
        5,2��ڏd��
        6,������
        7,�����d��
        8,�d�ʈ���
        9,�����d��

        -- 2�s�� --
        10,���ה��l
        11,�P�ʃR�[�h
        12,�P�ʖ���
        13,����
        14,�P��
        15,���z
        16,����Ŋz
*/
    line_colcount_map_.clear();

    ///// �sNo
    col_row_map_.clear();
    col_row_map_[0]               = 1;
    name_coord_map_["�sNo"]       = col_row_map_;
    coord_name_map_[col_row_map_] = "�sNo";
    col_width_map_["�sNo"]        = 32;

    ///// �i�ڃR�[�h
    col_row_map_.clear();
    col_row_map_[1]               = 1;
    name_coord_map_["�i�ڃR�[�h"] = col_row_map_;
    coord_name_map_[col_row_map_] = "�i�ڃR�[�h";;
    col_width_map_["�i�ڃR�[�h"]  = 50;

    ///// �i�ږ���
    col_row_map_.clear();
    col_row_map_[2]                   = 1;
    name_coord_map_["�i�ڃ}�X�^����"] = col_row_map_;
    coord_name_map_[col_row_map_]     = "�i�ڃ}�X�^����";
    col_width_map_["�i�ڃ}�X�^����"]  = 330;

    ///// 1��ڏd��
    col_row_map_.clear();
    col_row_map_[3]               = 1;
    name_coord_map_["1��ڏd��"]  = col_row_map_;
    coord_name_map_[col_row_map_] = "1��ڏd��";
    col_width_map_["1��ڏd��"]   = 90;

    ///// 2��ڏd��
    col_row_map_.clear();
    col_row_map_[4]               = 1;
    name_coord_map_["2��ڏd��"]  = col_row_map_;
    coord_name_map_[col_row_map_] = "2��ڏd��";
    col_width_map_["2��ڏd��"]   = 90;

    int col_no = 4;
    int row_no = 1; // ���s�ڂ�

    ///// ������, �����d��
    if (ToBit(DM->CFG["�����g�p�敪"])){
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["������"]     = col_row_map_;
        coord_name_map_[col_row_map_] = "������";
        col_width_map_["������"]      = 90;

        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["�����d��"]   = col_row_map_;
        coord_name_map_[col_row_map_] = "�����d��";
        col_width_map_["�����d��"]    = 90;
    }

    ///// �d�ʈ���
    if (ToBit(DM->CFG["�d�ʈ����g�p�敪"])){
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["�d�ʈ���"]   = col_row_map_;
        coord_name_map_[col_row_map_] = "�d�ʈ���";
        col_width_map_["�d�ʈ���"]    = 90;
    }

    ///// �����d��
    col_row_map_.clear();
    col_no++;
    col_row_map_[col_no]          = row_no;
    name_coord_map_["�����d��"]   = col_row_map_;
    coord_name_map_[col_row_map_] = "�����d��";
    col_width_map_["�����d��"]    = 90;


    ///// ���ה��l
    if (!ToBit(DM->CFG["�����g�p�敪"]) && !ToBit(DM->CFG["�d�ʈ����g�p�敪"]) && !ToBit(DM->CFG["�P���g�p�敪"])){
        col_no++;
    }else{
        line_colcount_map_[row_no] = col_no;
        row_no++;
        col_no = 2;
    }

    col_row_map_.clear();
    col_row_map_[col_no]          = row_no;
    name_coord_map_["���ה��l"]   = col_row_map_;
    coord_name_map_[col_row_map_] = "���ה��l";
    col_width_map_["���ה��l"]    = 170;

    ///// �P��
    if (ToBit(DM->CFG["�P���g�p�敪"])){

        ///// �P�ʃR�[�h
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["�P�ʃR�[�h"] = col_row_map_;
        coord_name_map_[col_row_map_] = "�P�ʃR�[�h";
        col_width_map_["�P�ʃR�[�h"]  = 32;

        ///// �P�ʖ���
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]              = row_no;
        name_coord_map_["�P�ʃ}�X�^����"] = col_row_map_;
        coord_name_map_[col_row_map_]     = "�P�ʃ}�X�^����";
        col_width_map_["�P�ʃ}�X�^����"]  = 80;

        ///// ����
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["����"]       = col_row_map_;
        coord_name_map_[col_row_map_] = "����";
        if (major_version >= 6)
            col_width_map_["����"] = 95;
        else
            col_width_map_["����"] = 100;

        ///// �P��
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["�P��"]       = col_row_map_;
        coord_name_map_[col_row_map_] = "�P��";
        if (major_version >= 6)
            col_width_map_["�P��"] = 95;
        else
            col_width_map_["�P��"] = 100;

        ///// ���z
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["���z"]       = col_row_map_;
        coord_name_map_[col_row_map_] = "���z";
        if (major_version >= 6)
            col_width_map_["���z"] = 95;
        else
            col_width_map_["���z"] = 100;

        ///// ����Ŋz
        col_row_map_.clear();
        col_no++;
        col_row_map_[col_no]          = row_no;
        name_coord_map_["����Ŋz"]   = col_row_map_;
        coord_name_map_[col_row_map_] = "����Ŋz";
        if (major_version >= 6)
            col_width_map_["����Ŋz"] = 95;
        else
            col_width_map_["����Ŋz"] = 100;
    }

    // 1���ׂ̍ŏI����Col�̈ʒu���
    line_end_col = col_no;
    line_colcount_map_[row_no] = col_no;

    // 1�v�ʂɑ΂���v�ʖ��ׂ̍s���ݒ�
    int col_count = 6;
    if (!ToBit(DM->CFG["�����g�p�敪"]) && !ToBit(DM->CFG["�d�ʈ����g�p�敪"]) && !ToBit(DM->CFG["�P���g�p�敪"])){
        detail_line      = 1;
        col_count++;
        SCGrid->ColCount = col_count;
    }else{
        detail_line      = 2;

        if (ToBit(DM->CFG["�����g�p�敪"]))
            col_count += 2;

        if (ToBit(DM->CFG["�d�ʈ����g�p�敪"]))
            col_count++;

        if (ToBit(DM->CFG["�P���g�p�敪"]))
            col_count = 9;

        SCGrid->ColCount = col_count;
    }

    // ���ׂ̍ő�s���ݒ�
    max_line_no_ = 6;

    // �O���b�h�����ݒ�
    SCGrid->FixedRows = detail_line;
    SCGrid->FixedCols = 1;
    SCGrid->DefaultColWidth = 10;

    // ���ږ����N���A
    for (int r = 0; r < detail_line; r++){
        for (int c = 0; c < SCGrid->ColCount; c++)
            SCGrid->Cells[c][r] = AnsiString();
    }

    // ���ږ��̃Z�b�g
    for (int r = 0; r < detail_line; r++){
        for (int c = 0; c < SCGrid->ColCount; c++){
            CoordToNameMap::iterator ctnm;

            col_row_map_.clear();
            col_row_map_[c] = r + 1; // col_row_map_��row��1�s�ڂ���Ȃ̂� + 1����
            ctnm = coord_name_map_.find(col_row_map_);

            if (ctnm == coord_name_map_.end()){
                SCGrid->Cells[c][r] = AnsiString();

                if (SCGrid->ColWidths[c] < 10)
                    SCGrid->ColWidths[c] = 10;
            }else{
                SCGrid->Cells[c][r] = GetColName(ctnm);

                if (SCGrid->ColWidths[c] < col_width_map_[ctnm->second])
                    SCGrid->ColWidths[c] = col_width_map_[ctnm->second];
            }

        }
    }

    if (detail_line == 2)
        max_row = 14;
    else
        max_row = 7;

    SCGrid->RowCount = max_row;

    TRect rect;
    int c = 0;
    int r = 0;
    for (int i = 0; i < detail_col; i++){
        if (SCGrid->Cells[c][r] == "���ה��l" && detail_line == 2){
            r = 2;
            c = 2;
        }

        rect.Left   = c;
        rect.Top    = r;
        rect.Right  = c;
        rect.Bottom = r;
        DrawText(SCGrid->Canvas->Handle, SCGrid->Cells[c][r].c_str(), SCGrid->Cells[c][r].Length(), &rect, DT_VCENTER | DT_CENTER | DT_SINGLELINE); //������

        c++;
    }

    // �O���b�h�̏c������
    if (detail_line == 2){
        SCGrid->Height       = 311;
        MeisaiScrollBox->Top = 288;
        SCGrid->Col          = 1;
        SCGrid->Row          = 2;
    }else{
        SCGrid->Height       = 157;
        MeisaiScrollBox->Top = 442;
        SCGrid->Col          = 1;
        SCGrid->Row          = 1;
    }
}
//---------------------------------------------------------------------------
// ���׃O���b�h�N���A
void __fastcall TMainForm::ClearDetailGrid()
{
    // DataColumn�N���A
    // Cells[col][row]�H
    // SCGrid->Cells[12][12]

    row_lineno_map_.clear(); // �sNo���N���A

    //SCGrid->Col = (int)1;
    //SCGrid->Row = (int)detail_line;

    for (int r = detail_line; r < SCGrid->RowCount; r++){
        for (int c = 0; c < SCGrid->ColCount; c++)
            SCGrid->Cells[c][r] = AnsiString();
    }

    // ���v�p�l���N���A
    TotalWeightLabel->Caption = AnsiString();
    MoneyLabel->Caption       = AnsiString();
    TaxLabel->Caption         = AnsiString();
    TotalMoneyLabel->Caption  = AnsiString();

    SCGrid->Options    = SCGrid->Options >> goEditing;
    SCGrid->EditorMode = false;
}
//---------------------------------------------------------------------------
// ���׃O���b�h�̃Z���͈͎̔w��
void __fastcall TMainForm::SCGrid_SelectCell(TStrColGrid *grid, int left, int top, int right, int bottom)
{
    TGridRect r;

    r.Left   = left;
    r.Top    = top;
    r.Right  = right;
    r.Bottom = bottom;

    grid->Selection = r;
}
//---------------------------------------------------------------------------
// ���ږ��Z�b�g
AnsiString __fastcall TMainForm::GetColName(CoordToNameMap::iterator ctnm)
{
    if (ctnm->second == "�i�ڃR�[�h" || ctnm->second == "�P�ʃR�[�h")
        return "*";
    else if (ctnm->second == "�i�ڃ}�X�^����")
        return DM->TrimString(ToString(DM->CFG["�i�ڃ}�X�^����"]));
    else if (ctnm->second == "�P�ʃ}�X�^����")
        return "�P��";
    else
        return ctnm->second;
}
//---------------------------------------------------------------------------
// ���ږ�����Col���擾
int __fastcall TMainForm::GetColNo(AnsiString name)
{
    NameToCoordMap::iterator ntcm;
    IntIntMap::iterator      iim;

    ntcm = name_coord_map_.find(name);
    if (ntcm == name_coord_map_.end()){
        return -1;
    }else{
        iim = ntcm->second.begin();
        return iim->first;
    }
}
//---------------------------------------------------------------------------
// ���ږ����牽�s�ڂ����擾
int __fastcall TMainForm::GetRowNo(AnsiString name)
{
    NameToCoordMap::iterator ntcm;
    IntIntMap::iterator      iim;

    ntcm = name_coord_map_.find(name);
    if (ntcm == name_coord_map_.end()){
        return -1;
    }else{
        iim = ntcm->second.begin();
        return iim->second;
    }
}
//---------------------------------------------------------------------------
// 2�s�ȏ�̏ꍇ�g���֐�
// ���ږ��ƌ��݂�Row��n���āA���ږ��ɑΉ�����Row��Ԃ�
// �߂�l�̍s����0�X�^�[�g�̍s��
int __fastcall TMainForm::CalcRowNo(AnsiString name, int row)
{
    if (detail_line == 1)
        return row;

    int item_row_no = GetRowNo(name);

    if (item_row_no == 1 && row % 2 == 0)
        return row;
    else if (item_row_no == 1 && row % 2 == 1)
        return row - 1;
    else if (item_row_no == 2 && row % 2 == 0)
        return row + 1;
    else if (item_row_no == 2 && row % 2 == 1)
        return row;
    else
        return row;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::GetCellName(int col, int row)
{
    CoordToNameMap::iterator ctnm;

    col_row_map_.clear();
    col_row_map_[col] = (row % detail_line) + 1;
    ctnm = coord_name_map_.find(col_row_map_);
    if (ctnm == coord_name_map_.end())
        return AnsiString();

    return ctnm->second;
}
//---------------------------------------------------------------------------
// �s���擾
int __fastcall TMainForm::GetLineNo(int row, int detail_line)
{
    int line_no = (row % detail_line) + 1;
    return line_no; 
}
//---------------------------------------------------------------------------
// �\������Ă���ő�s���擾
int __fastcall TMainForm::GetMaxLineNo()
{
    int no = 0;
    for (int r = detail_line; r < max_row; r += detail_line){
        if (!SCGrid->Cells[0][r].IsEmpty())
            no = SCGrid->Cells[0][r].ToIntDef(0);
    }

    return no;
}
//---------------------------------------------------------------------------
// �\������Ă���ő�s���擾 �����R�[�h�Ŕ���
int __fastcall TMainForm::GetMaxLineNo_M()
{
    int no = 0;

    if (StrToCurrDef(SCGrid->Cells[GetColNo("1��ڏd��")][detail_line], 0) > 0)
        no = SCGrid->Cells[0][detail_line].ToIntDef(0);

    for (int r = detail_line; r < max_row; r += detail_line){
        if (StrToCurrDef(SCGrid->Cells[GetColNo("2��ڏd��")][r], 0) > 0 || StrToCurrDef(SCGrid->Cells[GetColNo("�����d��")][r], 0) > 0)
            no = SCGrid->Cells[0][r].ToIntDef(0);
    }

    return no;
}
//---------------------------------------------------------------------------
// ���ʃZ���̒P�ʂȂ��̒l���擾
Currency __fastcall TMainForm::GetSuryoCellValue(AnsiString cell)
{
    if (tani_id_ == 0)
        return StrToCurrDef(cell, 0);

    AnsiString tani_name = ToString(DM->DBI.Lookup("M_�P��", "�P��ID", tani_id_, "�P�ʖ���"));

    int index;
    while ((index = cell.AnsiPos(" ")) > 0)
        cell.Delete(index, 1);

    while ((index = cell.AnsiPos(tani_name)) > 0)
        cell.Delete(index, tani_name.Length());

    return StrToCurrDef(cell, 0);
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

        // ���i�͏������Ȃ�
        //if (GetMode() == imFirst)
            //FirstWEdit->Text = cur_weight_;

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
        ShabanEdit->SetFocus();
        return false;
    }

    car_id_      = ShabanSanshoForm->GetCarID();
    int mastered = ShabanSanshoForm->GetDataDiv();

    if (!car_id_){
        // �V�K�ԗ��i��Ɠ��������j
        NsFieldSet fields;
        TDateTime  now(Now());

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

        // ���i�͏������Ȃ�
        //if (GetMode() == imFirst)
            //FirstWEdit->Text = cur_weight_;

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
            ShabanEdit->SetFocus();
            return false;
        }

        if (GetMode() != imMod){
            if (TokuCodeEdit->Text.IsEmpty())
                TokuCodeEdit->Text    = ZeroSuppress(ToInt(SET_TOP(set)["���Ӑ�R�[�h"]));
            if (Komoku1CodeEdit->Text.IsEmpty())
                Komoku1CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����1�R�[�h"]));
            if (Komoku2CodeEdit->Text.IsEmpty())
                Komoku2CodeEdit->Text = ZeroSuppress(ToInt(SET_TOP(set)["����2�R�[�h"]));
            //if (HinCodeEdit->Text.IsEmpty())
                //HinCodeEdit->Text     = ZeroSuppress(ToInt(SET_TOP(set)["�i�ڃR�[�h"]));

            if (ToCurrency(SET_TOP(set)["��ԏd��"]) > 0)
                keiryo_count_ = 1;
            else
                keiryo_count_ = 2;

            gross_limit_ = ToCurrency(SET_TOP(set)["�ԗ����d��"]);
            net_limit_   = ToCurrency(SET_TOP(set)["�ő�ύڗ�"]);

            SharyoNameEdit->Text = ToString(SET_TOP(set)["�ԗ�����"]);

            /* ���i�v�ʂ͏������Ȃ�
            if (keiryo_count_ == 2)
                FirstWEdit->Text = cur_weight_;
            else
                SecondWEdit->Text = cur_weight_;
            */
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
            return false;
        }

        //TNotifyEvent OnExit = ShabanEdit->OnExit;
        //ShabanEdit->OnExit  = 0;
        ContinueWeighing(keiryo_id);
        //ShabanEdit->OnExit  = OnExit;
    }

    //if (keiryo_count_ == 1)
        //CalcWeight();

    return true;
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::CalcNextRow(int keiryo_id)
{
    NsRecordSet set;
    AnsiString  sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     D_�v��"
          " WHERE"
          "     �v��ID = " + IntToStr(keiryo_id);
          " ORDER BY"
          "     �sNo ASC";
    if (!DM->DBI.GetRecordSet(sql, set))
        return 0;

    // 1���זڂ�2��ڏd�ʂ�0�ȉ���������1���ז�
    if (ToInt(SET_TOP(set)["2��ڏd��"]) <= 0)
        return detail_line;

    return (set.size() + 1) * detail_line;
}
//---------------------------------------------------------------------------

