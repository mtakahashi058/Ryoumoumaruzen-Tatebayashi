//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "Item2EditFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TItem2EditForm *Item2EditForm;
//---------------------------------------------------------------------------
__fastcall TItem2EditForm::TItem2EditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::FormShow(TObject *Sender)
{
    DM->AddComboMap(UseDivComboBox, use_div_map_, "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 10 ORDER BY 区分コード");

    if (id_ == 0)
        SetMode(imNew);
    else
        SetMode(imMod);

    ClearForm();
    if (DM->GetMode(ModePanel) == imMod)
        BrowseRecord();

    is_edit_  = true;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];

    CodeEdit->SetFocus();
    Application->OnMessage = this->AutoKanaMessage;
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
      case VK_ESCAPE:
            Close();
            break;
	}
}
//---------------------------------------------------------------------------
int __fastcall TItem2EditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::ClearForm()
{
      int code = GetNo();
      if (code != -1)
            CodeEdit->Text = code;
      else
            CodeEdit->Text = AnsiString();

      NameEdit->Text            = AnsiString();
      ShortNameEdit->Text       = AnsiString();
      KanaEdit->Text            = AnsiString();
      UseDivComboBox->ItemIndex = 1;

      RenewDateEdit->Text  = AnsiString();
      CreateDateEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
            ModePanel->Caption       = "新規";
            ModePanel->Color         = TColor(NEW_CLR);
            SaibanButton->Enabled    = true;
            RenzokuCheckBox->Enabled = true;
            Action3->Enabled         = false;
            Action8->Enabled         = false;
      }else if (mode == imMod){
            ModePanel->Caption       = "修正";
            ModePanel->Color         = TColor(MOD_CLR);
            SaibanButton->Enabled    = false;
            RenzokuCheckBox->Enabled = false;
            Action3->Enabled         = true;
            Action8->Enabled         = true;
      }
}
//---------------------------------------------------------------------------
int __fastcall TItem2EditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT 項目2コード FROM M_項目2 WHERE 項目2コード > 0 ORDER BY 項目2コード", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["項目2コード"]))
            break;
        else
            code++;
    }

	if (code > 99999){
		Application->MessageBox("登録件数が上限に達しました。\r\nこれ以上登録できません。",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return -1;
	}

	return code;
}
//---------------------------------------------------------------------------
bool __fastcall TItem2EditForm::CheckEdit()
{
	if (CodeEdit->Text.ToIntDef(0) == 0){
		Application->MessageBox("コードが無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		CodeEdit->SetFocus();
		return false;
	}

      ///// コード重複チェック
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT"
            "     *"
            " FROM"
            "     M_項目2"
            " WHERE"
            "     項目2コード = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
            " AND"
            "     項目2ID <> " + IntToStr(id_);
      if (DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("コードが重複しています。他のコードを指定してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            CodeEdit->SetFocus();
            return false;
      }

	if (NameEdit->Text == ""){
		Application->MessageBox("名称が無効です", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		NameEdit->SetFocus();
		return false;
	}

      if (NameEdit->Text.Length() > 40)
            NameEdit->Text = DM->TrimString(NameEdit->Text, 40);

      if (ShortNameEdit->Text.Length() > 20)
            ShortNameEdit->Text = DM->TrimString(ShortNameEdit->Text, 20);

      if (KanaEdit->Text.Length() > 50)
            KanaEdit->Text = DM->TrimString(KanaEdit->Text, 50);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TItem2EditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[項目2コード]",       CodeEdit->Text.ToIntDef(0))
		   << NsField("[項目2名称]",         NameEdit->Text)
		   << NsField("[項目2略称]",         ShortNameEdit->Text)
		   << NsField("[項目2カナ]",         KanaEdit->Text)
		   << NsField("[使用区分]",          use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[更新日時]",          Now());

	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_項目2", fields);
		}else{
			DM->DBI.Update("M_項目2", "項目2ID", id_, fields);
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
void __fastcall TItem2EditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_項目2 WHERE 項目2ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                       = ToInt(set[0]["項目2ID"]);
	CodeEdit->Text            = ToString(set[0]["項目2コード"]);
	NameEdit->Text            = ToString(set[0]["項目2名称"]);
	ShortNameEdit->Text       = ToString(set[0]["項目2略称"]);
	KanaEdit->Text            = ToString(set[0]["項目2カナ"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["使用区分"]));

	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::AutoKanaMessage(tagMSG &Msg, bool &Handled)
{
	if (Msg.message == WM_IME_ENDCOMPOSITION){
		int ret;
		HIMC ime;
		char buf[256];
		ime = ImmGetContext(Handle);

		ret = ImmGetCompositionString(ime, GCS_RESULTREADSTR, buf, sizeof(buf));

		buf[ret] = '\0';

		ImmReleaseContext(Handle, ime);

		AnsiString buff = "";
		if (ActiveControl == NameEdit){
			buff = KanaEdit->Text;
			if (KanaEdit->Text != "")
				buff = buff + (AnsiString)buf;
			else
				buff = (AnsiString)buf;
			KanaEdit->Text = AnsiSubString(buff, 1, 50);
			Handled = false;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (!DM->DBI.IsExist("M_項目2", "項目2ID", id_)){
        Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (ToInt(DM->DBI.Lookup("M_項目2", "項目2ID", id_, "使用区分")) != 0){

        if (Application->MessageBox("このデータを使用出来なくなります。よろしいですか？\r\nなお、本当に削除する場合は一度この処理を行なった後\r\nもう一度削除ボタンをクリックして下さい",
                "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

        NsFieldSet fields;
        try{
            fields << NsField("[使用区分]", 0);
            DM->DBI.Update("M_項目2", "項目2ID", id_, fields);
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
        keys << NsField("[項目2ID]", id_);
        try{
            DM->DBI.Delete("M_項目2", keys);
            DM->DeleteRelateMaster(page_, keyfield_, id_);
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
void __fastcall TItem2EditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == CodeEdit)
		SaibanButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::Action5Execute(TObject *Sender)
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
			ClearForm();
			CodeEdit->SetFocus();
		}else{
			Close();
		}
	}else{
		BrowseRecord();
		NameEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::Action7Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) == imMod && DM->M_Item2->Bof)
            return;

      if (DM->GetMode(ModePanel) == imNew){
            ClearForm();
            SetMode(imMod);
            is_edit_ = false;
            DM->M_Item2->Last();
      }else
            DM->M_Item2->Prior();

      id_ = DM->M_Item2->FieldByName("項目2ID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Item2->Eof)
		return;

	DM->M_Item2->Next();
	id_ = DM->M_Item2->FieldByName("項目2ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::CodeEditExit(TObject *Sender)
{
      if (CodeEdit->Text == "")
            return;

      NsRecordSet set;
      if (!DM->DBI.GetRecordSet("SELECT 項目2ID FROM M_項目2 WHERE 項目2コード = " + CodeEdit->Text + " AND 項目2ID <> " + IntToStr(id_), set))
            return;

      if (Application->MessageBox("同一コードが登録されています。\r\n修正モードで呼び出しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

      SetMode(imMod);
      id_ = ToInt(set[0]["項目2ID"]);
      BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::SaibanButtonClick(TObject *Sender)
{
      CodeEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::NameEditExit(TObject *Sender)
{
	if (DM->GetMode(ModePanel) == imMod)
		return;

	if (NameEdit->Text == "")
		return;

	ShortNameEdit->Text = AnsiSubString(DM->Formal2Informal(NameEdit->Text), 1, 20);
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  コードを入力して下さい（採番[F4]を押す事で、空き番検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::NameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  名称を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::ShortNameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  必要な場合略称を変更して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::KanaEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  必要な場合カナを変更して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  使用区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::UseDivComboBoxExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TItem2EditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

