/** NiiState.h
 *      Nii プリンタステータス取得クラスヘッダー
 *
 *     @author  a_oshima
 *     @history
 *                  2008-01-07  作成
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
