//---------------------------------------------------------------------------

#ifndef RoadMeterThreadH
#define RoadMeterThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include "ocomm.h"
#include "wicommon.h"
//---------------------------------------------------------------------------
class TRoadMeterThread : public TThread
{            
private:
protected:
	void __fastcall Execute();
	bool __fastcall formatMessage(std::string& msg);
	const WICommInfo info_;
	WICommStatus status_;
	WIWeight weight_;
public:
	__fastcall TRoadMeterThread(bool CreateSuspended, const WICommInfo& info);
};
//---------------------------------------------------------------------------
#endif
