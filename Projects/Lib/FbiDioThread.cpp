//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FbiDioThread.h"
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
//      void __fastcall TFbiDioThread::UpdateCaption()
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
                status = "16�r�b�g�o�͂Ɏ��s���܂��� / ERR: " + IntToStr(ret);
                SendMessage(owner_, DIOM_STATUS, 0, (LPARAM)status.c_str());
            }
            Sleep(500);
        }

        ret = DioInputWord(device_, FBIDIO_IN1_16, &input);
        if (ret != 0){
            status = "16�r�b�g���͂Ɏ��s���܂��� / ERR: " + IntToStr(ret);
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
