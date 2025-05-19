//---------------------------------------------------------------------------

#ifndef CF701ThreadH
#define CF701ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// CF701 thread
class TCF701Thread : public TThread
{
private:
protected:
	void __fastcall Execute();
	bool __fastcall formatMessage(std::string& msg);
	const WICommInfo info_;
	WICommStatus status_;
	WIWeight weight_;
public:
	__fastcall TCF701Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
