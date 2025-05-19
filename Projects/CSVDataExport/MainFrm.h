//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TButton *ExportButton;
    TPanel *TitlePanel;
    TButton *Button1;
    TPanel *Panel2;
    TBevel *Bevel3;
    TDateTimePicker *FromPicker;
    TDateTimePicker *ToPicker;
    TLabel *Label1;
    TPageControl *PageControl;
    TTabSheet *USBSheet;
    TPanel *Panel1;
    TBevel *Bevel1;
    TListBox *DriveList;
    TPanel *SelectPanel;
    TBevel *Bevel2;
    TComboBox *DriveCombo;
    TTabSheet *PathSheet;
    TEdit *PathEdit;
    TButton *RefButton;
    TSaveDialog *SaveDialog;
	TMemo *ErrorMemo;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ExportButtonClick(TObject *Sender);
    void __fastcall RefButtonClick(TObject *Sender);
private:	// ユーザー宣言
    std::vector<AnsiString> ExportTables_;
    std::vector<AnsiString> DateFields_;
    void __fastcall Export(const AnsiString& path);
public:		// ユーザー宣言
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
