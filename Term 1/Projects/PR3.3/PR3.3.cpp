// PR3/3.cpp
// Горанов Анастас
// Лабораторна робота №3.3
// Розгалуження, задане графіком функції.
// Варіант 8

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x; // вхідний аргумент
	double R; // вхідний параметр
	double y; // результат обчислення виразу
	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;
	
	// розгалуження в повній формі
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
	cout << endl;
	cout << "y = " << y << endl;
	cin.get();
	return 0;
}