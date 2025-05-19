//---------------------------------------------------------------------------

#ifndef QRLabelFrmH
#define QRLabelFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TQRLabelForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TQuickRep *QuickRep;
	TQRBand *DetailBand1;
	TADOQuery *Q_Label;
	TQRDBText *QRDBText1;
	TQRLabel *TokuName1;
	TQRLabel *TokuName2;
	TQRLabel *lblYubin;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRDBText *QRDBText4;
	TQRDBText *QRDBText5;
	void __fastcall DetailBand1BeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TQRLabelForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRLabelForm *QRLabelForm;
//---------------------------------------------------------------------------
#endif
