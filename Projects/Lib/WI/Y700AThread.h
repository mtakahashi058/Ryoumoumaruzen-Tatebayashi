//---------------------------------------------------------------------------

#ifndef Y700AThreadH
#define Y700AThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// Y700A thread
class TY700AThread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall TY700AThread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
