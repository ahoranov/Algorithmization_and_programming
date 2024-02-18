// 8.1IT.cpp
// < Горанов Анастас >
// Лабораторна робота № 8.1IT
// Пошук та заміна символів у літерному рядку 
// Варіант 10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool Include(const char* s);
char* Change(char* s);

int main()
{
    char s[101];

    cout << "Enter string:" << endl;
    cin.getline(s, 100);

    if (Include(s))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << endl;
    cout << "Modified string: " << Change(s) << endl;

    return 0;
}

bool Include(const char* s)
{
    for (int j = 0; s[j + 1] != '\0'; j++)
        if ((s[j] == 'a' && s[j + 1] == 'a') || (s[j] == 'b' && s[j + 1] == 'b') || (s[j] == 'c' && s[j + 1] == 'c'))
            return true;

    return false;
}

char* Change(char* s)
{
    size_t len = strlen(s);
    if (len < 2)
        return s;

    char* tmp = new char[static_cast<size_t>(len * 1.5) + 1];
    char* t = tmp;

    tmp[0] = '\0';
    int i = 0;

    while (i < len && s[i + 1] != '\0')
    {
        if ((s[i] == 'a' && s[i + 1] == 'a') || (s[i] == 'b' && s[i + 1] == 'b') || (s[i] == 'c' && s[i + 1] == 'c'))
        {
            strncat_s(t, len * 1.5 + 1, "***", 3);
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = s[i++];
            *t = '\0';
        }
    }
    *t++ = s[i++];
    *t++ = s[i++];
    *t = '\0';

    strncpy_s(s, len * 1.5 + 1, tmp, len * 1.5 + 1);
    delete[] tmp;
    return s;
}
