// 8.1CHAR.cpp
// < Горанов Анастас >
// Лабораторна робота № 8.1CHAR
// Пошук та заміна символів у літерному рядку
// Варіант 10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool Include(const char* s, const char* ss)
{
    if (strstr(s, ss))
        return true;

    return false;
}

char* Change0(char* s)
{
    size_t len = strnlen_s(s, 100);
    char* t = new char[len * 2 + 1];
    size_t pos1 = 0, pos2 = 0;
    t[0] = '\0';

    const char* p;
    while ((p = strchr(s + pos1, 'a')))
    {
        if (s[p - s + 1] == 'a')
        {
            pos2 = p - s + 2;
            strncat_s(t, len * 2 + 1, s + pos1, pos2 - pos1 - 2);
            strcat_s(t, len * 2 + 1, "***");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1;
            strncat_s(t, len * 2 + 1, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }

    strcat_s(t, len * 2 + 1, s + pos1);
    strcpy_s(s, 100, t);
    delete[] t;

    return s;
}

char* Change1(char* s)
{
    size_t len = strnlen_s(s, 100);
    char* t = new char[len * 2 + 1];
    size_t pos1 = 0, pos2 = 0;
    t[0] = '\0';

    const char* p;
    while ((p = strchr(s + pos1, 'b')))
    {
        if (s[p - s + 1] == 'b')
        {
            pos2 = p - s + 2;
            strncat_s(t, len * 2 + 1, s + pos1, pos2 - pos1 - 2);
            strcat_s(t, len * 2 + 1, "***");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1;
            strncat_s(t, len * 2 + 1, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }

    strcat_s(t, len * 2 + 1, s + pos1);
    strcpy_s(s, 100, t);
    delete[] t;

    return s;
}

char* Change2(char* s)
{
    size_t len = strnlen_s(s, 100);
    char* t = new char[len * 2 + 1];
    size_t pos1 = 0, pos2 = 0;
    t[0] = '\0';

    const char* p;
    while ((p = strchr(s + pos1, 'c')))
    {
        if (s[p - s + 1] == 'c')
        {
            pos2 = p - s + 2;
            strncat_s(t, len * 2 + 1, s + pos1, pos2 - pos1 - 2);
            strcat_s(t, len * 2 + 1, "***");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1;
            strncat_s(t, len * 2 + 1, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }

    strcat_s(t, len * 2 + 1, s + pos1);
    strcpy_s(s, 100, t);
    delete[] t;

    return s;
}

int main()
{
    char Str[100];
    cout << "Enter string: " << endl;
    cin.getline(Str, 100);

    char modstr[151];
    strcpy_s(modstr, sizeof(modstr), Str);
    Change0(modstr);
    Change1(modstr);
    Change2(modstr);

    cout << "Modified string: " << modstr << endl;

    return 0;
}
