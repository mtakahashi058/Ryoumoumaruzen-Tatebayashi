//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ioMirrorThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// ���ӁF�قȂ�X���b�h�����L���� VCL �̃��\�b�h/�֐�/�v���p�e�B��
//       �ʂ̃X���b�h�̒����爵���ꍇ�C�r�������̖�肪�������܂��B
//
//       ���C���X���b�h�̏��L����I�u�W�F�N�g�ɑ΂��Ă� Synchronize
//       ���\�b�h���g�������ł��܂��B���̃I�u�W�F�N�g���Q�Ƃ��邽��
//       �̃��\�b�h���X���b�h�N���X�ɒǉ����CSynchronize ���\�b�h��
//       �����Ƃ��ēn���܂��B
//
//       ���Ƃ��� UpdateCaption ���ȉ��̂悤�ɒ�`���A
//
//      void __fastcall TioMirrorThread::UpdateCaption()
//      {
//        Form1->Caption = "�X���b�h���珑�������܂���";
//      }
//
//       Execute ���\�b�h�̒��� Synchronize ���\�b�h�ɓn�����ƂŃ��C
//       ���X���b�h�����L���� Form1 �� Caption �v���p�e�B�����S�ɕ�
//       �X�ł��܂��B
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
	SendMessage(owner_, DIOM_STATUS, 0, (LPARAM)"IO���j�b�g�Ƃ̒ʐM���ؒf����܂���");
	PostMessage(owner_, DIOM_ABORTED, 0, 0);
	Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TioMirrorThread::Execute()
{
	MSG msg;

	///////////////////////////////////////////////
	// ioMirror �ɐڑ�

	try{
		IO_.SetHandler(OnIOInput, OnIOResponse, OnIOError);
		IO_.Open(address_);
	}catch(Exception& e){
		SendMessage(owner_, DIOM_STATUS, 0, (LPARAM)"IO�f�o�C�X�ɐڑ��ł��܂���");
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
