/** NiiState.cpp
 *      Nii �v�����^�X�e�[�^�X�擾�N���X
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
        throw Exception("Nii DLL �����[�h�ł��܂���");

    NiiGetStatus = (FNiiGetStatus)GetProcAddress(nii_dll_, "NGetStatusA");
    if (!NiiGetStatus)
        throw Exception("Nii API �����[�h�ł��܂���");
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
	//case   0: result_text = "�X�e�[�^�X�擾����";         break;
	case   0: status_text = "";                             break;
	case  -3: status_text = "�v�����^�I�[�v���G���[";       break;
	case  -5: status_text = "�v�����^ OFFLINE";             break;
	case  -9: status_text = "�v�����^���擾�G���[";       break;
	case -11: status_text = "�X�e�[�^�X���擾�G���[";     break;
	case -12: status_text = "�X�e�[�^�X���I�[�v���G���["; break;
	default:  status_text = "�X�e�[�^�X�擾���ʕs��";       break;
	}

	if (!status_text.IsEmpty())
		status_text += " - ";

    switch (*status){
    case  1: status_text += "�p���Ȃ�";                             break;
    case  2: status_text += "�v���[���^�[�I�[�v���i�����ρj";       break;
    case  3: status_text += "�v���[���^�[�I�[�v��";                 break;
    case  4: status_text += "������";                               break;
    case  5: status_text += "���[����������";                       break;
    case  6: status_text += "�v���[���^�[�I�[�v���i�������j";       break;
    case  7: status_text += "�v���[���^�[�I�[�v�������[����������"; break;
    default: status_text += "�s��(" + IntToStr(status) + ")";       break;
    }
    
    return status_text;
}

