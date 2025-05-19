//---------------------------------------------------------------------------

#ifndef ioMirrorThreadH
#define ioMirrorThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "ioMirrorE3210.h"
//---------------------------------------------------------------------------
/** í êMópMessageID **/

#define DIOM_TOP        (WM_APP + 0x8f0)
#define DIOM_ABORTED	(DIOM_TOP + 0)
	/** Thread Abort Message
	  * <SEND> thread -> owner, [WPARAM: N/A], [LPARAM: N/A]
	  */
#define DIOM_STATUS     (DIOM_TOP + 1)
	/** Send Status Message
	  * <SEND> thread -> owner, [WPARAM: N/A], [LPARAM: LPCSTR status]
	  */
#define DIOM_INPUT      (DIOM_TOP + 2)
	/** Notify Input Value
	  * <SEND> thread -> owner, [WPARAM: N/A], [LPARAM: BYTE inputs]
	  */
#define DIOM_OUTPUT     (DIOM_TOP + 3)
	/** Output Value
	  * <POST> owner -> thread, [WPARAM: N/A], [LPARAM: BYTE outputs]
	  */
//---------------------------------------------------------------------------
class TioMirrorThread : public TThread
{
private:
protected:
	void __fastcall Execute();

	HWND owner_;
	AnsiString address_;

	ioMirrorE3210 IO_;
	Channels last_inputs_;

	void __fastcall OnIOInput(const Channels& channels);
	void __fastcall OnIOResponse(const AnsiString& message);
	void __fastcall OnIOError(const AnsiString& message);
public:
	__fastcall TioMirrorThread(bool CreateSuspended, HWND owner, const AnsiString& address);
};
//---------------------------------------------------------------------------
#endif
