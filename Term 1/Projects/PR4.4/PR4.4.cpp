// PR4/4.cpp
// Горанов Анастас
// Лабораторна робота № 4.4
// Табуляція функції, заданої графіком.
// Варіант 8

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double R, xp, xk, dx, x, y;

	cout << "R = "; cin >> R;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << fixed;
	cout << "----------------------" << endl;
	cout << "| " << setw(5) << "x " << "  |"
		<< setw(7) << "y " << "    |" << endl;
	cout << "----------------------" << endl;

	x = xp;
	while (x <= xk) 
	{
		if (x <= -8)
			y = -R;
		else
			if (-8 < x && x <= -R)
				y = -8 - (R / (R + 8)) * (x + 8);
			else
				if (-R < x && x <= R)
					y = (R, 2) - (x, 2);
				else
					if (R < x && x <= 5)
						y = 2 / 5 * (x - R);
					else
						y = 2;
		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y << " |" << endl;
		x += dx;

	}

	cout << "----------------------" << endl;
	return 0;
}