//---------------------------------------------------------------------------

#ifndef F252ThreadH
#define F252ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// N9500/9500/AD4323 stream thread
class TF252Thread : public TThread
{            
private:
protected:
	void __fastcall Execute();
	bool __fastcall formatMessage(std::string& msg);
	const WICommInfo info_;
	WICommStatus status_;
	WIWeight weight_;
public:
	__fastcall TF252Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
