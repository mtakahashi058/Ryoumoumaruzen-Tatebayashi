//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <string>
#include "clientSocket.h"

//---------------------------------------------------------------------------
__fastcall clientSocket::clientSocket(TComponent* owner)
	: owner_(owner),sock_stream_(0)
{
	socket_ = new TClientSocket(0);
}

__fastcall clientSocket::~clientSocket()
{
    if (sock_stream_)
        delete sock_stream_;
	delete socket_;
}

void __fastcall clientSocket::SetHandler(TMBReadEvent read_handler, TMBErrorEvent err_handler)
{
    read_handler_ = read_handler;
    error_handler_ = err_handler;
}

bool __fastcall clientSocket::IsActive()
{
    if (socket_)
        if (socket_->Active)
            return true;

    return false;
}

void __fastcall clientSocket::Reopen()
{
    if (socket_->Active)
        return;

    try{

        socket_->Socket->Close();
        socket_->Open();

    }catch(...){

    }
}


bool __fastcall clientSocket::WaitForData()
{
    return sock_stream_->WaitForData(500);
}


bool __fastcall clientSocket::CanCommand()
{
    if (!IsActive())
        return false;

    return true;
}

void __fastcall clientSocket::ReadCommand()
{
    std::string buf = "";
    int len = sock_stream_->Read(buf.begin(), 100);

    read_handler_(buf.c_str());
}

bool __fastcall clientSocket::SendCommand(LPBYTE buff, int len)
{
	if (!sock_stream_->Write(buff, len))
		return false;

	//ReadCommand();
	return true;
}


void __fastcall clientSocket::Open(const AnsiString& host, int port)
{
    if (!socket_)
        return;

	socket_->ClientType = ctBlocking;
	socket_->OnRead = OnSocketRead;
	socket_->OnError = OnSocketError;
    socket_->OnDisconnect = OnSocketDisconnect;
    socket_->OnConnect = OnSocketConnect;
	socket_->Port = port;
	socket_->Host = host;

    socket_->Socket->Open("", host, "", port, false);

}

void __fastcall clientSocket::Close()
{
	socket_->Socket->Close();
}


void __fastcall clientSocket::OnSocketRead(TObject *Sender, TCustomWinSocket *Socket)
{
	AnsiString msg = Socket->ReceiveText();
}

void __fastcall clientSocket::OnSocketConnect(TObject* Sender, TCustomWinSocket* Socket){
	sock_stream_ = new TWinSocketStream(Socket, 100000);
}

void __fastcall clientSocket::OnSocketDisconnect(TObject* Sender, TCustomWinSocket* Socket){
	delete sock_stream_;
	sock_stream_ = 0;
}


void __fastcall clientSocket::OnSocketError(TObject *Sender, TCustomWinSocket *Socket,
	TErrorEvent ErrorEvent, int &ErrorCode)
{
	AnsiString msg = "Error: " + IntToStr(ErrorCode);
}

#pragma package(smart_init)
