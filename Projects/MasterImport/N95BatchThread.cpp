//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "N95BatchThread.h"
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
//      void __fastcall TN95BatchThread::UpdateCaption()
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
__fastcall TN95BatchThread::TN95BatchThread(bool CreateSuspended, int port, const AnsiString& def, HWND owner)
    : TThread(CreateSuspended), port_(port), def_(def), owner_(owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TN95BatchThread::Execute()
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
	char cmd[] = "\x02SEN CHIT      \x03m";
	short ch;
	char buff[131];
	int i = 0;
	int receive_cnt = 0;	// ��M����
	//int n95_cnt;		// �w���v���ł̑��M����

	try{
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ���M...");
		if (!comm.SendChar(ENQ))
			throw Exception("ENQ�̑��M�Ɏ��s���܂���");

        Sleep(100);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK��M...");
		if (!comm.WaitChar(ACK, TIMEOUT))
			throw Exception("ACK����M�ł��܂���");

		while(1){
            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"�R�}���h���M...");
			if (comm.WaitWrite(cmd, TIMEOUT) != (DWORD)lstrlen(cmd))
				throw Exception("�R�}���h�e�L�X�g�̑��M�Ɏ��s���܂���");

            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK��M...");
			ch = comm.ReceiveChar(TIMEOUT);
			if (ch == (short)ACK){
				break;
			}else if (ch == (short)NAK)
				continue;
			else
				throw Exception("ACK����M�ł��܂���");
			//Sleep(100);
		}

        Sleep(100);

		SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT���M...");
		if (!comm.SendChar(EOT))
			throw Exception("EOT�̑��M�Ɏ��s���܂���");

		while (!Terminated){
            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ENQ��M...");
			if (!comm.WaitChar(ENQ, TIMEOUT))
				throw Exception("ENQ�̎�M�Ɏ��s���܂���");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

            Sleep(100);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK���M...");
			if (!comm.SendChar(ACK))
				throw Exception("ACK�̑��M�Ɏ��s���܂���");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"�f�[�^��M...");
			while(1){
                Sleep(100);

                ZeroMemory(buff, sizeof(buff));

				if (comm.WaitRead(buff, 129) == 129)
					break;
				i++;
				if (!comm.SendChar(NAK))
					throw Exception("NAK�̑��M�Ɏ��s���܂���");
				if (i >= RETRY)
					throw Exception("�f�[�^�̎�M�Ɏ��s���܂���");
				Sleep(100);
			}
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			i = 0;

			buff[127] = '\0';

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"ACK���M...");
			if (!comm.SendChar(ACK))
				throw Exception("ACK�̑��M�Ɏ��s���܂���");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			SendMessage(owner_, BM_STATUS, 0, (LPARAM)"EOT��M...");
			if (!comm.WaitChar(EOT, TIMEOUT))
				throw Exception("EOT�̎�M�Ɏ��s���܂���");
			PostMessage(owner_, BM_PROCESS_STEP, 0, 0);

			if (buff[2] == 'E' && buff[3] == 'N' && buff[4] == 'D'){
				// n95_cnt = satoi(&buff[11]);
				break;
			}

			SendMessage(owner_, BM_DATARECEIVED, 0, (LPARAM)buff);
			receive_cnt++;
			Sleep(100);
		}
	}catch(Exception& e){
        comm.Close();
		SendMessage(owner_, BM_STATUS, 0, (LPARAM)e.Message.c_str());
		PostMessage(owner_, BM_ABORTED, 0, 0);
		return;
	}
	PostMessage(owner_, BM_COMPLETED, 0, 0);
}
//---------------------------------------------------------------------------
