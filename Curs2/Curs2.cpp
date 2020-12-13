// Curs2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Curs2.h"

#include <combaseapi.h>
#include <string>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HWND buttonRedUp;
HWND buttonRedDown;
HWND buttonGreenUp;
HWND buttonGreenDown;
HWND buttonBlueUp;
HWND buttonBlueDown;
HWND label;

int red = 240;
int green = 200;
int blue = 60;
int stepSize = 10;

int getNewValue(int prevValue, int step)
{
	if ((prevValue + step) < 0 || (prevValue + step) > 255)
	{
        return prevValue;
	}

    return prevValue + step;
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
    LoadStringW(hInstance, IDC_CURS2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CURS2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CURS2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CURS2);
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
      CW_USEDEFAULT, 0, 450, 300, nullptr, nullptr, hInstance, nullptr);
	
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

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
    case WM_CREATE:
        buttonRedUp = CreateWindow(_T("Button"), _T("красный +"), WS_VISIBLE | WS_CHILD, 10, 10, 160, 20, hWnd, (HMENU) 1001,  NULL, NULL);
        buttonRedDown = CreateWindow(_T("Button"), _T("красный -"), WS_VISIBLE | WS_CHILD, 10, 30, 160, 20, hWnd, (HMENU)1002, NULL, NULL);
        buttonGreenUp = CreateWindow(_T("Button"), _T("зеленый +"), WS_VISIBLE | WS_CHILD, 10, 55, 160, 20, hWnd, (HMENU)1003, NULL, NULL);
        buttonGreenDown = CreateWindow(_T("Button"), _T("зеленый -"), WS_VISIBLE | WS_CHILD, 10, 75, 160, 20, hWnd, (HMENU)1004, NULL, NULL);
        buttonBlueUp = CreateWindow(_T("Button"), _T("синий +"), WS_VISIBLE | WS_CHILD, 10, 100, 160, 20, hWnd, (HMENU)1005, NULL, NULL);
        buttonBlueDown = CreateWindow(_T("Button"), _T("синий -"), WS_VISIBLE | WS_CHILD, 10, 120, 160, 20, hWnd, (HMENU)1006, NULL, NULL);

        label = CreateWindow(_T("STATIC"), _T(""), WS_VISIBLE | WS_CHILD, 200, 10, 200, 200, hWnd, NULL, NULL, NULL);

    	
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int lmId = LOWORD(lParam);
            // Parse the menu selections:

            switch (wmId)
            {
            case 1001:
                red = getNewValue(red, stepSize);
                break;
            case 1002:
                red = getNewValue(red, -stepSize);
                break;
            case 1003:
                green = getNewValue(green, stepSize);
                break;
            case 1004:
                green = getNewValue(green, -stepSize);
                break;
            case 1005:
                blue = getNewValue(blue, stepSize);
                break;
            case 1006:
                blue = getNewValue(blue, -stepSize);
                break;
            }

            RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_INTERNALPAINT);
    		
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
        RECT rc;
        HDC hdc = BeginPaint(label, &ps);
        GetClientRect(label, &rc);
        SetDCBrushColor(hdc, RGB(red, green, blue));
        FillRect(hdc, &rc, (HBRUSH)GetStockObject(DC_BRUSH));

        //SetWindowTextW(label, s2ws(std::to_string(red)+ std::to_string(green)+ std::to_string(blue)).c_str());

    		
        //or use ps.rcPaint to repaint only the section which requires update
        //FillRect(hdc, &ps.rcPaint, (HBRUSH)GetStockObject(DC_BRUSH));

            EndPaint(label, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
