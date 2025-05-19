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
    TPanel *TitlePanel;
    TButton *Button1;
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
    TButton *ExportButton;
    TOpenDialog *OpenDialog;
	TMemo *ErrorMemo;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ExportButtonClick(TObject *Sender);
    void __fastcall RefButtonClick(TObject *Sender);
private:	// ユーザー宣言
    std::vector<AnsiString> ImportTables_;
    void __fastcall Import(const AnsiString& path);
    int __fastcall FindOrInsertSyaryo(int car_no);
public:		// ユーザー宣言
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
