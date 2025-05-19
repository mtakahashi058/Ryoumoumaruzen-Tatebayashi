//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "MainFrm.h"
#include "PostConfFrm.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
TPostConfForm *PostConfForm;
//----------------------------------------------------------------------------
__fastcall TPostConfForm::TPostConfForm(TComponent *Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall TPostConfForm::FormShow(TObject *Sender)
{
    if (MainForm->GetMode() == imMod)
		ButtonKanryo->SetFocus();
	else if (ButtonKeizoku->Enabled)
		ButtonKeizoku->SetFocus();
	else
		ButtonKanryo->SetFocus();
}
//---------------------------------------------------------------------------
// �����{�^���N���b�N
void __fastcall TPostConfForm::ButtonKanryoClick(TObject *Sender)
{
    ModalResult = mrYes;
}
//---------------------------------------------------------------------------
// �p���{�^���N���b�N
void __fastcall TPostConfForm::ButtonKeizokuClick(TObject *Sender)
{
    ModalResult = mrNo;
}
//---------------------------------------------------------------------------
// �L�����Z���{�^���N���b�N
void __fastcall TPostConfForm::ButtonCancelClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

