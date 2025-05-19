//---------------------------------------------------------------------------

#ifndef SettingFrmH
#define SettingFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "CEdit.h"
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
#include <memory>
//---------------------------------------------------------------------------
static int __stdcall BrowseCallbackProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
//---------------------------------------------------------------------------
class TSettingForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TButton *OKButton;
	TButton *CancelButton;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TCobEdit *MotoPathEdit;
	TLabel *Label2;
	TCobEdit *SakiPathEdit;
	TButton *btnMotoPath;
	TButton *btnSakiPath;
	TListBox *TaishoListBox;
	TLabel *Label3;
	TListBox *GaiListBox;
	TButton *TaishoButton;
	TLabel *Label4;
	TLabel *Label5;
	TButton *GaiButton;
	TLabel *Label6;
	TComboBox *cbSettingFile;
	TFileListBox *FileListBox;
	TLabel *Label7;
	TLabel *Label8;
	TRadioButton *rbUseKosin;
	TRadioButton *rbUnuseKosin;
	TGroupBox *GroupBox2;
	TLabel *Label9;
	TButton *ConnEditButton;
	TComboBox *cbConnFile;
	void __fastcall btnMotoPathClick(TObject *Sender);
	void __fastcall btnSakiPathClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall MotoPathEditExit(TObject *Sender);
	void __fastcall TaishoButtonClick(TObject *Sender);
	void __fastcall OKButtonClick(TObject *Sender);
	void __fastcall ConnEditButtonClick(TObject *Sender);
private:	// ユーザー宣言
	AnsiString __fastcall ShowFolderDialog(char *path);
	void __fastcall SaveKosinIni();
public:		// ユーザー宣言
	__fastcall TSettingForm(TComponent* Owner);
	bool UseKosin;
	AnsiString MotoPath, SakiPath, GaiList, SettingName;
	bool __fastcall ReadKosinIni();
	std::auto_ptr<TStringList> __fastcall CopySearch();
	void __fastcall SetIni2Form();
};
//---------------------------------------------------------------------------
extern PACKAGE TSettingForm *SettingForm;
//---------------------------------------------------------------------------
#endif

