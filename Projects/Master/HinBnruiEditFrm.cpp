//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "HinBnruiEditFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
THinBunruiEditForm *HinBunruiEditForm;
//---------------------------------------------------------------------------
__fastcall THinBunruiEditForm::THinBunruiEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::FormShow(TObject *Sender)
{
      DM->AddComboMap(UseDivComboBox, use_div_map_, "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 10 ORDER BY 区分コード");

      if (id_ == 0)
            SetMode(imNew);
      else
            SetMode(imMod);

      ClearForm();
      if (DM->GetMode(ModePanel) == imMod)
            BrowseRecord();

      is_edit_ = true;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];

      CodeEdit->SetFocus();
      Application->OnMessage = this->AutoKanaMessage;
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall THinBunruiEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::ClearForm()
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
void __fastcall THinBunruiEditForm::SetMode(TInputMode mode)
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
int __fastcall THinBunruiEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT 品目分類コード FROM M_品目分類 WHERE 品目分類コード > 0 ORDER BY 品目分類コード", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["品目分類コード"]))
            break;
        else
            code++;
    }

	if (code > 999){
		Application->MessageBox("登録件数が上限に達しました。\r\nこれ以上登録できません。",
			this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return -1;
	}

	return code;
}
//---------------------------------------------------------------------------
bool __fastcall THinBunruiEditForm::CheckEdit()
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
            "     M_品目分類"
            " WHERE"
            "     品目分類コード = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
            " AND"
            "     品目分類ID <> " + IntToStr(id_);
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
bool __fastcall THinBunruiEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[品目分類コード]",       CodeEdit->Text.ToIntDef(0))
		   << NsField("[品目分類名称]",         NameEdit->Text)
		   << NsField("[品目分類略称]",         ShortNameEdit->Text)
		   << NsField("[品目分類カナ]",         KanaEdit->Text)
		   << NsField("[使用区分]",          use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[更新日時]",          Now());

	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_品目分類", fields);
		}else{
			DM->DBI.Update("M_品目分類", "品目分類ID", id_, fields);
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
void __fastcall THinBunruiEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_品目分類 WHERE 品目分類ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                       = ToInt(set[0]["品目分類ID"]);
	CodeEdit->Text            = ToString(set[0]["品目分類コード"]);
	NameEdit->Text            = ToString(set[0]["品目分類名称"]);
	ShortNameEdit->Text       = ToString(set[0]["品目分類略称"]);
	KanaEdit->Text            = ToString(set[0]["品目分類カナ"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["使用区分"]));

	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::AutoKanaMessage(tagMSG &Msg, bool &Handled)
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
// F1 新規
void __fastcall THinBunruiEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F3 削除
void __fastcall THinBunruiEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_品目分類", "品目分類ID", id_)){
            Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
      if (ToInt(DM->DBI.Lookup("M_品目分類", "品目分類ID", id_, "使用区分")) != 0){

            if (Application->MessageBox("このデータを使用出来なくなります。よろしいですか？\r\nなお、本当に削除する場合は一度この処理を行なった後\r\nもう一度削除ボタンをクリックして下さい",
                        "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet fields;
            try{
                  fields << NsField("[使用区分]", 0);
                  DM->DBI.Update("M_品目分類", "品目分類ID", id_, fields);
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
            keys << NsField("[品目分類ID]", id_);
            try{
                  DM->DBI.Delete("M_品目分類", keys);
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
// F4 参照
void __fastcall THinBunruiEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == CodeEdit)
		SaibanButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
// F5 登録
void __fastcall THinBunruiEditForm::Action5Execute(TObject *Sender)
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
// F7 前へ
void __fastcall THinBunruiEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_HinBunrui->Bof)
		return;

	DM->M_HinBunrui->Prior();
	id_ = DM->M_HinBunrui->FieldByName("品目分類ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
// F8 次へ
void __fastcall THinBunruiEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_HinBunrui->Eof)
		return;

	DM->M_HinBunrui->Next();
	id_ = DM->M_HinBunrui->FieldByName("品目分類ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
// F12 閉じる
void __fastcall THinBunruiEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::CodeEditExit(TObject *Sender)
{
	if (CodeEdit->Text == "")
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT 品目分類ID FROM M_品目分類 WHERE 品目分類コード = " + CodeEdit->Text + " AND 品目分類ID <> " + IntToStr(id_), set))
		return;

      if (Application->MessageBox("同一コードが登録されています。\r\n修正モードで呼び出しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

	SetMode(imMod);
	id_ = ToInt(set[0]["品目分類ID"]);
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::SaibanButtonClick(TObject *Sender)
{
    CodeEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::NameEditExit(TObject *Sender)
{
	if (DM->GetMode(ModePanel) == imMod)
		return;

	if (NameEdit->Text == "")
		return;

	ShortNameEdit->Text = AnsiSubString(DM->Formal2Informal(NameEdit->Text), 1, 20);
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  コードを入力して下さい（採番[F4]を押す事で、空き番検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::NameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  名称を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::ShortNameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  必要な場合略称を変更して下さい";
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::KanaEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  必要な場合カナを変更して下さい";
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  使用区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::UseDivComboBoxExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall THinBunruiEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

void __fastcall THinBunruiEditForm::UseDivComboBoxChange(TObject *Sender)
{
/*	if (UseDivComboBox->ItemIndex == 1)
		UseDivLabel->Color = TColor(0x00E1E1E1);
	else
		UseDivLabel->Color = TColor(0x008080FF);
*/
}
//---------------------------------------------------------------------------

