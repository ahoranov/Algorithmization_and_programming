// PR6/1/1.cpp
// Горанов Анастас
// Лабораторна робота №6.1.1(iter)
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 8

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void Create(int arr[], const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = Low + rand() % (High - Low + 1);
	}


}

void Print(int arr[], const int size)
{

	cout << "p[ ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;

}

double Sum(int arr[], const int size) {

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ((arr[i] < 0) && (arr[i] % 2 == 0)) 
		{
			sum += arr[i];
		}
	}
	return sum;
}

double Amount(int arr[], const int size) {

	int a = 0;
	for (int i = 0; i < size; i++) {
		if ((arr[i] < 0) && (arr[i] % 2 == 0)) 
		{
			a += 1;
		}
	}
	return a;
}
int Criterion(int arr[], const int size)
{

	for (int i = 0; i < size; i++)
	{
		if ((arr[i] < 0) && (arr[i] % 2 == 0))
		{
			arr[i] = 0;
		}
	}
	return *arr;

}

int main()
{
	srand((unsigned)time(NULL));

	const int n = 24;
	int b[n];
	int Low = -15;
	int High = 75;

	Create(b, n, Low, High);
	Print(b, n);

	cout << "Amount: " << Amount(b, n) << endl;
	cout << "Sum: " << Sum(b, n) << endl;

	Criterion(b, n);
	Print(b, n);

	return 0;
}

