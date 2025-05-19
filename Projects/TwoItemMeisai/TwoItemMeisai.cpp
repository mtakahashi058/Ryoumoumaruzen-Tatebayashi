//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("MainFrm.cpp", MainForm);
USEFORM("..\Lib\SearchFrm.cpp", SearchForm);
USEFORM("QRFrm.cpp", QRForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "‚Q€–Ú•Ê–¾×•\";
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TSearchForm), &SearchForm);
		Application->CreateForm(__classid(TQRForm), &QRForm);
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
