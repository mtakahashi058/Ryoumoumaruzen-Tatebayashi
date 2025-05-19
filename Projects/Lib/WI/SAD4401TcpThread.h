//---------------------------------------------------------------------------

#ifndef SAD4401TcpThreadH
#define SAD4401TcpThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <string>
#include "wicommon.h"
#include "clientSocket.h"
//---------------------------------------------------------------------------
class SAD4401TCPThread : public TThread
{
private:
protected:
    void __fastcall Execute();

    clientSocket socket_;

    void __fastcall OnSocketRead(const AnsiString& data);
    void __fastcall OnSocketError(const AnsiString& message);

    const WITcpInfo info_;
    WICommStatus status_;
    WIWeight weight_;
public:
    __fastcall SAD4401TCPThread(bool CreateSuspended, const WITcpInfo& info);
};
//---------------------------------------------------------------------------
#endif
