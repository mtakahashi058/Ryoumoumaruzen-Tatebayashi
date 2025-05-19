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
__published:	// IDE �Ǘ��̃R���|�[�l���g
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
private:	// ���[�U�[�錾
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

    // StrColGrid�̊֐�
    void __fastcall ClearDetailGrid();
    void __fastcall SetGridTitle();
    void __fastcall SCGrid_SelectCell(TStrColGrid *grid, int left, int top, int right, int bottom);
    void __fastcall Line_Add();               // �s�ǉ��p
    void __fastcall Line_Insert(int line_no); // �s�}���p
    int __fastcall GetColNo(AnsiString name); // ���ږ�����Col�擾
    int __fastcall GetRowNo(AnsiString name); // ���ږ����牽�s�ڂ����擾
    int __fastcall CalcRowNo(AnsiString name, int row); // �P���ׂ������s�̎��A���ږ��ƍs�ԍ�����
                                                        // �Ώۍ��ڂ�row��Ԃ�
    int __fastcall GetLineNo(int row, int detail_line); // �s���擾
    int __fastcall GetMaxLineNo();   // �o�^�Ώۂ̍sNo�擾
    int __fastcall GetMaxLineNo_M(); // �o�^�Ώۂ̍sNo�擾 �������i�ڃR�[�h
    AnsiString __fastcall GetCellName(int col, int row);
    AnsiString __fastcall GetColName(CoordToNameMap::iterator ctnm);
    Currency __fastcall GetSuryoCellValue(AnsiString cell);

	Currency old_weight_;
	Currency cur_weight_;
	int keiryo_id_;
	NsRecordSet keiryo_set_;		// �v�ʃ��R�[�h keiryo_id_ �ƑΉ�
									// ���̃v���O�����͒P�i�p�Ȃ̂� NsRecord �ł���������
									// ���i�ł����p�ł���悤�� Set ��
    int id_total_;                  // �ؗ��f�[�^ID���v

    int toku_id_;
	NsRecord toku_rec_;				// ���Ӑ���

    int default_index;

    // �ԗ������o�^�֌W
    bool new_car_;
	int car_id_;
    NsFieldSet new_car_fields_;

    int tani_id_;
    int item_relate_hin_id_;        // ���ڊ֘A�}�X�^�̕i��ID
	int keiryo_count_;				// �v�ʉ�
	Currency gross_limit_;			// �ԗ����d��
	Currency net_limit_;			// �ő�ύڗ�
    int slip_tax_;                  // �`�[�����

    int detail_col;                 // ���ׂɕ\�����鍀�ڐ�
    int line_end_col;               // �P���ׂ̍ŏI���ڂ�col�ʒu
    int max_row;                    // ���ׂ�RowCount
    int max_line_no_;               // ���ׂ̍ő�sNo
    int detail_line;                // 1�v�ʃf�[�^�ɑ΂��閾�׍s��
                                    // ��{2�s ���ڎg�p��Ԃɂ��1�s
    int standard_tani_code_;        // �W���P��
    int money_print_div_;           // �v�ʓ`�[�̋��z�󎚋敪
    bool delete_flag_;              // ���׍폜�t���O


	NsRecordSet kyoten_set_;

    CellsMap       col_map_;           // <���ڐ�, <���ږ�, Width>>
    IntIntMap      id_edit_map_;
    IntIntMap      row_id_map_;        // row�Ɍv��ID������
    IntIntMap      row_lineno_map_;    // row�ɍsNo������
    IntIntMap      line_colcount_map_; // �s�����Ƃ�ColCount

    IntIntMap      col_row_map_;      // <col, row> row�͉��s�ڂ�������
    NameToCoordMap name_coord_map_;   // <���ږ�, <col, row>>
    CoordToNameMap coord_name_map_;   // <<col, row>, ���ږ�>>
    ColInfoMap     col_width_map_;    // <���ږ�, Width>

    void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
public:		// ���[�U�[�錾
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
