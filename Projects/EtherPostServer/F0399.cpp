// F0399.cpp: エフテック社製 7セグ表示器 F0399 制御クラス実装

#include "F0399.h"

F0399::~F0399(){
	Close();
}

bool F0399::Initialize(int port, LPCSTR def){

	// シリアルポートのオープン
	if (!comm_.open(port))
		return false;

	// シリアルポートの初期化
	DCB dcb;
	COMMTIMEOUTS timeouts;

	if (!comm_.getState(&dcb))
    	return false;

	if (!comm_.buildDCB(def, &dcb))
    	return false;

	if (!comm_.setState(&dcb))
    	return false;

	timeouts.ReadIntervalTimeout = MAXDWORD;
	timeouts.ReadTotalTimeoutMultiplier = 0;
	timeouts.ReadTotalTimeoutConstant = 0;
	timeouts.WriteTotalTimeoutMultiplier = 0;
	timeouts.WriteTotalTimeoutConstant = 0;
	if (!comm_.setTimeouts(&timeouts))
    	return false;

	ZeroMemory(&o_write_, sizeof(OVERLAPPED));
	o_write_.hEvent = CreateEvent(NULL, true, false, NULL);

	return true;
}

void F0399::Close(){
	if (comm_.isOpened()){
    	comm_.close();

        if (o_write_.hEvent)
			CloseHandle(o_write_.hEvent);
    }
}

bool F0399::IsActive(){
	return comm_.isOpened();
}

void F0399::Display(LPCSTR text){
	char buff[6];
    lstrcpyn(buff, text, 6);

	char send_buff[8];
    wsprintf(send_buff, " %5s\r", buff);

    DWORD size = 0;
    DWORD transfer = 0;

	comm_.write(send_buff, &size, &o_write_);
    comm_.getOverlappedResult(&o_write_, &transfer, true);
}


