// PR6/2/1.cpp
// Горанов Анастас
// Лабораторна робота №6.2.1
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 8

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);

}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

void reverse(int* arr, int size) {
	int i, j;

	for (i = 0, j = size - 1; i < size / 2; i++, j--)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];
	int Low = -10;
	int High = 10;
	Create(a, n, Low, High);
	Print(a, n);
	reverse(a, n);
	cout << "After revers: " << endl;
	Print(a, n);
	return 0;
}
