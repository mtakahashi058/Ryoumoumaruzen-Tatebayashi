//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "HinmokuEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
THinmokuEditForm *HinmokuEditForm;
//---------------------------------------------------------------------------
__fastcall THinmokuEditForm::THinmokuEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::FormShow(TObject *Sender)
{
	DM->AddComboMap(UseDivComboBox, use_div_map_, "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 10 ORDER BY �敪�R�[�h");
	DM->AddComboMap(IoDivComboBox,  io_div_map_,  "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 2 ORDER BY �敪�R�[�h");

    if (id_ == 0)
        SetMode(imNew);
    else
        SetMode(imMod);

	ClearForm();
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

	is_edit_  = true;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];

	Application->OnMessage = this->AutoKanaMessage;

	hinbun_ = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]) + "����", " ", "");
	hinbun_ = AnsiReplaceStr(hinbun_, "�@", "");
    CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
	}
}
//---------------------------------------------------------------------------
int __fastcall THinmokuEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::ClearForm()
{
      int code = GetNo();
      if (code != -1)
            CodeEdit->Text = code;
      else
            CodeEdit->Text = AnsiString();

	NameEdit->Text            = AnsiString();
	ShortNameEdit->Text       = AnsiString();
	KanaEdit->Text            = AnsiString();
	HinBunruiCodeEdit->Text   = AnsiString();
	ChoseiEdit->Text          = AnsiString();
	IoDivComboBox->ItemIndex  = 0;
    DealDivCombo->ItemIndex   = 0;
	UseDivComboBox->ItemIndex = 1;

	RenewDateEdit->Text  = AnsiString();
	CreateDateEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption = "�V�K";
		ModePanel->Color = TColor(NEW_CLR);
		SaibanButton->Enabled = true;
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "�C��";
		ModePanel->Color = TColor(MOD_CLR);
		SaibanButton->Enabled = false;
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled = true;
		Action8->Enabled = true;
	}
}
//---------------------------------------------------------------------------
int __fastcall THinmokuEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT �i�ڃR�[�h FROM M_�i�� WHERE �i�ڃR�[�h > 0 ORDER BY �i�ڃR�[�h", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["�i�ڃR�[�h"]))
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
bool __fastcall THinmokuEditForm::CheckEdit()
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
            "     M_�i��"
            " WHERE"
            "     �i�ڃR�[�h = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
            " AND"
            "     �i��ID <> " + IntToStr(id_);
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

      if (NameEdit->Text.Length() > 40)
            NameEdit->Text = DM->TrimString(NameEdit->Text, 40);

      if (ShortNameEdit->Text.Length() > 20)
            ShortNameEdit->Text = DM->TrimString(ShortNameEdit->Text, 20);

      if (KanaEdit->Text.Length() > 50)
            KanaEdit->Text = DM->TrimString(KanaEdit->Text, 50);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall THinmokuEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[�i�ڃR�[�h]", CodeEdit->Text.ToIntDef(0))
		   << NsField("[�i�ږ���]",   NameEdit->Text)
		   << NsField("[�i�ڗ���]",   ShortNameEdit->Text)
		   << NsField("[�i�ڃJ�i]",   KanaEdit->Text)
		   << NsField("[�i�ڕ���ID]", ToInt(DM->DBI.Lookup("M_�i�ڕ���", "�i�ڕ��ރR�[�h", HinBunruiCodeEdit->Text.ToIntDef(0), "�i�ڕ���ID", "�g�p�敪 = 1")))
		   << NsField("[�����o�敪]", io_div_map_[IoDivComboBox->ItemIndex])
		   << NsField("[�d�ʒ�����]", StrToCurrDef(ChoseiEdit->Text, 0))
		   << NsField("[����敪]",   DealDivCombo->ItemIndex + 1)
		   << NsField("[�g�p�敪]",   use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[�X�V����]",   Now());

	try{
		if (id_ == 0){
			fields << NsField("[�쐬����]", Now());
			DM->DBI.Insert("M_�i��", fields);
		}else{
			DM->DBI.Update("M_�i��", "�i��ID", id_, fields);
		}
	}catch (Exception &e){
		Application->MessageBox(("�o�^�^�C���Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	is_edit_ = true;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�i�� WHERE �i��ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                       = ToInt(set[0]["�i��ID"]);
	CodeEdit->Text            = ToString(set[0]["�i�ڃR�[�h"]);
	NameEdit->Text            = ToString(set[0]["�i�ږ���"]);
	ShortNameEdit->Text       = ToString(set[0]["�i�ڗ���"]);
	KanaEdit->Text            = ToString(set[0]["�i�ڃJ�i"]);
	HinBunruiCodeEdit->Text   = ToString(set[0]["�i�ڕ��ރR�[�h"]);
	ChoseiEdit->Text          = ToCurrency(set[0]["�d�ʒ�����"]);
	IoDivComboBox->ItemIndex  = DM->SearchIndex(io_div_map_,  ToInt(set[0]["�����o�敪"]));
	try{
		DealDivCombo->ItemIndex = ToInt(set[0]["����敪"]) - 1;
	}catch(...){
		DealDivCombo->ItemIndex = 0;
	}
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["�g�p�敪"]));

	RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::AutoKanaMessage(tagMSG &Msg, bool &Handled)
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
// F1 �V�K
void __fastcall THinmokuEditForm::Action1Execute(TObject *Sender)
{
	  id_ = 0;
	  SetMode(imNew);
	  ClearForm();
	  is_edit_ = false;
	  CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F3 �폜
void __fastcall THinmokuEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (!DM->DBI.IsExist("M_�i��", "�i��ID", id_)){
        Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (ToInt(DM->DBI.Lookup("M_�i��", "�i��ID", id_, "�g�p�敪")) != 0){

        if (Application->MessageBox("���̃f�[�^���g�p�o���Ȃ��Ȃ�܂��B��낵���ł����H\r\n�Ȃ��A�{���ɍ폜����ꍇ�͈�x���̏������s�Ȃ�����\r\n������x�폜�{�^�����N���b�N���ĉ�����",
                "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

        NsFieldSet fields;
        try{
            fields << NsField("[�g�p�敪]", 0);
            DM->DBI.Update("M_�i��", "�i��ID", id_, fields);
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
        keys << NsField("[�i��ID]", id_);
        try{
            DM->DBI.Delete("M_�i��", keys);
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
// F4 �Q��
void __fastcall THinmokuEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == CodeEdit)
		SaibanButton->OnClick(NULL);
	if (ActiveControl == HinBunruiCodeEdit || ActiveControl == HinBunruiNameEdit)
		HinBunruiSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
// F5 �o�^
void __fastcall THinmokuEditForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("�o�^�^�C�����܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("�o�^�^�C�����܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

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
// F7 �O��
void __fastcall THinmokuEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Hinmoku->Bof)
		return;

	DM->M_Hinmoku->Prior();
	id_ = DM->M_Hinmoku->FieldByName("�i��ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
// F8 ����
void __fastcall THinmokuEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Hinmoku->Eof)
		return;

	DM->M_Hinmoku->Next();
	id_ = DM->M_Hinmoku->FieldByName("�i��ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
// F12 ����
void __fastcall THinmokuEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::CodeEditExit(TObject *Sender)
{
	if (CodeEdit->Text == "")
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT �i��ID FROM M_�i�� WHERE �i�ڃR�[�h = " + CodeEdit->Text + " AND �i��ID <> " + IntToStr(id_), set))
		return;

	  if (Application->MessageBox("����R�[�h���o�^����Ă��܂��B\r\n�C�����[�h�ŌĂяo���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
			return;

	SetMode(imMod);
	id_ = ToInt(set[0]["�i��ID"]);
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::SaibanButtonClick(TObject *Sender)
{
	CodeEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::NameEditExit(TObject *Sender)
{
	if (DM->GetMode(ModePanel) == imMod)
		return;

	if (NameEdit->Text == "")
		return;

	ShortNameEdit->Text = AnsiSubString(DM->Formal2Informal(NameEdit->Text), 1, 20);
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::HinBunruiCodeEditChange(TObject *Sender)
{
	if (HinBunruiCodeEdit->Text == ""){
		HinBunruiNameEdit->Text = AnsiString();
		return;
	}
	HinBunruiNameEdit->Text = ToString(DM->DBI.Lookup("M_�i�ڕ���", "�i�ڕ��ރR�[�h", HinBunruiCodeEdit->Text.ToIntDef(0), "�i�ڕ��ޖ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::HinBunruiSearchButtonClick(
	  TObject *Sender)
{
	SearchForm->Top              = Application->MainForm->Top + 50;
	SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT �i�ڕ��ރR�[�h, �i�ڕ��ޖ���, �i�ڕ��ރJ�i FROM V_�i�ڕ���";
	SearchForm->orderby_sql      = " ORDER BY �i�ڕ��ރR�[�h";
	SearchForm->table_name       = " V_�i�ڕ���";
	SearchForm->list_->CommaText = " �i�ڕ��ޗ���, �i�ڕ��ރJ�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	HinBunruiCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڕ��ރR�[�h")->AsInteger;
	HinBunruiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �R�[�h����͂��ĉ������i�̔�[F4]���������ŁA�󂫔Ԍ������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::NameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  ���̂���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::ShortNameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �K�v�ȏꍇ���̂�ύX���ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::KanaEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �K�v�ȏꍇ�J�i��ύX���ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::HinBunruiCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + hinbun_ + "����͂��ĉ������B�i[F4] " + hinbun_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::ChoseiEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �d�ʒ���������͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::IoDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �����o�敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �g�p�敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::UseDivComboBoxExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall THinmokuEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

