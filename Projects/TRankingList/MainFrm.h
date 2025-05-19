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
//---------------------------------------------------------------------------
#include <map>
typedef std::map<int, AnsiString> ItemMap;
#include "XlWrap.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel1;
	TPanel *Panel2;
	TGroupBox *GroupBox1;
	TButton *PrintButton;
	TButton *PreviewButton;
	TButton *OutputButton;
	TButton *CloseButton;
	TActionList *ActionList1;
	TAction *SanshoAction;
	TAction *PrintAction;
	TAction *PreviewAction;
	TAction *OutputAction;
	TAction *EndAction;
	TLabel *Label8;
	TComboBox *OrderComboBox;
	TLabel *Label6;
	TLabel *Label7;
	TCobEdit *MaxCountEdit;
	TLabel *Label2;
	TLabel *Label3;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TDateTimePicker *FromDatePicker;
	TDateTimePicker *ToDatePicker;
	TPanel *Panel3;
	TRadioButton *DayRadioButton;
	TRadioButton *MonthRadioButton;
	TRadioButton *YearRadioButton;
	TLabel *Label1;
	TSpeedButton *ItemSearchButtonF;
	TComboBox *SelectItemComboBox;
	TCheckBox *ItemAllCheckBox;
	TCobEdit *ItemCodeEditF;
	TCobEdit *ItemNameEditF;
	TSpeedButton *SpotSearchButton;
	TCheckBox *SpotAllCheckBox;
	TCobEdit *SpotCodeEdit;
	TCobEdit *SpotNameEdit;
	TLabel *IoDivLabel;
	TComboBox *IoDivComboBox;
	TSpeedButton *ItemSearchButtonT;
	TCobEdit *ItemCodeEditT;
	TCobEdit *ItemNameEditT;
	TLabel *Label5;
	TLabel *Label4;
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
	void __fastcall SelectItemComboBoxChange(TObject *Sender);
	void __fastcall SpotAllCheckBoxClick(TObject *Sender);
	void __fastcall ItemAllCheckBoxClick(TObject *Sender);
	void __fastcall ItemSearchButtonFClick(TObject *Sender);
	void __fastcall SpotCodeEditChange(TObject *Sender);
	void __fastcall SpotSearchButtonClick(TObject *Sender);
	void __fastcall ItemCodeEditFChange(TObject *Sender);
	void __fastcall Panel4Enter(TObject *Sender);
	void __fastcall Panel4Exit(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ItemCodeEditTChange(TObject *Sender);
	void __fastcall ItemSearchButtonTClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall SetItems();
	bool __fastcall SetQuery();

	ItemMap item_map_;
	AnsiString where, where_rep, orderby;
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
