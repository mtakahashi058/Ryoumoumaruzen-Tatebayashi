//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <vector>
#include "BatMsgs.h"
#include "N95ExportThread.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TButton *ItemExportButton;
    TButton *CloseButton;
    TLabel *StatusLabel;
    TProgressBar *ProgressBar;
    TBevel *Bevel1;
    TButton *CarsExportButton;
    TLabel *Label1;
    TLabel *CountLabel;
    TLabel *Label2;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CloseButtonClick(TObject *Sender);
    void __fastcall ItemExportButtonClick(TObject *Sender);
    void __fastcall CarsExportButtonClick(TObject *Sender);
private:	// ���[�U�[�錾
    int port_;
    AnsiString def_;
    TThread *thread_;
    Records records_;

	void __fastcall OnCompleted(TMessage& message);
	void __fastcall OnAborted(TMessage& message);
	void __fastcall OnStatus(TMessage& message);
	void __fastcall OnDataSended(TMessage& message);
	void __fastcall OnProcessStep(TMessage& message);
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(BM_COMPLETED,    TMessage, OnCompleted)
	MESSAGE_HANDLER(BM_ABORTED,      TMessage, OnAborted)
	MESSAGE_HANDLER(BM_STATUS,       TMessage, OnStatus)
	MESSAGE_HANDLER(BM_DATASENDED,   TMessage, OnDataSended)
	MESSAGE_HANDLER(BM_PROCESS_STEP, TMessage, OnProcessStep)
END_MESSAGE_MAP(TForm)

public:		// ���[�U�[�錾
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
