#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

BOOL CALLBACK WindowProc(HWND hwnd, LPARAM lParam)
{  RECT rect;
    if (GetWindowRect(hwnd, &rect))
    {
        wchar_t windowTitle[256];
        GetWindowTextW(hwnd, windowTitle, 256);
        wcout << L"name: " << windowTitle << L", Window handle: " << hwnd << L", Rect: " << rect.left << L", " << rect.top << L", " << rect.right << L", " << rect.bottom << endl;
    }
    return TRUE;
}
int main()
{
   EnumWindows(WindowProc, 0);

    return  0;
}
