/**
 * AD4385.h: A&D4385�ʐM�N���X�w�b�_�[
 *
 *	@author		�哇����(ack, akio)
 *	@history	2002/09/24 create
 *			2002/10/04 modify(compile throw)
 *
 *	@description
 *	[eod]
 */

#ifndef _AD4385H_
#define _AD4385H_

#include "CComm.h"
#include <stdexcept>

// AD4385�ʐM������O�N���X
class AD85Exception : public std::runtime_error{
public:
	explicit AD85Exception(const std::string& what_arg) : std::runtime_error(what_arg){}
};

// 4385���瑗�M�����X�e�[�^�X���̒�`
enum E85Status {
	esCard,			/* �J�[�h�}�� */
	esCardReverse,		/* �J�[�h�t�}�� */
	esCardOut,		/* �J�[�h�������� */
	esPowerOn,		/* �p���[�I���i�Z���t�e�X�gOK�j */
	esPowerNg,		/* �p���[�I���i�Z���t�e�X�gNG�j */
	esPrinterAbnormal,	/* �󎚕s�� */
	esPaperExist,		/* ������ */
	esNoPaper,		/* ���Ȃ� */
	esPrintAck,		/* �󎚐���I�� */
	esEos,	  		/* �X�e�[�^�X���M�I�� */
	esOther,		/* ����`�̃X�e�[�^�X */
	esKa,			/* �v�ʊJ�n�v�� */
	esNm,			/* ���̑��M�v�� */
	};

class AD4385{
public:

	AD4385(char CNo = 'A');
	~AD4385() {if (Comm.IsOpened()) Comm.Close();}
	void setChannel(char CNo);
	bool open(short Port = 1, LPCSTR Def = "9600,E,8,1");
	void close() {try{Comm.Close();}catch(...){}}

	bool restart() {return sendText("S");}
	bool setLamp(bool Insert = false, bool Complete = false, bool Error = false);
	bool setKey(bool On = true);
	bool setDisplay(bool On = true);
	bool setCursorHome()
		{return sendText("V\x23");}
	bool setCursorNext()
		{return sendText("V\x24");}
	bool setCursorBack()
		{return sendText("V\x25");}
	bool clearDisplay();
	bool displayWeight(LPCSTR Weight);
	bool displayText(LPCSTR Text);
	bool beep(LPCSTR second);
    bool setTopMargin(int dot);
	bool printWideText(LPCSTR Text);
	bool printNL();
	bool printText(LPCSTR Text);
	bool print83WideText(LPCSTR Text);
	bool print83Text(LPCSTR Text);
	bool moveDot(int n);
	bool setRelay(bool chA = false, bool chB = false);

	E85Status receiveText(LPSTR Dest);
	CComm Comm;
private:
	bool sendText(LPSTR Src);
	char calculateBCC(LPSTR Text);
	char upper_channel_;
	char lower_channel_;
	void dump(LPSTR Text);
};

class AD4385Ptr{
public:

	AD4385Ptr(char CNo = 'A');
	~AD4385Ptr() {}
	void setChannel(char CNo);

	bool restart() {return sendText("S");}
	bool setLamp(bool Insert = false, bool Complete = false, bool Error = false);
	bool setKey(bool On = true);
	bool setDisplay(bool On = true);
	bool setCursorHome()
		{return sendText("V\x23");}
	bool setCursorNext()
		{return sendText("V\x24");}
	bool setCursorBack()
		{return sendText("V\x25");}
	bool clearDisplay();
	bool displayWeight(LPCSTR Weight);
	bool displayText(LPCSTR Text);
	bool beep(LPCSTR second);
	bool printWideText(LPCSTR Text);
	bool printText(LPCSTR Text);
	bool print83WideText(LPCSTR Text);
	bool print83Text(LPCSTR Text);
	bool moveDot(int n);
	bool setRelay(bool chA = false, bool chB = false);

	E85Status receiveText(LPSTR Dest);
	CComm *Comm;
private:
	bool sendText(LPSTR Src);
	char calculateBCC(LPSTR Text);
	char upper_channel_;
	char lower_channel_;
	void dump(LPSTR Text);
};

#endif	//_AD4385H_
