//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", MainForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("QRFrm.cpp", QRForm);
USEFORM("..\Lib\SearchFrm.cpp", SearchForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "業者別銘柄別日別月報";
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TQRForm), &QRForm);
		Application->CreateForm(__classid(TSearchForm), &SearchForm);
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
