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
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TButton *ExportButton;
    TPanel *TitlePanel;
    TButton *Button1;
    TPageControl *PageControl;
    TTabSheet *USBSheet;
    TTabSheet *PathSheet;
    TEdit *PathEdit;
    TButton *RefButton;
    TListBox *DriveList;
    TPanel *Panel1;
    TBevel *Bevel1;
    TComboBox *DriveCombo;
    TPanel *SelectPanel;
    TBevel *Bevel2;
    TOpenDialog *OpenDialog;
	TMemo *ErrorMemo;
	TCheckBox *ExportSharyoCheck;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall ExportButtonClick(TObject *Sender);
    void __fastcall RefButtonClick(TObject *Sender);
private:	// ���[�U�[�錾
    void __fastcall Import(const AnsiString& path);
public:		// ���[�U�[�錾
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
