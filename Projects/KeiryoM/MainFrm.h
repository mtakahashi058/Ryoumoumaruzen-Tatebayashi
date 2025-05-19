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
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
enum InputMode {imFirst, imSecond, imMod};
//---------------------------------------------------------------------------
#include <map>
typedef std::map<AnsiString, int> ColInfoMap;
typedef std::map<int, ColInfoMap> CellsMap;
typedef std::map<int, int>        IntIntMap;
typedef std::map<int, AnsiString> IntStrMap;
typedef std::map<IntIntMap, AnsiString> CoordToNameMap;
typedef std::map<AnsiString, IntIntMap> NameToCoordMap;
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
	TPanel *WeightPanel;
    TLabel *kgPanel;
	TPanel *TairyuPanel;
	TADOQuery *Q_Tairyu;
	TDataSource *dsTairyu;
	TLabel *Label16;
	TDBCtrlGrid *TairyuGrid;
	TLabel *TairyuTokuisakiLabel;
	TDBText *TairyuCarNameText;
	TDBText *TairyuTokuisakiText;
	TDBText *TairyuDateText;
	TLabel *TairyuDateLabel;
	TShape *Shape1;
	TShape *Shape2;
	TScrollBox *ScrollBox;
	TPanel *SharyoPanel;
	TButton *SharyoButton;
	TCobEdit *ShabanEdit;
	TCobEdit *SharyoNameEdit;
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
	TPanel *BikoPanel;
	TButton *BikoButton;
	TCobEdit *BikoEdit;
	TLabel *Label20;
	TDateTimePicker *KeiryoDatePicker;
	TLabel *Label21;
	TCobEdit *KeiryoNoEdit;
    TLabel *KyotenLabel;
	TComboBox *PlaceCombo;
	TIntegerField *Q_TairyuDSDesigner;
	TIntegerField *Q_TairyuNo;
	TStringField *Q_TairyuDSDesigner2;
	TStringField *Q_TairyuDSDesigner3;
	TLabel *Label4;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label23;
	TADOQuery *Q_Meisai;
	TDataSource *dsMeisai;
	TAutoIncField *Q_MeisaiID;
	TIntegerField *Q_MeisaiNo;
	TIntegerField *Q_MeisaiNo2;
	TIntegerField *Q_MeisaiID2;
	TStringField *Q_MeisaiDSDesigner;
	TBCDField *Q_MeisaiDSDesigner2;
	TDateTimeField *Q_MeisaiDSDesigner1;
	TBCDField *Q_MeisaiDSDesigner3;
	TDateTimeField *Q_MeisaiDSDesigner22;
	TBCDField *Q_MeisaiDSDesigner4;
	TBCDField *Q_MeisaiDSDesigner5;
	TBCDField *Q_MeisaiDSDesigner6;
	TBCDField *Q_MeisaiDSDesigner7;
	TBCDField *Q_MeisaiDSDesigner8;
	TIntegerField *Q_MeisaiID3;
	TStringField *Q_MeisaiDSDesigner9;
	TBCDField *Q_MeisaiDSDesigner10;
	TBCDField *Q_MeisaiDSDesigner11;
	TStringField *Q_MeisaiDSDesigner12;
	TIntegerField *Q_MeisaiDSDesigner13;
	TShape *Shape3;
	TShape *Shape4;
	TClientSocket *ClientSocket;
	TIntegerField *Q_TairyuDSDesigner5;
	TDBText *TairyuCarNoText;
	TLabel *Label2;
	TDateTimeField *Q_TairyuDSDesigner1;
	TAutoIncField *Q_TairyuID;
	TCheckBox *AutoPrintCheck;
	TTimer *SocketReopenTimer;
	TCheckBox *DataDeleteCheck;
    TTimer *TairyuTimer;
    TCheckBox *HideTimeCheck;
    TStrColGrid *SCGrid;
    TScrollBox *MeisaiScrollBox;
    TButton *MeisaiAddButton;
    TButton *MeisaiDeleteButton;
    TButton *RecalcButton;
    TComboBox *HannyuCombo;
    TPanel *TotalPanel;
    TLabel *TotalWeightTitle;
    TLabel *TotalWeightLabel;
    TLabel *MoneyTitle;
    TLabel *MoneyLabel;
    TLabel *TaxTitle;
    TLabel *TaxLabel;
    TLabel *TotalMoneyTitle;
    TLabel *TotalMoneyLabel;
    TShape *TotalWeightShape;
    TShape *MoneyShape;
    TShape *TaxShape;
    TShape *TotalMoneyShape;
    TCheckBox *PostMessageCheck;
    TLabel *Label1;
    TDateTimePicker *KeiryoTimePicker;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SharyoPanelEnter(TObject *Sender);
	void __fastcall SharyoPanelExit(TObject *Sender);
	void __fastcall Action1Execute(TObject *Sender);
	void __fastcall Action2Execute(TObject *Sender);
	void __fastcall Action3Execute(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action8Execute(TObject *Sender);
	void __fastcall Action9Execute(TObject *Sender);
	void __fastcall Action10Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall ShabanEditChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall HannyuComboKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TokuCodeEditChange(TObject *Sender);
	void __fastcall Komoku1CodeEditChange(TObject *Sender);
	void __fastcall Komoku2CodeEditChange(TObject *Sender);
	void __fastcall ClientSocketError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall ClientSocketRead(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall Action6Execute(TObject *Sender);
	void __fastcall Action7Execute(TObject *Sender);
	void __fastcall Q_TairyuAfterOpen(TDataSet *DataSet);
	void __fastcall ShabanEditExit(TObject *Sender);
	void __fastcall OnSelectTairyu(TObject *Sender);
	void __fastcall PlaceComboChange(TObject *Sender);
	void __fastcall OnWeightRecalc(TObject *Sender);
	void __fastcall OnAmountRecalc(TObject *Sender);
	void __fastcall OnSalesTaxRecalc(TObject *Sender);
	void __fastcall Q_TairyuBeforeOpen(TDataSet *DataSet);
	void __fastcall TokuButtonClick(TObject *Sender);
	void __fastcall Komoku1ButtonClick(TObject *Sender);
	void __fastcall Komoku2ButtonClick(TObject *Sender);
	void __fastcall FirstWEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall BikoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OnItemsChanged(TObject *Sender);
	void __fastcall TrailerWeightButtonClick(TObject *Sender);
	void __fastcall SocketReopenTimerTimer(TObject *Sender);
	void __fastcall KeiryoNoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TokuCodeEditExit(TObject *Sender);
	void __fastcall Komoku1CodeEditExit(TObject *Sender);
	void __fastcall Komoku2CodeEditExit(TObject *Sender);
    void __fastcall TairyuTimerTimer(TObject *Sender);
    void __fastcall WeighingDateTimePickerChange(TObject *Sender);
    void __fastcall KeiryoDatePickerChange(TObject *Sender);
    void __fastcall SCGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall MeisaiAddButtonClick(TObject *Sender);
    void __fastcall SCGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall SCGridSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall SCGridSetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
    void __fastcall SCGridDblClick(TObject *Sender);
    void __fastcall MeisaiDeleteButtonClick(TObject *Sender);
    void __fastcall SCGridClick(TObject *Sender);
    void __fastcall RecalcButtonClick(TObject *Sender);
    void __fastcall SCGridKeyPress(TObject *Sender, char &Key);
    void __fastcall Action4Execute(TObject *Sender);
    void __fastcall BikoEditKeyPress(TObject *Sender, char &Key);
    void __fastcall SCGridCellChanged(TObject *Sender, int AOldCol,
          int AOldRow, int ANewCol, int ANewRow);
    void __fastcall ShabanEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall SharyoButtonClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall ClearForm();
	void __fastcall ApplyConfig();
	AnsiString __fastcall ZeroSuppress(Currency v);
	bool __fastcall LoadFromID(int id);
    bool __fastcall LoadFromID_Insert(int id, int insert_line_no);

	void __fastcall StartWeighing();
	void __fastcall ContinueWeighing(int id);
	void __fastcall PostWeighing();
	void __fastcall Print(int keiryo_id);
	bool __fastcall CheckOverload();
	bool __fastcall ValidateForm();
    void __fastcall UpdateCheck();
    bool __fastcall CheckEdit();

	void __fastcall GetCalcInfo();
    void __fastcall CalcWeight(int row);
    void __fastcall CalcAmount(int row);
    void __fastcall CalcSalesTax(int row);

	void __fastcall SetMode(InputMode mode);
    int __fastcall GetHeaderID(int keiryo_id);
    int __fastcall GetTotalWeight();
    void __fastcall GetTotalMoney();
    void __fastcall Recalc_NoMsg();
    TDateTime __fastcall GetLastKeiryoTime(int date, int slip_no, int place_id);
    TDateTime __fastcall GetTimePicker_ZeroSec();
    bool __fastcall SharyoCheck();
    int __fastcall CalcNextRow(int keiryo_id);

    // StrColGridの関数
    void __fastcall ClearDetailGrid();
    void __fastcall SetGridTitle();
    void __fastcall SCGrid_SelectCell(TStrColGrid *grid, int left, int top, int right, int bottom);
    void __fastcall Line_Add();               // 行追加用
    void __fastcall Line_Insert(int line_no); // 行挿入用
    int __fastcall GetColNo(AnsiString name); // 項目名からCol取得
    int __fastcall GetRowNo(AnsiString name); // 項目名から何行目かを取得
    int __fastcall CalcRowNo(AnsiString name, int row); // １明細が複数行の時、項目名と行番号から
                                                        // 対象項目のrowを返す
    int __fastcall GetLineNo(int row, int detail_line); // 行数取得
    int __fastcall GetMaxLineNo();   // 登録対象の行No取得
    int __fastcall GetMaxLineNo_M(); // 登録対象の行No取得 条件が品目コード
    AnsiString __fastcall GetCellName(int col, int row);
    AnsiString __fastcall GetColName(CoordToNameMap::iterator ctnm);
    Currency __fastcall GetSuryoCellValue(AnsiString cell);

	Currency old_weight_;
	Currency cur_weight_;
	int keiryo_id_;
	NsRecordSet keiryo_set_;		// 計量レコード keiryo_id_ と対応
									// このプログラムは単品用なので NsRecord でもいいけど
									// 多段でも流用できるように Set で
    int id_total_;                  // 滞留データID合計

    int toku_id_;
	NsRecord toku_rec_;				// 得意先情報

    int default_index;

    // 車両自動登録関係
    bool new_car_;
	int car_id_;
    NsFieldSet new_car_fields_;

    int tani_id_;
    int item_relate_hin_id_;        // 項目関連マスタの品目ID
	int keiryo_count_;				// 計量回数
	Currency gross_limit_;			// 車両総重量
	Currency net_limit_;			// 最大積載量
    int slip_tax_;                  // 伝票消費税

    int detail_col;                 // 明細に表示する項目数
    int line_end_col;               // １明細の最終項目のcol位置
    int max_row;                    // 明細のRowCount
    int max_line_no_;               // 明細の最大行No
    int detail_line;                // 1計量データに対する明細行数
                                    // 基本2行 項目使用状態により1行
    int standard_tani_code_;        // 標準単位
    int money_print_div_;           // 計量伝票の金額印字区分
    bool delete_flag_;              // 明細削除フラグ


	NsRecordSet kyoten_set_;

    CellsMap       col_map_;           // <項目数, <項目名, Width>>
    IntIntMap      id_edit_map_;
    IntIntMap      row_id_map_;        // rowに計量IDを入れる
    IntIntMap      row_lineno_map_;    // rowに行Noを入れる
    IntIntMap      line_colcount_map_; // 行数ごとのColCount

    IntIntMap      col_row_map_;      // <col, row> rowは何行目かを入れる
    NameToCoordMap name_coord_map_;   // <項目名, <col, row>>
    CoordToNameMap coord_name_map_;   // <<col, row>, 項目名>>
    ColInfoMap     col_width_map_;    // <項目名, Width>

    void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);

	Currency __fastcall GetWeight();
	InputMode __fastcall GetMode();
	int __fastcall GetPlaceID();

    int major_version, minor_version;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
