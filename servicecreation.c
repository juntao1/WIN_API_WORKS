//A service in windows its manage by the SCM
// Works on background and gives specific funcionality
// A normal user cant create a new service, but a user with rights can create a new service and 
// use it for persistence
// The function CreateServiceA() thats interacts with the windows api allows to create a new service 
/*

SC_HANDLE CreateServiceA(
  [in]            SC_HANDLE hSCManager,
  [in]            LPCSTR    lpServiceName,
  [in, optional]  LPCSTR    lpDisplayName,
  [in]            DWORD     dwDesiredAccess,
  [in]            DWORD     dwServiceType,
  [in]            DWORD     dwStartType,
  [in]            DWORD     dwErrorControl,
  [in, optional]  LPCSTR    lpBinaryPathName,
  [in, optional]  LPCSTR    lpLoadOrderGroup,
  [out, optional] LPDWORD   lpdwTagId,
  [in, optional]  LPCSTR    lpDependencies,
  [in, optional]  LPCSTR    lpServiceStartName,
  [in, optional]  LPCSTR    lpPassword
);

SC_HANDLE OpenSCManagerA(
  [in, optional] LPCSTR lpMachineName,
  [in, optional] LPCSTR lpDatabaseName,
  [in]           DWORD  dwDesiredAccess
);

*///

#include <stdio.h>
#include <windows.h>
#include <winsvc.h>

int main(){

  HANDLE newproces;
  HANDLE evilprocess;
  SC_HANDLE scminstance;

  scminstance = OpenSCManagerA(SC_MANAGER_ALL_ACCESS);
  newprocess = CreateServiceA(scminstance, evilprocess, SERVICE_ALL_ACCESS, SERVICE_FILE_SYSTEM_DRIVER, SERVICE_AUTO_START,SERVICE_ERROR_IGNORE);

  //Now its time to stablish th service binPath and put it there the path of our payload

  return 0;
}
