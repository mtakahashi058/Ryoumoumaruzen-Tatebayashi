/**
  * NsDB.h: NikkoSoftware DB Acccess Library Header
  *
  *     @author a_oshima
  *     @history
  *                 2006-06-12  �쐬
  *                 2006-06-21  Update ���ɁAIS NULL ���ݒ�ł���悤�ɂ���
  *                 2006-07-07  Insert / Update ���� NULL �l���g�p�ł���悤�ɂ���
  *                 2006-10-11  ���t�����^�ɑΉ�
  *                 2007-03-13  SET_ �}�N����ǉ�
  *                 2007-03-14  Lookup ��ǉ�
  *                 2007-06-18  ToFilter �֐���ǉ�
  *                 2007-06-26  NsFilter / NsFilterSet ��ǉ�
  *                             ToFilter �֐���ύX
  *                 2007-07-19  FullSearchSQL ��ǉ�
  *                 2007-10-12  ADODB.hpp �ւ̈ˑ�������
  *                             SET_TOP �}�N����ǉ�
  *                             SET_ �}�N���͔񐄏�
  *                 2007-10-31  ��L�ˑ������ɖ�肪���������ߏC��
  *                 2007-12-14  Generate ���\�b�h�� public ��
  *                 2008-01-09  Generate ���\�b�h�� private ��
  *                 2008-02-07  ToVariant �֐���ǉ�
  *                             �󕶎���i""�j�� NULL �Ƃ��ēo�^���邽�߂�
  *                             �w���p�֐�
  *                 2008-02-13  NsFormat / NsFormatSet ��ǉ�
  *                             SetToFormattedFile �֐���ǉ�
  *                             NsRecordSet ����Œ蒷�t�@�C�����o�͂���w���p
  *                 2008-02-26  SetToFormattedFile �֐��̃o�O���C��
  *                             SET_ �}�N�����폜
  *                 2008-06-19  FullSearchSQL ��[rowguid]�t�B�[���h�����݂������ɃG���[���o�Ă��܂��̂��A�������悤�ɏC��(48)
  *                 2008-07-24  FullSearchSQL �Ō����Ώۃt�B�[���h���w��ł��郁�\�b�h��ǉ�
  *                 2008-11-11  GetLastID ���\�b�h���쐬
  *                 2009-02-25  Lookup �ɕ����L�[�Ή����\�b�h��ǉ�
  *                             GenerateFilter ���\�b�h��ǉ�
  *                 2009-03-11  RecordToFormattedString �֐���ǉ�
  *                 2009-08-18  ToInt / ToCurrency ���C���iToIntDef, StrToCurrDef ���g�p����悤�Ɂj
  *                 2009-08-19  IsNull �֐���ǉ�
  *                 2010-02-22  FullSearchSQL ��30�o�C�g�܂ł��������ł��Ȃ��������ߏC��
  *                 2010-03-04  �EGetLastID ���\�b�h���쐬
  *                             �EToInt / ToCurrency ���C���iToIntDef, StrToCurrDef ���g�p����悤�Ɂj
  *                             �EIsNull �֐���ǉ�
  *                             ��L3�������Ƃ��Ēǉ�
  *                 2010-04-16  NsFilterSet �p�w���p ReplaceSetField ��ǉ�
  *                 2011-06-16  GetLastID ���\�b�h�����v���P�[�V�������Ō듮�삷��̂��C��
  *                 2011-08-25  Update ���\�b�h�ɁAAnsiString where �������Ɏ��^�C�v��ǉ�
  *                             ����ɔ����AGenerateUpdateQuery �̓������ł�ǉ�
  *                 2012-03-08  Variant �֘A�w���p��ʃw�b�_�ɕ���
  *                 2013-02-14  SetToLTSV �֐���ǉ�
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
