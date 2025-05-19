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
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TPanel *Panel6;
	TRichEdit *NoticeRichEdit;
	void __fastcall FormCreate(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TWaitExitStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TWaitExitStateForm *WaitExitStateForm;
//---------------------------------------------------------------------------
#endif
