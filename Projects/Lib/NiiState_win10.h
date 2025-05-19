/** NiiState.h
 *      Nii �v�����^�X�e�[�^�X�擾�N���X�w�b�_�[
 *
 *     @author  a_oshima
 *     @history
 *                  2008-01-07  �쐬
 */

#ifndef NiiState_H_
#define NiiState_H_

class NiiStatusInterface {
public:
    NiiStatusInterface();
    virtual ~NiiStatusInterface();
    
    void Initialize(const AnsiString& printer_name);
    AnsiString GetStatusText(int *result, DWORD *status);
private:
	HMODULE nii_dll_;
	AnsiString printer_name_;

typedef INT	__stdcall (*FNiiGetStatus)(LPCSTR, LPDWORD);
FNiiGetStatus NiiGetStatus;

};

#endif  //NiiState_H_
