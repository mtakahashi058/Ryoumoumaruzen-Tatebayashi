//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("CardIssueFrm.cpp", CardIssueForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("RFIDWriteFrm.cpp", SCRFIDIssueForm);
USEFORM("ShabanSanshoFrm.cpp", ShabanSanshoForm);
USEFORM("..\Lib\SearchFrm.cpp", SearchForm);
USEFORM("N24TPCardsFrm.cpp", N24TPCardsForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TCardIssueForm), &CardIssueForm);
         Application->CreateForm(__classid(TDM), &DM);
         Application->CreateForm(__classid(TSCRFIDIssueForm), &SCRFIDIssueForm);
         Application->CreateForm(__classid(TShabanSanshoForm), &ShabanSanshoForm);
         Application->CreateForm(__classid(TSearchForm), &SearchForm);
         Application->CreateForm(__classid(TN24TPCardsForm), &N24TPCardsForm);
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
