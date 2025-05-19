//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RMThread.h"
#pragma package(smart_init)
#include <map>
#include <fstream>
#include <memory>
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
//      void __fastcall TRoadMeterThread::UpdateCaption()
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
__fastcall TRoadMeterThread::TRoadMeterThread(bool CreateSuspended, const WICommInfo& info)
    : TThread(CreateSuspended), info_(info)
{
}
//---------------------------------------------------------------------------
bool __fastcall TRoadMeterThread::formatMessage(std::string& msg)
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
void __fastcall TRoadMeterThread::Execute()
{
    ackl::OverlappedComm comm_;

    const char DELIMITER = '\n';
    const int DELAY = 200;
    const int DATA_LEN = 22;

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
    std::string local_buff;
    std::string err_buff;
    bool isWaited = false;
    unsigned int buff_size;

    int max_cell_no = 0;
    int cell_no;
    typedef std::map<int, Currency> Cells;
    Cells cells;
    Currency weight;

    ZeroMemory(&o_event, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_event.hEvent = CreateEvent(NULL, true, false, NULL);
    o_read.hEvent = CreateEvent(NULL, true, false, NULL);

    std::auto_ptr<TStringList> BuffList(new TStringList());
    std::string ansi_buff;
    int idx;

//  std::ofstream ofs("c:\\rm.txt");

    while (!Terminated){
        Sleep(DELAY);

        if (!isWaited){
            comm_.cancelIo();
            comm_.waitEvent(&event, &o_event);
            if (GetLastError() != ERROR_IO_PENDING){
                std::string msg;
                formatMessage(msg);
                status_.is_fatal = false;
                status_.message = msg.c_str();
                SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
                continue;
            }
            isWaited = true;
        }

        // 処理が完了したかどうか
        if (!comm_.getOverlappedResult(&o_event, &transfer, false))
            continue;

        isWaited = false;

        comm_.clearError(&error, &stat);
        err_buff.clear();
        if (comm_.formatMessage(error, err_buff)){
            status_.is_fatal = false;
            status_.message = err_buff.c_str();
            SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }
        if (stat.cbInQue == 0)
            continue;

        comm_.read(buff, stat.cbInQue, &size, &o_read);
        comm_.getOverlappedResult(&o_read, &transfer, true);

        buff = local_buff + buff;
        
        buff_size = buff.size();

        if (buff_size <= DATA_LEN){
            local_buff = buff;
            continue;
        }


        BuffList->Clear();
        while((idx = buff.find(DELIMITER)) >= DELIMITER - 1){
            BuffList->Append(buff.substr((idx - DATA_LEN) + 1, DATA_LEN).c_str());
            buff.erase(0, idx + 1);
        }
        local_buff = buff;

        if (!BuffList->Count)
            continue;

        for (int i = 0; i < BuffList->Count; i++){
            ansi_buff = BuffList->Strings[i].c_str();

            // 計量台No の取得
            if (ansi_buff[6] == ' ')
                ansi_buff[6] = '0';
            cell_no = StrToIntDef(ansi_buff.substr(6, 2).c_str(), 0);
            if (cell_no < 1)    // 計量台No が 1 未満なら無効
                continue;
            // 最大計量台No
            if (cell_no > max_cell_no) max_cell_no = cell_no;

            // 重量を取得し、計量台No と紐付け
            std::string weight_buff = ansi_buff.substr(9, 7).c_str();
            for (unsigned int i = 0; i < weight_buff.size(); i++)
                if (weight_buff[i] == ' ')
                    weight_buff[i] = '0';

            try{
                weight = Currency(weight_buff.c_str());
            }catch(...){
                continue;
            }
            cells[cell_no] = weight;
//          ofs << cell_no << ", " << weight_buff.c_str() << std::endl;

            // 送られたデータの計量台No がこれまでで最大のものであれば、
            // ここまでのデータを合算し、送信

            if (cell_no != max_cell_no)
                continue;

            weight_.status = WIWeight::wiStable;
            weight_.weight = 0;
            for (Cells::iterator i = cells.begin(); i != cells.end(); i++)
                weight_.weight += i->second;

            SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);
        }
    }

    CloseHandle(o_event.hEvent);
    CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
