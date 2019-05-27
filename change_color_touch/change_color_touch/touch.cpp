#include <windows.h>
#include <TCHAR.H>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x, y;
	static int flag = 0;

	switch (iMsg) {
	case WM_CREATE:
		x = 20; y = 20;
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Rectangle(hdc, 0, 0, 1400, 720);

		if (flag == 0)
		{
			SelectObject(hdc, GetStockObject(NULL_BRUSH));
		}
		else
		{
			SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));
		}
		Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);

		EndPaint(hwnd, &ps);



		return 0;
	case WM_KEYDOWN:

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
			{
				x -= 40;
			}

		}


		if (wParam == VK_UP)
		{
			if (y > 20)
			{
				y -= 40;
			}
		}

		if (wParam == VK_DOWN)
		{
			if (y < 660)
			{
				y += 40;
			}
		}

		if (wParam == VK_HOME) {
			{
				x = 20;
				y = 20;
			}
		}

		if (x > 1360)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}




		InvalidateRgn(hwnd, NULL, TRUE);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
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