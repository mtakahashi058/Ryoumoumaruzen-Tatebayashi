//---------------------------------------------------------------------------

#ifndef F720ThreadH
#define F720ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
// F720 thread
class TF720Thread : public TThread
{
private:
protected:
	void __fastcall Execute();
	bool __fastcall formatMessage(std::string& msg);
	const WICommInfo info_;
	WICommStatus status_;
	WIWeight weight_;
public:
	__fastcall TF720Thread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
