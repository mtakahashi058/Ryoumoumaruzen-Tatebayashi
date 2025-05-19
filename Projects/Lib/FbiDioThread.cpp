//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FbiDioThread.h"
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
//      void __fastcall TFbiDioThread::UpdateCaption()
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
__fastcall TFbiDioThread::TFbiDioThread(bool CreateSuspended, HWND owner, HANDLE device)
    : TThread(CreateSuspended), owner_(owner), device_(device)
{
}
//---------------------------------------------------------------------------
void __fastcall TFbiDioThread::Execute()
{
    MSG msg;
    int ret;
    Channels *channels;
    AnsiString status;
    WORD input = 0;
    Channels cur_ch(16);
    Channels last_ch(16);
    Channels off_ch(16);

    last_ch.SetWord(0);

    while (!Terminated){
        Sleep(0);

    	while (PeekMessage(&msg, 0, DIOM_OUTPUT, DIOM_OUTPUT, PM_REMOVE)){
            channels = reinterpret_cast<Channels *>(msg.lParam);
            ret = DioOutputWord(device_, FBIDIO_OUT1_16, channels->GetWordImage());
            if (ret != 0){
                status = "16ビット出力に失敗しました / ERR: " + IntToStr(ret);
                SendMessage(owner_, DIOM_STATUS, 0, (LPARAM)status.c_str());
            }
            Sleep(500);
        }

        ret = DioInputWord(device_, FBIDIO_IN1_16, &input);
        if (ret != 0){
            status = "16ビット入力に失敗しました / ERR: " + IntToStr(ret);
            SendMessage(owner_, DIOM_STATUS, 0, (LPARAM)status.c_str());
            continue;
        }

        cur_ch.SetWord(input);

        if (last_ch.GetWordImage() != cur_ch.GetWordImage()){
            off_ch.SetWord(0);
            for (int i = 1; i <= 16; i++){
                if (last_ch[i] == chOn && cur_ch[i] == chOff)
                    off_ch[i] = chOn;
            }
            SendMessage(owner_, DIOM_INPUT, 0, off_ch.GetWordImage());
        }

        last_ch.SetWord(cur_ch.GetWordImage());
    }

    DioClose(device_);
}
//---------------------------------------------------------------------------
