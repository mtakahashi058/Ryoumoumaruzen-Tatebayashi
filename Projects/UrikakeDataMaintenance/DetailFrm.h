//---------------------------------------------------------------------------

#ifndef DetailFrmH
#define DetailFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
#ifndef _INPUTMODE_
#define _INPUTMODE_
enum TInputMode {imNew, imMod, imDel};
#endif
//---------------------------------------------------------------------------
class TDetailForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TCobEdit *cedtID;
	TPanel *pnlMode;
	TCobEdit *cedtSeikyuCode;
	TButton *btnOk;
	TButton *btnCancel;
	TCobEdit *cedtSeikyuName;
	TGroupBox *GroupBox1;
	TLabel *Label4;
	TCobEdit *cedtZenSeikyu;
	TLabel *Label5;
	TCobEdit *cedtKonNyukin;
	TLabel *Label6;
	TCobEdit *cedtKonChosei;
	TLabel *Label7;
	TCobEdit *cedtKonKurikosi;
	TLabel *Label8;
	TCobEdit *cedtKonUriage;
	TLabel *Label9;
	TCobEdit *cedtKonShohizei;
	TLabel *Label10;
	TCobEdit *cedtKonSeikyu;
	TSpeedButton *btnSeikyu;
	TActionList *ActionList1;
	TAction *SanshoAction;
	TAction *PostAction;
	TAction *CloseAction;
	TLabel *TaxLabel;
	TCheckBox *RenzokuCheckBox;
	TMaskEdit *SimekiribiMaskEdit;
	TDateTimePicker *SimekiribiPicker;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cedtSeikyuCodeChange(TObject *Sender);
	void __fastcall cedtZenSeikyuChange(TObject *Sender);
	void __fastcall cedtKonUriageChange(TObject *Sender);
	void __fastcall SanshoActionExecute(TObject *Sender);
	void __fastcall PostActionExecute(TObject *Sender);
	void __fastcall CloseActionExecute(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall btnSeikyuClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall SimekiribiPickerChange(TObject *Sender);
	void __fastcall SimekiribiMaskEditExit(TObject *Sender);
	void __fastcall SimekiribiPickerEnter(TObject *Sender);
	void __fastcall SimekiribiPickerExit(TObject *Sender);
	void __fastcall SimekiribiPickerCloseUp(TObject *Sender);
	void __fastcall cedtKonSeikyuKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
	int id_;
	bool is_edit_;

	void __fastcall BrowseRecord(int id);
	bool __fastcall PostRecord(int id);
	void __fastcall ClearForm(bool date_clear);
	void __fastcall SetMode(TInputMode Mode);
	TInputMode __fastcall GetMode();
public:		// ユーザー宣言
	__fastcall TDetailForm(TComponent* Owner);

	int post_count_;

	int __fastcall ShowModalWithID(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDetailForm *DetailForm;
//---------------------------------------------------------------------------
#endif
