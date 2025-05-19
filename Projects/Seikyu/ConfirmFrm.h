//---------------------------------------------------------------------------

#ifndef ConfirmFrmH
#define ConfirmFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TConfirmForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *CreateDataPanel;
	TRichEdit *CreateDataEdit;
	TPanel *SeikyuPanel;
	TPanel *PrintPanel;
	TButton *ExecButton;
	TButton *CancelButton;
	TPanel *Panel4;
	TPanel *HikaePanel;
	TPanel *PreviewPanel;
	TDBGrid *DBGridSimeCheck;
	TDataSource *DataSource1;
	TPanel *ChuiPanel;
	void __fastcall FormShow(TObject *Sender);
private:	// ユーザー宣言
	int seikyu_, hikae_, print_;
public:		// ユーザー宣言
	__fastcall TConfirmForm(TComponent* Owner);
	int __fastcall ShowModalWith(int seikyu, int hikae, int print);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfirmForm *ConfirmForm;
//---------------------------------------------------------------------------
#endif
