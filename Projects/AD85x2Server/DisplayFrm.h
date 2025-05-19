//---------------------------------------------------------------------------

#ifndef DisplayFrmH
#define DisplayFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
class TDisplayForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TPanel *JuryobikiPanel;
    TLabel *Label11;
    TButton *JuryobikiButton;
    TCobEdit *JuryobikiEdit;
    TPanel *SuryoPanel;
    TButton *SuryoButton;
    TCobEdit *SuryoEdit;
    TPanel *HeaderPanel;
    TBevel *Bevel1;
    TLabel *Label20;
    TLabel *Label21;
    TPanel *ScalePanel;
    TPanel *ClientPanel;
    TPanel *RecordPanel;
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
    TPanel *HinPanel;
    TButton *HinButton;
    TCobEdit *HinNameEdit;
    TCobEdit *HinCodeEdit;
    TComboBox *HannyuCombo;
    TPanel *SojuPanel;
    TLabel *Label5;
    TLabel *FirstTimeLabel;
    TLabel *Label13;
    TButton *SojuButton;
    TCobEdit *FirstWEdit;
    TPanel *KushaPanel;
    TLabel *SecondTimeLabel;
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
    TLabel *Label3;
    TLabel *PureNetLabel;
    TButton *ShomiButton;
    TCobEdit *ShomiEdit;
    TPanel *TankaPanel;
    TButton *TankaButton;
    TCobEdit *TankaEdit;
    TPanel *KingakuPanel;
    TButton *KingakuButton;
    TCobEdit *KingakuEdit;
    TButton *ShohizeiButton;
    TCobEdit *ShohizeiEdit;
    TDateTimePicker *KeiryoDatePicker;
    TCobEdit *KeiryoNoEdit;
    TPanel *WeightPanel;
    TLabel *Label1;
    TPanel *ScaleNamePanel;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// ユーザー宣言
    void __fastcall ClearForm();
    AnsiString __fastcall ZeroSuppress(Currency v);
public:		// ユーザー宣言
    __fastcall TDisplayForm(TComponent* Owner);
    void __fastcall ShowRecord(int id);
    void __fastcall Clear();
};
//---------------------------------------------------------------------------
extern PACKAGE TDisplayForm *DisplayForm;
//---------------------------------------------------------------------------
#endif
