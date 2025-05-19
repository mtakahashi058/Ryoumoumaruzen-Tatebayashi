//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SlipInfoEditFrm.h"
#include "DMFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TSlipInfoEditForm *SlipInfoEditForm;
//---------------------------------------------------------------------------
__fastcall TSlipInfoEditForm::TSlipInfoEditForm(TComponent* Owner)
      : TForm(Owner), is_edit_(false)
{
}
//---------------------------------------------------------------------------
int __fastcall TSlipInfoEditForm::ShowModalWithId(int id)
{
      id_ = id;
      return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::FormShow(TObject *Sender)
{
      if (id_ == 0){
            SetMode(imNew);
            SlipInfoNoEdit->SetFocus();
      }else{
            SetMode(imMod);
            SlipInfoNameEdit->SetFocus();
      }

      ClearForm();
      if (DM->GetMode(ModePanel) == imMod)
            BrowseRecord();

      is_edit_ = false;
      page_     = MainForm->page;
      keyfield_ = MainForm->keyfield[page_];
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
                  if (ActiveControl->Tag != 0){
                        keybd_event(VK_SHIFT, 0, 0, 0);
                        keybd_event(VK_TAB, 0, 0, 0);
                        keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
                        keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
                  }
                  break;
      }
}
//---------------------------------------------------------------------------
// F1 êVãK
void __fastcall TSlipInfoEditForm::Action1Execute(TObject *Sender)
{
      id_ = 0;
      SetMode(imNew);
      ClearForm();
      is_edit_ = false;
      SlipInfoNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
// F3 çÌèú
void __fastcall TSlipInfoEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (id_ == 1){
        Application->MessageBox("Ç±ÇÃÉfÅ[É^ÇÕçÌèúÇ≈Ç´Ç‹ÇπÇÒ", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
        return;
    }

    if (!DM->DBI.IsExist("M_ì`ï[èÓïÒ", "ì`ï[èÓïÒID", id_)){
        Application->MessageBox("ëŒè€ÉfÅ[É^íäèoÇ…é∏îsÇµÇ‹ÇµÇΩ", "çÌèú", MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (Application->MessageBox("ñ{ìñÇ…çÌèúÇµÇƒÇ‡ÇÊÇÎÇµÇ¢Ç≈Ç∑Ç©ÅH", "çÌèú", MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    NsFieldSet keys;
    keys << NsField("[ì`ï[èÓïÒID]", id_);
    try{
        DM->DBI.Delete("M_ì`ï[èÓïÒ", keys);
    }catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
        Application->MessageBox(("ÉfÅ[É^çÌèúÇ…é∏îsÇµÇ‹ÇµÇΩ\r\n" + e.Message).c_str(), "çÌèú", MB_OK | MB_ICONWARNING);
        return;
    }
    msg = "ÉfÅ[É^ÇçÌèúÇµÇ‹ÇµÇΩ";

    DM->ADOConnection->CommitTrans();
    MainForm->OpenQuery(page_, MainForm->order_);
    id_ = MainForm->query[page_]->FieldByName(keyfield_)->AsInteger;
    BrowseRecord();
    Application->MessageBox(msg.c_str(), "çÌèú", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
// ìoò^
void __fastcall TSlipInfoEditForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("ìoò^Å^èCê≥ÇµÇ‹Ç∑Ç©ÅH", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("ìoò^Å^èCê≥ÇµÇ‹ÇµÇΩ", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	if (DM->GetMode(ModePanel) == imNew){
		if (RenzokuCheckBox->Checked)
			ClearForm();
		else
			Close();
	}else{
		BrowseRecord();
	}
      SlipInfoNameEdit->SetFocus();
}
//---------------------------------------------------------------------------
// ëOÇ÷
void __fastcall TSlipInfoEditForm::Action7Execute(TObject *Sender)
{
      if (DM->M_SlipInfo->Bof)
            return;

      DM->M_SlipInfo->Prior();
      id_ = DM->M_SlipInfo->FieldByName("ì`ï[èÓïÒID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
// éüÇ÷
void __fastcall TSlipInfoEditForm::Action8Execute(TObject *Sender)
{
      if (DM->M_SlipInfo->Eof)
            return;

      DM->M_SlipInfo->Next();
      id_ = DM->M_SlipInfo->FieldByName("ì`ï[èÓïÒID")->AsInteger;
      BrowseRecord();
}
//---------------------------------------------------------------------------
// ï¬Ç∂ÇÈ
void __fastcall TSlipInfoEditForm::Action12Execute(TObject *Sender)
{
      Close();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SlipInfoNoEditExit(TObject *Sender)
{
      if (SlipInfoNoEdit->Text.ToIntDef(0) == 0)
            return;

      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT * FROM V_ì`ï[èÓïÒ WHERE ì`ï[èÓïÒÉRÅ[Éh = " + IntToStr(SlipInfoNoEdit->Text.ToIntDef(0)) + " AND ì`ï[èÓïÒID <> " + IntToStr(id_);
      if (!DM->DBI.GetRecordSet(sql, set))
            return;

      if (Application->MessageBox("ìØàÍÉRÅ[ÉhÇ™ìoò^Ç≥ÇÍÇƒÇ¢Ç‹Ç∑ÅB\r\nèCê≥ÉÇÅ[ÉhÇ≈åƒÇ—èoÇµÇ‹Ç∑Ç©ÅH", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

      id_ = ToInt(set[0]["ì`ï[èÓïÒID"]);
      SetMode(imMod);
      BrowseRecord();
      SlipInfoNameEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SaibanButtonClick(TObject *Sender)
{
      SlipInfoNoEdit->Text = GetSlipInfoNo();
      SlipInfoNoEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SetMode(TInputMode mode)
{
      if (mode == imNew){
            ModePanel->Caption       = "êVãK";
            ModePanel->Color         = TColor(NEW_CLR);
            //SlipInfoNoEdit->ReadOnly = false;
            //SlipInfoNoEdit->Color    = clWindow;
            SaibanButton->Enabled    = true;
            Action7->Enabled         = false;
            Action8->Enabled         = false;
      }else if (mode == imMod){
            ModePanel->Caption       = "èCê≥";
            ModePanel->Color         = TColor(MOD_CLR);
            //SlipInfoNoEdit->ReadOnly = true;
            //SlipInfoNoEdit->Color    = clSilver;
            SaibanButton->Enabled    = false;
            Action7->Enabled         = true;
            Action8->Enabled         = true;
      }
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::ClearForm()
{
      SlipInfoNoEdit->Text    = GetSlipInfoNo();
      SlipInfoNameEdit->Text  = AnsiString();
      NyukoTitleEdit1->Text   = AnsiString();
      NyukoTitleEdit2->Text   = AnsiString();
      NyukoTitleEdit3->Text   = AnsiString();
      ShukoTitleEdit1->Text   = AnsiString();
      ShukoTitleEdit2->Text   = AnsiString();
      ShukoTitleEdit3->Text   = AnsiString();
      CompanyNameEdit->Text   = AnsiString();
      CompanyInfoEdit1->Text  = AnsiString();
      CompanyInfoEdit2->Text  = AnsiString();
      CompanyInfoEdit3->Text  = AnsiString();
      CompanyInfoEdit4->Text  = AnsiString();

      AmountPrint1Check->Checked = true;
      AmountPrint2Check->Checked = true;
      AmountPrint3Check->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::BrowseRecord()
{
      NsRecordSet set;
      if (!DM->DBI.GetRecordSet("SELECT * FROM M_ì`ï[èÓïÒ WHERE ì`ï[èÓïÒID = " + IntToStr(id_), set)){
            Application->MessageBox("äYìñÇ∑ÇÈÉfÅ[É^Ç™Ç†ÇËÇ‹ÇπÇÒ", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            ClearForm();
            id_ = 0;
            return;
      }

      id_                        = ToInt(set[0]["ì`ï[èÓïÒID"]);
      SlipInfoNoEdit->Text       = ToInt(set[0]["ì`ï[èÓïÒÉRÅ[Éh"]);
      SlipInfoNameEdit->Text     = ToString(set[0]["ì`ï[èÓïÒñº"]);
      NyukoTitleEdit1->Text      = ToString(set[0]["ì¸å…ì`ï[É^ÉCÉgÉã1"]);
      NyukoTitleEdit2->Text      = ToString(set[0]["ì¸å…ì`ï[É^ÉCÉgÉã2"]);
      NyukoTitleEdit3->Text      = ToString(set[0]["ì¸å…ì`ï[É^ÉCÉgÉã3"]);
      ShukoTitleEdit1->Text      = ToString(set[0]["èoå…ì`ï[É^ÉCÉgÉã1"]);
      ShukoTitleEdit2->Text      = ToString(set[0]["èoå…ì`ï[É^ÉCÉgÉã2"]);
      ShukoTitleEdit3->Text      = ToString(set[0]["èoå…ì`ï[É^ÉCÉgÉã3"]);
      CompanyNameEdit->Text      = ToString(set[0]["âÔé–ñº"]);
      CompanyInfoEdit1->Text     = ToString(set[0]["âÔé–èÓïÒ1"]);
      CompanyInfoEdit2->Text     = ToString(set[0]["âÔé–èÓïÒ2"]);
      CompanyInfoEdit3->Text     = ToString(set[0]["âÔé–èÓïÒ3"]);
      CompanyInfoEdit4->Text     = ToString(set[0]["âÔé–èÓïÒ4"]);
      AmountPrint1Check->Checked = ToBit(set[0]["ã‡äzàÛéöãÊï™1"]);
      AmountPrint2Check->Checked = ToBit(set[0]["ã‡äzàÛéöãÊï™2"]);
      AmountPrint3Check->Checked = ToBit(set[0]["ã‡äzàÛéöãÊï™3"]);
}
//---------------------------------------------------------------------------
bool __fastcall TSlipInfoEditForm::PostRecord()
{
      NsFieldSet fields, keys;

      fields      << NsField("[ì`ï[èÓïÒÉRÅ[Éh]",      SlipInfoNoEdit->Text.ToIntDef(0))
                  << NsField("[ì`ï[èÓïÒñº]",          SlipInfoNameEdit->Text)
                  << NsField("[ì¸å…ì`ï[É^ÉCÉgÉã1]",   NyukoTitleEdit1->Text)
                  << NsField("[ì¸å…ì`ï[É^ÉCÉgÉã2]",   NyukoTitleEdit2->Text)
                  << NsField("[ì¸å…ì`ï[É^ÉCÉgÉã3]",   NyukoTitleEdit3->Text)
                  << NsField("[èoå…ì`ï[É^ÉCÉgÉã1]",   ShukoTitleEdit1->Text)
                  << NsField("[èoå…ì`ï[É^ÉCÉgÉã2]",   ShukoTitleEdit2->Text)
                  << NsField("[èoå…ì`ï[É^ÉCÉgÉã3]",   ShukoTitleEdit3->Text)
                  << NsField("[ã‡äzàÛéöãÊï™1]",       AmountPrint1Check->Checked ? 1 : 0)
                  << NsField("[ã‡äzàÛéöãÊï™2]",       AmountPrint2Check->Checked ? 1 : 0)
                  << NsField("[ã‡äzàÛéöãÊï™3]",       AmountPrint3Check->Checked ? 1 : 0)
                  << NsField("[âÔé–ñº]",              CompanyNameEdit->Text)
                  << NsField("[âÔé–èÓïÒ1]",           CompanyInfoEdit1->Text)
                  << NsField("[âÔé–èÓïÒ2]",           CompanyInfoEdit2->Text)
                  << NsField("[âÔé–èÓïÒ3]",           CompanyInfoEdit3->Text)
                  << NsField("[âÔé–èÓïÒ4]",           CompanyInfoEdit4->Text);

      try{
            if (id_ == 0){
                  // êVãK
                  DM->DBI.Insert("M_ì`ï[èÓïÒ", fields);
            }else{
                  // çXêV
                  DM->DBI.Update("M_ì`ï[èÓïÒ", "ì`ï[èÓïÒID", id_, fields);
            }
      }catch (Exception &e){
            Application->MessageBox(("ìoò^Å^èCê≥Ç…é∏îsÇµÇ‹ÇµÇΩ\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
            return false;
      }

      is_edit_ = true;

      return true;
}
//---------------------------------------------------------------------------
bool __fastcall TSlipInfoEditForm::CheckEdit()
{
      if (DM->GetMode(ModePanel) != imNew && SlipInfoNoEdit->Text.ToIntDef(0) == 0){
            Application->MessageBox("ì`ï[èÓïÒÉRÅ[ÉhÇ™ñ≥å¯Ç≈Ç∑", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoNoEdit->SetFocus();
            return false;
      }

      ///// ÉRÅ[Éhèdï°É`ÉFÉbÉN
      NsRecordSet set;
      AnsiString sql;
      sql = " SELECT"
            "     *"
            " FROM"
            "     M_ì`ï[èÓïÒ"
            " WHERE"
            "     ì`ï[èÓïÒÉRÅ[Éh = " + IntToStr(SlipInfoNoEdit->Text.ToIntDef(0)) +
            " AND"
            "     ì`ï[èÓïÒID <> " + IntToStr(id_);
      if (DM->DBI.GetRecordSet(sql, set)){
            Application->MessageBox("ÉRÅ[ÉhÇ™èdï°ÇµÇƒÇ¢Ç‹Ç∑ÅBëºÇÃÉRÅ[ÉhÇéwíËÇµÇƒÇ≠ÇæÇ≥Ç¢", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoNoEdit->SetFocus();
            return false;
      }

      if (SlipInfoNameEdit->Text == ""){
            Application->MessageBox("ì`ï[èÓïÒñºÇ™ñ≥å¯Ç≈Ç∑", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            SlipInfoNameEdit->SetFocus();
            return false;
      }

      if (NyukoTitleEdit1->Text == ""){
            Application->MessageBox("ì¸å…ì`ï[É^ÉCÉgÉã1Ç™ñ≥å¯Ç≈Ç∑", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
            NyukoTitleEdit1->SetFocus();
            return false;
      }

      if (SlipInfoNameEdit->Text.Length() > 40)
            SlipInfoNameEdit->Text = DM->TrimString(SlipInfoNameEdit->Text, 40);

      if (NyukoTitleEdit1->Text.Length() > 16)
            NyukoTitleEdit1->Text = DM->TrimString(NyukoTitleEdit1->Text, 16);

      if (NyukoTitleEdit2->Text.Length() > 16)
            NyukoTitleEdit2->Text = DM->TrimString(NyukoTitleEdit2->Text, 16);

      if (NyukoTitleEdit3->Text.Length() > 16)
            NyukoTitleEdit3->Text = DM->TrimString(NyukoTitleEdit3->Text, 16);

      if (ShukoTitleEdit1->Text.Length() > 16)
            ShukoTitleEdit1->Text = DM->TrimString(ShukoTitleEdit1->Text, 16);

      if (ShukoTitleEdit2->Text.Length() > 16)
            ShukoTitleEdit2->Text = DM->TrimString(ShukoTitleEdit2->Text, 16);

      if (ShukoTitleEdit3->Text.Length() > 16)
            ShukoTitleEdit3->Text = DM->TrimString(ShukoTitleEdit3->Text, 16);

      if (CompanyNameEdit->Text.Length() > 40)
            CompanyNameEdit->Text = DM->TrimString(CompanyNameEdit->Text, 40);

      if (CompanyInfoEdit1->Text.Length() > 40)
            CompanyInfoEdit1->Text = DM->TrimString(CompanyInfoEdit1->Text, 40);

      if (CompanyInfoEdit2->Text.Length() > 40)
            CompanyInfoEdit2->Text = DM->TrimString(CompanyInfoEdit2->Text, 40);

      if (CompanyInfoEdit3->Text.Length() > 40)
            CompanyInfoEdit3->Text = DM->TrimString(CompanyInfoEdit3->Text, 40);

      if (CompanyInfoEdit4->Text.Length() > 40)
            CompanyInfoEdit4->Text = DM->TrimString(CompanyInfoEdit4->Text, 40);

      return true;
}
//---------------------------------------------------------------------------
int __fastcall TSlipInfoEditForm::GetSlipInfoNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT ì`ï[èÓïÒÉRÅ[Éh FROM M_ì`ï[èÓïÒ WHERE ì`ï[èÓïÒÉRÅ[Éh > 0 ORDER BY ì`ï[èÓïÒÉRÅ[Éh", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["ì`ï[èÓïÒÉRÅ[Éh"]))
            break;
        else
            code++;
    }

    if (code > 999){
        Application->MessageBox("ìoò^åèêîÇ™è„å¿Ç…íBÇµÇ‹ÇµÇΩÅB\r\nÇ±ÇÍà»è„ìoò^Ç≈Ç´Ç‹ÇπÇÒÅB",
            this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return -1;
    }

    return code;
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SlipInfoNoPanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TSlipInfoEditForm::SlipInfoNoPanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

