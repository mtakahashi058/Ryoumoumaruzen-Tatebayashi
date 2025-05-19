/////////////////////////////////////////////////////////////////////////////////
// CComm.cpp: 通信ポート制御ラッパークラスヘッダー			       //
//									       //
//			   <作 成 者>	 大島晶博			       //
//			   <注意事項>	 非同期I/O未サポート		       //
//					 バイナリデータはLPBYTEにキャスト      //
//					 タイムアウト処理をする場合は	       //
//					 SetTimeout() を呼ぶこと	       //
//			   <履	  歴>	 2001.11.13 コピーコンストラクタ追加   //
//						    呼出規約の削除	       //
/////////////////////////////////////////////////////////////////////////////////

#ifndef _CCommH_
#define _CCommH_

#define STX			(0x02)
#define ETX			(0x03)
#define EOT			(0x04)
#define ENQ			(0x05)
#define	ACK			(0x06)
#define NAK			(0x15)

#define COMMERR_INVALIDID	(0)
#define COMMERR_NOTCLOSE	(1)
#define	COMMERR_NOTOPEN		(2)
#define COMMERR_BREAK		(3)
#define COMMERR_FRAME		(4)
#define COMMERR_IOE		(5)
#define COMMERR_MODE		(6)
#define COMMERR_OOP		(7)
#define COMMERR_OVERRUN		(8)
#define	COMMERR_RXOVER		(9)
#define COMMERR_RXPARITY	(10)
#define COMMERR_TXFULL		(11)
#define COMMERR_DNS		(12)
#define COMMERR_PTO		(13)

typedef unsigned char byte;
typedef byte *LPBYTE;

class CComm
{
public:
	//------------------ 通信処理エラー
	class CommCtrlException
	{
	public:
		CommCtrlException(LPCSTR pMessage, int nErrCode)
		{
			pExceptionMsg = pMessage;
			nExceptionErrCode = nErrCode;
		}
		LPCSTR GetMessage() {return pExceptionMsg;}
		int GetErrCode() {return nExceptionErrCode;}
	private:
		LPCSTR pExceptionMsg;
		int nExceptionErrCode;
	};

	CComm();
	CComm(const CComm& Comm){
		if (IsOpened()){
			Close();
		}
		Handle = Comm.Handle;
		stDCB = Comm.stDCB;
	}
	~CComm();
	bool Open(short nPort);
	bool Open(short nPort, LPCSTR pDefString);
	bool Open(short nPort, DCB *pstDCB);
	bool Open(LPCSTR pPort);
	bool Open(LPCSTR pPort, LPCSTR pDefString);
	bool Open(LPCSTR pPort, DCB *pstDCB);
	void Close();
	bool SetupComm(DCB *pstDCB);
	bool SetupComm(LPCSTR pDefString);
	bool GetState(DCB *pstDCB);
	bool WaitChar(char cChar, DWORD dwTimeoutMSecond = 3000);
	DWORD WaitRead(LPSTR pDest, DWORD dwLength, DWORD dwTimeoutMSecond = 3000);
	DWORD WaitRead(LPBYTE pDest, DWORD dwLength, DWORD dwTimeoutMSecond = 3000);
	DWORD Read(LPSTR pDest, DWORD dwLength);
	DWORD Read(LPBYTE pDest, DWORD dwLength);
	DWORD WaitWrite(LPCSTR pSrc, DWORD dwTimeoutMSecond = 3000);
	DWORD WaitWrite(LPBYTE pSrc, DWORD dwLength, DWORD dwTimeoutMSecond = 3000);
	DWORD Write(LPCSTR pSrc);
	DWORD Write(LPBYTE pSrc, DWORD dwLength);
	bool SetTimeout(COMMTIMEOUTS *pstTimeouts = NULL);
	bool FlushSendBuffers();
	bool Purge(DWORD dwAction = PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	DWORD ClearError(COMSTAT *pstComst = NULL);
	short ReceiveChar(DWORD dwTimeoutMSecond = 3000);
	bool SendChar(char ch);
	bool ReadWord(WORD *pwDest);
	bool WriteWord(WORD *pwSrc);
	bool ReadDWord(DWORD *pdwDest);
	bool WriteDWord(DWORD *pdwSrc);
	bool EscapeFunction(DWORD dwFunc);
	void Terminate() {bTerminated = true;}
	bool IsOpened() {return Handle != INVALID_HANDLE_VALUE;}
	HANDLE Handle;
private:
	DCB stDCB;
	bool bTerminated;
};

#endif	// _CComH_
