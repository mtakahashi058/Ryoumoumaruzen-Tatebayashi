//---------------------------------------------------------------------------

#ifndef N24TPCardsFrmH
#define N24TPCardsFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TN24TPCardsForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TButton *AdminButton;
    TButton *ZeroSetButton;
    TButton *ZeroClrButton;
    TButton *CancelButton;
    void __fastcall CancelButtonClick(TObject *Sender);
    void __fastcall AdminButtonClick(TObject *Sender);
    void __fastcall ZeroSetButtonClick(TObject *Sender);
    void __fastcall ZeroClrButtonClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
    __fastcall TN24TPCardsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TN24TPCardsForm *N24TPCardsForm;
//---------------------------------------------------------------------------
#endif
