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
#include "NP3411Thread.h"
//---------------------------------------------------------------------------
enum InputMode {imFirst, imSecond, imMod};
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
	TPanel *HinPanel;
	TButton *HinButton;
	TCobEdit *HinNameEdit;
	TCobEdit *HinCodeEdit;
	TPanel *SojuPanel;
	TLabel *Label5;
	TLabel *Label13;
	TButton *SojuButton;
	TCobEdit *FirstWEdit;
	TPanel *KushaPanel;
	TLabel *Label8;
	TLabel *Label12;
	TButton *KushaButton;
	TCobEdit *SecondWEdit;
	TPanel *ChoseiPanel;
	TLabel *Label9;
	TLabel *Label10;
	TButton *ChoseiButton;
	TCobEdit *ChoseirituEdit;
	TCobEdit *ChoseiEdit;
	TPanel *ShomiPanel;
	TLabel *Label14;
	TButton *ShomiButton;
	TCobEdit *ShomiEdit;
	TPanel *JuryobikiPanel;
	TLabel *Label11;
	TButton *JuryobikiButton;
	TCobEdit *JuryobikiEdit;
	TPanel *SuryoPanel;
	TLabel *TaniLabel;
	TButton *SuryoButton;
	TCobEdit *SuryoEdit;
	TPanel *TankaPanel;
	TButton *TankaButton;
	TCobEdit *TankaEdit;
	TPanel *KingakuPanel;
	TButton *KingakuButton;
	TCobEdit *KingakuEdit;
	TPanel *TaniPanel;
	TButton *TaniButton;
	TCobEdit *TaniCodeEdit;
	TCobEdit *TaniNameEdit;
	TPanel *ShohizeiPanel;
	TButton *ShohizeiButton;
	TCobEdit *ShohizeiEdit;
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
	TComboBox *HannyuCombo;
    TClientSocket *ClientSocket1;
	TIntegerField *Q_TairyuDSDesigner5;
	TDBText *TairyuCarNoText;
	TLabel *Label2;
	TDateTimeField *Q_TairyuDSDesigner1;
	TAutoIncField *Q_TairyuID;
	TLabel *Label3;
	TLabel *PureNetLabel;
	TCheckBox *AutoPrintCheck;
	TButton *TrailerWeight1Button;
	TButton *TrailerWeight2Button;
    TTimer *SocketReopenTimer1;
	TCheckBox *DataDeleteCheck;
    TTimer *TairyuTimer;
    TDateTimePicker *FirstDatePicker;
    TDateTimePicker *FirstTimePicker;
    TDateTimePicker *SecondDatePicker;
    TDateTimePicker *SecondTimePicker;
    TCheckBox *HideTimeCheck;
    TLabel *Label6;
    TLabel *DefTankaLabel;
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
	TLabel *RirekiHinCodeLabel;
	TLabel *RirekiHinNameLabel;
	TLabel *RirekiKomoku1NameLabel;
	TLabel *RirekiKomoku1CodeLabel;
	TLabel *RirekiKomoku2NameLabel;
	TLabel *RirekiKomoku2CodeLabel;
	TLabel *TairyuKensuLabel;
    TPanel *FWBasePanel;
    TLabel *Label17;
    TPanel *WeightPanel1;
    TPanel *FWNamePanel;
    TLabel *ScaleNameLabel1;
    TLabel *ScaleNameLabel2;
    TLabel *ScaleNameLabel3;
    TPanel *SWBasePanel;
    TLabel *Label1;
    TPanel *WeightPanel2;
    TPanel *SWNamePanel;
    TLabel *ScaleNameLabel4;
    TLabel *ScaleNameLabel5;
    TLabel *ScaleNameLabel6;
    TClientSocket *ClientSocket2;
    TTimer *SocketReopenTimer2;
    TPanel *Panel1;
    TPanel *Panel3;
    TLabel *BreakdownLabel1;
    TLabel *BreakdownWLabel1;
    TLabel *BreakdownLabel2;
    TLabel *BreakdownWLabel2;
    TLabel *BreakdownLabel3;
    TLabel *BreakdownLabel4;
    TLabel *BreakdownWLabel4;
    TLabel *BreakdownWLabel3;
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
	void __fastcall HinCodeEditChange(TObject *Sender);
	void __fastcall TaniCodeEditChange(TObject *Sender);
	void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall Action6Execute(TObject *Sender);
	void __fastcall Action7Execute(TObject *Sender);
	void __fastcall Q_TairyuAfterOpen(TDataSet *DataSet);
	void __fastcall OnSelectTairyu(TObject *Sender);
	void __fastcall PlaceComboChange(TObject *Sender);
	void __fastcall OnWeightRecalc(TObject *Sender);
	void __fastcall OnAmountRecalc(TObject *Sender);
	void __fastcall OnSalesTaxRecalc(TObject *Sender);
	void __fastcall Q_TairyuBeforeOpen(TDataSet *DataSet);
	void __fastcall TokuButtonClick(TObject *Sender);
	void __fastcall Komoku1ButtonClick(TObject *Sender);
	void __fastcall Komoku2ButtonClick(TObject *Sender);
	void __fastcall HinButtonClick(TObject *Sender);
	void __fastcall TaniButtonClick(TObject *Sender);
	void __fastcall FirstWEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall BikoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OnItemsChanged(TObject *Sender);
	void __fastcall TrailerWeightButtonClick(TObject *Sender);
	void __fastcall SocketReopenTimer1Timer(TObject *Sender);
	void __fastcall KeiryoNoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TokuCodeEditExit(TObject *Sender);
	void __fastcall HinCodeEditExit(TObject *Sender);
	void __fastcall Komoku1CodeEditExit(TObject *Sender);
	void __fastcall Komoku2CodeEditExit(TObject *Sender);
    void __fastcall TairyuTimerTimer(TObject *Sender);
    void __fastcall WeighingDateTimePickerChange(TObject *Sender);
    void __fastcall KeiryoDatePickerChange(TObject *Sender);
    void __fastcall ShabanEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ShabanEditExit(TObject *Sender);
    void __fastcall Action4Execute(TObject *Sender);
    void __fastcall TankaEditExit(TObject *Sender);
    void __fastcall SharyoButtonClick(TObject *Sender);
	void __fastcall ActionRirekiBeforeExecute(TObject *Sender);
	void __fastcall ActionRirekiNextExecute(TObject *Sender);
	void __fastcall Action11Execute(TObject *Sender);
	void __fastcall DispRirekiCheckBoxClick(TObject *Sender);
	void __fastcall ShabanEditEnter(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ClientSocket2Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ClientSocket2Read(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall SocketReopenTimer2Timer(TObject *Sender);
    void __fastcall SelectScale1(TObject *Sender);
    void __fastcall SelectScale2(TObject *Sender);
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
    bool __fastcall RFIDSharyoCheck(int card_no);

	void __fastcall GetCalcInfo();
	void __fastcall CalcWeight();
	void __fastcall CalcAmount(bool update = true);
	void __fastcall CalcSalesTax();

	void __fastcall SetMode(InputMode mode);
	InputMode __fastcall GetMode();

	Currency old_weight1_, old_weight2_;
	Currency cur_weight1_, cur_weight2_;
	Currency bdn_weight1_, bdn_weight2_;
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
    int weighing_border_;

	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
	void __fastcall SetRireki(int sharyo_id);
	NsRecordSet rireki_set_;
	int rireki_id_;
	void __fastcall RirekiDisp();
	void __fastcall ClearRireki();

    ////////////////////////////// NP3411関連
	TNP3411Thread *printer_thread_;
    CfgInfo cfginfo_;
    //NsRecordSet keiryo_set_;
    NsRecordSet print_set_;

	void __fastcall UMNiiAborted(TMessage& message);
	void __fastcall UMNiiStatus(TMessage& message);
	void __fastcall UMNiiReboot(TMessage& message);
    ////////////////////////////// RFID
    THF04Thread *rfid_thread_;
    int last_card_no_;

	void __fastcall OnRFIDAborted(TMessage& message);
	void __fastcall OnRFIDStatus(TMessage& message);
	void __fastcall OnRFIDCard(TMessage& message);
	void __fastcall OnRFIDTimeout(TMessage& message);

    ////////////////////////////// MessageMap
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(RFIDM_ABORTED, TMessage, OnRFIDAborted);
	MESSAGE_HANDLER(RFIDM_STATUS,  TMessage, OnRFIDStatus);
	MESSAGE_HANDLER(RFIDM_CARD,    TMessage, OnRFIDCard);
	MESSAGE_HANDLER(RFIDM_TIMEOUT, TMessage, OnRFIDTimeout);
	MESSAGE_HANDLER(UM_NII_ABORTED, TMessage, UMNiiAborted);
	MESSAGE_HANDLER(UM_NII_STATUS,  TMessage, UMNiiStatus);
	MESSAGE_HANDLER(UM_NII_REBOOT,  TMessage, UMNiiReboot);
END_MESSAGE_MAP(TForm)

public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);

	int __fastcall GetPlaceID();
	Currency __fastcall GetWeight();
	void __fastcall PrintKeiryoData(int keiryo_id);
	void __fastcall PrintCopy(int keiryo_id);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
