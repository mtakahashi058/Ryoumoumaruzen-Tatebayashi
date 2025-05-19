//---------------------------------------------------------------------------

#ifndef TrailerWeightFrmH
#define TrailerWeightFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ExtCtrls.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
class TTrailerWeightForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *ClientPanel;
	TPanel *SojuPanel;
	TLabel *Label13;
	TCobEdit *FirstWEdit;
	TPanel *Panel1;
	TLabel *Label1;
	TCobEdit *SecondWEdit;
	TPanel *KeyPanel;
	TActionList *ActionList;
	TAction *Action12;
	TPanel *F12Panel;
	TButton *F12Button;
	TAction *Action5;
	TPanel *Panel2;
	TButton *F5Button;
	TPanel *Panel3;
	TLabel *Label2;
	TCobEdit *TotalWEdit;
	TButton *Weight1Button;
	TButton *Weight2Button;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall FirstWEditEnter(TObject *Sender);
	void __fastcall SecondWEditEnter(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SecondWEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OnWEditChange(TObject *Sender);
	void __fastcall WeightButtonClick(TObject *Sender);
	void __fastcall FirstWEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TotalWEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TotalWEditEnter(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall CalcWeight();
public:		// ユーザー宣言
	__fastcall TTrailerWeightForm(TComponent* Owner);
	Currency TotalWeight;
};
//---------------------------------------------------------------------------
extern PACKAGE TTrailerWeightForm *TrailerWeightForm;
//---------------------------------------------------------------------------
#endif
