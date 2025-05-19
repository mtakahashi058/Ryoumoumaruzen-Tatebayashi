//---------------------------------------------------------------------------

#ifndef WaitExitStateFrmH
#define WaitExitStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TWaitExitStateForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel6;
	TRichEdit *NoticeRichEdit;
	void __fastcall FormCreate(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TWaitExitStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TWaitExitStateForm *WaitExitStateForm;
//---------------------------------------------------------------------------
#endif
