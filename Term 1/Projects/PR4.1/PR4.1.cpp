// PR4/1.cpp
// Горанов Анастас
// Лабораторна робота №4.1
// Цикли
// Варіант 8

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int k, N, i;
	double p;
	cout << "k = "; cin >> k;
	cout << "N = "; cin >> N;
	p = 0;
	i = k;
	while (i <= N)
	{
		p+=(k / i) + (i / N);
		i++;
	}
	cout << p << endl;
	p = 0;
	i = k;
	do {
		p+= (k / i) + (i / N);
		i++;
	} while (i <= N);
	cout << p << endl;
	p = 0;
	for (i = k; i <= N; i++)
	{
		p+= (k / i) + (i / N);
	}
	cout << p << endl;
	p = 0;
	for (i = N; i >= k; i--)
	{
		p+= (k / i) + (i / N);
	}
	cout << p << endl;
	return 0;
}