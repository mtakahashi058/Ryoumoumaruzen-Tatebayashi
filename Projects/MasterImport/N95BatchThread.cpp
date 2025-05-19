//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "N95BatchThread.h"
#pragma package(smart_init)
#include "CComm.h"
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
//      void __fastcall TN95BatchThread::UpdateCaption()
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
__fastcall TN95BatchThread::TN95BatchThread(bool CreateSuspended, int port, const AnsiString& def, HWND owner)
    : TThread(CreateSuspended), port_(port), def_(def), owner_(owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TN95BatchThread::Execute()
{
    CComm comm;

	try{
		if (!comm.Open(port_)){
			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"シリアルポートのオープンに失敗しました");
			PostMessage(owner_, BM_ABORTED, 0, 0);
			return;
		}
		if (!comm.SetupComm(def_.c_str())){
			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"シリアルデバイスの初期化に失敗しました");
			PostMessage(owner_, BM_ABORTED, 0, 0);
			return;
		}
	}catch(CComm::CommCtrlException& e){
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)AnsiString(AnsiString("シリアルデバイスエラー - ") + e.GetMessage()).c_str());
		PostMessage(owner_, BM_ABORTED, 0, 0);
		return;
	}
	comm.SetTimeout();

	const RETRY = 5;
	const DWORD TIMEOUT = 3000;
	char cmd[] = "\x02SEN CHIT      \x03m";
	short ch;
	char buff[131];
	int i = 0;
	int receive_cnt = 0;	// 受信件数
	//int n95_cnt;		// 指示計側での送信件数

	try{
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ送信...");
		if (!comm.SendChar(ENQ))
			throw Exception("ENQの送信に失敗しました");

        Sleep(100);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK受信...");
		if (!comm.WaitChar(ACK, TIMEOUT))
			throw Exception("ACKを受信できません");

		while(1){
            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"コマンド送信...");
			if (comm.WaitWrite(cmd, TIMEOUT) != (DWORD)lstrlen(cmd))
				throw Exception("コマンドテキストの送信に失敗しました");

            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK受信...");
			ch = comm.ReceiveChar(TIMEOUT);
			if (ch == (short)ACK){
				break;
			}else if (ch == (short)NAK)
				continue;
			else
				throw Exception("ACKを受信できません");
			//Sleep(100);
		}

        Sleep(100);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT送信...");
		if (!comm.SendChar(EOT))
			throw Exception("EOTの送信に失敗しました");

		while (!Terminated){
            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ受信...");
			if (!comm.WaitChar(ENQ, TIMEOUT))
				throw Exception("ENQの受信に失敗しました");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK送信...");
			if (!comm.SendChar(ACK))
				throw Exception("ACKの送信に失敗しました");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"データ受信...");
			while(1){
                Sleep(100);

                ZeroMemory(buff, sizeof(buff));

				if (comm.WaitRead(buff, 129) == 129)
					break;
				i++;
				if (!comm.SendChar(NAK))
					throw Exception("NAKの送信に失敗しました");
				if (i >= RETRY)
					throw Exception("データの受信に失敗しました");
				Sleep(100);
			}
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			i = 0;

			buff[127] = '\0';

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK送信...");
			if (!comm.SendChar(ACK))
				throw Exception("ACKの送信に失敗しました");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT受信...");
			if (!comm.WaitChar(EOT, TIMEOUT))
				throw Exception("EOTの受信に失敗しました");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			if (buff[2] == 'E' && buff[3] == 'N' && buff[4] == 'D'){
				// n95_cnt = satoi(&buff[11]);
				break;
			}

			SendMessage(owner_, BM_DATARECEIVED, 0, (LPARAM)buff);
			receive_cnt++;
			Sleep(100);
		}
	}catch(Exception& e){
        comm.Close();
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)e.Message.c_str());
		PostMessage(owner_, BM_ABORTED, 0, 0);
		return;
	}
	PostMessage(owner_, BM_COMPLETED, 0, 0);
}
//---------------------------------------------------------------------------
