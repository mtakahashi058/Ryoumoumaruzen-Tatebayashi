//---------------------------------------------------------------------------

#ifndef SKW201012ThreadH
#define SKW201012ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// ��S�i�s���^�����F2010-12�j stream thread
class TSKW201012Thread : public TThread
{
private:
protected:
    void __fastcall Execute();
    bool __fastcall formatMessage(std::string& msg);
    const WICommInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall TSKW201012Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
