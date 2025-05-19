//---------------------------------------------------------------------------

#ifndef MasterImportFrmH
#define MasterImportFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMasterImportForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TPanel *TitlePanel;
	TPanel *ClientPanel;
	TButton *ImportButton;
	TMemo *ErrorMemo;
	TPanel *BottomPanel;
	TButton *CloseButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall ImportButtonClick(TObject *Sender);
private:	// ���[�U�[�錾
	void __fastcall Import();
public:		// ���[�U�[�錾
	__fastcall TMasterImportForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMasterImportForm *MasterImportForm;
//---------------------------------------------------------------------------
#endif
