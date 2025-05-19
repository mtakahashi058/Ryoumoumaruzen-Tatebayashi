//---------------------------------------------------------------------------

#ifndef CAD4401TcpThreadH
#define CAD4401TcpThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <string>
#include "wicommon.h"
#include "clientSocket.h"
//---------------------------------------------------------------------------
class CAD4401TcpThread : public TThread
{
private:
protected:
    void __fastcall Execute();

    clientSocket socket_;

    void __fastcall OnSocketError(const AnsiString& message);
    void __fastcall OnSocketRead(const AnsiString& data);

    const WITcpInfo info_;
    WICommStatus status_;
    WIWeight weight_;

public:
    __fastcall CAD4401TcpThread(bool CreateSuspended, const WITcpInfo& info);
};
//---------------------------------------------------------------------------
#endif
