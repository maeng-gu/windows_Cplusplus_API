#include "resource.h"

#include <windows.h>

#include <TCHAR.H>


HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,

	WPARAM wParam, LPARAM lParam);

HDC hdc;
PAINTSTRUCT ps;
static int x, y;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,

	LPSTR lpszCmdLine, int nCmdShow)

{

	HWND     hwnd;

	MSG     msg;

	WNDCLASS WndClass;

	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	WndClass.lpfnWndProc = WndProc;

	WndClass.cbClsExtra = 0;

	WndClass.cbWndExtra = 0;

	WndClass.hInstance = hInstance;

	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	WndClass.lpszMenuName = NULL;

	WndClass.lpszClassName = _T("Window Class Name");

	RegisterClass(&WndClass);

	hwnd = CreateWindow(_T("Window Class Name"),

		_T("Window Title Name"),

		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT,

		CW_USEDEFAULT,

		CW_USEDEFAULT,

		CW_USEDEFAULT,

		NULL,

		NULL,

		hInstance,

		NULL

	);

	ShowWindow(hwnd, nCmdShow);

	hInst = hInstance;
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))

	{

		TranslateMessage(&msg);

		DispatchMessage(&msg);

	}




	return (int)msg.wParam;

}

LRESULT CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_COMMAND: switch (LOWORD(wParam)) {
	case IDOK: // 버튼 
		EndDialog(hDlg, 0);
		break;
	case IDCANCEL: // 버튼 
		EndDialog(hDlg, 0);
		break;
	}
					 break;
	}
	return 0;
}
LRESULT CALLBACK Dlg6_2Proc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	HDC hdc; 
	switch (iMessage) 
	{
	case WM_COMMAND: 
		switch (LOWORD(wParam)) 
		{
			
			case ID_BUTTON_PRINT:
				hdc = GetDC(hDlg);
				TextOut(hdc, 0, 0, _T("Hello World"), 11);
				ReleaseDC(hDlg, hdc); break;
				if (wParam == VK_RIGHT)
				{
					if (x < 1360)
					{
						x += 40;
					}
				}

				if (wParam == VK_LEFT)
				{
					if (x > 20)
						x -= 40;
				}


				if (wParam == VK_UP)
				{
					if (y > 20)
						y -= 40;
				}

				if (wParam == VK_DOWN)
				{
					if (y < 660)
						y += 40;
				}

				if (wParam == VK_HOME) {
					x = 20;
					y = 20;
				}

				break;

			case ID_BUTTON_END:
				EndDialog(hDlg, 0);
				break;
			case IDCANCEL:
				EndDialog(hDlg, 0);
				break;
		}
	}		

	LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_CREATE:
		break;
		;
	case WM_LBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG6_2), hwnd,
			Dlg6_2Proc);
		break;
	}
	return
		DefWindowProc(hwnd, iMsg, wParam, lParam);
}
