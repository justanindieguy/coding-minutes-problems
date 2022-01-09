#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string str)
{
    int spaces = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            spaces++;
    }

    int originalLength = str.length();
    int additionalLength = 2 * spaces;
    int idx = str.length() + additionalLength;

    str.resize(str.length() + additionalLength + 1);
    for (int i = originalLength - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[idx - 1] = '0';
            str[idx - 2] = '2';
            str[idx - 3] = '%';
            idx = idx - 3;
        }
        else
        {
            str[idx - 1] = str[i];
            idx--;
        }
    }

    return str;
}

int main()
{
    string str;
    getline(cin, str);

    str = replaceSpace(str);
    cout << str << endl;

    return 0;
}
