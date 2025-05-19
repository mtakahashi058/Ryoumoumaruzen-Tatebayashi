//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("ObserveFrm.cpp", ObserveForm);
USEFORM("QRChitFrm.cpp", QRChitForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
//---------------------------------------------------------------------------
LPCSTR lpszClassName = "TObserveForm";
LPCSTR lpszWinName   = "�t�H���_�Ď�";
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		// ���d�N���h�~����
		if(FindWindow(lpszClassName, lpszWinName)!=NULL){
			MessageBox(NULL, "���łɋN�����Ă���܂��B" ,"Multiplex starting prevention Test B", MB_OK);
			return 0;
		}

		Application->Initialize();
		Application->ShowMainForm = false;
		Application->Title = "�t�H���_�Ď�";
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TObserveForm), &ObserveForm);
		Application->CreateForm(__classid(TQRChitForm), &QRChitForm);
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
