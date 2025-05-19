//---------------------------------------------------------------------------

#ifndef AnbunFrmH
#define AnbunFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include "CEdit.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#include <map>
//---------------------------------------------------------------------------
typedef struct AnbunValue {
    int code;
    AnsiString name;
    Currency choseiper;
    Currency choseibiki;
    Currency juryobiki;
    Currency shomi;
}aValue;


class TAnbunForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TButton *ButtonExec;
	TButton *ButtonCancel;
	TPanel *Panel2;
	TCobEdit *EditRate1;
	TLabel *Label1;
	TPanel *PanelHinT2;
	TCobEdit *EditHinCode1;
	TCobEdit *EditHinName1;
	TPanel *Panel4;
    TCobEdit *EditChoseiBiki1;
	TPanel *Panel5;
    TCobEdit *EditJuryoBiki1;
	TPanel *Panel6;
	TCobEdit *EditShomi1;
	TCobEdit *EditRate2;
	TLabel *Label2;
	TCobEdit *EditHinCode2;
	TCobEdit *EditHinName2;
    TCobEdit *EditChoseiBiki2;
    TCobEdit *EditJuryoBiki2;
	TCobEdit *EditShomi2;
	TCobEdit *EditRate3;
	TLabel *Label3;
	TCobEdit *EditHinCode3;
	TCobEdit *EditHinName3;
    TCobEdit *EditChoseiBiki3;
    TCobEdit *EditJuryoBiki3;
	TCobEdit *EditShomi3;
	TCobEdit *EditRate4;
	TLabel *Label4;
	TCobEdit *EditHinCode4;
	TCobEdit *EditHinName4;
    TCobEdit *EditChoseiBiki4;
    TCobEdit *EditJuryoBiki4;
	TCobEdit *EditShomi4;
	TCobEdit *EditRate5;
	TLabel *Label5;
	TCobEdit *EditHinCode5;
	TCobEdit *EditHinName5;
    TCobEdit *EditChoseiBiki5;
    TCobEdit *EditJuryoBiki5;
	TCobEdit *EditShomi5;
	TCobEdit *EditRate6;
	TLabel *Label6;
	TCobEdit *EditHinCode6;
	TCobEdit *EditHinName6;
    TCobEdit *EditChoseiBiki6;
    TCobEdit *EditJuryoBiki6;
	TCobEdit *EditShomi6;
	TSpeedButton *ButtonHin1;
	TSpeedButton *ButtonHin2;
	TSpeedButton *ButtonHin3;
	TSpeedButton *ButtonHin4;
	TSpeedButton *ButtonHin5;
	TSpeedButton *ButtonHin6;
	TPanel *Panel1;
	TCobEdit *EditRate;
	TLabel *Label7;
	TPanel *PanelHinT1;
	TCobEdit *EditHinCode;
	TCobEdit *EditHinName;
    TPanel *ChoseiPanel;
    TCobEdit *EditChoseiBiki;
    TPanel *BikiPanel;
    TCobEdit *EditJuryoBiki;
	TPanel *Panel10;
	TCobEdit *EditShomi;
	TSpeedButton *SpeedButton1;
	TShape *Shape1;
	TCobEdit *EditRateZan;
	TLabel *Label8;
    TCobEdit *EditChoseiBikiZan;
    TCobEdit *EditJuryoBikiZan;
	TCobEdit *EditShomiZan;
	TCobEdit *CobEdit1;
	TSpeedButton *SpeedButton2;
	TCobEdit *CobEdit2;
    TCobEdit *EditChoseiPer1;
    TCobEdit *EditChoseiPer2;
    TCobEdit *EditChoseiPer3;
    TCobEdit *EditChoseiPer4;
    TCobEdit *EditChoseiPer5;
    TCobEdit *EditChoseiPer6;
	void __fastcall ButtonHin1Click(TObject *Sender);
	void __fastcall EditHinCode1Change(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall EditRate1Change(TObject *Sender);
	void __fastcall EditRate1Exit(TObject *Sender);
	void __fastcall EditShomi1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall EditHinCode1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ButtonExecClick(TObject *Sender);
    void __fastcall EditHinCode1Exit(TObject *Sender);
    void __fastcall EditChoseiPer1Exit(TObject *Sender);
    void __fastcall EditJuryoBiki1Exit(TObject *Sender);
private:	// ユーザー宣言
	TCobEdit *edits[6][7];
	TSpeedButton *buttons[6];
	void __fastcall CalcZan();
	bool __fastcall CheckSuryo(int tag);
	int max_record;
	bool is_first;
	void __fastcall ResetName();
    void __fastcall CalcWeight(int row);

    TCobEdit *rate[7];
    TCobEdit *hincode[7];
    TCobEdit *hinname[7];
    TCobEdit *choper[7];
    TCobEdit *choweight[7];
    TCobEdit *bikiweight[7];
    TCobEdit *shomi[7];
    AnsiString processingShomi_;
public:		// ユーザー宣言
	__fastcall TAnbunForm(TComponent* Owner);
	void __fastcall ClearForm();
	TStringList *record_list;
	int rec_count;

    std::map <int , AnbunValue> AnbunMap;
    AnbunValue avalue;
};
//---------------------------------------------------------------------------
extern PACKAGE TAnbunForm *AnbunForm;
//---------------------------------------------------------------------------
#endif
