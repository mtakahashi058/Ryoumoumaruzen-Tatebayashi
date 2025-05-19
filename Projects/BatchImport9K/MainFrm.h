//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <vector>
#include <map>
#include "BatMsgs.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TButton *ImportButton;
    TButton *CloseButton;
    TLabel *StatusLabel;
    TProgressBar *ProgressBar;
    TBevel *Bevel1;
    TLabel *Label1;
    TLabel *CountLabel;
    TLabel *Label2;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CloseButtonClick(TObject *Sender);
    void __fastcall ImportButtonClick(TObject *Sender);
private:	// ユーザー宣言
    int port_;
    AnsiString def_;
    TThread *thread_;
	std::vector<AnsiString> received_rec_;
    std::map <int, int> no_date_map_;

	void __fastcall OnCompleted(TMessage& message);
	void __fastcall OnAborted(TMessage& message);
	void __fastcall OnStatus(TMessage& message);
	void __fastcall OnDataReceived(TMessage& message);
	void __fastcall OnProcessStep(TMessage& message);
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(BM_COMPLETED,    TMessage, OnCompleted)
	MESSAGE_HANDLER(BM_ABORTED,      TMessage, OnAborted)
	MESSAGE_HANDLER(BM_STATUS,       TMessage, OnStatus)
	MESSAGE_HANDLER(BM_DATARECEIVED, TMessage, OnDataReceived)
	MESSAGE_HANDLER(BM_PROCESS_STEP, TMessage, OnProcessStep)
END_MESSAGE_MAP(TForm)

    bool __fastcall PostRecord(AnsiString record);
public:		// ユーザー宣言
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
