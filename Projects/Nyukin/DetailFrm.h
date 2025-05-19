//---------------------------------------------------------------------------

#ifndef DetailFrmH
#define DetailFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "CEdit.h"
#include "StrCGrid.hpp"
#include <Grids.hpp>
//---------------------------------------------------------------------------
#define NEW_CLR	(0x00E8D0B9)
#define MOD_CLR	(0x00BEE7BA)
#define DEL_CLR	(0x00BAC1E7)
#define NON_CLR	(clBtnFace)
#ifndef _INPUTMODE_
#define _INPUTMODE_
enum TInputMode{imNew,imMod,imDel,imNon};
#endif
//---------------------------------------------------------------------------
class TDetailForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *DatePanel;
	TLabel *Label1;
	TPanel *SlipNoPanel;
	TLabel *Label2;
	TPanel *TokuisakiPanel;
	TLabel *Label3;
	TDateTimePicker *DatePicker;
	TSpeedButton *SeikyusakiSearchButton;
	TCobEdit *SeikyusakiNameEdit;
	TCobEdit *SeikyusakiCodeEdit;
	TCobEdit *SlipNoEdit;
	TGroupBox *NyukinGroupBox;
	TPanel *GenkinPanel;
	TLabel *Label4;
	TCobEdit *GenkinEdit;
	TPanel *HurikomiPanel;
	TLabel *Label5;
	TCobEdit *HurikomiEdit;
	TPanel *TesuryoPanel;
	TLabel *Label6;
	TCobEdit *TesuryoEdit;
	TPanel *KogittePanel;
	TLabel *Label7;
	TCobEdit *KogitteEdit;
	TPanel *TegataPanel;
	TLabel *Label9;
	TCobEdit *TegataEdit;
	TPanel *SousaiPanel;
	TLabel *Label10;
	TCobEdit *SousaiEdit;
	TPanel *NebikiPanel;
	TLabel *Label11;
	TCobEdit *NebikiEdit;
	TPanel *ChoseiPanel;
	TLabel *Label12;
	TCobEdit *ChoseiEdit;
	TPanel *SonotaPanel;
	TLabel *Label13;
	TCobEdit *SonotaEdit;
	TPanel *GokeiPanel;
	TLabel *Label14;
	TCobEdit *GokeiEdit;
	TPanel *KijituPanel;
	TLabel *Label15;
	TDateTimePicker *KijituPicker;
	TPanel *BikoPanel;
	TLabel *Label16;
	TCobEdit *BikoEdit;
	TPanel *ModePanel;
	TPanel *F1Panel;
	TPanel *F4Panel;
	TButton *F5Button;
	TButton *F12Button;
	TPanel *RenewDatePanel;
	TLabel *Label19;
	TLabel *RenewDateLabel;
	TPanel *CreateDatePanel;
	TLabel *Label21;
	TLabel *CreateDateLabel;
	TCheckBox *RenzokuCheckBox;
	TActionList *ActionList1;
	TAction *Action4;
	TAction *Action5;
	TAction *Action12;
	TCobEdit *DateEdit;
	TCobEdit *KijituEdit;
	TPanel *KyotenPanel;
	TLabel *Label8;
	TSpeedButton *KyotenSearchButton;
	TCobEdit *KyotenNameEdit;
	TCobEdit *KyotenCodeEdit;
	TPanel *BankPanel;
	TLabel *Label17;
	TCobEdit *BankCodeEdit;
	TCobEdit *BankNameEdit;
	TSpeedButton *BankSearchButton;
	TCobEdit *SitenEdit;
	TCobEdit *KouzaEdit;
	TSpeedButton *SaibanButton;
	TGroupBox *SeikyuInfoGroupBox;
	TPanel *Panel3;
	TLabel *Label18;
	TDateTimePicker *NyukinDatePicker;
	TPanel *Panel4;
	TLabel *Label20;
	TCobEdit *YoteigakuEdit;
	TPanel *Panel5;
	TLabel *Label22;
	TCobEdit *NyukinEdit;
	TSpeedButton *PriorButton;
	TSpeedButton *NextButton;
	TPanel *Panel6;
	TLabel *Label23;
	TCobEdit *SagakuEdit;
	TPanel *Panel7;
	TLabel *Label24;
	TStrColGrid *StrColGrid;
	TLabel *SiteLabel;
	TLabel *LastTesuryoLabel;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DateMaskEditExit(TObject *Sender);
	void __fastcall DatePickerChange(TObject *Sender);
	void __fastcall DatePickerCloseUp(TObject *Sender);
	void __fastcall DatePickerEnter(TObject *Sender);
	void __fastcall DatePickerExit(TObject *Sender);
	void __fastcall SlipNoEditExit(TObject *Sender);
	void __fastcall SeikyusakiCodeEditChange(TObject *Sender);
	void __fastcall SeikyusakiSearchButtonClick(TObject *Sender);
	void __fastcall GenkinEditExit(TObject *Sender);
	void __fastcall KijituPickerChange(TObject *Sender);
	void __fastcall KijituPickerCloseUp(TObject *Sender);
	void __fastcall KijituPickerEnter(TObject *Sender);
	void __fastcall KijituPickerExit(TObject *Sender);
	void __fastcall BikoEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall Action4Execute(TObject *Sender);
	void __fastcall Action5Execute(TObject *Sender);
	void __fastcall Action12Execute(TObject *Sender);
	void __fastcall TegataEditChange(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall GenkinEditEnter(TObject *Sender);
	void __fastcall DateEditEnter(TObject *Sender);
	void __fastcall DateEditExit(TObject *Sender);
	void __fastcall KijituEditEnter(TObject *Sender);
	void __fastcall KijituEditExit(TObject *Sender);
	void __fastcall KyotenCodeEditChange(TObject *Sender);
	void __fastcall KyotenSearchButtonClick(TObject *Sender);
	void __fastcall BankCodeEditChange(TObject *Sender);
	void __fastcall BankSearchButtonClick(TObject *Sender);
	void __fastcall NyukinDatePickerChange(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall StrColGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall SaibanButtonClick(TObject *Sender);
	void __fastcall DatePanelEnter(TObject *Sender);
	void __fastcall DatePanelExit(TObject *Sender);
private:	// ユーザー宣言
	int id_;

	TInputMode __fastcall GetMode();
	void __fastcall SetMode(TInputMode mode);
	int __fastcall GetNo();
	void __fastcall ClearForm();
	void __fastcall BrowseRecord(int id);
	bool __fastcall CheckEdit();
	bool __fastcall PostRecord();
	void __fastcall SetSeikyuDate();
	void __fastcall BrowseSeikyuInfo();
public:		// ユーザー宣言
	__fastcall TDetailForm(TComponent* Owner);

	int __fastcall ShowModalWithId(int id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDetailForm *DetailForm;
//---------------------------------------------------------------------------
#endif
