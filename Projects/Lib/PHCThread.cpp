//---------------------------------------------------------------------------
/**
 *	PATLITE PHC用thread
 */
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ocomm.h"

#include "PHCThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// 注意：異なるスレッドが所有する VCL のメソッド/関数/プロパティを
//		 別のスレッドの中から扱う場合，排他処理の問題が発生します。
//
//		 メインスレッドの所有するオブジェクトに対しては Synchronize
//		 メソッドを使う事ができます。他のオブジェクトを参照するため
//		 のメソッドをスレッドクラスに追加し，Synchronize メソッドの
//		 引数として渡します。
//
//		 たとえば UpdateCaption を以下のように定義し、
//
//		void __fastcall TPHCThread::UpdateCaption()
//		{
//		  Form1->Caption = "スレッドから書き換えました";
//		}
//
//		 Execute メソッドの中で Synchronize メソッドに渡すことでメイ
//		 ンスレッドが所有する Form1 の Caption プロパティを安全に変
//		 更できます。
//
//		Synchronize(UpdateCaption);
//
//---------------------------------------------------------------------------
PHC_OCTET& operator<<(PHC_OCTET& octet, int bit)
{
	switch (bit){
	case 0:	octet.b.b0 = 1;	break;
	case 1:	octet.b.b1 = 1;	break;
	case 2:	octet.b.b2 = 1;	break;
	case 3:	octet.b.b3 = 1;	break;
	case 4:	octet.b.b4 = 1;	break;
	case 5:	octet.b.b5 = 1;	break;
	case 6:	octet.b.b6 = 1;	break;
	case 7:	octet.b.b7 = 1;	break;
	}
	return octet;
}
//---------------------------------------------------------------------------
__fastcall TPHCThread::TPHCThread(bool CreateSuspended, const PHCCommInfo& info)
	: TThread(CreateSuspended), info_(info)
{
}
//---------------------------------------------------------------------------
std::string TPHCThread::generateCommand(bool done, char ch)
{
	PHC_OCTET octet;
	PHC_OCTET data1;
	PHC_OCTET data2;

	octet.ch = ch;
	data1.ch = '0';	// 00110000 (default)
	data2.ch = '0';	// 00110000 (default)

	char buff[50];

	data2.b.b0 = octet.b.b0;
	data2.b.b1 = octet.b.b1;
	data2.b.b2 = octet.b.b2;
	data2.b.b3 = octet.b.b3;
	data1.b.b0 = octet.b.b4;
	data1.b.b1 = octet.b.b5;
	data1.b.b2 = octet.b.b6;
	data1.b.b3 = octet.b.b7;

	wsprintf(buff, "@??%c**!", done ? '1' : '0');
	buff[4] = data1.ch;
	buff[5] = data2.ch;

	return std::string(buff);
}
//---------------------------------------------------------------------------
void __fastcall TPHCThread::Execute()
{
	ackl::OverlappedComm comm;

	const int DELAY = 200;

	// シリアルポートのオープン
	if (!comm.open(info_.port)){
		SendMessage(info_.owner, PHCM_STATUS, ThreadID, (LPARAM)"COMポートがオープンできません");
		PostMessage(info_.owner, PHCM_ABORTED, ThreadID, 0);
		return;
	}

	// シリアルポートの初期化
	try{
		DCB dcb;
		COMMTIMEOUTS timeouts;

		if (!comm.getState(&dcb))
			throw std::runtime_error("getState");

		if (!comm.buildDCB(info_.def.c_str(), &dcb))
			throw std::runtime_error("buildDCB");

		if (!comm.setState(&dcb))
			throw std::runtime_error("setState");

		timeouts.ReadIntervalTimeout = MAXDWORD;
		timeouts.ReadTotalTimeoutMultiplier = 0;
		timeouts.ReadTotalTimeoutConstant = 0;
		timeouts.WriteTotalTimeoutMultiplier = 0;
		timeouts.WriteTotalTimeoutConstant = 0;
		if (!comm.setTimeouts(&timeouts))
			throw std::runtime_error("setTimeouts");
	}catch(std::runtime_error& e){
		SendMessage(info_.owner, PHCM_STATUS, ThreadID, (LPARAM)"COMポートの初期化に失敗しました");
		PostMessage(info_.owner, PHCM_ABORTED, ThreadID, 0);
		return;
	}

	OVERLAPPED o_write;
	OVERLAPPED o_read;
	COMSTAT stat;
	DWORD event;
	DWORD transfer;
	DWORD error;
	DWORD size;
	std::string buff;
	std::string err_buff;
	MSG msg;
	char ch;

	ZeroMemory(&o_write, sizeof(OVERLAPPED));
	ZeroMemory(&o_read, sizeof(OVERLAPPED));
	o_write.hEvent = CreateEvent(NULL, true, false, NULL);
	o_read.hEvent = CreateEvent(NULL, true, false, NULL);

	bool done;

	while (!Terminated){
		Sleep(DELAY);

		if (!PeekMessage(&msg, 0, PHCM_COMMAND, PHCM_COMMAND, PM_REMOVE))
			continue;

		done = static_cast<bool>(msg.wParam);
		ch = static_cast<char>(msg.lParam);

		buff = generateCommand(done, ch);

		comm.write(buff, &size, &o_write);
		comm.getOverlappedResult(&o_write, &transfer, true);

		Sleep(300);

		comm.clearError(&error, &stat);
		err_buff.clear();
		if (comm.formatMessage(error, err_buff))
			SendMessage(info_.owner, PHCM_STATUS, ThreadID, (LPARAM)err_buff.c_str());

		if (stat.cbInQue == 0)
			continue;

		comm.read(buff, stat.cbInQue, &size, &o_read);
		comm.getOverlappedResult(&o_read, &transfer, true);

		if (buff[0] != ACK){
			SendMessage(info_.owner, PHCM_STATUS, ThreadID, (LPARAM)"リレーユニットからの返答が無効です");
		}

	}

	CloseHandle(o_write.hEvent);
	CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
