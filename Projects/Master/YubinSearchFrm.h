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
__published:	// IDE �Ǘ��̃R���|�[�l���g
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
private:	// ���[�U�[�錾
	void __fastcall GetRecord(NsRecordSet &set, AnsiString target);
public:		// ���[�U�[�錾
	__fastcall TYubinSearchForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TYubinSearchForm *YubinSearchForm;
//---------------------------------------------------------------------------
#endif
