/////////////////////////////////////////////////////////////////////////////////
// CComm.cpp: 通信ポート制御ラッパークラスインプリメント		       //
//									       //
//			   <会社名>	 ニッコーソフトウェア		       //
//			   <作成者>	 大島晶博			       //
//			   <備	考>	 修正履歴等はヘッダーを参照のこと      //
/////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include "CComm.h"

/////////////////////////////////////////////////////////////////////////////////
// CComm::CComm - コンストラクタ					       //
// ポートハンドルの初期化、DCB構造体のクリア、				       //
// エラーメッセージキャプションの初期化					       //
/////////////////////////////////////////////////////////////////////////////////
CComm::CComm()
{
	Handle = INVALID_HANDLE_VALUE;
	ZeroMemory(&stDCB, sizeof(stDCB));
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::~CComm - デストラクタ						       //
// ポートハンドルの廃棄							       //
/////////////////////////////////////////////////////////////////////////////////
CComm::~CComm()
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("Closeされていないオブジェクトが破棄されました",
			COMMERR_NOTCLOSE);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// 通信ポートのオープン							       //
// short nPort : オープンするポートID					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(short nPort)
{
	if (nPort < 1 || nPort > 9)
		throw CommCtrlException("サポートされていないポートIDが指定されました",
			COMMERR_INVALIDID);
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは閉じていません", COMMERR_NOTCLOSE);
	char szPortName[5] = "COM";
	szPortName[3] = (char)(nPort + 0x30);
	szPortName[4] = '\0';
	Handle =  CreateFile(szPortName,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// 通信ポートのオープン							       //
// short nPort : オープンするポートID					       //
// LPSTR pDefString : ポート設定文字列					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(short nPort, LPCSTR pDefString)
{
	if (nPort < 1 || nPort > 9)
		throw CommCtrlException("サポートされていないポートIDが指定されました",
			COMMERR_INVALIDID);
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは閉じていません", COMMERR_NOTCLOSE);
	char szPortName[5] = "COM";
	szPortName[3] = (char)(nPort + 0x30);
	szPortName[4] = '\0';
	Handle =  CreateFile(szPortName,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	BuildCommDCB(pDefString, &stDCB);
	SetCommState(Handle, &stDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// 通信ポートのオープン							       //
// short nPort : オープンするポートID					       //
// DCB *pstDCB : 設定用DCB構造体へのポインタ				       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(short nPort, DCB *pstDCB)
{
	if (nPort < 1 || nPort > 9)
		throw CommCtrlException("サポートされていないポートIDが指定されました",
			COMMERR_INVALIDID);
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは閉じていません", COMMERR_NOTCLOSE);
	char szPortName[5] = "COM";
	szPortName[3] = (char)(nPort + 0x30);
	szPortName[4] = '\0';
	Handle =  CreateFile(szPortName,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	SetCommState(Handle, pstDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// 通信ポートのオープン							       //
// LPCSTR pPort : オープンするポート名					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(LPCSTR pPort)
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは閉じていません", COMMERR_NOTCLOSE);
	Handle =  CreateFile(pPort,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// 通信ポートのオープン							       //
// LPCSTR pPort : オープンするポート名					       //
// LPSTR pDefString : ポート設定文字列					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(LPCSTR pPort, LPCSTR pDefString)
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは閉じていません", COMMERR_NOTCLOSE);
	Handle =  CreateFile(pPort,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	BuildCommDCB(pDefString, &stDCB);
	SetCommState(Handle, &stDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// 通信ポートのオープン							       //
// LPCSTR pPort : オープンするポート名					       //
// DCB *pstDCB : 設定用DCB構造体へのポインタ				       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(LPCSTR pPort, DCB *pstDCB)
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは閉じていません", COMMERR_NOTCLOSE);
	Handle =  CreateFile(pPort,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	SetCommState(Handle, pstDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Close								       //
// 通信ポートのクローズ							       //
/////////////////////////////////////////////////////////////////////////////////
void CComm::Close()
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	CloseHandle(Handle);
	Handle = INVALID_HANDLE_VALUE;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SetupComm							       //
// 通信ポートの設定							       //
// DCB *pstDCB : 設定用DCB構造体へのポインタ				       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SetupComm(DCB *pstDCB)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	stDCB = *pstDCB;
	return (bool)SetCommState(Handle, &stDCB);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SetupComm							       //
// 通信ポートの設定							       //
// LPSTR pDefString : ポート設定文字列					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SetupComm(LPCSTR pDefString)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	BuildCommDCB(pDefString, &stDCB);
	return (bool)SetCommState(Handle, &stDCB);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::GetState							       //
// 通信ポート設定の取得							       //
// DCB *pstDCB : DCB構造体へのポインタ					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::GetState(DCB *pstDCB)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	return (bool)GetCommState(Handle, pstDCB);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitChar							       //
// 指定文字の受信							       //
// char cChar : 受信文字						       //
// DWORD dwTimeoutMSecond : 受信タイムアウト値				       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::WaitChar(char cChar, DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	char szBuffer[2];
	bool IsSuccess;
	DWORD dwNum;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		szBuffer[0] = '\0';
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			return false;
		if (bTerminated)
			return false;
		IsSuccess = (bool)ReadFile(Handle, szBuffer, 1, &dwNum, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		if (dwNum != 1)
			continue;
		if (szBuffer[0] == cChar)
			return true;
	}
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitRead							       //
// タイムアウト付き受信							       //
// LPSTR pDest : 受信データ						       //
// DWORD dwLength : 受信長						       //
// DWORD dwTimeoutMSecond : 受信タイムアウト値				       //
// DWORD : 読み込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitRead(LPSTR pDest, DWORD dwLength, DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwLen = 0;
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)ReadFile(Handle, pDest + dwLen, dwLength - dwLen, &dwReadBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwLen += dwReadBytes;
		if (dwLen >= dwLength)
			return dwLen;
	}
	return dwLen;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitRead							       //
// タイムアウト付き受信							       //
// LPBYTE pDest : 受信データ						       //
// DWORD dwLength : 受信長						       //
// DWORD dwTimeoutMSecond : 受信タイムアウト値				       //
// DWORD : 読み込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitRead(LPBYTE pDest, DWORD dwLength, DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwLen = 0;
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)ReadFile(Handle, pDest + dwLen, dwLength - dwLen, &dwReadBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwLen += dwReadBytes;
		if (dwLen >= dwLength)
			return dwLen;
	}
	return dwLen;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Read								       //
// 受信									       //
// LPSTR pDest : 受信データ						       //
// DWORD dwLength : 受信長						       //
// DWORD : 読み込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Read(LPSTR pDest, DWORD dwLength)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pDest, dwLength, &dwReadBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwReadBytes;
	}
	return dwReadBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Read								       //
// 受信									       //
// LPSTR pDest : 受信データ						       //
// DWORD dwLength : 受信長						       //
// DWORD : 読み込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Read(LPBYTE pDest, DWORD dwLength)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pDest, dwLength, &dwReadBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwReadBytes;
	}
	return dwReadBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitWrite							       //
// タイムアウト付き送信							       //
// LPSTR pDest : 送信データ						       //
// DWORD dwTimeoutMSecond : 送信タイムアウト値				       //
// DWORD : 書き込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitWrite(LPCSTR pSrc, DWORD dwTimeoutMSecond)
{
	COMSTAT stComst;
	DWORD dwLength = lstrlen(pSrc);
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwSize = 0;
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)WriteFile(Handle, pSrc + dwSize, dwLength - dwSize, &dwWriteBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwSize += dwWriteBytes;
		if (dwSize >= dwLength)
			return dwSize;
		ClearError(&stComst);
		while (stComst.cbOutQue != 0)
			FlushSendBuffers();
	}
	return dwSize;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitWrite							       //
// タイムアウト付き送信							       //
// LPBYTE pDest : 送信データ						       //
// DWORD dwLength : 送信長						       //
// DWORD dwTimeoutMSecond : 送信タイムアウト値				       //
// DWORD : 書き込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitWrite(LPBYTE pSrc, DWORD dwLength, DWORD dwTimeoutMSecond)
{
	COMSTAT stComst;
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwSize = 0;
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)WriteFile(Handle, pSrc + dwSize, dwLength - dwSize, &dwWriteBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwSize += dwWriteBytes;
		if (dwSize >= dwLength)
			return dwSize;
		ClearError(&stComst);
		while (stComst.cbOutQue != 0)
			FlushSendBuffers();
	}
	return dwSize;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Write								       //
// 送信									       //
// LPSTR pDest : 送信データ						       //
// DWORD : 書き込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Write(LPCSTR pSrc)
{
	DWORD dwLength = lstrlen(pSrc);
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pSrc, dwLength, &dwWriteBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwWriteBytes;
	}
	return dwWriteBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Write								       //
// 送信									       //
// LPSTR pDest : 送信データ						       //
// DWORD dwLength : 送信長						       //
// DWORD : 書き込んだ長さ						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Write(LPBYTE pSrc, DWORD dwLength)
{
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pSrc, dwLength, &dwWriteBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwWriteBytes;
	}
	return dwWriteBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SetTimeout							       //
// ローレベルタイムアウトの設定						       //
// COMMTIMEOUTS *pstTimeouts : COMMTIMEOUTS構造体へのポインタ		       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SetTimeout(COMMTIMEOUTS *pstTimeouts)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	if (pstTimeouts == NULL)
	{
		COMMTIMEOUTS stTimeouts;
		stTimeouts.ReadIntervalTimeout = MAXDWORD;
		stTimeouts.ReadTotalTimeoutMultiplier = 0;
		stTimeouts.ReadTotalTimeoutConstant = 0;
		stTimeouts.WriteTotalTimeoutMultiplier = 0;
		stTimeouts.WriteTotalTimeoutConstant = 0;
		return (bool)SetCommTimeouts(Handle, &stTimeouts);
	}
	return (bool)SetCommTimeouts(Handle, pstTimeouts);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::FlushSendBuffers						       //
// 送信バッファのフラッシュ						       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::FlushSendBuffers()
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	return (bool)FlushFileBuffers(Handle);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Purge								       //
// バッファのクリア							       //
// DWORD dwAction : クリアの内容					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Purge(DWORD dwAction)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	return (bool)PurgeComm(Handle, dwAction);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ClearError							       //
// 通信エラーの取得、クリア						       //
// COMSTAT *pstComst : 通信状態を取得するCOMSTAT構造体へのポインタ	       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::ClearError(COMSTAT *pstComst)
{
	DWORD dwErrors = 0;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	ClearCommError(Handle, &dwErrors, pstComst);
	if (dwErrors & CE_BREAK)
		throw CommCtrlException("ハードウェアがブレーク条件を検出しました", COMMERR_BREAK);
	if (dwErrors & CE_FRAME)
		throw CommCtrlException("ハードウェアがフレーミングエラーを検出しました", COMMERR_FRAME);
	if (dwErrors & CE_IOE)
		throw CommCtrlException("デバイスとの通信中にI/Oエラーが発生しました", COMMERR_IOE);
	if (dwErrors & CE_MODE)
		throw CommCtrlException("要求されたモードがサポートされていないか､ハンドルが無効です", COMMERR_MODE);
	if (dwErrors & CE_OOP)
		throw CommCtrlException("パラレルデバイスが用紙切れであることを警告しました", COMMERR_OOP);
	if (dwErrors & CE_OVERRUN)
		throw CommCtrlException("文字バッファがいっぱいです", COMMERR_OVERRUN);
	if (dwErrors & CE_RXOVER)
		throw CommCtrlException("入力バッファのオーバーフローが発生しました", COMMERR_RXOVER);
	if (dwErrors & CE_RXPARITY)
		throw CommCtrlException("ハードウェアがパリティーエラーを検出しました", COMMERR_RXPARITY);
	if (dwErrors & CE_TXFULL)
		throw CommCtrlException("出力バッファがいっぱいです", COMMERR_TXFULL);
	if (dwErrors & CE_DNS)
		throw CommCtrlException("パラレルデバイスが選択されていません", COMMERR_DNS);
	if (dwErrors & CE_PTO)
		throw CommCtrlException("パラレルデバイス上でタイムアウトになりました", COMMERR_PTO);
	return dwErrors;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ReceiveChar							       //
// １バイト受信								       //
// DWORD dwTimeoutMSecond : 受信タイムアウト値				       //
// short : 成功 受信文字, 失敗 -1					       //
/////////////////////////////////////////////////////////////////////////////////
short CComm::ReceiveChar(DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	char szBuffer[2];
	bool IsSuccess;
	DWORD dwNum;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			return -1;
		if (bTerminated)
			return -1;
		IsSuccess = (bool)ReadFile(Handle, szBuffer, 1, &dwNum, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		if (dwNum != 1)
			continue;
		return (short)szBuffer[0];
	}
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SendChar							       //
// 指定文字の送信							       //
// char ch : 送信文字							       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SendChar(char ch)
{
	char szTemp[1];
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	szTemp[0] = ch;
	IsSuccess = (bool)WriteFile(Handle, szTemp, 1, &dwWriteBytes, NULL);
	if (!IsSuccess || dwWriteBytes != 1)
	{
		ClearError();
		return false;
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ReadWord							       //
// WORD入力								       //
// WORD *pwDest : WORD受信データ					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::ReadWord(WORD *pwDest)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pwDest, 2, &dwReadBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwReadBytes == 2)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WriteWord							       //
// WORD出力								       //
// WORD *pwDest : WORD送信データ					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::WriteWord(WORD *pwSrc)
{
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pwSrc, 2, &dwWriteBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwWriteBytes == 2)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ReadDWord							       //
// DWORD入力								       //
// DWORD *pdwDest : DWORD受信データ					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::ReadDWord(DWORD *pdwDest)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pdwDest, 4, &dwReadBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwReadBytes == 4)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WriteDWord							       //
// DWORD出力								       //
// DWORD *pdwDest : DWORD送信データ					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::WriteDWord(DWORD *pdwSrc)
{
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pdwSrc, 4, &dwWriteBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwWriteBytes == 4)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::EscapeFunction						       //
// 拡張機能の実行							       //
// DWORD dwFunc : 拡張機能コード					       //
// bool : 成功 true, 失敗 false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::EscapeFunction(DWORD dwFunc)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("ポートは開いていません", COMMERR_NOTOPEN);
	return (bool)EscapeCommFunction(Handle, dwFunc);
}
