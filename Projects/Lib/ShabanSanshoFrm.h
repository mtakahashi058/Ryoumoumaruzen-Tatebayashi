//---------------------------------------------------------------------------

#ifndef ShabanSanshoFrmH
#define ShabanSanshoFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TShabanSanshoForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *BottomPanel;
	TButton *OkButton;
	TButton *CancelButton;
	TDataSource *DataSource;
	TDBGrid *DBGrid;
	TPanel *TopPanel;
	TButton *NewButton;
	TStatusBar *StatusBar;
	void __fastcall OkButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall NewButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGridDblClick(TObject *Sender);
	void __fastcall DBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DBGridDrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// ユーザー宣言
	int car_id_, car_no_, data_div_;
public:		// ユーザー宣言
	__fastcall TShabanSanshoForm(TComponent* Owner);

	int __fastcall GetCarID();
    int __fastcall GetCarNo();
	int __fastcall GetDataDiv();
};
//---------------------------------------------------------------------------
extern PACKAGE TShabanSanshoForm *ShabanSanshoForm;
//---------------------------------------------------------------------------
#endif
