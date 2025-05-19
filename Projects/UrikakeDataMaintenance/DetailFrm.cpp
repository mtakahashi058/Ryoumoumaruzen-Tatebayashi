//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DetailFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TDetailForm *DetailForm;
//---------------------------------------------------------------------------
__fastcall TDetailForm::TDetailForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// ShowModal
int __fastcall TDetailForm::ShowModalWithID(int id)
{
	id_ = id;
	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
// DetailForm->OnShow
void __fastcall TDetailForm::FormShow(TObject *Sender)
{
	if (id_ == 0){
		ClearForm(true);
		SetMode(imNew);
		SimekiribiMaskEdit->SetFocus();
	}else{
		BrowseRecord(id_);
		cedtZenSeikyu->SetFocus();
	}

	is_edit_ = false;

	post_count_ = 0;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	switch (Key){
	case VK_DOWN:
		if (ActiveControl->Tag != 99  && ActiveControl->Tag != 1){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_RETURN:
		if (ActiveControl->Tag != 99){
			keybd_event(VK_TAB, 0, 0, 0);
		}
		break;
	case VK_UP:
		if (ActiveControl->Tag != 1 && ActiveControl->Tag != 99){
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(VK_TAB, 0, 0, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
// �f�[�^��\������
void __fastcall TDetailForm::BrowseRecord(int id)
{
	NsRecordSet set;

	if (!DM->DBI.GetRecordSet("SELECT * FROM V_���| WHERE ���|ID = " + IntToStr(id), set)){
		SetMode(imNew);
		ClearForm(true);
		return;
	}
	SetMode(imMod);

	cedtID->Text             = set[0]["���|ID"];
	SimekiribiPicker->Date   = IntToDate(ToInt(set[0]["���ؓ�"]));
	SimekiribiMaskEdit->Text = DateToStr(SimekiribiPicker->Date);
	cedtSeikyuCode->Text     = set[0]["���Ӑ�R�[�h"];
	cedtZenSeikyu->Text      = set[0]["�O���c��"];
	cedtKonNyukin->Text      = set[0]["���������z"];
	cedtKonChosei->Text      = set[0]["���������z"];
	cedtKonKurikosi->Text    = set[0]["�����J�z�z"];
	cedtKonUriage->Text      = set[0]["��������z"];
	cedtKonShohizei->Text    = set[0]["��������Ŋz"];
	cedtKonSeikyu->Text      = set[0]["�����c��"];
}
//---------------------------------------------------------------------------
// id == 0 �̏ꍇ�ːV�K  id != 0 �̏ꍇ�ˏC��
bool __fastcall TDetailForm::PostRecord(int id)
{
	NsFieldSet keys;
	NsFieldSet fields;

	if (id != 0)
		keys << NsField("���|ID", id);

	fields << NsField("[���ؓ�]",       RemoveSlash(SimekiribiMaskEdit->Text).ToIntDef(0));
	fields << NsField("[������ID]",     DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", cedtSeikyuCode->Text.ToIntDef(0), "���Ӑ�ID", ""));
	fields << NsField("[�O���c��]",     StrToCurrDef(cedtZenSeikyu->Text, 0));
	fields << NsField("[���������z]",   StrToCurrDef(cedtKonNyukin->Text, 0));
	fields << NsField("[���������z]",   StrToCurrDef(cedtKonChosei->Text, 0));
	fields << NsField("[�����J�z�z]",   StrToCurrDef(cedtKonKurikosi->Text, 0));
	fields << NsField("[��������z]",   StrToCurrDef(cedtKonUriage->Text, 0));
	fields << NsField("[��������Ŋz]", StrToCurrDef(cedtKonShohizei->Text, 0));
	fields << NsField("[�����c��]",     StrToCurrDef(cedtKonSeikyu->Text, 0));
	fields << NsField("[�X�V����]",     Now());
	if (id == 0)
		fields << NsField("[�쐬����]", Now());

	try{
		if (id == 0)
			DM->DBI.Insert("D_���|", fields);
		else
			DM->DBI.Update("D_���|", keys, fields);

	}catch (Exception& e){
		Application->MessageBox(("�o�^�Ɏ��s���܂���\r\n�G���[�F" + e.Message).c_str(), "�o�^", MB_OK | MB_ICONSTOP);
		return false;
	}

	is_edit_ = true;
	post_count_++;
	return true;
}
//---------------------------------------------------------------------------
// �t�H�[���̃N���A
void __fastcall TDetailForm::ClearForm(bool date_clear)
{
	cedtID->Text = "0";
	if (date_clear){
		SimekiribiPicker->Date = Date();
		SimekiribiMaskEdit->Text = DateToStr(Date());
	}
	cedtSeikyuCode->Text = "";
	cedtSeikyuCode->OnChange(NULL);
	cedtZenSeikyu->Text = "";
	cedtKonNyukin->Text = "";
	cedtKonChosei->Text = "";
	cedtKonKurikosi->Text = "";
	cedtKonUriage->Text = "";
	cedtKonShohizei->Text = "";
	cedtKonSeikyu->Text = "";
}
//---------------------------------------------------------------------------
// ���[�h��ݒ肷��
void __fastcall TDetailForm::SetMode(TInputMode Mode)
{
	switch(Mode){
	case imNew:
		pnlMode->Caption = "�V�K";
		pnlMode->Color = clSkyBlue;
		break;
	case imMod:
		pnlMode->Caption = "�C��";
		pnlMode->Color = clMoneyGreen;
		break;
	case imDel:
		pnlMode->Caption = "�폜";
		pnlMode->Color = TColor(0x00E4DDFF);
		break;
	}
}
//---------------------------------------------------------------------------
// ���݂̃��[�h���擾����
TInputMode __fastcall TDetailForm::GetMode()
{
	if (pnlMode->Caption == "�V�K")
		return imNew;
	else if (pnlMode->Caption == "�C��")
		return imMod;
	else if (pnlMode->Caption == "�폜")
		return imDel;
	throw Exception("���̓��[�h���ُ�ł�");
}
//---------------------------------------------------------------------------
// ������R�[�h->OnChange
void __fastcall TDetailForm::cedtSeikyuCodeChange(TObject *Sender)
{
	cedtSeikyuName->Text = DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", cedtSeikyuCode->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1 AND ���Ӑ�ID = ������ID");
}
//---------------------------------------------------------------------------
// ����J�z�z���O�񐿋��z�|��������z�|���񒲐��z
void __fastcall TDetailForm::cedtZenSeikyuChange(TObject *Sender)
{
	cedtKonKurikosi->Text =	StrToCurrDef(cedtZenSeikyu->Text, 0) -
				StrToCurrDef(cedtKonNyukin->Text, 0) -
				StrToCurrDef(cedtKonChosei->Text, 0);
}
//---------------------------------------------------------------------------
// ���񐿋��z������J�z�z�{���񔄏�z�{�������Ŋz
void __fastcall TDetailForm::cedtKonUriageChange(TObject *Sender)
{
	int tax_rate     = DM->GetShohizeiritu(RemoveSlash(SimekiribiMaskEdit->Text));
	int tax_fraction = ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", cedtSeikyuCode->Text.ToIntDef(0), "����Œ[�������敪", ""));
	// ����Œ[�������敪��������Ȃ��ꍇ�A�u�؂�̂āv���f�t�H���g

	Currency money = StrToCurrDef(cedtKonUriage->Text, 0);
	Currency tax = 0;
	tax = money * tax_rate / 100;
	TaxLabel->Caption = AnsiString();

	if (tax != 0)
		tax = ExtendedRound(tax, 0, tax_fraction);

	cedtKonShohizei->Text = tax;

	cedtKonSeikyu->Text = 	StrToCurrDef(cedtKonKurikosi->Text, 0) +
				StrToCurrDef(cedtKonUriage->Text, 0) +
				StrToCurrDef(cedtKonShohizei->Text, 0);
}
//---------------------------------------------------------------------------
// �����挟��
void __fastcall TDetailForm::SanshoActionExecute(TObject *Sender)
{
	if (ActiveControl == SimekiribiMaskEdit){
		if (GetMode() == imMod)
			return;
		SimekiribiPicker->SetFocus();
		keybd_event(VK_F4, 0, 0, 0);
	}

	if (ActiveControl != cedtSeikyuCode && ActiveControl != cedtSeikyuName)
		return;
	btnSeikyu->OnClick(NULL);
}
//---------------------------------------------------------------------------
// �o�^����
void __fastcall TDetailForm::PostActionExecute(TObject *Sender)
{
	if (Application->MessageBox("�o�^���܂����H", "OK", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	NsRecordSet set;
	if (GetMode() == imNew){
		if (DM->DBI.GetRecordSet("SELECT * FROM V_���| WHERE ���ؓ� = " + RemoveSlash(SimekiribiMaskEdit->Text) + " AND ���Ӑ�R�[�h = " + IntToStr(cedtSeikyuCode->Text.ToIntDef(0)), set)){
			if (Application->MessageBox("�������ؓ��̔��|�f�[�^�����ɑ��݂��܂�\r\n�㏑���o�^���s���܂����H", "�d���`�F�b�N", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
				return;
			else
				cedtID->Text = set[0]["���|ID"];
		}
	}
	if (!PostRecord(cedtID->Text.ToIntDef(0)))
		return;

	if (RenzokuCheckBox->Checked){
		ClearForm(false);
		SimekiribiMaskEdit->SetFocus();
	}else{
		Close();
	}
}
//---------------------------------------------------------------------------
// �L�����Z��
void __fastcall TDetailForm::CloseActionExecute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::btnSeikyuClick(TObject *Sender)
{
	SearchForm->based_sql = " SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE �g�p�敪 = 1 AND ���Ӑ�ID = ������ID";
	SearchForm->orderby_sql = " ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	cedtSeikyuCode->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
	cedtSeikyuCode->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerChange(TObject *Sender)
{
	SimekiribiMaskEdit->Text = DateToStr(SimekiribiPicker->Date);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiMaskEditExit(TObject *Sender)
{
	SimekiribiPicker->Date = StrToDate(SimekiribiMaskEdit->Text);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerEnter(TObject *Sender)
{
	SanshoAction->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerExit(TObject *Sender)
{
	SanshoAction->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SimekiribiPickerCloseUp(TObject *Sender)
{
	cedtSeikyuCode->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::cedtKonSeikyuKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN)
		btnOk->OnClick(NULL);
}
//---------------------------------------------------------------------------

