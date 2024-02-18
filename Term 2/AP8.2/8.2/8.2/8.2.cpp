// 8.2.cpp
// < Горанов Анастас >
// Лабораторна робота № 8.2
// Опрацювання літерних рядків
// Варіант 10

#include <string.h>
#include <iostream>
#include <cassert>

using namespace std;
bool FirstLetter(char* str);

int main()
{
    char s[101];
    cout << "Enter string:" << endl;
    cin.getline(s, 101);
    if (FirstLetter(s))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

bool FirstLetter(char* str)
{
    int k = 0;
    char* nextToken;
    char* str2 = strtok_s(str, " ", &nextToken);
    while (str2 != NULL)
    {
        if (str2[0] == 'a')
            return true;

        str2 = strtok_s(NULL, " ", &nextToken);
    }

    return false;
}
