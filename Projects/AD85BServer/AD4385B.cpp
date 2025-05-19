/**
 * AD4385.cpp: A&D4385通信クラス
 *
 *				@author		大島晶博(ack)
 *				@history	@see AD4385.h
 */

#include <windows.h>
#include "AD4385B.h"

const int MAXBUFF = 150;
const int MAXTRY = 5;

AD4385B::AD4385B(char CNo){
	if (std::islower(CNo))	{
		lower_channel_ = CNo;
		upper_channel_ = std::toupper(CNo);
	}else{
		upper_channel_ = CNo;
		lower_channel_ = std::tolower(CNo);
	}
}

void AD4385B::setChannel(char CNo){
	if (islower(CNo)){
		lower_channel_ = CNo;
		upper_channel_ = (char)toupper(CNo);
	}else{
		upper_channel_ = CNo;
		lower_channel_ = (char)tolower(CNo);
	}
}

bool AD4385B::open(short Port, LPCSTR Def){
	if (!Comm.Open(Port, Def))
		return false;
	Comm.EscapeFunction(SETDTR);
	Comm.EscapeFunction(SETRTS);
	Comm.EscapeFunction(CLRBREAK);
	Comm.SetTimeout();
	return true;
}

// global
char lamp_buff[5];
bool AD4385B::setLamp(bool Insert, bool Complete, bool Error){
	//char lamp_buff[5];
	lamp_buff[0] = 'L';
	lamp_buff[1] = Insert ? '1' : '0';
	lamp_buff[2] = Complete ? '1' : '0';
	lamp_buff[3] = Error ? '1' : '0';
	lamp_buff[4] = '\0';
	return sendText(lamp_buff);
}

// global
char relay_buff[4];
bool AD4385B::setRelay(bool chA, bool chB){
	//char szBuff[4];
	relay_buff[0] = 'R';
	relay_buff[1] = chA ? '0' : '1';
	relay_buff[2] = chB ? '0' : '1';
	relay_buff[3] = '\0';
	return sendText(relay_buff);
}

bool AD4385B::setKey(bool On){
	if (On)
		return sendText("I");
	else
		return sendText("F");
}

bool AD4385B::setDisplay(bool On){
	//if (On)
	//	return sendText("V\x21");
	//else
	//	return sendText("V\x22");
}

bool AD4385B::clearDisplay(){
	if (!setCursorHome())
		return false;
	//if (!sendText("V              "))
	//	return false;
	return setCursorHome();
}

//global
char weight_buff[19];
bool AD4385B::displayWeight(LPCSTR Weight){
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


bool AD4385B::displayText(LPCSTR Text){
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

//global
char beep_buff[4];
bool AD4385B::beep(LPCSTR second){
	//char szBuff[4];
	beep_buff[0] = 'B';
	lstrcpyn(&beep_buff[1], second, 3);
	return sendText(beep_buff);
}

bool AD4385B::setTopMargin(int dot){
	char szBuff[5];
    wsprintf(szBuff, "D%03d", dot);
	return sendText(szBuff);
}

bool AD4385B::setTopMargin(int yohaku_dot, int nl_dot){
    char szBuff[8];
    wsprintf(szBuff, "D%03d%03d", yohaku_dot, nl_dot);
    return sendText(szBuff);
}

bool AD4385B::setMargin16(){
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
    return sendText(szBuff);
}

//global
char margin_buff[7];

bool AD4385B::setMargin16(int top_margin){
    //char szBuff[7];

    if (top_margin < 1){
        margin_buff[0] = 0x44;
        margin_buff[1] = 0x30;
        margin_buff[2] = 0x30;
        margin_buff[3] = 0x30;
        margin_buff[4] = 0x30;
        margin_buff[5] = 0x31;
        margin_buff[6] = 0x35;
    }else{
        margin_buff[0] = 0x44;
        margin_buff[1] = 0x30;
        margin_buff[2] = 0x30 + (top_margin / 10);
        margin_buff[3] = 0x30 + (top_margin % 10);
        margin_buff[4] = 0x30;
        margin_buff[5] = 0x31;
        margin_buff[6] = 0x35;
    }


    return sendText(margin_buff);
}

// 
bool AD4385B::printWideText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0f;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385B::printNL(){
    char szBuff[] = "P";
	bool res = sendText(szBuff);
	return res;
}

bool AD4385B::printText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 2];
	*pszBuff = 'P';
	lstrcpy(pszBuff + 1, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385B::print83WideText(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0f;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385B::print83Text(LPCSTR Text){
	char *pszBuff = new char[lstrlen(Text) + 3];
	*pszBuff = 'P';
	*(pszBuff + 1) = 0x0e;
	lstrcpy(pszBuff + 2, Text);
	bool res = sendText(pszBuff);
	delete [] pszBuff;
	return res;
}

bool AD4385B::moveDot(int n){
	char szBuff[10];
	wsprintf(szBuff, "%c%03d", 'D', n);
	return sendText(szBuff);
}

//global
char receive_buff[MAXBUFF + 1];
char rt_send_buff[4];
E85Status AD4385B::receiveText(LPSTR Dest){
	//char szBuff[MAXBUFF + 1];
	int ch;
	int i;
	

	rt_send_buff[0] = '@';
	rt_send_buff[1] = lower_channel_;
	rt_send_buff[2] = 0x05;
	rt_send_buff[3] = '\0';

	if (Comm.WaitWrite(rt_send_buff, 3) != 3)
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
		receive_buff[i] = (char)Comm.ReceiveChar();
		if (receive_buff[i] == ETX){
			receive_buff[i] = '\0';
			Comm.ReceiveChar(); // BCCの読み込み
			break;
		}
	}
	if (i == MAXBUFF)
		throw AD85Exception("受信バッファがいっぱいです in receiveText");
	if (Dest != NULL)
		lstrcpy(Dest, receive_buff);
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
	if (receive_buff[0] == 'C' && receive_buff[2] == 'D')
		return esCard;
	else if (receive_buff[0] == 'C' && receive_buff[2] == 'W')
		return esCardReverse;
	else if (receive_buff[0] == 'C' && receive_buff[2] == 'O')
		return esCardOut;
	else if (receive_buff[0] == 'S' && receive_buff[2] == 'O')
		return esPowerOn;
	else if (receive_buff[0] == 'S' && receive_buff[2] == 'N')
		return esPowerNg;
	else if (receive_buff[0] == 'P' && receive_buff[2] == 'T')
		return esPrinterAbnormal;
	else if (receive_buff[0] == 'P' && receive_buff[2] == 'N')
		return esPaperExist;
	else if (receive_buff[0] == 'P' && receive_buff[2] == 'E')
		return esNoPaper;
	else if (receive_buff[0] == 'P' && receive_buff[2] == 'A')
		return esPrintAck;
	else if (receive_buff[0] == 'K')
		return esKa;
	else if (receive_buff[0] == 'N')
		return esNm;
	else{
		//OutputDebugString(receive_buff);
		return esOther;
	}
}

//global
char send_buff[4];
bool AD4385B::sendText(LPSTR Src){
	int ch;
	//char szSendBuff[4];

	//OutputDebugString("送信処理開始");
	send_buff[0] = '@';
	send_buff[1] = upper_channel_;
	send_buff[2] = 0x05;
	send_buff[3] = '\0';

	Comm.FlushSendBuffers();
	Comm.Purge(PURGE_TXABORT | PURGE_TXCLEAR);
	Comm.WaitWrite(send_buff, 3);
	//{
	//	//throw AD85Exception("データ送信コマンドの送信に失敗しました");
	//	Comm.FlushSendBuffers();
	//	Comm.WaitWrite(send_buff, 3);
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

char AD4385B::calculateBCC(LPSTR Text){
	char bcc = 0x00;
	while (*Text != '\0')
		bcc ^= *Text++;
	return bcc;
}

//global
char dump_buff[3];
void AD4385B::dump(LPSTR Text){
	//char szBuff[3];
	while (*Text){
		wsprintf(dump_buff, "%02X", *Text++);
		//OutputDebugString(szBuff);
	}
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

