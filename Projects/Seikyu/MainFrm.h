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
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include "CEdit.h"
#include <DB.hpp>
#include <dbcgrids.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *pnlTitle;
	TActionList *ActionList1;
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
	TComboBox *SimeComboBox;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TCheckBox *AllCheckBox;
	TGroupBox *GroupBox2;
	TSpeedButton *SeikyusakiSearchButtonF;
	TCobEdit *SeikyusakiCodeEditF;
	TCobEdit *SeikyusakiNameEditF;
	TLabel *Label7;
	TSpeedButton *SeikyusakiSearchButtonT;
	TCobEdit *SeikyusakiCodeEditT;
	TCobEdit *SeikyusakiNameEditT;
	TLabel *Label8;
	TRichEdit *RichEdit1;
	TLabel *LastSimeLabel;
	TPanel *CreatePanel;
	TLabel *Label6;
	TLabel *Label9;
	TPanel *JunbiPanel;
	TLabel *Label15;
	TGroupBox *GroupBox4;
	TLabel *Label10;
	TLabel *Label16;
	TLabel *Label2;
	TDateTimePicker *DateFromPicker;
	TDateTimePicker *DateToPicker;
	TDateTimePicker *SimekiriDatePicker;
	TCheckBox *KobetuCheckBox;
	TButton *PrevButton;
	TButton *NextButton;
	TGroupBox *GroupBox5;
	TComboBox *CreateSeikyuComboBox;
	TComboBox *HikaeComboBox;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *TokuKensuLabel;
	TCobEdit *SimekiriEdit;
	TCobEdit *DateFromEdit;
	TCobEdit *DateToEdit;
	TLabel *BeforeLastSimeLabel;
	TLabel *ShoriKensuLabel;
	TLabel *KensuLabel;
	TButton *ShosikiButton;
	TButton *SeikyuConfButton;
	TAction *Action4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall PrevButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall SimeComboBoxChange(TObject *Sender);
	void __fastcall AllCheckBoxClick(TObject *Sender);
	void __fastcall SeikyusakiCodeEditFChange(TObject *Sender);
	void __fastcall SeikyusakiSearchButtonFClick(TObject *Sender);
	void __fastcall SeikyusakiCodeEditTChange(TObject *Sender);
	void __fastcall SeikyusakiSearchButtonTClick(TObject *Sender);
	void __fastcall Action4Execute(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ShosikiButtonClick(TObject *Sender);
	void __fastcall KobetuCheckBoxClick(TObject *Sender);
	void __fastcall SimekiriDatePickerChange(TObject *Sender);
	void __fastcall CreateSeikyuComboBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall btnF9Click(TObject *Sender);
	void __fastcall SeikyuConfButtonClick(TObject *Sender);
	void __fastcall Action11Execute(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall SetSimeCheckRange();
	bool __fastcall SetRange(bool create_data);
	int __fastcall GetShohizeiritu(int date);
	bool __fastcall CreateSeikyuData();
	bool __fastcall InputCheck();
	int create_cnt;
	void __fastcall SetDate();
	bool __fastcall CreateProcess(AnsiString exename, bool wait);

public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
