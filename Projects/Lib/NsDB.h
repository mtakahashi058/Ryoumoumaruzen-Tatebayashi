/**
  * NsDB.h: NikkoSoftware DB Acccess Library Header
  *
  *     @author a_oshima
  *     @history
  *                 2006-06-12  作成
  *                 2006-06-21  Update 時に、IS NULL も設定できるようにした
  *                 2006-07-07  Insert / Update 時に NULL 値を使用できるようにした
  *                 2006-10-11  日付時刻型に対応
  *                 2007-03-13  SET_ マクロを追加
  *                 2007-03-14  Lookup を追加
  *                 2007-06-18  ToFilter 関数を追加
  *                 2007-06-26  NsFilter / NsFilterSet を追加
  *                             ToFilter 関数を変更
  *                 2007-07-19  FullSearchSQL を追加
  *                 2007-10-12  ADODB.hpp への依存を解消
  *                             SET_TOP マクロを追加
  *                             SET_ マクロは非推奨
  *                 2007-10-31  上記依存解消に問題があったため修正
  *                 2007-12-14  Generate メソッドを public に
  *                 2008-01-09  Generate メソッドを private に
  *                 2008-02-07  ToVariant 関数を追加
  *                             空文字列（""）を NULL として登録するための
  *                             ヘルパ関数
  *                 2008-02-13  NsFormat / NsFormatSet を追加
  *                             SetToFormattedFile 関数を追加
  *                             NsRecordSet から固定長ファイルを出力するヘルパ
  *                 2008-02-26  SetToFormattedFile 関数のバグを修正
  *                             SET_ マクロを削除
  *                 2008-06-19  FullSearchSQL で[rowguid]フィールドが存在した時にエラーが出てしまうのを、回避するように修正(48)
  *                 2008-07-24  FullSearchSQL で検索対象フィールドを指定できるメソッドを追加
  *                 2008-11-11  GetLastID メソッドを作成
  *                 2009-02-25  Lookup に複数キー対応メソッドを追加
  *                             GenerateFilter メソッドを追加
  *                 2009-03-11  RecordToFormattedString 関数を追加
  *                 2009-08-18  ToInt / ToCurrency を修正（ToIntDef, StrToCurrDef を使用するように）
  *                 2009-08-19  IsNull 関数を追加
  *                 2010-02-22  FullSearchSQL で30バイトまでしか検索できなかったため修正
  *                 2010-03-04  ・GetLastID メソッドを作成
  *                             ・ToInt / ToCurrency を修正（ToIntDef, StrToCurrDef を使用するように）
  *                             ・IsNull 関数を追加
  *                             上記3つを差分として追加
  *                 2010-04-16  NsFilterSet 用ヘルパ ReplaceSetField を追加
  *                 2011-06-16  GetLastID メソッドがレプリケーション環境で誤動作するのを修正
  *                 2011-08-25  Update メソッドに、AnsiString where を引数に持つタイプを追加
  *                             それに伴い、GenerateUpdateQuery の同引数版を追加
  *                 2012-03-08  Variant 関連ヘルパを別ヘッダに分割
  *                 2013-02-14  SetToLTSV 関数を追加
  */

#ifndef NsDB_H_
#define NsDB_H_

#include <map>
#include <vector>
#include <algorithm>
#include "NsVar.h"

namespace Adodb {
class TADOConnection;
class TADODataSet;
}

struct NsField{
    NsField() {}
    NsField(const AnsiString& n, const Variant& v) : name(n), value(v) {}

    AnsiString name;
    Variant value;
};

struct NsFilter{
    NsFilter() {}
    NsFilter(const AnsiString& n) : name(n) {}
    NsFilter(const AnsiString& n, const Variant& v) : name(n), value(v) {}

    AnsiString name;
    Variant value;
};

struct NsFormat{
    NsFormat() {}
    NsFormat(const AnsiString& f, int l) : field(f), len(l) {}
    NsFormat(const AnsiString& f, int l, const AnsiString& m) : field(f), len(l), format(m) {}

    AnsiString field;
    int len;
    AnsiString format;
};

typedef std::vector<NsField> NsFieldSet;
typedef std::vector<NsFilter> NsFilterSet;
typedef std::vector<NsFormat> NsFormatSet;
typedef std::map<AnsiString, Variant> NsRecord;
typedef std::map<int, NsRecord> NsRecordSet;

class NsDBInterface{
public:
    NsDBInterface(Adodb::TADOConnection *conn);
    virtual ~NsDBInterface();

    int Insert(const AnsiString& table, const NsFieldSet& record);
    int Update(const AnsiString& table, const AnsiString& key, const Variant& key_val, const NsFieldSet& record);
    int Update(const AnsiString& table, const NsFieldSet& keys, const NsFieldSet& record);
    int Update(const AnsiString& table, const AnsiString& where, const NsFieldSet& record);
    int Delete(const AnsiString& table, const NsFieldSet& keys);
    int GetLastID();

    bool IsExist(const AnsiString& table, const AnsiString& key, const Variant& key_val);
    bool IsExist(const AnsiString& table, const NsFieldSet& keys);

    bool GetRecordSet(const AnsiString& query, NsRecordSet& set);

    AnsiString GenerateFilter(const NsFieldSet& keys);

    int Execute(const AnsiString& query);

    Variant Lookup(const AnsiString& table, const AnsiString& key_field, const Variant& key_val, const AnsiString& value_field, const AnsiString& where = "");
    Variant Lookup(const AnsiString& table, const NsFieldSet& keys, const AnsiString& value_field);

    AnsiString FullSearchSQL(const AnsiString& keywords, const AnsiString& table, bool and = true);
    AnsiString FullSearchSQL(const AnsiString& keywords, const AnsiString& table, TStringList *Fields, bool and = true);

private:
    AnsiString GenerateSelectQuery(const AnsiString& table, const NsFieldSet& keys);
    AnsiString GenerateInsertQuery(const AnsiString& table, const NsFieldSet& record);
    AnsiString GenerateUpdateQuery(const AnsiString& table, const NsFieldSet& keys, const NsFieldSet& record);
    AnsiString GenerateUpdateQuery(const AnsiString& table, const AnsiString& where, const NsFieldSet& record);
    AnsiString GenerateDeleteQuery(const AnsiString& table, const NsFieldSet& keys);

    AnsiString GenerateFullSearchSQL(const AnsiString& keywords, const AnsiString& table, TStringList *Fields, bool and);

    AnsiString Escape(const AnsiString& src);

    Adodb::TADOConnection *Connection_;
    Adodb::TADODataSet *DataSet_;
};  // end of class NsDBInterface


/** NsFieldSet Helper Function **/
NsFieldSet& operator<<(NsFieldSet& set, const NsField& field);
void AppendField(NsFieldSet& set, const AnsiString& field, const Variant& value);
void ReplaceSetField(NsFieldSet& set, const AnsiString& field, const Variant& value);

/** NsFilterSet Helper Function **/
NsFilterSet& operator<<(NsFilterSet& set, const NsFilter& field);
void AppendField(NsFilterSet& set, const AnsiString& field, const Variant& value);

/** NsFormatSet Helper Function **/
NsFormatSet& operator<<(NsFormatSet& set, const NsFormat& format);

AnsiString RecordToFormattedString(const NsRecord& rec, const NsFormatSet& formats);
bool SetToFormattedFile(const AnsiString& file, const NsRecordSet& set, const NsFormatSet& formats);

AnsiString ToFilter(const NsFilterSet& filters, const AnsiString& logical_operator);

/** NsRecordSet Helper Function **/
int SetToLTSV(const AnsiString& file, const NsRecordSet& set, bool strict = false);

#define SET_TOP(s)      (s[0])

#endif  //NsDB_H_
