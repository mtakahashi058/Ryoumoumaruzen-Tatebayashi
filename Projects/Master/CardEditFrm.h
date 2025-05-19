//---------------------------------------------------------------------------

#ifndef CardEditFrmH
#define CardEditFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TCardEditForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TPanel *ModePanel;
    TCheckBox *RenzokuCheckBox;
    TPanel *RenewDatePanel;
    TLabel *Label23;
    TCobEdit *RenewDateEdit;
    TPanel *CreateDatePanel;
    TLabel *Label24;
    TCobEdit *CreateDateEdit;
    TStatusBar *StatusBar;
    TPanel *Panel1;
    TPanel *ShabanPanel;
    TLabel *Label1;
    TCobEdit *CarNoEdit;
    TPanel *HinmokuPanel;
    TLabel *HinmokuLabel;
    TSpeedButton *HinmokuSearchButton;
    TCobEdit *HinmokuCodeEdit;
    TCobEdit *HinmokuNameEdit;
    TPanel *TokuisakiPanel;
    TLabel *TokuisakiLabel;
    TSpeedButton *GyoshaSearchButton;
    TCobEdit *GyoshaCodeEdit;
    TCobEdit *GyoshaNameEdit;
    TPanel *UseDivPanel;
    TLabel *Label10;
    TComboBox *UseDivComboBox;
    TPanel *CardNoPanel;
    TLabel *Label5;
    TCobEdit *RegistryNoEdit;
    TButton *Button1;
    TPanel *Panel2;
    TButton *Button2;
    TPanel *Panel3;
    TPanel *F1Panel;
    TPanel *F2Panel;
    TPanel *F3Panel;
    TPanel *F4Panel;
    TButton *F5Button;
    TButton *F7Button;
    TButton *F3Button;
    TButton *F4Button;
    TActionList *ActionList;
    TAction *Action1;
    TAction *Action3;
    TAction *Action4;
    TAction *Action5;
    TAction *Action7;
    TAction *Action8;
    TAction *Action12;
    TCobEdit *CarNameEdit;
    TPanel *SharyoNamePanel;
    TLabel *Label2;
    TCobEdit *BikouEdit1;
    TPanel *Panel4;
    TLabel *Label3;
    TPanel *Panel5;
    TLabel *Label4;
    TCobEdit *BikouEdit2;
    TCobEdit *BikouEdit3;
    TPanel *Panel6;
    TButton *Button3;
    TAction *Action6;
    TSpeedButton *CarSearchButton;
    TSpeedButton *RegistryNoButton;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall Action1Execute(TObject *Sender);
    void __fastcall Action3Execute(TObject *Sender);
    void __fastcall Action4Execute(TObject *Sender);
    void __fastcall Action5Execute(TObject *Sender);
    void __fastcall Action6Execute(TObject *Sender);
    void __fastcall Action7Execute(TObject *Sender);
    void __fastcall Action8Execute(TObject *Sender);
    void __fastcall Action12Execute(TObject *Sender);
    void __fastcall CarNoEditChange(TObject *Sender);
    void __fastcall CarSearchButtonClick(TObject *Sender);
    void __fastcall GyoshaCodeEditChange(TObject *Sender);
    void __fastcall GyoshaSearchButtonClick(TObject *Sender);
    void __fastcall HinmokuCodeEditChange(TObject *Sender);
    void __fastcall HinmokuSearchButtonClick(TObject *Sender);
    void __fastcall RegistryNoEditEnter(TObject *Sender);
    void __fastcall CarNoEditEnter(TObject *Sender);
    void __fastcall GyoshaCodeEditEnter(TObject *Sender);
    void __fastcall HinmokuCodeEditEnter(TObject *Sender);
    void __fastcall BikouEdit1Enter(TObject *Sender);
    void __fastcall BikouEdit2Enter(TObject *Sender);
    void __fastcall BikouEdit3Enter(TObject *Sender);
    void __fastcall UseDivComboBoxEnter(TObject *Sender);
    void __fastcall UseDivComboBoxExit(TObject *Sender);
    void __fastcall UseDivComboBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall RegistryNoButtonClick(TObject *Sender);
private:	// ユーザー宣言
	int id_, page_, car_id_;
	bool is_edit_;
	AnsiString keyfield_;
    MasterMap use_div_map_;

    void __fastcall ClearForm(int n);
	void __fastcall SetMode(TInputMode mode);
	bool __fastcall CheckEdit();
	bool __fastcall PostRecord();
	void __fastcall BrowseRecord();
    int __fastcall GetRegistryNo();
public:		// ユーザー宣言
    __fastcall TCardEditForm(TComponent* Owner);

    int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TCardEditForm *CardEditForm;
//---------------------------------------------------------------------------
#endif
