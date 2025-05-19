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
__published:	// IDE 管理のコンポーネント
    TPanel *ClientPanel;
    TButton *CloseButton;
    TPanel *TitlePanel;
    TBevel *Bevel1;
    TMemo *TextMemo;
    TApplicationEvents *ApplicationEvents;
    void __fastcall CloseButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ApplicationEventsDeactivate(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// ユーザー宣言
public:		// ユーザー宣言
    __fastcall TErrorForm(TComponent* Owner);
    bool Showed;
};
//---------------------------------------------------------------------------
extern PACKAGE TErrorForm *ErrorForm;
//---------------------------------------------------------------------------
#endif
