/**
  * HF04Issuer.cpp: RFID HF04 Issue Class
  *
  *     @author a_oshima
  */

#include <vcl.h>
#pragma hdrstop

#include "HF04Issuer.h"
#include "ocomm.h"

HF04Issuer::HF04Issuer(int port)
    : port_(port){

    ZeroMemory(&o_write_, sizeof(OVERLAPPED));
    ZeroMemory(&o_event_, sizeof(OVERLAPPED));
    ZeroMemory(&o_read_, sizeof(OVERLAPPED));
    o_write_.hEvent = CreateEvent(0, true, false, 0);
    o_event_.hEvent = CreateEvent(0, true, false, 0);
    o_read_.hEvent  = CreateEvent(0, true, false, 0);
}

HF04Issuer::~HF04Issuer(){
    CloseHandle(o_write_.hEvent);
    CloseHandle(o_event_.hEvent);
    CloseHandle(o_read_.hEvent);
}

void HF04Issuer::IssueCard(int card_no){
    const char DELIMITER = '\r';
    const int DELAY = 200;
    const DWORD TIMEOUT = 3000;
    char DEF[] = "38400,N,8,1";

    ackl::OverlappedComm comm;

    if (!comm.open(port_))
        throw ERFIDError("RFIDユニットに接続できません（内部COMオープンエラー）");

    try{
        DCB dcb;
        COMMTIMEOUTS timeouts;

        if (!comm.getState(&dcb))
            throw std::runtime_error("getState");

        if (!comm.buildDCB(DEF, &dcb))
            throw std::runtime_error("buildDCB");

        dcb.fOutxCtsFlow = false;
        dcb.fOutxDsrFlow = false;
        dcb.fRtsControl = RTS_CONTROL_DISABLE;
        dcb.fDtrControl = DTR_CONTROL_DISABLE;
        dcb.EvtChar = DELIMITER;

        if (!comm.setState(&dcb))
            throw std::runtime_error("setState");

        timeouts.ReadIntervalTimeout = MAXDWORD;
        timeouts.ReadTotalTimeoutMultiplier = 0;
        timeouts.ReadTotalTimeoutConstant = 0;
        timeouts.WriteTotalTimeoutMultiplier = 0;
        timeouts.WriteTotalTimeoutConstant = 0;
        if (!comm.setTimeouts(&timeouts))
            throw std::runtime_error("setTimeouts");

        if (!comm.setMask(EV_RXFLAG))
            throw std::runtime_error("setMask");
    }catch(std::runtime_error& e){
        throw ERFIDError("RFIDユニット通信エラー（内部COM設定エラー）");
    }

    COMSTAT stat;
    DWORD size, transfer, error;
    DWORD event, sended_count;
    std::string buff, err_buff;
    std::auto_ptr<TStringList> ResList(new TStringList());
    bool card_presented;

    comm.cancelIo();
    comm.write("2XX\r", &size, &o_write_);
    comm.getOverlappedResult(&o_write_, &transfer, true);
    comm.waitEvent(&event, &o_event_);
    if ((error = GetLastError()) != ERROR_IO_PENDING){
        std::string msg;
        FormatMessage(msg);
        throw ERFIDError("RFIDユニット通信エラー（レスポンスイベントエラー）");
    }

    sended_count = GetTickCount();
    card_presented = false;
    while (GetTickCount() - sended_count <= TIMEOUT){
        if (!comm.getOverlappedResult(&o_event_, &transfer, false)){
            Sleep(DELAY);
            continue;
        }

        comm.clearError(&error, &stat);
        comm.read(buff, stat.cbInQue, &size, &o_read_);
        comm.getOverlappedResult(&o_read_, &transfer, true);

        buff.erase(buff.length() - 1);  // [CR] の削除

        ResList->Clear();
        ResList->CommaText = buff.c_str();
        if (ResList->Strings[0].ToIntDef(0) > 0)
            card_presented = true;
        break;
    }
    if (!card_presented)
        throw ERFIDError("RFIDカードがありません");

    char cmd[200];

    wsprintf(cmd, "NKSWSCAMRFID%08d", card_no);
    AnsiString bytes = BytesToHexString(cmd, lstrlen(cmd), 0x00);
    wsprintf(cmd, "2WM,01,00,05,%s\r", bytes.c_str());

    comm.cancelIo();

    comm.write(cmd, &size, &o_write_);
    comm.getOverlappedResult(&o_write_, &transfer, true);
    comm.waitEvent(&event, &o_event_);
    if ((error = GetLastError()) != ERROR_IO_PENDING){
        std::string msg;
        FormatMessage(msg);
        throw ERFIDError("RFIDユニット通信エラー（書込レスポンスイベントエラー）");
    }

    sended_count = GetTickCount();
    ResList->Clear();
    while (GetTickCount() - sended_count <= TIMEOUT){
        if (!comm.getOverlappedResult(&o_event_, &transfer, false)){
            Sleep(DELAY);
            continue;
        }

        comm.clearError(&error, &stat);
        comm.read(buff, stat.cbInQue, &size, &o_read_);
        comm.getOverlappedResult(&o_read_, &transfer, true);

        buff.erase(buff.length() - 1);  // [CR] の削除

        ResList->CommaText = buff.c_str();

        break;
    }


    if (ResList->Count == 0)
        throw ERFIDError("RFIDユニットからの返答がありません");
    if (ResList->Strings[0][1] == 'E')
        throw ERFIDError("書き込み中にエラーが発生しました");
    if (ResList->Count != 2)
        throw ERFIDError("RFIDユニットからのレスポンスが異常です");
    if (ResList->Strings[1] == "NG"){
        throw ERFIDError("書き込みに失敗しました");
    }
}

bool HF04Issuer::FormatMessage(std::string& msg){
    LPVOID buff;
    DWORD result = ::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
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

AnsiString HF04Issuer::BytesToHexString(LPBYTE bytes, int size, char sep){
    AnsiString buff;
    char hex[3];
    for (int i = 0; i < size; i++){
        wsprintf(hex, "%02X", (BYTE)bytes[i]);
        buff = buff + hex;
        if (sep)
            buff = buff + AnsiString(sep);
    }
    return buff;
}

