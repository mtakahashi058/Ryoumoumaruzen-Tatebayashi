//---------------------------------------------------------------------------

#ifndef TokuisakiEditFrmH
#define TokuisakiEditFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
#include "DMFrm.h"
//---------------------------------------------------------------------------
class TTokuisakiEditForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TGroupBox *BasicInfoGroupBox;
	TGroupBox *SeikyuInfoGroupBox;
	TPanel *CodePanel;
	TLabel *Label1;
	TCobEdit *CodeEdit;
	TPanel *NamePanel;
	TLabel *Label2;
	TCobEdit *NameEdit;
	TPanel *ShortNamePanel;
	TLabel *Label3;
	TCobEdit *ShortNameEdit;
	TPanel *KanaPanel;
	TLabel *Label4;
	TCobEdit *KanaEdit;
	TPanel *YubinPanel;
	TLabel *Label5;
	TCobEdit *YubinEdit;
	TPanel *Address1Panel;
	TLabel *Label6;
	TCobEdit *Address1Edit;
	TPanel *Address2Panel;
	TLabel *Label7;
	TCobEdit *Address2Edit;
	TPanel *TelPanel;
	TLabel *Label8;
	TCobEdit *TelEdit;
	TPanel *FaxPanel;
	TLabel *Label9;
	TCobEdit *FaxEdit;
	TPanel *UseDivPanel;
	TLabel *Label10;
	TComboBox *UseDivComboBox;
	TPanel *SeikyusakiPanel;
	TLabel *Label11;
	TCobEdit *SeikyusakiCodeEdit;
	TCobEdit *SeikyusakiNameEdit;
	TSpeedButton *SeikyusakiSearchButton;
	TPanel *SeikyushoPrintPanel;
	TLabel *Label12;
	TComboBox *SeikyushoPrintComboBox;
	TPanel *GenkakePanel;
	TLabel *Label13;
	TComboBox *GenkakeComboBox;
	TPanel *SimebiPanel;
	TLabel *Label14;
	TCobEdit *SimebiEdit;
	TPanel *ZanDispPanel;
	TLabel *Label15;
	TComboBox *ZanDispComboBox;
	TPanel *MoneyFractionPanel;
	TLabel *Label16;
	TComboBox *MoneyFractionComboBox;
	TPanel *TaxFractionPanel;
	TLabel *Label17;
	TComboBox *TaxFractionComboBox;
	TPanel *NyukinSitePanel;
	TLabel *Label18;
	TComboBox *NyukinSiteComboBox;
	TPanel *NyukinbiPanel;
	TLabel *Label19;
	TCobEdit *NyukinbiEdit;
	TPanel *NyukinMethodPanel;
	TLabel *Label21;
	TComboBox *NyukinMethodComboBox;
	TLabel *Label20;
	TLabel *Label22;
	TPanel *ModePanel;
	TCheckBox *RenzokuCheckBox;
	TPanel *RenewDatePanel;
	TLabel *Label23;
	TCobEdit *RenewDateEdit;
	TPanel *CreateDatePanel;
	TLabel *Label24;
	TCobEdit *CreateDateEdit;
	TStatusBar *StatusBar;
	TPanel *F1Panel;
	TPanel *F2Panel;
	TPanel *F3Panel;
	TPanel *F4Panel;
	TButton *F5Button;
	TButton *F7Button;
      TButton *F8Button;
      TButton *F12Button;
	TSpeedButton *AddressSearchButton;
	TSpeedButton *YubinSearchButton;
	TActionList *ActionList;
      TAction *Action3;
	TAction *Action5;
	TAction *Action7;
	TAction *Action8;
	TAction *Action12;
	TSpeedButton *SaibanButton;
	TPanel *SyncPanel;
	TLabel *Label25;
	TCobEdit *SyncCodeEdit;
	TPanel *BankPanel;
	TLabel *Label26;
	TCobEdit *BankCodeEdit;
	TCobEdit *BankNameEdit;
	TSpeedButton *BankSearchButton;
	TPanel *BranchPanel;
	TLabel *Label27;
	TCobEdit *BranchNameEdit;
	TPanel *AccontPanel;
	TLabel *Label28;
	TCobEdit *AccountEdit;
	TPanel *AccontNamePanel;
	TLabel *Label29;
    TCobEdit *AccountNameEdit;
	TPanel *ConversionFractionPanel;
	TLabel *Label30;
	TComboBox *ConversionFractionComboBox;
    TPanel *Panel1;
    TPanel *Panel3;
    TButton *F1Button;
    TButton *F3Button;
    TAction *Action1;
    TAction *Action4;
    TPanel *HonorificPanel;
    TLabel *Label31;
    TComboBox *HonorificComboBox;
    TPanel *TaxCalcPanel;
    TLabel *Label32;
    TComboBox *TaxCalcComboBox;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
        TShiftState Shift);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Action3Execute(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action7Execute(TObject *Sender);
	void __fastcall Action8Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall CodeEditExit(TObject *Sender);
	void __fastcall SaibanButtonClick(TObject *Sender);
	void __fastcall NameEditExit(TObject *Sender);
	void __fastcall AddressSearchButtonClick(TObject *Sender);
	void __fastcall YubinSearchButtonClick(TObject *Sender);
	void __fastcall SeikyusakiCodeEditChange(TObject *Sender);
	void __fastcall SeikyusakiSearchButtonClick(TObject *Sender);
	void __fastcall SeikyusakiCodeEditExit(TObject *Sender);
	void __fastcall UseDivComboBoxEnter(TObject *Sender);
	void __fastcall UseDivComboBoxExit(TObject *Sender);
	void __fastcall CodeEditEnter(TObject *Sender);
	void __fastcall NameEditEnter(TObject *Sender);
	void __fastcall ShortNameEditEnter(TObject *Sender);
	void __fastcall KanaEditEnter(TObject *Sender);
	void __fastcall YubinEditEnter(TObject *Sender);
	void __fastcall Address1EditEnter(TObject *Sender);
	void __fastcall Address2EditEnter(TObject *Sender);
	void __fastcall TelEditEnter(TObject *Sender);
	void __fastcall FaxEditEnter(TObject *Sender);
	void __fastcall SeikyusakiCodeEditEnter(TObject *Sender);
	void __fastcall SeikyushoPrintComboBoxEnter(TObject *Sender);
	void __fastcall GenkakeComboBoxEnter(TObject *Sender);
	void __fastcall SimebiEditEnter(TObject *Sender);
	void __fastcall ZanDispComboBoxEnter(TObject *Sender);
	void __fastcall MoneyFractionComboBoxEnter(TObject *Sender);
	void __fastcall TaxFractionComboBoxEnter(TObject *Sender);
	void __fastcall NyukinSiteComboBoxEnter(TObject *Sender);
	void __fastcall NyukinbiEditEnter(TObject *Sender);
	void __fastcall NyukinMethodComboBoxEnter(TObject *Sender);
    void __fastcall BankCodeEditChange(TObject *Sender);
    void __fastcall BankCodeEditEnter(TObject *Sender);
    void __fastcall BankSearchButtonClick(TObject *Sender);
    void __fastcall AccountNameEditEnter(TObject *Sender);
    void __fastcall AccountNameEditKeyDown(TObject *Sender, WORD &Key,
        TShiftState Shift);
    void __fastcall Action1Execute(TObject *Sender);
    void __fastcall Action4Execute(TObject *Sender);
	void __fastcall CodePanelEnter(TObject *Sender);
	void __fastcall CodePanelExit(TObject *Sender);
private:	// ユーザー宣言
    int id_;
    MasterMap use_div_map_, seikyu_print_map_, genkake_map_, zan_disp_map_,
			  fraction_map_, nyukin_site_map_, nyukin_method_map_, tax_calc_map_;
	bool is_edit_;
    int page_;
    AnsiString keyfield_;

    void __fastcall ClearForm();
    int __fastcall GetNo();
    void __fastcall SetMode(TInputMode mode);
    bool __fastcall CheckEdit();
    bool __fastcall PostRecord();
    void __fastcall BrowseRecord();
    void __fastcall AutoKanaMessage(tagMSG &Msg, bool &Handled);
public:		// ユーザー宣言
    __fastcall TTokuisakiEditForm(TComponent* Owner);

    int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TTokuisakiEditForm *TokuisakiEditForm;
//---------------------------------------------------------------------------
#endif
