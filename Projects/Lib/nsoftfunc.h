// nsoftfunc.h:     nsoft用関数郡

/*  更新内容
2005/07/15  「Table2Str」をCommaTextを使うように変更。
2005/05/17  「ShiftDate」の日付範囲に年範囲を追加。
2005/05/13  「IntToTime」を追加。
2005/05/12  「GetWeekDate」を追加。
        「ShiftDate」の日付範囲を月範囲以外でも可能にした。
2005/03/17  「GetFirstDate」を追加。
        「ShiftDate」を指定月分づらすように修正。
2005/07/22  「Table2Str」で"CommaText"を使用するようにした。
2007/10/04  「Table2Str」で"DisplayLabel"をフィールド名として出力するように変更。
2008/03/25  「BigMul」「BigDiv」を追加。
2008/11/05  「AnsiDivide」を追加。
2009/02/02  「AnsiSubString」を追加。
2009/07/01  「GetRyakusho を追加。
2009/08/27  「GetKishuDate」「GetKimatuDate」を追加。
2010/06/12  「CombineDateTime」を追加。
2010/12/07  「ZeroSuppress」を追加。
2011/01/31  「Table2Str」で "use_displaytext" 引数を true に設定すると
              DisplayText を使用するように。また、上記引数は省略可能なため
              旧来のソースはそのまま変更無しで元の動作を行う。
2011/11/04  「Han2Zen」を追加。
2012/12/20  「SpaceSuppress」を追加。
2013/01/24  「Zen2Han」を追加。
2013/02/01  「IntToTTime」を追加。
2013/05/24  「GetTimeDuration」を追加。
2013/08/12  「IsFileAlreadyOpen」を追加。
*/

#ifndef _NsoftFuncH_
#define _NsoftFuncH_

#include <QuickRpt.hpp>
#include <math.h>
#include <StrUtils.hpp>
#include <DateUtils.hpp>

//------------------------------------------------------------------------
//          データセット関連関数郡
//------------------------------------------------------------------------

// 指定テーブルのレコードを探す
bool FindRecord(TDataSet *ds, AnsiString field, Variant value)
{
    if (ds->Locate(field, value, TLocateOptions()))
        return true;
    else
        return false;
}

// 指定テーブルの名称を返す
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

// データセットを CSV出力
void Table2Str(TDataSet *ds, TStringList *list, bool fieldname, bool use_displaytext = false)
{
    int nRowCount, nColCount;
    nRowCount = 0;
    ds->FieldList->Text;
    TStringList *FieldList = new TStringList();
    // フィールド名
    if (fieldname){
        FieldList->Clear();
        for (nColCount = 0; nColCount < ds->FieldCount; nColCount++){
//          FieldList->Append(ds->FieldList->Strings[nColCount]);
            FieldList->Append(ds->Fields->Fields[nColCount]->DisplayLabel);
        }
        list->Add(FieldList->CommaText);
    }
    // データ
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

    /* 使用例
    #include <memory>
    
    std::auto_ptr<TStringList> Records(new TStringList());
    Table2Str(DM->Table1, Records.get(), false);
    SaveDialog->FileName = DM->Table1->TableName + "_" + Date().FormatString("yyyymmdd") + ".csv";
    if (SaveDialog->Execute())
        Records->SaveToFile(SaveDialog->FileName);
    */
}

//------------------------------------------------------------------------
//          日付関連関数群
//------------------------------------------------------------------------

// 日付文字列からスラッシュを取り除く
AnsiString RemoveSlash(AnsiString src){
    int idx = src.Pos('/');
    while (idx){
        src.Delete(idx, 1);
        idx = src.Pos('/');
    }
    return src;
}

// 日付文字列にスラッシュを挿入
AnsiString InsertSlash(AnsiString src){
    src.Insert("/", 5);
    src.Insert("/", 8);
    return src;
}

// 文字列を指定文字数で分割する
AnsiString AnsiDivide(AnsiString *args, int len)
{
    AnsiString buff;

    if (args->IsLeadByte(len))
        len--;

    buff = args->SubString(1, len);
    *args = args->SubString(len + 1, args->Length());

    return buff;
}

// MBS 対応 SubString
AnsiString AnsiSubString(const AnsiString& s, int pos, int len)
{
    // 頭のチェック
    if (pos != 1){
        if (s.IsLeadByte(pos - 1)){
            pos++;
            len--;
        }
    }
    // 尻のチェック
    if (s.IsLeadByte(pos + len - 1)){
        len--;
    }
    return s.SubString(pos, len);
}

// 名称から略称
AnsiString GetRyakusho(AnsiString meisho, int len)
{
    AnsiString name = meisho;
    name = AnsiReplaceStr(name, "株式会社", "(株)");
    name = AnsiReplaceStr(name, "有限会社", "(有)");
    name = AnsiReplaceStr(name, "合名会社", "(名)");
    name = AnsiReplaceStr(name, "合資会社", "(資)");
    name = AnsiReplaceStr(name, "財団法人", "(財)");
    name = AnsiReplaceStr(name, "合同会社", "(同)");
    name = AnsiSubString(name, 1, len);
    return name;
}

// 日付型変数を日付整数に変換
int DateToInt(TDateTime dt){
    WORD y, m, d;
    dt.DecodeDate(&y, &m, &d);
    return (y * 10000) + (m * 100) + d;
}

// 日付整数を日付型に変換
TDateTime IntToDate(int dt){
    WORD y, m, d;
    y = dt / 10000;
    m = (dt % 10000) / 100;
    d = dt % 100;
    return TDateTime(y, m, d);
}

// 指定年月の初日を取得
TDateTime GetFirstDate(TDateTime dt){
    WORD y, m, d;
    dt.DecodeDate(&y, &m, &d);
    d = 1;

    dt = EncodeDate(y, m, d);
    return dt;
}

// 指定年月の最終日を取得
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

// 前後の指定曜日の日付を取得
TDateTime GetWeekDate(TDateTime dt, int before_after, int week){
    while (DayOfWeek(dt) != week){
        if (before_after == 1)
            dt++;
        else
            dt--;
    }
    return dt;
}

// TDate と TTime を連結
TDateTime CombineDateTime(const TDate& date, const TTime& time)
{
    Word yyyy, mm, dd;
    Word hh, nn, ss, ms;

    date.DecodeDate(&yyyy, &mm, &dd);
    time.DecodeTime(&hh, &nn, &ss, &ms);

    return EncodeDateTime(yyyy, mm, dd, hh, nn, ss, ms);
}

// 期首日付を取得
TDateTime __fastcall GetKishuDate(TDateTime date, int kishu)
{
    int nMonth = DateToStr(date).SubString(6, 2).ToIntDef(0);
    while (nMonth != kishu){
        date = IncMonth(date, -1);
        nMonth = DateToStr(date).SubString(6, 2).ToIntDef(0);
    }
    
    return GetFirstDate(date);
}

// 期末日付を取得
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

/*  使用例.今週を取得
    GetWeekDate(Date(), -1, 1); // 範囲開始 日曜日
    GetWeekDate(Date(), 1, 7);  // 範囲終了 土曜日
*/

// 時間型整数を、時間整数に変換
int TimeToInt(TTime tm){
    Word h, m, s, ms;

    tm.DecodeTime(&h, &m, &s, &ms);
    return (h * 100) + m;
}

// 時間整数を、時間型文字列に変換
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

// 時間整数を TTime に変換
TTime IntToTTime(int n){
    short h, m;
    h = n / 100;
    m = n % 100;
    return TTime(h, m, 0, 0);
}

// 時間差を取得（ただし分単位まで）
//    bool use_hhmm -> false: 時間差を分単位で習得（default）
//                     true:  時間差を hhmm 形式で取得（何時間何分という形式を使用したい場合）
int GetTimeDuration(int t1, int t2, bool use_hhmm = false)
{
    int time1 = (t1 / 100) * 60 + t1 % 100;
    int time2 = (t2 / 100) * 60 + t2 % 100;
    int dur = time1 > time2 ? time1 - time2 : time2 - time1;

    return dur;

    /** 下記は、無理に hhmm 形式にしてるので、今回は不使用
    int hour, min;
    hour = dur / 60;
    min  = dur % 60;
    return hour * 100 + min;
    */
}

// 日付範囲の前後   PriorNext { 前範囲 : -1, 後範囲 : 1 }
void ShiftDate(TDateTimePicker *dtp1, TDateTimePicker *dtp2, int PriorNext){
    TDateTime dt1, dt2;
    unsigned short y, m, d;
    int nShiftMonth = PriorNext;

        if (int(dtp2->Date - dtp1->Date) >= 27 && int(dtp2->Date - dtp1->Date) <= 30){
            // 月範囲
        while (nShiftMonth < 0){    // <- 前範囲
            dt1 = IncMonth(dtp1->Date, -1);
            dt2 = IncMonth(dtp2->Date, -1);
            dtp1->Date = dt1;
            if (DateToInt(dtp2->Date) == DateToInt(GetLastDate(dtp2->Date)))
                dtp2->Date = GetLastDate(dt2);
            else
                dtp2->Date = dt2;
            nShiftMonth++;
        }
        while (nShiftMonth > 0){    // -> 後範囲
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
        // 年範囲
        if (nShiftMonth < 0){   // <- 前範囲
            dt1 = IncMonth(dtp1->Date, -12);
            dt2 = IncMonth(dtp2->Date, -12);
            dtp1->Date = dt1;
            if (DateToInt(dtp2->Date) == DateToInt(GetLastDate(dtp2->Date)))
                dtp2->Date = GetLastDate(dt2);
            else
                dtp2->Date = dt2;

        }else{          // -> 後範囲
            dt1 = IncMonth(dtp1->Date, 12);
            dt2 = IncMonth(dtp2->Date, 12);
            dtp1->Date = dt1;
            if (DateToInt(dtp2->Date) == DateToInt(GetLastDate(dtp2->Date)))
                dtp2->Date = GetLastDate(dt2);
            else
                dtp2->Date = dt2;
        }

    }else{
            // その他範囲
                dt1 = dtp1->Date;
                dt2 = dtp2->Date;
        dtp1->Date = dt1 + (int(dt2 - dt1 + 1) * PriorNext);
        dtp2->Date = dt2 + (int(dt2 - dt1 + 1) * PriorNext);
        }
}

//------------------------------------------------------------------------
//          数字関連関数郡
//------------------------------------------------------------------------

// ゼロ抑制
AnsiString ZeroSuppress(Currency v)
{
    if (v == 0)
        return AnsiString();
    else
        return AnsiString(v);
}

// 端数処理関数
// digit    {0:整数部まで -1:小数第１位まで -2:小数第２位まで}
// fractionflag {0:切捨て 1:四捨五入 2:切上げ}
Currency ExtendedRound(Currency data, int digit, int fractionflag)
{
    Currency cyReturnValue = 0, cyShiftDigitData;
    // 端数処理位置を変更する
    if (digit != 0)
        cyShiftDigitData = data / pow(10, digit);
    else
        cyShiftDigitData = data;
    // 端数処理
    switch (fractionflag){
    case 0: // 切り捨て
        cyReturnValue = floor(cyShiftDigitData);
        break;
    case 1: // 四捨五入
        if(cyShiftDigitData > 0.000)
            cyReturnValue =  ((cyShiftDigitData-floor(cyShiftDigitData)) < 0.5 ? floor(cyShiftDigitData):ceil(cyShiftDigitData));
        else
            cyReturnValue = (fabs(cyShiftDigitData-ceil(cyShiftDigitData)) < 0.5 ? ceil(cyShiftDigitData): floor(cyShiftDigitData));
        break;
    case 2: // 切り上げ
        cyReturnValue = ceil(cyShiftDigitData);
        break;
    }
    // ずらした端数処理位置を元に戻す
    if (digit != 0)
        cyReturnValue = cyReturnValue * pow(10, digit);

    return cyReturnValue;
}

// 最大桁数が11桁以上15桁未満の掛け算
Currency __fastcall BigMul(const Currency& lhs, const Currency& rhs){
    __int64 lv = lhs.Val;
    __int64 rv = rhs.Val;

    rv /= 10000;
    lv *= rv;

    Currency ret;
    ret.Val = lv;
    return ret;
}

// 最大桁数が11桁以上15桁未満の割り算
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
//          その他関数郡
//------------------------------------------------------------------------

// プリンタを指定
bool SetPrinter(TQuickRep *quickrep, AnsiString asPrtName)
{
    TQRPrinter *prn = QRPrinter();
    int Index = prn->Printers->IndexOf(asPrtName);
    // プリンタが見つからない時 -- Indexは-1
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

// 空白（全角含む）抑制
AnsiString SpaceSuppress(const AnsiString& src)
{
    return AnsiReplaceStr(AnsiReplaceStr(src, " ", ""), "　", "");
}

BOOL IsFileAlreadyOpen(const AnsiString& filename){
     HFILE theFile = HFILE_ERROR;
     DWORD lastErr  = NO_ERROR;

    // ファイルを排他オープンします。
    theFile = _lopen(filename.c_str(), OF_READ | OF_SHARE_EXCLUSIVE);

    if (theFile == HFILE_ERROR)      // 今のエラーを保存します。
         lastErr = GetLastError();
    else                                   // 無事オープンした場合は、ファイルをクローズします。
         _lclose(theFile);

    // 共有違反がある場合は TRUE を返します。
    return ((theFile == HFILE_ERROR) && (lastErr == ERROR_SHARING_VIOLATION));
}

//---------------------------------------------------------------------------

#endif  //_NsoftFuncH_
