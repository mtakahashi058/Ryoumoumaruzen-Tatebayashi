/**
 * AD4385.cpp: A&D4385通信クラス
 *
 *				@author		大島晶博(ack)
 *				@history	@see AD4385.h
 */

#include <windows.h>
#include "AD4385.h"

const int MAXBUFF = 150;
const int MAXTRY = 5;

AD4385::AD4385(char CNo){
	if (std::islower(CNo))	{
		lower_channel_ = CNo;
		upper_channel_ = std::toupper(CNo);
	}else{
		upper_channel_ = CNo;
		lower_channel_ = std::tolower(CNo);
	}
}

void AD4385::setChannel(char CNo){
	if (islower(CNo)){
		lower_channel_ = CNo;
		upper_channel_ = (char)toupper(CNo);
	}else{
		upper_channel_ = CNo;
		lower_channel_ = (char)tolower(CNo);
	}
}

bool AD4385::open(short Port, LPCSTR Def){
	if (!Comm.Open(Port, Def))
		return false;
	Comm.EscapeFunction(SETDTR);
	Comm.EscapeFunction(SETRTS);
	Comm.EscapeFunction(CLRBREAK);
	Comm.SetTimeout();
	return true;
}

bool AD4385::setLamp(bool Insert, bool Complete, bool Error){
	char szBuff[5];
	szBuff[0] = 'L';
	szBuff[1] = Insert ? '1' : '0';
	szBuff[2] = Complete ? '1' : '0';
	szBuff[3] = Error ? '1' : '0';
	szBuff[4] = '\0';
	return sendText(szBuff);
}

bool AD4385::setRelay(bool chA, bool chB){
	char szBuff[4];
	szBuff[0] = 'R';
	szBuff[1] = chA ? '0' : '1';
	szBuff[2] = chB ? '0' : '1';
	szBuff[3] = '\0';
	return sendText(szBuff);
}

bool AD4385::setKey(bool On){
	if (On)
		return sendText("I");
	else
		return sendText("F");
}

bool AD4385::setDisplay(bool On){
	//if (On)
	//	return sendText("V\x21");
	//else
	//	return sendText("V\x22");
}

bool AD4385::clearDisplay(){
	if (!setCursorHome())
		return false;
	//if (!sendText("V              "))
	//	return false;
	return setCursorHome();
}

bool AD4385::displayWeight(LPCSTR Weight){
	//Weightは0x30～0x39の7バイトまでの文字列
	char szText[19] = "";
    char c_front[19];
    char c_weight[6];
	int Length = lstrlen(Weight);
	int SpCnt = 7 - Length;
	int i;

	if (!setCursorHome())
		return false;
	c_front[0] = 'E';
    c_front[1] = 'S';
    c_front[2] = 'T';
    c_front[3] = ',';
    c_front[4] = 'G';
    c_front[5] = 'S';
    c_front[6] = ',';

    int i_weight = std::atoi(Weight);

    // 重量の符号
    if (i_weight >= 0){
        c_front[7] = '+';
    } else {
        c_front[7] = '-';
    }

    c_front[8] = ' ';

    wsprintf(c_weight, "%6d", std::abs(i_weight));

    std::strcat(c_front, c_weight);
    std::strcat(szText, c_front);
    szText[15] = 'k';
    szText[16] = 'g';
    szText[17] = '\r';
    szText[18] = '\n';

	return sendText(szText);
}

bool AD4385::displayText(LPCSTR Text){
	bool ret;
	char *pszText = new char[lstrlen(Text) + 2];

	if (!setCursorHome()){
    	delete[] pszText;
		return false;
    }
	pszText[0] = 'N';
	lstrcpy(&(pszText[1]), Text);
	ret = sendText(pszText);
	delete[] pszText;
	return ret;
}

bool AD4385::beep(LPCSTR second){
	char szBuff[4];
	szBuff[0] = 'B';
	lstrcpyn(&szBuff[1], second, 3);
	return sendText(szBuff);
}

bool AD4385::setTopMargin(int dot){
	char szBuff[5];
    wsprintf(szBuff, "D%03d", dot);
	return sendText(szBuff);
}

bool AD4385::setTopMargin(int yohaku_dot, int nl_dot){
    char szBuff[8];
    wsprintf(szBuff, "D%03d%03d", yohaku_dot, nl_dot);
    return sendText(szBuff);
}

bool AD4385::setMargin16(){
    char szBuff[7];

    szBuff[0] = 0x44;
    szBuff[1] = 0x30;
    //szBuff[1] = 0x2d;
    szBuff[2] = 0x30;
    //szBuff[2] = 0x31;
    szBuff[3] = 0x30;
    szBuff[4] = 0x30;
    szBuff[5] = 0x31;
    szBuff[6] = 0x35;
/*
    szBuff[0] = 0x44;
    szBuff[1] = 0x30;
    szBuff[2] = 0x30;
    szBuff[3] = 0x35;
    szBuff[4] = 0x30;
    szBuff[5] = 0x31;
    szBuff[6] = 0x35;
*/
    return sendText(szBuff);
}

bool AD4385::printWideText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0f;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385::printNL(){
    char szBuff[] = "P";
	bool res = sendText(szBuff);
	return res;
}

bool AD4385::printText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 2];
	*pszBuff = 'P';
	lstrcpy(pszBuff + 1, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385::print83WideText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0f;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385::print83Text(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0e;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385::moveDot(int n){
	char szBuff[10];
	wsprintf(szBuff, "%c%03d", 'D', n);
	return sendText(szBuff);
}

E85Status AD4385::receiveText(LPSTR Dest){
	char szBuff[MAXBUFF + 1];
	int ch;
	int i;
	char szSendBuff[4];

	szSendBuff[0] = '@';
	szSendBuff[1] = lower_channel_;
	szSendBuff[2] = 0x05;
	szSendBuff[3] = '\0';

	if (Comm.WaitWrite(szSendBuff, 3) != 3)
		throw AD85Exception("データ要求コマンドの送信に失敗しました in receiveText");
	//OutputDebugString("コマンド送信");

	ch = Comm.ReceiveChar();
	if (ch == EOT){
		Comm.SendChar(EOT);
		return esEos;
	}else if (ch == NAK){
		Comm.SendChar(EOT);
		throw AD85Exception("NAKを受信しました in receiveText");
	}else if (ch != STX){
		throw AD85Exception("STX、ETXの受信に失敗しました in receiveText");
	}
	//OutputDebugString("STX受信");
	for (i = 0; i < MAXBUFF; i++){
		szBuff[i] = (char)Comm.ReceiveChar();
		if (szBuff[i] == ETX){
			szBuff[i] = '\0';
			Comm.ReceiveChar(); // BCCの読み込み
			break;
		}
	}
	if (i == MAXBUFF)
		throw AD85Exception("受信バッファがいっぱいです in receiveText");
	if (Dest != NULL)
		lstrcpy(Dest, szBuff);
	//OutputDebugString("テキスト受信");
	if (!Comm.SendChar(ACK))
		throw AD85Exception("ACKの送信に失敗しました in receiveText");
	//OutputDebugString("ACK送信");
	ch = Comm.ReceiveChar();
	if (ch != EOT){
		char debug[50];
		wsprintf(debug, "EOT受信時に入ってきた文字 : %02X", ch);
		//OutputDebugString(debug);
		Comm.SendChar(ACK);
		ch = Comm.ReceiveChar();
		if (ch != EOT){
			char debug[50];
			wsprintf(debug, "２回目EOT受信時に入ってきた文字 : %02X", ch);
			//OutputDebugString(debug);
			throw AD85Exception("EOTが受信できません in receiveText");
		}
	}
	//OutputDebugString("EOT受信");
	//OutputDebugString("受信終了");
	if (szBuff[0] == 'C' && szBuff[2] == 'D')
		return esCard;
	else if (szBuff[0] == 'C' && szBuff[2] == 'W')
		return esCardReverse;
	else if (szBuff[0] == 'C' && szBuff[2] == 'O')
		return esCardOut;
	else if (szBuff[0] == 'S' && szBuff[2] == 'O')
		return esPowerOn;
	else if (szBuff[0] == 'S' && szBuff[2] == 'N')
		return esPowerNg;
	else if (szBuff[0] == 'P' && szBuff[2] == 'T')
		return esPrinterAbnormal;
	else if (szBuff[0] == 'P' && szBuff[2] == 'N')
		return esPaperExist;
	else if (szBuff[0] == 'P' && szBuff[2] == 'E')
		return esNoPaper;
	else if (szBuff[0] == 'P' && szBuff[2] == 'A')
		return esPrintAck;
	else if (szBuff[0] == 'K')
		return esKa;
	else if (szBuff[0] == 'N')
		return esNm;
	else{
		//OutputDebugString(szBuff);
		return esOther;
	}
}

bool AD4385::sendText(LPSTR Src){
	int ch;
	char szSendBuff[4];

	//OutputDebugString("送信処理開始");
	szSendBuff[0] = '@';
	szSendBuff[1] = upper_channel_;
	szSendBuff[2] = 0x05;
	szSendBuff[3] = '\0';

	Comm.FlushSendBuffers();
	Comm.Purge(PURGE_TXABORT | PURGE_TXCLEAR);
	Comm.WaitWrite(szSendBuff, 3);
	//{
	//	//throw AD85Exception("データ送信コマンドの送信に失敗しました");
	//	Comm.FlushSendBuffers();
	//	Comm.WaitWrite(szSendBuff, 3);
	//}
	//OutputDebugString("コマンド送信");
	ch = Comm.ReceiveChar();
	if (ch == NAK){
		return false;
	}else if (ch == -1){
		throw AD85Exception("文字を受信できませんでした in sendText");
    }else if (ch == EOT){
        Sleep(500);
        return false;
		//throw AD85Exception("EOTを受信しました in sendText");
	}else if (ch != ACK){
		throw AD85Exception("ACK、NAK以外の文字を受信しました in sendText");
	}
	//OutputDebugString("ACK受信");

    char str = Src[0];

    if (str == 'E'){
        std::string word = Src;
        word = word.substr(0, 18);
        strcpy(Src, word.c_str());
    }

	int Length = lstrlen(Src);
	char *SendText = new char[Length + 4];
	SendText[0] = 0x02;
	lstrcpy(SendText + 1, Src);
	SendText[Length + 1] = 0x03;
	SendText[Length + 2] = '\0';
	SendText[Length + 2] = calculateBCC(SendText + 1);
	SendText[Length + 3] = '\0';

//
	if (SendText[2] == 0x21)
		SendText[Length + 2] = 0x74;
	else if (SendText[2] == 0x23)
		SendText[Length + 2] = 0x76;
	//Dump(SendText);
//

	for (int i = 0; i < MAXTRY; i++){
		Comm.WaitWrite((LPBYTE)SendText, Length + 3, 3000);
		//OutputDebugString("テキスト送信");
		Sleep(100);
		ch = Comm.ReceiveChar();
		if (ch == ACK){
			Comm.SendChar(EOT);
			delete [] SendText;
			return true;
		}
		Comm.Purge();
	}
	throw AD85Exception("ACKを受信できませんでした in sendText");
	//return false;
}

char AD4385::calculateBCC(LPSTR Text){
	char bcc = 0x00;
	while (*Text != '\0')
		bcc ^= *Text++;
	return bcc;
}

void AD4385::dump(LPSTR Text){
	char szBuff[3];
	while (*Text){
		wsprintf(szBuff, "%02X", *Text++);
		//OutputDebugString(szBuff);
	}
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

AD4385Ptr::AD4385Ptr(char CNo){
	if (std::islower(CNo))	{
		lower_channel_ = CNo;
		upper_channel_ = std::toupper(CNo);
	}else{
		upper_channel_ = CNo;
		lower_channel_ = std::tolower(CNo);
	}
}

void AD4385Ptr::setChannel(char CNo){
	if (islower(CNo)){
		lower_channel_ = CNo;
		upper_channel_ = (char)toupper(CNo);
	}else{
		upper_channel_ = CNo;
		lower_channel_ = (char)tolower(CNo);
	}
}

bool AD4385Ptr::setLamp(bool Insert, bool Complete, bool Error){
	char szBuff[5];
	szBuff[0] = 'L';
	szBuff[1] = Insert ? '1' : '0';
	szBuff[2] = Complete ? '1' : '0';
	szBuff[3] = Error ? '1' : '0';
	szBuff[4] = '\0';
	return sendText(szBuff);
}

bool AD4385Ptr::setRelay(bool chA, bool chB){
	char szBuff[4];
	szBuff[0] = 'R';
	szBuff[1] = chA ? '0' : '1';
	szBuff[2] = chB ? '0' : '1';
	szBuff[3] = '\0';
	return sendText(szBuff);
}

bool AD4385Ptr::setKey(bool On){
	if (On)
		return sendText("I");
	else
		return sendText("F");
}

bool AD4385Ptr::setDisplay(bool On){
	if (On)
		return sendText("V\x21");
	else
		return sendText("V\x22");
}

bool AD4385Ptr::clearDisplay(){
	if (!setCursorHome())
		return false;
	if (!sendText("V              "))
		return false;
	return setCursorHome();
}

bool AD4385Ptr::displayWeight(LPCSTR Weight){
	//Weightは0x30～0x39の7バイトまでの文字列
	char szText[10];
	int Length = lstrlen(Weight);
	int SpCnt = 7 - Length;
	int i;

	if (!setCursorHome())
		return false;
	szText[0] = 'V';
	if (Length > 7)
		return false;
	for (i = 0; i < SpCnt; i++)
		szText[i + 1] = ' ';
	lstrcpy(&szText[i + 1], Weight);
	return sendText(szText);
}

bool AD4385Ptr::displayText(LPCSTR Text){
	bool ret;
	char *pszText = new char[lstrlen(Text) + 2];

	if (!setCursorHome())
		return false;
	pszText[0] = 'N';
	lstrcpy(&(pszText[1]), Text);
	ret = sendText(pszText);
	delete[] pszText;
	return ret;
}

bool AD4385Ptr::beep(LPCSTR second){
	char szBuff[4];
	szBuff[0] = 'B';
	lstrcpyn(&szBuff[1], second, 3);
	return sendText(szBuff);
}

bool AD4385Ptr::printWideText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0f;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385Ptr::printText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 2];
	*pszBuff = 'P';
	lstrcpy(pszBuff + 1, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385Ptr::print83WideText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0f;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385Ptr::print83Text(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0e;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385Ptr::moveDot(int n){
	char szBuff[10];
	wsprintf(szBuff, "%c%03d", 'D', n);
	return sendText(szBuff);
}

E85Status AD4385Ptr::receiveText(LPSTR Dest){
	char szBuff[MAXBUFF + 1];
	int ch;
	int i;
	char szSendBuff[4];

	//OutputDebugString("受信開始");

	szSendBuff[0] = '@';
	szSendBuff[1] = lower_channel_;
	szSendBuff[2] = 0x05;
	szSendBuff[3] = '\0';

	if (Comm->WaitWrite(szSendBuff, 3) != 3)
		throw AD85Exception("データ要求コマンドの送信に失敗しました in receiveText");
	//OutputDebugString("コマンド送信");

	ch = Comm->ReceiveChar();
	if (ch == EOT){
		Comm->SendChar(EOT);
		return esEos;
	}else if (ch == NAK){
		Comm->SendChar(EOT);
		throw AD85Exception("NAKを受信しました in receiveText");
	}else if (ch != STX){
		throw AD85Exception("STX、ETXの受信に失敗しました in receiveText");
	}
	//OutputDebugString("STX受信");
	for (i = 0; i < MAXBUFF; i++){
		szBuff[i] = (char)Comm->ReceiveChar();
		if (szBuff[i] == ETX){
			szBuff[i] = '\0';
			Comm->ReceiveChar(); // BCCの読み込み
			break;
		}
	}
	if (i == MAXBUFF)
		throw AD85Exception("受信バッファがいっぱいです in receiveText");
	if (Dest != NULL)
		lstrcpy(Dest, szBuff);
	//OutputDebugString("テキスト受信");
	if (!Comm->SendChar(ACK))
		throw AD85Exception("ACKの送信に失敗しました in receiveText");
	//OutputDebugString("ACK送信");
	ch = Comm->ReceiveChar();
	if (ch != EOT){
		char debug[50];
		wsprintf(debug, "EOT受信時に入ってきた文字 : %02X", ch);
		//OutputDebugString(debug);
		Comm->SendChar(ACK);
		ch = Comm->ReceiveChar();
		if (ch != EOT){
			char debug[50];
			wsprintf(debug, "２回目EOT受信時に入ってきた文字 : %02X", ch);
			//OutputDebugString(debug);
			throw AD85Exception("EOTが受信できません in receiveText");
		}
	}
	//OutputDebugString("EOT受信");
	//OutputDebugString("受信終了");
	if (szBuff[0] == 'C' && szBuff[2] == 'D')
		return esCard;
	else if (szBuff[0] == 'C' && szBuff[2] == 'W')
		return esCardReverse;
	else if (szBuff[0] == 'C' && szBuff[2] == 'O')
		return esCardOut;
	else if (szBuff[0] == 'S' && szBuff[2] == 'O')
		return esPowerOn;
	else if (szBuff[0] == 'S' && szBuff[2] == 'N')
		return esPowerNg;
	else if (szBuff[0] == 'P' && szBuff[2] == 'T')
		return esPrinterAbnormal;
	else if (szBuff[0] == 'P' && szBuff[2] == 'N')
		return esPaperExist;
	else if (szBuff[0] == 'P' && szBuff[2] == 'E')
		return esNoPaper;
	else if (szBuff[0] == 'P' && szBuff[2] == 'A')
		return esPrintAck;
	else if (szBuff[0] == 'K')
		return esKa;
	else if (szBuff[0] == 'N')
		return esNm;
	else{
		//OutputDebugString(szBuff);
		return esOther;
	}
}

bool AD4385Ptr::sendText(LPSTR Src){
	int ch;
	char szSendBuff[4];

	//OutputDebugString("送信処理開始");
	szSendBuff[0] = '@';
	szSendBuff[1] = upper_channel_;
	szSendBuff[2] = 0x05;
	szSendBuff[3] = '\0';

	Comm->FlushSendBuffers();
	Comm->Purge(PURGE_TXABORT | PURGE_TXCLEAR);
	Comm->WaitWrite(szSendBuff, 3);
	//{
	//	//throw AD85Exception("データ送信コマンドの送信に失敗しました");
	//	Comm->FlushSendBuffers();
	//	Comm->WaitWrite(szSendBuff, 3);
	//}
	//OutputDebugString("コマンド送信");
	ch = Comm->ReceiveChar();
	if (ch == NAK){
		return false;
	}else if (ch == -1){
		throw AD85Exception("文字を受信できませんでした in sendText");
	}else if (ch != ACK){
		throw AD85Exception("ACK、NAK以外の文字を受信しました in sendText");
	}
	//OutputDebugString("ACK受信");

	int Length = lstrlen(Src);
	char *SendText = new char[Length + 4];
	SendText[0] = 0x02;
	lstrcpy(SendText + 1, Src);
	SendText[Length + 1] = 0x03;
	SendText[Length + 2] = '\0';
	SendText[Length + 2] = calculateBCC(SendText + 1);
	SendText[Length + 3] = '\0';

//
	if (SendText[2] == 0x21)
		SendText[Length + 2] = 0x74;
	else if (SendText[2] == 0x23)
		SendText[Length + 2] = 0x76;
	//Dump(SendText);
//

	for (int i = 0; i < MAXTRY; i++){
		Comm->WaitWrite((LPBYTE)SendText, Length + 3, 3000);
		//OutputDebugString("テキスト送信");
		Sleep(100);
		ch = Comm->ReceiveChar();
		if (ch == ACK){
			Comm->SendChar(EOT);
			delete [] SendText;
			return true;
		}
		Comm->Purge();
	}
	throw AD85Exception("ACKを受信できませんでした in sendText");
	//return false;
}


char AD4385Ptr::calculateBCC(LPSTR Text){
	char bcc = 0x00;
	while (*Text != '\0')
		bcc ^= *Text++;
	return bcc;
}

void AD4385Ptr::dump(LPSTR Text){
	char szBuff[3];
	while (*Text){
		wsprintf(szBuff, "%02X", *Text++);
		//OutputDebugString(szBuff);
	}
}

