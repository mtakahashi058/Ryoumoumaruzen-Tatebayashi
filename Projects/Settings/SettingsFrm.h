//---------------------------------------------------------------------------

#ifndef SettingsFrmH
#define SettingsFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CEdit.h"
#include "CSPIN.h"
#include "DMFrm.h"
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TSettingsForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TopPanel;
	TPanel *KeyPanel;
	TButton *SaveButton;
	TButton *CancelButton;
	TOpenDialog *OpenDialog;
    TPageControl *PageControl;
    TTabSheet *WISheet;
    TPanel *Panel1;
    TTabSheet *WIClientSheet;
    TPanel *Panel2;
    TTabSheet *PrinterSheet;
    TTabSheet *KeiryoSheet;
    TPanel *Panel3;
    TPanel *Panel4;
    TLabel *Label17;
    TComboBox *PlaceCombo;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label11;
    TComboBox *WICombo;
    TCobEdit *ComDefEdit;
    TCSpinEdit *ComPortEdit;
    TCobEdit *WIServerPortEdit;
    TMemo *Memo1;
    TLabel *Label10;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TCobEdit *WIServerEdit;
    TCobEdit *WIConnectPortEdit;
    TCobEdit *AlermWeightEdit;
    TCobEdit *SoundFileEdit;
    TButton *SoundRefButton;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TComboBox *SlipPrinterCombo;
    TCobEdit *SlipLeftMarginEdit;
    TCobEdit *SlipTopMarginEdit;
    TComboBox *ReportPrinterCombo;
    TTabSheet *AD4385Sheet;
    TPanel *Panel5;
    TLabel *Label16;
    TLabel *Label18;
    TCobEdit *AD85DefEdit;
    TCSpinEdit *AD85PortEdit;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label21;
    TCobEdit *AD85BorderEdit;
    TCobEdit *NotifySoundEdit;
    TButton *NotifySoundRefButton;
    TTabSheet *BatchSheet;
    TLabel *Label22;
    TLabel *Label23;
    TCobEdit *BatchDefEdit;
    TCSpinEdit *BatchPortEdit;
    TPanel *Panel6;
    TLabel *Label24;
    TComboBox *SlipBinCombo;
    TTabSheet *RFIDSheet;
    TPanel *Panel7;
    TLabel *Label25;
    TCSpinEdit *DeskRFIDPortEdit;
    TLabel *Label26;
    TCSpinEdit *BoxRFIDPortEdit;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall SoundRefButtonClick(TObject *Sender);
    void __fastcall NotifySoundRefButtonClick(TObject *Sender);
private:	// ユーザー宣言
	NsRecordSet kyoten_set_;
public:		// ユーザー宣言
	__fastcall TSettingsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSettingsForm *SettingsForm;
//---------------------------------------------------------------------------
#endif
