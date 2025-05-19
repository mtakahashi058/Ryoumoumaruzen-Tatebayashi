//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "KanzanEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TKanzanEditForm *KanzanEditForm;
//---------------------------------------------------------------------------
__fastcall TKanzanEditForm::TKanzanEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::FormShow(TObject *Sender)
{
	ClearForm();

      if (id_ == 0){
            SetMode(imNew);
            TokuisakiCodeEdit->SetFocus();
      }else{
            SetMode(imMod);
            KanzanEdit->SetFocus();
      }

	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

	is_edit_  = true;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];

	toku_ = AnsiReplaceStr(ToString(DM->config_["���Ӑ�}�X�^����"]), " ", "");
	toku_ = AnsiReplaceStr(toku_, "�@", "");
	hin_  = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]), " ", "");
	hin_  = AnsiReplaceStr(hin_, "�@", "");
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
		if (ActiveControl->Tag != 0 && ActiveControl->Tag != 2){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
int __fastcall TKanzanEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::ClearForm()
{
      TokuisakiCodeEdit->Text = AnsiString();
      HinmokuCodeEdit->Text   = AnsiString();
      TaniCodeEdit->Text      = AnsiString();
	KanzanEdit->Text        = AnsiString();
	RenewDateEdit->Text     = AnsiString();
	CreateDateEdit->Text    = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption       = "�V�K";
		ModePanel->Color         = TColor(NEW_CLR);
		//TokuisakiCodeEdit->ReadOnly = false;
		//TokuisakiCodeEdit->Color = clWindow;
		//HinmokuCodeEdit->ReadOnly = false;
		//HinmokuCodeEdit->Color = clWindow;
		//TaniCodeEdit->ReadOnly = false;
		//TaniCodeEdit->Color = clWindow;
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled         = false;
		Action8->Enabled         = false;
	}else if (mode == imMod){
		ModePanel->Caption       = "�C��";
		ModePanel->Color         = TColor(MOD_CLR);
		//TokuisakiCodeEdit->ReadOnly = true;
		//TokuisakiCodeEdit->Color = clSilver;
		//HinmokuCodeEdit->ReadOnly = true;
		//HinmokuCodeEdit->Color = clSilver;
		//TaniCodeEdit->ReadOnly = true;
		//TaniCodeEdit->Color = clSilver;
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled         = true;
		Action8->Enabled         = true;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TKanzanEditForm::CheckEdit()
{
	if (HinmokuCodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("�i�ڂ������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		HinmokuCodeEdit->SetFocus();
		return false;
	}

	if (TaniCodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("�P�ʂ������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		TaniCodeEdit->SetFocus();
		return false;
	}

	if (StrToCurrDef(KanzanEdit->Text, 0) == 0){
		Application->MessageBox("���Z���������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		KanzanEdit->SetFocus();
		return false;
	}

      if (StrToCurrDef(KanzanEdit->Text, 0) > 99999999.99){
            Application->MessageBox("���Z���������ł�\r\n0�`99999999.99�̊ԂŐݒ肵�Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            KanzanEdit->SetFocus();
            return false;
      }

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TKanzanEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[���Ӑ�ID]",   ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID", "�g�p�敪 = 1")))
		   << NsField("[�i��ID]",     ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID", "�g�p�敪 = 1")))
		   << NsField("[�P��ID]",     ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID", "")))
		   << NsField("[���Z��]",     StrToCurrDef(KanzanEdit->Text, 0))
		   << NsField("[�X�V����]",   Now());

	try{
		if (id_ == 0){
			fields << NsField("[�쐬����]", Now());
			DM->DBI.Insert("M_���Z", fields);
		}else{
			DM->DBI.Update("M_���Z", "���ZID", id_, fields);
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
void __fastcall TKanzanEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_���Z WHERE ���ZID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                     = ToInt(set[0]["���ZID"]);
	TokuisakiCodeEdit->Text = ToInt(set[0]["���Ӑ�R�[�h"]);
	HinmokuCodeEdit->Text   = ToInt(set[0]["�i�ڃR�[�h"]);
	TaniCodeEdit->Text      = ToInt(set[0]["�P�ʃR�[�h"]);
	KanzanEdit->Text        = ToCurrency(set[0]["���Z��"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_���Z", "���ZID", id_)){
            Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
            if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H", "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet keys;
            keys << NsField("[���ZID]", id_);
            try{
                  DM->DBI.Delete("M_���Z", keys);
            }catch (Exception &e){
                  DM->ADOConnection->RollbackTrans();
                  Application->MessageBox(("�f�[�^�폜�Ɏ��s���܂���\r\n" + e.Message).c_str(), "�폜", MB_OK | MB_ICONWARNING);
                  return;
            }
            msg = "�f�[�^���폜���܂���";

      DM->ADOConnection->CommitTrans();
      MainForm->OpenQuery(page_, MainForm->order_);
      id_ = MainForm->query[page_]->FieldByName(keyfield_)->AsInteger;
      BrowseRecord();
      Application->MessageBox(msg.c_str(), "�폜", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == TokuisakiCodeEdit || ActiveControl == TokuisakiNameEdit)
		TokuisakiSearchButton->OnClick(NULL);

	if (ActiveControl == HinmokuCodeEdit || ActiveControl == HinmokuNameEdit)
		HinmokuSearchButton->OnClick(NULL);

	if (ActiveControl == TaniCodeEdit || ActiveControl == TaniNameEdit)
		TaniSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action5Execute(TObject *Sender)
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
			TokuisakiCodeEdit->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		KanzanEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Kanzan->Bof)
		return;

	DM->M_Kanzan->Prior();
	id_ = DM->M_Kanzan->FieldByName("���ZID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Kanzan->Eof)
		return;

	DM->M_Kanzan->Next();
	id_ = DM->M_Kanzan->FieldByName("���ZID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiCodeEditChange(TObject *Sender)
{
	TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiCodeEditExit(TObject *Sender)
{
    int tokuisaki_id, hinmoku_id, tani_id;
    tokuisaki_id = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
    hinmoku_id   = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID"));
    tani_id      = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID"));
    NsRecordSet set;
    AnsiString sql;
    sql = " SELECT"
          "     *"
          " FROM"
          "     M_���Z"
          " WHERE"
          "     ���Ӑ�ID = " + IntToStr(tokuisaki_id) +
          " AND"
          "     �i��ID = " + IntToStr(hinmoku_id) +
          " AND"
          "     �P��ID = " + IntToStr(tani_id);
          " AND"
          "     ���ZID <> " + IntToStr(id_);
    if (!DM->DBI.GetRecordSet(sql, set)){
        id_ = 0;
        SetMode(imNew);
        is_edit_ = false;
        KanzanEdit->Text     = AnsiString();
        RenewDateEdit->Text  = AnsiString();
      	CreateDateEdit->Text = AnsiString();
    }else{
        SetMode(imMod);
        id_                  = ToInt(set[0]["���ZID"]);
        KanzanEdit->Text     = ToCurrency(set[0]["���Z��"]);
      	RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
        CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
    }
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiSearchButtonClick(
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
void __fastcall TKanzanEditForm::TaniCodeEditChange(TObject *Sender)
{
	TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P�ʖ���", ""));
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TaniCodeEditExit(TObject *Sender)
{
/*
      if (TokuisakiCodeEdit->Text.ToIntDef(0) == 0 || HinmokuCodeEdit->Text.ToIntDef(0) == 0 || TaniCodeEdit->Text.ToIntDef(0) == 0)
            return;

      int tokuisaki_id, hinmoku_id, tani_id;
      tokuisaki_id = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
      hinmoku_id   = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID"));
      tani_id      = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID"));
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT"
            "     *"
            " FROM"
            "     M_���Z"
            " WHERE"
            "     ���Ӑ�ID = " + IntToStr(tokuisaki_id) +
            " AND"
            "     �i��ID = " + IntToStr(hinmoku_id) +
            " AND"
            "     �P��ID = " + IntToStr(tani_id);
            " AND"
            "     ���ZID <> " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set))
            return;

      if (Application->MessageBox("����R�[�h���o�^����Ă��܂��B\r\n�C�����[�h�ŌĂяo���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

	SetMode(imMod);
	id_ = ToInt(set[0]["���ZID"]);
	BrowseRecord();
*/
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TaniSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P��";
	SearchForm->orderby_sql      = " ORDER BY �P�ʃR�[�h";
	SearchForm->table_name       = " M_�P��";
	SearchForm->list_->CommaText = " �P�ʃR�[�h,�P�ʗ���";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TaniCodeEdit->Text = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
	TaniCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i�ږ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::HinmokuSearchButtonClick(
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
void __fastcall TKanzanEditForm::KanzanEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  ���Z������͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + toku_ + "����͂��ĉ������B�i[F4] " + toku_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TaniCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �P�ʂ���͂��ĉ������B�i[F4] �P�ʌ������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + hin_ + "����͂��ĉ������B�i[F4] " + hin_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TKanzanEditForm::TokuisakiPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

