//---------------------------------------------------------------------------

#ifndef CCSD904ADThreadH
#define CCSD904ADThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// CCSD904AD thread
class TCCSD904ADThread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall TCCSD904ADThread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
