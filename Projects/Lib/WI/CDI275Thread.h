//---------------------------------------------------------------------------

#ifndef CDI275ThreadH
#define CDI275ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// CDI275 thread
class TCDI275Thread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall TCDI275Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
