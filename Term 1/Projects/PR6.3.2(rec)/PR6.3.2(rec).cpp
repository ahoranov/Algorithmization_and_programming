// PR6.3.2(rec).cpp
// Горанов Анастас
// Лабораторна робота №6.3.2(rec)
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 8

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i == size) {
        return;
    }
    a[i] = Low + rand() % (High - Low + 1);
    i++;
    Create(a, size, Low, High, i);
}
void Print(int* a, const int size, int i = 0)
{
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    i++;
    Print(a, size, i);

}
int sumOfPositive(int* a, const int size)
{

    return   (a[size] > 0 ? a[size] : 0)
        + (size > 0 ? sumOfPositive(a, size - 1) : 0);
}
template <typename T> // шаблон функції
T sumOfPositiveTemplete(T* a, const int size)
{
    return   (a[size] > 0 ? a[size] : 0)
        + (size > 0 ? sumOfPositiveTemplete(a, size - 1) : 0);
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 10;
    int a[n];
    int Low = -10;
    int High = 10;
    Create(a, n, Low, High);
    Print(a, n);
    cout << "  " << "Sum = " << sumOfPositive(a, n) << endl;
    cout << "  " << "Sum Template = " << sumOfPositiveTemplete(a, n) << endl;
    return 0;
}