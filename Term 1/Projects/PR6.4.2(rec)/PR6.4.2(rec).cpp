// PR6.4.2(rec).cpp
// Горанов Анастас
// Лабораторна робота №6.4.2(rec)
// Опрацювання та впорядкування одновимірних динамічних масивів
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
int Min(int* a, int size)
{
	if (size <= 1)
		return 1;
	int i = Min(a, --size);
	return a[size] < a[i] ? size : i;
}
int sum(int* arr, int n, bool findedNeg = false) {
	if (n <= 0 || findedNeg && (*arr) < 0) return 0;
	if (!findedNeg && *arr > 0) return sum(arr + 1, n - 1, findedNeg);
	if (!findedNeg && *arr < 0) return sum(arr + 1, n - 1, true);
	return sum(arr + 1, n - 1, findedNeg) + *arr;
}

void zavd2(int* arr, int n) {

	if (n == 1)
		return;

	int count = 0;

	for (int i = 0; i < n - 1; i++)
		if (fabs(arr[i]) >= 1 && fabs(arr[i + 1]) <= 1) {
			swap(arr[i], arr[i + 1]);
			count++;
		}

	if (count == 0)
		return;
	zavd2(arr, n - 1);
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
	cout << "Min elem: " << Min(arr, n) + 1 << endl;
	cout << "Sum: " << sum(arr, n) << endl;
	zavd2(arr, n);
	cout << "After changing: " << endl;
	Print(arr, n);
	delete[] arr;
	return 0;
}