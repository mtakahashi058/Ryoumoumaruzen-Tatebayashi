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

	long_list_->CommaText  = "�������,�L�����,�������,�������,���c�@�l,�������";
	short_list_->CommaText = "(��),(�L),(��),(��),(��),(��)";
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
// ���ڊ֘A�}�X�^ ���ڔԍ�����
void __fastcall TDM::M_ItemRelateCalcFields(TDataSet *DataSet)
{
    if (M_ItemRelate->FieldByName("���ڔԍ�")->AsInteger == 1)
        M_ItemRelate->FieldByName("���ڊ֘A����")->AsString = ToString(config_["���Ӑ�}�X�^����"]);
    else if (M_ItemRelate->FieldByName("���ڔԍ�")->AsInteger == 2)
        M_ItemRelate->FieldByName("���ڊ֘A����")->AsString = ToString(config_["����1�}�X�^����"]);
    else if (M_ItemRelate->FieldByName("���ڔԍ�")->AsInteger == 3)
        M_ItemRelate->FieldByName("���ڊ֘A����")->AsString = ToString(config_["����2�}�X�^����"]);
    else if (M_ItemRelate->FieldByName("���ڔԍ�")->AsInteger == 4)
        M_ItemRelate->FieldByName("���ڊ֘A����")->AsString = ToString(config_["�i�ڃ}�X�^����"]);
}
//---------------------------------------------------------------------------
// ���Ӑ�N�G���擾
AnsiString __fastcall TDM::GetTokuisakiQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_���Ӑ�"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "���Ӑ於��,���Ӑ旪��,���Ӑ�J�i,�Z��1,�Z��2,�d�b�ԍ�";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " �g�p�敪 = 1";
    else
        where = " �g�p�敪 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_���Ӑ�", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ���Ӑ�R�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// ����1�N�G���擾
AnsiString __fastcall TDM::GetItem1Query(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_����1"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "����1����,����1����,����1�J�i";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " �g�p�敪 = 1";
    else
        where = " �g�p�敪 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_����1", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ����1�R�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// ����2�N�G���擾
AnsiString __fastcall TDM::GetItem2Query(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_����2"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "����2����,����2����,����2�J�i";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " �g�p�敪 = 1";
    else
        where = " �g�p�敪 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_����2", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ����2�R�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �i�ڕ��ޗp�N�G���擾
AnsiString __fastcall TDM::GetHinBunruiQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_�i�ڕ���"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "�i�ڕ��ޖ���,�i�ڕ��ޗ���,�i�ڕ��ރJ�i";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " �g�p�敪 = 1";
    else
        where = " �g�p�敪 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_�i�ڕ���", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �i�ڕ��ރR�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �i�ڗp�N�G���擾
AnsiString __fastcall TDM::GetHinmokuQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_�i��"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "�i�ږ���,�i�ڗ���,�i�ڃJ�i,�����o�敪����,�i�ڕ��ޗ���";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " �g�p�敪 = 1";
    else
        where = " �g�p�敪 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_�i��", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �i�ڃR�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �ԗ��p�N�G���擾
AnsiString __fastcall TDM::GetSharyoQuery(AnsiString search_word, bool all_show, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_�ԗ�"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "�Ԕ�,�ԗ�����,���Ӑ旪��,����1����,����2����,�i�ڗ���";

	AnsiString where = AnsiString();
	if (!all_show)
		where = " �g�p�敪 = 1";
    else
        where = " �g�p�敪 = 0";

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_�ԗ�", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �Ԕ�";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// ���Z�p�N�G���擾
AnsiString __fastcall TDM::GetKanzanQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_���Z"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "���Ӑ旪��,�i�ڗ���,�P�ʖ���";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_���Z", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ���Ӑ�R�[�h, �i�ڃR�[�h, �P�ʃR�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// ���_�p�N�G���擾
AnsiString __fastcall TDM::GetKyotenQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	M_���_"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "���_����";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "M_���_", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ���_�R�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �P�ʗp�N�G���擾
AnsiString __fastcall TDM::GetTaniQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	M_�P��"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "�P�ʖ���";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "M_�P��", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �P�ʃR�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �P���p�N�G���擾
AnsiString __fastcall TDM::GetTankaQuery(AnsiString search_word, AnsiString order)
{
	AnsiString sql =
		" SELECT"
		" 	*"
		" FROM"
		" 	V_�P��"
		" $WHERE$";

	std::auto_ptr<TStringList> fields (new TStringList);
	fields->CommaText = "���Ӑ旪��, �i�ڗ���, ����1����, ����2����, �P�ʖ���";

	AnsiString where = AnsiString();

	if (search_word != ""){
		if (where != "")
			where += " AND";
		where += DBI.FullSearchSQL(search_word, "V_�P��", fields.get(), true);
	}

	if (where != "")
		where = " WHERE" + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ���Ӑ�R�[�h, �i�ڃR�[�h, ����1�R�[�h, ����2�R�[�h, �P�ʃR�[�h";

	return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �`�[���N�G���擾
AnsiString __fastcall TDM::GetSlipInfoQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_�`�[���"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "�`�[���,���ɓ`�[�^�C�g��1,���ɓ`�[�^�C�g��2,���ɓ`�[�^�C�g��3,�o�ɓ`�[�^�C�g��1,�o�ɓ`�[�^�C�g��2,�o�ɓ`�[�^�C�g��3,"
                                "��Ж�,��Џ��1,��Џ��2,��Џ��3,��Џ��4";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_�`�[���", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �`�[���R�[�h";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �`�[���֘A�N�G���擾
AnsiString __fastcall TDM::GetSlipInfoRelateQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_�`�[���֘A"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "���ڔԍ�����,���ڗ���,�`�[���";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_�`�[���֘A", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ���ڔԍ�, ���ڃR�[�h";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// ��s�N�G���擾
AnsiString __fastcall TDM::GetBankQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_��s"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "��s����,�x�X����,����";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_��s", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ��s�R�[�h";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �ȖڃN�G���擾
AnsiString __fastcall TDM::GetKamokuQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_�Ȗ�"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "�Ȗږ���";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_�Ȗ�", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �ȖڃR�[�h";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// �⏕��N�G���擾
AnsiString __fastcall TDM::GetHojoboQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_�⏕��"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "�Ȗږ���,�⏕�떼��";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_�⏕��", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �ȖڃR�[�h, �⏕��R�[�h";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// ����ŃN�G���擾
AnsiString __fastcall TDM::GetTaxQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     M_�����"
        "$WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "�J�n���t,����ŗ�";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "M_�����", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY �J�n���t";

    return AnsiReplaceStr(sql, "$WHERE$", where);
}
//---------------------------------------------------------------------------
// ���ڊ֘A�N�G���擾
AnsiString __fastcall TDM::GetItemRelateQuery(AnsiString search_word, AnsiString order)
{
    AnsiString sql =
        " SELECT"
        "     *"
        " FROM"
        "     V_���ڊ֘A"
        " $WHERE$";

    std::auto_ptr<TStringList> fields (new TStringList);
    fields->CommaText = "���ڔԍ�����,���ڗ���,���Ӑ旪��,����1����,����2����,�i�ڗ���";

    AnsiString where = AnsiString();

    if (search_word != ""){
        if (where != "")
            where += " AND ";
        where += DBI.FullSearchSQL(search_word, "V_���ڊ֘A", fields.get(), true);
    }

    if (where != "")
        where = " WHERE " + where;

    if (order != "")
        where = where + order;
    else
        where = where + " ORDER BY ���ڔԍ�,���ڃR�[�h,���Ӑ�R�[�h,����1�R�[�h,����2�R�[�h,�i�ڃR�[�h";

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
		combo->Items->Add(ToString(set[i]["����"]));
		map[i] = ToInt(set[i]["�R�[�h"]);
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

      if (ToInt(DM->DBI.Lookup("M_����", "�ݒ薼", "���Ӑ�}�X�^�g�p�敪", "�ݒ�l")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_����", "�ݒ薼", "���Ӑ�}�X�^����", "�ݒ�l")));
      else
            combo->Items->Add("���g�p");

      if (ToInt(DM->DBI.Lookup("M_����", "�ݒ薼", "����1�}�X�^�g�p�敪", "�ݒ�l")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_����", "�ݒ薼", "����1�}�X�^����", "�ݒ�l")));
      else
            combo->Items->Add("���g�p");

      if (ToInt(DM->DBI.Lookup("M_����", "�ݒ薼", "����2�}�X�^�g�p�敪", "�ݒ�l")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_����", "�ݒ薼", "����2�}�X�^����", "�ݒ�l")));
      else
            combo->Items->Add("���g�p");

      if (ToInt(DM->DBI.Lookup("M_����", "�ݒ薼", "�i�ڃ}�X�^�g�p�敪", "�ݒ�l")) != 0)
            combo->Items->Add(ToString(DM->DBI.Lookup("M_����", "�ݒ薼", "�i�ڃ}�X�^����", "�ݒ�l")));
      else
            combo->Items->Add("���g�p");

      combo->Items->Add("���|�敪");
}
//---------------------------------------------------------------------------
// �h�̃R���{�{�b�N�X�p
void __fastcall TDM::AddComboBox_Honorific(TComboBox *combo)
{
    combo->Clear();

    NsRecordSet set;
    if (!DM->DBI.GetRecordSet("SELECT �h�� FROM M_���Ӑ� GROUP BY �h��", set)){
        // �f�[�^���Ȃ������牽�����Ȃ���return;
        return;
    }

    for (unsigned int i = 0; i < set.size(); i++)
        combo->Items->Add(ToString(set[i]["�h��"]));
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
	if (panel->Caption == "�V�K")
		return imNew;
	else if (panel->Caption == "�C��")
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
// str:�������������� width:�w��̒���
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
    int no = DataSet->FieldByName("���ڔԍ�")->AsInteger;
    switch(no){
    case 1: name = ToString(config_["���Ӑ�}�X�^����"]); break;
    case 2: name = ToString(config_["����1�}�X�^����"]);  break;
    case 3: name = ToString(config_["����2�}�X�^����"]);  break;
    case 4: name = ToString(config_["�i�ڃ}�X�^����"]);   break;
    case 5: name = "���|�敪"; break;
    };
    DataSet->FieldByName("���ڔԍ����䖼��")->AsString = name;
}
//---------------------------------------------------------------------------
void __fastcall TDM::DeleteRelateMaster(int page, AnsiString keyfield, int key)
{
    // �P���A�`�[���֘A�A���ڊ֘A���폜����

    int item_no;
    if (page != 4)
        item_no = page + 1;
    else
        item_no = 4;

    NsFieldSet tanka_keys, slip_relate_keys, item_relate_keys;
    tanka_keys       << NsField(keyfield,     key);
    slip_relate_keys << NsField("[���ڔԍ�]", item_no)
                     << NsField("[����ID]",   key);
    item_relate_keys << NsField("[���ڔԍ�]", item_no)
                     << NsField("[����ID]",   key);

    DBI.Delete("M_�P��",         tanka_keys);
    DBI.Delete("M_�`�[���֘A", slip_relate_keys);
    DBI.Delete("M_���ڊ֘A",     item_relate_keys);
}
//---------------------------------------------------------------------------

