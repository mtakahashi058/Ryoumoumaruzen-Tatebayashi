//---------------------------------------------------------------------------

#ifndef ManualDotSlipFrmH
#define ManualDotSlipFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TManualDotSlipForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TQuickRep *QuickRep;
	TQRBand *DetailBand1;
	TQRShape *QRShape1;
	TQRShape *QRShape2;
	TQRShape *QRShape3;
	TQRShape *QRShape4;
	TQRShape *QRShape5;
	TQRShape *QRShape6;
	TQRShape *QRShape7;
	TQRShape *QRShape8;
	TQRShape *QRShape9;
	TQRShape *QRShape10;
	TQRShape *QRShape11;
	TQRShape *QRShape12;
	TQRShape *QRShape13;
	TQRLabel *NoLabel;
	TQRLabel *DateLabel;
	TQRLabel *ShabanLabel;
	TQRLabel *Item1CodeLabel;
	TQRLabel *Item1NameLabel;
	TQRLabel *Item2CodeLabel;
	TQRLabel *Item2NameLabel;
	TQRLabel *Item3CodeLabel;
	TQRLabel *Item3NameLabel;
	TQRLabel *Item4CodeLabel;
	TQRLabel *Item4NameLabel;
	TQRLabel *GrossTimeLabel;
	TQRLabel *GrossWeightLabel;
	TQRLabel *TareTimeLabel;
	TQRLabel *TareWeightLabel;
	TQRLabel *NetWeightLabel;
	TQRLabel *BikoLabel;
	TQRLabel *CompanyNameLabel;
	TQRLabel *CompanyInfoLabel1;
	TQRLabel *CompanyInfoLabel2;
	TQRLabel *CompanyInfoLabel3;
	TQRLabel *CompanyInfoLabel4;
	TQRLabel *QRLabel1;
private:	// ユーザー宣言
	TQRLabel* code_label_[4];
	TQRLabel* name_label_[4];
public:		// ユーザー宣言
	__fastcall TManualDotSlipForm(TComponent* Owner);

	bool __fastcall Print(int keiryo_id, bool hide_time = false);
};
//---------------------------------------------------------------------------
extern PACKAGE TManualDotSlipForm *ManualDotSlipForm;
//---------------------------------------------------------------------------
#endif
