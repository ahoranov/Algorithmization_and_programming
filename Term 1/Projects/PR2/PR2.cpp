// PR.cpp
// Горанов Анастас
// Лабораторна робота №2.1
// Лінійні програми.
// Варіант 8
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double Pi = 4 * atan(1.); // число Пі
	double a;     // вхідний параметр
	double z1;    // результат 1 виразу
	double z2;    // результат 2 виразу

	cout << "a = "; cin >> a;

	z1 = cos(a) + sin(a) + cos(3 * a) + sin(3 * a);
	z2 = 2 * sqrt(2) * cos(a) * sin((Pi / 4) + 2 * a);

	cout << endl;
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;

	cin.get();
	return 0;
}