//---------------------------------------------------------------------------

#ifndef N95ExportThreadH
#define N95ExportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "BatMsgs.h"
#include <vector>
//---------------------------------------------------------------------------
typedef std::vector<AnsiString> Records;
//---------------------------------------------------------------------------
enum ExportTarget {etID, etItem};
//---------------------------------------------------------------------------
class TN95ExportThread : public TThread
{
private:
protected:
    void __fastcall Execute();
    int port_;
    AnsiString def_;
    HWND owner_;
    AnsiString command_;
    Records records_;
public:
    __fastcall TN95ExportThread(bool CreateSuspended, int port, const AnsiString& def, HWND owner, ExportTarget target, const Records& recs);
};
//---------------------------------------------------------------------------
#endif
