//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("YubinSearchFrm.cpp", YubinSearchForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("MainFrm.cpp", MainForm);
USEFORM("..\Lib\SearchFrm.cpp", SearchForm);
USEFORM("TokuisakiEditFrm.cpp", TokuisakiEditForm);
USEFORM("Item2EditFrm.cpp", Item2EditForm);
USEFORM("HinBnruiEditFrm.cpp", HinBunruiEditForm);
USEFORM("TankaEditFrm.cpp", TankaEditForm);
USEFORM("TaniEditFrm.cpp", TaniEditForm);
USEFORM("HinmokuEditFrm.cpp", HinmokuEditForm);
USEFORM("SharyoEditFrm.cpp", SharyoEditForm);
USEFORM("Item1EditFrm.cpp", Item1EditForm);
USEFORM("KyotenEditFrm.cpp", KyotenEditForm);
USEFORM("KanzanEditFrm.cpp", KanzanEditForm);
USEFORM("QRKyotenFrm.cpp", QRKyotenForm);
USEFORM("QRTaniFrm.cpp", QRTaniForm);
USEFORM("QRHinmokuFrm.cpp", QRHinmokuForm);
USEFORM("QRItem1Frm.cpp", QRItem1Form);
USEFORM("QRItem2Frm.cpp", QRItem2Form);
USEFORM("QRHinBunruiFrm.cpp", QRHinBunruiForm);
USEFORM("QRTokuisakiFrm.cpp", QRTokuisakiForm);
USEFORM("QRKanzanFrm.cpp", QRKanzanForm);
USEFORM("QRTankaFrm.cpp", QRTankaForm);
USEFORM("QRSharyoFrm.cpp", QRSharyoForm);
USEFORM("SlipInfoEditFrm.cpp", SlipInfoEditForm);
USEFORM("SlipInfoRelateEditFrm.cpp", SlipInfoRelateEditForm);
USEFORM("ItemRelateEditFrm.cpp", ItemRelateEditForm);
USEFORM("TaxEditFrm.cpp", TaxEditForm);
USEFORM("BankEditFrm.cpp", BankEditForm);
USEFORM("QRSlipInfoFrm.cpp", QRSlipInfoForm);
USEFORM("QRSlipInfoRelateFrm.cpp", QRSlipInfoRelateForm);
USEFORM("QRItemRelateFrm.cpp", QRItemRelateForm);
USEFORM("QRBankFrm.cpp", QRBankForm);
USEFORM("QRTaxFrm.cpp", QRTaxForm);
USEFORM("SortSetFrm.cpp", SortSetForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "マスタメンテナンス";
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TSearchForm), &SearchForm);
		Application->CreateForm(__classid(TYubinSearchForm), &YubinSearchForm);
		Application->CreateForm(__classid(TTokuisakiEditForm), &TokuisakiEditForm);
		Application->CreateForm(__classid(TItem2EditForm), &Item2EditForm);
		Application->CreateForm(__classid(THinBunruiEditForm), &HinBunruiEditForm);
		Application->CreateForm(__classid(TTankaEditForm), &TankaEditForm);
		Application->CreateForm(__classid(TTaniEditForm), &TaniEditForm);
		Application->CreateForm(__classid(THinmokuEditForm), &HinmokuEditForm);
		Application->CreateForm(__classid(TSharyoEditForm), &SharyoEditForm);
		Application->CreateForm(__classid(TItem1EditForm), &Item1EditForm);
		Application->CreateForm(__classid(TKyotenEditForm), &KyotenEditForm);
		Application->CreateForm(__classid(TKanzanEditForm), &KanzanEditForm);
		Application->CreateForm(__classid(TQRKyotenForm), &QRKyotenForm);
		Application->CreateForm(__classid(TQRTaniForm), &QRTaniForm);
		Application->CreateForm(__classid(TQRHinmokuForm), &QRHinmokuForm);
		Application->CreateForm(__classid(TQRItem1Form), &QRItem1Form);
		Application->CreateForm(__classid(TQRItem2Form), &QRItem2Form);
		Application->CreateForm(__classid(TQRHinBunruiForm), &QRHinBunruiForm);
		Application->CreateForm(__classid(TQRTokuisakiForm), &QRTokuisakiForm);
		Application->CreateForm(__classid(TQRKanzanForm), &QRKanzanForm);
		Application->CreateForm(__classid(TQRTankaForm), &QRTankaForm);
		Application->CreateForm(__classid(TQRSharyoForm), &QRSharyoForm);
		Application->CreateForm(__classid(TSlipInfoEditForm), &SlipInfoEditForm);
		Application->CreateForm(__classid(TSlipInfoRelateEditForm), &SlipInfoRelateEditForm);
		Application->CreateForm(__classid(TItemRelateEditForm), &ItemRelateEditForm);
		Application->CreateForm(__classid(TTaxEditForm), &TaxEditForm);
		Application->CreateForm(__classid(TBankEditForm), &BankEditForm);
		Application->CreateForm(__classid(TQRSlipInfoForm), &QRSlipInfoForm);
		Application->CreateForm(__classid(TQRSlipInfoRelateForm), &QRSlipInfoRelateForm);
		Application->CreateForm(__classid(TQRItemRelateForm), &QRItemRelateForm);
		Application->CreateForm(__classid(TQRBankForm), &QRBankForm);
		Application->CreateForm(__classid(TQRTaxForm), &QRTaxForm);
		Application->CreateForm(__classid(TSortSetForm), &SortSetForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
