//---------------------------------------------------------------------------

#ifndef PrintStateFrmH
#define PrintStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TPrintStateForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TRichEdit *NoticeRichEdit;
	TButton *ReprintButton;
	TLabel *Title1Label;
	TLabel *Title2Label;
	TTimer *ForceTimer;
    TTimer *ReprintTimer;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ReprintButtonClick(TObject *Sender);
	void __fastcall ForceTimerTimer(TObject *Sender);
    void __fastcall ReprintTimerTimer(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall Print();
	//void __fastcall PrintWeightChit();
public:		// ユーザー宣言
	__fastcall TPrintStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintStateForm *PrintStateForm;
//---------------------------------------------------------------------------
#endif
