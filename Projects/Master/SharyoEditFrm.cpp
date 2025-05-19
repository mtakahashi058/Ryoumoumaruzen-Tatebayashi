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
	DM->AddComboMap(UseDivComboBox, use_div_map_, "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 10 ORDER BY 区分コード");

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

	toku_ = AnsiReplaceStr(ToString(DM->config_["得意先マスタ名称"]), " ", "");
	toku_ = AnsiReplaceStr(toku_, "　", "");
	item1_ = AnsiReplaceStr(ToString(DM->config_["項目1マスタ名称"]), " ", "");
	item1_ = AnsiReplaceStr(item1_, "　", "");
	item2_ = AnsiReplaceStr(ToString(DM->config_["項目2マスタ名称"]), " ", "");
	item2_ = AnsiReplaceStr(item2_, "　", "");
	hin_ = AnsiReplaceStr(ToString(DM->config_["品目マスタ名称"]), " ", "");
	hin_ = AnsiReplaceStr(hin_, "　", "");
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
		ModePanel->Caption = "新規";
		ModePanel->Color = TColor(NEW_CLR);
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "修正";
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
		Application->MessageBox("コードが無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		CarNoEdit->SetFocus();
		return false;
	}

      // カード番号重複チェック
      if (CardNoEdit->Text != "" && CardNoEdit->Text.ToIntDef(0) != 0){
            if (id_ != 0){ /////// 修正

                  NsRecordSet set;
                  AnsiString sql;
                  sql = " SELECT"
                        "     *"
                        " FROM"
                        "     M_車両"
                        " WHERE"
                        "     カード番号 = " + IntToStr(CardNoEdit->Text.ToIntDef(0)) +
                        " AND"
                        "     車両ID <> " + IntToStr(id_);
                  if (DM->DBI.GetRecordSet(sql, set)){
                        Application->MessageBox("カード番号が重複しています\r\n別の番号を選択してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
                        CardNoEdit->SetFocus();
                        return false;
                  }

            }else{         /////// 新規

                  if (DM->DBI.IsExist("M_車両", "カード番号", CardNoEdit->Text.ToIntDef(0))){
                        Application->MessageBox("カード番号が重複しています\r\n別の番号を選択してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
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

	fields << NsField("[車番]",       CarNoEdit->Text.ToIntDef(0))
		   << NsField("[車両名称]",   SharyoNameEdit->Text)
		   << NsField("[空車重量]",   StrToCurrDef(EmptyWeightEdit->Text, 0))
		   << NsField("[最大積載量]", StrToCurrDef(KasekisaiEdit->Text, 0))
		   << NsField("[車両総重量]", StrToCurrDef(SharyoGrossWeightEdit->Text, 0))
		   << NsField("[得意先ID]",   ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先ID", "使用区分 = 1")))
		   << NsField("[項目1ID]",    ToInt(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1ID", "使用区分 = 1")))
		   << NsField("[項目2ID]",    ToInt(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2ID", "使用区分 = 1")))
		   << NsField("[品目ID]",     ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID", "使用区分 = 1")))
		   << NsField("[使用区分]",   use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[更新日時]",   Now());

      if (CardNoEdit->Text.ToIntDef(0) != 0)
            fields << NsField("[カード番号]", CardNoEdit->Text.ToIntDef(0));
      else
            fields << NsField("[カード番号]", Variant());

	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_車両", fields);
		}else{
			DM->DBI.Update("M_車両", "車両ID", id_, fields);
		}
	}catch (Exception &e){
		Application->MessageBox(("登録／修正に失敗しました\r\n" + e.Message).c_str(),
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
	AnsiString sql = "SELECT * FROM V_車両 WHERE 車両ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm(0);
		id_ = 0;
		return;
	}

	id_                         = ToInt(set[0]["車両ID"]);
	CarNoEdit->Text             = ToString(set[0]["車番"]);
	SharyoNameEdit->Text        = ToString(set[0]["車両名称"]);
	EmptyWeightEdit->Text       = ToCurrency(set[0]["空車重量"]);
	KasekisaiEdit->Text         = ToCurrency(set[0]["最大積載量"]);
	SharyoGrossWeightEdit->Text = ToCurrency(set[0]["車両総重量"]);
	if (ToInt(set[0]["得意先コード"]) == 0)
		TokuisakiCodeEdit->Text = AnsiString();
	else
		TokuisakiCodeEdit->Text = ToInt(set[0]["得意先コード"]);
	if (ToInt(set[0]["項目1コード"]) == 0)
		Item1CodeEdit->Text = AnsiString();
	else
		Item1CodeEdit->Text = ToInt(set[0]["項目1コード"]);
	if (ToInt(set[0]["項目2コード"]) == 0)
		Item2CodeEdit->Text = AnsiString();
	else
		Item2CodeEdit->Text = ToInt(set[0]["項目2コード"]);
	if (ToInt(set[0]["品目コード"]) == 0)
		HinmokuCodeEdit->Text = AnsiString();
	else
		HinmokuCodeEdit->Text = ToInt(set[0]["品目コード"]);
      if (ToInt(set[0]["カード番号"]) == 0)
            CardNoEdit->Text = AnsiString();
      else
            CardNoEdit->Text = ToInt(set[0]["カード番号"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["使用区分"]));

	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
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

      if (!DM->DBI.IsExist("M_車両", "車両ID", id_)){
            Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
      if (ToInt(DM->DBI.Lookup("M_車両", "車両ID", id_, "使用区分")) != 0){

            if (Application->MessageBox("このデータを使用出来なくなります。よろしいですか？\r\nなお、本当に削除する場合は一度この処理を行なった後\r\nもう一度削除ボタンをクリックして下さい",
                        "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet fields;
            try{
                  fields << NsField("[使用区分]", 0);
                  DM->DBI.Update("M_車両", "車両ID", id_, fields);
            }catch (Exception &e){
                  DM->ADOConnection->RollbackTrans();
                  Application->MessageBox(("データ削除に失敗しました\r\n" + e.Message).c_str(), "削除", MB_OK | MB_ICONWARNING);
                  return;
            }
            msg = "使用区分を変更しました\r\n再度使用する際には使用区分を変更して下さい";

      }else{

            if (Application->MessageBox("本当に削除してもよろしいですか？", "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet keys;
            keys << NsField("[車両ID]", id_);
            try{
                  DM->DBI.Delete("M_車両", keys);
            }catch (Exception &e){
                  DM->ADOConnection->RollbackTrans();
                  Application->MessageBox(("データ削除に失敗しました\r\n" + e.Message).c_str(), "削除", MB_OK | MB_ICONWARNING);
                  return;
            }
            msg = "データを削除しました";

      }
      DM->ADOConnection->CommitTrans();
      MainForm->OpenQuery(page_, MainForm->order_);
      id_ = MainForm->query[page_]->FieldByName(keyfield_)->AsInteger;
      BrowseRecord();
      Application->MessageBox(msg.c_str(), "削除", MB_OK | MB_ICONINFORMATION);
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

	if (Application->MessageBox("登録／修正しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("登録／修正しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

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
	id_ = DM->M_Sharyo->FieldByName("車両ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Sharyo->Eof)
		return;

	DM->M_Sharyo->Next();
	id_ = DM->M_Sharyo->FieldByName("車両ID")->AsInteger;
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
	if (!DM->DBI.GetRecordSet("SELECT 車両ID FROM M_車両 WHERE 車番 = " + CarNoEdit->Text + " AND 使用区分 = 1", set))
		return;

	if (Application->MessageBox("同一車番が登録されています。\r\n修正モードで開きますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

    int car_id;
    if (set.size() > 1){
        SearchForm->Top              = Application->MainForm->Top + 50;
        SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
        SearchForm->based_sql        = " SELECT 車番, 車両名称, 得意先名称, 項目1名称, 項目2名称, 品目名称, カード番号, 空車重量, 車両ID FROM V_車両 WHERE 車番 = " + CarNoEdit->Text;
        SearchForm->orderby_sql      = " ORDER BY 車番";
        SearchForm->table_name       = " V_車両";
        SearchForm->list_->CommaText = " 車番, 車両名称, 得意先名称, 項目1名称, 項目2名所, 品目名称";
        if (SearchForm->ShowModal() != mrOk)
            return;

        car_id = SearchForm->Query->FieldByName("車両ID")->AsInteger;
    }else{
        car_id = ToInt(set[0]["車両ID"]);
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
	TokuisakiNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::TokuisakiSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 得意先コード, 得意先名称, 得意先カナ, 住所1, 住所2, 電話番号 FROM V_得意先";
	SearchForm->orderby_sql      = " ORDER BY 得意先コード";
	SearchForm->table_name       = " V_得意先";
	SearchForm->list_->CommaText = " 得意先コード,得意先略称,得意先カナ,住所1,住所2,電話番号";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item1CodeEditChange(TObject *Sender)
{
	if (Item1CodeEdit->Text == ""){
		Item1NameEdit->Text = AnsiString();
		return;
	}
	Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item1SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 項目1コード, 項目1名称, 項目1カナ FROM V_項目1";
	SearchForm->orderby_sql      = " ORDER BY 項目1コード";
	SearchForm->table_name       = " V_項目1";
	SearchForm->list_->CommaText = " 項目1コード,項目1略称,項目1カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEdit->Text = SearchForm->Query->FieldByName("項目1コード")->AsInteger;
	Item1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item2CodeEditChange(TObject *Sender)
{
	if (Item2CodeEdit->Text == ""){
		Item2NameEdit->Text = AnsiString();
		return;
	}
	Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item2SearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 項目2コード, 項目2名称, 項目2カナ FROM V_項目2";
	SearchForm->orderby_sql      = " ORDER BY 項目2コード";
	SearchForm->table_name       = " V_項目2";
	SearchForm->list_->CommaText = " 項目2コード,項目2略称,項目2カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEdit->Text = SearchForm->Query->FieldByName("項目2コード")->AsInteger;
	Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	if (HinmokuCodeEdit->Text == ""){
		HinmokuNameEdit->Text = AnsiString();
		return;
	}
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::HinmokuSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
	SearchForm->based_sql        = " SELECT 品目コード, 品目略称, 品目カナ FROM V_品目";
	SearchForm->orderby_sql      = " ORDER BY 品目コード";
	SearchForm->table_name       = " V_品目";
	SearchForm->list_->CommaText = " 品目略称, 品目カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	HinmokuCodeEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
	HinmokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::CarNoEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  車番を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::SharyoNameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  車両名称を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::EmptyWeightEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  空車重量を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::KasekisaiEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  過積載重量を入力してください";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::TokuisakiCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + toku_ + "を入力して下さい。（[F4] " + toku_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item1CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item1_ + "を入力して下さい。（[F4] " + item1_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::Item2CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + item2_ + "を入力して下さい。（[F4] " + item2_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  " + hin_ + "を入力して下さい。（[F4] " + hin_ + "検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TSharyoEditForm::CardNoEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  カード番号を入力してください";

      if (DM->GetMode(ModePanel) != imNew)
            return;

      if (DM->DBI.IsExist("M_車両", "カード番号", CarNoEdit->Text.ToIntDef(0))){
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

	StatusBar->SimpleText = "  使用区分を選択してください";
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
            if (!DM->DBI.IsExist("M_車両", "カード番号", code))
                  break;
            code++;
      }

      if (code > 999999){
            Application->MessageBox("登録件数が上限に達しました。\r\nこれ以上登録できません。",
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

