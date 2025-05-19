// nsoftfunc.h:     nsoft�p�֐��S

/*  �X�V���e
2005/07/15  �uTable2Str�v��CommaText���g���悤�ɕύX�B
2005/05/17  �uShiftDate�v�̓��t�͈͂ɔN�͈͂�ǉ��B
2005/05/13  �uIntToTime�v��ǉ��B
2005/05/12  �uGetWeekDate�v��ǉ��B
        �uShiftDate�v�̓��t�͈͂����͈͈ȊO�ł��\�ɂ����B
2005/03/17  �uGetFirstDate�v��ǉ��B
        �uShiftDate�v���w�茎���Â炷�悤�ɏC���B
2005/07/22  �uTable2Str�v��"CommaText"���g�p����悤�ɂ����B
2007/10/04  �uTable2Str�v��"DisplayLabel"���t�B�[���h���Ƃ��ďo�͂���悤�ɕύX�B
2008/03/25  �uBigMul�v�uBigDiv�v��ǉ��B
2008/11/05  �uAnsiDivide�v��ǉ��B
2009/02/02  �uAnsiSubString�v��ǉ��B
2009/07/01  �uGetRyakusho ��ǉ��B
2009/08/27  �uGetKishuDate�v�uGetKimatuDate�v��ǉ��B
2010/06/12  �uCombineDateTime�v��ǉ��B
2010/12/07  �uZeroSuppress�v��ǉ��B
2011/01/31  �uTable2Str�v�� "use_displaytext" ������ true �ɐݒ肷���
              DisplayText ���g�p����悤�ɁB�܂��A��L�����͏ȗ��\�Ȃ���
              �����̃\�[�X�͂��̂܂ܕύX�����Ō��̓�����s���B
2011/11/04  �uHan2Zen�v��ǉ��B
2012/12/20  �uSpaceSuppress�v��ǉ��B
2013/01/24  �uZen2Han�v��ǉ��B
2013/02/01  �uIntToTTime�v��ǉ��B
2013/05/24  �uGetTimeDuration�v��ǉ��B
2013/08/12  �uIsFileAlreadyOpen�v��ǉ��B
*/

#ifndef _NsoftFuncH_
#define _NsoftFuncH_

#include <QuickRpt.hpp>
#include <math.h>
#include <StrUtils.hpp>
#include <DateUtils.hpp>

//------------------------------------------------------------------------
//          �f�[�^�Z�b�g�֘A�֐��S
//------------------------------------------------------------------------

// �w��e�[�u���̃��R�[�h��T��
bool FindRecord(TDataSet *ds, AnsiString field, Variant value)
{
    if (ds->Locate(field, value, TLocateOptions()))
        return true;
    else
        return false;
}

// �w��e�[�u���̖��̂�Ԃ�
AnsiString GetName(TDataSet *ds, const AnsiString KeyFields, const Variant &KeyValues, const AnsiString ResultFields)
{
    if (FindRecord(ds, KeyFields, KeyValues))
        if (ds->FieldByName(ResultFields)->IsNull)
            return "";
        else
            return ds->Lookup(KeyFields, KeyValues, ResultFields);
    else
        return "";
}

// �f�[�^�Z�b�g�� CSV�o��
void Table2Str(TDataSet *ds, TStringList *list, bool fieldname, bool use_displaytext = false)
{
    int nRowCount, nColCount;
    nRowCount = 0;
    ds->FieldList->Text;
    TStringList *FieldList = new TStringList();
    // �t�B�[���h��
    if (fieldname){
        FieldList->Clear();
        for (nColCount = 0; nColCount < ds->FieldCount; nColCount++){
//          FieldList->Append(ds->FieldList->Strings[nColCount]);
            FieldList->Append(ds->Fields->Fields[nColCount]->DisplayLabel);
        }
        list->Add(FieldList->CommaText);
    }
    // �f�[�^
    ds->First();
    while (!ds->Eof){
        FieldList->Clear();
        for (nColCount = 0; nColCount < ds->FieldCount; nColCount++){
            if (use_displaytext)
                FieldList->Append(ds->FieldByName(ds->FieldList->Strings[nColCount])->AsString);
            else
                FieldList->Append(ds->FieldByName(ds->FieldList->Strings[nColCount])->DisplayText);
        }
        list->Add(FieldList->CommaText);
        nRowCount++;
        ds->Next();
    }
    delete FieldList;

    /* �g�p��
    #include <memory>
    
    std::auto_ptr<TStringList> Records(new TStringList());
    Table2Str(DM->Table1, Records.get(), false);
    SaveDialog->FileName = DM->Table1->TableName + "_" + Date().FormatString("yyyymmdd") + ".csv";
    if (SaveDialog->Execute())
        Records->SaveToFile(SaveDialog->FileName);
    */
}

//------------------------------------------------------------------------
//          ���t�֘A�֐��Q
//------------------------------------------------------------------------

// ���t�����񂩂�X���b�V������菜��
AnsiString RemoveSlash(AnsiString src){
    int idx = src.Pos('/');
    while (idx){
        src.Delete(idx, 1);
        idx = src.Pos('/');
    }
    return src;
}

// ���t������ɃX���b�V����}��
AnsiString InsertSlash(AnsiString src){
    src.Insert("/", 5);
    src.Insert("/", 8);
    return src;
}

// ��������w�蕶�����ŕ�������
AnsiString AnsiDivide(AnsiString *args, int len)
{
    AnsiString buff;

    if (args->IsLeadByte(len))
        len--;

    buff = args->SubString(1, len);
    *args = args->SubString(len + 1, args->Length());

    return buff;
}

// MBS �Ή� SubString
AnsiString AnsiSubString(const AnsiString& s, int pos, int len)
{
    // ���̃`�F�b�N
    if (pos != 1){
        if (s.IsLeadByte(pos - 1)){
            pos++;
            len--;
        }
    }
    // �K�̃`�F�b�N
    if (s.IsLeadByte(pos + len - 1)){
        len--;
    }
    return s.SubString(pos, len);
}

// ���̂��痪��
AnsiString GetRyakusho(AnsiString meisho, int len)
{
    AnsiString name = meisho;
    name = AnsiReplaceStr(name, "�������", "(��)");
    name = AnsiReplaceStr(name, "�L�����", "(�L)");
    name = AnsiReplaceStr(name, "�������", "(��)");
    name = AnsiReplaceStr(name, "�������", "(��)");
    name = AnsiReplaceStr(name, "���c�@�l", "(��)");
    name = AnsiReplaceStr(name, "�������", "(��)");
    name = AnsiSubString(name, 1, len);
    return name;
}

// ���t�^�ϐ�����t�����ɕϊ�
int DateToInt(TDateTime dt){
    WORD y, m, d;
    dt.DecodeDate(&y, &m, &d);
    return (y * 10000) + (m * 100) + d;
}

// ���t��������t�^�ɕϊ�
TDateTime IntToDate(int dt){
    WORD y, m, d;
    y = dt / 10000;
    m = (dt % 10000) / 100;
    d = dt % 100;
    return TDateTime(y, m, d);
}

// �w��N���̏������擾
TDateTime GetFirstDate(TDateTime dt){
    WORD y, m, d;
    dt.DecodeDate(&y, &m, &d);
    d = 1;

    dt = EncodeDate(y, m, d);
    return dt;
}

// �w��N���̍ŏI�����擾
TDateTime GetLastDate(TDateTime dt){
    WORD y, m, d;
    dt.DecodeDate(&y, &m, &d);
    d = 1;

    if(m == 12){
    y++;
    m = 0;
    }
    m++;
    dt = EncodeDate(y, m, d);
    dt--;
    return dt;
}

// �O��̎w��j���̓��t���擾
TDateTime GetWeekDate(TDateTime dt, int before_after, int week){
    while (DayOfWeek(dt) != week){
        if (before_after == 1)
            dt++;
        else
            dt--;
    }
    return dt;
}

// TDate �� TTime ��A��
TDateTime CombineDateTime(const TDate& date, const TTime& time)
{
    Word yyyy, mm, dd;
    Word hh, nn, ss, ms;

    date.DecodeDate(&yyyy, &mm, &dd);
    time.DecodeTime(&hh, &nn, &ss, &ms);

    return EncodeDateTime(yyyy, mm, dd, hh, nn, ss, ms);
}

// ������t���擾
TDateTime __fastcall GetKishuDate(TDateTime date, int kishu)
{
    int nMonth = DateToStr(date).SubString(6, 2).ToIntDef(0);
    while (nMonth != kishu){
        date = IncMonth(date, -1);
        nMonth = DateToStr(date).SubString(6, 2).ToIntDef(0);
    }
    
    return GetFirstDate(date);
}

// �������t���擾
TDateTime __fastcall GetKimatuDate(TDateTime date, int kishu)
{
    int kimatu;
    if (kishu == 1)
        kimatu = 12;
    else
        kimatu = kishu - 1;

    int nMonth = DateToStr(date).SubString(6, 2).ToIntDef(0);
    while (nMonth != kimatu){
        date = IncMonth(date, 1);
        nMonth = DateToStr(date).SubString(6, 2).ToIntDef(0);
    }

    return GetLastDate(date);
}

/*  �g�p��.���T���擾
    GetWeekDate(Date(), -1, 1); // �͈͊J�n ���j��
    GetWeekDate(Date(), 1, 7);  // �͈͏I�� �y�j��
*/

// ���Ԍ^�������A���Ԑ����ɕϊ�
int TimeToInt(TTime tm){
    Word h, m, s, ms;

    tm.DecodeTime(&h, &m, &s, &ms);
    return (h * 100) + m;
}

// ���Ԑ������A���Ԍ^������ɕϊ�
AnsiString IntToTime(int nTime)
{
    AnsiString asTime = IntToStr(nTime);
    if (asTime == 0)
        return "00:00";
    if (asTime.Length() == 3)
        asTime.Insert("0", 1);
    if (asTime.Length() == 2)
        asTime.Insert("00", 1);
    if (asTime.Length() == 1)
        asTime.Insert("000", 1);
    asTime.Insert(":", 3);
    return asTime;
}

// ���Ԑ����� TTime �ɕϊ�
TTime IntToTTime(int n){
    short h, m;
    h = n / 100;
    m = n % 100;
    return TTime(h, m, 0, 0);
}

// ���ԍ����擾�i���������P�ʂ܂Łj
//    bool use_hhmm -> false: ���ԍ��𕪒P�ʂŏK���idefault�j
//                     true:  ���ԍ��� hhmm �`���Ŏ擾�i�����ԉ����Ƃ����`�����g�p�������ꍇ�j
int GetTimeDuration(int t1, int t2, bool use_hhmm = false)
{
    int time1 = (t1 / 100) * 60 + t1 % 100;
    int time2 = (t2 / 100) * 60 + t2 % 100;
    int dur = time1 > time2 ? time1 - time2 : time2 - time1;

    return dur;

    /** ���L�́A������ hhmm �`���ɂ��Ă�̂ŁA����͕s�g�p
    int hour, min;
    hour = dur / 60;
    min  = dur % 60;
    return hour * 100 + min;
    */
}

// ���t�͈͂̑O��   PriorNext { �O�͈� : -1, ��͈� : 1 }
void ShiftDate(TDateTimePicker *dtp1, TDateTimePicker *dtp2, int PriorNext){
    TDateTime dt1, dt2;
    unsigned short y, m, d;
    int nShiftMonth = PriorNext;

        if (int(dtp2->Date - dtp1->Date) >= 27 && int(dtp2->Date - dtp1->Date) <= 30){
            // ���͈�
        while (nShiftMonth < 0){    // <- �O�͈�
            dt1 = IncMonth(dtp1->Date, -1);
            dt2 = IncMonth(dtp2->Date, -1);
            dtp1->Date = dt1;
            if (DateToInt(dtp2->Date) == DateToInt(GetLastDate(dtp2->Date)))
                dtp2->Date = GetLastDate(dt2);
            else
                dtp2->Date = dt2;
            nShiftMonth++;
        }
        while (nShiftMonth > 0){    // -> ��͈�
            dt1 = IncMonth(dtp1->Date, 1);
            dt2 = IncMonth(dtp2->Date, 1);
            dtp1->Date = dt1;
            if (DateToInt(dtp2->Date) == DateToInt(GetLastDate(dtp2->Date)))
                dtp2->Date = GetLastDate(dt2);
            else
                dtp2->Date = dt2;
            nShiftMonth--;
        }

    }else if (int(dtp2->Date - dtp1->Date) >= 360 && int(dtp2->Date - dtp1->Date) <= 365){
        // �N�͈�
        if (nShiftMonth < 0){   // <- �O�͈�
            dt1 = IncMonth(dtp1->Date, -12);
            dt2 = IncMonth(dtp2->Date, -12);
            dtp1->Date = dt1;
            if (DateToInt(dtp2->Date) == DateToInt(GetLastDate(dtp2->Date)))
                dtp2->Date = GetLastDate(dt2);
            else
                dtp2->Date = dt2;

        }else{          // -> ��͈�
            dt1 = IncMonth(dtp1->Date, 12);
            dt2 = IncMonth(dtp2->Date, 12);
            dtp1->Date = dt1;
            if (DateToInt(dtp2->Date) == DateToInt(GetLastDate(dtp2->Date)))
                dtp2->Date = GetLastDate(dt2);
            else
                dtp2->Date = dt2;
        }

    }else{
            // ���̑��͈�
                dt1 = dtp1->Date;
                dt2 = dtp2->Date;
        dtp1->Date = dt1 + (int(dt2 - dt1 + 1) * PriorNext);
        dtp2->Date = dt2 + (int(dt2 - dt1 + 1) * PriorNext);
        }
}

//------------------------------------------------------------------------
//          �����֘A�֐��S
//------------------------------------------------------------------------

// �[���}��
AnsiString ZeroSuppress(Currency v)
{
    if (v == 0)
        return AnsiString();
    else
        return AnsiString(v);
}

// �[�������֐�
// digit    {0:�������܂� -1:������P�ʂ܂� -2:������Q�ʂ܂�}
// fractionflag {0:�؎̂� 1:�l�̌ܓ� 2:�؏グ}
Currency ExtendedRound(Currency data, int digit, int fractionflag)
{
    Currency cyReturnValue = 0, cyShiftDigitData;
    // �[�������ʒu��ύX����
    if (digit != 0)
        cyShiftDigitData = data / pow(10, digit);
    else
        cyShiftDigitData = data;
    // �[������
    switch (fractionflag){
    case 0: // �؂�̂�
        cyReturnValue = floor(cyShiftDigitData);
        break;
    case 1: // �l�̌ܓ�
        if(cyShiftDigitData > 0.000)
            cyReturnValue =  ((cyShiftDigitData-floor(cyShiftDigitData)) < 0.5 ? floor(cyShiftDigitData):ceil(cyShiftDigitData));
        else
            cyReturnValue = (fabs(cyShiftDigitData-ceil(cyShiftDigitData)) < 0.5 ? ceil(cyShiftDigitData): floor(cyShiftDigitData));
        break;
    case 2: // �؂�グ
        cyReturnValue = ceil(cyShiftDigitData);
        break;
    }
    // ���炵���[�������ʒu�����ɖ߂�
    if (digit != 0)
        cyReturnValue = cyReturnValue * pow(10, digit);

    return cyReturnValue;
}

// �ő包����11���ȏ�15�������̊|���Z
Currency __fastcall BigMul(const Currency& lhs, const Currency& rhs){
    __int64 lv = lhs.Val;
    __int64 rv = rhs.Val;

    rv /= 10000;
    lv *= rv;

    Currency ret;
    ret.Val = lv;
    return ret;
}

// �ő包����11���ȏ�15�������̊���Z
Currency __fastcall BigDiv(const Currency& lhs, const Currency& rhs){
    __int64 lv = lhs.Val;
    __int64 rv = rhs.Val;

    rv /= 10000;
    lv /= rv;

    Currency ret;
    ret.Val = lv;
    return ret;
}

//------------------------------------------------------------------------
//          ���̑��֐��S
//------------------------------------------------------------------------

// �v�����^���w��
bool SetPrinter(TQuickRep *quickrep, AnsiString asPrtName)
{
    TQRPrinter *prn = QRPrinter();
    int Index = prn->Printers->IndexOf(asPrtName);
    // �v�����^��������Ȃ��� -- Index��-1
    if (Index < 0)
        return false;
    quickrep->PrinterSettings->PrinterIndex = Index;
    return true;
}

AnsiString Han2Zen(const AnsiString& src)
{
    AnsiString result;
    int size = src.Length() * 3 + 10;
    char *res = new char[size];
    ZeroMemory(res, size);
    LCMapString(GetUserDefaultLCID(), LCMAP_FULLWIDTH, src.c_str(), src.Length() + 1, res, size);
    result = res;
    delete[] res;
    return result;
}

AnsiString Zen2Han(const AnsiString& src)
{
    AnsiString result;
    int size = src.Length() * 3 + 10;
    char *res = new char[size];
    ZeroMemory(res, size);
    LCMapString(GetUserDefaultLCID(), LCMAP_HALFWIDTH, src.c_str(), src.Length() + 1, res, size);
    result = res;
    delete[] res;
    return result;
}

// �󔒁i�S�p�܂ށj�}��
AnsiString SpaceSuppress(const AnsiString& src)
{
    return AnsiReplaceStr(AnsiReplaceStr(src, " ", ""), "�@", "");
}

BOOL IsFileAlreadyOpen(const AnsiString& filename){
     HFILE theFile = HFILE_ERROR;
     DWORD lastErr  = NO_ERROR;

    // �t�@�C����r���I�[�v�����܂��B
    theFile = _lopen(filename.c_str(), OF_READ | OF_SHARE_EXCLUSIVE);

    if (theFile == HFILE_ERROR)      // ���̃G���[��ۑ����܂��B
         lastErr = GetLastError();
    else                                   // �����I�[�v�������ꍇ�́A�t�@�C�����N���[�Y���܂��B
         _lclose(theFile);

    // ���L�ᔽ������ꍇ�� TRUE ��Ԃ��܂��B
    return ((theFile == HFILE_ERROR) && (lastErr == ERROR_SHARING_VIOLATION));
}

//---------------------------------------------------------------------------

#endif  //_NsoftFuncH_
