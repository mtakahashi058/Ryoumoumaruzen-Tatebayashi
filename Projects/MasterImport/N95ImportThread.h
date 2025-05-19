//---------------------------------------------------------------------------

#ifndef N95ImportThreadH
#define N95ImportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "BatMsgs.h"
//---------------------------------------------------------------------------
enum ImportTarget {itID, itItem};
//---------------------------------------------------------------------------
class TN95ImportThread : public TThread
{            
private:
protected:
    void __fastcall Execute();
    int port_;
    AnsiString def_;
    HWND owner_;
    AnsiString command_;
public:
    __fastcall TN95ImportThread(bool CreateSuspended, int port, const AnsiString& def, HWND owner, ImportTarget target);
};
//---------------------------------------------------------------------------
#endif
