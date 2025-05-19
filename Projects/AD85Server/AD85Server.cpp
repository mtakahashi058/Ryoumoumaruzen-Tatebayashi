//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", AD4385PostForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("NotifyFrm.cpp", NotifyForm);
USEFORM("ErrorFrm.cpp", ErrorForm);
USEFORM("..\Lib\DotSlipPrintFrm.cpp", DotSlipPrintForm);
USEFORM("..\Lib\LaserSlipPrintFrm.cpp", LaserSlipPrintForm);
USEFORM("DisplayFrm.cpp", DisplayForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    HWND main_wnd = ::FindWindow("TAD4385PostForm", "AD4385 ����|�X�g����");
    if (main_wnd)
        return 0;

    try
    {
         Application->Initialize();
         Application->ShowMainForm = false;
         Application->Title = "AD4385 ����|�X�g����";
         Application->CreateForm(__classid(TDM), &DM);
         Application->CreateForm(__classid(TAD4385PostForm), &AD4385PostForm);
         Application->CreateForm(__classid(TNotifyForm), &NotifyForm);
         Application->CreateForm(__classid(TErrorForm), &ErrorForm);
         Application->CreateForm(__classid(TDotSlipPrintForm), &DotSlipPrintForm);
         Application->CreateForm(__classid(TLaserSlipPrintForm), &LaserSlipPrintForm);
         Application->CreateForm(__classid(TDisplayForm), &DisplayForm);
         ShowWindow(Application->Handle, SW_HIDE);
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
