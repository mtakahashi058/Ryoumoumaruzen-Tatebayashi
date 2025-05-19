//---------------------------------------------------------------------------

#ifndef QRFrmH
#define QRFrmH
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
class TQRForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TQuickRep *QuickRep;
	TQRBand *PageHeaderBand;
	TQRBand *DetailBand;
	TQRSysData *QRSysData1;
	TQRSysData *QRSysData2;
	TQRLabel *TitleLabel;
	TQRLabel *RangeLabel;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRLabel *ItemLabel;
	TADOQuery *Query;
	TQRLabel *WeightLabel;
	TQRLabel *AmountLabel;
	TQRLabel *MoneyLabel;
	TQRLabel *TaniLabel;
	TIntegerField *QueryDSDesigner;
	TStringField *QueryDSDesigner2;
	TIntegerField *QueryDSDesigner3;
	TBCDField *QueryDSDesigner4;
	TBCDField *QueryDSDesigner5;
	TIntegerField *QueryDSDesigner6;
	TStringField *QueryDSDesigner7;
	TBCDField *QueryDSDesigner8;
	TQRDBText *ItemText;
	TQRShape *QRShape3;
	TQRBand *SummaryBand1;
	TQRDBText *WeightText;
	TQRDBText *AmountText;
	TQRDBText *TaniText;
	TQRDBText *MoneyText;
	TQRLabel *QRLabel1;
	TQRExpr *QRExpr1;
	TQRExpr *MoneyExpr;
	TQRDBText *QRDBText1;
	TQRLabel *QRLabel2;
	TQRDBText *QRDBText2;
	TQRExpr *QRExpr2;
	TQRShape *QRShape4;
private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TQRForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRForm *QRForm;
//---------------------------------------------------------------------------
#endif
