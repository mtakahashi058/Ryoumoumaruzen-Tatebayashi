// ioMirrorE3210.h:

#ifndef ioMirrorE3210_h_
#define ioMirrorE3210_h_

#include "ns_compatible.h"
#include "BitField.h"
#include <ScktComp.hpp>

#define UNIT_IDENTIFIER		(1)

typedef void __fastcall (__closure *TMBReadEvent)(const Channels& channels);
typedef void __fastcall (__closure *TMBResponseEvent)(const STRING& message);
typedef void __fastcall (__closure *TMBErrorEvent)(const STRING& message);

class ioMirrorE3210 {
public:
	__fastcall ioMirrorE3210(TComponent* owner);
	__fastcall virtual ~ioMirrorE3210();

	void __fastcall SetHandler(TMBReadEvent read_handler, TMBResponseEvent res_handler, TMBErrorEvent err_handler);

	void __fastcall Open(const STRING& host, int port = 502);		// throws Exception
	void __fastcall Close();
	bool __fastcall IsActive();
	bool __fastcall CanCommand();

	bool __fastcall OutputSingle(int ch, bool value);		// start_ch: 0
	bool __fastcall OutputAll(BF8 octet);
	bool __fastcall OutputAll(BYTE value = 0);				// value: 8bits

	bool __fastcall InputSingle(int ch);					// start_ch: 0 *** not implemented ***
	bool __fastcall InputAll();

	void __fastcall OnSocketConnect(TObject* Sender, TCustomWinSocket* Socket);
	void __fastcall OnSocketDisconnect(TObject* Sender, TCustomWinSocket* Socket);
	//void __fastcall OnSocketRead(TObject* Sender, TCustomWinSocket* Socket);
	void __fastcall OnSocketError(TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);
protected:
	TMBReadEvent read_handler_;
	TMBResponseEvent response_handler_;
	TMBErrorEvent error_handler_;

	bool __fastcall SendCommand(LPBYTE buff, int len);
	void __fastcall ReadCommand();

	int __fastcall CreateDOCommand(LPBYTE buff, char ch, bool value);
	int __fastcall CreateDOMultiCommand(LPBYTE buff, BYTE value, char count = 8);
	int __fastcall CreateDIMultiCommand(LPBYTE buff, char count = 8);

	TComponent* owner_;
	TClientSocket *client_socket_;
	TWinSocketStream *sock_stream_;
};

#endif  //ioMirrorE3210_h_
