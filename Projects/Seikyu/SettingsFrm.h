//---------------------------------------------------------------------------

#ifndef SettingsFrmH
#define SettingsFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include "StrCGrid.hpp"
#include <Grids.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
class TSettingsForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel1;
	TCobEdit *SeikyumotoEdit01;
	TCobEdit *ShameiEdit;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TCobEdit *SeikyumotoEdit02;
	TCobEdit *SeikyumotoEdit03;
	TCobEdit *SeikyumotoEdit04;
	TCobEdit *SeikyumotoEdit05;
	TCobEdit *SeikyumotoEdit06;
	TCobEdit *SeikyumotoEdit07;
	TCobEdit *SeikyumotoEdit08;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TCobEdit *UpperMessageEdit;
	TPanel *ColorPanel1;
	TCobEdit *KagamiName1Edit;
	TCobEdit *KagamiName2Edit;
	TCobEdit *KagamiName3Edit;
	TCobEdit *KagamiName4Edit;
	TCobEdit *KagamiName5Edit;
	TCobEdit *KagamiName6Edit;
	TPanel *ColorPanel2;
	TCobEdit *KagamiName7Edit;
	TShape *Shape1;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
	TShape *Shape6;
	TShape *Shape7;
	TShape *Shape8;
	TShape *Shape9;
	TShape *Shape10;
	TCobEdit *MiddleMessageEdit;
	TLabel *Label10;
	TLabel *Label11;
	TCobEdit *LowerMessageEdit;
	TPanel *ColorPanel3;
	TCobEdit *DateTitleEdit;
	TCobEdit *HinTitleEdit;
	TCobEdit *TaniTitleEdit;
	TCobEdit *TankaTitleEdit;
	TCobEdit *KingakuTitleEdit;
	TCobEdit *BikoTitleEdit;
	TShape *Shape11;
	TShape *Shape12;
	TShape *Shape13;
	TCobEdit *SuryoTitleEdit;
	TColorDialog *ColorDialog;
	TButton *SaveButton;
	TButton *CancelButton;
	TShape *Shape18;
	TShape *Shape19;
	TShape *Shape20;
	TShape *Shape21;
	TShape *Shape22;
	TShape *Shape23;
	TGroupBox *GroupBox1;
	TRadioGroup *MukiRadio;
	TRadioGroup *NyukinRadio;
	TShape *Shape16;
	TShape *Shape15;
	TShape *Shape14;
	TButton *BgColorButton;
	TLabel *Label12;
	TComboBox *BikoItemComboBox;
	TRadioGroup *TotalRadio;
	TButton *TxColorButton;
	TPanel *ColorPanel;
	TLabel *TitleLabel;
	TShape *Shape17;
	TGroupBox *GroupBoxKomoku;
	TButton *UpButton;
	TStrColGrid *KomokuListGrid;
	TButton *DownButton;
	TListBox *ListBox1;
	TLabel *Label1;
	TCobEdit *PasswordEdit;
	TPanel *KomokuDispPanel;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall BgColorButtonClick(TObject *Sender);
	void __fastcall TxColorButtonClick(TObject *Sender);
	void __fastcall KomokuListGridDblClick(TObject *Sender);
	void __fastcall UpButtonClick(TObject *Sender);
	void __fastcall PasswordEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall KomokuDispPanelClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall GetValueFromDB();
	bool __fastcall SetValueToDB();
	void __fastcall GetValueFromForm();
	void __fastcall SetValueToForm();
	bool is_set, is_value_set;
	AnsiString shamei;
	AnsiString seikyumoto[8];
	AnsiString kagami[7];
	AnsiString mei_title[7];
	AnsiString message[3];
	AnsiString orderby;
	AnsiString shokei;
	AnsiString newpage;
	AnsiString desc;
	AnsiString orientation;
	AnsiString output_nyukin;
	AnsiString output_total;
	AnsiString biko_komoku;
	TColor bgcolor;
	TColor txcolor;
	AnsiString __fastcall GetKomokuName(AnsiString mode, int komoku_id);
	AnsiString __fastcall RemoveSpace(AnsiString buff);
	void __fastcall PostSettings(AnsiString fname, AnsiString value);
	AnsiString __fastcall GetExpressionSql(AnsiString list, AnsiString komoku_name);

public:		// ユーザー宣言
	__fastcall TSettingsForm(TComponent* Owner);
	void __fastcall SetSeikyusho();
	TQuickRep *report;
	TQRLabel *title_label;
	TQRLabel *date_label;
	TQRLabel *seikyusaki_label;
	TForm *report_form;
};
//---------------------------------------------------------------------------
extern PACKAGE TSettingsForm *SettingsForm;
//---------------------------------------------------------------------------
#endif
