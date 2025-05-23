//---------------------------------------------------------------------------

#ifndef ContinuationStateFrmH
#define ContinuationStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TContinuationStateForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TBitBtn *CancelButton;
	TLabel *Label10;
	TRichEdit *NoticeRichEdit;
	TPanel *TitlePanel;
	TLabel *Title1Label;
	TLabel *Title2Label;
	TLabel *Label11;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TContinuationStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TContinuationStateForm *ContinuationStateForm;
//---------------------------------------------------------------------------
#endif
