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
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TButton *AdminButton;
    TButton *ZeroSetButton;
    TButton *ZeroClrButton;
    TButton *CancelButton;
    void __fastcall CancelButtonClick(TObject *Sender);
    void __fastcall AdminButtonClick(TObject *Sender);
    void __fastcall ZeroSetButtonClick(TObject *Sender);
    void __fastcall ZeroClrButtonClick(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
    __fastcall TN24TPCardsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TN24TPCardsForm *N24TPCardsForm;
//---------------------------------------------------------------------------
#endif
