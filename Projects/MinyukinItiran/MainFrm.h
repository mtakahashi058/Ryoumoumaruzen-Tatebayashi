//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include "CEdit.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TPanel *pnlTitle;
	TActionList *ActionList1;
	TAction *Action1;
	TAction *Action2;
	TAction *Action3;
	TAction *Action4;
	TAction *Action5;
	TAction *Action6;
	TAction *Action7;
	TAction *Action8;
	TAction *Action9;
	TAction *Action10;
	TAction *Action11;
	TAction *Action12;
	TSaveDialog *SaveDialog;
	TPanel *pnlFunction;
	TButton *btnF1;
	TButton *btnF2;
	TButton *btnF3;
	TButton *btnF4;
	TButton *btnF5;
	TButton *btnF6;
	TButton *btnF7;
	TButton *btnF8;
	TButton *btnF9;
	TButton *btnF10;
	TButton *btnF11;
	TButton *btnF12;
	TProgressBar *ProgressBar;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TDateTimePicker *DateFromPicker;
	TDateTimePicker *DateToPicker;
	TButton *NextButton;
	TButton *PrevButton;
	TDateTimePicker *MonthPicker;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Action9Execute(TObject *Sender);
	void __fastcall Action10Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall PrevButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall MonthPickerChange(TObject *Sender);
private:	// ���[�U�[�錾
	AnsiString __fastcall GetNyukinQuery(int date, int id);
	bool __fastcall SetRange();
public:		// ���[�U�[�錾
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
