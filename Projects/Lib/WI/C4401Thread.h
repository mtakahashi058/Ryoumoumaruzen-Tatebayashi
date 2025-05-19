//---------------------------------------------------------------------------

#ifndef C4401ThreadH
#define C4401ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// C4401 thread
class TC4401Thread : public TThread
{
private:
protected:
	void __fastcall Execute();
	bool __fastcall formatMessage(std::string& msg);
	const WICommInfo info_;
	WICommStatus status_;
	WIWeight weight_;
public:
	__fastcall TC4401Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
