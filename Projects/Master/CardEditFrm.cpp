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
	DM->AddComboMap(UseDivComboBox, use_div_map_, "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 10 ORDER BY 区分コード");

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
		ModePanel->Caption = "新規";
		ModePanel->Color = TColor(NEW_CLR);
		RenzokuCheckBox->Enabled = true;
		Action3->Enabled = false;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "修正";
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
		Application->MessageBox("登録番号が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		RegistryNoEdit->SetFocus();
		return false;
	}

    // 登録番号重複チェック
    if (RegistryNoEdit->Text != "" && RegistryNoEdit->Text.ToIntDef(0) != 0){
        if (id_ != 0){ /////// 修正
            NsRecordSet set;
            AnsiString sql;
            sql = " SELECT"
                  "     *"
                  " FROM"
                  "     M_カード"
                  " WHERE"
                  "     登録番号 = " + IntToStr(RegistryNoEdit->Text.ToIntDef(0)) +
                  " AND"
                  "     カードID <> " + IntToStr(id_);
            if (DM->DBI.GetRecordSet(sql, set)){
                Application->MessageBox("登録番号が重複しています\r\n別の番号を選択してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
                RegistryNoEdit->SetFocus();
                return false;
            }
        }else{         /////// 新規
            if (DM->DBI.IsExist("M_カード", "登録番号", RegistryNoEdit->Text.ToIntDef(0))){
                Application->MessageBox("登録番号が重複しています\r\n別の番号を選択してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
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
	fields << NsField("[登録番号]",    RegistryNoEdit->Text.ToIntDef(0))
           << NsField("[車両ID]",      ToInt(DM->DBI.Lookup("M_車両", "車番", CarNoEdit->Text.ToIntDef(0), "車両ID")))
		   << NsField("[業者ID]",      ToInt(DM->DBI.Lookup("M_業者", "業者コード", GyoshaCodeEdit->Text.ToIntDef(0), "業者ID")))
		   << NsField("[品目ID]",      ToInt(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目ID")))
           << NsField("[備考通信欄1]", BikouEdit1->Text)
           << NsField("[備考通信欄2]", BikouEdit2->Text)
           << NsField("[備考通信欄3]", BikouEdit3->Text)
		   << NsField("[使用区分]",    use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[更新日時]",    Now());

	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_カード", fields);
		}else{
			DM->DBI.Update("M_カード", "カードID", id_, fields);
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
void __fastcall TCardEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_カード WHERE カードID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm(0);
		id_ = 0;
		return;
	}

	id_                  = ToInt(set[0]["カードID"]);
    RegistryNoEdit->Text = ToInt(SET_TOP(set)["登録番号"]);
	CarNoEdit->Text      = ToString(set[0]["車番"]);
	CarNameEdit->Text    = ToString(set[0]["車両名称"]);

	if (ToInt(set[0]["業者コード"]) == 0)
		GyoshaCodeEdit->Text = AnsiString();
	else
		GyoshaCodeEdit->Text = ToInt(set[0]["業者コード"]);
	if (ToInt(set[0]["品目コード"]) == 0)
		HinmokuCodeEdit->Text = AnsiString();
	else
		HinmokuCodeEdit->Text = ToInt(set[0]["品目コード"]);

    BikouEdit1->Text          = ToString(SET_TOP(set)["備考通信欄1"]);
    BikouEdit2->Text          = ToString(SET_TOP(set)["備考通信欄2"]);
    BikouEdit3->Text          = ToString(SET_TOP(set)["備考通信欄3"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["使用区分"]));
	RenewDateEdit->Text       = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text      = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
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

    if (!DM->DBI.IsExist("M_カード", "カードID", id_)){
        Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (ToInt(DM->DBI.Lookup("M_カード", "カードID", id_, "使用区分")) != 0){

        if (Application->MessageBox("このデータを使用出来なくなります。よろしいですか？\r\nなお、本当に削除する場合は一度この処理を行なった後\r\nもう一度削除ボタンをクリックして下さい",
                "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

        NsFieldSet fields;
        try{
            fields << NsField("[使用区分]", 0);
            DM->DBI.Update("M_カード", "カードID", id_, fields);
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
        keys << NsField("[カードID]", id_);
        try{
            DM->DBI.Delete("M_カード", keys);
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

	if (Application->MessageBox("登録／修正しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("登録／修正しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

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
	id_ = DM->M_Card->FieldByName("カードID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Card->Eof)
		return;

	DM->M_Card->Next();
	id_ = DM->M_Card->FieldByName("カードID")->AsInteger;
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
          "     M_車両"
          " WHERE"
          "     車番 = " + IntToStr(CarNoEdit->Text.ToIntDef(0) +
          " AND"
          "     使用区分 = 1";
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
	GyoshaNameEdit->Text = ToString(DM->DBI.Lookup("M_業者", "業者コード", GyoshaCodeEdit->Text.ToIntDef(0), "業者名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::GyoshaSearchButtonClick(TObject *Sender)
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
void __fastcall TCardEditForm::HinmokuCodeEditChange(TObject *Sender)
{
	if (HinmokuCodeEdit->Text == ""){
		HinmokuNameEdit->Text = AnsiString();
		return;
	}
	HinmokuNameEdit->Text = ToString(DM->DBI.Lookup("M_品目", "品目コード", HinmokuCodeEdit->Text.ToIntDef(0), "品目名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::HinmokuSearchButtonClick(TObject *Sender)
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
void __fastcall TCardEditForm::RegistryNoEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  登録番号を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::CarNoEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  車番を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::GyoshaCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  業者コードを入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::HinmokuCodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  品目コードを入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::BikouEdit1Enter(TObject *Sender)
{
	StatusBar->SimpleText = "  備考通信欄1を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::BikouEdit2Enter(TObject *Sender)
{
	StatusBar->SimpleText = "  備考通信欄2を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::BikouEdit3Enter(TObject *Sender)
{
	StatusBar->SimpleText = "  備考通信欄3を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TCardEditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  使用区分を選択して下さい（[F4] 候補を表示します）";
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
            if (!DM->DBI.IsExist("M_カード", "登録番号", no))
                  break;
            no++;
      }

      if (no > 9999){
            Application->MessageBox("登録件数が上限に達しました。\r\nこれ以上登録できません。",
                  this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            return -1;
      }

      return no;
}
//---------------------------------------------------------------------------

