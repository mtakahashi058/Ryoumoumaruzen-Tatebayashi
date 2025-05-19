// ---------------------------------------------------------------------------

#ifndef ObserveFrmH
#define ObserveFrmH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "trayicon.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "CEdit.h"
#include <ScktComp.hpp>
// ---------------------------------------------------------------------------
#include <fstream>
#include <map>
typedef std::map<AnsiString, AnsiString> StringMap;
// ---------------------------------------------------------------------------
int __stdcall BrowseCallbackProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
class TObserveForm : public TForm
{
__published: // IDE 管理のコンポーネント
	TImageList *ImageList;
	TPopupMenu *PopupMenu;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TSpeedButton *TargetButton;
	TGroupBox *WorkaroundGroupBox;
	TRadioButton *MoveRadioButton;
	TRadioButton *DeleteRadioButton;
	TLabel *Label4;
	TSpeedButton *EvacuationButton;
	TPanel *BottomPanel;
	TButton *ApplyButton;
	TButton *CancelButton;
	TCobEdit *IntervalEdit;
	TCobEdit *TargetEdit;
	TCobEdit *EvacuationEdit;
	TTimer *ObserveTimer;
	TTrayIcon *TrayIcon;
	TLabel *Label5;
	TTimer *PrintTimer;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall TargetButtonClick(TObject *Sender);
	void __fastcall MoveRadioButtonClick(TObject *Sender);
	void __fastcall EvacuationButtonClick(TObject *Sender);
	void __fastcall ApplyButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall ObserveTimerTimer(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall PrintTimerTimer(TObject *Sender);
private: // ユーザー宣言
	bool is_exit_selected_, print_chit_;
	StringMap data_keys_;
	int print_count_;

	void __fastcall LoadInifile();
	AnsiString __fastcall ShowFolderDialog(char *path);
	bool __fastcall PostTable(AnsiString table, AnsiString file_path, AnsiString& msg);
public: // ユーザー宣言
	__fastcall TObserveForm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TObserveForm *ObserveForm;
// ---------------------------------------------------------------------------
#endif
