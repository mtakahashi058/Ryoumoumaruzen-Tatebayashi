//---------------------------------------------------------------------------

#ifndef RFIDWriteFrmH
#define RFIDWriteFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "HF04Issuer.h"
//---------------------------------------------------------------------------
class TRFIDIssueForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TPanel *Panel1;
	TPanel *Panel2;
	TButton *WriteButton;
	TButton *CancelButton;
	TLabel *Label1;
	TLabel *Label2;
	TPanel *StatusPanel;
	TMemo *StatusMemo;
	void __fastcall WriteButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// ���[�U�[�錾
    int comm_port_;
    int card_no_;

	bool __fastcall IssueCard();
public:		// ���[�U�[�錾
	__fastcall TRFIDIssueForm(TComponent* Owner);

    void __fastcall SetCommPort(int port);
    void __fastcall SetCardNo(int card_no);
};
//---------------------------------------------------------------------------
extern PACKAGE TRFIDIssueForm *RFIDIssueForm;
//---------------------------------------------------------------------------
#endif
