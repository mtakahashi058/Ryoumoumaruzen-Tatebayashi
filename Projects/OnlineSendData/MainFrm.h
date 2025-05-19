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
#include <vector>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TButton *SendButton;
	TPanel *KeiryoDatePanel;
    TBevel *Bevel1;
    TPanel *TitlePanel;
    TButton *Button1;
	TDateTimePicker *DatePickerFrom;
	TLabel *Label1;
	TDateTimePicker *DatePickerTo;
	TButton *BeforeButton;
	TButton *NextButton;
	TButton *SettingButton;
	TStatusBar *StatusBar;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall SendButtonClick(TObject *Sender);
	void __fastcall TitlePanelDblClick(TObject *Sender);
	void __fastcall SettingButtonClick(TObject *Sender);
	void __fastcall BeforeButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
private:	// ユーザー宣言
    void __fastcall Export();
	void __fastcall Upload();
	void __fastcall DeleteFiles();
	
public:		// ユーザー宣言
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
