//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TCheckListBox *CheckListBox;
	TButton *btnPrint;
	TButton *btnPreview;
	TButton *btnClose;
	TButton *btnAll;
	TButton *btnNone;
	TLabel *Label1;
	TCobEdit *cedtCode;
	TLabel *Label2;
	TComboBox *cbRetu;
	TComboBox *cbGyo;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnPreviewClick(TObject *Sender);
	void __fastcall btnPrintClick(TObject *Sender);
	void __fastcall btnCloseClick(TObject *Sender);
	void __fastcall CheckListBoxClick(TObject *Sender);
	void __fastcall btnAllClick(TObject *Sender);
	void __fastcall btnNoneClick(TObject *Sender);
	void __fastcall cedtCodeKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
	bool __fastcall SetRange();
	//std::auto_ptr<TStringList> TokuList(new TStringList());
	TStrings *TokuList;
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
