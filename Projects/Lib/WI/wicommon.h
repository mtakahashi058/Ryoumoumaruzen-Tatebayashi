// wicommon.h:	指示計統合インターフェース用ヘッダー

#ifndef _WICommonH_
#define _WICommonH_

#ifndef	WIM_TOP
#define	WIM_TOP			(WM_APP + 0xFF)
#endif	//WIM_TOP

/** 通信用MessageID **/

#define	WIM_STATUS		(WIM_TOP + 1)
/** WIM_STATUS		通信状態通知
 *  WPARAM: unsigned int thread_id
 *  LPARAM: WICommStatus *status
 *  destination: owner
 */

#define	WIM_ABORTED		(WIM_TOP + 2)
/** WIM_ABORTED		通信異常終了通知
 *  WPARAM: unsigned int thread_id
 *  LPARAM: none
 *  destination: owner
 */

#define	WIM_WEIGHT		(WIM_TOP + 3)
/** WIM_WEIGHT		重量通知
 *  WPARAM: unsigned int thread_id
 *  LPARAM: const WIWeight *weight
 *  destination: owner
 */

#define WIM_ZEROSET		(WIM_TOP + 4)
/** WIM_ZEROSET		ゼロ設定命令
 *	WPARAM: none
 *	LPARAM: none
 *	destination: thread
 */

#define WIM_CANCELZERO		(WIM_TOP + 5)
/** WIM_CANCELZERO	ゼロ設定キャンセル命令
 *	WPARAM: none
 *	LPARAM: none
 *	destination: thread
 */

/** データ交換用構造体定義 **/

/** ステータス通知構造体 **/
struct WICommStatus{
	bool is_fatal;
	AnsiString message;
};

/** 重量通知構造体 **/
struct WIWeight{
	enum {wiStable, wiUnstable, wiOverload} status;
	Currency weight;
};

/** 通信設定構造体 **/
struct WICommInfo{
	int port;
	AnsiString def;
	HANDLE owner;
};

/** SocketClient用構造体 **/
struct WITcpInfo{
    AnsiString addr;
    int port;
    HANDLE owner;
};

#endif //_WICommonH_
