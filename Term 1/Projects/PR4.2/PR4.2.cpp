// PR4/2.cpp
// Горанов Анастас
// Лабораторна робота №4.2
// Табуляція функції, заданої формулою: функція однієї змінної
// Варіант 8

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double x, xp, xk, dx, A, B, y;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout << "---------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(7) << "y" << " |" << endl;
	cout << "---------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		A = 1 / x + 4;
		if (x < 1)
			B = 0.65 * x + 8;
		else
			if (x >= 5)
				B = sqrt(1 + sqrt(x));
			else
				B = atan((x + 6.1) / 2) + exp(x);
		y = A + B;
		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;
		x += dx;
	}
	cout << "---------------------------" << endl;
	return 0;
}