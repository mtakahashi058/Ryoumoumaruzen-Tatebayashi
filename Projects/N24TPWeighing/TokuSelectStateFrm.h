//---------------------------------------------------------------------------

#ifndef TokuSelectStateFrmH
#define TokuSelectStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTokuSelectForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TButton *ScrollUpButton;
	TButton *ScrollDownButton;
	TButton *Item1Button;
	TButton *Item2Button;
	TButton *Item3Button;
	TButton *Item4Button;
	TButton *Item5Button;
	TButton *Item6Button;
	TButton *Item7Button;
	TButton *Item8Button;
	TButton *Item9Button;
	TButton *Item10Button;
	TButton *Item11Button;
	TButton *Item12Button;
	TButton *Item13Button;
	TButton *Item14Button;
	TButton *Item15Button;
	TButton *Item16Button;
	TButton *Item17Button;
	TButton *Item18Button;
	TButton *CancelButton;
	TButton *Kana1Button;
	TButton *Kana2Button;
	TButton *Kana3Button;
	TButton *Kana4Button;
	TButton *Kana5Button;
	TButton *Kana6Button;
	TButton *Kana7Button;
	TButton *Kana8Button;
	TButton *Kana9Button;
	TButton *Kana10Button;
	TButton *KanaBackButton;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Item1ButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall ScrollUpButtonClick(TObject *Sender);
	void __fastcall ScrollDownButtonClick(TObject *Sender);
	void __fastcall Kana1ButtonClick(TObject *Sender);
private:	// ユーザー宣言
	TButton *Buttons_[18];
	TButton *KanaButtons_[10];
	int lefttop_rec_no_;
	int enable_count_;

	void __fastcall AllocateRecordToButtons(int top_rec_no, const AnsiString& kana1 = AnsiString(), const AnsiString& kana2 = AnsiString());
public:		// ユーザー宣言
	__fastcall TTokuSelectForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TTokuSelectForm *TokuSelectForm;
//---------------------------------------------------------------------------
#endif
