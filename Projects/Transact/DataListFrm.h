//---------------------------------------------------------------------------

#ifndef DataListFrmH
#define DataListFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ActnList.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <map>
//---------------------------------------------------------------------------
class TDataListForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TPanel *FilterPanel;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TDateTimePicker *dtpDateFrom;
	TDateTimePicker *dtpDateTo;
	TCobEdit *cedtSearch;
	TDataSource *DataSource;
    TADOQuery *Q_Trans;
	TActionList *ActionList1;
	TAction *Action5;
    TButton *PriorDateButton;
    TButton *NextDateButton;
	TButton *btnExec;
	TLabel *Label7;
    TPanel *ClientPanel;
	TDBGrid *DBGrid;
    TIntegerField *Q_TransID;
    TIntegerField *Q_TransDSDesigner2;
    TIntegerField *Q_TransDSDesigner3;
    TIntegerField *Q_TransDSDesigner4;
    TIntegerField *Q_TransID2;
    TStringField *Q_TransDSDesigner5;
    TIntegerField *Q_TransNo;
    TIntegerField *Q_TransID3;
    TIntegerField *Q_TransDSDesigner8;
    TStringField *Q_TransDSDesigner9;
    TIntegerField *Q_TransID4;
    TIntegerField *Q_TransDSDesigner10;
    TStringField *Q_TransDSDesigner11;
    TStringField *Q_TransDSDesigner12;
    TStringField *Q_TransDSDesigner13;
    TStringField *Q_TransDSDesigner14;
    TIntegerField *Q_TransDSDesigner1ID;
    TIntegerField *Q_TransDSDesigner1;
    TStringField *Q_TransDSDesigner15;
    TStringField *Q_TransDSDesigner16;
    TStringField *Q_TransDSDesigner17;
    TStringField *Q_TransDSDesigner18;
    TIntegerField *Q_TransDSDesigner2ID;
    TIntegerField *Q_TransDSDesigner22;
    TStringField *Q_TransDSDesigner23;
    TStringField *Q_TransDSDesigner24;
    TStringField *Q_TransDSDesigner25;
    TStringField *Q_TransDSDesigner26;
    TStringField *Q_TransDSDesigner19;
    TBCDField *Q_TransDSDesigner20;
    TIntegerField *Q_TransNo2;
    TIntegerField *Q_TransID5;
    TIntegerField *Q_TransDSDesigner21;
    TStringField *Q_TransDSDesigner27;
    TStringField *Q_TransDSDesigner28;
    TStringField *Q_TransDSDesigner29;
    TStringField *Q_TransDSDesigner30;
    TIntegerField *Q_TransID6;
    TIntegerField *Q_TransDSDesigner31;
    TStringField *Q_TransDSDesigner32;
    TStringField *Q_TransDSDesigner33;
    TStringField *Q_TransDSDesigner34;
    TBCDField *Q_TransDSDesigner39;
    TIntegerField *Q_TransID7;
    TIntegerField *Q_TransDSDesigner40;
    TStringField *Q_TransDSDesigner41;
    TBCDField *Q_TransDSDesigner42;
    TBCDField *Q_TransDSDesigner43;
    TBCDField *Q_TransDSDesigner44;
    TStringField *Q_TransDSDesigner45;
    TIntegerField *Q_TransDSDesigner46;
    TStringField *Q_TransDSDesigner47;
    TDateTimeField *Q_TransDSDesigner48;
    TDateTimeField *Q_TransDSDesigner49;
    TIntegerField *Q_TransID8;
    TIntegerField *Q_TransDSDesigner50;
    TIntegerField *Q_TransDSDesigner51;
    TIntegerField *Q_TransDSDesigner54;
    TComboBox *PlaceCombo;
    TComboBox *UnitCombo;
    TLabel *Label3;
    TStringField *Q_TransDSDesigner;
    TPanel *FooterPanel;
    TButton *ClearGridButton;
    TButton *btnOk;
    TButton *btnCancel;
    TButton *ClearButton;
    TButton *FilterShowButton;
    TCobEdit *TokuCodeEdit;
    TCobEdit *TokuNameEdit;
    TCobEdit *HinCodeEdit;
    TCobEdit *HinNameEdit;
    TCobEdit *Item1CodeEdit;
    TCobEdit *Item1NameEdit;
    TCobEdit *Item2CodeEdit;
    TCobEdit *Item2NameEdit;
    TButton *TokuButton;
    TButton *HinButton;
    TButton *Item1Button;
    TButton *Item2Button;
    TButton *CarNoButton;
    TCobEdit *CarNoEdit;
    TBevel *Bevel1;
	void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
	void __fastcall FirstButtonClick(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall LastButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnOkClick(TObject *Sender);
	void __fastcall DBGridDblClick(TObject *Sender);
    void __fastcall PriorDateButtonClick(TObject *Sender);
    void __fastcall NextDateButtonClick(TObject *Sender);
    void __fastcall ClearGridButtonClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FilterShowButtonClick(TObject *Sender);
    void __fastcall ClearButtonClick(TObject *Sender);
    void __fastcall TokuButtonClick(TObject *Sender);
    void __fastcall HinButtonClick(TObject *Sender);
    void __fastcall Item1ButtonClick(TObject *Sender);
    void __fastcall Item2ButtonClick(TObject *Sender);
    void __fastcall TokuCodeEditChange(TObject *Sender);
    void __fastcall HinCodeEditChange(TObject *Sender);
    void __fastcall Item1CodeEditChange(TObject *Sender);
    void __fastcall Item2CodeEditChange(TObject *Sender);
private:	// ユーザー宣言
    bool first_;
    int rec_no_;

    int place_id_;
    bool grid_cleared_;
public:		// ユーザー宣言
	__fastcall TDataListForm(TComponent* Owner);
	int selected_id;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataListForm *DataListForm;
//---------------------------------------------------------------------------
#endif
