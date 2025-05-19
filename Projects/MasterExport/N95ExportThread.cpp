//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "N95ExportThread.h"
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
//      void __fastcall TN95ExportThread::UpdateCaption()
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
char CalcBCC(LPCSTR text) {
    char bcc = 0x00;
    while (*text != '\0')
        bcc ^= *text++;
    return bcc;
}
//---------------------------------------------------------------------------
__fastcall TN95ExportThread::TN95ExportThread(bool CreateSuspended,
    int port, const AnsiString& def, HWND owner, ExportTarget target, const Records& recs)
    : TThread(CreateSuspended), port_(port), def_(def), owner_(owner), records_(recs)
{
    if (target == etID){
        command_ = "*REC ID.       *";
    }else if (target == etItem){
        command_ = "*REC CODE      *";
    }
    command_[1] = 0x02;                 // STX
    command_[command_.Length()] = 0x03; // ETX
    char bcc = CalcBCC(command_.c_str() + 1);
    command_ += "*";
    command_[command_.Length()] = bcc;
}
//---------------------------------------------------------------------------
void __fastcall TN95ExportThread::Execute()
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
	short ch;
	char buff[131];
	int i = 0;

	try{
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ送信...");
		if (!comm.SendChar(ENQ))
			throw Exception("ENQの送信に失敗しました");

        //Sleep(200);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK受信...");
		if (!comm.WaitChar(ACK, TIMEOUT))
			throw Exception("ACKを受信できません");

		while(1){
            //Sleep(200);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"コマンド送信...");
			if (comm.WaitWrite(command_.c_str(), TIMEOUT) != (DWORD)command_.Length())
				throw Exception("コマンドテキストの送信に失敗しました");

            //Sleep(200);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK受信...");
			ch = comm.ReceiveChar(TIMEOUT);
			if (ch == (short)ACK){
				break;
			}else if (ch == (short)NAK)
				continue;
			else
				throw Exception("ACKを受信できません");
			////Sleep(200);
		}

        //Sleep(200);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT送信...");
		if (!comm.SendChar(EOT))
			throw Exception("EOTの送信に失敗しました");

        ///////////////////////////////////////////////////// ↑ コマンド送信フロー
        ///////////////////////////////////////////////////// ↓ データ送信フロー

        AnsiString buff;
        for (unsigned i = 0; i < records_.size(); i++){
            buff = records_[i];

            Sleep(150);

    		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ送信...");
    		if (!comm.SendChar(ENQ))
    			throw Exception("ENQの送信に失敗しました");

            //OutputDebugString("P1. Send ENQ");

    		PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

            //Sleep(200);

    		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK受信...");
    		if (!comm.WaitChar(ACK, TIMEOUT)){
                OutputDebugString("P2. ERR");
    			throw Exception("ACKを受信できません");
            }

            //OutputDebugString("P2. Recv ACK");

    		PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

    		while(1){
                //Sleep(200);

    			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"データ送信...");
    			if (comm.WaitWrite((LPBYTE)(buff.c_str()), 129, TIMEOUT) != (DWORD)buff.Length()){
                    int len = buff.Length();
                    len++; len--;
    				throw Exception("コマンドテキストの送信に失敗しました");
                }

                //OutputDebugString("P3-1. Send DATA");

                //Sleep(200);

    			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK受信...");
    			ch = comm.ReceiveChar(TIMEOUT);
    			if (ch == (short)ACK){
                    //OutputDebugString("P3-2. Recv ACK");
    				break;
    			}else if (ch == (short)NAK){
                    //OutputDebugString("P3 WARN. Recv NAK");
    				continue;
    			}else{
                    if (ch != -1){
                        char chbuff[5];
                        wsprintf(chbuff, "%02X", (unsigned char)(ch));
                        AnsiString msg = AnsiString("P3 ERR, ") + chbuff;
                        OutputDebugString(msg.c_str());
                    }else{
                        AnsiString msg = AnsiString("P3 ERR.");
                        OutputDebugString(msg.c_str());
                    }
    				throw Exception("ACKを受信できません");
                }
    			////Sleep(200);
	    	}

            if (i != records_.size() -1)
    			SendMessage(owner_, BM_DATASENDED, 0, i + 1);
            
    		PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

            //OutputDebugString("P3. DATA SEND END");

            //Sleep(200);

    		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT送信...");
	    	if (!comm.SendChar(EOT))
    			throw Exception("EOTの送信に失敗しました");

            //OutputDebugString("P4. Send EOT");

    		PostMessage(owner_, BM_PROCESS_STEP, 0, 0);
        }
	}catch(Exception& e){
        comm.Close();
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)e.Message.c_str());
		PostMessage(owner_, BM_ABORTED, 0, 0);
		return;
	}
    comm.Close();
	PostMessage(owner_, BM_COMPLETED, 0, 0);
}
//---------------------------------------------------------------------------
