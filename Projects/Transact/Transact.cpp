//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", MainForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("..\Lib\SearchFrm.cpp", SearchForm);
USEFORM("..\Lib\ShabanSanshoFrm.cpp", ShabanSanshoForm);
USEFORM("DataListFrm.cpp", DataListForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TDM), &DM);
         Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TSearchForm), &SearchForm);
         Application->CreateForm(__classid(TShabanSanshoForm), &ShabanSanshoForm);
         Application->CreateForm(__classid(TDataListForm), &DataListForm);
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
