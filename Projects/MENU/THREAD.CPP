//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "thread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
//   注意: VCL オブジェクトのメソッドとプロパティを使用するには, Synchronize 
//         を使ったメソッド呼び出しでなければなりません。次に例を示します。
//
//      Synchronize(UpdateCaption);
//
//   ここで, UpdateCaption は次のように記述できます。
//
//      void __fastcall TExecThread::UpdateCaption()
//      {
//        Form1->Caption = "スレッドから書き換えました";
//      }
//---------------------------------------------------------------------------
__fastcall TExecThread::TExecThread(bool CreateSuspended, AnsiString name, HWND hWnd)
	: TThread(CreateSuspended), ExeName(name), hWndOwner(hWnd)
{
}
//---------------------------------------------------------------------------
void __fastcall TExecThread::Execute()
{
	if (ExeName == "")
		return;
	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	if (Terminated)
		return;
	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;
	if (!CreateProcess(NULL, ExeName.c_str(), NULL, NULL, false,
			CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS,
			NULL, NULL, &stStartupInfo, &stProcessInfo)){
		OutputDebugString("プロセス生成失敗");
		PostMessage(hWndOwner, UM_EXECTERMINATE, 0, 0);
		return;
	}
	while (!Terminated){
		if (WaitForSingleObject(stProcessInfo.hProcess, 500) != WAIT_TIMEOUT)
			break;
		Sleep(300);
	}
	if (Terminated)
		return;
	PostMessage(hWndOwner, UM_EXECTERMINATE, 0, 0);
}
//---------------------------------------------------------------------------
