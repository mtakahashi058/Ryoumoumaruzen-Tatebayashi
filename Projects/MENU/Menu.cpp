//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("Main.cpp", MainForm);
USEFORM("SettingFrm.cpp", SettingForm);
USEFORM("KosinListFrm.cpp", KosinListForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Scale Manager ƒƒjƒ…[";
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TSettingForm), &SettingForm);
		Application->CreateForm(__classid(TKosinListForm), &KosinListForm);
		Application->CreateForm(__classid(TDM), &DM);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
