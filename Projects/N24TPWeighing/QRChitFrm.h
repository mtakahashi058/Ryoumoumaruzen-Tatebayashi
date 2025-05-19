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
    TStringField *ChitQueryStringField;
    TIntegerField *ChitQueryNo;
    TIntegerField *ChitQueryIntegerField2;
    TStringField *ChitQueryStringField2;
    TIntegerField *ChitQueryID3;
    TIntegerField *ChitQueryIntegerField3;
    TStringField *ChitQueryStringField3;
    TIntegerField *ChitQueryID4;
    TIntegerField *ChitQueryIntegerField4;
    TStringField *ChitQueryStringField4;
    TStringField *ChitQueryStringField5;
    TStringField *ChitQueryStringField6;
    TIntegerField *ChitQueryIntegerField5;
    TStringField *ChitQueryStringField7;
    TIntegerField *ChitQueryIntegerField1ID;
    TIntegerField *ChitQueryIntegerField1;
    TStringField *ChitQueryStringField1;
    TStringField *ChitQueryStringField12;
    TStringField *ChitQueryStringField13;
    TStringField *ChitQueryStringField14;
    TIntegerField *ChitQueryIntegerField2ID;
    TIntegerField *ChitQueryIntegerField22;
    TStringField *ChitQueryStringField22;
    TStringField *ChitQueryStringField23;
    TStringField *ChitQueryStringField24;
    TStringField *ChitQueryStringField25;
    TStringField *ChitQueryStringField8;
    TBCDField *ChitQueryBCDField;
    TIntegerField *ChitQueryNo2;
    TIntegerField *ChitQueryID5;
    TIntegerField *ChitQueryIntegerField6;
    TStringField *ChitQueryStringField9;
    TStringField *ChitQueryStringField10;
    TStringField *ChitQueryStringField11;
    TStringField *ChitQueryStringField15;
    TIntegerField *ChitQueryIntegerField7;
    TStringField *ChitQueryStringField16;
    TIntegerField *ChitQueryID6;
    TIntegerField *ChitQueryIntegerField8;
    TStringField *ChitQueryStringField17;
    TStringField *ChitQueryStringField18;
    TStringField *ChitQueryStringField19;
    TBCDField *ChitQueryBCDField1;
    TDateTimeField *ChitQueryDateTimeField1;
    TBCDField *ChitQueryBCDField2;
    TDateTimeField *ChitQueryDateTimeField2;
    TBCDField *ChitQueryBCDField3;
    TBCDField *ChitQueryBCDField4;
    TBCDField *ChitQueryBCDField5;
    TBCDField *ChitQueryBCDField6;
    TBCDField *ChitQueryBCDField7;
    TIntegerField *ChitQueryID7;
    TIntegerField *ChitQueryIntegerField9;
    TStringField *ChitQueryStringField20;
    TBCDField *ChitQueryBCDField8;
    TBCDField *ChitQueryBCDField9;
    TBCDField *ChitQueryBCDField10;
    TStringField *ChitQueryStringField21;
    TIntegerField *ChitQueryIntegerField10;
    TStringField *ChitQueryStringField26;
    TDateTimeField *ChitQueryDateTimeField;
    TDateTimeField *ChitQueryDateTimeField3;
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
