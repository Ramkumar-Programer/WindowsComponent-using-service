#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    BOOL startService = FALSE;
    SC_HANDLE hOpenSCManager =  NULL;
    SC_HANDLE hOpenService = NULL;

    hOpenSCManager = OpenSCManager(
        NULL, 
        NULL,
        SC_MANAGER_ALL_ACCESS
    );

    if(NULL == hOpenSCManager)
    {
        cout << "scmanager failed " << GetLastError() << endl;
    }

    else
    {
        cout << "success" << endl;
    }


    hOpenService = OpenService(
        hOpenSCManager,
        "GoogleChromeElevationService",
        SC_MANAGER_ALL_ACCESS
    );

    if(NULL == hOpenService)
    {
        cout << "scmanager failed2 " << GetLastError() << endl;
    }

    else
    {
        cout << "success SERVICE" << endl;
    }


    startService = StartService(
        hOpenService,
        NULL,
        NULL
    );

    if(FALSE == startService)
    {
        cout << "START Service failed" << GetLastError() << endl;
        CloseServiceHandle(hOpenService);
        CloseServiceHandle(hOpenSCManager);
    }
    else
        {
            cout << " Serive is Success" << endl;
        }

    CloseServiceHandle(hOpenService);
    CloseServiceHandle(hOpenSCManager);


}