// Mutex.h: Mutex Classes
//	by Aki.O

#ifndef _MutexH_
#define _MutexH_

class WaitMutex{
public:
	WaitMutex(LPCSTR pszMutexName){
		hMutex = CreateMutex(NULL, FALSE, pszMutexName);
		WaitForSingleObject(hMutex, INFINITE);
	}
	~WaitMutex(){
		ReleaseMutex(hMutex);
		CloseHandle(hMutex);
	}
private:
	HANDLE hMutex;
};

class ExclMutex{
public:
	ExclMutex(LPCSTR cpszMutexName) : bFailed(false), hMutex(NULL){
		HANDLE hPrevMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, cpszMutexName);
		if (hPrevMutex){
			CloseHandle(hPrevMutex);
			bFailed = true;
		}
		else
			hMutex = CreateMutex(NULL, FALSE, cpszMutexName);
	}
	~ExclMutex(){
		if (hMutex){
			ReleaseMutex(hMutex);
			CloseHandle(hMutex);
		}
	}
	bool Failed() {return bFailed;}
private:
	HANDLE hMutex;
	bool bFailed;
};

class TimeoutMutex{
public:
	TimeoutMutex(LPCSTR pszMutexName, DWORD dwTimeout){
		hMutex = CreateMutex(NULL, FALSE, pszMutexName);
		dwResult = WaitForSingleObject(hMutex, dwTimeout);
	}
	~TimeoutMutex(){
		ReleaseMutex(hMutex);
		CloseHandle(hMutex);
	}
	DWORD dwResult;
	bool Timeout() {return dwResult == WAIT_TIMEOUT;}
private:
	HANDLE hMutex;
};

#endif	//_MutexH_
