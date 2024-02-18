// PR5/5.cpp
// Горанов Анастас
// Лабораторна робота №5.5
// Рекурсивні функції
// Варіант 8

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double q(int m, int n);
double w(int r, int m, int n);
int main()
{
	int n, m, r;
	cout << "m = "; cin >> m;
	cout << "n = "; cin >> n;
	r = n % m;
	cout << "HCD(" << m << "," << n << ")=" << q(m, n) << endl;
	cout << "HCD(" << r << "," << m << ")=" << w(r, m, n) << endl;
	if (q(m, n) == w(r, m, n)) {
		cout << "HCD(m,n) = HCD(r,m)";
	}
	else {
		cout << "HCD(m,n) != HCD(r,m)";
	}
}
double q(int m, int n) {
	while (m != n) {
		if (m > n) {
			m = m - n;
		}
		else {
			n = n - m;
		}
	}
	return m;
}
double w(int r, int m, int n) {
	while (r != m) {
		if (r > m) {
			r = r - m;
		}
		else {
			m = m - r;
		}
	}

	return r;
}