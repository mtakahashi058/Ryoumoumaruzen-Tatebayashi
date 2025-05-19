// ioMirrorE3210.cpp

#include <vcl.h>
#pragma hdrstop

#include "ioMirrorE3210.h"

__fastcall ioMirrorE3210::ioMirrorE3210(TComponent* owner) : owner_(owner),	sock_stream_(0) {
	client_socket_ = new TClientSocket(owner);
}

__fastcall ioMirrorE3210::~ioMirrorE3210(){
	if (sock_stream_)
		delete sock_stream_;
	delete client_socket_;
}

void __fastcall ioMirrorE3210::SetHandler(TMBReadEvent read_handler, TMBResponseEvent res_handler, TMBErrorEvent err_handler){
	read_handler_     = read_handler;
	response_handler_ = res_handler;
	error_handler_    = err_handler;
}

void __fastcall ioMirrorE3210::Open(const STRING& host, int port){
	if (!client_socket_)
		return;

	client_socket_->ClientType = ctBlocking;
	client_socket_->OnConnect    = OnSocketConnect;
	client_socket_->OnDisconnect = OnSocketDisconnect;
	client_socket_->OnError      = OnSocketError;
	//client_socket_->OnRead       = OnSocketRead;
	client_socket_->Host         = host;
	client_socket_->Port         = port;
	client_socket_->Open();
}

void __fastcall ioMirrorE3210::Close(){
	if (!client_socket_)
		return;
	client_socket_->Close();
}

bool __fastcall ioMirrorE3210::IsActive(){
	if (client_socket_)
		if (client_socket_->Active)
			return true;
	return false;
}

bool __fastcall ioMirrorE3210::CanCommand(){
	if (!IsActive())
		return false;
	return true;
}

bool __fastcall ioMirrorE3210::OutputSingle(int ch, bool value){
	BYTE buff[20];
	int len = CreateDOCommand(buff, ch, value);
	return SendCommand(buff, len);
}

bool __fastcall ioMirrorE3210::OutputAll(BF8 octet){
	BYTE buff[20];
	int len = CreateDOMultiCommand(buff, octet.val);
	return SendCommand(buff, len);
}

bool __fastcall ioMirrorE3210::OutputAll(BYTE value){
	BYTE buff[20];
	int len = CreateDOMultiCommand(buff, value);
	return SendCommand(buff, len);
}

bool __fastcall ioMirrorE3210::InputSingle(int ch){
	return false;
}

bool __fastcall ioMirrorE3210::InputAll(){
	BYTE buff[20];
	int len = CreateDIMultiCommand(buff, 8);
	return SendCommand(buff, len);
}

bool __fastcall ioMirrorE3210::SendCommand(LPBYTE buff, int len){
	if (!sock_stream_->Write(buff, len))
		return false;

	ReadCommand();
	return true;
}

void __fastcall ioMirrorE3210::ReadCommand(){
	BYTE buff[20];
	int len = sock_stream_->Read(buff, 12);

	STRING response;
	TCHAR hex[3];
	for (int i = 0; i < len; i++) {
		wsprintf(hex, CSTR("%02X"), buff[i]);
		response += hex;
	}

	if (buff[0] == 1){		// Function 1 に対するレスポンス
		Channels channels(buff[len - 1]);
		if (read_handler_)
			read_handler_(channels);
	}else{
		if (response_handler_)
			response_handler_(response);
	}
}

int __fastcall ioMirrorE3210::CreateDOCommand(LPBYTE buff, char ch, bool value){
	buff[ 0] = 0;						// transaction identifier (1/2)
	buff[ 1] = 0;						// transaction identifier (2/2)
	buff[ 2] = 0;						// protocol identifier (1/2)
	buff[ 3] = 0;						// protocol identifier (2/2)
	buff[ 4] = 0;						// message length (1/2)
	buff[ 5] = 6;    					// message length (2/2)
	buff[ 6] = UNIT_IDENTIFIER;
	buff[ 7] = 5;
	///// data section
	buff[ 8] = 0;						// 16bit address (1/2)
	buff[ 9] = 0 + ch;					// 16bit address (2/2)
	buff[10] = value ? 0xff : 0;
	buff[11] = 0;

	return 12;
}

int __fastcall ioMirrorE3210::CreateDOMultiCommand(LPBYTE buff, BYTE value, char count){
	buff[ 0] = 0;						// transaction identifier (1/2)
	buff[ 1] = 1;						// transaction identifier (2/2)
	buff[ 2] = 0;						// protocol identifier (1/2)
	buff[ 3] = 0;						// protocol identifier (2/2)
	buff[ 4] = 0;						// message length (1/2)
	buff[ 5] = 8;    					// message length (2/2)
	buff[ 6] = UNIT_IDENTIFIER;
	buff[ 7] = 15;
	///// data section
	buff[ 8] = 0;						// 16bit address (1/2)
	buff[ 9] = 0;						// 16bit address (2/2)
	buff[10] = 0;						// number of coils (1/2)
	buff[11] = 8;                       // number of coils (2/2)
	buff[12] = 1;						// number of bytes of coil value to follow
	buff[13] = value;

	return 14;
}

int __fastcall ioMirrorE3210::CreateDIMultiCommand(LPBYTE buff, char count){
	buff[ 0] = 1;						// transaction identifier (1/2)
	buff[ 1] = 0;						// transaction identifier (2/2)
	buff[ 2] = 0;						// protocol identifier (1/2)
	buff[ 3] = 0;						// protocol identifier (2/2)
	buff[ 4] = 0;						// message length (1/2)
	buff[ 5] = 6;    					// message length (2/2)
	buff[ 6] = UNIT_IDENTIFIER;
	buff[ 7] = 2;
	///// data section
	buff[ 8] = 0;						// 16bit address (1/2)
	buff[ 9] = 0;						// 16bit address (2/2)
	buff[10] = 0;						// number of coil (1/2)
	buff[11] = count;                 	// number of coil (2/2)

	return 12;
}

void __fastcall ioMirrorE3210::OnSocketConnect(TObject* Sender, TCustomWinSocket* Socket){
	sock_stream_ = new TWinSocketStream(Socket, 100000);
}

void __fastcall ioMirrorE3210::OnSocketDisconnect(TObject* Sender, TCustomWinSocket* Socket){
	delete sock_stream_;
	sock_stream_ = 0;
}

/*
void __fastcall ioMirrorE3210::OnSocketRead(TObject* Sender, TCustomWinSocket* Socket){
	if (Sender != client_socket_)
		return;

	LPBYTE buff;
	int len = Socket->ReceiveLength();

	buff = new BYTE[len + 1];
	Socket->ReceiveBuf(buff, len);

	STRING response;
	TCHAR hex[3];
	for (int i = 0; i < len; i++) {
		wsprintf(hex, CSTR("%02X"), buff[i]);
		response += hex;
	}

	if (buff[0] == 1){		// Function 1 に対するレスポンス
		Channels channels(buff[len - 1]);
		if (read_handler_)
			read_handler_(channels);
	}else{
		if (response_handler_)
			response_handler_(response);
	}

	delete[] buff;
}
*/

void __fastcall ioMirrorE3210::OnSocketError(TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode){
	if (Sender != client_socket_)
		return;

	if (error_handler_){
		switch (ErrorEvent){
		case eeReceive:
			error_handler_(CSTR("Modbus/TCP: 受信エラー"));
			break;
		case eeConnect:
			error_handler_(CSTR("Modbus/TCP: 接続エラー"));
			break;
		case eeDisconnect:
			error_handler_(CSTR("Modbus/TCP: 切断エラー"));
			break;
		default:
			error_handler_(CSTR("Modbus/TCP: 一般エラー"));
			break;
		};
	}

	Socket->Close();
    client_socket_->Close();

    ErrorCode = 0;
}

