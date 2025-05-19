//---------------------------------------------------------------------------

#ifndef FirstWeightStateFrmH
#define FirstWeightStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFirstWeightStateForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel5;
	TPanel *InfoPanel;
	TLabel *Item1Label;
	TLabel *CarNoLabel;
	TLabel *Item2Label;
	TButton *CancelButton;
	TPanel *WeightPanel;
	TLabel *Label2;
	TButton *ConfirmButton;
	TButton *Item1ChangeButton;
	TButton *Item2ChangeButton;
	TButton *CarNoChangeButton;
	TMemo *WarningMemo;
    TLabel *TokuLabel;
    TButton *TokuChangeButton;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ConfirmButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall CarNoChangeButtonClick(TObject *Sender);
	void __fastcall Item1ChangeButtonClick(TObject *Sender);
	void __fastcall Item2ChangeButtonClick(TObject *Sender);
    void __fastcall TokuChangeButtonClick(TObject *Sender);
private:	// ユーザー宣言
	int weight_;
public:		// ユーザー宣言
	__fastcall TFirstWeightStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TFirstWeightStateForm *FirstWeightStateForm;
//---------------------------------------------------------------------------
#endif
