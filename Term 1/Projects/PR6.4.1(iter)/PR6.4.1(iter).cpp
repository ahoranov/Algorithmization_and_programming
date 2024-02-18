// PR6.4.1(iter).cpp
// Горанов Анастас
// Лабораторна робота №6.4.1(iter)
// Опрацювання та впорядкування одновимірних динамічних масивів
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
int Min(int* a, const int size)
{
	int z = 0;
	int min = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] < min) {
			min = a[i];
			z = i;
		}
	}
	return z + 1;
}
int sum(int* a, const int size) {
	int rez = 0;
	for (int i = 0; i <= size; i++) {
		if (a[i] < 0) {
			for (int x = i + 1; x < size; x++) {
				if (a[x] < 0) {
					return rez;
				}
				else {
					rez = rez + a[x];
				}
			}
		}
	}
	return rez;
}

void zavd2(int* a, const int size) {
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (fabs(a[j]) >= 1 && fabs(a[j + 1]) <= 1)
				swap(a[j], a[j + 1]);
}

int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "Input: "; cin >> n;
	int* arr = new int[n];
	int Low = -2;
	int High = 10;
	Create(arr, n, Low, High);
	Print(arr, n);
	cout << "Min elem: " << Min(arr, n) << endl;
	cout << "Sum: " << sum(arr, n) << endl;
	zavd2(arr, n);
	cout << "After changing: " << endl;
	Print(arr, n);
	delete[] arr;
	return 0;
}