//---------------------------------------------------------------------------

#ifndef SlipInfoRelateEditFrmH
#define SlipInfoRelateEditFrmH
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
#include "DMFrm.h"
//---------------------------------------------------------------------------
class TSlipInfoRelateEditForm : public TForm
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
      TPanel *StoreroomEntryTitlePanel1;
      TLabel *StoreroomEntryTitleLabel1;
      TCobEdit *StoreroomEntryTitleEdit1;
      TPanel *StoreroomEntryTitlePanel2;
      TLabel *StoreroomEntryTitleLabel2;
      TCobEdit *StoreroomEntryTitleEdit2;
      TPanel *StoreroomEntryTitlePanel3;
      TLabel *StoreroomEntryTitleLabel3;
      TCobEdit *StoreroomEntryTitleEdit3;
      TPanel *DeliverySlipPanel1;
      TLabel *DeliverySlipLabel1;
      TCobEdit *DeliverySlipEdit1;
      TPanel *DeliverySlipPanel2;
      TLabel *DeliverySlipLabel2;
      TCobEdit *DeliverySlipEdit2;
      TPanel *DeliverySlipPanel3;
      TLabel *DeliverySlipLabel3;
      TCobEdit *DeliverySlipEdit3;
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
      TPanel *Panel2;
      TPanel *SettingPanel;
      TLabel *SettingLabel;
      TSpeedButton *SettingSearchButton;
      TCobEdit *SettingNameEdit;
      TCobEdit *SettingCodeEdit;
      TPanel *ItemNoPanel;
      TLabel *ItemNoLabel;
      TCobEdit *ItemNoCodeEdit;
      TComboBox *ItemNoNameComboBox;
      TPanel *SlipInfoPanel;
      TLabel *SlipInfoLabel;
      TSpeedButton *SlipInfoSerachButton;
      TCobEdit *SlipInfoCodeEdit;
      TActionList *ActionList;
      TAction *Action4;
      TAction *Action5;
      TAction *Action7;
      TAction *Action8;
      TAction *Action12;
      void __fastcall FormShow(TObject *Sender);
      void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
      void __fastcall Action4Execute(TObject *Sender);
      void __fastcall Action5Execute(TObject *Sender);
      void __fastcall Action7Execute(TObject *Sender);
      void __fastcall Action8Execute(TObject *Sender);
      void __fastcall Action12Execute(TObject *Sender);
      void __fastcall ItemNoCodeEditChange(TObject *Sender);
      void __fastcall ItemNoCodeEditEnter(TObject *Sender);
      void __fastcall SettingCodeEditChange(TObject *Sender);
      void __fastcall SettingCodeEditEnter(TObject *Sender);
      void __fastcall SettingSearchButtonClick(TObject *Sender);
      void __fastcall SlipInfoCodeEditChange(TObject *Sender);
      void __fastcall SlipInfoSerachButtonClick(TObject *Sender);
      void __fastcall SlipInfoCodeEditEnter(TObject *Sender);
      void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
      void __fastcall ItemNoNameComboBoxChange(TObject *Sender);
	void __fastcall ItemNoPanelEnter(TObject *Sender);
	void __fastcall ItemNoPanelExit(TObject *Sender);
private:	// ユーザー宣言
      int id_;
      bool is_edit_;

      void __fastcall SetMode(TInputMode mode);
      void __fastcall ClearForm();
      void __fastcall ClearSlipInfo();
      void __fastcall BrowseRecord();
      bool __fastcall PostRecord();
      bool __fastcall CheckEdit();
public:		// ユーザー宣言
      __fastcall TSlipInfoRelateEditForm(TComponent* Owner);

      int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TSlipInfoRelateEditForm *SlipInfoRelateEditForm;
//---------------------------------------------------------------------------
#endif
