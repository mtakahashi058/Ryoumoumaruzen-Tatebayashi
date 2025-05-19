//---------------------------------------------------------------------------

#ifndef DataExportFrmH
#define DataExportFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TDataExportForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *BottomPanel;
	TButton *CloseButton;
	TPanel *ClientPanel;
	TPanel *Panel1;
	TBevel *Bevel1;
	TDateTimePicker *FromPicker;
	TButton *FromIncButton;
	TButton *FromDecButton;
	TDateTimePicker *ToPicker;
	TButton *ToIncButton;
	TButton *ToDecButton;
	TLabel *Label1;
	TButton *ExportButton;
	TMemo *ErrorMemo;
	TButton *FromTodayButton;
	TButton *ToTodayButton;
	TLabel *Label2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FromDecButtonClick(TObject *Sender);
	void __fastcall FromIncButtonClick(TObject *Sender);
	void __fastcall ToDecButtonClick(TObject *Sender);
	void __fastcall ToIncButtonClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall ExportButtonClick(TObject *Sender);
	void __fastcall FromTodayButtonClick(TObject *Sender);
	void __fastcall ToTodayButtonClick(TObject *Sender);
private:	// ユーザー宣言
    std::vector<AnsiString> ExportTables_;
    std::vector<AnsiString> DateFields_;

	void __fastcall Export();
public:		// ユーザー宣言
	__fastcall TDataExportForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataExportForm *DataExportForm;
//---------------------------------------------------------------------------
#endif
