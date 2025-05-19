//---------------------------------------------------------------------------

#ifndef TaxEditFrmH
#define TaxEditFrmH
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
class TTaxEditForm : public TForm
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
      TPanel *DatePanel;
      TLabel *Label1;
      TPanel *TaxRatePanel;
      TLabel *Label2;
      TCobEdit *TaxRateEdit;
      TActionList *ActionList;
      TAction *Action4;
      TAction *Action5;
      TAction *Action7;
      TAction *Action8;
      TAction *Action12;
      TDateTimePicker *StartDatePicker;
      void __fastcall FormShow(TObject *Sender);
      void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
      void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
      void __fastcall Action5Execute(TObject *Sender);
      void __fastcall Action7Execute(TObject *Sender);
      void __fastcall Action8Execute(TObject *Sender);
      void __fastcall Action12Execute(TObject *Sender);
	void __fastcall DatePanelEnter(TObject *Sender);
	void __fastcall DatePanelExit(TObject *Sender);
private:	// ユーザー宣言
      void __fastcall BrowseRecord();
      void __fastcall ClearForm();
      bool __fastcall PostRecord();
      void __fastcall SetMode(TInputMode mode);
      bool __fastcall CheckEdit();
public:		// ユーザー宣言
      __fastcall TTaxEditForm(TComponent* Owner);

      int date_;
      bool is_edit_;

      int __fastcall ShowModalWithId(int date);
};
//---------------------------------------------------------------------------
extern PACKAGE TTaxEditForm *TaxEditForm;
//---------------------------------------------------------------------------
#endif
