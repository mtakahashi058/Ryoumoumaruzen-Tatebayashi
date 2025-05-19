//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TPanel *TitlePanel;
	TButton *CloseButton;
	TCheckListBox *TablesCheckList;
	TButton *SelectAllButton;
	TButton *CancelAllButton;
	TLabeledEdit *FolderEdit;
	TButton *FolderSelectButton;
	TButton *ExportButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SelectAllButtonClick(TObject *Sender);
	void __fastcall CancelAllButtonClick(TObject *Sender);
	void __fastcall FolderSelectButtonClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall ExportButtonClick(TObject *Sender);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
