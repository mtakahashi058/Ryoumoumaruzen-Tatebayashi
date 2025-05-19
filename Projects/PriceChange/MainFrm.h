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
//---------------------------------------------------------------------------
typedef struct{
	int div;
	int id;
	int base;
	int date;
	int slip_no;
	int toku_code;
	Currency amount;
}ChangeData;

#include <map>
typedef std::map<int, ChangeData> DataMap;
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TopPanel;
	TGroupBox *GroupBox1;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label3;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TDateTimePicker *FromDatePicker;
	TDateTimePicker *ToDatePicker;
	TRadioButton *DayRadioButton;
	TRadioButton *MonthRadioButton;
	TRadioButton *YearRadioButton;
	TPanel *Panel2;
	TLabel *TokuLabel;
	TCobEdit *TokuCodeEdit;
	TCobEdit *TokuNameEdit;
	TSpeedButton *TokuButton;
	TPanel *Panel3;
	TLabel *HinLabel;
	TSpeedButton *HinButton;
	TCobEdit *HinCodeEdit;
	TCobEdit *HinNameEdit;
	TPanel *Panel4;
	TLabel *Item1Label;
	TSpeedButton *Item1Button;
	TCobEdit *Item1CodeEdit;
	TCobEdit *Item1NameEdit;
	TPanel *Panel5;
	TLabel *Item2Label;
	TSpeedButton *Item2Button;
	TCobEdit *Item2CodeEdit;
	TCobEdit *Item2NameEdit;
	TPanel *Panel6;
	TLabel *Label7;
	TSpeedButton *TaniButton;
	TCobEdit *TaniCodeEdit;
	TCobEdit *TaniNameEdit;
	TDBGrid *DBGrid;
	TPanel *Panel7;
	TButton *ExtractionButton;
	TPanel *Panel8;
	TLabel *Label8;
	TCobEdit *PriceEdit;
	TButton *SelectButton;
	TButton *ReleaseButton;
	TButton *RunButton;
	TPanel *Panel9;
	TButton *EndButton;
	TDataSource *DataSource;
	TPanel *Panel10;
	TLabel *Label9;
	TComboBox *GenkakeComboBox;
    TButton *UpdateAllButton;
    TLabel *Label2;
    TLabel *Label4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall DayRadioButtonClick(TObject *Sender);
	void __fastcall MonthRadioButtonClick(TObject *Sender);
	void __fastcall YearRadioButtonClick(TObject *Sender);
	void __fastcall TokuCodeEditChange(TObject *Sender);
	void __fastcall TokuButtonClick(TObject *Sender);
	void __fastcall HinCodeEditChange(TObject *Sender);
	void __fastcall HinButtonClick(TObject *Sender);
	void __fastcall Item1CodeEditChange(TObject *Sender);
	void __fastcall Item2CodeEditChange(TObject *Sender);
	void __fastcall Item2ButtonClick(TObject *Sender);
	void __fastcall Item1ButtonClick(TObject *Sender);
	void __fastcall TaniCodeEditChange(TObject *Sender);
	void __fastcall TaniButtonClick(TObject *Sender);
	void __fastcall ExtractionButtonClick(TObject *Sender);
	void __fastcall SelectButtonClick(TObject *Sender);
	void __fastcall ReleaseButtonClick(TObject *Sender);
	void __fastcall RunButtonClick(TObject *Sender);
	void __fastcall EndButtonClick(TObject *Sender);
    void __fastcall UpdateAllButtonClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall SetItem();
	Currency __fastcall GetTaxRate(int date);
	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
    int __fastcall UpdateAllFromMaster();
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
