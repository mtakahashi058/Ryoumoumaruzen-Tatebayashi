#include <stdio.h>

//Function address 
typedef int ( *lpNPrint)(PCHAR,PCHAR,DWORD,PDWORD);
typedef int ( *lpNImagePrint)(PCHAR,HDC, int,int,BYTE,PDWORD);
typedef int ( *lpNBitImagePrint)(PCHAR,HDC, int,int,PDWORD);
typedef int ( *lpNGetStatus)(PCHAR,LPDWORD);
typedef int ( *lpNStartDoc)(PCHAR,PDWORD);
typedef int ( *lpNEndDoc)(PCHAR);
typedef int ( *lpNCancelDoc)(PCHAR);
typedef int ( *lpNGetInformation)(PCHAR,BYTE,PVOID,PDWORD);

typedef int ( *lpNDPrint)(PCHAR,PBYTE,DWORD,PDWORD);
typedef int ( *lpNBarcode)(PCHAR,PCHAR,HDC,int,int,int,int,PBYTE,DWORD);

typedef int ( *lpNImagePrintF)(PCHAR,PCHAR,BYTE,PDWORD);
typedef int ( *lpNBitImagePrintF)(PCHAR,PCHAR,PDWORD);
typedef int ( *lpNResetPrinter)(PCHAR);

class CPrinterAPI 
{
protected:
	// Handle to a DLL
    HINSTANCE hLibHandle;

private:
    lpNPrint m_NPrint;
    lpNImagePrint m_NImagePrint;
    lpNBitImagePrint m_NBitImagePrint;
    lpNGetStatus m_NGetStatus;
    lpNStartDoc m_NStartDoc;
    lpNEndDoc m_NEndDoc;
    lpNCancelDoc m_NCancelDoc;
    lpNGetInformation m_NGetInformation;
    lpNDPrint m_NDPrint;
    lpNBarcode m_NBarcode;
    lpNImagePrintF m_NImagePrintF;
    lpNBitImagePrintF m_NBitImagePrintF;
    lpNResetPrinter m_NResetPrinter;

public:
	// Constructor
	CPrinterAPI(void)
	{
		hLibHandle = NULL;
		m_NPrint          = NULL;
		m_NImagePrint	  = NULL;
		m_NBitImagePrint  = NULL;
		m_NGetStatus      = NULL;
		m_NStartDoc       = NULL;
		m_NEndDoc         = NULL;
		m_NCancelDoc      = NULL;
		m_NGetInformation = NULL;
		m_NDPrint         = NULL;
		m_NBarcode        = NULL;
		m_NImagePrintF    = NULL;
		m_NBitImagePrintF = NULL;
		m_NResetPrinter   = NULL;
	};
	//Destructor
	virtual ~CPrinterAPI()
	{
		if ( hLibHandle != NULL ) 
		{
			::FreeLibrary(hLibHandle);
		}
	};

	// Public API Functions. Must call Initialize() before anything else
	BOOL Initialize()
	{
		hLibHandle = ::LoadLibrary("NPrinterLib.DLL");
		if ( hLibHandle != NULL ) 
		{
			m_NPrint = (lpNPrint)GetProcAddress(hLibHandle,"NPrintA");
			m_NImagePrint = (lpNImagePrint)GetProcAddress(hLibHandle,"NImagePrintA");
			m_NBitImagePrint = (lpNBitImagePrint)GetProcAddress(hLibHandle,"NBitImagePrintA");
			m_NGetStatus = (lpNGetStatus)GetProcAddress(hLibHandle,"NGetStatusA");
			m_NStartDoc = (lpNStartDoc)GetProcAddress(hLibHandle,"NStartDocA");
			m_NEndDoc = (lpNEndDoc)GetProcAddress(hLibHandle,"NEndDocA");
			m_NCancelDoc = (lpNCancelDoc)GetProcAddress(hLibHandle,"NCancelDocA");
			m_NGetInformation = (lpNGetInformation)GetProcAddress(hLibHandle,"NGetInformationA");
			m_NDPrint = (lpNDPrint)GetProcAddress(hLibHandle,"NDPrintA");
			m_NBarcode = (lpNBarcode)GetProcAddress(hLibHandle,"NBarcodeA");
			m_NImagePrintF = (lpNImagePrintF)GetProcAddress(hLibHandle,"NImagePrintFA");
			m_NBitImagePrintF = (lpNBitImagePrintF)GetProcAddress(hLibHandle,"NBitImagePrintFA");
			m_NResetPrinter = (lpNResetPrinter)GetProcAddress(hLibHandle,"NResetPrinterA");

			if (m_NPrint != NULL &&
				m_NBitImagePrint != NULL &&
				m_NGetStatus != NULL &&
				m_NStartDoc != NULL &&
				m_NEndDoc != NULL &&
				m_NCancelDoc != NULL &&
				m_NGetInformation != NULL &&
				m_NDPrint != NULL &&
				m_NBarcode != NULL &&
				m_NImagePrintF != NULL &&
				m_NBitImagePrintF != NULL &&
				m_NResetPrinter != NULL)
				return TRUE;
			else	 
				return FALSE;
		}
		else 
			return FALSE;
	};
	int NPrint(PCHAR i_prt, PCHAR i_dat, DWORD i_size, PDWORD o_jobid)
	{
		if (m_NPrint!=NULL ) 
			return m_NPrint(i_prt, i_dat, i_size, o_jobid);
		return -9999;
	};
	int NImagePrint(PCHAR i_prt, HDC i_bmp, int i_x, int i_y, BYTE i_file, PDWORD o_jobid)
	{
		if (m_NImagePrint!=NULL ) 
			return m_NImagePrint(i_prt, i_bmp, i_x, i_y, i_file, o_jobid);
		return -9999;
	};
	int NBitImagePrint(PCHAR i_prt, HDC i_bmp, int i_x, int i_y, PDWORD o_jobid)
	{
		if (m_NBitImagePrint!=NULL ) 
			return m_NBitImagePrint( i_prt,  i_bmp,  i_x,  i_y,  o_jobid);
		return -9999;
	};
	int NGetStatus(PCHAR i_prt, LPDWORD o_status)
	{
		if (m_NGetStatus!=NULL ) 
			return m_NGetStatus( i_prt,  o_status);
		return -9999;
	};
	int NStartDoc(PCHAR i_prt, PDWORD o_jobid)
	{
		if (m_NStartDoc!=NULL ) 
			return m_NStartDoc( i_prt,  o_jobid);
		return -9999;
	};
	int NEndDoc(PCHAR i_prt)
	{
		if (m_NEndDoc!=NULL ) 
			return m_NEndDoc( i_prt);
		return -9999;
	};
	int NCancelDoc(PCHAR i_prt)
	{
		if (m_NCancelDoc!=NULL ) 
			return m_NCancelDoc( i_prt);
		return -9999;
	};
	int NGetInformation(PCHAR i_prt, BYTE i_id, PVOID o_dat, PDWORD o_time)
	{
		if (m_NGetInformation!=NULL ) 
			return m_NGetInformation( i_prt,  i_id,  o_dat,  o_time);
		return -9999;
	};
	int NDPrint(PCHAR i_prt, PBYTE i_dat, DWORD i_size, PDWORD o_jobid)
	{
		if (m_NDPrint!=NULL ) 
			return m_NDPrint( i_prt,  i_dat,  i_size,  o_jobid);
		return -9999;
	};
	int NBarcode(PCHAR i_prt,PCHAR i_fname, HDC i_bmp, int i_x, int i_y, int i_width, int i_height,PBYTE i_dat,DWORD i_size)
	{
		if (m_NBarcode!=NULL ) 
			return m_NBarcode( i_prt, i_fname,  i_bmp,  i_x,  i_y, i_width, i_height, i_dat, i_size);
		return -9999;
	};
	int NImagePrintF(PCHAR i_prt, PCHAR i_bmp, BYTE i_file, PDWORD o_jobid)
	{
		if (m_NImagePrint!=NULL ) 
			return m_NImagePrintF(i_prt, i_bmp, i_file, o_jobid);
		return -9999;
	};
	int NBitImagePrintF(PCHAR i_prt, PCHAR i_bmp, PDWORD o_jobid)
	{
		if (m_NBitImagePrint!=NULL ) 
			return m_NBitImagePrintF( i_prt,  i_bmp,  o_jobid);
		return -9999;
	};
	int NResetPrinter(PCHAR i_prt)
	{
		if (m_NResetPrinter!=NULL ) 
			return m_NResetPrinter( i_prt);
		return -9999;
	};

};