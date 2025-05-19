//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("TrailerWeightFrm.cpp", TrailerWeightForm);
USEFORM("DataListFrm.cpp", DataListForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("MainFrm.cpp", MainForm);
USEFORM("QRLedgerFrm.cpp", QRLedgerForm);
USEFORM("SearchFrm.cpp", SearchForm);
USEFORM("..\Lib\DotSlipPrintFrm.cpp", DotSlipPrintForm);
USEFORM("..\Lib\LaserSlipPrintFrm.cpp", LaserSlipPrintForm);
USEFORM("..\Lib\LaserSlipPrintM_GenkinFrm.cpp", LaserSlipPrintM_GenkinForm);
USEFORM("..\Lib\LaserSlipPrintM_KakeFrm.cpp", LaserSlipPrintM_KakeForm);
USEFORM("..\Lib\PostConfFrm.cpp", PostConfForm);
USEFORM("..\Lib\ShabanSanshoFrm.cpp", ShabanSanshoForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "ScaleManager";
         Application->CreateForm(__classid(TDM), &DM);
         Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TDataListForm), &DataListForm);
         Application->CreateForm(__classid(TTrailerWeightForm), &TrailerWeightForm);
         Application->CreateForm(__classid(TQRLedgerForm), &QRLedgerForm);
         Application->CreateForm(__classid(TSearchForm), &SearchForm);
         Application->CreateForm(__classid(TDotSlipPrintForm), &DotSlipPrintForm);
         Application->CreateForm(__classid(TLaserSlipPrintForm), &LaserSlipPrintForm);
         Application->CreateForm(__classid(TLaserSlipPrintM_GenkinForm), &LaserSlipPrintM_GenkinForm);
         Application->CreateForm(__classid(TLaserSlipPrintM_KakeForm), &LaserSlipPrintM_KakeForm);
         Application->CreateForm(__classid(TPostConfForm), &PostConfForm);
         Application->CreateForm(__classid(TShabanSanshoForm), &ShabanSanshoForm);
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
