/**
  * NsDB.h: NikkoSoftware DB Acccess Library Header
  *
  *     @author a_oshima
  */

#include <vcl.h>
#pragma hdrstop

#include <ADODB.hpp>
#include <DB.hpp>

#include "NsDB.h"
#include <Classes.hpp>
#include <StrUtils.hpp>
#include <memory>
#include <fstream>

NsDBInterface::NsDBInterface(TADOConnection *conn) : Connection_(conn), DataSet_(0) {
    DataSet_ = new TADODataSet(0);
    DataSet_->Connection     = conn;
    DataSet_->ParamCheck     = false;
    DataSet_->LockType       = ltReadOnly;
    DataSet_->CommandTimeout = conn->CommandTimeout;
}

NsDBInterface::~NsDBInterface(){
    if (DataSet_){
        if (DataSet_->Active)
            DataSet_->Close();
        delete DataSet_;
    }
}

int NsDBInterface::Insert(const AnsiString& table, const NsFieldSet& record){
    AnsiString query = GenerateInsertQuery(table, record);

    return Execute(query);
}

int NsDBInterface::Update(const AnsiString& table, const AnsiString& key, const Variant& key_val, const NsFieldSet& record){
    NsFieldSet keys;
    keys.push_back(NsField(key, key_val));

    AnsiString query = GenerateUpdateQuery(table, keys, record);

    return Execute(query);
}

int NsDBInterface::Update(const AnsiString& table, const NsFieldSet& keys, const NsFieldSet& record){
    AnsiString query = GenerateUpdateQuery(table, keys, record);

    return Execute(query);
}

int NsDBInterface::Update(const AnsiString& table, const AnsiString& where, const NsFieldSet& record){
    AnsiString query = GenerateUpdateQuery(table, where, record);

    return Execute(query);
}

int NsDBInterface::Delete(const AnsiString& table, const NsFieldSet& keys){
    AnsiString query = GenerateDeleteQuery(table, keys);

    return Execute(query);
}

int NsDBInterface::GetLastID(){
    NsRecordSet set;
    // if (!GetRecordSet("SELECT CAST(@@IDENTITY AS int) AS LAST_ID", set))
    if (!GetRecordSet("SELECT CAST(SCOPE_IDENTITY() AS int) AS LAST_ID", set))
        return -1;
    return ToInt(SET_TOP(set)["LAST_ID"]);
}

bool NsDBInterface::IsExist(const AnsiString& table, const AnsiString& key, const Variant& key_val){
    NsFieldSet keys;
    keys.push_back(NsField(key, key_val));

    AnsiString query = GenerateSelectQuery(table, keys);

    NsRecordSet set;
    return GetRecordSet(query, set);
}

bool NsDBInterface::IsExist(const AnsiString& table, const NsFieldSet& keys){
    AnsiString query = GenerateSelectQuery(table, keys);

    NsRecordSet set;
    return GetRecordSet(query, set);
}

bool NsDBInterface::GetRecordSet(const AnsiString& query, NsRecordSet& set){
    bool result;

    if (DataSet_->Active)
        DataSet_->Close();

    set.clear();

    DataSet_->CommandText = query;
    DataSet_->Open();

    if (DataSet_->Eof)
        result = false;
    else{
        result = true;

        int index = 0;
        NsRecord rec;
        while (!DataSet_->Eof){
            rec.clear();

            for (int i = 0; i < DataSet_->FieldCount; i++)
                rec[DataSet_->Fields->Fields[i]->FieldName] = DataSet_->Fields->Fields[i]->Value;
            set[index] = rec;

            DataSet_->Next();
            index++;
        }
    }

    DataSet_->Close();

    return result;
}

AnsiString NsDBInterface::GenerateFilter(const NsFieldSet& keys){
    AnsiString query = "";

    if (keys.empty())   return "";

    for (unsigned int i = 0; i < keys.size(); i++){
        if (i > 0)
            query += " AND ";
        query += keys[i].name + " = ";
        if (keys[i].value.Type() == varString || keys[i].value.Type() == varDate){
            query += AnsiString("'") + Escape(AnsiString(keys[i].value)) + "' ";
        }else
            query += AnsiString(keys[i].value) + ' ';
    }

    return query;
}

int NsDBInterface::Execute(const AnsiString& query){
    int affected_row(0);

    Connection_->Execute(query, affected_row);

    return affected_row;
}

Variant NsDBInterface::Lookup(const AnsiString& table, const AnsiString& key_field, const Variant& key_val, const AnsiString& value_field, const AnsiString& where){
    AnsiString query;

    query = "SELECT " + value_field + " FROM " + table;

    query += " WHERE " + key_field + " = ";
    if (key_val.Type() == varString || key_val.Type() == varDate)
        query += "'" + Escape(AnsiString(key_val)) + "' ";
    else
        query += AnsiString(key_val) + ' ';

    if (!where.IsEmpty())
        query += " AND " + where;

    NsRecordSet set;
    if (!GetRecordSet(query, set))
        return Variant();
    return set[0][value_field];
}

Variant NsDBInterface::Lookup(const AnsiString& table, const NsFieldSet& keys, const AnsiString& value_field){
    AnsiString query =
        "SELECT " + value_field + " FROM " + table + " WHERE " +
        GenerateFilter(keys);

    NsRecordSet set;
    if (!GetRecordSet(query, set))
        return Variant();

    return SET_TOP(set)[value_field];
}

AnsiString NsDBInterface::FullSearchSQL(const AnsiString& keywords, const AnsiString& table, bool and){
    return GenerateFullSearchSQL(keywords, table, 0, and);
}

AnsiString NsDBInterface::FullSearchSQL(const AnsiString& keywords, const AnsiString& table, TStringList *Fields, bool and){
    return GenerateFullSearchSQL(keywords, table, Fields, and);
}

AnsiString NsDBInterface::GenerateFullSearchSQL(const AnsiString& keywords, const AnsiString& table, TStringList *Fields, bool and){
    const char QUOTE = '"';

    std::auto_ptr<TStringList> ParamList(new TStringList());
    std::auto_ptr<TStringList> FieldList(new TStringList());
    if (Fields)
        FieldList->Assign(Fields);

    AnsiString params = AnsiReplaceStr(keywords, "　", " ");

    ParamList->Delimiter = ' ';
    ParamList->QuoteChar = QUOTE;
    ParamList->DelimitedText = params;

    if (!Fields)
        Connection_->GetFieldNames(table, FieldList.get());

    AnsiString search_expr;
    AnsiString buff;
    for (int param_i = 0; param_i < ParamList->Count; param_i++){
        buff = AnsiString();

        if (!search_expr.IsEmpty()){
            if (and)
                search_expr += " AND ";
            else
                search_expr += " OR ";
        }
        for (int field_i = 0; field_i < FieldList->Count; field_i++){
            if (FieldList->Strings[field_i] == "rowguid")
                continue;

            if (!buff.IsEmpty())
                buff += " + ";
            buff += " ISNULL(CAST([" + FieldList->Strings[field_i] + "] AS varchar (100)), '') + '^' ";
        }
        buff += "LIKE '%" + ParamList->Strings[param_i] + "%'";
        search_expr += buff;
    }

    return " (" + search_expr + ") ";
}

AnsiString NsDBInterface::GenerateSelectQuery(const AnsiString& table, const NsFieldSet& keys){
    AnsiString query;

    if (keys.empty())   return "";

    query = "SELECT \n";

    for (NsFieldSet::const_iterator i = keys.begin(); i != keys.end(); i++){
        if (i != keys.begin())
            query += ", ";
        query += i->name;
    }

    query += " FROM " + table + "\nWHERE ";
    for (unsigned int i = 0; i < keys.size(); i++){
        if (i > 0)
            query += " AND ";
        query += keys[i].name + " = ";
        if (keys[i].value.Type() == varString || keys[i].value.Type() == varDate){
            query += AnsiString("'") + Escape(AnsiString(keys[i].value)) + "' ";
        }else
            query += AnsiString(keys[i].value) + ' ';
    }

    return query;
}

AnsiString NsDBInterface::GenerateInsertQuery(const AnsiString& table, const NsFieldSet& record){
    AnsiString query;

    if (record.empty()) return "";

    query = "INSERT INTO " + table + "\n(";

    for (NsFieldSet::const_iterator i = record.begin(); i != record.end(); i++){
        if (i != record.begin())
            query += ", ";
        query += i->name;
    }
    query += ") \nVALUES(";

    for (NsFieldSet::const_iterator i = record.begin(); i != record.end(); i++){
        if (i != record.begin())
            query += ", ";
        if (i->value.Type() == varString || i->value.Type() == varDate)
            query += "'" + Escape(AnsiString(i->value)) + "'";
        else if (i->value.IsNull() || i->value.IsEmpty())
            query += "NULL";
        else
            query += AnsiString(i->value);
    }

    query += ")";

    return query;
}

AnsiString NsDBInterface::GenerateUpdateQuery(const AnsiString& table, const NsFieldSet& keys, const NsFieldSet& record){
    AnsiString query;

    if (keys.empty())   return "";
    if (record.empty()) return "";

    query = "UPDATE " + table + " \nSET ";

    for (NsFieldSet::const_iterator i = record.begin(); i != record.end(); i++){
        if (i != record.begin())
            query += ", ";
        query += i->name + " = ";
        if (i->value.Type() == varString || i->value.Type() == varDate)
            query += "'" + Escape(AnsiString(i->value)) + "'";
        else if (i->value.IsNull() || i->value.IsEmpty())
            query += "NULL";
        else
            query += AnsiString(i->value);
    }

    // keys が存在する場合にのみ WHERE を使用するようにもできるのだが
    // その場合、単純なミスで全レコード UPDATE を行ってしまう可能性があるため
    // 必ず WHERE を設定するようにした
    query += " \nWHERE ";
    for (unsigned int i = 0; i < keys.size(); i++){
        if (i > 0)
            query += " AND ";
        if (keys[i].value.Type() == varString || keys[i].value.Type() == varDate)
            query += keys[i].name + " = '" + Escape(AnsiString(keys[i].value)) + "' ";
        else if (keys[i].value.IsNull() || keys[i].value.IsEmpty())
            query += keys[i].name + " IS NULL ";
        else
            query += keys[i].name + " = " + AnsiString(keys[i].value) + ' ';
    }

    return query;
}

AnsiString NsDBInterface::GenerateUpdateQuery(const AnsiString& table, const AnsiString& where, const NsFieldSet& record){
    AnsiString query;

    if (where.IsEmpty())   return "";
    if (record.empty()) return "";

    query = "UPDATE " + table + " \nSET ";

    for (NsFieldSet::const_iterator i = record.begin(); i != record.end(); i++){
        if (i != record.begin())
            query += ", ";
        query += i->name + " = ";
        if (i->value.Type() == varString || i->value.Type() == varDate)
            query += "'" + Escape(AnsiString(i->value)) + "'";
        else if (i->value.IsNull() || i->value.IsEmpty())
            query += "NULL";
        else
            query += AnsiString(i->value);
    }

    if (where.UpperCase().AnsiPos("WHERE")){
        query += where;
    }else{
        query += "\nWHERE " + where;
    }

    return query;
}

AnsiString NsDBInterface::GenerateDeleteQuery(const AnsiString& table, const NsFieldSet& keys){
    AnsiString query;

    if (keys.empty())   return "";

    query = "DELETE FROM " + table + " WHERE ";

    for (unsigned int i = 0; i < keys.size(); i++){
        if (i > 0)
            query += " AND ";
        query += keys[i].name + " = ";
        if (keys[i].value.Type() == varString || keys[i].value.Type() == varDate)
            query += "'" + Escape(AnsiString(keys[i].value)) + "' ";
        else
            query += AnsiString(keys[i].value) + ' ';
    }

    return query;
}

AnsiString NsDBInterface::Escape(const AnsiString& src){
    return AnsiReplaceStr(src, "'", "''");
}

/** NsRecordSet Helper Function **/

NsFieldSet& operator<<(NsFieldSet& set, const NsField& field){
    set.push_back(field);
    return set;
}

void AppendField(NsFieldSet& set, const AnsiString& field, const Variant& value){
    set.push_back(NsField(field, value));
}

void ReplaceSetField(NsFieldSet& set, const AnsiString& field, const Variant& value){
    for (NsFieldSet::iterator i = set.begin(); i != set.end(); i++){
        if (i->name == field){
            i->value = value;
            return;
        }
    }
    AppendField(set, field, value);
}

/** NsFilterSet Helper Function **/
NsFilterSet& operator<<(NsFilterSet& set, const NsFilter& field){
    set.push_back(field);
    return set;
}

void AppendField(NsFilterSet& set, const AnsiString& field, const Variant& value){
    set.push_back(NsFilter(field, value));
}

/** NsFormatSet Helper Function **/
NsFormatSet& operator<<(NsFormatSet& set, const NsFormat& format){
    set.push_back(format);
    return set;
}

AnsiString RecordToFormattedString(const NsRecord& rec, const NsFormatSet& formats){
    AnsiString line_buff;
    AnsiString value_buff;
    char field_buff[256];
    NsRecord::const_iterator iRec;

    for (NsFormatSet::const_iterator iFormat = formats.begin(); iFormat != formats.end(); iFormat++){
        iRec = rec.find(iFormat->field);
        if (iRec == rec.end())
            continue;   // RecordSet にないフィールド指定は無視

        if (iFormat->format.IsEmpty()){
            value_buff = ToString(iRec->second);
        }else{
            value_buff = FormatFloat(iFormat->format, ToCurrency(iRec->second));
        }
        // 桁あわせ
        wsprintf(field_buff, AnsiString("%-" + IntToStr(iFormat->len) + "s").c_str(), value_buff.c_str());
        field_buff[iFormat->len] = '\0';
        line_buff += AnsiString(field_buff);
    }
    return line_buff;
}

bool SetToFormattedFile(const AnsiString& file, const NsRecordSet& set, const NsFormatSet& formats){
    std::ofstream ofs(file.c_str());

    AnsiString line_buff;
    NsRecordSet::const_iterator iRecSet;
    for (iRecSet = set.begin(); iRecSet != set.end(); iRecSet++){
        if (!ofs)
            return false;

        line_buff = RecordToFormattedString(iRecSet->second, formats);
        ofs << line_buff.c_str() << std::endl;

/*
        line_buff = AnsiString();
        for (NsFormatSet::const_iterator iFormat = formats.begin(); iFormat != formats.end(); iFormat++){
            iRec = iRecSet->second.find(iFormat->field);
            if (iRec == iRecSet->second.end())
                continue;   // RecordSet にないフィールド指定は無視

            if (iFormat->format.IsEmpty()){
                buff = ToString(iRec->second);
            }else{
                buff = FormatFloat(iFormat->format, ToCurrency(iRec->second));
            }
            // 桁あわせ
            wsprintf(field_buff, AnsiString("%-" + IntToStr(iFormat->len) + "s").c_str(), buff.c_str());
            field_buff[iFormat->len] = '\0';
            line_buff += AnsiString(field_buff);
        }
        ofs << line_buff.c_str() << std::endl;
*/
    }
    return true;
}

AnsiString ToFilter(const NsFilterSet& filters, const AnsiString& logical_operator){
    AnsiString filter;

    for (unsigned int i = 0; i < filters.size(); i++){
        if (i > 0)
            filter += " " + logical_operator + " ";
        if (filters[i].value.Type() == varString || filters[i].value.Type() == varDate)
            filter += filters[i].name + " '" + AnsiString(filters[i].value) + "'";
        else if (filters[i].value.IsNull() || filters[i].value.IsEmpty())
            filter += filters[i].name;
        else
            filter += filters[i].name + " " + AnsiString(filters[i].value);
    }
    filter += " ";
    return filter;
}

int SetToLTSV(const AnsiString& file, const NsRecordSet& set, bool strict){
    int set_size = int(set.size());

    std::ofstream ofs(file.c_str());
    if (!ofs)
        throw Exception("LTSV出力ファイルを開けません");
    AnsiString buff;
    AnsiString val;
    for (NsRecordSet::const_iterator si = set.begin(); si != set.end(); si++){
        buff = AnsiString();
        for (NsRecord::const_iterator ri = (si->second).begin(); ri != (si->second).end(); ri++){
            val = ToString(ri->second);
            if (val.IsEmpty() && strict)
                continue;

            if (!buff.IsEmpty())
                buff += "\t";
            buff += ri->first + ":" + ToString(ri->second);
        }
        ofs << buff.c_str() << std::endl;
    }
    return set_size;
}

