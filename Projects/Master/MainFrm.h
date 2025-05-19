//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ActnList.hpp>
#include <DB.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <QuickRpt.hpp>
#include <Dialogs.hpp>
#include <ADODB.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
#include <memory>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TStatusBar *StatusBar;
	TPanel *Panel1;
	TButton *btnF1;
	TButton *btnF2;
	TButton *btnF3;
	TButton *btnF4;
	TButton *btnF5;
	TButton *btnF6;
	TButton *btnF7;
	TButton *btnF8;
	TButton *btnF9;
	TButton *btnF10;
	TButton *btnF11;
	TButton *btnF12;
	TPageControl *PageControl;
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
	TTabSheet *TabSheet1;
	TDBGrid *DBGrid1;
	TSaveDialog *SaveDialog;
	TDataSource *DataSource1;
	TDataSource *DataSource2;
	TDataSource *DataSource3;
	TPanel *Panel4;
	TAction *PagePrior;
	TAction *PageNext;
	TProgressBar *ProgressBar;
	TDBNavigator *DBNavigator2;
	TDataSource *DataSource4;
	TDataSource *DataSource5;
	TLabel *Label1;
	TCobEdit *SearchEdit1;
	TCheckBox *AllDataShowCheckBox1;
	TDataSource *DataSource6;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	TTabSheet *TabSheet7;
	TTabSheet *TabSheet9;
	TPanel *Panel2;
	TLabel *Label2;
	TDBNavigator *DBNavigator1;
	TCobEdit *SearchEdit2;
	TCheckBox *AllDataShowCheckBox2;
	TDBGrid *DBGrid2;
	TPanel *Panel3;
	TLabel *Label3;
	TDBNavigator *DBNavigator3;
	TCobEdit *SearchEdit3;
	TCheckBox *AllDataShowCheckBox3;
	TDBGrid *DBGrid3;
	TPanel *Panel5;
	TLabel *Label4;
	TDBNavigator *DBNavigator4;
	TCobEdit *SearchEdit4;
	TDBGrid *DBGrid4;
	TPanel *Panel6;
	TLabel *Label5;
	TDBNavigator *DBNavigator5;
	TCobEdit *SearchEdit5;
	TCheckBox *AllDataShowCheckBox5;
	TDBGrid *DBGrid5;
	TPanel *Panel8;
	TLabel *Label6;
	TDBNavigator *DBNavigator6;
	TCobEdit *SearchEdit6;
	TDBGrid *DBGrid6;
	TPanel *Panel9;
	TLabel *Label7;
	TDBNavigator *DBNavigator7;
	TCobEdit *SearchEdit7;
	TDBGrid *DBGrid7;
	TPanel *Panel13;
	TLabel *Label9;
	TDBNavigator *DBNavigator9;
	TCobEdit *SearchEdit9;
	TDBGrid *DBGrid9;
	TTabSheet *TabSheet8;
	TPanel *Panel14;
	TLabel *Label8;
	TDBNavigator *DBNavigator8;
	TCobEdit *SearchEdit8;
	TDBGrid *DBGrid8;
	TDataSource *DataSource7;
	TDataSource *DataSource8;
	TDataSource *DataSource9;
	TCheckBox *AllDataShowCheckBox4;
	TTabSheet *TabSheet10;
	TPanel *Panel7;
	TLabel *Label10;
	TDBNavigator *DBNavigator10;
	TCobEdit *SearchEdit10;
	TDBGrid *DBGrid10;
	TDataSource *DataSource10;
    TTabSheet *TabSheet11;
    TTabSheet *TabSheet12;
    TTabSheet *TabSheet13;
    TPanel *Panel10;
    TLabel *Label11;
    TDBNavigator *DBNavigator11;
    TCobEdit *SearchEdit11;
    TDBGrid *DBGrid11;
    TPanel *Panel11;
    TLabel *Label12;
    TDBNavigator *DBNavigator12;
      TCobEdit *SearchEdit12;
      TDBGrid *DBGrid12;
      TPanel *Panel12;
      TLabel *Label13;
      TDBNavigator *DBNavigator13;
      TCobEdit *SearchEdit13;
      TDBGrid *DBGrid13;
      TDataSource *DataSource11;
      TDataSource *DataSource12;
      TDataSource *DataSource13;
      TTabSheet *TabSheet16;
      TTabSheet *TabSheet17;
      TPanel *Panel17;
      TLabel *Label16;
      TDBNavigator *DBNavigator16;
      TCobEdit *SearchEdit16;
      TDBGrid *DBGrid16;
      TPanel *Panel18;
      TLabel *Label17;
      TDBNavigator *DBNavigator17;
      TCobEdit *SearchEdit17;
      TDBGrid *DBGrid17;
      TDataSource *DataSource16;
      TDataSource *DataSource17;
      TCheckBox *AllDataShowCheckBox6;
    TTabSheet *TabSheet14;
    TTabSheet *TabSheet15;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Action1Execute(TObject *Sender);
	void __fastcall Action2Execute(TObject *Sender);
	void __fastcall Action3Execute(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall PageControlChange(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall Action6Execute(TObject *Sender);
	void __fastcall Action8Execute(TObject *Sender);
	void __fastcall Action4Execute(TObject *Sender);
	void __fastcall Action11Execute(TObject *Sender);
	void __fastcall Action7Execute(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall PagePriorExecute(TObject *Sender);
	void __fastcall PageNextExecute(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift);
	void __fastcall Action9Execute(TObject *Sender);
	void __fastcall Action10Execute(TObject *Sender);
	void __fastcall SearchEdit1KeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall AllDataShowCheckBox1Click(TObject *Sender);
    void __fastcall DBGrid1CellClick(TColumn *Column);
    void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
private:	// ユーザー宣言
	AnsiString message_, asKeyField;
	int code_, count_;
	AnsiString index_field_name_;
	AnsiString value[20];	// 最大フィールド数

	int page_count;
	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
	void __fastcall AutoKanaMessage(tagMSG &Msg, bool &Handled);
	void __fastcall SetItem();
	void __fastcall SetPageInfo(int page);

public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);

    AnsiString toku_, item1_, item2_, hinbun_, hin_, order_;
    int page;
	/* 初期設定 */
	TADOQuery  *query[17];
	TDBGrid    *grid[17];
	AnsiString keyfield[17];
	TQuickRep  *report[17];
	TCobEdit   *search_edit[17];
	TCheckBox  *check_box[17];
	AnsiString master_name_[17];
	AnsiString table_name_[17];

    //void __fastcall OpenQuery(int p);
    void __fastcall OpenQuery(int p, AnsiString order);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
