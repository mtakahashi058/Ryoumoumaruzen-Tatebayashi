//---------------------------------------------------------------------------

#ifndef QRChitFrmH
#define QRChitFrmH
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
class TQRChitForm : public TForm
{
__published:	// IDE Ǘ̃R|[lg
	TQuickRep *QR;
	TQRBand *QRBand1;
	TQRLabel *QRTitle;
	TQRBand *QRBand2;
    TQRLabel *QRCompany;
    TQRLabel *QRFooter1;
	TQRBand *QRBand3;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRShape *QRShape3;
	TQRShape *QRShape6;
	TQRLabel *QRLabel11;
	TQRShape *QRShape7;
	TQRShape *QRShape8;
	TQRLabel *QRLabel13;
	TQRShape *QRShape9;
	TQRShape *QRShape10;
    TQRLabel *TokuTitleLabel;
	TQRShape *QRShape11;
    TQRLabel *MeigTitleLabel;
	TQRShape *QRShape13;
	TQRShape *QRShape14;
	TQRLabel *QRLabel19;
	TQRShape *QRShape15;
	TQRLabel *QRLabel21;
	TQRShape *QRShape16;
	TQRDBText *QRDBText1;
	TQRDBText *QRDBText2;
	TQRDBText *QRDBText3;
	TQRShape *QRShape21;
	TQRLabel *QRLabel6;
	TQRShape *QRShape22;
	TQRLabel *QRLabel12;
	TQRDBText *QRDBText4;
	TQRShape *QRShape23;
	TQRLabel *QRLabel18;
	TQRShape *QRShape24;
	TQRLabel *QRLabel20;
	TQRDBText *QRDBText5;
	TADOQuery *ChitQuery;
	TQRLabel *QRLabel7;
	TQRDBText *QRDBText6;
	TQRDBText *QRDBText7;
	TQRDBText *QRDBText8;
	TQRDBText *QRDBText9;
	TQRDBText *QRDBText11;
	TQRDBText *QRDBText12;
	TQRLabel *QRLabel8;
    TQRLabel *QRFooter2;
    TQRLabel *QRFooter3;
	TQRShape *QRShape5;
	TQRDBText *QRDBText10;
	TQRDBText *QRDBText13;
    TQRLabel *Item1TitleLabel;
	TQRShape *QRShape12;
    TQRLabel *QRFooter4;
    TQRShape *QRShape4;
    TQRDBText *QRDBText14;
    TQRDBText *QRDBText15;
    TQRLabel *Item2TitleLabel;
    TQRShape *QRShape27;
    TIntegerField *ChitQueryID;
    TIntegerField *ChitQueryIntegerField;
    TIntegerField *ChitQueryID2;
    TIntegerField *ChitQueryNo;
    TIntegerField *ChitQueryIntegerField2;
    TIntegerField *ChitQueryIntegerField3;
    TIntegerField *ChitQueryIntegerField4;
    TStringField *ChitQueryStringField5;
    TIntegerField *ChitQueryIntegerField1;
    TStringField *ChitQueryStringField13;
    TIntegerField *ChitQueryIntegerField22;
    TStringField *ChitQueryStringField24;
    TIntegerField *ChitQueryNo2;
    TIntegerField *ChitQueryIntegerField6;
    TStringField *ChitQueryStringField11;
    TBCDField *ChitQueryBCDField1;
    TBCDField *ChitQueryBCDField2;
    TDateTimeField *ChitQueryDateTimeField2;
    TBCDField *ChitQueryBCDField6;
    TIntegerField *ChitQueryIntegerField11;
    TIntegerField *ChitQueryIntegerField12;
    void __fastcall ChitQueryCalcFields(TDataSet *DataSet);
private:   
public:
	__fastcall TQRChitForm(TComponent* Owner);
	void __fastcall Print(int keiryo_id);
};
//---------------------------------------------------------------------------
extern PACKAGE TQRChitForm *QRChitForm;
//---------------------------------------------------------------------------
#endif
