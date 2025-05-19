/////////////////////////////////////////////////////////////////////////////////
// CComm.cpp: �ʐM�|�[�g���䃉�b�p�[�N���X�C���v�������g		       //
//									       //
//			   <��Ж�>	 �j�b�R�[�\�t�g�E�F�A		       //
//			   <�쐬��>	 �哇����			       //
//			   <��	�l>	 �C�����𓙂̓w�b�_�[���Q�Ƃ̂���      //
/////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include "CComm.h"

/////////////////////////////////////////////////////////////////////////////////
// CComm::CComm - �R���X�g���N�^					       //
// �|�[�g�n���h���̏������ADCB�\���̂̃N���A�A				       //
// �G���[���b�Z�[�W�L���v�V�����̏�����					       //
/////////////////////////////////////////////////////////////////////////////////
CComm::CComm()
{
	Handle = INVALID_HANDLE_VALUE;
	ZeroMemory(&stDCB, sizeof(stDCB));
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::~CComm - �f�X�g���N�^						       //
// �|�[�g�n���h���̔p��							       //
/////////////////////////////////////////////////////////////////////////////////
CComm::~CComm()
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("Close����Ă��Ȃ��I�u�W�F�N�g���j������܂���",
			COMMERR_NOTCLOSE);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// �ʐM�|�[�g�̃I�[�v��							       //
// short nPort : �I�[�v������|�[�gID					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(short nPort)
{
	if (nPort < 1 || nPort > 9)
		throw CommCtrlException("�T�|�[�g����Ă��Ȃ��|�[�gID���w�肳��܂���",
			COMMERR_INVALIDID);
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͕��Ă��܂���", COMMERR_NOTCLOSE);
	char szPortName[5] = "COM";
	szPortName[3] = (char)(nPort + 0x30);
	szPortName[4] = '\0';
	Handle =  CreateFile(szPortName,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// �ʐM�|�[�g�̃I�[�v��							       //
// short nPort : �I�[�v������|�[�gID					       //
// LPSTR pDefString : �|�[�g�ݒ蕶����					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(short nPort, LPCSTR pDefString)
{
	if (nPort < 1 || nPort > 9)
		throw CommCtrlException("�T�|�[�g����Ă��Ȃ��|�[�gID���w�肳��܂���",
			COMMERR_INVALIDID);
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͕��Ă��܂���", COMMERR_NOTCLOSE);
	char szPortName[5] = "COM";
	szPortName[3] = (char)(nPort + 0x30);
	szPortName[4] = '\0';
	Handle =  CreateFile(szPortName,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	BuildCommDCB(pDefString, &stDCB);
	SetCommState(Handle, &stDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// �ʐM�|�[�g�̃I�[�v��							       //
// short nPort : �I�[�v������|�[�gID					       //
// DCB *pstDCB : �ݒ�pDCB�\���̂ւ̃|�C���^				       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(short nPort, DCB *pstDCB)
{
	if (nPort < 1 || nPort > 9)
		throw CommCtrlException("�T�|�[�g����Ă��Ȃ��|�[�gID���w�肳��܂���",
			COMMERR_INVALIDID);
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͕��Ă��܂���", COMMERR_NOTCLOSE);
	char szPortName[5] = "COM";
	szPortName[3] = (char)(nPort + 0x30);
	szPortName[4] = '\0';
	Handle =  CreateFile(szPortName,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	SetCommState(Handle, pstDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// �ʐM�|�[�g�̃I�[�v��							       //
// LPCSTR pPort : �I�[�v������|�[�g��					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(LPCSTR pPort)
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͕��Ă��܂���", COMMERR_NOTCLOSE);
	Handle =  CreateFile(pPort,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// �ʐM�|�[�g�̃I�[�v��							       //
// LPCSTR pPort : �I�[�v������|�[�g��					       //
// LPSTR pDefString : �|�[�g�ݒ蕶����					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(LPCSTR pPort, LPCSTR pDefString)
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͕��Ă��܂���", COMMERR_NOTCLOSE);
	Handle =  CreateFile(pPort,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	BuildCommDCB(pDefString, &stDCB);
	SetCommState(Handle, &stDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Open								       //
// �ʐM�|�[�g�̃I�[�v��							       //
// LPCSTR pPort : �I�[�v������|�[�g��					       //
// DCB *pstDCB : �ݒ�pDCB�\���̂ւ̃|�C���^				       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Open(LPCSTR pPort, DCB *pstDCB)
{
	if (Handle != INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͕��Ă��܂���", COMMERR_NOTCLOSE);
	Handle =  CreateFile(pPort,
		GENERIC_READ | GENERIC_WRITE,
		0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
		return false;
	SetCommState(Handle, pstDCB);
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Close								       //
// �ʐM�|�[�g�̃N���[�Y							       //
/////////////////////////////////////////////////////////////////////////////////
void CComm::Close()
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	CloseHandle(Handle);
	Handle = INVALID_HANDLE_VALUE;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SetupComm							       //
// �ʐM�|�[�g�̐ݒ�							       //
// DCB *pstDCB : �ݒ�pDCB�\���̂ւ̃|�C���^				       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SetupComm(DCB *pstDCB)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	stDCB = *pstDCB;
	return (bool)SetCommState(Handle, &stDCB);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SetupComm							       //
// �ʐM�|�[�g�̐ݒ�							       //
// LPSTR pDefString : �|�[�g�ݒ蕶����					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SetupComm(LPCSTR pDefString)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	BuildCommDCB(pDefString, &stDCB);
	return (bool)SetCommState(Handle, &stDCB);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::GetState							       //
// �ʐM�|�[�g�ݒ�̎擾							       //
// DCB *pstDCB : DCB�\���̂ւ̃|�C���^					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::GetState(DCB *pstDCB)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	return (bool)GetCommState(Handle, pstDCB);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitChar							       //
// �w�蕶���̎�M							       //
// char cChar : ��M����						       //
// DWORD dwTimeoutMSecond : ��M�^�C���A�E�g�l				       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::WaitChar(char cChar, DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	char szBuffer[2];
	bool IsSuccess;
	DWORD dwNum;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		szBuffer[0] = '\0';
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			return false;
		if (bTerminated)
			return false;
		IsSuccess = (bool)ReadFile(Handle, szBuffer, 1, &dwNum, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		if (dwNum != 1)
			continue;
		if (szBuffer[0] == cChar)
			return true;
	}
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitRead							       //
// �^�C���A�E�g�t����M							       //
// LPSTR pDest : ��M�f�[�^						       //
// DWORD dwLength : ��M��						       //
// DWORD dwTimeoutMSecond : ��M�^�C���A�E�g�l				       //
// DWORD : �ǂݍ��񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitRead(LPSTR pDest, DWORD dwLength, DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwLen = 0;
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)ReadFile(Handle, pDest + dwLen, dwLength - dwLen, &dwReadBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwLen += dwReadBytes;
		if (dwLen >= dwLength)
			return dwLen;
	}
	return dwLen;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitRead							       //
// �^�C���A�E�g�t����M							       //
// LPBYTE pDest : ��M�f�[�^						       //
// DWORD dwLength : ��M��						       //
// DWORD dwTimeoutMSecond : ��M�^�C���A�E�g�l				       //
// DWORD : �ǂݍ��񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitRead(LPBYTE pDest, DWORD dwLength, DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwLen = 0;
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)ReadFile(Handle, pDest + dwLen, dwLength - dwLen, &dwReadBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwLen += dwReadBytes;
		if (dwLen >= dwLength)
			return dwLen;
	}
	return dwLen;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Read								       //
// ��M									       //
// LPSTR pDest : ��M�f�[�^						       //
// DWORD dwLength : ��M��						       //
// DWORD : �ǂݍ��񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Read(LPSTR pDest, DWORD dwLength)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pDest, dwLength, &dwReadBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwReadBytes;
	}
	return dwReadBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Read								       //
// ��M									       //
// LPSTR pDest : ��M�f�[�^						       //
// DWORD dwLength : ��M��						       //
// DWORD : �ǂݍ��񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Read(LPBYTE pDest, DWORD dwLength)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pDest, dwLength, &dwReadBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwReadBytes;
	}
	return dwReadBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitWrite							       //
// �^�C���A�E�g�t�����M							       //
// LPSTR pDest : ���M�f�[�^						       //
// DWORD dwTimeoutMSecond : ���M�^�C���A�E�g�l				       //
// DWORD : �������񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitWrite(LPCSTR pSrc, DWORD dwTimeoutMSecond)
{
	COMSTAT stComst;
	DWORD dwLength = lstrlen(pSrc);
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwSize = 0;
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)WriteFile(Handle, pSrc + dwSize, dwLength - dwSize, &dwWriteBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwSize += dwWriteBytes;
		if (dwSize >= dwLength)
			return dwSize;
		ClearError(&stComst);
		while (stComst.cbOutQue != 0)
			FlushSendBuffers();
	}
	return dwSize;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WaitWrite							       //
// �^�C���A�E�g�t�����M							       //
// LPBYTE pDest : ���M�f�[�^						       //
// DWORD dwLength : ���M��						       //
// DWORD dwTimeoutMSecond : ���M�^�C���A�E�g�l				       //
// DWORD : �������񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::WaitWrite(LPBYTE pSrc, DWORD dwLength, DWORD dwTimeoutMSecond)
{
	COMSTAT stComst;
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	DWORD dwSize = 0;
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			break;
		if (bTerminated)
			break;
		IsSuccess = (bool)WriteFile(Handle, pSrc + dwSize, dwLength - dwSize, &dwWriteBytes, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		dwSize += dwWriteBytes;
		if (dwSize >= dwLength)
			return dwSize;
		ClearError(&stComst);
		while (stComst.cbOutQue != 0)
			FlushSendBuffers();
	}
	return dwSize;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Write								       //
// ���M									       //
// LPSTR pDest : ���M�f�[�^						       //
// DWORD : �������񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Write(LPCSTR pSrc)
{
	DWORD dwLength = lstrlen(pSrc);
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pSrc, dwLength, &dwWriteBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwWriteBytes;
	}
	return dwWriteBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Write								       //
// ���M									       //
// LPSTR pDest : ���M�f�[�^						       //
// DWORD dwLength : ���M��						       //
// DWORD : �������񂾒���						       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::Write(LPBYTE pSrc, DWORD dwLength)
{
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pSrc, dwLength, &dwWriteBytes, NULL);
	if (!IsSuccess)
	{
		ClearError();
		return dwWriteBytes;
	}
	return dwWriteBytes;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SetTimeout							       //
// ���[���x���^�C���A�E�g�̐ݒ�						       //
// COMMTIMEOUTS *pstTimeouts : COMMTIMEOUTS�\���̂ւ̃|�C���^		       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SetTimeout(COMMTIMEOUTS *pstTimeouts)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	if (pstTimeouts == NULL)
	{
		COMMTIMEOUTS stTimeouts;
		stTimeouts.ReadIntervalTimeout = MAXDWORD;
		stTimeouts.ReadTotalTimeoutMultiplier = 0;
		stTimeouts.ReadTotalTimeoutConstant = 0;
		stTimeouts.WriteTotalTimeoutMultiplier = 0;
		stTimeouts.WriteTotalTimeoutConstant = 0;
		return (bool)SetCommTimeouts(Handle, &stTimeouts);
	}
	return (bool)SetCommTimeouts(Handle, pstTimeouts);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::FlushSendBuffers						       //
// ���M�o�b�t�@�̃t���b�V��						       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::FlushSendBuffers()
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	return (bool)FlushFileBuffers(Handle);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::Purge								       //
// �o�b�t�@�̃N���A							       //
// DWORD dwAction : �N���A�̓��e					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::Purge(DWORD dwAction)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	return (bool)PurgeComm(Handle, dwAction);
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ClearError							       //
// �ʐM�G���[�̎擾�A�N���A						       //
// COMSTAT *pstComst : �ʐM��Ԃ��擾����COMSTAT�\���̂ւ̃|�C���^	       //
/////////////////////////////////////////////////////////////////////////////////
DWORD CComm::ClearError(COMSTAT *pstComst)
{
	DWORD dwErrors = 0;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	ClearCommError(Handle, &dwErrors, pstComst);
	if (dwErrors & CE_BREAK)
		throw CommCtrlException("�n�[�h�E�F�A���u���[�N���������o���܂���", COMMERR_BREAK);
	if (dwErrors & CE_FRAME)
		throw CommCtrlException("�n�[�h�E�F�A���t���[�~���O�G���[�����o���܂���", COMMERR_FRAME);
	if (dwErrors & CE_IOE)
		throw CommCtrlException("�f�o�C�X�Ƃ̒ʐM����I/O�G���[���������܂���", COMMERR_IOE);
	if (dwErrors & CE_MODE)
		throw CommCtrlException("�v�����ꂽ���[�h���T�|�[�g����Ă��Ȃ�����n���h���������ł�", COMMERR_MODE);
	if (dwErrors & CE_OOP)
		throw CommCtrlException("�p�������f�o�C�X���p���؂�ł��邱�Ƃ��x�����܂���", COMMERR_OOP);
	if (dwErrors & CE_OVERRUN)
		throw CommCtrlException("�����o�b�t�@�������ς��ł�", COMMERR_OVERRUN);
	if (dwErrors & CE_RXOVER)
		throw CommCtrlException("���̓o�b�t�@�̃I�[�o�[�t���[���������܂���", COMMERR_RXOVER);
	if (dwErrors & CE_RXPARITY)
		throw CommCtrlException("�n�[�h�E�F�A���p���e�B�[�G���[�����o���܂���", COMMERR_RXPARITY);
	if (dwErrors & CE_TXFULL)
		throw CommCtrlException("�o�̓o�b�t�@�������ς��ł�", COMMERR_TXFULL);
	if (dwErrors & CE_DNS)
		throw CommCtrlException("�p�������f�o�C�X���I������Ă��܂���", COMMERR_DNS);
	if (dwErrors & CE_PTO)
		throw CommCtrlException("�p�������f�o�C�X��Ń^�C���A�E�g�ɂȂ�܂���", COMMERR_PTO);
	return dwErrors;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ReceiveChar							       //
// �P�o�C�g��M								       //
// DWORD dwTimeoutMSecond : ��M�^�C���A�E�g�l				       //
// short : ���� ��M����, ���s -1					       //
/////////////////////////////////////////////////////////////////////////////////
short CComm::ReceiveChar(DWORD dwTimeoutMSecond)
{
	DWORD StartTime = GetTickCount();
	DWORD CurrentTime;
	char szBuffer[2];
	bool IsSuccess;
	DWORD dwNum;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	bTerminated = false;
	while (1)
	{
		CurrentTime = GetTickCount();
		if (int(CurrentTime - StartTime) > int(dwTimeoutMSecond))
			return -1;
		if (bTerminated)
			return -1;
		IsSuccess = (bool)ReadFile(Handle, szBuffer, 1, &dwNum, NULL);
		if (!IsSuccess)
		{
			ClearError();
			continue;
		}
		if (dwNum != 1)
			continue;
		return (short)szBuffer[0];
	}
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::SendChar							       //
// �w�蕶���̑��M							       //
// char ch : ���M����							       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::SendChar(char ch)
{
	char szTemp[1];
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	szTemp[0] = ch;
	IsSuccess = (bool)WriteFile(Handle, szTemp, 1, &dwWriteBytes, NULL);
	if (!IsSuccess || dwWriteBytes != 1)
	{
		ClearError();
		return false;
	}
	return true;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ReadWord							       //
// WORD����								       //
// WORD *pwDest : WORD��M�f�[�^					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::ReadWord(WORD *pwDest)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pwDest, 2, &dwReadBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwReadBytes == 2)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WriteWord							       //
// WORD�o��								       //
// WORD *pwDest : WORD���M�f�[�^					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::WriteWord(WORD *pwSrc)
{
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pwSrc, 2, &dwWriteBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwWriteBytes == 2)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::ReadDWord							       //
// DWORD����								       //
// DWORD *pdwDest : DWORD��M�f�[�^					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::ReadDWord(DWORD *pdwDest)
{
	DWORD dwReadBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)ReadFile(Handle, pdwDest, 4, &dwReadBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwReadBytes == 4)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::WriteDWord							       //
// DWORD�o��								       //
// DWORD *pdwDest : DWORD���M�f�[�^					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::WriteDWord(DWORD *pdwSrc)
{
	DWORD dwWriteBytes;
	bool IsSuccess;

	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	IsSuccess = (bool)WriteFile(Handle, pdwSrc, 4, &dwWriteBytes, NULL);
	if (!IsSuccess)
		ClearError();
	if (dwWriteBytes == 4)
		return true;
	return false;
}

/////////////////////////////////////////////////////////////////////////////////
// CComm::EscapeFunction						       //
// �g���@�\�̎��s							       //
// DWORD dwFunc : �g���@�\�R�[�h					       //
// bool : ���� true, ���s false						       //
/////////////////////////////////////////////////////////////////////////////////
bool CComm::EscapeFunction(DWORD dwFunc)
{
	if (Handle == INVALID_HANDLE_VALUE)
		throw CommCtrlException("�|�[�g�͊J���Ă��܂���", COMMERR_NOTOPEN);
	return (bool)EscapeCommFunction(Handle, dwFunc);
}
