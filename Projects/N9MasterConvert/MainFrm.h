//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TCnvProcess)(const AnsiString& file);
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TLabel *Label1;
    TButton *RefButton;
    TOpenDialog *OpenDialog;
    TEdit *FileEdit;
    TRadioGroup *MasterGroup;
    TButton *CnvButton;
    void __fastcall RefButtonClick(TObject *Sender);
    void __fastcall CnvButtonClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// ユーザー宣言
    void __fastcall ConvertID(const AnsiString& file);
    void __fastcall ConvertItem(const AnsiString& file, int no);
public:		// ユーザー宣言
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
