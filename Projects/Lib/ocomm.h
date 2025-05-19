/**
 * ocomm.h: Overlappedシリアル操作ラッパークラスヘッダー
 *
 *	@author		ack(akio)
 *	@history	2003/03/07 作成
 *			2003/03/13 stringを使用しないread/write追加
 *				   readの戻値の型をDWORDからboolに修正
 *
 *	@description
 *	単なるラッパーなので、実際の挙動についてはWin32APIのドキュメントを参照。
 *	[eod]
 */

#ifndef _ocomm_h_
#define _ocomm_h_

#include <windows.h>
#include <memory>
#include <exception>
#include "utility.h"

#pragma warning(disable:4800)

// ackl: original namespace
namespace ackl{

#define SOH			(0x01)
#define STX			(0x02)
#define ETX			(0x03)
#define EOT			(0x04)
#define ENQ			(0x05)
#define ACK			(0x06)
#define BEL			(0x07)
#define BS			(0x08)
#define HT			(0x09)
#define LF			(0x0a)
#define VT			(0x0b)
#define FF			(0x0c)
#define CR			(0x0d)
#define SO			(0x0e)
#define SI			(0x0f)
#define NAK			(0x15)

class OverlappedComm{
public:
	OverlappedComm() : comm_(INVALID_HANDLE_VALUE) {}
	virtual ~OverlappedComm()
		{if (isOpened()) close();}

	bool open(int port){
		if (isOpened())
			return false;

        std::string target;
        if (port < 10){
    		target = "COM";
	    	target += ackl::toString<int>(port);
        }else{
    		target = "\\\\.\\COM";
	    	target += ackl::toString<int>(port);
        }

		comm_ = CreateFile(target.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			0, 0, OPEN_EXISTING,
			FILE_FLAG_OVERLAPPED, 0);

		return isOpened();
	}

	void close(){
		CloseHandle(comm_);
		comm_ = INVALID_HANDLE_VALUE;
	}

	bool buildDCB(const std::string& def, DCB *dcb) const
		{return BuildCommDCB(def.c_str(), dcb);}

	bool setState(DCB *dcb)
		{return SetCommState(comm_, dcb);}
	bool getState(DCB *dcb) const
		{return GetCommState(comm_, dcb);}

	bool setTimeouts(COMMTIMEOUTS *timeouts)
		{return SetCommTimeouts(comm_, timeouts);}
	bool getTimeouts(COMMTIMEOUTS *timeouts) const
		{return GetCommTimeouts(comm_, timeouts);}
	bool setMask(DWORD evt)
		{return SetCommMask(comm_, evt);}
	bool getMask(DWORD *evt) const
		{return GetCommMask(comm_, evt);}
	bool clearError(DWORD *error, COMSTAT *stat)
		{return ClearCommError(comm_, error, stat);}
	bool formatMessage(DWORD errors, std::string& msg){
//		msg.clear();

		if ((errors & CE_MODE) == CE_MODE)
			msg = "要求されたモードがサポートされていないか､ハンドルが無効です";
		if ((errors & CE_BREAK) == CE_BREAK)
			msg += "ハードウェアがブレーク条件を検出しました";
		if ((errors & CE_FRAME) == CE_FRAME)
			msg += "ハードウェアがフレーミングエラーを検出しました";
		if ((errors & CE_IOE) == CE_IOE)
			msg += "デバイスとの通信中にI/Oエラーが発生しました";
		if ((errors & CE_OOP) == CE_OOP)
			msg += "パラレルデバイスが用紙切れであることを警告しました";
		if ((errors & CE_OVERRUN) == CE_OVERRUN)
			msg += "文字バッファがいっぱいです";
		if ((errors & CE_RXOVER) == CE_RXOVER)
			msg += "入力バッファのオーバーフローが発生しました";
		if ((errors & CE_RXPARITY) == CE_RXPARITY)
			msg += "ハードウェアがパリティーエラーを検出しました";
		if ((errors & CE_TXFULL) == CE_TXFULL)
			msg += "出力バッファがいっぱいです";
		if ((errors & CE_DNS) == CE_DNS)
			msg += "パラレルデバイスが選択されていません";
		if ((errors & CE_PTO) == CE_PTO)
			msg += "パラレルデバイス上でタイムアウトになりました";

		return (!msg.empty());
	}
	bool formatLastErrorMessage(std::string& msg){
		LPVOID buff;
		DWORD result = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
				NULL,
				GetLastError(),
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				(LPTSTR)&buff,
				0, NULL);
		if (result){
			msg = (char *)buff;
			LocalFree(buff);
			return true;
		}
		return false;
	}
	bool escapeFunction(DWORD func)
		{return EscapeCommFunction(comm_, func);}
	bool purge(DWORD flags = PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR)
		{return PurgeComm(comm_, flags);}

	bool waitEvent(DWORD *event, OVERLAPPED *overlap)
		{return WaitCommEvent(comm_, event, overlap);}

	bool read(std::string& buff, DWORD len, DWORD *size, OVERLAPPED *overlap){
		bool result;
		char *l_buff = new char[len + 1];
		result = ReadFile(comm_, l_buff, len, size, overlap);
		*(l_buff + *size) = '\0';
		buff = l_buff;
		delete[] l_buff;
		return result;
	}
	bool read(LPSTR buff, DWORD len, DWORD *size, OVERLAPPED *overlap){
		return	ReadFile(comm_, buff, len, size, overlap);
	}
	bool write(const std::string& buff, DWORD *size, OVERLAPPED *overlap){
		return WriteFile(comm_, buff.c_str(), buff.size(), size, overlap);
	}
	bool write(LPCSTR buff, DWORD len, DWORD *size, OVERLAPPED *overlap){
		return WriteFile(comm_, buff, len, size, overlap);
	}
	bool cancelIo()
		{return CancelIo(comm_);}

	bool getOverlappedResult(OVERLAPPED *overlap, DWORD *transfer, bool wait)
		{return GetOverlappedResult(comm_, overlap, transfer, wait);}

	bool isOpened() const {return comm_ != INVALID_HANDLE_VALUE;}
private:
	HANDLE comm_;
};

};

#pragma warning(default:4800)

#endif	//_ocomm_h_
