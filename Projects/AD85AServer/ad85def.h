// common.h:	スレッド間通信及び受渡データ用ヘッダー

#ifndef _CommonH_
#define _CommonH_

#include <string>
#include <vector>

/** 通信用MessageID **/

#ifndef	AD85M_TOP
#define	AD85M_TOP			(WM_APP + 0x1FF)
#endif	//AD85M_TOP


#define UM_AD4385_ABORTED		(AD85M_TOP + 1)
/** UM_ABORTED		処理異常終了通知
  * WPARAM: unsigned int ThreadID
  * LPARAM: int tag
  * destination: MainForm
  */

#define UM_AD4385_COMMAND		(AD85M_TOP + 2)
/** UM_AD4385_COMMAND	AD4385コマンド通知
 *  WPARAM: AD4385Command command
 *  LPARAM: AD4385Params *params;
 */

/** AD4385 ステータスタイプ列挙型 **/
/** 注: AD4385.h内に定義されているE85Statusとは内部的に別であり
  * MainFormとのメッセージ通信に利用される
  */
enum AD4385Event{
	evCard,				/* カード挿入
						 *	PARAM: AD4385CardKeyInfo
						 */
	evCardReverse,		/* カード逆挿入 */
	evCardOut,			/* カード引き抜き */
	evPowerOn,			/* パワーオン（セルフテストOK） */
	evPowerNg,			/* パワーオン（セルフテストNG） */
	evPrinterAbnormal,	/* 印字不良 */
	evPaperExist,		/* 紙あり */
	evNoPaper,			/* 紙なし */
	evPrintAck,			/* 印字正常終了 */
	evKeiryo,			/* 計量開始 */
	evNm				/* 名称送信要求
						 *	PARAM: AD4385RequiredInfo
						 */
	};

/** AD4385 カード＆キー情報構造体(イベントパラメータ) **/
struct AD4385CardKeyInfo{
	struct CardInfo{
		std::string str_id;
		int item1;
		int item2;
		int item3;
		int item4;
	} card;
	struct KeyInfo{
		int id;
		int item1;
		int item2;
		int item3;
		int item4;
	} key;
};

/** AD4385 名称要求情報構造体(イベントパラメータ) **/
struct AD4385RequiredInfo{
	int item_no;
	int item_code;
	std::string reply;
};

/** AD4385 コマンドタイプ列挙型 **/
enum AD4385Command{
	cmRestart,		/* リスタートコマンド */
	cmLamp,			/* ランプ指定コマンド
				 *	PARAM: AD4385Lamp
				 */
	cmKey,			/* キーボード切替コマンド
				 *	PARAM: bool
				 */
	cmDisplay,		/* ディスプレイ切替コマンド
				 *	PARAM: bool
				 */
	cmWeight,		/* 重量値
				 *	PARAM: int(0～9999999)
				 */
	cmRelay,		/* リレーコマンド
				 *	PARAM: AD4385Relay
				 */
	cmPrint,		/* 印字コマンド
				 *	PARAM: Denpyou
				 */
				 
	cmPrint2,	 /* 印字コマンド
					PARAM: Denpyou2
				 */
	cmPrintMoveDot,		/* 印字ドット移動コマンド
				 *	PARAM: int(0～999)
				 */
	cmBeep,			/* BEEPコマンド
				 *	PARAM: int(0～99)
				 */
};

/** AD4385 ランプ指定情報(コマンドパラメータ) **/
struct AD4385Lamp{
	AD4385Lamp(){}
	AD4385Lamp(bool i, bool c, bool e)
		: insert(i), complete(c), error(e) {}
	bool insert;
	bool complete;
	bool error;
};

/** AD4385 リレー指定情報(コマンドパラメータ) **/
struct AD4385Relay{
	AD4385Relay(){}
	AD4385Relay(bool a, bool b)
		: channel_a(a), channel_b(b) {}
	bool channel_a;
	bool channel_b;
};

//////////////////////////////////////// インターフェース

/** 警告通知用構造体 **/
struct AD4385Warning{
	bool is_fatal;
	AnsiString message;
};

/** AD4385 情報構造体 **/
struct AD4385Status{
	AD4385Event event;
	AD4385CardKeyInfo card_key_info;
	AD4385RequiredInfo *required_info;
};

/** AD4385 初期設定 **/
struct AD4385StartInfo{
	int port;
	std::string def;
	HWND owner;
	int tag;
	int *display_weight;
	AD4385Warning *warning;
	AD4385Status *status;
	unsigned int *thread_id;
};

typedef std::vector<std::string> PrintImage;

/** AD4385 コマンドパラメータ管理構造体 **/
struct AD4385Params{
	AD4385Lamp lamp;
	bool key;
	bool display;
	int weight;
	AD4385Relay relay;
	int dot_size;
	int beep_len;
	PrintImage image;
};

#endif //_CommonH_
