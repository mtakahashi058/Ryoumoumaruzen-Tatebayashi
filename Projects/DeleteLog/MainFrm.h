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
	TLabel *Label1;
	TLabel *Label2;
	TDateTimePicker *DatePickerFrom;
	TDateTimePicker *DatePickerTo;
	TButton *DeleteLogButton;
	TCheckBox *FromCheckBox;
	TCheckBox *ToCheckBox;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DeleteLogButtonClick(TObject *Sender);
	void __fastcall FromCheckBoxClick(TObject *Sender);
	void __fastcall ToCheckBoxClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
