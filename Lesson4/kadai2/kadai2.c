#include <windows.h>
#include <shellapi.h>
#include <objbase.h>
#include <stdio.h>
 
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "shell32.lib")
 
int main(int argc, char *argv[])
{
    char *url = NULL;
    HINSTANCE hInst = NULL;
    if (2 > argc) {
        fprintf(stderr, "usage: %s url\n", argv[0]);
        return 1;
    }
 
    url = argv[1];
 
    // recommended by ShellExecute() MSDN
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
 
    printf("hit return to continue;\n");
    getchar();
 
    hInst = ShellExecute(
            GetDesktopWindow(),
            "open",
            url,
            "", // LPCTSTR lpParameters
            "", // LPCSTR lpDirectory
            SW_SHOW);
 
    if (32 >= (int)hInst) {
        fprintf(stderr, "ShellExecute() failed, result = %d\n", hInst);
    } else {
        printf("ShellExecute() success, HINSTANCE = 0x%08X\n", hInst);
    }
 
    return 0;
}
