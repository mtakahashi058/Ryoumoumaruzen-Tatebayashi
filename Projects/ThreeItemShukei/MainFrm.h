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
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
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
	TLabel *Label1;
	TComboBox *SelectItem1ComboBox;
	TLabel *Label2;
	TDateTimePicker *FromDatePicker;
	TDateTimePicker *ToDatePicker;
	TLabel *Label3;
	TCheckBox *Item1AllCheckBox;
	TCobEdit *Item1CodeEditF;
	TCobEdit *Item1NameEditF;
	TCheckBox *SpotAllCheckBox;
	TCobEdit *SpotCodeEdit;
	TCobEdit *SpotNameEdit;
	TLabel *IoDivLabel;
	TComboBox *IoDivComboBox;
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
	TSpeedButton *Item1SearchButtonF;
	TSpeedButton *SpotSearchButton;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TRichEdit *RichEdit1;
	TPanel *InfoPanel;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label4;
	TSpeedButton *Item2SearchButtonF;
	TComboBox *SelectItem2ComboBox;
	TCheckBox *Item2AllCheckBox;
	TCobEdit *Item2CodeEditF;
	TCobEdit *Item2NameEditF;
	TLabel *Label5;
	TSpeedButton *Item3SearchButtonF;
	TComboBox *SelectItem3ComboBox;
	TCheckBox *Item3AllCheckBox;
	TCobEdit *Item3CodeEditF;
	TCobEdit *Item3NameEditF;
	TSpeedButton *Item1SearchButtonT;
	TCobEdit *Item1CodeEditT;
	TCobEdit *Item1NameEditT;
	TLabel *Label6;
	TSpeedButton *Item2SearchButtonT;
	TCobEdit *Item2CodeEditT;
	TCobEdit *Item2NameEditT;
	TLabel *Label7;
	TSpeedButton *Item3SearchButtonT;
	TCobEdit *Item3CodeEditT;
	TCobEdit *Item3NameEditT;
	TLabel *Label10;
	TLabel *Label11;
	TComboBox *TorihikiComboBox;
	TLabel *Label12;
	TComboBox *GenkakeComboBox;
	TPanel *ShabanPanel1;
	TRadioButton *SharyoRadioButton1;
	TRadioButton *ShabanRadioButton1;
	TPanel *ShabanPanel2;
	TRadioButton *SharyoRadioButton2;
	TRadioButton *ShabanRadioButton2;
	TPanel *ShabanPanel3;
	TRadioButton *SharyoRadioButton3;
	TRadioButton *ShabanRadioButton3;
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
	void __fastcall SelectItem1ComboBoxChange(TObject *Sender);
	void __fastcall SpotAllCheckBoxClick(TObject *Sender);
	void __fastcall Item1AllCheckBoxClick(TObject *Sender);
	void __fastcall Item1SearchButtonFClick(TObject *Sender);
	void __fastcall SpotCodeEditChange(TObject *Sender);
	void __fastcall SpotSearchButtonClick(TObject *Sender);
	void __fastcall Item1CodeEditFChange(TObject *Sender);
	void __fastcall SelectItem2ComboBoxChange(TObject *Sender);
	void __fastcall Item2AllCheckBoxClick(TObject *Sender);
	void __fastcall Item2CodeEditFChange(TObject *Sender);
	void __fastcall Item2SearchButtonFClick(TObject *Sender);
	void __fastcall SelectItem3ComboBoxChange(TObject *Sender);
	void __fastcall Item3AllCheckBoxClick(TObject *Sender);
	void __fastcall Item3CodeEditFChange(TObject *Sender);
	void __fastcall Item3SearchButtonFClick(TObject *Sender);
	void __fastcall Item1CodeEditTChange(TObject *Sender);
	void __fastcall Item1SearchButtonTClick(TObject *Sender);
	void __fastcall Item2CodeEditTChange(TObject *Sender);
	void __fastcall Item2SearchButtonTClick(TObject *Sender);
	void __fastcall Item3CodeEditTChange(TObject *Sender);
	void __fastcall Item3SearchButtonTClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
	void __fastcall SetItems();

	ItemMap item_map_;
	bool __fastcall OpenQuery();
	void __fastcall ExcelOut();
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
