//---------------------------------------------------------------------------

#ifndef Item1EditFrmH
#define Item1EditFrmH
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
class TItem1EditForm : public TForm
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
      TButton *F8Button;
      TButton *F12Button;
	TActionList *ActionList;
	TAction *Action5;
	TAction *Action7;
	TAction *Action8;
	TAction *Action12;
	TPanel *Panel1;
	TPanel *CodePanel;
	TLabel *Label1;
	TSpeedButton *SaibanButton;
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
	TPanel *UseDivPanel;
	TLabel *Label10;
	TComboBox *UseDivComboBox;
	TAction *Action4;
      TPanel *Panel2;
      TPanel *Panel3;
      TButton *F1Button;
      TButton *F3Button;
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
	void __fastcall CodeEditExit(TObject *Sender);
	void __fastcall SaibanButtonClick(TObject *Sender);
	void __fastcall NameEditExit(TObject *Sender);
	void __fastcall CodeEditEnter(TObject *Sender);
	void __fastcall NameEditEnter(TObject *Sender);
	void __fastcall ShortNameEditEnter(TObject *Sender);
	void __fastcall KanaEditEnter(TObject *Sender);
	void __fastcall UseDivComboBoxEnter(TObject *Sender);
	void __fastcall UseDivComboBoxExit(TObject *Sender);
	void __fastcall UseDivComboBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
      void __fastcall Action1Execute(TObject *Sender);
      void __fastcall Action3Execute(TObject *Sender);
	void __fastcall CodePanelEnter(TObject *Sender);
	void __fastcall CodePanelExit(TObject *Sender);
private:	// ユーザー宣言
      int id_, page_;
      bool is_edit_;
      MasterMap use_div_map_;
      AnsiString keyfield_;

      void __fastcall ClearForm();
	void __fastcall SetMode(TInputMode mode);
	int __fastcall GetNo();
	bool __fastcall CheckEdit();
	bool __fastcall PostRecord();
	void __fastcall BrowseRecord();
	void __fastcall AutoKanaMessage(tagMSG &Msg, bool &Handled);
public:		// ユーザー宣言
	__fastcall TItem1EditForm(TComponent* Owner);

	int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TItem1EditForm *Item1EditForm;
//---------------------------------------------------------------------------
#endif
