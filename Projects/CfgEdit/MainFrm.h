//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CEdit.h"
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TDataSource *DataSource;
	TTabControl *TabControl;
	TDBGrid *DBGrid;
	TADOTable *ConfigTable;
	TAutoIncField *ConfigTableID;
	TStringField *ConfigTableDSDesigner;
	TStringField *ConfigTableDSDesigner2;
	TStringField *ConfigTableDSDesigner3;
	TStringField *ConfigTableDSDesigner4;
	TPanel *BottomPanel;
	TButton *SaveButton;
	TIntegerField *ConfigTableDSDesigner5;
	TPanel *InfoBasePanel;
	TPanel *InfoBlankPanel;
	TPanel *InfoPanel;
	TMemo *InfoMemo;
	TPanel *InfoLabelPanel;
	TSplitter *Splitter;
    TButton *CloseButton;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TabControlChanging(TObject *Sender, bool &AllowChange);
	void __fastcall TabControlChange(TObject *Sender);
	void __fastcall ConfigTableAfterInsert(TDataSet *DataSet);
	void __fastcall DBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall ConfigTableAfterScroll(TDataSet *DataSet);
	void __fastcall CloseButtonClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall MessageProc(tagMSG &Msg, bool &Handled);
public:		// ユーザー宣言
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
