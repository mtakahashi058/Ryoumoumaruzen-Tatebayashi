//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "DetailFrm.h"
#include <StrUtils.hpp>
#include <SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "StrCGrid"
#pragma resource "*.dfm"
TDetailForm *DetailForm;
//---------------------------------------------------------------------------
__fastcall TDetailForm::TDetailForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormShow(TObject *Sender)
{
	ClearForm();

	if (id_ == 0){
		SetMode(imNew);
	}else{
		BrowseRecord(id_);
		SetMode(imMod);
	}

	DateEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall TDetailForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == DateEdit){
		if (GetMode() == imMod)
			return;
		DatePicker->SetFocus();
		keybd_event(VK_F4, 0, 0, 0);
	}else if (ActiveControl == KyotenCodeEdit || ActiveControl == KyotenNameEdit){
		KyotenSearchButton->Click();
	}else if (ActiveControl == SeikyusakiCodeEdit || ActiveControl == SeikyusakiNameEdit){
		SeikyusakiSearchButton->Click();
	}else if (ActiveControl == BankCodeEdit || ActiveControl == BankNameEdit){
		BankSearchButton->Click();
	}else if (ActiveControl == KijituEdit){
		if (TegataEdit->Text == "")
			return;
		KijituPicker->SetFocus();
		keybd_event(VK_F4, 0, 0, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("�o�^���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	if (GetMode() == imNew){
		if (RenzokuCheckBox->Checked)
			ClearForm();
		else
			ModalResult = mrOk;
	}else{
		BrowseRecord(id_);
	}

	KyotenCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::Action12Execute(TObject *Sender)
{
	if (RenzokuCheckBox->Checked || GetMode() == imMod)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
TInputMode __fastcall TDetailForm::GetMode()
{
	if (ModePanel->Caption == "�V�K")
		return imNew;
	else if (ModePanel->Caption == "�C��")
		return imMod;
	else if (ModePanel->Caption == "�폜")
		return imDel;
	else
		return imNon;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption = "�V�K";
		ModePanel->Color = TColor(NEW_CLR);
		SlipNoEdit->ReadOnly = false;
		SlipNoEdit->Color = clWindow;
		RenzokuCheckBox->Enabled = true;
	}else if (mode == imMod){
		ModePanel->Caption = "�C��";
		ModePanel->Color = TColor(MOD_CLR);
		SlipNoEdit->ReadOnly = true;
		SlipNoEdit->Color = clSilver;
		RenzokuCheckBox->Checked = false;
		RenzokuCheckBox->Enabled = false;
	}else if (mode == imDel){
		ModePanel->Caption = "�폜";
		ModePanel->Color = TColor(DEL_CLR);
	}
}
//---------------------------------------------------------------------------
int __fastcall TDetailForm::GetNo()
{
	int id = ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", KyotenCodeEdit->Text.ToIntDef(0), "���_ID", ""));

	AnsiString sql = "SELECT ISNULL(MAX(�`�[No), 0) + 1 AS �`�[�ԍ� FROM D_���� WHERE ���_ID = " + IntToStr(id);
	NsRecordSet set;

	if (DM->DBI.GetRecordSet(sql, set))
		return ToInt(set[0]["�`�[�ԍ�"]);
	else
		return 1;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::ClearForm()
{
	KyotenCodeEdit->Text = ToInt(DM->INI["Place::Code"]);

	SlipNoEdit->Text = GetNo();
	DateEdit->Text   = DateToStr(Date());
	DatePicker->Date = Date();

	SeikyusakiCodeEdit->Text = AnsiString();

	GenkinEdit->Text   = AnsiString();
	HurikomiEdit->Text = AnsiString();
	TesuryoEdit->Text  = AnsiString();
	KogitteEdit->Text  = AnsiString();
	TegataEdit->Text   = AnsiString();
	SousaiEdit->Text   = AnsiString();
	NebikiEdit->Text   = AnsiString();
	ChoseiEdit->Text   = AnsiString();
	SonotaEdit->Text   = AnsiString();
	GokeiEdit->Text    = AnsiString();

	BankCodeEdit->Text    = AnsiString();
	KijituEdit->Text      = AnsiString();
	KijituEdit->ReadOnly  = true;
	KijituEdit->Color     = clSilver;
	KijituPicker->Date    = Date();
	KijituPicker->Enabled = false;
	BikoEdit->Text        = AnsiString();

	RenewDateLabel->Caption  = AnsiString();
	CreateDateLabel->Caption = AnsiString();

	NyukinDatePicker->Date = Date();
	NyukinDatePicker->OnChange(NULL);

	for (int i = 1; i < 8; i++){
		StrColGrid->Cells[0][i] = AnsiString();
		StrColGrid->Cells[1][i] = AnsiString();
		StrColGrid->Cells[2][i] = AnsiString();
		StrColGrid->Cells[3][i] = AnsiString();
		StrColGrid->Cells[4][i] = AnsiString();
		StrColGrid->Cells[5][i] = AnsiString();
		StrColGrid->Cells[6][i] = AnsiString();
		StrColGrid->Cells[7][i] = AnsiString();
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BrowseRecord(int id)
{
	AnsiString sql = AnsiString();
	sql =
		" SELECT"
		" 	���_�R�[�h,"
		" 	�`�[No,"
		" 	������,"
		" 	������R�[�h,"
		" 	����,"
		" 	�U��,"
		" 	�萔��,"
		" 	���؎�,"
		" 	��`,"
		" 	���E,"
		" 	�l����,"
		" 	����,"
		" 	���̑�,"
		" 	��s�R�[�h,"
		" 	��`����,"
		" 	���l,"
		" 	�X�V����,"
		" 	�쐬����"
		" FROM"
		" 	V_����"
		" WHERE"
		" 	����ID = " + IntToStr(id);
	NsRecordSet set;

	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("�Y������f�[�^��������܂���ł���",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	KyotenCodeEdit->Text     = ToInt(set[0]["���_�R�[�h"]);
	SlipNoEdit->Text         = ToInt(set[0]["�`�[No"]);
	DateEdit->Text           = IntToDate(ToInt(set[0]["������"]));
	DatePicker->Date         = IntToDate(ToInt(set[0]["������"]));
	if (ToInt(set[0]["��s�R�[�h"]))
		BankCodeEdit->Text = ToInt(set[0]["��s�R�[�h"]);
	else
		BankCodeEdit->Text = AnsiString();
	SeikyusakiCodeEdit->Text = ToInt(set[0]["������R�[�h"]);
	if (ToCurrency(set[0]["����"]) != 0)
		GenkinEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["����"]));
	else
		GenkinEdit->Text = AnsiString();
	if (ToCurrency(set[0]["�U��"]) != 0)
		HurikomiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["�U��"]));
	else
		HurikomiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["�萔��"]) != 0)
		TesuryoEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["�萔��"]));
	else
		TesuryoEdit->Text = AnsiString();
	if (ToCurrency(set[0]["���؎�"]) != 0)
		KogitteEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["���؎�"]));
	else
		KogitteEdit->Text = AnsiString();
	if (ToCurrency(set[0]["��`"]) != 0)
		TegataEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["��`"]));
	else
		TegataEdit->Text = AnsiString();
	if (ToCurrency(set[0]["���E"]) != 0)
		SousaiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["���E"]));
	else
		SousaiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["�l����"]) != 0)
		NebikiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["�l����"]));
	else
		NebikiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["����"]) != 0)
		ChoseiEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["����"]));
	else
		ChoseiEdit->Text = AnsiString();
	if (ToCurrency(set[0]["���̑�"]) != 0)
		SonotaEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["���̑�"]));
	else
		SonotaEdit->Text = AnsiString();
	GenkinEdit->OnExit(NULL);

	if (!set[0]["��`����"].IsNull()){
		KijituEdit->Text   = IntToDate(ToInt(set[0]["��`����"]));
		KijituPicker->Date = IntToDate(ToInt(set[0]["��`����"]));
	}else{
		KijituEdit->Text   = AnsiString();
		KijituPicker->Date = DateToStr(Date());
	}
	BikoEdit->Text = ToString(set[0]["���l"]);

	RenewDateLabel->Caption  = VarToDateTime(set[0]["�X�V����"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateLabel->Caption = VarToDateTime(set[0]["�쐬����"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
bool __fastcall TDetailForm::CheckEdit()
{
	if (KyotenCodeEdit->Text == ""){
		Application->MessageBox("���_�������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		KyotenCodeEdit->SetFocus();
		return false;
	}

	if (SlipNoEdit->Text == ""){
		Application->MessageBox("�`�[�ԍ��������ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		SlipNoEdit->SetFocus();
		return false;
	}

	TDateTime dt;
	try{
		dt = StrToDate(DateEdit->Text);
	}catch (Exception &e){
		Application->MessageBox(("���t���ē��͂��ĉ�����\r\n" + e.Message).c_str(),
			"�y���t�ƔF���ł��Ȃ����́z", MB_OK | MB_ICONWARNING);
		DateEdit->Text = DateToStr(Date());
		DateEdit->SetFocus();
		return false;
	}
	if (DateToInt(dt) < 17520914 || DateToInt(dt) > 99991231){
		Application->MessageBox("���t���ē��͂��ĉ�����",
			"�y���t�ƔF���ł��Ȃ����́z", MB_OK | MB_ICONWARNING);
		DateEdit->Text = DateToStr(Date());
		DateEdit->SetFocus();
		return false;
	}

	if (SeikyusakiCodeEdit->Text == ""){
		Application->MessageBox("�����悪�����ł�", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		SeikyusakiCodeEdit->SetFocus();
		return false;
	}

	if (!KijituEdit->ReadOnly){
		try{
			dt = StrToDate(KijituEdit->Text);
		}catch (Exception &e){
			Application->MessageBox(("���t���ē��͂��ĉ�����\r\n" + e.Message).c_str(),
				"�y���t�ƔF���ł��Ȃ����́z", MB_OK | MB_ICONWARNING);
			KijituEdit->Text = DateToStr(Date());
			KijituEdit->SetFocus();
			return false;
		}
		if (DateToInt(dt) < 17520914 || DateToInt(dt) > 99991231){
			Application->MessageBox("���t���ē��͂��ĉ�����",
				"�y���t�ƔF���ł��Ȃ����́z", MB_OK | MB_ICONWARNING);
			KijituEdit->Text = DateToStr(Date());
			KijituEdit->SetFocus();
			return false;
		}
	}

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TDetailForm::PostRecord()
{
	NsFieldSet fields;

	try{
		DM->ADOConnection->BeginTrans();

		fields
			<< NsField("[���_ID]",   ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", KyotenCodeEdit->Text.ToIntDef(0), "���_ID", "")))
			<< NsField("[������]",   RemoveSlash(DateEdit->Text))
			<< NsField("[������ID]", ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID", "")))
			<< NsField("[����]",     StrToCurrDef(AnsiReplaceStr(GenkinEdit->Text, ",", ""), 0))
			<< NsField("[�U��]",     StrToCurrDef(AnsiReplaceStr(HurikomiEdit->Text, ",", ""), 0))
			<< NsField("[�萔��]",   StrToCurrDef(AnsiReplaceStr(TesuryoEdit->Text, ",", ""), 0))
			<< NsField("[���؎�]",   StrToCurrDef(AnsiReplaceStr(KogitteEdit->Text, ",", ""), 0))
			<< NsField("[��`]",     StrToCurrDef(AnsiReplaceStr(TegataEdit->Text, ",", ""), 0))
			<< NsField("[���E]",     StrToCurrDef(AnsiReplaceStr(SousaiEdit->Text, ",", ""), 0))
			<< NsField("[�l����]",   StrToCurrDef(AnsiReplaceStr(NebikiEdit->Text, ",", ""), 0))
			<< NsField("[����]",     StrToCurrDef(AnsiReplaceStr(ChoseiEdit->Text, ",", ""), 0))
			<< NsField("[���̑�]",   StrToCurrDef(AnsiReplaceStr(SonotaEdit->Text, ",", ""), 0))
			<< NsField("[���l]",     BikoEdit->Text)
			<< NsField("[�X�V����]", Now());

		if (BankCodeEdit->Text != "")
			fields << NsField("[��sID]", ToInt(DM->DBI.Lookup("M_��s", "��s�R�[�h", BankCodeEdit->Text.ToIntDef(0), "��sID", "")));
		else
			fields << NsField("[��sID]", Variant());

		if (TegataEdit->Text != "")
			fields << NsField("[��`����]", RemoveSlash(KijituEdit->Text));
		else
			fields << NsField("[��`����]", Variant());

		if (id_ == 0){
			fields	<< NsField("[�`�[No]", GetNo())
				<< NsField("[�쐬����]", Now());
			DM->DBI.Insert("D_����", fields);
		}else{
			fields	<< NsField("[�`�[No]", SlipNoEdit->Text.ToIntDef(0));
			DM->DBI.Update("D_����", "����ID", id_, fields);
		}

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("�o�^�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SetSeikyuDate()
{
	if (SeikyusakiCodeEdit->Text == "")
		return;

	AnsiString sql = "SELECT MAX(�����\���) AS �����\��� FROM V_���� WHERE �����\��� <= " + RemoveSlash(DateEdit->Text) + " AND ������ID = " + ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "���Ӑ�ID", ""));
	NsRecordSet set;
	if (!DM->DBI.GetRecordSet(sql, set)){
		NyukinDatePicker->Date = Date();
		return;
	}

	if (set[0]["�����\���"].IsNull()){
		NyukinDatePicker->Date = Date();
		return;
	}

	NyukinDatePicker->Date = IntToDate(ToInt(set[0]["�����\���"]));
	NyukinDatePicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DateEditEnter(TObject *Sender)
{
	DateEdit->Text = AnsiReplaceStr(DateEdit->Text, "/", "");
	DateEdit->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DateEditExit(TObject *Sender)
{
	if (DateEdit->Text.AnsiPos("/") == 0)
		DateEdit->Text = IntToDate(DateEdit->Text.ToIntDef(0));

	try{
		DatePicker->Date = StrToDate(DateEdit->Text);
	}catch (...){
		DatePicker->Date = Date();
	}

	SetSeikyuDate();

	if (GetMode() == imMod)
		return;

	SlipNoEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DateMaskEditExit(TObject *Sender)
{
/*
	try{
		DatePicker->Date = StrToDate(DateMaskEdit->Text);
	}catch (...){
		DatePicker->Date = Date();
	}

	if (GetMode() == imMod)
		return;

	SlipNoEdit->Text = GetNo();
*/
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerChange(TObject *Sender)
{
	try{
		DateEdit->Text = DateToStr(DatePicker->Date);
	}catch (...){
		DateEdit->Text = DateToStr(Date());
	}

	SetSeikyuDate();

	if (GetMode() == imMod)
		return;

	SlipNoEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerCloseUp(TObject *Sender)
{
	keybd_event(VK_TAB, 0, 0, 0);
//	SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerEnter(TObject *Sender)
{
	Action4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePickerExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SlipNoEditExit(TObject *Sender)
{
	if (DateEdit->Text == "" || SlipNoEdit->Text == "")
		return;

	AnsiString sql = "SELECT ����ID FROM D_���� WHERE ������ = " + RemoveSlash(DateEdit->Text) + " AND �`�[No = " + SlipNoEdit->Text;
	NsRecordSet set;
	if (!DM->DBI.GetRecordSet(sql, set))
		return;

	BrowseRecord(ToInt(set[0]["����ID"]));
	SetMode(imMod);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SaibanButtonClick(TObject *Sender)
{
	SlipNoEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KyotenCodeEditChange(TObject *Sender)
{
	if (KyotenCodeEdit->Text == ""){
		KyotenNameEdit->Text = AnsiString();
		return;
	}
	KyotenNameEdit->Text = ToString(DM->DBI.Lookup("M_���_", "���_�R�[�h", KyotenCodeEdit->Text.ToIntDef(0), "���_����", ""));
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KyotenSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = "SELECT ���_�R�[�h, ���_���� FROM M_���_";
	SearchForm->orderby_sql      = "ORDER BY ���_�R�[�h";
	SearchForm->table_name       = "M_���_";
	SearchForm->list_->CommaText = "���_�R�[�h,���_����";

	if (SearchForm->ShowModal() != mrOk)
		return;
	KyotenCodeEdit->Text = SearchForm->Query->FieldByName("���_�R�[�h")->AsInteger;
	KyotenCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SeikyusakiCodeEditChange(TObject *Sender)
{
	if (SeikyusakiCodeEdit->Text == ""){
		SeikyusakiNameEdit->Text = AnsiString();
		SiteLabel->Caption       = AnsiString();
		LastTesuryoLabel->Caption = "���O��̐U���萔�� -----�~";
		return;
	}

	// �U���萔��
	NsRecordSet set;
	DM->DBI.GetRecordSet("SELECT TOP 1 �萔�� FROM V_���� WHERE ������R�[�h = " + IntToStr(SeikyusakiCodeEdit->Text.ToIntDef(0)) + " AND �U�� <> 0 ORDER BY ������ DESC, �`�[No DESC", set);
	if (ToInt(set[0]["�萔��"]) != 0)
		LastTesuryoLabel->Caption = "���O��̐U���萔�� " + FormatFloat("#,##0", ToInt(set[0]["�萔��"])) + "�~";
	else
		LastTesuryoLabel->Caption = "���O��̐U���萔�� -----�~";
	
	try{
		SeikyusakiNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1"));
		AnsiString site = ToString(DM->DBI.Lookup("M_�敪", "�敪�R�[�h", DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "�����T�C�g", "�g�p�敪 = 1"), "�敪����", "�敪���ރR�[�h = 6"));
		AnsiString day  = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "������", "�g�p�敪 = 1"));
		SiteLabel->Caption = "�����T�C�g�F" + site + day + "��";
		SetSeikyuDate();
		NyukinDatePicker->OnChange(NULL);

		for (int i = 1; i < 8; i++){
			StrColGrid->Cells[0][i] = AnsiString();
			StrColGrid->Cells[1][i] = AnsiString();
			StrColGrid->Cells[2][i] = AnsiString();
			StrColGrid->Cells[3][i] = AnsiString();
			StrColGrid->Cells[4][i] = AnsiString();
			StrColGrid->Cells[5][i] = AnsiString();
			StrColGrid->Cells[6][i] = AnsiString();
			StrColGrid->Cells[7][i] = AnsiString();
		}
		AnsiString sql = AnsiString();
		NsRecordSet set;
		// �ߋ�6�����Ԃ̐����f�[�^�\��
		sql =
			" SELECT"
			" 	TOP 7"
			" 	���ؓ�,"
			" 	ISNULL(�O�񐿋��z, 0) AS �O�񐿋��z,"
			" 	ISNULL(��������z, 0) AS ��������z,"
			" 	ISNULL(���񒲐��z, 0) AS ���񒲐��z,"
			" 	ISNULL(����J�z�z, 0) AS ����J�z�z,"
			" 	ISNULL(���񔄏�z, 0) + ISNULL(�������Ŋz, 0) AS ���񔄏�z,"
			" 	ISNULL(���񐿋��z, 0) AS ���񐿋��z,"
			" 	�����\���"
			" FROM"
			" 	V_����"
			" WHERE"
			" 	���ؓ� BETWEEN " + GetFirstDate(IncMonth(Date(), -6)).FormatString("yyyymmdd") +
						 " AND " + GetLastDate(Date()).FormatString("yyyymmdd") +
			" AND"
			" 	���Ӑ�R�[�h = " + SeikyusakiCodeEdit->Text +
			" ORDER BY"
			" 	���ؓ� DESC";
		set.clear();
		if (!DM->DBI.GetRecordSet(sql, set))
			return;

		for (unsigned int i = 0; i < set.size(); i++){
			StrColGrid->Cells[0][i + 1] = IntToDate(ToInt(set[i]["���ؓ�"]));
			StrColGrid->Cells[1][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["�O�񐿋��z"]));
			StrColGrid->Cells[2][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["��������z"]));
			StrColGrid->Cells[3][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["���񒲐��z"]));
			StrColGrid->Cells[4][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["����J�z�z"]));
			StrColGrid->Cells[5][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["���񔄏�z"]));
			StrColGrid->Cells[6][i + 1] = FormatFloat("#,##0 ", ToCurrency(set[i]["���񐿋��z"]));
			StrColGrid->Cells[7][i + 1] = IntToDate(ToInt(set[i]["�����\���"]));
		}
	}catch (...){
		for (int i = 1; i < 8; i++){
			StrColGrid->Cells[0][i] = AnsiString();
			StrColGrid->Cells[1][i] = AnsiString();
			StrColGrid->Cells[2][i] = AnsiString();
			StrColGrid->Cells[3][i] = AnsiString();
			StrColGrid->Cells[4][i] = AnsiString();
			StrColGrid->Cells[5][i] = AnsiString();
			StrColGrid->Cells[6][i] = AnsiString();
			StrColGrid->Cells[7][i] = AnsiString();
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::SeikyusakiSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1";
	SearchForm->orderby_sql      = "ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name       = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
	SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BankCodeEditChange(TObject *Sender)
{
	if (BankCodeEdit->Text == ""){
		BankNameEdit->Text = AnsiString();
		SitenEdit->Text    = AnsiString();
		KouzaEdit->Text    = AnsiString();
		return;
	}
	BankNameEdit->Text = ToString(DM->DBI.Lookup("M_��s", "��s�R�[�h", BankCodeEdit->Text.ToIntDef(0), "��s����", ""));
	SitenEdit->Text    = ToString(DM->DBI.Lookup("M_��s", "��s�R�[�h", BankCodeEdit->Text.ToIntDef(0), "�x�X����", ""));
	KouzaEdit->Text    = ToString(DM->DBI.Lookup("M_��s", "��s�R�[�h", BankCodeEdit->Text.ToIntDef(0), "����", ""));
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BankSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = " SELECT ��s�R�[�h, ��s����, �x�X����, ���� FROM M_��s";
	SearchForm->orderby_sql      = " ORDER BY ��s�R�[�h";
	SearchForm->table_name       = "M_��s";
	SearchForm->list_->CommaText = "��s�R�[�h,��s����,�x�X����,����";

	if (SearchForm->ShowModal() != mrOk)
		return;
	BankCodeEdit->Text = SearchForm->Query->FieldByName("��s�R�[�h")->AsInteger;
	BankCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::GenkinEditExit(TObject *Sender)
{
	if (StrToCurrDef(AnsiReplaceStr(GenkinEdit->Text, ",", ""), 0) == 0  && StrToCurrDef(AnsiReplaceStr(HurikomiEdit->Text, ",", ""), 0) == 0 &&
		StrToCurrDef(AnsiReplaceStr(TesuryoEdit->Text, ",", ""), 0) == 0 && StrToCurrDef(AnsiReplaceStr(KogitteEdit->Text, ",", ""), 0) == 0  &&
		StrToCurrDef(AnsiReplaceStr(TegataEdit->Text, ",", ""), 0) == 0  && StrToCurrDef(AnsiReplaceStr(SousaiEdit->Text, ",", ""), 0) == 0   &&
		StrToCurrDef(AnsiReplaceStr(NebikiEdit->Text, ",", ""), 0) == 0  && StrToCurrDef(AnsiReplaceStr(ChoseiEdit->Text, ",", ""), 0) == 0   &&
		StrToCurrDef(AnsiReplaceStr(SonotaEdit->Text, ",", ""), 0) == 0)
		return;

	GokeiEdit->Text = FormatFloat("#,##0",
		StrToCurrDef(AnsiReplaceStr(GenkinEdit->Text, ",", ""), 0)  + StrToCurrDef(AnsiReplaceStr(HurikomiEdit->Text, ",", ""), 0) +
		StrToCurrDef(AnsiReplaceStr(TesuryoEdit->Text, ",", ""), 0) + StrToCurrDef(AnsiReplaceStr(KogitteEdit->Text, ",", ""), 0)  +
		StrToCurrDef(AnsiReplaceStr(TegataEdit->Text, ",", ""), 0)  + StrToCurrDef(AnsiReplaceStr(SousaiEdit->Text, ",", ""), 0)   +
		StrToCurrDef(AnsiReplaceStr(NebikiEdit->Text, ",", ""), 0)  + StrToCurrDef(AnsiReplaceStr(ChoseiEdit->Text, ",", ""), 0)   +
		StrToCurrDef(AnsiReplaceStr(SonotaEdit->Text, ",", ""), 0));

	((TCobEdit *)Sender)->Text = FormatFloat("#,###", StrToCurrDef(((TCobEdit *)Sender)->Text, 0));
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::TegataEditChange(TObject *Sender)
{
	if (TegataEdit->Text == ""){
		KijituEdit->ReadOnly = true;
		KijituEdit->Color = clSilver;
		KijituPicker->Enabled = false;
	}else{
		KijituEdit->ReadOnly = false;
		KijituEdit->Color = clWindow;
		KijituPicker->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituEditEnter(TObject *Sender)
{
	KijituEdit->Text = AnsiReplaceStr(KijituEdit->Text, "/", "");
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituEditExit(TObject *Sender)
{
	if (KijituEdit->Text == "")
		return;
	
	try{
		if (KijituEdit->Text.AnsiPos("/") == 0)
			KijituEdit->Text = IntToDate(KijituEdit->Text.ToIntDef(0));

		KijituPicker->Date = StrToDate(KijituEdit->Text);
	}catch (...){
		KijituPicker->Date = Date();
		KijituEdit->Text   = KijituPicker->Date;
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerChange(TObject *Sender)
{
	try{
		KijituEdit->Text = DateToStr(KijituPicker->Date);
	}catch (...){
		KijituEdit->Text = DateToStr(Date());
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerCloseUp(TObject *Sender)
{
	BikoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerEnter(TObject *Sender)
{
	Action4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::KijituPickerExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BikoEditKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	Action5->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::GenkinEditEnter(TObject *Sender)
{
	((TCobEdit *)Sender)->Text = AnsiReplaceStr(((TCobEdit *)Sender)->Text, ",", "");
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::BrowseSeikyuInfo()
{
	YoteigakuEdit->Text = "----------";
	NyukinEdit->Text    = "----------";
	SagakuEdit->Text    = "----------";

	if (SeikyusakiCodeEdit->Text == "")
		return;

	AnsiString from_date, to_date;
	from_date = RemoveSlash(DateToStr(GetFirstDate(NyukinDatePicker->Date)));
	to_date   = RemoveSlash(DateToStr(GetLastDate(NyukinDatePicker->Date)));
	NsRecordSet set;
	AnsiString sql =
		" SELECT"
		" 	TOP 1"
		" 	���Ӑ�R�[�h AS ������R�[�h,"
		" 	���񐿋��z,"
		" 	���ؓ�"
		" FROM"
		" 	V_����"
		" WHERE"
		" 	�����\��� BETWEEN " + from_date + " AND " + to_date +
		" AND"
		" 	���Ӑ�R�[�h = " + SeikyusakiCodeEdit->Text +
		" ORDER BY"
		" 	���ؓ� DESC";
	try{
		if (!DM->DBI.GetRecordSet(sql, set)){
			YoteigakuEdit->Text = "----------";
			NyukinEdit->Text    = "----------";
			SagakuEdit->Text    = "----------";
		}else{
			YoteigakuEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["���񐿋��z"]));

			sql =
				" SELECT"
				" 	������R�[�h,"
				" 	ISNULL(SUM(����), 0) + ISNULL(SUM(�U��), 0)   + ISNULL(SUM(�萔��), 0) + ISNULL(SUM(���؎�), 0) + ISNULL(SUM(��`), 0) +"
				" 	ISNULL(SUM(���E), 0) + ISNULL(SUM(�l����), 0) + ISNULL(SUM(����), 0)   + ISNULL(SUM(���̑�), 0) AS �����z"
				" FROM"
				" 	V_����"
				" WHERE"
				" 	������ > " + ToString(set[0]["���ؓ�"]) +
				" AND"
				" 	������R�[�h = " + SeikyusakiCodeEdit->Text +
				" GROUP BY"
				" 	������R�[�h";
			set.clear();
			DM->DBI.GetRecordSet(sql, set);

			NyukinEdit->Text = FormatFloat("#,##0", ToCurrency(set[0]["�����z"]));
			SagakuEdit->Text = FormatFloat("#,##0", StrToCurrDef(AnsiReplaceStr(YoteigakuEdit->Text, ",", ""), 0) - StrToCurrDef(AnsiReplaceStr(NyukinEdit->Text, ",", ""), 0));
		}
	}catch (...){
		YoteigakuEdit->Text = "----------";
		NyukinEdit->Text    = "----------";
		SagakuEdit->Text    = "----------";
	}
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::NyukinDatePickerChange(TObject *Sender)
{
	BrowseSeikyuInfo();
	StrColGrid->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::PriorButtonClick(TObject *Sender)
{
	NyukinDatePicker->Date = IncMonth(NyukinDatePicker->Date, -1);
	NyukinDatePicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::NextButtonClick(TObject *Sender)
{
	NyukinDatePicker->Date = IncMonth(NyukinDatePicker->Date, 1);
	NyukinDatePicker->OnChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::StrColGridDrawCell(TObject *Sender, int ACol,
	  int ARow, TRect &Rect, TGridDrawState State)
{
	if (ARow == 0)
		return;

	if (StrColGrid->Cells[7][ARow] == "")
		return;

	AnsiString nyukin = NyukinDatePicker->Date.FormatString("yyyymm");
	if (nyukin == RemoveSlash(StrColGrid->Cells[7][ARow]).SubString(1, 6)){
		if (DateToInt(StrToDate(StrColGrid->Cells[7][ARow])) <= DateToInt(DatePicker->Date)){
			StrColGrid->Canvas->Brush->Color = TColor(0x00D7CBFE);
			StrColGrid->Canvas->FillRect(Rect);
		}else{
			StrColGrid->Canvas->Brush->Color = clWhite;
			StrColGrid->Canvas->FillRect(Rect);
		}
	}else{
		StrColGrid->Canvas->Brush->Color = clWhite;
		StrColGrid->Canvas->FillRect(Rect);
	}

	UINT opt = 0;
	switch(ACol){
		case 0:
		case 7:
			opt = DT_VCENTER | DT_CENTER | DT_SINGLELINE;
			break;

		default:  //���l�͉E��
			opt = DT_VCENTER | DT_RIGHT | DT_SINGLELINE;
			break;
	}

	DrawText(StrColGrid->Canvas->Handle, StrColGrid->Cells[ACol][ARow].c_str(), -1, &Rect, opt);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TDetailForm::DatePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

