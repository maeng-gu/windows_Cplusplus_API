#include "resource.h"

#include <windows.h>

#include <TCHAR.H>


HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,

	WPARAM wParam, LPARAM lParam);

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

BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_COMMAND: switch (LOWORD(wParam)) {
	case IDOK: // ��ư 
		EndDialog(hDlg, 0);
		break;
	case IDCANCEL: // ��ư 
		EndDialog(hDlg, 0);
		break;
	}
					 break;
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg) {
	case WM_CREATE:
		break;
		;
	case WM_LBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd,
			Dlg6_1Proc);
		break;
	}
	return
		DefWindowProc(hwnd, iMsg, wParam, lParam);
}
