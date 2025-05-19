//---------------------------------------------------------------------------

#ifndef ItemRelateEditFrmH
#define ItemRelateEditFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "CEdit.h"
#include <Buttons.hpp>
#include "DMFrm.h"
//---------------------------------------------------------------------------
class TItemRelateEditForm : public TForm
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
      TPanel *SetObjectPanel;
      TPanel *ItemNoPanel;
      TLabel *ItemNoLabel;
      TCobEdit *ItemNoCodeEdit;
      TPanel *TokuisakiPanel;
      TComboBox *ItemNoNameComboBox;
      TLabel *TokuisakiLabel;
      TCobEdit *TokuisakiCodeEdit;
      TCobEdit *TokuisakiNameEdit;
      TSpeedButton *TokuisakiSearchButton;
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
      TPanel *HinmokuPanel;
      TLabel *HinmokuLabel;
      TSpeedButton *HinmokuSearchButton;
      TCobEdit *HinmokuCodeEdit;
      TCobEdit *HinmokuNameEdit;
      TLabel *SetObjectLabel;
      TCobEdit *SetObjectCodeEdit;
      TCobEdit *SetObjectNameEdit;
      TSpeedButton *SetObjectSearchButton;
      TActionList *ActionList;
      TAction *Action4;
      TAction *Action5;
      TAction *Action7;
      TAction *Action8;
      TAction *Action12;
      void __fastcall Action4Execute(TObject *Sender);
      void __fastcall Action5Execute(TObject *Sender);
      void __fastcall Action7Execute(TObject *Sender);
      void __fastcall Action8Execute(TObject *Sender);
      void __fastcall Action12Execute(TObject *Sender);
      void __fastcall FormShow(TObject *Sender);
      void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
      void __fastcall ItemNoCodeEditChange(TObject *Sender);
      void __fastcall ItemNoCodeEditEnter(TObject *Sender);
      void __fastcall ItemNoNameComboBoxChange(TObject *Sender);
      void __fastcall ItemNoNameComboBoxEnter(TObject *Sender);
      void __fastcall SetObjectCodeEditChange(TObject *Sender);
      void __fastcall SetObjectCodeEditEnter(TObject *Sender);
      void __fastcall SetObjectSearchButtonClick(TObject *Sender);
      void __fastcall TokuisakiCodeEditChange(TObject *Sender);
      void __fastcall TokuisakiCodeEditEnter(TObject *Sender);
      void __fastcall TokuisakiSearchButtonClick(TObject *Sender);
      void __fastcall Item1CodeEditChange(TObject *Sender);
      void __fastcall Item1CodeEditEnter(TObject *Sender);
      void __fastcall Item1SearchButtonClick(TObject *Sender);
      void __fastcall Item2CodeEditChange(TObject *Sender);
      void __fastcall Item2CodeEditEnter(TObject *Sender);
      void __fastcall Item2SearchButtonClick(TObject *Sender);
      void __fastcall HinmokuCodeEditChange(TObject *Sender);
      void __fastcall HinmokuCodeEditEnter(TObject *Sender);
      void __fastcall HinmokuSearchButtonClick(TObject *Sender);
      void __fastcall HinmokuCodeEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
      void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
      void __fastcall Item2CodeEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ItemNoPanelEnter(TObject *Sender);
	void __fastcall ItemNoPanelExit(TObject *Sender);
private:	// ユーザー宣言
      void __fastcall ClearForm();
      void __fastcall BrowseRecord();
      bool __fastcall PostRecord();
      bool __fastcall CheckEdit();
      void __fastcall SetMode(TInputMode mode);
      void __fastcall SetComponent(int no);
public:		// ユーザー宣言
      __fastcall TItemRelateEditForm(TComponent* Owner);

      int id_;
      bool is_edit_;

      int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TItemRelateEditForm *ItemRelateEditForm;
//---------------------------------------------------------------------------
#endif
