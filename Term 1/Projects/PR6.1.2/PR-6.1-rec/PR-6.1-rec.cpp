// PR6/1/2.cpp
// Горанов Анастас
// Лабораторна робота №6.1.2
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 8

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int arr[], const int size, const int Low, const int High, int i)
{
		arr[i] = Low + rand() % (High - Low + 1);
		if (i < size - 1) 
		{
			Create(arr, size, Low, High, i + 1);
		}
}

void Print(int arr[], const int size, int i)
{
		cout << arr[i] << " ";
		if (i < size - 1) 
		{
			Print(arr, size, i + 1);
		}	
}

int Sum(int arr[], const int size, int i)
{
	if ((arr[i] < 0) && (arr[i] % 2 == 0))
	{
		if (i < size)
			return arr[i] + Sum(arr, size, i + 1);
		else
			return 0;
	}
	else
		return Sum(arr, size, i + 1);
}

int Amount(int arr[], const int size, int i)
{
	if ((arr[i] < 0) && (arr[i] % 2 == 0))
	{
		if (i < size)
			return 1 + Amount(arr, size, i + 1);
		else
			return 0;
	}
	else 
		return Amount(arr, size, i + 1);
}

int Criterion(int arr[], const int size, int i)
{
	if (i == size)
		return 0;
	if ((arr[i] < 0) && (arr[i] % 2 == 0))
			arr[i] = 0;
		return Criterion(arr, size, i + 1);
}

int main()
{
	srand((unsigned)time(NULL));

	const int n = 24;
	int b[n];

	int Low = -15;
	int High = 75;

	Create(b, n, Low, High, 0);

	cout << "p[ ";
	Print(b, n, 0);
	cout << "]" << endl;

	cout << "Sum = " << Sum(b, n, 0) << endl;
	cout << "Amount = " << Amount(b, n, 0) << endl;

	Criterion(b, n, 0);

	cout << "p[ ";
	Print(b, n, 0);
	cout << "]" << endl;

	return 0;
}
