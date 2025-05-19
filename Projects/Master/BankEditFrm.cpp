//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BankEditFrm.h"
#include "DMFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TBankEditForm *BankEditForm;
//---------------------------------------------------------------------------
__fastcall TBankEditForm::TBankEditForm(TComponent* Owner)
      : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall TBankEditForm::ShowModalWithId(int id)
{
      id_ = id;

      return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::FormShow(TObject *Sender)
{
      ClearForm();
      if (id_ == 0){
            SetMode(imNew);
      }else{
            SetMode(imMod);
            BrowseRecord();
      }

      CodeEdit->SetFocus();
      is_edit_ = false;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
		}else{
                  Action5->OnExecute(NULL);
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
void __fastcall TBankEditForm::CodeEditExit(TObject *Sender)
{
	if (CodeEdit->Text == "")
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT 銀行ID FROM M_銀行 WHERE 銀行コード = " + CodeEdit->Text + " AND 銀行ID <> " + IntToStr(id_), set))
		return;

      if (Application->MessageBox("同一コードが登録されています。\r\n修正モードで呼び出しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

	SetMode(imMod);
	id_ = ToInt(set[0]["銀行ID"]);
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_銀行", "銀行ID", id_)){
            Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
            if (Application->MessageBox("本当に削除してもよろしいですか？", "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet keys;
            keys << NsField("[銀行ID]", id_);
            try{
                  DM->DBI.Delete("M_銀行", keys);
            }catch (Exception &e){
                  DM->ADOConnection->RollbackTrans();
                  Application->MessageBox(("データ削除に失敗しました\r\n" + e.Message).c_str(), "削除", MB_OK | MB_ICONWARNING);
                  return;
            }
            msg = "データを削除しました";

      DM->ADOConnection->CommitTrans();
      MainForm->OpenQuery(page_, MainForm->order_);
      id_ = MainForm->query[page_]->FieldByName(keyfield_)->AsInteger;
      BrowseRecord();
      Application->MessageBox(msg.c_str(), "削除", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action5Execute(TObject *Sender)
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
void __fastcall TBankEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Bank->Bof)
		return;

	DM->M_Bank->Prior();
	id_ = DM->M_Bank->FieldByName("銀行ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Bank->Eof)
		return;

	DM->M_Bank->Next();
	id_ = DM->M_Bank->FieldByName("銀行ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::Action12Execute(TObject *Sender)
{
      Close();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::ClearForm()
{
      CodeEdit->Text          = GetNo();
      NameEdit->Text          = AnsiString();
      SitenNameEdit->Text     = AnsiString();
      KozaNameEdit->Text      = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::BrowseRecord()
{
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT * FROM V_銀行 WHERE 銀行ID = " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
      }

      id_                     = ToInt(set[0]["銀行ID"]);
      CodeEdit->Text          = ToInt(set[0]["銀行コード"]);
      NameEdit->Text          = ToString(set[0]["銀行名称"]);
      SitenNameEdit->Text     = ToString(set[0]["支店名称"]);
      KozaNameEdit->Text      = ToString(set[0]["口座"]);
      RenewDateEdit->Text     = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
      CreateDateEdit->Text    = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
bool __fastcall TBankEditForm::PostRecord()
{
      NsFieldSet fields;

      fields      << NsField("[銀行コード]",    CodeEdit->Text.ToIntDef(0))
                  << NsField("[銀行名称]",      NameEdit->Text)
                  << NsField("[支店名称]",      SitenNameEdit->Text)
                  << NsField("[口座]",          KozaNameEdit->Text)
                  << NsField("[更新日時]",      Now());

      try{
            if (id_ == 0){
                  fields << NsField("[作成日時]", Now());
                  DM->DBI.Insert("M_銀行", fields);
            }else{
                  DM->DBI.Update("M_銀行", "銀行ID", id_, fields);
            }
      }catch (Exception &e){
		Application->MessageBox(("登録／修正に失敗しました\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
      }

      is_edit_ = true;

      return true;
}
//---------------------------------------------------------------------------
bool __fastcall TBankEditForm::CheckEdit()
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
            "     M_銀行"
            " WHERE"
            "     銀行コード = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
            " AND"
            "     銀行ID <> " + IntToStr(id_);
      if (DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("コードが重複しています。他のコードを指定してください", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            CodeEdit->SetFocus();
            return false;
      }

      if (NameEdit->Text.Length() > 16)
            NameEdit->Text = DM->TrimString(NameEdit->Text, 16);

      if (SitenNameEdit->Text.Length() > 16)
            SitenNameEdit->Text = DM->TrimString(SitenNameEdit->Text, 16);

      if (KozaNameEdit->Text.Length() > 14)
            KozaNameEdit->Text = DM->TrimString(KozaNameEdit->Text, 14);

      return true;
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
		ModePanel->Caption      = "新規";
		ModePanel->Color        = TColor(NEW_CLR);
            SaibanButton->Enabled   = true;
            Action7->Enabled        = false;
            Action8->Enabled        = false;
      }else if (mode == imMod){
		ModePanel->Caption      = "修正";
		ModePanel->Color        = TColor(MOD_CLR);
            SaibanButton->Enabled   = false;
            Action7->Enabled        = true;
            Action8->Enabled        = true;
      }
}
//---------------------------------------------------------------------------
int __fastcall TBankEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT 銀行コード FROM M_銀行 WHERE 銀行コード > 0 ORDER BY 銀行コード", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["銀行コード"]))
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
void __fastcall TBankEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TBankEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

