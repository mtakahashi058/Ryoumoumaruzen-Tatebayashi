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
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TPanel *TitlePanel;
    TButton *Button1;
	TStatusBar *StatusBar;
	TButton *ReceiveButton;
	TButton *SettingButton;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);
	void __fastcall ReceiveButtonClick(TObject *Sender);
	void __fastcall TitlePanelDblClick(TObject *Sender);
	void __fastcall SettingButtonClick(TObject *Sender);

private:	// ���[�U�[�錾
	void __fastcall Import();
	void __fastcall Download();
	int __fastcall FindOrInsertSyaryo(int car_no);

public:		// ���[�U�[�錾
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
