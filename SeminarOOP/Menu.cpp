#include "Menu.h"
void highLight(int x, int y, int w, int h, int b_color,string text) {
	TextColor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++) {
		for (int ix = x + 1; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	setColor(7);
	gotoXY(x + 1, y + 1);
	cout << text;
}
void box(int x, int y, int w, int h, int t_color, int b_color, string text) {
	TextColor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++) {
		for (int ix = x + 1; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	setColor(7);
	gotoXY(x + 1, y + 1);
	cout << text;
	TextColor(15);
	setColor(t_color);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y+h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x+w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);
}

void check(char& ch)
{
	TextColor(15);
	cout << "Press ""SPACEBAR"" to start\n";
	cout << "To cancel, please press ""ESC""\n";

	// chờ người dùng nhấn phím
	bool flag = true;
	while (flag)
	{
		if (_kbhit())
		{
			ch = _getch();
			Sleep(500);
			if (ch == 32)
			{
				clrscr();
				PlaySound(TEXT("Building.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "Starting...\n";
				flag = !flag;
				Sleep(1500);
				return;
			}
			if (ch == 27)
			{
				clrscr();
				PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
				cout << "Canceling...";
				Sleep(1500);
				return;
			}
		}
	}
	cin.ignore();
}
// nhập các dữ liệu cần thiết để bắt đầu sắp xếp
void input(Sort* sort, int n)
{
	int x = 0, s = 0, dem = 0;
	char ch;
	// chọn cách nhập
	PlaySound(TEXT("selecttarget.wav"), NULL, SND_FILENAME | SND_ASYNC); 
	do
	{
		clrscr();
		TextColor(15);
		cout << "\nChoose insert way:"; cout << "\n------------------\n";
		if (dem == 0) TextColor(12);
		else TextColor(15);
		cout << "   =========================\n   =                       =\n   =  1. Insert directly   =\n   =                       =\n   =========================\n";
		if (dem == 1) TextColor(12);
		else TextColor(15);
		cout << "   ==============================\n   =                            =\n   =  2. Create randomly array  =\n   =                            =\n   ==============================\n";
		if (dem == 2) TextColor(12);
		else TextColor(15);
		cout << "   =====================\n   =                   =\n   =  3. Insert file   =\n   =                   =\n   =====================\n";
		ch = _getch();
		if (ch == 80) // xử lý thao tác nhấn nút down
		{
			dem++;
			if (dem > 2) dem = 0;
		} 
		else if (ch == 72) // xử lý thao tác nhấn nút up
		{
			dem--;
			if (dem < 0) dem = 2;
		}
	} while (ch != 13);

	// xử lý yêu cầu nhập
	if (dem == 0) cin >> sort;
	else if (dem == 1) sort->Random();
	else sort->inputFile();
	cout << sort << endl;
	sort->complexity();
	TextColor(12);
	cout << "\nPress any key to continue...";
	ch = _getch();

	// chọn cách sắp xếp
	PlaySound(TEXT("selecttarget.wav"), NULL, SND_FILENAME | SND_ASYNC);
	do
	{
		clrscr();
		TextColor(15);
		cout << "Sort by:\n";	cout << "--------\n";
		
		if (x == 0) TextColor(12);
		else TextColor(15);
		cout << "   ======================\n   =                    =\n   =     Increment      =\n   =                    =\n   ======================\n";
		if (x == 1) TextColor(12);
		else TextColor(15);
		cout << "   ======================\n   =                    =\n   =     Decrement      =\n   =                    =\n   ======================\n";
		ch = _getch();
		if (ch == 80) // xử lý thao tác nhấn nút down
		{
			x++;
			if (x > 1) x = 0;
		}
		else if (ch == 72) // xử lý thao tác nhấn nút up
		{
			x--;
			if (x < 0) x = 1;
		}
	} while (ch != 13);

	
	// chọn tốc độ biểu diễn
	PlaySound(TEXT("selecttarget.wav"), NULL, SND_FILENAME | SND_ASYNC);
	do
	{
		clrscr();
		TextColor(15);
		cout << "Choose the speed:\n"; cout << "-----------------\n";
		if (s == 0) TextColor(12);
		else TextColor(15);
		cout << "   =================\n   =               =\n   =     Slow      =\n   =               =\n   =================\n";
		if (s == 1) TextColor(12);
		else TextColor(15);
		cout << "   =================\n   =               =\n   =    Normal     =\n   =               =\n   =================\n";
		if (s == 2) TextColor(12);
		else TextColor(15);
		cout << "   =================\n   =               =\n   =     Fast      =\n   =               =\n   =================\n";
		ch = _getch();
		if (ch == 80) // xử lý thao tác nhấn nút down
		{
			s++;
			if (s > 2) s = 0;
		}
		else if (ch == 72) // xử lý thao tác nhấn nút up
		{
			s--;
			if (s < 0) s = 2;
		}
	} while (ch != 13);

	// xử lý tốc độ biểu diễn
	if (s == 0) sort->setSpeed(500);
	else if (s == 1) sort->setSpeed(250);
	else sort->setSpeed(100);
	TextColor(15);
	clrscr();
	cout << sort << endl;
	check(ch);
	if (ch == 27) return;

	// xử lý yêu cầu sắp xếp
	if (x == 0) sort->increase();
	else sort->decrease();
	if (n != 7 & dem != 2) clrscr();
	else if (dem == 2) cout << sort;
	TextColor(15);
	if (dem == 2) sort->outputFile();
	PlaySound(TEXT("constructioncompleted.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cout << sort;
	cout << "\nSorting completed. Press any key to continue...\n";
	Sleep(100);
	ch = _getch();
}

// xử lý các lựa chọn của người dùng
void selection(int x)
{
	Sort* sort;
	TextColor(15);
	switch (x)
	{
	case 0: 
		sort = new SelectionSort;
		input(sort,x);
		delete sort;
		break; 
	case 1: 
		sort = new InterchangeSort;
		input(sort,x);
		delete sort;
		break; 
	case 2: 
		sort = new InsertionSort;
		input(sort,x);
		delete sort;
		break; 
	case 3: 
		sort = new BinaryInsertionSort;
		input(sort,x);
		delete sort;
		break; 
	case 4:
		sort = new BubbleSort;
		input(sort,x);
		delete sort;
		break;
	case 5:
		sort = new ShakerSort;
		input(sort,x);
		delete sort;
		break;
	case 6:
		clrscr();
		break;
	case 7:
		// xử lý khi người dùng thoát
		Sleep(400);
		infor();
		TextColor(12);
		gotoXY(65, 15);
		cout << "Exiting...\n";
		Sleep(1000);
		clrscr();
		gotoXY(65, 15);
		PlaySound(TEXT("quit.wav"), NULL, SND_FILENAME | SND_ASYNC);
		cout << "Cya";
		gotoXY(65, 15);
		Sleep(3000);
		break;
	case 8:
		sort = new ShellSort;
		input(sort,x);
		delete sort;
		break;
	case 9:
		sort = new CountingSort;
		input(sort,x);
		delete sort;
		break;
	case 10:
		sort = new RadixSort;
		input(sort,x);
		delete sort;
		break;
	case 11:
		sort = new HeapSort;
		input(sort,x);
		delete sort;
		break;
	case 12:
		sort = new QuickSort;
		input(sort,x);
		delete sort;
		break;
	case 13:
		sort = new MergeSort;
		input(sort,x);
		delete sort;
		break;
	case 14:
		clrscr();
		break;
	case 15:
		// xử lý khi người dùng thoát
		Sleep(400);
		infor();
		TextColor(12);
		gotoXY(65, 15);
		cout << "Exiting...\n";
		Sleep(1000);
		clrscr();
		gotoXY(65, 15);
		PlaySound(TEXT("quit.wav"), NULL, SND_FILENAME | SND_ASYNC);
		cout << "Cya";
		gotoXY(65, 15);
		Sleep(3000);
		break;

	}

}

// in ra thông tin của các bạn trong nhóm
void infor()
{
	PlaySound(TEXT("outro.wav"), NULL, SND_FILENAME | SND_ASYNC);
	ShowCur(0);
			clrscr();
			TextColor(7);
			gotoXY(65, 12);
			cout << "== Mentor ==\n";
			TextColor(15);
			gotoXY(62, 13);
			cout << "------------------\n";
			TextColor(3);
			gotoXY(64, 15);
			Sleep(1000);
			cout << " Bùi Văn Thành\n";
			TextColor(7);
			gotoXY(64, 17);
			Sleep(1000);
			cout << "== Created by ==\n";
			TextColor(15);
			gotoXY(61, 18);
			cout << "---------------------\n";
			TextColor(2);
			gotoXY(61, 20);
			Sleep(1000);
			cout << "Lê Đình Trí - 21521561\n";
			Sleep(1000);
			gotoXY(59, 21);
			cout << "Nguyễn Ngọc Nhung - 21521248\n";
			gotoXY(60, 22);
			Sleep(1000);
			cout << "Bùi Thành Đạt - 21520689\n";
			Sleep(2500);
	clrscr();
}

// in ra menu để người dùng lựa chọn
void firstMenu(int dem, int x, int y, int w, int h, int b_color) {
	if (dem =+ 0) TextColor(18);
	ShowCur(0);
	string b;
	box(5, 1, 122, 5, 11, 1, "\n\n                                                       SORTING PROGRAM");
	box(50,9, 30, 2,  11, 1, "Selection Sort");
	box(50,11, 30, 2, 11, 1, "Interchange Sort");
	gotoXY(50, 11); cout << char(195);
	gotoXY(80, 11); cout << char(180);
	box(50, 13, 30, 2, 11, 1, "Insertion Sort");
	gotoXY(50, 13); cout << char(195);
	gotoXY(80, 13); cout << char(180);
	box(50, 15, 30, 2, 11, 1, "Binary Insersion Sort");
	gotoXY(50, 15); cout << char(195);
	gotoXY(80, 15); cout << char(180);
	box(50, 17, 30, 2, 11, 1, "Bubble Sort");
	gotoXY(50, 17); cout << char(195);
	gotoXY(80, 17); cout << char(180);
	box(50, 19, 30, 2, 11, 1, "Shaker Sort");
	gotoXY(50, 19); cout << char(195);
	gotoXY(80, 19); cout << char(180);
	box(50, 21, 30, 2, 11, 1, "More...");
	gotoXY(50, 21); cout << char(195);
	gotoXY(80, 21); cout << char(180);
	box(50, 23, 30, 2, 11, 1, "Quit");
	gotoXY(50, 23); cout << char(195);
	gotoXY(80, 23); cout << char(180);
	if (dem == 0) b = "Selection Sort";
	if (dem == 1) b = "Interchange Sort";
	if (dem == 2) b = "Insertion Sort";
	if (dem == 3) b = "Binary Insersion Sort";
	if (dem == 4) b = "Bubble Sort";
	if (dem == 5) b = "Shaker Sort";
	if (dem == 6) b = "More...";
	if (dem == 7) b = "Quit";
	highLight(x, y, w, h, b_color, b);
}
void secondMenu(int& dem){
	clrscr();
	TextColor(15);
	cout << "=======================================================================================================================================\n";
	cout << "                                                     SORT PROGRAM\n\n=======================================================================================================================================\n\n";
	if (dem == 8) TextColor(12);
	else TextColor(15);
	cout << "   ===================\n   = 7. Shell Sort   =\n   ===================\n";
	if (dem == 9) TextColor(12);
	else TextColor(15);
	cout << "   =====================\n   = 8. Counting Sort  =\n   =====================\n";
	if (dem == 10) TextColor(12);
	else TextColor(15);
	cout << "   =================\n   = 9. Radix Sort =\n   =================\n";
	if (dem == 11) TextColor(12);
	else TextColor(15);
	cout << "   =================\n   = 10. Heap Sort =\n   =================\n";
	if (dem == 12) TextColor(12);
	else TextColor(15);
	cout << "   ==================\n   = 11. Quick Sort =\n   ==================\n";
	if (dem == 13) TextColor(12);
	else TextColor(15);
	cout << "   ==================\n   = 12. Merge Sort =\n   ==================\n";
	if (dem == 14) TextColor(12);
	else TextColor(15);
	cout << "   ==================\n   =    Back...     =\n   ==================\n";
	if (dem == 15) TextColor(12);
	else TextColor(15);
	cout << "   =================\n   =     Quit      =\n   =================\n";
}
void command()
{	
	char ch;
	int dem = 0;
	int x = 50;
	int y = 9;
	//PlaySound(TEXT("begining.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//gotoXY(61, 12);
	//TextColor(12);
	//ShowCur(0);
	//cout << "== GROUP 12 IT002.M21 ==";
	//gotoXY(59, 13);
	//TextColor(15);
	//cout << "-----------------------------";
	//Sleep(3600);
	//gotoXY(58, 14);
	//TextColor(10);
	//ShowCur(0);
	//ShowCur(0);
	//cout << "== NTD Cooperation Present! ==";
	//gotoXY(56, 15);
	//TextColor(15);
	//cout << "-----------------------------------";
	//Sleep(3600);
	//TextColor(9);
	//gotoXY(60, 16);
	//ShowCur(0);
	//cout << "== SORTING PROGRAM 0.1a ==";
	//gotoXY(58, 17);
	//TextColor(15);
	//cout << "-------------------------------";
	//Sleep(3000);
	//clrscr();
	//TextColor(15);
	//ShowCur(1);
	//PlaySound(TEXT("boot.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//cout << "0> This is demo of Sorting Program. If you want the full version please DONATE...............";
	//Sleep(300);
	//cout << "\n0> LAUNCHING PROGRAM.........................................................................";
	//Sleep(300);
	//cout << "\n0> Copyright © 2022 NTD Cooperation, Inc.All rights reserved.................................";
	//Sleep(300);
	//cout << "\n0> NTD PROPRIETARY / CONFIDENTIAL............................................................";
	//Sleep(300);
	//cout << "\n0> Use is subject to license terms...........................................................";
	//Sleep(300);
	//cout << "\n0> POST engaging.............................................................................";
	//Sleep(300);
	//cout << "\n0> Executing TACTICAL ELECTRONIC VOICE AGENT ARTIFICIAL INTELLIGENCE.........................";
	//Sleep(300);
	//cout << "\n0> Start VOLKNET.....";
	//Sleep(3000);
	//PlaySound(TEXT("Start.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//cout << "\n0> "; cout << "E"; Sleep(50); cout << "s"; Sleep(50); cout << "t"; Sleep(50); cout << "a"; Sleep(50); cout << "b"; Sleep(50); cout << "l"; Sleep(50); cout << "i"; Sleep(50); cout << "s"; Sleep(50); cout << "h"; Sleep(50); cout << "i"; Sleep(50); cout << "n"; Sleep(50); cout << "g"; Sleep(50); cout << " B"; Sleep(50); cout << "a"; Sleep(50); cout << "t"; Sleep(50); cout << "t"; Sleep(50); cout << "l"; Sleep(50); cout << "e"; Sleep(50); cout << "f"; Sleep(50); cout << "i"; Sleep(50); cout << "e"; Sleep(50); cout << "l"; Sleep(50); cout << "d"; Sleep(50); cout << " C"; Sleep(50); cout << "o"; Sleep(50); cout << "n"; Sleep(50); cout << "t"; Sleep(50); cout << "r"; Sleep(50); cout << "o"; Sleep(50); cout << "l"; Sleep(50); cout << " S"; Sleep(50); cout << "t"; Sleep(50); cout << "a"; Sleep(50); cout << "n"; Sleep(50); cout << "d"; Sleep(50); cout << "b"; Sleep(50); cout << "y"; Sleep(50); cout << "."; Sleep(50); cout << "."; Sleep(50); cout << ".";
	//Sleep(3000);
	//PlaySound(TEXT("Welcome.wav"), NULL, SND_FILENAME | SND_ASYNC); 
	//clrscr();
	//TextColor(11);
	//gotoXY(65, 15);
	//ShowCur(0);
	//cout << "W"; Sleep(50); cout << "E"; Sleep(50); cout << "L"; Sleep(50); cout << "C"; Sleep(50); cout << "O"; Sleep(50); cout << "M"; Sleep(50); cout << "E"; Sleep(500);
	//Sleep(2000);
	//PlaySound(TEXT("newtechaquired(inputfile).wav"), NULL, SND_FILENAME | SND_ASYNC);
	do
	{	
		int xp = x; int yp = y;
		while (true) {
			firstMenu(dem,xp,yp, 30, 2, 150);
			ch = _getch();
			if (ch == 13)
			{
				selection(dem);
				if (dem == 7 || dem == 6) break;
				dem = 0;
			}
			if (ch == 80) // xử lý thao tác nhấn nút down
			{
				dem++;
				yp=yp + 2;
				if (dem > 7) dem = 0;
				if (y + 14 < yp) yp = y;
			}
			else if (ch == 72) // xử lý thao tác nhấn nút up
			{
				dem--;
				yp=yp - 2;
				if (dem < 0) dem = 7;
				if (y > yp) yp = y+14;
			}
		}
		if (dem == 7) break;
		while (true) {
			dem == 8;
			secondMenu(dem);
			ch = _getch();
			if (ch == 13)
			{
				selection(dem);
				if (dem == 15 || dem == 14) break;
				dem = 8;
			}
			if (ch == 80) // xử lý thao tác nhấn nút down
			{
				dem++;
				if (dem > 15) dem = 8;
			}
			else if (ch == 72) // xử lý thao tác nhấn nút up
			{
				dem--;
				if (dem < 8) dem = 15;
			}
		}
		if (dem == 15) break;
	} while (true);
}