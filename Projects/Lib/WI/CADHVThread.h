//---------------------------------------------------------------------------

#ifndef CADHVThreadH
#define CADHVThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// CADHV thread
class TCADHVThread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall TCADHVThread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
