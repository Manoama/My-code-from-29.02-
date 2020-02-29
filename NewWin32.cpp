#include <Windows.h>

HWND textfield;

int CALLBACK  wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCmdLine, int nCmdShow)
/*CALLBACK - #define ��� stdcall (���������� ��� �������, ���������� ������ ����� ��� �� ����� ������� ����
 wWinMain - �������������
 HINSTANCE  hInstance - ��������� �� ������ ������������ ������, �� ���������. ����� ������.
 HINSTANCE - �� ������������ ��� ���. ��� 16 ������ ������ �������.
 PWSTR szCmdLine - ��������� �� ������ UNICOD �������� �������������� ����. �� ���� ������ ���������.
 int nCmdShow - �������� ���������� �� �� ��� ����� ������������ ���� (�������, ���������, �� ���� ����� � �.�.).
*/
{
	MSG msg{};                             // ���������, ������� �������� � ���� ���������� � ����������� (����� Windows � ����� ��� ����� ������).
	HWND hwnd{};                          // ���������� ���� ( HANDLE ����. �� ������ ���� � ������� ��������� ���������� � ����� ����).
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) }; // ��� ��������� �������� �� ����� �-�� ���� (� �������� ������� �������).���. ���������� �������������.
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT
	{
		switch (uMsg)
		{
		case WM_CREATE:
			textfield = CreateWindow(
				L"Static", 
				L"Hi, you are looking on the Window", 
				WS_VISIBLE | WS_CHILD | WS_BORDER,
				150, 150, 300, 25, 
				hWnd, nullptr, nullptr, nullptr);
				/*void CreateWindowW(
					lpClassName,
					lpWindowName,
					dwStyle,
					x,
					y,
					nWidth,
					nHeight,
					hWndParent,
					hMenu,
					hInstance,
					lpParam
				);*/
				break;
		case WM_DESTROY:
		{
			PostQuitMessage(EXIT_SUCCESS);
		}
		return 0;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam); // ���������� � ������ ���� ��������� �� ��������������
	};
	wc.lpszClassName = L"MyAppClass";
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;
	/*
	wc.cbClsExtra = 0; �������� �� �������������� ��������� ������ �
	wc.cbWndExtra = 0; ������ ������ ���� (��� ������ ����� ���� ���������� � ����).

	hbrBackground - ��� ���� ��������� ���������� ����� ������� ���������� ����.
	GetStockObject - ���������� GDI ������ ������� �� ����� �������� � ���� HBRUSH.

	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);     - HANDLE �������.
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);   - HANDLE ������.
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION); - HANDLE ������ (������������ ������ ����� � ��������� ����).

	wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT
	- ��� ��������� �������� �� ��������� ��������� (MSG msg{};)
	  ��������� 4 ������������ ��������� � ���������� LRESULT (���������).
	  HWND hWnd     - ���������� ���� � �������� �������� ���������.
	  UINT uMsg     - ��� ���������.
	  WPARAM wParam - ��������� � �� ��������� ����������� ��� ��������� ����������.
	  LPARAM lParam - ��������� � �� ��������� ����������� ��� ��������� ����������.

	  wc.lpszClassName = L"MyAppClass";   - ��� ������ (�����).
	  wc.lpszMenuName = nullptr;          - ��������� �� ��� ����.
	  wc.style = CS_VREDRAW | CS_HREDRAW; - ����� ���� (2 ����� �� ���������)



	*/

	if (!RegisterClassEx(&wc))
		return EXIT_FAILURE;

	if (hwnd = CreateWindow(wc.lpszClassName, L"���������!", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr, wc.hInstance, nullptr); hwnd == INVALID_HANDLE_VALUE)
		return EXIT_FAILURE;
	/*
	 if (!RegisterClassEx(&wc)) - ����������� � ������� ������ ������ ����.
	  return EXIT_FAILURE;

	 if (hwnd = CreateWindow(wc.lpszClassName, L"���������!", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr, wc.hInstance, nullptr ); hwnd == INVALID_HANDLE_VALUE)
	  return EXIT_FAILURE;
	  - �������� ������ ����.
	  wc.lpszClassName    - ��� ������.
	  L"���������!"       - ��������� ����.
	  WS_OVERLAPPEDWINDOW - ����� ���� (����� ���������� � msdn).
	  0, 0,               - X � Y ���������� ���� (������������� �� ����� ������� �����).
	  600, 600,           - ������, ������.


	 */
	ShowWindow(hwnd, nCmdShow); // ����� ����
	UpdateWindow(hwnd);         // ����������� ���� (��������� HANDLE)

	while (GetMessage(&msg, nullptr, 0, 0)) // ���� ��������� ���������
	{
		TranslateMessage(&msg); // ������� �������������� ��������� ���������
		DispatchMessage(&msg);  // �������  ������� ��������� � ������� ��������� �� ���������
	}

	return static_cast<int> (msg.wParam); // ������������ �������� ����� �����



	// hWnd - ������������� ����.
	// nullptr - ������� ���������.
}