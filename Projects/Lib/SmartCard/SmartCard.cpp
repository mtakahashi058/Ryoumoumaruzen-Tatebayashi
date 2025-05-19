/**
  * SmartCard.h: SmartCard Control Class (for ACR122)
  *
  *     @author a_oshima
  */

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include "SmartCard.h"

SmartCardService::SmartCardService()
    : context_(0), last_result_(0) {
}

SmartCardService::~SmartCardService(){
    if (context_)
        SCardReleaseContext(context_);
}

bool SmartCardService::Establish(){
    last_result_ = SCardEstablishContext(SCARD_SCOPE_USER, 0, 0, &context_);
    if (last_result_ != SCARD_S_SUCCESS)
        return false;
    return true;
}

bool SmartCardService::EnumReaders(SmartCardService::Readers& readers){
    if (!context_)
        throw Exception("invalid context");

    readers.clear();
    
    LPSTR names = 0;
    DWORD names_size = SCARD_AUTOALLOCATE;

    last_result_ = SCardListReaders(context_, SCARD_ALL_READERS, (LPSTR)&names, &names_size);
    if (last_result_ != SCARD_S_SUCCESS)
        return false;

    LPSTR name = names;
    int count = 0;
    while (*name != '\0'){
        readers[count] = AnsiString(name);

        name = name + lstrlen(name) + 1;
        count++;
    }
    SCardFreeMemory(context_, names);
    return true;
}

void SmartCardService::SetReader(AnsiString reader){
    reader_ = reader;
}

bool SmartCardService::GetStatusChange(DWORD& event, DWORD cur_state, DWORD timeout){

    SCARD_READERSTATE state;
    ZeroMemory(&state, sizeof(SCARD_READERSTATE));

    state.szReader       = reader_.c_str();
    state.dwCurrentState = cur_state;

    last_result_ = SCardGetStatusChange(context_, timeout, &state, 1);
    if (last_result_ != SCARD_S_SUCCESS)
        return false;

    event = state.dwEventState;
    return true;
}

bool SmartCardService::ConnectCard(SmartCard *smart_card){
    SCARDHANDLE handle;
    DWORD protocol;
    last_result_ = SCardConnect(context_, reader_.c_str(), SCARD_SHARE_SHARED,
                            SCARD_PROTOCOL_T1, &handle, &protocol);
    if (last_result_ != SCARD_S_SUCCESS)
        return false;
        
    smart_card->Assign(handle);
    return true;
}

DWORD SmartCardService::GetLastError(DWORD& err, AnsiString& text){
	try{
		err = last_result_;
	}catch (...){}
    text = GetErrorText(err);
    return err;
}

bool SmartCardService::CheckService(){
    DWORD  result;
    HANDLE sc_event;

    sc_event = SCardAccessStartedEvent();
    result   = WaitForSingleObject(sc_event, 0);
    SCardReleaseStartedEvent();
    if (result != WAIT_OBJECT_0)
        return false;
    return true;
}

SmartCard::SmartCard() : handle_(0) {
}

SmartCard::SmartCard(SCARDHANDLE handle)
    : last_result_(0), handle_(handle) {
}

SmartCard::~SmartCard(){
    Disconnect();
}

void SmartCard::Assign(SCARDHANDLE handle){
    Disconnect();
    handle_ = handle;
}

void SmartCard::Disconnect(){
    if (handle_){
        SCardDisconnect(handle_, SCARD_LEAVE_CARD);
        handle_ = 0;
    }
}

bool SmartCard::Transmit(LPBYTE cmd, DWORD size, SCBytes& res, DWORD& res_size){
    DWORD response_size = res.size();

    last_result_ = SCardTransmit(handle_, SCARD_PCI_T1, cmd, size, 0, res(), &response_size);
    if (last_result_ != SCARD_S_SUCCESS)
        return false;

    res_size = response_size;
    return true;
}

bool SmartCard::BeginTransaction(){
    last_result_ = SCardBeginTransaction(handle_);
    return (last_result_ == SCARD_S_SUCCESS);
}

bool SmartCard::EndTransaction(DWORD disposition){
    last_result_ = SCardEndTransaction(handle_, disposition);
    return (last_result_ == SCARD_S_SUCCESS);
}

bool SmartCard::LoadKey(BYTE& sw1, BYTE& sw2, LPBYTE key, BYTE number){
    LPBYTE cmd;
    int size;
    SCBytes res(256);
    DWORD res_size;

    // Load Authentication Keys APDU Format(11 Byte)
    GenerateCommand(0xFF, 0x82, 0x00, 0x00, 0x06, key, 6, &cmd, size);
    //GenerateCommand(0xFF, 0x88, 0x00, 0x01, 0x60, key, 6, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);
    if (succeeded)
        ParseResponse(res(), res_size, sw1, sw2);
    delete[] cmd;

    return succeeded;
}

bool SmartCard::Authenticate(BYTE& sw1, BYTE& sw2, BYTE block, AuthKeyType type, BYTE key_number){
    BYTE data[5];
    LPBYTE cmd;
    int size;
    SCBytes res(256);
    DWORD res_size;

    data[0] = 0x01;
    data[1] = 0x00;
    data[2] = block;
    data[3] = type == TypeA ? 0x60 : 0x61;
    data[4] = 0x00;
    GenerateCommand(0xff, 0x86, 0x00, 0x00, 5, data, 5, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);
    if (succeeded)
        ParseResponse(res(), res_size, sw1, sw2);
    delete[] cmd;

    return succeeded;
}

bool SmartCard::ReadBlock(BYTE& sw1, BYTE& sw2, BYTE block, LPBYTE data){
    LPBYTE cmd;
    int size;
    SCBytes res(256);
    DWORD res_size;

    GenerateCommand(0xff, 0xb0, 0x00, block, 0x10, 0, 0, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);
    if (succeeded){
        ParseResponse(res(), res_size, sw1, sw2);
        MoveMemory(data, res(), res_size - 2); 
    }
    delete[] cmd;

    return succeeded;
}

// Ultralight Reading
bool SmartCard::ReadPage(BYTE& sw1, BYTE& sw2, BYTE page, LPBYTE data){
    LPBYTE cmd;
    int size;
    SCBytes res(256);
    DWORD res_size;

    GenerateCommand(0xff, 0xb0, 0x00, page, 0x10, 0, 0, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);
    if (succeeded){
        ParseResponse(res(), res_size, sw1, sw2);
        MoveMemory(data, res(), res_size - 2);
    }
    delete[] cmd;

    return succeeded;
}

// ultralight
bool SmartCard::ReadUltraBlock(BYTE block, LPBYTE data){
    LPBYTE cmd;
    int size;
    SCBytes res(256);
    DWORD res_size;

    GenerateCommand(0xff, 0xb0, 0x00, block, 0x10, 0, 0, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);
    if (succeeded){
        //ParseResponse
        MoveMemory(data, res(), res_size - 2);
    }
    delete[] cmd;

    return succeeded;
}

// 1K Classicóp
bool SmartCard::WriteBlock(BYTE& sw1, BYTE& sw2, BYTE block, LPBYTE data){
    LPBYTE cmd;
    int size;
    SCBytes res(256);
    DWORD res_size;

    GenerateCommand(0xff, 0xd6, 0x00, block, 0x10, data, 0x10, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);
    if (succeeded)
        ParseResponse(res(), res_size, sw1, sw2);
    delete[] cmd;

    return succeeded;
}

// Ultralight
bool SmartCard::WritePage(BYTE& sw1, BYTE& sw2, BYTE page, LPBYTE data){
    LPBYTE cmd;
    int    size;
    SCBytes res(256);
    DWORD res_size;

    GenerateCommand(0xff, 0xd6, 0x00, page, 0x10, data, 0x10, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);

    if (succeeded) {
        ParseResponse(res(), res_size, sw1, sw2);
        MoveMemory(data, res(), res_size -2);
    }
    delete[] cmd;

    return succeeded;
}

// ultraèëçûÇ›
bool SmartCard::WriteUltraBlock(BYTE& sw1, BYTE& sw2, BYTE block, LPBYTE data) {
    LPBYTE cmd;
    int size;
    SCBytes res(256);
    DWORD res_size;

    GenerateCommand(0xff, 0xd6, 0x00, block, 0x10, data, 0x10, &cmd, size);

    bool succeeded = Transmit(cmd, size, res, res_size);

    if (succeeded) {
        ParseResponse(res(), res_size, sw1, sw2);
        MoveMemory(data, res(), res_size - 2);
    }
    delete[] cmd;

    return succeeded;
}

bool SmartCard::GetATR(LPBYTE buff){
    DWORD atr_size = 32;

    last_result_ = SCardStatus(handle_, 0, 0, 0, 0, buff, &atr_size);
    if (last_result_ != SCARD_S_SUCCESS)
        return false;
    return true;
}

DWORD SmartCard::GetLastError(DWORD& err, AnsiString& text){
    err = last_result_;
    text = GetErrorText(err);
    return err;
}

void SmartCard::GenerateCommand(BYTE CLA, BYTE INS, BYTE P1, BYTE P2, BYTE Lc, LPBYTE data, int data_len, LPBYTE *cmd, int& size){
    size = 5 + data_len;  // CLA + INS + P1 + P2 + Lc + data_len
    *cmd = new BYTE[size];
    (*cmd)[0] = CLA;
    (*cmd)[1] = INS;
    (*cmd)[2] = P1;
    (*cmd)[3] = P2;
    (*cmd)[4] = Lc;
    if (data_len)
        MoveMemory((*cmd) + 5, data, data_len);
}

int SmartCard::ParseResponse(LPBYTE res, int size, BYTE& sw1, BYTE& sw2){
    sw1 = res[size - 2];
    sw2 = res[size - 1];

    return sw1;
}

bool SmartCard::IsAvailableBlock(BYTE block){
    if (block <= 2)     // system block
        return false;

    int block_no;       // block number in the sector

    ///// first 2K area

    if (block < 0x7f){
        block_no = block % 4;
        if (block_no == 3)      // trailer block
            return false;
        return true;
    }

    ///// second 2K area

    block_no = block % 16;
    if (block_no == 15)         // trailer block;
        return false;
    return true;
}


// SmartCard Helper ------------------------------------------------------------
bool IsSucceeded(BYTE sw1){
    return (sw1 == 0x90);
}

AnsiString BytesToHexString(LPBYTE bytes, int size, char sep){
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

bool HexStringToBytes(LPCSTR src, LPBYTE bytes){
    LPCSTR p = src;
    BYTE byte;
    BYTE c;
    int count = 0;
    while (*p){
        c = std::tolower(*p);
        if (c == ' '){
            p++;
            continue;
        }

        if ((c < '0' || c > '9') && (c < 'a' || c > 'f'))
            return false;
        if (count % 2 == 0){
            byte = 0;
            switch (c){
            case '0':                   break;
            case '1':   byte += 0x10;   break;
            case '2':   byte += 0x20;   break;
            case '3':   byte += 0x30;   break;
            case '4':   byte += 0x40;   break;
            case '5':   byte += 0x50;   break;
            case '6':   byte += 0x60;   break;
            case '7':   byte += 0x70;   break;
            case '8':   byte += 0x80;   break;
            case '9':   byte += 0x90;   break;
            case 'a':   byte += 0xa0;   break;
            case 'b':   byte += 0xb0;   break;
            case 'c':   byte += 0xc0;   break;
            case 'd':   byte += 0xd0;   break;
            case 'e':   byte += 0xe0;   break;
            case 'f':   byte += 0xf0;   break;
            default:    return false;
            }
        }else{
            switch (c){
            case '0':                   break;
            case '1':   byte += 0x01;   break;
            case '2':   byte += 0x02;   break;
            case '3':   byte += 0x03;   break;
            case '4':   byte += 0x04;   break;
            case '5':   byte += 0x05;   break;
            case '6':   byte += 0x06;   break;
            case '7':   byte += 0x07;   break;
            case '8':   byte += 0x08;   break;
            case '9':   byte += 0x09;   break;
            case 'a':   byte += 0x0a;   break;
            case 'b':   byte += 0x0b;   break;
            case 'c':   byte += 0x0c;   break;
            case 'd':   byte += 0x0d;   break;
            case 'e':   byte += 0x0e;   break;
            case 'f':   byte += 0x0f;   break;
            default:    return false;
            }
            *(bytes + (count / 2)) = byte;
        }

        p++;
        count++;
    }
    return true;
}

AnsiString GetErrorText(DWORD err){
    AnsiString msg;
    LPVOID buff;
    DWORD result = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            0, err,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPTSTR)&buff,
            0, 0);
    if (result){
        msg = (char *)buff;
        LocalFree(buff);
    }
    return msg;
}

bool CompareBytes(const LPBYTE p1, const LPBYTE p2, int size){
    for (int i = 0; i < size; i++){
        if (*(p1 + i) != *(p2 + i))
            return false;
    }
    return true;
}

AnsiString GetSwitchValueForLog(BYTE sw1, BYTE sw2){
    char buff[50];
    wsprintf(buff, "SW1: 0x%02X / SW2: 0x%02X", sw1, sw2);
    return AnsiString(buff);
}

