/** NiiState.cpp
 *      Nii プリンタステータス取得クラス
 */

#include <vcl.h>
#pragma hdrstop

#include "NiiState_win10.h"

NiiStatusInterface::NiiStatusInterface() : nii_dll_(0) {
}

void NiiStatusInterface::Initialize(const AnsiString& printer_name){
    printer_name_ = printer_name;
    
    if (nii_dll_)
        FreeLibrary(nii_dll_);
    
    nii_dll_ = LoadLibrary("NPrinterLib.DLL");
    if (!nii_dll_)
        throw Exception("Nii DLL がロードできません");

    NiiGetStatus = (FNiiGetStatus)GetProcAddress(nii_dll_, "NGetStatusA");
    if (!NiiGetStatus)
        throw Exception("Nii API がロードできません");
}

NiiStatusInterface::~NiiStatusInterface(){
    if (nii_dll_)
        FreeLibrary(nii_dll_);
}

AnsiString NiiStatusInterface::GetStatusText(int *result, DWORD *status){
    *status = 0;
	*result = NiiGetStatus(printer_name_.c_str(), status);

	if (*result == 1)
		*result = NiiGetStatus(printer_name_.c_str(), status);

	AnsiString status_text;

	switch (*result){
	//case   0: result_text = "ステータス取得成功";         break;
	case   0: status_text = "";                             break;
	case  -3: status_text = "プリンタオープンエラー";       break;
	case  -5: status_text = "プリンタ OFFLINE";             break;
	case  -9: status_text = "プリンタ情報取得エラー";       break;
	case -11: status_text = "ステータス情報取得エラー";     break;
	case -12: status_text = "ステータス情報オープンエラー"; break;
	default:  status_text = "ステータス取得結果不明";       break;
	}

	if (!status_text.IsEmpty())
		status_text += " - ";

    switch (*status){
    case  1: status_text += "用紙なし";                             break;
    case  2: status_text += "プレゼンターオープン（給紙済）";       break;
    case  3: status_text += "プレゼンターオープン";                 break;
    case  4: status_text += "未給紙";                               break;
    case  5: status_text += "ロール紙未装着";                       break;
    case  6: status_text += "プレゼンターオープン（未給紙）";       break;
    case  7: status_text += "プレゼンターオープン＆ロール紙未装着"; break;
    default: status_text += "不明(" + IntToStr(status) + ")";       break;
    }
    
    return status_text;
}

