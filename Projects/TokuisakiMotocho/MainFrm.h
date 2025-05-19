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
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
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
	TLabel *Label5;
	TGroupBox *GroupBox2;
	TSpeedButton *SeikyusakiSearchButtonF;
	TCobEdit *SeikyusakiCodeEditF;
	TCobEdit *SeikyusakiNameEditF;
	TCheckBox *AllCheckBox;
	TSpeedButton *SeikyusakiSearchButtonT;
	TCobEdit *SeikyusakiCodeEditT;
	TCobEdit *SeikyusakiNameEditT;
	TLabel *SiteiLabel;
	TGroupBox *GroupBox3;
	TLabel *Label3;
	TLabel *Label4;
	TComboBox *CreateDataComboBox;
	TLabel *ShoriKensuLabel;
	TButton *SeikyuConfButton;
	TLabel *Label6;
	TLabel *Label9;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Action9Execute(TObject *Sender);
	void __fastcall Action10Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall PrevButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall MonthPickerChange(TObject *Sender);
	void __fastcall SeikyusakiCodeEditFChange(TObject *Sender);
	void __fastcall SeikyusakiSearchButtonFClick(TObject *Sender);
	void __fastcall CreateDataComboBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SeikyusakiCodeEditTChange(TObject *Sender);
	void __fastcall SeikyusakiSearchButtonTClick(TObject *Sender);
	void __fastcall SeikyuConfButtonClick(TObject *Sender);
	void __fastcall AllCheckBoxClick(TObject *Sender);
private:	// ユーザー宣言
	bool __fastcall SetRange();
	bool __fastcall PostUrikake();
	int seikyu_id_;
	bool __fastcall CreateProcess(AnsiString exename, bool wait);
	bool __fastcall CheckEdit();

public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
