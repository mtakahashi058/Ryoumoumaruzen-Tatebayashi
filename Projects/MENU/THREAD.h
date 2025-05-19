//---------------------------------------------------------------------------
#ifndef threadH
#define threadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
#define UM_EXECTERMINATE	(WM_USER + 1)
//---------------------------------------------------------------------------
class TExecThread : public TThread
{
private:
protected:
	void __fastcall Execute();
	AnsiString ExeName;
	HWND hWndOwner;
public:
	__fastcall TExecThread(bool CreateSuspended, AnsiString name, HWND hWnd);
};
//---------------------------------------------------------------------------
#endif
