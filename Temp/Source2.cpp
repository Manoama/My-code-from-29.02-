#include <Windows.h>
#include "resource.h"

HWND textfield;
HWND hListBox;

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int CALLBACK  wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCmdLine, int nCmdShow)

{
	DialogBox(hInstance, MAKEINTRESOURCE(IDOK), 0, DlgProc);

return 0; 
}


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		hListBox = GetDlgItem(hwnd, IDC_LIST1);
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"WINAPI 1");
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"WINAPI 2");
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"WINAPI 3");
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"WINAPI 4");
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"WINAPI 5");
		break;
	case WM_COMMAND:
	{
		case IDOK:
		{
			MessageBox(hwnd, L"W", L"dw", MB_OKCANCEL | MB_ICONEXCLAMATION);
		}
		break;
	}	
	break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return FALSE;


	}
	return FALSE;
}
