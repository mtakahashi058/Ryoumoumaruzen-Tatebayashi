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
USEFORM("..\Lib\PostConfFrm.cpp", PostConfForm);
USEFORM("..\Lib\LaserSlipPrintM_GenkinFrm.cpp", LaserSlipPrintM_GenkinForm);
USEFORM("..\Lib\LaserSlipPrintM_KakeFrm.cpp", LaserSlipPrintM_KakeForm);
USEFORM("AnbunFrm.cpp", AnbunForm);
USEFORM("DivideFrm.cpp", DivideForm);
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
         Application->CreateForm(__classid(TPostConfForm), &PostConfForm);
         Application->CreateForm(__classid(TLaserSlipPrintM_GenkinForm), &LaserSlipPrintM_GenkinForm);
         Application->CreateForm(__classid(TLaserSlipPrintM_KakeForm), &LaserSlipPrintM_KakeForm);
         Application->CreateForm(__classid(TAnbunForm), &AnbunForm);
         Application->CreateForm(__classid(TDivideForm), &DivideForm);
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
