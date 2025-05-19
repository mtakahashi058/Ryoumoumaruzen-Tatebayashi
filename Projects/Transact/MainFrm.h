//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <dbcgrids.hpp>
#include <DBCtrls.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "CEdit.h"
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ScktComp.hpp>
#include "StrCGrid.hpp"
//---------------------------------------------------------------------------
enum InputMode {imNew, imMod};
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TopPanel;
	TPanel *KeyPanel;
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
	TStatusBar *StatusBar;
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
	TPanel *ModePanel;
	TScrollBox *ScrollBox;
	TPanel *SharyoPanel;
	TButton *SharyoButton;
	TCobEdit *ShabanEdit;
	TCobEdit *SharyoNameEdit;
	TLabel *Label20;
    TDateTimePicker *DatePicker;
	TLabel *Label21;
    TCobEdit *NoEdit;
	TLabel *Label22;
	TComboBox *PlaceCombo;
    TPanel *TokuPanel;
    TButton *TokuButton;
    TCobEdit *TokuCodeEdit;
    TCobEdit *TokuNameEdit;
    TPanel *Komoku1Panel;
    TButton *Komoku1Button;
    TCobEdit *Komoku1CodeEdit;
    TCobEdit *Komoku1NameEdit;
    TPanel *Komoku2Panel;
    TButton *Komoku2Button;
    TCobEdit *Komoku2NameEdit;
    TCobEdit *Komoku2CodeEdit;
    TPanel *SummaryPanel;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *UAmountLabel;
    TLabel *UTotalZeiLabel;
    TLabel *Label5;
    TLabel *Label7;
    TPageControl *PageControl;
    TTabSheet *TransSheet;
    TTabSheet *KeiryoSheet;
    TStrColGrid *DetailGrid;
    TStrColGrid *KeiryoGrid;
    TLabel *Label3;
    TPanel *Panel1;
    TLabel *Label4;
    TLabel *Label8;
    TLabel *SAmountLabel;
    TLabel *STotalZeiLabel;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TPanel *BikoPanel;
    TButton *BikoButton;
    TCobEdit *BikoEdit;
    TPanel *Panel2;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label18;
    TCobEdit *KeiryoDate;
    TCobEdit *KeiryoNo;
    TPanel *Panel3;
    TButton *RowInsertButton;
    TButton *RowDeleteButton;
    TButton *TankaUpdateButton;
    TPanel *Panel4;
    TStrColGrid *DefTankaGrid;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SharyoPanelEnter(TObject *Sender);
	void __fastcall SharyoPanelExit(TObject *Sender);
	void __fastcall Action1Execute(TObject *Sender);
	void __fastcall Action2Execute(TObject *Sender);
	void __fastcall Action3Execute(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action8Execute(TObject *Sender);
	void __fastcall Action9Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall ShabanEditChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall TokuCodeEditChange(TObject *Sender);
	void __fastcall Komoku1CodeEditChange(TObject *Sender);
	void __fastcall Komoku2CodeEditChange(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall Action6Execute(TObject *Sender);
	void __fastcall Action7Execute(TObject *Sender);
	void __fastcall ShabanEditExit(TObject *Sender);
	void __fastcall PlaceComboChange(TObject *Sender);
	void __fastcall TokuButtonClick(TObject *Sender);
	void __fastcall Komoku1ButtonClick(TObject *Sender);
	void __fastcall Komoku2ButtonClick(TObject *Sender);
	void __fastcall HinButtonClick(TObject *Sender);
	void __fastcall TaniButtonClick(TObject *Sender);
	void __fastcall NoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TokuCodeEditExit(TObject *Sender);
	void __fastcall Komoku1CodeEditExit(TObject *Sender);
	void __fastcall Komoku2CodeEditExit(TObject *Sender);
    void __fastcall DatePickerChange(TObject *Sender);
    void __fastcall DetailGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall DetailGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall DetailGridSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall DetailGridSetEditText(TObject *Sender, int ACol,
          int ARow, const AnsiString Value);
    void __fastcall DetailGridCellChanged(TObject *Sender, int AOldCol,
          int AOldRow, int ANewCol, int ANewRow);
    void __fastcall PageControlEnter(TObject *Sender);
    void __fastcall Action4Execute(TObject *Sender);
    void __fastcall RowDeleteButtonClick(TObject *Sender);
    void __fastcall PageControlChange(TObject *Sender);
    void __fastcall RowInsertButtonClick(TObject *Sender);
    void __fastcall TankaUpdateButtonClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall ClearForm();
	void __fastcall ApplyConfig();
	AnsiString __fastcall ZeroSuppress(Currency v);
	bool __fastcall LoadFromID(int id);

	void __fastcall PostRecords();
	void __fastcall Print(int record_id);
	bool __fastcall ValidateForm();

	void __fastcall SetMode(InputMode mode);
	InputMode __fastcall GetMode();

    void __fastcall GetCalcInfo(int row);
    void __fastcall CalcAmount(int row, bool update = true);
    void __fastcall CalcTotal();

    int trans_id_;                  // 取引データ 先頭ID
    NsRecordSet trans_set_;         // 取引レコードセット
    int keiryo_id_;                 // 計量ID（ある場合）

	int toku_id_;                   //
	NsRecord toku_rec_;				// 得意先情報

	int car_id_;

    std::map<int, int> deftanka_table_;    // 各明細ごとに標準単価かどうか
    std::map<int, int> zei_table_;  // 各明細ごとの税額
    std::map<int, bool> sundry_table_;  // 各明細ごとの諸口かどうか
    int total_zei_;                 // 合計消費税

	NsRecordSet kyoten_set_;

    void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);

	int __fastcall GetPlaceID();
    AnsiString __fastcall GetPlaceText();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
