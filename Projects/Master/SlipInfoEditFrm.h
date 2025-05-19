//---------------------------------------------------------------------------

#ifndef SlipInfoEditFrmH
#define SlipInfoEditFrmH
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
#include "DMFrm.h"
//---------------------------------------------------------------------------
class TSlipInfoEditForm : public TForm
{
__published:	// IDE 管理のコンポーネント
      TPanel *ModePanel;
      TCheckBox *RenzokuCheckBox;
      TStatusBar *StatusBar;
      TPanel *F1Panel;
      TPanel *F2Panel;
      TPanel *F3Panel;
      TPanel *F4Panel;
      TButton *F5Button;
      TButton *F7Button;
      TButton *F3Button;
      TButton *F4Button;
      TPanel *Panel1;
      TPanel *SlipInfoNamePanel;
      TLabel *SlipInfoNameLabel;
      TCobEdit *SlipInfoNameEdit;
      TPanel *SlipInfoNoPanel;
      TLabel *SlipInfoNoLabel;
      TCobEdit *SlipInfoNoEdit;
      TPanel *StoreroomEntryTitlePanel1;
      TLabel *StoreroomEntryTitleLabel1;
      TCobEdit *NyukoTitleEdit1;
      TActionList *ActionList;
      TAction *Action4;
      TAction *Action5;
      TAction *Action7;
      TAction *Action8;
      TAction *Action12;
      TPanel *StoreroomEntryTitlePanel2;
      TLabel *StoreroomEntryTitleLabel2;
      TCobEdit *NyukoTitleEdit2;
      TPanel *StoreroomEntryTitlePanel3;
      TLabel *StoreroomEntryTitleLabel3;
      TCobEdit *NyukoTitleEdit3;
      TPanel *DeliverySlipPanel1;
      TLabel *DeliverySlipLabel1;
      TCobEdit *ShukoTitleEdit1;
      TPanel *DeliverySlipPanel2;
      TLabel *DeliverySlipLabel2;
      TCobEdit *ShukoTitleEdit2;
      TPanel *DeliverySlipPanel3;
      TLabel *DeliverySlipLabel3;
      TCobEdit *ShukoTitleEdit3;
      TPanel *CompanyNamePanel;
      TLabel *CompanyNameLabel;
      TCobEdit *CompanyNameEdit;
      TPanel *CompanyInfoPanel1;
      TLabel *CompanyInfoLabel1;
      TCobEdit *CompanyInfoEdit1;
      TPanel *CompanyInfoPanel2;
      TLabel *CompanyInfoLabel2;
      TCobEdit *CompanyInfoEdit2;
      TPanel *CompanyInfoPanel3;
      TLabel *CompanyInfoLabel3;
      TCobEdit *CompanyInfoEdit3;
      TPanel *CompanyInfoPanel4;
      TLabel *CompanyInfoLabel4;
      TCobEdit *CompanyInfoEdit4;
      TSpeedButton *SaibanButton;
      TButton *Button1;
      TPanel *Panel2;
      TButton *Button2;
      TPanel *Panel3;
      TAction *Action1;
      TAction *Action3;
    TCheckBox *AmountPrint1Check;
    TCheckBox *AmountPrint2Check;
    TCheckBox *AmountPrint3Check;
      void __fastcall FormShow(TObject *Sender);
      void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
      void __fastcall Action5Execute(TObject *Sender);
      void __fastcall Action7Execute(TObject *Sender);
      void __fastcall Action8Execute(TObject *Sender);
      void __fastcall Action12Execute(TObject *Sender);
      void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
      void __fastcall SaibanButtonClick(TObject *Sender);
      void __fastcall SlipInfoNoEditExit(TObject *Sender);
      void __fastcall Action1Execute(TObject *Sender);
      void __fastcall Action3Execute(TObject *Sender);
	void __fastcall SlipInfoNoPanelEnter(TObject *Sender);
	void __fastcall SlipInfoNoPanelExit(TObject *Sender);
private:	// ユーザー宣言
      int id_, page_;
      bool is_edit_;
      AnsiString keyfield_;

      void __fastcall SetMode(TInputMode mode);
      bool __fastcall CheckEdit();
      int __fastcall GetSlipInfoNo();
      void __fastcall ClearForm();
      void __fastcall BrowseRecord();
      bool __fastcall PostRecord();
public:		// ユーザー宣言
      __fastcall TSlipInfoEditForm(TComponent* Owner);

      int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TSlipInfoEditForm *SlipInfoEditForm;
//---------------------------------------------------------------------------
#endif
