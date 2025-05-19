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
__published:	// IDE 管理のコンポーネント
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
private:	// ユーザー宣言
    int comm_port_;
    int card_no_;

	bool __fastcall IssueCard();
public:		// ユーザー宣言
	__fastcall TRFIDIssueForm(TComponent* Owner);

    void __fastcall SetCommPort(int port);
    void __fastcall SetCardNo(int card_no);
};
//---------------------------------------------------------------------------
extern PACKAGE TRFIDIssueForm *RFIDIssueForm;
//---------------------------------------------------------------------------
#endif
