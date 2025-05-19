//---------------------------------------------------------------------------

#ifndef SettingFrmH
#define SettingFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CEdit.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TSettingForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TButton *SaveButton;
	TButton *CancelButton;
	TGroupBox *GroupBox1;
	TPanel *Panel1;
	TListBox *SendListBox;
	TListBox *IgnoreListBox;
	TPanel *Panel2;
	TButton *AllSendButton;
	TButton *SelectedSendButton;
	TButton *SelectedIgnoreButton;
	TButton *AllIgnoreButton;
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
	void __fastcall AllSendButtonClick(TObject *Sender);
	void __fastcall AllIgnoreButtonClick(TObject *Sender);
	void __fastcall SelectedSendButtonClick(TObject *Sender);
	void __fastcall SelectedIgnoreButtonClick(TObject *Sender);
private:	// ユーザー宣言

public:		// ユーザー宣言
	__fastcall TSettingForm(TComponent* Owner);
	void __fastcall LoadSetting();

};
//---------------------------------------------------------------------------
extern PACKAGE TSettingForm *SettingForm;
//---------------------------------------------------------------------------
#endif
