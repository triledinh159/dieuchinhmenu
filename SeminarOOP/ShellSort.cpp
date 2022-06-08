#include "ShellSort.h"

void ShellSort::complexity()
{
	cout << "Best case O(n^2) = O(" << length * length << ")\n";
	cout << "Average case O(n^2) = O(" << length * length << ")\n";
	cout << "Worst case O(n^2) = O(" << length * length << ")\n";
}

// sắp xếp tăng
void ShellSort::increase()
{
	int interval, i, j, temp;
	for (interval = length / 2; interval > 0; interval /= 2) 
	{
		for (i = interval; i < length; i++) 
		{
			temp = Arr[i];
			for (j = i; j >= interval && Arr[j - interval] > temp; j -= interval) Arr[j] = Arr[j - interval];

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
						Sleep(1000);
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

			Arr[j] = temp;
			if (i != j) output();
		}
	}
}

// sắp xếp giảm
void ShellSort::decrease()
{
	int interval, i, j, temp;
	for (interval = length / 2; interval > 0; interval /= 2) 
	{
		for (i = interval; i < length; i++) 
		{
			temp = Arr[i];
			for (j = i; j >= interval && Arr[j - interval] < temp; j -= interval) Arr[j] = Arr[j - interval];

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

			Arr[j] = temp;
			if (i != j) output();
		}
	}
}

// in mảng
void ShellSort::output()
{
	clrscr();
	TextColor(12);
	cout << "Arr = ";
	for (int k = 0; k < length; k++) cout << Arr[k] << " ";
	cout << endl;
	Sleep(speed);
}