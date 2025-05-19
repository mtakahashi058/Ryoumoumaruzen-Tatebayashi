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
__published:    // IDE 管理のコンポーネント
    TPanel *FilterPanel;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TDateTimePicker *dtpDateFrom;
    TDateTimePicker *dtpDateTo;
    TCobEdit *cedtSearch;
    TDataSource *DataSource;
    TADOQuery *Q_Keiryo;
    TActionList *ActionList1;
    TAction *Action5;
    TSaveDialog *SaveDialog;
    TButton *PriorDateButton;
    TButton *NextDateButton;
    TButton *btnExec;
    TPanel *ClientPanel;
    TDBGrid *DBGrid;
    TPanel *MeisaiPanel;
    TLabel *Label6;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label14;
    TLabel *TokuLabel;
    TLabel *MeigLabel;
    TLabel *Item1Label;
    TLabel *Item2Label;
    TLabel *Label17;
    TLabel *Label18;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label21;
    TLabel *Label22;
    TLabel *Label23;
    TLabel *Label24;
    TLabel *CoordLabel;
    TLabel *ReduceLabel;
    TLabel *Label27;
    TLabel *Label28;
    TLabel *Label30;
    TLabel *Label31;
    TLabel *Label32;
    TLabel *Label33;
    TLabel *Label34;
    TLabel *Label35;
    TSpeedButton *FirstButton;
    TSpeedButton *PriorButton;
    TSpeedButton *NextButton;
    TSpeedButton *LastButton;
    TDBEdit *DBEdit1;
    TDBEdit *DBEdit2;
    TDBEdit *DBEdit3;
    TDBEdit *DBEdit4;
    TDBEdit *DBEdit5;
    TDBEdit *DBEdit6;
    TDBEdit *DBEdit7;
    TDBEdit *DBEdit8;
    TDBEdit *DBEdit9;
    TDBEdit *DBEdit10;
    TDBEdit *DBEdit11;
    TDBEdit *DBEdit12;
    TDBEdit *DBEdit13;
    TDBEdit *DBEdit14;
    TDBEdit *DBEdit15;
    TDBEdit *DBEdit16;
    TDBEdit *DBEdit17;
    TDBEdit *DBEdit18;
    TDBEdit *DBEdit19;
    TDBEdit *DBEdit20;
    TDBEdit *DBEdit21;
    TDBEdit *DBEdit22;
    TDBEdit *DBEdit23;
    TDBEdit *DBEdit24;
    TDBEdit *DBEdit25;
    TDBEdit *DBEdit26;
    TDBEdit *DBEdit27;
    TCheckBox *DispMeisaiCheckBox;
    TIntegerField *Q_KeiryoID;
    TIntegerField *Q_KeiryoDSDesigner;
    TIntegerField *Q_KeiryoDSDesigner2;
    TIntegerField *Q_KeiryoDSDesigner3;
    TIntegerField *Q_KeiryoDSDesigner4;
    TIntegerField *Q_KeiryoID2;
    TStringField *Q_KeiryoDSDesigner5;
    TIntegerField *Q_KeiryoNo;
    TIntegerField *Q_KeiryoDSDesigner6;
    TStringField *Q_KeiryoDSDesigner7;
    TIntegerField *Q_KeiryoID3;
    TIntegerField *Q_KeiryoDSDesigner8;
    TStringField *Q_KeiryoDSDesigner9;
    TIntegerField *Q_KeiryoID4;
    TIntegerField *Q_KeiryoDSDesigner10;
    TStringField *Q_KeiryoDSDesigner11;
    TStringField *Q_KeiryoDSDesigner12;
    TStringField *Q_KeiryoDSDesigner13;
    TStringField *Q_KeiryoDSDesigner14;
    TIntegerField *Q_KeiryoDSDesigner1ID;
    TIntegerField *Q_KeiryoDSDesigner1;
    TStringField *Q_KeiryoDSDesigner15;
    TStringField *Q_KeiryoDSDesigner16;
    TStringField *Q_KeiryoDSDesigner17;
    TStringField *Q_KeiryoDSDesigner18;
    TIntegerField *Q_KeiryoDSDesigner2ID;
    TIntegerField *Q_KeiryoDSDesigner22;
    TStringField *Q_KeiryoDSDesigner23;
    TStringField *Q_KeiryoDSDesigner24;
    TStringField *Q_KeiryoDSDesigner25;
    TStringField *Q_KeiryoDSDesigner26;
    TStringField *Q_KeiryoDSDesigner19;
    TBCDField *Q_KeiryoDSDesigner20;
    TIntegerField *Q_KeiryoNo2;
    TIntegerField *Q_KeiryoID5;
    TIntegerField *Q_KeiryoDSDesigner21;
    TStringField *Q_KeiryoDSDesigner27;
    TStringField *Q_KeiryoDSDesigner28;
    TStringField *Q_KeiryoDSDesigner29;
    TStringField *Q_KeiryoDSDesigner30;
    TIntegerField *Q_KeiryoID6;
    TIntegerField *Q_KeiryoDSDesigner31;
    TStringField *Q_KeiryoDSDesigner32;
    TStringField *Q_KeiryoDSDesigner33;
    TStringField *Q_KeiryoDSDesigner34;
    TBCDField *Q_KeiryoDSDesigner110;
    TDateTimeField *Q_KeiryoDSDesigner111;
    TBCDField *Q_KeiryoDSDesigner210;
    TDateTimeField *Q_KeiryoDSDesigner211;
    TBCDField *Q_KeiryoDSDesigner35;
    TBCDField *Q_KeiryoDSDesigner36;
    TBCDField *Q_KeiryoDSDesigner37;
    TBCDField *Q_KeiryoDSDesigner38;
    TBCDField *Q_KeiryoDSDesigner39;
    TIntegerField *Q_KeiryoID7;
    TIntegerField *Q_KeiryoDSDesigner40;
    TStringField *Q_KeiryoDSDesigner41;
    TBCDField *Q_KeiryoDSDesigner42;
    TBCDField *Q_KeiryoDSDesigner43;
    TBCDField *Q_KeiryoDSDesigner44;
    TStringField *Q_KeiryoDSDesigner45;
    TIntegerField *Q_KeiryoDSDesigner46;
    TStringField *Q_KeiryoDSDesigner47;
    TDateTimeField *Q_KeiryoDSDesigner48;
    TDateTimeField *Q_KeiryoDSDesigner49;
    TComboBox *UnitCombo;
    TComboBox *StateCombo;
    TLabel *Label10;
    TComboBox *PlaceCombo;
    TButton *ClearButton;
    TButton *FilterShowButton;
    TBevel *Bevel1;
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
    TPanel *FooterPanel;
    TButton *ClearGridButton;
    TButton *btnSave;
    TButton *btnOk;
    TButton *btnCancel;
	TStringField *Q_KeiryoNo3;
	TPanel *IngPanel;
	TLabel *SumLabel;
	TLabel *Label7;
	TLabel *Label13;
	TButton *Button1;
	TComboBox *OrderComboBox;
	TCheckBox *KoujunCheckBox;
    void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
    void __fastcall FirstButtonClick(TObject *Sender);
    void __fastcall PriorButtonClick(TObject *Sender);
    void __fastcall NextButtonClick(TObject *Sender);
    void __fastcall LastButtonClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Q_KeiryoAfterScroll(TDataSet *DataSet);
    void __fastcall DispMeisaiCheckBoxClick(TObject *Sender);
    void __fastcall Action5Execute(TObject *Sender);
    void __fastcall btnCancelClick(TObject *Sender);
    void __fastcall btnOkClick(TObject *Sender);
    void __fastcall DBGridDblClick(TObject *Sender);
    void __fastcall btnSaveClick(TObject *Sender);
    void __fastcall PriorDateButtonClick(TObject *Sender);
    void __fastcall NextDateButtonClick(TObject *Sender);
    void __fastcall ClearGridButtonClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FilterShowButtonClick(TObject *Sender);
    void __fastcall ClearButtonClick(TObject *Sender);
    void __fastcall TokuCodeEditChange(TObject *Sender);
    void __fastcall HinCodeEditChange(TObject *Sender);
    void __fastcall Item1CodeEditChange(TObject *Sender);
    void __fastcall Item2CodeEditChange(TObject *Sender);
    void __fastcall TokuButtonClick(TObject *Sender);
    void __fastcall HinButtonClick(TObject *Sender);
    void __fastcall Item1ButtonClick(TObject *Sender);
    void __fastcall Item2ButtonClick(TObject *Sender);
	void __fastcall Q_KeiryoCalcFields(TDataSet *DataSet);
	void __fastcall cedtSearchKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OrderComboBoxChange(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:    // ユーザー宣言
    void __fastcall SetButtonEnabled();

    bool first_;
    int rec_no_;
    bool grid_cleared_;

    int place_id_;
public:     // ユーザー宣言
    __fastcall TDataListForm(TComponent* Owner);
    int selected_id;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataListForm *DataListForm;
//---------------------------------------------------------------------------
#endif
