//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HF04Thread.h"
#include "SystemID.h"
#include <memory>
#pragma package(smart_init)
//---------------------------------------------------------------------------

// 注意：異なるスレッドが所有する VCL のメソッド/関数/プロパティを
//       別のスレッドの中から扱う場合，排他処理の問題が発生します。
//
//       メインスレッドの所有するオブジェクトに対しては Synchronize
//       メソッドを使う事ができます。他のオブジェクトを参照するため
//       のメソッドをスレッドクラスに追加し，Synchronize メソッドの
//       引数として渡します。
//
//       たとえば UpdateCaption を以下のように定義し、
//
//      void __fastcall THF04Thread::UpdateCaption()
//      {
//        Form1->Caption = "スレッドから書き換えました";
//      }
//
//       Execute メソッドの中で Synchronize メソッドに渡すことでメイ
//       ンスレッドが所有する Form1 の Caption プロパティを安全に変
//       更できます。
//
//      Synchronize(UpdateCaption);
//
//---------------------------------------------------------------------------
__fastcall THF04Thread::THF04Thread(bool CreateSuspended, HWND owner, int port, const AnsiString& def)
    : TThread(CreateSuspended), owner_(owner), port_(port), def_(def)
{
}
//---------------------------------------------------------------------------
bool __fastcall THF04Thread::FormatMessage(std::string& msg)
{
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
//---------------------------------------------------------------------------
AnsiString THF04Thread::BytesToHexString(LPBYTE bytes, int size, char sep)
{
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
//---------------------------------------------------------------------------
bool THF04Thread::HexStringToBytes(LPCSTR src, LPBYTE bytes)
{
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
//---------------------------------------------------------------------------
void __fastcall THF04Thread::IssueCard(HWND callback_wnd, int card_no)
{
    const int DELAY = 100;
    const DWORD TIMEOUT = 3000;

    if (card_no > 99999999){
        SendMessage(callback_wnd, RFIDM_STATUS, false, (LPARAM)"カード番号が無効です");
        SendMessage(callback_wnd, RFIDM_ISS_FAIL, 0, 0);
        return;
    }

    char cmd[200];
    DWORD size, transfer, event, error;
    COMSTAT stat;
    std::string err_buff, buff;
    std::auto_ptr<TStringList> ResList(new TStringList());

    wsprintf(cmd, "A85RSCAMRFID%08d", card_no);
    AnsiString bytes = BytesToHexString(cmd, lstrlen(cmd), 0x00);

    wsprintf(cmd, "2WM,01,00,05,%s\r", bytes.c_str());

    comm_.cancelIo();

    comm_.write(cmd, &size, &o_write);
    comm_.getOverlappedResult(&o_write, &transfer, true);
    comm_.waitEvent(&event, &o_event);
    if ((error = GetLastError()) != ERROR_IO_PENDING){
        std::string msg;
        FormatMessage(msg);
        if (!Terminated)
            SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)msg.c_str());
        return;
    }

    DWORD sended_count = GetTickCount();
    ResList->Clear();
    while (GetTickCount() - sended_count <= TIMEOUT){
        if (!comm_.getOverlappedResult(&o_event, &transfer, false)){
            Sleep(DELAY);
            continue;
        }

        comm_.clearError(&error, &stat);
        err_buff.clear();
        if (comm_.formatMessage(error, err_buff)){
            if (!Terminated)
                SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)err_buff.c_str());
        }

        comm_.read(buff, stat.cbInQue, &size, &o_read);
        comm_.getOverlappedResult(&o_read, &transfer, true);

        buff.erase(buff.length() - 1);  // [CR] の削除

        ResList->CommaText = buff.c_str();

        break;
    }

    if (ResList->Count < 1){
        SendMessage(callback_wnd, RFIDM_STATUS, false, (LPARAM)"レスポンスエラー");
        SendMessage(callback_wnd, RFIDM_ISS_FAIL, 0, 0);
        return;
    }

    if (ResList->Strings[0][1] == 'E'){
        SendMessage(callback_wnd, RFIDM_STATUS, false, (LPARAM)"コマンドエラー");
        SendMessage(callback_wnd, RFIDM_ISS_FAIL, 0, 0);
        return;
    }
    if (ResList->Count != 2){
        SendMessage(callback_wnd, RFIDM_STATUS, false, (LPARAM)"レスポンスエラー");
        SendMessage(callback_wnd, RFIDM_ISS_FAIL, 0, 0);
        return;
    }
    if (ResList->Strings[1] == "OK"){
        SendMessage(callback_wnd, RFIDM_ISS_COMP, 0, 0);
   		Sleep(5000);
    }else{
        SendMessage(callback_wnd, RFIDM_STATUS, false, (LPARAM)"カードへの書き込みに失敗しました");
        SendMessage(callback_wnd, RFIDM_ISS_FAIL, 0, 0);
    }
}
//---------------------------------------------------------------------------
void __fastcall THF04Thread::Execute()
{
    const char DELIMITER = '\r';
    const int DELAY = 100;
    const DWORD TIMEOUT = 3000;

    // シリアルポートのオープン
    if (!comm_.open(port_)){
        SendMessage(owner_, RFIDM_STATUS, true, (LPARAM)"COMポートがオープンできません");
        PostMessage(owner_, RFIDM_ABORTED, 0, 0);
        return;
    }

    // シリアルポートの初期化
    try{
        DCB dcb;
        COMMTIMEOUTS timeouts;

        if (!comm_.getState(&dcb))
            throw std::runtime_error("getState");

        if (!comm_.buildDCB(def_.c_str(), &dcb))
            throw std::runtime_error("buildDCB");

        dcb.fOutxCtsFlow = false;
        dcb.fOutxDsrFlow = false;
        dcb.fRtsControl = RTS_CONTROL_DISABLE;
        dcb.fDtrControl = DTR_CONTROL_DISABLE;
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
        SendMessage(owner_, RFIDM_STATUS, true, (LPARAM)"COMポートの初期化に失敗しました");
        PostMessage(owner_, RFIDM_ABORTED, 0, 0);
        return;
    }

    COMSTAT stat;
    MSG msg;
    DWORD size, transfer, error;
    DWORD event, sended_count;
    AnsiString status, image;
    std::string buff, err_buff;
    std::auto_ptr<TStringList> ResList(new TStringList());
    BYTE read_bytes[65];
    int card_no;

    bool card_presented = false;
    bool timeouted;

    ZeroMemory(&o_write, sizeof(OVERLAPPED));
    ZeroMemory(&o_event, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_write.hEvent = CreateEvent(0, true, false, 0);
    o_event.hEvent = CreateEvent(0, true, false, 0);
    o_read.hEvent = CreateEvent(0, true, false, 0);


    while (!Terminated){
        Sleep(DELAY);

        ////////////////////////////////////////////////////////////////////////
        // 書込命令の確認

		if (PeekMessage(&msg, 0, RFIDM_ISSUE, RFIDM_ISSUE, PM_REMOVE)){
            HWND wnd = reinterpret_cast<HWND>(msg.wParam);
            if (card_presented){
    			IssueCard(wnd, msg.lParam);
            }else{
                SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)"カードが存在しないため書き込みできません");
                SendMessage(wnd, RFIDM_ISS_FAIL, 0, 0);
            }
            continue;
        }

        ////////////////////////////////////////////////////////////////////////
        // カードの検出

        comm_.cancelIo();

        comm_.write("2XX\r", &size, &o_write);
        comm_.getOverlappedResult(&o_write, &transfer, true);
        comm_.waitEvent(&event, &o_event);
        if ((error = GetLastError()) != ERROR_IO_PENDING){
            std::string msg;
            FormatMessage(msg);
            if (!Terminated)
                SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)msg.c_str());
            continue;
        }

        sended_count = GetTickCount();
        card_presented = false;
        timeouted      = true;
        while (GetTickCount() - sended_count <= TIMEOUT){
            if (!comm_.getOverlappedResult(&o_event, &transfer, false)){
                Sleep(DELAY);
                continue;
            }

            comm_.clearError(&error, &stat);
            err_buff.clear();
            if (comm_.formatMessage(error, err_buff)){
                if (!Terminated)
                    SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)err_buff.c_str());
            }

            comm_.read(buff, stat.cbInQue, &size, &o_read);
            comm_.getOverlappedResult(&o_read, &transfer, true);

            buff.erase(buff.length() - 1);  // [CR] の削除

            ResList->Clear();                   
            ResList->CommaText = buff.c_str();
            if (ResList->Strings[0].ToIntDef(0) > 0){
                card_presented = true;
                timeouted      = false;
            }else{
                card_presented = false;
                timeouted      = false;
            }
            break;
        }

        if (!Terminated){
            if (timeouted)
                PostMessage(owner_, RFIDM_TIMEOUT, true,  0);
            else
                PostMessage(owner_, RFIDM_TIMEOUT, false, 0);
        }

        if (!card_presented)
            continue;

        //status = "検出UID: " + ResList->Strings[1];
        //SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)status.c_str());

        ////////////////////////////////////////////////////////////////////////
        // カードの読込

        comm_.write("2R,01,00,05\r", &size, &o_write);           // 5block read
        comm_.getOverlappedResult(&o_write, &transfer, true);
        comm_.waitEvent(&event, &o_event);
        if ((error = GetLastError()) != ERROR_IO_PENDING){
            std::string msg;
            FormatMessage(msg);
            if (!Terminated)
                SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)msg.c_str());
            continue;
        }

        sended_count = GetTickCount();
        while (GetTickCount() - sended_count <= TIMEOUT){
            if (!comm_.getOverlappedResult(&o_event, &transfer, false)){
                Sleep(DELAY);
                continue;
            }

            comm_.clearError(&error, &stat);
            err_buff.clear();
            if (comm_.formatMessage(error, err_buff)){
                if (!Terminated)
                    SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)err_buff.c_str());
            }

            comm_.read(buff, stat.cbInQue, &size, &o_read);
            comm_.getOverlappedResult(&o_read, &transfer, true);

            buff.erase(buff.length() - 1);  // [CR] の削除

            ResList->CommaText = buff.c_str();
            break;
        }

        if (ResList->Count < 3){
            if (!Terminated)
                SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)"カードの読み込みに失敗しました");
            continue;
        }

        if (!HexStringToBytes(ResList->Strings[2].c_str(), read_bytes)){
            if (!Terminated)
                SendMessage(owner_, RFIDM_STATUS, false, (LPARAM)"カードイメージが不正です");
            continue;
        }
        image = AnsiString(LPCSTR(read_bytes));

        if (image.AnsiPos("NKSW") != 1){
			if (!Terminated)
                SendMessage(owner_, RFIDM_CARD, false, reinterpret_cast<LPARAM>("機器IDの認証に失敗しました"));
			if (!Terminated)
                Sleep(2000);
			continue;
        }
        if (image.AnsiPos("SCAMRFID") != 5){
			if (!Terminated)
                SendMessage(owner_, RFIDM_CARD, false, reinterpret_cast<LPARAM>("システムキーの認証に失敗しました"));
			if (!Terminated)
                Sleep(2000);
			continue;
        }

		::MessageBeep(MB_ICONASTERISK);

        card_no = image.SubString(13, 8).ToIntDef(-1);

        if (!Terminated){
            PostMessage(owner_, RFIDM_CARD, true, card_no);

            if (card_no != RFID::ADMIN_CARD_NO)
                Sleep(1000);
        }
    }

    CloseHandle(o_write.hEvent);
    CloseHandle(o_event.hEvent);
    CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
