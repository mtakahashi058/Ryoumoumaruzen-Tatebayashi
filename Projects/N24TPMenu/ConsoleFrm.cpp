//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <IniFiles.hpp>
#include <memory>

#include "ConsoleFrm.h"
#include <fstream>
#include "NsIni.h"
#include "NsDB.h"
#include "n24tp.h"
#include "DMFrm.h"
#include "DataExportFrm.h"
#include "MasterImportFrm.h"
#include "DataView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConsoleForm *ConsoleForm;
//---------------------------------------------------------------------------
/** �v�ʃv���O�����N���܂ł̗���

  **�w���v���g�p����ꍇ
	1. �d�ʒl�X���b�h����d�ʂ�������̂�҂�
	   -> OnWIMWeight

	2. DB �ڑ��p�^�C�}�[���J�n����
	   -> OnWIMWeight ���� ConnectionTimer �� Enable ��

	3. DB �ڑ����m�F����
	   -> ConnectionTimerTimer

	4. �v�ʋN���^�C�}�[���J�n����
	   -> ConnectionTimerTimer ���� WeighingBootTimer �� Enable ��

	5. �v�ʃv���O�������N������
	   -> WeighingBootTimerTimer

  **�w���v���g�p���Ȃ��ꍇ
	1. DB �ڑ��p�^�C�}�[���J�n����
	   -> FormCreate ���� ConnectionTimer �� Enable ��

	2. DB �ڑ����m�F����
	   -> ConnectionTimerTimer

	3. �v�ʋN���^�C�}�[���J�n����
	   -> ConnectionTimerTimer ���� WeighingBootTimer �� Enable ��

	4. �v�ʃv���O�������N������
	   -> WeighingBootTimerTimer
*/
//---------------------------------------------------------------------------
__fastcall TConsoleForm::TConsoleForm(TComponent* Owner)
	: TForm(Owner), start_connect_(false), wi_thread_(0), sense_nii_status_(false), use_windicator_(false)
{
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormCreate(TObject *Sender)
{
	DeleteFile("c:\\firstweight.txt");
	DeleteFile("c:\\status.txt");

	//ClientPanel->Left = 44;
	ClientPanel->Align = alClient;
	ErrorMemo->Lines->Clear();

    DM->INI.Load(ExtractFilePath(Application->ExeName) + N24TP::INI_NAME);

	//////////////////////////////////////////////////////////////////////
	// ADO
	udl_file_  = ToString(DM->INI["ADO::UDL"]);

	//////////////////////////////////////////////////////////////////////
	// WI

	WICommInfo info;
	AnsiString wi_type;

	info.port       = ToInt(DM->INI["WeightComm::Port"]);
	info.def        = ToString(DM->INI["WeightComm::Def"]);
	info.owner      = Handle;
	wi_type         = ToString(DM->INI["WeightComm::Type"]);
	use_windicator_ = ToInt(DM->INI["WeightComm::Use"]) == 1 ? true : false;

	//////////////////////////////////////////////////////////////////////
	// WI Server
	WIServerSocket->Port = ToInt(DM->INI["WeightServer::Port"]);

	//////////////////////////////////////////////////////////////////////
	// Nii Printer Status

	AnsiString printer_name;
	bool nii_failed = false;

	NiiServerSocket->Port = ToInt(DM->INI["NiiServer::Port"]);
	printer_name          = ToString(DM->INI["NiiServer::PrinterName"]);
	sense_nii_status_     = ToInt(DM->INI["NiiServer::Use"]) == 1 ? true : false;

	if (sense_nii_status_){
		// Nii �X�e�[�^�X�Ď�
		try{
			NiiState.Initialize(printer_name);
		}catch(Exception& e){
			StatusBar->SimpleText = e.Message;
			nii_failed = true;
		}
	}

	//////////////////////////////////////////////////////////////////////
	// �d�ʒʐM�̊J�n
	if (use_windicator_){
		try{
			WIServerSocket->Open();
		}catch(Exception& e){
			::MessageBox(0, AnsiString("�d�ʒl�T�[�o�̋N���Ɏ��s���܂��� - " + e.Message).c_str(),
				"�d�ʒl��M", MB_OK | MB_ICONSTOP | MB_TOPMOST);
			PostMessage(Handle, WM_CLOSE, 0, 0);
			return;
		}

		if (wi_type == "ZF720"){
			SetZeroButton->Enabled = true;
			CancelZeroButton->Enabled = true;
		}else{
			SetZeroButton->Enabled = false;
			CancelZeroButton->Enabled = false;
		}

    	if (wi_type == "S9500"){
    		wi_thread_ = new TN95Thread(false, info);
    	}else if (wi_type == "C9500"){
    		wi_thread_ = new TC95Thread(false, info);
    	}else if (wi_type == "S4401"){
    		wi_thread_ = new T4401Thread(false, info);
    	}else if (wi_type == "C4401"){
    		wi_thread_ = new TC4401Thread(false, info);
    	}else if (wi_type == "F720"){
    		wi_thread_ = new TF720Thread(false, info);
    	}else if (wi_type == "ZF720"){
    		wi_thread_ = new TZF720Thread(false, info);
    	}else if (wi_type == "F701"){
    		wi_thread_ = new TCF701Thread(false, info);
    	}else if (wi_type == "RoadMeter"){
    		wi_thread_ = new TRoadMeterThread(false, info);
    	}else if (wi_type == "MU790"){
    		wi_thread_ = new TSMU790Thread(false, info);
    	}else if (wi_type == "Y700A"){
    		wi_thread_ = new TY700AThread(false, info);
    	}else if (wi_type == "EDP1700"){
    		wi_thread_ = new TSEDP1700Thread(false, info);
    	}else if (wi_type == "ADHV"){
    		wi_thread_ = new TCADHVThread(false, info);
    	}else if (wi_type == "SKLD2000"){
    		wi_thread_ = new TSKLD2000Thread(false, info);
    	}else if (wi_type == "CKLD2000"){
    		wi_thread_ = new TCKLD2000Thread(false, info);
    	}else if (wi_type == "CDI275"){
    		wi_thread_ = new TCDI275Thread(false, info);
    	}else if (wi_type == "SDI750"){
    		wi_thread_ = new TSDI750Thread(false, info);
    	}else if (wi_type == "SDIPC275"){
    		wi_thread_ = new TSDIPC275Thread(false, info);
        }else if (wi_type == "SXK3190D2"){
    		wi_thread_ = new TSXK3190D2Thread(false, info);
        }else if (wi_type == "CCSD904AD"){
	    	wi_thread_ = new TCCSD904ADThread(false, info);
        }else if (wi_type == "CCSD904AD"){
	    	wi_thread_ = new TCCSD904ADThread(false, info);
        }else if (wi_type == "SKW201012"){
	    	wi_thread_ = new TSKW201012Thread(false, info);
    	}else if (wi_type == "F252"){
	    	wi_thread_ = new TF252Thread(false, info);
        }else if (wi_type == "CCSD904"){
    		wi_thread_ = new TCCSD904Thread(false, info);
        }

		if (!wi_thread_){
			::MessageBox(0, "�����Ȏw���v���ݒ肳��Ă��܂� - ", "�d�ʒl��M", MB_OK | MB_ICONSTOP | MB_TOPMOST);
			PostMessage(Handle, WM_CLOSE, 0, 0);
			return;
		}
		wi_thread_->FreeOnTerminate = true;
	}else{
		SetZeroButton->Enabled    = false;
		CancelZeroButton->Enabled = false;

		// �w���v�Ƃ̒ʐM���s��Ȃ��ꍇ�A�����Ƀf�[�^�x�[�X�ɐڑ�����

		start_connect_ = true;
		TitlePanel->Caption = "�@�@�@N-24TP �f�[�^�x�[�X�ڑ����m�F��";

		if (sense_nii_status_){
			int result   = 0;
			DWORD status = 0;
			NiiState.GetStatusText(&result, &status);
			if (status == 1){
				ErrorMemo->Lines->Append("");
				ErrorMemo->Lines->Append("�`�[�p�������Ȃ��Ȃ��Ă��܂�");
			}
		}

		ConnectionTimer->Interval = 2000;
		ConnectionTimer->Enabled  = true;
	}

	//////////////////////////////////////////////////////////////////////
	// Nii �X�e�[�^�X�T�[�o�̊J�n
	if (!nii_failed && sense_nii_status_){
		try{
			NiiServerSocket->Open();
			NiiStatusTimer->Enabled = true;
		}catch(Exception& e){
			::MessageBox(0, AnsiString("�v�����^�X�e�[�^�X�T�[�o�̋N���Ɏ��s���܂��� - " + e.Message).c_str(),
				"�v�����^�X�e�[�^�X�ʒm", MB_OK | MB_ICONSTOP | MB_TOPMOST);
			return;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormShow(TObject *Sender)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	Left = rect.left;
	Top = rect.top;
	Width = rect.right - rect.left;
	Height = rect.bottom - rect.top;

	ShutdownButton->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	if (wi_thread_)
		wi_thread_->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::OnWIMAborted(TMessage& message)
{
	wi_thread_ = 0;

	ErrorMemo->Lines->Append("");
	ErrorMemo->Lines->Append("�w���v�Ƃ̒ʐM���~���܂���");
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::OnWIMStatus(TMessage& message)
{
	//
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::OnWIMWeight(TMessage& message)
{
	WIWeight wiweight(*reinterpret_cast<WIWeight *>(message.LParam));

	if (wiweight.status == WIWeight::wiStable)
		socket_buff_ = "S";
	else if (wiweight.status == WIWeight::wiUnstable)
		socket_buff_ = "U";
	else
		socket_buff_ = "O";

	socket_buff_ += FormatFloat("#####0.00", wiweight.weight);

	try{
		for (int i = 0; i < WIServerSocket->Socket->ActiveConnections; i++){
			WIServerSocket->Socket->Connections[i]->SendText(socket_buff_ + "\r\n");
		}
	}catch(...){}

	if (!start_connect_){
		start_connect_ = true;
		TitlePanel->Caption = "�@�@�@N-24TP �f�[�^�x�[�X�ڑ����m�F��";

		if (sense_nii_status_){
			int result   = 0;
			DWORD status = 0;
			NiiState.GetStatusText(&result, &status);
			if (status == 1){
				ErrorMemo->Lines->Append("");
				ErrorMemo->Lines->Append("�`�[�p�������Ȃ��Ȃ��Ă��܂�");
			}
		}

		ConnectionTimer->Interval = 2000;
		ConnectionTimer->Enabled  = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::OnControlZero(TMessage& message)
{
	if (!SetZeroButton->Enabled || !CancelZeroButton->Enabled)
		return;

	bool set_mode = message.WParam;
	if (set_mode)
		SetZeroButton->Click();
	else
		CancelZeroButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::ConnectionTimerTimer(TObject *Sender)
{
	ConnectionTimer->Enabled = false;

	bool connected = false;
	try{
		if (DM->ADOConnection->Connected)
			DM->ADOConnection->Close();
		DM->ADOConnection->ConnectionString = "FILE NAME=" + udl_file_;
		DM->ADOConnection->Open();
    	DM->CFG.Load(&(DM->DBI));
		connected = true;
	}catch(Exception& e){
	}

	if (!connected){
		ConnectionTimer->Enabled = true;
		return;
	}

	TitlePanel->Caption = "�@�@�@N-24TP �N����";

    if (!N24TP::SetPlace(ToInt(DM->INI["N-24TP::PlaceCode"]))){
        Application->MessageBox("���_�R�[�h���L���ł͂���܂���", "N-24TP ����������", MB_OK | MB_ICONSTOP);
        PostMessage(Handle, WM_CLOSE, 0, 0);
        return;
    }

	WeighingBootTimer->Interval = 1000;
	WeighingBootTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::WeighingBootTimerTimer(TObject *Sender)
{
	WeighingBootTimer->Enabled = false;

	WeighButton->Click();

	ClientPanel->Visible = false;
	TitlePanel->Caption = "�@�@�@N-24TP �Ǘ����j���[";
	Caption = "N-24TP �Ǘ����j���[";
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::NiiStatusTimerTimer(TObject *Sender)
{
	NiiStatusTimer->Enabled = false;

	int result;
	DWORD status;
	AnsiString status_text = NiiState.GetStatusText(&result, &status);

	std::auto_ptr<TStringList> SendData(new TStringList());
	SendData->Append(IntToStr(result));
	SendData->Append(IntToStr(status));
	SendData->Append(status_text);

	for (int i = 0; i < NiiServerSocket->Socket->ActiveConnections; i++){
		try{
			NiiServerSocket->Socket->Connections[i]->SendText(SendData->CommaText + "\r\n");
		}catch(...){}
	}

	NiiStatusTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::SignalDetectTimerTimer(TObject *Sender)
{
	if (WaitForSingleObject(process_handle_, 0) != WAIT_TIMEOUT){
		process_handle_ = 0;
		SignalDetectTimer->Enabled = false;
		Visible = true;
		ShowTotalResult();
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::ServerSocketClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
	ErrorCode = 0;
}
//---------------------------------------------------------------------------
bool __fastcall TConsoleForm::CreateProcess(AnsiString path, bool wait)
{
	if (process_handle_ && wait){
		// �I���҂����s����̂́A��x��1�v���Z�X�̂�
		//throw Exception("���ɋN�����Ă���v���O�������I�������Ă�����s���Ă�������");
		return false;
	}

	STARTUPINFO stStartupInfo;
	PROCESS_INFORMATION stProcessInfo;

	ZeroMemory(&stStartupInfo, sizeof(STARTUPINFO));
	ZeroMemory(&stProcessInfo, sizeof(PROCESS_INFORMATION));
	stStartupInfo.cb = sizeof(STARTUPINFO);
	stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	stStartupInfo.wShowWindow = SW_SHOWNORMAL;
	if (!::CreateProcess(0, path.c_str(), 0, 0, false,
			CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS,
			0, 0, &stStartupInfo, &stProcessInfo))
		return false;
	if (wait){
		process_handle_ = stProcessInfo.hProcess;
		SignalDetectTimer->Enabled = true;
	}
	return true;
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::WeighButtonClick(TObject *Sender)
{
	if (!start_connect_)
		return;

	bool boot;

	static_cast<TButton *>(Sender)->Enabled = false;

	if (!(boot = CreateProcess("N24TPWeighing.exe", true))){
		Application->MessageBox("�Ǘ����j���[���ڂ̋N���Ɏ��s���܂���", Caption.c_str(), MB_OK | MB_ICONWARNING);
	}
	static_cast<TButton *>(Sender)->Enabled = true;

	if (boot)
		Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::IssueCardButtonClick(TObject *Sender)
{
	static_cast<TButton *>(Sender)->Enabled = false;
	bool succeeded = CreateProcess("N24TPRFIDIssue.exe", true);
	static_cast<TButton *>(Sender)->Enabled = true;

	if (succeeded)
		Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::LookupCardButtonClick(TObject *Sender)
{
	static_cast<TButton *>(Sender)->Enabled = false;
	bool succeeded = CreateProcess("N24TPRFIDLookup.exe", true);
	static_cast<TButton *>(Sender)->Enabled = true;

	if (succeeded)
		Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::WeighTareButtonClick(TObject *Sender)
{
	static_cast<TButton *>(Sender)->Enabled = false;
	bool succeeded = CreateProcess("N24TPTareWeighing.exe", true);
	static_cast<TButton *>(Sender)->Enabled = true;

	if (succeeded)
		Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::SetZeroButtonClick(TObject *Sender)
{
	if (wi_thread_)
		PostThreadMessage(wi_thread_->ThreadID, WIM_ZEROSET, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::CancelZeroButtonClick(TObject *Sender)
{
	if (wi_thread_)
		PostThreadMessage(wi_thread_->ThreadID, WIM_CANCELZERO, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::ExportButtonClick(TObject *Sender)
{
	DataExportForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::ImportButtonClick(TObject *Sender)
{
	MasterImportForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::ShutdownButtonClick(TObject *Sender)
{
	if (Application->MessageBox("�Ɩ����I�����AN-24TP���V���b�g�_�E�����܂��B��낵���ł����H",
			Caption.c_str(), MB_YESNO | MB_ICONWARNING) != IDYES)
		return;


	OSVERSIONINFO ver_info;

	ZeroMemory(&ver_info, sizeof(OSVERSIONINFO));
	ver_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&ver_info);
	if(ver_info.dwPlatformId == VER_PLATFORM_WIN32_NT) { // NT
		HANDLE			 hToken;
		LUID			 luid;
		TOKEN_PRIVILEGES tokenPrivileges;

		//�A�N�Z�X�g�[�N�����I�[�v������
		if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) {
			if (LookupPrivilegeValue(0, SE_SHUTDOWN_NAME, &luid)) {
				//SE_SHUTDOWN_NAME ������L���ɂ���
				tokenPrivileges.PrivilegeCount = 1;
				tokenPrivileges.Privileges[0].Luid = luid;
				tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
				AdjustTokenPrivileges(hToken, FALSE, &tokenPrivileges, NULL, NULL, NULL);
				if (GetLastError() == ERROR_SUCCESS)
					ExitWindowsEx(EWX_SHUTDOWN, 0);
			}
			CloseHandle(hToken);
		}
	}
	else { //Windows
		ExitWindowsEx(EWX_SHUTDOWN, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::ShowTotalResult()
{
	NsRecordSet set;
	AnsiString sql;
	int count = 0;
	int quantity = 0;
	sql = " SELECT COUNT(*) AS ���� FROM D_�v��"
		  " WHERE �v�ʓ� = " + Now().FormatString("yyyymmdd") +
          "   AND ���_ID = " + IntToStr(N24TP::place_id) +
          "   AND �sNo = 1";
          "   AND �����敪 = 1";
	if (DM->DBI.GetRecordSet(sql, set)){
		count    = ToInt(SET_TOP(set)["����"]);
	}
	sql = " SELECT SUM(�����d��) AS ���v�d�� FROM V_�v��"
		  " WHERE �v�ʓ� = " + Now().FormatString("yyyymmdd") +
          "   AND ���_ID = " + IntToStr(N24TP::place_id) +
          "   AND �����敪 = 1";
	if (DM->DBI.GetRecordSet(sql, set)){
		quantity = ToInt(SET_TOP(set)["���v�d��"]);
	}
	CountLabel->Caption  = FormatFloat("##,##0",    count);
	WeightLabel->Caption = FormatFloat("#,###,##0", quantity);

	Currency avg = 0;
	if (count > 0)
		avg = quantity / count;
	AvgLabel->Caption = FormatFloat("#,###,##0.0", avg);

}
//---------------------------------------------------------------------------
void __fastcall TConsoleForm::ResultDetailButtonClick(TObject *Sender)
{
	DataViewForm->ShowModal();
	ShowTotalResult();
}
//---------------------------------------------------------------------------


