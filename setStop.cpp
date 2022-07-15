#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    BOOL stopService = TRUE;
    SC_HANDLE hOpenSCManager =  NULL;
    SC_HANDLE hOpenService = NULL;
    SERVICE_STATUS_PROCESS statusProcess;

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

    stopService = ControlService(
        hOpenService,
        SERVICE_CONTROL_STOP,
        (LPSERVICE_STATUS) &statusProcess
    );
    

    if(FALSE == stopService)
    {
        cout << "STOP Service failed" << GetLastError() << endl;
        CloseServiceHandle(hOpenService);
        CloseServiceHandle(hOpenSCManager);
    }
    else
        {
            cout << "Serive is STOP" << endl;
        }

    CloseServiceHandle(hOpenService);
    CloseServiceHandle(hOpenSCManager);


}