//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SearchFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	Application->OnMessage = this->MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Connected = false;

	try{
		DM->ADOConnection->Connected = true;
	}catch (Exception &e){
		Application->MessageBox(("データベース接続に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		Close();
	}

	DM->CFG.Load(&DM->DBI);

	SetItem();

	DayRadioButton->Checked = true;
	DayRadioButton->OnClick(NULL);
	TokuCodeEdit->Text  = AnsiString();
	HinCodeEdit->Text   = AnsiString();
	Item1CodeEdit->Text = AnsiString();
	Item2CodeEdit->Text = AnsiString();
	TaniCodeEdit->Text  = AnsiString();

	DM->Q_Itiran->Close();

	PriceEdit->Text     = AnsiString();

	FromDatePicker->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriorButtonClick(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, -1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, 1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DayRadioButtonClick(TObject *Sender)
{
	FromDatePicker->Date = Date();
	ToDatePicker->Date = Date();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MonthRadioButtonClick(TObject *Sender)
{
	FromDatePicker->Date = GetFirstDate(Date());
	ToDatePicker->Date = GetLastDate(Date());
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::YearRadioButtonClick(TObject *Sender)
{
	WORD y, m, d;
	Date().DecodeDate(&y, &m, &d);

	m = ToInt(DM->CFG["期首日付"]);

	try{
		FromDatePicker->Date = EncodeDate(y, m, 1);
	}catch (...){
		FromDatePicker->Date = EncodeDate(y, 4, 1);
	}
	ToDatePicker->Date = IncYear(FromDatePicker->Date, 1) - 1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuCodeEditChange(TObject *Sender)
{
	if (TokuCodeEdit->Text == ""){
		TokuNameEdit->Text = AnsiString();
		return;
	}
	TokuNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 得意先コード, 得意先略称 FROM M_得意先 WHERE 使用区分 = 1";
	SearchForm->orderby_sql = " ORDER BY 得意先コード ";
	SearchForm->table_name = "M_得意先";
	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	TokuCodeEdit->OnChange(NULL);
	TokuCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinCodeEditChange(TObject *Sender)
{
	if (HinCodeEdit->Text == ""){
		HinNameEdit->Text = AnsiString();
		return;
	}
	HinNameEdit->Text = ToString(DM->DBI.Lookup("M_品目", "品目コード", HinCodeEdit->Text.ToIntDef(0), "品目名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HinButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 品目コード, 品目略称, 取引区分名称 AS 取引区分 FROM V_品目 WHERE 使用区分 = 1";
	SearchForm->orderby_sql = " ORDER BY 品目コード ";
	SearchForm->table_name = "M_品目";
	if (SearchForm->ShowModal() != mrOk)
		return;
	HinCodeEdit->Text = SearchForm->Query->FieldByName("品目コード")->AsInteger;
	HinCodeEdit->OnChange(NULL);
	HinCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1CodeEditChange(TObject *Sender)
{
	if (Item1CodeEdit->Text == ""){
		Item1NameEdit->Text = AnsiString();
		return;
	}
	Item1NameEdit->Text = ToString(DM->DBI.Lookup("M_項目1", "項目1コード", Item1CodeEdit->Text.ToIntDef(0), "項目1名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item1ButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 項目1コード, 項目1略称 FROM M_項目1 WHERE 使用区分 = 1";
	SearchForm->orderby_sql = " ORDER BY 項目1コード ";
	SearchForm->table_name = "M_項目1";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item1CodeEdit->Text = SearchForm->Query->FieldByName("項目1コード")->AsInteger;
	Item1CodeEdit->OnChange(NULL);
	Item1CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2CodeEditChange(TObject *Sender)
{
	if (Item2CodeEdit->Text == ""){
		Item2NameEdit->Text = AnsiString();
		return;
	}
	Item2NameEdit->Text = ToString(DM->DBI.Lookup("M_項目2", "項目2コード", Item2CodeEdit->Text.ToIntDef(0), "項目2名称", "使用区分 = 1"));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Item2ButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 項目2コード, 項目2略称 FROM M_項目2 WHERE 使用区分 = 1";
	SearchForm->orderby_sql = " ORDER BY 項目2コード ";
	SearchForm->table_name = "M_項目2";
	if (SearchForm->ShowModal() != mrOk)
		return;
	Item2CodeEdit->Text = SearchForm->Query->FieldByName("項目2コード")->AsInteger;
	Item2CodeEdit->OnChange(NULL);
	Item2CodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TaniCodeEditChange(TObject *Sender)
{
	if (TaniCodeEdit->Text == ""){
		TaniNameEdit->Text = AnsiString();
		return;
	}
	TaniNameEdit->Text = ToString(DM->DBI.Lookup("M_単位", "単位コード", TaniCodeEdit->Text.ToIntDef(0), "単位名称", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TaniButtonClick(TObject *Sender)
{
	SearchForm->Top = MainForm->Top;
	SearchForm->Left = MainForm->Left + 450;
	SearchForm->based_sql = "SELECT 単位コード, 単位名称 FROM M_単位 ";
	SearchForm->orderby_sql = " ORDER BY 単位コード ";
	SearchForm->table_name = "M_単位";
	if (SearchForm->ShowModal() != mrOk)
		return;
	TaniCodeEdit->Text = SearchForm->Query->FieldByName("単位コード")->AsInteger;
	TaniCodeEdit->OnChange(NULL);
	TaniCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
// マスタから一括更新
void __fastcall TMainForm::UpdateAllButtonClick(TObject *Sender)
{
    if (Application->MessageBox("指定範囲のデータを全て更新します。本当に実行してよろしいですか？", Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
        return;

    UpdateAllButton->Enabled  = false;
    ExtractionButton->Enabled = false;
    RunButton->Enabled        = false;

    try{
        DM->ADOConnection->BeginTrans();

        int count = UpdateAllFromMaster();

        DM->ADOConnection->CommitTrans();

        AnsiString msg = "計量/取引で " + IntToStr(count) + "件のデータを更新しました";
        Application->MessageBox(msg.c_str(), UpdateAllButton->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

    }catch(Exception& e){
        DM->ADOConnection->RollbackTrans();

        AnsiString msg = "更新中にエラーが発生しました - " + e.Message;
        Application->MessageBox(msg.c_str(), UpdateAllButton->Caption.c_str(), MB_OK | MB_ICONSTOP);
    }

    UpdateAllButton->Enabled  = true;
    ExtractionButton->Enabled = true;
    RunButton->Enabled        = true;
}
//---------------------------------------------------------------------------
int __fastcall TMainForm::UpdateAllFromMaster()
{
    int date_from = FromDatePicker->Date.FormatString("yyyymmdd").ToInt();
    int date_to   = ToDatePicker->Date.FormatString("yyyymmdd").ToInt();
    TDateTime now(Now());

    AnsiString sql;
    NsRecordSet set;
    NsRecordSet toku_set;
    NsFieldSet fields;

    int date, toku_id, meig_id, item1_id, item2_id, tani_id;
    Currency qty, tanka;
    Currency tax_rate;
    int amount, amount_div, tax, tax_div;
    int count = 0;

    ///// 計量データ更新
    sql = "SELECT * FROM D_計量 WHERE 計量日 >= " + IntToStr(date_from) + " AND 計量日 <= " + IntToStr(date_to) + " AND 完了区分 = 1";
    DM->DBI.GetRecordSet(sql, set);
    for (unsigned int i = 0; i < set.size(); i++){
        date     = ToInt(set[i]["計量日"]);
        toku_id  = ToInt(set[i]["得意先ID"]);
        meig_id  = ToInt(set[i]["品目ID"]);
        item1_id = ToInt(set[i]["項目1ID"]);
        item2_id = ToInt(set[i]["項目2ID"]);
        tani_id  = ToInt(set[i]["単位ID"]);
        qty      = ToCurrency(set[i]["数量"]);
        tanka    = DM->GetTanka(toku_id, meig_id, item1_id, item2_id, tani_id);

        DM->DBI.GetRecordSet("SELECT * FROM M_得意先 WHERE 得意先ID = " + IntToStr(toku_id), toku_set);

    	amount_div = -1;
	    if (!toku_set.empty()){
		    if (!IsNull(SET_TOP(toku_set)["金額端数処理区分"]))
			    amount_div = ToInt(SET_TOP(toku_set)["金額端数処理区分"]);
	    }
	    if (amount_div == -1)
		    amount_div = ToInt(DM->CFG["金額端数処理区分"]);

        amount = ExtendedRound(qty * tanka, 0, amount_div);

	    tax_rate = DM->GetSalesTax(date);			// 消費税率

	    tax_div = -1;
    	if (!toku_set.empty()){
	    	if (!IsNull(SET_TOP(toku_set)["消費税端数処理区分"]))
		    	tax_div = ToInt(SET_TOP(toku_set)["消費税端数処理区分"]);
    	}
	    if (tax_div == -1)
		    tax_div = ToInt(DM->CFG["消費税端数処理区分"]);

    	tax    = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

        fields.clear();
        fields << NsField("[単価]",     tanka)
               << NsField("[金額]",     amount)
               << NsField("[消費税額]", tax)
               << NsField("[更新日時]", now);
        DM->DBI.Update("D_計量", "計量ID", ToInt(set[i]["計量ID"]), fields);


        count++;
    }

    ///// 取引データ更新
    sql = "SELECT * FROM D_取引 WHERE 取引日 >= " + IntToStr(date_from) + " AND 取引日 <= " + IntToStr(date_to) + " AND 完了区分 = 1";
    DM->DBI.GetRecordSet(sql, set);
    for (unsigned int i = 0; i < set.size(); i++){
        date     = ToInt(set[i]["取引日"]);
        toku_id  = ToInt(set[i]["得意先ID"]);
        meig_id  = ToInt(set[i]["品目ID"]);
        item1_id = ToInt(set[i]["項目1ID"]);
        item2_id = ToInt(set[i]["項目2ID"]);
        tani_id  = ToInt(set[i]["単位ID"]);
        qty      = ToCurrency(set[i]["数量"]);
        tanka    = DM->GetTanka(toku_id, meig_id, item1_id, item2_id, tani_id);

        DM->DBI.GetRecordSet("SELECT * FROM M_得意先 WHERE 得意先ID = " + IntToStr(toku_id), toku_set);

    	amount_div = -1;
	    if (!toku_set.empty()){
		    if (!IsNull(SET_TOP(toku_set)["金額端数処理区分"]))
			    amount_div = ToInt(SET_TOP(toku_set)["金額端数処理区分"]);
	    }
	    if (amount_div == -1)
		    amount_div = ToInt(DM->CFG["金額端数処理区分"]);

        amount = ExtendedRound(qty * tanka, 0, amount_div);

	    tax_rate = DM->GetSalesTax(date);			// 消費税率

	    tax_div = -1;
    	if (!toku_set.empty()){
	    	if (!IsNull(SET_TOP(toku_set)["消費税端数処理区分"]))
		    	tax_div = ToInt(SET_TOP(toku_set)["消費税端数処理区分"]);
    	}
	    if (tax_div == -1)
		    tax_div = ToInt(DM->CFG["消費税端数処理区分"]);

    	tax    = ExtendedRound(Currency(amount) * tax_rate, 0, tax_div);

        fields.clear();
        fields << NsField("[単価]",     tanka)
               << NsField("[金額]",     amount)
               << NsField("[消費税額]", tax)
               << NsField("[更新日時]", now);
        DM->DBI.Update("D_取引", "取引ID", ToInt(set[i]["取引ID"]), fields);


        count++;
    }
    return count;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExtractionButtonClick(TObject *Sender)
{
	DM->Q_Itiran->Close();

	AnsiString where = AnsiString();

	if (TokuCodeEdit->Text != "")
		where += " AND 得意先コード = " + TokuCodeEdit->Text;

	if (HinCodeEdit->Text != "")
		where += " AND 品目コード = " + HinCodeEdit->Text;

	if (Item1CodeEdit->Text != "")
		where += " AND 項目1コード = " + Item1CodeEdit->Text;

	if (Item2CodeEdit->Text != "")
		where += " AND 項目2コード = " + Item2CodeEdit->Text;

	if (TaniCodeEdit->Text != "")
		where += " AND 単位コード = " + TaniCodeEdit->Text;

	DM->Q_Itiran->SQL->Text = DM->GetExtractionQuery(where);

	DM->Q_Itiran->Parameters->ParamByName("DATE_FROM")->Value = DateToInt(FromDatePicker->Date);
	DM->Q_Itiran->Parameters->ParamByName("DATE_TO")->Value   = DateToInt(ToDatePicker->Date);
	DM->Q_Itiran->Parameters->ParamByName("GENKAKE")->Value   = GenkakeComboBox->ItemIndex + 1;

	try{
		DM->Q_Itiran->Open();
	}catch (Exception &e){
		Application->MessageBox(("変更対象データの抽出に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
	}

	Application->OnMessage = this->MessageProc;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SelectButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->First();
	for (int i = 0; i < DBGrid->DataSource->DataSet->RecordCount; i++){
		DBGrid->SelectedRows->CurrentRowSelected = true;
		DBGrid->DataSource->DataSet->Next();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReleaseButtonClick(TObject *Sender)
{
	DBGrid->DataSource->DataSet->First();
	for (int i = 0; i < DBGrid->DataSource->DataSet->RecordCount; i++){
		DBGrid->SelectedRows->CurrentRowSelected = false;
		DBGrid->DataSource->DataSet->Next();
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RunButtonClick(TObject *Sender)
{
	int c = 0;
	DataMap data_map;

	try{
		DM->ADOConnection->BeginTrans();

		data_map.clear();
		DBGrid->DataSource->DataSet->First();
		while(!DBGrid->DataSource->DataSet->Eof){
			if (!DBGrid->SelectedRows->CurrentRowSelected){
				DBGrid->DataSource->DataSet->Next();
				continue;
			}
			data_map[c].div       = DBGrid->DataSource->DataSet->FieldByName("データ区分")->AsInteger;
			data_map[c].id        = DBGrid->DataSource->DataSet->FieldByName("ID")->AsInteger;
			data_map[c].base      = DBGrid->DataSource->DataSet->FieldByName("拠点ID")->AsInteger;
			data_map[c].date      = DBGrid->DataSource->DataSet->FieldByName("日付")->AsInteger;
			data_map[c].slip_no   = DBGrid->DataSource->DataSet->FieldByName("伝票No")->AsInteger;
			data_map[c].toku_code = DBGrid->DataSource->DataSet->FieldByName("得意先コード")->AsInteger;
			data_map[c].amount    = DBGrid->DataSource->DataSet->FieldByName("数量")->AsCurrency;

			c++;
			DBGrid->DataSource->DataSet->Next();
		}

		if (c <= 0){
			Application->MessageBox("変更対象データが選択されていません。\r\nデータ選択後、再度実行してください。",
				this->Caption.c_str(), MB_OK | MB_ICONWARNING);
			DM->ADOConnection->RollbackTrans();
			return;
		}

		int fraction;
		NsFieldSet fields, keys;
		NsRecordSet set;
		AnsiString sql = AnsiString();
		for (DataMap::iterator i = data_map.begin(); i != data_map.end(); i++){
			fraction = ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", i->second.toku_code, "金額端数処理区分", ""));
			fields.clear();
			Currency money = ExtendedRound(StrToCurrDef(PriceEdit->Text, 0) * i->second.amount, 0, fraction);
			Currency tax_rate = GetTaxRate(i->second.date);
			fields << NsField("[単価]", StrToCurrDef(PriceEdit->Text, 0))
				   << NsField("[金額]", money)
				   << NsField("[消費税額]", ExtendedRound(money * tax_rate, 0, fraction));

			switch (i->second.div){
			case 1: // 計量
				DM->DBI.Update("D_計量", "計量ID", i->second.id, fields);

				sql = "SELECT SUM(金額) AS 伝票金額 FROM V_計量 WHERE 拠点ID = " + IntToStr(i->second.base)
															  + " AND 計量日 = " + IntToStr(i->second.date)
															  + " AND 伝票No = " + IntToStr(i->second.slip_no);
				keys.clear();
				keys << NsField("拠点ID", i->second.base)
					 << NsField("計量日", i->second.date)
					 << NsField("伝票No", i->second.slip_no);

				set.clear();
				DM->DBI.GetRecordSet(sql, set);

				fields.clear();
				if (ToCurrency(set[0]["伝票金額"]) == 0)
					fields << NsField("[伝票消費税額]", 0);
				else
					fields << NsField("[伝票消費税額]", ExtendedRound(ToCurrency(set[0]["伝票金額"]) * tax_rate, 0, fraction));

				DM->DBI.Update("D_計量", keys, fields);
				break;
			case 2: // 取引
				DM->DBI.Update("D_取引", "取引ID", i->second.id, fields);

				sql = "SELECT SUM(金額) AS 伝票金額 FROM V_取引 WHERE 拠点ID = " + IntToStr(i->second.base)
															  + " AND 取引日 = " + IntToStr(i->second.date)
															  + " AND 伝票No = " + IntToStr(i->second.slip_no);

				keys.clear();
				keys << NsField("拠点ID", i->second.base)
					 << NsField("取引日", i->second.date)
					 << NsField("伝票No", i->second.slip_no);

				set.clear();
				DM->DBI.GetRecordSet(sql, set);

				fields.clear();
				if (ToCurrency(set[0]["伝票金額"]) == 0)
					fields << NsField("[伝票消費税額]", 0);
				else
					fields << NsField("[伝票消費税額]", ExtendedRound(ToCurrency(set[0]["伝票金額"]) * tax_rate, 0, fraction));

				DM->DBI.Update("D_取引", keys, fields);
				break;
			}
		}

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("単価の変更に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	Application->MessageBox("単価変更が完了しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	ExtractionButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EndButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetItem()
{
	AnsiString cap = ToString(DM->CFG["得意先マスタ名称"]);
	if (ToString(DM->CFG["得意先マスタ使用区分"]) == "1"){
		TokuLabel->Caption = cap;
		DBGrid->Columns->Items[4]->Title->Caption  = cap;
	}else{
		TokuLabel->Caption = "未使用";
		DBGrid->Columns->Items[4]->Title->Caption  = "未使用";
	}

	cap = ToString(DM->CFG["品目マスタ名称"]);
	if (ToString(DM->CFG["品目マスタ使用区分"]) == "1"){
		HinLabel->Caption = cap;
		DBGrid->Columns->Items[6]->Title->Caption  = cap;
	}else{
		HinLabel->Caption = "未使用";
		DBGrid->Columns->Items[6]->Title->Caption  = "未使用";
	}

	cap = ToString(DM->CFG["項目1マスタ名称"]);
	if (ToString(DM->CFG["項目1マスタ使用区分"]) == "1"){
		Item1Label->Caption = cap;
		DBGrid->Columns->Items[12]->Title->Caption  = cap;
	}else{
		Item1Label->Caption = "未使用";
		DBGrid->Columns->Items[12]->Title->Caption  = "未使用";
	}

	cap = ToString(DM->CFG["項目2マスタ名称"]);
	if (ToString(DM->CFG["項目2マスタ使用区分"]) == "1"){
		Item2Label->Caption = cap;
		DBGrid->Columns->Items[14]->Title->Caption  = cap;
	}else{
		Item2Label->Caption = "未使用";
		DBGrid->Columns->Items[14]->Title->Caption  = "未使用";
	}
}
//---------------------------------------------------------------------------
Currency __fastcall TMainForm::GetTaxRate(int date)
{
	if (!date)
		date = Now().FormatString("yyyymmdd").ToInt();

	AnsiString sql;
	NsRecordSet set;

	sql = " SELECT TOP 1 消費税率 FROM M_消費税"
		  " WHERE"
		  " 	開始日付 <= " + IntToStr(date) +
		  " ORDER BY 開始日付 DESC";
	if (!DM->DBI.GetRecordSet(sql, set))
		return 0.05;
	int n = ToInt(SET_TOP(set)["消費税率"]);
	return n / Currency(100);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	switch(Msg.message){
		case WM_MOUSEWHEEL:
		if(Msg.hwnd == DBGrid->Handle){
			//ホイールマウスのイベントで上下に動くように設定
			if((short)HIWORD(Msg.wParam) > 0){
				DBGrid->DataSource->DataSet->Prior();
			}else{
				DBGrid->DataSource->DataSet->Next();
			}
			//処理はここでストップさせる
			Handled = true;
		}
		if(Msg.hwnd == SearchForm->DBGrid->Handle){
			//ホイールマウスのイベントで上下に動くように設定
			if((short)HIWORD(Msg.wParam) > 0){
				SearchForm->DBGrid->DataSource->DataSet->Prior();
			}else{
				SearchForm->DBGrid->DataSource->DataSet->Next();
			}
			//処理はここでストップさせる
			Handled = true;
		}
		break;
	}
}
//---------------------------------------------------------------------------

