//---------------------------------------------------------------------------

#ifndef TankaEditFrmH
#define TankaEditFrmH
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
class TTankaEditForm : public TForm
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
	TPanel *F1Panel;
	TPanel *F2Panel;
	TPanel *F3Panel;
	TPanel *F4Panel;
	TButton *F5Button;
	TButton *F7Button;
	TButton *F3Button;
	TButton *F4Button;
	TActionList *ActionList;
	TAction *Action5;
	TAction *Action7;
	TAction *Action8;
	TAction *Action12;
	TPanel *Panel1;
	TPanel *TankaPanel;
	TLabel *Label3;
	TCobEdit *TankaEdit;
	TAction *Action4;
	TPanel *HinmokuPanel;
	TLabel *HinmokuLabel;
	TSpeedButton *HinmokuSearchButton;
	TCobEdit *HinmokuCodeEdit;
	TCobEdit *HinmokuNameEdit;
	TPanel *TokuisakiPanel;
	TLabel *TokuisakiLabel;
	TSpeedButton *TokuisakiSearchButton;
	TCobEdit *TokuisakiCodeEdit;
	TCobEdit *TokuisakiNameEdit;
	TPanel *TaniPanel;
	TLabel *TaniLabel;
	TSpeedButton *TaniSearchButton;
	TCobEdit *TaniCodeEdit;
	TCobEdit *TaniNameEdit;
	TPanel *Item1Panel;
	TLabel *Item1Label;
	TSpeedButton *Item1SearchButton;
	TCobEdit *Item1CodeEdit;
	TCobEdit *Item1NameEdit;
	TPanel *Item2Panel;
	TLabel *Item2Label;
	TSpeedButton *Item2SearchButton;
	TCobEdit *Item2CodeEdit;
	TCobEdit *Item2NameEdit;
      TButton *Button1;
      TPanel *Panel2;
      TButton *Button2;
      TPanel *Panel3;
      TAction *Action1;
      TAction *Action3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action7Execute(TObject *Sender);
	void __fastcall Action8Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall Action4Execute(TObject *Sender);
	void __fastcall TankaEditEnter(TObject *Sender);
	void __fastcall UseDivComboBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall HinmokuCodeEditChange(TObject *Sender);
	void __fastcall HinmokuSearchButtonClick(TObject *Sender);
	void __fastcall HinmokuCodeEditEnter(TObject *Sender);
	void __fastcall TokuisakiCodeEditChange(TObject *Sender);
	void __fastcall TaniCodeEditChange(TObject *Sender);
	void __fastcall TokuisakiSearchButtonClick(TObject *Sender);
	void __fastcall TaniSearchButtonClick(TObject *Sender);
	void __fastcall TokuisakiCodeEditEnter(TObject *Sender);
	void __fastcall TaniCodeEditEnter(TObject *Sender);
	void __fastcall Item1CodeEditChange(TObject *Sender);
	void __fastcall Item1SearchButtonClick(TObject *Sender);
	void __fastcall Item2CodeEditChange(TObject *Sender);
	void __fastcall Item2SearchButtonClick(TObject *Sender);
	void __fastcall Item1CodeEditEnter(TObject *Sender);
	void __fastcall Item2CodeEditEnter(TObject *Sender);
      void __fastcall Action1Execute(TObject *Sender);
      void __fastcall Action3Execute(TObject *Sender);
      void __fastcall TokuisakiCodeEditExit(TObject *Sender);
	void __fastcall TokuisakiPanelEnter(TObject *Sender);
	void __fastcall TokuisakiPanelExit(TObject *Sender);
private:	// ユーザー宣言
	int id_, page_;
	bool is_edit_;
	AnsiString toku_, hin_, item1_, item2_, keyfield_; 

	void __fastcall ClearForm();
	void __fastcall SetMode(TInputMode mode);
	bool __fastcall CheckEdit();
	bool __fastcall PostRecord();
	void __fastcall BrowseRecord();
public:		// ユーザー宣言
	__fastcall TTankaEditForm(TComponent* Owner);

	int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TTankaEditForm *TankaEditForm;
//---------------------------------------------------------------------------
#endif
