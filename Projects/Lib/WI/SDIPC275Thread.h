//---------------------------------------------------------------------------

#ifndef SDIPC275ThreadH
#define SDIPC275ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// DIPC275 stream thread
class TSDIPC275Thread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall TSDIPC275Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
