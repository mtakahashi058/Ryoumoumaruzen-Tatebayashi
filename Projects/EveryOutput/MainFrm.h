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
#include "NsIni.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include "trayicon.h"
#include "NsDB.h"
#include <ImgList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TTimer *OutputTimer;
	TADOConnection *ADOConnection;
	TTrayIcon *TrayIcon;
	TImageList *il16;
	TPopupMenu *PopupMenu;
	TMenuItem *AD43851;
	TMenuItem *N1;
	TMenuItem *ExitItem;
	TTimer *CloseTimer;
	void __fastcall OutputTimerTimer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ExitItemClick(TObject *Sender);
	void __fastcall CloseTimerTimer(TObject *Sender);
private:	// ユーザー宣言
	NsIni INI;
    bool output_keiryo_, output_tran_;
    AnsiString local_path_, copy_path_;
    bool delete_local_file_;
    bool copy_file_;
    int mode_;	// mode = 1 :: 計量結果をポスト→事務所 ／ mode = 2 :: 伝票発行命令を事務所→ポスト
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
    NsDBInterface DBI;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
