// 8.1STR.cpp
// < Горанов Анастас >
// Лабораторна робота № 8.1STR
// Пошук та заміна символів у літерному рядку
// Варіант 10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

bool Include(string s, string ss)
{
    if (s.find(ss) != string::npos)
        return true;

    return false;
}

string Change(string& s)
{
    size_t pos = 0;

    while ((pos = s.find('a', pos)) != string::npos)
    {
        if (s[pos + 1] == 'a')
            s.replace(pos, 2, "***");

        if (s[pos + 1] != 'a')
            pos++;
    }

    pos = 0;

    while ((pos = s.find('b', pos)) != string::npos)
    {
        if (s[pos + 1] == 'b')
            s.replace(pos, 2, "***");

        if (s[pos + 1] != 'b')
            pos++;
    }

    pos = 0;

    while ((pos = s.find('c', pos)) != string::npos)
    {
        if (s[pos + 1] == 'c')
            s.replace(pos, 2, "***");

        if (s[pos + 1] != 'c')
            pos++;
    }

    return s;
}

int main()
{
    string s;

    cout << "Enter string:" << endl;
    getline(cin, s);
    cout << endl;

    string s1 = "aa", s2 = "bb", s3 = "cc"; // символи, входження яких перевіряється

    if (Include(s, s1) || Include(s, s2) || Include(s, s3)) // перевіряємо
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    Change(s);

    cout << "Modified string:" << s << endl;

    return 0;
}
