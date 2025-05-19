//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include "CardEditFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TCardEditForm *CardEditForm;
//---------------------------------------------------------------------------
__fastcall TCardEditForm::TCardEditForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::FormShow(TObject *Sender)
{
	DM->AddComboMap(UseDivComboBox, use_div_map_, "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 10 ORDER BY �敪�R�[�h");

      if (id_ == 0){
            SetMode(imNew);
            RegistryNoEdit->SetFocus();
      }else{
            SetMode(imMod);
            CarNoEdit->SetFocus();
      }

	ClearForm(0);
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

	is_edit_ = false;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall TCardEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::ClearForm(int n)
{
    RegistryNoEdit->Text        = AnsiString();
	CarNoEdit->Text             = AnsiString();
	CarNameEdit->Text           = AnsiString();
    GyoshaCodeEdit->Text        = AnsiString();
	HinmokuCodeEdit->Text       = AnsiString();
    BikouEdit1->Text            = AnsiString();
    BikouEdit2->Text            = AnsiString();
    BikouEdit3->Text            = AnsiString();
    UseDivComboBox->ItemIndex   = 1;
	RenewDateEdit->Text         = AnsiString();
	CreateDateEdit->Text        = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption = "�V�K";
		ModePanel->Color = TColor(NEW_CLR);
		RenzokuCheckBox->Enabled = true;
		Action3->Enabled = false;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "�C��";
		ModePanel->Color = TColor(MOD_CLR);
		RenzokuCheckBox->Enabled = false;
		Action3->Enabled = true;
		Action7->Enabled = true;
		Action8->Enabled = true;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TCardEditForm::CheckEdit()
{
	if (RegistryNoEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("�o�^�ԍ��������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		RegistryNoEdit->SetFocus();
		return false;
	}

    // �o�^�ԍ��d���`�F�b�N
    if (RegistryNoEdit->Text != "" && RegistryNoEdit->Text.ToIntDef(0) != 0){
        if (id_ != 0){ /////// �C��
            NsRecordSet set;
            AnsiString sql;
            sql = " SELECT"
                  "     *"
                  " FROM"
                  "     M_�J�[�h"
                  " WHERE"
                  "     �o�^�ԍ� = " + IntToStr(RegistryNoEdit->Text.ToIntDef(0)) +
                  " AND"
                  "     �J�[�hID <> " + IntToStr(id_);
            if (DM->DBI.GetRecordSet(sql, set)){
                Application->MessageBox("�o�^�ԍ����d�����Ă��܂�\r\n�ʂ̔ԍ���I�����Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
                RegistryNoEdit->SetFocus();
                return false;
            }
        }else{         /////// �V�K
            if (DM->DBI.IsExist("M_�J�[�h", "�o�^�ԍ�", RegistryNoEdit->Text.ToIntDef(0))){
                Application->MessageBox("�o�^�ԍ����d�����Ă��܂�\r\n�ʂ̔ԍ���I�����Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
                RegistryNoEdit->SetFocus();
                return false;
            }
        }
    }

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TCardEditForm::PostRecord()
{
	NsFieldSet fields;
	fields << NsField("[�o�^�ԍ�]",    RegistryNoEdit->Text.ToIntDef(0))
           << NsField("[�ԗ�ID]",      ToInt(DM->DBI.Lookup("M_�ԗ�", "�Ԕ�", CarNoEdit->Text.ToIntDef(0), "�ԗ�ID")))
		   << NsField("[�Ǝ�ID]",      ToInt(DM->DBI.Lookup("M_�Ǝ�", "�Ǝ҃R�[�h", GyoshaCodeEdit->Text.ToIntDef(0), "�Ǝ�ID")))
		   << NsField("[�i��ID]",      ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID")))
           << NsField("[���l�ʐM��1]", BikouEdit1->Text)
           << NsField("[���l�ʐM��2]", BikouEdit2->Text)
           << NsField("[���l�ʐM��3]", BikouEdit3->Text)
		   << NsField("[�g�p�敪]",    use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[�X�V����]",    Now());

	try{
		if (id_ == 0){
			fields << NsField("[�쐬����]", Now());
			DM->DBI.Insert("M_�J�[�h", fields);
		}else{
			DM->DBI.Update("M_�J�[�h", "�J�[�hID", id_, fields);
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
void __fastcall TCardEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�J�[�h WHERE �J�[�hID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm(0);
		id_ = 0;
		return;
	}

	id_                  = ToInt(set[0]["�J�[�hID"]);
    RegistryNoEdit->Text = ToInt(SET_TOP(set)["�o�^�ԍ�"]);
	CarNoEdit->Text      = ToString(set[0]["�Ԕ�"]);
	CarNameEdit->Text    = ToString(set[0]["�ԗ�����"]);

	if (ToInt(set[0]["�Ǝ҃R�[�h"]) == 0)
		GyoshaCodeEdit->Text = AnsiString();
	else
		GyoshaCodeEdit->Text = ToInt(set[0]["�Ǝ҃R�[�h"]);
	if (ToInt(set[0]["�i�ڃR�[�h"]) == 0)
		HinmokuCodeEdit->Text = AnsiString();
	else
		HinmokuCodeEdit->Text = ToInt(set[0]["�i�ڃR�[�h"]);

    BikouEdit1->Text          = ToString(SET_TOP(set)["���l�ʐM��1"]);
    BikouEdit2->Text          = ToString(SET_TOP(set)["���l�ʐM��2"]);
    BikouEdit3->Text          = ToString(SET_TOP(set)["���l�ʐM��3"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["�g�p�敪"]));
	RenewDateEdit->Text       = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text      = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action1Execute(TObject *Sender)
{
    id_ = 0;
    SetMode(imNew);
    ClearForm(0);
    is_edit_ = false;
    RegistryNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (!DM->DBI.IsExist("M_�J�[�h", "�J�[�hID", id_)){
        Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (ToInt(DM->DBI.Lookup("M_�J�[�h", "�J�[�hID", id_, "�g�p�敪")) != 0){

        if (Application->MessageBox("���̃f�[�^���g�p�o���Ȃ��Ȃ�܂��B��낵���ł����H\r\n�Ȃ��A�{���ɍ폜����ꍇ�͈�x���̏������s�Ȃ�����\r\n������x�폜�{�^�����N���b�N���ĉ�����",
                "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

        NsFieldSet fields;
        try{
            fields << NsField("[�g�p�敪]", 0);
            DM->DBI.Update("M_�J�[�h", "�J�[�hID", id_, fields);
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
        keys << NsField("[�J�[�hID]", id_);
        try{
            DM->DBI.Delete("M_�J�[�h", keys);
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
void __fastcall TCardEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == GyoshaCodeEdit || ActiveControl == GyoshaNameEdit)
		GyoshaSearchButton->OnClick(NULL);
	if (ActiveControl == HinmokuCodeEdit || ActiveControl == HinmokuNameEdit)
		HinmokuSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action5Execute(TObject *Sender)
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
			ClearForm(0);
			RegistryNoEdit->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		CarNoEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action6Execute(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Card->Bof)
		return;

	DM->M_Card->Prior();
	id_ = DM->M_Card->FieldByName("�J�[�hID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Card->Eof)
		return;

	DM->M_Card->Next();
	id_ = DM->M_Card->FieldByName("�J�[�hID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::RegistryNoButtonClick(TObject *Sender)
{
    RegistryNoEdit->Text = GetRegistryNo();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::CarNoEditChange(TObject *Sender)
{
    if (CarNoEdit->Text == ""){
        CarNameEdit->Text = AnsiString();
        return;
    }

    AnsiString  sql;
    NsRecordSet set;
    sql = " SELECT"
          "     *"
          " FROM"
          "     M_�ԗ�"
          " WHERE"
          "     �Ԕ� = " + IntToStr(CarNoEdit->Text.ToIntDef(0) +
          " AND"
          "     �g�p�敪 = 1";
    if (!DM->DBI.GetRecordSet(sql, set)){
        CarNameEdit->Text = AnsiString();
        return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::CarSearchButtonClick(TObject *Sender)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::GyoshaCodeEditChange(TObject *Sender)
{
	if (GyoshaCodeEdit->Text == ""){
		GyoshaNameEdit->Text = AnsiString();
		return;
	}
	GyoshaNameEdit->Text = ToString(DM->DBI.Lookup("M_�Ǝ�", "�Ǝ҃R�[�h", GyoshaCodeEdit->Text.ToIntDef(0), "�ƎҖ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::GyoshaSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i, �Z��1, �Z��2, �d�b�ԍ� FROM V_���Ӑ�";
	SearchForm->orderby_sql      = " ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name       = " V_���Ӑ�";
	SearchForm->list_->CommaText = " ���Ӑ�R�[�h,���Ӑ旪��,���Ӑ�J�i,�Z��1,�Z��2,�d�b�ԍ�";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
	TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	if (HinmokuCodeEdit->Text == ""){
		HinmokuNameEdit->Text = AnsiString();
		return;
	}
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i�ږ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::HinmokuSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT �i�ڃR�[�h, �i�ڗ���, �i�ڃJ�i FROM V_�i��";
	SearchForm->orderby_sql      = " ORDER BY �i�ڃR�[�h";
	SearchForm->table_name       = " V_�i��";
	SearchForm->list_->CommaText = " �i�ڗ���, �i�ڃJ�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	HinmokuCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
	HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::RegistryNoEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �o�^�ԍ�����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::CarNoEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �ԔԂ���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::GyoshaCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �Ǝ҃R�[�h����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �i�ڃR�[�h����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::BikouEdit1Enter(TObject *Sender)
{
	StatusBar->SimpleText = "  ���l�ʐM��1����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::BikouEdit2Enter(TObject *Sender)
{
	StatusBar->SimpleText = "  ���l�ʐM��2����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::BikouEdit3Enter(TObject *Sender)
{
	StatusBar->SimpleText = "  ���l�ʐM��3����͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �g�p�敪��I�����ĉ������i[F4] ����\�����܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::UseDivComboBoxExit(TObject *Sender)
{
    Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::UseDivComboBoxKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Key != VK_RETURN)
        return;

    Action5->OnExecute();
}
//---------------------------------------------------------------------------
int __fastcall TSharyoEditForm::GetRegistryNo()
{
      int no = 1;
      while (1){
            if (!DM->DBI.IsExist("M_�J�[�h", "�o�^�ԍ�", no))
                  break;
            no++;
      }

      if (no > 9999){
            Application->MessageBox("�o�^����������ɒB���܂����B\r\n����ȏ�o�^�ł��܂���B",
                  this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            return -1;
      }

      return no;
}
//---------------------------------------------------------------------------

