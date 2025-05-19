//---------------------------------------------------------------------------

#ifndef CardIssueFrmH
#define CardIssueFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
class TCardIssueForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *BottomPanel;
	TButton *CloseButton;
	TPanel *ClientPanel;
	TPageControl *PageControl;
	TTabSheet *CardSheet;
	TPanel *Panel4;
	TPanel *CarNoPanel;
	TBevel *Bevel2;
    TPanel *TokuTitlePanel;
	TBevel *Bevel3;
	TTimer *ActivateTimer;
    TButton *ReissueButton;
    TPanel *Item1TitlePanel;
	TBevel *Bevel4;
    TPanel *Item2TitlePanel;
	TBevel *Bevel1;
	TCobEdit *CarNoEdit;
    TCobEdit *TokuEdit;
    TCobEdit *Item1Edit;
    TCobEdit *Item2Edit;
    TCobEdit *TokuNameEdit;
    TCobEdit *Item1NameEdit;
    TCobEdit *Item2NameEdit;
	TPanel *Panel1;
	TBevel *Bevel5;
	TCobEdit *TareEdit;
	TPanel *Panel2;
	TBevel *Bevel6;
	TCobEdit *GrossLimitEdit;
	TPanel *Panel5;
	TBevel *Bevel7;
	TCobEdit *NetLimitEdit;
    TPanel *HinTitlePanel;
    TBevel *Bevel8;
    TCobEdit *HinEdit;
    TCobEdit *HinNameEdit;
    TCobEdit *CarNameEdit;
    TButton *CarRefButton;
    TButton *ClearButton;
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ReissueButtonClick(TObject *Sender);
    void __fastcall CarRefButtonClick(TObject *Sender);
    void __fastcall CarNoEditChange(TObject *Sender);
    void __fastcall CarNoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall CarNoEditExit(TObject *Sender);
    void __fastcall TokuEditChange(TObject *Sender);
    void __fastcall HinEditChange(TObject *Sender);
    void __fastcall Item1EditChange(TObject *Sender);
    void __fastcall Item2EditChange(TObject *Sender);
    void __fastcall ClearButtonClick(TObject *Sender);
private:	// ユーザー宣言
    int rfid_comm_port_;
    int car_id_;

	void __fastcall ClearForm();
	bool __fastcall IsValidForm();
    void __fastcall MessageProc(tagMSG &Msg, bool &Handled);

public:		// ユーザー宣言
	__fastcall TCardIssueForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCardIssueForm *CardIssueForm;
//---------------------------------------------------------------------------
#endif
