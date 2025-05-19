//---------------------------------------------------------------------------

#ifndef ErrorFrmH
#define ErrorFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TErrorForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TPanel *ClientPanel;
    TButton *CloseButton;
    TPanel *TitlePanel;
    TBevel *Bevel1;
    TMemo *TextMemo;
    TApplicationEvents *ApplicationEvents;
    void __fastcall CloseButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ApplicationEventsDeactivate(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
    __fastcall TErrorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TErrorForm *ErrorForm;
//---------------------------------------------------------------------------
#endif
