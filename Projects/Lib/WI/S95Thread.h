//---------------------------------------------------------------------------

#ifndef S95ThreadH
#define S95ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// N9500/9500/AD4323 stream thread
class TN95Thread : public TThread
{            
private:
protected:
	void __fastcall Execute();
	bool __fastcall formatMessage(std::string& msg);
	const WICommInfo info_;
	WICommStatus status_;
	WIWeight weight_;
public:
	__fastcall TN95Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
