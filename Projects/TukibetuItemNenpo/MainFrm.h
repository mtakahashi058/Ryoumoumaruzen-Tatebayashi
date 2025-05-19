//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
#include <map>
typedef std::map<int, AnsiString> ItemMap;
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel1;
	TPanel *Panel2;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TComboBox *SelectItemComboBox;
	TLabel *Label2;
	TDateTimePicker *FromDatePicker;
	TDateTimePicker *ToDatePicker;
	TLabel *Label3;
	TCheckBox *ItemAllCheckBox;
	TCobEdit *ItemCodeEditF;
	TCobEdit *ItemNameEditF;
	TCheckBox *SpotAllCheckBox;
	TCobEdit *SpotCodeEdit;
	TCobEdit *SpotNameEdit;
	TLabel *IoDivLabel;
	TComboBox *IoDivComboBox;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TActionList *ActionList1;
	TAction *SanshoAction;
	TAction *PrintAction;
	TAction *PreviewAction;
	TAction *OutputAction;
	TAction *EndAction;
	TSpeedButton *ItemSearchButtonF;
	TSpeedButton *SpotSearchButton;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TRichEdit *RichEdit1;
	TPanel *InfoPanel;
	TLabel *Label8;
	TLabel *Label9;
	TSpeedButton *ItemSearchButtonT;
	TCobEdit *ItemCodeEditT;
	TCobEdit *ItemNameEditT;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TComboBox *TorihikiComboBox;
	TComboBox *GenkakeComboBox;
	TPanel *ShabanPanel;
	TRadioButton *SharyoRadioButton;
	TRadioButton *ShabanRadioButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SanshoActionExecute(TObject *Sender);
	void __fastcall PrintActionExecute(TObject *Sender);
	void __fastcall PreviewActionExecute(TObject *Sender);
	void __fastcall OutputActionExecute(TObject *Sender);
	void __fastcall EndActionExecute(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall SelectItemComboBoxChange(TObject *Sender);
	void __fastcall SpotAllCheckBoxClick(TObject *Sender);
	void __fastcall ItemAllCheckBoxClick(TObject *Sender);
	void __fastcall ItemSearchButtonFClick(TObject *Sender);
	void __fastcall SpotCodeEditChange(TObject *Sender);
	void __fastcall SpotSearchButtonClick(TObject *Sender);
	void __fastcall ItemCodeEditFChange(TObject *Sender);
	void __fastcall ItemCodeEditTChange(TObject *Sender);
	void __fastcall ItemSearchButtonTClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
	void __fastcall SetItems();

	ItemMap item_map_;
	bool __fastcall OpenQuery();
	void __fastcall ExcelOut();
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
