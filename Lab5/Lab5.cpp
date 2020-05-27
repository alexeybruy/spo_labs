#include <string>
#include <windows.h>
#include <tchar.h>
#include <vector>
#include <math.h>

using namespace std;

HINSTANCE hInst;

POINT mousePosition;
int windowHeight = 500, windowWidth = 500;
bool windowSticked = false;

bool wasLeft = false, wasRight = false, wasTop = false;

int skipCounter = 0;

HWND label;

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

POINT previousPoint;
string text;

void clearFlags()
{
	wasLeft = false;
	wasRight = false;
	wasTop = false;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		label = CreateWindow(_T("STATIC"), _T("Label"), WS_VISIBLE | WS_CHILD, 10, 10, 160, 20, hWnd, NULL, NULL, NULL);
	case WM_MOUSEMOVE:
		GetCursorPos(&mousePosition);

		text = "";
			
		text += wasLeft ? "Y" : "N";
		text += wasRight ? "Y" : "N";
		text += wasTop ? "Y" : "N";

		SetWindowTextW(label, s2ws(text).c_str());
		
		if (skipCounter == 25)
		{
			skipCounter = 0;

			if (windowSticked)
			{

				// left, right, up
				if (mousePosition.x < previousPoint.x && abs(mousePosition.y - previousPoint.y) <= abs(mousePosition.x - previousPoint.x))
				{
					clearFlags();
					wasLeft = true;
				}
				else if (mousePosition.x > previousPoint.x && abs(mousePosition.y - previousPoint.y) <= abs(mousePosition.x - previousPoint.x))
				{
					if (wasLeft)
						wasRight = true;
					else
						clearFlags();
				}
				else if (mousePosition.y < previousPoint.y && abs(mousePosition.x - previousPoint.x) <= abs(mousePosition.y - previousPoint.y))
				{
					if (wasRight)
						wasTop = true;
					else
						clearFlags();
				}
				else
				{
					clearFlags();
				}

				if (wasLeft && wasRight && wasTop)
				{
					windowSticked = false;
				}
			}

			previousPoint = mousePosition;
		}
		else
		{
			skipCounter++;		
		}

		if (windowSticked)
		{
			RECT windowRect;
			GetWindowRect(hWnd, &windowRect);
			MoveWindow(hWnd, mousePosition.x - (windowRect.right - windowRect.left) / 2, mousePosition.y - (windowRect.bottom - windowRect.top) / 2, windowWidth, windowHeight, true);
		}
		
		
		break;
	case WM_PAINT:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDBLCLK:
		break;
	case WM_LBUTTONDOWN:
		windowSticked = true;
		break;
	case WM_LBUTTONUP:
		//mouseDown = false;
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("DesktopApp");
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	RegisterClassEx(&wcex);

	hInst = hInstance;

	HWND hWnd = CreateWindow(_T("DesktopApp"), _T("MouseDrag - LR6"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, windowWidth, windowHeight, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

