//---------------------------------------------------------------------------

#ifndef ConfirmWeighingStateFrmH
#define ConfirmWeighingStateFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "StateForm.h"
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TConfirmWeighingStateForm : public AbstractStateForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *Label1;
	TLabel *Label7;
	TPanel *ConfirmItemTitlePanel;
    TButton *MeigChangeButton;
    TPanel *MeigPanel;
	TPanel *NetWeightPanel;
	TPanel *ConfirmShohinCardPanel;
	TLabel *Item1Label;
	TLabel *CarNoLabel;
	TLabel *Item2Label;
	TButton *CancelButton;
	TButton *ContinueButton;
	TButton *CompleteButton;
	TPanel *GridPanel;
	TPanel *Panel1;
	TDBGrid *DBGrid;
	TMemo *WarningMemo;
	TDataSource *DataSource;
	TADOQuery *GridQuery;
	TBCDField *GridQueryDSDesigner;
    TStringField *GridQueryDSDesigner2;
    TLabel *TokuLabel;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall ContinueButtonClick(TObject *Sender);
	void __fastcall CompleteButtonClick(TObject *Sender);
	void __fastcall MeigChangeButtonClick(TObject *Sender);
private:	// ユーザー宣言
    int current_weight_;

	void __fastcall PostRecord(bool complete);
    void __fastcall CopyRecords(int date, int place, int no);
public:		// ユーザー宣言
	__fastcall TConfirmWeighingStateForm(TComponent* Owner);

	virtual void __fastcall OnEvent(Event::EventID event, void *param);
	virtual void __fastcall OnEnter();
	virtual void __fastcall OnExit();
};
//---------------------------------------------------------------------------
extern PACKAGE TConfirmWeighingStateForm *ConfirmWeighingStateForm;
//---------------------------------------------------------------------------
#endif
