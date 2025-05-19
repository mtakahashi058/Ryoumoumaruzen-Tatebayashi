//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "SharyoEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TSharyoEditForm *SharyoEditForm;
//---------------------------------------------------------------------------
__fastcall TSharyoEditForm::TSharyoEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::FormShow(TObject *Sender)
{
	DM->AddComboMap(UseDivComboBox, use_div_map_, "SELECT �敪�R�[�h AS �R�[�h, �敪���� AS ���� FROM M_�敪 WHERE �敪���ރR�[�h = 10 ORDER BY �敪�R�[�h");

      if (id_ == 0){
            SetMode(imNew);
            CarNoEdit->SetFocus();
      }else{
            SetMode(imMod);
            SharyoNameEdit->SetFocus();
      }

	ClearForm(0);
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

	is_edit_ = false;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];

	toku_ = AnsiReplaceStr(ToString(DM->config_["���Ӑ�}�X�^����"]), " ", "");
	toku_ = AnsiReplaceStr(toku_, "�@", "");
	item1_ = AnsiReplaceStr(ToString(DM->config_["����1�}�X�^����"]), " ", "");
	item1_ = AnsiReplaceStr(item1_, "�@", "");
	item2_ = AnsiReplaceStr(ToString(DM->config_["����2�}�X�^����"]), " ", "");
	item2_ = AnsiReplaceStr(item2_, "�@", "");
	hin_ = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]), " ", "");
	hin_ = AnsiReplaceStr(hin_, "�@", "");
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall TSharyoEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::ClearForm(int n)
{
	CarNoEdit->Text             = AnsiString();
	SharyoNameEdit->Text        = AnsiString();
	EmptyWeightEdit->Text       = AnsiString();
	KasekisaiEdit->Text         = AnsiString();
	SharyoGrossWeightEdit->Text = AnsiString();
	TokuisakiCodeEdit->Text     = AnsiString();
	Item1CodeEdit->Text         = AnsiString();
	Item2CodeEdit->Text         = AnsiString();
	HinmokuCodeEdit->Text       = AnsiString();
      CardNoEdit->Text            = AnsiString();
      UseDivComboBox->ItemIndex   = 1;

	RenewDateEdit->Text  = AnsiString();
	CreateDateEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption = "�V�K";
		ModePanel->Color = TColor(NEW_CLR);
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "�C��";
		ModePanel->Color = TColor(MOD_CLR);
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled = true;
		Action8->Enabled = true;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TSharyoEditForm::CheckEdit()
{
	if (CarNoEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("�R�[�h�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		CarNoEdit->SetFocus();
		return false;
	}

      // �J�[�h�ԍ��d���`�F�b�N
      if (CardNoEdit->Text != "" && CardNoEdit->Text.ToIntDef(0) != 0){
            if (id_ != 0){ /////// �C��

                  NsRecordSet set;
                  AnsiString sql;
                  sql = " SELECT"
                        "     *"
                        " FROM"
                        "     M_�ԗ�"
                        " WHERE"
                        "     �J�[�h�ԍ� = " + IntToStr(CardNoEdit->Text.ToIntDef(0)) +
                        " AND"
                        "     �ԗ�ID <> " + IntToStr(id_);
                  if (DM->DBI.GetRecordSet(sql, set)){
                        Application->MessageBox("�J�[�h�ԍ����d�����Ă��܂�\r\n�ʂ̔ԍ���I�����Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
                        CardNoEdit->SetFocus();
                        return false;
                  }

            }else{         /////// �V�K

                  if (DM->DBI.IsExist("M_�ԗ�", "�J�[�h�ԍ�", CardNoEdit->Text.ToIntDef(0))){
                        Application->MessageBox("�J�[�h�ԍ����d�����Ă��܂�\r\n�ʂ̔ԍ���I�����Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
                        CardNoEdit->SetFocus();
                        return false;
                  }

            }
      }

      if (SharyoNameEdit->Text.Length() > 20)
            SharyoNameEdit->Text = DM->TrimString(SharyoNameEdit->Text, 20);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TSharyoEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[�Ԕ�]",       CarNoEdit->Text.ToIntDef(0))
		   << NsField("[�ԗ�����]",   SharyoNameEdit->Text)
		   << NsField("[��ԏd��]",   StrToCurrDef(EmptyWeightEdit->Text, 0))
		   << NsField("[�ő�ύڗ�]", StrToCurrDef(KasekisaiEdit->Text, 0))
		   << NsField("[�ԗ����d��]", StrToCurrDef(SharyoGrossWeightEdit->Text, 0))
		   << NsField("[���Ӑ�ID]",   ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID", "�g�p�敪 = 1")))
		   << NsField("[����1ID]",    ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1ID", "�g�p�敪 = 1")))
		   << NsField("[����2ID]",    ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2ID", "�g�p�敪 = 1")))
		   << NsField("[�i��ID]",     ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID", "�g�p�敪 = 1")))
		   << NsField("[�g�p�敪]",   use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[�X�V����]",   Now());

      if (CardNoEdit->Text.ToIntDef(0) != 0)
            fields << NsField("[�J�[�h�ԍ�]", CardNoEdit->Text.ToIntDef(0));
      else
            fields << NsField("[�J�[�h�ԍ�]", Variant());

	try{
		if (id_ == 0){
			fields << NsField("[�쐬����]", Now());
			DM->DBI.Insert("M_�ԗ�", fields);
		}else{
			DM->DBI.Update("M_�ԗ�", "�ԗ�ID", id_, fields);
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
void __fastcall TSharyoEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�ԗ� WHERE �ԗ�ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm(0);
		id_ = 0;
		return;
	}

	id_                         = ToInt(set[0]["�ԗ�ID"]);
	CarNoEdit->Text             = ToString(set[0]["�Ԕ�"]);
	SharyoNameEdit->Text        = ToString(set[0]["�ԗ�����"]);
	EmptyWeightEdit->Text       = ToCurrency(set[0]["��ԏd��"]);
	KasekisaiEdit->Text         = ToCurrency(set[0]["�ő�ύڗ�"]);
	SharyoGrossWeightEdit->Text = ToCurrency(set[0]["�ԗ����d��"]);
	if (ToInt(set[0]["���Ӑ�R�[�h"]) == 0)
		TokuisakiCodeEdit->Text = AnsiString();
	else
		TokuisakiCodeEdit->Text = ToInt(set[0]["���Ӑ�R�[�h"]);
	if (ToInt(set[0]["����1�R�[�h"]) == 0)
		Item1CodeEdit->Text = AnsiString();
	else
		Item1CodeEdit->Text = ToInt(set[0]["����1�R�[�h"]);
	if (ToInt(set[0]["����2�R�[�h"]) == 0)
		Item2CodeEdit->Text = AnsiString();
	else
		Item2CodeEdit->Text = ToInt(set[0]["����2�R�[�h"]);
	if (ToInt(set[0]["�i�ڃR�[�h"]) == 0)
		HinmokuCodeEdit->Text = AnsiString();
	else
		HinmokuCodeEdit->Text = ToInt(set[0]["�i�ڃR�[�h"]);
      if (ToInt(set[0]["�J�[�h�ԍ�"]) == 0)
            CardNoEdit->Text = AnsiString();
      else
            CardNoEdit->Text = ToInt(set[0]["�J�[�h�ԍ�"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["�g�p�敪"]));

	RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm(0);
      is_edit_ = false;
      CarNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_�ԗ�", "�ԗ�ID", id_)){
            Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
      if (ToInt(DM->DBI.Lookup("M_�ԗ�", "�ԗ�ID", id_, "�g�p�敪")) != 0){

            if (Application->MessageBox("���̃f�[�^���g�p�o���Ȃ��Ȃ�܂��B��낵���ł����H\r\n�Ȃ��A�{���ɍ폜����ꍇ�͈�x���̏������s�Ȃ�����\r\n������x�폜�{�^�����N���b�N���ĉ�����",
                        "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet fields;
            try{
                  fields << NsField("[�g�p�敪]", 0);
                  DM->DBI.Update("M_�ԗ�", "�ԗ�ID", id_, fields);
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
            keys << NsField("[�ԗ�ID]", id_);
            try{
                  DM->DBI.Delete("M_�ԗ�", keys);
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
void __fastcall TSharyoEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == TokuisakiCodeEdit || ActiveControl == TokuisakiNameEdit)
		TokuisakiSearchButton->OnClick(NULL);

	if (ActiveControl == Item1CodeEdit || ActiveControl == Item1NameEdit)
		Item1SearchButton->OnClick(NULL);

	if (ActiveControl == Item2CodeEdit || ActiveControl == Item2NameEdit)
		Item2SearchButton->OnClick(NULL);

	if (ActiveControl == HinmokuCodeEdit || ActiveControl == HinmokuNameEdit)
		HinmokuSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Action5Execute(TObject *Sender)
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
			CarNoEdit->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		SharyoNameEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Sharyo->Bof)
		return;

	DM->M_Sharyo->Prior();
	id_ = DM->M_Sharyo->FieldByName("�ԗ�ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Sharyo->Eof)
		return;

	DM->M_Sharyo->Next();
	id_ = DM->M_Sharyo->FieldByName("�ԗ�ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::CarNoEditExit(TObject *Sender)
{
	if (CarNoEdit->Text == "")
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT �ԗ�ID FROM M_�ԗ� WHERE �Ԕ� = " + CarNoEdit->Text + " AND �g�p�敪 = 1", set))
		return;

	if (Application->MessageBox("����ԔԂ��o�^����Ă��܂��B\r\n�C�����[�h�ŊJ���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

    int car_id;
    if (set.size() > 1){
        SearchForm->Top              = Application->MainForm->Top + 50;
        SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
        SearchForm->based_sql        = " SELECT �Ԕ�, �ԗ�����, ���Ӑ於��, ����1����, ����2����, �i�ږ���, �J�[�h�ԍ�, ��ԏd��, �ԗ�ID FROM V_�ԗ� WHERE �Ԕ� = " + CarNoEdit->Text;
        SearchForm->orderby_sql      = " ORDER BY �Ԕ�";
        SearchForm->table_name       = " V_�ԗ�";
        SearchForm->list_->CommaText = " �Ԕ�, �ԗ�����, ���Ӑ於��, ����1����, ����2����, �i�ږ���";
        if (SearchForm->ShowModal() != mrOk)
            return;

        car_id = SearchForm->Query->FieldByName("�ԗ�ID")->AsInteger;
    }else{
        car_id = ToInt(set[0]["�ԗ�ID"]);
    }

	SetMode(imMod);
	id_ = car_id;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::TokuisakiCodeEditChange(TObject *Sender)
{
	if (TokuisakiCodeEdit->Text == ""){
		TokuisakiNameEdit->Text = AnsiString();
		return;
	}
	TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::TokuisakiSearchButtonClick(
	  TObject *Sender)
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
void __fastcall TSharyoEditForm::Item1CodeEditChange(TObject *Sender)
{
	if (Item1CodeEdit->Text == ""){
		Item1NameEdit->Text = AnsiString();
		return;
	}
	Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item1SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT ����1�R�[�h, ����1����, ����1�J�i FROM V_����1";
	SearchForm->orderby_sql      = " ORDER BY ����1�R�[�h";
	SearchForm->table_name       = " V_����1";
	SearchForm->list_->CommaText = " ����1�R�[�h,����1����,����1�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEdit->Text = SearchForm->Query->FieldByName("����1�R�[�h")->AsInteger;
	Item1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item2CodeEditChange(TObject *Sender)
{
	if (Item2CodeEdit->Text == ""){
		Item2NameEdit->Text = AnsiString();
		return;
	}
	Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item2SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT ����2�R�[�h, ����2����, ����2�J�i FROM V_����2";
	SearchForm->orderby_sql      = " ORDER BY ����2�R�[�h";
	SearchForm->table_name       = " V_����2";
	SearchForm->list_->CommaText = " ����2�R�[�h,����2����,����2�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEdit->Text = SearchForm->Query->FieldByName("����2�R�[�h")->AsInteger;
	Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	if (HinmokuCodeEdit->Text == ""){
		HinmokuNameEdit->Text = AnsiString();
		return;
	}
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i�ږ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::HinmokuSearchButtonClick(
	  TObject *Sender)
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
void __fastcall TSharyoEditForm::CarNoEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �ԔԂ���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::SharyoNameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �ԗ����̂���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::EmptyWeightEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  ��ԏd�ʂ���͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::KasekisaiEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �ߐύڏd�ʂ���͂��Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::TokuisakiCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + toku_ + "����͂��ĉ������B�i[F4] " + toku_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item1CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item1_ + "����͂��ĉ������B�i[F4] " + item1_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item2CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item2_ + "����͂��ĉ������B�i[F4] " + item2_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + hin_ + "����͂��ĉ������B�i[F4] " + hin_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::CardNoEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  �J�[�h�ԍ�����͂��Ă�������";

      if (DM->GetMode(ModePanel) != imNew)
            return;

      if (DM->DBI.IsExist("M_�ԗ�", "�J�[�h�ԍ�", CarNoEdit->Text.ToIntDef(0))){
            CardNoEdit->Text = AnsiString();
      }else{
            CardNoEdit->Text = CarNoEdit->Text.ToIntDef(0);
            CardNoEdit->SelectAll();
      }
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::CardNoButtonClick(TObject *Sender)
{
      CardNoEdit->Text = GetCardNo();
      CardNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  �g�p�敪��I�����Ă�������";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::UseDivComboBoxExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
int __fastcall TSharyoEditForm::GetCardNo()
{
      int code = 1;
      while (1){
            if (!DM->DBI.IsExist("M_�ԗ�", "�J�[�h�ԍ�", code))
                  break;
            code++;
      }

      if (code > 999999){
            Application->MessageBox("�o�^����������ɒB���܂����B\r\n����ȏ�o�^�ł��܂���B",
                  this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            return -1;
      }

      return code;
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::ShabanPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::ShabanPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

