// AlwaysInstallElevated is a Windows Policy that allows to install Windows Packages with admin privs
// This code try to execute a payload on a machine that have this setting activated
// The process will be easy-->check if policy its activated on this two locations:
// HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows\Installer /v AlwaysInstallElevated /t REG_DWORD /d 1
// HKEY_USERS\(USER_SID)\Software\Policies\Microsoft\Windows\Installer /v AlwaysInstallElevated /t REG_DWORD /d 1
// If both are one the payload(.msi) is run and  the shell is accomplished.
/*

LSTATUS RegQueryInfoKeyA(
  [in]                HKEY      hKey,
  [out, optional]     LPSTR     lpClass,
  [in, out, optional] LPDWORD   lpcchClass,
                      LPDWORD   lpReserved,
  [out, optional]     LPDWORD   lpcSubKeys,
  [out, optional]     LPDWORD   lpcbMaxSubKeyLen,
  [out, optional]     LPDWORD   lpcbMaxClassLen,
  [out, optional]     LPDWORD   lpcValues,
  [out, optional]     LPDWORD   lpcbMaxValueNameLen,
  [out, optional]     LPDWORD   lpcbMaxValueLen,
  [out, optional]     LPDWORD   lpcbSecurityDescriptor,
  [out, optional]     PFILETIME lpftLastWriteTime
);

*/
#include <stdio.h>
#include <windows.h>
#include <msi.h>
#include <Winreg.h>

int main(){
  
  string payload;
  bool rquery1;
  bool rquery2;
  HKEY hKey1 = HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows\Installer;
  HKEY hKey2 = HKEY_USERS\(USER_SID)\Software\Policies\Microsoft\Windows\Installer;
  //query 1
  
  RegQueryInfoKeyA(HKEY_LOCAL_MACHINE)
    
  //query 2
    
  RegQueryInfoKeyA(HKEY_USERS)  
  
  return 0;
}
