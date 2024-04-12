#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
std::wstring GetMonitorName(HWND hwnd)
{
    HMONITOR hMonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    if (hMonitor == NULL)
    {
        return L""; // Failed to get monitor handle
    }

    MONITORINFOEXW mi;
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoW(hMonitor, &mi))
    {
        return L""; // Failed to get monitor info
    }

    return mi.szDevice; // Return the monitor name
}


BOOL CALLBACK WindowProc(HWND hwnd, LPARAM lParam) // hwnd is the memory location of the window
{
    RECT rect;
    MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    if (GetWindowRect(hwnd, &rect))
    {
        wchar_t windowTitle[256];
        GetWindowTextW(hwnd, windowTitle, 256);

        // Check if the window is not in the system tray
        if (wcslen(windowTitle) > 0 && IsWindowVisible(hwnd))
        {
            
             wcout << "Monitor name" << GetMonitorName(hwnd) << L"name: "  << windowTitle << L", Window handle: " << hwnd << L", Rect: " << rect.left << L", " << rect.top << L", " << rect.right << L", " << rect.bottom << endl ;

       
        }
    }
    return TRUE;
}






int main()
{
    EnumWindows(WindowProc, 0); // enumarate throgh the windows

    return 0;
}
