//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SKLD2000Thread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// 注意：異なるスレッドが所有する VCL のメソッド/関数/プロパティを
//   別のスレッドの中から扱う場合，排他処理の問題が発生します。
//
//   メインスレッドの所有するオブジェクトに対しては Synchronize
//   メソッドを使う事ができます。他のオブジェクトを参照するため
//   のメソッドをスレッドクラスに追加し，Synchronize メソッドの
//   引数として渡します。
//
//   たとえば UpdateCaption を以下のように定義し、
//
//  void __fastcall TSKLD2000Thread::UpdateCaption()
//  {
//    Form1->Caption = "スレッドから書き換えました";
//  }
//
//   Execute メソッドの中で Synchronize メソッドに渡すことでメイ
//   ンスレッドが所有する Form1 の Caption プロパティを安全に変
//   更できます。
//
//  Synchronize(UpdateCaption);
//
//---------------------------------------------------------------------------
__fastcall TSKLD2000Thread::TSKLD2000Thread(bool CreateSuspended, const WICommInfo& info)
    : TThread(CreateSuspended), info_(info)
{
}
//---------------------------------------------------------------------------
bool __fastcall TSKLD2000Thread::formatMessage(std::string& msg)
{
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
//---------------------------------------------------------------------------
void __fastcall TSKLD2000Thread::Execute()
{
    ackl::OverlappedComm comm_;

    const char DELIMITER = ETX;
    const int DELAY = 200;
	const int DATA_LEN = 18;

    // シリアルポートのオープン
    if (!comm_.open(info_.port)){
        status_.is_fatal = true;
        status_.message = "COMポートがオープンできません";
        SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        SendMessage(info_.owner, WIM_ABORTED, ThreadID, 0);
        return;
    }

    // シリアルポートの初期化
    try{
        DCB dcb;
        COMMTIMEOUTS timeouts;

        if (!comm_.getState(&dcb))
            throw std::runtime_error("getState");

		if (!comm_.buildDCB(info_.def.c_str(), &dcb))
			throw std::runtime_error("buildDCB");

        dcb.EvtChar = DELIMITER;
        if (!comm_.setState(&dcb))
            throw std::runtime_error("setState");

        timeouts.ReadIntervalTimeout = MAXDWORD;
        timeouts.ReadTotalTimeoutMultiplier = 0;
        timeouts.ReadTotalTimeoutConstant = 0;
        timeouts.WriteTotalTimeoutMultiplier = 0;
        timeouts.WriteTotalTimeoutConstant = 0;
        if (!comm_.setTimeouts(&timeouts))
            throw std::runtime_error("setTimeouts");

        if (!comm_.setMask(EV_RXFLAG))
            throw std::runtime_error("setMask");
    }catch(std::runtime_error& e){
        status_.is_fatal = true;
        status_.message = "COMポートの初期化に失敗しました";
        SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        SendMessage(info_.owner, WIM_ABORTED, ThreadID, 0);
        return;
    }

    OVERLAPPED o_event;
    OVERLAPPED o_read;
    COMSTAT stat;
    DWORD event;
    DWORD transfer;
    DWORD error;
    DWORD size;
    std::string buff;
	std::string err_buff;
	std::string weight_buff;
	unsigned int buff_size;

	ZeroMemory(&o_event, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_event.hEvent = CreateEvent(NULL, true, false, NULL);
    o_read.hEvent = CreateEvent(NULL, true, false, NULL);
    
	while (!Terminated){
        Sleep(DELAY);

        comm_.clearError(&error, &stat);
        err_buff.clear();
        if (comm_.formatMessage(error, err_buff)){
            status_.is_fatal = false;
            status_.message = err_buff.c_str();
            // SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }
        if (stat.cbInQue < DATA_LEN){
            continue;
        }

        //if (event == EV_RXFLAG){
        {
            comm_.read(buff, stat.cbInQue, &size, &o_read);
            // 受信待ち
            comm_.getOverlappedResult(&o_read, &transfer, true);

			int idx = buff.rfind(DELIMITER);
            if (idx == std::string::npos){
                continue;
            }

			if (idx < 17)
				continue;

			buff = buff.substr(idx - (DATA_LEN - 1), DATA_LEN);

			if (buff[1] == 'U')
				weight_.status = WIWeight::wiUnstable;
			else
				weight_.status = WIWeight::wiStable;

			weight_buff = buff.substr(6, 9);

			try{
                weight_.weight = Currency(weight_buff.c_str());
            }catch(...){
                continue;
            }

            SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);
        }
    }

    CloseHandle(o_event.hEvent);
    CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
