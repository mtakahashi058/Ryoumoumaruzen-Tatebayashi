//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ActnList.hpp>
#include <DB.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel1;
	TPanel *BottomPanel;
	TPanel *F1Panel;
	TPanel *F2Panel;
	TPanel *F3Panel;
	TPanel *F4Panel;
	TPanel *F5Panel;
	TPanel *F6Panel;
	TPanel *F7Panel;
	TPanel *F8Panel;
	TPanel *F9Panel;
	TPanel *F10Panel;
	TPanel *F11Panel;
	TPanel *F12Panel;
	TButton *F1Button;
	TButton *F2Button;
	TButton *F3Button;
	TButton *F4Button;
	TButton *F5Button;
	TButton *F6Button;
	TButton *F7Button;
	TButton *F8Button;
	TButton *F9Button;
	TButton *F10Button;
	TButton *F11Button;
	TButton *F12Button;
	TStatusBar *StatusBar;
	TDBGrid *DBGrid;
	TCobEdit *SimebiEdit;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TDateTimePicker *FromDatePicker;
	TDateTimePicker *ToDatePicker;
	TSpeedButton *TokuisakiSearchButton;
	TLabel *Label4;
	TCobEdit *TokuisakiNameEdit;
	TCobEdit *TokuisakiCodeEdit;
	TButton *ApplyButton;
	TButton *ClearButton;
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
	TDataSource *DataSource;
	TSaveDialog *SaveDialog;
	TCheckBox *ViewZeroCheckBox;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TOpenDialog *OpenDialog;
	TButton *GridClearButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Action1Execute(TObject *Sender);
	void __fastcall Action2Execute(TObject *Sender);
	void __fastcall Action3Execute(TObject *Sender);
	void __fastcall Action4Execute(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action6Execute(TObject *Sender);
	void __fastcall Action7Execute(TObject *Sender);
	void __fastcall Action8Execute(TObject *Sender);
	void __fastcall Action9Execute(TObject *Sender);
	void __fastcall Action10Execute(TObject *Sender);
	void __fastcall Action11Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall TokuisakiCodeEditChange(TObject *Sender);
	void __fastcall TokuisakiSearchButtonClick(TObject *Sender);
	void __fastcall ApplyButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall FromDatePickerEnter(TObject *Sender);
	void __fastcall FromDatePickerExit(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall GridClearButtonClick(TObject *Sender);
private:	// ユーザー宣言
	AnsiString __fastcall GetSeikyuRange();
	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
	bool grid_cleared_;
	
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
