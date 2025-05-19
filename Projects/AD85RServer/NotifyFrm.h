//---------------------------------------------------------------------------

#ifndef NotifyFrmH
#define NotifyFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TNotifyForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TPanel *ClientPanel;
    TPanel *HeaderPanel;
    TPanel *TitlePanel;
    TBevel *Bevel1;
    TApplicationEvents *ApplicationEvents;
    TTimer *HideTimer;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ApplicationEventsDeactivate(TObject *Sender);
    void __fastcall HideTimerTimer(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
    __fastcall TNotifyForm(TComponent* Owner);
    AnsiString Sound;

    void __fastcall Show(); // override
    void __fastcall Notify(const AnsiString& text, bool highlight, int disp_msec);
};
//---------------------------------------------------------------------------
extern PACKAGE TNotifyForm *NotifyForm;
//---------------------------------------------------------------------------
#endif
