//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "N95ExportThread.h"
#pragma package(smart_init)
#include "CComm.h"
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
//      void __fastcall TN95ExportThread::UpdateCaption()
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
			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"�V���A���|�[�g�̃I�[�v���Ɏ��s���܂���");
			PostMessage(owner_, BM_ABORTED, 0, 0);
			return;
		}
		if (!comm.SetupComm(def_.c_str())){
			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"�V���A���f�o�C�X�̏������Ɏ��s���܂���");
			PostMessage(owner_, BM_ABORTED, 0, 0);
			return;
		}
	}catch(CComm::CommCtrlException& e){
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)AnsiString(AnsiString("�V���A���f�o�C�X�G���[ - ") + e.GetMessage()).c_str());
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
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ���M...");
		if (!comm.SendChar(ENQ))
			throw Exception("ENQ�̑��M�Ɏ��s���܂���");

        //Sleep(200);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK��M...");
		if (!comm.WaitChar(ACK, TIMEOUT))
			throw Exception("ACK����M�ł��܂���");

		while(1){
            //Sleep(200);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"�R�}���h���M...");
			if (comm.WaitWrite(command_.c_str(), TIMEOUT) != (DWORD)command_.Length())
				throw Exception("�R�}���h�e�L�X�g�̑��M�Ɏ��s���܂���");

            //Sleep(200);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK��M...");
			ch = comm.ReceiveChar(TIMEOUT);
			if (ch == (short)ACK){
				break;
			}else if (ch == (short)NAK)
				continue;
			else
				throw Exception("ACK����M�ł��܂���");
			////Sleep(200);
		}

        //Sleep(200);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT���M...");
		if (!comm.SendChar(EOT))
			throw Exception("EOT�̑��M�Ɏ��s���܂���");

        ///////////////////////////////////////////////////// �� �R�}���h���M�t���[
        ///////////////////////////////////////////////////// �� �f�[�^���M�t���[

        AnsiString buff;
        for (unsigned i = 0; i < records_.size(); i++){
            buff = records_[i];

            Sleep(150);

    		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ���M...");
    		if (!comm.SendChar(ENQ))
    			throw Exception("ENQ�̑��M�Ɏ��s���܂���");

            //OutputDebugString("P1. Send ENQ");

    		PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

            //Sleep(200);

    		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK��M...");
    		if (!comm.WaitChar(ACK, TIMEOUT)){
                OutputDebugString("P2. ERR");
    			throw Exception("ACK����M�ł��܂���");
            }

            //OutputDebugString("P2. Recv ACK");

    		PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

    		while(1){
                //Sleep(200);

    			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"�f�[�^���M...");
    			if (comm.WaitWrite((LPBYTE)(buff.c_str()), 129, TIMEOUT) != (DWORD)buff.Length()){
                    int len = buff.Length();
                    len++; len--;
    				throw Exception("�R�}���h�e�L�X�g�̑��M�Ɏ��s���܂���");
                }

                //OutputDebugString("P3-1. Send DATA");

                //Sleep(200);

    			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK��M...");
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
    				throw Exception("ACK����M�ł��܂���");
                }
    			////Sleep(200);
	    	}

            if (i != records_.size() -1)
    			SendMessage(owner_, BM_DATASENDED, 0, i + 1);
            
    		PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

            //OutputDebugString("P3. DATA SEND END");

            //Sleep(200);

    		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT���M...");
	    	if (!comm.SendChar(EOT))
    			throw Exception("EOT�̑��M�Ɏ��s���܂���");

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
