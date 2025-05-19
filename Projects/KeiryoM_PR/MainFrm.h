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
#include "HF04Thread.h"
//---------------------------------------------------------------------------
enum InputMode {imFirst, imSecond, imMod};
const int limit_line_ = 6;

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
	TLabel *Label1;
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
	TLabel *Label22;
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
	TShape *Shape3;
	TShape *Shape4;
	TClientSocket *ClientSocket;
	TIntegerField *Q_TairyuDSDesigner5;
	TDBText *TairyuCarNoText;
	TLabel *Label2;
	TDateTimeField *Q_TairyuDSDesigner1;
	TAutoIncField *Q_TairyuID;
	TTimer *SocketReopenTimer;
    TTimer *TairyuTimer;
	TPanel *RirekiPanel;
	TPanel *Panel2;
	TLabel *Label7;
	TLabel *Label15;
	TShape *Shape5;
	TCheckBox *DispRirekiCheckBox;
	TADOQuery *Q_Rireki;
	TDataSource *dsRireki;
	TIntegerField *Q_RirekiID;
	TIntegerField *Q_RirekiDSDesigner;
	TIntegerField *Q_RirekiID2;
	TIntegerField *Q_RirekiDSDesigner2;
	TStringField *Q_RirekiDSDesigner3;
	TIntegerField *Q_RirekiID3;
	TIntegerField *Q_RirekiDSDesigner4;
	TStringField *Q_RirekiDSDesigner5;
	TIntegerField *Q_RirekiDSDesigner1ID;
	TIntegerField *Q_RirekiDSDesigner1;
	TStringField *Q_RirekiDSDesigner12;
	TIntegerField *Q_RirekiDSDesigner2ID;
	TIntegerField *Q_RirekiDSDesigner22;
	TStringField *Q_RirekiDSDesigner23;
	TButton *Button1;
	TButton *Button2;
	TAction *ActionRirekiBefore;
	TAction *ActionRirekiNext;
	TLabel *RirekiOrderLabel;
	TLabel *RirekiDateLabel;
	TLabel *RirekiTokuNameLabel;
	TLabel *RirekiTokuCodeLabel;
	TLabel *RirekiKomoku1NameLabel;
	TLabel *RirekiKomoku1CodeLabel;
	TLabel *RirekiKomoku2NameLabel;
	TLabel *RirekiKomoku2CodeLabel;
	TLabel *TairyuKensuLabel;
	TCheckBox *AutoPrintCheck;
	TCheckBox *DataDeleteCheck;
	TCheckBox *HideTimeCheck;
	TScrollBox *MeisaiScrollBox1;
	TCobEdit *GyoEdit1;
	TCobEdit *HinCodeEdit1;
	TCobEdit *HinNameEdit1;
	TCobEdit *GyoTitleEdit;
	TCobEdit *HinCodeTitleEdit;
	TCobEdit *HinNameTitleEdit;
	TScrollBox *MeisaiScrollBox2;
	TCobEdit *WeightEdit11;
	TCobEdit *WeightTitleEdit1;
	TCobEdit *WeightTitleEdit2;
	TCobEdit *WeightEdit12;
	TCobEdit *ChoseiTitleEdit;
	TCobEdit *ChoseiPerEdit1;
	TCobEdit *ChoseiWeightEdit1;
	TCobEdit *BikiWeightTitleEdit;
	TCobEdit *BikiWeightEdit1;
	TCobEdit *ShomiTitleEdit;
	TCobEdit *ShomiEdit1;
	TCobEdit *TaniCodeEdit1;
	TCobEdit *TaniTitleEdit;
	TCobEdit *TaniNameEdit1;                                           
	TCobEdit *SuryoEdit1;
	TCobEdit *SuryoTitleEdit;
	TCobEdit *TankaEdit1;
	TCobEdit *TankaTitleEdit;
	TCobEdit *KingakuEdit1;
	TCobEdit *KingakuTitleEdit;
	TCobEdit *BikoEdit1;
	TCobEdit *BikoTitleEdit;
	TShape *Shape6;
	TCobEdit *GyoEdit2;
	TCobEdit *HinCodeEdit2;
	TCobEdit *HinNameEdit2;
	TCobEdit *GyoEdit3;
	TCobEdit *HinCodeEdit3;
	TCobEdit *HinNameEdit3;
	TCobEdit *GyoEdit4;
	TCobEdit *HinCodeEdit4;
	TCobEdit *HinNameEdit4;
	TCobEdit *GyoEdit5;
	TCobEdit *HinCodeEdit5;
	TCobEdit *HinNameEdit5;
	TCobEdit *GyoEdit6;
	TCobEdit *HinCodeEdit6;
	TCobEdit *HinNameEdit6;
	TCobEdit *WeightEdit21;
	TCobEdit *WeightEdit22;
	TCobEdit *ChoseiPerEdit2;
	TCobEdit *ChoseiWeightEdit2;
	TCobEdit *BikiWeightEdit2;
	TCobEdit *ShomiEdit2;
	TCobEdit *TaniCodeEdit2;
	TCobEdit *TaniNameEdit2;
	TCobEdit *SuryoEdit2;
	TCobEdit *WeightEdit31;
	TCobEdit *WeightEdit32;
	TCobEdit *ChoseiPerEdit3;
	TCobEdit *ChoseiWeightEdit3;
	TCobEdit *BikiWeightEdit3;
	TCobEdit *ShomiEdit3;
	TCobEdit *TaniCodeEdit3;
	TCobEdit *TaniNameEdit3;
	TCobEdit *SuryoEdit3;
	TCobEdit *WeightEdit41;
	TCobEdit *WeightEdit42;
	TCobEdit *ChoseiPerEdit4;
	TCobEdit *ChoseiWeightEdit4;
	TCobEdit *BikiWeightEdit4;
	TCobEdit *ShomiEdit4;
	TCobEdit *TaniCodeEdit4;
	TCobEdit *TaniNameEdit4;
	TCobEdit *SuryoEdit4;
	TCobEdit *WeightEdit51;
	TCobEdit *WeightEdit52;
	TCobEdit *ChoseiPerEdit5;
	TCobEdit *ChoseiWeightEdit5;
	TCobEdit *BikiWeightEdit5;
	TCobEdit *ShomiEdit5;
	TCobEdit *TaniCodeEdit5;
	TCobEdit *TaniNameEdit5;
	TCobEdit *SuryoEdit5;
	TCobEdit *WeightEdit61;
	TCobEdit *WeightEdit62;
	TCobEdit *ChoseiPerEdit6;
	TCobEdit *ChoseiWeightEdit6;
	TCobEdit *BikiWeightEdit6;
	TCobEdit *ShomiEdit6;
	TCobEdit *TaniCodeEdit6;
	TCobEdit *TaniNameEdit6;
	TCobEdit *SuryoEdit6;
	TCobEdit *TankaEdit2;
	TCobEdit *KingakuEdit2;
	TCobEdit *BikoEdit2;
	TCobEdit *TankaEdit3;
	TCobEdit *KingakuEdit3;
	TCobEdit *BikoEdit3;
	TCobEdit *TankaEdit4;
	TCobEdit *KingakuEdit4;
	TCobEdit *BikoEdit4;
	TCobEdit *TankaEdit5;
	TCobEdit *KingakuEdit5;
	TCobEdit *BikoEdit5;
	TCobEdit *TankaEdit6;
	TCobEdit *KingakuEdit6;
	TCobEdit *BikoEdit6;
	TPanel *KingakuPanel;
	TButton *Button3;
	TCobEdit *ZeikomiEdit;
	TPanel *HannyuPanel;
	TButton *Button6;
	TComboBox *HannyuCombo;
	TStringGrid *StringGridID;
	TCheckBox *ShudoCheckBox;
    TPanel *Panel1;
    TLabel *WeightSumTitleLabel;
    TCobEdit *ShomiSumEdit;
    TLabel *KingakuSumTitleLabel;
    TCobEdit *KingakuSumEdit;
    TLabel *ShohizeiTitleLabel;
    TCobEdit *ShohizeiEdit;
    TLabel *Label3;
    TDateTimePicker *KeiryoTimePicker;
    TSpeedButton *MeisaiAddButton;
    TSpeedButton *RecalcButton;
    TCobEdit *ShouhizeiTitleEdit;
    TCobEdit *ShouhizeiEdit1;
    TCobEdit *ShouhizeiEdit2;
    TCobEdit *ShouhizeiEdit3;
    TCobEdit *ShouhizeiEdit4;
    TCobEdit *ShouhizeiEdit5;
    TCobEdit *ShouhizeiEdit6;
    TSpeedButton *MeisakiDeleteButton;
    TSpeedButton *AnbunButton;
    TIntegerField *Q_MeisaiID;
    TIntegerField *Q_MeisaiNo;
    TIntegerField *Q_MeisaiNo2;
    TIntegerField *Q_MeisaiID2;
    TIntegerField *Q_MeisaiDSDesigner;
    TStringField *Q_MeisaiDSDesigner2;
    TIntegerField *Q_MeisaiDSDesigner3;
    TDateTimeField *Q_MeisaiDSDesigner1;
    TIntegerField *Q_Meisai_1;
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
	void __fastcall HannyuCombo_KeyDown(TObject *Sender, WORD &Key,
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
	void __fastcall OnSelectTairyu(TObject *Sender);
	void __fastcall PlaceComboChange(TObject *Sender);
	void __fastcall Q_TairyuBeforeOpen(TDataSet *DataSet);
	void __fastcall TokuButtonClick(TObject *Sender);
	void __fastcall Komoku1ButtonClick(TObject *Sender);
	void __fastcall Komoku2ButtonClick(TObject *Sender);
	void __fastcall OnItemsChanged(TObject *Sender);
	void __fastcall SocketReopenTimerTimer(TObject *Sender);
	void __fastcall KeiryoNoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TokuCodeEditExit(TObject *Sender);
	void __fastcall Komoku1CodeEditExit(TObject *Sender);
	void __fastcall Komoku2CodeEditExit(TObject *Sender);
    void __fastcall TairyuTimerTimer(TObject *Sender);
    void __fastcall KeiryoDatePickerChange(TObject *Sender);
    void __fastcall ShabanEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ShabanEditExit(TObject *Sender);
    void __fastcall Action4Execute(TObject *Sender);
    void __fastcall SharyoButtonClick(TObject *Sender);
	void __fastcall ActionRirekiBeforeExecute(TObject *Sender);
	void __fastcall ActionRirekiNextExecute(TObject *Sender);
	void __fastcall Action11Execute(TObject *Sender);
	void __fastcall DispRirekiCheckBoxClick(TObject *Sender);
	void __fastcall ShabanEditEnter(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TaniTitleEditClick(TObject *Sender);
	void __fastcall HinNameTitleEditClick(TObject *Sender);
	void __fastcall HinCodeEdit1Change(TObject *Sender);
	void __fastcall HinCodeEdit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall HinCodeEdit1Exit(TObject *Sender);
	void __fastcall WeightEdit11Exit(TObject *Sender);
	void __fastcall ChoseiPerEdit1Enter(TObject *Sender);
    void __fastcall BikoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall TaniCodeEdit1Change(TObject *Sender);
    void __fastcall ShomiEdit1Change(TObject *Sender);
    void __fastcall SuryoEdit1Exit(TObject *Sender);
    void __fastcall MeisaiAddButtonClick(TObject *Sender);
    void __fastcall MeisakiDeleteButtonClick(TObject *Sender);
    void __fastcall RecalcButtonClick(TObject *Sender);
    void __fastcall TankaEdit1Exit(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall WeightEdit12KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ChoseiPerEdit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall SuryoEdit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ChoseiPerEdit1Exit(TObject *Sender);
    void __fastcall KingakuEdit1Exit(TObject *Sender);
    void __fastcall ShudoCheckBoxClick(TObject *Sender);
    void __fastcall WeightEdit11Enter(TObject *Sender);
    void __fastcall WeightEdit12Enter(TObject *Sender);
    void __fastcall BikoEditExit(TObject *Sender);
    void __fastcall TaniCodeEdit1Exit(TObject *Sender);
    void __fastcall ShouhizeiEdit1Exit(TObject *Sender);
    void __fastcall BikoEdit1Exit(TObject *Sender);
    void __fastcall HinCodeEdit1Enter(TObject *Sender);
    void __fastcall BikiWeightEdit1Enter(TObject *Sender);
    void __fastcall SuryoEdit1Enter(TObject *Sender);
    void __fastcall TaniCodeEdit1Enter(TObject *Sender);
    void __fastcall TankaEdit1Enter(TObject *Sender);
    void __fastcall KingakuEdit1Enter(TObject *Sender);
    void __fastcall ShouhizeiEdit1Enter(TObject *Sender);
    void __fastcall BikoEdit1Enter(TObject *Sender);
    void __fastcall SharyoNameEditEnter(TObject *Sender);
    void __fastcall SharyoNameEditExit(TObject *Sender);
    void __fastcall WeightEdit22Enter(TObject *Sender);
    void __fastcall ChoseiPerEdit1Change(TObject *Sender);
    void __fastcall ShomiEdit1Exit(TObject *Sender);
    void __fastcall AnbunButtonClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall ClearForm();
	void __fastcall ApplyConfig();
	bool __fastcall LoadFromID(int id);

	void __fastcall StartWeighing();
	void __fastcall ContinueWeighing(int id);
	void __fastcall PostWeighing();
	void __fastcall Print(int keiryo_id);
	bool __fastcall CheckOverload();
	bool __fastcall ValidateForm();

    bool __fastcall SharyoCheck();

	void __fastcall GetCalcInfo();
	void __fastcall CalcWeight(int row = 9);
	void __fastcall CalcAmount(bool update = true);
	void __fastcall CalcSalesTax();
    //正味合計
    void __fastcall CalcShomiTotal();
    //消費税合計
    void __fastcall CalcTaxTotal();
    //金額(税抜き)
    void __fastcall CalcKingaku();
    //金額合計(税抜き)
    void __fastcall CalcKingakuTotal();
    //明細追加時 重量取得
    void __fastcall MeisaiAddWeightRecieve();
    void __fastcall GetTotalMoney();
    // 単価が登録単価かどうか判別して色付けする
    void __fastcall TankaCheck(int row);
    // 1行削除関数
    void __fastcall DeleteSingleRow(int row);
    //按分後の数量調整
    void __fastcall AnbunAfterChousei(int row);
    //按分重量の調整、挿入
    void __fastcall AnbunCalcChousei(int row, int carrytype);
    //按分行の金額、消費税挿入
    void __fastcall AnbunCalcAmountTax(int row);
    //調整率changeでEditを消されないように
    //フラグを宣言
    int AnbunFlag_;

    // 20160627
    // 登録単価を調べて表示する
    void __fastcall CallTanka();

    // 品目取得
    void __fastcall GetHinmoku();

	void __fastcall SetMode(InputMode mode);

	Currency old_weight_;
	Currency cur_weight_;
	int keiryo_id_;
	NsRecordSet keiryo_set_;		// 計量レコード keiryo_id_ と対応
									// このプログラムは単品用なので NsRecord でもいいけど
									// 多段でも流用できるように Set で
    int id_total_;                  // 滞留データID合計

	int toku_id_;                   //
	NsRecord toku_rec_;				// 得意先情報

    bool new_car_;
	int car_id_;
    NsFieldSet new_car_fields_;

	int keiryo_count_;				// 計量回数
	Currency gross_limit_;			// 車両総重量
	Currency net_limit_;			// 最大積載量

    //20160520
    int shomi_total_;
    int kingaku_total_;     //金額計(税別)
    int tax_total_;         //税合計
    int slip_tax_;
    int sum_total_;         //金額合計
    int cur_w2_row_;

    //20160628
    int weighing_border_;

    //20160628
    ///////////////////////RFID
    THF04Thread *rfid_thread_;
    int last_card_no_;

    void __fastcall OnRFIDAborted(TMessage& message);
    void __fastcall OnRFIDStatus(TMessage& message);
    void __fastcall OnRFIDCard(TMessage& message);
    void __fastcall OnRFIDTimeout(TMessage& message);

    ///////////////////////MessageMap
BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(RFIDM_ABORTED, TMessage, OnRFIDAborted);
    MESSAGE_HANDLER(RFIDM_STATUS, TMessage, OnRFIDStatus);
    MESSAGE_HANDLER(RFIDM_CARD, TMessage, OnRFIDCard);
    MESSAGE_HANDLER(RFIDM_TIMEOUT, TMessage, OnRFIDTimeout);
END_MESSAGE_MAP(TForm)

    bool __fastcall TMainForm::RFIDSharyoCheck(int card_no);

    TDateTime __fastcall GetTimePicker_ZeroSec();
    TDateTime __fastcall GetLastKeiryoTime(int date, int slip_no, int place_id);

    //20160603
    bool chk_addflag_;

	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
	void __fastcall SetRireki(int sharyo_id);
	NsRecordSet rireki_set_;
	int rireki_id_;
	void __fastcall RirekiDisp();
	void __fastcall ClearRireki();


	// ヘッダーで定義
	//int limit_line_ = 6;

	// タイトル行(1行)＋行数(6行)
	TCobEdit *gyo[7];
	TCobEdit *hincode[7];
	TCobEdit *hinname[7];
	TCobEdit *weight1[7];
	TCobEdit *weight2[7];
	TCobEdit *choritu[7];
	TCobEdit *choweight[7];
	TCobEdit *bikiweight[7];
	TCobEdit *shomi[7];
	TCobEdit *suryo[7];
	TCobEdit *tanicode[7];
	TCobEdit *taniname[7];
	TCobEdit *tanka[7];
	TCobEdit *kingaku[7];
    TCobEdit *shouhi[7];
	TCobEdit *biko[7];
    int      *weighing1time[7];
    int      *weighing2time[7];
	TStringList *delete_id_list_;
	int max_line_;
	int __fastcall GetRowNo();
	int keiryo_kaisu_;
    int last_gyo_;

public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);

	InputMode __fastcall GetMode();
	int __fastcall GetPlaceID();
	Currency __fastcall GetWeight();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
