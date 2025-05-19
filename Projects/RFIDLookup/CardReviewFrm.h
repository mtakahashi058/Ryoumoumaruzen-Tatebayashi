//---------------------------------------------------------------------------

#ifndef CardReviewFrmH
#define CardReviewFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "HF04Thread.h"
//---------------------------------------------------------------------------
class TCardReviewForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *BottomPanel;
	TButton *CloseButton;
	TPanel *ClientPanel;
	TPageControl *PageControl;
	TTabSheet *ConfirmSheet;
	TPanel *Panel4;
	TPanel *CarNoTitlePanel;
	TBevel *Bevel2;
    TPanel *TokuTitlePanel;
	TBevel *Bevel3;
	TPanel *CarNoPanel;
    TPanel *TokuPanel;
	TMemo *StatusMemo;
	TLabel *StatusLabel;
	TTimer *ActivateTimer;
    TPanel *HinTitlePanel;
	TBevel *Bevel1;
    TPanel *HinPanel;
	TPanel *Panel2;
	TBevel *Bevel4;
	TPanel *Panel3;
	TBevel *Bevel5;
	TPanel *Panel6;
	TBevel *Bevel6;
	TLabel *TareWeightLabel;
	TLabel *GrossLimitLabel;
	TLabel *NetLimitLabel;
    TPanel *Item1TitlePanel;
	TBevel *Bevel8;
    TPanel *Item1Panel;
	TPanel *Panel5;
	TBevel *Bevel10;
	TLabel *UseDateLabel;
    TPanel *Item2TitlePanel;
    TBevel *Bevel7;
    TPanel *Item2Panel;
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ActivateTimerTimer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// ユーザー宣言

	THF04Thread *rfid_thread_;
	void __fastcall ClearForm();

	void __fastcall OnRFIDAborted(TMessage& message);
	void __fastcall OnRFIDStatus(TMessage& message);
	void __fastcall OnRFIDCard(TMessage& message);
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(RFIDM_ABORTED, TMessage, OnRFIDAborted);
	MESSAGE_HANDLER(RFIDM_STATUS, TMessage, OnRFIDStatus);
	MESSAGE_HANDLER(RFIDM_CARD, TMessage, OnRFIDCard);
END_MESSAGE_MAP(TForm)
public:		// ユーザー宣言
	__fastcall TCardReviewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCardReviewForm *CardReviewForm;
//---------------------------------------------------------------------------
#endif
