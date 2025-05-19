//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SAD4401TcpThread.h"
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
//      void __fastcall SAD4401TCPThread::UpdateCaption()
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

__fastcall SAD4401TCPThread::SAD4401TCPThread(bool CreateSuspended, const WITcpInfo& info)
    : TThread(CreateSuspended), info_(info),socket_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall SAD4401TCPThread::OnSocketRead(const AnsiString& data)
{
    const char DELIMITER = '\r';
    const int  DATA_LEN = 17;

    unsigned int buff_size;

    buff_size = data.Length();
    std::string buff = data.c_str();

    if (buff_size > DATA_LEN){

        int idx = buff.rfind(DELIMITER);
        if (idx == std::string::npos){
            return;
        }

        if (idx < DATA_LEN -1){
            return;
        }

        buff = buff.substr((idx - DATA_LEN) + 1, DATA_LEN);

    }else if (buff_size < DATA_LEN){
        return;
    }

    if (buff[0] == 'S'){
        weight_.status = WIWeight::wiStable;
    }else if(buff[0] == 'U'){
        weight_.status = WIWeight::wiUnstable;
    }else if(buff[0] == 'O'){
        weight_.status = WIWeight::wiOverload;
    }else{
        return;
    }

    buff.erase(0, 6);
    buff.erase(8);

    try{

        if (weight_.status == WIWeight::wiOverload){
            weight_.weight = 0;
        }else{
            weight_.weight = Currency(buff.c_str());
        }

    }catch(...){
        return;
    }

    SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);
}
//---------------------------------------------------------------------------
void __fastcall SAD4401TCPThread::OnSocketError(const AnsiString& message)
{
    SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)"重量値用ソケットとの通信が切断されました");
    PostMessage(info_.owner, WIM_ABORTED, ThreadID, 0);
    return;
}
//---------------------------------------------------------------------------
void __fastcall SAD4401TCPThread::Execute()
{
    MSG msg;


    try {

        socket_.SetHandler(OnSocketRead, OnSocketError);
        socket_.Open(info_.addr, info_.port);

    }catch(Exception& e){
        status_.is_fatal = true;
        status_.message = "ソケット初期化に失敗しました";
        SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        SendMessage(info_.owner, WIM_ABORTED, ThreadID, 0);
        return;
    }

    while(!Terminated) {

        if (Terminated){
            break;
        }

        if (!socket_.IsActive()){
            socket_.Reopen();
        }

        Sleep(200);

        if (socket_.WaitForData()){                      
            socket_.ReadCommand();
        }else{
            status_.is_fatal = true;
            status_.message = "重量値を受信できません";
            SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }

    }

    socket_.Close();
}
//---------------------------------------------------------------------------

