//---------------------------------------------------------------------------

#ifndef NP3411ThreadH
#define NP3411ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "ocomm.h"
#include <vector>
#include "DMFrm.h"
//---------------------------------------------------------------------------
/** 通信用MessageID **/

#ifndef	NIIM_TOP
#define	NIIM_TOP			(WM_APP + 0x7FF)
#endif	//NIIM_TOP


#define UM_NII_ABORTED		(NIIM_TOP + 1)
/** UM_NII_ABORTED		処理異常終了通知
  * WPARAM: unsigned int ThreadID
  * LPARAM: none
  * destination: Owner
  */

#define UM_NII_STATUS       (NIIM_TOP + 2)
/** UM_NII_STATUS       プリンタステータス通知
  * WPARAM: unsigned int ThreadID
  * LPARAM: NiiStatus *status
  * destination: Owner
  */

#define UM_NII_PRINT		(NIIM_TOP + 3)
/** UM_NII_PRINT	    印字命令
 *  WPARAM: int keiryo_id
 *  LPARAM: none
 *  destination: Thread
 */

 #define UM_NII_REBOOT       (NIIM_TOP + 4)
/** UM_NII_REBOOT       再起動通知
  * WPARAM: unsigned int ThreadID
  * LPARAM: none
  * destination: Owner
  */
//---------------------------------------------------------------------------
struct NiiStatus{
    NiiStatus() : comm_error(false), status(0) {}
    NiiStatus(bool error, int stat, const AnsiString& msg) : comm_error(error), status(stat), message(msg) {}
    NiiStatus(int stat) : comm_error(false), status(stat) {}
    bool comm_error;
    int status;
    AnsiString message;
};
typedef std::vector<std::string> LineBuff;

struct CfgInfo{
    AnsiString	customer;
    AnsiString items;
    AnsiString item1;
    AnsiString item2;
    bool	   use_toku;
    bool 	   use_items;
    bool	   use_item1;
    bool       use_item2;
};

//---------------------------------------------------------------------------
class TNP3411Thread : public TThread
{
private:
protected:
    void __fastcall Execute();
    int port_;
    AnsiString def_;
    HWND owner_;
	NiiStatus status_;
    CfgInfo   cfginfo_;
    int copy_;

	void __fastcall CreatePrintImage(int keiryo_id, int copy_no, LineBuff& line_buff);
    void __fastcall SetPrintImage(NsRecordSet set,NsRecordSet print_set, int copy_no, LineBuff& line_buff);
    //void __fastcall CreatePrintImage(NsRecordSet tmp_set, int copy_no, LineBuff& line_buff);
public:
	__fastcall TNP3411Thread(bool CreateSuspended, int port, const AnsiString& def, HWND owner, const CfgInfo& info, int copy = 1);
};
//---------------------------------------------------------------------------
#endif
