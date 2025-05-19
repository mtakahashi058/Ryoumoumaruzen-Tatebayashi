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
__published:	// IDE �Ǘ��̃R���|�[�l���g
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
private:	// ���[�U�[�錾
	int seikyu_, hikae_, print_;
public:		// ���[�U�[�錾
	__fastcall TConfirmForm(TComponent* Owner);
	int __fastcall ShowModalWith(int seikyu, int hikae, int print);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfirmForm *ConfirmForm;
//---------------------------------------------------------------------------
#endif
