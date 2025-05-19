//---------------------------------------------------------------------------

#ifndef DivideFrmH
#define DivideFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include <map>
//---------------------------------------------------------------------------
typedef struct AnbunValue2{
    int code;
    AnsiString name;
    Currency choseibiki;
    Currency juryobiki;
    Currency shomi;
}aValue;

class TDivideForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TSpeedButton *ButtonHin1;
    TSpeedButton *ButtonHin2;
    TSpeedButton *ButtonHin3;
    TSpeedButton *ButtonHin4;
    TSpeedButton *ButtonHin5;
    TSpeedButton *ButtonHin6;
    TLabel *Label7;
    TSpeedButton *SpeedButton1;
    TShape *Shape1;
    TLabel *Label8;
    TSpeedButton *SpeedButton2;
    TButton *ButtonExec;
    TButton *ButtonCancel;
    TPanel *Panel2;
    TCobEdit *EditRate1;
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
    TCobEdit *EditHinCode2;
    TCobEdit *EditHinName2;
    TCobEdit *EditChoseiBiki2;
    TCobEdit *EditJuryoBiki2;
    TCobEdit *EditShomi2;
    TCobEdit *EditRate3;
    TCobEdit *EditHinCode3;
    TCobEdit *EditHinName3;
    TCobEdit *EditChoseiBiki3;
    TCobEdit *EditJuryoBiki3;
    TCobEdit *EditShomi3;
    TCobEdit *EditRate4;
    TCobEdit *EditHinCode4;
    TCobEdit *EditHinName4;
    TCobEdit *EditChoseiBiki4;
    TCobEdit *EditJuryoBiki4;
    TCobEdit *EditShomi4;
    TCobEdit *EditRate5;
    TCobEdit *EditHinCode5;
    TCobEdit *EditHinName5;
    TCobEdit *EditChoseiBiki5;
    TCobEdit *EditJuryoBiki5;
    TCobEdit *EditShomi5;
    TCobEdit *EditRate6;
    TCobEdit *EditHinCode6;
    TCobEdit *EditHinName6;
    TCobEdit *EditChoseiBiki6;
    TCobEdit *EditJuryoBiki6;
    TCobEdit *EditShomi6;
    TPanel *Panel1;
    TCobEdit *EditRate;
    TPanel *PanelHinT1;
    TCobEdit *EditHinCode;
    TCobEdit *EditHinName;
    TPanel *Panel10;
    TCobEdit *EditShomi;
    TCobEdit *EditRateZan;
    TCobEdit *EditShomiZan;
    TCobEdit *CobEdit1;
    TCobEdit *CobEdit2;
    TCobEdit *ChoseiPerEdit1;
    TCobEdit *ChoseiPerEdit2;
    TCobEdit *ChoseiPerEdit3;
    TCobEdit *ChoseiPerEdit4;
    TCobEdit *ChoseiPerEdit5;
    TCobEdit *ChoseiPerEdit6;
    TPanel *Panel3;
    TCobEdit *EditBaseWeight1;
    TCobEdit *EditBaseWeight2;
    TCobEdit *EditBaseWeight3;
    TCobEdit *EditBaseWeight4;
    TCobEdit *EditBaseWeight5;
    TCobEdit *EditBaseWeight6;
private:	// ユーザー宣言
    TCobEdit *edit[8][6];
    TSpeedButton *button[6];
    void __fastcall CalcZan();
    bool __fastcall CheckSuryo(int tag);
    int max_record;
    bool is_first;
    void __fastcall ResetName();
public:		// ユーザー宣言
    __fastcall TDivideForm(TComponent* Owner);
    void __fastcall ClearForm();
    TStringList *record_list;
    int rec_count;

    std::map<int, AnbunValue2> AnbunMap;
    AnbunValue2 avalue;
};
//---------------------------------------------------------------------------
extern PACKAGE TDivideForm *DivideForm;
//---------------------------------------------------------------------------
#endif
