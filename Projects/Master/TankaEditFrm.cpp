//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "TankaEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TTankaEditForm *TankaEditForm;
//---------------------------------------------------------------------------
__fastcall TTankaEditForm::TTankaEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::FormShow(TObject *Sender)
{
    if (id_ == 0){
        SetMode(imNew);
        TokuisakiCodeEdit->SetFocus();
    }else{
        SetMode(imMod);
        TankaEdit->SetFocus();
    }

	ClearForm();
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

	is_edit_  = false;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];

	toku_  = AnsiReplaceStr(ToString(DM->config_["���Ӑ�}�X�^����"]), " ", "");
	toku_  = AnsiReplaceStr(toku_, "�@", "");
	hin_   = AnsiReplaceStr(ToString(DM->config_["�i�ڃ}�X�^����"]), " ", "");
	hin_   = AnsiReplaceStr(hin_, "�@", "");
	item1_ = AnsiReplaceStr(ToString(DM->config_["����1�}�X�^����"]), " ", "");
	item1_ = AnsiReplaceStr(item1_, "�@", "");
	item2_ = AnsiReplaceStr(ToString(DM->config_["����2�}�X�^����"]), " ", "");
    item2_ = AnsiReplaceStr(item2_, "�@", "");
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall TTankaEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::ClearForm()
{
	TokuisakiCodeEdit->Text = AnsiString();
	HinmokuCodeEdit->Text   = AnsiString();
	Item1CodeEdit->Text     = AnsiString();
	Item2CodeEdit->Text     = AnsiString();
	TaniCodeEdit->Text      = AnsiString();
	TankaEdit->Text         = AnsiString();
	RenewDateEdit->Text     = AnsiString();
	CreateDateEdit->Text    = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::SetMode(TInputMode mode)
{
    if (mode == imNew){
        ModePanel->Caption = "�V�K";
		ModePanel->Color   = TColor(NEW_CLR);
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "�C��";
		ModePanel->Color   = TColor(MOD_CLR);
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled = true;
		Action8->Enabled = true;
	}
}
//---------------------------------------------------------------------------
bool __fastcall TTankaEditForm::CheckEdit()
{
	if (TaniCodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("�P�ʂ������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		TaniCodeEdit->SetFocus();
		return false;
	}

	if (StrToCurrDef(TankaEdit->Text, 0) == 0){
		Application->MessageBox("�P���������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		TankaEdit->SetFocus();
		return false;
	}

    if (StrToCurrDef(TankaEdit->Text, 0) > 9999999999.999){
        Application->MessageBox("�P���������ł�\r\n0�`9999999999.999�̊ԂŐݒ肵�Ă�������", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        TankaEdit->SetFocus();
        return false;
    }

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TTankaEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[���Ӑ�ID]",   ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID", "�g�p�敪 = 1")))
		   << NsField("[�i��ID]",     ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID", "�g�p�敪 = 1")))
		   << NsField("[����1ID]",    ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1ID", "�g�p�敪 = 1")))
		   << NsField("[����2ID]",    ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2ID", "�g�p�敪 = 1")))
		   << NsField("[�P��ID]",     ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID", "")))
		   << NsField("[�P��]",     StrToCurrDef(TankaEdit->Text, 0))
		   << NsField("[�X�V����]",   Now());

	try{
		if (id_ == 0){
			fields << NsField("[�쐬����]", Now());
			DM->DBI.Insert("M_�P��", fields);
		}else{
			DM->DBI.Update("M_�P��", "�P��ID", id_, fields);
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
void __fastcall TTankaEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_�P�� WHERE �P��ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                     = ToInt(set[0]["�P��ID"]);
	TokuisakiCodeEdit->Text = ToInt(set[0]["���Ӑ�R�[�h"]);
	HinmokuCodeEdit->Text   = ToInt(set[0]["�i�ڃR�[�h"]);
	Item1CodeEdit->Text     = ToInt(set[0]["����1�R�[�h"]);
	Item2CodeEdit->Text     = ToInt(set[0]["����2�R�[�h"]);
	TaniCodeEdit->Text      = ToInt(set[0]["�P�ʃR�[�h"]);
	TankaEdit->Text         = ToCurrency(set[0]["�P��"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action1Execute(TObject *Sender)
{
    id_ = 0;
    SetMode(imNew);
    ClearForm();
    TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (!DM->DBI.IsExist("M_�P��", "�P��ID", id_)){
        Application->MessageBox("�Ώۃf�[�^���o�Ɏ��s���܂���", "�폜", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();

    if (Application->MessageBox("�{���ɍ폜���Ă���낵���ł����H", "�폜", MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    NsFieldSet keys;
    keys << NsField("[�P��ID]", id_);
    try{
        DM->DBI.Delete("M_�P��", keys);
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
void __fastcall TTankaEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == TokuisakiCodeEdit || ActiveControl == TokuisakiNameEdit)
		TokuisakiSearchButton->OnClick(NULL);

	if (ActiveControl == HinmokuCodeEdit || ActiveControl == HinmokuNameEdit)
		HinmokuSearchButton->OnClick(NULL);

	if (ActiveControl == Item1CodeEdit || ActiveControl == Item1NameEdit)
		Item1SearchButton->OnClick(NULL);

	if (ActiveControl == Item2CodeEdit || ActiveControl == Item2NameEdit)
		Item2SearchButton->OnClick(NULL);

	if (ActiveControl == TaniCodeEdit || ActiveControl == TaniNameEdit)
		TaniSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action5Execute(TObject *Sender)
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
		TankaEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Tanka->Bof)
		return;

	DM->M_Tanka->Prior();
	id_ = DM->M_Tanka->FieldByName("�P��ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Tanka->Eof)
		return;

	DM->M_Tanka->Next();
	id_ = DM->M_Tanka->FieldByName("�P��ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiCodeEditChange(TObject *Sender)
{
	TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiCodeEditExit(TObject *Sender)
{
    NsRecordSet set;
    AnsiString sql;
    int tokuisaki_id, hinmoku_id, item1_id, item2_id, tani_id;
    tokuisaki_id = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID"));
    hinmoku_id   = ToInt(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i��ID"));
    item1_id     = ToInt(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1ID"));
    item2_id     = ToInt(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2ID"));
    tani_id      = ToInt(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P��ID"));
    sql = " SELECT"
          "     *"
          " FROM"
          "     M_�P��"
          " WHERE"
          "     ���Ӑ�ID = " + IntToStr(tokuisaki_id) +
          " AND"
          "     �i��ID = " + IntToStr(hinmoku_id) +
          " AND"
          "     ����1ID = " + IntToStr(item1_id) +
          " AND"
          "     ����2ID = " + IntToStr(item2_id) +
          " AND"
          "     �P��ID = " + IntToStr(tani_id);
    if (!DM->DBI.GetRecordSet(sql, set)){
        id_ = 0;
        SetMode(imNew);
        TankaEdit->Text      = AnsiString();
        RenewDateEdit->Text  = AnsiString();
        CreateDateEdit->Text = AnsiString();
    }else{
        SetMode(imMod);
        id_                  = ToInt(set[0]["�P��ID"]);
        TankaEdit->Text      = ToCurrency(set[0]["�P��"]);
        RenewDateEdit->Text  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
        CreateDateEdit->Text = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
    }
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i, �Z��1, �Z��2, �d�b�ԍ� FROM V_���Ӑ�";
	SearchForm->orderby_sql      = " ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name       = " V_���Ӑ�";
	SearchForm->list_->CommaText = " ���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i,�Z��1,�Z��2,�d�b�ԍ�";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
	TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_�i��", "�i�ڃR�[�h", HinmokuCodeEdit->Text.ToIntDef(0), "�i�ږ���", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::HinmokuSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT �i�ڃR�[�h, �i�ږ���, �i�ڃJ�i FROM V_�i��";
	SearchForm->orderby_sql      = " ORDER BY �i�ڃR�[�h";
	SearchForm->table_name       = " V_�i��";
	SearchForm->list_->CommaText = " �i�ږ���, �i�ڃJ�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	HinmokuCodeEdit->Text = SearchForm->Query->FieldByName("�i�ڃR�[�h")->AsInteger;
	HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item1CodeEditChange(TObject *Sender)
{
	Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_����1", "����1�R�[�h", Item1CodeEdit->Text.ToIntDef(0), "����1����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item1SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT ����1�R�[�h, ����1����, ����1�J�i FROM V_����1";
	SearchForm->orderby_sql      = " ORDER BY ����1�R�[�h";
	SearchForm->table_name       = " V_����1";
	SearchForm->list_->CommaText = " ����1����, ����1�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEdit->Text = SearchForm->Query->FieldByName("����1�R�[�h")->AsInteger;
	Item1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item2CodeEditChange(TObject *Sender)
{
	Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_����2", "����2�R�[�h", Item2CodeEdit->Text.ToIntDef(0), "����2����", "�g�p�敪 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item2SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT ����2�R�[�h, ����2����, ����2�J�i FROM V_����2";
	SearchForm->orderby_sql      = " ORDER BY ����2�R�[�h";
	SearchForm->table_name       = " V_����2";
	SearchForm->list_->CommaText = " ����2����, ����2�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEdit->Text = SearchForm->Query->FieldByName("����2�R�[�h")->AsInteger;
	Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TaniCodeEditChange(TObject *Sender)
{
	TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_�P��", "�P�ʃR�[�h", TaniCodeEdit->Text.ToIntDef(0), "�P�ʖ���", ""));
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TaniSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT �P�ʃR�[�h, �P�ʖ��� FROM M_�P��";
	SearchForm->orderby_sql      = " ORDER BY �P�ʃR�[�h";
	SearchForm->table_name       = " M_�P��";
	SearchForm->list_->CommaText = " �P�ʃR�[�h,�P�ʖ���";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TaniCodeEdit->Text = SearchForm->Query->FieldByName("�P�ʃR�[�h")->AsInteger;
	TaniCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + toku_ + "����͂��ĉ������B�i[F4] " + toku_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + hin_ + "����͂��ĉ������B�i[F4] " + hin_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item1CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item1_ + "����͂��ĉ������B�i[F4] " + item1_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::Item2CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item2_ + "����͂��ĉ������B�i[F4] " + item2_ + "�������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TaniCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �P�ʂ���͂��ĉ������B�i[F4] �P�ʌ������s���܂��j";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TankaEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  �P������͂��ĉ�����";
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TTankaEditForm::TokuisakiPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

