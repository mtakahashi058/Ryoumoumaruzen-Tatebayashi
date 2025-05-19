//---------------------------------------------------------------------------

#ifndef DivideDateFrmH
#define DivideDateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
struct NoRangeDate {
	NoRangeDate() : from(0), to(0), date(0) {}
	NoRangeDate(int f, int t, int d) : from(f), to(t), date(d) {}

    int from, to, date;
};
typedef std::vector<NoRangeDate> NRDates;
//---------------------------------------------------------------------------
class TDivideDateForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Date1Panel;
	TLabel *Label1;
	TCobEdit *Date1NoFromEdit;
	TLabel *Label2;
	TCobEdit *Date1NoToEdit;
	TDateTimePicker *Date1Picker;
	TButton *Date1PrevButton;
	TButton *Date1NextButton;
	TPanel *Panel1;
	TLabel *Label3;
	TPanel *Date2Panel;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TCobEdit *Date2NoFromEdit;
	TCobEdit *Date2NoToEdit;
	TDateTimePicker *Date2Picker;
	TButton *Date2PrevButton;
	TButton *Date2NextButton;
	TPanel *Panel3;
	TPanel *Date3Panel;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TCobEdit *Date3NoFromEdit;
	TCobEdit *Date3NoToEdit;
	TDateTimePicker *Date3Picker;
	TButton *Date3PrevButton;
	TButton *Date3NextButton;
	TPanel *Panel4;
	TButton *PostButton;
	TButton *CancelButton;
	TPanel *Date4Panel;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TCobEdit *Date4NoFromEdit;
	TCobEdit *Date4NoToEdit;
	TDateTimePicker *Date4Picker;
	TButton *Date4PrevButton;
	TButton *Date4NextButton;
	TPanel *Panel5;
	TPanel *Date5Panel;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TCobEdit *Date5NoFromEdit;
	TCobEdit *Date5NoToEdit;
	TDateTimePicker *Date5Picker;
	TButton *Date5PrevButton;
	TButton *Date5NextButton;
	TPanel *Panel7;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DateNPrevButtonClick(TObject *Sender);
	void __fastcall DateNNextButtonClick(TObject *Sender);
	void __fastcall PostButtonClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
	int r1_from_;
    int r1_to_;
    int r2_from_;
    int r2_to_;
public:		// ユーザー宣言
	void __fastcall SetNoRange(int r1from, int r1to, int r2from, int r2to);
	__fastcall TDivideDateForm(TComponent* Owner);

	NRDates NoRangeDates;
};
//---------------------------------------------------------------------------
extern PACKAGE TDivideDateForm *DivideDateForm;
//---------------------------------------------------------------------------
#endif
