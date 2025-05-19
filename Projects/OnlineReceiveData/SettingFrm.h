//---------------------------------------------------------------------------

#ifndef SettingFrmH
#define SettingFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
class TSettingForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TButton *SaveButton;
	TButton *CancelButton;
	TGroupBox *GroupBox2;
	TPanel *Panel3;
	TCobEdit *LocalFolderEdit;
	TPanel *Panel4;
	TCobEdit *ServerNameEdit;
	TPanel *Panel5;
	TCobEdit *PortEdit;
	TPanel *Panel6;
	TCobEdit *UserEdit;
	TPanel *Panel7;
	TCobEdit *PasswordEdit;
	TPanel *Panel8;
	TCobEdit *ServerPathEdit;
	TLabel *Label1;
	TRichEdit *RichEdit1;
	TRichEdit *RichEdit2;
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
private:	// ���[�U�[�錾

public:		// ���[�U�[�錾
	__fastcall TSettingForm(TComponent* Owner);
	void __fastcall LoadSetting();

};
//---------------------------------------------------------------------------
extern PACKAGE TSettingForm *SettingForm;
//---------------------------------------------------------------------------
#endif
