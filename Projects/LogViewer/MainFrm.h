//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
#include <memory>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *Panel1;
	TDBGrid *DBGrid;
	TDataSource *DataSource;
	TLabel *Label1;
	TDateTimePicker *DatePickerFrom;
	TLabel *Label2;
	TDateTimePicker *DatePickerTo;
	TButton *PriorButton;
	TButton *NextButton;
	TLabel *Label3;
	TPanel *Panel2;
	TButton *OutputButton;
	TPanel *Panel3;
	TComboBox *ErrorLevelCombo;
	TSaveDialog *SaveDialog;
    TButton *UpdateButton;
	TButton *DeleteLogButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DatePickerFromChange(TObject *Sender);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall OutputButtonClick(TObject *Sender);
    void __fastcall UpdateButtonClick(TObject *Sender);
	void __fastcall DeleteLogButtonClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall SetRange();
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
