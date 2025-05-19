//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SearchFrm.h"
#include "YubinSearchFrm.h"
#include "TokuisakiEditFrm.h"
#include <StrUtils.hpp>
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TTokuisakiEditForm *TokuisakiEditForm;
//---------------------------------------------------------------------------
__fastcall TTokuisakiEditForm::TTokuisakiEditForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::FormShow(TObject *Sender)
{
	DM->AddComboMap(UseDivComboBox,         use_div_map_,       "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 10 ORDER BY 区分コード");
	DM->AddComboMap(SeikyushoPrintComboBox, seikyu_print_map_,  "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 8  ORDER BY 区分コード");
	DM->AddComboMap(GenkakeComboBox,        genkake_map_,       "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 4  ORDER BY 区分コード");
	DM->AddComboMap(ZanDispComboBox,        zan_disp_map_,      "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 9  ORDER BY 区分コード");
	DM->AddComboMap(MoneyFractionComboBox,  fraction_map_,      "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 5  ORDER BY 区分コード");
	TaxFractionComboBox->Items->Text        = MoneyFractionComboBox->Items->Text;
    ConversionFractionComboBox->Items->Text = MoneyFractionComboBox->Items->Text;
	DM->AddComboMap(NyukinSiteComboBox,     nyukin_site_map_,   "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 6  ORDER BY 区分コード");
	DM->AddComboMap(NyukinMethodComboBox,   nyukin_method_map_, "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 7  ORDER BY 区分コード");
    // 敬称
    DM->AddComboBox_Honorific(HonorificComboBox);
    // 消費税計算区分
    DM->AddComboMap(TaxCalcComboBox,        tax_calc_map_,      "SELECT 区分コード AS コード, 区分名称 AS 名称 FROM M_区分 WHERE 区分分類コード = 13 ORDER BY 区分コード");

	if (id_ == 0)
		SetMode(imNew);
	else
		SetMode(imMod);

	ClearForm();
	if (DM->GetMode(ModePanel) == imMod)
		BrowseRecord();

    is_edit_  = false;
    page_     = MainForm->page;
    keyfield_ = MainForm->keyfield[page_];

	Application->OnMessage = this->AutoKanaMessage;

	CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::FormKeyDown(TObject *Sender, WORD &Key,
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
void __fastcall TTokuisakiEditForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (is_edit_)
		ModalResult = mrOk;
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
int __fastcall TTokuisakiEditForm::ShowModalWithId(int id)
{
	id_ = id;

	return TForm::ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::ClearForm()
{
    int code = GetNo();
    if (code != -1)
        CodeEdit->Text = code;
    else
        CodeEdit->Text = AnsiString();

	NameEdit->Text            = AnsiString();
	ShortNameEdit->Text       = AnsiString();
	KanaEdit->Text            = AnsiString();
	YubinEdit->Text           = AnsiString();
	Address1Edit->Text        = AnsiString();
	Address2Edit->Text        = AnsiString();
	TelEdit->Text             = AnsiString();
	FaxEdit->Text             = AnsiString();
	SyncCodeEdit->Text        = AnsiString();
	UseDivComboBox->ItemIndex = 1;

	SeikyusakiCodeEdit->Text                = AnsiString();
	SeikyusakiNameEdit->Text                = AnsiString();
	SeikyushoPrintComboBox->ItemIndex       = 1;
	GenkakeComboBox->ItemIndex              = 0;
	SimebiEdit->Text                        = AnsiString();
	ZanDispComboBox->ItemIndex              = 1;
	ConversionFractionComboBox->ItemIndex   = 0;
	MoneyFractionComboBox->ItemIndex        = 0;
	TaxFractionComboBox->ItemIndex          = 0;
    TaxCalcComboBox->ItemIndex              = 0;
    HonorificComboBox->ItemIndex            = 0;
	NyukinSiteComboBox->ItemIndex           = 1;
	NyukinbiEdit->Text                      = AnsiString();
	NyukinMethodComboBox->ItemIndex         = 1;
	BankCodeEdit->Text                      = AnsiString();
	BankNameEdit->Text                      = AnsiString();
	BranchNameEdit->Text                    = AnsiString();
	AccountEdit->Text                       = AnsiString();
	AccountNameEdit->Text                   = AnsiString();

	RenewDateEdit->Text  = AnsiString();
	CreateDateEdit->Text = AnsiString();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SetMode(TInputMode mode)
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
int __fastcall TTokuisakiEditForm::GetNo()
{
    int code = 1;
    NsRecordSet set;
    DM->DBI.GetRecordSet("SELECT 得意先コード FROM M_得意先 WHERE 得意先コード > 0 ORDER BY 得意先コード", set);
    for (unsigned int i = 0; i < set.size(); i++){
        if (code != ToInt(set[i]["得意先コード"]))
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
bool __fastcall TTokuisakiEditForm::CheckEdit()
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
          "     M_得意先"
          " WHERE"
          "     得意先コード = " + IntToStr(CodeEdit->Text.ToIntDef(0)) +
          " AND"
          "     得意先ID <> " + IntToStr(id_);
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

    if (NameEdit->Text.Length() > 50)
        NameEdit->Text = DM->TrimString(NameEdit->Text, 50);

    if (ShortNameEdit->Text.Length() > 20)
        ShortNameEdit->Text = DM->TrimString(ShortNameEdit->Text, 20);

    if (KanaEdit->Text.Length() > 50)
        KanaEdit->Text = DM->TrimString(KanaEdit->Text, 50);

    if (Address1Edit->Text.Length() > 40)
        Address1Edit->Text = DM->TrimString(Address1Edit->Text, 40);

    if (Address2Edit->Text.Length() > 40)
        Address2Edit->Text = DM->TrimString(Address2Edit->Text, 40);

    if (SyncCodeEdit->Text.Length() > 20)
        SyncCodeEdit->Text = DM->TrimString(SyncCodeEdit->Text, 20);

    if (AccountNameEdit->Text.Length() > 30)
        AccountNameEdit->Text = DM->TrimString(AccountNameEdit->Text, 30);

	return true;
}
//---------------------------------------------------------------------------
bool __fastcall TTokuisakiEditForm::PostRecord()
{
	NsFieldSet fields;

	fields << NsField("[得意先コード]",       CodeEdit->Text.ToIntDef(0))
		   << NsField("[得意先名称]",         NameEdit->Text)
		   << NsField("[得意先略称]",         ShortNameEdit->Text)
		   << NsField("[得意先カナ]",         KanaEdit->Text)
		   << NsField("[郵便番号]",           YubinEdit->Text)
		   << NsField("[住所1]",              Address1Edit->Text)
		   << NsField("[住所2]",              Address2Edit->Text)
		   << NsField("[電話番号]",           TelEdit->Text)
		   << NsField("[FAX番号]",            FaxEdit->Text)
           << NsField("[連携用コード]",       SyncCodeEdit->Text)
		   << NsField("[使用区分]",           use_div_map_[UseDivComboBox->ItemIndex])
		   << NsField("[請求書発行区分]",     seikyu_print_map_[SeikyushoPrintComboBox->ItemIndex])
		   << NsField("[現掛区分]",           genkake_map_[GenkakeComboBox->ItemIndex])
		   << NsField("[締日]",               SimebiEdit->Text.ToIntDef(0))
		   << NsField("[残高表示区分]",       zan_disp_map_[ZanDispComboBox->ItemIndex])
           << NsField("[換算端数処理区分]",   fraction_map_[ConversionFractionComboBox->ItemIndex])
		   << NsField("[金額端数処理区分]",   fraction_map_[MoneyFractionComboBox->ItemIndex])
		   << NsField("[消費税端数処理区分]", fraction_map_[TaxFractionComboBox->ItemIndex])
           << NsField("[消費税計算区分]",     tax_calc_map_[TaxCalcComboBox->ItemIndex])
		   << NsField("[敬称]",               HonorificComboBox->Text)
		   << NsField("[入金サイト]",         nyukin_site_map_[NyukinSiteComboBox->ItemIndex])
		   << NsField("[入金日]",             NyukinbiEdit->Text.ToIntDef(0))
		   << NsField("[入金方法]",           nyukin_method_map_[NyukinMethodComboBox->ItemIndex])
           << NsField("[銀行ID]",             ToInt(DM->DBI.Lookup("M_銀行", "銀行コード", BankCodeEdit->Text.ToIntDef(0), "銀行ID")))
           << NsField("[口座名義名称]",       AccountNameEdit->Text)
		   << NsField("[更新日時]",           Now());


    // マスタデータ登録/更新
    DM->ADOConnection->BeginTrans();
	try{
		if (id_ == 0){
			fields << NsField("[作成日時]", Now());
			DM->DBI.Insert("M_得意先", fields);
		}else{
            //int seikyu = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "得意先ID", ""));
			fields << NsField("[請求先ID]", ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "得意先ID", "")));
			DM->DBI.Update("M_得意先", "得意先ID", id_, fields);
		}
	}catch (Exception &e){
        DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("登録／修正に失敗しました\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return false;
	}
    DM->ADOConnection->CommitTrans();

    // 新規登録時の請求先IDの登録
    if (id_ == 0){
        DM->ADOConnection->BeginTrans();
        try{
            fields.clear();
            fields << NsField("[請求先ID]", ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", CodeEdit->Text.ToIntDef(0), "得意先ID", "")));

            int id_buff = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", CodeEdit->Text.ToIntDef(0), "得意先ID", ""));
            DM->DBI.Update("M_得意先", "得意先ID", id_buff, fields);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("請求先の更新に失敗しました。登録完了後に再度確認してください。\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
        }
        DM->ADOConnection->CommitTrans();
    }

    // 他のデータの請求情報を更新
    DM->ADOConnection->BeginTrans();
    if (id_ != 0){
        AnsiString sql;
        sql = " UPDATE"
              "     M_得意先"
              " SET"
              "     請求書発行区分 = "     + IntToStr(seikyu_print_map_[SeikyushoPrintComboBox->ItemIndex]) + "," +
              "     現掛区分 = "           + IntToStr(genkake_map_[GenkakeComboBox->ItemIndex]) + "," +
              "     締日 = "               + IntToStr(SimebiEdit->Text.ToIntDef(0)) + "," +
              "     残高表示区分 = "       + IntToStr(zan_disp_map_[ZanDispComboBox->ItemIndex]) + "," +
              "     換算端数処理区分 = "   + IntToStr(fraction_map_[ConversionFractionComboBox->ItemIndex]) + "," +
              "     金額端数処理区分 = "   + IntToStr(fraction_map_[MoneyFractionComboBox->ItemIndex]) + "," +
              "     消費税端数処理区分 = " + IntToStr(fraction_map_[TaxFractionComboBox->ItemIndex]) + "," +
              "     敬称 = '"              + HonorificComboBox->Text + "'," +
              "     入金サイト = "         + IntToStr(nyukin_site_map_[NyukinSiteComboBox->ItemIndex]) + "," +
              "     入金日 = "             + IntToStr(NyukinbiEdit->Text.ToIntDef(0)) + "," +
              "     入金方法 = "           + IntToStr(nyukin_method_map_[NyukinMethodComboBox->ItemIndex]) + "," +
              "     銀行ID = "             + IntToStr(ToInt(DM->DBI.Lookup("M_銀行", "銀行コード", BankCodeEdit->Text.ToIntDef(0), "銀行ID"))) + "," +
              "     口座名義名称 = '"      + AccountNameEdit->Text + "'," +
              "     更新日時 = GETDATE()"
              " WHERE"
              "     請求先ID = " + IntToStr(ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "得意先ID")));
        try{
            DM->DBI.Execute(sql);
        }catch (Exception &e){
            DM->ADOConnection->RollbackTrans();
            Application->MessageBox(("請求情報の更新に失敗しました\r\n" + e.Message).c_str(), this->Caption.c_str(), MB_OK | MB_ICONHAND);
            return false;
        }
    }
    DM->ADOConnection->CommitTrans();

	is_edit_ = true;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BrowseRecord()
{
	NsRecordSet set;
	AnsiString sql = "SELECT * FROM V_得意先 WHERE 得意先ID = " + IntToStr(id_);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("該当するデータがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		ClearForm();
		id_ = 0;
		return;
	}

	id_                       = ToInt(set[0]["得意先ID"]);
	CodeEdit->Text            = ToString(set[0]["得意先コード"]);
	NameEdit->Text            = ToString(set[0]["得意先名称"]);
	ShortNameEdit->Text       = ToString(set[0]["得意先略称"]);
	KanaEdit->Text            = ToString(set[0]["得意先カナ"]);
	YubinEdit->Text           = ToString(set[0]["郵便番号"]);
	Address1Edit->Text        = ToString(set[0]["住所1"]);
	Address2Edit->Text        = ToString(set[0]["住所2"]);
	TelEdit->Text             = ToString(set[0]["電話番号"]);
	FaxEdit->Text             = ToString(set[0]["FAX番号"]);
    SyncCodeEdit->Text        = ToString(set[0]["連携用コード"]);
	UseDivComboBox->ItemIndex = DM->SearchIndex(use_div_map_, ToInt(set[0]["使用区分"]));

	SeikyusakiCodeEdit->Text          = ToString(set[0]["請求先コード"]);
	SeikyushoPrintComboBox->ItemIndex = DM->SearchIndex(seikyu_print_map_, ToInt(set[0]["請求書発行区分"]));
	GenkakeComboBox->ItemIndex        = DM->SearchIndex(genkake_map_, ToInt(set[0]["現掛区分"]));
	SimebiEdit->Text                  = ToString(set[0]["締日"]);
	ZanDispComboBox->ItemIndex        = DM->SearchIndex(zan_disp_map_, ToInt(set[0]["残高表示区分"]));
    ConversionFractionComboBox->ItemIndex = DM->SearchIndex(fraction_map_, ToInt(set[0]["換算端数処理区分"]));
	MoneyFractionComboBox->ItemIndex  = DM->SearchIndex(fraction_map_, ToInt(set[0]["金額端数処理区分"]));
	TaxFractionComboBox->ItemIndex    = DM->SearchIndex(fraction_map_, ToInt(set[0]["消費税端数処理区分"]));
    TaxCalcComboBox->ItemIndex        = DM->SearchIndex(tax_calc_map_, ToInt(set[0]["消費税計算区分"]));
    HonorificComboBox->Text           = ToString(set[0]["敬称"]);
	NyukinSiteComboBox->ItemIndex     = DM->SearchIndex(nyukin_site_map_, ToInt(set[0]["入金サイト"]));
	NyukinbiEdit->Text                = ToString(set[0]["入金日"]);
	NyukinMethodComboBox->ItemIndex   = DM->SearchIndex(nyukin_method_map_, ToInt(set[0]["入金方法"]));
    BankCodeEdit->Text                = ToString(set[0]["銀行コード"]);
    BranchNameEdit->Text              = ToString(set[0]["支店名称"]);
    AccountEdit->Text                 = ToString(set[0]["口座"]);
    AccountNameEdit->Text             = ToString(set[0]["口座名義名称"]);

	RenewDateEdit->Text  = VarToDateTime(set[0]["更新日時"]).FormatString("yyyy/mm/dd hh:nn");
	CreateDateEdit->Text = VarToDateTime(set[0]["作成日時"]).FormatString("yyyy/mm/dd hh:nn");
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AutoKanaMessage(tagMSG &Msg, bool &Handled)
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
void __fastcall TTokuisakiEditForm::Action1Execute(TObject *Sender)
{
    id_ = 0;
    SetMode(imNew);
    ClearForm();
    is_edit_ = false;
    CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action3Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) != imMod)
        return;

    if (!DM->DBI.IsExist("M_得意先", "得意先ID", id_)){
        Application->MessageBox("対象データ抽出に失敗しました", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
        return;
    }

    AnsiString msg = AnsiString();
    DM->ADOConnection->BeginTrans();
    if (ToInt(DM->DBI.Lookup("M_得意先", "得意先ID", id_, "使用区分")) != 0){

        if (Application->MessageBox("このデータを使用出来なくなります。よろしいですか？\r\nなお、本当に削除する場合は一度この処理を行なった後\r\nもう一度削除ボタンをクリックして下さい",
                "削除", MB_YESNO | MB_ICONQUESTION) != IDYES)
            return;

        NsFieldSet fields;
        try{
            fields << NsField("[使用区分]", 0);
            DM->DBI.Update("M_得意先", "得意先ID", id_, fields);
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
        keys << NsField("[得意先ID]", id_);
        try{
            DM->DBI.Delete("M_得意先", keys);
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
void __fastcall TTokuisakiEditForm::Action4Execute(TObject *Sender)
{
    if (ActiveControl == CodeEdit)
        SaibanButton->OnClick(NULL);
    else if (ActiveControl == YubinEdit)
        YubinSearchButton->OnClick(NULL);
    else if (ActiveControl == SeikyusakiCodeEdit || ActiveControl == SeikyusakiNameEdit)
        SeikyusakiSearchButton->OnClick(NULL);
    else if (ActiveControl == BankCodeEdit || ActiveControl == BankNameEdit)
        BankSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action5Execute(TObject *Sender)
{
	if (!CheckEdit())
		return;

	if (Application->MessageBox("登録／修正しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	if (!PostRecord())
		return;

	Application->MessageBox("登録／修正しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    // 登録時に敬称が増えるケースを考えて敬称コンボボックス再設定
    DM->AddComboBox_Honorific(HonorificComboBox);

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
void __fastcall TTokuisakiEditForm::Action7Execute(TObject *Sender)
{
    if (DM->GetMode(ModePanel) == imMod && DM->M_Tokuisaki->Bof)
        return;

    if (DM->GetMode(ModePanel) == imNew){
        ClearForm();
        SetMode(imMod);
        is_edit_ = false;
        DM->M_Tokuisaki->Last();
    }else
        DM->M_Tokuisaki->Prior();

    id_ = DM->M_Tokuisaki->FieldByName("得意先ID")->AsInteger;
    BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action8Execute(TObject *Sender)
{
	if (DM->M_Tokuisaki->Eof)
		return;

	DM->M_Tokuisaki->Next();
	id_ = DM->M_Tokuisaki->FieldByName("得意先ID")->AsInteger;
	BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodeEditExit(TObject *Sender)
{
    if (CodeEdit->Text == "")
        return;

    NsRecordSet set;
    if (!DM->DBI.GetRecordSet("SELECT 得意先ID FROM M_得意先 WHERE 得意先コード = " + CodeEdit->Text + " AND 得意先ID <> " + IntToStr(id_), set))
        return;

    if (Application->MessageBox("同一コードが登録されています。\r\n修正モードで呼び出しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) != IDYES)
        return;

    SetMode(imMod);
    id_ = ToInt(set[0]["得意先ID"]);
    BrowseRecord();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SaibanButtonClick(TObject *Sender)
{
    CodeEdit->Text = GetNo();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NameEditExit(TObject *Sender)
{
	if (DM->GetMode(ModePanel) == imMod)
		return;

	if (NameEdit->Text == "")
		return;

	ShortNameEdit->Text = AnsiSubString(DM->Formal2Informal(NameEdit->Text), 1, 20);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AddressSearchButtonClick(
	  TObject *Sender)
{
	AnsiString sql = AnsiString();
	NsRecordSet set;
	AnsiString postal_code = YubinEdit->Text;
	postal_code = AnsiReplaceStr(postal_code, "-", "");
	if (postal_code.ToIntDef(0) == 0){
		Application->OnMessage = this->AutoKanaMessage;
		return;
	}

	sql = "SELECT 都道府県名, 市区町村名, 町域名 FROM M_郵便番号 WHERE 郵便番号 = " + postal_code;
	set.clear();
	if (!DM->DBI.GetRecordSet(sql, set)){
		if (Application->MessageBox("該当する郵便番号が見つかりませんでした", "郵便番号検索", MB_OK | MB_ICONEXCLAMATION) != IDYES){
			Application->OnMessage = this->AutoKanaMessage;
			return;
		}
	}

	if (Address1Edit->Text != "" || Address2Edit->Text != ""){
		if (Application->MessageBox("該当する郵便番号が見つかりました\r\n上書きしてよろしいですか？", "郵便番号検索", MB_YESNO | MB_ICONQUESTION) != IDYES){
			Application->OnMessage = this->AutoKanaMessage;
			return;
		}
	}

	AnsiString address = ToString(set[0]["都道府県名"]) + ToString(set[0]["市区町村名"]) + ToString(set[0]["町域名"]);
	Address1Edit->Text = AnsiDivide(&address, 40);
	Address2Edit->Text = AnsiDivide(&address, 40);
	Address1Edit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::YubinSearchButtonClick(TObject *Sender)
{
	if (YubinSearchForm->ShowModal() == mrCancel)
		return;

	if (YubinEdit->Text != ""){
		if (Application->MessageBox("現在入力されている郵便番号に上書きしてよろしいですか？",
				this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
			return;
	}

	YubinEdit->Text    = YubinSearchForm->YubinEdit->Text;
	AnsiString address = YubinSearchForm->KenListBox->Items->Strings[YubinSearchForm->KenListBox->ItemIndex] +
    YubinSearchForm->SiListBox->Items->Strings[YubinSearchForm->SiListBox->ItemIndex] +
    YubinSearchForm->TyouikiListBox->Items->Strings[YubinSearchForm->TyouikiListBox->ItemIndex];
	Address1Edit->Text = AnsiDivide(&address, 40);
	Address2Edit->Text = AnsiDivide(&address, 40);
	YubinEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiCodeEditChange(
	  TObject *Sender)
{
	if (SeikyusakiCodeEdit->Text == ""){
		SeikyusakiNameEdit->Text = AnsiString();
		return;
	}

    NsRecordSet set;
    if (!DM->DBI.GetRecordSet("SELECT * FROM V_得意先 WHERE 得意先コード = " + IntToStr(SeikyusakiCodeEdit->Text.ToIntDef(0)), set)){

        if (DM->GetMode(ModePanel) == imNew && CodeEdit->Text.ToIntDef(0) == SeikyusakiCodeEdit->Text.ToIntDef(0))
        	SeikyusakiNameEdit->Text = ShortNameEdit->Text;
        else
            SeikyusakiNameEdit->Text = AnsiString();

    	SeikyushoPrintComboBox->ItemIndex = 1;
    	GenkakeComboBox->ItemIndex        = 0;
    	SimebiEdit->Text                  = AnsiString();
    	ZanDispComboBox->ItemIndex        = 1;
        ConversionFractionComboBox->ItemIndex = 0;
    	MoneyFractionComboBox->ItemIndex  = 0;
    	TaxFractionComboBox->ItemIndex    = 0;
	    NyukinSiteComboBox->ItemIndex     = 1;
    	NyukinbiEdit->Text                = AnsiString();
	    NyukinMethodComboBox->ItemIndex   = 1;
        BankCodeEdit->Text                = AnsiString();
        BranchNameEdit->Text              = AnsiString();
        AccountEdit->Text                 = AnsiString();
        AccountNameEdit->Text             = AnsiString();
        return;
    }

	SeikyusakiCodeEdit->Text          = ToString(set[0]["得意先コード"]);
    SeikyusakiNameEdit->Text          = ToString(set[0]["得意先略称"]);
	SeikyushoPrintComboBox->ItemIndex = DM->SearchIndex(seikyu_print_map_, ToInt(set[0]["請求書発行区分"]));
	GenkakeComboBox->ItemIndex        = DM->SearchIndex(genkake_map_, ToInt(set[0]["現掛区分"]));
	SimebiEdit->Text                  = ToString(set[0]["締日"]);
	ZanDispComboBox->ItemIndex        = DM->SearchIndex(zan_disp_map_, ToInt(set[0]["残高表示区分"]));
    ConversionFractionComboBox->ItemIndex = DM->SearchIndex(fraction_map_, ToInt(set[0]["換算端数処理区分"]));
	MoneyFractionComboBox->ItemIndex  = DM->SearchIndex(fraction_map_, ToInt(set[0]["金額端数処理区分"]));
	TaxFractionComboBox->ItemIndex    = DM->SearchIndex(fraction_map_, ToInt(set[0]["消費税端数処理区分"]));
	NyukinSiteComboBox->ItemIndex     = DM->SearchIndex(nyukin_site_map_, ToInt(set[0]["入金サイト"]));
	NyukinbiEdit->Text                = ToString(set[0]["入金日"]);
	NyukinMethodComboBox->ItemIndex   = DM->SearchIndex(nyukin_method_map_, ToInt(set[0]["入金方法"]));
    BankCodeEdit->Text                = ToString(set[0]["銀行コード"]);
    BranchNameEdit->Text              = ToString(set[0]["支店名称"]);
    AccountEdit->Text                 = ToString(set[0]["口座"]);
    AccountNameEdit->Text             = ToString(set[0]["口座名義名称"]);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiCodeEditExit(TObject *Sender)
{
	if (SeikyusakiCodeEdit->Text != "")
		return;

	SeikyusakiCodeEdit->Text = CodeEdit->Text;
	SeikyusakiNameEdit->Text = ShortNameEdit->Text;
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiSearchButtonClick(
	  TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT 得意先コード AS 請求先コード, 得意先略称 AS 請求先略称, 得意先カナ AS 請求先カナ, 住所1, 住所2, 電話番号 FROM V_得意先";
    SearchForm->orderby_sql      = " ORDER BY 得意先コード";
    SearchForm->table_name       = " V_得意先";
    SearchForm->list_->CommaText = " 得意先コード,得意先略称,得意先カナ,住所1,住所2,電話番号";

    if (SearchForm->ShowModal() != mrOk)
        return;
    SeikyusakiCodeEdit->Text = SearchForm->Query->FieldByName("請求先コード")->AsInteger;
    SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BankSearchButtonClick(TObject *Sender)
{
    SearchForm->Top              = Application->MainForm->Top + 50;
    SearchForm->Left             = (Application->MainForm->Left + Application->MainForm->Width) - SearchForm->Width;
    SearchForm->based_sql        = " SELECT 銀行コード, 銀行名称, 支店名称, 口座 FROM V_銀行";
    SearchForm->orderby_sql      = " ORDER BY 銀行コード";
    SearchForm->table_name       = " V_銀行";
    SearchForm->list_->CommaText = " 銀行コード,銀行名称,支店名称,口座";

    if (SearchForm->ShowModal() != mrOk)
        return;
    BankCodeEdit->Text = SearchForm->Query->FieldByName("銀行コード")->AsInteger;
    AccountNameEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodeEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  コードを入力して下さい（採番[F4]を押す事で、空き番検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  名称を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::ShortNameEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  必要な場合略称を変更して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::KanaEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  必要な場合カナを変更して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::YubinEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  郵便番号を入力して下さい（入力後、住所検索をクリックすると住所が自動入力されます。また郵便番号検索[F4]で郵便番号の検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Address1EditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  住所1を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::Address2EditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  住所2を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::TelEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  電話番号を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::FaxEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  FAX番号を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::UseDivComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  使用区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::UseDivComboBoxExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyusakiCodeEditEnter(
	  TObject *Sender)
{
	StatusBar->SimpleText = "  請求先を入力して下さい。（[F4] 請求先検索を行います）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SeikyushoPrintComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  請求書発行区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::GenkakeComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  現掛区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::SimebiEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  締日を入力して下さい（末日は[99]を入力して下さい）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::ZanDispComboBoxEnter(TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  残高表示区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::MoneyFractionComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  金額端数処理区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::TaxFractionComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  消費税端数処理区分を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NyukinSiteComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  入金サイトを選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NyukinbiEditEnter(TObject *Sender)
{
	StatusBar->SimpleText = "  入金日を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::NyukinMethodComboBoxEnter(
	  TObject *Sender)
{
	Action4->Enabled = false;

	StatusBar->SimpleText = "  入金方法を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BankCodeEditChange(TObject *Sender)
{
      NsRecordSet set;
      AnsiString sql;
      sql = "SELECT * FROM V_銀行 WHERE 銀行コード = " + IntToStr(BankCodeEdit->Text.ToIntDef(0));
      if (!DM->DBI.GetRecordSet(sql, set)){
            BankNameEdit->Text      = AnsiString();
            BranchNameEdit->Text    = AnsiString();
            AccountEdit->Text       = AnsiString();
            return;
      }

      BankNameEdit->Text      = ToString(set[0]["銀行名称"]);
      BranchNameEdit->Text    = ToString(set[0]["支店名称"]);
      AccountEdit->Text       = ToString(set[0]["口座"]);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::BankCodeEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  銀行を選択して下さい（[F4] 候補を表示します）";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AccountNameEditEnter(TObject *Sender)
{
      StatusBar->SimpleText = "  口座名義名称を入力して下さい";
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::AccountNameEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	Action5->OnExecute(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodePanelEnter(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00A8A8A8);
}
//---------------------------------------------------------------------------
void __fastcall TTokuisakiEditForm::CodePanelExit(TObject *Sender)
{
	((TPanel *)Sender)->Color = TColor(0x00E1E1E1);
}
//---------------------------------------------------------------------------

