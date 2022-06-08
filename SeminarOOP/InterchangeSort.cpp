#include "InterchangeSort.h"

void InterchangeSort::complexity()
{
	cout << "Best case O(n^2) = O(" << length * length << ")\n";
	cout << "Average case O(n^2) = O(" << length * length << ")\n";
	cout << "Worst case O(n*(n-1)/2) = O(" << length * (length - 1) / 2 << ")\n";
}

// sắp xếp mảng tăng
void InterchangeSort::increase()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	clrscr();
	for (int i = 0; i < length - 1; i++)
		for (int j = i + 1; j < length; j++)
		{
			output(i, j);
			if (Arr[i] > Arr[j]) // nếu giá trị phần tử trước lớn hơn giá trị của phần tử sau thì hoàn vị
			{
				swap(Arr[i], Arr[j]);
				output(i, j);
			}
			bool flag = false;
			char ch;
			// xử lý khi người dùng có yêu cầu dừng, tiếp tục, hủy
			if (_kbhit())
			{
				TextColor(15);
				ch = _getch();
				if (ch == 32)
				{
					if (flag == false)
					{
						cout << "\nOn hold!...\n";
						PlaySound(TEXT("Onhold.wav"), NULL, SND_FILENAME | SND_ASYNC);
						cout << "Press ""SPACEBAR"" to continue\n";
					}
					flag = !flag;
				}
				else if (ch == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\nCanceling...";
					Sleep(2000);
					return;
				}
			}
			if (flag)
			{
				char ch1 = _getch();
				if (ch1 == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\nCanceling...";
					Sleep(2000);
					return;
				}
				else
				{
					clrscr();
					cout << "\nInitiating...";
					PlaySound(TEXT("Building.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(1000);
				}
				flag = !flag;
			}
		}
	clrscr();
	output(-1, -1);
}

void InterchangeSort::decrease()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < length - 1; i++)
		for (int j = i + 1; j < length; j++)
		{
			output(i, j);
			if (Arr[i] < Arr[j])
			{
				swap(Arr[i], Arr[j]);
				output(i, j);
			}
			bool flag = false;
			char ch;
			// xử lý khi người dùng có yêu cầu dừng, tiếp tục, hủy
			if (_kbhit())
			{
				TextColor(15);
				ch = _getch();
				if (ch == 32)
				{
					if (flag == false)
					{
						cout << "\nOn hold!...\n";
						PlaySound(TEXT("Onhold.wav"), NULL, SND_FILENAME | SND_ASYNC);
						Sleep(10000);
						cout << "Press ""SPACEBAR"" to continue\n";
						Sleep(10000);
						PlaySound(TEXT("Building.wav"), NULL, SND_FILENAME | SND_ASYNC);
					}
					flag = !flag;
				}
				else if (ch == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\nCanceling...";
					Sleep(2000);
					return;
				}
			}
			if (flag)
			{
				char ch1 = _getch();
				if (ch1 == 27)
				{
					PlaySound(TEXT("cancel.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cout << "\nCanceling...";
					Sleep(2000);
					return;
				}
				else
				{
					clrscr();
					cout << "\nInitiating...";
					PlaySound(TEXT("Building.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(1000);
				}
				flag = !flag;
			}
		}
	clrscr();
	output(-1, -1);
}

// xuất các giá trị tại vị trí i, j màu đỏ
void InterchangeSort::output(int i, int j)
{
	clrscr();
	TextColor(15);
	cout << "Arr = ";
	for (int k = 0; k < length; k++)
		if (k == i || k == j)
		{
			TextColor(12);
			cout << Arr[k] << " ";
		}
		else
		{
			TextColor(15);
			cout << Arr[k] << " ";
		}
	Sleep(speed);
}