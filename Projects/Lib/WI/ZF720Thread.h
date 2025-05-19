//---------------------------------------------------------------------------

#ifndef ZF720ThreadH
#define ZF720ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// F720 thread(zero set supported)
class TZF720Thread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    void __fastcall SetZero();
    void __fastcall CancelZero();
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
    ackl::OverlappedComm comm_;
public:
    __fastcall TZF720Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
