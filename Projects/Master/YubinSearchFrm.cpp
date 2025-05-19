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
		KenListBox->Items->Add(set[i]["“s“¹•{Œ§–¼"]);
}
//---------------------------------------------------------------------------
void __fastcall TYubinSearchForm::GetRecord(NsRecordSet &set, AnsiString target)
{
	AnsiString sql = AnsiString();
	if (target == "ken"){
		sql =	" SELECT"
			" 	“s“¹•{Œ§–¼"
			" FROM"
			" 	M_—X•Ö”Ô†"
			" GROUP BY"
			" 	“s“¹•{Œ§–¼, “s“¹•{Œ§–¼ƒJƒi"
			" ORDER BY"
			" 	“s“¹•{Œ§–¼ƒJƒi";
	}else if (target == "si"){
		sql =	" SELECT"
			" 	Žs‹æ’¬‘º–¼"
			" FROM"
			" 	M_—X•Ö”Ô†"
			" WHERE"
			" 	“s“¹•{Œ§–¼ = '" + KenListBox->Items->Strings[KenListBox->ItemIndex] + "'"
			" GROUP BY"
			" 	“s“¹•{Œ§–¼, Žs‹æ’¬‘º–¼, “s“¹•{Œ§–¼ƒJƒi, Žs‹æ’¬‘º–¼ƒJƒi"
			" ORDER BY"
			" 	“s“¹•{Œ§–¼ƒJƒi, Žs‹æ’¬‘º–¼ƒJƒi";
	}else if (target == "tyouiki"){
		sql =	" SELECT"
			" 	’¬ˆæ–¼"
			" FROM"
			" 	M_—X•Ö”Ô†"
			" WHERE"
			" 	“s“¹•{Œ§–¼ = '" + KenListBox->Items->Strings[KenListBox->ItemIndex] + "'"
			" AND"
			" 	Žs‹æ’¬‘º–¼ = '" + SiListBox->Items->Strings[SiListBox->ItemIndex] + "'"
			" GROUP BY"
			" 	“s“¹•{Œ§–¼, Žs‹æ’¬‘º–¼, ’¬ˆæ–¼, “s“¹•{Œ§–¼ƒJƒi, Žs‹æ’¬‘º–¼ƒJƒi, ’¬ˆæ–¼ƒJƒi"
			" ORDER BY"
			" 	“s“¹•{Œ§–¼ƒJƒi, Žs‹æ’¬‘º–¼ƒJƒi, ’¬ˆæ–¼ƒJƒi";
	}else if (target == "yubin"){
		sql =	" SELECT"
			" 	—X•Ö”Ô†"
			" FROM"
			" 	M_—X•Ö”Ô†"
			" WHERE"
			" 	“s“¹•{Œ§–¼ = '" + KenListBox->Items->Strings[KenListBox->ItemIndex] + "'"
			" AND"
			" 	Žs‹æ’¬‘º–¼ = '" + SiListBox->Items->Strings[SiListBox->ItemIndex] + "'"
			" AND"
			" 	’¬ˆæ–¼ = '" + TyouikiListBox->Items->Strings[TyouikiListBox->ItemIndex] + "'";
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
		SiListBox->Items->Add(set[i]["Žs‹æ’¬‘º–¼"]);
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
		TyouikiListBox->Items->Add(set[i]["’¬ˆæ–¼"]);
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
		YubinEdit->Text = set[0]["—X•Ö”Ô†"];
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
