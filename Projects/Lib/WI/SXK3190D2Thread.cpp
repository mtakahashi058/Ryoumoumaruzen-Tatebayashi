//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SXK3190D2Thread.h"
#pragma package(smart_init)
#include <fstream>
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
//  void __fastcall TSXK3190D2Thread::UpdateCaption()
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
__fastcall TSXK3190D2Thread::TSXK3190D2Thread(bool CreateSuspended, const WICommInfo& info)
    : TThread(CreateSuspended), info_(info)
{
}
//---------------------------------------------------------------------------
bool __fastcall TSXK3190D2Thread::formatMessage(std::string& msg)
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
void __fastcall TSXK3190D2Thread::Execute()
{
    ackl::OverlappedComm comm_;

    const char DELIMITER = '=';
    const int DELAY = 200;
    const int DATA_LEN = 8;

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
    std::string buff, rec_buff;
    std::string err_buff;
    bool isWaited = false;
    unsigned int buff_size;

    ZeroMemory(&o_event, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_event.hEvent = CreateEvent(NULL, true, false, NULL);
    o_read.hEvent = CreateEvent(NULL, true, false, NULL);
    
    while (!Terminated){
        Sleep(DELAY);

        comm_.clearError(&error, &stat);
        err_buff.clear();
        if (comm_.formatMessage(error, err_buff)){
            status_.is_fatal = false;
            status_.message = err_buff.c_str();
            // SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }
        if (stat.cbInQue < DATA_LEN){
            continue;
        }

        //if (event == EV_RXFLAG){
        {
            comm_.read(buff, stat.cbInQue, &size, &o_read);
            // ��M�҂�
            comm_.getOverlappedResult(&o_read, &transfer, true);

            buff_size = buff.size();

            int idx = buff.rfind(DELIMITER);
            if (idx == std::string::npos)
                continue;

            // 000=03210000=
            while (1){
                if (idx < buff.size() - 1){
                    rec_buff = buff.substr(idx);
                    if (rec_buff.size() >= DATA_LEN)
                        break;
                }

                idx = buff.rfind(DELIMITER, idx - 1);
            }
            if (idx == std::string::npos)
                continue;

            buff = buff.substr(idx + 1, DATA_LEN);

            // buff: 03210000
            rec_buff.clear();
            for (std::string::reverse_iterator i = buff.rbegin(); i != buff.rend(); i++){
                rec_buff += *i;
            }

            weight_.status = WIWeight::wiStable;
            try{
                weight_.weight = Currency(rec_buff.c_str());
            }catch(...){
                continue;
            }

            SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);
        }
    }

    CloseHandle(o_event.hEvent);
    CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
