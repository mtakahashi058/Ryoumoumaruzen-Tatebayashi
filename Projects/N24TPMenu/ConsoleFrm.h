//---------------------------------------------------------------------------

#ifndef ConsoleFrmH
#define ConsoleFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <ComCtrls.hpp>
#include <string>
#include "n24tp.h"
//---------------------------------------------------------------------------
#include "wicommon.h"
#include "NiiState_win10.h"
//---------------------------------------------------------------------------
#include "S95Thread.h"
#include "C95Thread.h"
#include "S4401Thread.h"
#include "C4401Thread.h"
#include "ZF720Thread.h"
#include "F720Thread.h"
#include "CF701Thread.h"
#include "RMThread.h"
#include "SMU790Thread.h"
#include "Y700AThread.h"
#include "SEDP1700Thread.h"
#include "CADHVThread.h"
#include "SKLD2000Thread.h"
#include "CKLD2000Thread.h"
#include "CDI275Thread.h"
#include "SDI750Thread.h"
#include "SDIPC275Thread.h"
#include "SXK3190D2Thread.h"
#include "CCSD904ADThread.h"
#include "SKW201012Thread.h"
#include "F252Thread.h"
#include "CCSD904Thread.h"
//---------------------------------------------------------------------------
class TConsoleForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel5;
	TSpeedButton *WeighButton;
	TButton *ShutdownButton;
	TPanel *TitlePanel;
	TServerSocket *WIServerSocket;
	TPanel *ClientPanel;
	TMemo *ErrorMemo;
	TButton *SetZeroButton;
	TButton *CancelZeroButton;
	TTimer *ConnectionTimer;
	TStatusBar *StatusBar;
	TTimer *SignalDetectTimer;
	TPanel *Panel2;
	TSpeedButton *LookupCardButton;
	TPanel *Panel4;
	TSpeedButton *ImportButton;
	TPanel *Panel6;
	TSpeedButton *ExportButton;
	TPanel *Panel3;
	TSpeedButton *WeighTareButton;
	TPanel *Panel7;
	TSpeedButton *IssueCardButton;
	TServerSocket *NiiServerSocket;
	TTimer *NiiStatusTimer;
	TTimer *WeighingBootTimer;
	TPanel *TotalPanel;
	TPanel *Panel1;
	TBevel *Bevel1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *ResultDetailButton;
	TLabel *CountLabel;
	TLabel *WeightLabel;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *AvgLabel;
	void __fastcall WeighButtonClick(TObject *Sender);
	void __fastcall ShutdownButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SetZeroButtonClick(TObject *Sender);
	void __fastcall CancelZeroButtonClick(TObject *Sender);
	void __fastcall ConnectionTimerTimer(TObject *Sender);
	void __fastcall LookupCardButtonClick(TObject *Sender);
	void __fastcall SignalDetectTimerTimer(TObject *Sender);
	void __fastcall ServerSocketClientError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall NiiStatusTimerTimer(TObject *Sender);
	void __fastcall WeighingBootTimerTimer(TObject *Sender);
	void __fastcall IssueCardButtonClick(TObject *Sender);
	void __fastcall WeighTareButtonClick(TObject *Sender);
	void __fastcall ExportButtonClick(TObject *Sender);
	void __fastcall ImportButtonClick(TObject *Sender);
	void __fastcall ResultDetailButtonClick(TObject *Sender);
private:	// ユーザー宣言
	bool start_connect_;

	TThread *wi_thread_;
    bool use_windicator_;

	AnsiString udl_file_;
	AnsiString socket_buff_;
	AnsiString printer_;

	HANDLE process_handle_;

	NiiStatusInterface NiiState;
	bool sense_nii_status_;

	bool __fastcall CreateProcess(AnsiString path, bool wait);
	void __fastcall ShowTotalResult();
	//////////////////////////////////////////////////
	// Message Handler
	void __fastcall OnWIMAborted(TMessage& message);
	void __fastcall OnWIMStatus(TMessage& message);
	void __fastcall OnWIMWeight(TMessage& message);
	void __fastcall OnControlZero(TMessage& message);
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(WIM_ABORTED,   TMessage, OnWIMAborted);
	MESSAGE_HANDLER(WIM_STATUS,    TMessage, OnWIMStatus);
	MESSAGE_HANDLER(WIM_WEIGHT,    TMessage, OnWIMWeight);
	MESSAGE_HANDLER(UM_CONTROL_ZERO, TMessage, OnControlZero);
END_MESSAGE_MAP(TForm)
public:		// ユーザー宣言
	__fastcall TConsoleForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConsoleForm *ConsoleForm;
//---------------------------------------------------------------------------
#endif
