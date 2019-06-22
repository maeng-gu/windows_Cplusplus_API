

#include <windows.h>

#include <TCHAR.H>

#include "resource.h"
HINSTANCE hinst;
BOOL CALLBACK Dlg6_6Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_LBUTTONDOWN:
		DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, Dlg6_6Proc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}



	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}
BOOL CALLBACK Dlg6_6Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hCombo;
	static int selection;
	TCHAR name[20];

	switch (iMsg)
	{
	case WM_INITDIALOG:
		hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);
		return 1;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_INSERT:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 20);
			if (_tcscmp(name, _T(""))) SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);
			return 0;
		case IDC_BUTTON_DELETE:
			// Å»ÅðÇÏ¶ó¹öÆ°ÀÌ¹°·ÁÁü 
			SendMessage(hCombo, CB_DELETESTRING, selection, 0);
			break;
		case IDC_COMBO_LIST: // ÄÞº¸¹Ú½º°¡´­·ÁÁü 
			if (HIWORD(wParam) == CBN_SELCHANGE)
				// ÇÏ³ª°¡¼±ÅÃµÊ(»óÅÂº¯°æ) 
				selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			break;
		}
	}
	return 0;
}






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

	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))

	{

		TranslateMessage(&msg);

		DispatchMessage(&msg);

	}




	return (int)msg.wParam;

}


