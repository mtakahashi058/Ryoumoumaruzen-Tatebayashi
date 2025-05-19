//---------------------------------------------------------------------------

#ifndef clientSocketH
#define clientSocketH
#include <ScktComp.hpp>
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TMBReadEvent)(const AnsiString& read);
typedef void __fastcall (__closure *TMBErrorEvent)(const AnsiString& message);

class clientSocket {
public:
	__fastcall clientSocket(TComponent* owner);
	__fastcall ~clientSocket();

    void __fastcall SetHandler(TMBReadEvent read_handler, TMBErrorEvent err_handler);

	void __fastcall Open(const AnsiString& host, int port = 57100);
	void __fastcall Close();
	bool __fastcall IsActive();
    void __fastcall Reopen();
    bool __fastcall WaitForData();
	bool __fastcall CanCommand();
    bool __fastcall SendCommand(LPBYTE buff, int len);
    void __fastcall ReadCommand();

	void __fastcall OnSocketConnect(TObject* Sender, TCustomWinSocket* Socket);
	void __fastcall OnSocketDisconnect(TObject* Sender, TCustomWinSocket* Socket);
	void __fastcall OnSocketRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall OnSocketError(TObject *Sender, TCustomWinSocket *Socket,
		TErrorEvent ErrorEvent, int &ErrorCode);

protected:

    TMBReadEvent read_handler_;
    TMBErrorEvent error_handler_;

	TComponent* owner_;
	TClientSocket* socket_;
    TWinSocketStream *sock_stream_;
};
#endif
