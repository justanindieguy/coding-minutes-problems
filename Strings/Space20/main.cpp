#include <iostream>
#include <cstring>
using namespace std;

void replaceSpaceQuadratic(char *str)
{
    char replaceString[4] = {'%', '2', '0', '\0'};
    int lastIdx = strlen(str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            int j = lastIdx + 2;
            while (j > i)
            {
                str[j] = str[j - 2];
                j--;
            }

            j = i;
            int lastToReplace = i + 3;
            while (j < lastToReplace)
            {
                str[j] = replaceString[(j + 3) - lastToReplace];
                j++;
            }

            lastIdx += 2;
        }
    }
}

void replaceSpace(char *str)
{
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            spaces++;
    }

    int idx = strlen(str) + 2 * spaces;
    str[idx] = '\0';

    for (int i = strlen(str) - 1; i >= 0; i--)
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
}

int main()
{
    char input[10000];

    cin.getline(input, 1000);
    replaceSpace(input);

    cout << input << endl;

    return 0;
}
