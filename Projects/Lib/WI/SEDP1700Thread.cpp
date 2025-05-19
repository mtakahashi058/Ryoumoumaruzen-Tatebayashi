//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SEDP1700Thread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// ���ӁF�قȂ�X���b�h�����L���� VCL �̃��\�b�h/�֐�/�v���p�e�B��
//   �ʂ̃X���b�h�̒����爵���ꍇ�C�r�������̖�肪�������܂��B
//
//   ���C���X���b�h�̏��L����I�u�W�F�N�g�ɑ΂��Ă� Synchronize
//   ���\�b�h���g�������ł��܂��B���̃I�u�W�F�N�g���Q�Ƃ��邽��
//   �̃��\�b�h���X���b�h�N���X�ɒǉ����CSynchronize ���\�b�h��
//   �����Ƃ��ēn���܂��B
//
//   ���Ƃ��� UpdateCaption ���ȉ��̂悤�ɒ�`���A
//
//  void __fastcall TSEDP1700Thread::UpdateCaption()
//  {
//    Form1->Caption = "�X���b�h���珑�������܂���";
//  }
//
//   Execute ���\�b�h�̒��� Synchronize ���\�b�h�ɓn�����ƂŃ��C
//   ���X���b�h�����L���� Form1 �� Caption �v���p�e�B�����S�ɕ�
//   �X�ł��܂��B
//
//  Synchronize(UpdateCaption);
//
//---------------------------------------------------------------------------
__fastcall TSEDP1700Thread::TSEDP1700Thread(bool CreateSuspended, const WICommInfo& info)
    : TThread(CreateSuspended), info_(info)
{
}
//---------------------------------------------------------------------------
bool __fastcall TSEDP1700Thread::formatMessage(std::string& msg)
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
void __fastcall TSEDP1700Thread::Execute()
{
    ackl::OverlappedComm comm_;

/*
[STX]��XXXXXX[ETX][BCC]
     1
     0
*/

    const char DELIMITER = ETX;
    const int DELAY = 200;
    const int DATA_LEN = 10;

    // �V���A���|�[�g�̃I�[�v��
    if (!comm_.open(info_.port)){
        status_.is_fatal = true;
        status_.message = "COM�|�[�g���I�[�v���ł��܂���";
        SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        SendMessage(info_.owner, WIM_ABORTED, ThreadID, 0);
        return;
    }

    // �V���A���|�[�g�̏�����
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
        status_.message = "COM�|�[�g�̏������Ɏ��s���܂���";
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
    std::string err_buff;
    bool isWaited = false;
    unsigned int buff_size;

    ZeroMemory(&o_event, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_event.hEvent = CreateEvent(NULL, true, false, NULL);
    o_read.hEvent = CreateEvent(NULL, true, false, NULL);

    while (!Terminated){
        Sleep(DELAY);
/*
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

        // �����������������ǂ���
        if (!comm_.getOverlappedResult(&o_event, &transfer, false))
            continue;

        isWaited = false;
*/

        comm_.clearError(&error, &stat);
        err_buff.clear();
        if (comm_.formatMessage(error, err_buff)){
            status_.is_fatal = false;
            status_.message = err_buff.c_str();
            // SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }
        if (stat.cbInQue < DATA_LEN)
            continue;

        //if (event == EV_RXFLAG){
        {
            comm_.read(buff, stat.cbInQue, &size, &o_read);
            // ��M�҂�
            comm_.getOverlappedResult(&o_read, &transfer, true);

            buff_size = buff.size();

            int idx = buff.rfind(DELIMITER);
            if (idx == std::string::npos){
                comm_.purge();
                continue;
            }
            
            if (idx < 7)
                continue;
            
            buff = buff.substr(idx - 7, 7);

            if (buff[0] == '1')
                weight_.status = WIWeight::wiStable;
            else
                weight_.status = WIWeight::wiUnstable;

            buff.erase(0, 1);   // ����t���O�폜

            try{
                weight_.weight = Currency(buff.c_str());
            }catch(...){
                continue;
            }

            SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);

            comm_.purge();
        }
    }

    CloseHandle(o_event.hEvent);
    CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
