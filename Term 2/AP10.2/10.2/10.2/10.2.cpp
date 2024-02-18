// 10.2.cpp
// < Горанов Анастас >
// Лабораторна робота № 10.2
// Пошук слів у текстовому файлі
// Варіант 10

#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
bool firstletter();

int main()
{
    cout << "Word starts with \'a\': ";
    if (firstletter())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

bool firstletter()
{
    ifstream f;
    char words[100];
    f.open("t.txt");

    while (f >> words)
    {
        if (words[0] == 'a')
            return true;
    }

    f.close();
    return false;
}
