#include <windows.h>
#include <TCHAR.H>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) {

	return DefWindowProc(hwnd, iMsg, wParam, lParam);
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


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)

{

	switch (iMsg)

	{

	case WM_CREATE:

		break;

	case WM_COMMAND:

		switch (LOWORD(wParam))

		{

		case ID_DIALOG_6:

			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, Dlg_Proc);

			break;

		}

		break;

	case WM_DESTROY:

		PostQuitMessage(0);

		break;

	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}



BOOL CALLBACK Dlg_Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)

{

	static char str[50] = "0";



	switch (iMsg)

	{

	case WM_INITDIALOG:

		SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

		return 1;

	case WM_COMMAND:

		switch (LOWORD(wParam))

		{

		case IDC_BUTTON_0:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

				}

				else

					a = 0;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

				}

				else

					b = 0;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_1:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 1;

				}

				else

					a = 1;



				//sprintf_s(str, "%d", a);

				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 1;

				}

				else

					b = 1;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_2:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 2;

				}

				else

					a = 2;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 2;

				}

				else

					b = 2;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_3:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 3;

				}

				else

					a = 3;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 3;

				}

				else

					b = 3;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_4:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 4;

				}

				else

					a = 4;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 4;

				}

				else

					b = 4;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_5:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 5;

				}

				else

					a = 5;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 5;

				}

				else

					b = 5;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_6:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 6;

				}

				else

					a = 6;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 6;

				}

				else

					b = 6;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_7:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 7;

				}

				else

					a = 7;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 7;

				}

				else

					b = 7;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_8:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 8;

				}

				else

					a = 8;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 8;

				}

				else

					b = 8;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_9:

			if (count == NULL)

			{

				if (a != NULL)

				{

					a *= 10;

					a += 9;

				}

				else

					a = 9;



				_itoa_s(a, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			else

			{

				if (b != NULL)

				{

					b *= 10;

					b += 9;

				}

				else

					b = 9;



				_itoa_s(b, str, 10);

				SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);

			}

			break;

		case IDC_BUTTON_DODGE:

			break;

		case IDC_BUTTON_ADD:

			ch = '+';

			count = 1;

			break;

		case IDC_BUTTON_SUB:

			ch = '-';

			count = 1;

			break;

		case IDC_BUTTON_MUL:

			ch = 'X';

			count = 1;

			break;

		case IDC_BUTTON_DIV:

			ch = '/';

			count = 1;

			break;

		case IDC_BUTTON_RESULT:

			if (ch == '+')

				result = a + b;

			else if (ch == '-')

				result = a - b;

			else if (ch == 'X')

				result = a * b;

			else if (ch == '/')

			{

				if (b = NULL)

					b = 1;



				result = a / b;

			}

			else

				break;



			sprintf_s(str, "%d", result);

			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, str);



			count = 0;

			a = 0;

			b = 0;



			break;

		case IDC_BUTTON_CLOSE:

			count = 0;

			a = 0;

			b = 0;

			result = 0;



			EndDialog(hDlg, 0);

			break;

		case IDCANCEL:

			EndDialog(hDlg, 0);

			break;

		}

		break;

	}

	return 0;

}