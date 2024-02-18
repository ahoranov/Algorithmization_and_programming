// PR5/3.cpp
// Горанов Анастас
// Лабораторна робота №5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 8
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double s(const double x);
int main()
{
	double rp, rk, z;
	int n;
	cout << "rp = "; cin >> rp;
	cout << "rk = "; cin >> rk;
	cout << "n = "; cin >> n;
	double dr = (rk - rp) / n;
	double r = rp;
	cout << fixed;

	cout << "----------------------" << endl;
	cout << "|" << setw(5) << "z" << "   |"
		<< setw(7) << "c" << "    |"
		<< endl;
	cout << "----------------------" << endl;

	while (r <= rk)
	{
		z = s(sqrt(r) + 1) - s(sqrt(r) - 1) * s(sqrt(r) - 1) + 1;
		cout << "|" << setw(7) << setprecision(2) << r << " |"
			<< setw(10) << setprecision(5) << z << " |"
			<< endl;

		r += dr;
	}
	return 0;
}
double s(const double x)
{
	if (abs(x) >= 1)
		return (1 + pow(x, 2) + sqrt(abs(sin(x)))) / (pow(sin(2 * pow(x, 2)), 2) + 3);
	else
	{
		double S, A = 0, B = 0;
		int i = 0;
		int resi = 1, resk = 1;
		int k = 1;

		i = 0;
		while (i <= 5) {
			for (int t = 1; t <= i; t++) {
				resi *= t;
			}
			A += pow(x, i) / resi;
			i++;
		}

		k = 1;
		while (k <= 6) {
			for (int t = 1; t <= k; t++) {
				resk *= t;
			}
			B += pow(x, k) / resk;
			k++;
		}
		S = A + B;
		return S;
	}
}