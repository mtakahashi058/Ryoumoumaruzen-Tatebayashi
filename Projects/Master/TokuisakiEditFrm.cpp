//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SearchFrm.h"
#include "YubinSearchFrm.h"
#include "TokuisakiEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TTokuisakiEditForm *TokuisakiEditForm;
//---------------------------------------------------------------------------
__fastcall TTokuisakiEditForm::TTokuisakiEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::FormShow(TObject *Sender)
{
	DM->AddComboMap(UseDivComboBox,         use_div_map_,       "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 10 ORDER BY �敪�R�[�h");
	DM->AddComboMap(SeikyushoPrintComboBox, seikyu_print_map_,  "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 8  ORDER BY �敪�R�[�h");
	DM->AddComboMap(GenkakeComboBox,        genkake_map_,       "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 4  ORDER BY �敪�R�[�h");
	DM->AddComboMap(ZanDispComboBox,        zan_disp_map_,      "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 9  ORDER BY �敪�R�[�h");
	DM->AddComboMap(MoneyFractionComboBox,  fraction_map_,      "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 5  ORDER BY �敪�R�[�h");
	TaxFractionComboBox->Items->Text        = MoneyFractionComboBox->Items->Text;
    ConversionFractionComboBox->Items->Text = MoneyFractionComboBox->Items->Text;
	DM->AddComboMap(NyukinSiteComboBox,     nyukin_site_map_,   "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 6  ORDER BY �敪�R�[�h");
	DM->AddComboMap(NyukinMethodComboBox,   nyukin_method_map_, "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 7  ORDER BY �敪�R�[�h");
    // �h��
    DM->AddComboBox_Honorific(HonorificComboBox);
    // ����Ōv�Z�敪
    DM->AddComboMap(TaxCalcComboBox,        tax_calc_map_,      "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 13 ORDER BY �敪�R�[�h");

	if (id_ == 0)
		SetMode(imNew);
	else
		SetMode(imMod);

	ClearForm();
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

    is_edit_  = false;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];

	Application->OnMessage = this->AutoKanaMessage;

	CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 99 && ActiveControl->Tag != 2){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 99){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag != 0 && ActiveControl->Tag != 2 && ActiveControl->Tag != 99){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
      case VK_ESCAPE:
            Close();
            break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
int __fastcall TTokuisakiEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::ClearForm()
{
    int code = GetNo();
    if (code != -1)
        CodeEdit->Text = code;
    else
        CodeEdit->Text = AnsiString();

	NameEdit->Text            = AnsiString();
	ShortNameEdit->Text       = AnsiString();
	KanaEdit->Text            = AnsiString();
	YubinEdit->Text           = AnsiString();
	Address1Edit->Text        = AnsiString();
	Address2Edit->Text        = AnsiString();
	TelEdit->Text             = AnsiString();
	FaxEdit->Text             = AnsiString();
	SyncCodeEdit->Text        = AnsiString();
	UseDivComboBox->ItemIndex = 1;

	SeikyusakiCodeEdit->Text                = AnsiString();
	SeikyusakiNameEdit->Text                = AnsiString();
	SeikyushoPrintComboBox->ItemIndex       = 1;
	GenkakeComboBox->ItemIndex              = 0;
	SimebiEdit->Text                        = AnsiString();
	ZanDispComboBox->ItemIndex              = 1;
	ConversionFractionComboBox->ItemIndex   = 0;
	MoneyFractionComboBox->ItemIndex        = 0;
	TaxFractionComboBox->ItemIndex          = 0;
    TaxCalcComboBox->ItemIndex              = 0;
    HonorificComboBox->ItemIndex            = 0;
	NyukinSiteComboBox->ItemIndex           = 1;
	NyukinbiEdit->Text                      = AnsiString();
	NyukinMethodComboBox->ItemIndex         = 1;
	BankCodeEdit->Text                      = AnsiString();
	BankNameEdit->Text                      = AnsiString();
	BranchNameEdit->Text                    = AnsiString();
	AccountEdit->Text                       = AnsiString();
	AccountNameEdit->Text                   = AnsiString();

	RenewDateEdit->Text  = AnsiString();
	CreateDateEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SetMode(TInputMode mode)
{
    if (mode == imNew){
        ModePanel->Caption       = "�V�K";
        ModePanel->Color         = TColor(NEW_CLR);
        SaibanButton->Enabled    = true;
        RenzokuCheckBox->Enabled = true;
        Action3->Enabled         = false;
        Action8->Enabled         = false;
    }else if (mode == imMod){
        ModePanel->Caption       = "�C��";
        ModePanel->Color         = TColor(MOD_CLR);
        SaibanButton->Enabled    = false;
        RenzokuCheckBox->Enabled = false;
        Action3->Enabled         = true;
        Action8->Enabled         = true;
    }
}
//---------------------------------------------------------------------------
int __fastcall TTokuisakiEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT ���Ӑ�R�[�h FROM M_���Ӑ� WHERE ���Ӑ�R�[�h > 0 ORDER BY ���Ӑ�R�[�h", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["���Ӑ�R�[�h"]))
            break;
        else
            code++;
    }

	if (code > 99999){
		Application->MessageBox("�o�^����������ɒB���܂����B\r\n����ȏ�o�^�ł��܂���B",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return -1;
	}

	return code;
}
//---------------------------------------------------------------------------
bool __fastcall TTokuisakiEditForm::CheckEdit()
{
	if (CodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("�R�[�h�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		CodeEdit->SetFocus();
		return false;
	}

    ///// �R�[�h�d���`�F�b�N
    NsRecordSet set;
    AnsiString sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     M_���Ӑ�"
          " WHERE"
          "     ���Ӑ�R�[�h = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
          " AND"
          "     ���Ӑ�ID <> " + IntToStr(id_);
    if (DM->DBI.GetRecordSet(sql, set)){
        Application->MessageBox("�R�[�h���d�����Ă��܂��B���̃R�[�h���w�肵�Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        CodeEdit->SetFocus();
        return false;
    }

	if (NameEdit->Text == ""){
		Application->MessageBox("���̂������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		NameEdit->SetFocus();
		return false;
	}

    if (NameEdit->Text.Length() > 50)
        NameEdit->Text = DM->TrimString(NameEdit->Text, 50);

    if (ShortNameEdit->Text.Length() > 20)
        ShortNameEdit->Text = DM->TrimString(ShortNameEdit->Text, 20);

    if (KanaEdit->Text.Length() > 50)
        KanaEdit->Text = DM->TrimString(KanaEdit->Text, 50);

    if (Address1Edit->Text.Length() > 40)
        Address1Edit->Text = DM->TrimString(Address1Edit->Text, 40);

    if (Address2Edit->Text.Length() > 40)
        Address2Edit->Text = DM->TrimString(Address2Edit->Text, 40);

    if (SyncCodeEdit->Text.Length() > 20)
        SyncCodeEdit->Text = DM->TrimString(SyncCodeEdit->Text, 20);

    if (AccountNameEdit->Text.Length() > 30)
        AccountNameEdit->Text = DM->TrimString(AccountNameEdit->Text, 30);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TTokuisakiEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[���Ӑ�R�[�h]",       CodeEdit->Text.ToIntDef(0))
		   << NsField("[���Ӑ於��]",         NameEdit->Text)
		   << NsField("[���Ӑ旪��]",         ShortNameEdit->Text)
		   << NsField("[���Ӑ�J�i]",         KanaEdit->Text)
		   << NsField("[�X�֔ԍ�]",           YubinEdit->Text)
		   << NsField("[�Z��1]",              Address1Edit->Text)
		   << NsField("[�Z��2]",              Address2Edit->Text)
		   << NsField("[�d�b�ԍ�]",           TelEdit->Text)
		   << NsField("[FAX�ԍ�]",            FaxEdit->Text)
           << NsField("[�A�g�p�R�[�h]",       SyncCodeEdit->Text)
		   << NsField("[�g�p�敪]",           use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[���������s�敪]",     seikyu_print_map_[SeikyushoPrintComboBox->ItemIndex])
		   << NsField("[���|�敪]",           genkake_map_[GenkakeComboBox->ItemIndex])
		   << NsField("[����]",               SimebiEdit->Text.ToIntDef(0))
		   << NsField("[�c���\���敪]",       zan_disp_map_[ZanDispComboBox->ItemIndex])
           << NsField("[���Z�[�������敪]",   fraction_map_[ConversionFractionComboBox->ItemIndex])
		   << NsField("[���z�[�������敪]",   fraction_map_[MoneyFractionComboBox->ItemIndex])
		   << NsField("[����Œ[�������敪]", fraction_map_[TaxFractionComboBox->ItemIndex])
           << NsField("[����Ōv�Z�敪]",     tax_calc_map_[TaxCalcComboBox->ItemIndex])
		   << NsField("[�h��]",               HonorificComboBox->Text)
		   << NsField("[�����T�C�g]",         nyukin_site_map_[NyukinSiteComboBox->ItemIndex])
		   << NsField("[������]",             NyukinbiEdit->Text.ToIntDef(0))
		   << NsField("[�������@]",           nyukin_method_map_[NyukinMethodComboBox->ItemIndex])
           << NsField("[��sID]",             ToInt(DM->DBI.Lookup("M_��s", "��s�R�[�h", BankCodeEdit->Text.ToIntDef(0), "��sID")))
           << NsField("[�������`����]",       AccountNameEdit->Text)
		   << NsField("[�X�V����]",           Now());


    // �}�X�^�f�[�^�o�^/�X�V
    DM->ADOConnection->BeginTrans();
	try{
		if (id_ == 0){
			fields << NsField("[�쐬����]", Now());
			DM->DBI.Insert("M_���Ӑ�", fields);
		}else{
            //int seikyu = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID", ""));
			fields << NsField("[������ID]", ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID", "")));
			DM->DBI.Update("M_���Ӑ�", "���Ӑ�ID", id_, fields);
		}
	}catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}
    DM->ADOConnection->CommitTrans();

    // �V�K�o�^���̐�����ID�̓o�^
    if (id_ == 0){
        DM->ADOConnection->BeginTrans();
        try{
            fields.clear();
            fields << NsField("[������ID]", ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", CodeEdit->Text.ToIntDef(0), "���Ӑ�ID", "")));

            int id_buff = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", CodeEdit->Text.ToIntDef(0), "���Ӑ�ID", ""));
            DM->DBI.Update("M_���Ӑ�", "���Ӑ�ID", id_buff, fields);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("������̍X�V�Ɏ��s���܂����B�o�^������ɍēx�m�F���Ă��������B\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
        }
        DM->ADOConnection->CommitTrans();
    }

    // ���̃f�[�^�̐��������X�V
    DM->ADOConnection->BeginTrans();
    if (id_ != 0){
        AnsiString sql;
        sql = " UPDATE"
              "     M_���Ӑ�"
              " SET"
              "     ���������s�敪 = "     + IntToStr(seikyu_print_map_[SeikyushoPrintComboBox->ItemIndex]) + "," +
              "     ���|�敪 = "           + IntToStr(genkake_map_[GenkakeComboBox->ItemIndex]) + "," +
              "     ���� = "               + IntToStr(SimebiEdit->Text.ToIntDef(0)) + "," +
              "     �c���\���敪 = "       + IntToStr(zan_disp_map_[ZanDispComboBox->ItemIndex]) + "," +
              "     ���Z�[�������敪 = "   + IntToStr(fraction_map_[ConversionFractionComboBox->ItemIndex]) + "," +
              "     ���z�[�������敪 = "   + IntToStr(fraction_map_[MoneyFractionComboBox->ItemIndex]) + "," +
              "     ����Œ[�������敪 = " + IntToStr(fraction_map_[TaxFractionComboBox->ItemIndex]) + "," +
              "     �h�� = '"              + HonorificComboBox->Text + "'," +
              "     �����T�C�g = "         + IntToStr(nyukin_site_map_[NyukinSiteComboBox->ItemIndex]) + "," +
              "     ������ = "             + IntToStr(NyukinbiEdit->Text.ToIntDef(0)) + "," +
              "     �������@ = "           + IntToStr(nyukin_method_map_[NyukinMethodComboBox->ItemIndex]) + "," +
              "     ��sID = "             + IntToStr(ToInt(DM->DBI.Lookup("M_��s", "��s�R�[�h", BankCodeEdit->Text.ToIntDef(0), "��sID"))) + "," +
              "     �������`���� = '"      + AccountNameEdit->Text + "'," +
              "     �X�V���� = GETDATE()"
              " WHERE"
              "     ������ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID")));
        try{
            DM->DBI.Execute(sql);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("�������̍X�V�Ɏ��s���܂���\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
            return false;
        }
    }
    DM->ADOConnection->CommitTrans();

	is_edit_ = true;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_���Ӑ� WHERE ���Ӑ�ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                       = ToInt(set[0]["���Ӑ�ID"]);
	CodeEdit->Text            = ToString(set[0]["���Ӑ�R�[�h"]);
	NameEdit->Text            = ToString(set[0]["���Ӑ於��"]);
	ShortNameEdit->Text       = ToString(set[0]["���Ӑ旪��"]);
	KanaEdit->Text            = ToString(set[0]["���Ӑ�J�i"]);
	YubinEdit->Text           = ToString(set[0]["�X�֔ԍ�"]);
	Address1Edit->Text        = ToString(set[0]["�Z��1"]);
	Address2Edit->Text        = ToString(set[0]["�Z��2"]);
	TelEdit->Text             = ToString(set[0]["�d�b�ԍ�"]);
	FaxEdit->Text             = ToString(set[0]["FAX�ԍ�"]);
    SyncCodeEdit->Text        = ToString(set[0]["�A�g�p�R�[�h"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["�g�p�敪"]));

	SeikyusakiCodeEdit->Text          = ToString(set[0]["������R�[�h"]);
	SeikyushoPrintComboBox->ItemIndex = DM->SearchIndex(seikyu_print_map_, ToInt(set[0]["���������s�敪"]));
	GenkakeComboBox->ItemIndex        = DM->SearchIndex(genkake_map_, ToInt(set[0]["���|�敪"]));
	SimebiEdit->Text                  = ToString(set[0]["����"]);
	ZanDispComboBox->ItemIndex        = DM->SearchIndex(zan_disp_map_, ToInt(set[0]["�c���\���敪"]));
    ConversionFractionComboBox->ItemIndex = DM->SearchIndex(fraction_map_, ToInt(set[0]["���Z�[�������敪"]));
	MoneyFractionComboBox->ItemIndex  = DM->SearchIndex(fraction_map_, ToInt(set[0]["���z�[�������敪"]));
	TaxFractionComboBox->ItemIndex    = DM->SearchIndex(fraction_map_, ToInt(set[0]["����Œ[�������敪"]));
    TaxCalcComboBox->ItemIndex        = DM->SearchIndex(tax_calc_map_, ToInt(set[0]["����Ōv�Z�敪"]));
    HonorificComboBox->Text           = ToString(set[0]["�h��"]);
	NyukinSiteComboBox->ItemIndex     = DM->SearchIndex(nyukin_site_map_, ToInt(set[0]["�����T�C�g"]));
	NyukinbiEdit->Text                = ToString(set[0]["������"]);
	NyukinMethodComboBox->ItemIndex   = DM->SearchIndex(nyukin_method_map_, ToInt(set[0]["�������@"]));
    BankCodeEdit->Text                = ToString(set[0]["��s�R�[�h"]);
    BranchNameEdit->Text              = ToString(set[0]["�x�X����"]);
    AccountEdit->Text                 = ToString(set[0]["����"]);
    AccountNameEdit->Text             = ToString(set[0]["�������`����"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AutoKanaMessage(tagMSG &Msg, bool &Handled)
{
	if (Msg.message == WM_IME_ENDCOMPOSITION){
		int ret;
		HIMC ime;
		char buf[256];
		ime = ImmGetContext(Handle);

		ret = ImmGetCompositionString(ime, GCS_RESULTREADSTR, buf, sizeof(buf));

		buf[ret] = '\0';

		ImmReleaseContext(Handle, ime);

		AnsiString buff = "";
		if (ActiveControl == NameEdit){
			buff = KanaEdit->Text;
			if (KanaEdit->Text != "")
				buff = buff + (AnsiString)buf;
			else
				buff = (AnsiString)buf;
			KanaEdit->Text = AnsiSubString(buff, 1, 50);
			Handled = false;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action1Execute(TObject *Sender)
{
    id_ = 0;
    SetMode(imNew);
    ClearForm();
    is_edit_ = false;
    CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (!DM->DBI.IsExist("M_���Ӑ�", "���Ӑ�ID", id_)){
        Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�ID", id_, "�g�p�敪")) != 0){

        if (Application->MessageBox("���̃f�[�^���g�p�o���Ȃ��Ȃ�܂��B��낵���ł����H\r\n�Ȃ��A�{���ɍ폜����ꍇ�͈�x���̏������s�Ȃ�����\r\n������x�폜�{�^�����N���b�N���ĉ�����",
                "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

        NsFieldSet fields;
        try{
            fields << NsField("[�g�p�敪]", 0);
            DM->DBI.Update("M_���Ӑ�", "���Ӑ�ID", id_, fields);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("�f�[�^�폜�Ɏ��s���܂���\r\n" + e.Message).c_str(), "�폜", MB_OK | MB_ICONWARNING);
            return;
        }
        msg = "�g�p�敪��ύX���܂���\r\n�ēx�g�p����ۂɂ͎g�p�敪��ύX���ĉ�����";

    }else{

        if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H", "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

        NsFieldSet keys;
        keys << NsField("[���Ӑ�ID]", id_);
        try{
            DM->DBI.Delete("M_���Ӑ�", keys);
            DM->DeleteRelateMaster(page_, keyfield_, id_);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("�f�[�^�폜�Ɏ��s���܂���\r\n" + e.Message).c_str(), "�폜", MB_OK | MB_ICONWARNING);
            return;
        }
        msg = "�f�[�^���폜���܂���";

    }
    DM->ADOConnection->CommitTrans();
    MainForm->OpenQuery(page_, MainForm->order_);
    id_ = MainForm->query[page_]->FieldByName(keyfield_)->AsInteger;
    BrowseRecord();
    Application->MessageBox(msg.c_str(), "�폜", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action4Execute(TObject *Sender)
{
    if (ActiveControl == CodeEdit)
        SaibanButton->OnClick(NULL);
    else if (ActiveControl == YubinEdit)
        YubinSearchButton->OnClick(NULL);
    else if (ActiveControl == SeikyusakiCodeEdit || ActiveControl == SeikyusakiNameEdit)
        SeikyusakiSearchButton->OnClick(NULL);
    else if (ActiveControl == BankCodeEdit || ActiveControl == BankNameEdit)
        BankSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("�o�^�^�C�����܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("�o�^�^�C�����܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    // �o�^���Ɍh�̂�������P�[�X���l���Čh�̃R���{�{�b�N�X�Đݒ�
    DM->AddComboBox_Honorific(HonorificComboBox);

	if (DM->GetMode(ModePanel) == imNew){
		if (RenzokuCheckBox->Checked){
			ClearForm();
			CodeEdit->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		NameEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action7Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) == imMod && DM->M_Tokuisaki->Bof)
        return;

    if (DM->GetMode(ModePanel) == imNew){
        ClearForm();
        SetMode(imMod);
        is_edit_ = false;
        DM->M_Tokuisaki->Last();
    }else
        DM->M_Tokuisaki->Prior();

    id_ = DM->M_Tokuisaki->FieldByName("���Ӑ�ID")->AsInteger;
    BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Tokuisaki->Eof)
		return;

	DM->M_Tokuisaki->Next();
	id_ = DM->M_Tokuisaki->FieldByName("���Ӑ�ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodeEditExit(TObject *Sender)
{
    if (CodeEdit->Text == "")
        return;

    NsRecordSet set;
    if (!DM->DBI.GetRecordSet("SELECT ���Ӑ�ID FROM M_���Ӑ� WHERE ���Ӑ�R�[�h = " + CodeEdit->Text + " AND ���Ӑ�ID <> " + IntToStr(id_), set))
        return;

    if (Application->MessageBox("����R�[�h���o�^����Ă��܂��B\r\n�C�����[�h�ŌĂяo���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    SetMode(imMod);
    id_ = ToInt(set[0]["���Ӑ�ID"]);
    BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SaibanButtonClick(TObject *Sender)
{
    CodeEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NameEditExit(TObject *Sender)
{
	if (DM->GetMode(ModePanel) == imMod)
		return;

	if (NameEdit->Text == "")
		return;

	ShortNameEdit->Text = AnsiSubString(DM->Formal2Informal(NameEdit->Text), 1, 20);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AddressSearchButtonClick(
	  TObject *Sender)
{
	AnsiString sql = AnsiString();
	NsRecordSet set;
	AnsiString postal_code = YubinEdit->Text;
	postal_code = AnsiReplaceStr(postal_code, "-", "");
	if (postal_code.ToIntDef(0) == 0){
		Application->OnMessage = this->AutoKanaMessage;
		return;
	}

	sql = "SELECT �s���{����, �s�撬����, ���於 FROM M_�X�֔ԍ� WHERE �X�֔ԍ� = " + postal_code;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set)){
		if (Application->MessageBox("�Y������X�֔ԍ���������܂���ł���", "�X�֔ԍ�����", MB_OK | MB_ICONEXCLAMATION) != IDYES){
			Application->OnMessage = this->AutoKanaMessage;
			return;
		}
	}

	if (Address1Edit->Text != "" || Address2Edit->Text != ""){
		if (Application->MessageBox("�Y������X�֔ԍ���������܂���\r\n�㏑�����Ă�낵���ł����H", "�X�֔ԍ�����", MB_YESNO | MB_ICONQUESTION) != IDYES){
			Application->OnMessage = this->AutoKanaMessage;
			return;
		}
	}

	AnsiString address = ToString(set[0]["�s���{����"]) + ToString(set[0]["�s�撬����"]) + ToString(set[0]["���於"]);
	Address1Edit->Text = AnsiDivide(&address, 40);
	Address2Edit->Text = AnsiDivide(&address, 40);
	Address1Edit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::YubinSearchButtonClick(TObject *Sender)
{
	if (YubinSearchForm->ShowModal() == mrCancel)
		return;

	if (YubinEdit->Text != ""){
		if (Application->MessageBox("���ݓ��͂���Ă���X�֔ԍ��ɏ㏑�����Ă�낵���ł����H",
				this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
			return;
	}

	YubinEdit->Text    = YubinSearchForm->YubinEdit->Text;
	AnsiString address = YubinSearchForm->KenListBox->Items->Strings[YubinSearchForm->KenListBox->ItemIndex] +
    YubinSearchForm->SiListBox->Items->Strings[YubinSearchForm->SiListBox->ItemIndex] +
    YubinSearchForm->TyouikiListBox->Items->Strings[YubinSearchForm->TyouikiListBox->ItemIndex];
	Address1Edit->Text = AnsiDivide(&address, 40);
	Address2Edit->Text = AnsiDivide(&address, 40);
	YubinEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiCodeEditChange(
	  TObject *Sender)
{
	if (SeikyusakiCodeEdit->Text == ""){
		SeikyusakiNameEdit->Text = AnsiString();
		return;
	}

    NsRecordSet set;
    if (!DM->DBI.GetRecordSet("SELECT * FROM V_���Ӑ� WHERE ���Ӑ�R�[�h = " + IntToStr(SeikyusakiCodeEdit->Text.ToIntDef(0)), set)){

        if (DM->GetMode(ModePanel) == imNew && CodeEdit->Text.ToIntDef(0) == SeikyusakiCodeEdit->Text.ToIntDef(0))
        	SeikyusakiNameEdit->Text = ShortNameEdit->Text;
        else
            SeikyusakiNameEdit->Text = AnsiString();

    	SeikyushoPrintComboBox->ItemIndex = 1;
    	GenkakeComboBox->ItemIndex        = 0;
    	SimebiEdit->Text                  = AnsiString();
    	ZanDispComboBox->ItemIndex        = 1;
        ConversionFractionComboBox->ItemIndex = 0;
    	MoneyFractionComboBox->ItemIndex  = 0;
    	TaxFractionComboBox->ItemIndex    = 0;
	    NyukinSiteComboBox->ItemIndex     = 1;
    	NyukinbiEdit->Text                = AnsiString();
	    NyukinMethodComboBox->ItemIndex   = 1;
        BankCodeEdit->Text                = AnsiString();
        BranchNameEdit->Text              = AnsiString();
        AccountEdit->Text                 = AnsiString();
        AccountNameEdit->Text             = AnsiString();
        return;
    }

	SeikyusakiCodeEdit->Text          = ToString(set[0]["���Ӑ�R�[�h"]);
    SeikyusakiNameEdit->Text          = ToString(set[0]["���Ӑ旪��"]);
	SeikyushoPrintComboBox->ItemIndex = DM->SearchIndex(seikyu_print_map_, ToInt(set[0]["���������s�敪"]));
	GenkakeComboBox->ItemIndex        = DM->SearchIndex(genkake_map_, ToInt(set[0]["���|�敪"]));
	SimebiEdit->Text                  = ToString(set[0]["����"]);
	ZanDispComboBox->ItemIndex        = DM->SearchIndex(zan_disp_map_, ToInt(set[0]["�c���\���敪"]));
    ConversionFractionComboBox->ItemIndex = DM->SearchIndex(fraction_map_, ToInt(set[0]["���Z�[�������敪"]));
	MoneyFractionComboBox->ItemIndex  = DM->SearchIndex(fraction_map_, ToInt(set[0]["���z�[�������敪"]));
	TaxFractionComboBox->ItemIndex    = DM->SearchIndex(fraction_map_, ToInt(set[0]["����Œ[�������敪"]));
	NyukinSiteComboBox->ItemIndex     = DM->SearchIndex(nyukin_site_map_, ToInt(set[0]["�����T�C�g"]));
	NyukinbiEdit->Text                = ToString(set[0]["������"]);
	NyukinMethodComboBox->ItemIndex   = DM->SearchIndex(nyukin_method_map_, ToInt(set[0]["�������@"]));
    BankCodeEdit->Text                = ToString(set[0]["��s�R�[�h"]);
    BranchNameEdit->Text              = ToString(set[0]["�x�X����"]);
    AccountEdit->Text                 = ToString(set[0]["����"]);
    AccountNameEdit->Text             = ToString(set[0]["�������`����"]);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiCodeEditExit(TObject *Sender)
{
	if (SeikyusakiCodeEdit->Text != "")
		return;

	SeikyusakiCodeEdit->Text = CodeEdit->Text;
	SeikyusakiNameEdit->Text = ShortNameEdit->Text;
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT ���Ӑ�R�[�h AS ������R�[�h, ���Ӑ旪�� AS �����旪��, ���Ӑ�J�i AS ������J�i, �Z��1, �Z��2, �d�b�ԍ� FROM V_���Ӑ�";
    SearchForm->orderby_sql      = " ORDER BY ���Ӑ�R�[�h";
    SearchForm->table_name       = " V_���Ӑ�";
    SearchForm->list_->CommaText = " ���Ӑ�R�[�h,���Ӑ旪��,���Ӑ�J�i,�Z��1,�Z��2,�d�b�ԍ�";

    if (SearchForm->ShowModal() != mrOk)
        return;
    SeikyusakiCodeEdit->Text = SearchForm->Query->FieldByName("������R�[�h")->AsInteger;
    SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BankSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT ��s�R�[�h, ��s����, �x�X����, ���� FROM V_��s";
    SearchForm->orderby_sql      = " ORDER BY ��s�R�[�h";
    SearchForm->table_name       = " V_��s";
    SearchForm->list_->CommaText = " ��s�R�[�h,��s����,�x�X����,����";

    if (SearchForm->ShowModal() != mrOk)
        return;
    BankCodeEdit->Text = SearchForm->Query->FieldByName("��s�R�[�h")->AsInteger;
    AccountNameEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �R�[�h����͂��ĉ������i�̔�[F4]���������ŁA�󂫔Ԍ������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  ���̂���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::ShortNameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �K�v�ȏꍇ���̂�ύX���ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::KanaEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �K�v�ȏꍇ�J�i��ύX���ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::YubinEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �X�֔ԍ�����͂��ĉ������i���͌�A�Z���������N���b�N����ƏZ�����������͂���܂��B�܂��X�֔ԍ�����[F4]�ŗX�֔ԍ��̌������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Address1EditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �Z��1����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Address2EditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �Z��2����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::TelEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �d�b�ԍ�����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::FaxEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  FAX�ԍ�����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �g�p�敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::UseDivComboBoxExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiCodeEditEnter(
	  TObject *Sender)
{
	StatusBar->SimpleText = "  ���������͂��ĉ������B�i[F4] �����挟�����s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyushoPrintComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  ���������s�敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::GenkakeComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  ���|�敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SimebiEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  ��������͂��ĉ������i������[99]����͂��ĉ������j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::ZanDispComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �c���\���敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::MoneyFractionComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  ���z�[�������敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::TaxFractionComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  ����Œ[�������敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NyukinSiteComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �����T�C�g��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NyukinbiEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  ����������͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NyukinMethodComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �������@��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BankCodeEditChange(TObject *Sender)
{
      NsRecordSet set;
      AnsiString sql;
      sql = "SELECT * FROM V_��s WHERE ��s�R�[�h = " + IntToStr(BankCodeEdit->Text.ToIntDef(0));
      if (!DM->DBI.GetRecordSet(sql, set)){
            BankNameEdit->Text      = AnsiString();
            BranchNameEdit->Text    = AnsiString();
            AccountEdit->Text       = AnsiString();
            return;
      }

      BankNameEdit->Text      = ToString(set[0]["��s����"]);
      BranchNameEdit->Text    = ToString(set[0]["�x�X����"]);
      AccountEdit->Text       = ToString(set[0]["����"]);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BankCodeEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  ��s��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AccountNameEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  �������`���̂���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AccountNameEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

