//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainFrm.cpp", KeiryoStateBaseForm);
USEFORM("DMFrm.cpp", DM); /* TDataModule: File Type */
USEFORM("IdleStateFrm.cpp", IdleStateForm);
USEFORM("CardStateFrm.cpp", CardStateForm);
USEFORM("FirstWeightStateFrm.cpp", FirstWeightStateForm);
USEFORM("WaitExitStateFrm.cpp", WaitExitStateForm);
USEFORM("ConfirmWeighingStateFrm.cpp", ConfirmWeighingStateForm);
USEFORM("ErrorStateFrm.cpp", ErrorStateForm);
USEFORM("ContinuationStateFrm.cpp", ContinuationStateForm);
USEFORM("PrintStateFrm.cpp", PrintStateForm);
USEFORM("MeigSelectStateFrm.cpp", MeigSelectForm);
USEFORM("Item1SelectStateFrm.cpp", Item1SelectForm);
USEFORM("Item2SelectStateFrm.cpp", Item2SelectForm);
USEFORM("CarNoInputStateFrm.cpp", CarNoInputForm);
USEFORM("QRChitFrm.cpp", QRChitForm);
USEFORM("TokuSelectStateFrm.cpp", TokuSelectForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TKeiryoStateBaseForm), &KeiryoStateBaseForm);
		Application->CreateForm(__classid(TIdleStateForm), &IdleStateForm);
		Application->CreateForm(__classid(TCardStateForm), &CardStateForm);
		Application->CreateForm(__classid(TFirstWeightStateForm), &FirstWeightStateForm);
		Application->CreateForm(__classid(TWaitExitStateForm), &WaitExitStateForm);
		Application->CreateForm(__classid(TConfirmWeighingStateForm), &ConfirmWeighingStateForm);
		Application->CreateForm(__classid(TErrorStateForm), &ErrorStateForm);
		Application->CreateForm(__classid(TContinuationStateForm), &ContinuationStateForm);
		Application->CreateForm(__classid(TPrintStateForm), &PrintStateForm);
		Application->CreateForm(__classid(TMeigSelectForm), &MeigSelectForm);
		Application->CreateForm(__classid(TItem1SelectForm), &Item1SelectForm);
		Application->CreateForm(__classid(TItem2SelectForm), &Item2SelectForm);
		Application->CreateForm(__classid(TCarNoInputForm), &CarNoInputForm);
		Application->CreateForm(__classid(TQRChitForm), &QRChitForm);
		Application->CreateForm(__classid(TTokuSelectForm), &TokuSelectForm);
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
