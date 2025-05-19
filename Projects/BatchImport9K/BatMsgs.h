/** BatMsgs.h
 *      バッチ取り込みスレッドで使用するメッセージ定義ヘッダ
 */

#ifndef BatMsgs_H_
#define BatMsgs_H_

#define BM_TOP              (WM_APP + 0x5ff)

#define BM_COMPLETED        (BM_TOP + 1)
// WPARAM:  none
// LPARAM:  none

#define BM_ABORTED          (BM_TOP + 2)
// WPARAM:  none
// LPARAM:  none

#define BM_STATUS           (BM_TOP + 3)
// WPARAM:  none
// LPARAM:  LPCSTR status

#define BM_DATARECEIVED     (BM_TOP + 4)
// WPARAM:  none
// LPARAM:  LPCSTR data

#define BM_PROCESS_STEP     (BM_TOP + 5)
// WPARAM:  none
// LPARAM:  none


#endif  // BatMsgs_H_
