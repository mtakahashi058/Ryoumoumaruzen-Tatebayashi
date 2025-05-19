//---------------------------------------------------------------------------

#ifndef CCSD904ThreadH
#define CCSD904ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// CCSD904 thread
class TCCSD904Thread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    void __fastcall SetZero();

    ackl::OverlappedComm comm_;
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall TCCSD904Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
