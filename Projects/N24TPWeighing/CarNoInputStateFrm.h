//---------------------------------------------------------------------------

#ifndef CarNoInputStateFrmH
#define CarNoInputStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCarNoInputForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TButton *CancelButton;
	TPanel *CarNoPanel;
	TButton *CarNoSetButton;
	TPanel *CarNoInputPanel;
	TButton *Input7Button;
	TButton *Input8Button;
	TButton *Input9Button;
	TButton *Input4Button;
	TButton *Input5Button;
	TButton *Input6Button;
	TButton *Input1Button;
	TButton *Input2Button;
	TButton *Input3Button;
	TButton *Input0Button;
	TButton *InputBackButton;
	TButton *InputClearButton;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall CarNoSetButtonClick(TObject *Sender);
	void __fastcall Input0ButtonClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TCarNoInputForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TCarNoInputForm *CarNoInputForm;
//---------------------------------------------------------------------------
#endif
