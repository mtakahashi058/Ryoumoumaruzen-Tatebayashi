//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "YubinSearchFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "CEdit"
#pragma link "CEdit"
#pragma link "CEdit"
#pragma link "CEdit"
#pragma resource "*.dfm"
TYubinSearchForm *YubinSearchForm;
//---------------------------------------------------------------------------
__fastcall TYubinSearchForm::TYubinSearchForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TYubinSearchForm::FormShow(TObject *Sender)
{
	KenListBox->Items->Clear();
	SiListBox->Items->Clear();
	TyouikiListBox->Items->Clear();
	YubinEdit->Text = AnsiString();

	FixButton->Enabled = false;

	NsRecordSet set;
	set.clear();
	GetRecord(set, "ken");
	if (set.size() < 1)
		return;
	for (unsigned int i = 0; i < set.size(); i++)
		KenListBox->Items->Add(set[i]["�s���{����"]);
}
//---------------------------------------------------------------------------
void __fastcall TYubinSearchForm::GetRecord(NsRecordSet &set, AnsiString target)
{
	AnsiString sql = AnsiString();
	if (target == "ken"){
		sql =	" SELECT"
			" 	�s���{����"
			" FROM"
			" 	M_�X�֔ԍ�"
			" GROUP BY"
			" 	�s���{����, �s���{�����J�i"
			" ORDER BY"
			" 	�s���{�����J�i";
	}else if (target == "si"){
		sql =	" SELECT"
			" 	�s�撬����"
			" FROM"
			" 	M_�X�֔ԍ�"
			" WHERE"
			" 	�s���{���� = '" + KenListBox->Items->Strings[KenListBox->ItemIndex] + "'"
			" GROUP BY"
			" 	�s���{����, �s�撬����, �s���{�����J�i, �s�撬�����J�i"
			" ORDER BY"
			" 	�s���{�����J�i, �s�撬�����J�i";
	}else if (target == "tyouiki"){
		sql =	" SELECT"
			" 	���於"
			" FROM"
			" 	M_�X�֔ԍ�"
			" WHERE"
			" 	�s���{���� = '" + KenListBox->Items->Strings[KenListBox->ItemIndex] + "'"
			" AND"
			" 	�s�撬���� = '" + SiListBox->Items->Strings[SiListBox->ItemIndex] + "'"
			" GROUP BY"
			" 	�s���{����, �s�撬����, ���於, �s���{�����J�i, �s�撬�����J�i, ���於�J�i"
			" ORDER BY"
			" 	�s���{�����J�i, �s�撬�����J�i, ���於�J�i";
	}else if (target == "yubin"){
		sql =	" SELECT"
			" 	�X�֔ԍ�"
			" FROM"
			" 	M_�X�֔ԍ�"
			" WHERE"
			" 	�s���{���� = '" + KenListBox->Items->Strings[KenListBox->ItemIndex] + "'"
			" AND"
			" 	�s�撬���� = '" + SiListBox->Items->Strings[SiListBox->ItemIndex] + "'"
			" AND"
			" 	���於 = '" + TyouikiListBox->Items->Strings[TyouikiListBox->ItemIndex] + "'";
	}else{}
	if (!DM->DBI.GetRecordSet(sql, set))
		set.clear();
}
//---------------------------------------------------------------------------
void __fastcall TYubinSearchForm::KenListBoxClick(TObject *Sender)
{
	if (KenListBox->ItemIndex == -1)
		return;

	SiListBox->Items->Clear();
	TyouikiListBox->Items->Clear();
	YubinEdit->Text = AnsiString();

	NsRecordSet set;
	set.clear();
	GetRecord(set, "si");
	if (set.size() < 1)
		return;
	for (unsigned int i = 0; i < set.size(); i++)
		SiListBox->Items->Add(set[i]["�s�撬����"]);
}
//---------------------------------------------------------------------------
void __fastcall TYubinSearchForm::SiListBoxClick(TObject *Sender)
{
	if (SiListBox->ItemIndex == -1)
		return;

	TyouikiListBox->Items->Clear();
	YubinEdit->Text = AnsiString();

	NsRecordSet set;
	set.clear();
	GetRecord(set, "tyouiki");
	if (set.size() < 1)
		return;
	for (unsigned int i = 0; i < set.size(); i++)
		TyouikiListBox->Items->Add(set[i]["���於"]);
}
//---------------------------------------------------------------------------
void __fastcall TYubinSearchForm::TyouikiListBoxClick(TObject *Sender)
{
	if (TyouikiListBox->ItemIndex == -1)
		return;

	NsRecordSet set;
	set.clear();
	GetRecord(set, "yubin");
	if (set.size() < 1)
		YubinEdit->Text = AnsiString();
	else
		YubinEdit->Text = set[0]["�X�֔ԍ�"];
}
//---------------------------------------------------------------------------
void __fastcall TYubinSearchForm::YubinEditChange(TObject *Sender)
{
	if (YubinEdit->Text == "")
		FixButton->Enabled = false;
	else
		FixButton->Enabled = true;
}
//---------------------------------------------------------------------------
