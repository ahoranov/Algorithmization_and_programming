// PR3/4.cpp
// Горанов Анастас
// Лабораторна робота №3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 8

#include <iostream>
using namespace std;
int main()
{
	double R; // вхідний аргумент
	double x; // вхідний аргумент
	double y; // вхідний параметр
	cout << "r = "; cin >> R;
	cout << "y = "; cin >> y;
	cout << "x = "; cin >> x;
	
	// розгалуження в повній формі
	if (y <= (R, 2) - (x, 2) && y <= 0 && x <= 0 
		|| (0 < x && x >= R) && y == 0 + (2 - 0) / (R / 2 - 0) 
		|| (-R < x && x >= R) && y == (-R) + (0 + R) / (R - R / 2) 
		|| (R < x && x >= 0) && y == 0 + (0 + 0) / (0 - R))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cin.get();
	return 0;
}