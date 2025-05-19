//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "TaniEditFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TTaniEditForm *TaniEditForm;
//---------------------------------------------------------------------------
__fastcall TTaniEditForm::TTaniEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::FormShow(TObject *Sender)
{
      if (id_ == 0)
            SetMode(imNew);
      else
            SetMode(imMod);

	ClearForm();
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

      CodeEdit->SetFocus();
	is_edit_ = true;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
int __fastcall TTaniEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::ClearForm()
{
	int code = GetNo();
	if (code != -1)
		CodeEdit->Text        = code;
	else
		CodeEdit->Text        = AnsiString();
	NameEdit->Text            = AnsiString();
	RenewDateEdit->Text  = AnsiString();
	CreateDateEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::SetMode(TInputMode mode)
{
	if (mode == imNew){
		ModePanel->Caption = "新規";
		ModePanel->Color = TColor(NEW_CLR);
		SaibanButton->Enabled = true;
		RenzokuCheckBox->Enabled = true;
		Action7->Enabled = false;
		Action8->Enabled = false;
	}else if (mode == imMod){
		ModePanel->Caption = "修正";
		ModePanel->Color = TColor(MOD_CLR);
      	SaibanButton->Enabled = false;
		RenzokuCheckBox->Enabled = false;
		Action7->Enabled = true;
		Action8->Enabled = true;
	}
}
//---------------------------------------------------------------------------
int __fastcall TTaniEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT 単位コード FROM M_単位 WHERE 単位コード > 0 ORDER BY 単位コード", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["単位コード"]))
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
bool __fastcall TTaniEditForm::CheckEdit()
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
            "     M_単位"
            " WHERE"
            "     単位コード = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
            " AND"
            "     単位ID <> " + IntToStr(id_);
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

      if (NameEdit->Text.Length() > 10)
            NameEdit->Text = DM->TrimString(NameEdit->Text, 10);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TTaniEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[単位コード]",       CodeEdit->Text.ToIntDef(0))
		   << NsField("[単位名称]",         NameEdit->Text)
		   << NsField("[更新日時]",          Now());

	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_単位", fields);
		}else{
			DM->DBI.Update("M_単位", "単位ID", id_, fields);
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
void __fastcall TTaniEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM M_単位 WHERE 単位ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                       = ToInt(set[0]["単位ID"]);
	CodeEdit->Text            = ToString(set[0]["単位コード"]);
	NameEdit->Text            = ToString(set[0]["単位名称"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::Action3Execute(TObject *Sender)
{
      if (DM->GetMode(ModePanel) != imMod)
            return;

      if (!DM->DBI.IsExist("M_拠点", "拠点ID", id_)){
            Application->MessageBox("対象データ抽出に失敗しました", "削除", MB_OK | MB_ICONWARNING);
            return;
      }

      AnsiString msg = AnsiString();
      DM->ADOConnection->BeginTrans();
            if (Application->MessageBox("本当に削除してもよろしいですか？", "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
                  return;

            NsFieldSet keys;
            keys << NsField("[拠点ID]", id_);
            try{
                  DM->DBI.Delete("M_拠点", keys);
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
void __fastcall TTaniEditForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == CodeEdit)
		SaibanButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::Action5Execute(TObject *Sender)
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
void __fastcall TTaniEditForm::Action7Execute(TObject *Sender)
{
	if (DM->M_Tani->Bof)
		return;

	DM->M_Tani->Prior();
	id_ = DM->M_Tani->FieldByName("単位ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Tani->Eof)
		return;

	DM->M_Tani->Next();
	id_ = DM->M_Tani->FieldByName("単位ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::CodeEditExit(TObject *Sender)
{
	if (CodeEdit->Text == "")
		return;

	NsRecordSet set;
	if (!DM->DBI.GetRecordSet("SELECT 単位ID FROM M_単位 WHERE 単位コード = " + CodeEdit->Text + " AND 単位ID <> " + IntToStr(id_), set))
		return;

      if (Application->MessageBox("同一コードが登録されています。\r\n修正モードで呼び出しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

	SetMode(imMod);
	id_ = ToInt(set[0]["単位ID"]);
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::SaibanButtonClick(TObject *Sender)
{
	CodeEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  コードを入力して下さい（採番[F4]を押す事で、空き番検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::NameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  名称を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::UseDivComboBoxKeyDown(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TTaniEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

