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
	void __fastcall OkButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGridDblClick(TObject *Sender);
	void __fastcall DBGridKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall NewButtonClick(TObject *Sender);
private:	// ユーザー宣言
	int car_id_;
public:		// ユーザー宣言
	__fastcall TShabanSanshoForm(TComponent* Owner);

	int __fastcall GetCarID();
};
//---------------------------------------------------------------------------
extern PACKAGE TShabanSanshoForm *ShabanSanshoForm;
//---------------------------------------------------------------------------
#endif
