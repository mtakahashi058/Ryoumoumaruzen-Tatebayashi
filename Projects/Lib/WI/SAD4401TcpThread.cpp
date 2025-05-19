//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SAD4401TcpThread.h"
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
//      void __fastcall SAD4401TCPThread::UpdateCaption()
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

__fastcall SAD4401TCPThread::SAD4401TCPThread(bool CreateSuspended, const WITcpInfo& info)
    : TThread(CreateSuspended), info_(info),socket_(0)
{
}
//---------------------------------------------------------------------------
void __fastcall SAD4401TCPThread::OnSocketRead(const AnsiString& data)
{
    const char DELIMITER = '\r';
    const int  DATA_LEN = 17;

    unsigned int buff_size;

    buff_size = data.Length();
    std::string buff = data.c_str();

    if (buff_size > DATA_LEN){

        int idx = buff.rfind(DELIMITER);
        if (idx == std::string::npos){
            return;
        }

        if (idx < DATA_LEN -1){
            return;
        }

        buff = buff.substr((idx - DATA_LEN) + 1, DATA_LEN);

    }else if (buff_size < DATA_LEN){
        return;
    }

    if (buff[0] == 'S'){
        weight_.status = WIWeight::wiStable;
    }else if(buff[0] == 'U'){
        weight_.status = WIWeight::wiUnstable;
    }else if(buff[0] == 'O'){
        weight_.status = WIWeight::wiOverload;
    }else{
        return;
    }

    buff.erase(0, 6);
    buff.erase(8);

    try{

        if (weight_.status == WIWeight::wiOverload){
            weight_.weight = 0;
        }else{
            weight_.weight = Currency(buff.c_str());
        }

    }catch(...){
        return;
    }

    SendMessage(info_.owner, WIM_WEIGHT, ThreadID, (LPARAM)&weight_);
}
//---------------------------------------------------------------------------
void __fastcall SAD4401TCPThread::OnSocketError(const AnsiString& message)
{
    SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)"�d�ʒl�p�\�P�b�g�Ƃ̒ʐM���ؒf����܂���");
    PostMessage(info_.owner, WIM_ABORTED, ThreadID, 0);
    return;
}
//---------------------------------------------------------------------------
void __fastcall SAD4401TCPThread::Execute()
{
    MSG msg;


    try {

        socket_.SetHandler(OnSocketRead, OnSocketError);
        socket_.Open(info_.addr, info_.port);

    }catch(Exception& e){
        status_.is_fatal = true;
        status_.message = "�\�P�b�g�������Ɏ��s���܂���";
        SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        SendMessage(info_.owner, WIM_ABORTED, ThreadID, 0);
        return;
    }

    while(!Terminated) {

        if (Terminated){
            break;
        }

        if (!socket_.IsActive()){
            socket_.Reopen();
        }

        Sleep(200);

        if (socket_.WaitForData()){                      
            socket_.ReadCommand();
        }else{
            status_.is_fatal = true;
            status_.message = "�d�ʒl����M�ł��܂���";
            SendMessage(info_.owner, WIM_STATUS, ThreadID, (LPARAM)&status_);
        }

    }

    socket_.Close();
}
//---------------------------------------------------------------------------

