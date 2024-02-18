// 8.1REC.cpp
// < Горанов Анастас >
// Лабораторна робота № 8.1REC
// Пошук та заміна символів у літерному рядку
// Варіант 10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool Include(const char* s, int i)
{
    if ((s[i] == 'a' && s[i + 1] == 'a') || (s[i] == 'b' && s[i + 1] == 'b') || (s[i] == 'c' && s[i + 1] == 'c'))
        return true;

    if (s[i + 1] != '\0')
        return Include(s, i + 1);
    else
        return false;
}

char* Change(char* dest, const char* s, char* t, int i)
{
    if (s[i + 1] != '\0')
    {
        if ((s[i] == 'a' && s[i + 1] == 'a') || (s[i] == 'b' && s[i + 1] == 'b') || (s[i] == 'c' && s[i + 1] == 'c'))
        {
            strncat_s(dest, 151, "***", 3);
            return Change(dest, s, t + 3, i + 2);
        }
        else
        {
            *t++ = s[i++];
            *t = '\0';
            return Change(dest, s, t, i);
        }
    }
    else
    {
        *t++ = s[i++];
        *t++ = s[i++];
        *t = '\0';
        return dest;
    }
}

int main()
{
    char s[101];

    cout << "Enter string:" << endl;
    cin.getline(s, 100);

    if (Include(s, 0))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    char* dest = new char[151];
    dest[0] = '\0';

    char* modifiedString = Change(dest, s, dest, 0);

    cout << endl;
    cout << "String: " << s << endl;
    cout << "Modified string: " << modifiedString << endl;

    delete[] dest;

    return 0;
}
