//---------------------------------------------------------------------------

#ifndef FbiDioThreadH
#define FbiDioThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "BitField.h"
#include "FbiDio.h"
//---------------------------------------------------------------------------
#define DIOM_TOP        (WM_APP + 0x8f0)
#define DIOM_STATUS     (DIOM_TOP + 1)
    /** Send Status Message
      * <SEND> thread -> owner, [WPARAM: N/A], [LPARAM: LPCSTR status]
      */
#define DIOM_INPUT      (DIOM_TOP + 3)
    /** Notify Input Value
      * <SEND> thread -> owner, [WPARAM: N/A], [LPARAM: WORD signaled]
      */
#define DIOM_OUTPUT     (DIOM_TOP + 4)
    /** Output Value
      * <POST> owner -> thread, [WPARAM: N/A], [LPARAM: Channels *channels]
      */
//---------------------------------------------------------------------------
class TFbiDioThread : public TThread
{            
private:
protected:
    void __fastcall Execute();
    HWND   owner_;
    HANDLE device_;
public:
    __fastcall TFbiDioThread(bool CreateSuspended, HWND owner, HANDLE device);
};
//---------------------------------------------------------------------------
#endif
