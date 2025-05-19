//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("ConsoleFrm.cpp", ConsoleForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("DataExportFrm.cpp", DataExportForm);
USEFORM("MasterImportFrm.cpp", MasterImportForm);
USEFORM("DataView.cpp", DataViewForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "N-24TP ŠÇ—ƒRƒ“ƒ\[ƒ‹";
		Application->CreateForm(__classid(TDM), &DM);
         Application->CreateForm(__classid(TConsoleForm), &ConsoleForm);
         Application->CreateForm(__classid(TDataExportForm), &DataExportForm);
         Application->CreateForm(__classid(TMasterImportForm), &MasterImportForm);
         Application->CreateForm(__classid(TDataViewForm), &DataViewForm);
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
