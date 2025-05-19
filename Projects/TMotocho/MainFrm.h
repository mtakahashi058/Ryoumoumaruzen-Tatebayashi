//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <System.Actions.hpp>
//---------------------------------------------------------------------------
#include <map>
typedef std::map<int, AnsiString> ItemMap;
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel1;
	TPanel *Panel2;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TDateTimePicker *FromDatePicker;
	TDateTimePicker *ToDatePicker;
	TLabel *Label3;
	TCheckBox *SpotAllCheckBox;
	TLabel *IoDivLabel;
	TComboBox *TorihikiComboBox;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TActionList *ActionList1;
	TPanel *Panel3;
	TRadioButton *DayRadioButton;
	TRadioButton *MonthRadioButton;
	TRadioButton *YearRadioButton;
	TAction *SanshoAction;
	TAction *PrintAction;
	TAction *PreviewAction;
	TAction *OutputAction;
	TAction *EndAction;
	TSpeedButton *SpotSearchButton;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TSaveDialog *SaveDialog;
	TSpeedButton *HinbunSearchButton;
	TCheckBox *HinbunAllCheckBox;
	TLabel *HinbunLabel;
	TLabel *Label1;
	TComboBox *GenkakeComboBox;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SanshoActionExecute(TObject *Sender);
	void __fastcall PrintActionExecute(TObject *Sender);
	void __fastcall PreviewActionExecute(TObject *Sender);
	void __fastcall OutputActionExecute(TObject *Sender);
	void __fastcall EndActionExecute(TObject *Sender);
	void __fastcall DayRadioButtonClick(TObject *Sender);
	void __fastcall MonthRadioButtonClick(TObject *Sender);
	void __fastcall YearRadioButtonClick(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall SpotAllCheckBoxClick(TObject *Sender);
	void __fastcall SpotCodeEditChange(TObject *Sender);
	void __fastcall SpotSearchButtonClick(TObject *Sender);
	void __fastcall HinbunAllCheckBoxClick(TObject *Sender);
	void __fastcall HinbunCodeEditChange(TObject *Sender);
	void __fastcall HinbunSearchButtonClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
	void __fastcall SetItems();

	ItemMap item_map_;
	bool __fastcall OpenQuery();
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
