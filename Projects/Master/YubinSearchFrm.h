//---------------------------------------------------------------------------

#ifndef YubinSearchFrmH
#define YubinSearchFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "DMFrm.h"
#include "CEdit.h"
//---------------------------------------------------------------------------
class TYubinSearchForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TListBox *KenListBox;
	TListBox *SiListBox;
	TListBox *TyouikiListBox;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TCobEdit *YubinEdit;
	TButton *FixButton;
	TButton *CancelButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall KenListBoxClick(TObject *Sender);
	void __fastcall SiListBoxClick(TObject *Sender);
	void __fastcall TyouikiListBoxClick(TObject *Sender);
	void __fastcall YubinEditChange(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall GetRecord(NsRecordSet &set, AnsiString target);
public:		// ユーザー宣言
	__fastcall TYubinSearchForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TYubinSearchForm *YubinSearchForm;
//---------------------------------------------------------------------------
#endif
