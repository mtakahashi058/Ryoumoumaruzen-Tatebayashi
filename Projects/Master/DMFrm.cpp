//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include <StrUtils.hpp>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner), DBI(ADOConnection)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataModuleCreate(TObject *Sender)
{
	long_list_  = new TStringList();
	short_list_ = new TStringList();

	long_list_->CommaText  = "株式会社,有限会社,合名会社,合資会社,財団法人,合同会社";
	short_list_->CommaText = "(株),(有),(名),(資),(財),(同)";
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataModuleDestroy(TObject *Sender)
{
	delete long_list_;
	delete short_list_;
}
//---------------------------------------------------------------------------
void __fastcall TDM::ADOConnectionBeforeConnect(TObject *Sender)
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");
	ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TDM::Formal2Informal(AnsiString args)
{
	AnsiString result = args;

	for (int i = 0; i < long_list_->Count; i++){
		result = AnsiReplaceStr(args, long_list_->Strings[i], short_list_->Strings[i]);

		if (args != result)
			break;
	}
	return result;
}
//---------------------------------------------------------------------------
// 項目関連マスタ 項目番号名称
void __fastcall TDM::M_ItemRelateCalcFields(TDataSet *DataSet)
{
    if (M_ItemRelate->FieldByName("項目番号")->AsInteger == 1)
        M_ItemRelate->FieldByName("項目関連名称")->AsString = ToString(config_["得意先マスタ名称"]);
    else if (M_ItemRelate->FieldByName("項目番号")->AsInteger == 2)
        M_ItemRelate->FieldByName("項目関連名称")->AsString = ToString(config_["項目1マスタ名称"]);
    else if (M_ItemRelate->FieldByName("項目番号")->AsInteger == 3)
        M_ItemRelate->FieldByName("項目関連名称")->AsString = ToString(config_["項目2マスタ名称"]);
    else if (M_ItemRelate->FieldByName("項目番号")->AsInteger == 4)
        M_ItemRelate->FieldByName("項目関連名称")->AsString = ToString(config_["品目マスタ名称"]);
}
//---------------------------------------------------------------------------
// 得意先クエリ取得
AnsiString __fastcall TDM::GetTokuisakiQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_得意先"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "得意先名称,得意先略称,得意先カナ,住所1,住所2,電話番号";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " 使用区分 = 1";
    else
        where = " 使用区分 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_得意先", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 得意先コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 項目1クエリ取得
AnsiString __fastcall TDM::GetItem1Query(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_項目1"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "項目1名称,項目1略称,項目1カナ";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " 使用区分 = 1";
    else
        where = " 使用区分 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_項目1", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 項目1コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 項目2クエリ取得
AnsiString __fastcall TDM::GetItem2Query(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_項目2"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "項目2名称,項目2略称,項目2カナ";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " 使用区分 = 1";
    else
        where = " 使用区分 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_項目2", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 項目2コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 品目分類用クエリ取得
AnsiString __fastcall TDM::GetHinBunruiQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_品目分類"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "品目分類名称,品目分類略称,品目分類カナ";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " 使用区分 = 1";
    else
        where = " 使用区分 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_品目分類", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 品目分類コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 品目用クエリ取得
AnsiString __fastcall TDM::GetHinmokuQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_品目"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "品目名称,品目略称,品目カナ,搬入出区分名称,品目分類略称";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " 使用区分 = 1";
    else
        where = " 使用区分 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_品目", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 品目コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 車両用クエリ取得
AnsiString __fastcall TDM::GetSharyoQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_車両"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "車番,車両名称,得意先略称,項目1略称,項目2略称,品目略称";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " 使用区分 = 1";
    else
        where = " 使用区分 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_車両", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 車番";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 換算用クエリ取得
AnsiString __fastcall TDM::GetKanzanQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_換算"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "得意先略称,品目略称,単位名称";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_換算", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 得意先コード, 品目コード, 単位コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 拠点用クエリ取得
AnsiString __fastcall TDM::GetKyotenQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	M_拠点"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "拠点名称";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "M_拠点", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 拠点コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 単位用クエリ取得
AnsiString __fastcall TDM::GetTaniQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	M_単位"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "単位名称";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "M_単位", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 単位コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 単価用クエリ取得
AnsiString __fastcall TDM::GetTankaQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_単価"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "得意先略称, 品目略称, 項目1略称, 項目2略称, 単位名称";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_単価", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 得意先コード, 品目コード, 項目1コード, 項目2コード, 単位コード";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 伝票情報クエリ取得
AnsiString __fastcall TDM::GetSlipInfoQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_伝票情報"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "伝票情報名,入庫伝票タイトル1,入庫伝票タイトル2,入庫伝票タイトル3,出庫伝票タイトル1,出庫伝票タイトル2,出庫伝票タイトル3,"
                                "会社名,会社情報1,会社情報2,会社情報3,会社情報4";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_伝票情報", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 伝票情報コード";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 伝票情報関連クエリ取得
AnsiString __fastcall TDM::GetSlipInfoRelateQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_伝票情報関連"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "項目番号名称,項目略称,伝票情報名";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_伝票情報関連", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 項目番号, 項目コード";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 銀行クエリ取得
AnsiString __fastcall TDM::GetBankQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_銀行"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "銀行名称,支店名称,口座";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_銀行", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 銀行コード";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 科目クエリ取得
AnsiString __fastcall TDM::GetKamokuQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_科目"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "科目名称";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_科目", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 科目コード";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 補助簿クエリ取得
AnsiString __fastcall TDM::GetHojoboQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_補助簿"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "科目名称,補助簿名称";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_補助簿", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 科目コード, 補助簿コード";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 消費税クエリ取得
AnsiString __fastcall TDM::GetTaxQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     M_消費税"
        "$WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "開始日付,消費税率";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "M_消費税", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 開始日付";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// 項目関連クエリ取得
AnsiString __fastcall TDM::GetItemRelateQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_項目関連"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "項目番号名称,項目略称,得意先略称,項目1略称,項目2略称,品目略称";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_項目関連", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY 項目番号,項目コード,得意先コード,項目1コード,項目2コード,品目コード";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
void __fastcall TDM::AddComboMap(TComboBox *combo, MasterMap &map, AnsiString sql)
{
	NsRecordSet set;
	combo->Clear();
	map.clear();

	if (!DM->DBI.GetRecordSet(sql, set))
		return;

	for (unsigned int i = 0; i < set.size(); i++){
		combo->Items->Add(ToString(set[i]["名称"]));
		map[i] = ToInt(set[i]["コード"]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDM::AddComboMap_Item(TComboBox *combo, MasterMap &map)
{
      combo->Clear();
      map.clear();

      map[0] = 1;
      map[1] = 2;
      map[2] = 3;
      map[3] = 4;
      map[4] = 5;

      if (ToInt(DM->DBI.Lookup("M_制御", "設定名", "得意先マスタ使用区分", "設定値")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_制御", "設定名", "得意先マスタ名称", "設定値")));
      else
            combo->Items->Add("未使用");

      if (ToInt(DM->DBI.Lookup("M_制御", "設定名", "項目1マスタ使用区分", "設定値")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_制御", "設定名", "項目1マスタ名称", "設定値")));
      else
            combo->Items->Add("未使用");

      if (ToInt(DM->DBI.Lookup("M_制御", "設定名", "項目2マスタ使用区分", "設定値")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_制御", "設定名", "項目2マスタ名称", "設定値")));
      else
            combo->Items->Add("未使用");

      if (ToInt(DM->DBI.Lookup("M_制御", "設定名", "品目マスタ使用区分", "設定値")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_制御", "設定名", "品目マスタ名称", "設定値")));
      else
            combo->Items->Add("未使用");

      combo->Items->Add("現掛区分");
}
//---------------------------------------------------------------------------
// 敬称コンボボックス用
void __fastcall TDM::AddComboBox_Honorific(TComboBox *combo)
{
    combo->Clear();

    NsRecordSet set;
    if (!DM->DBI.GetRecordSet("SELECT 敬称 FROM M_得意先 GROUP BY 敬称", set)){
        // データがなかったら何もしないでreturn;
        return;
    }

    for (unsigned int i = 0; i < set.size(); i++)
        combo->Items->Add(ToString(set[i]["敬称"]));
}
//---------------------------------------------------------------------------
int __fastcall TDM::SearchIndex(MasterMap &map, int value)
{
	for (MasterMap::iterator i = map.begin(); i != map.end(); i++){
		if (i->second == value)
			return i->first;
	}
	return -1;
}
//---------------------------------------------------------------------------
TInputMode __fastcall TDM::GetMode(TPanel *panel)
{
	if (panel->Caption == "新規")
		return imNew;
	else if (panel->Caption == "修正")
		return imMod;
	else
		return imNon;
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataSetCloseOpen(TDataSet *query)
{
	TBookmark save_place;
	save_place = query->GetBookmark();
	query->Close();
	query->Open();
	try{
		query->GotoBookmark(save_place);
	}catch(...){}
	query->FreeBookmark(save_place);
}
//---------------------------------------------------------------------------
// str:処理したい文字 width:指定の長さ
AnsiString __fastcall TDM::TrimString(AnsiString str, int width)
{
      if (str.IsLeadByte(width))
            return str.SubString(1, width - 1);
      else
            return str.SubString(1, width);
}
//---------------------------------------------------------------------------
void __fastcall TDM::M_SlipInfoRelateCalcFields(TDataSet *DataSet)
{
    AnsiString name;
    int no = DataSet->FieldByName("項目番号")->AsInteger;
    switch(no){
    case 1: name = ToString(config_["得意先マスタ名称"]); break;
    case 2: name = ToString(config_["項目1マスタ名称"]);  break;
    case 3: name = ToString(config_["項目2マスタ名称"]);  break;
    case 4: name = ToString(config_["品目マスタ名称"]);   break;
    case 5: name = "現掛区分"; break;
    };
    DataSet->FieldByName("項目番号制御名称")->AsString = name;
}
//---------------------------------------------------------------------------
void __fastcall TDM::DeleteRelateMaster(int page, AnsiString keyfield, int key)
{
    // 単価、伝票情報関連、項目関連を削除する

    int item_no;
    if (page != 4)
        item_no = page + 1;
    else
        item_no = 4;

    NsFieldSet tanka_keys, slip_relate_keys, item_relate_keys;
    tanka_keys       << NsField(keyfield,     key);
    slip_relate_keys << NsField("[項目番号]", item_no)
                     << NsField("[項目ID]",   key);
    item_relate_keys << NsField("[項目番号]", item_no)
                     << NsField("[項目ID]",   key);

    DBI.Delete("M_単価",         tanka_keys);
    DBI.Delete("M_伝票情報関連", slip_relate_keys);
    DBI.Delete("M_項目関連",     item_relate_keys);
}
//---------------------------------------------------------------------------

