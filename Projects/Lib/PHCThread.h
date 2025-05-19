//---------------------------------------------------------------------------
/**
 *  PATLITE PHC用thread
 */
//---------------------------------------------------------------------------
#ifndef PHCThreadH
#define PHCThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <set>
//---------------------------------------------------------------------------
/** TPHCThread の使用方法
  *
  * [全点ON]
  *     PHC_OCTET octet;
  *     octet.ch = 0xff;    // 全点
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)true, (LPARAM)octet.ch);
  *
  * [全点OFF]
  *     PHC_OCTET octet;
  *     octet.ch = 0xff;    // 全点
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)false, (LPARAM)octet.ch);
  *
  * [指定ON]
  *     PHC_OCTET octet;
  *     octet.ch = 0;
  *     octet << 0 << 2 << 3;       // 接点0, 2, 3 のみ指定
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)true, (LPARAM)octet.ch);
  *
  * [指定OFF]
  *     PHC_OCTET octet;
  *     octet.ch = 0;
  *     octet << 0 << 2 << 3;       // 接点0, 2, 3 のみ指定
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)false, (LPARAM)octet.ch);
  */
//---------------------------------------------------------------------------
#ifndef PHCM_TOP
#define PHCM_TOP        (WM_APP + 0x2FF)
#endif  //WIM_TOP

/** 通信用MessageID **/

#define PHCM_STATUS     (PHCM_TOP + 1)
/** PHCM_STATUS     通信状態通知
 *  WPARAM: unsigned int thread_id
 *  LPARAM: LPCSTR
 *  Thread -> Owner
 */

#define PHCM_ABORTED        (PHCM_TOP + 2)
/** PHCM_ABORTED    通信異常終了通知
 *  WPARAM: unsigned int thread_id
 *  LPARAM: none
 *  Thread -> Owner
 */

#define PHCM_COMMAND        (PHCM_TOP + 3)
/** PHCM_COMMAND    通信命令
 *  WPARAM: bool on
 *  LPARAM: char ch (cast to PHC_OCTET)
 *  Owner -> Thread
 */
struct PHCCommInfo{
    int port;
    AnsiString def;
    HANDLE owner;
};
//---------------------------------------------------------------------------
union PHC_OCTET{
    char ch;
    struct{
        char b0:1;
        char b1:1;
        char b2:1;
        char b3:1;
        char b4:1;
        char b5:1;
        char b6:1;
        char b7:1;
    } b;
};
PHC_OCTET& operator<<(PHC_OCTET& octet, int bit);
//---------------------------------------------------------------------------
class TPHCThread : public TThread
{
private:
    PHCCommInfo info_;
    std::string generateCommand(bool done, char ch);
protected:
    void __fastcall Execute();
public:
    __fastcall TPHCThread(bool CreateSuspended, const PHCCommInfo& info);
};
//---------------------------------------------------------------------------
#endif
