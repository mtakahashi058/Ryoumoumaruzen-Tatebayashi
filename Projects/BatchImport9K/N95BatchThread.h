//---------------------------------------------------------------------------

#ifndef N95BatchThreadH
#define N95BatchThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "BatMsgs.h"
//---------------------------------------------------------------------------
class TN95BatchThread : public TThread
{            
private:
protected:
    void __fastcall Execute();
    int port_;
    AnsiString def_;
    HWND owner_;
public:
    __fastcall TN95BatchThread(bool CreateSuspended, int port, const AnsiString& def, HWND owner);
};
//---------------------------------------------------------------------------
#endif
