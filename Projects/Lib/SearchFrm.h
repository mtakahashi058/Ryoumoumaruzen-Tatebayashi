//---------------------------------------------------------------------------

#ifndef SearchFrmH
#define SearchFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
class TSearchForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TDataSource *DataSource1;
	TADOQuery *Query;
	TDBGrid *DBGrid;
	TButton *btnOk;
	TButton *btnCancel;
    TPanel *FilterPanel;
	TCobEdit *cedtSearch;
	TLabel *Label1;
	TButton *btnSearch;
	TSpeedButton *FirstButton;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TSpeedButton *LastButton;
	TDBNavigator *DBNavigator1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnOkClick(TObject *Sender);
	void __fastcall btnSearchClick(TObject *Sender);
	void __fastcall cedtSearchKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
	void __fastcall FirstButtonClick(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall LastButtonClick(TObject *Sender);
	void __fastcall QueryAfterScroll(TDataSet *DataSet);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall SetButtonEnabled();
public:		// ユーザー宣言
	__fastcall TSearchForm(TComponent* Owner);
	AnsiString based_sql, orderby_sql, table_name;
	TStringList *list_;
};
//---------------------------------------------------------------------------
extern PACKAGE TSearchForm *SearchForm;
//---------------------------------------------------------------------------
#endif
