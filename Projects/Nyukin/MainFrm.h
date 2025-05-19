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
#include <DB.hpp>
#include <ActnList.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel2;
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
	TPanel *Panel1;
	TDBGrid *DBGrid;
	TStatusBar *StatusBar;
	TLabel *Label2;
	TLabel *Label3;
	TDateTimePicker *FromDatePicker;
	TDateTimePicker *ToDatePicker;
	TSpeedButton *SeikyusakiSearchButton;
	TLabel *Label1;
	TCobEdit *SeikyusakiNameEdit;
	TCobEdit *SeikyusakiCodeEdit;
	TButton *ApplyButton;
	TButton *ClearButton;
	TDataSource *DataSource;
	TActionList *ActionList;
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
	TSpeedButton *KyotenSearchButton;
	TLabel *Label4;
	TCobEdit *KyotenNameEdit;
	TCobEdit *KyotenCodeEdit;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TComboBox *OrderComboBox;
	TLabel *Label5;
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
	void __fastcall SeikyusakiCodeEditChange(TObject *Sender);
	void __fastcall SeikyusakiSearchButtonClick(TObject *Sender);
	void __fastcall ApplyButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall DBGridDblClick(TObject *Sender);
	void __fastcall DBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KyotenCodeEditChange(TObject *Sender);
	void __fastcall KyotenSearchButtonClick(TObject *Sender);
	void __fastcall PriorButton_Click(TObject *Sender);
	void __fastcall NextButton_Click(TObject *Sender);
	void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
private:	// ユーザー宣言
	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
