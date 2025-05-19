//----------------------------------------------------------------------------
#ifndef PostConfFrmH
#define PostConfFrmH
//----------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <Messages.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
//----------------------------------------------------------------------------
class TPostConfForm : public TForm
{
__published:
	TButton *ButtonKanryo;
	TButton *ButtonCancel;
	TButton *ButtonKeizoku;
	TLabel *Label1;
	TImage *ImageQuestion;
	void __fastcall FormShow(TObject *Sender);
    void __fastcall ButtonKanryoClick(TObject *Sender);
    void __fastcall ButtonKeizokuClick(TObject *Sender);
    void __fastcall ButtonCancelClick(TObject *Sender);
private:
public:
	virtual __fastcall TPostConfForm(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TPostConfForm *PostConfForm;
//----------------------------------------------------------------------------
#endif
