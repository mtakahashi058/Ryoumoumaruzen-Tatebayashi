//---------------------------------------------------------------------------

#ifndef KosinListFrmH
#define KosinListFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TKosinListForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TListBox *KosinListBox;
	TButton *Button1;
	TButton *Button2;
	TCheckBox *chSettingFile;
	void __fastcall FormShow(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TKosinListForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKosinListForm *KosinListForm;
//---------------------------------------------------------------------------
#endif
