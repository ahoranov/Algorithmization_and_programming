// PR6/2/2.cpp
// Горанов Анастас
// Лабораторна робота №6.2.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 8

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
	if (i == size) {
		return;
	}
	a[i] = Low + rand() % (High - Low + 1);
	i++;
	Create(a, size, Low, High, i);
}
void Print(int* a, const int size, int i = 0)
{
	if (i == size) {
		cout << endl;
		return;
	}
	cout << setw(4) << a[i];
	i++;
	Print(a, size, i);

}

void reverse(int* arr, int i, int size) {
	if (i == size)
		return;
	int elem = arr[i];
	reverse(arr, i + 1, size);
	arr[size - i - 1] = elem;

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
	reverse(a, 0, n);
	cout << "After revers: " << endl;
	Print(a, n);
	return 0;
}

