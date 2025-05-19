//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RMThread.h"
#pragma package(smart_init)
#include <map>
#include <fstream>
#include <memory>
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
//      void __fastcall TRoadMeterThread::UpdateCaption()
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
__fastcall TRoadMeterThread::TRoadMeterThread(bool CreateSuspended, const WICommInfo& info)
    : TThread(CreateSuspended), info_(info)
{
}
//---------------------------------------------------------------------------
bool __fastcall TRoadMeterThread::formatMessage(std::string& msg)
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
void __fastcall TRoadMeterThread::Execute()
{
    ackl::OverlappedComm comm_;

    const char DELIMITER = '\n';
    const int DELAY = 200;
    const int DATA_LEN = 22;

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
    std::string local_buff;
    std::string err_buff;
    bool isWaited = false;
    unsigned int buff_size;

    int max_cell_no = 0;
    int cell_no;
    typedef std::map<int, Currency> Cells;
    Cells cells;
    Currency weight;

    ZeroMemory(&o_event, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_event.hEvent = CreateEvent(NULL, true, false, NULL);
    o_read.hEvent = CreateEvent(NULL, true, false, NULL);

    std::auto_ptr<TStringList> BuffList(new TStringList());
    std::string ansi_buff;
    int idx;

//  std::ofstream ofs("c:\\rm.txt");

    while (!Terminated){
        Sleep(DELAY);

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

        comm_.clearError(&error, &stat);
        err_buff.clear();
        if (comm_.formatMessage(error, err_buff)){
            status_.is_fatal = false;
            status_.message = err_buff.c_str();
            SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }
        if (stat.cbInQue == 0)
            continue;

        comm_.read(buff, stat.cbInQue, &size, &o_read);
        comm_.getOverlappedResult(&o_read, &transfer, true);

        buff = local_buff + buff;
        
        buff_size = buff.size();

        if (buff_size <= DATA_LEN){
            local_buff = buff;
            continue;
        }


        BuffList->Clear();
        while((idx = buff.find(DELIMITER)) >= DELIMITER - 1){
            BuffList->Append(buff.substr((idx - DATA_LEN) + 1, DATA_LEN).c_str());
            buff.erase(0, idx + 1);
        }
        local_buff = buff;

        if (!BuffList->Count)
            continue;

        for (int i = 0; i < BuffList->Count; i++){
            ansi_buff = BuffList->Strings[i].c_str();

            // �v�ʑ�No �̎擾
            if (ansi_buff[6] == ' ')
                ansi_buff[6] = '0';
            cell_no = StrToIntDef(ansi_buff.substr(6, 2).c_str(), 0);
            if (cell_no < 1)    // �v�ʑ�No �� 1 �����Ȃ疳��
                continue;
            // �ő�v�ʑ�No
            if (cell_no > max_cell_no) max_cell_no = cell_no;

            // �d�ʂ��擾���A�v�ʑ�No �ƕR�t��
            std::string weight_buff = ansi_buff.substr(9, 7).c_str();
            for (unsigned int i = 0; i < weight_buff.size(); i++)
                if (weight_buff[i] == ' ')
                    weight_buff[i] = '0';

            try{
                weight = Currency(weight_buff.c_str());
            }catch(...){
                continue;
            }
            cells[cell_no] = weight;
//          ofs << cell_no << ", " << weight_buff.c_str() << std::endl;

            // ����ꂽ�f�[�^�̌v�ʑ�No ������܂łōő�̂��̂ł���΁A
            // �����܂ł̃f�[�^�����Z���A���M

            if (cell_no != max_cell_no)
                continue;

            weight_.status = WIWeight::wiStable;
            weight_.weight = 0;
            for (Cells::iterator i = cells.begin(); i != cells.end(); i++)
                weight_.weight += i->second;

            SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);
        }
    }

    CloseHandle(o_event.hEvent);
    CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
