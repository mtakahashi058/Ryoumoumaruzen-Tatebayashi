//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Item2SelectStateFrm.h"
#include "DMFrm.h"
#include <mmsystem.h>
#include "n24tp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TItem2SelectForm *Item2SelectForm;
//---------------------------------------------------------------------------
__fastcall TItem2SelectForm::TItem2SelectForm(TComponent* Owner)
	: AbstractStateForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::FormCreate(TObject *Sender)
{
	SFM.AddStateForm(State::SelectItem2, this);

	Buttons_[0]  = Item1Button;
	Buttons_[1]  = Item2Button;
	Buttons_[2]  = Item3Button;
	Buttons_[3]  = Item4Button;
	Buttons_[4]  = Item5Button;
	Buttons_[5]  = Item6Button;
	Buttons_[6]  = Item7Button;
	Buttons_[7]  = Item8Button;
	Buttons_[8]  = Item9Button;
	Buttons_[9]  = Item10Button;
	Buttons_[10] = Item11Button;
	Buttons_[11] = Item12Button;
	Buttons_[12] = Item13Button;
	Buttons_[13] = Item14Button;
	Buttons_[14] = Item15Button;
	Buttons_[15] = Item16Button;
	Buttons_[16] = Item17Button;
	Buttons_[17] = Item18Button;

	KanaButtons_[0] = Kana1Button;
	KanaButtons_[1] = Kana2Button;
	KanaButtons_[2] = Kana3Button;
	KanaButtons_[3] = Kana4Button;
	KanaButtons_[4] = Kana5Button;
	KanaButtons_[5] = Kana6Button;
	KanaButtons_[6] = Kana7Button;
	KanaButtons_[7] = Kana8Button;
	KanaButtons_[8] = Kana9Button;
	KanaButtons_[9] = Kana10Button;
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::OnEnter()
{
    TitlePanel->Caption = DM->TrimSpace(ToString(DM->CFG["項目2マスタ名称"])) + "を選択して下さい";

	SFM.AddLog("項目2選択画面 車両ID/車番: " + ToString(SFM.Stashed("車両ID")) + "/" + ToString(SFM.car_rec["車番"]));

	SFM.SendStatus(AnsiString());

	KanaButtons_[0]->Caption = N24TP::Kana(0);
	KanaButtons_[1]->Caption = N24TP::Kana(1);
	KanaButtons_[2]->Caption = N24TP::Kana(2);
	KanaButtons_[3]->Caption = N24TP::Kana(3);
	KanaButtons_[4]->Caption = N24TP::Kana(4);
	KanaButtons_[5]->Caption = N24TP::Kana(5);
	KanaButtons_[6]->Caption = N24TP::Kana(6);
	KanaButtons_[7]->Caption = N24TP::Kana(7);
	KanaButtons_[8]->Caption = N24TP::Kana(8);
	KanaButtons_[9]->Caption = N24TP::Kana(9);
	KanaButtons_[0]->Visible = true;
	KanaButtons_[1]->Visible = true;
	KanaButtons_[2]->Visible = true;
	KanaButtons_[3]->Visible = true;
	KanaButtons_[4]->Visible = true;
	KanaButtons_[5]->Visible = true;
	KanaButtons_[6]->Visible = true;
	KanaButtons_[7]->Visible = true;
	KanaButtons_[8]->Visible = true;
	KanaButtons_[9]->Visible = true;
	KanaBackButton->Visible  = false;

	AllocateRecordToButtons(0);

	PlaySound(ToString(DM->Sounds["Item2Select"]).c_str(), 0, SND_ASYNC | SND_FILENAME);
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::OnEvent(Event::EventID event, void *param)
{
	if (event == Event::ExitWeighing){
		SFM.Transit(State::Idle);
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::OnExit()
{
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::AllocateRecordToButtons(int top_rec_no, const AnsiString& kana1, const AnsiString& kana2)
{
	NsRecordSet set;
	DM->GetItem2Set(kana1, kana2, set);

	lefttop_rec_no_ = top_rec_no;
	int record_count = int(set.size());
	enable_count_ = 0;

	int len;
	int cur_rec_no;
	for (int i = 0; i < 18; i++){
		cur_rec_no = i + lefttop_rec_no_;

		if (cur_rec_no >= record_count){
			Buttons_[i]->Caption = AnsiString();
			Buttons_[i]->Tag     = 0;
			Buttons_[i]->Enabled = false;
		}else{
			len = ToString(set[cur_rec_no]["項目2略称"]).Length();
			if (len <= 20)
				Buttons_[i]->Font->Size = 16;
			else if (len <= 22)
				Buttons_[i]->Font->Size = 14;
			else if (len <= 26)
				Buttons_[i]->Font->Size = 12;
			else
				Buttons_[i]->Font->Size = 10;

			Buttons_[i]->Caption = ToString(set[cur_rec_no]["項目2略称"]);
			Buttons_[i]->Tag     = ToInt(set[cur_rec_no]["項目2ID"]);
			Buttons_[i]->Enabled = true;

			enable_count_++;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::CancelButtonClick(TObject *Sender)
{
	SFM.Transit(PrevState(SFM.GetCurrentStateID()));
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::Item1ButtonClick(TObject *Sender)
{
	SFM.stash["項目2ID"]     = dynamic_cast<TButton *>(Sender)->Tag;
	SFM.stash["項目2略称"]   = dynamic_cast<TButton *>(Sender)->Caption;

	SFM.Transit(NextState(SFM.GetCurrentStateID()));
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::ScrollUpButtonClick(TObject *Sender)
{
	int lefttop = lefttop_rec_no_;
	lefttop -= 3;
	lefttop = (lefttop < 0) ? 0 : lefttop;
	AllocateRecordToButtons(lefttop);
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::ScrollDownButtonClick(TObject *Sender)
{
	int lefttop = lefttop_rec_no_;
	lefttop += 3;
	AllocateRecordToButtons(lefttop);
	if (enable_count_ < 1)
		AllocateRecordToButtons(lefttop - 3);
}
//---------------------------------------------------------------------------
void __fastcall TItem2SelectForm::Kana1ButtonClick(TObject *Sender)
{
	int tag = dynamic_cast<TComponent *>(Sender)->Tag;

	AnsiString kana;
	enum KanaDisplayMode {kdmAll, kdmLine, kdmChar} kana_mode;

	if (Kana10Button->Visible)
		kana_mode = kdmAll;
	else if (Kana5Button->Visible)
		kana_mode = kdmLine;
	else
		kana_mode = kdmChar;

	if (tag != 99){
		kana = dynamic_cast<TButton *>(Sender)->Caption;
		if (kana.IsEmpty())
			return;
	}

	// 単音表示で戻るボタン以外の場合は、無効
	if (kana_mode == kdmChar && tag != 99)
		return;

	if (tag == 99){		// 戻るボタン
		if (kana_mode == kdmLine){
			Kana1Button->Caption  = N24TP::Kana(0);
			Kana2Button->Caption  = N24TP::Kana(1);
			Kana3Button->Caption  = N24TP::Kana(2);
			Kana4Button->Caption  = N24TP::Kana(3);
			Kana5Button->Caption  = N24TP::Kana(4);
			Kana6Button->Caption  = N24TP::Kana(5);
			Kana7Button->Caption  = N24TP::Kana(6);
			Kana8Button->Caption  = N24TP::Kana(7);
			Kana9Button->Caption  = N24TP::Kana(8);
			Kana10Button->Caption = N24TP::Kana(9);
			Kana1Button->Visible  = true;
			Kana2Button->Visible  = true;
			Kana3Button->Visible  = true;
			Kana4Button->Visible  = true;
			Kana5Button->Visible  = true;
			Kana6Button->Visible  = true;
			Kana7Button->Visible  = true;
			Kana8Button->Visible  = true;
			Kana9Button->Visible  = true;
			Kana10Button->Visible = true;
			KanaBackButton->Visible = false;
			AllocateRecordToButtons(0, AnsiString(), AnsiString());
		}else if (kana_mode == kdmChar){
			int line = N24TP::Kana.SearchLine(Kana1Button->Caption);
			Kana1Button->Caption = N24TP::Kana(line, 0);
			Kana2Button->Caption = N24TP::Kana(line, 1);
			Kana3Button->Caption = N24TP::Kana(line, 2);
			Kana4Button->Caption = N24TP::Kana(line, 3);
			Kana5Button->Caption = N24TP::Kana(line, 4);
			Kana1Button->Visible = true;
			Kana2Button->Visible = true;
			Kana3Button->Visible = true;
			Kana4Button->Visible = true;
			Kana5Button->Visible = true;
			AllocateRecordToButtons(0, N24TP::Kana(line, 0), N24TP::Kana(line, 4));
		}
		return;
	}

	if (kana_mode == kdmAll){
		int line = N24TP::Kana.SearchLine(kana);
		Kana1Button->Caption = N24TP::Kana(line, 0);
		Kana2Button->Caption = N24TP::Kana(line, 1);
		Kana3Button->Caption = N24TP::Kana(line, 2);
		Kana4Button->Caption = N24TP::Kana(line, 3);
		Kana5Button->Caption = N24TP::Kana(line, 4);
		Kana6Button->Caption = AnsiString();
		Kana7Button->Caption = AnsiString();
		Kana8Button->Caption = AnsiString();
		Kana9Button->Caption = AnsiString();
		Kana10Button->Caption = AnsiString();
		Kana1Button->Visible = true;
		Kana2Button->Visible = true;
		Kana3Button->Visible = true;
		Kana4Button->Visible = true;
		Kana5Button->Visible = true;
		Kana6Button->Visible = false;
		Kana7Button->Visible = false;
		Kana8Button->Visible = false;
		Kana9Button->Visible = false;
		Kana10Button->Visible = false;
		KanaBackButton->Visible = true;
		AllocateRecordToButtons(0, N24TP::Kana(line, 0), N24TP::Kana(line, 4));
	}else if (kana_mode == kdmLine){
		Kana1Button->Caption = kana;
		Kana2Button->Caption = AnsiString();
		Kana3Button->Caption = AnsiString();
		Kana4Button->Caption = AnsiString();
		Kana5Button->Caption = AnsiString();
		Kana6Button->Caption = AnsiString();
		Kana7Button->Caption = AnsiString();
		Kana8Button->Caption = AnsiString();
		Kana9Button->Caption = AnsiString();
		Kana10Button->Caption = AnsiString();
		Kana1Button->Visible = true;
		Kana2Button->Visible = false;
		Kana3Button->Visible = false;
		Kana4Button->Visible = false;
		Kana5Button->Visible = false;
		Kana6Button->Visible = false;
		Kana7Button->Visible = false;
		Kana8Button->Visible = false;
		Kana9Button->Visible = false;
		Kana10Button->Visible = false;
		KanaBackButton->Visible = true;
		AllocateRecordToButtons(0, kana, AnsiString());
	}
}
//---------------------------------------------------------------------------

