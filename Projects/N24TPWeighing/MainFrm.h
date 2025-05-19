//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "HF04Thread.h"
#include <ComCtrls.hpp>
#include <ScktComp.hpp>
#include "PHCThread.h"
//---------------------------------------------------------------------------
class TKeiryoStateBaseForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *HeaderPanel;
	TPanel *TitlePanel;
	TPanel *WeightPanel;
	TClientSocket *ClientSocket;
	TStatusBar *StatusBar;
	TTimer *WeightDetectTimer;
	TTimer *CloseTimer;
	TButton *ForceWeighingButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ClientSocketError(TObject *Sender,
		  TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
		  int &ErrorCode);
	void __fastcall ClientSocketRead(TObject *Sender,
		  TCustomWinSocket *Socket);
	void __fastcall CloseTimerTimer(TObject *Sender);
	void __fastcall WeightDetectTimerTimer(TObject *Sender);
	void __fastcall TitlePanelMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall TitlePanelMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ForceWeighingButtonClick(TObject *Sender);
private:	// ユーザー宣言
	Currency cur_weight_;
	Currency old_weight_;
	bool weight_detected_;
	DWORD close_tick_;
//-- USB RFID ------------------------------------------------------------------
	THF04Thread *rfid_thread_;
//-- PHC100 Thread -------------------------------------------------------------
	bool use_phc_;
	TPHCThread* phc_thread_;
    PHCCommInfo phc_info_;
//-- SFM Handler ---------------------------------------------------------------
	void __fastcall OnStatus(const AnsiString& message);
	void __fastcall OnEvent(State::EventID event, void *param);
	void __fastcall OnLog(const AnsiString& message);
    void __fastcall OnPatlite(bool complete, bool error);
//-- message handler -----------------------------------------------------------
	void __fastcall OnRFIDAborted(TMessage& message);
	void __fastcall OnRFIDStatus(TMessage& message);
	void __fastcall OnRFIDCard(TMessage& message);
    void __fastcall OnPHCAborted(TMessage& message);
    void __fastcall OnPHCStatus(TMessage& Message);
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(RFIDM_ABORTED, TMessage, OnRFIDAborted);
	MESSAGE_HANDLER(RFIDM_STATUS,  TMessage, OnRFIDStatus);
	MESSAGE_HANDLER(RFIDM_CARD,    TMessage, OnRFIDCard);
	MESSAGE_HANDLER(PHCM_ABORTED,  TMessage, OnPHCAborted);
	MESSAGE_HANDLER(PHCM_STATUS,   TMessage, OnPHCStatus);
END_MESSAGE_MAP(TForm)
public:		// ユーザー宣言
	__fastcall TKeiryoStateBaseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKeiryoStateBaseForm *KeiryoStateBaseForm;
//---------------------------------------------------------------------------
#endif
