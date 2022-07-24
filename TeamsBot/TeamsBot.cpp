// TeamsBot.cpp : Defines the entry point for the application.
//
#include "stdc++.h"
#include <windows.h>
#include "framework.h"
#include "TeamsBot.h"


#define MAX_LOADSTRING 100
#define IDT_TIMER1 1001

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

void LeftClick()
{
    INPUT    Input = { 0 };
    // left down 
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));

    // left up
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void MouseMove(int x, int y)
{
    double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1.0;
    double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1.0;
    double fx = x * (65535.0f / fScreenWidth);
    double fy = y * (65535.0f / fScreenHeight);
    INPUT  Input = { 0 };
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    Input.mi.dx = fx;
    Input.mi.dy = fy;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void JoinMeeting() {
    MouseMove(1081, 478);
    LeftClick();
    Sleep(1000);
    MouseMove(1401, 707);
    LeftClick();
}

void codeThatDoesStuff() {
    // time (hour/minute)
    time_t now = time(0);
    std::string date_time = ctime(&now);
    std::string weekday, month, date, currTime;
    bool aDayIsEven;
    weekday = date_time.substr(0, 3);
    month = date_time.substr(4, 3);
    date = date_time.substr(8, 2);
    currTime = date_time.substr(11, 5);
    // a day or b day
    std::map<std::string, int> monthNum;
    monthNum.insert(std::make_pair("Feb", 2));
    monthNum.insert(std::make_pair("Mar", 3));
    monthNum.insert(std::make_pair("Apr", 4));
    monthNum.insert(std::make_pair("May", 5));
    monthNum.insert(std::make_pair("Jun", 6));
    if ((monthNum[month] / 2) % 2 == 1) {
        // A is even, B is odd
        aDayIsEven = true;
    }
    else {
        // A is odd, B is even
        aDayIsEven = false;
    }
    // all the schoology teams links
    std::ifstream fin("C:\\Users\\Andy Jiang\\Documents\\10th Grade School year\\Teams_Links.txt");
    std::string links[9];
    for (int i = 0; i < 9; i++) {
        getline(fin, links[i]);
    }
    // if it is a weekday
    std::map<std::string, int> weekDayNum;
    weekDayNum.insert(std::make_pair("Mon", 1));
    weekDayNum.insert(std::make_pair("Tue", 2));
    weekDayNum.insert(std::make_pair("Wed", 3));
    weekDayNum.insert(std::make_pair("Thu", 4));
    weekDayNum.insert(std::make_pair("Fri", 5));
    weekDayNum.insert(std::make_pair("Sat", 6));
    weekDayNum.insert(std::make_pair("Sun", 7));
    
    int aDay = 4;
    if (weekDayNum[weekday] <= 5) {
        std::stringstream convert(date);
        int dateNum;
        convert >> dateNum;
        if (aDayIsEven == true) {
            if (dateNum % 2 == 0)
                aDay = 0;
        else 
            if (dateNum % 2 == 1)
                aDay = 0;
          
        }
        // look at the time
        if (currTime.compare("08:58") == 0) {
            // open the link
            ShellExecute(NULL, L"open", s2ws(links[1+aDay]).c_str(), NULL, NULL, SW_SHOWNORMAL);
            Sleep(2000);
            // joinmeetin();
            JoinMeeting();
        }
        else if (currTime.compare("10:13") == 0) {
            // open the link
            ShellExecute(NULL, L"open", s2ws(links[2 + aDay]).c_str(), NULL, NULL, SW_SHOWNORMAL);
            Sleep(2000);
            // joinmeetin();
            JoinMeeting();
        }
        else if (currTime.compare("11:28") == 0) {
            // open the link
            ShellExecute(NULL, L"open", s2ws(links[3 + aDay]).c_str(), NULL, NULL, SW_SHOWNORMAL);
            Sleep(2000);
            // joinmeetin();
            JoinMeeting();
        }
        else if (currTime.compare("13:28") == 0) {
            if (aDay == 4) {
                // open the link
                ShellExecute(NULL, L"open", s2ws(links[4 + aDay]).c_str(), NULL, NULL, SW_SHOWNORMAL);
                Sleep(2000);
                // joinmeetin();
                JoinMeeting();
            }
        }
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
    

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEAMSBOT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEAMSBOT));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEAMSBOT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TEAMSBOT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   // APPARENTLY THIS IS THE TIMER THAT WILL REPEAT ITSELF EVERY 5 SECONDS
   SetTimer(hWnd,                // handle to main window 
       IDT_TIMER1,					 // timer identifier 
       60000,                     // 5-second interval 
       NULL); // timer callback

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    // APPARENTLY HERE IS SOME COOL CODE THAT MAKES THE CODE REPEAT ITSELF IDK HOW IT WORKS
    case WM_TIMER:
        switch (wParam)
        {
        case IDT_TIMER1:
            codeThatDoesStuff();
            
            return 0;

        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
