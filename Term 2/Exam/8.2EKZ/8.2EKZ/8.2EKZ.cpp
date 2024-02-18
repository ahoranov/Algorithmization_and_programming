#include <string.h>
#include <iostream>

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
