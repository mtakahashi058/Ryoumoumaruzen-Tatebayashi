//---------------------------------------------------------------------------

#ifndef ErrorStateFrmH
#define ErrorStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TErrorStateForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *ErrorPanel;
	TMemo *ErrorMemo;
	void __fastcall FormCreate(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TErrorStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TErrorStateForm *ErrorStateForm;
//---------------------------------------------------------------------------
#endif
