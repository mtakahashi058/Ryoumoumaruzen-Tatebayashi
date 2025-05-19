//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IniFiles.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//#include "CuteBtn.hpp"
//#include "GradBox.hpp"
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
#include <Menus.hpp>
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ActnMenus.hpp>
#include <ToolWin.hpp>
#include <FileCtrl.hpp>
#include <ImgList.hpp>
#include <vector>
#include <map>
//---------------------------------------------------------------------------
#include "thread.h"
#include <memory>
#include "StrUtils.hpp"
//---------------------------------------------------------------------------
struct TSection{
	AnsiString SectionName;
	AnsiString Paths[9];
	AnsiString ShiftPaths[9];
	AnsiString Captions[9];
	AnsiString ShiftCaptions[9];
};
typedef std::vector<TSection> SectionVector;
typedef SectionVector::iterator SectionIterator;
typedef std::map<AnsiString, PROCESS_INFORMATION> ProcessMap;
typedef ProcessMap::iterator ProcessIterator;
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TTabControl *TabPages;
	TButton *cbtn1;
	TButton *cbtn2;
	TButton *cbtn3;
	TButton *cbtn4;
	TButton *cbtn5;
	TButton *cbtn6;
	TButton *cbtn7;
	TButton *cbtn8;
	TButton *cbtn9;
	TButton *cbtnS1;
	TButton *cbtnS2;
	TButton *cbtnS3;
	TButton *cbtnS4;
	TButton *cbtnS5;
	TButton *cbtnS6;
	TButton *cbtnS7;
	TButton *cbtnS8;
	TButton *cbtnS9;
	TTimer *Timer1;
	TPopupMenu *PopupMenu1;
	TMenuItem *hoge1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TStatusBar *StatusBar;
	TButton *KosinButton;
	TButton *SettingButton;
	TLabel *LabelTitle;
	TShape *Shape1;
	TLabel *SubTitleLabel;
	TImageList *ImageList1;
	TTimer *ProcessTimer;
	TLabel *Label19;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TabPagesChange(TObject *Sender);

	void __fastcall cbtn1_Click(TObject *Sender);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cbtn1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall SettingButtonClick(TObject *Sender);
	void __fastcall KosinButtonClick(TObject *Sender);
	void __fastcall ProcessTimerTimer(TObject *Sender);
private:	// ユーザー宣言
	DWORD __fastcall AppExec(AnsiString ExeName, bool Wait = false);
	void __fastcall Execute(int Index, bool Shift = false);
	void __fastcall FillPanel(int Index);
	TExecThread *Thread;
	AnsiString IniName;
	AnsiString OnLoadPath;
	AnsiString OnEndPath;
	bool Exec;
	Word OldKey;
	DWORD DownedTime;
	SectionVector Sections;
	TButton *ButtonTable[9];
	TButton *ShiftButtonTable[9];

	ProcessMap process_map_;

	void __fastcall OnExecTerminate(TMessage& Message);
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(UM_EXECTERMINATE, TMessage, OnExecTerminate)
END_MESSAGE_MAP(TForm)
	AnsiString __fastcall AddSpace(AnsiString str);
	int nSpaceCount;
	void __fastcall CheckExistKosin();
	bool chofuku;
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
	AnsiString asConnName;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
