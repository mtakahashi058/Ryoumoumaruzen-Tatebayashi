//---------------------------------------------------------------------------

#ifndef TareWeighingFrmH
#define TareWeighingFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "HF04Thread.h"
//---------------------------------------------------------------------------
#include "CEdit.h"
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
// かな検索テーブル
typedef std::map<int, AnsiString> KanaOnTable;
typedef std::map<int, KanaOnTable> KanaTable;
//---------------------------------------------------------------------------
class TTareWeighingForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *BottomPanel;
	TButton *CloseButton;
	TPanel *ClientPanel;
	TButton *BackButton;
	TPageControl *PageControl;
	TTabSheet *ModeSelectSheet;
	TPanel *Panel4;
	TTimer *ActivateTimer;
	TButton *SetTareButton;
	TTabSheet *WaitCardSheet;
	TPanel *Panel10;
	TLabel *StatusLabel;
	TMemo *StatusMemo;
	TPanel *Panel1;
	TBevel *Bevel1;
	TPanel *Item2TitlePanel;
	TBevel *Bevel5;
	TPanel *CarNoPanel;
	TPanel *Item2Panel;
    TPanel *TokuTitlePanel;
	TBevel *Bevel6;
    TPanel *TokuPanel;
	TTabSheet *WarningSheet;
	TMemo *WarningMemo;
	TButton *WarningConfirmButton;
	TPanel *Panel3;
	TButton *Button1;
	TMemo *Memo1;
	TPanel *Panel5;
	TBevel *Bevel4;
	TLabel *TareWeightLabel;
	TTabSheet *CompleteSheet;
	TPanel *Panel6;
	TMemo *CompleteMemo;
	TTabSheet *WeighTareSheet;
	TPanel *Panel7;
	TButton *CompleteConfirmButton;
	TClientSocket *ClientSocket;
	TPanel *WeightPanel;
	TButton *WeighTareButton;
	TPanel *Item1TitlePanel;
	TBevel *Bevel2;
	TPanel *Item1Panel;
    TPanel *MeigTitlePanel;
    TBevel *Bevel3;
    TPanel *MeigPanel;
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall ActivateTimerTimer(TObject *Sender);
	void __fastcall SetTareButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall WarningConfirmButtonClick(TObject *Sender);
	void __fastcall CompleteConfirmButtonClick(TObject *Sender);
	void __fastcall ClientSocketError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall ClientSocketRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall WeighTareButtonClick(TObject *Sender);
private:	// ユーザー宣言
	ackl::State *current_state_;
	Currency cur_weight_;

	THF04Thread *rfid_thread_;

	void __fastcall OnRFIDAborted(TMessage& message);
	void __fastcall OnRFIDStatus(TMessage& message);
	void __fastcall OnRFIDCard(TMessage& message);
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(RFIDM_ABORTED, TMessage, OnRFIDAborted);
	MESSAGE_HANDLER(RFIDM_STATUS, TMessage, OnRFIDStatus);
	MESSAGE_HANDLER(RFIDM_CARD, TMessage, OnRFIDCard);
END_MESSAGE_MAP(TForm)
public:		// ユーザー宣言
	__fastcall TTareWeighingForm(TComponent* Owner);
	Currency __fastcall GetWeight();
};
//---------------------------------------------------------------------------
extern PACKAGE TTareWeighingForm *TareWeighingForm;
//---------------------------------------------------------------------------
#endif
