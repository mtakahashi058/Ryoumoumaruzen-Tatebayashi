//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", MainForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("SearchFrm.cpp", SearchForm);
USEFORM("DataListFrm.cpp", DataListForm);
USEFORM("TrailerWeightFrm.cpp", TrailerWeightForm);
USEFORM("..\Lib\LaserSlipPrintFrm.cpp", LaserSlipPrintForm);
USEFORM("..\Lib\DotSlipPrintFrm.cpp", DotSlipPrintForm);
USEFORM("..\Lib\ShabanSanshoFrm.cpp", ShabanSanshoForm);
USEFORM("..\Lib\ManualDotSlipFrm.cpp", ManualDotSlipForm);
USEFORM("..\Lib\QRChitFrm.cpp", QRChitForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TDM), &DM);
         Application->CreateForm(__classid(TSearchForm), &SearchForm);
         Application->CreateForm(__classid(TDataListForm), &DataListForm);
         Application->CreateForm(__classid(TTrailerWeightForm), &TrailerWeightForm);
         Application->CreateForm(__classid(TLaserSlipPrintForm), &LaserSlipPrintForm);
         Application->CreateForm(__classid(TDotSlipPrintForm), &DotSlipPrintForm);
         Application->CreateForm(__classid(TShabanSanshoForm), &ShabanSanshoForm);
         Application->CreateForm(__classid(TManualDotSlipForm), &ManualDotSlipForm);
         Application->CreateForm(__classid(TQRChitForm), &QRChitForm);
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
