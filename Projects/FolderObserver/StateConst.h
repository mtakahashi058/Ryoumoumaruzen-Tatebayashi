/** StateConst.h
 *      状態遷移のための定数定義
 *      アプリケーションごとに定義する必要がある
 */

#ifndef StateConst_H_
#define StateConst_H_

#include "NsDB.h"

#include <vector>

namespace State {
    enum StateID {
        Idle,                   /* 計量待機                  */
        WaitCard,               /* カード待ち                */
        InputCarNo,             /* 車番入力                  */

        SelectToku,             /* 得意先選択                */
        SelectItem1,            /* 項目1選択                 */
        SelectItem2,            /* 項目2選択                 */
        ConfirmFirstWeight,     /* 総重量確認                */

        SelectMeig,             /* 品目選択                  */
        ConfirmWeighing,        /* 計量確認                  */
        
		ConfirmContinuation,    /* 継続確認                  */
        ConfirmPrint,           /* 印字確認                  */
        
        WaitExit,               /* 降車待ち                  */

        Error,
        none = -1
        };
#if 0
    OLD:
    enum StateID {
        Idle,                   /* 計量待機                  */
        WaitCard,               /* カード待ち                */
        InputCarNo,             /* 車番入力                  */
        SelectItem1,            /* 項目1選択                 */
        SelectItem2,            /* 項目2選択                 */
        ConfirmFirstWeight,     /* 総重量確認                */

        SelectItem3,            /* 項目3選択                 */
        ConfirmWeighing,        /* 計量確認                  */

		ConfirmContinuation,    /* 継続確認                  */
        ConfirmPrint,           /* 印字確認                  */

        WaitExit,               /* 降車待ち                  */

        Error,
        none = -1
        };
#endif
}

namespace Event {
    // Event ID
    enum EventID {
        EnterWeighing,          /* 計量開始                  */
        ExitWeighing,           /* 計量終了                  */
        Card,                   /* RFID カード読み取り       */
        
		//CarNoInput,             /* 車番入力                  */
		//Item1Select,            /* 項目1選択                 */
        //Item2Select,            /* 項目2選択                 */
        
		//Confirm,                /* 確認                      */
		//Cancel,                 /* 取消                      */
		//Continue,               /* 継続                      */
		//Complete,               /* 完了                      */

        //Print,                  /* 印字                      */

        Error                   /* 内部: エラー通知          */
    };
}

namespace State {
	// State Event ID
	enum EventID {
		ForceWeighingEnabled,	/* 強制計量使用状態     */
		None
	};
};

class NsIni;
extern NsIni INI;

#endif  //StateConst_H_
