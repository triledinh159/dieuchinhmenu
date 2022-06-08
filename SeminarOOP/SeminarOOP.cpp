#include "Menu.h"


void charRun() {
	char a[1024] = "--- IT002.M21: SEMINAR OOP EXERCISE 2 ---", b[1024], c[40];
	strcpy_s(b, a);
	strcat_s(a, b);
	for (int i = 0; i < strlen(a); i++) {
		strncpy_s(c, a + i, 30);
		Sleep(200);
		gotoXY(50, 1); cout << c;
		if (i == strlen(b)) i = 0;
	}
}
void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

int main()
{
	DisableResizeWindow();
	//DisableSelection();
	SetConsoleTitle(L"IT002.M21: SEMINAR OOP EXERCISE 2");
	system("mode 650");
	//thread th1(charRun);
	//thread th2(command);
	//th1.join();
	//th2.join();
	command();
	system("pause");
	return 0;
}