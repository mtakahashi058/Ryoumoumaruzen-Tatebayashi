//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ioMirrorThread.h"
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
//      void __fastcall TioMirrorThread::UpdateCaption()
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
__fastcall TioMirrorThread::TioMirrorThread(bool CreateSuspended, HWND owner, const AnsiString& address)
	: TThread(CreateSuspended), owner_(owner), IO_(0), address_(address), last_inputs_(8)
{
}
//---------------------------------------------------------------------------
void __fastcall TioMirrorThread::OnIOInput(const Channels& channels)
{
	Channels cur_channels(channels);
	if (last_inputs_.GetByteImage() != cur_channels.GetByteImage()){
		SendMessage(owner_, DIOM_INPUT, 0, cur_channels.GetByteImage());
	}
	last_inputs_.SetByte(cur_channels.GetByteImage());
}
//---------------------------------------------------------------------------
void __fastcall TioMirrorThread::OnIOResponse(const AnsiString& message)
{
	// nothing to do
}
//---------------------------------------------------------------------------
void __fastcall TioMirrorThread::OnIOError(const AnsiString& message)
{
	SendMessage(owner_, DIOM_STATUS, 0, (LPARAM)"IOユニットとの通信が切断されました");
	PostMessage(owner_, DIOM_ABORTED, 0, 0);
	Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TioMirrorThread::Execute()
{
	MSG msg;

	///////////////////////////////////////////////
	// ioMirror に接続

	try{
		IO_.SetHandler(OnIOInput, OnIOResponse, OnIOError);
		IO_.Open(address_);
	}catch(Exception& e){
		SendMessage(owner_, DIOM_STATUS, 0, (LPARAM)"IOデバイスに接続できません");
		PostMessage(owner_, DIOM_ABORTED, 0, 0);
		return;
	}

	while (!Terminated){
tol:
		if (Terminated)
			break;

		Sleep(200);

/*
		while (PeekMessage(&msg, 0, DIOM_OUTPUT, DIOM_OUTPUT, PM_REMOVE)){
			if (!IO_.CanCommand())
				continue;
			IO_.OutputAll(BYTE(msg.lParam));
			continue;
		}
*/
		while (PeekMessage(&msg, 0, DIOM_OUTPUT, DIOM_OUTPUT, PM_NOREMOVE)){
			if (!IO_.CanCommand())
				goto tol;
			GetMessage(&msg, 0, DIOM_OUTPUT, DIOM_OUTPUT);
			IO_.OutputAll(BYTE(msg.lParam));
			continue;
		}

		if (!IO_.CanCommand())
			continue;
		IO_.InputAll();
	}

	if (IO_.CanCommand())
		IO_.OutputAll();
	IO_.Close();
}
//---------------------------------------------------------------------------
