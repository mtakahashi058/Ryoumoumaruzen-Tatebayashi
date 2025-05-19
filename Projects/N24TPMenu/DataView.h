//---------------------------------------------------------------------------

#ifndef DataViewH
#define DataViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDataViewForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *ClientPanel;
	TPanel *BottomPanel;
	TButton *CloseButton;
	TDBGrid *DBGrid;
	TDataSource *DataSource;
	TADOQuery *ADOQuery;
	TIntegerField *ADOQueryDSDesigner;
	TBCDField *ADOQueryDSDesigner4;
	TButton *PriorButton;
	TButton *NextButton;
    TStringField *ADOQueryDSDesigner2;
    TStringField *ADOQueryDSDesigner1;
    TStringField *ADOQueryDSDesigner22;
    TStringField *ADOQueryDSDesigner3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
	void __fastcall PriorButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
	__fastcall TDataViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataViewForm *DataViewForm;
//---------------------------------------------------------------------------
#endif
