//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CKLD2000Thread.h"
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
//  void __fastcall TCKLD2000Thread::UpdateCaption()
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
__fastcall TCKLD2000Thread::TCKLD2000Thread(bool CreateSuspended, const WICommInfo& info)
    : TThread(CreateSuspended), info_(info)
{
}
//---------------------------------------------------------------------------
bool __fastcall TCKLD2000Thread::formatMessage(std::string& msg)
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
void __fastcall TCKLD2000Thread::Execute()
{
    ackl::OverlappedComm comm_;

	const char DELIMITER = ETX;
	const int DELAY = 200;
    const int DATA_LEN = 18;
    const DWORD TIMEOUT = 3000;

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

        // CKLD2000�̐M��������ɖ�肪���邽�߁A�ȉ���ݒ�
        dcb.fOutxCtsFlow = false;
        dcb.fOutxDsrFlow = false;
        dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
        dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
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

    OVERLAPPED o_write;
    OVERLAPPED o_event;
    OVERLAPPED o_read;
    COMSTAT stat;
    DWORD event;
    DWORD transfer;
    DWORD error;
    DWORD size;
    DWORD sended_count;
    std::string buff;
	std::string err_buff;
	std::string weight_buff;
    bool cmd_sended = false;
    unsigned int buff_size;
	int space_pos;
	int idx;
	char command[] = "*OD*\r\n"; 			// ���Ӂj�@�^�[�~�l�[�^�͎w���v�ݒ�Ɉˑ�
	command[0] = STX;
	command[3] = ETX;

    ZeroMemory(&o_write, sizeof(OVERLAPPED));
    ZeroMemory(&o_event, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_write.hEvent = CreateEvent(0, true, false, 0);
    o_event.hEvent = CreateEvent(0, true, false, 0);
    o_read.hEvent = CreateEvent(0, true, false, 0);

    while (!Terminated){
        Sleep(DELAY);

        // �R�}���h�̑��M
        if (!cmd_sended){
			comm_.write(command, &size, &o_write);
            comm_.getOverlappedResult(&o_write, &transfer, true);
            if (transfer != lstrlen(command)){
                comm_.clearError(&error, &stat);
                err_buff.clear();
                comm_.formatMessage(error, err_buff);
                if (err_buff.empty()){
                    err_buff = "�R�}���h�̑��M�Ɏ��s���܂���";
                }
                status_.is_fatal = false;
                status_.message = err_buff.c_str();
                SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
                continue;
            }
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
            sended_count = GetTickCount();
            cmd_sended = true;
        }

        if (GetTickCount() - sended_count > TIMEOUT){
            status_.is_fatal = false;
            status_.message = "�ԓ��^�C���A�E�g";
            SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
            cmd_sended = false;
            comm_.purge();
            continue;
        }

        // �����������������ǂ���
        if (!comm_.getOverlappedResult(&o_event, &transfer, false))
            continue;

        cmd_sended = false;

        comm_.clearError(&error, &stat);
        err_buff.clear();
        if (comm_.formatMessage(error, err_buff)){
            status_.is_fatal = false;
            status_.message = err_buff.c_str();
            SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }
        if (stat.cbInQue < DATA_LEN)
            continue;

        comm_.read(buff, stat.cbInQue, &size, &o_read);
        comm_.getOverlappedResult(&o_read, &transfer, true);

		buff_size = buff.size();

		idx = buff.rfind(DELIMITER);
		if (idx == std::string::npos){
			continue;
		}

		if (idx < 17)
			continue;

		if (buff[1] == 'U')
			weight_.status = WIWeight::wiUnstable;
		else
			weight_.status = WIWeight::wiStable;

		weight_buff = buff.substr(6, 9);

		try{
			weight_.weight = Currency(weight_buff.c_str());
		}catch(...){
			continue;
		}

		SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);
	}

    CloseHandle(o_event.hEvent);
    CloseHandle(o_read.hEvent);
}
//---------------------------------------------------------------------------
