#include <windows.h>
#include <TCHAR.H>
#include "resource.h"
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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU4_1);
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
	return msg.wParam;
}

void OutFreomFile(TCHAR filename[], HWND hwnd)
{
	FILE *fPtr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hwnd);
#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r, ccs = UNICODE"));
#else
	_tfopen_s(&fPtr, filename, _T("r"));
#endif
	while (_fgetts(buffer, 100, fPtr) != NULL)
	{
		if (buffer[_tcslen(buffer) - 1] == _T('Wn'))
			buffer[_tcslen(buffer) - 1] = NULL;
		TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
		line++;
	}
	//fclose(fPtr);
	ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	int answer;

	OPENFILENAME OFN;
	OPENFILENAME SFN;
	int i;
	CHOOSECOLOR COLOR;
	static COLORREF tmp[16], color;
	HBRUSH hBrush, OldBrush;

	HDC hdc;
	PAINTSTRUCT ps;
	CHOOSEFONT FONT;
	static COLORREF fColor;
	HFONT hFont, OldFont;
	static LOGFONT LogFont;

	static HMENU hMenu, hSubMenu;
	HBRUSH hBrush, OldBrush;

	TCHAR str[100], lpstrFile[100] = _T("");
	TCHAR filter[] = _T("Every File(*.*) \0*.*Text File\0*.txt;*.doc\0");
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		hFont = CreateFontIndirect(&LogFont);
		OldFont = (HFONT)SelectObject(hdc, hBrush);
		Ellipse(hdc, 10, 10, 200, 200);
		SelectObject(hdc, OldBrush);
		DeleteObject(hBrush);
		EndPaint(hwnd, &ps);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_COLORDLG:
			for (i = 0; i < 16; i++)
			{
				tmp[i] = RGB(rand() % 256, rand() % 256, rand() % 256);
				memset(&COLOR, 0, sizeof(CHOOSECOLOR));
				COLOR.lStructSize = sizeof(CHOOSECOLOR);
				COLOR.hwndOwner = hwnd;
				COLOR.lpCustColors = tmp;
				COLOR.Flags = CC_FULLOPEN;
				if (ChooseColor(&COLOR) != 0)
				{
					color = COLOR.rgbResult;
					InvalidateRgn(hwnd, NULL, TRUE);
				}
				break;
			}
			break;
		case ID_FILEOPEN:
			memset(&OFN, 0, sizeof(OPENFILENAME));
			OFN.lStructSize = sizeof(OPENFILENAME);
			OFN.hwndOwner = hwnd;
			OFN.lpstrFilter = filter;
			OFN.lpstrFile = lpstrFile;
			OFN.nMaxFile = 100;
			OFN.lpstrInitialDir = _T(".");
			if (GetOpenFileName(&OFN) != 0)
			{
				_stprintf_s(str, _T("%s 파일을 열겠습니까?"), OFN.lpstrFile);
				MessageBox(hwnd, str, _T("열기 선택"), MB_OK);
				OutFreomFile(OFN.lpstrFile, hwnd);
			}
			break;
		case ID_FILESAVE:
			memset(&SFN, 0, sizeof(OPENFILENAME));
			SFN.lStructSize = sizeof(OPENFILENAME);
			SFN.hwndOwner = hwnd;
			SFN.lpstrFilter = filter;
			SFN.lpstrFile = lpstrFile;
			SFN.nMaxFile = 256;
			SFN.lpstrInitialDir = _T(".");
			if (GetOpenFileName(&OFN) != 0)
			{
				_stprintf_s(str, _T("%s 파일로 저장하겠습니까?"), SFN.lpstrFile);
				MessageBox(hwnd, str, _T("저장하기 선택"), MB_OK);
			}
			break;
		case ID_FONTDLG:
			memset(&FONT, 0, sizeof(CHOOSEFONT));
			FONT.lStructSize = sizeof(CHOOSEFONT);
			FONT.hwndOwner = hwnd;
			FONT.lpLogFont = &LogFont;
			FONT.Flags = CF_EFFECTS | CF_SCREENFONTS;
			if (ChooseFont(&FONT) != 0)
			{
				fColor = FONT.rgbColors;
				InvalidateRgn(hwnd, NULL, TRUE);
			}
			break;
		case ID_FILENEW:
			MessageBox(hwnd,
				_T("새 파일을 열겠습니까?"),
				_T("새 파일 선택"),
				MB_OKCANCEL);
			break;
		case ID_EXIT:
			answer = MessageBox(hwnd,
				_T("파일을 저장하고 끝내겠습니까?"),
				_T("끝내기 선택"),
				MB_YESNOCANCEL);
			if (answer == IDYES || answer == IDNO)
				PostQuitMessage(0);
		case ID_EDITUNDO:
			answer = MessageBox(hwnd,
				_T("파일을 취소 끝내겠습니까?"),
				_T("끝내기 선택"),
				MB_YESNOCANCEL);
			if (answer == IDYES || answer == IDNO)
				PostQuitMessage(0);
		case ID_EDITCOPY:
			answer = MessageBox(hwnd,
				_T("파일을 복사하시겠습니까?"),
				_T("복사하기 선택"),
				MB_YESNOCANCEL);
			if (answer == IDYES || answer == IDNO)
				PostQuitMessage(0);
		case ID_EDITPASTE:
			answer = MessageBox(hwnd,
				_T("붙쳐넣을랭?"),
				_T("골랑"),
				MB_YESNOCANCEL);
			if (answer == IDYES || answer == IDNO)
				PostQuitMessage(0);

			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}