//---------------------------------------------------------------------------

#ifndef CardStateFrmH
#define CardStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCardStateForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *CardPanel;
	TButton *PrintButton;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PrintButtonClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TCardStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TCardStateForm *CardStateForm;
//---------------------------------------------------------------------------
#endif
