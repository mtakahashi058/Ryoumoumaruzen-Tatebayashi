//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", MainForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("DetailFrm.cpp", DetailForm);
USEFORM("QRSeikyuItiranFrm.cpp", QRSeikyuItiranForm);
USEFORM("..\Lib\SearchFrm.cpp", SearchForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "請求データメンテナンス";
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TDetailForm), &DetailForm);
		Application->CreateForm(__classid(TQRSeikyuItiranForm), &QRSeikyuItiranForm);
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
