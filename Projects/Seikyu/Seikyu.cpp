//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("MainFrm.cpp", MainForm);
USEFORM("..\Lib\SearchFrm.cpp", SearchForm);
USEFORM("SeikyushoYokoFrm.cpp", SeikyushoYokoForm);
USEFORM("SettingsFrm.cpp", SettingsForm);
USEFORM("ConfirmFrm.cpp", ConfirmForm);
USEFORM("SeikyushoTateFrm.cpp", SeikyushoTateForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "¿‹‘”­s";
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TSearchForm), &SearchForm);
		Application->CreateForm(__classid(TSeikyushoYokoForm), &SeikyushoYokoForm);
		Application->CreateForm(__classid(TSettingsForm), &SettingsForm);
		Application->CreateForm(__classid(TConfirmForm), &ConfirmForm);
		Application->CreateForm(__classid(TSeikyushoTateForm), &SeikyushoTateForm);
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
